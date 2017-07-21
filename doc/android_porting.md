# Porting an Android library

## Creating required build files

To port an Android library, files for the Genode build system need to be
created to define the process of check out, compilation and import. Many
details are hidden by Android-specific Makefile fragments (see
‵lib/mk/android\*.inc‵ and ‵lib/import/import-android.inc‵.  The ‵tool/portlib‵
helps creating build files that call those fragments with the right parameters.

To use it, the library name, the git repository location and its directory
within the repository need to be identified. This is best be done with a
checked-out Android source tree. The following example obtains the required
information for the ‵libnativebridge‵ library, assuming the Android tree is
located in ANDROID_DIR:

1. Find the library directory

	‵‵‵
	$ cd ANDROID_DIR
	$ find . -name libnativebridge -type d
	./system/core/libnativebridge
	‵‵‵

2. Identify the remote repository

	‵‵‵
	$ cd system/core/libnativebridge
	$ git remote -v show
	aosp    https://android.googlesource.com/platform/system/core (fetch)
	aosp    https://android.googlesource.com/platform/system/core (push)
	‵‵‵

3. Identify the library subdirectory within the repository

	‵‵‵
	$ git rev-parse --show-toplevel
	ANDROID_DIR/system/core
	‵‵‵

	This implies that the library is located in the ‵libnativebridge‵ subdirectory
	of the repository.

4. Derive parameters for ‵portlib‵

	* ‵--portname‵: This is the name of the port to be created. It will typically be name of the Android library (libnativebridge)
	* ‵--urlsuffix‵: Remote path to the repository URL relative to https://android.googlesource.com/platform/ (system/core)
	* ‵--subdir‵: Directory within the repository (libnativebridge)

	The ‵portlib‵ tool must be called from the root directory of the componolit repositroy. For the above example a call is as follows:

	‵‵‵
	./tool/portlib --portname libnativebridge --urlsuffix system/core --subdir libnativebridge
	‵‵‵

The following files are created:

	* Port file: ‵ports/libnativebridge.port‵
	* Port hash file: ‵ports/libnativebridge.hash‵
	* Library build file: ‵lib/mk/libnativebridge.mk‵
	* Library import file: ‵lib/import/import-libnativebridge.mk‵

The hash file is just a dummy which needs to be updated with a proper hash.
Most likely, changes to the library build file are required to add compiler
flags, include paths or to evaluate other sections of the Android.bp build
file.

## System-specific code

Android encapsulates system-specific code into conditional preprocessor blocks.
Android, Windows, OS X and Linux are supported platforms. As the FreeBSD libc
ported to Genode is not covered by the Android platform, often there is no
appropriate code block or #else block that would raise an error.

Hence, when porting a library, system-specific portions of the code should be
identified and extended:

‵‵‵
$ egrep -nar '(_WIN32|__APPLE__|__ANDROID__|__linux__)' <SOURCE_DIR>
‵‵‵

By convention, the android build fragment (‵android.inc‵) defines the
‵__GENODE__‵ macro to distinguish Genode builds. There are two problematic
construct in the code that should be investigated:

1. Missing else block

    In ‵if/elif‵ preprocessor blocks the final else block is missing. This
	can result in missing includes, missing functions, undefined types and
	more. When porting such code, an ‵elif defined(__GENODE__)‵ block
	should be added with a Genode-specific implementation. Optionally,
	an else branch emitting an error message could be added in addition.

2. Default else block

	Sometimes a default implementation is put into the else block. One should
	check whether this implementation is suitable and add an
	‵elif defined(__GENODE__)‵ block if necessary.

3. Error else block

	Add an appropriate ‵elif defined(__GENODE__)‵ block.

## Initialization

The Android base library (libbase) expects a proper program name to be set
before ‵main()‵ is executed. If you encounter errors like

	‵‵‵
	Error: Uncaught exception of type 'std::logic_error'
	Warning: abort called - thread: ep
	‵‵‵

you should add a ‵setprogname()‵ call to your Libc::Component::construct()
method before calling ‵main()‵:

	‵‵‵
	setprogname (argv[0]);
	exit (main(argc, argv));
	‵‵‵
