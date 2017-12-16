/** 
  \file System.cpp
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  Note: every routine must call init() first.

  There are two kinds of detection used in this file.  At compile
  time, the _MSC_VER #define is used to determine whether x86 assembly
  can be used at all.  At runtime, processor detection is used to
  determine if we can safely call the routines that use that assembly.

  \created 2003-01-25
  \edited  2012-01-05
 */

#include "G3D/platform.h"
#include "G3D/System.h"
#include "G3D/debug.h"
#include "G3D/fileutils.h"
#include "G3D/TextOutput.h"
#include "G3D/G3DGameUnits.h"
#include "G3D/Crypto.h"
#include "G3D/prompt.h"
#include "G3D/stringutils.h"
#include "G3D/Log.h"
#include "G3D/Table.h"
#include "G3D/GMutex.h"
#include "G3D/units.h"
#include "G3D/FileSystem.h"
#include <time.h>

#include <cstring>
#include <cstdio>

// Uncomment the following line to turn off G3D::System memory
// allocation and use the operating system's malloc.
//#define NO_BUFFERPOOL

#include <cstdlib>

#ifdef G3D_WINDOWS

#   include <conio.h>
#   include <sys/timeb.h>
#   include "G3D/RegistryUtil.h"
#include <Ole2.h>
#include <intrin.h>

#elif defined(G3D_LINUX) 

#   include <stdlib.h>
#   include <stdio.h>
#   include <errno.h>
#   include <sys/types.h>
#   include <sys/select.h>
#   include <termios.h>
#   include <unistd.h>
#   include <sys/ioctl.h>
#   include <sys/time.h>
#   include <pthread.h>

#elif defined(G3D_OSX)

    #include <stdlib.h>
    #include <stdio.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/sysctl.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <termios.h>
    #include <unistd.h>
    #include <pthread.h>
    #include <mach-o/arch.h>

    #include <sstream>
    #include <CoreServices/CoreServices.h>
#endif

// SIMM include
#include <xmmintrin.h>


namespace G3D {
    
/** Checks if the CPUID command is available on the processor (called from init) */
static bool checkForCPUID();

/** Called from init */
static void getG3DVersion(std::string& s);

/** Called from init */
static G3DEndian checkEndian();


System& System::instance() {
    static System thesystem;
    return thesystem;
}


System::System() :
    m_initialized(false),
    m_cpuSpeed(0),
    m_hasCPUID(false),
    m_hasRDTSC(false),
    m_hasMMX(false),
    m_hasSSE(false),
    m_hasSSE2(false),
    m_hasSSE3(false),
    m_has3DNOW(false),
    m_has3DNOW2(false),
    m_hasAMDMMX(false),
    m_cpuVendor("Uninitialized"),
    m_numCores(1),
    m_machineEndian(G3D_LITTLE_ENDIAN),
    m_cpuArch("Uninitialized"),
    m_operatingSystem("Uninitialized"),
    m_version("Uninitialized"),
    m_outOfMemoryCallback(NULL),
    m_realWorldGetTickTime0(0),
    m_highestCPUIDFunction(0) {

    init();
}


void System::init() {
    // NOTE: Cannot use most G3D data structures or utility functions
    // in here because they are not initialized.

    if (m_initialized) {
        return;
    } else {
        m_initialized = true;
    }

    getG3DVersion(m_version);
    
    m_machineEndian = checkEndian();

    m_hasCPUID = checkForCPUID();
    // Process the CPUID information
    if (m_hasCPUID) {
        // We read the standard CPUID level 0x00000000 which should
        // be available on every x86 processor.  This fills out
        // a string with the processor vendor tag.
        unsigned int eaxreg = 0, ebxreg = 0, ecxreg = 0, edxreg = 0;

        cpuid(CPUID_VENDOR_ID, eaxreg, ebxreg, ecxreg, edxreg);

        {
            char c[100];
            // Then we connect the single register values to the vendor string
            *((unsigned int*) c)         = ebxreg;
            *((unsigned int*) (c + 4))   = edxreg;
            *((unsigned int*) (c + 8))   = ecxreg;
            c[12] = '\0';
            m_cpuVendor = c;
        }

        switch (ebxreg) {
        case 0x756E6547:        // GenuineIntel
            m_cpuArch = "Intel Processor";
            break;
            
        case 0x68747541:        // AuthenticAMD
            m_cpuArch = "AMD Processor";
            break;

        default:
            m_cpuArch = "Unknown Processor Vendor";
            break;
        }


        unsigned int highestFunction = eaxreg;
        if (highestFunction >= CPUID_NUM_CORES) {
            cpuid(CPUID_NUM_CORES, eaxreg, ebxreg, ecxreg, edxreg);
            // Number of cores is in (eax>>26) + 1
            m_numCores = (eaxreg >> 26) + 1;
        }

        cpuid(CPUID_GET_HIGHEST_FUNCTION, m_highestCPUIDFunction, ebxreg, ecxreg, edxreg);
    }


    // Get the operating system name (also happens to read some other information)
#    ifdef G3D_WINDOWS
	    HRESULT r = OleInitialize(NULL);
        // Note that this overrides some of the values computed above
        bool success = RegistryUtil::readInt32
            ("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 
             "~MHz", m_cpuSpeed);
        HRESULT s = OleInitialize(NULL);
        SYSTEM_INFO systemInfo;
        GetSystemInfo(&systemInfo);
        const char* arch = NULL;
        switch (systemInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_INTEL:
            arch = "x86 Intel";
            break;
    
		case PROCESSOR_ARCHITECTURE_AMD64:
			arch = "x64 Intel/AMD";
			break;

		case PROCESSOR_ARCHITECTURE_ARM:
			arch = "ARM";
			break;

        default:
            arch = "Unknown";
			break;
        }

        m_numCores = systemInfo.dwNumberOfProcessors;
        uint64_t maxAddr = reinterpret_cast<uint64_t>(systemInfo.lpMaximumApplicationAddress);
        {
            char c[1024];
            sprintf(c, "%d - %s cores",
                    systemInfo.dwNumberOfProcessors,
                    arch);
            m_cpuArch = c;
        }

        OSVERSIONINFO osVersionInfo;
        osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
        success = GetVersionEx(&osVersionInfo) != 0;

        if (success) {
            char c[1000];
            sprintf(c, "Windows %d.%d build %d Platform %d %s",
                osVersionInfo.dwMajorVersion,
                osVersionInfo.dwMinorVersion,
                osVersionInfo.dwBuildNumber,
                osVersionInfo.dwPlatformId,
                osVersionInfo.szCSDVersion);
            m_operatingSystem = c;
        } else {
            m_operatingSystem = "Windows";
        }
    
#    elif defined(G3D_LINUX) || defined(G3D_FREEBSD)

        {
            // Find the operating system using the 'uname' command
            FILE* f = popen("uname -a", "r");

            int len = 100;
            char* r = (char*)::malloc(len * sizeof(char));
            (void)fgets(r, len, f);
            // Remove trailing newline
            if (r[strlen(r) - 1] == '\n') {
                r[strlen(r) - 1] = '\0';
            }
            fclose(f);
            f = NULL;

            m_operatingSystem = r;
            ::free(r);
        }

#   elif defined(G3D_OSX)

        // Operating System:
        SInt32 macVersion;
        Gestalt(gestaltSystemVersion, &macVersion);

        int major = (macVersion >> 8) & 0xFF;
        int minor = (macVersion >> 4) & 0xF;
        int revision = macVersion & 0xF;

        {
            char c[1000];
            sprintf(c, "OS X %x.%x.%x", major, minor, revision); 
            m_operatingSystem = c;
        }
                 
        // Clock Cycle Timing Information:
        Gestalt('pclk', &m_OSXCPUSpeed);
        m_cpuSpeed = iRound((double)m_OSXCPUSpeed / (1024 * 1024));
        m_secondsPerNS = 1.0 / 1.0e9;
        
        // System Architecture:
    const NXArchInfo* pInfo = NXGetLocalArchInfo();
        
    if (pInfo) {
        m_cpuArch = pInfo->description;
            
        switch (pInfo->cputype) {
        case CPU_TYPE_POWERPC:
            switch(pInfo->cpusubtype){
        case CPU_SUBTYPE_POWERPC_750:
        case CPU_SUBTYPE_POWERPC_7400:
        case CPU_SUBTYPE_POWERPC_7450:
            m_cpuVendor = "Motorola";
            break;
        case CPU_SUBTYPE_POWERPC_970:
            m_cpuVendor = "IBM";
            break;
        }
        break;
        
            case CPU_TYPE_I386:
                m_cpuVendor = "Intel";
                break;
        }
    }
#   endif

    initTime();

    getStandardProcessorExtensions();

    m_appDataDir = FilePath::parent(System::currentProgramFilename());
}


void getG3DVersion(std::string& s) {

    const char* build = 
#       ifdef G3D_64BIT
            "64-bit";
#       else
            "32-bit";
#       endif

    const char* debug =
#       ifdef G3D_DEBUG
            " (Debug)";
#       else
            "";
#       endif

    char cstr[100];
    if ((G3D_VER % 100) != 0) {
        sprintf(cstr, "G3D Innovation Engine %d.%02d beta %d, %s%s",
                G3D_VER / 10000,
                (G3D_VER / 100) % 100,
                G3D_VER % 100,
                build,
                debug);
    } else {
        sprintf(cstr, "G3D Innovation Engine %d.%02d, %s%s",
                G3D_VER / 10000,
                (G3D_VER / 100) % 100,
                build,
                debug);
    }

    s = cstr;
}

// Places where specific files were most recently found.  This is
// used to cache seeking of common files.
static Table<std::string, std::string> lastFound;

// Places to look in findDataFile
static Array<std::string> directoryArray;

#define MARK_LOG()
//#define MARK_LOG() logPrintf("%s(%d)\n", __FILE__, __LINE__)
std::string System::findDataFile
(const std::string&  _full,
 bool                errorIfNotFound,
 bool                caseSensitive) {
MARK_LOG();

    const std::string full = FilePath::expandEnvironmentVariables(_full);

    // First check if the file exists as requested.  This will go
    // through the FileSystemCache, so most calls do not touch disk.
    if (FileSystem::exists(full, true, caseSensitive)) {
        return full;
    }

MARK_LOG();
    // Now check where we previously found this file.
    std::string* last = lastFound.getPointer(full);
    if (last != NULL) {
        if (FileSystem::exists(*last, true, caseSensitive)) {
            // Even if cwd has changed the file is still present.
            // We won't notice if it has been deleted, however.
            return *last;
        } else {
            // Remove this from the cache it is invalid
            lastFound.remove(full);
        }
    }

MARK_LOG();

    const std::string initialAppDataDir(instance().m_appDataDir);
    const char* g3dPath = getenv("G3D9DATA");

    if (directoryArray.size() == 0) {
        // Initialize the directory array
        RealTime t0 = System::time();

        Array<std::string> baseDirArray;
        
        baseDirArray.append(FileSystem::currentDirectory());
MARK_LOG();
        if (! initialAppDataDir.empty()) {
MARK_LOG();
            baseDirArray.append(initialAppDataDir);
            baseDirArray.append(pathConcat(initialAppDataDir, "data"));
            baseDirArray.append(pathConcat(initialAppDataDir, "data.zip"));
        } else {
MARK_LOG();
            baseDirArray.append("data");
            baseDirArray.append("data.zip");
        }
MARK_LOG();

#       ifdef G3D_WINDOWS
        if (g3dPath == NULL) {
            // If running the demos under visual studio from the G3D.sln file,
            // this will locate the data directory.
            const char* paths[] = {"../data-files/", "../../data-files/", "../../../data-files/", NULL};
            for (int i = 0; paths[i]; ++i) {
                if (FileSystem::exists(pathConcat(paths[i], "G3D-DATA-README.TXT"), true, caseSensitive)) {
                    g3dPath = paths[i];
                    break;
                }
            }
        }
#       endif

        if (g3dPath && (initialAppDataDir != g3dPath)) {
            baseDirArray.append(g3dPath);
        }

        static const std::string subdirs[] = 
            {"font", "gui", "shader", "model", "cubemap", "icon", "material", "image", "md2", "md3", "ifs", "3ds", "sky", "music", "sound", "scene", ""};
        for (int j = 0; j < baseDirArray.size(); ++j) {
            std::string d = baseDirArray[j];
//logPrintf("%s", d.c_str());
            if ((d == "") || FileSystem::exists(d)) {
//logPrintf(" exists\n");
                directoryArray.append(d);
                for (int i = 0; ! subdirs[i].empty(); ++i) {
                    const std::string& p = pathConcat(d, subdirs[i]);
                    if (FileSystem::exists(p, true, caseSensitive)) {
                        directoryArray.append(p);
                    }
                }
            } else {
//logPrintf(" does not exist\n");
            }
        }

        logLazyPrintf("Initializing System::findDataFile took %fs\n", System::time() - t0);

    }
MARK_LOG();

    for (int i = 0; i < directoryArray.size(); ++i) {
        const std::string& p = pathConcat(directoryArray[i], full);
        if (FileSystem::exists(p, true, caseSensitive)) {
            lastFound.set(full, p);
            return p;
        }
    }
MARK_LOG();

    if (errorIfNotFound) {
        // Generate an error message.  Delay this operation until we know that we need it;
        // otherwise all of the string concatenation would run on each successful find.
        std::string locations;
        for (int i = 0; i < directoryArray.size(); ++i) {
            locations += "\'" + pathConcat(directoryArray[i], full) + "'\n";
        }
MARK_LOG();

        std::string msg = "Could not find '" + full + "'.\n\n";
        msg +=     "  cwd                    = '" + FileSystem::currentDirectory() + "'\n";
        if (g3dPath) {
            msg += "  G3D9DATA               = '" + std::string(g3dPath) + "'";
            if (! FileSystem::exists(g3dPath, true, caseSensitive)) {
                msg += " (illegal path!)";
            }
            msg += "\n";
        } else {
            msg += "  G3D9DATA               = (environment variable is not defined)\n";
        }
MARK_LOG();
        msg +=     "  GApp::Settings.dataDir = '" + initialAppDataDir + "'";
        if (! FileSystem::exists(initialAppDataDir, true, caseSensitive)) {
            msg += " (illegal path!)";
        }
        msg += "\n";

        msg += "\nFilenames tested:\n" + locations;

MARK_LOG();
logPrintf("%s\n", msg.c_str());
        throw FileNotFound(full, msg);
        alwaysAssertM(false, msg);
    }
MARK_LOG();

    // Not found
    return "";
}
#undef MARK_LOG

void System::setAppDataDir(const std::string& path) {
    instance().m_appDataDir = path;

    // Wipe the findDataFile cache
    lastFound.clear();
    directoryArray.clear();
}


void System::cleanup() {
    lastFound.clear();
    directoryArray.clear();
}


const std::string& System::build() {
    const static std::string b =
#   ifdef _DEBUG
        "Debug";
#   else 
        "Release";
#   endif

    return b;
}


static G3DEndian checkEndian() {
    int32 a = 1;
    if (*(uint8*)&a == 1) {
        return G3D_LITTLE_ENDIAN;
    } else {
        return G3D_BIG_ENDIAN;
    }
}


static bool checkForCPUID() {
    // all known supported architectures have cpuid
    // add cases for incompatible architectures if they are added
    // e.g., if we ever support __powerpc__ being defined again

    return true;
}


void System::getStandardProcessorExtensions() {
#if ! defined(G3D_OSX) || defined(G3D_OSX_INTEL)
    if (! m_hasCPUID) {
        return;
    }

    uint32 eaxreg = 0, ebxreg = 0, ecxreg = 0, features = 0;

    cpuid(CPUID_PROCESSOR_FEATURES, eaxreg, ebxreg, ecxreg, features);

#   define checkBit(var, bit)   ((var & (1 << bit)) ? true : false)

    m_hasRDTSC    = checkBit(features, 4);
    m_hasMMX      = checkBit(features, 23);
    m_hasSSE      = checkBit(features, 25);
    m_hasSSE2     = checkBit(features, 26);
    // Bit 28 is HTT; not checked by G3D

    m_hasSSE3     = checkBit(ecxreg, 0);

    if (m_highestCPUIDFunction >= CPUID_EXTENDED_FEATURES) {
        cpuid(CPUID_EXTENDED_FEATURES, eaxreg, ebxreg, ecxreg, features);
        m_hasAMDMMX = checkBit(features, 22);  // Only on AMD
        m_has3DNOW  = checkBit(features, 31);  // Only on AMD
        m_has3DNOW2 = checkBit(features, 30);  // Only on AMD
    } else {
        m_hasAMDMMX = false;
        m_has3DNOW  = false;
        m_has3DNOW2 = false;
    }

#   undef checkBit
#endif
}

#if defined(G3D_WINDOWS) && defined(_M_IX86) && !defined(__MINGW32__) /* G3DFIX: Don't check if on 64-bit Windows platforms or using MinGW */
// 32-bit
/** Michael Herf's fast memcpy.  Assumes 16-byte alignment */
void memcpyMMX(void* dst, const void* src, int nbytes) {
    int remainingBytes = nbytes;

    alwaysAssertM((int)dst % 16 == 0, format("Must be on 16-byte boundary.  dst = 0x%x", dst));
    alwaysAssertM((int)src % 16 == 0, format("Must be on 16-byte boundary.  src = 0x%x", src));

    if (nbytes > 64) {
        _asm {
            mov esi, src 
            mov edi, dst 
            mov ecx, nbytes 
            shr ecx, 6 // 64 bytes per iteration 

          loop1: 
            movq mm1,  0[ESI] // Read in source data 
            movq mm2,  8[ESI]
            movq mm3, 16[ESI]
            movq mm4, 24[ESI] 
            movq mm5, 32[ESI]
            movq mm6, 40[ESI]
            movq mm7, 48[ESI]
            movq mm0, 56[ESI]

            movntq  0[EDI], mm1 // Non-temporal stores 
            movntq  8[EDI], mm2 
            movntq 16[EDI], mm3 
            movntq 24[EDI], mm4 
            movntq 32[EDI], mm5 
            movntq 40[EDI], mm6 
            movntq 48[EDI], mm7 
            movntq 56[EDI], mm0 

            add esi, 64 
            add edi, 64 
            dec ecx 
            jnz loop1 

            emms
        }
        remainingBytes -= ((nbytes >> 6) << 6); 
    }

    if (remainingBytes > 0) {
        // Memcpy the rest
        memcpy((uint8*)dst + (nbytes - remainingBytes),
               (const uint8*)src + (nbytes - remainingBytes), remainingBytes); 
    }
}
#endif

void System::memcpy(void* dst, const void* src, size_t numBytes) {
#if defined(G3D_WINDOWS) && defined(_M_IX86) && !defined(__MINGW32__) /* G3DFIX: Don't check if on 64-bit Windows platforms or using MinGW */
    // The overhead of our memcpy seems to only be worthwhile on large arrays
    if (((size_t)dst % 16 == 0) && ((size_t)src % 16 == 0) && (numBytes > 3400000)) {
        memcpyMMX(dst, src, numBytes);
    } else {
        ::memcpy(dst, src, numBytes);
    }
#else
    ::memcpy(dst, src, numBytes);
#endif
}


/** Michael Herf's fastest memset. n32 must be filled with the same
    character repeated. */
#if defined(G3D_WINDOWS) && defined(_M_IX86) && !defined(__MINGW32__) /* G3DFIX: Don't check if on 64-bit Windows platforms or using MinGW */
// On x86 processors, use MMX
void memfill(void *dst, int n32, unsigned long i) {

    int originalSize = i;
    int bytesRemaining = i;

    if (i > 16) {
        
        bytesRemaining = i % 16;
        i -= bytesRemaining;
        __asm {
            movq mm0, n32
            punpckldq mm0, mm0
            mov edi, dst
                
          loopwrite:

            movntq 0[edi], mm0
            movntq 8[edi], mm0

            add edi, 16
            sub i, 16
            jg loopwrite

            emms
        }
    }

    if (bytesRemaining > 0) {
        ::memset((uint8*)dst + (originalSize - bytesRemaining), n32, bytesRemaining); 
    }
}
#endif


void System::memset(void* dst, uint8 value, size_t numBytes) {
    alwaysAssertM(dst != NULL, "Cannot memset NULL address.");
#if defined(G3D_WINDOWS) && defined(_M_IX86) && !defined(__MINGW32__) /* G3DFIX: Don't check if on 64-bit Windows platforms or using MinGW */
    if ((((size_t)dst % 16) == 0) && (numBytes >= 512*1024)) {
        uint32 v = value;
        v = v + (v << 8) + (v << 16) + (v << 24); 
        G3D::memfill(dst, v, numBytes);
    } else {
        ::memset(dst, value, numBytes);
    }
#else
    ::memset(dst, value, numBytes);
#endif
}


/** Removes the 'd' that icompile / Morgan's VC convention appends. */
static std::string computeAppName(const std::string& start) {
    if (start.size() < 2) {
        return start;
    }

    if (start[start.size() - 1] == 'd') {
        // Maybe remove the 'd'; see if ../ or ../../ has the same name
        char tmp[1024];
        (void)getcwd(tmp, sizeof(tmp));
        std::string drive, base, ext;
        Array<std::string> path;
        parseFilename(tmp, drive, path, base, ext);

        std::string shortName = start.substr(0, start.size() - 1);

        if ((path.size() > 1) && (toLower(path.last()) == toLower(shortName))) {
            return shortName;
        }

        if ((path.size() > 2) && (toLower(path[path.size() - 2]) == toLower(shortName))) {
            return shortName;
        }
    }

    return start;
}


std::string& System::appName() {
    static std::string n = computeAppName(filenameBase(currentProgramFilename()));
    return n;
}


std::string System::currentProgramFilename() {
    char filename[2048];

#   ifdef G3D_WINDOWS
    {
        GetModuleFileNameA(NULL, filename, sizeof(filename));
    } 
#   elif defined(G3D_OSX)
    {
        // Run the 'ps' program to extract the program name
        // from the process ID.
        int pid;
        FILE* fd;
        char cmd[80];
        pid = getpid();
        sprintf(cmd, "ps -p %d -o comm=\"\"", pid);

        fd = popen(cmd, "r");
        int s = fread(filename, 1, sizeof(filename), fd);
        // filename will contain a newline.  Overwrite it:
        filename[s - 1] = '\0';
        pclose(fd);
    }
#   else
    {
        int ret = readlink("/proc/self/exe", filename, sizeof(filename));
            
        // In case of an error, leave the handling up to the caller
        if (ret == -1) {
            return "";
        }
            
        debugAssert((int)sizeof(filename) > ret);
            
        // Ensure proper NULL termination
        filename[ret] = 0;      
    }
    #endif

    return filename;
}


void System::sleep(RealTime t) {

    // Overhead of calling this function, measured from a previous run.
    static const RealTime OVERHEAD = 0.00006f;

    RealTime now = time();
    RealTime wakeupTime = now + t - OVERHEAD;

    RealTime remainingTime = wakeupTime - now;
    RealTime sleepTime = 0;

    // On Windows, a "time slice" is measured in quanta of 3-5 ms (http://support.microsoft.com/kb/259025)
    // Sleep(0) yields the remainder of the time slice, which could be a long time.
    // A 1 ms minimum time experimentally kept the "Empty GApp" at nearly no CPU load at 100 fps,
    // yet nailed the frame timing perfectly.
    static RealTime minRealSleepTime = 3 * units::milliseconds();

    while (remainingTime > 0) {

        if (remainingTime > minRealSleepTime * 2.5) {
            // Safe to use Sleep with a time... sleep for half the remaining time
            sleepTime = max(remainingTime * 0.5, 0.0005);
        } else if (remainingTime > minRealSleepTime) {
            // Safe to use Sleep with a zero time;
            // causes the program to yield only
            // the current time slice, and then return.
            sleepTime = 0;
        } else {
            // Not safe to use Sleep; busy wait
            sleepTime = -1;
        }

        if (sleepTime >= 0) {
            #ifdef G3D_WINDOWS
                // Translate to milliseconds
                Sleep((int)(sleepTime * 1e3));
            #else
                // Translate to microseconds
                usleep((int)(sleepTime * 1e6));
            #endif
        }

        now = time();
        remainingTime = wakeupTime - now;
    }
}


void System::consoleClearScreen() {
#   ifdef G3D_WINDOWS
        (void)system("cls");
#   else
        (void)system("clear");
#   endif
}


bool System::consoleKeyPressed() {
    #ifdef G3D_WINDOWS
    
        return _kbhit() != 0;

    #else
    
        static const int STDIN = 0;
        static bool initialized = false;

        if (! initialized) {
            // Use termios to turn off line buffering
            termios term;
            tcgetattr(STDIN, &term);
            term.c_lflag &= ~ICANON;
            tcsetattr(STDIN, TCSANOW, &term);
            setbuf(stdin, NULL);
            initialized = true;
        }

        #ifdef G3D_LINUX

            int bytesWaiting;
            ioctl(STDIN, FIONREAD, &bytesWaiting);
            return bytesWaiting;

        #else

            timeval timeout;
            fd_set rdset;

            FD_ZERO(&rdset);
            FD_SET(STDIN, &rdset);
            timeout.tv_sec  = 0;
            timeout.tv_usec = 0;

            return select(STDIN + 1, &rdset, NULL, NULL, &timeout);
        #endif
    #endif
}


int System::consoleReadKey() {
#   ifdef G3D_WINDOWS
        return _getch();
#   else
        char c;
        (void)read(0, &c, 1);
        return c;
#   endif
}


void System::initTime() {
    #ifdef G3D_WINDOWS
        if (QueryPerformanceFrequency(&m_counterFrequency)) {
            QueryPerformanceCounter(&m_start);
        }

        struct _timeb t;
        _ftime(&t);
        
        m_realWorldGetTickTime0 = (RealTime)t.time - t.timezone * G3D::MINUTE + (t.dstflag ? G3D::HOUR : 0);

    #else
        gettimeofday(&m_start, NULL);
        // "sse" = "seconds since epoch".  The time
        // function returns the seconds since the epoch
        // GMT (perhaps more correctly called UTC). 
        time_t gmt = ::time(NULL);
        
        // No call to free or delete is needed, but subsequent
        // calls to asctime, ctime, mktime, etc. might overwrite
        // local_time_vals. 
        tm* localTimeVals = localtime(&gmt);
    
        time_t local = gmt;
        
        if (localTimeVals) {
            // tm_gmtoff is already corrected for daylight savings.
            local = local + localTimeVals->tm_gmtoff;
        }
        
        m_realWorldGetTickTime0 = local;
    #endif
}


RealTime System::time() { 
#   ifdef G3D_WINDOWS
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);

        return ((RealTime)(now.QuadPart - instance().m_start.QuadPart) /
                instance().m_counterFrequency.QuadPart) + instance().m_realWorldGetTickTime0;
#   else
        // Linux resolution defaults to 100Hz.
        // There is no need to do a separate RDTSC call as gettimeofday
        // actually uses RDTSC when on systems that support it, otherwise
        // it uses the system clock.
        struct timeval now;
        gettimeofday(&now, NULL);

        return (now.tv_sec  - instance().m_start.tv_sec) +
            (now.tv_usec - instance().m_start.tv_usec) / 1e6
            + instance().m_realWorldGetTickTime0;
#   endif
}


////////////////////////////////////////////////////////////////

#define REALPTR_TO_USERPTR(x)   ((uint8*)(x) + sizeof(size_t))
#define USERPTR_TO_REALPTR(x)   ((uint8*)(x) - sizeof(size_t))
#define USERSIZE_TO_REALSIZE(x)       ((x) + sizeof(size_t))
#define REALSIZE_FROM_USERPTR(u) (*(size_t*)USERPTR_TO_REALPTR(ptr) + sizeof(size_t))
#define USERSIZE_FROM_USERPTR(u) (*(size_t*)USERPTR_TO_REALPTR(ptr))

class BufferPool {
public:

    /** Only store buffers up to these sizes (in bytes) in each pool->
        Different pools have different management strategies.

        A large block is preallocated for tiny buffers; they are used with
        tremendous frequency.  Other buffers are allocated as demanded.
        Tiny buffers are 128 bytes long because that seems to align well with
        cache sizes on many machines.
      */
#ifdef G3D_64BIT
    // 64-bit machines have larger pointers...and probably have more memory as well
    enum {tinyBufferSize = 256, smallBufferSize = 2048, medBufferSize = 8192};
#else
    enum {tinyBufferSize = 128, smallBufferSize = 1024, medBufferSize = 4096};
#endif

    /** 
       Most buffers we're allowed to store.
       250000 * { 128 |  256} = {32 | 64} MB (preallocated)
        40000 * {1024 | 2048} = {40 | 80} MB (allocated on demand)
         5000 * {4096 | 8192} = {20 | 40} MB (allocated on demand)
     */
    enum {maxTinyBuffers = 250000, maxSmallBuffers = 40000, maxMedBuffers = 5000};

private:

    /** Pointer given to the program.  Unless in the tiny heap, the user size of the block is stored right in front of the pointer as a uint32.*/
    typedef void* UserPtr;

    /** Actual block allocated on the heap */
    typedef void* RealPtr;

    class MemBlock {
    public:
        UserPtr     ptr;
        size_t      bytes;

        inline MemBlock() : ptr(NULL), bytes(0) {}
        inline MemBlock(UserPtr p, size_t b) : ptr(p), bytes(b) {}
    };

    MemBlock smallPool[maxSmallBuffers];
    int smallPoolSize;

    MemBlock medPool[maxMedBuffers];
    int medPoolSize;

    /** The tiny pool is a single block of storage into which all tiny
        objects are allocated.  This provides better locality for
        small objects and avoids the search time, since all tiny
        blocks are exactly the same size. */
    void* tinyPool[maxTinyBuffers];
    int tinyPoolSize;

    /** Pointer to the data in the tiny pool */
    void* tinyHeap;

    Spinlock            m_lock;

    void lock() {
        m_lock.lock();
    }

    void unlock() {
        m_lock.unlock();
    }

    /** 
     Malloc out of the tiny heap. Returns NULL if allocation failed.
     */
    inline UserPtr tinyMalloc(size_t bytes) {
        // Note that we ignore the actual byte size
        // and create a constant size block.
        (void)bytes;
        assert(tinyBufferSize >= bytes);

        UserPtr ptr = NULL;

        if (tinyPoolSize > 0) {
            --tinyPoolSize;

            // Return the old last pointer from the freelist
            ptr = tinyPool[tinyPoolSize];

#           ifdef G3D_DEBUG
                if (tinyPoolSize > 0) {
                    assert(tinyPool[tinyPoolSize - 1] != ptr); 
                     //   "System::malloc heap corruption detected: "
                     //   "the last two pointers on the freelist are identical (during tinyMalloc).");
                }
#           endif

            // NULL out the entry to help detect corruption
            tinyPool[tinyPoolSize] = NULL;
        }

        return ptr;
    }

    /** Returns true if this is a pointer into the tiny heap. */
    bool inTinyHeap(UserPtr ptr) {
        return 
            (ptr >= tinyHeap) && 
            (ptr < (uint8*)tinyHeap + maxTinyBuffers * tinyBufferSize);
    }

    void tinyFree(UserPtr ptr) {
        assert(ptr);
        assert(tinyPoolSize < maxTinyBuffers);
 //           "Tried to free a tiny pool buffer when the tiny pool freelist is full.");

#       ifdef G3D_DEBUG
            if (tinyPoolSize > 0) {
                UserPtr prevOnHeap = tinyPool[tinyPoolSize - 1];
                assert(prevOnHeap != ptr); 
//                    "System::malloc heap corruption detected: "
//                    "the last two pointers on the freelist are identical (during tinyFree).");
            }
#       endif

        assert(tinyPool[tinyPoolSize] == NULL);

        // Put the pointer back into the free list
        tinyPool[tinyPoolSize] = ptr;
        ++tinyPoolSize;

    }

    void flushPool(MemBlock* pool, int& poolSize) {
        for (int i = 0; i < poolSize; ++i) {
            bytesAllocated -= USERSIZE_TO_REALSIZE(pool[i].bytes);
            ::free(USERPTR_TO_REALPTR(pool[i].ptr));
            pool[i].ptr = NULL;
            pool[i].bytes = 0;
        }
        poolSize = 0;
    }


    /** Allocate out of a specific pool.  Return NULL if no suitable 
        memory was found. */
    UserPtr malloc(MemBlock* pool, int& poolSize, size_t bytes) {

        // OPT: find the smallest block that satisfies the request.

        // See if there's something we can use in the buffer pool.
        // Search backwards since usually we'll re-use the last one.
        for (int i = (int)poolSize - 1; i >= 0; --i) {
            if (pool[i].bytes >= bytes) {
                // We found a suitable entry in the pool.

                // No need to offset the pointer; it is already offset
                UserPtr ptr = pool[i].ptr;

                // Remove this element from the pool, replacing it with
                // the one from the end (same as Array::fastRemove)
                --poolSize;
                pool[i] = pool[poolSize];

                return ptr;
            }
        }

        return NULL;
    }

public:

    /** Count of memory allocations that have occurred. */
    int totalMallocs;
    int mallocsFromTinyPool;
    int mallocsFromSmallPool;
    int mallocsFromMedPool;

    /** Amount of memory currently allocated (according to the application). 
        This does not count the memory still remaining in the buffer pool,
        but does count extra memory required for rounding off to the size
        of a buffer.
        Primarily useful for detecting leaks.*/
    // TODO: make me an atomic int!
    volatile size_t bytesAllocated;

    BufferPool() {
        totalMallocs         = 0;

        mallocsFromTinyPool  = 0;
        mallocsFromSmallPool = 0;
        mallocsFromMedPool   = 0;

        bytesAllocated       = 0;

        tinyPoolSize         = 0;
        tinyHeap             = NULL;

        smallPoolSize        = 0;

        medPoolSize          = 0;


        // Initialize the tiny heap as a bunch of pointers into one
        // pre-allocated buffer.
        tinyHeap = ::malloc(maxTinyBuffers * tinyBufferSize);
        for (int i = 0; i < maxTinyBuffers; ++i) {
            tinyPool[i] = (uint8*)tinyHeap + (tinyBufferSize * i);
        }
        tinyPoolSize = maxTinyBuffers;

#if 0        ///---------------------------------- old mutex
#       ifdef G3D_WINDOWS
            InitializeCriticalSection(&mutex);
#       else
            pthread_mutex_init(&mutex, NULL);
#       endif
#endif        ///---------------------------------- old mutex
    }


    ~BufferPool() {
        ::free(tinyHeap);
        flushPool(smallPool, smallPoolSize);
        flushPool(medPool, medPoolSize);
#if 0 //-------------------------------- old mutex
#       ifdef G3D_WINDOWS
            DeleteCriticalSection(&mutex);
#       else
            // No destruction on pthreads
#       endif
#endif //--------------------------------old mutex
    }

    
    UserPtr realloc(UserPtr ptr, size_t bytes) {
        if (ptr == NULL) {
            return malloc(bytes);
        }

        if (inTinyHeap(ptr)) {
            if (bytes <= tinyBufferSize) {
                // The old pointer actually had enough space.
                return ptr;
            } else {
                // Free the old pointer and malloc
                
                UserPtr newPtr = malloc(bytes);
                System::memcpy(newPtr, ptr, tinyBufferSize);
                tinyFree(ptr);
                return newPtr;

            }
        } else {
            // In one of our heaps.

            // See how big the block really was
            size_t userSize = USERSIZE_FROM_USERPTR(ptr);
            if (bytes <= userSize) {
                // The old block was big enough.
                return ptr;
            }

            // Need to reallocate and move
            UserPtr newPtr = malloc(bytes);
            System::memcpy(newPtr, ptr, userSize);
            free(ptr);
            return newPtr;
        }
    }


    UserPtr malloc(size_t bytes) {
        lock();
        ++totalMallocs;

        if (bytes <= tinyBufferSize) {

            UserPtr ptr = tinyMalloc(bytes);

            if (ptr) {
                ++mallocsFromTinyPool;
                unlock();
                return ptr;
            }

        } 
        
        // Failure to allocate a tiny buffer is allowed to flow
        // through to a small buffer
        if (bytes <= smallBufferSize) {
            
            UserPtr ptr = malloc(smallPool, smallPoolSize, bytes);

            if (ptr) {
                ++mallocsFromSmallPool;
                unlock();
                return ptr;
            }

        } else if (bytes <= medBufferSize) {
            // Note that a small allocation failure does *not* fall
            // through into a medium allocation because that would
            // waste the medium buffer's resources.

            UserPtr ptr = malloc(medPool, medPoolSize, bytes);

            if (ptr) {
                ++mallocsFromMedPool;
                unlock();
                debugAssertM(ptr != NULL, "BufferPool::malloc returned NULL");
                return ptr;
            }
        }

        bytesAllocated += USERSIZE_TO_REALSIZE(bytes);
        unlock();

        // Heap allocate

        // Allocate 4 extra bytes for our size header (unfortunate,
        // since malloc already added its own header).
        RealPtr ptr = ::malloc(USERSIZE_TO_REALSIZE(bytes));

        if (ptr == NULL) {
#           ifdef G3D_WINDOWS
                // Check for memory corruption
                alwaysAssertM(_CrtCheckMemory() == TRUE, "Heap corruption detected.");
#           endif

            // Flush memory pools to try and recover space
            flushPool(smallPool, smallPoolSize);
            flushPool(medPool, medPoolSize);
            ptr = ::malloc(USERSIZE_TO_REALSIZE(bytes));
        }

        if (ptr == NULL) {
            if ((System::outOfMemoryCallback() != NULL) &&
                (System::outOfMemoryCallback()(USERSIZE_TO_REALSIZE(bytes), true) == true)) {
                // Re-attempt the malloc
                ptr = ::malloc(USERSIZE_TO_REALSIZE(bytes));
            }
        }

        if (ptr == NULL) {
            if (System::outOfMemoryCallback() != NULL) {
                // Notify the application
                System::outOfMemoryCallback()(USERSIZE_TO_REALSIZE(bytes), false);
            }
#           ifdef G3D_DEBUG
            debugPrintf("::malloc(%d) returned NULL\n", (int)USERSIZE_TO_REALSIZE(bytes));
#           endif
            debugAssertM(ptr != NULL, 
                         "::malloc returned NULL. Either the "
                         "operating system is out of memory or the "
                         "heap is corrupt.");
            return NULL;
        }

        ((size_t*)ptr)[0] = bytes;

        return REALPTR_TO_USERPTR(ptr);
    }


    void free(UserPtr ptr) {
        if (ptr == NULL) {
            // Free does nothing on null pointers
            return;
        }

        assert(isValidPointer(ptr));

        if (inTinyHeap(ptr)) {
            lock();
            tinyFree(ptr);
            unlock();
            return;
        }

        size_t bytes = USERSIZE_FROM_USERPTR(ptr);

        lock();
        if (bytes <= smallBufferSize) {
            if (smallPoolSize < maxSmallBuffers) {
                smallPool[smallPoolSize] = MemBlock(ptr, bytes);
                ++smallPoolSize;
                unlock();
                return;
            }
        } else if (bytes <= medBufferSize) {
            if (medPoolSize < maxMedBuffers) {
                medPool[medPoolSize] = MemBlock(ptr, bytes);
                ++medPoolSize;
                unlock();
                return;
            }
        }
        bytesAllocated -= USERSIZE_TO_REALSIZE(bytes);
        unlock();

        // Free; the buffer pools are full or this is too big to store.
        ::free(USERPTR_TO_REALPTR(ptr));
    }

    std::string performance() const {
        if (totalMallocs > 0) {
            int pooled = mallocsFromTinyPool +
                         mallocsFromSmallPool + 
                         mallocsFromMedPool;

            int total = totalMallocs;

            return format("malloc performance: %5.1f%% <= %db, %5.1f%% <= %db, "
                          "%5.1f%% <= %db, %5.1f%% > %db",
                          100.0 * mallocsFromTinyPool  / total,
                          BufferPool::tinyBufferSize,
                          100.0 * mallocsFromSmallPool / total,
                          BufferPool::smallBufferSize,
                          100.0 * mallocsFromMedPool   / total,
                          BufferPool::medBufferSize,
                          100.0 * (1.0 - (double)pooled / total),
                          BufferPool::medBufferSize);
        } else {
            return "No System::malloc calls made yet.";
        }
    }

    std::string status() const {
        return format("preallocated shared buffers: %5d/%d x %db",
            maxTinyBuffers - tinyPoolSize, maxTinyBuffers, tinyBufferSize);
    }
};

// Dynamically allocated because we need to ensure that
// the buffer pool is still around when the last global variable 
// is deallocated.
static BufferPool* bufferpool = NULL;

std::string System::mallocPerformance() {    
#ifndef NO_BUFFERPOOL
    return bufferpool->performance();
#else
    return "NO_BUFFERPOOL";
#endif
}

std::string System::mallocStatus() {    
#ifndef NO_BUFFERPOOL
    return bufferpool->status();
#else
    return "NO_BUFFERPOOL";
#endif
}


void System::resetMallocPerformanceCounters() {
#ifndef NO_BUFFERPOOL
    bufferpool->totalMallocs         = 0;
    bufferpool->mallocsFromMedPool   = 0;
    bufferpool->mallocsFromSmallPool = 0;
    bufferpool->mallocsFromTinyPool  = 0;
#endif
}


#ifndef NO_BUFFERPOOL
inline void initMem() {
    // Putting the test here ensures that the system is always
    // initialized, even when globals are being allocated.
    static bool initialized = false;
    if (! initialized) {
        bufferpool = new BufferPool();
        initialized = true;
    }
}
#endif


void* System::malloc(size_t bytes) {
#ifndef NO_BUFFERPOOL
    initMem();
    return bufferpool->malloc(bytes);
#else
    return ::malloc(bytes);
#endif
}

void* System::calloc(size_t n, size_t x) {
#ifndef NO_BUFFERPOOL
    void* b = System::malloc(n * x);
    debugAssertM(b != NULL, "System::malloc returned NULL");
    debugAssertM(isValidHeapPointer(b), "System::malloc returned an invalid pointer");
    System::memset(b, 0, n * x);
    return b;
#else
    return ::calloc(n, x);
#endif
}


void* System::realloc(void* block, size_t bytes) {
#ifndef NO_BUFFERPOOL
    initMem();
    return bufferpool->realloc(block, bytes);
#else
    return ::realloc(block, bytes);
#endif
}


void System::free(void* p) {
#ifndef NO_BUFFERPOOL
    bufferpool->free(p);
#else
    return ::free(p);
#endif
}


void* System::alignedMalloc(size_t bytes, size_t alignment) {

    alwaysAssertM(isPow2((uint32)alignment), "alignment must be a power of 2");

    // We must align to at least a word boundary.
    alignment = max(alignment, sizeof(void *));

    // Pad the allocation size with the alignment size and the size of
    // the redirect pointer.  This is the worst-case size we'll need.
    // Since the alignment size is at least teh word size, we don't
    // need to allocate space for the redirect pointer.  We repeat the max here
    // for clarity.
    size_t totalBytes = bytes + max(alignment, sizeof(void*));

    size_t truePtr = (size_t)System::malloc(totalBytes);

    if (truePtr == 0) {
        // malloc returned NULL
        return NULL;
    }

    debugAssert(isValidHeapPointer((void*)truePtr));
    #ifdef G3D_WINDOWS
    // The blocks we return will not be valid Win32 debug heap
    // pointers because they are offset 
    //  debugAssert(_CrtIsValidPointer((void*)truePtr, totalBytes, TRUE) );
    #endif


    // We want alignedPtr % alignment == 0, which we'll compute with a
    // binary AND because 2^n - 1 has the form 1111... in binary.
    const size_t bitMask = (alignment - 1);

    // The return pointer will be the next aligned location that is at
    // least sizeof(void*) after the true pointer. We need the padding
    // to have a place to write the redirect pointer.
    size_t alignedPtr = truePtr + sizeof(void*);

    const size_t remainder = alignedPtr & bitMask;
    
    // Add what we need to make it to the next alignment boundary, but
    // if the remainder was zero, let it wrap to zero and don't add
    // anything.
    alignedPtr += ((alignment - remainder) & bitMask);

    debugAssert((alignedPtr & bitMask) == 0);
    debugAssert((alignedPtr - truePtr + bytes) <= totalBytes);

    // Immediately before the aligned location, write the true array location
    // so that we can free it correctly.
    size_t* redirectPtr = (size_t *)(alignedPtr - sizeof(void *));
    redirectPtr[0] = truePtr;

    debugAssert(isValidHeapPointer((void*)truePtr));

    #if defined(G3D_WINDOWS) && defined(G3D_DEBUG)
        if (bytes < 0xFFFFFFFF) { 
            debugAssert( _CrtIsValidPointer((void*)alignedPtr, (int)bytes, TRUE) );
        }
    #endif
    return (void *)alignedPtr;
}


void System::alignedFree(void* _ptr) {
    if (_ptr == NULL) {
        return;
    }

    size_t alignedPtr = (size_t)_ptr;

    // Back up one word from the pointer the user passed in.
    // We now have a pointer to a pointer to the true start
    // of the memory block.
    size_t* redirectPtr = (size_t*)(alignedPtr - sizeof(void *));

    // Dereference that pointer so that ptr = true start
    void* truePtr = (void*)redirectPtr[0];

    debugAssert(isValidHeapPointer((void*)truePtr));
    System::free(truePtr);
}


void System::setEnv(const std::string& name, const std::string& value) {
    std::string cmd = name + "=" + value;
#   ifdef G3D_WINDOWS
        _putenv(cmd.c_str());
#   else
        // Many linux implementations of putenv expect char*
        putenv(const_cast<char*>(cmd.c_str()));
#   endif
}


const char* System::getEnv(const std::string& name) {
    return getenv(name.c_str());
}


static void var(TextOutput& t, const std::string& name, const std::string& val) {
    t.writeSymbols(name,"=");
    t.writeString(val);
    t.writeNewline();
}


static void var(TextOutput& t, const std::string& name, const bool val) {
    t.writeSymbols(name, "=", val ? "Yes" : "No");
    t.writeNewline();
}


static void var(TextOutput& t, const std::string& name, const int val) {
    t.writeSymbols(name,"=");
    t.writeNumber(val);
    t.writeNewline();
}


void System::describeSystem(
    std::string&        s) {

    TextOutput t;
    describeSystem(t);
    t.commitString(s);
}

void System::describeSystem(
    TextOutput& t) {

    t.writeSymbols("App", "{");
    t.writeNewline();
    t.pushIndent();
    {
        var(t, "Name", System::currentProgramFilename());
        char cwd[1024];
        (void)getcwd(cwd, 1024);
        var(t, "cwd", std::string(cwd));
    }
    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();

    t.writeSymbols("OS", "{");
    t.writeNewline();
    t.pushIndent();
    {
        var(t, "Name", System::operatingSystem());
    }
    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();

    t.writeSymbols("CPU", "{");
    t.writeNewline();
    t.pushIndent();
    {
        var(t, "Vendor", System::cpuVendor());
        var(t, "Architecture", System::cpuArchitecture());
        var(t, "hasCPUID", System::hasCPUID());
        var(t, "hasMMX", System::hasMMX());
        var(t, "hasSSE", System::hasSSE());
        var(t, "hasSSE2", System::hasSSE2());
        var(t, "hasSSE3", System::hasSSE3());
        var(t, "has3DNow", System::has3DNow());
        var(t, "hasRDTSC", System::hasRDTSC());
        var(t, "numCores", System::numCores());
    }
    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();
       
    t.writeSymbols("G3D", "{");
    t.writeNewline();
    t.pushIndent();
    {
        const char* g3dPath = getenv("G3D9DATA");
        var(t, "Link version", G3D_VER);
        var(t, "Compile version", System::version());
        var(t, "G3D9DATA", std::string(g3dPath ? g3dPath : ""));
    }
    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();
}

std::string System::currentDateString() {
    time_t t1;
    ::time(&t1);
    tm* t = localtime(&t1);
    return format("%d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday); 
}

std::string System::currentTimeString() {
    time_t t1;
    ::time(&t1);
    tm* t = localtime(&t1);
    return format("%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);
}

#if defined(_MSC_VER)

// Windows 64-bit
void System::cpuid(CPUIDFunction func, uint32& eax, uint32& ebx, uint32& ecx, uint32& edx) {
	int regs[4] = {eax, ebx, ecx, edx};
	__cpuid(regs, func);
	eax = regs[0];
	ebx = regs[1];
	ecx = regs[2];
	edx = regs[3];
}

#else

// See http://sam.zoy.org/blog/2007-04-13-shlib-with-non-pic-code-have-inline-assembly-and-pic-mix-well
// for a discussion of why the second version saves ebx; it allows 32-bit code to compile with the -fPIC option.
// On 64-bit x86, PIC code has a dedicated rip register for PIC so there is no ebx conflict.
void System::cpuid(CPUIDFunction func, uint32& eax, uint32& ebx, uint32& ecx, uint32& edx) {
#if ! defined(__PIC__) || defined(__x86_64__)
    // AT&T assembler syntax
    asm volatile(
                 "movl $0, %%ecx   \n\n" /* Wipe ecx */
                 "cpuid            \n\t"
                 : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
                 : "a"(func));
#else
    // AT&T assembler syntax
    asm volatile(
                 "pushl %%ebx      \n\t" /* save ebx */
                 "movl $0, %%ecx   \n\n" /* Wipe ecx */
                 "cpuid            \n\t"
                 "movl %%ebx, %1   \n\t" /* save what cpuid just put in %ebx */
                 "popl %%ebx       \n\t" /* restore the old ebx */
                 : "=a"(eax), "=r"(ebx), "=c"(ecx), "=d"(edx)
                 : "a"(func));
#endif
}

#endif

}  // namespace
