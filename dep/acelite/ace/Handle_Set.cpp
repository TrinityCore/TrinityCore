// Handle_Set.cpp
// $Id: Handle_Set.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/Handle_Set.h"

#if !defined (__ACE_INLINE__)
#include "ace/Handle_Set.inl"
#endif /* __ACE_INLINE__ */

#include "ace/OS_NS_string.h"



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Handle_Set)

  // ACE_MSB_MASK is only used here.
  // This needs to go here to avoid overflow problems on some compilers.
#if defined (ACE_WIN32)
   //  Does ACE_WIN32 have an fd_mask?
#  define ACE_MSB_MASK (~(1 << (NFDBITS - 1)))
#else  /* ! ACE_WIN32 */
#  define ACE_MSB_MASK (~((fd_mask) 1 << (NFDBITS - 1)))
#endif /* ! ACE_WIN32 */

#if defined (linux) && __GLIBC__ > 1 && __GLIBC_MINOR__ >= 1 && !defined (_XOPEN_SOURCE)
  // XPG4.2 requires the fds_bits member name, so it is not enabled by
  // default on Linux/glibc-2.1.x systems.  Instead use "__fds_bits."
  // Ugly, but "what are you going to do?" 8-)
#define fds_bits __fds_bits
#endif  /* linux && __GLIBC__ > 1 && __GLIBC_MINOR__ >= 1 && !_XOPEN_SOURCE */

void
ACE_Handle_Set::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Handle_Set::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nsize_ = %d"), this->size_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nmax_handle_ = %d"), this->max_handle_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n[ ")));

#if defined (ACE_WIN32)
  for (size_t i = 0; i < (size_t) this->mask_.fd_count + 1; i++)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT (" %x "), this->mask_.fd_array[i]));
#else /* !ACE_WIN32 */
  for (ACE_HANDLE i = 0; i < this->max_handle_ + 1; i++)
    if (this->is_set (i))
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT (" %d "), i));
#endif /* ACE_WIN32 */

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT (" ]\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// Table that maps bytes to counts of the enabled bits in each value
// from 0 to 255,
//
// nbits_[0] == 0
//
// because there are no bits enabled for the value 0.
//
// nbits_[5] == 2
//
// because there are 2 bits enabled in the value 5, i.e., it's
// 101 in binary.

const char ACE_Handle_Set::nbits_[256] =
{
  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};

// Constructor, initializes the bitmask to all 0s.

ACE_Handle_Set::ACE_Handle_Set (void)
{
  ACE_TRACE ("ACE_Handle_Set::ACE_Handle_Set");
  this->reset ();
}

ACE_Handle_Set::ACE_Handle_Set (const fd_set &fd_mask)
{
  ACE_TRACE ("ACE_Handle_Set::ACE_Handle_Set");
  this->reset ();
  ACE_OS::memcpy ((void *) &this->mask_,
                  (void *) &fd_mask,
                  sizeof this->mask_);
#if !defined (ACE_WIN32)
  this->sync (ACE_Handle_Set::MAXSIZE);
#if defined (ACE_HAS_BIG_FD_SET)
  this->min_handle_ = 0;
#endif /* ACE_HAS_BIG_FD_SET */
#endif /* !ACE_WIN32 */
}

// Counts the number of bits enabled in N.  Uses a table lookup to
// speed up the count.

int
ACE_Handle_Set::count_bits (u_long n)
{

 ACE_TRACE ("ACE_Handle_Set::count_bits");
#if defined (ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT)
  register int rval = 0;

  // Count the number of enabled bits in <n>.  This algorithm is very
  // fast, i.e., O(enabled bits in n).

  for (register u_long m = n;
       m != 0;
       m &= m - 1)
    rval++;

  return rval;
#else
   return (ACE_Handle_Set::nbits_[n & 0xff]
          + ACE_Handle_Set::nbits_[(n >> 8) & 0xff]
          + ACE_Handle_Set::nbits_[(n >> 16) & 0xff]
          + ACE_Handle_Set::nbits_[(n >> 24) & 0xff]);
#endif /* ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT */
}

#if defined (ACE_HAS_BIG_FD_SET)
// Find the bit position counting from right to left worst case
// (1<<31) is 8.

int
ACE_Handle_Set::bitpos (u_long bit)
{
  register int l = 0;
  register u_long n = bit - 1;

  // This is a fast count method when have the most significative bit.

  while (n >> 8)
    {
      n >>= 8;
      l += 8;
    }

  // Is greater than 15?
  if (n & 16)
    {
      n >>= 4;
      l += 4;
    }

  // Count number remaining bits.
  while (n != 0)
    {
      n &= n - 1;
      l++;
    }
  return l;
}
#endif /* ACE_HAS_BIG_FD_SET */

// Synchronize the underlying FD_SET with the MAX_FD and the SIZE.

#if defined (ACE_USE_SHIFT_FOR_EFFICIENCY)
// These don't work because shifting right 3 bits is not the same as
// dividing by 3, e.g., dividing by 8 requires shifting right 3 bits.
// In order to do the shift, we need to calculate the number of bits
// at some point.
#define ACE_DIV_BY_WORDSIZE(x) ((x) >> ((int) ACE_Handle_Set::WORDSIZE))
#define ACE_MULT_BY_WORDSIZE(x) ((x) << ((int) ACE_Handle_Set::WORDSIZE))
#else
#define ACE_DIV_BY_WORDSIZE(x) ((x) / ((int) ACE_Handle_Set::WORDSIZE))
#define ACE_MULT_BY_WORDSIZE(x) ((x) * ((int) ACE_Handle_Set::WORDSIZE))
#endif /* ACE_USE_SHIFT_FOR_EFFICIENCY */

void
ACE_Handle_Set::sync (ACE_HANDLE max)
{
  ACE_TRACE ("ACE_Handle_Set::sync");
#if !defined (ACE_WIN32)
  fd_mask *maskp = (fd_mask *)(this->mask_.fds_bits);
  this->size_ = 0;

  for (int i = ACE_DIV_BY_WORDSIZE (max - 1);
       i >= 0;
       i--)
    this->size_ += ACE_Handle_Set::count_bits (maskp[i]);

  this->set_max (max);
#else
  ACE_UNUSED_ARG (max);
#endif /* !ACE_WIN32 */
}

// Resets the MAX_FD after a clear of the original MAX_FD.

void
ACE_Handle_Set::set_max (ACE_HANDLE current_max)
{
  ACE_TRACE ("ACE_Handle_Set::set_max");
#if !defined(ACE_WIN32)
  fd_mask * maskp = (fd_mask *)(this->mask_.fds_bits);

  if (this->size_ == 0)
    this->max_handle_ = ACE_INVALID_HANDLE;
  else
    {
      int i;

      for (i = ACE_DIV_BY_WORDSIZE (current_max - 1);
           maskp[i] == 0;
           i--)
        continue;
#if defined (ACE_TANDEM_NSK_BIT_ORDER)
      // bits are in reverse order, MSB (sign bit) = bit 0.
      this->max_handle_ = ACE_MULT_BY_WORDSIZE (i);
      for (fd_mask val = maskp[i];
           (val & ACE_MSB_MASK) != 0;
           val = (val << 1))
        ++this->max_handle_;
#elif 1 /* !defined(ACE_HAS_BIG_FD_SET) */
      this->max_handle_ = ACE_MULT_BY_WORDSIZE (i);
      for (fd_mask val = maskp[i];
           (val & ~1) != 0; // This obscure code is needed since "bit 0" is in location 1...
           val = (val >> 1) & ACE_MSB_MASK)
        ++this->max_handle_;
#else
      register u_long val = this->mask_.fds_bits[i];
      this->max_handle_ = ACE_MULT_BY_WORDSIZE (i)
        + ACE_Handle_Set::bitpos(val & ~(val - 1));
#endif /* 1 */
    }

  // Do some sanity checking...
  if (this->max_handle_ >= ACE_Handle_Set::MAXSIZE)
    this->max_handle_ = ACE_Handle_Set::MAXSIZE - 1;
#else
  ACE_UNUSED_ARG (current_max);
#endif /* !ACE_WIN32 */
}

ACE_ALLOC_HOOK_DEFINE(ACE_Handle_Set_Iterator)

void
ACE_Handle_Set_Iterator::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Handle_Set_Iterator::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
#if defined(ACE_WIN32) || !defined(ACE_HAS_BIG_FD_SET)
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nhandle_index_ = %d"), this->handle_index_));
#elif defined(ACE_HAS_BIG_FD_SET)
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nword_max_ = %d"), this->word_max_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nword_val_ = %d"), this->word_val_));
#endif
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nword_num_ = %d"), this->word_num_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_HANDLE
ACE_Handle_Set_Iterator::operator () (void)
{
  ACE_TRACE ("ACE_Handle_Set_Iterator::operator");
#if defined (ACE_WIN32)
  if (this->handle_index_ < this->handles_.mask_.fd_count)
    // Return the handle and advance the iterator.
    return (ACE_HANDLE) this->handles_.mask_.fd_array[this->handle_index_++];
  else
    return ACE_INVALID_HANDLE;

#elif !defined (ACE_HAS_BIG_FD_SET) /* !ACE_WIN32 */
  // No sense searching further than the max_handle_ + 1;
  ACE_HANDLE maxhandlep1 = this->handles_.max_handle_ + 1;

  // HP-UX 11 plays some games with the fd_mask type - fd_mask is
  // defined as an int_32t, but the fds_bits is an array of longs.
  // This makes plainly indexing through the array by hand tricky,
  // since the FD_* macros treat the array as int32_t.  So the bits
  // are in the right place for int32_t, even though the array is
  // long.  This, they say, is to preserve the same in-memory layout
  // for 32-bit and 64-bit processes.  So, we play the same game as
  // the FD_* macros to get the bits right.  On all other systems,
  // this amounts to practically a NOP, since this is what would have
  // been done anyway, without all this type jazz.
  fd_mask * maskp = (fd_mask *)(this->handles_.mask_.fds_bits);

  if (this->handle_index_ >= maxhandlep1)
    // We've seen all the handles we're interested in seeing for this
    // iterator.
    return ACE_INVALID_HANDLE;
  else
    {
      ACE_HANDLE result = this->handle_index_;

      // Increment the iterator and advance to the next bit in this
      // word.
      this->handle_index_++;
#if defined (ACE_TANDEM_NSK_BIT_ORDER)
      // bits are in reverse order, MSB (sign bit) = bit 0.
      this->word_val_ = (this->word_val_ << 1);
#  else
      this->word_val_ = (this->word_val_ >> 1) & ACE_MSB_MASK;
#  endif /* ACE_TANDEM_NSK_BIT_ORDER */

      // If we've examined all the bits in this word, we'll go onto
      // the next word.

      if (this->word_val_ == 0)
        {
          // Start the handle_index_ at the beginning of the next word
          // and then loop until we've found the first non-zero bit or
          // we run past the <maxhandlep1> of the bitset.

          for (this->handle_index_ = ACE_MULT_BY_WORDSIZE(++this->word_num_);
               this->handle_index_ < maxhandlep1
                 && maskp[this->word_num_] == 0;
               this->word_num_++)
            this->handle_index_ += ACE_Handle_Set::WORDSIZE;

          // If the bit index becomes >= the maxhandlep1 that means
          // there weren't any more bits set that we want to consider.
          // Therefore, we'll just store the maxhandlep1, which will
          // cause <operator()> to return <ACE_INVALID_HANDLE>
          // immediately next time it's called.
          if (this->handle_index_ >= maxhandlep1)
            {
              this->handle_index_ = maxhandlep1;
              return result;
            }
          else
            // Load the bits of the next word.
            this->word_val_ = maskp[this->word_num_];
        }

      // Loop until we get <word_val_> to have its least significant
      // bit enabled, keeping track of which <handle_index> this
      // represents (this information is used by subsequent calls to
      // <operator()>).

#if defined (ACE_TANDEM_NSK_BIT_ORDER)
      // bits are in reverse order, MSB (sign bit) = bit 0.
      for (;
           this->word_val_ > 0;
           this->word_val_ = (this->word_val_ << 1))
        this->handle_index_++;
#  else
      for (;
           ACE_BIT_DISABLED (this->word_val_, 1);
           this->handle_index_++)
        this->word_val_ = (this->word_val_ >> 1) & ACE_MSB_MASK;
#  endif /* ACE_TANDEM_NSK_BIT_ORDER */

      return result;
    }
#else /* !ACE_HAS_BIG_FD_SET */
   // Find the first word in fds_bits with bit on
   register u_long lsb = this->word_val_;

   if (lsb == 0)
     {
       do
         {
           // We have exceeded the word count in Handle_Set?
           if (++this->word_num_ >= this->word_max_)
             return ACE_INVALID_HANDLE;

           lsb = this->handles_.mask_.fds_bits[this->word_num_];
         }
       while (lsb == 0);

       // Set index to word boundary.
       this->handle_index_ = ACE_MULT_BY_WORDSIZE (this->word_num_);

       // Put new word_val.
       this->word_val_ = lsb;

       // Find the least significative bit.
       lsb &= ~(lsb - 1);

       // Remove least significative bit.
       this->word_val_ ^= lsb;

       // Save to calculate bit distance.
       this->oldlsb_ = lsb;

       // Move index to least significative bit.
       while (lsb >>= 1)
         this->handle_index_++;
     }
   else
     {
        // Find the least significative bit.
        lsb &= ~(lsb - 1);

        // Remove least significative bit.
        this->word_val_ ^= lsb;

        register u_long n = lsb - this->oldlsb_;

        // Move index to bit distance between new lsb and old lsb.
        do
          {
            this->handle_index_++;
            n &= n >> 1;
          }
        while (n != 0);

        this->oldlsb_ = lsb;
      }

   return this->handle_index_;
#endif /* ACE_WIN32 */
}

ACE_Handle_Set_Iterator::ACE_Handle_Set_Iterator (const ACE_Handle_Set &hs)
  : handles_ (hs),
#if !defined (ACE_HAS_BIG_FD_SET) || defined (ACE_WIN32)
    handle_index_ (0),
    word_num_ (-1)
#elif defined (ACE_HAS_BIG_FD_SET)
    oldlsb_ (0),
    word_max_ (hs.max_handle_ == ACE_INVALID_HANDLE
               ? 0
               : ((ACE_DIV_BY_WORDSIZE (hs.max_handle_)) + 1))
#endif /* ACE_HAS_BIG_FD_SET */
{
  ACE_TRACE ("ACE_Handle_Set_Iterator::ACE_Handle_Set_Iterator");
#if !defined (ACE_WIN32) && !defined (ACE_HAS_BIG_FD_SET)
  // No sense searching further than the max_handle_ + 1;
  ACE_HANDLE maxhandlep1 =
    this->handles_.max_handle_ + 1;

  fd_mask *maskp =
    (fd_mask *)(this->handles_.mask_.fds_bits);

  // Loop until we've found the first non-zero bit or we run past the
  // <maxhandlep1> of the bitset.
  while (this->handle_index_ < maxhandlep1
         && maskp[++this->word_num_] == 0)
    this->handle_index_ += ACE_Handle_Set::WORDSIZE;

  // If the bit index becomes >= the maxhandlep1 that means there
  // weren't any bits set.  Therefore, we'll just store the
  // maxhandlep1, which will cause <operator()> to return
  // <ACE_INVALID_HANDLE> immediately.
  if (this->handle_index_ >= maxhandlep1)
    this->handle_index_ = maxhandlep1;
  else
    // Loop until we get <word_val_> to have its least significant bit
    // enabled, keeping track of which <handle_index> this represents
    // (this information is used by <operator()>).
#if defined (ACE_TANDEM_NSK_BIT_ORDER)
    // bits are in reverse order, MSB (sign bit) = bit 0.
    for (this->word_val_ = maskp[this->word_num_];
         this->word_val_ > 0;
         this->word_val_ = (this->word_val_ << 1))
      this->handle_index_++;
#  else
    for (this->word_val_ = maskp[this->word_num_];
         ACE_BIT_DISABLED (this->word_val_, 1)
           && this->handle_index_ < maxhandlep1;
         this->handle_index_++)
      this->word_val_ = (this->word_val_ >> 1) & ACE_MSB_MASK;
#  endif /* ACE_TANDEM_NSK_BIT_ORDER */
#elif !defined (ACE_WIN32) && defined (ACE_HAS_BIG_FD_SET)
    if (this->word_max_==0)
      {
        this->word_num_ = -1;
        this->word_val_ = 0;
      }
    else
      {
        this->word_num_ =
          ACE_DIV_BY_WORDSIZE (this->handles_.min_handle_) - 1;
        this->word_val_ = 0;
      }
#endif /* !ACE_WIN32 && !ACE_HAS_BIG_FD_SET */
}


void
ACE_Handle_Set_Iterator::reset_state (void)
{
  ACE_TRACE ("ACE_Handle_Set_Iterator::reset_state");

#if !defined (ACE_HAS_BIG_FD_SET) || defined (ACE_WIN32)
  this->handle_index_  = 0;
  this->word_num_ = -1;
#elif defined (ACE_HAS_BIG_FD_SET)
  this->oldlsb_ = 0;
  this->word_max_  =
    this->handles_.max_handle_ == ACE_INVALID_HANDLE  ? 0
    : ((ACE_DIV_BY_WORDSIZE (this->handles_.max_handle_)) + 1);
#endif /* ACE_HAS_BIG_FD_SET */

#if !defined (ACE_WIN32) && !defined (ACE_HAS_BIG_FD_SET)
  // No sense searching further than the max_handle_ + 1;
  ACE_HANDLE maxhandlep1 =
    this->handles_.max_handle_ + 1;

  fd_mask *maskp =
    (fd_mask *)(this->handles_.mask_.fds_bits);

  // Loop until we've found the first non-zero bit or we run past the
  // <maxhandlep1> of the bitset.
  while (this->handle_index_ < maxhandlep1
         && maskp[++this->word_num_] == 0)
    this->handle_index_ += ACE_Handle_Set::WORDSIZE;

  // If the bit index becomes >= the maxhandlep1 that means there
  // weren't any bits set.  Therefore, we'll just store the
  // maxhandlep1, which will cause <operator()> to return
  // <ACE_INVALID_HANDLE> immediately.
  if (this->handle_index_ >= maxhandlep1)
    this->handle_index_ = maxhandlep1;
  else
    // Loop until we get <word_val_> to have its least significant bit
    // enabled, keeping track of which <handle_index> this represents
    // (this information is used by <operator()>).
#if defined (ACE_TANDEM_NSK_BIT_ORDER)
    // bits are in reverse order, MSB (sign bit) = bit 0.
    for (this->word_val_ = maskp[this->word_num_];
         this->word_val_ > 0;
         this->word_val_ = (this->word_val_ << 1))
      this->handle_index_++;
#  else
    for (this->word_val_ = maskp[this->word_num_];
         ACE_BIT_DISABLED (this->word_val_, 1)
           && this->handle_index_ < maxhandlep1;
         this->handle_index_++)
      this->word_val_ = (this->word_val_ >> 1) & ACE_MSB_MASK;
#  endif /* ACE_TANDEM_NSK_BIT_ORDER */
#elif !defined (ACE_WIN32) && defined (ACE_HAS_BIG_FD_SET)
    if (this->word_max_==0)
      {
        this->word_num_ = -1;
        this->word_val_ = 0;
      }
    else
      {
        this->word_num_ =
          ACE_DIV_BY_WORDSIZE (this->handles_.min_handle_) - 1;
        this->word_val_ = 0;
      }
#endif /* !ACE_WIN32 && !ACE_HAS_BIG_FD_SET */
}

ACE_END_VERSIONED_NAMESPACE_DECL
