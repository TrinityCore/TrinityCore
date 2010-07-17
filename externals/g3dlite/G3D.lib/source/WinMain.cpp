/*
    Dervied from SDL_main.c, which was placed in the public domain by Sam Lantinga  4/13/98

    The WinMain function -- calls your program's main() function
*/

#include "G3D/platform.h"

#ifdef G3D_WIN32

#include <stdio.h>
#include <stdlib.h>
#include <cctype>

#ifdef main
#   ifndef _WIN32_WCE_EMULATION
#       undef main
#   endif /* _WIN32_WCE_EMULATION */
#endif /* main */

#if defined(_WIN32_WCE) && _WIN32_WCE < 300
/* seems to be undefined in Win CE although in online help */
#define isspace(a) (((CHAR)a == ' ') || ((CHAR)a == '\t'))
#endif /* _WIN32_WCE < 300 */

// Turn off the G3D for loop scoping for C++
#ifdef for
#  undef for
#endif

extern int main(int argc, const char** argv);

/* Parse a command line buffer into arguments */
static int ParseCommandLine(char *cmdline, char **argv) {
    char *bufp;
    int argc;

    argc = 0;
    for (bufp = cmdline; *bufp;) {
        /* Skip leading whitespace */
        while (isspace(*bufp)) {
            ++bufp;
        }
        /* Skip over argument */
        if (*bufp == '"') {
            ++bufp;
            if (*bufp) {
                if (argv) {
                    argv[argc] = bufp;
                }
                ++argc;
            }
            /* Skip over word */
            while (*bufp && (*bufp != '"')) {
                ++bufp;
            }
        } else {
            if (*bufp) {
                if (argv) {
                    argv[argc] = bufp;
                }
                ++argc;
            }
            /* Skip over word */
            while (*bufp && !isspace(*bufp)) {
                ++bufp;
            }
        }
        if (*bufp) {
            if (argv) {
                *bufp = '\0';
            }
            ++bufp;
        }
    }
    if (argv) {
        argv[argc] = NULL;
    }
    return (argc);
}

/* Show an error message */
static void ShowError(const char *title, const char *message) {
/* If USE_MESSAGEBOX is defined, you need to link with user32.lib */
#ifdef USE_MESSAGEBOX
    MessageBox(NULL, message, title, MB_ICONEXCLAMATION | MB_OK);
#else
    fprintf(stderr, "%s: %s\n", title, message);
#endif
}

/* Pop up an out of memory message, returns to Windows */
static BOOL OutOfMemory(void) {
    ShowError("Fatal Error", "Out of memory - aborting");
    return FALSE;
}


int WINAPI G3D_WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR szCmdLine, int sw) {
    char **argv;
    int argc;
    int status;
    char *cmdline;
#   ifdef _WIN32_WCE
        wchar_t *bufp;
        int nLen;
#   else
        char *bufp;
        size_t nLen;
#   endif

#ifdef _WIN32_WCE
#error WinCE not supported
    /*
    nLen = wcslen(szCmdLine) + 128 + 1;
    bufp = SDL_stack_alloc(wchar_t, nLen * 2);
    wcscpy(bufp, TEXT("\""));
    GetModuleFileName(NULL, bufp + 1, 128 - 3);
    wcscpy(bufp + wcslen(bufp), TEXT("\" "));
    wcsncpy(bufp + wcslen(bufp), szCmdLine, nLen - wcslen(bufp));
    nLen = wcslen(bufp) + 1;
    cmdline = SDL_stack_alloc(char, nLen);
    if (cmdline == NULL) {
        return OutOfMemory();
    }
    WideCharToMultiByte(CP_ACP, 0, bufp, -1, cmdline, nLen, NULL, NULL);
    */
#else
    /* Grab the command line */
    bufp = GetCommandLineA();
    nLen = strlen(bufp) + 1;
    cmdline = (char*)malloc(sizeof(char) * nLen);
    if (cmdline == NULL) {
        return OutOfMemory();
    }
    strncpy(cmdline, bufp, nLen);
#endif

    /* Parse it into argv and argc */
    argc = ParseCommandLine(cmdline, NULL);
    argv = (char**)malloc(sizeof(char*) * (argc + 1));
    if (argv == NULL) {
        return OutOfMemory();
    }
    ParseCommandLine(cmdline, argv);

    /* Run the main program */
    status = main(argc, (const char**)argv);
    free(argv);
    free(cmdline);

    return status;
}

#endif // if Win32
