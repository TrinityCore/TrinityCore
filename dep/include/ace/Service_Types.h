// -*- C++ -*-

//==========================================================================
/**
 *  @file    Service_Types.h
 *
 *  $Id: Service_Types.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_SERVICE_TYPE_H
#define ACE_SERVICE_TYPE_H

#include /**/ "ace/pre.h"

#include "ace/Service_Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Service_Type_Impl
 *
 * @brief The abstract base class of the hierarchy that defines the
 * contents of the ACE_Service_Repository.  The subclasses of
 * this class allow the configuration of ACE_Service_Objects,
 * ACE_Modules, and ACE_Streams.
 *
 * This class provides the root of the implementation hierarchy
 * of the "Bridge" pattern.  It maintains a pointer to the
 * appropriate type of service implementation, i.e.,
 * ACE_Service_Object, ACE_Module, or ACE_Stream.
 */
class ACE_Export ACE_Service_Type_Impl
{
public:
  // = Initialization and termination methods.
  ACE_Service_Type_Impl (void *object,
                         const ACE_TCHAR *s_name,
                         u_int flags = 0,
                         ACE_Service_Object_Exterminator gobbler = 0);
  virtual ~ACE_Service_Type_Impl (void);

  // = Pure virtual interface (must be defined by the subclass).
  virtual int suspend (void) const = 0;
  virtual int resume (void) const = 0;
  virtual int init (int argc, ACE_TCHAR *argv[]) const = 0;
  virtual int fini (void) const;
  virtual int info (ACE_TCHAR **str, size_t len) const = 0;

  /// The pointer to the service.
  void *object (void) const;

  /// Get the name of the service.
  const ACE_TCHAR *name (void) const;

  /// Set the name of the service.
  void name (const ACE_TCHAR *);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Name of the service.
  const ACE_TCHAR *name_;

  /// Pointer to object that implements the service.  This actually
  /// points to an ACE_Service_Object, ACE_Module, or ACE_Stream.
  void *obj_;

  /// Destroy function to deallocate obj_.
  ACE_Service_Object_Exterminator gobbler_;

  /// Flags that control serivce behavior (particularly deletion).
  u_int flags_;
};

/**
 * @class ACE_Service_Object_Type
 *
 * @brief Define the methods for handling the configuration of
 * ACE_Service_Objects.
 */
class ACE_Export ACE_Service_Object_Type : public ACE_Service_Type_Impl
{
public:
  // = Initialization method.
  ACE_Service_Object_Type (void *so,
                           const ACE_TCHAR *name,
                           u_int flags = 0,
                           ACE_Service_Object_Exterminator gobbler = 0);

  ~ACE_Service_Object_Type (void);

  // = Implement the hooks for <ACE_Service_Objects>.
  virtual int suspend (void) const;
  virtual int resume (void) const;
  virtual int init (int argc, ACE_TCHAR *argv[]) const;
  virtual int fini (void) const;
  virtual int info (ACE_TCHAR **str, size_t len) const;

private:
  /// Holds the initialization status (result of object->init())
  mutable int initialized_;
};

/**
 * @class ACE_Module_Type
 *
 * @brief Define the methods for handling the configuration of
 * ACE_Modules.
 */
class ACE_Export ACE_Module_Type : public ACE_Service_Type_Impl
{
public:
  // = Initialization method.
  ACE_Module_Type (void *m, // Really an ACE_Module *.
                   const ACE_TCHAR *identifier,
                   u_int flags = 0);

  ~ACE_Module_Type (void);

  // = Implement the hooks for <ACE_Modules>.
  virtual int suspend (void) const;
  virtual int resume (void) const;
  virtual int init (int argc, ACE_TCHAR *argv[]) const;
  virtual int fini (void) const;
  virtual int info (ACE_TCHAR **str, size_t len) const;

  /// Get the link pointer.
  ACE_Module_Type *link (void) const;

  /// Set the link pointer.
  void link (ACE_Module_Type *);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to the next ACE_Module_Type in an ACE_Stream_Type.
  ACE_Module_Type *link_;
};

/**
 * @class ACE_Stream_Type
 *
 * @brief Define the methods for handling the configuration of
 * ACE_Streams.
 */
class ACE_Export ACE_Stream_Type : public ACE_Service_Type_Impl
{
public:
  // = Initialization method.
  ACE_Stream_Type (void *s, // Really an ACE_Stream *.
                   const ACE_TCHAR *identifier,
                   u_int flags = 0);

  ~ACE_Stream_Type (void);

  // = Implement the hooks for <ACE_Streams>.
  virtual int suspend (void) const;
  virtual int resume (void) const;
  virtual int init (int argc, ACE_TCHAR *argv[]) const;
  virtual int fini (void) const;
  virtual int info (ACE_TCHAR **str, size_t len) const;

  /// Add a new  ACE_Module to the top of the ACE_Stream.
  int push (ACE_Module_Type *new_module);

  /// Search for @a module and remove it from the ACE_Stream.
  int remove (ACE_Module_Type *module);

  /// Locate the ACE_Module with @a mod_name.
  ACE_Module_Type *find (const ACE_TCHAR *mod_name) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to the head of the ACE_Module list.
  ACE_Module_Type *head_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Service_Types.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* _SERVICE_TYPE_H */

