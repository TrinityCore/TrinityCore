/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Service_Object.h
 *
 *  $Id: Service_Object.h 81388 2008-04-23 14:02:05Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SERVICE_OBJECT_H
#define ACE_SERVICE_OBJECT_H
#include /**/ "ace/pre.h"

#include "ace/Shared_Object.h"
#include "ace/Svc_Conf_Tokens.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Event_Handler.h"
#include "ace/DLL.h"

#include "ace/Service_Gestalt.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#define ACE_Component ACE_Service_Object

/**
 * @class ACE_Service_Object
 *
 * @brief Provide the abstract base class common to all service
 * implementations.
 *
 * Classes that inherit from ACE_Service_Objects are capable
 * of being registered with the ACE_Reactor (due to the
 * ACE_Event_Handler, as well as being dynamically linked by
 * the ACE_Service_Config (due to the ACE_Shared_Object).
 */
class ACE_Export ACE_Service_Object
  : public ACE_Event_Handler,
    public ACE_Shared_Object
{
public:
  // = Initialization and termination methods.
  /// Constructor.
  ACE_Service_Object (ACE_Reactor * = 0);

  /// Destructor.
  virtual ~ACE_Service_Object (void);

    /// Temporarily disable a service without removing it completely.
  virtual int suspend (void);

    /// Re-enable a previously suspended service.
  virtual int resume (void);
};

// Forward decl.
class ACE_Service_Type_Impl;

/**
 * @class ACE_Service_Type
 *
 * @brief Keeps track of information related to the various
 * ACE_Service_Type_Impl subclasses.
 *
 * This class acts as the interface of the "Bridge" pattern.
 */
class ACE_Export ACE_Service_Type
{
public:
  enum
  {
    /// Delete the payload object.
    DELETE_OBJ = 1,

    /// Delete the enclosing object.
    DELETE_THIS = 2
  };

  enum
    {
      SERVICE_OBJECT = ACE_SVC_OBJ_T,
      MODULE = ACE_MODULE_T,
      STREAM = ACE_STREAM_T,
      INVALID_TYPE = -1
    };

  // = Initialization and termination methods.
  ACE_Service_Type (const ACE_TCHAR *n,
                    ACE_Service_Type_Impl *o,
                    const ACE_DLL &dll,
                    bool active);
  ACE_Service_Type (const ACE_TCHAR *n,
                    ACE_Service_Type_Impl *o,
                    ACE_SHLIB_HANDLE handle,
                    bool active);
  ~ACE_Service_Type (void);

  const ACE_TCHAR *name (void) const;
  void name (const ACE_TCHAR *);

  const ACE_Service_Type_Impl *type (void) const;
  void type (const ACE_Service_Type_Impl *, bool active = true);

  /// Is this just a stub for the real thing?
  bool is_forward_declaration (void) const;

  int suspend (void) const;
  int resume (void) const;
  bool active (void) const;
  void active (bool turnon);

  /// Calls <fini> on <type_>
  int fini (void);

  /// Check if the service has been fini'ed.
  bool fini_called (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Get to the DLL's implentation
  const ACE_DLL & dll (void) const;

  /// Sets the DLL
  void dll (const ACE_DLL&);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Humanly readible name of svc.
  const ACE_TCHAR *name_;

  /// Pointer to C++ object that implements the svc.
  const ACE_Service_Type_Impl *type_;

  /// ACE_DLL representing the shared object file (non-zero if
  /// dynamically linked).
  mutable ACE_DLL dll_;

  /// true if svc is currently active, otherwise false.
  bool active_;

  /// true if <fini> on <type_> has already been called, otherwise false.
  bool fini_already_called_;
};

/**
 * @class ACE_Service_Object_Ptr
 *
 * @brief This is a smart pointer that holds onto the associated
 * ACE_Service_Object * until the current scope is left, at
 * which point the object's <fini> hook is called and the
 * service_object_ gets deleted.
 *
 * This class is similar to the Standard C++ Library class
 * <auto_ptr>.  It is used in conjunction with statically linked
 * <ACE_Service_Objects>, as shown in the
 * ./netsvcs/server/main.cpp example.
 */
class ACE_Export ACE_Service_Object_Ptr
{
public:
  // = Initialization and termination methods.
  /// Acquire ownership of the @a so.
  ACE_Service_Object_Ptr (ACE_Service_Object *so);

  /// Release the held ACE_Service_Object by calling its <fini> hook.
  ~ACE_Service_Object_Ptr (void);

  /// Smart pointer to access the underlying ACE_Service_Object.
  ACE_Service_Object *operator-> ();

private:
  /// Holds the service object until we're done.
  ACE_Service_Object *service_object_;
};

#if defined (ACE_OPENVMS)
/**
 * @class ACE_Dynamic_Svc_Registrar
 *
 * @brief Used to register Service allocator function by its full name.
 */
class ACE_Dynamic_Svc_Registrar
{
public:
  ACE_Dynamic_Svc_Registrar (const ACE_TCHAR* alloc_name,
                             void* svc_allocator);
};
#endif

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Service_Object.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SERVICE_OBJECT_H */

