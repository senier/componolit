
#include <libc/component.h>
#include <base/log.h>

struct Main{
    
    Main(Genode::Env &env)
    {
        Genode::log("threads basic: ", __func__);
    }
};

void Libc::Component::construct(Libc::Env &env)
{
   static Main main(env); 
}
