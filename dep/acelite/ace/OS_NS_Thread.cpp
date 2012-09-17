// $Id: OS_NS_Thread.cpp 96061 2012-08-16 09:36:07Z mcorino $

#include "ace/OS_NS_Thread.h"

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_Thread.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#include "ace/OS_NS_stdio.h"
#include "ace/Sched_Params.h"
#include "ace/OS_Memory.h"
#include "ace/OS_Thread_Adapter.h"
#include "ace/Min_Max.h"
#include "ace/Object_Manager_Base.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_ctype.h"
#include "ace/Log_Msg.h" // for ACE_ASSERT
// This is necessary to work around nasty problems with MVS C++.
#include "ace/Auto_Ptr.h"
#include "ace/Thread_Mutex.h"
#include "ace/Condition_Thread_Mutex.h"
#include "ace/Guard_T.h"

extern "C" void
ACE_MUTEX_LOCK_CLEANUP_ADAPTER_NAME (void *args)
{
  ACE_VERSIONED_NAMESPACE_NAME::ACE_OS::mutex_lock_cleanup (args);
}


#if !defined(ACE_WIN32) && defined (__IBMCPP__) && (__IBMCPP__ >= 400)
# define ACE_BEGINTHREADEX(STACK, STACKSIZE, ENTRY_POINT, ARGS, FLAGS, THR_ID) \
       (*THR_ID = ::_beginthreadex ((void(_Optlink*)(void*))ENTRY_POINT, STACK, STACKSIZE, ARGS), *THR_ID)
#elif defined (ACE_HAS_WINCE)
# define ACE_BEGINTHREADEX(STACK, STACKSIZE, ENTRY_POINT, ARGS, FLAGS, THR_ID) \
      CreateThread (0, STACKSIZE, (unsigned long (__stdcall *) (void *)) ENTRY_POINT, ARGS, (FLAGS) & (CREATE_SUSPENDED | STACK_SIZE_PARAM_IS_A_RESERVATION), (unsigned long *) THR_ID)
#elif defined(ACE_HAS_WTHREADS)
  // Green Hills compiler gets confused when __stdcall is imbedded in
  // parameter list, so we define the type ACE_WIN32THRFUNC_T and use it
  // instead.
  typedef unsigned (__stdcall *ACE_WIN32THRFUNC_T)(void*);
# define ACE_BEGINTHREADEX(STACK, STACKSIZE, ENTRY_POINT, ARGS, FLAGS, THR_ID) \
      ::_beginthreadex (STACK, STACKSIZE, (ACE_WIN32THRFUNC_T) ENTRY_POINT, ARGS, FLAGS, (unsigned int *) THR_ID)
#endif /* defined (__IBMCPP__) && (__IBMCPP__ >= 400) */

/*****************************************************************************/

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

void
ACE_Thread_ID::to_string (char *thr_string) const
{
#if defined (ACE_WIN32)
  ACE_OS::sprintf (thr_string, "%u",
                   static_cast <unsigned> (this->thread_id_));
#else
  // Yes, this is an ugly C-style cast, but the
  // correct C++ cast is different depending on
  // whether the t_id is an integral type or a pointer
  // type. FreeBSD uses a pointer type, but doesn't
  // have a _np function to get an integral type like
  // other OSes, so use the bigger hammer.
  ACE_OS::sprintf (thr_string, "%lu",
                   (unsigned long) thread_handle_);
#endif /* ACE_WIN32 */
}

/*****************************************************************************/

#if defined (ACE_WIN32) || defined (ACE_HAS_TSS_EMULATION)

#if defined (ACE_HAS_TSS_EMULATION)
u_int ACE_TSS_Emulation::total_keys_ = 0;

ACE_TSS_Keys* ACE_TSS_Emulation::tss_keys_used_ = 0;

ACE_TSS_Emulation::ACE_TSS_DESTRUCTOR
ACE_TSS_Emulation::tss_destructor_[ACE_TSS_Emulation::ACE_TSS_THREAD_KEYS_MAX]
 = { 0 };

#  if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)

bool ACE_TSS_Emulation::key_created_ = false;

ACE_OS_thread_key_t ACE_TSS_Emulation::native_tss_key_;

/* static */
#    if defined (ACE_HAS_THR_C_FUNC)
extern "C"
void
ACE_TSS_Emulation_cleanup (void *)
{
   // Really this must be used for ACE_TSS_Emulation code to make the TSS
   // cleanup
}
#    else
void
ACE_TSS_Emulation_cleanup (void *)
{
   // Really this must be used for ACE_TSS_Emulation code to make the TSS
   // cleanup
}
#    endif /* ACE_HAS_THR_C_FUNC */

void **
ACE_TSS_Emulation::tss_base (void* ts_storage[], u_int *ts_created)
{
  // TSS Singleton implementation.

  // Create the one native TSS key, if necessary.
  if (!key_created_)
    {
      // Double-checked lock . . .
      ACE_TSS_BASE_GUARD

      if (!key_created_)
        {
          ACE_NO_HEAP_CHECK;
          if (ACE_OS::thr_keycreate_native (&native_tss_key_,
                                     &ACE_TSS_Emulation_cleanup) != 0)
            {
              ACE_ASSERT (0);
              return 0; // Major problems, this should *never* happen!
            }
          key_created_ = true;
        }
    }

  void **old_ts_storage = 0;

  // Get the tss_storage from thread-OS specific storage.
  if (ACE_OS::thr_getspecific_native (native_tss_key_,
                               (void **) &old_ts_storage) == -1)
    {
      ACE_ASSERT (false);
      return 0; // This should not happen!
    }

  // Check to see if this is the first time in for this thread.
  // This block can also be entered after a fork () in the child process.
  if (old_ts_storage == 0)
    {
      if (ts_created)
        *ts_created = 1u;

      // Use the ts_storage passed as argument, if non-zero.  It is
      // possible that this has been implemented in the stack. At the
      // moment, this is unknown.  The cleanup must not do nothing.
      // If ts_storage is zero, allocate (and eventually leak) the
      // storage array.
      if (ts_storage == 0)
        {
          ACE_NO_HEAP_CHECK;

          ACE_NEW_RETURN (ts_storage,
                          void*[ACE_TSS_THREAD_KEYS_MAX],
                          0);

          // Zero the entire TSS array.  Do it manually instead of
          // using memset, for optimum speed.  Though, memset may be
          // faster :-)
          void **tss_base_p = ts_storage;

          for (u_int i = 0;
               i < ACE_TSS_THREAD_KEYS_MAX;
               ++i)
            *tss_base_p++ = 0;
        }

       // Store the pointer in thread-specific storage.  It gets
       // deleted via the ACE_TSS_Emulation_cleanup function when the
       // thread terminates.
       if (ACE_OS::thr_setspecific_native (native_tss_key_,
                                    (void *) ts_storage) != 0)
          {
            ACE_ASSERT (false);
            return 0; // This should not happen!
          }
    }
  else
    if (ts_created)
      ts_created = 0;

  return ts_storage  ?  ts_storage  :  old_ts_storage;
}
#  endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */

u_int
ACE_TSS_Emulation::total_keys ()
{
  ACE_OS_Recursive_Thread_Mutex_Guard (
    *static_cast <ACE_recursive_thread_mutex_t *>
                      (ACE_OS_Object_Manager::preallocated_object[
                        ACE_OS_Object_Manager::ACE_TSS_KEY_LOCK]));

  return total_keys_;
}

int
ACE_TSS_Emulation::next_key (ACE_thread_key_t &key)
{
  ACE_OS_Recursive_Thread_Mutex_Guard (
    *static_cast <ACE_recursive_thread_mutex_t *>
                      (ACE_OS_Object_Manager::preallocated_object[
                        ACE_OS_Object_Manager::ACE_TSS_KEY_LOCK]));

  // Initialize the tss_keys_used_ pointer on first use.
  if (tss_keys_used_ == 0)
    {
      ACE_NEW_RETURN (tss_keys_used_, ACE_TSS_Keys, -1);
    }

  if (total_keys_ < ACE_TSS_THREAD_KEYS_MAX)
    {
       u_int counter = 0;
       // Loop through all possible keys and check whether a key is free
       for ( ;counter < ACE_TSS_THREAD_KEYS_MAX; counter++)
         {
            ACE_thread_key_t localkey = counter;
            // If the key is not set as used, we can give out this key, if not
            // we have to search further
            if (tss_keys_used_->is_set(localkey) == 0)
            {
               tss_keys_used_->test_and_set(localkey);
               key = localkey;
               break;
            }
         }

      ++total_keys_;
      return 0;
    }
  else
    {
      key = ACE_OS::NULL_key;
      return -1;
    }
}

int
ACE_TSS_Emulation::release_key (ACE_thread_key_t key)
{
  ACE_OS_Recursive_Thread_Mutex_Guard (
    *static_cast <ACE_recursive_thread_mutex_t *>
                      (ACE_OS_Object_Manager::preallocated_object[
                        ACE_OS_Object_Manager::ACE_TSS_KEY_LOCK]));

  if (tss_keys_used_ != 0 &&
      tss_keys_used_->test_and_clear (key) == 0)
  {
    --total_keys_;
    return 0;
  }
  return 1;
}

int
ACE_TSS_Emulation::is_key (ACE_thread_key_t key)
{
  ACE_OS_Recursive_Thread_Mutex_Guard (
    *static_cast <ACE_recursive_thread_mutex_t *>
                      (ACE_OS_Object_Manager::preallocated_object[
                        ACE_OS_Object_Manager::ACE_TSS_KEY_LOCK]));

  if (tss_keys_used_ != 0 &&
      tss_keys_used_->is_set (key) == 1)
  {
    return 1;
  }
  return 0;
}

void *
ACE_TSS_Emulation::tss_open (void *ts_storage[ACE_TSS_THREAD_KEYS_MAX])
{
#    if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
        // On VxWorks, in particular, don't check to see if the field
        // is 0.  It isn't always, specifically, when a program is run
        // directly by the shell (without spawning a new task) after
        // another program has been run.

  u_int ts_created = 0;
  tss_base (ts_storage, &ts_created);
  if (ts_created)
    {
#    else  /* ! ACE_HAS_THREAD_SPECIFIC_STORAGE */
      tss_base () = ts_storage;
#    endif

      // Zero the entire TSS array.  Do it manually instead of using
      // memset, for optimum speed.  Though, memset may be faster :-)
      void **tss_base_p = tss_base ();
      for (u_int i = 0; i < ACE_TSS_THREAD_KEYS_MAX; ++i, ++tss_base_p)
        {
          *tss_base_p = 0;
        }

      return tss_base ();
#    if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
    }
  else
    {
      return 0;
    }
#    endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */
}

void
ACE_TSS_Emulation::tss_close ()
{
#if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
  ACE_OS::thr_keyfree_native (native_tss_key_);
#endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */
}

#endif /* ACE_HAS_TSS_EMULATION */

#endif /* WIN32 || ACE_HAS_TSS_EMULATION */

/*****************************************************************************/

#if defined (ACE_WIN32) || defined (ACE_HAS_TSS_EMULATION)

// Moved class ACE_TSS_Ref declaration to OS.h so it can be visible to
// the single file of template instantiations.

ACE_TSS_Ref::ACE_TSS_Ref (ACE_thread_t id)
  : tid_(id)
{
  ACE_OS_TRACE ("ACE_TSS_Ref::ACE_TSS_Ref");
}

ACE_TSS_Ref::ACE_TSS_Ref (void)
{
  ACE_OS_TRACE ("ACE_TSS_Ref::ACE_TSS_Ref");
}

// Check for equality.
bool
ACE_TSS_Ref::operator== (const ACE_TSS_Ref &info) const
{
  ACE_OS_TRACE ("ACE_TSS_Ref::operator==");

  return this->tid_ == info.tid_;
}

// Check for inequality.
ACE_SPECIAL_INLINE
bool
ACE_TSS_Ref::operator != (const ACE_TSS_Ref &tss_ref) const
{
  ACE_OS_TRACE ("ACE_TSS_Ref::operator !=");

  return !(*this == tss_ref);
}

// moved class ACE_TSS_Info declaration
// to OS.h so it can be visible to the
// single file of template instantiations

ACE_TSS_Info::ACE_TSS_Info (ACE_thread_key_t key,
                            ACE_TSS_Info::Destructor dest)
  : key_ (key),
    destructor_ (dest),
    thread_count_ (-1)
{
  ACE_OS_TRACE ("ACE_TSS_Info::ACE_TSS_Info");
}

ACE_TSS_Info::ACE_TSS_Info (void)
  : key_ (ACE_OS::NULL_key),
    destructor_ (0),
    thread_count_ (-1)
{
  ACE_OS_TRACE ("ACE_TSS_Info::ACE_TSS_Info");
}

// Check for equality.
bool
ACE_TSS_Info::operator== (const ACE_TSS_Info &info) const
{
  ACE_OS_TRACE ("ACE_TSS_Info::operator==");

  return this->key_ == info.key_;
}

// Check for inequality.
bool
ACE_TSS_Info::operator != (const ACE_TSS_Info &info) const
{
  ACE_OS_TRACE ("ACE_TSS_Info::operator !=");

  return !(*this == info);
}

void
ACE_TSS_Info::dump (void)
{
# if defined (ACE_HAS_DUMP)
  //  ACE_OS_TRACE ("ACE_TSS_Info::dump");

#   if 0
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("key_ = %u\n"), this->key_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("destructor_ = %u\n"), this->destructor_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#   endif /* 0 */
# endif /* ACE_HAS_DUMP */
}

// Moved class ACE_TSS_Keys declaration to OS.h so it can be visible
// to the single file of template instantiations.

ACE_TSS_Keys::ACE_TSS_Keys (void)
{
  for (u_int i = 0; i < ACE_WORDS; ++i)
    {
      key_bit_words_[i] = 0;
    }
}

ACE_SPECIAL_INLINE
void
ACE_TSS_Keys::find (const u_int key, u_int &word, u_int &bit)
{
  word = key / ACE_BITS_PER_WORD;
  bit = key % ACE_BITS_PER_WORD;
}

int
ACE_TSS_Keys::test_and_set (const ACE_thread_key_t key)
{
  u_int word, bit;
  find (key, word, bit);

  if (ACE_BIT_ENABLED (key_bit_words_[word], 1 << bit))
    {
      return 1;
    }
  else
    {
      ACE_SET_BITS (key_bit_words_[word], 1 << bit);
      return 0;
    }
}

int
ACE_TSS_Keys::test_and_clear (const ACE_thread_key_t key)
{
  u_int word, bit;
  find (key, word, bit);

  if (word < ACE_WORDS && ACE_BIT_ENABLED (key_bit_words_[word], 1 << bit))
    {
      ACE_CLR_BITS (key_bit_words_[word], 1 << bit);
      return 0;
    }
  else
    {
      return 1;
    }
}

int
ACE_TSS_Keys::is_set (const ACE_thread_key_t key) const
{
  u_int word, bit;
  find (key, word, bit);

  return word < ACE_WORDS ? ACE_BIT_ENABLED (key_bit_words_[word], 1 << bit) : 0;
}

/**
 * @class ACE_TSS_Cleanup
 * @brief Singleton that helps to manage the lifetime of TSS objects and keys.
 */
class ACE_TSS_Cleanup
{
public:
  /// Register a newly-allocated key
  /// @param key the key to be monitored
  /// @param destructor the function to call to delete objects stored via this key
  int insert (ACE_thread_key_t key, void (*destructor)(void *));

  /// Mark a key as being used by this thread.
  void thread_use_key (ACE_thread_key_t key);

  /// This thread is no longer using this key
  /// call destructor if appropriate
  int thread_detach_key (ACE_thread_key_t key);

  /// This key is no longer used
  ///   Release key if use count == 0
  ///   fail if use_count != 0;
  /// @param key the key to be released
  int free_key (ACE_thread_key_t key);

  /// Cleanup the thread-specific objects.  Does _NOT_ exit the thread.
  /// For each used key perform the same actions as free_key.
  void thread_exit (void);

private:
  void dump (void);

  /// Release a key used by this thread
  /// @param info reference to the info for this key
  /// @param destructor out arg to receive destructor function ptr
  /// @param tss_obj out arg to receive pointer to deletable object
  void thread_release (
          ACE_TSS_Info &info,
          ACE_TSS_Info::Destructor & destructor,
          void *& tss_obj);

  /// remove key if it's unused (thread_count == 0)
  /// @param info reference to the info for this key
  int remove_key (ACE_TSS_Info &info);

  /// Find the TSS keys (if any) for this thread.
  /// @param thread_keys reference to pointer to be filled in by this function.
  /// @return false if keys don't exist.
  bool find_tss_keys (ACE_TSS_Keys *& thread_keys) const;

  /// Accessor for this threads ACE_TSS_Keys instance.
  /// Creates the keys if necessary.
  ACE_TSS_Keys *tss_keys ();

  /// Ensure singleton.
  ACE_TSS_Cleanup (void);
  ~ACE_TSS_Cleanup (void);

  /// ACE_TSS_Cleanup access only via TSS_Cleanup_Instance
  friend class TSS_Cleanup_Instance;

private:
  // Array of <ACE_TSS_Info> objects.
  typedef ACE_TSS_Info ACE_TSS_TABLE[ACE_DEFAULT_THREAD_KEYS];
  typedef ACE_TSS_Info *ACE_TSS_TABLE_ITERATOR;

  /// Table of <ACE_TSS_Info>'s.
  ACE_TSS_TABLE table_;

  /// Key for the thread-specific ACE_TSS_Keys
  /// Used by find_tss_keys() or tss_keys() to find the
  /// bit array that records whether each TSS key is in
  /// use by this thread.
  ACE_thread_key_t in_use_;
};


/*****************************************************************************/
/**
 * @class TSS_Cleanup_Instance
 * @A class to manage an instance pointer to ACE_TSS_Cleanup.
 * Note: that the double checked locking pattern doesn't allow
 * safe deletion.
 * Callers who wish to access the singleton ACE_TSS_Cleanup must
 * do so by instantiating a TSS_Cleanup_Instance, calling the valid
 * method to be sure the ACE_TSS_Cleanup is available, then using
 * the TSS_Cleanup_Instance as a pointer to the instance.
 * Construction argument to the TSS_Cleanup_Instance determines how
 * it is to be used:
 *   CREATE means allow this call to create an ACE_TSS_Cleanup if necessary.
 *   USE means use the existing ACE_TSS_Cleanup, but do not create a new one.
 *   DESTROY means provide exclusive access to the ACE_TSS_Cleanup, then
 *   delete it when the TSS_Cleanup_Instance goes out of scope.
 */

class TSS_Cleanup_Instance
{
public:
  enum Purpose
  {
    CREATE,
    USE,
    DESTROY
  };
  TSS_Cleanup_Instance (Purpose purpose = USE);
  ~TSS_Cleanup_Instance();

  bool valid();
  ACE_TSS_Cleanup * operator ->();

private:

  ACE_TSS_Cleanup * operator *();

private:
  static unsigned int reference_count_;
  static ACE_TSS_Cleanup * instance_;
  static ACE_Thread_Mutex* mutex_;
  static ACE_Condition_Thread_Mutex* condition_;

private:
  ACE_TSS_Cleanup * ptr_;
  unsigned short flags_;
  enum
  {
    FLAG_DELETING = 1,
    FLAG_VALID_CHECKED = 2
  };
};

TSS_Cleanup_Instance::TSS_Cleanup_Instance (Purpose purpose)
  : ptr_(0)
  , flags_(0)
{
  // During static construction or construction of the ACE_Object_Manager,
  // there can be only one thread in this constructor at any one time, so
  // it's safe to check for a zero mutex_.  If it's zero, we create a new
  // mutex and condition variable.
  if (mutex_ == 0)
    {
      ACE_NEW (mutex_, ACE_Thread_Mutex ());
      ACE_NEW (condition_, ACE_Condition_Thread_Mutex (*mutex_));
    }

  ACE_GUARD (ACE_Thread_Mutex, m, *mutex_);

  if (purpose == CREATE)
  {
    if (instance_ == 0)
    {
      instance_ = new ACE_TSS_Cleanup();
    }
    ptr_ = instance_;
    ++reference_count_;
  }
  else if(purpose == DESTROY)
  {
    if (instance_ != 0)
    {
      ptr_ = instance_;
      instance_ = 0;
      ACE_SET_BITS(flags_, FLAG_DELETING);
      while (reference_count_ > 0)
      {
        condition_->wait();
      }
    }
  }
  else // must be normal use
  {
    ACE_ASSERT(purpose == USE);
    if (instance_ != 0)
      {
        ptr_ = instance_;
        ++reference_count_;
      }
  }
}

TSS_Cleanup_Instance::~TSS_Cleanup_Instance (void)
{
  // Variable to hold the mutex_ to delete outside the scope of the
  // guard.
  ACE_Thread_Mutex *del_mutex = 0;

  // scope the guard
  {
    ACE_GUARD (ACE_Thread_Mutex, guard, *mutex_);
    if (ptr_ != 0)
      {
        if (ACE_BIT_ENABLED (flags_, FLAG_DELETING))
          {
            ACE_ASSERT(instance_ == 0);
            ACE_ASSERT(reference_count_ == 0);
            delete ptr_;
            del_mutex = mutex_ ;
            mutex_ = 0;
          }
        else
          {
            ACE_ASSERT (reference_count_ > 0);
            --reference_count_;
            if (reference_count_ == 0 && instance_ == 0)
              condition_->signal ();
          }
      }
  }// end of guard scope

  if (del_mutex != 0)
    {
      delete condition_;
      condition_ = 0;
      delete del_mutex;
    }
}

bool
TSS_Cleanup_Instance::valid()
{
  ACE_SET_BITS(flags_, FLAG_VALID_CHECKED);
  return (this->instance_ != 0);
}

ACE_TSS_Cleanup *
TSS_Cleanup_Instance::operator *()
{
  ACE_ASSERT(ACE_BIT_ENABLED(flags_, FLAG_VALID_CHECKED));
  return instance_;
}

ACE_TSS_Cleanup *
TSS_Cleanup_Instance::operator ->()
{
  ACE_ASSERT(ACE_BIT_ENABLED(flags_, FLAG_VALID_CHECKED));
  return instance_;
}

// = Static object initialization.
unsigned int TSS_Cleanup_Instance::reference_count_ = 0;
ACE_TSS_Cleanup * TSS_Cleanup_Instance::instance_ = 0;
ACE_Thread_Mutex* TSS_Cleanup_Instance::mutex_ = 0;
ACE_Condition_Thread_Mutex* TSS_Cleanup_Instance::condition_ = 0;

ACE_TSS_Cleanup::~ACE_TSS_Cleanup (void)
{
}

void
ACE_TSS_Cleanup::thread_exit (void)
{
  ACE_OS_TRACE ("ACE_TSS_Cleanup::thread_exit");
  // variables to hold the destructors, keys
  // and pointers to the object to be destructed
  // the actual destruction is deferred until the guard is released
  ACE_TSS_Info::Destructor destructor[ACE_DEFAULT_THREAD_KEYS];
  void * tss_obj[ACE_DEFAULT_THREAD_KEYS];
  ACE_thread_key_t keys[ACE_DEFAULT_THREAD_KEYS];
  // count of items to be destroyed
  unsigned int d_count = 0;

  // scope the guard
  {
    ACE_TSS_CLEANUP_GUARD

    // if not initialized or already cleaned up
    ACE_TSS_Keys *this_thread_keys = 0;
    if (! find_tss_keys (this_thread_keys) )
      {
        return;
      }

    // Minor hack: Iterating in reverse order means the LOG buffer which is
    // accidentally allocated first will be accidentally deallocated (almost)
    // last -- in case someone logs something from the other destructors.
    // applications should not count on this behavior because platforms which
    // do not use ACE_TSS_Cleanup may delete objects in other orders.
    unsigned int key_index = ACE_DEFAULT_THREAD_KEYS;
    while( key_index > 0)
      {
        --key_index;
        ACE_TSS_Info & info = this->table_[key_index];
        // if this key is in use by this thread
        if (info.key_in_use () && this_thread_keys->is_set(info.key_))
          {
            // defer deleting the in-use key until all others have been deleted
            if(info.key_ != this->in_use_)
              {
                destructor[d_count] = 0;
                tss_obj[d_count] = 0;
                keys[d_count] = 0;
                this->thread_release (info, destructor[d_count], tss_obj[d_count]);
                if (destructor[d_count] != 0 && tss_obj[d_count] != 0)
                  {
                    keys[d_count] = info.key_;
                    ++d_count;
                  }
              }
          }
      }

    // remove the in_use bit vector last
    u_int use_index = this->in_use_;
    ACE_TSS_Info & info = this->table_[use_index];
    destructor[d_count] = 0;
    tss_obj[d_count] = 0;
    keys[d_count] = 0;
    this->thread_release (info, destructor[d_count], tss_obj[d_count]);
    if (destructor[d_count] != 0 &&  tss_obj[d_count] != 0)
      {
        keys[d_count] = info.key_;
        ++d_count;
      }
  } // end of guard scope
  for (unsigned int d_index = 0; d_index < d_count; ++d_index)
    {
      (*destructor[d_index])(tss_obj[d_index]);
#if defined (ACE_HAS_TSS_EMULATION)
      ACE_TSS_Emulation::ts_object (keys[d_index]) = 0;
#else // defined (ACE_HAS_TSS_EMULATION)
      ACE_OS::thr_setspecific_native (keys[d_index], 0);
#endif // defined (ACE_HAS_TSS_EMULATION)
    }
}

extern "C" void
ACE_TSS_Cleanup_keys_destroyer (void *tss_keys)
{
  delete static_cast <ACE_TSS_Keys *> (tss_keys);
}

ACE_TSS_Cleanup::ACE_TSS_Cleanup (void)
  : in_use_ (ACE_OS::NULL_key)
{
  ACE_OS_TRACE ("ACE_TSS_Cleanup::ACE_TSS_Cleanup");
}

int
ACE_TSS_Cleanup::insert (ACE_thread_key_t key,
                         void (*destructor)(void *))
{
  ACE_OS_TRACE ("ACE_TSS_Cleanup::insert");
  ACE_TSS_CLEANUP_GUARD

  u_int key_index = key;
  ACE_ASSERT (key_index < ACE_DEFAULT_THREAD_KEYS);
  if (key_index < ACE_DEFAULT_THREAD_KEYS)
    {
      ACE_ASSERT (table_[key_index].thread_count_ == -1);
      table_[key_index] = ACE_TSS_Info (key, destructor);
      table_[key_index].thread_count_ = 0; // inserting it does not use it
                                           // but it does "allocate" it
      return 0;
    }
  else
    {
      return -1;
    }
}

int
ACE_TSS_Cleanup::free_key (ACE_thread_key_t key)
{
  ACE_OS_TRACE ("ACE_TSS_Cleanup::free_key");
  ACE_TSS_CLEANUP_GUARD
  u_int key_index = key;
  if (key_index < ACE_DEFAULT_THREAD_KEYS)
    {
      return remove_key (this->table_ [key_index]);
    }
  return -1;
}

int
ACE_TSS_Cleanup::remove_key (ACE_TSS_Info &info)
{
  // assume CLEANUP_GUARD is held by caller
  ACE_OS_TRACE ("ACE_TSS_Cleanup::remove_key");

#if 0 // This was a good idea, but POSIX says it's legal to delete used keys.
      // When this is done, any existing TSS objects controlled by this key are leaked
      // There is no "right thing" to do in this case

  // only remove it if all threads are done with it
  if (info.thread_count_ != 0)
    {
      return -1;
    }
#endif // 0

#if !defined (ACE_HAS_TSS_EMULATION)
  ACE_OS_thread_key_t temp_key = info.key_;
  ACE_OS::thr_keyfree_native (temp_key);
#endif /* !ACE_HAS_TSS_EMULATION */
  if (info.key_ == this->in_use_)
    {
      this->in_use_ = ACE_OS::NULL_key;
    }
  info.key_in_use (0);
  info.destructor_ = 0;
  return 0;
}

int
ACE_TSS_Cleanup::thread_detach_key (ACE_thread_key_t key)
{
  // variables to hold the destructor and the object to be destructed
  // the actual call is deferred until the guard is released
  ACE_TSS_Info::Destructor destructor = 0;
  void * tss_obj = 0;

  // scope the guard
  {
    ACE_TSS_CLEANUP_GUARD

    u_int key_index = key;
    ACE_ASSERT (key_index < sizeof(this->table_)/sizeof(this->table_[0])
        && this->table_[key_index].key_ == key);
    ACE_TSS_Info &info = this->table_ [key_index];

    // sanity check
    if (!info.key_in_use ())
      {
        return -1;
      }

    this->thread_release (info, destructor, tss_obj);
  } // end of scope for the Guard
  // if there's a destructor and an object to be destroyed
  if (destructor != 0 && tss_obj != 0)
    {
      (*destructor) (tss_obj);
    }
  return 0;
}

void
ACE_TSS_Cleanup::thread_release (
        ACE_TSS_Info &info,
        ACE_TSS_Info::Destructor & destructor,
        void *& tss_obj)
{
  // assume guard is held by caller
  // Find the TSS keys (if any) for this thread
  // do not create them if they don't exist
  ACE_TSS_Keys * thread_keys = 0;
  if (find_tss_keys (thread_keys))
    {
        // if this key is in use by this thread
      if (thread_keys->test_and_clear(info.key_) == 0)
      {
        // save destructor & pointer to tss object
        // until after the guard is released
        destructor = info.destructor_;
        ACE_OS::thr_getspecific (info.key_, &tss_obj);
        ACE_ASSERT (info.thread_count_ > 0);
        --info.thread_count_;
      }
    }
}

void
ACE_TSS_Cleanup::thread_use_key (ACE_thread_key_t key)
{
  // If the key's ACE_TSS_Info in-use bit for this thread is not set,
  // set it and increment the key's thread_count_.
  if (! tss_keys ()->test_and_set (key))
    {
      ACE_TSS_CLEANUP_GUARD

      // Retrieve the key's ACE_TSS_Info and increment its thread_count_.
      u_int key_index = key;
      ACE_TSS_Info &key_info = this->table_ [key_index];

      ACE_ASSERT (key_info.key_in_use ());
      ++key_info.thread_count_;
    }
}

void
ACE_TSS_Cleanup::dump (void)
{
# if defined (ACE_HAS_DUMP)
  // Iterate through all the thread-specific items and dump them all.

  ACE_TSS_TABLE_ITERATOR key_info = table_;
  for (unsigned int i = 0;
       i < ACE_DEFAULT_THREAD_KEYS;
       ++key_info, ++i)
    key_info->dump ();
# endif /* ACE_HAS_DUMP */
}

bool
ACE_TSS_Cleanup::find_tss_keys (ACE_TSS_Keys *& tss_keys) const
{
  if (this->in_use_ == ACE_OS::NULL_key)
    return false;
  if (ACE_OS::thr_getspecific (in_use_,
          reinterpret_cast<void **> (&tss_keys)) == -1)
    {
      ACE_ASSERT (false);
      return false; // This should not happen!
    }
  return tss_keys != 0;
}

ACE_TSS_Keys *
ACE_TSS_Cleanup::tss_keys ()
{
  if (this->in_use_ == ACE_OS::NULL_key)
    {
      ACE_TSS_CLEANUP_GUARD
      // Double-check;
      if (in_use_ == ACE_OS::NULL_key)
        {
          // Initialize in_use_ with a new key.
          if (ACE_OS::thr_keycreate (&in_use_,
                                     &ACE_TSS_Cleanup_keys_destroyer))
            {
              ACE_ASSERT (false);
              return 0; // Major problems, this should *never* happen!
            }
        }
    }

  void *ts_keys = 0;
  if (ACE_OS::thr_getspecific (in_use_, &ts_keys) == -1)
    {
      ACE_ASSERT (false);
      return 0; // This should not happen!
    }

  if (ts_keys == 0)
    {
      ACE_NEW_RETURN (ts_keys,
                      ACE_TSS_Keys,
                      0);
      // Store the dynamically allocated pointer in thread-specific
      // storage.
      if (ACE_OS::thr_setspecific (in_use_, ts_keys) == -1)
        {
          ACE_ASSERT (false);
          delete reinterpret_cast <ACE_TSS_Keys*> (ts_keys);
          return 0; // Major problems, this should *never* happen!
        }
    }

  return reinterpret_cast <ACE_TSS_Keys*>(ts_keys);
}

#endif /* ACE_WIN32 || ACE_HAS_TSS_EMULATION */

/*****************************************************************************/

// = Static initialization.

// This is necessary to deal with POSIX pthreads insanity.  This
// guarantees that we've got a "zero'd" thread id even when
// ACE_thread_t, ACE_hthread_t, and ACE_thread_key_t are implemented
// as structures...  Under no circumstances should these be given
// initial values.
// Note: these three objects require static construction.
ACE_thread_t ACE_OS::NULL_thread;
ACE_hthread_t ACE_OS::NULL_hthread;
#if defined (ACE_HAS_TSS_EMULATION)
  ACE_thread_key_t ACE_OS::NULL_key = static_cast <ACE_thread_key_t> (-1);
#else  /* ! ACE_HAS_TSS_EMULATION */
  ACE_thread_key_t ACE_OS::NULL_key;
#endif /* ! ACE_HAS_TSS_EMULATION */

/*****************************************************************************/

void
ACE_OS::cleanup_tss (const u_int main_thread)
{
#if defined (ACE_HAS_TSS_EMULATION) || defined (ACE_WIN32)
  { // scope the cleanup instance
    // Call TSS destructors for current thread.
    TSS_Cleanup_Instance cleanup;
    if (cleanup.valid ())
      {
        cleanup->thread_exit ();
      }
  }
#endif /* ACE_HAS_TSS_EMULATION || ACE_WIN32 */

  if (main_thread)
    {
#if !defined (ACE_HAS_TSS_EMULATION)  &&  !defined (ACE_HAS_MINIMAL_ACE_OS)
      // Just close the ACE_Log_Msg for the current (which should be
      // main) thread.  We don't have TSS emulation; if there's native
      // TSS, it should call its destructors when the main thread
      // exits.
      ACE_Base_Thread_Adapter::close_log_msg ();
#endif /* ! ACE_HAS_TSS_EMULATION  &&  ! ACE_HAS_MINIMAL_ACE_OS */

#if defined (ACE_WIN32) || defined (ACE_HAS_TSS_EMULATION)
      // Finally, free up the ACE_TSS_Cleanup instance.  This method gets
      // called by the ACE_Object_Manager.
      TSS_Cleanup_Instance cleanup(TSS_Cleanup_Instance::DESTROY);
      if (cleanup.valid ())
      {
        ; // the pointer deletes the Cleanup when it goes out of scope
      }

#endif /* WIN32 || ACE_HAS_TSS_EMULATION */

#if defined (ACE_HAS_TSS_EMULATION)
      ACE_TSS_Emulation::tss_close ();
#endif /* ACE_HAS_TSS_EMULATION */
    }
}

/*****************************************************************************/
// CONDITIONS BEGIN
/*****************************************************************************/

#if defined (ACE_LACKS_COND_T)
int
ACE_OS::cond_broadcast (ACE_cond_t *cv)
{
  ACE_OS_TRACE ("ACE_OS::cond_broadcast");
# if defined (ACE_HAS_THREADS)
  // The <external_mutex> must be locked before this call is made.

  // This is needed to ensure that <waiters_> and <was_broadcast_> are
  // consistent relative to each other.
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    {
      return -1;
    }

  bool have_waiters = false;

  if (cv->waiters_ > 0)
    {
      // We are broadcasting, even if there is just one waiter...
      // Record the fact that we are broadcasting.  This helps the
      // cond_wait() method know how to optimize itself.  Be sure to
      // set this with the <waiters_lock_> held.
      cv->was_broadcast_ = 1;
      have_waiters = true;
    }

  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    {
      // This is really bad, we have the lock but can't release it anymore
      return -1;
    }

  int result = 0;
  if (have_waiters)
    {
      // Wake up all the waiters.
      if (ACE_OS::sema_post (&cv->sema_, cv->waiters_) == -1)
        result = -1;
      // Wait for all the awakened threads to acquire their part of
      // the counting semaphore.
#   if defined (ACE_VXWORKS)
      else if (ACE_OS::sema_wait (&cv->waiters_done_) == -1)
#   else
      else if (ACE_OS::event_wait (&cv->waiters_done_) == -1)
#   endif /* ACE_VXWORKS */
        result = -1;
      // This is okay, even without the <waiters_lock_> held because
      // no other waiter threads can wake up to access it.
      cv->was_broadcast_ = 0;
    }
  return result;
# else
  ACE_UNUSED_ARG (cv);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}

int
ACE_OS::cond_destroy (ACE_cond_t *cv)
{
  ACE_OS_TRACE ("ACE_OS::cond_destroy");
# if defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_WTHREADS)
  ACE_OS::event_destroy (&cv->waiters_done_);
#   elif defined (ACE_VXWORKS)
  ACE_OS::sema_destroy (&cv->waiters_done_);
#   endif /* ACE_VXWORKS */
  int result = 0;
  if (ACE_OS::thread_mutex_destroy (&cv->waiters_lock_) != 0)
    result = -1;

  if (ACE_OS::sema_destroy (&cv->sema_) != 0)
    result = -1;

  return result;
# else
  ACE_UNUSED_ARG (cv);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}

int
ACE_OS::cond_init (ACE_cond_t *cv,
                   ACE_condattr_t &attributes,
                   const char *name, void *arg)
{
  return
    ACE_OS::cond_init (cv, static_cast<short> (attributes.type), name, arg);
}

# if defined (ACE_HAS_WCHAR)
int
ACE_OS::cond_init (ACE_cond_t *cv,
                   ACE_condattr_t &attributes,
                   const wchar_t *name, void *arg)
{
  return
    ACE_OS::cond_init (cv, static_cast<short> (attributes.type), name, arg);
}
# endif /* ACE_HAS_WCHAR */

int
ACE_OS::cond_init (ACE_cond_t *cv, short type, const char *name, void *arg)
{
  ACE_OS_TRACE ("ACE_OS::cond_init");
# if defined (ACE_HAS_THREADS)
  cv->waiters_ = 0;
  cv->was_broadcast_ = 0;

  int result = 0;
  if (ACE_OS::sema_init (&cv->sema_, 0, type, name, arg) == -1)
    result = -1;
  else if (ACE_OS::thread_mutex_init (&cv->waiters_lock_) == -1)
    result = -1;
#   if defined (ACE_VXWORKS)
  else if (ACE_OS::sema_init (&cv->waiters_done_, 0, type) == -1)
#   else
  else if (ACE_OS::event_init (&cv->waiters_done_) == -1)
#   endif /* ACE_VXWORKS */
    result = -1;
  return result;
# else
  ACE_UNUSED_ARG (cv);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}

# if defined (ACE_HAS_WCHAR)
int
ACE_OS::cond_init (ACE_cond_t *cv, short type, const wchar_t *name, void *arg)
{
  ACE_OS_TRACE ("ACE_OS::cond_init");
#   if defined (ACE_HAS_THREADS)
  cv->waiters_ = 0;
  cv->was_broadcast_ = 0;

  int result = 0;
  if (ACE_OS::sema_init (&cv->sema_, 0, type, name, arg) == -1)
    result = -1;
  else if (ACE_OS::thread_mutex_init (&cv->waiters_lock_) == -1)
    result = -1;
#     if defined (ACE_VXWORKS)
  else if (ACE_OS::sema_init (&cv->waiters_done_, 0, type) == -1)
#     else
  else if (ACE_OS::event_init (&cv->waiters_done_) == -1)
#     endif /* ACE_VXWORKS */
    result = -1;
  return result;
#   else
  ACE_UNUSED_ARG (cv);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_THREADS */
}
# endif /* ACE_HAS_WCHAR */

int
ACE_OS::cond_signal (ACE_cond_t *cv)
{
  ACE_OS_TRACE ("ACE_OS::cond_signal");
# if defined (ACE_HAS_THREADS)
  // If there aren't any waiters, then this is a no-op.  Note that
  // this function *must* be called with the <external_mutex> held
  // since other wise there is a race condition that can lead to the
  // lost wakeup bug...  This is needed to ensure that the <waiters_>
  // value is not in an inconsistent internal state while being
  // updated by another thread.
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    return -1;
  bool const have_waiters = cv->waiters_ > 0;
  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    return -1;

  if (have_waiters)
    return ACE_OS::sema_post (&cv->sema_);
  else
    return 0; // No-op
# else
  ACE_UNUSED_ARG (cv);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}

int
ACE_OS::cond_wait (ACE_cond_t *cv,
                   ACE_mutex_t *external_mutex)
{
  ACE_OS_TRACE ("ACE_OS::cond_wait");
# if defined (ACE_HAS_THREADS)
  // Prevent race conditions on the <waiters_> count.
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    return -1;

  ++cv->waiters_;

  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    return -1;

  int result = 0;

#   if defined (ACE_HAS_SIGNAL_OBJECT_AND_WAIT)
  if (external_mutex->type_ == USYNC_PROCESS)
    {
      // This call will automatically release the mutex and wait on the semaphore.
      ACE_WIN32CALL (ACE_ADAPT_RETVAL (::SignalObjectAndWait (external_mutex->proc_mutex_,
                                                              cv->sema_, INFINITE, FALSE),
                                      result),
                    int, -1, result);
      if (result == -1)
        return result;
    }
  else
#   endif /* ACE_HAS_SIGNAL_OBJECT_AND_WAIT */
    {
      // We keep the lock held just long enough to increment the count of
      // waiters by one.  Note that we can't keep it held across the call
      // to ACE_OS::sema_wait() since that will deadlock other calls to
      // ACE_OS::cond_signal().
      if (ACE_OS::mutex_unlock (external_mutex) != 0)
        return -1;

      // Wait to be awakened by a ACE_OS::cond_signal() or
      // ACE_OS::cond_broadcast().
      result = ACE_OS::sema_wait (&cv->sema_);
    }

  // Reacquire lock to avoid race conditions on the <waiters_> count.
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    return -1;

  // We're ready to return, so there's one less waiter.
  --cv->waiters_;

  bool const last_waiter = cv->was_broadcast_ && cv->waiters_ == 0;

  // Release the lock so that other collaborating threads can make
  // progress.
  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    return -1;

  if (result == -1)
    // Bad things happened, so let's just return below.
    /* NOOP */;
#   if defined (ACE_HAS_SIGNAL_OBJECT_AND_WAIT)
  else if (external_mutex->type_ == USYNC_PROCESS)
    {
      if (last_waiter)

        // This call atomically signals the <waiters_done_> event and
        // waits until it can acquire the mutex.  This is important to
        // prevent unfairness.
        ACE_WIN32CALL (ACE_ADAPT_RETVAL (::SignalObjectAndWait (cv->waiters_done_,
                                                                external_mutex->proc_mutex_,
                                                                INFINITE, FALSE),
                                         result),
                       int, -1, result);
      else
        // We must always regain the <external_mutex>, even when
        // errors occur because that's the guarantee that we give to
        // our callers.
        if (ACE_OS::mutex_lock (external_mutex) != 0)
          return -1;

      return result;
      /* NOTREACHED */
    }
#   endif /* ACE_HAS_SIGNAL_OBJECT_AND_WAIT */
  // If we're the last waiter thread during this particular broadcast
  // then let all the other threads proceed.
  else if (last_waiter)
#   if defined (ACE_VXWORKS)
    ACE_OS::sema_post (&cv->waiters_done_);
#   else
    ACE_OS::event_signal (&cv->waiters_done_);
#   endif /* ACE_VXWORKS */

  // We must always regain the <external_mutex>, even when errors
  // occur because that's the guarantee that we give to our callers.
  ACE_OS::mutex_lock (external_mutex);

  return result;
# else
  ACE_UNUSED_ARG (cv);
  ACE_UNUSED_ARG (external_mutex);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}

int
ACE_OS::cond_timedwait (ACE_cond_t *cv,
                        ACE_mutex_t *external_mutex,
                        ACE_Time_Value *timeout)
{
  ACE_OS_TRACE ("ACE_OS::cond_timedwait");
# if defined (ACE_HAS_THREADS)
  // Handle the easy case first.
  if (timeout == 0)
    return ACE_OS::cond_wait (cv, external_mutex);
#   if defined (ACE_HAS_WTHREADS) || defined (ACE_VXWORKS)

  // Prevent race conditions on the <waiters_> count.
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    return -1;

  ++cv->waiters_;

  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    return -1;

  int result = 0;
  ACE_Errno_Guard error (errno, 0);
  int msec_timeout = 0;

  if (timeout != 0 && *timeout != ACE_Time_Value::zero)
    {
      // Note that we must convert between absolute time (which is
      // passed as a parameter) and relative time (which is what
      // WaitForSingleObjects() expects).
      ACE_Time_Value relative_time = timeout->to_relative_time ();

      // Watchout for situations where a context switch has caused the
      // current time to be > the timeout.
      if (relative_time > ACE_Time_Value::zero)
        msec_timeout = relative_time.msec ();
    }

#     if defined (ACE_HAS_SIGNAL_OBJECT_AND_WAIT)
  if (external_mutex->type_ == USYNC_PROCESS)
    // This call will automatically release the mutex and wait on the
    // semaphore.
    result = ::SignalObjectAndWait (external_mutex->proc_mutex_,
                                    cv->sema_,
                                    msec_timeout,
                                    FALSE);
  else
#     endif /* ACE_HAS_SIGNAL_OBJECT_AND_WAIT */
    {
      // We keep the lock held just long enough to increment the count
      // of waiters by one.  Note that we can't keep it held across
      // the call to WaitForSingleObject since that will deadlock
      // other calls to ACE_OS::cond_signal().
      if (ACE_OS::mutex_unlock (external_mutex) != 0)
        return -1;

      // Wait to be awakened by a ACE_OS::signal() or
      // ACE_OS::broadcast().
#     if defined (ACE_WIN32)
#       if !defined (ACE_USES_WINCE_SEMA_SIMULATION)
      result = ::WaitForSingleObject (cv->sema_, msec_timeout);
#       else /* ACE_USES_WINCE_SEMA_SIMULATION */
      // Can't use Win32 API on our simulated semaphores.
      result = ACE_OS::sema_wait (&cv->sema_,
                                  timeout);
#       endif /* ACE_USES_WINCE_SEMA_SIMULATION */
#     elif defined (ACE_VXWORKS)
      // Inline the call to ACE_OS::sema_wait () because it takes an
      // ACE_Time_Value argument.  Avoid the cost of that conversion . . .
      int const ticks_per_sec = ::sysClkRateGet ();
      int const ticks = msec_timeout * ticks_per_sec / ACE_ONE_SECOND_IN_MSECS;
      result = ::semTake (cv->sema_.sema_, ticks);
#     endif /* ACE_WIN32 || VXWORKS */
    }

  // Reacquire lock to avoid race conditions.
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    return -1;

  --cv->waiters_;

  bool const last_waiter = cv->was_broadcast_ && cv->waiters_ == 0;

  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    return -1;

#     if defined (ACE_WIN32)
  if (result != WAIT_OBJECT_0)
    {
      switch (result)
        {
        case WAIT_TIMEOUT:
          error = ETIME;
          break;
        default:
          error = ::GetLastError ();
          break;
        }
      result = -1;
    }
#     elif defined (ACE_VXWORKS)
  if (result == ERROR)
    {
      switch (errno)
        {
        case S_objLib_OBJ_TIMEOUT:
          error = ETIME;
          break;
        case S_objLib_OBJ_UNAVAILABLE:
          if (msec_timeout == 0)
            error = ETIME;
          break;
        default:
          error = errno;
          break;
        }
      result = -1;
    }
#     endif /* ACE_WIN32 || VXWORKS */
#     if defined (ACE_HAS_SIGNAL_OBJECT_AND_WAIT)
  if (external_mutex->type_ == USYNC_PROCESS)
    {
      if (last_waiter)
        // This call atomically signals the <waiters_done_> event and
        // waits until it can acquire the mutex.  This is important to
        // prevent unfairness.
        ACE_WIN32CALL (ACE_ADAPT_RETVAL (::SignalObjectAndWait (cv->waiters_done_,
                                                                external_mutex->proc_mutex_,
                                                                INFINITE, FALSE),
                                         result),
                       int, -1, result);
      else
        {
          // We must always regain the <external_Mutex>, even when
          // errors occur because that's the guarantee that we give to
          // our callers.
          if (ACE_OS::mutex_lock (external_mutex) != 0)
            return -1;
        }

      return result;
      /* NOTREACHED */
    }
#     endif /* ACE_HAS_SIGNAL_OBJECT_AND_WAIT */
  // Note that this *must* be an "if" statement rather than an "else
  // if" statement since the caller may have timed out and hence the
  // result would have been -1 above.
  if (last_waiter)
    {
      // Release the signaler/broadcaster if we're the last waiter.
#     if defined (ACE_WIN32)
      if (ACE_OS::event_signal (&cv->waiters_done_) != 0)
#     else
      if (ACE_OS::sema_post (&cv->waiters_done_) != 0)
#     endif /* ACE_WIN32 */
        return -1;
    }

  // We must always regain the <external_mutex>, even when errors
  // occur because that's the guarantee that we give to our callers.
  if (ACE_OS::mutex_lock (external_mutex) != 0)
    return -1;

  return result;
#   endif /* ACE_HAS_WTHREADS || ACE_HAS_VXWORKS */
# else
  ACE_UNUSED_ARG (cv);
  ACE_UNUSED_ARG (external_mutex);
  ACE_UNUSED_ARG (timeout);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}
#else
int
ACE_OS::cond_init (ACE_cond_t *cv, short type, const char *name, void *arg)
{
  ACE_condattr_t attributes;
  if (ACE_OS::condattr_init (attributes, type) == 0
      && ACE_OS::cond_init (cv, attributes, name, arg) == 0)
    {
      (void) ACE_OS::condattr_destroy (attributes);
      return 0;
    }
  return -1;
}
#endif /* ACE_LACKS_COND_T */

#if defined (ACE_WIN32) && defined (ACE_HAS_WTHREADS)
int
ACE_OS::cond_timedwait (ACE_cond_t *cv,
                        ACE_thread_mutex_t *external_mutex,
                        ACE_Time_Value *timeout)
{
  ACE_OS_TRACE ("ACE_OS::cond_timedwait");
#   if defined (ACE_HAS_THREADS)
  // Handle the easy case first.
  if (timeout == 0)
    return ACE_OS::cond_wait (cv, external_mutex);

#   if defined (ACE_HAS_WTHREADS_CONDITION_VARIABLE)
  int msec_timeout = 0;
  int result = 0;

  ACE_Time_Value relative_time = timeout->to_relative_time ();
  // Watchout for situations where a context switch has caused the
  // current time to be > the timeout.
  if (relative_time > ACE_Time_Value::zero)
     msec_timeout = relative_time.msec ();

  ACE_OSCALL (ACE_ADAPT_RETVAL (::SleepConditionVariableCS (cv, external_mutex, msec_timeout),
                                result),
              int, -1, result);
  return result;
#else
  // Prevent race conditions on the <waiters_> count.
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    return -1;

  ++cv->waiters_;

  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    return -1;

  int result = 0;
  int error = 0;
  int msec_timeout = 0;

  if (timeout != 0 && *timeout != ACE_Time_Value::zero)
    {
      // Note that we must convert between absolute time (which is
      // passed as a parameter) and relative time (which is what
      // WaitForSingleObjects() expects).
      ACE_Time_Value relative_time = timeout->to_relative_time ();

      // Watchout for situations where a context switch has caused the
      // current time to be > the timeout.
      if (relative_time > ACE_Time_Value::zero)
        msec_timeout = relative_time.msec ();
    }

  // We keep the lock held just long enough to increment the count of
  // waiters by one.  Note that we can't keep it held across the call
  // to WaitForSingleObject since that will deadlock other calls to
  // ACE_OS::cond_signal().
  if (ACE_OS::thread_mutex_unlock (external_mutex) != 0)
    return -1;

  // Wait to be awakened by a ACE_OS::signal() or ACE_OS::broadcast().
#     if defined (ACE_USES_WINCE_SEMA_SIMULATION)
  // Can't use Win32 API on simulated semaphores.
  result = ACE_OS::sema_wait (&cv->sema_,
                              timeout);

  if (result == -1 && errno == ETIME)
    result = WAIT_TIMEOUT;
#     else
  result = ::WaitForSingleObject (cv->sema_, msec_timeout);
#     endif /* ACE_USES_WINCE_SEMA_SIMULATION */

  // Reacquire lock to avoid race conditions.
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    return -1;

  --cv->waiters_;

  bool const last_waiter = cv->was_broadcast_ && cv->waiters_ == 0;

  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    return -1;

  if (result != WAIT_OBJECT_0)
    {
      switch (result)
        {
        case WAIT_TIMEOUT:
          error = ETIME;
          break;
        default:
          error = ::GetLastError ();
          break;
        }
      result = -1;
    }

  if (last_waiter)
    {
      // Release the signaler/broadcaster if we're the last waiter.
      if (ACE_OS::event_signal (&cv->waiters_done_) != 0)
        return -1;
    }

  // We must always regain the <external_mutex>, even when errors
  // occur because that's the guarantee that we give to our callers.
  if (ACE_OS::thread_mutex_lock (external_mutex) != 0)
    result = -1;

  if (error != 0)
    {
      /* This assignment must only be done if error != 0,
       *   since writing 0 to errno violates the POSIX specification.
       */
      errno = error;
    }
  return result;
#   endif
#   else
  ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_THREADS */
}

int
ACE_OS::cond_wait (ACE_cond_t *cv,
                   ACE_thread_mutex_t *external_mutex)
{
  ACE_OS_TRACE ("ACE_OS::cond_wait");
#   if defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_WTHREADS_CONDITION_VARIABLE)
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::SleepConditionVariableCS (cv, external_mutex, INFINITE), result),
                     int, -1);
#else
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    return -1;
  ++cv->waiters_;

  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    return -1;

  int result = 0;
  int error = 0;

  // We keep the lock held just long enough to increment the count of
  // waiters by one.  Note that we can't keep it held across the call
  // to ACE_OS::sema_wait() since that will deadlock other calls to
  // ACE_OS::cond_signal().
  if (ACE_OS::thread_mutex_unlock (external_mutex) != 0)
    return -1;

  // Wait to be awakened by a ACE_OS::cond_signal() or
  // ACE_OS::cond_broadcast().
#     if !defined (ACE_USES_WINCE_SEMA_SIMULATION)
  result = ::WaitForSingleObject (cv->sema_, INFINITE);
#     else
  // Can't use Win32 API on simulated semaphores.
  result = ACE_OS::sema_wait (&cv->sema_);

  if (result != WAIT_OBJECT_0 && errno == ETIME)
    result = WAIT_TIMEOUT;

#     endif /* ACE_USES_WINCE_SEMA_SIMULATION */

  // Reacquire lock to avoid race conditions.
  if (ACE_OS::thread_mutex_lock (&cv->waiters_lock_) != 0)
    return -1;

  cv->waiters_--;

  bool const last_waiter = cv->was_broadcast_ && cv->waiters_ == 0;

  if (ACE_OS::thread_mutex_unlock (&cv->waiters_lock_) != 0)
    return -1;

  if (result != WAIT_OBJECT_0)
    {
      switch (result)
        {
        case WAIT_TIMEOUT:
          error = ETIME;
          break;
        default:
          error = ::GetLastError ();
          break;
        }
    }
  else if (last_waiter)
    {
      // Release the signaler/broadcaster if we're the last waiter.
      if (ACE_OS::event_signal (&cv->waiters_done_) != 0)
        return -1;
    }

  // We must always regain the <external_mutex>, even when errors
  // occur because that's the guarantee that we give to our callers.
  if (ACE_OS::thread_mutex_lock (external_mutex) != 0)
    result = -1;

  // Reset errno in case mutex_lock() also fails...
  if (error != 0)
  {
    /* This assignment must only be done if error != 0,
    *   since writing 0 to errno violates the POSIX specification.
    */
    errno = error;
  }
  return result;
#endif
#   else
  ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_THREADS */
}
# endif /* ACE_HAS_WTHREADS */

/*****************************************************************************/
// CONDITIONS END
/*****************************************************************************/

/*****************************************************************************/
// MUTEXES BEGIN
/*****************************************************************************/

int
ACE_OS::mutex_init (ACE_mutex_t *m,
                    int lock_scope,
                    const char *name,
                    ACE_mutexattr_t *attributes,
                    LPSECURITY_ATTRIBUTES sa,
                    int lock_type)
{
  // ACE_OS_TRACE ("ACE_OS::mutex_init");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (sa);

# if defined (ACE_PTHREAD_MUTEXATTR_T_INITIALIZE)
  /* Tests show that VxWorks 6.x pthread lib does not only
   * require zeroing of mutex/condition objects to function correctly
   * but also of the attribute objects.
   */
  pthread_mutexattr_t l_attributes = {0};
# else
  pthread_mutexattr_t l_attributes;
# endif

  if (attributes == 0)
    attributes = &l_attributes;
  int result = 0;
  int attr_init = 0;  // have we initialized the local attributes.

  // Only do these initializations if the <attributes> parameter
  // wasn't originally set.
  if (attributes == &l_attributes)
  {
      if (ACE_ADAPT_RETVAL (::pthread_mutexattr_init (attributes), result) == 0)
        {
          result = 0;
          attr_init = 1; // we have initialized these attributes
        }
      else
        {
          result = -1;        // ACE_ADAPT_RETVAL used it for intermediate status
        }
  }

  if (result == 0 && lock_scope != 0)
{
#     if defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_MUTEXATTR_PSHARED)
      (void) ACE_ADAPT_RETVAL (::pthread_mutexattr_setpshared (attributes,
                                                               lock_scope),
                               result);
#     endif /* _POSIX_THREAD_PROCESS_SHARED && !ACE_LACKS_MUTEXATTR_PSHARED */
}

  if (result == 0 && lock_type != 0)
{
#   if defined (ACE_HAS_RECURSIVE_MUTEXES)
      (void) ACE_ADAPT_RETVAL (::pthread_mutexattr_settype (attributes,
                                                            lock_type),
                               result);
#   endif /* ACE_HAS_RECURSIVE_MUTEXES */
}

  if (result == 0)
{
#   if defined (ACE_PTHREAD_MUTEX_T_INITIALIZE)
      /* VxWorks 6.x API reference states:
       * If the memory for the mutex variable object has been allocated
       *   dynamically, it is a good policy to always zero out the
       *   block of memory so as to avoid spurious EBUSY return code
       *   when calling this routine.
       * Tests shows this to be necessary.
       */
      ACE_OS::memset (m, 0, sizeof (*m));
#   endif
      if (ACE_ADAPT_RETVAL (::pthread_mutex_init (m, attributes), result) == 0)
        result = 0;
      else
        result = -1;        // ACE_ADAPT_RETVAL used it for intermediate status
}

  // Only do the deletions if the <attributes> parameter wasn't
  // originally set.
  if (attributes == &l_attributes && attr_init)
    ::pthread_mutexattr_destroy (&l_attributes);

  return result;
# elif defined (ACE_HAS_STHREADS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (sa);
  ACE_UNUSED_ARG (lock_type);
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_init (m,
                     lock_scope,
                     attributes),
  result),
  int, -1);
# elif defined (ACE_HAS_WTHREADS)
  m->type_ = lock_scope;

  SECURITY_ATTRIBUTES sa_buffer;
  SECURITY_DESCRIPTOR sd_buffer;
  switch (lock_scope)
{
  case USYNC_PROCESS:
#   if defined (ACE_HAS_WINCE)
      // @@todo (brunsch) This idea should be moved into ACE_OS_Win32.
      m->proc_mutex_ =
  ::CreateMutexW (ACE_OS::default_win32_security_attributes_r
                          (sa, &sa_buffer, &sd_buffer),
                        FALSE,
                        ACE_Ascii_To_Wide (name).wchar_rep ());
#   else /* ACE_HAS_WINCE */
      m->proc_mutex_ =
  ::CreateMutexA (ACE_OS::default_win32_security_attributes_r
                          (sa, &sa_buffer, &sd_buffer),
                        FALSE,
                        name);
#   endif /* ACE_HAS_WINCE */
      if (m->proc_mutex_ == 0)
        ACE_FAIL_RETURN (-1);
      else
      {
        // Make sure to set errno to ERROR_ALREADY_EXISTS if necessary.
        ACE_OS::set_errno_to_last_error ();
        return 0;
      }
  case USYNC_THREAD:
    return ACE_OS::thread_mutex_init (&m->thr_mutex_,
                                       lock_type,
                                       name,
                                       attributes);
  default:
    errno = EINVAL;
    return -1;
}
  /* NOTREACHED */

# elif defined (ACE_VXWORKS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (sa);
  ACE_UNUSED_ARG (lock_type);

  return (*m = ::semMCreate (lock_scope)) == 0 ? -1 : 0;
# endif /* ACE_HAS_PTHREADS */
#else
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (lock_scope);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (sa);
  ACE_UNUSED_ARG (lock_type);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

int
ACE_OS::mutex_destroy (ACE_mutex_t *m)
{
  ACE_OS_TRACE ("ACE_OS::mutex_destroy");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_mutex_destroy (m),
                     result), int, -1);
# elif defined (ACE_HAS_STHREADS)
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_destroy (m), result), int, -1);
# elif defined (ACE_HAS_WTHREADS)
  switch (m->type_)
{
  case USYNC_PROCESS:
    ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::CloseHandle (m->proc_mutex_),
                          ace_result_),
    int, -1);
  case USYNC_THREAD:
    return ACE_OS::thread_mutex_destroy (&m->thr_mutex_);
  default:
    errno = EINVAL;
    return -1;
}
  /* NOTREACHED */
# elif defined (ACE_VXWORKS)
  return ::semDelete (*m) == OK ? 0 : -1;
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

#if defined (ACE_HAS_WCHAR)
int
ACE_OS::mutex_init (ACE_mutex_t *m,
                    int lock_scope,
                    const wchar_t *name,
                    ACE_mutexattr_t *attributes,
                    LPSECURITY_ATTRIBUTES sa,
                    int lock_type)
{
#if defined (ACE_HAS_THREADS) && defined (ACE_HAS_WTHREADS)
  m->type_ = lock_scope;
  SECURITY_ATTRIBUTES sa_buffer;
  SECURITY_DESCRIPTOR sd_buffer;
  switch (lock_scope)
  {
    case USYNC_PROCESS:
      m->proc_mutex_ =
      ::CreateMutexW (ACE_OS::default_win32_security_attributes_r
          (sa, &sa_buffer, &sd_buffer),
      FALSE,
      name);
      if (m->proc_mutex_ == 0)
        ACE_FAIL_RETURN (-1);
      else
        {
          // Make sure to set errno to ERROR_ALREADY_EXISTS if necessary.
          ACE_OS::set_errno_to_last_error ();
          return 0;
        }
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_init (&m->thr_mutex_,
                                         lock_type,
                                         name,
                                         attributes);
  }

  errno = EINVAL;
  return -1;
#else /* ACE_HAS_THREADS && ACE_HAS_WTHREADS */
  return ACE_OS::mutex_init (m,
                             lock_scope,
                             ACE_Wide_To_Ascii (name).char_rep (),
                             attributes,
                             sa,
                             lock_type);
#endif /* ACE_HAS_THREADS && ACE_HAS_WTHREADS */
}
#endif /* ACE_HAS_WCHAR */

int
ACE_OS::mutex_lock (ACE_mutex_t *m)
{
  // ACE_OS_TRACE ("ACE_OS::mutex_lock");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  // Note, don't use "::" here since the following call is often a macro.
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_mutex_lock (m), result),
                     int, -1);
# elif defined (ACE_HAS_STHREADS)
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_lock (m), result), int, -1);
# elif defined (ACE_HAS_WTHREADS)
  switch (m->type_)
{
  case USYNC_PROCESS:
    switch (::WaitForSingleObject (m->proc_mutex_, INFINITE))
      {
        //
        // Timeout can't occur, so don't bother checking...
        //
      case WAIT_OBJECT_0:
      case WAIT_ABANDONED:
        // We will ignore abandonments in this method
        // Note that we still hold the lock
        return 0;
      default:
        // This is a hack, we need to find an appropriate mapping...
        ACE_OS::set_errno_to_last_error ();
        return -1;
      }
  case USYNC_THREAD:
    return ACE_OS::thread_mutex_lock (&m->thr_mutex_);
  default:
    errno = EINVAL;
    return -1;
}
  /* NOTREACHED */
# elif defined (ACE_VXWORKS)
  return ::semTake (*m, WAIT_FOREVER) == OK ? 0 : -1;
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

int
ACE_OS::mutex_lock (ACE_mutex_t *m,
                    int &abandoned)
{
  ACE_OS_TRACE ("ACE_OS::mutex_lock");
#if defined (ACE_HAS_THREADS) && defined (ACE_HAS_WTHREADS)
  abandoned = 0;
  switch (m->type_)
  {
    case USYNC_PROCESS:
      switch (::WaitForSingleObject (m->proc_mutex_, INFINITE))
      {
        //
          // Timeout can't occur, so don't bother checking...
        //
        case WAIT_OBJECT_0:
          return 0;
        case WAIT_ABANDONED:
          abandoned = 1;
          return 0;  // something goofed, but we hold the lock ...
        default:
          // This is a hack, we need to find an appropriate mapping...
          ACE_OS::set_errno_to_last_error ();
          return -1;
      }
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_lock (&m->thr_mutex_);
    default:
      errno = EINVAL;
      return -1;
  }
  /* NOTREACHED */
#else
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (abandoned);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS and ACE_HAS_WTHREADS */
}

int
ACE_OS::mutex_lock (ACE_mutex_t *m,
                    const ACE_Time_Value &timeout)
{
#if defined (ACE_HAS_THREADS) && defined (ACE_HAS_MUTEX_TIMEOUTS)

#  if defined (ACE_HAS_PTHREADS)
  int result;

  // "timeout" should be an absolute time.

  timespec_t ts = timeout;  // Calls ACE_Time_Value::operator timespec_t().

  // Note that the mutex should not be a recursive one, i.e., it
  // should only be a standard mutex or an error checking mutex.

  ACE_OSCALL (ACE_ADAPT_RETVAL (::pthread_mutex_timedlock (m, &ts), result), int, -1, result);

  // We need to adjust this to make the errno values consistent.
  if (result == -1 && errno == ETIMEDOUT)
    errno = ETIME;
  return result;

#  elif defined (ACE_HAS_WTHREADS)
  // Note that we must convert between absolute time (which is passed
  // as a parameter) and relative time (which is what the system call
  // expects).
  ACE_Time_Value relative_time = timeout.to_relative_time ();

  switch (m->type_)
  {
    case USYNC_PROCESS:
      switch (::WaitForSingleObject (m->proc_mutex_,
                relative_time.msec ()))
      {
        case WAIT_OBJECT_0:
        case WAIT_ABANDONED:
          // We will ignore abandonments in this method
          // Note that we still hold the lock
          return 0;
        case WAIT_TIMEOUT:
          errno = ETIME;
          return -1;
        default:
          // This is a hack, we need to find an appropriate mapping...
          ACE_OS::set_errno_to_last_error ();
          return -1;
      }
    case USYNC_THREAD:
      ACE_NOTSUP_RETURN (-1);
    default:
      errno = EINVAL;
      return -1;
  }
  /* NOTREACHED */

#  elif defined (ACE_VXWORKS)

  // Note that we must convert between absolute time (which is passed
  // as a parameter) and relative time (which is what the system call
  // expects).
  ACE_Time_Value relative_time = timeout.to_relative_time ();

  int ticks_per_sec = ::sysClkRateGet ();

  int ticks = relative_time.sec() * ticks_per_sec +
      relative_time.usec () * ticks_per_sec / ACE_ONE_SECOND_IN_USECS;
  if (::semTake (*m, ticks) == ERROR)
  {
    if (errno == S_objLib_OBJ_TIMEOUT)
        // Convert the VxWorks errno to one that's common for to ACE
        // platforms.
      errno = ETIME;
    else if (errno == S_objLib_OBJ_UNAVAILABLE)
      errno = EBUSY;
    return -1;
  }
  else
    return 0;
#  endif /* ACE_HAS_PTHREADS */

#else
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (timeout);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS && ACE_HAS_MUTEX_TIMEOUTS */
}

int
ACE_OS::mutex_trylock (ACE_mutex_t *m)
{
  ACE_OS_TRACE ("ACE_OS::mutex_trylock");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  // Note, don't use "::" here since the following call is often a macro.
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_mutex_trylock (m), result),
                     int, -1);
# elif defined (ACE_HAS_STHREADS)
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_trylock (m), result), int, -1);
# elif defined (ACE_HAS_WTHREADS)
  switch (m->type_)
{
  case USYNC_PROCESS:
  {
        // Try for 0 milliseconds - i.e. nonblocking.
    switch (::WaitForSingleObject (m->proc_mutex_, 0))
    {
      case WAIT_OBJECT_0:
        return 0;
      case WAIT_ABANDONED:
            // We will ignore abandonments in this method.  Note that
            // we still hold the lock.
        return 0;
      case WAIT_TIMEOUT:
        errno = EBUSY;
        return -1;
      default:
        ACE_OS::set_errno_to_last_error ();
        return -1;
    }
  }
  case USYNC_THREAD:
    return ACE_OS::thread_mutex_trylock (&m->thr_mutex_);
  default:
    errno = EINVAL;
    return -1;
}
  /* NOTREACHED */
# elif defined (ACE_VXWORKS)
  if (::semTake (*m, NO_WAIT) == ERROR)
    if (errno == S_objLib_OBJ_UNAVAILABLE)
{
        // couldn't get the semaphore
  errno = EBUSY;
  return -1;
}
    else
      // error
      return -1;
    else
    // got the semaphore
      return 0;
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

int
ACE_OS::mutex_trylock (ACE_mutex_t *m, int &abandoned)
{
#if defined (ACE_HAS_THREADS) && defined (ACE_HAS_WTHREADS)
  abandoned = 0;
  switch (m->type_)
  {
    case USYNC_PROCESS:
    {
        // Try for 0 milliseconds - i.e. nonblocking.
      switch (::WaitForSingleObject (m->proc_mutex_, 0))
      {
        case WAIT_OBJECT_0:
          return 0;
        case WAIT_ABANDONED:
          abandoned = 1;
          return 0;  // something goofed, but we hold the lock ...
        case WAIT_TIMEOUT:
          errno = EBUSY;
          return -1;
        default:
          ACE_OS::set_errno_to_last_error ();
          return -1;
      }
    }
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_trylock (&m->thr_mutex_);
    default:
      errno = EINVAL;
      return -1;
  }
  /* NOTREACHED */
#else
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (abandoned);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS and ACE_HAS_WTHREADS */
}

int
ACE_OS::mutex_unlock (ACE_mutex_t *m)
{
  ACE_OS_TRACE ("ACE_OS::mutex_unlock");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  // Note, don't use "::" here since the following call is often a macro.
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_mutex_unlock (m), result),
                     int, -1);
# elif defined (ACE_HAS_STHREADS)
  int result;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_unlock (m), result), int, -1);
# elif defined (ACE_HAS_WTHREADS)
  switch (m->type_)
{
  case USYNC_PROCESS:
    ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::ReleaseMutex (m->proc_mutex_),
                          ace_result_),
    int, -1);
  case USYNC_THREAD:
    return ACE_OS::thread_mutex_unlock (&m->thr_mutex_);
  default:
    errno = EINVAL;
    return -1;
}
  /* NOTREACHED */
# elif defined (ACE_VXWORKS)
  return ::semGive (*m) == OK ? 0 : -1;
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

void
ACE_OS::mutex_lock_cleanup (void *mutex)
{
  ACE_OS_TRACE ("ACE_OS::mutex_lock_cleanup");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  ACE_mutex_t *p_lock = (ACE_mutex_t *) mutex;
  ACE_OS::mutex_unlock (p_lock);
# else
  ACE_UNUSED_ARG (mutex);
# endif /* ACE_HAS_PTHREADS */
#else
  ACE_UNUSED_ARG (mutex);
#endif /* ACE_HAS_THREADS */
}

/*****************************************************************************/
// MUTEXES END
/*****************************************************************************/

/*****************************************************************************/
// EVENTS BEGIN
/*****************************************************************************/

int
ACE_OS::event_destroy (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::CloseHandle (*event), ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
  if (event->eventdata_)
    {
      // mutex_destroy()/cond_destroy() are called in a loop if the object
      // is BUSY.  This avoids conditions where we fail to destroy these
      // objects because at time of destroy they were just being used in
      // another thread possibly causing deadlocks later on if they keep
      // being used after we're gone.

      if (event->eventdata_->type_ == USYNC_PROCESS)
        {
          if (event->name_)
            {
              // Only destroy the event data if we're the ones who initialized
              // it.

              int r1, r2;
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
              // First destroy the mutex so locking after this will return
              // errors.
              while ((r1 = ACE_OS::mutex_destroy (&event->eventdata_->lock_)) == -1
                     && errno == EBUSY)
                {
                  ACE_OS::thr_yield ();
                }
# else
              r1 = ACE_OS::sema_destroy(&event->lock_);
# endif

# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
              // Now fix event to manual reset, raise signal and broadcast
              // until is's possible to destroy the condition.
              event->eventdata_->manual_reset_ = 1;
              while ((r2 = ACE_OS::cond_destroy (&event->eventdata_->condition_)) == -1
                     && errno == EBUSY)
                {
                  event->eventdata_->is_signaled_ = 1;
                  if (ACE_OS::cond_broadcast (&event->eventdata_->condition_) != 0)
                    return -1;
                  ACE_OS::thr_yield ();
                }
# else
              r2 = ACE_OS::sema_destroy(&event->semaphore_);
# endif
              ACE_OS::munmap (event->eventdata_,
                              sizeof (ACE_eventdata_t));
              ACE_OS::shm_unlink (ACE_TEXT_CHAR_TO_TCHAR(event->name_));
              ACE_OS::free (event->name_);
              return r1 != 0 || r2 != 0 ? -1 : 0;
            }
          else
            {
              ACE_OS::munmap (event->eventdata_,
                              sizeof (ACE_eventdata_t));
# if (!defined (ACE_HAS_PTHREADS) || !defined (_POSIX_THREAD_PROCESS_SHARED) || \
        (defined (ACE_LACKS_MUTEXATTR_PSHARED) && defined (ACE_LACKS_CONDATTR_PSHARED))) && \
     (defined (ACE_USES_FIFO_SEM) || \
        (defined (ACE_HAS_POSIX_SEM) && defined (ACE_HAS_POSIX_SEM_TIMEOUT) && defined (ACE_LACKS_NAMED_POSIX_SEM)))
              ACE_OS::sema_destroy(&event->lock_);
# endif
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
              return 0;
# else
              return ACE_OS::sema_destroy(&event->semaphore_);
# endif
            }
        }
      else
        {
          int r1, r2;
          // First destroy the mutex so locking after this will return errors.
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
      // first destroy the mutex so locking after this will return errors
          while ((r1 = ACE_OS::mutex_destroy (&event->eventdata_->lock_)) == -1
                 && errno == EBUSY)
            {
              ACE_OS::thr_yield ();
            }
# else
          r1 = ACE_OS::sema_destroy(&event->lock_);
# endif

# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
          // Now fix event to manual reset, raise signal and broadcast until
          // it's possible to destroy the condition.
          event->eventdata_->manual_reset_ = 1;
          while ((r2 = ACE_OS::cond_destroy (&event->eventdata_->condition_)) == -1
                 && errno == EBUSY)
            {
              event->eventdata_->is_signaled_ = 1;
              if (ACE_OS::cond_broadcast (&event->eventdata_->condition_) != 0)
                return -1;
              ACE_OS::thr_yield ();
            }
# else
          r2 = ACE_OS::sema_destroy(&event->semaphore_);
# endif
          delete event->eventdata_;
          return r1 != 0 || r2 != 0 ? -1 : 0;
        }
    }

  return 0;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

int
ACE_OS::event_init (ACE_event_t *event,
                    int manual_reset,
                    int initial_state,
                    int type,
                    const char *name,
                    void *arg,
                    LPSECURITY_ATTRIBUTES sa)
{
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (arg);
  SECURITY_ATTRIBUTES sa_buffer;
  SECURITY_DESCRIPTOR sd_buffer;
# if defined (ACE_HAS_WINCE)
  // @@todo (brunsch) This idea should be moved into ACE_OS_Win32.
  *event = ::CreateEventW (ACE_OS::default_win32_security_attributes_r
                             (sa, &sa_buffer, &sd_buffer),
                           manual_reset,
                           initial_state,
                           ACE_Ascii_To_Wide (name).wchar_rep ());
# else /* ACE_HAS_WINCE */
  *event = ::CreateEventA (ACE_OS::default_win32_security_attributes_r
                             (sa, &sa_buffer, &sd_buffer),
                           manual_reset,
                           initial_state,
                           name);
# endif /* ACE_HAS_WINCE */
  if (*event == 0)
    ACE_FAIL_RETURN (-1);
  else
    {
      // Make sure to set errno to ERROR_ALREADY_EXISTS if necessary.
      ACE_OS::set_errno_to_last_error ();
      return 0;
    }
#elif defined (ACE_HAS_THREADS)
  ACE_UNUSED_ARG (sa);
  event->eventdata_ = 0;
  ACE_eventdata_t* evtdata;

  if (type == USYNC_PROCESS)
    {
      const char *name_p = 0;
#  if defined (ACE_SHM_OPEN_REQUIRES_ONE_SLASH)
      char adj_name[MAXPATHLEN];
      if (name[0] != '/')
        {
          adj_name[0] = '/';
          ACE_OS::strsncpy (&adj_name[1], name, MAXPATHLEN-1);
          name_p = adj_name;
        }
      else
        {
          name_p = name;
        }
#  else
      name_p = name;
#  endif /* ACE_SHM_OPEN_REQUIRES_ONE_SLASH */
      int owner = 0;
      // Let's see if the shared memory entity already exists.
      ACE_HANDLE fd = ACE_OS::shm_open (ACE_TEXT_CHAR_TO_TCHAR (name_p),
                                        O_RDWR | O_CREAT | O_EXCL,
                                        ACE_DEFAULT_FILE_PERMS);
      if (fd == ACE_INVALID_HANDLE)
        {
          if (errno == EEXIST)
            fd = ACE_OS::shm_open (ACE_TEXT_CHAR_TO_TCHAR (name_p),
                                   O_RDWR | O_CREAT,
                                   ACE_DEFAULT_FILE_PERMS);
          if (fd == ACE_INVALID_HANDLE)   // Still can't get it.
            return -1;
        }
      else
        {
          // We own this shared memory object!  Let's set its size.
          if (ACE_OS::ftruncate (fd, sizeof (ACE_eventdata_t)) == -1)
            {
              ACE_OS::close (fd);
              return -1;
            }
          owner = 1;
        }

      evtdata =
        (ACE_eventdata_t *) ACE_OS::mmap (0,
                                          sizeof (ACE_eventdata_t),
                                          PROT_RDWR,
                                          MAP_SHARED,
                                          fd,
                                          0);
      ACE_OS::close (fd);
      if (evtdata == MAP_FAILED)
        {
          if (owner)
            ACE_OS::shm_unlink (ACE_TEXT_CHAR_TO_TCHAR (name_p));
          return -1;
        }

      if (owner)
        {
          event->name_ = ACE_OS::strdup (name_p);
          if (event->name_ == 0)
            {
              ACE_OS::shm_unlink (ACE_TEXT_CHAR_TO_TCHAR (name_p));
              return -1;
            }
          event->eventdata_ = evtdata;
          event->eventdata_->type_ = type;
          event->eventdata_->manual_reset_ = manual_reset;
          event->eventdata_->is_signaled_ = initial_state;
          event->eventdata_->auto_event_signaled_ = false;
          event->eventdata_->waiting_threads_ = 0;
          event->eventdata_->signal_count_ = 0;

# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
          int result = ACE_OS::cond_init (&event->eventdata_->condition_,
                                          static_cast<short> (type),
                                          name,
                                          arg);
# else
          char   sem_name[128];
          ACE_OS::strncpy (sem_name,
                           name,
                           sizeof (sem_name) - (1 + sizeof ("._ACE_EVTSEM_")));
          ACE_OS::strcat (sem_name, "._ACE_EVTSEM_");
          int result = ACE_OS::sema_init (&event->semaphore_,
                                          0,
                                          type,
                                          sem_name,
                                          arg);
# endif
          if (result == 0)
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
            result = ACE_OS::mutex_init (&event->eventdata_->lock_,
                                         type,
                                         name,
                                         (ACE_mutexattr_t *) arg);
# else
          {
            char   lck_name[128];
            ACE_OS::strncpy
              (lck_name,
               name,
               sizeof (lck_name) - (1 + sizeof ("._ACE_EVTLCK_")));
            ACE_OS::strcat (lck_name, "._ACE_EVTLCK_");
            result = ACE_OS::sema_init (&event->lock_,
                                        0,
                                        type,
                                        lck_name,
                                        arg);
            if (result == 0)
              result = ACE_OS::sema_post (&event->lock_); /* Initially unlock */
          }
# endif
          return result;
        }
      else
        {
          int result = 0;

          event->name_ = 0;
          event->eventdata_ = evtdata;
#if (!defined (ACE_HAS_PTHREADS) || !defined (_POSIX_THREAD_PROCESS_SHARED) || defined (ACE_LACKS_CONDATTR_PSHARED)) && \
  (defined (ACE_USES_FIFO_SEM) || \
    (defined (ACE_HAS_POSIX_SEM) && defined (ACE_HAS_POSIX_SEM_TIMEOUT) && !defined (ACE_LACKS_NAMED_POSIX_SEM)))
          char   sem_name[128];
          ACE_OS::strncpy (sem_name,
                           name,
                           sizeof (sem_name) - (1 + sizeof ("._ACE_EVTSEM_")));
          ACE_OS::strcat (sem_name, "._ACE_EVTSEM_");
          result = ACE_OS::sema_init(&event->semaphore_,
                                     0,
                                     type,
                                     sem_name,
                                     arg);
# endif

# if (!defined (ACE_HAS_PTHREADS) || !defined (_POSIX_THREAD_PROCESS_SHARED) || \
        (defined (ACE_LACKS_MUTEXATTR_PSHARED) && defined (ACE_LACKS_CONDATTR_PSHARED))) && \
     (defined (ACE_USES_FIFO_SEM) || \
        (defined (ACE_HAS_POSIX_SEM) && defined (ACE_HAS_POSIX_SEM_TIMEOUT) && defined (ACE_LACKS_NAMED_POSIX_SEM)))
          if (result == 0)
            {
              char   lck_name[128];
              ACE_OS::strncpy
                (lck_name,
                 name,
                 sizeof (lck_name) - (1 + sizeof ("._ACE_EVTLCK_")));
              ACE_OS::strcat (lck_name, "._ACE_EVTLCK_");
              result = ACE_OS::sema_init (&event->lock_,
                                          0,
                                          type,
                                          lck_name,
                                          arg);
            }
# endif
          return result;
        }
    }
  else
    {
      ACE_NEW_RETURN (evtdata, ACE_eventdata_t, -1);
      event->name_ = 0;
      event->eventdata_ = evtdata;
      event->eventdata_->type_ = type;
      event->eventdata_->manual_reset_ = manual_reset;
      event->eventdata_->is_signaled_ = initial_state;
      event->eventdata_->auto_event_signaled_ = false;
      event->eventdata_->waiting_threads_ = 0;
      event->eventdata_->signal_count_ = 0;

# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
      int result = ACE_OS::cond_init (&event->eventdata_->condition_,
                                      static_cast<short> (type),
                                      name,
                                      arg);
# else
      int result = ACE_OS::sema_init (&event->semaphore_,
                                      0,
                                      type,
                                      name,
                                      arg);
# endif
      if (result == 0)
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
        result = ACE_OS::mutex_init (&event->eventdata_->lock_,
                                     type,
                                     name,
                                     (ACE_mutexattr_t *) arg);
# else
      result = ACE_OS::sema_init (&event->lock_,
                                  0,
                                  type,
                                  name,
                                  arg);
      if (result == 0)
        result = ACE_OS::sema_post(&event->lock_);    /* initially unlock */
# endif

      return result;
    }
#else
  ACE_UNUSED_ARG (event);
  ACE_UNUSED_ARG (manual_reset);
  ACE_UNUSED_ARG (initial_state);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_UNUSED_ARG (sa);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

int
ACE_OS::event_pulse (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::PulseEvent (*event), ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
  int result = 0;
  int error = 0;

  // grab the lock first
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
  if (ACE_OS::mutex_lock (&event->eventdata_->lock_) == 0)
# else
  if (ACE_OS::sema_wait (&event->lock_) == 0)
# endif
  {
    if (event->eventdata_->waiting_threads_ > 0)
    {
      // Manual-reset event.
      if (event->eventdata_->manual_reset_ == 1)
      {
        // Wakeup all waiters.
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
        if (ACE_OS::cond_broadcast (&event->eventdata_->condition_) != 0)
        {
          result = -1;
          error = errno;
        }
        if (result == 0)
          event->eventdata_->signal_count_ = event->eventdata_->waiting_threads_;
# else
        event->eventdata_->signal_count_ = event->eventdata_->waiting_threads_;
        for (unsigned long i=0; i<event->eventdata_->signal_count_ ;++i)
          if (ACE_OS::sema_post(&event->semaphore_) != 0)
          {
            event->eventdata_->signal_count_ = 0;
            result = -1;
            error = errno;
          }

        if (result == 0)
          while(event->eventdata_->signal_count_!=0 && event->eventdata_->waiting_threads_!=0)
            ACE_OS::thr_yield ();
# endif
      }
      // Auto-reset event: wakeup one waiter.
      else
      {
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
        if (ACE_OS::cond_signal (&event->eventdata_->condition_) != 0)
# else
        if (ACE_OS::sema_post(&event->semaphore_) != 0)
# endif
        {
          result = -1;
          error = errno;
        }

        event->eventdata_->auto_event_signaled_ = true;
      }
    }

    // Reset event.
    event->eventdata_->is_signaled_ = 0;

    // Now we can let go of the lock.
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
    if (ACE_OS::mutex_unlock (&event->eventdata_->lock_) != 0)
      return -1;
# else
    if (ACE_OS::sema_post (&event->lock_) != 0)
      return -1;
# endif
    if (result == -1)
      // Reset errno in case mutex_unlock() also fails...
      errno = error;
  }
  else
    result = -1;
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

int
ACE_OS::event_reset (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::ResetEvent (*event), ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
  int result = 0;

  // Grab the lock first.
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
  if (ACE_OS::mutex_lock (&event->eventdata_->lock_) == 0)
# else
  if (ACE_OS::sema_wait (&event->lock_) == 0)
# endif
  {
    // Reset event.
    event->eventdata_->is_signaled_ = 0;
    event->eventdata_->auto_event_signaled_ = false;

    // Now we can let go of the lock.
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
    if (ACE_OS::mutex_unlock (&event->eventdata_->lock_) != 0)
      return -1;
# else
    if (ACE_OS::sema_post (&event->lock_) != 0)
      return -1;
# endif
  }
  else
    result = -1;
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

int
ACE_OS::event_signal (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::SetEvent (*event), ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
  int result = 0;
  int error = 0;

  // grab the lock first
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
  if (ACE_OS::mutex_lock (&event->eventdata_->lock_) == 0)
# else
  if (ACE_OS::sema_wait (&event->lock_) == 0)
# endif
  {
    // Manual-reset event.
    if (event->eventdata_->manual_reset_ == 1)
    {
      // wakeup all
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
      if (ACE_OS::cond_broadcast (&event->eventdata_->condition_) != 0)
      {
        result = -1;
        error = errno;
      }
# else
      if (ACE_OS::sema_post(&event->semaphore_) != 0)
      {
        result = -1;
        error = errno;
      }
# endif

      if (result == 0)
        // signal event
        event->eventdata_->is_signaled_ = 1;
    }
    // Auto-reset event
    else
    {
      if (event->eventdata_->waiting_threads_ == 0)
        // No waiters: signal event.
        event->eventdata_->is_signaled_ = 1;
      // Waiters: wakeup one waiter.
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
      else if (ACE_OS::cond_signal (&event->eventdata_->condition_) != 0)
# else
      else if (ACE_OS::sema_post(&event->semaphore_) != 0)
# endif
      {
        result = -1;
        error = errno;
      }

      event->eventdata_->auto_event_signaled_ = true;
    }

    // Now we can let go of the lock.
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
    if (ACE_OS::mutex_unlock (&event->eventdata_->lock_) != 0)
      return -1;
# else
    if (ACE_OS::sema_post (&event->lock_) != 0)
      return -1;
# endif

    if (result == -1)
      // Reset errno in case mutex_unlock() also fails...
      errno = error;
  }
  else
    result = -1;

  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

int
ACE_OS::event_timedwait (ACE_event_t *event,
                         ACE_Time_Value *timeout,
                         int use_absolute_time)
{
  if (timeout == 0)
    // Wait indefinitely.
    return ACE_OS::event_wait (event);

#if defined (ACE_WIN32)
  DWORD result;

  if (*timeout == ACE_Time_Value::zero)
    // Do a "poll".
    result = ::WaitForSingleObject (*event, 0);
  else
    {
      // Wait for upto <relative_time> number of milliseconds.  Note
      // that we must convert between absolute time (which is passed
      // as a parameter) and relative time (which is what
      // WaitForSingleObjects() expects).
      // <timeout> parameter is given in absolute or relative value
      // depending on parameter <use_absolute_time>.
      int msec_timeout = 0;
      if (use_absolute_time)
        {
          // Time is given in absolute time, we should use
          // gettimeofday() to calculate relative time
          ACE_Time_Value relative_time = timeout->to_relative_time ();

          // Watchout for situations where a context switch has caused
          // the current time to be > the timeout.  Thanks to Norbert
          // Rapp <NRapp@nexus-informatics.de> for pointing this.
          if (relative_time > ACE_Time_Value::zero)
            msec_timeout = relative_time.msec ();
        }
      else
        // time is given in relative time, just convert it into
        // milliseconds and use it
        msec_timeout = timeout->msec ();
      result = ::WaitForSingleObject (*event, msec_timeout);
    }

  switch (result)
    {
    case WAIT_OBJECT_0:
      return 0;
    case WAIT_TIMEOUT:
      errno = ETIME;
      return -1;
    default:
      // This is a hack, we need to find an appropriate mapping...
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
#elif defined (ACE_HAS_THREADS)
  int result = 0;
  int error = 0;

  // grab the lock first
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
  if (ACE_OS::mutex_lock (&event->eventdata_->lock_) == 0)
# else
  if (ACE_OS::sema_wait (&event->lock_) == 0)
# endif
    {
      if (event->eventdata_->is_signaled_ == 1)
        // event is currently signaled
        {
          if (event->eventdata_->manual_reset_ == 0)
            {
              // AUTO: reset state
              event->eventdata_->is_signaled_ = 0;
              event->eventdata_->auto_event_signaled_ = false;
            }
        }
      else
        // event is currently not signaled
        {
          event->eventdata_->waiting_threads_++;

          ACE_Time_Value absolute_timeout = *timeout;

          // cond_timewait() expects absolute time, check
          // <use_absolute_time> flag.
          if (use_absolute_time == 0)
            absolute_timeout = timeout->to_absolute_time ();

          while (event->eventdata_->is_signaled_ == 0 &&
                 event->eventdata_->auto_event_signaled_ == false)
            {
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
              if (ACE_OS::cond_timedwait (&event->eventdata_->condition_,
                                          &event->eventdata_->lock_,
                                          &absolute_timeout) != 0)
                {
                  result = -1;
                  error = errno;
                  break;
                }

              if (event->eventdata_->signal_count_ > 0)
                {
                  event->eventdata_->signal_count_--;
                  break;
                }
# else
#   if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_MUTEXATTR_PSHARED)) || \
      (!defined (ACE_USES_FIFO_SEM) && (!defined (ACE_HAS_POSIX_SEM) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
              if (ACE_OS::mutex_unlock (&event->eventdata_->lock_) != 0)
#   else
                if (ACE_OS::sema_post (&event->lock_) != 0)
#   endif
                  {
                    event->eventdata_->waiting_threads_--;
                    return -1;
                  }

              if (ACE_OS::sema_wait(&event->semaphore_, absolute_timeout) !=0)
                {
                  result = -1;
                  if (errno == ETIMEDOUT) // Semaphores time out with ETIMEDOUT (POSIX)
                    error = ETIME;
                  else
                    error = errno;
                }

              bool signalled = false;
              if (result == 0 && event->eventdata_->signal_count_ > 0)
                {
                  event->eventdata_->signal_count_--;
                  signalled = true;
                }

#   if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_MUTEXATTR_PSHARED)) || \
      (!defined (ACE_USES_FIFO_SEM) && (!defined (ACE_HAS_POSIX_SEM) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
              if (ACE_OS::mutex_lock (&event->eventdata_->lock_) != 0)
#   else
                if (ACE_OS::sema_wait (&event->lock_) != 0)
#   endif
                  {
                    event->eventdata_->waiting_threads_--;  // yes, I know it's not save
                    return -1;
                  }

              if (result)
                break;

              if (event->eventdata_->manual_reset_ == 1 && event->eventdata_->is_signaled_ == 1)
                if (ACE_OS::sema_post(&event->semaphore_) != 0)
                  {
                    result = -1;
                    error = errno;
                    break;
                  }

              if (signalled)
                break;
# endif
            }

          // Reset the auto_event_signaled_ to false now that we have
          // woken up.
          if (event->eventdata_->auto_event_signaled_ == true)
            event->eventdata_->auto_event_signaled_ = false;

          event->eventdata_->waiting_threads_--;
        }

      // Now we can let go of the lock.
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
      if (ACE_OS::mutex_unlock (&event->eventdata_->lock_) != 0)
        return -1;
# else
      if (ACE_OS::sema_post (&event->lock_) != 0)
        return -1;
# endif

      if (result == -1)
        // Reset errno in case mutex_unlock() also fails...
        errno = error;
    }
  else
    result = -1;
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (use_absolute_time);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

int
ACE_OS::event_wait (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  switch (::WaitForSingleObject (*event, INFINITE))
    {
    case WAIT_OBJECT_0:
      return 0;
    default:
      {
        ACE_OS::set_errno_to_last_error ();
        return -1;
      }
    }
#elif defined (ACE_HAS_THREADS)
  int result = 0;
  int error = 0;

  // grab the lock first
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
  if (ACE_OS::mutex_lock (&event->eventdata_->lock_) == 0)
# else
  if (ACE_OS::sema_wait (&event->lock_) == 0)
# endif
    {
      if (event->eventdata_->is_signaled_ == 1)
        // Event is currently signaled.
        {
          if (event->eventdata_->manual_reset_ == 0)
            // AUTO: reset state
            event->eventdata_->is_signaled_ = 0;
        }
      else // event is currently not signaled
        {
          event->eventdata_->waiting_threads_++;

          while (event->eventdata_->is_signaled_ == 0 &&
                 event->eventdata_->auto_event_signaled_ == false)
            {
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_CONDATTR_PSHARED)) || \
    (!defined (ACE_USES_FIFO_SEM) && \
      (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
              if (ACE_OS::cond_wait (&event->eventdata_->condition_,
                                     &event->eventdata_->lock_) != 0)
                {
                  result = -1;
                  error = errno;
                  // Something went wrong...
                  break;
                }
              if (event->eventdata_->signal_count_ > 0)
                {
                  event->eventdata_->signal_count_--;
                  break;
                }
# else
#   if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_MUTEXATTR_PSHARED)) || \
      (!defined (ACE_USES_FIFO_SEM) && (!defined (ACE_HAS_POSIX_SEM) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
              if (ACE_OS::mutex_unlock (&event->eventdata_->lock_) != 0)
#   else
                if (ACE_OS::sema_post (&event->lock_) != 0)
#   endif
                  {
                    event->eventdata_->waiting_threads_--;
                    return -1;
                  }

              if (ACE_OS::sema_wait (&event->semaphore_) !=0)
                {
                  result = -1;
                  error = errno;
                }

              bool signalled = false;
              if (result == 0 && event->eventdata_->signal_count_ > 0)
                {
                  event->eventdata_->signal_count_--;
                  signalled = true;
                }

#   if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_MUTEXATTR_PSHARED)) || \
      (!defined (ACE_USES_FIFO_SEM) && (!defined (ACE_HAS_POSIX_SEM) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
              if (ACE_OS::mutex_lock (&event->eventdata_->lock_) != 0)
#   else
                if (ACE_OS::sema_wait (&event->lock_) != 0)
#   endif
                  {
                    event->eventdata_->waiting_threads_--;
                    return -1;
                  }

              if (result)
                break;

              if (event->eventdata_->manual_reset_ == 1 && event->eventdata_->is_signaled_ == 1)
                if (ACE_OS::sema_post(&event->semaphore_) != 0)
                  {
                    result = -1;
                    error = errno;
                    break;
                  }

              if (signalled)
                break;
# endif
            }

          // Reset it since we have woken up.
          if (event->eventdata_->auto_event_signaled_ == true)
            event->eventdata_->auto_event_signaled_ = false;

          event->eventdata_->waiting_threads_--;
        }

      // Now we can let go of the lock.
# if (defined (ACE_HAS_PTHREADS) && defined (_POSIX_THREAD_PROCESS_SHARED) && \
        (!defined (ACE_LACKS_MUTEXATTR_PSHARED) || !defined (ACE_LACKS_CONDATTR_PSHARED))) || \
     (!defined (ACE_USES_FIFO_SEM) && \
        (!defined (ACE_HAS_POSIX_SEM) || !defined (ACE_HAS_POSIX_SEM_TIMEOUT) || defined (ACE_LACKS_NAMED_POSIX_SEM)))
      if (ACE_OS::mutex_unlock (&event->eventdata_->lock_) != 0)
        return -1;
# else
      if (ACE_OS::sema_post (&event->lock_) != 0)
        return -1;
# endif

      if (result == -1)
        // Reset errno in case mutex_unlock() also fails...
        errno = error;
    }
  else
    result = -1;
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

/*****************************************************************************/
// EVENTS END
/*****************************************************************************/

int
ACE_OS::lwp_getparams (ACE_Sched_Params &sched_params)
{
#if defined (ACE_HAS_STHREADS) || defined (sun)
  // Get the class TS and RT class IDs.
  ACE_id_t rt_id;
  ACE_id_t ts_id;
  if (ACE_OS::scheduling_class ("RT", rt_id) == -1
      || ACE_OS::scheduling_class ("TS", ts_id) == -1)
    return -1;

  // Get this LWP's scheduling parameters.
  pcparms_t pcparms;
  // The following is just to avoid Purify warnings about unitialized
  // memory reads.
  ACE_OS::memset (&pcparms, 0, sizeof pcparms);
  pcparms.pc_cid = PC_CLNULL;

  if (ACE_OS::priority_control (P_LWPID,
                                P_MYID,
                                PC_GETPARMS,
                                (char *) &pcparms) == -1)
    return -1;
  else if (pcparms.pc_cid == rt_id)
    {
      // RT class.
      rtparms_t rtparms;
      ACE_OS::memcpy (&rtparms, pcparms.pc_clparms, sizeof rtparms);

      sched_params.policy (ACE_SCHED_FIFO);
      sched_params.priority (rtparms.rt_pri);
      sched_params.scope (ACE_SCOPE_THREAD);
      ACE_Time_Value quantum (rtparms.rt_tqsecs,
                              rtparms.rt_tqnsecs == RT_TQINF
                              ? 0 : rtparms.rt_tqnsecs * 1000);
      sched_params.quantum (quantum);
      return 0;
    }
  else if (pcparms.pc_cid == ts_id)
    {
      /* TS class */
      tsparms_t tsparms;
      ACE_OS::memcpy (&tsparms, pcparms.pc_clparms, sizeof tsparms);

      sched_params.policy (ACE_SCHED_OTHER);
      sched_params.priority (tsparms.ts_upri);
      sched_params.scope (ACE_SCOPE_THREAD);
      return 0;
    }
  else
    return -1;

#else  /* ! ACE_HAS_STHREADS && ! sun */
  ACE_UNUSED_ARG (sched_params);
  ACE_NOTSUP_RETURN (-1);
#endif /* ! ACE_HAS_STHREADS && ! sun */
}

int
ACE_OS::lwp_setparams (const ACE_Sched_Params &sched_params)
{
#if defined (ACE_HAS_STHREADS) || defined (sun)
  ACE_Sched_Params lwp_params (sched_params);
  lwp_params.scope (ACE_SCOPE_LWP);
  return ACE_OS::sched_params (lwp_params);
#else  /* ! ACE_HAS_STHREADS && ! sun */
  ACE_UNUSED_ARG (sched_params);
  ACE_NOTSUP_RETURN (-1);
#endif /* ! ACE_HAS_STHREADS && ! sun */
}

#if !defined (ACE_HAS_THREADS) || (defined (ACE_LACKS_RWLOCK_T) && \
                                   !defined (ACE_HAS_PTHREADS_UNIX98_EXT))
int
ACE_OS::rwlock_init (ACE_rwlock_t *rw,
                     int type,
                     const ACE_TCHAR *name,
                     void *arg)
{
  // ACE_OS_TRACE ("ACE_OS::rwlock_init");
# if defined (ACE_HAS_THREADS) && defined (ACE_LACKS_RWLOCK_T)
  // NT, POSIX, and VxWorks don't support this natively.
  ACE_UNUSED_ARG (name);
  int result = -1;

  // Since we cannot use the user specified name for all three
  // objects, we will create three completely new names.
  ACE_TCHAR name1[ACE_UNIQUE_NAME_LEN];
  ACE_TCHAR name2[ACE_UNIQUE_NAME_LEN];
  ACE_TCHAR name3[ACE_UNIQUE_NAME_LEN];
  ACE_TCHAR name4[ACE_UNIQUE_NAME_LEN];

  ACE_OS::unique_name ((const void *) &rw->lock_,
                       name1,
                       ACE_UNIQUE_NAME_LEN);
  ACE_OS::unique_name ((const void *) &rw->waiting_readers_,
                       name2,
                       ACE_UNIQUE_NAME_LEN);
  ACE_OS::unique_name ((const void *) &rw->waiting_writers_,
                       name3,
                       ACE_UNIQUE_NAME_LEN);
  ACE_OS::unique_name ((const void *) &rw->waiting_important_writer_,
                       name4,
                       ACE_UNIQUE_NAME_LEN);

  ACE_condattr_t attributes;
  if (ACE_OS::condattr_init (attributes, type) == 0)
    {
      if (ACE_OS::mutex_init (&rw->lock_, type, name1,
                              (ACE_mutexattr_t *) arg) == 0
          && ACE_OS::cond_init (&rw->waiting_readers_,
                                attributes, name2, arg) == 0
          && ACE_OS::cond_init (&rw->waiting_writers_,
                                attributes, name3, arg) == 0
          && ACE_OS::cond_init (&rw->waiting_important_writer_,
                                attributes, name4, arg) == 0)
        {
          // Success!
          rw->ref_count_ = 0;
          rw->num_waiting_writers_ = 0;
          rw->num_waiting_readers_ = 0;
          rw->important_writer_ = false;
          result = 0;
        }
      ACE_OS::condattr_destroy (attributes);
    }

  if (result == -1)
    {
      // Save/restore errno.
      ACE_Errno_Guard error (errno);

      /* We're about to return -1 anyway, so
       * no need to check return values of these clean-up calls:
       */
      (void)ACE_OS::mutex_destroy (&rw->lock_);
      (void)ACE_OS::cond_destroy (&rw->waiting_readers_);
      (void)ACE_OS::cond_destroy (&rw->waiting_writers_);
      (void)ACE_OS::cond_destroy (&rw->waiting_important_writer_);
    }
  return result;
# else
  ACE_UNUSED_ARG (rw);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}
#endif /* ! ACE_HAS_THREADS || ACE_LACKS_RWLOCK_T */

int
ACE_OS::sched_params (const ACE_Sched_Params &sched_params,
                      ACE_id_t id)
{
  ACE_OS_TRACE ("ACE_OS::sched_params");
#if defined (ACE_HAS_STHREADS)
  return ACE_OS::set_scheduling_params (sched_params, id);
#elif defined (ACE_HAS_PTHREADS) && \
      (!defined (ACE_LACKS_SETSCHED) || \
      defined (ACE_HAS_PTHREAD_SCHEDPARAM))
  if (sched_params.quantum () != ACE_Time_Value::zero)
    {
      // quantums not supported
      errno = EINVAL;
      return -1;
    }

  // Thanks to Thilo Kielmann <kielmann@informatik.uni-siegen.de> for
  // providing this code for 1003.1c PThreads.  Please note that this
  // has only been tested for POSIX 1003.1c threads, and may cause
  // problems with other PThreads flavors!

  struct sched_param param;
  param.sched_priority = sched_params.priority ();

  if (sched_params.scope () == ACE_SCOPE_PROCESS)
    {
# if defined (ACE_HAS_PTHREAD_SCHEDPARAM)
      ACE_UNUSED_ARG (id);
      ACE_NOTSUP_RETURN (-1);
# else  /* !ACE_HAS_PTHREAD_SCHEDPARAM */
      int result = ::sched_setscheduler (id == ACE_SELF ? 0 : id,
                                         sched_params.policy (),
                                         &param) == -1 ? -1 : 0;
      return result;
# endif /* !ACE_HAS_PTHREAD_SCHEDPARAM */
    }
  else if (sched_params.scope () == ACE_SCOPE_THREAD)
    {
      ACE_thread_t thr_id = ACE_OS::thr_self ();

      int result;
      ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_setschedparam (thr_id,
                                                                    sched_params.policy (),
                                                                    &param),
                                           result),
                         int, -1);
    }
# if defined (sun)
  // We need to be able to set LWP priorities on Suns, even without
  // ACE_HAS_STHREADS, to obtain preemption.
  else if (sched_params.scope () == ACE_SCOPE_LWP)
    return ACE_OS::set_scheduling_params (sched_params, id);
# endif /* sun */
  else // sched_params.scope () == ACE_SCOPE_LWP, which isn't POSIX
    {
      errno = EINVAL;
      return -1;
    }

#elif defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)

  // PharLap ETS can act on the current thread - it can set the
  // quantum also, unlike Win32. All this only works on the RT
  // version.
# if defined (ACE_HAS_PHARLAP_RT)
  if (id != ACE_SELF)
    ACE_NOTSUP_RETURN (-1);

#   if !defined (ACE_PHARLAP_LABVIEW_RT)
  if (sched_params.quantum() != ACE_Time_Value::zero)
    EtsSetTimeSlice (sched_params.quantum().msec());
#   endif

# else

  if (sched_params.quantum () != ACE_Time_Value::zero)
    {
      // I don't know of a way to set the quantum on Win32.
      errno = EINVAL;
      return -1;
    }

# endif /* ACE_HAS_PHARLAP_RT */

  if (sched_params.scope () == ACE_SCOPE_THREAD)
    {

      // Setting the REALTIME_PRIORITY_CLASS on Windows is almost always
      // a VERY BAD THING. This include guard will allow people
      // to easily disable this feature in ACE.
      // It won't work at all for Pharlap since there's no SetPriorityClass.
#if !defined (ACE_HAS_PHARLAP) && \
    !defined (ACE_DISABLE_WIN32_INCREASE_PRIORITY)
      // Set the priority class of this process to the REALTIME process class
      // _if_ the policy is ACE_SCHED_FIFO.  Otherwise, set to NORMAL.
      if (!::SetPriorityClass (::GetCurrentProcess (),
                               (sched_params.policy () == ACE_SCHED_FIFO ||
                                sched_params.policy () == ACE_SCHED_RR)
                               ? REALTIME_PRIORITY_CLASS
                               : NORMAL_PRIORITY_CLASS))
        {
          ACE_OS::set_errno_to_last_error ();
          return -1;
        }
#endif /* ACE_DISABLE_WIN32_INCREASE_PRIORITY */

      // Now that we have set the priority class of the process, set the
      // priority of the current thread to the desired value.
      return ACE_OS::thr_setprio (sched_params.priority ());
    }
  else if (sched_params.scope () == ACE_SCOPE_PROCESS)
    {

# if defined (ACE_HAS_PHARLAP_RT)
      ACE_NOTSUP_RETURN (-1);
# else
      HANDLE hProcess
        = ::OpenProcess (PROCESS_SET_INFORMATION,
                         FALSE,
                         id == ACE_SELF ? ::GetCurrentProcessId() : id);
      if (!hProcess)
        {
          ACE_OS::set_errno_to_last_error();
          return -1;
        }
      // There is no way for us to set the priority of the thread when we
      // are setting the priority of a different process.  So just ignore
      // the priority argument when ACE_SCOPE_PROCESS is specified.
      // Setting the priority class will automatically increase the base
      // priority of all the threads within a process while maintaining the
      // relative priorities of the threads within it.
      if (!::SetPriorityClass (hProcess,
                               (sched_params.policy () == ACE_SCHED_FIFO ||
                                sched_params.policy () == ACE_SCHED_RR)
                               ? REALTIME_PRIORITY_CLASS
                               : NORMAL_PRIORITY_CLASS))
        {
          ACE_OS::set_errno_to_last_error ();
          ::CloseHandle (hProcess);
          return -1;
        }
      ::CloseHandle (hProcess);
      return 0;
#endif /* ACE_HAS_PHARLAP_RT */

    }
  else
    {
      errno = EINVAL;
      return -1;
    }
#elif defined (ACE_VXWORKS)
  ACE_UNUSED_ARG (id);

  // There is only one class of priorities on VxWorks, and no time
  // quanta.  So, just set the current thread's priority.

  if (sched_params.policy () != ACE_SCHED_FIFO
      || sched_params.scope () != ACE_SCOPE_PROCESS
      || sched_params.quantum () != ACE_Time_Value::zero)
    {
      errno = EINVAL;
      return -1;
    }

  // Set the thread priority on the current thread.
  return ACE_OS::thr_setprio (sched_params.priority ());
#else
  ACE_UNUSED_ARG (sched_params);
  ACE_UNUSED_ARG (id);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STHREADS */
}

int
ACE_OS::scheduling_class (const char *class_name, ACE_id_t &id)
{
#if defined (ACE_HAS_PRIOCNTL)
  // Get the priority class ID.
  pcinfo_t pcinfo;
  // The following is just to avoid Purify warnings about unitialized
  // memory reads.
  ACE_OS::memset (&pcinfo, 0, sizeof pcinfo);

  ACE_OS::strcpy (pcinfo.pc_clname, class_name);
  if (ACE_OS::priority_control (P_ALL /* ignored */,
                                P_MYID /* ignored */,
                                PC_GETCID,
                                (char *) &pcinfo) == -1)
    {
      return -1;
    }
  else
    {
      id = pcinfo.pc_cid;
      return 0;
    }
#else  /* ! ACE_HAS_PRIOCNTL */
  ACE_UNUSED_ARG (class_name);
  ACE_UNUSED_ARG (id);
  ACE_NOTSUP_RETURN (-1);
#endif /* ! ACE_HAS_PRIOCNTL */
}

int
ACE_OS::set_scheduling_params (const ACE_Sched_Params &sched_params,
                               ACE_id_t id)
{
#if defined (ACE_HAS_PRIOCNTL)
  // Set priority class, priority, and quantum of this LWP or process as
  // specified in sched_params.

  // Get the priority class ID.
  ACE_id_t class_id;
  if (ACE_OS::scheduling_class (sched_params.policy() == ACE_SCHED_OTHER  ?
                                  "TS"  :
                                  "RT", class_id) == -1)
    {
      return -1;
    }

  pcparms_t pcparms;
  // The following is just to avoid Purify warnings about unitialized
  // memory reads.
  ACE_OS::memset (&pcparms, 0, sizeof pcparms);

  pcparms.pc_cid = class_id;

  if (sched_params.policy () == ACE_SCHED_OTHER  &&
      sched_params.quantum () == ACE_Time_Value::zero)
      // SunOS doesn't support non-zero quantums in time-sharing class:  use
      // real-time class instead.
    {
      tsparms_t tsparms;
      // The following is just to avoid Purify warnings about unitialized
      // memory reads.
      ACE_OS::memset (&tsparms, 0, sizeof tsparms);

      // Don't change ts_uprilim (user priority limit)
      tsparms.ts_uprilim = TS_NOCHANGE;
      tsparms.ts_upri = sched_params.priority ();

      // Package up the TS class ID and parameters for the
      // priority_control () call.
      ACE_OS::memcpy (pcparms.pc_clparms, &tsparms, sizeof tsparms);
    }
  else if (sched_params.policy () == ACE_SCHED_FIFO  ||
           (sched_params.policy () == ACE_SCHED_RR &&
            sched_params.quantum () != ACE_Time_Value::zero))
           // must have non-zero quantum for RR, to make it meaningful
           // A zero quantum with FIFO has special significance:  it actually
           // means infinite time quantum, i.e., run-to-completion.
    {
      rtparms_t rtparms;
      // The following is just to avoid Purify warnings about unitialized
      // memory reads.
      ACE_OS::memset (&rtparms, 0, sizeof rtparms);

      rtparms.rt_pri = sched_params.priority ();

      if (sched_params.quantum () == ACE_Time_Value::zero)
        {
          // rtparms.rt_tqsecs is ignored with RT_TQINF
          rtparms.rt_tqnsecs = RT_TQINF;
        }
      else
        {
          rtparms.rt_tqsecs = (ulong) sched_params.quantum ().sec ();
          rtparms.rt_tqnsecs = sched_params.quantum ().usec () * 1000;
        }

      // Package up the RT class ID and parameters for the
      // priority_control () call.
      ACE_OS::memcpy (pcparms.pc_clparms, &rtparms, sizeof rtparms);
    }
  else
    {
      errno = EINVAL;
      return -1;
    }

  if (ACE_OS::priority_control ((idtype_t) (sched_params.scope () == ACE_SCOPE_THREAD
                                            ? ACE_SCOPE_PROCESS
                                            : sched_params.scope ()),
                                id,
                                PC_SETPARMS,
                                (char *) &pcparms) < 0)
    {
      return ACE_OS::last_error ();
    }

  return 0;
#else  /* ! ACE_HAS_PRIOCNTL */
  ACE_UNUSED_ARG (sched_params);
  ACE_UNUSED_ARG (id);
  ACE_NOTSUP_RETURN (-1);
#endif /* ! ACE_HAS_PRIOCNTL */
}

int
ACE_OS::thr_create (ACE_THR_FUNC func,
                    void *args,
                    long flags,
                    ACE_thread_t *thr_id,
                    ACE_hthread_t *thr_handle,
                    long priority,
                    void *stack,
                    size_t stacksize,
                    ACE_Base_Thread_Adapter *thread_adapter,
                    const char** thr_name)
{
  ACE_OS_TRACE ("ACE_OS::thr_create");

  if (ACE_BIT_DISABLED (flags, THR_DETACHED) &&
      ACE_BIT_DISABLED (flags, THR_JOINABLE))
    ACE_SET_BITS (flags, THR_JOINABLE);

#if defined (ACE_NO_THREAD_ADAPTER)
# define  ACE_THREAD_FUNCTION  func
# define  ACE_THREAD_ARGUMENT  args
#else /* ! defined (ACE_NO_THREAD_ADAPTER) */
# define  ACE_THREAD_FUNCTION  thread_args->entry_point ()
# define  ACE_THREAD_ARGUMENT  thread_args
#endif /* ! defined (ACE_NO_THREAD_ADAPTER) */

  ACE_Base_Thread_Adapter *thread_args = 0;
  if (thread_adapter == 0)
#if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
    ACE_NEW_RETURN (thread_args,
                    ACE_OS_Thread_Adapter (func, args,
                                           (ACE_THR_C_FUNC) ACE_THREAD_ADAPTER_NAME,
                                           ACE_OS_Object_Manager::seh_except_selector(),
                                           ACE_OS_Object_Manager::seh_except_handler(),
                                           flags),
                    -1);
#else
  ACE_NEW_RETURN (thread_args,
                  ACE_OS_Thread_Adapter (func, args,
                                         (ACE_THR_C_FUNC) ACE_THREAD_ADAPTER_NAME,
                                         flags),
                  -1);

#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
  else
    thread_args = thread_adapter;

  auto_ptr <ACE_Base_Thread_Adapter> auto_thread_args;

  if (thread_adapter == 0)
    ACE_auto_ptr_reset (auto_thread_args,
                        thread_args);

#if defined (ACE_HAS_THREADS)

  // *** Set Stack Size
# if defined (ACE_NEEDS_HUGE_THREAD_STACKSIZE)
  if (stacksize < ACE_NEEDS_HUGE_THREAD_STACKSIZE)
    stacksize = ACE_NEEDS_HUGE_THREAD_STACKSIZE;
# endif /* ACE_NEEDS_HUGE_THREAD_STACKSIZE */

  ACE_thread_t tmp_thr;
  if (thr_id == 0)
    thr_id = &tmp_thr;

  ACE_hthread_t tmp_handle;
  if (thr_handle == 0)
    thr_handle = &tmp_handle;

# if defined (ACE_HAS_PTHREADS)
  int result;
# if defined (ACE_PTHREAD_ATTR_T_INITIALIZE)
  /* Tests show that VxWorks 6.x pthread lib does not only
   * require zeroing of mutex/condition objects to function correctly
   * but also of the attribute objects.
   */
  pthread_attr_t attr = {0};
#   else
  pthread_attr_t attr;
#   endif
  if (ACE_ADAPT_RETVAL(::pthread_attr_init(&attr), result) != 0)
    return -1;

  if (stacksize != 0)
    {
      size_t size = stacksize;

#   if defined (PTHREAD_STACK_MIN)
      if (size < static_cast <size_t> (PTHREAD_STACK_MIN))
        size = PTHREAD_STACK_MIN;
#   endif /* PTHREAD_STACK_MIN */

#   if !defined (ACE_LACKS_PTHREAD_ATTR_SETSTACKSIZE)
#     if !defined (ACE_LACKS_PTHREAD_ATTR_SETSTACK)
      int result;
      if (stack != 0)
        result = ACE_ADAPT_RETVAL (pthread_attr_setstack (&attr, stack, size), result);
      else
        result = ACE_ADAPT_RETVAL (pthread_attr_setstacksize (&attr, size), result);
      if (result == -1)
#     else
      if (ACE_ADAPT_RETVAL (pthread_attr_setstacksize (&attr, size), result) == -1)
#     endif /* !ACE_LACKS_PTHREAD_ATTR_SETSTACK */
        {
          ::pthread_attr_destroy (&attr);
          return -1;
        }
#   else
      ACE_UNUSED_ARG (size);
#   endif /* !ACE_LACKS_PTHREAD_ATTR_SETSTACKSIZE */
    }

  // *** Set Stack Address
#   if defined (ACE_LACKS_PTHREAD_ATTR_SETSTACK)
#     if !defined (ACE_LACKS_PTHREAD_ATTR_SETSTACKADDR)
  if (stack != 0)
    {
      if (ACE_ADAPT_RETVAL(::pthread_attr_setstackaddr (&attr, stack), result) != 0)
        {
          ::pthread_attr_destroy (&attr);
          return -1;
        }
    }
#     else
  ACE_UNUSED_ARG (stack);
#     endif /* !ACE_LACKS_PTHREAD_ATTR_SETSTACKADDR */
#   endif /* ACE_LACKS_PTHREAD_ATTR_SETSTACK */

  // *** Deal with various attributes
  if (flags != 0)
    {
      // *** Set Detach state
#   if !defined (ACE_LACKS_SETDETACH)
      if (ACE_BIT_ENABLED (flags, THR_DETACHED)
          || ACE_BIT_ENABLED (flags, THR_JOINABLE))
        {
          int dstate = PTHREAD_CREATE_JOINABLE;

          if (ACE_BIT_ENABLED (flags, THR_DETACHED))
            dstate = PTHREAD_CREATE_DETACHED;

          if (ACE_ADAPT_RETVAL(::pthread_attr_setdetachstate (&attr, dstate),
                               result) != 0)
            {
              ::pthread_attr_destroy (&attr);
              return -1;
            }
        }

      // Note: if ACE_LACKS_SETDETACH and THR_DETACHED is enabled, we
      // call ::pthread_detach () below.  If THR_DETACHED is not
      // enabled, we call ::pthread_detach () in the Thread_Manager,
      // after joining with the thread.
#   endif /* ACE_LACKS_SETDETACH */

      // *** Set Policy
#   if !defined (ACE_LACKS_SETSCHED) || defined (ACE_HAS_PTHREAD_SCHEDPARAM)
      // If we wish to set the priority explicitly, we have to enable
      // explicit scheduling, and a policy, too.
      if (priority != ACE_DEFAULT_THREAD_PRIORITY)
        {
          ACE_SET_BITS (flags, THR_EXPLICIT_SCHED);
          if (ACE_BIT_DISABLED (flags, THR_SCHED_FIFO)
              && ACE_BIT_DISABLED (flags, THR_SCHED_RR)
              && ACE_BIT_DISABLED (flags, THR_SCHED_DEFAULT))
            ACE_SET_BITS (flags, THR_SCHED_DEFAULT);
        }

      if (ACE_BIT_ENABLED (flags, THR_SCHED_FIFO)
          || ACE_BIT_ENABLED (flags, THR_SCHED_RR)
          || ACE_BIT_ENABLED (flags, THR_SCHED_DEFAULT))
        {
          int spolicy;

#     if defined (ACE_HAS_ONLY_SCHED_OTHER)
          // SunOS, thru version 5.6, only supports SCHED_OTHER.
          spolicy = SCHED_OTHER;
#     elif defined (ACE_HAS_ONLY_SCHED_FIFO)
          // NonStop OSS standard pthread supports only SCHED_FIFO.
          spolicy = SCHED_FIFO;
#     else
          // Make sure to enable explicit scheduling, in case we didn't
          // enable it above (for non-default priority).
          ACE_SET_BITS (flags, THR_EXPLICIT_SCHED);

          if (ACE_BIT_ENABLED (flags, THR_SCHED_DEFAULT))
            spolicy = SCHED_OTHER;
          else if (ACE_BIT_ENABLED (flags, THR_SCHED_FIFO))
            spolicy = SCHED_FIFO;
#       if defined (SCHED_IO)
          else if (ACE_BIT_ENABLED (flags, THR_SCHED_IO))
            spolicy = SCHED_IO;
#       else
          else if (ACE_BIT_ENABLED (flags, THR_SCHED_IO))
            {
              errno = ENOSYS;
              return -1;
            }
#       endif /* SCHED_IO */
          else
            spolicy = SCHED_RR;

#     endif /* ACE_HAS_ONLY_SCHED_OTHER */

          (void) ACE_ADAPT_RETVAL(::pthread_attr_setschedpolicy (&attr, spolicy),
                           result);
          if (result != 0)
            {
              ::pthread_attr_destroy (&attr);
              return -1;
            }
        }

      // *** Set Priority (use reasonable default priorities)
#     if defined(ACE_HAS_PTHREADS)
      // If we wish to explicitly set a scheduling policy, we also
      // have to specify a priority.  We choose a "middle" priority as
      // default.  Maybe this is also necessary on other POSIX'ish
      // implementations?
      if ((ACE_BIT_ENABLED (flags, THR_SCHED_FIFO)
           || ACE_BIT_ENABLED (flags, THR_SCHED_RR)
           || ACE_BIT_ENABLED (flags, THR_SCHED_DEFAULT))
          && priority == ACE_DEFAULT_THREAD_PRIORITY)
        {
          if (ACE_BIT_ENABLED (flags, THR_SCHED_FIFO))
            priority = ACE_THR_PRI_FIFO_DEF;
          else if (ACE_BIT_ENABLED (flags, THR_SCHED_RR))
            priority = ACE_THR_PRI_RR_DEF;
          else // THR_SCHED_DEFAULT
            priority = ACE_THR_PRI_OTHER_DEF;
        }
#     endif /* ACE_HAS_PTHREADS */
      if (priority != ACE_DEFAULT_THREAD_PRIORITY)
        {
          struct sched_param sparam;
          ACE_OS::memset ((void *) &sparam, 0, sizeof sparam);

#     if defined (PTHREAD_MAX_PRIORITY) && !defined(ACE_HAS_PTHREADS)
          /* For MIT pthreads... */
          sparam.prio = ACE_MIN (priority, PTHREAD_MAX_PRIORITY);
#     elif defined(ACE_HAS_PTHREADS) && !defined (ACE_HAS_STHREADS)
          // The following code forces priority into range.
          if (ACE_BIT_ENABLED (flags, THR_SCHED_FIFO))
            sparam.sched_priority =
              ACE_MIN (ACE_THR_PRI_FIFO_MAX,
                       ACE_MAX (ACE_THR_PRI_FIFO_MIN, priority));
          else if (ACE_BIT_ENABLED(flags, THR_SCHED_RR))
            sparam.sched_priority =
              ACE_MIN (ACE_THR_PRI_RR_MAX,
                       ACE_MAX (ACE_THR_PRI_RR_MIN, priority));
          else // Default policy, whether set or not
            sparam.sched_priority =
              ACE_MIN (ACE_THR_PRI_OTHER_MAX,
                       ACE_MAX (ACE_THR_PRI_OTHER_MIN, priority));
#     elif defined (PRIORITY_MAX)
          sparam.sched_priority = ACE_MIN (priority,
                                           (long) PRIORITY_MAX);
#     else
          sparam.sched_priority = priority;
#     endif /*  PTHREAD_MAX_PRIORITY */

          {
#       if defined (sun)  &&  defined (ACE_HAS_ONLY_SCHED_OTHER)
            // SunOS, through 5.6, POSIX only allows priorities > 0 to
            // ::pthread_attr_setschedparam.  If a priority of 0 was
            // requested, set the thread priority after creating it, below.
            if (priority > 0)
#       endif /* sun && ACE_HAS_ONLY_SCHED_OTHER */
              {
                (void) ACE_ADAPT_RETVAL(::pthread_attr_setschedparam (&attr, &sparam),
                                        result);
                if (result != 0)
                  {
                    ::pthread_attr_destroy (&attr);
                    return -1;
                  }
              }
          }
        }

#       if !defined (ACE_LACKS_SETINHERITSCHED)
      // *** Set scheduling explicit or inherited
      if (ACE_BIT_ENABLED (flags, THR_INHERIT_SCHED)
          || ACE_BIT_ENABLED (flags, THR_EXPLICIT_SCHED))
        {
          int sched = PTHREAD_EXPLICIT_SCHED;
          if (ACE_BIT_ENABLED (flags, THR_INHERIT_SCHED))
            sched = PTHREAD_INHERIT_SCHED;
          if (ACE_ADAPT_RETVAL(::pthread_attr_setinheritsched (&attr, sched), result) != 0)
            {
              ::pthread_attr_destroy (&attr);
              return -1;
            }
        }
#       endif /* ACE_LACKS_SETINHERITSCHED */
#   else /* ACE_LACKS_SETSCHED */
      ACE_UNUSED_ARG (priority);
#   endif /* ACE_LACKS_SETSCHED */

  // *** Set pthread name
#   if defined (ACE_HAS_PTHREAD_ATTR_SETNAME)
  if (thr_name && *thr_name)
    {
      if (ACE_ADAPT_RETVAL(::pthread_attr_setname (&attr, const_cast<char*>(*thr_name)), result) != 0)
        {
          ::pthread_attr_destroy (&attr);
          return -1;
        }
    }
#else
  ACE_UNUSED_ARG (thr_name);
#   endif

      // *** Set Scope
#   if !defined (ACE_LACKS_THREAD_PROCESS_SCOPING)
      if (ACE_BIT_ENABLED (flags, THR_SCOPE_SYSTEM)
          || ACE_BIT_ENABLED (flags, THR_SCOPE_PROCESS))
        {
#     if defined (ACE_CONFIG_LINUX_H) || defined (HPUX) || defined (ACE_VXWORKS)
          // LinuxThreads do not have support for PTHREAD_SCOPE_PROCESS.
          // Neither does HPUX (up to HP-UX 11.00, as far as I know).
          // Also VxWorks only delivers scope system
          int scope = PTHREAD_SCOPE_SYSTEM;
#     else /* ACE_CONFIG_LINUX_H */
          int scope = PTHREAD_SCOPE_PROCESS;
#     endif /* ACE_CONFIG_LINUX_H */
          if (ACE_BIT_ENABLED (flags, THR_SCOPE_SYSTEM))
            scope = PTHREAD_SCOPE_SYSTEM;

          if (ACE_ADAPT_RETVAL(::pthread_attr_setscope (&attr, scope), result) != 0)
            {
              ::pthread_attr_destroy (&attr);
              return -1;
            }
        }
#   endif /* !ACE_LACKS_THREAD_PROCESS_SCOPING */

#   ifdef ACE_HAS_PTHREAD_ATTR_SETCREATESUSPEND_NP
      if (ACE_BIT_ENABLED (flags, THR_SUSPENDED))
        {
           if (ACE_ADAPT_RETVAL(::pthread_attr_setcreatesuspend_np(&attr), result) != 0)
            {

              ::pthread_attr_destroy (&attr);
              return -1;
            }
        }
#   endif /* !ACE_HAS_PTHREAD_ATTR_SETCREATESUSPEND_NP */

#   if ! defined(ACE_LACKS_THR_CONCURRENCY_FUNCS)
      if (ACE_BIT_ENABLED (flags, THR_NEW_LWP))
        {
          // Increment the number of LWPs by one to emulate the
          // SunOS semantics.
          int lwps = ACE_OS::thr_getconcurrency ();
          if (lwps == -1)
            {
              if (errno == ENOTSUP)
                // Suppress the ENOTSUP because it's harmless.
                errno = 0;
              else
                // This should never happen on SunOS:
                // ::thr_getconcurrency () should always succeed.
                return -1;
            }
          else if (ACE_OS::thr_setconcurrency (lwps + 1) == -1)
            {
              if (errno == ENOTSUP)
                {
                  // Unlikely: ::thr_getconcurrency () is supported
                  // but ::thr_setconcurrency () is not?
                }
              else
                return -1;
            }
        }
#   endif /* ! ACE_LACKS_THR_CONCURRENCY_FUNCS */
    }

  ACE_OSCALL (ACE_ADAPT_RETVAL (::pthread_create (thr_id,
                                                  &attr,
                                                  thread_args->entry_point (),
                                                  thread_args),
                                result),
              int, -1, result);
  ::pthread_attr_destroy (&attr);

  // This is a SunOS or POSIX implementation of pthreads, where we
  // assume that ACE_thread_t and ACE_hthread_t are the same.  If this
  // *isn't* correct on some platform, please let us know.
  if (result != -1)
    *thr_handle = *thr_id;

#   if defined (sun)  &&  defined (ACE_HAS_ONLY_SCHED_OTHER)
  // SunOS prior to 5.7:

  // If the priority is 0, then we might have to set it now because we
  // couldn't set it with ::pthread_attr_setschedparam, as noted
  // above.  This doesn't provide strictly correct behavior, because
  // the thread was created (above) with the priority of its parent.
  // (That applies regardless of the inherit_sched attribute: if it
  // was PTHREAD_INHERIT_SCHED, then it certainly inherited its
  // parent's priority.  If it was PTHREAD_EXPLICIT_SCHED, then "attr"
  // was initialized by the SunOS ::pthread_attr_init () to contain
  // NULL for the priority, which indicated to SunOS ::pthread_create
  // () to inherit the parent priority.)
  if (priority == 0)
    {
      // Check the priority of this thread, which is the parent
      // of the newly created thread.  If it is 0, then the
      // newly created thread will have inherited the priority
      // of 0, so there's no need to explicitly set it.
      struct sched_param sparam;
      int policy = 0;
      ACE_OSCALL (ACE_ADAPT_RETVAL (::pthread_getschedparam (thr_self (),
                                                             &policy,
                                                             &sparam),
                                    result), int,
                  -1, result);

      // The only policy supported by by SunOS, thru version 5.6,
      // is SCHED_OTHER, so that's hard-coded here.
      policy = ACE_SCHED_OTHER;

      if (sparam.sched_priority != 0)
        {
          ACE_OS::memset ((void *) &sparam, 0, sizeof sparam);
          // The memset to 0 sets the priority to 0, so we don't need
          // to explicitly set sparam.sched_priority.

          ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_setschedparam (*thr_id,
                                                                        policy,
                                                                        &sparam),
                                               result),
                             int, -1);
        }
    }

#     if defined (ACE_NEEDS_LWP_PRIO_SET)
#       if 0
  // It would be useful if we could make this work.  But, it requires
  // a mechanism for determining the ID of an LWP to which another
  // thread is bound.  Is there a way to do that?  Instead, just rely
  // on the code in ACE_Thread_Adapter::invoke () to set the LWP
  // priority.

  // If the thread is bound, then set the priority on its LWP.
  if (ACE_BIT_ENABLED (flags, THR_BOUND))
    {
      ACE_Sched_Params sched_params (ACE_BIT_ENABLED (flags, THR_SCHED_FIFO) ||
                                     ACE_BIT_ENABLED (flags, THR_SCHED_RR)  ?
                                     ACE_SCHED_FIFO  :
                                     ACE_SCHED_OTHER,
                                     priority);
      result = ACE_OS::lwp_setparams (sched_params,
                                      /* ? How do we find the ID of the LWP
                                         to which *thr_id is bound? */);
    }
#       endif /* 0 */
#     endif /* ACE_NEEDS_LWP_PRIO_SET */

#   endif /* sun && ACE_HAS_ONLY_SCHED_OTHER */
  auto_thread_args.release ();
  return result;
# elif defined (ACE_HAS_STHREADS)
  int result;
  int start_suspended = ACE_BIT_ENABLED (flags, THR_SUSPENDED);

  if (priority != ACE_DEFAULT_THREAD_PRIORITY)
    // If we need to set the priority, then we need to start the
    // thread in a suspended mode.
    ACE_SET_BITS (flags, THR_SUSPENDED);

  ACE_OSCALL (ACE_ADAPT_RETVAL (::thr_create (stack, stacksize,
                                              thread_args->entry_point (),
                                              thread_args,
                                              flags, thr_id), result),
              int, -1, result);

  if (result != -1)
    {
      // With SunOS threads, ACE_thread_t and ACE_hthread_t are the same.
      *thr_handle = *thr_id;

      if (priority != ACE_DEFAULT_THREAD_PRIORITY)
        {
          // Set the priority of the new thread and then let it
          // continue, but only if the user didn't start it suspended
          // in the first place!
          result = ACE_OS::thr_setprio (*thr_id, priority);
          if (result != 0)
            {
              errno = result;
              return -1;
            }

          if (start_suspended == 0)
            {
              result = ACE_OS::thr_continue (*thr_id);
              if (result != 0)
                {
                  errno = result;
                  return -1;
                }
            }
        }
    }
  auto_thread_args.release ();
  return result;
# elif defined (ACE_HAS_WTHREADS)
  ACE_UNUSED_ARG (thr_name);
  ACE_UNUSED_ARG (stack);
#   if defined (ACE_HAS_MFC) && (ACE_HAS_MFC != 0)
  if (ACE_BIT_ENABLED (flags, THR_USE_AFX))
    {
      CWinThread *cwin_thread =
        ::AfxBeginThread ((AFX_THREADPROC) thread_args->entry_point (),
                          thread_args,
                          priority,
                          0,
                          flags | THR_SUSPENDED);
      // Have to duplicate the handle because
      // CWinThread::~CWinThread() closes the original handle.
#     if !defined (ACE_HAS_WINCE)
      (void) ::DuplicateHandle (::GetCurrentProcess (),
                                cwin_thread->m_hThread,
                                ::GetCurrentProcess (),
                                thr_handle,
                                0,
                                TRUE,
                                DUPLICATE_SAME_ACCESS);
#     endif /* ! ACE_HAS_WINCE */
      *thr_id = cwin_thread->m_nThreadID;

      if (ACE_BIT_ENABLED (flags, THR_SUSPENDED) == 0)
        cwin_thread->ResumeThread ();
      // cwin_thread will be deleted in AfxThreadExit()
      // Warning: If AfxThreadExit() is called from within the
      // thread, ACE_TSS_Cleanup->thread_exit() never gets called !
    }
  else
#   endif /* ACE_HAS_MFC */
    {
      int start_suspended = ACE_BIT_ENABLED (flags, THR_SUSPENDED);

      if (priority != ACE_DEFAULT_THREAD_PRIORITY)
        // If we need to set the priority, then we need to start the
        // thread in a suspended mode.
        ACE_SET_BITS (flags, THR_SUSPENDED);

      *thr_handle = (void *) ACE_BEGINTHREADEX (0,
                                                static_cast <u_int> (stacksize),
                                                thread_args->entry_point (),
                                                thread_args,
                                                flags,
                                                thr_id);

      if (priority != ACE_DEFAULT_THREAD_PRIORITY && *thr_handle != 0)
        {
          // Set the priority of the new thread and then let it
          // continue, but only if the user didn't start it suspended
          // in the first place!
          if (ACE_OS::thr_setprio (*thr_handle, priority) != 0)
            {
              return -1;
            }

          if (start_suspended == 0)
            {
              ACE_OS::thr_continue (*thr_handle);
            }
        }
    }
#   if 0
  *thr_handle = ::CreateThread
    (0,
     stacksize,
     LPTHREAD_START_ROUTINE (thread_args->entry_point ()),
     thread_args,
     flags,
     thr_id);
#   endif /* 0 */

  // Close down the handle if no one wants to use it.
  if (thr_handle == &tmp_handle && tmp_handle != 0)
    ::CloseHandle (tmp_handle);

  if (*thr_handle != 0)
    {
      auto_thread_args.release ();
      return 0;
    }
  else
    ACE_FAIL_RETURN (-1);
  /* NOTREACHED */

# elif defined (ACE_VXWORKS)
  // The hard-coded values below are what ::sp () would use.  (::sp ()
  // hardcodes priority to 100, flags to VX_FP_TASK, and stacksize to
  // 20,000.)  stacksize should be an even integer.  If a stack is not
  // specified, ::taskSpawn () is used so that we can set the
  // priority, flags, and stacksize.  If a stack is specified,
  // ::taskInit ()/::taskActivate() are used.

  // If called with thr_create() defaults, use same default values as ::sp ():
  if (priority == ACE_DEFAULT_THREAD_PRIORITY) priority = 100;
  // Assumes that there is a floating point coprocessor.  As noted
  // above, ::sp () hardcodes this, so we should be safe with it.
  if (flags == 0) flags = VX_FP_TASK;
  if (stacksize == 0) stacksize = 20000;

  ACE_thread_t tid;
#   if 0 /* Don't support setting of stack, because it doesn't seem to work. */
  if (stack == 0)
    {
#   else
      ACE_UNUSED_ARG (stack);
#   endif /* 0 */
      // The call below to ::taskSpawn () causes VxWorks to assign a
      // unique task name of the form: "t" + an integer, because the
      // first argument is 0.
      tid = ::taskSpawn (thr_name && *thr_name ? const_cast <char*> (*thr_name) : 0,
                         priority,
                         (int) flags,
                         (int) stacksize,
                         thread_args->entry_point (),
                         (int) thread_args,
                         0, 0, 0, 0, 0, 0, 0, 0, 0);
#   if 0 /* Don't support setting of stack, because it doesn't seem to work. */
    }
  else
    {
      // If a task name (thr_id) was not supplied, then the task will
      // not have a unique name.  That's VxWorks' behavior.

      // Carve out a TCB at the beginning of the stack space.  The TCB
      // occupies 400 bytes with VxWorks 5.3.1/I386.
      WIND_TCB *tcb = (WIND_TCB *) stack;

      // The TID is defined to be the address of the TCB.
      int status = ::taskInit (tcb,
                               thr_name && *thr_name ? const_cast <char*>(*thr_name) : 0,
                               priority,
                               (int) flags,
                               (char *) stack + sizeof (WIND_TCB),
                               (int) (stacksize - sizeof (WIND_TCB)),
                               thread_args->entry_point (),
                               (int) thread_args,
                               0, 0, 0, 0, 0, 0, 0, 0, 0);

      if (status == OK)
        {
          // The task was successfully initialized, now activate it.
          status = ::taskActivate ((ACE_hthread_t) tcb);
        }

      tid = status == OK  ? (ACE_thread_t) tcb  :  ERROR;
    }
#   endif /* 0 */

  if (tid == ERROR)
    return -1;
  else
    {
      if (thr_id)
        *thr_id = tid;

      if (thr_handle)
        *thr_handle = tid;

      if (thr_name && !(*thr_name))
        *thr_name = ::taskName (tid);

      auto_thread_args.release ();
      return 0;
    }

# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (func);
  ACE_UNUSED_ARG (args);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (thr_handle);
  ACE_UNUSED_ARG (priority);
  ACE_UNUSED_ARG (stack);
  ACE_UNUSED_ARG (stacksize);
  ACE_UNUSED_ARG (thr_name);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

void
ACE_OS::thr_exit (ACE_THR_FUNC_RETURN status)
{
  ACE_OS_TRACE ("ACE_OS::thr_exit");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
    ::pthread_exit (status);
# elif defined (ACE_HAS_STHREADS)
    ::thr_exit (status);
# elif defined (ACE_HAS_WTHREADS)
    // Can't call it here because on NT, the thread is exited
    // directly by ACE_Thread_Adapter::invoke ().
    //   ACE_TSS_Cleanup::instance ()->thread_exit (status);

#   if defined (ACE_HAS_MFC) && (ACE_HAS_MFC != 0)
    int using_afx = -1;
    // An ACE_Thread_Descriptor really is an ACE_OS_Thread_Descriptor.
    // But without #including ace/Thread_Manager.h, we don't know that.
    ACE_OS_Thread_Descriptor *td =
      ACE_Base_Thread_Adapter::thr_desc_log_msg ();
    if (td)
      using_afx = ACE_BIT_ENABLED (td->flags (), THR_USE_AFX);
#   endif /* ACE_HAS_MFC && (ACE_HAS_MFC != 0) */

    // Call TSS destructors.
    ACE_OS::cleanup_tss (0 /* not main thread */);

    // Exit the thread.
    // Allow CWinThread-destructor to be invoked from AfxEndThread.
    // _endthreadex will be called from AfxEndThread so don't exit the
    // thread now if we are running an MFC thread.
#   if defined (ACE_HAS_MFC) && (ACE_HAS_MFC != 0)
    if (using_afx != -1)
      {
        if (using_afx)
          ::AfxEndThread (status);
        else
          ACE_ENDTHREADEX (status);
      }
    else
      {
        // Not spawned by ACE_Thread_Manager, use the old buggy
        // version.  You should seriously consider using
        // ACE_Thread_Manager to spawn threads.  The following code is
        // know to cause some problem.
        CWinThread *pThread = ::AfxGetThread ();
        if (!pThread || pThread->m_nThreadID != ACE_OS::thr_self ())
          ACE_ENDTHREADEX (status);
        else
          ::AfxEndThread (status);
      }
#   else
    ACE_ENDTHREADEX (status);
#   endif /* ACE_HAS_MFC && ACE_HAS_MFS != 0*/

# elif defined (ACE_HAS_VXTHREADS)
    ACE_thread_t tid = ACE_OS::thr_self ();
    *((int *) status) = ::taskDelete (tid);
# endif /* ACE_HAS_PTHREADS */
#else
  ACE_UNUSED_ARG (status);
#endif /* ACE_HAS_THREADS */
}

#if defined (ACE_HAS_VXTHREADS)
// Leave this in the global scope to allow
// users to adjust the delay value.
int ACE_THR_JOIN_DELAY = 5;

int
ACE_OS::thr_join (ACE_hthread_t thr_handle,
                  ACE_THR_FUNC_RETURN *status)
{
  // We can't get the status of the thread
  if (status != 0)
    {
      *status = 0;
    }

  // This method can not support joining all threads
  if (ACE_OS::thr_cmp (thr_handle, ACE_OS::NULL_hthread))
    {
      ACE_NOTSUP_RETURN (-1);
    }

  int retval = ESRCH;
  ACE_thread_t current = ACE_OS::thr_self ();

  // Make sure we are not joining ourself
  if (ACE_OS::thr_cmp (thr_handle, current))
    {
      retval = EDEADLK;
    }
  else
    {
      // Whether the task exists or not
      // we will return a successful value
      retval = 0;

      // Verify that the task id still exists
      while (taskIdVerify (thr_handle) == OK)
        {
          // Wait a bit to see if the task is still active.
          ACE_OS::sleep (ACE_THR_JOIN_DELAY);
        }
    }

  // Adapt the return value into errno and return value.
  // The ACE_ADAPT_RETVAL macro doesn't exactly do what
  // we need to do here, so we do it manually.
  if (retval != 0)
    {
      errno = retval;
      retval = -1;
    }

  return retval;
}

int
ACE_OS::thr_join (ACE_thread_t waiter_id,
                  ACE_thread_t *thr_id,
                  ACE_THR_FUNC_RETURN *status)
{
  thr_id = 0;
  return ACE_OS::thr_join (waiter_id, status);
}
#endif /* ACE_HAS_VXTHREADS */

int
ACE_OS::thr_key_detach (ACE_thread_key_t key)
{
#if defined (ACE_HAS_WTHREADS) || defined (ACE_HAS_TSS_EMULATION)
  TSS_Cleanup_Instance cleanup;
  if (cleanup.valid ())
    {
      return cleanup->thread_detach_key (key);
    }
  else
    {
      return -1;
    }
#else
  ACE_UNUSED_ARG (key);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_WTHREADS || ACE_HAS_TSS_EMULATION */
}

int
ACE_OS::thr_get_affinity (ACE_hthread_t thr_id,
                          size_t cpu_set_size,
                          cpu_set_t * cpu_mask)
{
#if defined (ACE_HAS_PTHREAD_GETAFFINITY_NP)
  // Handle of the thread, which is NPTL thread-id, normally a big number
  if (::pthread_getaffinity_np (thr_id, cpu_set_size, cpu_mask) != 0)
    {
      return -1;
    }
  return 0;
#elif defined (ACE_HAS_2_PARAM_SCHED_GETAFFINITY)
  // The process-id is expected as <thr_id>, which can be a thread-id of
  // linux-thread, thus making binding to cpu of that particular thread only.
  // If you are using this flag for NPTL-threads, however, please pass as a
  // thr_id process id obtained by ACE_OS::getpid ()
  ACE_UNUSED_ARG (cpu_set_size);
  if (::sched_getaffinity(thr_id, cpu_mask) == -1)
    {
      return -1;
    }
  return 0;
#elif defined (ACE_HAS_SCHED_GETAFFINITY)
  // The process-id is expected as <thr_id>, which can be a thread-id of
  // linux-thread, thus making binding to cpu of that particular thread only.
  // If you are using this flag for NPTL-threads, however, please pass as a
  // thr_id process id obtained by ACE_OS::getpid ()
  if (::sched_getaffinity(thr_id, cpu_set_size, cpu_mask) == -1)
    {
      return -1;
    }
  return 0;
#elif defined (ACE_HAS_TASKCPUAFFINITYSET)
  ACE_UNUSED_ARG (cpu_set_size);
  int result = 0;
  if (ACE_ADAPT_RETVAL (::taskCpuAffinitySet (thr_id, *cpu_mask), result) == -1)
    {
      return -1;
    }
  return 0;
#else
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (cpu_set_size);
  ACE_UNUSED_ARG (cpu_mask);
  ACE_NOTSUP_RETURN (-1);
#endif
}

int
ACE_OS::thr_set_affinity (ACE_hthread_t thr_id,
                          size_t cpu_set_size,
                          const cpu_set_t * cpu_mask)
{
#if defined (ACE_HAS_PTHREAD_SETAFFINITY_NP)
  if (::pthread_setaffinity_np (thr_id, cpu_set_size, cpu_mask) != 0)
    {
      return -1;
    }
  return 0;
#elif defined (ACE_HAS_2_PARAM_SCHED_SETAFFINITY)
  // The process-id is expected as <thr_id>, which can be a thread-id of
  // linux-thread, thus making binding to cpu of that particular thread only.
  // If you are using this flag for NPTL-threads, however, please pass as a
  // thr_id process id obtained by ACE_OS::getpid (), but whole process will bind your CPUs
  //
  ACE_UNUSED_ARG (cpu_set_size);
  if (::sched_setaffinity (thr_id, cpu_mask) == -1)
    {
      return -1;
    }
  return 0;
#elif defined (ACE_HAS_SCHED_SETAFFINITY)
  // The process-id is expected as <thr_id>, which can be a thread-id of
  // linux-thread, thus making binding to cpu of that particular thread only.
  // If you are using this flag for NPTL-threads, however, please pass as a
  // thr_id process id obtained by ACE_OS::getpid (), but whole process will bind your CPUs
  //
  if (::sched_setaffinity (thr_id, cpu_set_size, cpu_mask) == -1)
    {
      return -1;
    }
  return 0;
#elif defined (ACE_HAS_TASKCPUAFFINITYSET)
  int result = 0;
  if (ACE_ADAPT_RETVAL (::taskCpuAffinitySet (thr_id, *cpu_mask), result) == -1)
    {
      return -1;
    }
  return 0;
#else
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (cpu_set_size);
  ACE_UNUSED_ARG (cpu_mask);
  ACE_NOTSUP_RETURN (-1);
#endif
}

int
ACE_OS::thr_key_used (ACE_thread_key_t key)
{
#if defined (ACE_WIN32) || defined (ACE_HAS_TSS_EMULATION)
  TSS_Cleanup_Instance cleanup;
  if (cleanup.valid ())
    {
      cleanup->thread_use_key (key);
      return 0;
    }
  return -1;
#else
  ACE_UNUSED_ARG (key);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 || ACE_HAS_TSS_EMULATION */
}

#if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
int
ACE_OS::thr_keycreate_native (ACE_OS_thread_key_t *key,
# if defined (ACE_HAS_THR_C_DEST)
                       ACE_THR_C_DEST dest
# else
                       ACE_THR_DEST dest
# endif /* ACE_HAS_THR_C_DEST */
                       )
{
  // can't trace here. Trace uses TSS
  // ACE_OS_TRACE ("ACE_OS::thr_keycreate_native");
# if defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_PTHREADS)
    int result;
    ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_key_create (key, dest),
                                         result),
                       int, -1);
#   elif defined (ACE_HAS_STHREADS)
    int result;
    ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_keycreate (key, dest),
                                         result),
                       int, -1);
#   elif defined (ACE_HAS_WTHREADS)
    ACE_UNUSED_ARG (dest);
    *key = ::TlsAlloc ();

    if (*key == ACE_SYSCALL_FAILED)
      ACE_FAIL_RETURN (-1);
    return 0;
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (dest);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}
#endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */

int
ACE_OS::thr_keycreate (ACE_thread_key_t *key,
# if defined (ACE_HAS_THR_C_DEST)
                       ACE_THR_C_DEST dest)
# else
                       ACE_THR_DEST dest)
# endif /* ACE_HAS_THR_C_DEST */
{
  // ACE_OS_TRACE ("ACE_OS::thr_keycreate");
#if defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_TSS_EMULATION)
    if (ACE_TSS_Emulation::next_key (*key) == 0)
      {
        ACE_TSS_Emulation::tss_destructor (*key, dest);

        // Extract out the thread-specific table instance and stash away
        // the key and destructor so that we can free it up later on...
        TSS_Cleanup_Instance cleanup (TSS_Cleanup_Instance::CREATE);
        if (cleanup.valid ())
          {
            return cleanup->insert (*key, dest);
          }
        else
          {
            return -1;
          }
      }
    else
      return -1;
#   elif defined (ACE_HAS_WTHREADS)
    if (ACE_OS::thr_keycreate_native (key, dest) == 0)
      {
        // Extract out the thread-specific table instance and stash away
        // the key and destructor so that we can free it up later on...
        TSS_Cleanup_Instance cleanup (TSS_Cleanup_Instance::CREATE);
        if (cleanup.valid ())
          {
            return cleanup->insert (*key, dest);
          }
        else
          {
            return -1;
          }
      }
    else
      return -1;
      /* NOTREACHED */
#   elif defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
    return  ACE_OS::thr_keycreate_native (key, dest);
#   else
    ACE_UNUSED_ARG (key);
    ACE_UNUSED_ARG (dest);
    ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_TSS_EMULATION */
# else /* ACE_HAS_THREADS */
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (dest);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}

#if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
int
ACE_OS::thr_keyfree_native (ACE_OS_thread_key_t key)
{
  ACE_OS_TRACE ("ACE_OS::thr_keyfree_native");
# if defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_BROKEN_THREAD_KEYFREE) || defined (ACE_HAS_THR_KEYDELETE)
    // For some systems, e.g. LynxOS, we need to ensure that
    // any registered thread destructor action for this slot
    // is now disabled. Otherwise in the event of a dynamic library
    // unload of libACE, by a program not linked with libACE,
    // ACE_TSS_cleanup will be invoked again at the thread exit
    // after libACE has been actually been unmapped from memory.
    (void) ACE_OS::thr_setspecific (key, 0);
#   endif /* ACE_HAS_BROKEN_THREAD_KEYFREE */
#   if defined (ACE_HAS_PTHREADS)
    return ::pthread_key_delete (key);
#   elif defined (ACE_HAS_THR_KEYDELETE)
    return ::thr_keydelete (key);
#   elif defined (ACE_HAS_STHREADS)
    ACE_UNUSED_ARG (key);
    ACE_NOTSUP_RETURN (-1);
#   elif defined (ACE_HAS_WTHREADS)
    ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::TlsFree (key), ace_result_), int, -1);
#   else
    ACE_UNUSED_ARG (key);
    ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_PTHREADS */
# else
  ACE_UNUSED_ARG (key);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}
#endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */

int
ACE_OS::thr_keyfree (ACE_thread_key_t key)
{
  ACE_OS_TRACE ("ACE_OS::thr_keyfree");
# if defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_TSS_EMULATION)
    // Release the key in the TSS_Emulation administration
    ACE_TSS_Emulation::release_key (key);
    TSS_Cleanup_Instance cleanup;
    if (cleanup.valid ())
      {
        return cleanup->free_key (key);
      }
    return -1;
#   elif defined (ACE_HAS_WTHREADS)
    // Extract out the thread-specific table instance and free up
    // the key and destructor.
    TSS_Cleanup_Instance cleanup;
    if (cleanup.valid ())
      {
        return cleanup->free_key (key);
      }
    return -1;
#   elif defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
    return ACE_OS::thr_keyfree_native (key);
#   else
    ACE_UNUSED_ARG (key);
    ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_TSS_EMULATION */
# else /* ACE_HAS_THREADS */
  ACE_UNUSED_ARG (key);
  ACE_NOTSUP_RETURN (-1);
  return 0;
# endif /* ACE_HAS_THREADS */
}

int
ACE_OS::thr_setprio (const ACE_Sched_Priority prio)
{
  // Set the thread priority on the current thread.
  ACE_hthread_t my_thread_id;
  ACE_OS::thr_self (my_thread_id);

  int const status = ACE_OS::thr_setprio (my_thread_id, prio);

#if defined (ACE_NEEDS_LWP_PRIO_SET)
  // If the thread is in the RT class, then set the priority on its
  // LWP.  (Instead of doing this if the thread is in the RT class, it
  // should be done for all bound threads.  But, there doesn't appear
  // to be an easy way to determine if the thread is bound.)

  if (status == 0)
    {
      // Find what scheduling class the thread's LWP is in.
      ACE_Sched_Params sched_params (ACE_SCHED_OTHER, 0);
      if (ACE_OS::lwp_getparams (sched_params) == -1)
        {
          return -1;
        }
      else if (sched_params.policy () == ACE_SCHED_FIFO  ||
               sched_params.policy () == ACE_SCHED_RR)
        {
          // This thread's LWP is in the RT class, so we need to set
          // its priority.
          sched_params.priority (prio);
          return ACE_OS::lwp_setparams (sched_params);
        }
      // else this is not an RT thread.  Nothing more needs to be
      // done.
    }
#endif /* ACE_NEEDS_LWP_PRIO_SET */

  return status;
}

# if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
int
ACE_OS::thr_setspecific_native (ACE_OS_thread_key_t key, void *data)
{
  // ACE_OS_TRACE ("ACE_OS::thr_setspecific_native");
#   if defined (ACE_HAS_THREADS)
#     if defined (ACE_HAS_PTHREADS)
      int result;
      ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_setspecific (key, data),
                                           result),
                         int, -1);
#     elif defined (ACE_HAS_STHREADS)
      int result;
      ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_setspecific (key, data), result), int, -1);
#     elif defined (ACE_HAS_WTHREADS)
      ::TlsSetValue (key, data);
      return 0;
#     else /* ACE_HAS_STHREADS */
      ACE_UNUSED_ARG (key);
      ACE_UNUSED_ARG (data);
      ACE_NOTSUP_RETURN (-1);
#     endif /* ACE_HAS_STHREADS */
#   else
    ACE_UNUSED_ARG (key);
    ACE_UNUSED_ARG (data);
    ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_THREADS */
}
# endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */

int
ACE_OS::thr_setspecific (ACE_thread_key_t key, void *data)
{
  // ACE_OS_TRACE ("ACE_OS::thr_setspecific");
#if defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_TSS_EMULATION)
    if (ACE_TSS_Emulation::is_key (key) == 0)
      {
        errno = EINVAL;
        data = 0;
        return -1;
      }
    else
      {
        ACE_TSS_Emulation::ts_object (key) = data;
        TSS_Cleanup_Instance cleanup;
        if (cleanup.valid ())
          {
            cleanup->thread_use_key (key);
            // for TSS_Cleanup purposes treat stetting data to zero
            // like detaching.  This is a consequence of POSIX allowing
            // deletion of a "used" key.
            if (data == 0)
              {
                cleanup->thread_detach_key (key);
              }
            return 0;
          }
        else
          {
            return -1;
          }
      }
#   elif defined (ACE_HAS_WTHREADS)
    if (ACE_OS::thr_setspecific_native (key, data) == 0)
      {
        TSS_Cleanup_Instance cleanup;
        if (cleanup.valid ())
          {
            cleanup->thread_use_key (key);
            // for TSS_Cleanup purposes treat stetting data to zero
            // like detaching.  This is a consequence of POSIX allowing
            // deletion of a "used" key.
            if (data == 0)
              {
                cleanup->thread_detach_key (key);
              }
            return 0;
          }
        return -1;
      }
    return -1;
#   elif defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
      return ACE_OS::thr_setspecific_native (key, data);
#   else /* ACE_HAS_TSS_EMULATION */
      ACE_UNUSED_ARG (key);
      ACE_UNUSED_ARG (data);
      ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_TSS_EMULATION */
# else /* ACE_HAS_THREADS */
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (data);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_THREADS */
}

void
ACE_OS::unique_name (const void *object,
                     char *name,
                     size_t length)
{
  // The process ID will provide uniqueness between processes on the
  // same machine. The "this" pointer of the <object> will provide
  // uniqueness between other "live" objects in the same process. The
  // uniqueness of this name is therefore only valid for the life of
  // <object>.
  char temp_name[ACE_UNIQUE_NAME_LEN];
  ACE_OS::sprintf (temp_name,
                   "%p%d",
                   object,
                   static_cast <int> (ACE_OS::getpid ()));
  ACE_OS::strsncpy (name,
                    temp_name,
                    length);
}

#if defined (ACE_USES_WCHAR)
void
ACE_OS::unique_name (const void *object,
                     wchar_t *name,
                     size_t length)
{
  // The process ID will provide uniqueness between processes on the
  // same machine. The "this" pointer of the <object> will provide
  // uniqueness between other "live" objects in the same process. The
  // uniqueness of this name is therefore only valid for the life of
  // <object>.
  wchar_t temp_name[ACE_UNIQUE_NAME_LEN];
  ACE_OS::sprintf (temp_name,
                   ACE_TEXT ("%p%d"),
                   object,
                   static_cast <int> (ACE_OS::getpid ()));
  ACE_OS::strsncpy (name,
                    temp_name,
                    length);
}
#endif

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_VXWORKS) && !defined (__RTP__)
# include /**/ <usrLib.h>   /* for ::sp() */
# include /**/ <sysLib.h>   /* for ::sysClkRateGet() */
# include "ace/Service_Config.h"

// This global function can be used from the VxWorks shell to pass
// arguments to a C main () function.
//
// usage: -> spa main, "arg1", "arg2"
//
// All arguments must be quoted, even numbers.
int
spa (FUNCPTR entry, ...)
{
  static const unsigned int ACE_MAX_ARGS = 10;
  static char *argv[ACE_MAX_ARGS];
  va_list pvar;
  unsigned int argc;

  // Hardcode a program name because the real one isn't available
  // through the VxWorks shell.
  argv[0] = "ace_main";

  // Peel off arguments to spa () and put into argv.  va_arg () isn't
  // necessarily supposed to return 0 when done, though since the
  // VxWorks shell uses a fixed number (10) of arguments, it might 0
  // the unused ones.  This function could be used to increase that
  // limit, but then it couldn't depend on the trailing 0.  So, the
  // number of arguments would have to be passed.
  va_start (pvar, entry);

  for (argc = 1; argc <= ACE_MAX_ARGS; ++argc)
    {
      argv[argc] = va_arg (pvar, char *);

      if (argv[argc] == 0)
        break;
    }

  if (argc > ACE_MAX_ARGS  &&  argv[argc-1] != 0)
    {
      // try to read another arg, and warn user if the limit was exceeded
      if (va_arg (pvar, char *) != 0)
        ACE_OS::fprintf (stderr, "spa(): number of arguments limited to %d\n",
                         ACE_MAX_ARGS);
    }
  else
    {
      // fill unused argv slots with 0 to get rid of leftovers
      // from previous invocations
      for (unsigned int i = argc; i <= ACE_MAX_ARGS; ++i)
        argv[i] = 0;
    }

  // The hard-coded options are what ::sp () uses, except for the
  // larger stack size (instead of ::sp ()'s 20000).
  int const ret = ::taskSpawn (argv[0],    // task name
                               100,        // task priority
                               VX_FP_TASK, // task options
                               ACE_NEEDS_HUGE_THREAD_STACKSIZE, // stack size
                               entry,      // entry point
                               argc,       // first argument to main ()
                               (int) argv, // second argument to main ()
                               0, 0, 0, 0, 0, 0, 0, 0);
  va_end (pvar);

  // ::taskSpawn () returns the taskID on success: return 0 instead if
  // successful
  return ret > 0 ? 0 : ret;
}

// A helper function for the extended spa functions
static void
add_to_argv (int& argc, char** argv, int max_args, char* string)
{
  char indouble   = 0;
  size_t previous = 0;
  size_t length   = ACE_OS::strlen (string);

  if (length > 0)
    {
      // We use <= to make sure that we get the last argument
      for (size_t i = 0; i <= length; i++)
        {
          // Is it a double quote that hasn't been escaped?
          if (string[i] == '\"' && (i == 0 || string[i - 1] != '\\'))
            {
              indouble ^= 1;
              if (indouble)
                {
                  // We have just entered a double quoted string, so
                  // save the starting position of the contents.
                  previous = i + 1;
                }
              else
                {
                  // We have just left a double quoted string, so
                  // zero out the ending double quote.
                  string[i] = '\0';
                }
            }
          else if (string[i] == '\\')  // Escape the next character
            {
              // The next character is automatically skipped because
              // of the memmove().
              ACE_OS::memmove (string + i, string + i + 1, length);
              --length;
            }
          else if (!indouble &&
                   (ACE_OS::ace_isspace (string[i]) || string[i] == '\0'))
            {
              string[i] = '\0';
              if (argc < max_args)
                {
                  argv[argc] = string + previous;
                  ++argc;
                }
              else
                {
                  ACE_OS::fprintf (stderr, "spae(): number of arguments "
                                           "limited to %d\n", max_args);
                }

              // Skip over whitespace in between arguments
              for(++i; i < length && ACE_OS::ace_isspace (string[i]); ++i)
                {
                }

              // Save the starting point for the next time around
              previous = i;

              // Make sure we don't skip over a character due
              // to the above loop to skip over whitespace
              --i;
            }
        }
    }
}

// This global function can be used from the VxWorks shell to pass
// arguments to a C main () function.
//
// usage: -> spae main, "arg1 arg2 \"arg3 with spaces\""
//
// All arguments must be within double quotes, even numbers.
int
spae (FUNCPTR entry, ...)
{
  static int const WINDSH_ARGS = 10;
  static int const ACE_MAX_ARGS    = 128;
  static char* argv[ACE_MAX_ARGS]  = { "ace_main", 0 };
  va_list pvar;
  int argc = 1;

  // Peel off arguments to spa () and put into argv.  va_arg () isn't
  // necessarily supposed to return 0 when done, though since the
  // VxWorks shell uses a fixed number (10) of arguments, it might 0
  // the unused ones.
  va_start (pvar, entry);

  int i = 0;
  for (char* str = va_arg (pvar, char*);
       str != 0 && i < WINDSH_ARGS; str = va_arg (pvar, char*), ++i)
    {
      add_to_argv(argc, argv, ACE_MAX_ARGS, str);
    }

  // fill unused argv slots with 0 to get rid of leftovers
  // from previous invocations
  for (i = argc; i < ACE_MAX_ARGS; ++i)
    argv[i] = 0;

  // The hard-coded options are what ::sp () uses, except for the
  // larger stack size (instead of ::sp ()'s 20000).
  int const ret = ::taskSpawn (argv[0],    // task name
                               100,        // task priority
                               VX_FP_TASK, // task options
                               ACE_NEEDS_HUGE_THREAD_STACKSIZE, // stack size
                               entry,      // entry point
                               argc,       // first argument to main ()
                               (int) argv, // second argument to main ()
                               0, 0, 0, 0, 0, 0, 0, 0);
  va_end (pvar);

  // ::taskSpawn () returns the taskID on success: return 0 instead if
  // successful
  return ret > 0 ? 0 : ret;
}

// This global function can be used from the VxWorks shell to pass
// arguments to a C main () function.  The function will be run
// within the shells task.
//
// usage: -> spaef main, "arg1 arg2 \"arg3 with spaces\""
//
// All arguments must be within double quotes, even numbers.
// Unlike the spae function, this fuction executes the supplied
// routine in the foreground, rather than spawning it in a separate
// task.
int
spaef (FUNCPTR entry, ...)
{
  static int const WINDSH_ARGS = 10;
  static int const ACE_MAX_ARGS    = 128;
  static char* argv[ACE_MAX_ARGS]  = { "ace_main", 0 };
  va_list pvar;
  int argc = 1;

  // Peel off arguments to spa () and put into argv.  va_arg () isn't
  // necessarily supposed to return 0 when done, though since the
  // VxWorks shell uses a fixed number (10) of arguments, it might 0
  // the unused ones.
  va_start (pvar, entry);

  int i = 0;
  for (char* str = va_arg (pvar, char*);
       str != 0 && i < WINDSH_ARGS; str = va_arg (pvar, char*), ++i)
    {
      add_to_argv(argc, argv, ACE_MAX_ARGS, str);
    }

  // fill unused argv slots with 0 to get rid of leftovers
  // from previous invocations
  for (i = argc; i < ACE_MAX_ARGS; ++i)
    argv[i] = 0;

  int ret = entry (argc, argv);

  va_end (pvar);

  // Return the return value of the invoked ace_main routine.
  return ret;
}

// This global function can be used from the VxWorks shell to pass
// arguments to and run a main () function (i.e. ace_main).
//
// usage: -> vx_execae ace_main, "arg1 arg2 \"arg3 with spaces\"", [prio, [opt, [stacksz]]]
//
// All arguments must be within double quotes, even numbers.
// This routine spawns the main () function in a separate task and waits till the
// task has finished.
static int _vx_call_rc = 0;

static int
_vx_call_entry(FUNCPTR entry, int argc, char* argv[])
{
    ACE_Service_Config::current (ACE_Service_Config::global());
    _vx_call_rc = entry (argc, argv);
    return _vx_call_rc;
}

int
vx_execae (FUNCPTR entry, char* arg, int prio, int opt, int stacksz, ...)
{
  static int const ACE_MAX_ARGS    = 128;
  static char* argv[ACE_MAX_ARGS]  = { "ace_main", 0 };
  int argc = 1;

  // Peel off arguments to run_main () and put into argv.
  if (arg)
    {
      add_to_argv(argc, argv, ACE_MAX_ARGS, arg);
    }

  // fill unused argv slots with 0 to get rid of leftovers
  // from previous invocations
  for (int i = argc; i < ACE_MAX_ARGS; ++i)
    argv[i] = 0;

  // The hard-coded options are what ::sp () uses, except for the
  // larger stack size (instead of ::sp ()'s 20000).
  int const ret = ::taskSpawn (argv[0],    // task name
                               prio==0 ? 100 : prio,        // task priority
                               opt==0 ? VX_FP_TASK : opt, // task options
                               stacksz==0 ? ACE_NEEDS_HUGE_THREAD_STACKSIZE : stacksz, // stack size
                               (FUNCPTR)_vx_call_entry, // entrypoint caller
                               (int)entry,              // entry point
                               argc,                    // first argument to main ()
                               (int) argv,              // second argument to main ()
                               0, 0, 0, 0, 0, 0, 0);

  if (ret == ERROR)
    return 255;

  while( ret > 0 && ::taskIdVerify (ret) != ERROR )
    ::taskDelay (3 * ::sysClkRateGet ());

  // ::taskSpawn () returns the taskID on success: return _vx_call_rc instead if
  // successful
  return ret > 0 ? _vx_call_rc : 255;
}

#if defined(ACE_AS_STATIC_LIBS) && defined (ACE_VXWORKS_DEBUGGING_HELPER)
/** Wind River workbench allows the user to spawn a kernel task as a
    "Debug Configuration".  Use this function as the entrypoint so that
    the arguments are translated into the form that ace_main() requires.
 */
int ace_wb_exec (int arg0, int arg1, int arg2, int arg3, int arg4,
                 int arg5, int arg6, int arg7, int arg8, int arg9)
{
  return spaef ((FUNCPTR) ace_main, arg0, arg1, arg2, arg3, arg4,
                arg5, arg6, arg7, arg8, arg9);
}
#endif /* ACE_AS_STATIC_LIBS && ... */

#endif /* ACE_VXWORKS && !__RTP__ */
