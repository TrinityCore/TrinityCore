#include "ace/CDR_Base.h"

#if !defined (__ACE_INLINE__)
# include "ace/CDR_Base.inl"
#endif /* ! __ACE_INLINE__ */

#include "ace/Message_Block.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_string.h"

ACE_RCSID (ace,
           CDR_Base,
           "$Id: CDR_Base.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (NONNATIVE_LONGDOUBLE)
static const ACE_INT16 max_eleven_bit = 0x3ff;
static const ACE_INT16 max_fifteen_bit = 0x3fff;
#endif /* NONNATIVE_LONGDOUBLE */

//
// See comments in CDR_Base.inl about optimization cases for swap_XX_array.
//

void
ACE_CDR::swap_2_array (char const * orig, char* target, size_t n)
{
  // ACE_ASSERT(n > 0); The caller checks that n > 0

  // We pretend that AMD64/GNU G++ systems have a Pentium CPU to
  // take advantage of the inline assembly implementation.

  // Later, we try to read in 32 or 64 bit chunks,
  // so make sure we don't do that for unaligned addresses.
#if ACE_SIZEOF_LONG == 8 && \
    !((defined(__amd64__) || defined (__x86_64__)) && defined(__GNUG__))
  char const * const o8 = ACE_ptr_align_binary (orig, 8);
  while (orig < o8 && n > 0)
    {
      ACE_CDR::swap_2 (orig, target);
      orig += 2;
      target += 2;
      --n;
    }
#else
  char const * const o4 = ACE_ptr_align_binary (orig, 4);
  // this is an _if_, not a _while_. The mistmatch can only be by 2.
  if (orig != o4)
    {
      ACE_CDR::swap_2 (orig, target);
      orig += 2;
      target += 2;
      --n;
    }
#endif
  if (n == 0)
    return;

  //
  // Loop unrolling. Here be dragons.
  //

  // (n & (~3)) is the greatest multiple of 4 not bigger than n.
  // In the while loop ahead, orig will move over the array by 8 byte
  // increments (4 elements of 2 bytes).
  // end marks our barrier for not falling outside.
  char const * const end = orig + 2 * (n & (~3));

  // See if we're aligned for writting in 64 or 32 bit chunks...
#if ACE_SIZEOF_LONG == 8 && \
    !((defined(__amd64__) || defined (__x86_64__)) && defined(__GNUG__))
  if (target == ACE_ptr_align_binary (target, 8))
#else
  if (target == ACE_ptr_align_binary (target, 4))
#endif
    {
      while (orig < end)
        {
#if defined (ACE_HAS_INTEL_ASSEMBLY)
          unsigned int a =
            * reinterpret_cast<const unsigned int*> (orig);
          unsigned int b =
            * reinterpret_cast<const unsigned int*> (orig + 4);
          asm ( "bswap %1"      : "=r" (a) : "0" (a) );
          asm ( "bswap %1"      : "=r" (b) : "0" (b) );
          asm ( "rol $16, %1"   : "=r" (a) : "0" (a) );
          asm ( "rol $16, %1"   : "=r" (b) : "0" (b) );
          * reinterpret_cast<unsigned int*> (target) = a;
          * reinterpret_cast<unsigned int*> (target + 4) = b;
#elif defined(ACE_HAS_PENTIUM) \
      && (defined(_MSC_VER) || defined(__BORLANDC__)) \
      && !defined(ACE_LACKS_INLINE_ASSEMBLY)
          __asm mov ecx, orig;
          __asm mov edx, target;
          __asm mov eax, [ecx];
          __asm mov ebx, 4[ecx];
          __asm bswap eax;
          __asm bswap ebx;
          __asm rol eax, 16;
          __asm rol ebx, 16;
          __asm mov [edx], eax;
          __asm mov 4[edx], ebx;
#elif ACE_SIZEOF_LONG == 8
          // 64 bit architecture.
          register unsigned long a =
            * reinterpret_cast<const unsigned long*> (orig);

          register unsigned long a1 = (a & 0x00ff00ff00ff00ffUL) << 8;
          register unsigned long a2 = (a & 0xff00ff00ff00ff00UL) >> 8;

          a = (a1 | a2);

          * reinterpret_cast<unsigned long*> (target) = a;
#else
          register ACE_UINT32 a =
            * reinterpret_cast<const ACE_UINT32*> (orig);
          register ACE_UINT32 b =
            * reinterpret_cast<const ACE_UINT32*> (orig + 4);

          register ACE_UINT32 a1 = (a & 0x00ff00ffU) << 8;
          register ACE_UINT32 b1 = (b & 0x00ff00ffU) << 8;
          register ACE_UINT32 a2 = (a & 0xff00ff00U) >> 8;
          register ACE_UINT32 b2 = (b & 0xff00ff00U) >> 8;

          a = (a1 | a2);
          b = (b1 | b2);

          * reinterpret_cast<ACE_UINT32*> (target) = a;
          * reinterpret_cast<ACE_UINT32*> (target + 4) = b;
#endif
          orig += 8;
          target += 8;
        }
    }
  else
    {
      // We're out of luck. We have to write in 2 byte chunks.
      while (orig < end)
        {
#if defined (ACE_HAS_INTEL_ASSEMBLY)
          unsigned int a =
            * reinterpret_cast<const unsigned int*> (orig);
          unsigned int b =
            * reinterpret_cast<const unsigned int*> (orig + 4);
          asm ( "bswap %1" : "=r" (a) : "0" (a) );
          asm ( "bswap %1" : "=r" (b) : "0" (b) );
          // We're little endian.
          * reinterpret_cast<unsigned short*> (target + 2)
              = (unsigned short) (a & 0xffff);
          * reinterpret_cast<unsigned short*> (target + 6)
              = (unsigned short) (b & 0xffff);
          asm ( "shrl $16, %1" : "=r" (a) : "0" (a) );
          asm ( "shrl $16, %1" : "=r" (b) : "0" (b) );
          * reinterpret_cast<unsigned short*> (target + 0)
              = (unsigned short) (a & 0xffff);
          * reinterpret_cast<unsigned short*> (target + 4)
              = (unsigned short) (b & 0xffff);
#elif defined (ACE_HAS_PENTIUM) \
      && (defined (_MSC_VER) || defined (__BORLANDC__)) \
      && !defined (ACE_LACKS_INLINE_ASSEMBLY)
          __asm mov ecx, orig;
          __asm mov edx, target;
          __asm mov eax, [ecx];
          __asm mov ebx, 4[ecx];
          __asm bswap eax;
          __asm bswap ebx;
          // We're little endian.
          __asm mov 2[edx], ax;
          __asm mov 6[edx], bx;
          __asm shr eax, 16;
          __asm shr ebx, 16;
          __asm mov 0[edx], ax;
          __asm mov 4[edx], bx;
#elif ACE_SIZEOF_LONG == 8
          // 64 bit architecture.
          register unsigned long a =
            * reinterpret_cast<const unsigned long*> (orig);

          register unsigned long a1 = (a & 0x00ff00ff00ff00ffUL) << 8;
          register unsigned long a2 = (a & 0xff00ff00ff00ff00UL) >> 8;

          a = (a1 | a2);

          ACE_UINT16 b1 = static_cast<ACE_UINT16> (a >> 48);
          ACE_UINT16 b2 = static_cast<ACE_UINT16> ((a >> 32) & 0xffff);
          ACE_UINT16 b3 = static_cast<ACE_UINT16> ((a >> 16) & 0xffff);
          ACE_UINT16 b4 = static_cast<ACE_UINT16> (a & 0xffff);

#if defined(ACE_LITTLE_ENDIAN)
          * reinterpret_cast<ACE_UINT16*> (target) = b4;
          * reinterpret_cast<ACE_UINT16*> (target + 2) = b3;
          * reinterpret_cast<ACE_UINT16*> (target + 4) = b2;
          * reinterpret_cast<ACE_UINT16*> (target + 6) = b1;
#else
          * reinterpret_cast<ACE_UINT16*> (target) = b1;
          * reinterpret_cast<ACE_UINT16*> (target + 2) = b2;
          * reinterpret_cast<ACE_UINT16*> (target + 4) = b3;
          * reinterpret_cast<ACE_UINT16*> (target + 6) = b4;
#endif
#else
          register ACE_UINT32 a =
            * reinterpret_cast<const ACE_UINT32*> (orig);
          register ACE_UINT32 b =
            * reinterpret_cast<const ACE_UINT32*> (orig + 4);

          register ACE_UINT32 a1 = (a & 0x00ff00ff) << 8;
          register ACE_UINT32 b1 = (b & 0x00ff00ff) << 8;
          register ACE_UINT32 a2 = (a & 0xff00ff00) >> 8;
          register ACE_UINT32 b2 = (b & 0xff00ff00) >> 8;

          a = (a1 | a2);
          b = (b1 | b2);

          ACE_UINT32 c1 = static_cast<ACE_UINT16> (a >> 16);
          ACE_UINT32 c2 = static_cast<ACE_UINT16> (a & 0xffff);
          ACE_UINT32 c3 = static_cast<ACE_UINT16> (b >> 16);
          ACE_UINT32 c4 = static_cast<ACE_UINT16> (b & 0xffff);

#if defined(ACE_LITTLE_ENDIAN)
          * reinterpret_cast<ACE_UINT16*> (target) = c2;
          * reinterpret_cast<ACE_UINT16*> (target + 2) = c1;
          * reinterpret_cast<ACE_UINT16*> (target + 4) = c4;
          * reinterpret_cast<ACE_UINT16*> (target + 6) = c3;
#else
          * reinterpret_cast<ACE_UINT16*> (target) = c1;
          * reinterpret_cast<ACE_UINT16*> (target + 2) = c2;
          * reinterpret_cast<ACE_UINT16*> (target + 4) = c3;
          * reinterpret_cast<ACE_UINT16*> (target + 6) = c4;
#endif
#endif

          orig += 8;
          target += 8;
        }
    }

  // (n & 3) == (n % 4).
  switch (n&3) {
  case 3:
    ACE_CDR::swap_2 (orig, target);
    orig += 2;
    target += 2;
  case 2:
    ACE_CDR::swap_2 (orig, target);
    orig += 2;
    target += 2;
  case 1:
    ACE_CDR::swap_2 (orig, target);
  }
}

void
ACE_CDR::swap_4_array (char const * orig, char* target, size_t n)
{
  // ACE_ASSERT (n > 0); The caller checks that n > 0

#if ACE_SIZEOF_LONG == 8
  // Later, we read from *orig in 64 bit chunks,
  // so make sure we don't generate unaligned readings.
  char const * const o8 = ACE_ptr_align_binary (orig, 8);
  // The mismatch can only be by 4.
  if (orig != o8)
    {
      ACE_CDR::swap_4 (orig, target);
      orig += 4;
      target += 4;
      --n;
    }
#endif  /* ACE_SIZEOF_LONG == 8 */

  if (n == 0)
    return;

  //
  // Loop unrolling. Here be dragons.
  //

  // (n & (~3)) is the greatest multiple of 4 not bigger than n.
  // In the while loop, orig will move over the array by 16 byte
  // increments (4 elements of 4 bytes).
  // ends marks our barrier for not falling outside.
  char const * const end = orig + 4 * (n & (~3));

#if ACE_SIZEOF_LONG == 8
  // 64 bits architecture.
  // See if we can write in 8 byte chunks.
  if (target == ACE_ptr_align_binary (target, 8))
    {
      while (orig < end)
        {
          register unsigned long a =
            * reinterpret_cast<const long*> (orig);
          register unsigned long b =
            * reinterpret_cast<const long*> (orig + 8);

#if defined(ACE_HAS_INTEL_ASSEMBLY)
          asm ("bswapq %1" : "=r" (a) : "0" (a));
          asm ("bswapq %1" : "=r" (b) : "0" (b));
          asm ("rol $32, %1" : "=r" (a) : "0" (a));
          asm ("rol $32, %1" : "=r" (b) : "0" (b));
#else
          register unsigned long a84 = (a & 0x000000ff000000ffL) << 24;
          register unsigned long b84 = (b & 0x000000ff000000ffL) << 24;
          register unsigned long a73 = (a & 0x0000ff000000ff00L) << 8;
          register unsigned long b73 = (b & 0x0000ff000000ff00L) << 8;
          register unsigned long a62 = (a & 0x00ff000000ff0000L) >> 8;
          register unsigned long b62 = (b & 0x00ff000000ff0000L) >> 8;
          register unsigned long a51 = (a & 0xff000000ff000000L) >> 24;
          register unsigned long b51 = (b & 0xff000000ff000000L) >> 24;

          a = (a84 | a73 | a62 | a51);
          b = (b84 | b73 | b62 | b51);
#endif

          * reinterpret_cast<long*> (target) = a;
          * reinterpret_cast<long*> (target + 8) = b;

          orig += 16;
          target += 16;
        }
    }
  else
    {
      // We are out of luck, we have to write in 4 byte chunks.
      while (orig < end)
        {
          register unsigned long a =
            * reinterpret_cast<const long*> (orig);
          register unsigned long b =
            * reinterpret_cast<const long*> (orig + 8);

#if defined(ACE_HAS_INTEL_ASSEMBLY)
          asm ("bswapq %1" : "=r" (a) : "0" (a));
          asm ("bswapq %1" : "=r" (b) : "0" (b));
          asm ("rol $32, %1" : "=r" (a) : "0" (a));
          asm ("rol $32, %1" : "=r" (b) : "0" (b));
#else
          register unsigned long a84 = (a & 0x000000ff000000ffL) << 24;
          register unsigned long b84 = (b & 0x000000ff000000ffL) << 24;
          register unsigned long a73 = (a & 0x0000ff000000ff00L) << 8;
          register unsigned long b73 = (b & 0x0000ff000000ff00L) << 8;
          register unsigned long a62 = (a & 0x00ff000000ff0000L) >> 8;
          register unsigned long b62 = (b & 0x00ff000000ff0000L) >> 8;
          register unsigned long a51 = (a & 0xff000000ff000000L) >> 24;
          register unsigned long b51 = (b & 0xff000000ff000000L) >> 24;

          a = (a84 | a73 | a62 | a51);
          b = (b84 | b73 | b62 | b51);
#endif

          ACE_UINT32 c1 = static_cast<ACE_UINT32> (a >> 32);
          ACE_UINT32 c2 = static_cast<ACE_UINT32> (a & 0xffffffff);
          ACE_UINT32 c3 = static_cast<ACE_UINT32> (b >> 32);
          ACE_UINT32 c4 = static_cast<ACE_UINT32> (b & 0xffffffff);

#if defined (ACE_LITTLE_ENDIAN)
          * reinterpret_cast<ACE_UINT32*> (target + 0) = c2;
          * reinterpret_cast<ACE_UINT32*> (target + 4) = c1;
          * reinterpret_cast<ACE_UINT32*> (target + 8) = c4;
          * reinterpret_cast<ACE_UINT32*> (target + 12) = c3;
#else
          * reinterpret_cast<ACE_UINT32*> (target + 0) = c1;
          * reinterpret_cast<ACE_UINT32*> (target + 4) = c2;
          * reinterpret_cast<ACE_UINT32*> (target + 8) = c3;
          * reinterpret_cast<ACE_UINT32*> (target + 12) = c4;
#endif
          orig += 16;
          target += 16;
        }
    }

#else  /* ACE_SIZEOF_LONG != 8 */

  while (orig < end)
    {
#if defined (ACE_HAS_PENTIUM) && defined (__GNUG__)
      register unsigned int a =
        *reinterpret_cast<const unsigned int*> (orig);
      register unsigned int b =
        *reinterpret_cast<const unsigned int*> (orig + 4);
      register unsigned int c =
        *reinterpret_cast<const unsigned int*> (orig + 8);
      register unsigned int d =
        *reinterpret_cast<const unsigned int*> (orig + 12);

      asm ("bswap %1" : "=r" (a) : "0" (a));
      asm ("bswap %1" : "=r" (b) : "0" (b));
      asm ("bswap %1" : "=r" (c) : "0" (c));
      asm ("bswap %1" : "=r" (d) : "0" (d));

      *reinterpret_cast<unsigned int*> (target) = a;
      *reinterpret_cast<unsigned int*> (target + 4) = b;
      *reinterpret_cast<unsigned int*> (target + 8) = c;
      *reinterpret_cast<unsigned int*> (target + 12) = d;
#elif defined (ACE_HAS_PENTIUM) \
      && (defined (_MSC_VER) || defined (__BORLANDC__)) \
      && !defined (ACE_LACKS_INLINE_ASSEMBLY)
      __asm mov eax, orig
      __asm mov esi, target
      __asm mov edx, [eax]
      __asm mov ecx, 4[eax]
      __asm mov ebx, 8[eax]
      __asm mov eax, 12[eax]
      __asm bswap edx
      __asm bswap ecx
      __asm bswap ebx
      __asm bswap eax
      __asm mov [esi], edx
      __asm mov 4[esi], ecx
      __asm mov 8[esi], ebx
      __asm mov 12[esi], eax
#else
      register ACE_UINT32 a =
        * reinterpret_cast<const ACE_UINT32*> (orig);
      register ACE_UINT32 b =
        * reinterpret_cast<const ACE_UINT32*> (orig + 4);
      register ACE_UINT32 c =
        * reinterpret_cast<const ACE_UINT32*> (orig + 8);
      register ACE_UINT32 d =
        * reinterpret_cast<const ACE_UINT32*> (orig + 12);

      // Expect the optimizer reordering this A LOT.
      // We leave it this way for clarity.
      a = (a << 24) | ((a & 0xff00) << 8) | ((a & 0xff0000) >> 8) | (a >> 24);
      b = (b << 24) | ((b & 0xff00) << 8) | ((b & 0xff0000) >> 8) | (b >> 24);
      c = (c << 24) | ((c & 0xff00) << 8) | ((c & 0xff0000) >> 8) | (c >> 24);
      d = (d << 24) | ((d & 0xff00) << 8) | ((d & 0xff0000) >> 8) | (d >> 24);

      * reinterpret_cast<ACE_UINT32*> (target) = a;
      * reinterpret_cast<ACE_UINT32*> (target + 4) = b;
      * reinterpret_cast<ACE_UINT32*> (target + 8) = c;
      * reinterpret_cast<ACE_UINT32*> (target + 12) = d;
#endif

      orig += 16;
      target += 16;
    }

#endif /* ACE_SIZEOF_LONG == 8 */

  // (n & 3) == (n % 4).
  switch (n & 3) {
  case 3:
    ACE_CDR::swap_4 (orig, target);
    orig += 4;
    target += 4;
  case 2:
    ACE_CDR::swap_4 (orig, target);
    orig += 4;
    target += 4;
  case 1:
    ACE_CDR::swap_4 (orig, target);
  }
}

//
// We don't benefit from unrolling in swap_8_array and swap_16_array
// (swap_8 and swap_16 are big enough).
//
void
ACE_CDR::swap_8_array (char const * orig, char* target, size_t n)
{
  // ACE_ASSERT(n > 0); The caller checks that n > 0

  char const * const end = orig + 8*n;
  while (orig < end)
    {
      swap_8 (orig, target);
      orig += 8;
      target += 8;
    }
}

void
ACE_CDR::swap_16_array (char const * orig, char* target, size_t n)
{
  // ACE_ASSERT(n > 0); The caller checks that n > 0

  char const * const end = orig + 16*n;
  while (orig < end)
    {
      swap_16 (orig, target);
      orig += 16;
      target += 16;
    }
}

void
ACE_CDR::mb_align (ACE_Message_Block *mb)
{
#if !defined (ACE_CDR_IGNORE_ALIGNMENT)
  char * const start = ACE_ptr_align_binary (mb->base (),
                                             ACE_CDR::MAX_ALIGNMENT);
#else
  char * const start = mb->base ();
#endif /* ACE_CDR_IGNORE_ALIGNMENT */
  mb->rd_ptr (start);
  mb->wr_ptr (start);
}

int
ACE_CDR::grow (ACE_Message_Block *mb, size_t minsize)
{
  size_t newsize =
    ACE_CDR::first_size (minsize + ACE_CDR::MAX_ALIGNMENT);

  if (newsize <= mb->size ())
    return 0;

  ACE_Data_Block *db =
    mb->data_block ()->clone_nocopy (0, newsize);

  if (db == 0)
    return -1;

  // Do the equivalent of ACE_CDR::mb_align() here to avoid having
  // to allocate an ACE_Message_Block on the stack thereby avoiding
  // the manipulation of the data blocks reference count
  size_t mb_len = mb->length ();
  char *start = ACE_ptr_align_binary (db->base (),
                                      ACE_CDR::MAX_ALIGNMENT);

  ACE_OS::memcpy (start, mb->rd_ptr (), mb_len);
  mb->data_block (db);

  // Setting the data block on the mb resets the read and write
  // pointers back to the beginning.  We must set the rd_ptr to the
  // aligned start and adjust the write pointer to the end
  mb->rd_ptr (start);
  mb->wr_ptr (start + mb_len);

  // Remove the DONT_DELETE flags from mb
  mb->clr_self_flags (ACE_Message_Block::DONT_DELETE);

  return 0;
}

size_t
ACE_CDR::total_length (const ACE_Message_Block* begin,
                       const ACE_Message_Block* end)
{
  size_t l = 0;
  // Compute the total size.
  for (const ACE_Message_Block *i = begin;
       i != end;
       i = i->cont ())
    l += i->length ();
  return l;
}

void
ACE_CDR::consolidate (ACE_Message_Block *dst,
                      const ACE_Message_Block *src)
{
  if (src == 0)
    return;

  size_t newsize =
    ACE_CDR::first_size (ACE_CDR::total_length (src, 0)
                         + ACE_CDR::MAX_ALIGNMENT);
  dst->size (newsize);

#if !defined (ACE_CDR_IGNORE_ALIGNMENT)
  // We must copy the contents of <src> into the new buffer, but
  // respecting the alignment.
  ptrdiff_t srcalign =
    ptrdiff_t(src->rd_ptr ()) % ACE_CDR::MAX_ALIGNMENT;
  ptrdiff_t dstalign =
    ptrdiff_t(dst->rd_ptr ()) % ACE_CDR::MAX_ALIGNMENT;
  ptrdiff_t offset = srcalign - dstalign;
  if (offset < 0)
    offset += ACE_CDR::MAX_ALIGNMENT;
  dst->rd_ptr (static_cast<size_t> (offset));
  dst->wr_ptr (dst->rd_ptr ());
#endif /* ACE_CDR_IGNORE_ALIGNMENT */

  for (const ACE_Message_Block* i = src;
       i != 0;
       i = i->cont ())
    {
      // If the destination and source are the same, do not
      // attempt to copy the data.  Just update the write pointer.
      if (dst->wr_ptr () != i->rd_ptr ())
        dst->copy (i->rd_ptr (), i->length ());
      else
        dst->wr_ptr (i->length ());
    }
}

#if defined (NONNATIVE_LONGLONG)
bool
ACE_CDR::LongLong::operator== (const ACE_CDR::LongLong &rhs) const
{
  return this->h == rhs.h && this->l == rhs.l;
}

bool
ACE_CDR::LongLong::operator!= (const ACE_CDR::LongLong &rhs) const
{
  return this->l != rhs.l || this->h != rhs.h;
}

#endif /* NONNATIVE_LONGLONG */

#if defined (NONNATIVE_LONGDOUBLE)
ACE_CDR::LongDouble&
ACE_CDR::LongDouble::assign (const ACE_CDR::LongDouble::NativeImpl& rhs)
{
  ACE_OS::memset (this->ld, 0, sizeof (this->ld));

  if (sizeof (rhs) == 8)
    {
#if defined (ACE_LITTLE_ENDIAN)
      static const size_t byte_zero = 1;
      static const size_t byte_one = 0;
      char rhs_ptr[16];
      ACE_CDR::swap_8 (reinterpret_cast<const char*> (&rhs), rhs_ptr);
#else
      static const size_t byte_zero = 0;
      static const size_t byte_one = 1;
      const char* rhs_ptr = reinterpret_cast<const char*> (&rhs);
#endif
      ACE_INT16 sign  = static_cast<ACE_INT16> (
                          static_cast<signed char> (rhs_ptr[0])) & 0x8000;
      ACE_INT16 exponent = ((rhs_ptr[0] & 0x7f) << 4) |
                           ((rhs_ptr[1] >> 4) & 0xf);
      const char* exp_ptr = reinterpret_cast<const char*> (&exponent);

      // Infinity and NaN have an exponent of 0x7ff in 64-bit IEEE
      if (exponent == 0x7ff)
        {
          exponent = 0x7fff;
        }
      else
        {
          exponent = (exponent - max_eleven_bit) + max_fifteen_bit;
        }
      exponent |= sign;

      // Store the sign bit and exponent
      this->ld[0] = exp_ptr[byte_zero];
      this->ld[1] = exp_ptr[byte_one];

      // Store the mantissa.  In an 8 byte double, it is split by
      // 4 bits (because of the 12 bits for sign and exponent), so
      // we have to shift and or the rhs to get the right bytes.
      size_t li = 2;
      bool direction = true;
      for (size_t ri = 1; ri < sizeof (rhs);)
        {
          if (direction)
            {
              this->ld[li] |= ((rhs_ptr[ri] << 4) & 0xf0);
              direction = false;
              ++ri;
            }
          else
            {
              this->ld[li] |= ((rhs_ptr[ri] >> 4) & 0xf);
              direction = true;
              ++li;
            }
        }
#if defined (ACE_LITTLE_ENDIAN)
      ACE_OS::memcpy (rhs_ptr, this->ld, sizeof (this->ld));
      ACE_CDR::swap_16 (rhs_ptr, this->ld);
#endif
    }
  else
    {
      ACE_OS::memcpy(this->ld,
                     reinterpret_cast<const char*> (&rhs), sizeof (rhs));
    }
  return *this;
}

ACE_CDR::LongDouble&
ACE_CDR::LongDouble::assign (const ACE_CDR::LongDouble& rhs)
{
  if (this != &rhs)
    *this = rhs;
  return *this;
}

bool
ACE_CDR::LongDouble::operator== (const ACE_CDR::LongDouble &rhs) const
{
  return ACE_OS::memcmp (this->ld, rhs.ld, 16) == 0;
}

bool
ACE_CDR::LongDouble::operator!= (const ACE_CDR::LongDouble &rhs) const
{
  return ACE_OS::memcmp (this->ld, rhs.ld, 16) != 0;
}

ACE_CDR::LongDouble::operator ACE_CDR::LongDouble::NativeImpl () const
{
  ACE_CDR::LongDouble::NativeImpl ret = 0.0;
  char* lhs_ptr = reinterpret_cast<char*> (&ret);

  if (sizeof (ret) == 8)
    {
#if defined (ACE_LITTLE_ENDIAN)
      static const size_t byte_zero = 1;
      static const size_t byte_one = 0;
      char copy[16];
      ACE_CDR::swap_16 (this->ld, copy);
#else
      static const size_t byte_zero = 0;
      static const size_t byte_one = 1;
      const char* copy = this->ld;
#endif
      ACE_INT16 exponent = 0;
      char* exp_ptr = reinterpret_cast<char*> (&exponent);
      exp_ptr[byte_zero] = copy[0];
      exp_ptr[byte_one] = copy[1];

      ACE_INT16 sign = (exponent & 0x8000);
      exponent &= 0x7fff;

      // Infinity and NaN have an exponent of 0x7fff in 128-bit IEEE
      if (exponent == 0x7fff)
        {
          exponent = 0x7ff;
        }
      else
        {
          exponent = (exponent - max_fifteen_bit) + max_eleven_bit;
        }
      exponent = (exponent << 4) | sign;

      // Store the sign and exponent
      lhs_ptr[0] = exp_ptr[byte_zero];
      lhs_ptr[1] = exp_ptr[byte_one];

      // Store the mantissa.  In an 8 byte double, it is split by
      // 4 bits (because of the 12 bits for sign and exponent), so
      // we have to shift and or the rhs to get the right bytes.
      size_t li = 1;
      bool direction = true;
      for (size_t ri = 2; li < sizeof (ret); ) {
        if (direction)
          {
            lhs_ptr[li] |= ((copy[ri] >> 4) & 0xf);
            direction = false;
            ++li;
          }
        else
          {
            lhs_ptr[li] |= ((copy[ri] & 0xf) << 4);
            direction = true;
            ++ri;
          }
      }

#if defined (ACE_LITTLE_ENDIAN)
      ACE_CDR::swap_8 (lhs_ptr, lhs_ptr);
#endif
    }
  else
    {
      ACE_OS::memcpy(lhs_ptr, this->ld, sizeof (ret));
    }

  // This bit of code is unnecessary.  However, this code is
  // necessary to work around a bug in the gcc 4.1.1 optimizer.
  ACE_CDR::LongDouble tmp;
  tmp.assign (ret);

  return ret;
}
#endif /* NONNATIVE_LONGDOUBLE */

#if defined(_UNICOS) && !defined(_CRAYMPP)
// placeholders to get things compiling
ACE_CDR::Float::Float (void)
{
}

ACE_CDR::Float::Float (const float & /* init */)
{
}

ACE_CDR::Float &
ACE_CDR::Float::operator= (const float & /* rhs */)
{
  return *this;
}

bool
ACE_CDR::Float::operator!= (const ACE_CDR::Float & /* rhs */) const
{
  return false;
}
#endif /* _UNICOS */

ACE_END_VERSIONED_NAMESPACE_DECL

