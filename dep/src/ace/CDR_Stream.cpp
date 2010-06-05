#include "ace/CDR_Stream.h"
#include "ace/SString.h"
#include "ace/Auto_Ptr.h"
#include "ace/Truncate.h"

#if !defined (__ACE_INLINE__)
# include "ace/CDR_Stream.inl"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID (ace,
           CDR_Stream,
           "$Id: CDR_Stream.cpp 82559 2008-08-07 20:23:07Z parsons $")

// ****************************************************************

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

size_t ACE_OutputCDR::wchar_maxbytes_ = sizeof (ACE_CDR::WChar);

ACE_OutputCDR::ACE_OutputCDR (size_t size,
                              int byte_order,
                              ACE_Allocator *buffer_allocator,
                              ACE_Allocator *data_block_allocator,
                              ACE_Allocator *message_block_allocator,
                              size_t memcpy_tradeoff,
                              ACE_CDR::Octet major_version,
                              ACE_CDR::Octet minor_version)
  :  start_ ((size ? size : (size_t) ACE_CDR::DEFAULT_BUFSIZE) + ACE_CDR::MAX_ALIGNMENT,
             ACE_Message_Block::MB_DATA,
             0,
             0,
             buffer_allocator,
             0,
             0,
             ACE_Time_Value::zero,
             ACE_Time_Value::max_time,
             data_block_allocator,
             message_block_allocator),
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
     current_alignment_ (0),
#endif /* ACE_LACKS_CDR_ALIGNMENT */
     current_is_writable_ (true),
     do_byte_swap_ (byte_order != ACE_CDR_BYTE_ORDER),
     good_bit_ (true),
     memcpy_tradeoff_ (memcpy_tradeoff),
     major_version_ (major_version),
     minor_version_ (minor_version),
     char_translator_ (0),
     wchar_translator_ (0)

{
  ACE_CDR::mb_align (&this->start_);
  this->current_ = &this->start_;

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->total_length ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_OutputCDR::ACE_OutputCDR (char *data,
                              size_t size,
                              int byte_order,
                              ACE_Allocator *buffer_allocator,
                              ACE_Allocator *data_block_allocator,
                              ACE_Allocator *message_block_allocator,
                              size_t memcpy_tradeoff,
                              ACE_CDR::Octet major_version,
                              ACE_CDR::Octet minor_version)
  :  start_ (size,
             ACE_Message_Block::MB_DATA,
             0,
             data,
             buffer_allocator,
             0,
             0,
             ACE_Time_Value::zero,
             ACE_Time_Value::max_time,
             data_block_allocator,
             message_block_allocator),
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
     current_alignment_ (0),
#endif /* ACE_LACKS_CDR_ALIGNMENT */
     current_is_writable_ (true),
     do_byte_swap_ (byte_order != ACE_CDR_BYTE_ORDER),
     good_bit_ (true),
     memcpy_tradeoff_ (memcpy_tradeoff),
     major_version_ (major_version),
     minor_version_ (minor_version),
     char_translator_ (0),
     wchar_translator_ (0)
{
  // We cannot trust the buffer to be properly aligned
  ACE_CDR::mb_align (&this->start_);
  this->current_ = &this->start_;

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->total_length ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_OutputCDR::ACE_OutputCDR (ACE_Data_Block *data_block,
                              int byte_order,
                              ACE_Allocator *message_block_allocator,
                              size_t memcpy_tradeoff,
                              ACE_CDR::Octet major_version,
                              ACE_CDR::Octet minor_version)
  :  start_ (data_block,
             ACE_Message_Block::DONT_DELETE,
             message_block_allocator),
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
     current_alignment_ (0),
#endif /* ACE_LACKS_CDR_ALIGNMENT */
     current_is_writable_ (true),
     do_byte_swap_ (byte_order != ACE_CDR_BYTE_ORDER),
     good_bit_ (true),
     memcpy_tradeoff_ (memcpy_tradeoff),
     major_version_ (major_version),
     minor_version_ (minor_version),
     char_translator_ (0),
     wchar_translator_ (0)
{
  // We cannot trust the buffer to be properly aligned
  ACE_CDR::mb_align (&this->start_);
  this->current_ = &this->start_;

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->total_length ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_OutputCDR::ACE_OutputCDR (ACE_Message_Block *data,
                              int byte_order,
                              size_t memcpy_tradeoff,
                              ACE_CDR::Octet major_version,
                              ACE_CDR::Octet minor_version)
  :  start_ (data->data_block ()->duplicate ()),
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
     current_alignment_ (0),
#endif /* ACE_LACKS_CDR_ALIGNMENT */
     current_is_writable_ (true),
     do_byte_swap_ (byte_order != ACE_CDR_BYTE_ORDER),
     good_bit_ (true),
     memcpy_tradeoff_ (memcpy_tradeoff),
     major_version_ (major_version),
     minor_version_ (minor_version),
     char_translator_ (0),
     wchar_translator_ (0)
{
  // We cannot trust the buffer to be properly aligned
  ACE_CDR::mb_align (&this->start_);
  this->current_ = &this->start_;

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->total_length ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

/*static*/ void
ACE_OutputCDR::wchar_maxbytes (size_t maxbytes)
{
  ACE_OutputCDR::wchar_maxbytes_ = maxbytes;
}

/*static*/ size_t
ACE_OutputCDR::wchar_maxbytes ()
{
  return ACE_OutputCDR::wchar_maxbytes_;
}

int
ACE_OutputCDR::grow_and_adjust (size_t size,
                                size_t align,
                                char*& buf)
{
  if (!this->current_is_writable_
      || this->current_->cont () == 0
      || this->current_->cont ()->size () < size + ACE_CDR::MAX_ALIGNMENT)
    {
      // Calculate the new buffer's length; if growing for encode, we
      // don't grow in "small" chunks because of the cost.
      size_t cursize = this->current_->size ();
      if (this->current_->cont () != 0)
        cursize = this->current_->cont ()->size ();
      size_t minsize = size;

#if !defined (ACE_LACKS_CDR_ALIGNMENT)
      minsize += ACE_CDR::MAX_ALIGNMENT;
#endif /* ACE_LACKS_CDR_ALIGNMENT */

      // Make sure that there is enough room for <minsize> bytes, but
      // also make it bigger than whatever our current size is.
      if (minsize < cursize)
        minsize = cursize;

      size_t const newsize = ACE_CDR::next_size (minsize);

      this->good_bit_ = false;
      ACE_Message_Block* tmp = 0;
      ACE_NEW_RETURN (tmp,
                      ACE_Message_Block (newsize,
                                         ACE_Message_Block::MB_DATA,
                                         0,
                                         0,
                                         this->current_->data_block ()->allocator_strategy (),
                                         0,
                                         0,
                                         ACE_Time_Value::zero,
                                         ACE_Time_Value::max_time,
                                         this->current_->data_block ()->data_block_allocator ()),
                      -1);

      // Message block initialization may fail while the construction
      // succeds.  Since as a matter of policy, ACE may throw no
      // exceptions, we have to do a separate check like this.
      if (tmp != 0 && tmp->size () < newsize)
        {
          delete tmp;
          errno = ENOMEM;
          return -1;
        }

      this->good_bit_ = true;

#if !defined (ACE_LACKS_CDR_ALIGNMENT)
      // The new block must start with the same alignment as the
      // previous block finished.
      ptrdiff_t const tmpalign =
        reinterpret_cast<ptrdiff_t> (tmp->rd_ptr ()) % ACE_CDR::MAX_ALIGNMENT;
      ptrdiff_t const curalign =
        static_cast<ptrdiff_t> (this->current_alignment_) % ACE_CDR::MAX_ALIGNMENT;
      ptrdiff_t offset = curalign - tmpalign;
      if (offset < 0)
        offset += ACE_CDR::MAX_ALIGNMENT;
      tmp->rd_ptr (static_cast<size_t> (offset));
      tmp->wr_ptr (tmp->rd_ptr ());
#endif /* ACE_LACKS_CDR_ALIGNMENT */

      // grow the chain and set the current block.
      tmp->cont (this->current_->cont ());
      this->current_->cont (tmp);
    }
  this->current_ = this->current_->cont ();
  this->current_is_writable_ = true;

  return this->adjust (size, align, buf);
}

ACE_CDR::Boolean
ACE_OutputCDR::write_wchar (ACE_CDR::WChar x)
{
  if (this->wchar_translator_ != 0)
    return (this->good_bit_ = this->wchar_translator_->write_wchar (*this, x));
  if (ACE_OutputCDR::wchar_maxbytes_ == 0)
    {
      errno = EACCES;
      return (this->good_bit_ = false);
    }
  if (static_cast<ACE_CDR::Short> (major_version_) == 1
      && static_cast<ACE_CDR::Short> (minor_version_) == 2)
    {
      ACE_CDR::Octet len =
        static_cast<ACE_CDR::Octet> (ACE_OutputCDR::wchar_maxbytes_);
      if (this->write_1 (&len))
        {
          if (ACE_OutputCDR::wchar_maxbytes_ == sizeof(ACE_CDR::WChar))
            return
              this->write_octet_array (
                                       reinterpret_cast<const ACE_CDR::Octet*> (&x),
                                       static_cast<ACE_CDR::ULong> (len));
          else
            if (ACE_OutputCDR::wchar_maxbytes_ == 2)
              {
                ACE_CDR::Short sx = static_cast<ACE_CDR::Short> (x);
                return
                  this->write_octet_array (
                                           reinterpret_cast<const ACE_CDR::Octet*> (&sx),
                                           static_cast<ACE_CDR::ULong> (len));
              }
            else
              {
                ACE_CDR::Octet ox = static_cast<ACE_CDR::Octet> (x);
                return
                  this->write_octet_array (
                                           reinterpret_cast<const ACE_CDR::Octet*> (&ox),
                                           static_cast<ACE_CDR::ULong> (len));
              }
        }
    }
  else if (static_cast<ACE_CDR::Short> (minor_version_) == 0)
    { // wchar is not allowed with GIOP 1.0.
      errno = EINVAL;
      return (this->good_bit_ = false);
    }
  if (ACE_OutputCDR::wchar_maxbytes_ == sizeof (ACE_CDR::WChar))
    {
      void const * const temp = &x;
      return
        this->write_4 (reinterpret_cast<const ACE_CDR::ULong *> (temp));
    }
  else if (ACE_OutputCDR::wchar_maxbytes_ == 2)
    {
      ACE_CDR::Short sx = static_cast<ACE_CDR::Short> (x);
      return this->write_2 (reinterpret_cast<const ACE_CDR::UShort *> (&sx));
    }
  ACE_CDR::Octet ox = static_cast<ACE_CDR::Octet> (x);
  return this->write_1 (reinterpret_cast<const ACE_CDR::Octet *> (&ox));
}

ACE_CDR::Boolean
ACE_OutputCDR::write_string (ACE_CDR::ULong len,
                             const ACE_CDR::Char *x)
{
  // @@ This is a slight violation of "Optimize for the common case",
  // i.e. normally the translator will be 0, but OTOH the code is
  // smaller and should be better for the cache ;-) ;-)
  if (this->char_translator_ != 0)
    return this->char_translator_->write_string (*this, len, x);

  if (len != 0)
    {
      if (this->write_ulong (len + 1))
        return this->write_char_array (x, len + 1);
    }
  else
    {
      // Be nice to programmers: treat nulls as empty strings not
      // errors. (OMG-IDL supports languages that don't use the C/C++
      // notion of null v. empty strings; nulls aren't part of the OMG-IDL
      // string model.)
      if (this->write_ulong (1))
        return this->write_char (0);
    }

  return (this->good_bit_ = false);
}

ACE_CDR::Boolean
ACE_OutputCDR::write_string (const ACE_CString &x)
{
  // @@ Leave this method in here, not the `.i' file so that we don't
  //    have to unnecessarily pull in the `ace/SString.h' header.
  return this->write_string (static_cast<ACE_CDR::ULong> (x.length ()),
                             x.c_str());
}

ACE_CDR::Boolean
ACE_OutputCDR::write_wstring (ACE_CDR::ULong len,
                              const ACE_CDR::WChar *x)
{
  // @@ This is a slight violation of "Optimize for the common case",
  // i.e. normally the translator will be 0, but OTOH the code is
  // smaller and should be better for the cache ;-) ;-)
  // What do we do for GIOP 1.2???
  if (this->wchar_translator_ != 0)
    return this->wchar_translator_->write_wstring (*this, len, x);
  if (ACE_OutputCDR::wchar_maxbytes_ == 0)
    {
      errno = EACCES;
      return (this->good_bit_ = false);
    }

  if (static_cast<ACE_CDR::Short> (this->major_version_) == 1
      && static_cast<ACE_CDR::Short> (this->minor_version_) == 2)
    {
      if (x != 0)
        {
          //In GIOP 1.2 the length field contains the number of bytes
          //the wstring occupies rather than number of wchars
          //Taking sizeof might not be a good way! This is a temporary fix.
          ACE_CDR::Boolean good_ulong =
            this->write_ulong (
              ACE_Utils::truncate_cast<ACE_CDR::ULong> (
                ACE_OutputCDR::wchar_maxbytes_ * len));

          if (good_ulong)
            {
              return this->write_wchar_array (x, len);
            }
        }
      else
        {
          //In GIOP 1.2 zero length wstrings are legal
          return this->write_ulong (0);
        }
    }

  else
    if (x != 0)
      {
        if (this->write_ulong (len + 1))
          return this->write_wchar_array (x, len + 1);
      }
    else if (this->write_ulong (1))
      return this->write_wchar (0);
  return (this->good_bit_ = false);
}

ACE_CDR::Boolean
ACE_OutputCDR::write_octet_array_mb (const ACE_Message_Block* mb)
{
  // If the buffer is small and it fits in the current message
  // block it is be cheaper just to copy the buffer.
  for (const ACE_Message_Block* i = mb;
       i != 0;
       i = i->cont ())
    {
      size_t const length = i->length ();

      // If the mb does not own its data we are forced to make a copy.
      if (ACE_BIT_ENABLED (i->flags (),
                           ACE_Message_Block::DONT_DELETE))
        {
          if (! this->write_array (i->rd_ptr (),
                                   ACE_CDR::OCTET_SIZE,
                                   ACE_CDR::OCTET_ALIGN,
                                   static_cast<ACE_CDR::ULong> (length)))
            return (this->good_bit_ = false);
          continue;
        }

      if (length < this->memcpy_tradeoff_
          && this->current_->wr_ptr () + length < this->current_->end ())
        {
          if (! this->write_array (i->rd_ptr (),
                                   ACE_CDR::OCTET_SIZE,
                                   ACE_CDR::OCTET_ALIGN,
                                   static_cast<ACE_CDR::ULong> (length)))
            return (this->good_bit_ = false);
          continue;
        }

      ACE_Message_Block* cont = 0;
      this->good_bit_ = false;
      ACE_NEW_RETURN (cont,
                      ACE_Message_Block (i->data_block ()->duplicate ()),
                      false);
      this->good_bit_ = true;

      if (this->current_->cont () != 0)
        ACE_Message_Block::release (this->current_->cont ());
      cont->rd_ptr (i->rd_ptr ());
      cont->wr_ptr (i->wr_ptr ());

      this->current_->cont (cont);
      this->current_ = cont;
      this->current_is_writable_ = false;
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
      this->current_alignment_ =
        (this->current_alignment_ + cont->length ()) % ACE_CDR::MAX_ALIGNMENT;
#endif /* ACE_LACKS_CDR_ALIGNMENT */
    }

  return true;
}

ACE_CDR::Boolean
ACE_OutputCDR::write_1 (const ACE_CDR::Octet *x)
{
  char *buf = 0;
  if (this->adjust (1, buf) == 0)
    {
      *reinterpret_cast<ACE_CDR::Octet*> (buf) = *x;
      return true;
    }

  return false;
}

ACE_CDR::Boolean
ACE_OutputCDR::write_2 (const ACE_CDR::UShort *x)
{
  char *buf = 0;
  if (this->adjust (ACE_CDR::SHORT_SIZE, buf) == 0)
    {
#if !defined (ACE_ENABLE_SWAP_ON_WRITE)
      *reinterpret_cast<ACE_CDR::UShort*> (buf) = *x;
      return true;
#else
      if (!this->do_byte_swap_)
        {
          *reinterpret_cast<ACE_CDR::UShort *> (buf) = *x;
          return true;
        }
      else
        {
          ACE_CDR::swap_2 (reinterpret_cast<const char*> (x), buf);
          return true;
        }
#endif /* ACE_ENABLE_SWAP_ON_WRITE */
    }

  return false;
}

ACE_CDR::Boolean
ACE_OutputCDR::write_4 (const ACE_CDR::ULong *x)
{
  char *buf = 0;
  if (this->adjust (ACE_CDR::LONG_SIZE, buf) == 0)
    {
#if !defined (ACE_ENABLE_SWAP_ON_WRITE)
      *reinterpret_cast<ACE_CDR::ULong*> (buf) = *x;
      return true;
#else
      if (!this->do_byte_swap_)
        {
          *reinterpret_cast<ACE_CDR::ULong *> (buf) = *x;
          return true;
        }
      else
        {
          ACE_CDR::swap_4 (reinterpret_cast<const char*> (x), buf);
          return true;
        }
#endif /* ACE_ENABLE_SWAP_ON_WRITE */
    }

  return false;
}

ACE_CDR::Boolean
ACE_OutputCDR::write_8 (const ACE_CDR::ULongLong *x)
{
  char *buf = 0;

  if (this->adjust (ACE_CDR::LONGLONG_SIZE, buf) == 0)
    {
#if defined (__arm__)
      // Convert to Intel format (12345678 => 56781234)
      const char *orig = reinterpret_cast<const char *> (x);
      char *target = buf;
      register ACE_UINT32 x =
        *reinterpret_cast<const ACE_UINT32 *> (orig);
      register ACE_UINT32 y =
        *reinterpret_cast<const ACE_UINT32 *> (orig + 4);
      *reinterpret_cast<ACE_UINT32 *> (target) = y;
      *reinterpret_cast<ACE_UINT32 *> (target + 4) = x;
      return true;
#else
#  if !defined (ACE_ENABLE_SWAP_ON_WRITE)
      *reinterpret_cast<ACE_CDR::ULongLong *> (buf) = *x;
      return true;
#  else
      if (!this->do_byte_swap_)
        {
          *reinterpret_cast<ACE_CDR::ULongLong *> (buf) = *x;
          return true;
        }
      else
        {
          ACE_CDR::swap_8 (reinterpret_cast<const char*> (x), buf);
          return true;
        }
#  endif /* ACE_ENABLE_SWAP_ON_WRITE */
#endif /* !__arm__ */
     }

  return false;
}

ACE_CDR::Boolean
ACE_OutputCDR::write_16 (const ACE_CDR::LongDouble *x)
{
  char* buf = 0;
  if (this->adjust (ACE_CDR::LONGDOUBLE_SIZE,
                    ACE_CDR::LONGDOUBLE_ALIGN,
                    buf) == 0)
    {
#if !defined (ACE_ENABLE_SWAP_ON_WRITE)
      *reinterpret_cast<ACE_CDR::LongDouble*> (buf) = *x;
      return 1;
#else
      if (!this->do_byte_swap_)
        {
          *reinterpret_cast<ACE_CDR::LongDouble *> (buf) = *x;
          return true;
        }
      else
        {
          ACE_CDR::swap_16 (reinterpret_cast<const char*> (x), buf);
          return true;
        }
#endif /* ACE_ENABLE_SWAP_ON_WRITE */
    }

  return false;
}

ACE_CDR::Boolean
ACE_OutputCDR::write_wchar_array_i (const ACE_CDR::WChar *x,
                                    ACE_CDR::ULong length)
{
  if (length == 0)
    return true;
  char* buf = 0;
  size_t const align = (ACE_OutputCDR::wchar_maxbytes_ == 2) ?
    ACE_CDR::SHORT_ALIGN :
    ACE_CDR::OCTET_ALIGN;

  if (this->adjust (ACE_OutputCDR::wchar_maxbytes_ * length, align, buf) == 0)
    {
      if (ACE_OutputCDR::wchar_maxbytes_ == 2)
        {
          ACE_CDR::UShort *sb = reinterpret_cast<ACE_CDR::UShort *> (buf);
          for (size_t i = 0; i < length; ++i)
#if !defined (ACE_ENABLE_SWAP_ON_WRITE)
            sb[i] = static_cast<ACE_CDR::UShort> (x[i]);
#else
              if (!this->do_byte_swap_)
              sb[i] = static_cast<ACE_CDR::UShort> (x[i]);
            else
              {
                ACE_CDR::UShort sx = static_cast<ACE_CDR::UShort> (x[i]);
                ACE_CDR::swap_2 (reinterpret_cast<char *> (&sx), &buf[i * 2]);
              }
#endif /* ACE_ENABLE_SWAP_ON_WRITE */
        }
      else
        {
          for (size_t i = 0; i < length; ++i)
            buf[i] = static_cast<char> (x[i]);
        }
      return this->good_bit_;
    }
  return false;
}

ACE_CDR::Boolean
ACE_OutputCDR::write_array (const void *x,
                            size_t size,
                            size_t align,
                            ACE_CDR::ULong length)
{
  if (length == 0)
    return true;
  char *buf = 0;
  if (this->adjust (size * length, align, buf) == 0)
    {
#if !defined (ACE_ENABLE_SWAP_ON_WRITE)
      ACE_OS::memcpy (buf, x, size*length);
      return true;
#else
      if (!this->do_byte_swap_ || size == 1)
        {
          ACE_OS::memcpy (buf, x, size*length);
          return true;
        }
      else
        {
          const char *source = reinterpret_cast<const char *> (x);
          switch (size)
            {
            case 2:
              ACE_CDR::swap_2_array (source, buf, length);
              return true;
            case 4:
              ACE_CDR::swap_4_array (source, buf, length);
              return true;
            case 8:
              ACE_CDR::swap_8_array (source, buf, length);
              return true;
            case 16:
              ACE_CDR::swap_16_array (source, buf, length);
              return true;
            default:
              // TODO: print something?
              this->good_bit_ = false;
              return false;
            }
        }
#endif /* ACE_ENABLE_SWAP_ON_WRITE */
    }
  this->good_bit_ = false;
  return false;
}

ACE_CDR::Boolean
ACE_OutputCDR::write_boolean_array (const ACE_CDR::Boolean* x,
                                    ACE_CDR::ULong length)
{
  // It is hard to optimize this, the spec requires that on the wire
  // booleans be represented as a byte with value 0 or 1, but in
  // memory it is possible (though very unlikely) that a boolean has
  // a non-zero value (different from 1).
  // We resort to a simple loop.
  ACE_CDR::Boolean const * const end = x + length;

  for (ACE_CDR::Boolean const * i = x;
       i != end && this->good_bit ();
       ++i)
    (void) this->write_boolean (*i);

  return this->good_bit ();
}

char *
ACE_OutputCDR::write_long_placeholder (void)
{
  char *buf = 0;
  if (this->adjust (ACE_CDR::LONG_SIZE, buf) == 0)
    *reinterpret_cast<ACE_CDR::ULong*> (buf) = 0;
  else
    buf = 0;
  return buf;
}

char *
ACE_OutputCDR::write_short_placeholder (void)
{
  char *buf = 0;
  if (this->adjust (ACE_CDR::SHORT_SIZE, buf) == 0)
    *reinterpret_cast<ACE_CDR::UShort*> (buf) = 0;
  else
    buf = 0;
  return buf;
}

ACE_CDR::Boolean
ACE_OutputCDR::replace (ACE_CDR::Long x, char* loc)
{
  if (this->find (loc) == 0)
    return false;

#if !defined (ACE_ENABLE_SWAP_ON_WRITE)
  *reinterpret_cast<ACE_CDR::Long*> (loc) = x;
#else
  if (!this->do_byte_swap_)
  {
    *reinterpret_cast<ACE_CDR::Long *> (loc) = x;
  }
  else
  {
    ACE_CDR::swap_4 (reinterpret_cast<const char*> (&x), loc);
  }
#endif /* ACE_ENABLE_SWAP_ON_WRITE */

  return true;
}

ACE_CDR::Boolean
ACE_OutputCDR::replace (ACE_CDR::Short x, char* loc)
{
  if (this->find (loc) == 0)
    return false;

#if !defined (ACE_ENABLE_SWAP_ON_WRITE)
  *reinterpret_cast<ACE_CDR::Short*> (loc) = x;
#else
  if (!this->do_byte_swap_)
  {
    *reinterpret_cast<ACE_CDR::Short *> (loc) = x;
  }
  else
  {
    ACE_CDR::swap_2 (reinterpret_cast<const char*> (&x), loc);
  }
#endif /* ACE_ENABLE_SWAP_ON_WRITE */

  return true;
}

int
ACE_OutputCDR::consolidate (void)
{
  // Optimize by only doing something if we need to
  if (this->current_ != &this->start_)
    {
      // Set the number of bytes in the top-level block, reallocating
      // if necessary.  The rd_ptr and wr_ptr remain at the original offsets
      // into the buffer, even if it is reallocated.
      // Return an error if the allocation failed.
      size_t const newsize =
        ACE_CDR::first_size (this->total_length ()
                             + ACE_CDR::MAX_ALIGNMENT);
      if (this->start_.size (newsize) < 0)
        {
          return -1;
        }

      // Consolidate the chain into the first block.  NOTE that
      // ACE_CDR::consolidate can not be used since we don't want to
      // overwrite what is already in the first block. We just append it since
      // the read and write pointers weren't affected by the resizing above.
      // We also don't have to worry about alignment since the start block is
      // already aligned.
      // NOTE also we know there is a continuation since we checked for it
      // above.  There is therefore no reason to check for a 0 continuation
      // field here.
      ACE_Message_Block *cont = this->start_.cont ();
      for (const ACE_Message_Block* i = cont; i != 0; i = i->cont ())
        {
          this->start_.copy (i->rd_ptr (), i->length ());
        }

      // Release the old blocks that were consolidated and reset the
      // current_ and current_is_writable_ to reflect the single used block.
      ACE_Message_Block::release (cont);
      this->start_.cont (0);
      this->current_ = &this->start_;
      this->current_is_writable_ = true;
    }

  return 0;
}

ACE_Message_Block*
ACE_OutputCDR::find (char* loc)
{
  ACE_Message_Block* mb = 0;
  for (mb = &this->start_; mb != 0; mb = mb->cont ())
  {
    if (loc <= mb->wr_ptr () && loc >= mb->rd_ptr ())
    {
      break;
    }
  }

  return mb;
}

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)

void
ACE_OutputCDR::register_monitor (const char *id)
{
  this->monitor_->name (id);
  this->monitor_->add_to_registry ();
}

void
ACE_OutputCDR::unregister_monitor (void)
{
  this->monitor_->remove_from_registry ();
}

#endif /* ACE_HAS_MONITOR_POINTS==1 */

// ****************************************************************

ACE_InputCDR::ACE_InputCDR (const char *buf,
                            size_t bufsiz,
                            int byte_order,
                            ACE_CDR::Octet major_version,
                            ACE_CDR::Octet minor_version)
  : start_ (buf, bufsiz),
    do_byte_swap_ (byte_order != ACE_CDR_BYTE_ORDER),
    good_bit_ (true),
    major_version_ (major_version),
    minor_version_ (minor_version),
    char_translator_ (0),
    wchar_translator_ (0)
{
  this->start_.wr_ptr (bufsiz);

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (bufsiz);
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_InputCDR::ACE_InputCDR (size_t bufsiz,
                            int byte_order,
                            ACE_CDR::Octet major_version,
                            ACE_CDR::Octet minor_version)
  : start_ (bufsiz),
    do_byte_swap_ (byte_order != ACE_CDR_BYTE_ORDER),
    good_bit_ (true),
    major_version_ (major_version),
    minor_version_ (minor_version),
    char_translator_ (0),
    wchar_translator_ (0)
{
#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (bufsiz);
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_InputCDR::ACE_InputCDR (const ACE_Message_Block *data,
                            int byte_order,
                            ACE_CDR::Octet major_version,
                            ACE_CDR::Octet minor_version,
                            ACE_Lock* lock)
  : start_ (0, ACE_Message_Block::MB_DATA, 0, 0, 0, lock),
    good_bit_ (true),
    major_version_ (major_version),
    minor_version_ (minor_version),
    char_translator_ (0),
    wchar_translator_ (0)
{
#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */

  this->reset (data, byte_order);
}

ACE_InputCDR::ACE_InputCDR (ACE_Data_Block *data,
                            ACE_Message_Block::Message_Flags flag,
                            int byte_order,
                            ACE_CDR::Octet major_version,
                            ACE_CDR::Octet minor_version)
  : start_ (data, flag),
    do_byte_swap_ (byte_order != ACE_CDR_BYTE_ORDER),
    good_bit_ (true),
    major_version_ (major_version),
    minor_version_ (minor_version),
    char_translator_ (0),
    wchar_translator_ (0)
{
#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (data->size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_InputCDR::ACE_InputCDR (ACE_Data_Block *data,
                            ACE_Message_Block::Message_Flags flag,
                            size_t rd_pos,
                            size_t wr_pos,
                            int byte_order,
                            ACE_CDR::Octet major_version,
                            ACE_CDR::Octet minor_version)
  : start_ (data, flag),
    do_byte_swap_ (byte_order != ACE_CDR_BYTE_ORDER),
    good_bit_ (true),
    major_version_ (major_version),
    minor_version_ (minor_version),
    char_translator_ (0),
    wchar_translator_ (0)
{
  // Set the read pointer
  this->start_.rd_ptr (rd_pos);

  // Set the write pointer after doing a sanity check.
  char* wrpos = this->start_.base () + wr_pos;

  if (this->start_.end () >= wrpos)
    {
      this->start_.wr_ptr (wr_pos);
    }

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (data->size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_InputCDR::ACE_InputCDR (const ACE_InputCDR& rhs,
                            size_t size,
                            ACE_CDR::Long offset)
  : start_ (rhs.start_,
            ACE_CDR::MAX_ALIGNMENT),
    do_byte_swap_ (rhs.do_byte_swap_),
    good_bit_ (true),
    major_version_ (rhs.major_version_),
    minor_version_ (rhs.minor_version_),
    char_translator_ (rhs.char_translator_),
    wchar_translator_ (rhs.wchar_translator_)
{
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  // Align the base pointer assuming that the incoming stream is also
  // aligned the way we are aligned
  char *incoming_start = ACE_ptr_align_binary (rhs.start_.base (),
                                               ACE_CDR::MAX_ALIGNMENT);
#else
  char *incoming_start = rhs.start_.base ();
#endif /* ACE_LACKS_CDR_ALIGNMENT */

  const size_t newpos =
    (rhs.start_.rd_ptr() - incoming_start)  + offset;

  if (newpos <= this->start_.space ()
      && newpos + size <= this->start_.space ())
    {
      this->start_.rd_ptr (newpos);
      this->start_.wr_ptr (newpos + size);
    }
  else
    {
      this->good_bit_ = false;
    }

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_InputCDR::ACE_InputCDR (const ACE_InputCDR& rhs,
                            size_t size)
  : start_ (rhs.start_,
            ACE_CDR::MAX_ALIGNMENT),
    do_byte_swap_ (rhs.do_byte_swap_),
    good_bit_ (true),
    major_version_ (rhs.major_version_),
    minor_version_ (rhs.minor_version_),
    char_translator_ (rhs.char_translator_),
    wchar_translator_ (rhs.wchar_translator_)
{
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  // Align the base pointer assuming that the incoming stream is also
  // aligned the way we are aligned
  char *incoming_start = ACE_ptr_align_binary (rhs.start_.base (),
                                               ACE_CDR::MAX_ALIGNMENT);
#else
  char *incoming_start = rhs.start_.base ();
#endif /* ACE_LACKS_CDR_ALIGNMENT */

  const size_t newpos =
    rhs.start_.rd_ptr() - incoming_start;

  if (newpos <= this->start_.space ()
      && newpos + size <= this->start_.space ())
    {
      // Notice that ACE_Message_Block::duplicate may leave the
      // wr_ptr() with a higher value than what we actually want.
      this->start_.rd_ptr (newpos);
      this->start_.wr_ptr (newpos + size);

      ACE_CDR::Octet byte_order = 0;
      (void) this->read_octet (byte_order);
      this->do_byte_swap_ = (byte_order != ACE_CDR_BYTE_ORDER);
    }
  else
    {
      this->good_bit_ = false;
    }

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_InputCDR::ACE_InputCDR (const ACE_InputCDR& rhs)
  : start_ (rhs.start_,
            ACE_CDR::MAX_ALIGNMENT),
    do_byte_swap_ (rhs.do_byte_swap_),
    good_bit_ (true),
    major_version_ (rhs.major_version_),
    minor_version_ (rhs.minor_version_),
    char_translator_ (rhs.char_translator_),
    wchar_translator_ (rhs.wchar_translator_)
{
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
  char *buf = ACE_ptr_align_binary (rhs.start_.base (),
                                    ACE_CDR::MAX_ALIGNMENT);
#else
  char *buf = rhs.start_.base ();
#endif /* ACE_LACKS_CDR_ALIGNMENT */

  size_t rd_offset = rhs.start_.rd_ptr () - buf;
  size_t wr_offset = rhs.start_.wr_ptr () - buf;
  this->start_.rd_ptr (rd_offset);
  this->start_.wr_ptr (wr_offset);

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_InputCDR::ACE_InputCDR (ACE_InputCDR::Transfer_Contents x)
  : start_ (x.rhs_.start_.data_block ()),
    do_byte_swap_ (x.rhs_.do_byte_swap_),
    good_bit_ (true),
    major_version_ (x.rhs_.major_version_),
    minor_version_ (x.rhs_.minor_version_),
    char_translator_ (x.rhs_.char_translator_),
    wchar_translator_ (x.rhs_.wchar_translator_)
{
  this->start_.rd_ptr (x.rhs_.start_.rd_ptr ());
  this->start_.wr_ptr (x.rhs_.start_.wr_ptr ());

  ACE_Data_Block* db = this->start_.data_block ()->clone_nocopy ();
  (void) x.rhs_.start_.replace_data_block (db);

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_InputCDR&
ACE_InputCDR::operator= (const ACE_InputCDR& rhs)
{
  if (this != &rhs)
    {
      this->start_.data_block (rhs.start_.data_block ()->duplicate ());
      this->start_.rd_ptr (rhs.start_.rd_ptr ());
      this->start_.wr_ptr (rhs.start_.wr_ptr ());
      this->do_byte_swap_ = rhs.do_byte_swap_;
      this->good_bit_ = true;
      this->char_translator_ = rhs.char_translator_;
      this->major_version_ = rhs.major_version_;
      this->minor_version_ = rhs.minor_version_;
    }

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */

  return *this;
}

ACE_InputCDR::ACE_InputCDR (const ACE_OutputCDR& rhs,
                            ACE_Allocator* buffer_allocator,
                            ACE_Allocator* data_block_allocator,
                            ACE_Allocator* message_block_allocator)
  : start_ (rhs.total_length () + ACE_CDR::MAX_ALIGNMENT,
            ACE_Message_Block::MB_DATA,
            0,
            0,
            buffer_allocator,
            0,
            0,
            ACE_Time_Value::zero,
            ACE_Time_Value::max_time,
            data_block_allocator,
            message_block_allocator),
    do_byte_swap_ (rhs.do_byte_swap_),
    good_bit_ (true),
    major_version_ (rhs.major_version_),
    minor_version_ (rhs.minor_version_),
    char_translator_ (rhs.char_translator_),
    wchar_translator_ (rhs.wchar_translator_)
{
  ACE_CDR::mb_align (&this->start_);
  for (const ACE_Message_Block *i = rhs.begin ();
       i != rhs.end ();
       i = i->cont ())
    {
      this->start_.copy (i->rd_ptr (), i->length ());
    }

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_CDR::Boolean
ACE_InputCDR::skip_wchar (void)
{
  if (static_cast<ACE_CDR::Short> (major_version_) == 1
      && static_cast<ACE_CDR::Short> (minor_version_) == 2)
    {
      ACE_CDR::Octet len;
      if (this->read_1 (&len))
        return this->skip_bytes (static_cast<size_t> (len));
    }
  else
    {
      ACE_CDR::WChar x;
      void * const temp = &x;
      if (ACE_OutputCDR::wchar_maxbytes_ == 2)
        return this->read_2 (reinterpret_cast<ACE_CDR::UShort *> (temp));
      else
        return this->read_4 (reinterpret_cast<ACE_CDR::ULong *> (temp));
    }

  return (this->good_bit_ = false);
}

ACE_CDR::Boolean
ACE_InputCDR::read_wchar (ACE_CDR::WChar& x)
{
  if (this->wchar_translator_ != 0)
    {
      this->good_bit_ = this->wchar_translator_->read_wchar (*this,x);
      return this->good_bit_;
    }
  if (ACE_OutputCDR::wchar_maxbytes_ == 0)
    {
      errno = EACCES;
      return (this->good_bit_ = false);
    }

  if (ACE_OutputCDR::wchar_maxbytes_ == sizeof (ACE_CDR::WChar))
    {
      if (static_cast<ACE_CDR::Short> (major_version_) == 1
          && static_cast<ACE_CDR::Short> (minor_version_) == 2)
        {
          ACE_CDR::Octet len;

          if (this->read_1 (&len))
            return this->read_array
              (reinterpret_cast<ACE_CDR::Octet*> (&x),
               static_cast<ACE_CDR::ULong> (len),
               ACE_CDR::OCTET_ALIGN,
               1);

          else
            return (this->good_bit_ = false);
        }

      void * const temp = &x;
      if (sizeof (ACE_CDR::WChar) == 2)
        return this->read_2 (reinterpret_cast<ACE_CDR::UShort *> (temp));
      else
        return this->read_4 (reinterpret_cast<ACE_CDR::ULong *> (temp));
    }

  if (static_cast<ACE_CDR::Short> (major_version_) == 1
      && static_cast<ACE_CDR::Short> (minor_version_) == 2)
    {
      ACE_CDR::Octet len;

      if (this->read_1 (&len))
        {
          if (len == 2)
            {
              ACE_CDR::Short sx;
              if (this->read_array
                  (reinterpret_cast<ACE_CDR::Octet*> (&sx),
                   static_cast<ACE_CDR::ULong> (len),
                   ACE_CDR::OCTET_ALIGN,
                   1))
                {
                  x = static_cast<ACE_CDR::WChar> (sx);
                  return true;
                }
            }
          else
            {
              ACE_CDR::Octet ox;
              if (this->read_array
                  (reinterpret_cast<ACE_CDR::Octet*> (&ox),
                   static_cast<ACE_CDR::ULong> (len),
                   ACE_CDR::OCTET_ALIGN,
                   1))
                {
                  x = static_cast<ACE_CDR::WChar> (ox);
                  return true;
                }
            }
        }
    }
  else
    {
      if (ACE_OutputCDR::wchar_maxbytes_ == 2)
        {
          ACE_CDR::UShort sx;
          if (this->read_2 (reinterpret_cast<ACE_CDR::UShort *> (&sx)))
            {
              x = static_cast<ACE_CDR::WChar> (sx);
              return true;
            }
        }
      else
        {
          ACE_CDR::Octet ox;
          if (this->read_1 (&ox))
            {
              x = static_cast<ACE_CDR::WChar> (ox);
              return true;
            }

        }
    }
  return (this->good_bit_ = false);
}

ACE_CDR::Boolean
ACE_InputCDR::read_string (ACE_CDR::Char *&x)
{
  // @@ This is a slight violation of "Optimize for the common case",
  // i.e. normally the translator will be 0, but OTOH the code is
  // smaller and should be better for the cache ;-) ;-)
  if (this->char_translator_ != 0)
    {
      this->good_bit_ = this->char_translator_->read_string (*this, x);
      return this->good_bit_;
    }

  ACE_CDR::ULong len = 0;

  if (!this->read_ulong (len))
    return false;

  // A check for the length being too great is done later in the
  // call to read_char_array but we want to have it done before
  // the memory is allocated.
  if (len > 0 && len <= this->length())
    {
      ACE_NEW_RETURN (x,
                      ACE_CDR::Char[len],
                      0);

      ACE_Auto_Basic_Array_Ptr<ACE_CDR::Char> safe_data (x);

      if (this->read_char_array (x, len))
        {
          (void) safe_data.release ();
          return true;
        }
    }
  else if (len == 0)
    {
      // Convert any null strings to empty strings since empty
      // strings can cause crashes. (See bug 58.)
      ACE_NEW_RETURN (x,
                      ACE_CDR::Char[1],
                      0);
      ACE_OS::strcpy (const_cast<char *&> (x), "");
      return true;
    }

  x = 0;
  return (this->good_bit_ = false);
}

ACE_CDR::Boolean
ACE_InputCDR::read_string (ACE_CString &x)
{
  ACE_CDR::Char * data = 0;
  if (this->read_string (data))
    {
      ACE_Auto_Basic_Array_Ptr<ACE_CDR::Char> safe_data (data);
      x = data;
      return true;
    }

  x = "";
  return (this->good_bit_ = false);
}

ACE_CDR::Boolean
ACE_InputCDR::read_wstring (ACE_CDR::WChar*& x)
{
  // @@ This is a slight violation of "Optimize for the common case",
  // i.e. normally the translator will be 0, but OTOH the code is
  // smaller and should be better for the cache ;-) ;-)
  if (this->wchar_translator_ != 0)
    {
      this->good_bit_ = this->wchar_translator_->read_wstring (*this, x);
      return this->good_bit_;
    }
  if (ACE_OutputCDR::wchar_maxbytes_ == 0)
    {
      errno = EACCES;
      return (this->good_bit_ = false);
    }

  ACE_CDR::ULong len = 0;

  if (!this->read_ulong (len))
    {
      return false;
    }

  // A check for the length being too great is done later in the
  // call to read_char_array but we want to have it done before
  // the memory is allocated.
  if (len > 0 && len <= this->length ())
    {
      ACE_Auto_Basic_Array_Ptr<ACE_CDR::WChar> safe_data;

      if (static_cast<ACE_CDR::Short> (this->major_version_) == 1
          && static_cast<ACE_CDR::Short> (this->minor_version_) == 2)
        {
          len /=
            ACE_Utils::truncate_cast<ACE_CDR::ULong> (
              ACE_OutputCDR::wchar_maxbytes_);

          //allocating one extra for the null character needed by applications
          ACE_NEW_RETURN (x,
                          ACE_CDR::WChar [len + 1],
                          false);

          ACE_auto_ptr_reset (safe_data, x);

          if (this->read_wchar_array (x, len))
            {

              //Null character used by applications to find the end of
              //the wstring
              //Is this okay with the GIOP 1.2 spec??
              x[len] = '\x00';

              (void) safe_data.release ();

              return true;
            }
        }
      else
        {
          ACE_NEW_RETURN (x,
                          ACE_CDR::WChar [len],
                          false);

          ACE_auto_ptr_reset (safe_data, x);

          if (this->read_wchar_array (x, len))
            {
              (void) safe_data.release ();

              return true;
            }
        }
    }
  else if (len == 0)
    {
      // Convert any null strings to empty strings since empty
      // strings can cause crashes. (See bug 58.)
      ACE_NEW_RETURN (x,
                      ACE_CDR::WChar[1],
                      false);
      x[0] = '\x00';
      return true;
    }

  this->good_bit_ = false;
  x = 0;
  return false;
}

ACE_CDR::Boolean
ACE_InputCDR::read_array (void* x,
                          size_t size,
                          size_t align,
                          ACE_CDR::ULong length)
{
  if (length == 0)
    return true;
  char* buf = 0;

  if (this->adjust (size * length, align, buf) == 0)
    {
#if defined (ACE_DISABLE_SWAP_ON_READ)
      ACE_OS::memcpy (x, buf, size*length);
#else
      if (!this->do_byte_swap_ || size == 1)
        ACE_OS::memcpy (x, buf, size*length);
      else
        {
          char *target = reinterpret_cast<char*> (x);
          switch (size)
            {
            case 2:
              ACE_CDR::swap_2_array (buf, target, length);
              break;
            case 4:
              ACE_CDR::swap_4_array (buf, target, length);
              break;
            case 8:
              ACE_CDR::swap_8_array (buf, target, length);
              break;
            case 16:
              ACE_CDR::swap_16_array (buf, target, length);
              break;
            default:
              // TODO: print something?
              this->good_bit_ = false;
              return false;
            }
        }
#endif /* ACE_DISABLE_SWAP_ON_READ */
      return this->good_bit_;
    }
  return false;
}

ACE_CDR::Boolean
ACE_InputCDR::read_wchar_array_i (ACE_CDR::WChar* x,
                                  ACE_CDR::ULong length)
{
  if (length == 0)
    return true;
  char* buf = 0;
  size_t const align = (ACE_OutputCDR::wchar_maxbytes_ == 2) ?
    ACE_CDR::SHORT_ALIGN :
    ACE_CDR::OCTET_ALIGN;

  if (this->adjust (ACE_OutputCDR::wchar_maxbytes_ * length, align, buf) == 0)
    {
      if (ACE_OutputCDR::wchar_maxbytes_ == 2)
        {
          ACE_CDR::UShort *sb = reinterpret_cast<ACE_CDR::UShort *> (buf);
          for (size_t i = 0; i < length; ++i)
#if defined (ACE_DISABLE_SWAP_ON_READ)
            x[i] = static_cast<ACE_CDR::WChar> (sb[i]);
#else
            if (!this->do_byte_swap_)
              x[i] = static_cast<ACE_CDR::WChar> (sb[i]);
            else
              {
                ACE_CDR::UShort sx;
                ACE_CDR::swap_2 (&buf[i * 2], reinterpret_cast<char *> (&sx));
                x[i] = static_cast<ACE_CDR::WChar> (sx);
              }
#endif /* ACE_DISABLE_SWAP_ON_READ */
        }
      else
        {
          for (size_t i = 0; i < length; ++i)
            x[i] = static_cast<ACE_CDR::Octet> (buf[i]);
        }
      return this->good_bit_;
    }
  return false;
}

ACE_CDR::Boolean
ACE_InputCDR::read_boolean_array (ACE_CDR::Boolean *x,
                                  ACE_CDR::ULong length)
{
  // Make sure the length of the array isn't greater than the length of
  // the stream.
  if (length > this->length ())
    {
      this->good_bit_ = false;
      return false;
    }

  // It is hard to optimize this, the spec requires that on the wire
  // booleans be represented as a byte with value 0 or 1, but in
  // memory it is possible (though very unlikely) that a boolean has
  // a non-zero value (different from 1).
  // We resort to a simple loop.
  for (ACE_CDR::ULong i = 0; i != length && this->good_bit_; ++i)
    (void) this->read_boolean (x[i]);

  return this->good_bit_;
}

ACE_CDR::Boolean
ACE_InputCDR::read_1 (ACE_CDR::Octet *x)
{
  if (this->rd_ptr () < this->wr_ptr ())
    {
      *x = *reinterpret_cast<ACE_CDR::Octet*> (this->rd_ptr ());
      this->start_.rd_ptr (1);
      return true;
    }

  this->good_bit_ = false;
  return false;
}

ACE_CDR::Boolean
ACE_InputCDR::read_2 (ACE_CDR::UShort *x)
{
  char *buf = 0;
  if (this->adjust (ACE_CDR::SHORT_SIZE, buf) == 0)
    {
#if !defined (ACE_DISABLE_SWAP_ON_READ)
      if (!this->do_byte_swap_)
        *x = *reinterpret_cast<ACE_CDR::UShort*> (buf);
      else
        ACE_CDR::swap_2 (buf, reinterpret_cast<char*> (x));
#else
      *x = *reinterpret_cast<ACE_CDR::UShort*> (buf);
#endif /* ACE_DISABLE_SWAP_ON_READ */
      return true;
    }
  this->good_bit_ = false;
  return false;
}

ACE_CDR::Boolean
ACE_InputCDR::read_4 (ACE_CDR::ULong *x)
{
  char *buf = 0;
  if (this->adjust (ACE_CDR::LONG_SIZE, buf) == 0)
    {
#if !defined (ACE_DISABLE_SWAP_ON_READ)
      if (!this->do_byte_swap_)
        *x = *reinterpret_cast<ACE_CDR::ULong*> (buf);
      else
        ACE_CDR::swap_4 (buf, reinterpret_cast<char*> (x));
#else
      *x = *reinterpret_cast<ACE_CDR::ULong*> (buf);
#endif /* ACE_DISABLE_SWAP_ON_READ */
      return true;
    }
  this->good_bit_ = false;
  return false;
}

ACE_CDR::Boolean
ACE_InputCDR::read_8 (ACE_CDR::ULongLong *x)
{
  char *buf = 0;

  if (this->adjust (ACE_CDR::LONGLONG_SIZE, buf) == 0)
    {
#if !defined (ACE_DISABLE_SWAP_ON_READ)
#  if defined (__arm__)
      if (!this->do_byte_swap_)
        {
          // Convert from Intel format (12345678 => 56781234)
          const char *orig = buf;
          char *target = reinterpret_cast<char *> (x);
          register ACE_UINT32 x =
            *reinterpret_cast<const ACE_UINT32 *> (orig);
          register ACE_UINT32 y =
            *reinterpret_cast<const ACE_UINT32 *> (orig + 4);
          *reinterpret_cast<ACE_UINT32 *> (target) = y;
          *reinterpret_cast<ACE_UINT32 *> (target + 4) = x;
        }
      else
        {
          // Convert from Sparc format (12345678 => 43218765)
          const char *orig = buf;
          char *target = reinterpret_cast<char *> (x);
          register ACE_UINT32 x =
            *reinterpret_cast<const ACE_UINT32 *> (orig);
          register ACE_UINT32 y =
            *reinterpret_cast<const ACE_UINT32 *> (orig + 4);
          x = (x << 24) | ((x & 0xff00) << 8) | ((x & 0xff0000) >> 8) | (x >> 24);
          y = (y << 24) | ((y & 0xff00) << 8) | ((y & 0xff0000) >> 8) | (y >> 24);
          *reinterpret_cast<ACE_UINT32 *> (target) = x;
          *reinterpret_cast<ACE_UINT32 *> (target + 4) = y;
        }
#  else
      if (!this->do_byte_swap_)
        *x = *reinterpret_cast<ACE_CDR::ULongLong *> (buf);
      else
        ACE_CDR::swap_8 (buf, reinterpret_cast<char *> (x));
#  endif /* !__arm__ */
#else
      *x = *reinterpret_cast<ACE_CDR::ULongLong *> (buf);
#endif /* ACE_DISABLE_SWAP_ON_READ */
      return true;
    }

  this->good_bit_ = false;
  return false;
}

ACE_CDR::Boolean
ACE_InputCDR::read_16 (ACE_CDR::LongDouble *x)
{
  char *buf = 0;
  if (this->adjust (ACE_CDR::LONGDOUBLE_SIZE,
                    ACE_CDR::LONGDOUBLE_ALIGN,
                    buf) == 0)
    {
#if !defined (ACE_DISABLE_SWAP_ON_READ)
      if (!this->do_byte_swap_)
        *x = *reinterpret_cast<ACE_CDR::LongDouble *> (buf);
      else
        ACE_CDR::swap_16 (buf, reinterpret_cast<char*> (x));
#else
      *x = *reinterpret_cast<ACE_CDR::LongDouble*> (buf);
#endif /* ACE_DISABLE_SWAP_ON_READ */
      return true;
    }

  this->good_bit_ = false;
  return false;
}

ACE_CDR::Boolean
ACE_InputCDR::skip_string (void)
{
  ACE_CDR::ULong len = 0;
  if (this->read_ulong (len))
    {
      if (this->rd_ptr () + len <= this->wr_ptr ())
        {
          this->rd_ptr (len);
          return true;
        }
      this->good_bit_ = false;
    }
  return false;
}

ACE_CDR::Boolean
ACE_InputCDR::skip_wstring (void)
{
  ACE_CDR::ULong len = 0;
  ACE_CDR::Boolean continue_skipping = read_ulong (len);

  if (continue_skipping && len != 0)
    {
      if (static_cast<ACE_CDR::Short> (this->major_version_) == 1
            && static_cast<ACE_CDR::Short> (this->minor_version_) == 2)
          continue_skipping = this->skip_bytes ((size_t)len);
      else
        while (continue_skipping && len--)
          continue_skipping = this->skip_wchar ();
    }
  return continue_skipping;
}

ACE_CDR::Boolean
ACE_InputCDR::skip_bytes (size_t len)
{
  if (this->rd_ptr () + len <= this->wr_ptr ())
    {
      this->rd_ptr (len);
      return true;
    }
  this->good_bit_ = false;
  return false;
}

int
ACE_InputCDR::grow (size_t newsize)
{
  if (ACE_CDR::grow (&this->start_, newsize) == -1)
    return -1;

  ACE_CDR::mb_align (&this->start_);
  this->start_.wr_ptr (newsize);

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  if (newsize > this->start_.total_size ())
    {
      this->monitor_->receive (newsize);
    }
#endif /* ACE_HAS_MONITOR_POINTS==1 */

  return 0;
}

void
ACE_InputCDR::reset (const ACE_Message_Block* data,
                     int byte_order)
{
  this->reset_byte_order (byte_order);
  ACE_CDR::consolidate (&this->start_, data);

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

void
ACE_InputCDR::steal_from (ACE_InputCDR &cdr)
{
  this->do_byte_swap_ = cdr.do_byte_swap_;
  this->start_.data_block (cdr.start_.data_block ()->duplicate ());

  // If the message block had a DONT_DELETE flags, just clear it off..
  this->start_.clr_self_flags (ACE_Message_Block::DONT_DELETE);
  this->start_.rd_ptr (cdr.start_.rd_ptr ());

  this->start_.wr_ptr (cdr.start_.wr_ptr ());
  this->major_version_ = cdr.major_version_;
  this->minor_version_ = cdr.minor_version_;
  cdr.reset_contents ();

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

void
ACE_InputCDR::exchange_data_blocks (ACE_InputCDR &cdr)
{
  // Exchange byte orders
  int const byte_order = cdr.do_byte_swap_;
  cdr.do_byte_swap_ = this->do_byte_swap_;
  this->do_byte_swap_ = byte_order;

  // Get the destination read and write pointers
  size_t const drd_pos =
    cdr.start_.rd_ptr () - cdr.start_.base ();
  size_t const dwr_pos =
    cdr.start_.wr_ptr () - cdr.start_.base ();

  // Get the source read & write pointers
  size_t const srd_pos =
    this->start_.rd_ptr () - this->start_.base ();
  size_t const swr_pos =
    this->start_.wr_ptr () - this->start_.base ();

  // Exchange data_blocks. Dont release any of the data blocks.
  ACE_Data_Block *dnb =
    this->start_.replace_data_block (cdr.start_.data_block ());
  cdr.start_.replace_data_block (dnb);

  // Exchange the flags information..
  ACE_Message_Block::Message_Flags df = cdr.start_.self_flags ();
  ACE_Message_Block::Message_Flags sf = this->start_.self_flags ();

  cdr.start_.clr_self_flags (df);
  this->start_.clr_self_flags (sf);

  cdr.start_.set_self_flags (sf);
  this->start_.set_self_flags (df);

  // Reset the <cdr> pointers to zero before it is set again.
  cdr.start_.reset ();
  this->start_.reset ();

  // Set the read and write pointers.
  if (cdr.start_.size () >= srd_pos)
    {
      cdr.start_.rd_ptr (srd_pos);
    }

  if (cdr.start_.size () >= swr_pos)
    {
      cdr.start_.wr_ptr (swr_pos);
    }

  if (this->start_.size () >= drd_pos)
    {
      this->start_.rd_ptr (drd_pos);
    }

  if (this->start_.size () >= dwr_pos)
    {
      this->start_.wr_ptr (dwr_pos);
    }

  ACE_CDR::Octet const dmajor = cdr.major_version_;
  ACE_CDR::Octet const dminor = cdr.minor_version_;

  // Exchange the GIOP version info
  cdr.major_version_ = this->major_version_;
  cdr.minor_version_ = this->minor_version_;

  this->major_version_ = dmajor;
  this->minor_version_ = dminor;

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

ACE_Data_Block *
ACE_InputCDR::clone_from (ACE_InputCDR &cdr)
{
  this->do_byte_swap_ = cdr.do_byte_swap_;

  // Get the read & write pointer positions in the incoming CDR
  // streams
  char *rd_ptr = cdr.start_.rd_ptr ();
  char *wr_ptr = cdr.start_.wr_ptr ();

  // Now reset the incoming CDR stream
  cdr.start_.reset ();

  // As we have reset the stream, try to align the underlying message
  // block in the incoming stream
  ACE_CDR::mb_align (&cdr.start_);

  // Get the read & write pointer positions again
  char *nrd_ptr = cdr.start_.rd_ptr ();
  char *nwr_ptr = cdr.start_.wr_ptr ();

  // Actual length of the stream is..
  // @todo: This will look idiotic, but we dont seem to have much of a
  // choice. How do we calculate the length of the incoming stream?
  // Calling the method before calling reset () would give us the
  // wrong length of the stream that needs copying.  So we do the
  // calulation like this
  // (1) We get the <rd_ptr> and <wr_ptr> positions of the incoming
  // stream.
  // (2) Then we reset the <incoming> stream and then align it.
  // (3) We get the <rd_ptr> and <wr_ptr> positions again. (Points #1
  // thru #3 has been done already)
  // (4) The difference in the <rd_ptr> and <wr_ptr> positions gives
  // us the following, the actual bytes traversed by the <rd_ptr> and
  // <wr_ptr>.
  // (5) The bytes traversed by the <wr_ptr> is the actual length of
  // the stream.

  // Actual bytes traversed
  size_t rd_bytes = rd_ptr - nrd_ptr;
  size_t wr_bytes = wr_ptr - nwr_ptr;

  ACE_CDR::mb_align (&this->start_);

  ACE_Data_Block *db =
    this->start_.data_block ();

  // If the size of the data that needs to be copied are higher than
  // what is available, then do a reallocation.
  if (wr_bytes > (this->start_.size () - ACE_CDR::MAX_ALIGNMENT))
    {
      // @@NOTE: We need to probably add another method to the message
      // block interface to simplify this
      db =
        cdr.start_.data_block ()->clone_nocopy ();

      if (db == 0 || db->size ((wr_bytes) +
                               ACE_CDR::MAX_ALIGNMENT) == -1)
        return 0;

      // Replace our data block by using the incoming CDR stream.
      db = this->start_.replace_data_block (db);

      // Align the start_ message block.
      ACE_CDR::mb_align (&this->start_);

      // Clear the DONT_DELETE flag if it has been set
      this->start_.clr_self_flags (ACE_Message_Block::DONT_DELETE);
    }

  // Now do the copy
  (void) ACE_OS::memcpy (this->start_.wr_ptr (),
                         cdr.start_.rd_ptr (),
                         wr_bytes);

  // Set the read pointer position to the same point as that was in
  // <incoming> cdr.
  this->start_.rd_ptr (rd_bytes);
  this->start_.wr_ptr (wr_bytes);

  // We have changed the read & write pointers for the incoming
  // stream. Set them back to the positions that they were before..
  cdr.start_.rd_ptr (rd_bytes);
  cdr.start_.wr_ptr (wr_bytes);

  this->major_version_ = cdr.major_version_;
  this->minor_version_ = cdr.minor_version_;

  // Copy the char/wchar translators
  this->char_translator_ = cdr.char_translator_;
  this->wchar_translator_ = cdr.wchar_translator_;

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */

  return db;
}

ACE_Message_Block*
ACE_InputCDR::steal_contents (void)
{
  ACE_Message_Block* block = this->start_.clone ();
  this->start_.data_block (block->data_block ()->clone ());

  // If at all our message had a DONT_DELETE flag set, just clear it
  // off.
  this->start_.clr_self_flags (ACE_Message_Block::DONT_DELETE);

  ACE_CDR::mb_align (&this->start_);

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */

  return block;
}

void
ACE_InputCDR::reset_contents (void)
{
  this->start_.data_block (this->start_.data_block ()->clone_nocopy ());

  // Reset the flags...
  this->start_.clr_self_flags (ACE_Message_Block::DONT_DELETE);

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->start_.total_size ());
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)

void
ACE_InputCDR::register_monitor (const char *id)
{
  this->monitor_->name (id);
  this->monitor_->add_to_registry ();
}

void
ACE_InputCDR::unregister_monitor (void)
{
  this->monitor_->remove_from_registry ();
}

#endif /* ACE_HAS_MONITOR_POINTS==1 */

// --------------------------------------------------------------

ACE_Char_Codeset_Translator::~ACE_Char_Codeset_Translator (void)
{
}

// --------------------------------------------------------------

ACE_WChar_Codeset_Translator::~ACE_WChar_Codeset_Translator (void)
{
}

// --------------------------------------------------------------

ACE_CDR::Boolean
operator<< (ACE_OutputCDR &os, const ACE_CString &x)
{
  os.write_string (x);
  return os.good_bit ();
}

ACE_CDR::Boolean
operator>> (ACE_InputCDR &is, ACE_CString &x)
{
  is.read_string (x);
  return is.good_bit ();
}

#if defined (GEN_OSTREAM_OPS)

std::ostream&
operator<< (std::ostream &os, ACE_OutputCDR::from_boolean x)
{
  return (x.val_ ? os << "true" : os << "false");
}

std::ostream&
operator<< (std::ostream &os, ACE_OutputCDR::from_char x)
{
  return os << '\'' << x.val_ << '\'';
}

std::ostream&
operator<< (std::ostream &os, ACE_OutputCDR::from_wchar x)
{
  os.setf (ios_base::showbase);
  os.setf (ios_base::hex, ios_base::basefield);
  os << x.val_;
  os.unsetf (ios_base::showbase);
  os.setf (ios_base::dec, ios_base::basefield);
  return os;
}

std::ostream&
operator<< (std::ostream &os, ACE_OutputCDR::from_octet x)
{
  // Same format (hex) and no risk of overflow.
  ACE_CDR::WChar w = static_cast<ACE_CDR::WChar> (x.val_);
  ACE_OutputCDR::from_wchar tmp (w);
  return os << tmp;
}

#endif /* GEN_OSTREAM_OPS */

ACE_END_VERSIONED_NAMESPACE_DECL

