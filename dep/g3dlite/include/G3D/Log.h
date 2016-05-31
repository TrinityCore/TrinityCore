/**
  @file Log.h

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  @cite Backtrace by Aaron Orenstein
  @created 2001-08-04
  @edited  2005-11-04
 */

#ifndef G3D_LOG_H
#define G3D_LOG_H

#include <stdio.h>
#include <string>
#include "G3D/platform.h"

#ifndef G3D_WINDOWS
    #include <stdarg.h>
#endif

namespace G3D {

/** Prints to the common system log, log.txt, which is usually 
    in the working directory of the program.  If your disk is 
    not writable or is slow, it will attempt to write to "c:/tmp/log.txt" or
     "c:/temp/log.txt" on Windows systems instead. 

    Unlike printf or debugPrintf, 
    this function guarantees that all output is committed before it returns.
    This is very useful for debugging a crash, which might hide the last few
    buffered print statements otherwise.

    Many G3D routines write useful warnings and debugging information to the
    system log, which makes it a good first place to go when tracking down
    a problem.
     */
void logPrintf(const char* fmt, ...);

/** Does not flush the buffer; follow up with a logPrintf to force the flush. */
void logLazyPrintf(const char* fmt, ...);

/**
 System log for debugging purposes.  The first log opened
 is the "common log" and can be accessed with the static
 method common().  If you access common() and a common log
 does not yet exist, one is created for you.
 */
class Log {
private:

    /**
     Log messages go here.
     */
    FILE*                   logFile;

    std::string             filename;

    static Log*             commonLog;

public:
    int                     stripFromStackBottom;


    /**
     @param stripFromStackBottom Number of call stacks to strip from the
     bottom of the stack when printing a trace.  Useful for hiding
     routines like "main" and "WinMain".  If the specified file cannot
     be opened for some reason, tries to open "c:/tmp/log.txt" or
     "c:/temp/log.txt" instead.
     */
    Log(const std::string& filename = "log.txt",
        int stripFromStackBottom    = 0);

    virtual ~Log();

    /**
     Returns the handle to the file log.
     */
    FILE* getFile() const;

    /**
     Marks the beginning of a logfile section.
     */
    void section(const std::string& s);

    /**
     Given arguments like printf, writes characters to the debug text overlay.
     */
    // We want G3D_CHECK_PRINTF_ARGS here, but that conflicts with the
    // overload.
    void __cdecl printf(const char* fmt, ...) G3D_CHECK_PRINTF_METHOD_ARGS;

    void __cdecl vprintf(const char*, va_list argPtr) G3D_CHECK_VPRINTF_METHOD_ARGS;
    /** Does not flush */
    void __cdecl lazyvprintf(const char*, va_list argPtr) G3D_CHECK_VPRINTF_METHOD_ARGS;

    static Log* common();

    static std::string getCommonLogFilename();

    void print(const std::string& s);


    void println(const std::string& s);
};

}

#endif
