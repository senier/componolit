
#include <libc/component.h>
#include <base/log.h>
#include <timer_session/connection.h>

#include <thread>

static void test(int *x, Timer::Connection *_t)
{
    Genode::log("threads join: ", __func__);
    _t->msleep(5000);
    *x = 1;
}

struct Main {
    
    Timer::Connection _timer;

    Main(Genode::Env &env) : _timer(env)
    {
        cxxthread_env.initialize (env, 4096);
        Genode::log("threads join: ", __func__);
        int x = 0;
        std::thread t(test, &x, &_timer);
        t.join();
        Genode::log("threads join: ", "finished ", x);
    }
};

void Libc::Component::construct(Libc::Env &env)
{
   static Main main(env); 
}
