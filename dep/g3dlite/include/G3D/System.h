/** 
  @file System.h
 
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  @cite Rob Wyatt http://www.gamasutra.com/features/wyatts_world/19990709/processor_detection_01.htm
  @cite Benjamin Jurke http://www.flipcode.com/cgi-bin/msg.cgi?showThread=COTD-ProcessorDetectionClass&forum=cotd&id=-1
  @cite Michael Herf http://www.stereopsis.com/memcpy.html

  @created 2003-01-25
  @edited  2008-10-14
 */

#ifndef G3D_System_h
#define G3D_System_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/G3DGameUnits.h"
#include "G3D/BinaryFormat.h"
#include <string>

#ifdef G3D_OSX
#   include <CoreServices/CoreServices.h>
#endif

namespace G3D {

/**
 Routine used by the demos to find the data.  Searches in
 ../data, ../../data, etc. up to 5 levels back.  Checks
 common locations like \verbatim c:\libraries\g3d-<version>\data \endverbatim
 and some hard-coded paths on the Brown University file
 system.

 @deprecated
 */
std::string demoFindData(bool errorIfNotFound = true);

/** G3D, SDL, and IJG libraries require license documentation
    to be distributed with your program.  This generates the
    string that must appear in your documentation. 
    <B>Your program can be commercial, closed-source</B> under
    any license you want.
    @deprecated Use System::license
*/
std::string license();

/**
@brief The order in which the bytes of an integer are stored on a
machine. 

Intel/AMD chips tend to be G3D_LITTLE_ENDIAN, Mac PPC's and Suns are
G3D_BIG_ENDIAN. However, this is primarily used to specify the byte
order of file formats, which are fixed.
*/
enum G3DEndian {
    G3D_BIG_ENDIAN, 
    G3D_LITTLE_ENDIAN
};

/**
 @brief OS and processor abstraction.  

 The first time any method is called the processor will be analyzed.
 Future calls are then fast.

 Timing function overview:
    System::getCycleCount
      - actual cycle count

    System::getTick
      - High-resolution time in seconds since program started

    System::getLocalTime
      - High-resolution time in seconds since Jan 1, 1970
        (because it is stored in a double, this may be less
         accurate than getTick)
 */
class System {
public:
    /**
       @param size Size of memory that the system was trying to allocate

       @param recoverable If true, the system will attempt to allocate again
       if the callback returns true.  If false, malloc is going to return 
       NULL and this invocation is just to notify the application.

       @return Return true to force malloc to attempt allocation again if the
       error was recoverable.
     */
    typedef bool (*OutOfMemoryCallback)(size_t size, bool recoverable);

private:

    bool           m_initialized;
    int            m_cpuSpeed;
    bool           m_hasCPUID;
    bool           m_hasRDTSC;
    bool           m_hasMMX;
    bool           m_hasSSE;
    bool           m_hasSSE2;
    bool           m_hasSSE3;
    bool           m_has3DNOW;
    bool           m_has3DNOW2;
    bool           m_hasAMDMMX;
    std::string    m_cpuVendor;
    int            m_numCores;

    /** this holds the data directory set by the application (currently
        GApp) for use by findDataFile */
    std::string    m_appDataDir;

    G3DEndian      m_machineEndian;
    std::string    m_cpuArch;
    std::string    m_operatingSystem;

#   ifdef G3D_WIN32
    /** Used by getTick() for timing */
    LARGE_INTEGER  m_start;
    LARGE_INTEGER  m_counterFrequency;
#else
    struct timeval m_start;
#endif

    std::string    m_version;
    OutOfMemoryCallback m_outOfMemoryCallback;

#ifdef G3D_OSX
    /** In Cycles/Second */
    SInt32         m_OSXCPUSpeed;
    double         m_secondsPerNS;
#endif

    /** The Real-World time of System::getTick() time 0.  Set by initTime */
    RealTime       m_realWorldGetTickTime0;

    uint32         m_highestCPUIDFunction;

    /** @brief Used for the singleton instance only. */
    System();

    /** @brief The singleton instance. 

        Used instead of a global variable to ensure that the order of
        intialization is correct, which is critical because other
        globals may allocate memory using System::malloc.
     */
    static System& instance();

    enum CPUIDFunction {
        CPUID_VENDOR_ID              = 0x00000000,
        CPUID_PROCESSOR_FEATURES     = 0x00000001,
        CPUID_NUM_CORES              = 0x00000004,
        CPUID_GET_HIGHEST_FUNCTION   = 0x80000000,
        CPUID_EXTENDED_FEATURES      = 0x80000001};

    /** Helper macro to call cpuid functions and return all values 

       See http://software.intel.com/en-us/articles/intel-64-architecture-processor-topology-enumeration/
       or  http://www.amd.com/us-en/assets/content_type/white_papers_and_tech_docs/25481.pdf

       for description of the arguments.
    */
    static void cpuid(CPUIDFunction func, uint32& areg, uint32& breg, uint32& creg, uint32& dreg);

    void init();

    /** Called from init() */
    void getStandardProcessorExtensions();

    /** Called from init() */
    void initTime();
    
public:

    /** Returns the speed of processor 0 in MHz. 
        Always returns 0 on linux.*/
    inline static int cpuSpeedMHz() {
        return instance().m_cpuSpeed;
    }

    /** Returns the number of logical processor cores (i.e., the
        number of execution units for threads) */
    inline static int numCores() {
        return instance().m_numCores;
    }

    inline static bool hasCPUID() {
        return instance().m_hasCPUID;
    }

    inline static bool hasRDTSC() {
        return instance().m_hasRDTSC;
    }

    inline static bool hasSSE() {
        return instance().m_hasSSE;
    }

    inline static bool hasSSE2() {
        return instance().m_hasSSE2;
    }

    inline static bool hasSSE3() {
        return instance().m_hasSSE3;
    }

    inline static bool hasMMX() {
        return instance().m_hasMMX;
    }

    inline static bool has3DNow() {
        return instance().m_has3DNOW;
    }

    inline static const std::string& cpuVendor() {
        return instance().m_cpuVendor;
    }

    /**
     Returns the endianness of this machine.
    */
    inline static G3DEndian machineEndian() {
        return instance().m_machineEndian;
    }

    /** e.g., "Windows", "GNU/Linux" */
    inline static const std::string& operatingSystem() {
        return instance().m_operatingSystem;
    }
    
    /** e.g., 80686 */
    inline static const std::string& cpuArchitecture() {
        return instance().m_cpuArch;
    }

    /**
       Returns the current date as a string in the form YYYY-MM-DD
    */
    static std::string currentDateString();

    /**
       Guarantees that the start of the array is aligned to the 
       specified number of bytes.
    */
    static void* alignedMalloc(size_t bytes, size_t alignment);
    
    /**
       Uses pooled storage to optimize small allocations (1 byte to 5
       kilobytes).  Can be 10x to 100x faster than calling ::malloc or
       new.
       
       The result must be freed with free.
       
       Threadsafe on Win32.
       
       @sa calloc realloc OutOfMemoryCallback free
    */
    static void* malloc(size_t bytes);
    
    static void* calloc(size_t n, size_t x);

    /**
     Version of realloc that works with System::malloc.
     */
    static void* realloc(void* block, size_t bytes);

    /** Returns a string describing how well System::malloc is using
        its internal pooled storage.  "heap" memory was slow to
        allocate; the other data sizes are comparatively fast.*/
    static std::string mallocPerformance();
    static void resetMallocPerformanceCounters();

    /** 
       Returns a string describing the current usage of the buffer pools used for
       optimizing System::malloc.
     */
    static std::string mallocStatus();

    /**
     Free data allocated with System::malloc.

     Threadsafe on Win32.
     */
    static void free(void* p);

    /**
     Frees memory allocated with alignedMalloc.
     */
    static void alignedFree(void* ptr);

    /** An implementation of memcpy that may be up to 2x as fast as the C library
        one on some processors.  Guaranteed to have the same behavior as memcpy
        in all cases. */
    static void memcpy(void* dst, const void* src, size_t numBytes);
    
    /** An implementation of memset that may be up to 2x as fast as the C library
        one on some processors.  Guaranteed to have the same behavior as memset
        in all cases. */
    static void memset(void* dst, uint8 value, size_t numBytes);
    
    /**
     Returns the fully qualified filename for the currently running executable.

     This is more reliable than arg[0], which may be intentionally set
     to an incorrect value by a calling program, relative to a now
     non-current directory, or obfuscated by sym-links.

     @cite Linux version written by Nicolai Haehnle <prefect_@gmx.net>, http://www.flipcode.com/cgi-bin/msg.cgi?showThread=COTD-getexename&forum=cotd&id=-1
     */
    static std::string currentProgramFilename();

    /** Name of this program. Note that you can mutate this string to
        set your app name explicitly.*/
    static std::string& appName();

    /** G3D Version string */
    inline static const std::string& version() {
        return instance().m_version;
    }

    /**
       @brief The optimization status of the G3D library (not the program compiled against it)

       Either "Debug" or "Release", depending on whether _DEBUG was
       defined at compile-time for the library.
      */
    static const std::string& build();

    /**
     Causes the current thread to yield for the specified duration
     and consume almost no CPU.
     The sleep will be extremely precise; it uses System::time() 
     to calibrate the exact yeild time.
     */
    static void sleep(RealTime t);

    /**
     Clears the console.
     Console programs only.
     */
    static void consoleClearScreen();

    /**
     Returns true if a key is waiting.
     Console programs only.
     */
    static bool consoleKeyPressed();
    
    /**
     Blocks until a key is read (use consoleKeyPressed to determine if
     a key is waiting to be read) then returns the character code for
     that key.
     */
    static int consoleReadKey();

    /**
     The actual time (measured in seconds since
     Jan 1 1970 midnight).
     
     Adjusted for local timezone and daylight savings
     time.   This is as accurate and fast as getCycleCount().
    */
    static RealTime time();

    /**
     To count the number of cycles a given operation takes:

     <PRE>
     unsigned long count;
     System::beginCycleCount(count);
     ...
     System::endCycleCount(count);
     // count now contains the cycle count for the intervening operation.
     </PRE>
     */
    /* static void beginCycleCount(uint64& cycleCount);
    static void endCycleCount(uint64& cycleCount);

    static uint64 getCycleCount(); */

    inline static void setOutOfMemoryCallback(OutOfMemoryCallback c) {
        instance().m_outOfMemoryCallback = c;
    }

    /**
     When System::malloc fails to allocate memory because the system is
     out of memory, it invokes this handler (if it is not NULL).
     The argument to the callback is the amount of memory that malloc
     was trying to allocate when it ran out.  If the callback returns
     true, System::malloc will attempt to allocate the memory again.
     If the callback returns false, then System::malloc will return NULL.

     You can use outOfMemoryCallback to free data structures or to 
     register the failure.
     */
    inline static OutOfMemoryCallback outOfMemoryCallback() {
        return instance().m_outOfMemoryCallback;
    }

    /** Set an environment variable for the current process */
    static void setEnv(const std::string& name, const std::string& value);
	
    /** Get an environment variable for the current process.  Returns NULL if the variable doesn't exist. */
    static const char* getEnv(const std::string& name);

    /**
     Prints a human-readable description of this machine
     to the text output stream.  Either argument may be NULL.
     */
    static void describeSystem(
        class TextOutput& t);

    static void describeSystem(
        std::string&        s);

    /** On Win32, returns the clipboard text contents.  Does nothing on other
       platforms (yet) */
    static std::string getClipboardText();

    /** Copies the text to the clipboard on Win32. */
    static void setClipboardText(const std::string& s);

    /**
     Tries to locate the resource by looking in related directories.
     If found, returns the full path to the resource, otherwise
     returns the empty string.
     */    
    static std::string findDataFile(const std::string& full, bool errorIfNotFound = true);

    /**
        Sets the path that the application is using as its data directory.
        Used by findDataDir as an initial search location.  GApp sets this
        upon constrution.
    */
    static void setAppDataDir(const std::string& path);

};

/* don't need that for MaNGOS, not portable to Win64...
#ifdef _MSC_VER
    inline uint64 System::getCycleCount() {
        uint32 timehi, timelo;

        // Use the assembly instruction rdtsc, which gets the current
        // cycle count (since the process started) and puts it in edx:eax.
        __asm
            {
                rdtsc;
                mov timehi, edx;
                mov timelo, eax;
            }

        return ((uint64)timehi << 32) + (uint64)timelo;
    }

#elif defined(G3D_LINUX)

    inline uint64 System::getCycleCount() {
        uint32 timehi, timelo;

        __asm__ __volatile__ (
            "rdtsc            "
            : "=a" (timelo),
              "=d" (timehi)
            : );

        return ((uint64)timehi << 32) + (uint64)timelo;
    }

#elif defined(G3D_OSX)

    inline uint64 System::getCycleCount() {
		//Note:  To put off extra processing until the end, this does not 
		//return the actual clock cycle count.  It is a bus cycle count.
		//When endCycleCount() is called, it converts the two into a difference
		//of clock cycles
		
        return (uint64) UnsignedWideToUInt64(UpTime());
		//return (uint64) mach_absolute_time();
    }

#endif

inline void System::beginCycleCount(uint64& cycleCount) {
    cycleCount = getCycleCount();
}


inline void System::endCycleCount(uint64& cycleCount) {
#ifndef G3D_OSX
    cycleCount = getCycleCount() - cycleCount;
#else
    AbsoluteTime end = UpTime();
    Nanoseconds diffNS =
        AbsoluteDeltaToNanoseconds(end, UInt64ToUnsignedWide(cycleCount));
    cycleCount =
        (uint64) ((double) (instance().m_OSXCPUSpeed) *
                  (double) UnsignedWideToUInt64(diffNS) * instance().m_secondsPerNS);
#endif
}
 */

} // namespace

#endif
