# Porting an Android library

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

## Tests
