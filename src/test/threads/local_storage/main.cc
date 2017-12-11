
#include <libc/component.h>
#include <base/log.h>

#include <thread>

static void test()
{
    Genode::log("threads tls: ", __func__);
    thread_local int _x = 42;
    Genode::log("threads tls: ", _x, " @ ", (void*)&_x);
}

struct Main{
    
    Main(Genode::Env &)
    {
        Genode::log("threads tls: ", __func__);
        std::thread t(test);
    }
};

void Libc::Component::construct(Libc::Env &env)
{
   static Main main(env); 
}
