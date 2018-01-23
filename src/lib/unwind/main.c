#include <unwind.h>

_Unwind_Ptr _Unwind_GetIP (struct _Unwind_Context *context __attribute__((unused)))
{
    return 0;
}

_Unwind_Reason_Code LIBGCC2_UNWIND_ATTRIBUTE
_Unwind_Backtrace (_Unwind_Trace_Fn callback __attribute__((unused)), void *ptr __attribute__((unused)))
{
    return _URC_NO_REASON;
}
