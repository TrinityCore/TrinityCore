// $Id: Log_Record.cpp 81826 2008-06-02 15:29:53Z schmidt $

#include "ace/Log_Record.h"

#include "ace/Log_Msg.h"
#include "ace/ACE.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_time.h"
#include "ace/CDR_Stream.h"
#include "ace/Auto_Ptr.h"
#include "ace/Truncate.h"

#if !defined (__ACE_INLINE__)
# include "ace/Log_Record.inl"
#endif /* __ACE_INLINE__ */

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)
// FUZZ: disable check_for_streams_include
# include "ace/streams.h"
#endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */

#include "ace/OS_Memory.h"

ACE_RCSID(ace, Log_Record, "$Id: Log_Record.cpp 81826 2008-06-02 15:29:53Z schmidt $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Log_Record)

namespace
{
  // Symbolic names for the <ACE_Log_Priority> enumerators.
  ACE_TCHAR const * ace_priority_names[] =
    {
      ACE_TEXT ("LM_SHUTDOWN"),
      ACE_TEXT ("LM_TRACE"),
      ACE_TEXT ("LM_DEBUG"),
      ACE_TEXT ("LM_INFO"),
      ACE_TEXT ("LM_NOTICE"),
      ACE_TEXT ("LM_WARNING"),
      ACE_TEXT ("LM_STARTUP"),
      ACE_TEXT ("LM_ERROR"),
      ACE_TEXT ("LM_CRITICAL"),
      ACE_TEXT ("LM_ALERT"),
      ACE_TEXT ("LM_EMERGENCY"),
      ACE_TEXT ("LM_UNK(04000)"),
      ACE_TEXT ("LM_UNK(010000)"),
      ACE_TEXT ("LM_UNK(020000)"),
      ACE_TEXT ("LM_UNK(040000)"),
      ACE_TEXT ("LM_UNK(0100000)"),
      ACE_TEXT ("LM_UNK(0200000)"),
      ACE_TEXT ("LM_UNK(0400000)"),
      ACE_TEXT ("LM_UNK(01000000)"),
      ACE_TEXT ("LM_UNK(02000000)"),
      ACE_TEXT ("LM_UNK(04000000)"),
      ACE_TEXT ("LM_UNK(010000000)"),
      ACE_TEXT ("LM_UNK(020000000)"),
      ACE_TEXT ("LM_UNK(040000000)"),
      ACE_TEXT ("LM_UNK(0100000000)"),
      ACE_TEXT ("LM_UNK(0200000000)"),
      ACE_TEXT ("LM_UNK(0400000000)"),
      ACE_TEXT ("LM_UNK(01000000000)"),
      ACE_TEXT ("LM_UNK(02000000000)"),
      ACE_TEXT ("LM_UNK(04000000000)"),
      ACE_TEXT ("LM_UNK(010000000000)"),
      ACE_TEXT ("LM_UNK(020000000000)")
    };
}

const ACE_TCHAR *
ACE_Log_Record::priority_name (ACE_Log_Priority p)
{
  return ace_priority_names[ACE::log2 (p)];
}

void
ACE_Log_Record::priority_name (ACE_Log_Priority p,
                               const ACE_TCHAR *name)
{
  // Name must be a statically allocated string
  ace_priority_names[ACE::log2 (p)] = name;
}

u_long
ACE_Log_Record::priority (void) const
{
  ACE_TRACE ("ACE_Log_Record::priority");

  // Get the priority of the <Log_Record> <type_>.  This is computed
  // as the base 2 logarithm of <type_> (which must be a power of 2,
  // as defined by the enums in <ACE_Log_Priority>).
  return ACE::log2 ((u_long) this->type_);
}

void
ACE_Log_Record::priority (u_long p)
{
  ACE_TRACE ("ACE_Log_Record::priority");

  // Set the priority of the <Log_Record> <type_> (which must be a
  // power of 2, as defined by the enums in <ACE_Log_Priority>).
  this->type_ = (ACE_UINT32) p;
}

void
ACE_Log_Record::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // ACE_TRACE ("ACE_Log_Record::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("length_ = %d\n"), this->length_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ntype_ = %u\n"), this->type_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ntime_stamp_ = (%:, %d)\n"),
              this->secs_, this->usecs_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\npid_ = %u\n"), this->pid_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nmsg_data_ (0x%@) = %s\n"),
              this->msg_data_, this->msg_data_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nmsg_data_size_ = %B\n"),
              this->msg_data_size_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

int
ACE_Log_Record::msg_data (const ACE_TCHAR *data)
{
  // ACE_TRACE ("ACE_Log_Record::msg_data");
  size_t const newlen = ACE_OS::strlen (data) + 1;  // Will need room for '\0'
  if (newlen > this->msg_data_size_)
    {
      ACE_TCHAR *new_msg_data = 0;
      ACE_NEW_RETURN (new_msg_data, ACE_TCHAR[newlen], -1);
      delete [] this->msg_data_;
      this->msg_data_ = new_msg_data;
      this->msg_data_size_ = newlen;
    }
  ACE_OS::strcpy (this->msg_data_, data);
  this->round_up ();
  return 0;
}

ACE_Log_Record::ACE_Log_Record (ACE_Log_Priority lp,
                                time_t ts_sec,
                                long p)
  : length_ (0),
    type_ (ACE_UINT32 (lp)),
    secs_ (ts_sec),
    usecs_ (0),
    pid_ (ACE_UINT32 (p)),
    msg_data_ (0),
    msg_data_size_ (0)
{
  // ACE_TRACE ("ACE_Log_Record::ACE_Log_Record");
  ACE_NEW_NORETURN (this->msg_data_, ACE_TCHAR[MAXLOGMSGLEN]);
  if (0 != this->msg_data_)
    {
      this->msg_data_size_ = MAXLOGMSGLEN;
      this->msg_data_[0] = '\0';
    }
}

ACE_Log_Record::ACE_Log_Record (ACE_Log_Priority lp,
                                const ACE_Time_Value &ts,
                                long p)
  : length_ (0),
    type_ (ACE_UINT32 (lp)),
    secs_ (ts.sec ()),
    usecs_ ((ACE_UINT32) ts.usec ()),
    pid_ (ACE_UINT32 (p)),
    msg_data_ (0),
    msg_data_size_ (0)
{
  // ACE_TRACE ("ACE_Log_Record::ACE_Log_Record");
  ACE_NEW_NORETURN (this->msg_data_, ACE_TCHAR[MAXLOGMSGLEN]);
  if (0 != this->msg_data_)
    {
      this->msg_data_size_ = MAXLOGMSGLEN;
      this->msg_data_[0] = '\0';
    }
}

void
ACE_Log_Record::round_up (void)
{
  // ACE_TRACE ("ACE_Log_Record::round_up");
  // Determine the length of the payload.
  size_t len = sizeof (*this) + (sizeof (ACE_TCHAR) * ((ACE_OS::strlen (this->msg_data_) + 1)));

  // Round up to the alignment.
  len = ((len + ACE_Log_Record::ALIGN_WORDB - 1)
         & ~(ACE_Log_Record::ALIGN_WORDB - 1));
  this->length_ = static_cast<ACE_UINT32> (len);
}

ACE_Log_Record::ACE_Log_Record (void)
  : length_ (0),
    type_ (0),
    secs_ (0),
    usecs_ (0),
    pid_ (0),
    msg_data_ (0),
    msg_data_size_ (0)
{
  // ACE_TRACE ("ACE_Log_Record::ACE_Log_Record");
  ACE_NEW_NORETURN (this->msg_data_, ACE_TCHAR[MAXLOGMSGLEN]);
  if (0 != this->msg_data_)
    {
      this->msg_data_size_ = MAXLOGMSGLEN;
      this->msg_data_[0] = '\0';
    }
}

int
ACE_Log_Record::format_msg (const ACE_TCHAR host_name[],
                            u_long verbose_flag,
                            ACE_TCHAR *verbose_msg)
{
  /* 0123456789012345678901234     */
  /* Oct 18 14:25:36.000 1989<nul> */
  ACE_TCHAR timestamp[26]; // Only used by VERBOSE and VERBOSE_LITE.

  // The sprintf format needs to be different for Windows and POSIX
  // in the wide-char case.
#if defined (ACE_WIN32) || !defined (ACE_USES_WCHAR)
  const ACE_TCHAR *time_fmt =         ACE_TEXT ("%s.%03ld %s");
  const ACE_TCHAR *verbose_fmt =      ACE_TEXT ("%s@%s@%u@%s@%s");
  const ACE_TCHAR *verbose_lite_fmt = ACE_TEXT ("%s@%s@%s");
#else
  const ACE_TCHAR *time_fmt = ACE_TEXT ("%ls.%03ld %ls");
  const ACE_TCHAR *verbose_fmt = ACE_TEXT ("%ls@%ls@%u@%ls@%ls");
  const ACE_TCHAR *verbose_lite_fmt = ACE_TEXT ("%ls@%ls@%ls");
#endif

  if (ACE_BIT_ENABLED (verbose_flag,
                       ACE_Log_Msg::VERBOSE)
      || ACE_BIT_ENABLED (verbose_flag,
                          ACE_Log_Msg::VERBOSE_LITE))
    {
      time_t const now = this->secs_;
      ACE_TCHAR ctp[26]; // 26 is a magic number...

      if (ACE_OS::ctime_r (&now, ctp, sizeof ctp / sizeof (ACE_TCHAR)) == 0)
        return -1;

      /* 01234567890123456789012345 */
      /* Wed Oct 18 14:25:36 1989n0 */

      ctp[19] = '\0'; // NUL-terminate after the time.
      ctp[24] = '\0'; // NUL-terminate after the date.

      ACE_OS::sprintf (timestamp,
                       time_fmt,
                       ctp + 4,
                       ((long) this->usecs_) / 1000,
                       ctp + 20);
    }

  if (ACE_BIT_ENABLED (verbose_flag,
                       ACE_Log_Msg::VERBOSE))
    {
      const ACE_TCHAR *lhost_name = ((host_name == 0)
                                      ? ACE_TEXT ("<local_host>")
                                      : host_name);
      ACE_OS::sprintf (verbose_msg,
                       verbose_fmt,
                       timestamp,
                       lhost_name,
                       this->pid_,
                       ACE_Log_Record::priority_name (ACE_Log_Priority (this->type_)),
                       this->msg_data_);
    }
  else if (ACE_BIT_ENABLED (verbose_flag, ACE_Log_Msg::VERBOSE_LITE))
    ACE_OS::sprintf (verbose_msg,
                     verbose_lite_fmt,
                     timestamp,
                     ACE_Log_Record::priority_name (ACE_Log_Priority (this->type_)),
                     this->msg_data_);
  else
    ACE_OS::strcpy (verbose_msg, this->msg_data_);
  return 0;
}

int
ACE_Log_Record::print (const ACE_TCHAR host_name[],
                       u_long verbose_flag,
                       FILE *fp)
{
  if (ACE_LOG_MSG->log_priority_enabled (ACE_Log_Priority (this->type_)))
    {
      ACE_TCHAR *verbose_msg = 0;
      ACE_NEW_RETURN (verbose_msg, ACE_TCHAR[MAXVERBOSELOGMSGLEN], -1);

      int result = this->format_msg (host_name, verbose_flag, verbose_msg);

      if (result == 0)
        {
          if (fp != 0)
            {
              int const verbose_msg_len =
                static_cast<int> (ACE_OS::strlen (verbose_msg));
#if !defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
              int const fwrite_result = ACE_OS::fprintf (fp,
                                                         ACE_TEXT ("%ls"),
                                                         verbose_msg);
#else
              int const fwrite_result = ACE_OS::fprintf (fp,
                                                         ACE_TEXT ("%s"),
                                                         verbose_msg);
#endif
              // We should have written everything
              if (fwrite_result != verbose_msg_len)
                result = -1;
              else
                ACE_OS::fflush (fp);
            }
        }

      delete [] verbose_msg;

      return result;
    }
  else
    return 0;
}

int
operator<< (ACE_OutputCDR &cdr,
            const ACE_Log_Record &log_record)
{
  // The written message length can't be more than 32 bits (ACE_CDR::ULong)
  // so reduce it here if needed.
  ACE_CDR::ULong u_msglen =
    ACE_Utils::truncate_cast<ACE_CDR::ULong> (log_record.msg_data_len ());

  // Insert each field from <log_record> into the output CDR stream.
  cdr << ACE_CDR::Long (log_record.type ());
  cdr << ACE_CDR::Long (log_record.pid ());
  cdr << ACE_CDR::LongLong (log_record.time_stamp ().sec ());
  cdr << ACE_CDR::Long (log_record.time_stamp ().usec ());
  cdr << u_msglen;
#if defined (ACE_USES_WCHAR)
  cdr.write_wchar_array (log_record.msg_data (), u_msglen);
#else
  cdr.write_char_array (log_record.msg_data (), u_msglen);
#endif /* ACE_USES_WCHAR */
  return cdr.good_bit ();
}

int
operator>> (ACE_InputCDR &cdr,
            ACE_Log_Record &log_record)
{
  ACE_CDR::Long type;
  ACE_CDR::Long pid;
  ACE_CDR::LongLong sec;
  ACE_CDR::Long usec;
  ACE_CDR::ULong buffer_len;

  // Extract each field from input CDR stream into <log_record>.
  if ((cdr >> type) && (cdr >> pid) && (cdr >> sec) && (cdr >> usec)
      && (cdr >> buffer_len)) {
    ACE_TCHAR *log_msg;
    ACE_NEW_RETURN (log_msg, ACE_TCHAR[buffer_len + 1], -1);
    auto_ptr<ACE_TCHAR> log_msg_p (log_msg);
    log_record.type (type);
    log_record.pid (pid);
    log_record.time_stamp (ACE_Time_Value (ACE_Utils::truncate_cast<time_t> (sec),
                                           usec));
#if defined (ACE_USES_WCHAR)
    cdr.read_wchar_array (log_msg, buffer_len);
#else
    cdr.read_char_array (log_msg, buffer_len);
#endif /* ACE_USES_WCHAR */
    log_msg[buffer_len] = '\0';
    if (-1 == log_record.msg_data (log_msg))
      return -1;
  }
  return cdr.good_bit ();
}

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

int
ACE_Log_Record::print (const ACE_TCHAR host_name[],
                       u_long verbose_flag,
                       ACE_OSTREAM_TYPE &s)
{
  if (ACE_LOG_MSG->log_priority_enabled (ACE_Log_Priority (this->type_)))
    {
      ACE_TCHAR* verbose_msg = 0;
      ACE_NEW_RETURN (verbose_msg, ACE_TCHAR[MAXVERBOSELOGMSGLEN], -1);

      int const result = this->format_msg (host_name, verbose_flag, verbose_msg);

      if (result == 0)
        {
          // Since ostream expects only chars, we cannot pass wchar_t's
          s << ACE_TEXT_ALWAYS_CHAR (verbose_msg);
          s.flush ();
        }

      delete [] verbose_msg;

      return result;
    }
  return 0;
}

#endif /* ! ACE_LACKS_IOSTREAM_TOTALLY */

ACE_END_VERSIONED_NAMESPACE_DECL

