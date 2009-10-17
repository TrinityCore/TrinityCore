#include "ace/Message_Block.h"

#if !defined (__ACE_INLINE__)
#include "ace/Message_Block.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"
#include "ace/Malloc_Base.h"
#include "ace/OS_NS_string.h"

//#define ACE_ENABLE_TIMEPROBES
#include "ace/Timeprobe.h"

ACE_RCSID (ace,
           Message_Block,
           "$Id: Message_Block.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_Message_Block)

#if defined (ACE_ENABLE_TIMEPROBES)

static const char *ACE_MB_Timeprobe_Description[] =
{
  "Message_Block::init_i - enter",
  "Message_Block::init_i - leave",
  "Message_Block::init_i - db alloc",
  "Message_Block::init_i - db ctor",
  "Data_Block::ctor[1] - enter",
  "Data_Block::ctor[1] - leave",
  "Data_Block::ctor[2] - enter",
  "Data_Block::ctor[2] - leave",
  "Data_Block::clone - enter",
  "Data_Block::clone - leave"
};

enum
{
  ACE_MESSAGE_BLOCK_INIT_I_ENTER = 3000,
  ACE_MESSAGE_BLOCK_INIT_I_LEAVE,
  ACE_MESSAGE_BLOCK_INIT_I_DB_ALLOC,
  ACE_MESSAGE_BLOCK_INIT_I_DB_CTOR,
  ACE_DATA_BLOCK_CTOR1_ENTER,
  ACE_DATA_BLOCK_CTOR1_LEAVE,
  ACE_DATA_BLOCK_CTOR2_ENTER,
  ACE_DATA_BLOCK_CTOR2_LEAVE,
  ACE_DATA_BLOCK_CLONE_ENTER,
  ACE_DATA_BLOCK_CLONE_LEAVE
};


// Setup Timeprobes
ACE_TIMEPROBE_EVENT_DESCRIPTIONS (ACE_MB_Timeprobe_Description,
                                  ACE_MESSAGE_BLOCK_INIT_I_ENTER);

#endif /* ACE_ENABLE_TIMEPROBES */

void
ACE_Message_Block::data_block (ACE_Data_Block *db)
{
  ACE_TRACE ("ACE_Message_Block::data_block");
  if (ACE_BIT_DISABLED (this->flags_,
                        ACE_Message_Block::DONT_DELETE)
      && this->data_block_ != 0)
    this->data_block_->release ();

  this->data_block_ = db;

  // Set the read and write pointers in the <Message_Block> to point
  // to the buffer in the <ACE_Data_Block>.
  this->rd_ptr (this->data_block ()->base ());
  this->wr_ptr (this->data_block ()->base ());
}

int
ACE_Message_Block::copy (const char *buf, size_t n)
{
  ACE_TRACE ("ACE_Message_Block::copy");

  /*size_t len = static_cast<size_t> (this->end () - this->wr_ptr ());*/
  // Note that for this to work correct, end () *must* be >= mark ().
  size_t len = this->space ();

  if (len < n)
    {
      errno = ENOSPC;
      return -1;
    }
  else
    {
      (void) ACE_OS::memcpy (this->wr_ptr (),
                             buf,
                             n);
      this->wr_ptr (n);
      return 0;
    }
}

int
ACE_Message_Block::copy (const char *buf)
{
  ACE_TRACE ("ACE_Message_Block::copy");

  /* size_t len = static_cast<size_t> (this->end () - this->wr_ptr ()); */
  // Note that for this to work correct, end() *must* be >= wr_ptr().
  size_t len = this->space ();

  size_t buflen = ACE_OS::strlen (buf) + 1;

  if (len < buflen)
    {
      errno = ENOSPC;
      return -1;
    }
  else
    {
      (void) ACE_OS::memcpy (this->wr_ptr (),
                             buf,
                             buflen);
      this->wr_ptr (buflen);
      return 0;
    }
}

int
ACE_Message_Block::crunch (void)
{
  if (this->rd_ptr_ != 0)
    {
      if (this->rd_ptr_ > this->wr_ptr_)
        return -1;

      size_t const len = this->length ();
      (void) ACE_OS::memmove (this->base (),
                              this->rd_ptr (),
                              len);
      this->rd_ptr (this->base ());
      this->wr_ptr (this->base () + len);
    }
  return 0;
}

void
ACE_Data_Block::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Data_Block::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("-----( Data Block )-----\n")
              ACE_TEXT ("type_ = %d\n")
              ACE_TEXT ("cur_size_ = %u\n")
              ACE_TEXT ("max_size_ = %u\n")
              ACE_TEXT ("flags_ = %u\n")
              ACE_TEXT ("base_ = %u\n")
              ACE_TEXT ("locking_strategy_ = %u\n")
              ACE_TEXT ("reference_count_ = %u\n")
              ACE_TEXT ("---------------------------\n"),
              this->type_,
              this->cur_size_,
              this->max_size_,
              this->flags_,
              this->base_,
              this->locking_strategy_,
              this->reference_count_));
  this->allocator_strategy_->dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

void
ACE_Message_Block::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Message_Block::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("-----( Message Block )-----\n")
              ACE_TEXT ("priority_ = %d\n")
              ACE_TEXT ("next_ = %u\n")
              ACE_TEXT ("prev_ = %u\n")
              ACE_TEXT ("cont_ = %u\n")
              ACE_TEXT ("rd_ptr_ = %u\n")
              ACE_TEXT ("wr_ptr_ = %u\n")
              ACE_TEXT ("---------------------------\n"),
              this->priority_,
              this->next_,
              this->prev_,
              this->cont_,
              this->rd_ptr_,
              this->wr_ptr_));
  this->data_block ()->dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

int
ACE_Data_Block::reference_count (void) const
{
  if (this->locking_strategy_)
    {
      // We need to acquire the lock before retrieving the count
      ACE_GUARD_RETURN (ACE_Lock, ace_mon, *this->locking_strategy_, 0);

      return this->reference_count_i ();
    }

  return this->reference_count_i ();
}

int
ACE_Data_Block::size (size_t length)
{
  ACE_TRACE ("ACE_Data_Block::size");

  if (length <= this->max_size_)
    this->cur_size_ = length;
  else
    {
      // We need to resize!
      char *buf = 0;
      ACE_ALLOCATOR_RETURN (buf,
                            (char *) this->allocator_strategy_->malloc (length),
                            -1);

      ACE_OS::memcpy (buf,
                      this->base_,
                      this->cur_size_);
      if (ACE_BIT_DISABLED (this->flags_,
                            ACE_Message_Block::DONT_DELETE))
        this->allocator_strategy_->free ((void *) this->base_);
      else
        // We now assume ownership.
        ACE_CLR_BITS (this->flags_,
                      ACE_Message_Block::DONT_DELETE);
      this->max_size_ = length;
      this->cur_size_ = length;
      this->base_ = buf;
    }
  return 0;
}

int
ACE_Message_Block::size (size_t length)
{
  ACE_TRACE ("ACE_Message_Block::size");

  // Resize the underlying <ACE_Data_Block>.
  if (this->data_block ()->size (length) == -1)
    return -1;

  return 0;
}

void
ACE_Message_Block::total_size_and_length (size_t &mb_size,
                                          size_t &mb_length) const
{
  ACE_TRACE ("ACE_Message_Block::total_size_and_length");

  for (const ACE_Message_Block *i = this;
       i != 0;
       i = i->cont ())
    {
      mb_size += i->size ();
      mb_length += i->length ();
    }
}

size_t
ACE_Message_Block::total_size (void) const
{
  ACE_TRACE ("ACE_Message_Block::total_size");

  size_t size = 0;
  for (const ACE_Message_Block *i = this;
       i != 0;
       i = i->cont ())
    size += i->size ();

  return size;
}

size_t
ACE_Message_Block::total_length (void) const
{
  ACE_TRACE ("ACE_Message_Block::total_length");

  size_t length = 0;
  for (const ACE_Message_Block *i = this;
       i != 0;
       i = i->cont ())
    length += i->length ();

  return length;
}

size_t
ACE_Message_Block::total_capacity (void) const
{
  ACE_TRACE ("ACE_Message_Block::total_capacity");

  size_t size = 0;

  for (const ACE_Message_Block *i = this;
       i != 0;
       i = i->cont ())
    size += i->capacity ();

  return size;
}

ACE_Data_Block::ACE_Data_Block (void)
  : type_ (ACE_Message_Block::MB_DATA),
    cur_size_ (0),
    max_size_ (0),
    flags_ (ACE_Message_Block::DONT_DELETE),
    base_ (0),
    allocator_strategy_ (0),
    locking_strategy_ (0),
    reference_count_ (1),
    data_block_allocator_ (0)
{
  ACE_TRACE ("ACE_Data_Block::ACE_Data_Block");
  ACE_FUNCTION_TIMEPROBE (ACE_DATA_BLOCK_CTOR1_ENTER);

  ACE_ALLOCATOR (this->allocator_strategy_,
                 ACE_Allocator::instance ());

  ACE_ALLOCATOR (this->data_block_allocator_,
                 ACE_Allocator::instance ());
}

ACE_Data_Block::ACE_Data_Block (size_t size,
                                ACE_Message_Block::ACE_Message_Type msg_type,
                                const char *msg_data,
                                ACE_Allocator *allocator_strategy,
                                ACE_Lock *locking_strategy,
                                ACE_Message_Block::Message_Flags flags,
                                ACE_Allocator *data_block_allocator)
  : type_ (msg_type),
    cur_size_ (0),          // Reset later if memory alloc'd ok
    max_size_ (0),
    flags_ (flags),
    base_ (const_cast <char *> (msg_data)),
    allocator_strategy_ (allocator_strategy),
    locking_strategy_ (locking_strategy),
    reference_count_ (1),
    data_block_allocator_ (data_block_allocator)
{
  ACE_TRACE ("ACE_Data_Block::ACE_Data_Block");
  ACE_FUNCTION_TIMEPROBE (ACE_DATA_BLOCK_CTOR2_ENTER);

  // If the user didn't pass one in, let's use the
  // <ACE_Allocator::instance>.
  if (this->allocator_strategy_ == 0)
    ACE_ALLOCATOR (this->allocator_strategy_,
                   ACE_Allocator::instance ());

  if (this->data_block_allocator_ == 0)
    ACE_ALLOCATOR (this->data_block_allocator_,
                   ACE_Allocator::instance ());

  if (msg_data == 0)
    {
      ACE_ALLOCATOR (this->base_,
                     (char *) this->allocator_strategy_->malloc (size));
#if defined (ACE_INITIALIZE_MEMORY_BEFORE_USE)
      (void) ACE_OS::memset (this->base_,
                             '\0',
                             size);
#endif /* ACE_INITIALIZE_MEMORY_BEFORE_USE */
    }

  // ACE_ALLOCATOR returns on alloc failure but we cant throw, so setting
  // the size to 0 (i.e. "bad bit") ...
  if (this->base_ == 0)
    {
      size = 0;
    }

  // The memory is legit, whether passed in or allocated, so set
  // the size.
  this->cur_size_ = this->max_size_ = size;
}

ACE_Message_Block::ACE_Message_Block (const char *data,
                                      size_t size,
                                      unsigned long priority)
  : flags_ (0),
    data_block_ (0)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (size,    // size
                    MB_DATA, // type
                    0,       // cont
                    data,    // data
                    0,       // allocator
                    0,       // locking strategy
                    ACE_Message_Block::DONT_DELETE, // flags
                    priority, // priority
                    ACE_Time_Value::zero,     // execution time
                    ACE_Time_Value::max_time, // absolute time of deadline
                    0,  // data block
                    0,  // data_block allocator
                    0) == -1) // message_block allocator
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_Message_Block")));
}

ACE_Message_Block::ACE_Message_Block (ACE_Allocator *message_block_allocator)
  : flags_ (0),
    data_block_ (0)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (0,       // size
                    MB_DATA, // type
                    0,       // cont
                    0,       // data
                    0,       // allocator
                    0,       // locking strategy
                    ACE_Message_Block::DONT_DELETE, // flags
                    0, // priority
                    ACE_Time_Value::zero,     // execution time
                    ACE_Time_Value::max_time, // absolute time of deadline
                    0, // data block
                    0, // data_block allocator
                    message_block_allocator) == -1) // message_block allocator
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_Message_Block")));
}

ACE_Message_Block::ACE_Message_Block (size_t size,
                                      ACE_Message_Type msg_type,
                                      ACE_Message_Block *msg_cont,
                                      const char *msg_data,
                                      ACE_Allocator *allocator_strategy,
                                      ACE_Lock *locking_strategy,
                                      unsigned long priority,
                                      const ACE_Time_Value &execution_time,
                                      const ACE_Time_Value &deadline_time,
                                      ACE_Allocator *data_block_allocator,
                                      ACE_Allocator *message_block_allocator)
  :flags_ (0),
   data_block_ (0)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (size,
                    msg_type,
                    msg_cont,
                    msg_data,
                    allocator_strategy,
                    locking_strategy,
                    msg_data ? ACE_Message_Block::DONT_DELETE : 0,
                    priority,
                    execution_time,
                    deadline_time,
                    0, // data block
                    data_block_allocator,
                    message_block_allocator) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_Message_Block")));
}

int
ACE_Message_Block::init (size_t size,
                         ACE_Message_Type msg_type,
                         ACE_Message_Block *msg_cont,
                         const char *msg_data,
                         ACE_Allocator *allocator_strategy,
                         ACE_Lock *locking_strategy,
                         unsigned long priority,
                         const ACE_Time_Value &execution_time,
                         const ACE_Time_Value &deadline_time,
                         ACE_Allocator *data_block_allocator,
                         ACE_Allocator *message_block_allocator)
{
  ACE_TRACE ("ACE_Message_Block::init");

  return this->init_i (size,
                       msg_type,
                       msg_cont,
                       msg_data,
                       allocator_strategy,
                       locking_strategy,
                       msg_data ? ACE_Message_Block::DONT_DELETE : 0,
                       priority,
                       execution_time,
                       deadline_time,
                       0,  // data block
                       data_block_allocator,
                       message_block_allocator);
}

int
ACE_Message_Block::init (const char *data,
                         size_t size)
{
  ACE_TRACE ("ACE_Message_Block::init");
  // Should we also initialize all the other fields, as well?

  return this->init_i (size,    // size
                       MB_DATA, // type
                       0,       // cont
                       data,    // data
                       0,       // allocator
                       0,       // locking strategy
                       ACE_Message_Block::DONT_DELETE,  // flags
                       0,  // priority
                       ACE_Time_Value::zero,     // execution time
                       ACE_Time_Value::max_time, // absolute time of deadline
                       0,  // data block
                       0,  // data_block allocator
                       0); // message_block allocator
}

ACE_Message_Block::ACE_Message_Block (size_t size,
                                      ACE_Message_Type msg_type,
                                      ACE_Message_Block *msg_cont,
                                      const char *msg_data,
                                      ACE_Allocator *allocator_strategy,
                                      ACE_Lock *locking_strategy,
                                      Message_Flags flags,
                                      unsigned long priority,
                                      const ACE_Time_Value &execution_time,
                                      const ACE_Time_Value &deadline_time,
                                      ACE_Data_Block *db,
                                      ACE_Allocator *data_block_allocator,
                                      ACE_Allocator *message_block_allocator)
  : flags_ (0),
    data_block_ (0)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (size,
                    msg_type,
                    msg_cont,
                    msg_data,
                    allocator_strategy,
                    locking_strategy,
                    flags,
                    priority,
                    execution_time,
                    deadline_time,
                    db,
                    data_block_allocator,
                    message_block_allocator) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_Message_Block")));
}

ACE_Message_Block::ACE_Message_Block (ACE_Data_Block *data_block,
                                      ACE_Message_Block::Message_Flags flags,
                                      ACE_Allocator *message_block_allocator)
  : flags_ (flags),
    data_block_ (0)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (0,         // size
                    MB_NORMAL, // type
                    0,         // cont
                    0,         // data
                    0,         // allocator
                    0,         // locking strategy
                    0,         // flags
                    0,         // priority
                    ACE_Time_Value::zero,     // execution time
                    ACE_Time_Value::max_time, // absolute time of deadline
                    data_block, // data block
                    data_block->data_block_allocator (),
                    message_block_allocator) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_Message_Block")));
}

ACE_Message_Block::ACE_Message_Block (const ACE_Message_Block &mb,
                                      size_t align)
  :flags_ (0),
   data_block_ (0)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (ACE_BIT_DISABLED (mb.flags_,
                        ACE_Message_Block::DONT_DELETE))
    {
      if (this->init_i (0,         // size
                        MB_NORMAL, // type
                        0,         // cont
                        0,         // data
                        0,         // allocator
                        0,         // locking strategy
                        0,         // flags
                        0,         // priority
                        ACE_Time_Value::zero,     // execution time
                        ACE_Time_Value::max_time, // absolute time of deadline
                        mb.data_block ()->duplicate (), // data block
                        mb.data_block ()->data_block_allocator (),
                        mb.message_block_allocator_) == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("ACE_Message_Block")));
#if !defined (ACE_LACKS_CDR_ALIGNMENT)
      // Align ourselves
      char *start = ACE_ptr_align_binary (this->base (),
                                          align);
#else
      char *start = this->base ();
#endif /* ACE_LACKS_CDR_ALIGNMENT */

      // Set our rd & wr pointers
      this->rd_ptr (start);
      this->wr_ptr (start);

    }
  else
    {
      if (this->init_i (0,         // size
                        MB_NORMAL, // type
                        0,         // cont
                        0,         // data
                        0,         // allocator
                        0,         // locking strategy
                        0,         // flags
                        0,         // priority
                        ACE_Time_Value::zero,     // execution time
                        ACE_Time_Value::max_time, // absolute time of deadline
                        mb.data_block ()->clone_nocopy (),// data block
                        mb.data_block ()->data_block_allocator (),
                        mb.message_block_allocator_) == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("ACE_Message_Block")));

#if !defined (ACE_LACKS_CDR_ALIGNMENT)
      // Align ourselves
      char *start = ACE_ptr_align_binary (this->base (),
                                          align);
#else
      char *start = this->base ();
#endif /* ACE_LACKS_CDR_ALIGNMENT */

      // Set our rd & wr pointers
      this->rd_ptr (start);
      this->wr_ptr (start);

#if !defined (ACE_LACKS_CDR_ALIGNMENT)
      // Get the alignment offset of the incoming ACE_Message_Block
      start = ACE_ptr_align_binary (mb.base (),
                                    align);
#else
      start = mb.base ();
#endif /* ACE_LACKS_CDR_ALIGNMENT */

      // Actual offset for the incoming message block assuming that it
      // is also aligned to the same "align" byte
      size_t const wr_offset = mb.wr_ptr_ - (start - mb.base ());

      // Copy wr_offset amount of data in to <this->data_block>
      (void) ACE_OS::memcpy (this->wr_ptr (),
                             start,
                             wr_offset);

      // Dont move the write pointer, just leave it to the application
      // to do what it wants

    }
#if defined (ACE_LACKS_CDR_ALIGNMENT)
  ACE_UNUSED_ARG (align);
#endif /* ACE_LACKS_CDR_ALIGNMENT */
}

int
ACE_Message_Block::init_i (size_t size,
                           ACE_Message_Type msg_type,
                           ACE_Message_Block *msg_cont,
                           const char *msg_data,
                           ACE_Allocator *allocator_strategy,
                           ACE_Lock *locking_strategy,
                           Message_Flags flags,
                           unsigned long priority,
                           const ACE_Time_Value &execution_time,
                           const ACE_Time_Value &deadline_time,
                           ACE_Data_Block *db,
                           ACE_Allocator *data_block_allocator,
                           ACE_Allocator *message_block_allocator)
{
  ACE_TRACE ("ACE_Message_Block::init_i");
  ACE_FUNCTION_TIMEPROBE (ACE_MESSAGE_BLOCK_INIT_I_ENTER);

  this->rd_ptr_ = 0;
  this->wr_ptr_ = 0;
  this->priority_ = priority;
#if defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
  this->execution_time_ = execution_time;
  this->deadline_time_ = deadline_time;
#else
  ACE_UNUSED_ARG (execution_time);
  ACE_UNUSED_ARG (deadline_time);
#endif /* ACE_HAS_TIMED_MESSAGE_BLOCKS */
  this->cont_ = msg_cont;
  this->next_ = 0;
  this->prev_ = 0;

  this->message_block_allocator_ = message_block_allocator;

  if (this->data_block_ != 0)
    {
      this->data_block_->release ();
      this->data_block_ = 0;
    }

  if (db == 0)
    {
      if (data_block_allocator == 0)
        ACE_ALLOCATOR_RETURN (data_block_allocator,
                              ACE_Allocator::instance (),
                              -1);

      ACE_TIMEPROBE (ACE_MESSAGE_BLOCK_INIT_I_DB_ALLOC);

      // Allocate the <ACE_Data_Block> portion, which is reference
      // counted.
      ACE_NEW_MALLOC_RETURN (db,
                             static_cast<ACE_Data_Block *> (
                               data_block_allocator->malloc (sizeof (ACE_Data_Block))),
                             ACE_Data_Block (size,
                                             msg_type,
                                             msg_data,
                                             allocator_strategy,
                                             locking_strategy,
                                             flags,
                                             data_block_allocator),
                             -1);
      ACE_TIMEPROBE (ACE_MESSAGE_BLOCK_INIT_I_DB_CTOR);

      // Message block initialization may fail, while the construction
      // succeds.  Since ACE may throw no exceptions, we have to do a
      // separate check and clean up, like this:
      if (db != 0 && db->size () < size)
        {
          db->ACE_Data_Block::~ACE_Data_Block();  // placement destructor ...
          data_block_allocator->free (db); // free ...
          errno = ENOMEM;
          return -1;
        }
    }

  // Reset the data_block_ pointer.
  this->data_block (db);

  return 0;
}

ACE_Data_Block::~ACE_Data_Block (void)
{
  // Sanity check...
  ACE_ASSERT (this->reference_count_ <= 1);

  // Just to be safe...
  this->reference_count_ = 0;

  if (ACE_BIT_DISABLED (this->flags_,
                        ACE_Message_Block::DONT_DELETE))
    {
      this->allocator_strategy_->free ((void *) this->base_);
      this->base_ = 0;
    }
}

ACE_Data_Block *
ACE_Data_Block::release_i (void)
{
  ACE_TRACE ("ACE_Data_Block::release_i");

  ACE_ASSERT (this->reference_count_ > 0);

  ACE_Data_Block *result = 0;

  // decrement reference count
  --this->reference_count_;

  if (this->reference_count_ == 0)
    // this will cause deletion of this
    result = 0;
  else
    result = this;

  return result;
}

ACE_Data_Block *
ACE_Data_Block::release_no_delete (ACE_Lock *lock)
{
  ACE_TRACE ("ACE_Data_Block::release_no_delete");

  ACE_Data_Block *result = 0;
  ACE_Lock *lock_to_be_used = 0;

  // Check if we were passed in a lock
  if (lock != 0)
    {
      // Make sure that the lock passed in and our lock are the same
      if (lock == this->locking_strategy_)
        // In this case no locking is required.
        lock_to_be_used = 0;

      // The lock passed in does not match our lock
      else
        // Lock to be used is our lock
        lock_to_be_used = this->locking_strategy_;
    }
  // This is the case when no lock was passed in
  else
    // Lock to be used is our lock
    lock_to_be_used = this->locking_strategy_;

  // If there's a locking strategy then we need to acquire the lock
  // before decrementing the count.
  if (lock_to_be_used != 0)
    {
      ACE_GUARD_RETURN (ACE_Lock, ace_mon, *lock_to_be_used, 0);

      result = this->release_i ();
    }
  else
    result = this->release_i ();

  return result;
}

ACE_Data_Block *
ACE_Data_Block::release (ACE_Lock *lock)
{
  ACE_TRACE ("ACE_Data_Block::release");

  ACE_Allocator *allocator = this->data_block_allocator_;

  ACE_Data_Block *result = this->release_no_delete (lock);

  // We must delete this outside the scope of the locking_strategy_
  // since otherwise we'd be trying to "release" through a deleted
  // pointer!
  if (result == 0)
    ACE_DES_FREE (this,
                  allocator->free,
                  ACE_Data_Block);
  return result;
}

ACE_Message_Block *
ACE_Message_Block::release (void)
{
  ACE_TRACE ("ACE_Message_Block::release");

  // We want to hold the data block in a temporary variable because we
  // invoked "delete this;" at some point, so using this->data_block_
  // could be a bad idea.
  ACE_Data_Block *tmp = this->data_block ();

  // This flag is set to 1 when we have to destroy the data_block
  int destroy_dblock = 0;

  ACE_Lock *lock = 0;

  // Do we have a valid data block
  if (this->data_block ())
    {
      // Grab the lock that belongs to my data block
      lock = this->data_block ()->locking_strategy ();

      // if we have a lock
      if (lock != 0)
        {
          // One guard for all
          ACE_GUARD_RETURN (ACE_Lock, ace_mon, *lock, 0);

          // Call non-guarded release with <lock>
          destroy_dblock = this->release_i (lock);
        }
      // This is the case when we have a valid data block but no lock
      else
        // Call non-guarded release with no lock
        destroy_dblock = this->release_i (0);
    }
  else
    // This is the case when we don't even have a valid data block
    destroy_dblock = this->release_i (0);

  if (destroy_dblock != 0)
    {
      ACE_Allocator *allocator = tmp->data_block_allocator ();
      ACE_DES_FREE (tmp,
                    allocator->free,
                    ACE_Data_Block);
    }

  return 0;
}

int
ACE_Message_Block::release_i (ACE_Lock *lock)
{
  ACE_TRACE ("ACE_Message_Block::release_i");

  // Free up all the continuation messages.
  if (this->cont_)
    {
      ACE_Message_Block *mb = this->cont_;
      ACE_Message_Block *tmp = 0;

      do
        {
          tmp = mb;
          mb = mb->cont_;
          tmp->cont_ = 0;

          ACE_Data_Block *db = tmp->data_block ();
          if (tmp->release_i (lock) != 0)
            {
              ACE_Allocator *allocator = db->data_block_allocator ();
              ACE_DES_FREE (db,
                            allocator->free,
                            ACE_Data_Block);
            }
        }
      while (mb);

      this->cont_ = 0;
    }

  int result = 0;

  if (ACE_BIT_DISABLED (this->flags_,
                        ACE_Message_Block::DONT_DELETE) &&
      this->data_block ())
    {
      if (this->data_block ()->release_no_delete (lock) == 0)
        result = 1;
      this->data_block_ = 0;
    }

  // We will now commit suicide: this object *must* have come from the
  // allocator given.
  if (this->message_block_allocator_ == 0)
    delete this;
  else
    {
      ACE_Allocator *allocator = this->message_block_allocator_;
      ACE_DES_FREE (this,
                    allocator->free,
                    ACE_Message_Block);
    }

  return result;
}

/* static */ ACE_Message_Block *
ACE_Message_Block::release (ACE_Message_Block *mb)
{
  ACE_TRACE ("ACE_Message_Block::release");

  if (mb != 0)
    return mb->release ();
  else
    return 0;
}

ACE_Message_Block::~ACE_Message_Block (void)
{
  ACE_TRACE ("ACE_Message_Block::~ACE_Message_Block");

  if (ACE_BIT_DISABLED (this->flags_,
                        ACE_Message_Block::DONT_DELETE)&&
      this->data_block ())
    this->data_block ()->release ();

  this->prev_ = 0;
  this->next_ = 0;
}

ACE_Data_Block *
ACE_Data_Block::duplicate (void)
{
  ACE_TRACE ("ACE_Data_Block::duplicate");

  // Create a new <ACE_Message_Block>, but share the <base_> pointer
  // data (i.e., don't copy that).
  if (this->locking_strategy_)
    {
      // We need to acquire the lock before incrementing the count.
      ACE_GUARD_RETURN (ACE_Lock, ace_mon, *this->locking_strategy_, 0);
      ++this->reference_count_;
    }
  else
    ++this->reference_count_;

  return this;
}

#if defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
#define ACE_EXECUTION_TIME this->execution_time_
#define ACE_DEADLINE_TIME this->deadline_time_
#else
#define ACE_EXECUTION_TIME ACE_Time_Value::zero
#define ACE_DEADLINE_TIME ACE_Time_Value::max_time
#endif /* ACE_HAS_TIMED_MESSAGE_BLOCKS */

ACE_Message_Block *
ACE_Message_Block::duplicate (void) const
{
  ACE_TRACE ("ACE_Message_Block::duplicate");

  ACE_Message_Block *nb = 0;

  // Create a new <ACE_Message_Block> that contains unique copies of
  // the message block fields, but a reference counted duplicate of
  // the <ACE_Data_Block>.

  // If there is no allocator, use the standard new and delete calls.
  if (this->message_block_allocator_ == 0)
    ACE_NEW_RETURN (nb,
                    ACE_Message_Block (0, // size
                                       ACE_Message_Type (0), // type
                                       0, // cont
                                       0, // data
                                       0, // allocator
                                       0, // locking strategy
                                       0, // flags
                                       this->priority_, // priority
                                       ACE_EXECUTION_TIME,
                                       ACE_DEADLINE_TIME,
                                       // Get a pointer to a
                                       // "duplicated" <ACE_Data_Block>
                                       // (will simply increment the
                                       // reference count).
                                       this->data_block ()->duplicate  (),
                                       this->data_block ()->data_block_allocator (),
                                       this->message_block_allocator_),
                  0);
  else // Otherwise, use the message_block_allocator passed in.
    ACE_NEW_MALLOC_RETURN (nb,
                           static_cast<ACE_Message_Block*> (
                             message_block_allocator_->malloc (sizeof (ACE_Message_Block))),
                           ACE_Message_Block (0, // size
                                              ACE_Message_Type (0), // type
                                              0, // cont
                                              0, // data
                                              0, // allocator
                                              0, // locking strategy
                                              0, // flags
                                              this->priority_, // priority
                                              ACE_EXECUTION_TIME,
                                              ACE_DEADLINE_TIME,
                                              // Get a pointer to a
                                              // "duplicated" <ACE_Data_Block>
                                              // (will simply increment the
                                              // reference count).
                                              this->data_block ()->duplicate  (),
                                              this->data_block ()->data_block_allocator (),
                                              this->message_block_allocator_),
                           0);

  // Set the read and write pointers in the new <Message_Block> to the
  // same relative offset as in the existing <Message_Block>.  Note
  // that we are assuming that the data_block()->base() pointer
  // doesn't change when it's duplicated.
  nb->rd_ptr (this->rd_ptr_);
  nb->wr_ptr (this->wr_ptr_);

  // Increment the reference counts of all the continuation messages.
  if (this->cont_)
    {
      nb->cont_ = this->cont_->duplicate ();

      // If things go wrong, release all of our resources and return
      // 0.
      if (nb->cont_ == 0)
        {
          nb->release ();
          nb = 0;
        }
    }

  return nb;
}

ACE_Message_Block *
ACE_Message_Block::duplicate (const ACE_Message_Block *mb)
{
  ACE_TRACE ("ACE_Message_Block::duplicate");
  if (mb == 0)
    return 0;
  else
    return mb->duplicate ();
}

ACE_Data_Block *
ACE_Data_Block::clone (ACE_Message_Block::Message_Flags mask) const
{
  ACE_TRACE ("ACE_Data_Block::clone");

  ACE_Data_Block *nb = this->clone_nocopy (mask);

  // Copy all of the payload memory into the new object. The new block
  // was allocated with max_size_ (and, thus, it's cur_size_ is the same
  // as max_size_). Maintain the same "has been written" boundary in the
  // new block by only copying cur_size_ bytes.
  if (nb != 0)
    {
      ACE_OS::memcpy (nb->base_,
                      this->base_,
                      this->cur_size_);
    }

  return nb;
}

ACE_Data_Block *
ACE_Data_Block::clone_nocopy (ACE_Message_Block::Message_Flags mask,
                              size_t max_size) const
{
  ACE_FUNCTION_TIMEPROBE(ACE_DATA_BLOCK_CLONE_ENTER);

  ACE_TRACE ("ACE_Data_Block::clone_nocopy");

  // You always want to clear this one to prevent memory leaks but you
  // might add some others later.
  const ACE_Message_Block::Message_Flags always_clear =
    ACE_Message_Block::DONT_DELETE;

  const size_t newsize =
    max_size == 0 ? this->max_size_ : max_size;

  ACE_Data_Block *nb = 0;

  ACE_NEW_MALLOC_RETURN (nb,
                         static_cast<ACE_Data_Block*> (
                           this->data_block_allocator_->malloc (sizeof (ACE_Data_Block))),
                         ACE_Data_Block (newsize, // size
                                         this->type_,     // type
                                         0,               // data
                                         this->allocator_strategy_, // allocator
                                         this->locking_strategy_, // locking strategy
                                         this->flags_,  // flags
                                         this->data_block_allocator_),
                         0);

  // Message block initialization may fail while the construction
  // succeds.  Since as a matter of policy, ACE may throw no
  // exceptions, we have to do a separate check like this.
  if (nb != 0 && nb->size () < newsize)
    {
      nb->ACE_Data_Block::~ACE_Data_Block();  // placement destructor ...
      this->data_block_allocator_->free (nb); // free ...
      errno = ENOMEM;
      return 0;
    }


  // Set new flags minus the mask...
  nb->clr_flags (mask | always_clear);
  return nb;
}

ACE_Message_Block *
ACE_Message_Block::clone (Message_Flags mask) const
{
  ACE_TRACE ("ACE_Message_Block::clone");

  // Get a pointer to a "cloned" <ACE_Data_Block> (will copy the
  // values rather than increment the reference count).
  ACE_Data_Block *db = this->data_block ()->clone (mask);

  if (db == 0)
    return 0;

  ACE_Message_Block *nb = 0;

  if(message_block_allocator_ == 0)
    {
      ACE_NEW_RETURN (nb,
                      ACE_Message_Block (0, // size
                                         ACE_Message_Type (0), // type
                                         0, // cont
                                         0, // data
                                         0, // allocator
                                         0, // locking strategy
                                         0, // flags
                                         this->priority_, // priority
                                         ACE_EXECUTION_TIME, // execution time
                                         ACE_DEADLINE_TIME, // absolute time to deadline
                                         // Get a pointer to a
                                         // "duplicated" <ACE_Data_Block>
                                         // (will simply increment the
                                         // reference count).
                                         db,
                                         db->data_block_allocator (),
                                         this->message_block_allocator_),
                      0);
    }
  else
    {
      // This is the ACE_NEW_MALLOC macro with the return check removed.
      // We need to do it this way because if it fails we need to release
      // the cloned data block that was created above.  If we used
      // ACE_NEW_MALLOC_RETURN, there would be a memory leak because the
      // above db pointer would be left dangling.
      nb = static_cast<ACE_Message_Block*> (message_block_allocator_->malloc (sizeof (ACE_Message_Block)));
      if(nb != 0)
        new (nb) ACE_Message_Block (0, // size
                                    ACE_Message_Type (0), // type
                                    0, // cont
                                    0, // data
                                    0, // allocator
                                    0, // locking strategy
                                    0, // flags
                                    this->priority_, // priority
                                    ACE_EXECUTION_TIME, // execution time
                                    ACE_DEADLINE_TIME, // absolute time to deadline
                                    db,
                                    db->data_block_allocator (),
                                    this->message_block_allocator_);
    }

  if (nb == 0)
    {
      db->release ();
      return 0;
    }

  // Set the read and write pointers in the new <Message_Block> to the
  // same relative offset as in the existing <Message_Block>.
  nb->rd_ptr (this->rd_ptr_);
  nb->wr_ptr (this->wr_ptr_);

  // Clone all the continuation messages if necessary.
  if (this->cont () != 0
      && (nb->cont_ = this->cont ()->clone (mask)) == 0)
    {
      nb->release ();
      return 0;
    }
  return nb;
}

// This is private.
ACE_Message_Block &
ACE_Message_Block::operator= (const ACE_Message_Block &)
{
  ACE_TRACE ("ACE_Message_Block::operator=");
  return *this;
}

void
ACE_Data_Block::base (char *msg_data,
                      size_t msg_length,
                      ACE_Message_Block::Message_Flags msg_flags)
{
  if (ACE_BIT_DISABLED (this->flags_,
                        ACE_Message_Block::DONT_DELETE))
    this->allocator_strategy_->free (this->base_);

  this->max_size_ = msg_length;
  this->cur_size_ = msg_length;
  this->base_ = msg_data;
  this->flags_ = msg_flags;
}

ACE_END_VERSIONED_NAMESPACE_DECL

