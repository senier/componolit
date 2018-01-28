#include <base/log.h>
#include <libc/component.h>

class Test_failed : Genode::Exception { };

#define ASSERT(exp) if(!(exp)) { Genode::error("Assertion \"", #exp, "\" failed in ", __FILE__, ":", __LINE__); throw Test_failed(); }

extern "C" {

int tst_rwlock_1();
int tst_rwlock_5();
int tst_rwlock_13();

}

struct Main {

    Main(Genode::Env &env __attribute__((unused)))
    {
        Genode::log("tst_rwlock_1");
        ASSERT (tst_rwlock_1() == 0);
        Genode::log("tst_rwlock_13");
        ASSERT (tst_rwlock_13() == 0);

        // Must be last, as this test blocks forever and we test
        // for output of "tst-rwlock5 done"
        Genode::log("tst_rwlock_5");
        ASSERT (tst_rwlock_5() == 0);

        Genode::log("ERROR");
    }
};

void Libc::Component::construct(Libc::Env &env)
{
    Libc::with_libc([&] () { static Main main(env); });
}
