// -*- C++ -*-
//=============================================================================
/**
 *  @file    MEM_IO.h
 *
 *  $Id: MEM_IO.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_MEM_IO_H
#define ACE_MEM_IO_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)
#include "ace/SOCK.h"
#include "ace/MEM_SAP.h"
#include "ace/Message_Block.h"
#include "ace/Process_Semaphore.h"
#include "ace/Process_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Export ACE_Reactive_MEM_IO : public ACE_MEM_SAP
{
public:
  ACE_Reactive_MEM_IO (void);
  virtual ~ACE_Reactive_MEM_IO (void);
  /**
   * Initialize the MEM_SAP object.
   *
   * @a options is used to pass in the Malloc_Options to initialize
   * underlying ACE_MMAP.
   */
  virtual int init (ACE_HANDLE handle,
                    const ACE_TCHAR *name,
                    MALLOC_OPTIONS *options);
  /**
   * Fetch location of next available data into <recv_buffer_>.
   * As this operation read the address of the data off the socket
   * using ACE::recv, @a timeout only applies to ACE::recv.
   */
  virtual ssize_t recv_buf (ACE_MEM_SAP_Node *&buf,
                            int flags,
                            const ACE_Time_Value *timeout);
  /**
   * Wait to to @a timeout amount of time to send @a buf.  If <send>
   * times out a -1 is returned with @c errno == ETIME.  If it succeeds
   * the number of bytes sent is returned.  */
  virtual ssize_t send_buf (ACE_MEM_SAP_Node *buf,
                            int flags,
                            const ACE_Time_Value *timeout);
  /**
   * Convert the buffer offset <off> to absolute address to @a buf.
   * Return the size of valid information containing in the @a buf,
   * -1 if <shm_malloc_> is not initialized.
   */
  ssize_t get_buf_len (const ACE_OFF_T off, ACE_MEM_SAP_Node *&buf);
};
#if defined (ACE_WIN32) || !defined (_ACE_USE_SV_SEM)
class ACE_Export ACE_MT_MEM_IO : public ACE_MEM_SAP
{
public:
  typedef struct
  {
    ACE_MEM_SAP_Node::ACE_MEM_SAP_NODE_PTR head_;
    ACE_MEM_SAP_Node::ACE_MEM_SAP_NODE_PTR tail_;
  } MQ_Struct;                  // Structure for a simple queue
  class Simple_Queue
  {
  public:
    Simple_Queue (void);
    Simple_Queue (MQ_Struct *mq);
    int init (MQ_Struct *mq, ACE_MEM_SAP::MALLOC_TYPE *malloc);
    int write (ACE_MEM_SAP_Node *new_msg);
    ACE_MEM_SAP_Node *read (void);
  private:
    MQ_Struct *mq_;
    ACE_MEM_SAP::MALLOC_TYPE *malloc_;
  };
  typedef struct
  {
    ACE_SYNCH_PROCESS_SEMAPHORE *sema_;
    ACE_SYNCH_PROCESS_MUTEX *lock_;
    Simple_Queue queue_;
  } Channel;
  ACE_MT_MEM_IO (void);
  virtual ~ACE_MT_MEM_IO (void);
  /**
   * Initialize the MEM_SAP object.
   */
  virtual int init (ACE_HANDLE handle,
                    const ACE_TCHAR *name,
                    MALLOC_OPTIONS *options);
  /**
   * Fetch location of next available data into <recv_buffer_>.
   * As this operation read the address of the data off the socket
   * using ACE::recv, @a timeout only applies to ACE::recv.
   */
  virtual ssize_t recv_buf (ACE_MEM_SAP_Node *&buf,
                            int flags,
                            const ACE_Time_Value *timeout);
  /**
   * Wait to to @a timeout amount of time to send @a buf.  If <send>
   * times out a -1 is returned with @c errno == ETIME.  If it succeeds
   * the number of bytes sent is returned.  */
  virtual ssize_t send_buf (ACE_MEM_SAP_Node *buf,
                            int flags,
                            const ACE_Time_Value *timeout);
private:
  Channel recv_channel_;
  Channel send_channel_;
};
#endif /* ACE_WIN32 || !_ACE_USE_SV_SEM */
/**
 * @class ACE_MEM_IO
 *
 * @brief Defines the methods for the ACE shared memeory wrapper I/O
 * routines (e.g., send/recv).
 * The shared memory transport uses ACE_SOCK_* class to
 * implement the signaling mechanism so we can easily use the
 * new mechanism with the Reactor pattern (which uses select
 * under the hood.)
 * ACE_MEM_Acceptor and ACE_MEM_Connector are used to establish
 * connections.  When a connection is established,
 * ACE_MEM_Acceptor creates the MMAP file for data exchange and
 * sends the location of the file (complete path name) to
 * ACE_MEM_Connector thru the socket.  ACE_MEM_Connector then
 * reads the location of the file off the socket and opens up
 * the same MMAP file.  ACE_MEM_Stream at each side then
 * contains a reference to the ACE_Mallo object using the same
 * MMAP file.
 * When sending information using methods provided in this
 * class, ACE_MEM_IO requests a chunk of memory from the
 * MALLOC_TYPE object, copy the data into the shared memory and
 * send the memory offset (from the start of the ACE_Malloc)
 * across the socket.  This action also servers as a signal to
 * the other end.  The receiving side then reverses the
 * procedures and copies the information into user buffer.
 */
class ACE_Export ACE_MEM_IO : public ACE_SOCK
{
public:
  // = Initialization and termination methods.
  /// Constructor.
  ACE_MEM_IO (void);
  /// Destructor.
  ~ACE_MEM_IO (void);
  typedef enum
  {
    Reactive,
    MT
  }  Signal_Strategy;
  /**
   * Initialize the MEM_SAP object.
   */
  int init (const ACE_TCHAR *name,
            ACE_MEM_IO::Signal_Strategy type = ACE_MEM_IO::Reactive,
            ACE_MEM_SAP::MALLOC_OPTIONS *options = 0);
  /**
   * Finalizing the MEM_IO object.  This method doesn't invoke
   * the <remove> method.
   */
  int fini (void);
  /// Send an @a n byte buffer to the other process using shm_malloc_
  /// connected thru the socket.
  ssize_t send (const void *buf,
                size_t n,
                int flags) ;
  /// Recv an @a n byte buffer from the shm_malloc_ thru connected socket.
  ssize_t recv (void *buf,
                size_t n,
                int flags) ;
  /// Send an @a n byte buffer to the other process using shm_malloc_
  /// connected thru the socket.
  ssize_t send (const void *buf,
                size_t n) ;
  /// Recv an @a n byte buffer from the shm_malloc_ thru connected socket.
  ssize_t recv (void *buf,
                size_t n) ;
  /**
   * Wait to to @a timeout amount of time to send up to @a n bytes into
   * @a buf from <handle> (uses the <send> call).  If <send> times out
   * a -1 is returned with @c errno == ETIME.  If it succeeds the
   * number of bytes sent is returned.
   */
  ssize_t send (const void *buf,
                size_t n,
                const ACE_Time_Value *timeout);
  /**
   * Wait to to @a timeout amount of time to send up to @a n bytes into
   * @a buf from <handle> (uses the <send> call).  If <send> times out
   * a -1 is returned with @c errno == ETIME.  If it succeeds the
   * number of bytes sent is returned.
   */
  ssize_t send (const void *buf,
                size_t n,
                int flags,
                const ACE_Time_Value *timeout);
  /**
   * Wait to to @a timeout amount of time to send the @a message_block.
   * If <send> times out a -1 is returned with @c errno == ETIME.  If
   * it succeeds the number of bytes sent is returned.
   */
  ssize_t send (const ACE_Message_Block *message_block,
                const ACE_Time_Value *timeout);
  /**
   * Wait up to @a timeout amount of time to receive up to @a n bytes
   * into @a buf from <handle> (uses the <recv> call).  If <recv> times
   * out a -1 is returned with @c errno == ETIME.  If it succeeds the
   * number of bytes received is returned.
   */
  ssize_t recv (void *buf,
                size_t n,
                const ACE_Time_Value *timeout);
  /**
   * Wait up to @a timeout amount of time to receive up to @a n bytes
   * into @a buf from <handle> (uses the <recv> call).  If <recv> times
   * out a -1 is returned with @c errno == ETIME.  If it succeeds the
   * number of bytes received is returned.
   */
  ssize_t recv (void *buf,
                size_t n,
                int flags,
                const ACE_Time_Value *timeout);

  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
  /// Return the local endpoint port number.  Returns 0 if successful,
  /// else -1.
  /*  int get_local_port (u_short &) const;
  /// Return the port number of the remotely connected peer (if there
  /// is one). Returns 0 if successful, else -1.
  int get_remote_port (u_short &) const;
  */
private:
  ssize_t fetch_recv_buf (int flag, const ACE_Time_Value *timeout);
  /// Actual deliverying mechanism.
  ACE_MEM_SAP *deliver_strategy_;
  /// Internal pointer for support recv/send.
  ACE_MEM_SAP_Node *recv_buffer_;
  /// Record the current total buffer size of <recv_buffer_>.
  ssize_t buf_size_;
  /// Record the current read pointer location in <recv_buffer_>.
  ssize_t cur_offset_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/MEM_IO.inl"
#endif /* __ACE_INLINE__ */
#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */
#include /**/ "ace/post.h"
#endif /* ACE_SOCK_IO_H */

