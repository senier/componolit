
#include <libc/component.h>
#include <base/log.h>

class Test_exception : public Genode::Exception {};

struct Main{

    void __attribute__((noinline)) throw_scalar_exception(void)
    {
        Genode::log("threads exception: ", __func__);
        throw 0;
    }

    void __attribute__((noinline)) throw_class_exception(void)
    {
        Genode::log("threads exception: ", __func__);
        throw Test_exception();
    }

    Main(Genode::Env &env)
    {
        Genode::log("threads exception: ", __func__);
        try{
            Genode::log("threads exception: try");
            throw_scalar_exception();
        }catch(...){
            Genode::log("threads exception: catched");
        }
        
        try{
            Genode::log("threads exception: try");
            throw_class_exception();
        }catch(...){
            Genode::log("threads exception: catched");
        }
        throw_class_exception();
    }
};

void Libc::Component::construct(Libc::Env &env)
{
   static Main main(env); 
}
