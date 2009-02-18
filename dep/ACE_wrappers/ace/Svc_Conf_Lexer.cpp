// $Id: Svc_Conf_Lexer.cpp 81312 2008-04-09 21:01:34Z iliyan $
#include "ace/Svc_Conf_Lexer.h"

#if (ACE_USES_CLASSIC_SVC_CONF == 1)

#if defined (ACE_USES_WCHAR)
#include "ace/Encoding_Converter.h"
#include "ace/Encoding_Converter_Factory.h"
#endif /* ACE_USES_WCHAR */

#include "ace/Svc_Conf_Tokens.h"
#include "ace/Recursive_Thread_Mutex.h"
#include "ace/Static_Object_Lock.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_ctype.h"
#include "ace/OS_NS_string.h"
#include "ace/Guard_T.h"
#include "ace/Synch_Traits.h"
#include "ace/os_include/os_ctype.h"

#if !defined (__GNUG__)
# include "ace/Auto_Ptr.h"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#define ACE_YY_BUF_SIZE 4096
#define ACE_MAX_BYTES_PER_CHAR 4
#define ACE_YY_CONVERSION_SPACE ACE_YY_BUF_SIZE * ACE_MAX_BYTES_PER_CHAR

#if defined (__GNUG__)
# define ACE_TEMPORARY_STRING(X,SIZE) \
   __extension__ char X[SIZE]
#else
# define ACE_TEMPORARY_STRING(X,SIZE) \
   char* X = 0; \
   char X ## buf[ACE_YY_BUF_SIZE]; \
   ACE_Auto_Ptr<char> X ## bufp (0); \
   if (SIZE > ACE_YY_BUF_SIZE) { \
     X ## bufp.reset (new char[SIZE]); \
     X = X ## bufp.get (); \
   } \
   else { \
     X = X ## buf; \
   }
#endif /* __GNUG__ */

// These are states not covered by the tokens in Svc_Conf_Tokens.h
#define ACE_NO_STATE -1
#define ACE_COMMENT 0

#if defined (_MSC_VER) && (_MSC_VER >= 1400)
// Visual Studio .NET 2005 (VC8) issues warning C4351 for input_ in the
// constructor initializer list below. Since we like the warned-of new
// behavior (input_ elements will be default-initialized), squash the
// warning here.
#  pragma warning (push)
#  pragma warning (disable:4351)
#endif /* VC8 */

struct ace_yy_buffer_state
{
  ace_yy_buffer_state (void)
   : input_ (),
     index_ (0),
     size_ (0),
     start_ (0),
     need_more_ (true),
     eof_ (false),
     state_ (ACE_NO_STATE),
     string_start_ (0)
#if defined (ACE_USES_WCHAR)
     , converter_ (0)
#endif /* ACE_USES_WCHAR */
  {
  }
#if defined (_MSC_VER) && (_MSC_VER >= 1400)
#  pragma warning (pop)
#endif /* VC8 */

  ~ace_yy_buffer_state (void)
  {
#if defined (ACE_USES_WCHAR)
    delete converter_;
#endif /* ACE_USES_WCHAR */
  }

  // Input related
  char input_[ACE_YY_CONVERSION_SPACE];
  size_t index_;
  size_t size_;
  size_t start_;
  bool need_more_;
  bool eof_;

  // Parsing related
  int state_;
  char string_start_;

#if defined (ACE_USES_WCHAR)
  // Code set conversion related
  ACE_Encoding_Converter* converter_;
#endif /* ACE_USES_WCHAR */
};

// ******************************************************************
// Global functions
// ******************************************************************

int
ace_yylex (YYSTYPE *ace_yylval, void *YYLEX_PARAM)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_RECURSIVE_MUTEX,
                            ace_mon,
                            *ACE_Static_Object_Lock::instance (),
                            -1));

  return ACE_Svc_Conf_Lexer::yylex (ace_yylval, ACE_SVC_CONF_PARAM);

}

void
ace_yy_delete_buffer (ace_yy_buffer_state *buffer)
{
  delete buffer;
}

// ******************************************************************
// Inline methods
// ******************************************************************

inline size_t
normalize (size_t length)
{
  return (length >= ACE_MAX_BYTES_PER_CHAR ?
          (length / ACE_MAX_BYTES_PER_CHAR) * ACE_MAX_BYTES_PER_CHAR :
          length);
}

// ******************************************************************
// Static class methods
// ******************************************************************

int
ACE_Svc_Conf_Lexer::yylex (YYSTYPE* ace_yylval,
                           ACE_Svc_Conf_Param* param)
{
#if defined (ACE_USES_WCHAR)
  bool look_for_bom = false;
  ACE_Encoding_Converter_Factory::Encoding_Hint hint =
                ACE_Encoding_Converter_Factory::ACE_NONE;
#endif /* ACE_USES_WCHAR */
  if (param->buffer == 0)
    {
#if defined (ACE_USES_WCHAR)
      look_for_bom = true;
#endif /* ACE_USES_WCHAR */
      ACE_NEW_RETURN (param->buffer,
                      ace_yy_buffer_state,
                      -1);
    }

  int token = ACE_NO_STATE;
  do {
    if (param->buffer->need_more_)
      {
#if defined (ACE_USES_WCHAR)
        size_t skip_bytes = 0;
#endif /* ACE_USES_WCHAR */
        param->buffer->need_more_ = false;
        size_t amount =
               input (param,
                      param->buffer->input_ + param->buffer->size_,
                      normalize (ACE_YY_BUF_SIZE -
                                 param->buffer->size_));
        if (amount == 0)
          {
            param->buffer->eof_ = true;
#if defined (ACE_USES_WCHAR)
            skip_bytes = param->buffer->size_;
#endif /* ACE_USES_WCHAR */
          }
        else
          {
#if defined (ACE_USES_WCHAR)
            if (look_for_bom)
              {
                size_t read_more = 0;

                look_for_bom = false;
                hint = locate_bom (param->buffer->input_, amount, read_more);

                if (read_more != 0)
                  {
                    input (param,
                           param->buffer->input_ + amount,
                           read_more);
                    ACE_OS::memmove (param->buffer->input_,
                                     param->buffer->input_ + read_more,
                                     amount);
                  }
              }
            skip_bytes = param->buffer->size_;
#endif /* ACE_USES_WCHAR */
            param->buffer->size_ += amount;
          }

#if defined (ACE_USES_WCHAR)
        if (!convert_to_utf8 (param, skip_bytes, hint))
          {
            ace_yyerror (++param->yyerrno,
                         param->yylineno,
                         ACE_TEXT ("Unable to convert input stream to UTF-8"));
            return ACE_NO_STATE;
          }
#endif /* ACE_USES_WCHAR */
      }

    token = scan (ace_yylval, param);
  } while (token == ACE_NO_STATE && param->buffer->need_more_);

  return token;
}

size_t
ACE_Svc_Conf_Lexer::input (ACE_Svc_Conf_Param* param,
                           char* buf, size_t max_size)
{
  size_t result = 0;

  switch (param->type)
    {
    case ACE_Svc_Conf_Param::SVC_CONF_FILE:
      errno = 0;
      while ((result = ACE_OS::fread (buf, 1,
                                      max_size, param->source.file)) == 0 &&
             ferror (param->source.file))
        {
          if (errno == EINTR)
            {
              errno = 0;
#if !defined (ACE_LACKS_CLEARERR)
              ACE_OS::clearerr (param->source.file);
#endif /* !ACE_LACKS_CLEARERR */
            }
          else
            {
              ACE_OS::fprintf (stderr, "ERROR: input in scanner failed\n");
              ACE_OS::exit (2);
            }
        }
      break;
    case ACE_Svc_Conf_Param::SVC_CONF_DIRECTIVE:
      result = ACE_OS::strlen (param->source.directive +
                               param->buffer->start_) * sizeof (ACE_TCHAR);
      if (result != 0)
        {
          // Make sure that the amount we are going to copy
          // fits in the buffer
          if (result > max_size)
            {
              result = max_size;
            }
          ACE_OS::memcpy (buf,
                          param->source.directive + param->buffer->start_,
                          result);
          param->buffer->start_ += (result / sizeof (ACE_TCHAR));
        }
      break;
    default:
      ace_yyerror (++param->yyerrno,
                   param->yylineno,
                   ACE_TEXT ("Invalid Service Configurator type in ")
                   ACE_TEXT ("ACE_Svc_Conf_Lexer::input"));
    }

  return result;
}

int
ACE_Svc_Conf_Lexer::scan (YYSTYPE* ace_yylval,
                          ACE_Svc_Conf_Param* param)

{
  ace_yy_buffer_state* buffer = param->buffer;

  // If we are not currently in any state, skip over whitespace
  if (buffer->state_ == ACE_NO_STATE)
    {
      while (buffer->index_ < buffer->size_ &&
             isspace (buffer->input_[buffer->index_]))
        {
          // Make sure that we count all of the new lines
          if (buffer->input_[buffer->index_] == '\n')
            {
              ++param->yylineno;
            }
          ++buffer->index_;
        }
    }

  size_t current;
  size_t last = buffer->size_ + (buffer->eof_ ? 1 : 0);
  for (current = buffer->index_; current < last; current++)
    {
      static const char* separators = " \t\r\n:*(){}";
      char c = (buffer->eof_ && current == buffer->size_ ?
                                     '\n' : buffer->input_[current]);
      switch (buffer->state_)
        {
          case ACE_COMMENT:
            if (c == '\n')
              {
                buffer->state_ = ACE_NO_STATE;
                buffer->index_ = current + 1;
                ++param->yylineno;
              }
            break;
          case ACE_STRING:
            if (!(c >= ' ' && c <= '~'))
              {
                // The character at currrent is definitely not part of
                // the string so we need to move current back one.
                --current;

                // Get the starting point of our string (skipping the quote)
                char* source = buffer->input_ + buffer->index_ + 1;

                // Now, we need to move back in the string until we find the
                // same character that started the string
                bool string_end_found = false;
                if (current > buffer->index_)
                  {
                    for (size_t i = current - buffer->index_; i-- != 0; )
                      {
                        if (source[i] == buffer->string_start_)
                          {
                            current = buffer->index_ + i + 1;
                            string_end_found = true;
                            break;
                          }
                      }
                  }

                if (!string_end_found)
                  {
                    ace_yyerror (++param->yyerrno,
                                 param->yylineno,
                                 ACE_TEXT ("Unable to find the end of the string"));
                    return ACE_NO_STATE;
                  }

                size_t amount = (current - buffer->index_) - 1;
#if defined (ACE_USES_WCHAR)
                ACE_TCHAR target[ACE_YY_CONVERSION_SPACE] = ACE_TEXT ("");
                size_t length = 0;
                if (!convert_from_utf8 (buffer->converter_,
                                        source,
                                        amount,
                                        target,
                                        ACE_YY_CONVERSION_SPACE,
                                        length))
                  {
                    ace_yyerror (++param->yyerrno,
                                 param->yylineno,
                                 ACE_TEXT ("Unable to convert string from UTF-8"));
                    return ACE_NO_STATE;
                  }
                amount = length;
#else
                char* target = source;
#endif /* ACE_USES_WCHAR */
                ace_yylval->ident_ = param->obstack.copy (target, amount);
                buffer->state_ = ACE_NO_STATE;
                buffer->index_ = current + 1;
                return ACE_STRING;
              }
            break;
          case ACE_NO_STATE:
            if (c == '"' || c == '\'')
              {
                buffer->string_start_ = c;
                buffer->state_ = ACE_STRING;
              }
            else if (c == '#')
              {
                buffer->state_ = ACE_COMMENT;
              }
            else if (ACE_OS::strchr (separators, c) != 0)
              {
                if (c == '\n')
                  {
                    ++param->yylineno;
                  }

                if (current == buffer->index_ + 1)
                  {
                    int lower = ACE_OS::ace_tolower (
                                          buffer->input_[current - 1]);
                    if (c == ':' &&
                        (buffer->input_[current - 1] == '%' ||
                         (lower >= 'a' && lower <= 'z')))
                      {
                        // This is considered a path, so we need to
                        // skip over the ':' and go around the loop
                        // again
                        break;
                      }
                  }

                if (current == buffer->index_)
                  {
                    buffer->index_ = current + 1;
                    if (isspace (c))
                      {
                        // This is an empty line.
                        // Let's look for something else.
                        break;
                      }
                    else
                      {
                        return c;
                      }
                  }

                // String from buffer->index_ to current (inclusive)
                size_t size = (current - buffer->index_) + 1;
                ACE_TEMPORARY_STRING (str, size);
                ACE_OS::strncpy (str, buffer->input_ + buffer->index_,
                                 size - 1);
                str[size - 1] = '\0';


                if (ACE_OS::strcmp (str, "dynamic") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_DYNAMIC;
                  }
                else if (ACE_OS::strcmp (str, "static") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_STATIC;
                  }
                else if (ACE_OS::strcmp (str, "suspend") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_SUSPEND;
                  }
                else if (ACE_OS::strcmp (str, "resume") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_RESUME;
                  }
                else if (ACE_OS::strcmp (str, "remove") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_REMOVE;
                  }
                else if (ACE_OS::strcmp (str, "stream") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_USTREAM;
                  }
                else if (ACE_OS::strcmp (str, "Module") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_MODULE_T;
                  }
                else if (ACE_OS::strcmp (str, "Service_Object") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_SVC_OBJ_T;
                  }
                else if (ACE_OS::strcmp (str, "STREAM") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_STREAM_T;
                  }
                else if (ACE_OS::strcmp (str, "active") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_ACTIVE;
                  }
                else if (ACE_OS::strcmp (str, "inactive") == 0)
                  {
                    buffer->index_ = current;
                    return ACE_INACTIVE;
                  }
                else
                  {
                    // Get the string and save it in ace_yylval
                    int token = ACE_IDENT;
                    size_t amount = size - 1;
#if defined (ACE_USES_WCHAR)
                    ACE_TCHAR target[ACE_YY_CONVERSION_SPACE] = ACE_TEXT ("");
                    size_t length = 0;
                    if (!convert_from_utf8 (buffer->converter_,
                                            str,
                                            amount,
                                            target,
                                            ACE_YY_CONVERSION_SPACE,
                                            length))
                      {
                        ace_yyerror (++param->yyerrno,
                                     param->yylineno,
                                     ACE_TEXT ("Unable to convert ")
                                     ACE_TEXT ("identifier from UTF-8"));
                        return ACE_NO_STATE;
                      }
                    amount = length;
#else
                    char* target = str;
#endif /* ACE_USES_WCHAR */
                    ace_yylval->ident_ = param->obstack.copy (target, amount);

                    // Determine the difference between pathname and ident
                    if (ACE_OS::ace_isdigit (ace_yylval->ident_[0]))
                      {
                        token = ACE_PATHNAME;
                      }
                    else
                      {
                        static const ACE_TCHAR* path_parts =
                                                ACE_TEXT ("/\\:%.~-");
                        for (const ACE_TCHAR* p = path_parts; *p != '\0'; p++)
                          {
                            if (ACE_OS::strchr (ace_yylval->ident_, *p) != 0)
                              {
                                token = ACE_PATHNAME;
                                break;
                              }
                          }
                      }

                    buffer->state_ = ACE_NO_STATE;
                    buffer->index_ = current;
                    return token;
                  }
              }
            break;
          default:
            ace_yyerror (++param->yyerrno,
                         param->yylineno,
                         ACE_TEXT ("Unexpected state in ACE_Svc_Conf_Lexer::scan"));
            return ACE_NO_STATE;
        }
    }

  // We need more from the input source so, we will move the remainder of
  // the buffer to the front and signal that we need more
  if (!buffer->eof_)
    {
      buffer->need_more_ = true;
      if (buffer->state_ == ACE_COMMENT)
        {
          buffer->index_ = 0;
          buffer->size_  = 0;
        }
      else
        {
          buffer->size_ = current - buffer->index_;
          if (buffer->size_ != 0 && buffer->index_ != 0)
            ACE_OS::memmove (buffer->input_,
                             buffer->input_ + buffer->index_, buffer->size_);
          buffer->index_ = 0;
          buffer->state_ = ACE_NO_STATE;
        }
    }
  return ACE_NO_STATE;
}

#if defined (ACE_USES_WCHAR)

bool
ACE_Svc_Conf_Lexer::convert_to_utf8 (
                      ACE_Svc_Conf_Param* param,
                      size_t skip_bytes,
                      ACE_Encoding_Converter_Factory::Encoding_Hint hint)
{
  bool status = false;
  if (param->buffer->converter_ == 0)
    {
      param->buffer->converter_ =
        ACE_Encoding_Converter_Factory::create (
          reinterpret_cast<ACE_Byte*> (param->buffer->input_ + skip_bytes),
          param->buffer->size_ - skip_bytes,
          hint);
    }

  if (param->buffer->converter_ != 0)
    {
      char target[ACE_YY_CONVERSION_SPACE] = "";
      if (param->buffer->converter_->to_utf8 (
            param->buffer->input_ + skip_bytes,
            param->buffer->size_ - skip_bytes,
            reinterpret_cast<ACE_Byte*> (target),
            ACE_YY_CONVERSION_SPACE) == ACE_Encoding_Converter::CONVERSION_OK)
        {
          ACE_OS::strcpy (param->buffer->input_ + skip_bytes, target);
          param->buffer->size_ = ACE_OS::strlen (target) + skip_bytes;
          status = true;
        }
    }

  return status;
}

bool
ACE_Svc_Conf_Lexer::convert_from_utf8 (ACE_Encoding_Converter* converter,
                                       const char* source,
                                       size_t source_size,
                                       ACE_TCHAR* target,
                                       size_t target_size,
                                       size_t& length)
{
  if (converter != 0)
    {
      if (converter->from_utf8 (
            reinterpret_cast <const ACE_Byte*> (source),
            source_size,
            target,
            target_size) != ACE_Encoding_Converter::CONVERSION_OK)
        {
          return false;
        }
    }
  else
    {
      ACE_OS::strncpy (target, ACE_TEXT_CHAR_TO_TCHAR (source), source_size);
      target[source_size] = 0;
    }

  length = ACE_OS::strlen (target);
  return true;
}

ACE_Encoding_Converter_Factory::Encoding_Hint
ACE_Svc_Conf_Lexer::locate_bom (char* source,
                                size_t source_size,
                                size_t& bytes_used)
{
  struct bom {
    size_t length_;
    const char* data_;
    ACE_Encoding_Converter_Factory::Encoding_Hint hint_;
  };
  static const bom boms[] = {
    { 4, "\x00\x00\xfe\xff", ACE_Encoding_Converter_Factory::ACE_UTF_32BE },
    { 4, "\xff\xfe\x00\x00", ACE_Encoding_Converter_Factory::ACE_UTF_32LE },
    { 2, "\xfe\xff",         ACE_Encoding_Converter_Factory::ACE_UTF_16BE },
    { 2, "\xff\xfe",         ACE_Encoding_Converter_Factory::ACE_UTF_16LE },
    { 3, "\xef\xbb\xbf",     ACE_Encoding_Converter_Factory::ACE_UTF_8    },
  };

  for (size_t i = 0; i < sizeof (boms) / sizeof (bom); i++)
    {
      if (source_size >= boms[i].length_)
        {
          if (ACE_OS::memcmp (source,
                              boms[i].data_, boms[i].length_) == 0)
            {
              bytes_used = boms[i].length_;
              return boms[i].hint_;
            }
        }
    }

  // No BOM was found
  bytes_used = 0;
  return ACE_Encoding_Converter_Factory::ACE_NONE;
}

#endif /* ACE_USES_WCHAR */

ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_USES_CLASSIC_SVC_CONF = 1 */

