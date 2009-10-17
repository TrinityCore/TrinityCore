/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Message_Block_T.h
 *
 *  $Id: Message_Block_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Carlos O'Ryan <coryan@atdesk.com>
 */
//=============================================================================
#ifndef ACE_MESSAGE_BLOCK_T_H
#define ACE_MESSAGE_BLOCK_T_H
#include /**/ "ace/pre.h"
#include "ace/Message_Block.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Locked_Data_Block
 *
 * @brief A Data_Block with a concrete locking strategy.
 *
 * Data_Blocks can be parametric on the kind of lock they use; in
 * many cases the lifetime of the lock is tied to the lifetime of
 * the Data_Block itself. But since Data_Blocks are reference
 * counted it is hard for users to control the lock lifetime.
 * This class is parametric over the kind of lock used.
 */
template <class ACE_LOCK>
class ACE_Locked_Data_Block : public ACE_Data_Block
{
public:
  // = Initialization and termination methods.
  /// Default "do-nothing" constructor.
  ACE_Locked_Data_Block (void);
  /// Initialize.
  ACE_Locked_Data_Block (size_t size,
                         ACE_Message_Block::ACE_Message_Type msg_type,
                         const char *msg_data,
                         ACE_Allocator *allocator_strategy,
                         ACE_Message_Block::Message_Flags flags,
                         ACE_Allocator *data_block_allocator);
  /// Delete all the resources held in the message.
  virtual ~ACE_Locked_Data_Block (void);
  /**
   * Return an exact "deep copy" of the message, the dynamic type is
   * ACE_Locked_Data_Block<>
   * See the documentation in Message_Block.h for details.
   */
  virtual ACE_Data_Block *clone_nocopy (ACE_Message_Block::Message_Flags mask = 0,
                                        size_t max_size = 0) const;
private:
  /// The lock
  ACE_LOCK lock_;
  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (ACE_Locked_Data_Block<ACE_LOCK> &operator= (const ACE_Locked_Data_Block<ACE_LOCK> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Locked_Data_Block (const ACE_Locked_Data_Block<ACE_LOCK> &))
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Message_Block_T.inl"
#endif /* __ACE_INLINE__ */
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Message_Block_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Message_Block_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_MESSAGE_BLOCK_T_H */

