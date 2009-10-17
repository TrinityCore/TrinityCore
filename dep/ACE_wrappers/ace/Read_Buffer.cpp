// $Id: Read_Buffer.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Read_Buffer.h"
#include "ace/config-all.h"
#if !defined (__ACE_INLINE__)
#include "ace/Read_Buffer.inl"
#endif /* __ACE_INLINE__ */
#include "ace/Log_Msg.h"
#include "ace/Malloc_Base.h"
#include "ace/Service_Config.h"
#include "ace/OS_NS_stdio.h"
ACE_RCSID(ace, Read_Buffer, "$Id: Read_Buffer.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
void
ACE_Read_Buffer::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Read_Buffer::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("size_ = %d"), this->size_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\noccurrences_ = %d"), this->occurrences_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nstream_ = %x"), this->stream_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nallocator_ = %x"), this->allocator_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
ACE_Read_Buffer::ACE_Read_Buffer (FILE *fp,
                                  bool close_on_delete,
                                  ACE_Allocator *alloc)
  : stream_ (fp),
    close_on_delete_ (close_on_delete),
    allocator_ (alloc)
{
  ACE_TRACE ("ACE_Read_Buffer::ACE_Read_Buffer");
  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();
}
#if !defined (ACE_HAS_WINCE)
ACE_Read_Buffer::ACE_Read_Buffer (ACE_HANDLE handle,
                                  bool close_on_delete,
                                  ACE_Allocator *alloc)
  : stream_ (ACE_OS::fdopen (handle, ACE_TEXT ("r"))),
    close_on_delete_ (close_on_delete),
    allocator_ (alloc)
{
  ACE_TRACE ("ACE_Read_Buffer::ACE_Read_Buffer");
  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();
}
#endif  // ACE_HAS_WINCE
ACE_Read_Buffer::~ACE_Read_Buffer (void)
{
  ACE_TRACE ("ACE_Read_Buffer::~ACE_Read_Buffer");
  if (this->close_on_delete_)
    ACE_OS::fclose (this->stream_);
}
// Input: term        the character to terminate on
//        search      the character to search for
//        replace     the character with which to replace search
// Output: a buffer containing the contents of stream
// Method: call the recursive helper function read_helper
char *
ACE_Read_Buffer::read (int term, int search, int replace)
{
  ACE_TRACE ("ACE_Read_Buffer::read");
  this->occurrences_ = 0;
  this->size_ = 0;
  return this->rec_read (term, search, replace);
}
// Input: term       the termination character
//        search     the character to search for
//        replace    the character with which to replace search
// Purpose: read in a file to a buffer using only a single dynamic
//          allocation.
// Method: read until the local buffer is full and then recurse.
//         Must continue until the termination character is reached.
//         Allocate the final buffer based on the number of local
//         buffers read and as the recursive calls bottom out,
//         copy them in reverse order into the allocated buffer.
char *
ACE_Read_Buffer::rec_read (int term, int search, int replace)
{
  ACE_TRACE ("ACE_Read_Buffer::rec_read");
  // This is our temporary workspace.
  char buf[BUFSIZ];
  int c = EOF;
  size_t slot = 0;
  int done = 0;
  // Read in the file char by char
  while (slot < BUFSIZ)
    {
      c = ACE_OS::getc (this->stream_);
      // Don't insert EOF into the buffer...
      if (c == EOF)
        {
          ACE_OS::ungetc (c, this->stream_);
          break;
        }
      else if (c == term)
        done = 1;
      // Check for possible substitutions.
      if (c == search)
        {
          ++this->occurrences_;
          if (replace >= 0)
            c = replace;
        }
      buf[slot++] = (char) c;
      // Substitutions must be made before checking for termination.
      if (done)
        break;
    }
  // Increment the number of bytes.
  this->size_ += slot;
  // Don't bother going any farther if the total size is 0.
  if (this->size_ == 0)
    return 0;
  char *result = 0;
  // Recurse, when the recursion bottoms out, allocate the result
  // buffer.
  if (done || c == EOF)
    {
      // Use the allocator to acquire the memory.  The + 1 allows
      // space for the null terminator.
      result = (char *) this->allocator_->malloc (this->size_ + 1);
      if (result == 0)
        {
          errno = ENOMEM;
          return 0;
        }
      result += this->size_;
      // Null terminate the buffer.
      *result = '\0';
    }
  else if ((result = this->rec_read (term, search, replace)) == 0)
    return 0;
  // Copy buf into the appropriate location starting from end of
  // buffer.  Peter says this is confusing and that we should use
  // memcpy() ;-)
  for (size_t j = slot; j > 0; j--)
    *--result = buf[j - 1];
  return result;
}
ACE_END_VERSIONED_NAMESPACE_DECL

