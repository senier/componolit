
#include <libc/component.h>
#include <base/log.h>

struct Main{

    void __attribute__((noinline)) throw_exception(void)
    {
        Genode::log("threads exception: ", __func__);
        throw 0;
    }

    Main(Genode::Env &env)
    {
        Genode::log("threads exception: ", __func__);
        try{
            Genode::log("threads exception: try");
            throw_exception();
        }catch(...){
            Genode::log("threads exception: catched");
        }
        throw_exception();
    }
};

void Libc::Component::construct(Libc::Env &env)
{
   static Main main(env); 
}
