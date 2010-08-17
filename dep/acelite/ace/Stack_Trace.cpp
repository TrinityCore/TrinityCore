//=============================================================================
/**
 *  @file   Stack_Trace.cpp
 *
 *  $Id: Stack_Trace.cpp 90041 2010-04-29 03:38:07Z cleeland $
 *
 *  @brief  Encapsulate string representation of stack trace.
 *
 *  Some platform-specific areas of this code have been adapted from
 *  examples found elsewhere.  Specifically,
 *  - the GLIBC stack generation uses the documented "backtrace" API
 *    and is adapted from examples shown in relevant documentation
 *    and repeated elsewhere, e.g.,
 *    http://www.linuxselfhelp.com/gnu/glibc/html_chapter/libc_33.html
 *  - the Solaris stack generation is adapted from a 1995 post on
 *    comp.unix.solaris by Bart Smaalders,
 *    http://groups.google.com/group/comp.unix.solaris/browse_thread/thread/8b9f3de8be288f1c/31550f93a48231d5?lnk=gst&q=how+to+get+stack+trace+on+solaris+group:comp.unix.solaris#31550f93a48231d5
 *  - VxWorks kernel-mode stack tracing is adapted from a code example
 *    in the VxWorks FAQ at http://www.xs4all.nl/~borkhuis/vxworks/vxw_pt5.html
 *    although the undocumented functions it uses are also mentioned in
 *    various documents available on the WindRiver support website.
 *
 *  If you add support for a new platform, please add a bullet to the
 *  above list with durable references to the origins of your code.
 *    
 */
//=============================================================================

#include "ace/Stack_Trace.h"
#include "ace/Min_Max.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_stdio.h"

ACE_RCSID (ace, Stack_Trace, "$Id: Stack_Trace.cpp 90041 2010-04-29 03:38:07Z cleeland $")

/*
  This is ugly, simply because it's very platform-specific.
*/

const char ACE_Stack_Trace::UNSUPPORTED[] = "<stack traces unsupported platform>";
const char ACE_Stack_Trace::UNABLE_TO_GET_TRACE[] = "<unable to get trace>";

ACE_Stack_Trace::ACE_Stack_Trace (ssize_t starting_frame_offset, size_t num_frames)
  : buflen_(0)
{
  // cannot initialize arrays, so we must assign.
  this->buf_[0] = '\0';
  this->generate_trace (starting_frame_offset, num_frames);
}

const char*
ACE_Stack_Trace::c_str () const
{
  return &this->buf_[0];
}

static inline size_t
determine_starting_frame (ssize_t initial_frame, ssize_t offset)
{
  return ACE_MAX( initial_frame + offset, static_cast<ssize_t>(0));
}

#if (defined(__GLIBC__) || defined(ACE_HAS_EXECINFO_H)) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
// This is the code for glibc
#  include <execinfo.h>

void
ACE_Stack_Trace::generate_trace (ssize_t starting_frame_offset, size_t num_frames)
{
  const size_t MAX_FRAMES = 128;
  const ssize_t INITIAL_FRAME = 3;

  void* stack[MAX_FRAMES];
  size_t stack_size = 0;
  char** stack_syms;

  if (num_frames == 0)
    num_frames = MAX_FRAMES;

  size_t starting_frame =
    determine_starting_frame (INITIAL_FRAME, starting_frame_offset);

  stack_size = ::backtrace (&stack[0], sizeof(stack)/sizeof(stack[0]));
  if (stack_size != 0)
    {
      stack_syms = ::backtrace_symbols (stack, stack_size);

      for (size_t i = starting_frame;
           i < stack_size && num_frames > 0;
           i++, num_frames--)
        {
          // this could be more efficient by remembering where we left off in buf_
          char *symp = &stack_syms[i][0];
          while (this->buflen_ < SYMBUFSIZ - 2 && *symp != '\0')
            {
              this->buf_[this->buflen_++] = *symp++;
            }
          this->buf_[this->buflen_++] = '\n'; // put a newline at the end
        }
      this->buf_[this->buflen_] = '\0'; // zero terminate the string

      ::free (stack_syms);
    }
  else
    {
      ACE_OS::strcpy (&this->buf_[0], UNABLE_TO_GET_TRACE);
    }
}
#elif defined(VXWORKS) && !defined(__RTP__)
#  include <trcLib.h>
#  include <taskLib.h>  // hopefully this is enough to get all the necessary #defines.

struct ACE_Stack_Trace_stackstate
{
  ACE_Stack_Trace_stackstate (char* b, size_t& bl, size_t nf, size_t sf)
    : buf(b), buflen(bl), num_frames(nf), starting_frame(sf)
  { }

  char* buf;
  size_t& buflen;
  size_t num_frames;
  size_t starting_frame;
};

//@TODO: Replace with a TSS-based pointer to avoid problems in multithreaded environs, 
//       or use a mutex to serialize access to this.
static ACE_Stack_Trace_stackstate* ACE_Stack_Trace_stateptr = 0;

static void
ACE_Stack_Trace_Add_Frame_To_Buf (INSTR *caller,
                                  unsigned int func,
                                  unsigned int nargs,
                                  unsigned int *args)
{
  if (ACE_Stack_Trace_stateptr == 0)
    return;

  ACE_Stack_Trace_stackstate *stackstate = ACE_Stack_Trace_stateptr;

  // Decrement the num_frames and starting_frame elements,
  // then see if we're ready to start or ready to finish.
  --stackstate->num_frames;
  --stackstate->starting_frame;

  if (stackstate->num_frames == 0 || stackstate->starting_frame > 0)
    return;

  // These are references so that the structure gets updated
  // in the code below.
  char*& buf = stackstate->buf;
  unsigned int& len = stackstate->buflen;

  // At some point try using symFindByValue() to lookup func (and caller?)
  // to print out symbols rather than simply addresses.

  // VxWorks can pass -1 for "nargs" if there was an error
  if (nargs == static_cast<unsigned int> (-1)) nargs = 0;

  len += ACE_OS::sprintf (&buf[len], "%#10x: %#10x (", (int)caller, func);
  for (unsigned int i = 0; i < nargs; ++i)
    {
      if (i != 0)
        len += ACE_OS::sprintf (&buf[len], ", ");
      len += ACE_OS::sprintf(&buf [len], "%#x", args [i]);
    }

  len += ACE_OS::sprintf(&buf[len], ")\n");
}

void
ACE_Stack_Trace::generate_trace (ssize_t starting_frame_offset,
                                 size_t num_frames)
{
  const size_t MAX_FRAMES = 128;
  const ssize_t INITIAL_FRAME = 3;

  if (num_frames == 0)
    num_frames = MAX_FRAMES;

  size_t starting_frame =
    determine_starting_frame (INITIAL_FRAME, starting_frame_offset);

  ACE_Stack_Trace_stackstate state (&this->buf_[0], this->buflen_,
                                    num_frames, starting_frame);

  REG_SET regs;

  taskRegsGet ((int)taskIdSelf(), &regs);
  // Maybe we should take a lock here to guard stateptr?
  ACE_Stack_Trace_stateptr = &state;
  trcStack (&regs, (FUNCPTR)ACE_Stack_Trace_Add_Frame_To_Buf, taskIdSelf ());
}


#elif defined(VXWORKS) && defined(__RTP__)
#  include <setjmp.h>
#  include <taskLib.h>
#  include <private/trcLibP.h>

// See memEdrLib.c in VxWorks RTP sources for an example of stack tracing.

static STATUS ace_vx_rtp_pc_validate (INSTR *pc, TRC_OS_CTX *pOsCtx)
{
  return ALIGNED (pc, sizeof (INSTR)) ? OK : ERROR;
}

void
ACE_Stack_Trace::generate_trace (ssize_t starting_frame_offset,
                                 size_t num_frames)
{
  const size_t MAX_FRAMES = 128;
  const ssize_t INITIAL_FRAME = 2;

  if (num_frames == 0) num_frames = MAX_FRAMES;
  size_t starting_frame =
    determine_starting_frame (INITIAL_FRAME, starting_frame_offset);

  jmp_buf regs;
  setjmp (regs);

  TASK_DESC desc;
  if (taskInfoGet (taskIdSelf (), &desc) == ERROR) return;

  TRC_OS_CTX osCtx;
  osCtx.stackBase = desc.td_pStackBase;
  osCtx.stackEnd = desc.td_pStackEnd;
  osCtx.pcValidateRtn = reinterpret_cast<FUNCPTR> (ace_vx_rtp_pc_validate);

  char *fp = _WRS_FRAMEP_FROM_JMP_BUF (regs);
  INSTR *pc = _WRS_RET_PC_FROM_JMP_BUF (regs);

  for (size_t depth = 0; depth < num_frames + starting_frame; ++depth)
    {
      char *prevFp;
      INSTR *prevPc;
      INSTR *prevFn;

      if (trcLibFuncs.lvlInfoGet (fp, pc, &osCtx, &prevFp, &prevPc, &prevFn)
          == ERROR)
        {
          ACE_OS::strcpy (this->buf_, UNABLE_TO_GET_TRACE);
          return;
        }

      if(prevPc == 0 || prevFp == 0) break;

      if (depth >= starting_frame)
        {
          //Hopefully a future version of VxWorks will have a system call
          //for an RTP to query its own symbols, but this is not possible now.
          //An enhancement request has been filed under WIND00123307.
          const char *fnName = "(no symbols)";

          static const int N_ARGS = 12;
          int buf[N_ARGS];
          int *pArgs = 0;
          int numArgs =
            trcLibFuncs.lvlArgsGet (prevPc, prevFn, prevFp,
                                    buf, N_ARGS, &pArgs);

          // VxWorks can return -1 for "numArgs" if there was an error
          if (numArgs == -1) numArgs = 0;

          size_t len = ACE_OS::strlen (this->buf_);
          size_t space = SYMBUFSIZ - len - 1;
          char *cursor = this->buf_ + len;
          size_t written = ACE_OS::snprintf (cursor, space, "%x %s",
                                             prevFn, fnName);
          cursor += written;
          space -= written;

          if (space < 1) return; //no point in logging when we're out of buffer
          for (int arg = 0; numArgs != -1 && pArgs && arg < numArgs; ++arg)
            {
              if (arg == 0) *cursor++ = '(', --space;
              written = ACE_OS::snprintf (cursor, space,
                                          (arg < numArgs - 1) ? "%x, " : "%x",
                                          pArgs[arg]);
              cursor += written;
              space -= written;
              if (space && arg == numArgs - 1) *cursor++ = ')', --space;
            }
          if (space) *cursor++ = '\n', --space;
          *cursor++ = 0; //we saved space for the null terminator
        }

      fp = prevFp;
      pc = prevPc;
    }
}

#elif defined(sun)
/*
 * walks up call stack, printing library:routine+offset for each routine
 */

#  include <dlfcn.h>
#  include <setjmp.h>
#  include <sys/types.h>
#  include <sys/reg.h>
#  include <sys/frame.h>
#  define ACE_STACK_TRACE_BIAS 0

#  if defined(sparc) || defined(__sparc)
#    define ACE_STACK_TRACE_FLUSHWIN() asm("ta 3");
#    define ACE_STACK_TRACE_FRAME_PTR_INDEX 1
#    define ACE_STACK_TRACE_SKIP_FRAMES 0
#    if defined(__sparcv9)
#      undef  ACE_STACK_TRACE_BIAS
#      define ACE_STACK_TRACE_BIAS 2047
#    endif
#  endif

#  if defined(i386) || defined(__i386)
#    define ACE_STACK_TRACE_FLUSHWIN()
#    define ACE_STACK_TRACE_FRAME_PTR_INDEX 3
#    define ACE_STACK_TRACE_SKIP_FRAMES 0
#  endif

#  if defined(__amd64) || defined(__x86_64)
#    define ACE_STACK_TRACE_FLUSHWIN()
#    define ACE_STACK_TRACE_FRAME_PTR_INDEX 5
#    define ACE_STACK_TRACE_SKIP_FRAMES 0
#  endif

#  if defined(ppc) || defined(__ppc)
#    define ACE_STACK_TRACE_FLUSHWIN()
#    define ACE_STACK_TRACE_FRAME_PTR_INDEX 0
#    define ACE_STACK_TRACE_SKIP_FRAMES 2
#  endif

static frame*
cs_frame_adjust(frame* sp)
{
  unsigned char* sp_byte = (unsigned char*)sp;
  sp_byte += ACE_STACK_TRACE_BIAS;
  return (frame*) sp_byte;
}

/*
  this function walks up call stack, calling user-supplied
  function once for each stack frame, passing the pc and the user-supplied
  usrarg as the argument.
  */

static int
cs_operate(int (*func)(void *, void *), void * usrarg,
           size_t starting_frame, size_t num_frames_arg)
{
  ACE_STACK_TRACE_FLUSHWIN();

  jmp_buf env;
  setjmp(env);
  frame* sp = cs_frame_adjust((frame*) env[ACE_STACK_TRACE_FRAME_PTR_INDEX]);

  // make a copy of num_frames_arg to eliminate the following warning on some
  // solaris platforms:
  // Stack_Trace.cpp:318: warning: argument `size_t num_frames' might be clobbered by `longjmp' or `vfork'
  size_t num_frames = num_frames_arg;

  // I would like to use ACE_MAX below rather than ?:, but
  // I get linker relocation errors such as the following when
  // I use it:
  // ld: fatal: relocation error: file: .shobj/Stack_Trace.o section:
  // .rela.debug_line symbol: : relocation against a discarded symbol,
  //         symbol is part of discarded section:
  //         .text%const __type_0&ace_max<unsig\ned>(const __type_0&,const __type_0&)
  //
  const size_t starting_skip = starting_frame - 1;
#if ACE_STACK_TRACE_SKIP_FRAMES == 0
  size_t skip_frames = starting_skip;
#else
  size_t skip_frames =
    ACE_STACK_TRACE_SKIP_FRAMES > starting_skip ?
    ACE_STACK_TRACE_SKIP_FRAMES : starting_skip;
#endif /* ACE_STACK_TRACE_SKIP_FRAMES == 0 */
  size_t i;
  for (i = 0; i < skip_frames && sp; ++i)
    {
      sp = cs_frame_adjust((frame*) sp->fr_savfp);
    }

  i = 0;

  while (    sp
          && sp->fr_savpc
          && ++i
          && --num_frames
          && (*func)((void*)sp->fr_savpc, usrarg))
    {
      sp = cs_frame_adjust((frame*) sp->fr_savfp);
    }

  return(i);
}

static int
add_frame_to_buf (void* pc, void* usrarg)
{
  char* buf = (char*)usrarg;
  Dl_info info;
  const char* func = "??";
  const char* lib = "??";

  if(dladdr(pc, & info) != 0)
    {
      lib = (const char *) info.dli_fname;
      func = (const char *) info.dli_sname;
    }

  (void) ACE_OS::snprintf(buf,
                          ACE_Stack_Trace::SYMBUFSIZ,
                          "%s%s:%s+0x%x\n",
                          buf,
                          lib,
                          func,
                          //@@ Should the arithmetic on the following
                          //line be done with two void* ptrs?  The result
                          //would be ptrdiff_t, and what is the correct
                          //sprintf() conversion character for that?
                          (size_t)pc - (size_t)info.dli_saddr);

  return(1);
}

void
ACE_Stack_Trace::generate_trace (ssize_t starting_frame_offset,
                                 size_t num_frames)
{
  const size_t MAX_FRAMES = 128;
  const ssize_t INITIAL_FRAME = 3;

  if (num_frames == 0)
    num_frames = MAX_FRAMES;

  size_t starting_frame =
    determine_starting_frame (INITIAL_FRAME, starting_frame_offset);

  cs_operate (&add_frame_to_buf, &this->buf_[0], starting_frame, num_frames);
}

#elif defined(ACE_WIN64) && (_WIN32_WINNT <= _WIN32_WINNT_WIN2K)
#  if defined(_MSC_VER)
#    define STRING2(X) #X
#    define STRING(X) STRING2(X)
#    pragma message (__FILE__ "(" STRING(__LINE__) ") : warning: stack traces"\
       " can't be generated on 64-bit Windows when _WIN32_WINNT is less than "\
       "0x501.")
#  undef STRING
#  undef STRING2
#  endif /*_MSC_VER*/
void
ACE_Stack_Trace::generate_trace (ssize_t, size_t)
{
  ACE_OS::strcpy (&this->buf_[0], "<stack traces unsupported on Win64 unless "
    "ACE is built with _WIN32_WINNT set to 0x501 or above>");
}

#elif defined(ACE_WIN32) && !defined(ACE_HAS_WINCE) && !defined (__MINGW32__) \
      && !defined(__BORLANDC__)
#  include <windows.h>
#  include <Dbghelp.h>

#  define MAXTEXT 5000
#  define SYMSIZE 100

//@TODO: Test with WCHAR
//@TODO: Need a common CriticalSection since dbghelp is not thread-safe

typedef struct _dbghelp_functions
{
  HMODULE hMod; //our handle to dbghelp.dll

  //these already have typedefs in DbgHelp.h
  DWORD64 (WINAPI *SymGetModuleBase64) (HANDLE hProc, DWORD64 dwAddr);
  PVOID (WINAPI *SymFunctionTableAccess64) (HANDLE hProc, DWORD64 AddrBase);

  typedef BOOL (WINAPI *SymFromAddr_t)
    (HANDLE hProc, DWORD64 Addr, PDWORD64 Disp, PSYMBOL_INFO Symbol);
  SymFromAddr_t SymFromAddr;

  typedef BOOL (WINAPI *SymGetLineFromAddr64_t) (HANDLE hProc, DWORD64 dwAddr,
                                                 PDWORD pdwDisplacement,
                                                 PIMAGEHLP_LINE64 Line);
  SymGetLineFromAddr64_t SymGetLineFromAddr64;

  typedef DWORD (WINAPI *SymSetOptions_t) (DWORD SymOptions);
  SymSetOptions_t SymSetOptions;

  typedef DWORD (WINAPI *SymGetOptions_t) ();
  SymGetOptions_t SymGetOptions;

  typedef BOOL (WINAPI *SymInitialize_t) (HANDLE hProc, PCTSTR UserSearchPath,
                                          BOOL invasive);
  SymInitialize_t SymInitialize;

  typedef BOOL
  (WINAPI *StackWalk64_t) (DWORD MachineType, HANDLE hPRoc, HANDLE hThr,
                           LPSTACKFRAME64 StackFrame, PVOID ContextRecord,
                           PREAD_PROCESS_MEMORY_ROUTINE64 RMRoutine,
                           PFUNCTION_TABLE_ACCESS_ROUTINE64 FTARoutine,
                           PGET_MODULE_BASE_ROUTINE64 GMBRoutine,
                           PTRANSLATE_ADDRESS_ROUTINE64 TranslateAddress);
  StackWalk64_t StackWalk64;

  typedef BOOL (WINAPI *SymCleanup_t) (HANDLE hProc);
  SymCleanup_t SymCleanup;
} dbghelp_functions;


#  pragma warning (push)
#  pragma warning (disable:4706)  
static bool load_dbghelp_library_if_needed (dbghelp_functions *pDbg)
{
  //@TODO: See codeproject's StackWalker.cpp for the list of locations to
  //search so we get the "enhanced" dbghelp if the user has it but it is not
  //first on the path.
  if (!(pDbg->hMod = ACE_TEXT_LoadLibrary (ACE_TEXT ("Dbghelp"))))
    return false;

  //@TODO: Cache this so we don't have to re-link every time.  When to unload?

#  define LINK(TYPE, NAME) (pDbg->NAME = \
    (TYPE) GetProcAddress (pDbg->hMod, #NAME))
#  define LINK_T(NAME) LINK (dbghelp_functions::NAME##_t, NAME)
  return LINK (PGET_MODULE_BASE_ROUTINE64, SymGetModuleBase64)
    && LINK (PFUNCTION_TABLE_ACCESS_ROUTINE64, SymFunctionTableAccess64)
    && LINK_T (SymFromAddr) && LINK_T (SymGetLineFromAddr64)
    && LINK_T (SymSetOptions)&& LINK_T (SymGetOptions)
    && LINK_T (SymInitialize) && LINK_T (StackWalk64) && LINK_T (SymCleanup);
#  undef LINK
#  undef LINK_T
}
#  pragma warning (pop)


struct frame_state {
  STACKFRAME64 sf;
  PSYMBOL_INFO pSym;
  dbghelp_functions *pDbg;
};

static int
add_frame_to_buf (struct frame_state const *fs, void *usrarg)
{
  if (fs == 0 || usrarg == 0)
    return -1;

  char *buf = static_cast<char *> (usrarg);

  DWORD64 disp;
  DWORD64 dwModBase = fs->pDbg->SymGetModuleBase64 (GetCurrentProcess (),
                                                    fs->sf.AddrPC.Offset);
  if (fs->pDbg->SymFromAddr (GetCurrentProcess (),
                             fs->sf.AddrPC.Offset, &disp, fs->pSym))
    {
      IMAGEHLP_LINE64 line = {sizeof (IMAGEHLP_LINE64)};
      DWORD lineDisp;
      if (fs->pDbg->SymGetLineFromAddr64 (GetCurrentProcess (),
                                          fs->sf.AddrPC.Offset,
                                          &lineDisp, &line))
        {
          (void) ACE_OS::snprintf (buf, ACE_Stack_Trace::SYMBUFSIZ,
                                   "%s%s() %s: %d + 0x%x\n",
                                   buf, fs->pSym->Name, line.FileName,
                                   line.LineNumber, lineDisp);
        }
      else
        {
          (void) ACE_OS::snprintf (buf, ACE_Stack_Trace::SYMBUFSIZ,
                                   "%s%s()+0x%x [0x%x]\n",
                                   buf, fs->pSym->Name, disp,
                                   fs->sf.AddrPC.Offset - dwModBase);
        }
    }
  else
    {
      (void) ACE_OS::snprintf (buf, ACE_Stack_Trace::SYMBUFSIZ,
                               "%s[0x%x]\n",
                               buf, fs->sf.AddrPC.Offset - dwModBase);
    }
  return 0;
}

static void emptyStack () { }

#if defined (_MSC_VER)
#  pragma warning(push)
// Suppress warning 4748 "/GS can not protect parameters and local
// variables from local buffer overrun because optimizations are
// disabled in function"
#  pragma warning(disable: 4748)
#endif /* _MSC_VER */

static int
cs_operate(int (*func)(struct frame_state const *, void *), void *usrarg,
           size_t starting_frame, size_t num_frames)
{
  dbghelp_functions dbg;
  if (!load_dbghelp_library_if_needed (&dbg))
    {
      ACE_OS::strcpy (static_cast<char *> (usrarg),
                      "<error loading dbghelp.dll>");
      if (dbg.hMod) FreeLibrary (dbg.hMod);
      return 1;
    }

  frame_state fs;
  ZeroMemory (&fs.sf, sizeof (fs.sf));
  fs.pDbg = &dbg;
  emptyStack ();   //Not sure what this should do, Chad?
  
  CONTEXT c;
  ZeroMemory (&c, sizeof (CONTEXT));
  c.ContextFlags = CONTEXT_FULL;

#  if defined (_M_IX86)
  DWORD machine = IMAGE_FILE_MACHINE_I386;
  __asm {
    call x
    x: pop eax
    mov c.Eip, eax
    mov c.Ebp, ebp
    mov c.Esp, esp
  }
  fs.sf.AddrPC.Offset = c.Eip;
  fs.sf.AddrStack.Offset = c.Esp;
  fs.sf.AddrFrame.Offset = c.Ebp;
  fs.sf.AddrPC.Mode = AddrModeFlat;
  fs.sf.AddrStack.Mode = AddrModeFlat;
  fs.sf.AddrFrame.Mode = AddrModeFlat;
#  elif defined (_M_X64)
  DWORD machine = IMAGE_FILE_MACHINE_AMD64;
  RtlCaptureContext (&c);
  fs.sf.AddrPC.Offset = c.Rip;
  fs.sf.AddrFrame.Offset = c.Rsp; //should be Rbp or Rdi instead?
  fs.sf.AddrStack.Offset = c.Rsp;
  fs.sf.AddrPC.Mode = AddrModeFlat;
  fs.sf.AddrFrame.Mode = AddrModeFlat;
  fs.sf.AddrStack.Mode = AddrModeFlat;
#  elif defined (_M_IA64)
  DWORD machine = IMAGE_FILE_MACHINE_IA64;
  RtlCaptureContext (&c);
  fs.sf.AddrPC.Offset = c.StIIP;
  fs.sf.AddrFrame.Offset = c.RsBSP;
  fs.sf.AddrBStore.Offset = c.RsBSP;
  fs.sf.AddrStack.Offset = c.IntSp;
  fs.sf.AddrPC.Mode = AddrModeFlat;
  fs.sf.AddrFrame.Mode = AddrModeFlat;
  fs.sf.AddrBStore.Mode = AddrModeFlat;
  fs.sf.AddrStack.Mode = AddrModeFlat;
#  endif

  fs.pSym = (PSYMBOL_INFO) GlobalAlloc (GMEM_FIXED,
                                        sizeof (SYMBOL_INFO) +
                                        sizeof (ACE_TCHAR) * (SYMSIZE - 1));
  fs.pSym->SizeOfStruct = sizeof (SYMBOL_INFO);
  fs.pSym->MaxNameLen = SYMSIZE * sizeof (ACE_TCHAR);
  dbg.SymSetOptions (SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES
                     | SYMOPT_FAIL_CRITICAL_ERRORS | dbg.SymGetOptions ());
  dbg.SymInitialize (GetCurrentProcess (), 0, true);
  //What does the "true" parameter mean when tracing the current process?

  for (size_t current_frame = 0; current_frame < num_frames + starting_frame;
       ++current_frame)
    {
      BOOL ok = dbg.StackWalk64 (machine,
                                 GetCurrentProcess (),
                                 GetCurrentThread (),
                                 &fs.sf, &c, 0,
                                 dbg.SymFunctionTableAccess64,
                                 dbg.SymGetModuleBase64, 0);
      if (!ok || fs.sf.AddrFrame.Offset == 0)
        break;

      if (current_frame < starting_frame)
        continue;

      func (&fs, usrarg);
    }

  dbg.SymCleanup (GetCurrentProcess ());
  GlobalFree (fs.pSym);
  FreeLibrary (dbg.hMod);

  return 0;
}

#if defined (_MSC_VER)
// Restore the warning state to what it was before entry.
#  pragma warning(pop)
#endif /* _MSC_VER */

void
ACE_Stack_Trace::generate_trace (ssize_t starting_frame_offset,
                                 size_t num_frames)
{
  const size_t MAX_FRAMES = 128;
  const ssize_t INITIAL_FRAME = 3;

  if (num_frames == 0)
    num_frames = MAX_FRAMES;

  size_t starting_frame =
    determine_starting_frame (INITIAL_FRAME, starting_frame_offset);

  cs_operate (&add_frame_to_buf, &this->buf_[0], starting_frame, num_frames);
}

#else // Unsupported platform
void
ACE_Stack_Trace::generate_trace (ssize_t, size_t)
{
// Call determine_starting_frame() on HP aCC build to resolve declared 
// method never referenced warning.
#if defined (__HP_aCC)
  size_t starting_frame = determine_starting_frame (0, 0);
#endif

  ACE_OS::strcpy (&this->buf_[0], UNSUPPORTED);
}
#endif

