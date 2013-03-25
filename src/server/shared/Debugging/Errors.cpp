#include "Errors.h"
#include "Log.h"

#include <ace/Stack_Trace.h>
#include <ace/OS_NS_unistd.h>

namespace Trinity {

void Assert(char const *file, int line, char const *function, char const *message)
{
    ACE_Stack_Trace st;
    fprintf(stderr, "\n%s:%i in %s ASSERTION FAILED:\n  %s\n%s\n",
            file, line, function, message, st.c_str());
    *((volatile int*)NULL) = 0;
}

void Fatal(char const *file, int line, char const *function, char const *message)
{
    sLog->outError(LOG_FILTER_GENERAL, "\n%s:%i in %s FATAL ERROR:\n  %s\n",
                   file, line, function, message);
    ACE_OS::sleep(10);
    *((volatile int*)NULL) = 0;
}

void Error(char const *file, int line, char const *function, char const *message)
{
    sLog->outError(LOG_FILTER_GENERAL, "\n%s:%i in %s ERROR:\n  %s\n",
                   file, line, function, message);
    *((volatile int*)NULL) = 0;
}

void Warning(char const *file, int line, char const *function, char const *message)
{
    sLog->outError(LOG_FILTER_GENERAL, "\n%s:%i in %s WARNING:\n  %s\n",
                   file, line, function, message);
}

} // namespace Trinity
