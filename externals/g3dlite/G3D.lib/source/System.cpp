/** 
  @file System.cpp
 
  @maintainer Morgan McGuire, matrix@graphics3d.com

  Note: every routine must call init() first.

  There are two kinds of detection used in this file.  At compile
  time, the _MSC_VER #define is used to determine whether x86 assembly
  can be used at all.  At runtime, processor detection is used to
  determine if we can safely call the routines that use that assembly.

  @cite Rob Wyatt http://www.gamasutra.com/features/wyatts_world/19990709/processor_detection_01.htm
  @cite Benjamin Jurke http://www.flipcode.com/cgi-bin/msg.cgi?showThread=COTD-ProcessorDetectionClass&forum=cotd&id=-1
  @cite Michael Herf http://www.stereopsis.com/memcpy.html

  @created 2003-01-25
  @edited  2008-09-02
 */

#include "G3D/platform.h"
#include "G3D/System.h"
#include "G3D/debug.h"
#include "G3D/fileutils.h"
#include "G3D/TextOutput.h"
#include "G3D/G3DGameUnits.h"
#include "G3D/Crypto.h"
#include "G3D/prompt.h"
#include "G3D/Log.h"
#include <time.h>

#include <cstring>
#include <cstdio>

// Uncomment the following line to turn off G3D::System memory
// allocation and use the operating system's malloc.
//#define NO_BUFFERPOOL

#if defined(__i386__) || defined(__x86_64__) || defined(G3D_WIN32)
#    define G3D_NOT_OSX_PPC
#endif

#ifdef G3D_WIN32

#   include <conio.h>
#   include <sys/timeb.h>
#   include "G3D/RegistryUtil.h"

#elif defined(G3D_LINUX) 

    #include <stdlib.h>
    #include <stdio.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/select.h>
    #include <termios.h>
    #include <unistd.h>
    #include <sys/ioctl.h>
    #include <sys/time.h>
    #include <pthread.h>

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

#if defined(SSE)
    #include <xmmintrin.h>
#endif

namespace G3D {

struct CpuInfo
{
public:
    int     m_cpuSpeed;
    bool    m_hasCPUID;
    bool    m_hasRDTSC;
    bool    m_hasMMX;
    bool    m_hasSSE;
    bool    m_hasSSE2;
    bool    m_hasSSE3;
    bool    m_has3DNOW;
    char    m_cpuVendorStr[1024];
};

// helper macro to call cpuid functions and return all values
#ifdef _MSC_VER

    // VC on Intel
#   define CALL_CPUID(func, areg, breg, creg, dreg) \
	   __asm mov	eax, func   \
	   __asm cpuid             \
       __asm mov	areg, eax   \
       __asm mov	breg, ebx   \
	   __asm mov	creg, ecx   \
	   __asm mov	dreg, edx

#elif defined(__GNUC__) && defined(G3D_OSX_INTEL)
    // GCC on OS X intel
#    define CALL_CPUID(func, areg, breg, creg, dreg) \
       areg = 0;   \
       breg = 0;   \
       creg = 0;   \
       dreg = 0;
#else
    // Any other compiler/platform, likely GCC
#   define CALL_CPUID(func, areg, breg, creg, dreg) \
       __asm__ (           \
       "cpuid \n":         \
       "=a" (areg),        \
       "=b" (breg),        \
       "=c" (creg),        \
       "=d" (dreg):        \
       "a" (func)          \
       );
#endif

// this holds the data directory set by the application (currently GApp) for use by findDataFile
static char                                     g_appDataDir[FILENAME_MAX] = "";

static CpuInfo                                  g_cpuInfo = {
    0, false, false, false, false, false, false, false, {'U', 'n', 'k', 'n', 'o', 'w', 'n', '\0'}};

static G3DEndian                                _machineEndian      = G3D_LITTLE_ENDIAN;
static char                                     _cpuArchCstr[1024];
static char                                     _operatingSystemCstr[1024];

#ifdef G3D_WIN32
/** Used by getTick() for timing */
static LARGE_INTEGER                            _start;
static LARGE_INTEGER                            _counterFrequency;
#else
static struct timeval                           _start;
#endif

static char                                     versionCstr[1024];
System::OutOfMemoryCallback                     System::outOfMemoryCallback = NULL;

#ifdef G3D_OSX
long											System::m_OSXCPUSpeed;
double											System::m_secondsPerNS;
#endif

/** The Real-World time of System::getTick() time 0.  Set by initTime */
static RealTime             realWorldGetTickTime0;


static unsigned int      maxSupportedCPUIDLevel = 0;
static unsigned int      maxSupportedExtendedLevel = 0;

/** Checks if the CPUID command is available on the processor (called from init) */
static void checkForCPUID();

/** ReadRead the standard processor extensions.  Called from init(). */
static void getStandardProcessorExtensions();

/** Called from init */
static void initTime();


std::string System::findDataFile
(const std::string&  full,
 bool                errorIfNotFound) {

    if (fileExists(full)) {
        return full;
    }

    std::string initialAppDataDir(g_appDataDir);

    std::string name = filenameBaseExt(full);
    std::string originalPath = filenamePath(full);

    // Search several paths
    Array<std::string> pathBase;

    int backlen = 4;

    // add what should be the current working directory
    pathBase.append("");

    // add application specified data directory to be searched first
    pathBase.append(initialAppDataDir);

    // try walking back along the directory tree
    std::string prev = "";
    for (int i = 0; i < backlen; ++i) {
        pathBase.append(originalPath + prev);
        prev = prev + "../";        
    }

    prev = "../";
    for (int i = 0; i < backlen; ++i) {
        pathBase.append(prev);
        prev = prev + "../";        
    }

    // Hard-code in likely install directories
    int ver = G3D_VER;
    std::string lname = format("G3D-%d.%02d", ver / 10000, (ver / 100) % 100);

    if (G3D_VER % 100 != 0) {
        lname = lname + format("-b%02d/", ver % 100);
    } else {
        lname = lname + "/";
    }

    // Look in some other likely places
#   ifdef G3D_WIN32
        std::string lpath = "libraries/G3D/";
        pathBase.append(std::string("c:/") + lpath);
        pathBase.append(std::string("d:/") + lpath);
        pathBase.append(std::string("e:/") + lpath);
        pathBase.append(std::string("f:/") + lpath);
        pathBase.append(std::string("g:/") + lpath);
        pathBase.append(std::string("x:/") + lpath);
#   endif
#   if defined(G3D_LINUX)
        pathBase.append("/usr/local/");
        pathBase.append("/course/cs224/");
        pathBase.append("/map/gfx0/common/games/");
#   endif
#   if defined(G3D_FREEBSD)
        pathBase.append("/usr/local/");
        pathBase.append("/usr/local/371/");
        pathBase.append("/usr/cs-local/371/");
#   endif
#   if defined(G3D_OSX)
        pathBase.append("/usr/local/" + lname);
        pathBase.append("/Volumes/McGuire/Projects/");
#   endif

    // Add the library name to all variations
    int N = pathBase.size();
    for (int i = 0; i < N; ++i) {
        pathBase.append(pathBase[i] + lname);
        pathBase.append(pathBase[i] + "G3D/");
    }

    Array<std::string> subDir;
    subDir.append("", "font/", "sky/", "gui/");
    subDir.append("image/", "quake2/", "quake2/players/");
    subDir.append("quake3/", "SuperShader/", "ifs/", "3ds/");
    subDir.append("quake2/speedway/");

    Array<std::string> path;
    for (int p = 0; p < pathBase.size(); ++p) {
        for (int s = 0; s < subDir.size(); ++s) {
            path.append(pathBase[p] + subDir[s]);
            path.append(pathBase[p] + "data/" + subDir[s]);
            path.append(pathBase[p] + "data-files/" + subDir[s]);
        }
    }

    for (int i = 0; i < path.length(); ++i) {
        std::string filename = path[i] + name;
        if (fileExists(filename)) {
            logPrintf("\nWARNING: Could not find '%s' so '%s' "
                      "was substituted.\n", full.c_str(), 
                      filename.c_str());
            return filename;
        }
    }

    if (errorIfNotFound) {
        // Generate an error message
        std::string locations;
        for (int i = 0; i < path.size(); ++i) {
            locations += path[i] + name + "\n";
        }
        alwaysAssertM(false, "Could not find '" + full + "' in:\n" + locations);
    }
    // Not found
    return "";
}


void System::setAppDataDir(const std::string& path) {
    // just copy the path, it needs to be valid
    strncpy(g_appDataDir, path.c_str(), sizeof(g_appDataDir));
}


std::string demoFindData(bool errorIfNotFound) {
    // Directories that might contain the data
    Array<std::string> potential;

    // Look back up the directory tree
    std::string x = "../";
    std::string f = "";
    for (int i = 0; i < 6; ++i) {
        potential.append(f);
        f = f + x;
    }
    
    // Hard-code in likely install directories
    int ver = G3D_VER;
    std::string lname = format("G3D-%d.%02d", ver / 10000, (ver / 100) % 100);

    if (G3D_VER % 100 != 0) {
        lname = lname + format("-b%02d/", ver % 100);
    } else {
        lname = lname + "/";
    }

    std::string lpath = "libraries/" + lname;
    #ifdef G3D_WIN32
        potential.append(std::string("c:/") + lpath);
        potential.append(std::string("d:/") + lpath);
        potential.append(std::string("e:/") + lpath);
        potential.append(std::string("f:/") + lpath);
        potential.append(std::string("g:/") + lpath);
        potential.append(std::string("x:/") + lpath);
    #elif defined(G3D_LINUX)
        potential.append("/usr/local/" + lname);
        potential.append("/course/cs224/");
        potential.append("/map/gfx0/common/games/");
    #elif defined(G3D_FREEBSD)
        potential.append("/usr/local/" + lname);
	potential.append("/usr/local/371/")
	potential.append("/usr/cs-local/371/")
    #elif defined(G3D_OSX)
        potential.append("/usr/local/" + lname);
        potential.append("/Volumes/McGuire/Projects/");
        potential.append("/Volumes/McGuire/Projects/G3D/");
    #endif

    // Scan all potentials for the font directory
    for (int p = 0; p < potential.size();  ++p) {
        std::string path = potential[p];
        //debugPrintf("Looking at: %sdata\n", path.c_str());
        if (fileExists(path + "data") && fileExists(path + "data/font")) {
            return path + "data/";
        }
        if (fileExists(path + "data-files") && fileExists(path + "data-files/font")) {
            return path + "data-files/";
        }
    }

    if (errorIfNotFound) {
        const char* choice[] = {"Exit"};

        prompt("Demo Error", "The demo could not locate the data directory.  "
            "The data is required to run this demo.  If you have not downloaded "
            "the data zipfile, get it from http://g3d-cpp.sf.net.  If you have "
            "downloaded it, it needs to be no more than 4 directories above the "
            "demo directory.", choice, 1, true);
    }

    return "";
}

bool System::hasCPUID() {
    init();
    return g_cpuInfo.m_hasCPUID;
}

bool System::hasRDTSC() {
    init();
    return g_cpuInfo.m_hasRDTSC;
}


bool System::hasSSE() {
    init();
    return g_cpuInfo.m_hasSSE;
}


bool System::hasSSE2() {
    init();
    return g_cpuInfo.m_hasSSE2;
}

bool System::hasSSE3() {
	init();
    return g_cpuInfo.m_hasSSE3;
}

bool System::hasMMX() {
    init();
    return g_cpuInfo.m_hasMMX;
}


bool System::has3DNow() {
    init();
    return g_cpuInfo.m_has3DNOW;
}


const std::string& System::cpuVendor() {
    init();
    static const std::string _cpuVendor = g_cpuInfo.m_cpuVendorStr;
    return _cpuVendor;
}


G3DEndian System::machineEndian() {
    init();
    return _machineEndian;
}

const std::string& System::operatingSystem() {
    init();
    static const std::string _operatingSystem =_operatingSystemCstr;
    return _operatingSystem;
}
        

const std::string& System::cpuArchitecture() {
    init();
    static const std::string _cpuArch = _cpuArchCstr;
    return _cpuArch;
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

const std::string& System::version() {
    init();

    static const std::string _version = versionCstr;
    return _version;
}


void System::init() {
    // Cannot use most G3D data structures or utility functions in here because
    // they are not initialized.

    static bool initialized = false;

    if (initialized) {
        return;
    }

    initialized = true;

    if ((G3D_VER % 100) != 0) {
        sprintf(versionCstr, "G3D %d.%02d beta %d",
            G3D_VER / 10000,
            (G3D_VER / 100) % 100,
            G3D_VER % 100);
    } else {
        sprintf(versionCstr, "G3D %d.%02d",
            G3D_VER / 10000,
            (G3D_VER / 100) % 100);
    }

    // First of all we check if the CPUID command is available
    checkForCPUID();

    // Figure out if this machine is little or big endian.
    {
        int32 a = 1;
        if (*(uint8*)&a == 1) {
            _machineEndian = G3D_LITTLE_ENDIAN;
        } else {
            _machineEndian = G3D_BIG_ENDIAN;
        }
    }

#   ifdef G3D_NOT_OSX_PPC
    // Process the CPUID information
    if (g_cpuInfo.m_hasCPUID) {
        // We read the standard CPUID level 0x00000000 which should
        // be available on every x86 processor.  This fills out
        // a string with the processor vendor tag.
        unsigned int eaxreg = 0, ebxreg = 0, ecxreg = 0, edxreg = 0;

        CALL_CPUID(0x00, eaxreg, ebxreg, ecxreg, edxreg);

        // Then we connect the single register values to the vendor string
        *((unsigned int*) g_cpuInfo.m_cpuVendorStr)         = ebxreg;
        *((unsigned int*) (g_cpuInfo.m_cpuVendorStr + 4))   = edxreg;
        *((unsigned int*) (g_cpuInfo.m_cpuVendorStr + 8))   = ecxreg;
        g_cpuInfo.m_cpuVendorStr[12] = '\0';

        // We can also read the max. supported standard CPUID level
        maxSupportedCPUIDLevel = eaxreg & 0xFFFF;

        // Then we read the ext. CPUID level 0x80000000
        CALL_CPUID(0x80000000, eaxreg, ebxreg, ecxreg, edxreg);

        // ...to check the max. supported extended CPUID level
        maxSupportedExtendedLevel = eaxreg;

        // Then we switch to the specific processor vendors.
        // Fill out _cpuArch based on this information.  It will
        // be overwritten by the next block of code on Windows,
        // but on Linux will stand.
        switch (ebxreg) {
        case 0x756E6547:        // GenuineIntel
            strcpy(_cpuArchCstr, "Intel Processor");
            break;
            
        case 0x68747541:        // AuthenticAMD
            strcpy(_cpuArchCstr, "AMD Processor");
            break;

        case 0x69727943:        // CyrixInstead
            strcpy(_cpuArchCstr, "Cyrix Processor");
            break;

        default:
            strcpy(_cpuArchCstr, "Unknown Processor Vendor");
            break;
        }
    }
    #endif // G3D_NOT_OSX_PPC

    #ifdef G3D_WIN32
        bool success = RegistryUtil::readInt32
            ("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", "~MHz", g_cpuInfo.m_cpuSpeed);

        SYSTEM_INFO systemInfo;
        GetSystemInfo(&systemInfo);
        char* arch;
        switch (systemInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_INTEL:
            arch = "Intel";
            break;
    
        case PROCESSOR_ARCHITECTURE_MIPS:
            arch = "MIPS";
            break;

        case PROCESSOR_ARCHITECTURE_ALPHA:
            arch = "Alpha";
            break;

        case PROCESSOR_ARCHITECTURE_PPC:
            arch = "Power PC";
            break;

        default:
            arch = "Unknown";
        }

        uint32 maxAddr = (uint32)systemInfo.lpMaximumApplicationAddress;
        sprintf(_cpuArchCstr, "%d x %d-bit %s processor",
                    systemInfo.dwNumberOfProcessors,
                    (int)(::log((double)maxAddr) / ::log(2.0) + 2.0),
                    arch);
                   //                    _CPUSpeed / (1024.0 * 1024));

        OSVERSIONINFO osVersionInfo;
        osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
        success = GetVersionEx(&osVersionInfo) != 0;

        if (success) {
            sprintf(_operatingSystemCstr, "Windows %d.%d build %d Platform %d %s",
                osVersionInfo.dwMajorVersion, 
                osVersionInfo.dwMinorVersion,
                osVersionInfo.dwBuildNumber,
                osVersionInfo.dwPlatformId,
                osVersionInfo.szCSDVersion);
        } else {
            strcpy(_operatingSystemCstr, "Windows");
        }
    
    #elif defined(G3D_LINUX)

        {
            // Shell out to the 'uname' command
            FILE* f = popen("uname -a", "r");

            int len = 100;
            char* r = (char*)::malloc(len * sizeof(char));
            fgets(r, len, f);
            // Remove trailing newline
            if (r[strlen(r) - 1] == '\n') {
                r[strlen(r) - 1] = '\0';
            }
            fclose(f);

            strcpy(_operatingSystemCstr, r);
            ::free(r);
        }

    #elif defined(G3D_OSX)

        // Operating System:
        SInt32 macVersion;
        Gestalt(gestaltSystemVersion, &macVersion);

        int major = (macVersion >> 8) & 0xFF;
        int minor = (macVersion >> 4) & 0xF;
        int revision = macVersion & 0xF;

        sprintf(_operatingSystemCstr, "OS X %x.%x.%x", major, minor, revision); 
                 
        // Clock Cycle Timing Information:
        Gestalt('pclk', &System::m_OSXCPUSpeed);
        g_cpuInfo.m_cpuSpeed = iRound((double)m_OSXCPUSpeed / (1024 * 1024));
        m_secondsPerNS = 1.0 / 1.0e9;
        
        // System Architecture:
	const NXArchInfo* pInfo = NXGetLocalArchInfo();
		
	if (pInfo) {
	    strcpy(_cpuArchCstr, pInfo->description);
			
	    switch (pInfo->cputype) {
	    case CPU_TYPE_POWERPC:
	        switch(pInfo->cpusubtype){
		case CPU_SUBTYPE_POWERPC_750:
		case CPU_SUBTYPE_POWERPC_7400:
		case CPU_SUBTYPE_POWERPC_7450:
		    strcpy(g_cpuInfo.m_cpuVendorStr, "Motorola");
		    break;
		case CPU_SUBTYPE_POWERPC_970:
		    strcpy(g_cpuInfo.m_cpuVendorStr, "IBM");
		    break;
		}
		break;
	    
	        case CPU_TYPE_I386:
		    strcpy(g_cpuInfo.m_cpuVendorStr, "Intel");
		    break;
	    }
	}
    #endif

    initTime();

    getStandardProcessorExtensions();
}

static void checkForCPUID() {
    unsigned int bitChanged = 0;

    // We've to check if we can toggle the flag register bit 21.
    // If we can't the processor does not support the CPUID command.
    
#if defined(_MSC_VER)
    __asm {
        push eax
        push ebx
        pushfd
        pushfd
        pop   eax
        mov   ebx, eax
        xor   eax, 0x00200000 
        push  eax
        popfd
        pushfd
        pop   eax
        popfd
        xor   eax, ebx 
        mov   bitChanged, eax
        pop ebx
        pop eax
    }
#elif defined(__GNUC__) && defined(i386) && !defined(G3D_OSX_INTEL)
    // 32-bit g++
    __asm__ (
        "pushfl                      # Get original EFLAGS             \n"
        "pushfl                                                        \n"
        "popl    %%eax                                                 \n"
        "movl    %%eax, %%ecx                                          \n"
        "xorl    $0x200000, %%eax    # Flip ID bit in EFLAGS           \n"
        "pushl   %%eax               # Save new EFLAGS value on stack  \n"
        "popfl                       # Replace current EFLAGS value    \n"
        "pushfl                      # Get new EFLAGS                  \n"
        "popl    %%eax               # Store new EFLAGS in EAX         \n"
        "popfl                                                         \n"
        "xorl    %%ecx, %%eax        # Can not toggle ID bit,          \n"
        "movl    %%eax, %0           # We have CPUID support           \n"
        : "=m" (bitChanged)
        : // No inputs
        : "%eax", "%ecx"
    );
#elif defined(__GNUC__) && defined(__x86_64__) && !defined(G3D_OSX_INTEL)
    // x86_64 has SSE and CPUID

    bitChanged = 1;
#else 
    // Unknown architecture
    bitChanged = 0;
#endif

    g_cpuInfo.m_hasCPUID = ((bitChanged == 0) ? false : true);
}

void getStandardProcessorExtensions() {
#if !defined(G3D_OSX) || defined(G3D_OSX_INTEL)
    if (! g_cpuInfo.m_hasCPUID) {
        return;
    }

    unsigned int eaxreg = 0, ebxreg = 0, ecxreg = 0;
    unsigned int features = 0;

    // http://www.amd.com/us-en/assets/content_type/white_papers_and_tech_docs/25481.pdf
    // call cpuid with function 0x01 in EAX

    // Invoking CPUID with '1' in EAX fills out edx with a bit string.
    // The bits of this value indicate the presence or absence of 
    // useful processor features.
    CALL_CPUID(0x01, eaxreg, ebxreg, ecxreg, features);

    #define checkBit(var, bit)   ((var & (1 << bit)) ? true : false)

    g_cpuInfo.m_hasRDTSC    = checkBit(features, 16);
    g_cpuInfo.m_hasMMX      = checkBit(features, 23);
    g_cpuInfo.m_hasSSE      = checkBit(features, 25);
    g_cpuInfo.m_hasSSE2     = checkBit(features, 26);
    g_cpuInfo.m_hasSSE3     = checkBit(ecxreg, 0);

    if (maxSupportedExtendedLevel >= 0x80000001) {
        // function 0x80000001 changes bit 31 of edx to 3dnow support flag
        CALL_CPUID(0x80000001, eaxreg, ebxreg, ecxreg, features);
        g_cpuInfo.m_has3DNOW = checkBit(features, 31);
    } else {
        g_cpuInfo.m_has3DNOW = false;
    }

    #undef checkBit
#endif
}

#if defined(SSE)

// Copy in 128 bytes chunks, where each chunk contains 8*float32x4 = 8 * 4 * 4 bytes = 128 bytes
//
//
void memcpySSE2(void* dst, const void* src, int nbytes) {
    int remainingBytes = nbytes;

    if (nbytes > 128) {

        // Number of chunks
        int N = nbytes / 128;

        float* restrict d = (float*)dst;
        const float* restrict s = (const float*)src;
    
        // Finish when the destination pointer has moved 8N elements 
        float* stop = d + (N * 8 * 4);

        while (d < stop) {
            // Inner loop unrolled 8 times
            const __m128 r0 = _mm_loadu_ps(s);
            const __m128 r1 = _mm_loadu_ps(s + 4);
            const __m128 r2 = _mm_loadu_ps(s + 8);
            const __m128 r3 = _mm_loadu_ps(s + 12);
            const __m128 r4 = _mm_loadu_ps(s + 16);
            const __m128 r5 = _mm_loadu_ps(s + 20);
            const __m128 r6 = _mm_loadu_ps(s + 24);
            const __m128 r7 = _mm_loadu_ps(s + 28);

            _mm_storeu_ps(d, r0);
            _mm_storeu_ps(d + 4, r1);
            _mm_storeu_ps(d + 8, r2);
            _mm_storeu_ps(d + 12, r3);
            _mm_storeu_ps(d + 16, r4);
            _mm_storeu_ps(d + 20, r5);
            _mm_storeu_ps(d + 24, r6);
            _mm_storeu_ps(d + 28, r7);

            s += 32;
            d += 32;
        }

        remainingBytes -= N * 8 * 4 * 4; 
    }

    if (remainingBytes > 0) {
        // Memcpy the rest
        memcpy((uint8*)dst + (nbytes - remainingBytes), (const uint8*)src + (nbytes - remainingBytes), remainingBytes); 
    }
}
#else

    // Fall back to memcpy
    void memcpySSE2(void *dst, const void *src, int nbytes) {
        memcpy(dst, src, nbytes);
    }

#endif

#if defined(G3D_WIN32) && defined(SSE)
/** Michael Herf's fast memcpy */
void memcpyMMX(void* dst, const void* src, int nbytes) {
    int remainingBytes = nbytes;

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
        memcpy((uint8*)dst + (nbytes - remainingBytes), (const uint8*)src + (nbytes - remainingBytes), remainingBytes); 
    }
}

#else
    // Fall back to memcpy
    void memcpyMMX(void *dst, const void *src, int nbytes) {
        memcpy(dst, src, nbytes);
    }

#endif


void System::memcpy(void* dst, const void* src, size_t numBytes) {
    if (System::hasSSE2() && System::hasMMX()) {
        G3D::memcpyMMX(dst, src, numBytes);
    } else if (System::hasSSE() && System::hasMMX()) {
        G3D::memcpyMMX(dst, src, numBytes);
    } else {
        ::memcpy(dst, src, numBytes);
    }
}


/** Michael Herf's fastest memset. n32 must be filled with the same
    character repeated. */
#if defined(G3D_WIN32) && defined(SSE)

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

#else

// For non x86 processors, we fall back to the standard memset
void memfill(void *dst, int n32, unsigned long i) {
    ::memset(dst, n32, i);
}

#endif


void System::memset(void* dst, uint8 value, size_t numBytes) {
    if (System::hasSSE() && System::hasMMX()) {
        uint32 v = value;
        v = v + (v << 8) + (v << 16) + (v << 24); 
        G3D::memfill(dst, v, numBytes);
    } else {
        ::memset(dst, value, numBytes);
    }
}


std::string& System::appName() {
    static std::string n = filenameBase(currentProgramFilename());
    return n;
}


std::string System::currentProgramFilename() {
    char filename[2048];

    #ifdef G3D_WIN32
    {
        GetModuleFileNameA(NULL, filename, sizeof(filename));
    } 
    #else
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

    // Overhead of calling this function.
    static const RealTime OVERHEAD = .000006;

    RealTime now = time();
    RealTime wakeupTime = now + t - OVERHEAD;

    RealTime remainingTime = wakeupTime - now;
    RealTime sleepTime = 0;

    while (remainingTime > 0) {
        

        if (remainingTime > 0.001) {
            // Safe to use Sleep with a time... sleep for half the remaining time
            sleepTime = max(remainingTime * .5, 0.0005);
        } else if (remainingTime > 0.0001) {
            // Safe to use Sleep with a zero time;
            // causes the program to yield only
            // the current time slice, and then return.
            sleepTime = 0;
        } else {
            // Not safe to use Sleep; busy wait
            sleepTime = -1;
        }

        if (sleepTime >= 0) {
            #ifdef G3D_WIN32
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
    #ifdef G3D_WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


bool System::consoleKeyPressed() {
    #ifdef G3D_WIN32
    
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
    #ifdef G3D_WIN32
        return _getch();
    #else
        char c;
        read(0, &c, 1);
        return c;
    #endif
}


void initTime() {
    #ifdef G3D_WIN32
        if (QueryPerformanceFrequency(&_counterFrequency)) {
            QueryPerformanceCounter(&_start);
        }

        struct _timeb t;
        _ftime(&t);

        realWorldGetTickTime0 = (RealTime)t.time - t.timezone * G3D::MINUTE + (t.dstflag ? G3D::HOUR : 0);

    #else
        gettimeofday(&_start, NULL);
        // "sse" = "seconds since epoch".  The time
        // function returns the seconds since the epoch
        // GMT (perhaps more correctly called UTC). 
        time_t gmt = time(NULL);
        
        // No call to free or delete is needed, but subsequent
        // calls to asctime, ctime, mktime, etc. might overwrite
        // local_time_vals. 
        tm* localTimeVals = localtime(&gmt);
    
        time_t local = gmt;
        
        if (localTimeVals) {
            // tm_gmtoff is already corrected for daylight savings.
            local = local + localTimeVals->tm_gmtoff;
        }
        
        realWorldGetTickTime0 = local;
    #endif
}


RealTime System::time() { 
    init();
    #ifdef G3D_WIN32
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);

        return ((RealTime)(now.QuadPart - _start.QuadPart) /
                _counterFrequency.QuadPart) + realWorldGetTickTime0;
    #else
        // Linux resolution defaults to 100Hz.
        // There is no need to do a separate RDTSC call as gettimeofday
        // actually uses RDTSC when on systems that support it, otherwise
        // it uses the system clock.
        struct timeval now;
        gettimeofday(&now, NULL);

        return (now.tv_sec  - _start.tv_sec) +
               (now.tv_usec - _start.tv_usec) / 1e6
			    + realWorldGetTickTime0;
    #endif
}


////////////////////////////////////////////////////////////////

#define REALPTR_TO_USERPTR(x)   ((uint8*)(x) + sizeof (void *))
#define USERPTR_TO_REALPTR(x)   ((uint8*)(x) - sizeof (void *))
#define REALBLOCK_SIZE(x)       ((x) + sizeof (void *))

class BufferPool {
public:

    /** Only store buffers up to these sizes (in bytes) in each pool->
        Different pools have different management strategies.

        A large block is preallocated for tiny buffers; they are used with
        tremendous frequency.  Other buffers are allocated as demanded.
        Tiny buffers are 128 bytes long because that seems to align well with
        cache sizes on many machines.
      */
    enum {tinyBufferSize = 128, smallBufferSize = 1024, medBufferSize = 4096};

    /** 
       Most buffers we're allowed to store.
       128000 * 128  = 16 MB (preallocated)
         2048 * 1024 =  2 MB (allocated on demand)
         1024 * 4096 =  4 MB (allocated on demand)
     */
    enum {maxTinyBuffers = 128000, maxSmallBuffers = 2048, maxMedBuffers = 1024};

private:

    class MemBlock {
    public:
        void*           ptr;
        size_t          bytes;

        inline MemBlock() : ptr(NULL), bytes(0) {}
        inline MemBlock(void* p, size_t b) : ptr(p), bytes(b) {}
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

#   ifdef G3D_WIN32
    CRITICAL_SECTION    mutex;
#   else
    pthread_mutex_t     mutex;
#   endif

    /** Provide synchronization between threads */
    void lock() {
#       ifdef G3D_WIN32
            EnterCriticalSection(&mutex);
#       else
            pthread_mutex_lock(&mutex);
#       endif
    }

    void unlock() {
#       ifdef G3D_WIN32
            LeaveCriticalSection(&mutex);
#       else
            pthread_mutex_unlock(&mutex);
#       endif
    }

    /** 
     Malloc out of the tiny heap. Returns NULL if allocation failed.
     */
    inline void* tinyMalloc(size_t bytes) {
        // Note that we ignore the actual byte size
        // and create a constant size block.
        (void)bytes;
        assert(tinyBufferSize >= bytes);

        void* ptr = NULL;

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
    bool inTinyHeap(void* ptr) {
        return 
            (ptr >= tinyHeap) && 
            (ptr < (uint8*)tinyHeap + maxTinyBuffers * tinyBufferSize);
    }

    void tinyFree(void* ptr) {
        assert(ptr);
        assert(tinyPoolSize < maxTinyBuffers);
 //           "Tried to free a tiny pool buffer when the tiny pool freelist is full.");

#       ifdef G3D_DEBUG
            if (tinyPoolSize > 0) {
                void* prevOnHeap = tinyPool[tinyPoolSize - 1];
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
            ::free(pool[i].ptr);
            pool[i].ptr = NULL;
            pool[i].bytes = 0;
        }
        poolSize = 0;
    }


    /**  Allocate out of a specific pool->  Return NULL if no suitable 
         memory was found. 
    
         */
    void* malloc(MemBlock* pool, int& poolSize, size_t bytes) {

        // OPT: find the smallest block that satisfies the request.

        // See if there's something we can use in the buffer pool->
        // Search backwards since usually we'll re-use the last one.
        for (int i = (int)poolSize - 1; i >= 0; --i) {
            if (pool[i].bytes >= bytes) {
                // We found a suitable entry in the pool->

                // No need to offset the pointer; it is already offset
                void* ptr = pool[i].ptr;

                // Remove this element from the pool
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
    volatile int bytesAllocated;

    BufferPool() {
        totalMallocs         = 0;

        mallocsFromTinyPool  = 0;
        mallocsFromSmallPool = 0;
        mallocsFromMedPool   = 0;

        bytesAllocated       = true;

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

#       ifdef G3D_WIN32
            InitializeCriticalSection(&mutex);
#       else
            pthread_mutex_init(&mutex, NULL);
#       endif
    }


    ~BufferPool() {
        ::free(tinyHeap);
#       ifdef G3D_WIN32
            DeleteCriticalSection(&mutex);
#       else
            // No destruction on pthreads
#       endif
    }

    
    void* realloc(void* ptr, size_t bytes) {
        if (ptr == NULL) {
            return malloc(bytes);
        }

        if (inTinyHeap(ptr)) {
            if (bytes <= tinyBufferSize) {
                // The old pointer actually had enough space.
                return ptr;
            } else {
                // Free the old pointer and malloc
                
                void* newPtr = malloc(bytes);
                System::memcpy(newPtr, ptr, tinyBufferSize);
                tinyFree(ptr);
                return newPtr;

            }
        } else {
            // In one of our heaps.

            // See how big the block really was
            size_t realSize = *(uint32*)USERPTR_TO_REALPTR(ptr);
            if (bytes <= realSize) {
                // The old block was big enough.
                return ptr;
            }

            // Need to reallocate
            void* newPtr = malloc(bytes);
            System::memcpy(newPtr, ptr, realSize);
            free(ptr);
            return newPtr;
        }
    }


    void* malloc(size_t bytes) {
        lock();
        ++totalMallocs;

        if (bytes <= tinyBufferSize) {

            void* ptr = tinyMalloc(bytes);

            if (ptr) {
                ++mallocsFromTinyPool;
                unlock();
                return ptr;
            }

        } 
        
        // Failure to allocate a tiny buffer is allowed to flow
        // through to a small buffer
        if (bytes <= smallBufferSize) {
            
            void* ptr = malloc(smallPool, smallPoolSize, bytes);

            if (ptr) {
                ++mallocsFromSmallPool;
                unlock();
                return ptr;
            }

        } else if (bytes <= medBufferSize) {
            // Note that a small allocation failure does *not* fall
            // through into a medium allocation because that would
            // waste the medium buffer's resources.

            void* ptr = malloc(medPool, medPoolSize, bytes);

            if (ptr) {
                ++mallocsFromMedPool;
                unlock();
                debugAssertM(ptr != NULL, "BufferPool::malloc returned NULL");
                return ptr;
            }
        }

        bytesAllocated += REALBLOCK_SIZE(bytes);
        unlock();

        // Heap allocate

        // Allocate 4 extra bytes for our size header (unfortunate,
        // since malloc already added its own header).
        void* ptr = ::malloc(REALBLOCK_SIZE(bytes));

        if (ptr == NULL) {
            // Flush memory pools to try and recover space
            flushPool(smallPool, smallPoolSize);
            flushPool(medPool, medPoolSize);
            ptr = ::malloc(REALBLOCK_SIZE(bytes));
        }

        if (ptr == NULL) {
            if ((System::outOfMemoryCallback != NULL) &&
                (System::outOfMemoryCallback(REALBLOCK_SIZE(bytes), true) == true)) {
                // Re-attempt the malloc
                ptr = ::malloc(REALBLOCK_SIZE(bytes));
            }
        }

        if (ptr == NULL) {
            if (System::outOfMemoryCallback != NULL) {
                // Notify the application
                System::outOfMemoryCallback(REALBLOCK_SIZE(bytes), false);
            }
#           ifdef G3D_DEBUG
                debugPrintf("::malloc(%d) returned NULL\n", REALBLOCK_SIZE(bytes));
#           endif
            debugAssertM(ptr != NULL, 
                         "::malloc returned NULL. Either the "
                         "operating system is out of memory or the "
                         "heap is corrupt.");
            return NULL;
        }

        *(uint32*)ptr = bytes;

        return REALPTR_TO_USERPTR(ptr);
    }


    void free(void* ptr) {
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

        uint32 bytes = *(uint32*)USERPTR_TO_REALPTR(ptr);

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
        bytesAllocated -= REALBLOCK_SIZE(bytes);
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

    alwaysAssertM(isPow2(alignment), "alignment must be a power of 2");

    // We must align to at least a word boundary.
    alignment = iMax(alignment, sizeof(void *));

    // Pad the allocation size with the alignment size and the
    // size of the redirect pointer.
    size_t totalBytes = bytes + alignment + sizeof(void*);

    size_t truePtr = (size_t)System::malloc(totalBytes);

    if (truePtr == 0) {
        // malloc returned NULL
        return NULL;
    }

    debugAssert(isValidHeapPointer((void*)truePtr));
    #ifdef G3D_WIN32
    // The blocks we return will not be valid Win32 debug heap
    // pointers because they are offset 
    //  debugAssert(_CrtIsValidPointer((void*)truePtr, totalBytes, TRUE) );
    #endif

    // The return pointer will be the next aligned location (we must at least
    // leave space for the redirect pointer, however).
    size_t  alignedPtr = truePtr + sizeof(void*);

    // 2^n - 1 has the form 1111... in binary.
    uint32 bitMask = (alignment - 1);

    // Advance forward until we reach an aligned location.
    while ((alignedPtr & bitMask) != 0) {
        alignedPtr += sizeof(void*);
    }

    debugAssert(alignedPtr - truePtr + bytes <= totalBytes);

    // Immediately before the aligned location, write the true array location
    // so that we can free it correctly.
    size_t* redirectPtr = (size_t *)(alignedPtr - sizeof(void *));
    redirectPtr[0] = truePtr;

    debugAssert(isValidHeapPointer((void*)truePtr));

    #ifdef G3D_WIN32
        debugAssert( _CrtIsValidPointer((void*)alignedPtr, bytes, TRUE) );
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
#   ifdef G3D_WIN32
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
        var(t, "Name", System::currentProgramFilename());
        char cwd[1024];
        getcwd(cwd, 1024);
        var(t, "cwd", std::string(cwd));
    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();

    t.writeSymbols("OS", "{");
    t.writeNewline();
    t.pushIndent();
        var(t, "Name", System::operatingSystem());
    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();

    t.writeSymbols("CPU", "{");
    t.writeNewline();
    t.pushIndent();
        var(t, "Vendor", System::cpuVendor());
        var(t, "Architecture", System::cpuArchitecture());
        var(t, "hasCPUID", System::hasCPUID());
        var(t, "hasMMX", System::hasMMX());
        var(t, "hasSSE", System::hasSSE());
        var(t, "hasSSE2", System::hasSSE2());
        var(t, "hasSSE3", System::hasSSE3());
        var(t, "has3DNow", System::has3DNow());
        var(t, "hasRDTSC", System::hasRDTSC());
    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();
       
    t.writeSymbols("G3D", "{");
    t.writeNewline();
    t.pushIndent();
        var(t, "Link version", G3D_VER);
        var(t, "Compile version", System::version());
    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();
}


int System::cpuSpeedMHz() {
    return g_cpuInfo.m_cpuSpeed;
}


void System::setClipboardText(const std::string& s) {
#   ifdef G3D_WIN32
        if (OpenClipboard(NULL)) {
            HGLOBAL hMem = GlobalAlloc(GHND | GMEM_DDESHARE, s.size() + 1);
            if (hMem) {
                char *pMem = (char*)GlobalLock(hMem);
                strcpy(pMem, s.c_str());
                GlobalUnlock(hMem);

                EmptyClipboard();
                SetClipboardData(CF_TEXT, hMem);
            }

            CloseClipboard();
            GlobalFree(hMem);
        }
#   endif
}


std::string System::getClipboardText() {
    std::string s;

#   ifdef G3D_WIN32
        if (OpenClipboard(NULL)) {
            HANDLE h = GetClipboardData(CF_TEXT);

            if (h) {
                char* temp = (char*)GlobalLock(h);
                if (temp) {
    	            s = temp;
                }
                temp = NULL;
                GlobalUnlock(h);
            }
            CloseClipboard();
        }
#   endif
    return s;
}


std::string System::currentDateString() {
    time_t t1;
    ::time(&t1);
    tm* t = localtime(&t1);
    return format("%d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday); 
}


}  // namespace
