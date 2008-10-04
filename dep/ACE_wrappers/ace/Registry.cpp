// $Id: Registry.cpp 82435 2008-07-28 11:53:42Z johnnyw $

#include "ace/Registry.h"

ACE_RCSID (ace,
           Registry,
           "$Id: Registry.cpp 82435 2008-07-28 11:53:42Z johnnyw $")

#if defined (ACE_WIN32) && !defined (ACE_LACKS_WIN32_REGISTRY)

#  include "ace/os_include/os_netdb.h"
#  include "ace/OS_NS_unistd.h"

// Funky macro to deal with strange error passing semantics
// of Win32 Reg*() functions
#define ACE_REGISTRY_CALL_RETURN(X) \
  do { \
    if (X != ERROR_SUCCESS) \
    { \
      errno = X; \
      return -1; \
    } \
    else \
      return 0; \
    } while (0)


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_TCHAR const ACE_Registry::STRING_SEPARATOR[] = ACE_TEXT ("\\");

bool
ACE_Registry::Name_Component::operator== (const Name_Component &rhs) const
{
  return
    rhs.id_ == this->id_ &&
    rhs.kind_ == this->kind_;
}

bool
ACE_Registry::Name_Component::operator!= (const Name_Component &rhs) const
{
  return !this->operator== (rhs);
}

// Simple binding constructor
ACE_Registry::Binding::Binding ()
  : name_ (),
    type_ (INVALID)
{
}


// Binding constructor
// (Name version)
ACE_Registry::Binding::Binding (const Name &name,
                                Binding_Type type)
  : name_ (ACE_Registry::make_string (name)),
    type_ (type)
{
}


// Binding constructor
// (String version)
ACE_Registry::Binding::Binding (const ACE_TString &name,
                                Binding_Type type)
  : name_ (name),
    type_ (type)
{
}


bool
ACE_Registry::Binding::operator== (const Binding &rhs) const
{
  return
    rhs.name_ == this->name_ &&
    rhs.type_ == this->type_;
}

bool
ACE_Registry::Binding::operator!= (const Binding &rhs) const
{
  return !this->operator== (rhs);
}

// Name accessor
// (Name version)
void
ACE_Registry::Binding::name (Name &name)
{
  name = ACE_Registry::make_name (this->name_);
}


// Name accessors
// (String version)
void
ACE_Registry::Binding::name (ACE_TString &name)
{
  name = this->name_;
}


// Name accessors
// (String version)
ACE_TString
ACE_Registry::Binding::name (void)
{
  return this->name_;
}


// Type accessor
ACE_Registry::Binding_Type
ACE_Registry::Binding::type (void)
{
  return this->type_;
}


// Simple object constructor
ACE_Registry::Object::Object (void *data,
                              u_long size,
                              u_long type)
  : data_ (data),
    size_ (size),
    type_ (type)
{
}

// Object accessors and set methods
void
ACE_Registry::Object::data (void *data)
{
  this->data_ = data;
}


void *
ACE_Registry::Object::data (void) const
{
  return this->data_;
}


void
ACE_Registry::Object::size (u_long size)
{
  this->size_ = size;
}


u_long
ACE_Registry::Object::size (void) const
{
  return this->size_;
}


void
ACE_Registry::Object::type (u_long type)
{
  this->type_ = type;
}


u_long
ACE_Registry::Object::type (void) const
{
  return this->type_;
}


// Simple context constructor
ACE_Registry::Naming_Context::Naming_Context (void)
  : key_ ((HKEY) 0),
    parent_key_ ((HKEY) 0),
    name_ ()
{
}


// Context constructor
ACE_Registry::Naming_Context::Naming_Context (const HKEY &key)
  : key_ (key),
    parent_key_ ((HKEY) 0),
    name_ ()
{
}


ACE_Registry::Naming_Context::Naming_Context (const Naming_Context &rhs)
  : key_ (rhs.key_),
    parent_key_ (rhs.parent_key_),
    name_ (rhs.name_)
{
  // This is incorrect.
  // Rather than copying key, we should call ::DuplicateHandle()
  // But since this is private (and not used), I don't care much
}


const ACE_Registry::Naming_Context &
ACE_Registry::Naming_Context::operator= (const Naming_Context &rhs)
{
        ACE_UNUSED_ARG(rhs);

        // Not implemented
        return *this;
}


// Destructor
ACE_Registry::Naming_Context::~Naming_Context ()
{
  this->close ();
}


// Insert <object> with <name> into <this> context
// (Name version)
int
ACE_Registry::Naming_Context::bind_new (const Name &name,
                                        const Object &object)
{
  return this->bind_new (ACE_Registry::make_string (name), object);
}


// Insert <object> with <name> into <this> context
// (String version)
int
ACE_Registry::Naming_Context::bind_new (const ACE_TString &name,
                                        const Object &object)
{
  // temporary object
  Object temp;
  long result = this->resolve (name, temp);
  if (result == 0)
    // resolve succeeded
    result = -1;
  else
    // resolve failed
    result = this->bind (name, object);
  return result;
}


// Insert or update <object> with <name> into <this> context
// (Name version)
int
ACE_Registry::Naming_Context::bind (const Name &name,
                                    const Object &object)
{
  return this->bind (ACE_Registry::make_string (name), object);
}


// Insert or update <object> with <name> into <this> context
// (String version)
int
ACE_Registry::Naming_Context::bind (const ACE_TString &name,
                                    const Object &object)
{
  long result = ACE_TEXT_RegSetValueEx (this->key_,
                                        name.c_str (),
                                        0,
                                        object.type (),
                                        (const BYTE *) object.data (),
                                        object.size ());
  ACE_REGISTRY_CALL_RETURN (result);
}


// Update <object> with <name> in <this> context
// (Name version)
int
ACE_Registry::Naming_Context::rebind (const Name &name,
                                      const Object &new_object)
{
  return this->rebind (ACE_Registry::make_string (name), new_object);
}


// Update <object> with <name> in <this> context
// (String version)
int
ACE_Registry::Naming_Context::rebind (const ACE_TString &name,
                                      const Object &new_object)
{
  Object old_object;
  // find the old one first
  long result = this->resolve (name, old_object);
  if (result == 0)
    // no need to delete first
    result = this->bind (name, new_object);
  return result;
}


// Find <object> with <name> in <this> context
// (Name version)
int
ACE_Registry::Naming_Context::resolve (const Name &name,
                                       Object &object)
{
  return this->resolve (ACE_Registry::make_string (name), object);
}


// Find <object> with <name> in <this> context
// (String version)
int
ACE_Registry::Naming_Context::resolve (const ACE_TString &name,
                                       Object &object)
{
  // Get object state
  u_long type;
  void *data = object.data ();
  u_long size = object.size ();

  long result = ACE_TEXT_RegQueryValueEx (this->key_,
                                          name.c_str (),
                                          0,
                                          &type,
                                          (BYTE *)data,
                                          &size);
  if (result == ERROR_SUCCESS)
    {
      // Reset object state
      // No need to set object.data()
      object.type (type);
      object.size (size);
    }

  ACE_REGISTRY_CALL_RETURN (result);
}


// Remove object with <name> in <this> context
// (Name version)
int
ACE_Registry::Naming_Context::unbind (const Name &name)
{
  return this->unbind (ACE_Registry::make_string (name));
}


// Remove object with <name> in <this> context
// (String version)
int
ACE_Registry::Naming_Context::unbind (const ACE_TString &name)
{
  long result = ACE_TEXT_RegDeleteValue (this->key_,
                                         name.c_str ());

  ACE_REGISTRY_CALL_RETURN (result);
}


// Create new <naming_context> relative to <this> context
// This method may not mean a lot in this implementation
int
ACE_Registry::Naming_Context::new_context (Naming_Context &naming_context)
{
  // Make sure that we reset the state and close keys
  return naming_context.close ();
}


// Insert <naming_context> with <name> relative to <this> context
// (Name version)
int
ACE_Registry::Naming_Context::bind_new_context (const Name &name,
                                                Naming_Context &naming_context,
                                                u_long persistence,
                                                u_long security_access,
                                                LPSECURITY_ATTRIBUTES security_attributes)
{
  return this->bind_new_context (ACE_Registry::make_string (name),
                                 naming_context,
                                 persistence,
                                 security_access,
                                 security_attributes);
}


// Insert <naming_context> with <name> relative to <this> context
// (String version)
int
ACE_Registry::Naming_Context::bind_new_context (const ACE_TString &name,
                                                Naming_Context &naming_context,
                                                u_long persistence,
                                                u_long security_access,
                                                LPSECURITY_ATTRIBUTES security_attributes)
{
  u_long reason;

  long result = ACE_TEXT_RegCreateKeyEx (this->key_,
                                         name.c_str (),
                                         0,
                                         0,
                                         persistence,
                                         security_access,
                                         security_attributes,
                                         &naming_context.key_,
                                         &reason);
  if (result == ERROR_SUCCESS)
    // If create succeeds
    {
      if (reason == REG_CREATED_NEW_KEY)
        // If new key: success
        {
          // Set the correct parent
          naming_context.parent (this->key_);
          // Set the correct name
          naming_context.name (name);
        }
      else
        // reason == REG_OPENED_EXISTING_KEY
        // Failed to make new key
        {
          // reset result to failure
          result = -1;
          // Close the key first
          ::RegCloseKey (naming_context.key_);
          // Reset key
          naming_context.key_ = (HKEY) 0;
        }
    }

  ACE_REGISTRY_CALL_RETURN (result);
}


// Insert or update <naming_context> with <name> relative to <this> context
// (Name version)
int
ACE_Registry::Naming_Context::bind_context (const Name &name,
                                            /* const */ Naming_Context &naming_context,
                                            u_long persistence,
                                            u_long security_access,
                                            LPSECURITY_ATTRIBUTES security_attributes)
{
  return this->bind_context (ACE_Registry::make_string (name),
                             naming_context,
                             persistence,
                             security_access,
                             security_attributes);
}


// Insert or update <naming_context> with <name> relative to <this> context
// (String version)
int
ACE_Registry::Naming_Context::bind_context (const ACE_TString &name,
                                            /* const */ Naming_Context &naming_context,
                                            u_long persistence,
                                            u_long security_access,
                                            LPSECURITY_ATTRIBUTES security_attributes)
{
  u_long reason;

  long result = ACE_TEXT_RegCreateKeyEx (this->key_,
                                         name.c_str (),
                                         0,
                                         0,
                                         persistence,
                                         security_access,
                                         security_attributes,
                                         &naming_context.key_,
                                         &reason);
  if (result == ERROR_SUCCESS)
    {
      // Set the correct parent
      naming_context.parent (this->key_);
      // Set the correct name
      naming_context.name (name);
    }

  ACE_REGISTRY_CALL_RETURN (result);
}


// Rename <naming_context> to <name>
// (Name version)
int
ACE_Registry::Naming_Context::rebind_context (const Name &name,
                                              /* const */ Naming_Context &new_naming_context)
{
  return this->rebind_context (ACE_Registry::make_string (name),
                               new_naming_context);
}


// Rename <naming_context> to <name>
// (String version)
int
ACE_Registry::Naming_Context::rebind_context (const ACE_TString &name,
                                              /* const */ Naming_Context &new_naming_context)
{
  Naming_Context old_naming_context;
  // find the old one first
  long result = this->resolve_context (name,
                                       old_naming_context);
  if (result == 0)
    {
      // naming_context is found: delete entry
      result = this->unbind_context (name);
      if (result == 0)
        {
          // successful deletion; rebind
          // beware of race conditions here
          // (lets resolve this later)
          result = this->bind_new_context (name, new_naming_context);
        }
    }
  return result;
}


// Remove naming_context with <name> from <this> context
// (Name version)
int
ACE_Registry::Naming_Context::unbind_context (const Name &name)
{
  return this->unbind_context (ACE_Registry::make_string (name));
}


// Remove naming_context with <name> from <this> context
// (String version)
int
ACE_Registry::Naming_Context::unbind_context (const ACE_TString &name)
{
  long result = ACE_TEXT_RegDeleteKey (this->key_,
                                                       name.c_str ());

  ACE_REGISTRY_CALL_RETURN (result);
}


// Find <naming_context> with <name> in <this> context
// (Name version)
int
ACE_Registry::Naming_Context::resolve_context (const Name &name,
                                               Naming_Context &naming_context,
                                               u_long security_access)
{
  return this->resolve_context (ACE_Registry::make_string (name),
                                naming_context,
                                security_access);
}


// Find <naming_context> with <name> in <this> context
// (String version)
int
ACE_Registry::Naming_Context::resolve_context (const ACE_TString &name,
                                               Naming_Context &naming_context,
                                               u_long security_access)
{
  long result = ACE_TEXT_RegOpenKeyEx (this->key_,
                                       name.c_str (),
                                       0,
                                       security_access,
                                       &naming_context.key_);
  if (result == ERROR_SUCCESS)
    {
      // set the correct parent
      naming_context.parent (this->key_);
      // set the correct name
      naming_context.name (name);
    }

  ACE_REGISTRY_CALL_RETURN (result);
}


// Same as unbind_context() with <this> as naming_context
int
ACE_Registry::Naming_Context::destroy (void)
{
  // hopefully the parent_key_ is still open
  long result = ACE_TEXT_RegDeleteKey (this->parent_key_,
                                                       this->name_.c_str ());

  ACE_REGISTRY_CALL_RETURN (result);
}


// Sync content of context to disk
int
ACE_Registry::Naming_Context::flush (void)
{
  long result = ::RegFlushKey (this->key_);
  ACE_REGISTRY_CALL_RETURN (result);
}


// Close the handle of the context
int
ACE_Registry::Naming_Context::close (void)
{
  long result = this->key_ ? ::RegCloseKey (this->key_) : ERROR_SUCCESS;
  ACE_REGISTRY_CALL_RETURN (result);
}


// Convert a <name> to a <string>
ACE_TString
ACE_Registry::make_string (const Name &const_name)
{
  ACE_TString string;
  Name &name = const_cast<Name &> (const_name);

  // Iterator through the components of name
  for (Name::iterator iterator = name.begin ();
       iterator != name.end ();
       iterator++)
    {
      if (iterator != name.begin ())
        // If this is not the first component, we will add separators
        string += STRING_SEPARATOR;
      const Name_Component &component = *iterator;
      // Add to string
      string += component.id_;
    }

  return string;
}


// Convert a <string> to a <name>
ACE_Registry::Name
ACE_Registry::make_name (const ACE_TString &string)
{
  ACE_TString::size_type new_position = 0;
  ACE_TString::size_type last_position = 0;
  Name name;

  // Rememeber: NPOS is -1
  while (new_position != ACE_TString::npos)
    {
      Name_Component component;
      // Find the separator
      new_position = string.find (STRING_SEPARATOR, new_position);
      if (new_position != ACE_TString::npos)
        // If we have not gone past the end
        {
          // Get the substring
          component.id_ = string.substr (last_position,
                                         new_position - last_position);
          // Skip past the seperator
          new_position +=
            ACE_OS::strlen (STRING_SEPARATOR);
        }
      else
        {
          // Get the last substring
          component.id_ = string.substr (last_position);
        }
      // Update positions
      last_position = new_position;
      // Insert component into name
      name.insert (component);
    }

  return name;
}


// Set key
void
ACE_Registry::Naming_Context::key (HKEY key)
{
  this->key_ = key;
}


// Get key
HKEY
ACE_Registry::Naming_Context::key (void)
{
  return this->key_;
}


// Set parent
void
ACE_Registry::Naming_Context::parent (HKEY parent)
{
  this->parent_key_ = parent;
}


// Get parent
HKEY
ACE_Registry::Naming_Context::parent (void)
{
  return this->parent_key_;
}


// Set name
// (Name version)
void
ACE_Registry::Naming_Context::name (const Name &name)
{
  this->name_ = ACE_Registry::make_string (name);
}


// Get name
// (Name version)
void
ACE_Registry::Naming_Context::name (Name &name)
{
  name = ACE_Registry::make_name (this->name_);
}


// Set name
// (String version)
void
ACE_Registry::Naming_Context::name (const ACE_TString &name)
{
  this->name_ = name;
}


// Get name
// (String version)
ACE_TString
ACE_Registry::Naming_Context::name (void)
{
  return this->name_;
}


// Get name
// (String version)
void
ACE_Registry::Naming_Context::name (ACE_TString &name)
{
  name = this->name_;
}

// Empty list
static const ACE_Registry::Binding_List ace_binding_empty_list;

// listing function: iterator creator
// This is useful when there are many objects and contexts
// in <this> context and you only want to look at a few entries
// at a time
int
ACE_Registry::Naming_Context::list (u_long how_many,
                                    Binding_List &list,
                                    Binding_Iterator &iter)
{
  // Make sure that the list is empty
  list = ace_binding_empty_list;

  // Correctly initalize the iterator
  iter.reset ();

  // Make sure that the iterator uses <this> naming context
  iter.naming_context (*this);

  // Start iterations from the objects
  iter.current_enumeration (iter.object_iteration_);

  // Get the next <how_many> values
  return iter.next_n (how_many, list);
}


// listing function: iterator creator
// This gives back a listing of all entries in <this> context.
int
ACE_Registry::Naming_Context::list (Binding_List &list)
{
  // Make sure that the list is empty
  list = ace_binding_empty_list;

  // Create an iterator
  ACE_Registry::Binding_Iterator iterator;

  // Make sure that the iterator uses <this> naming context
  iterator.naming_context (*this);

  // Start iterations from the objects
  iterator.current_enumeration (iterator.object_iteration_);

  long result = 0;
  while (1)
    {
      ACE_Registry::Binding binding;
      result = iterator.next_one (binding);
      if (result == 0)
        list.insert (binding);
      else
        break;
    }
  return 0;
}


// Default constructor
ACE_Registry::Binding_Iterator::Binding_Iterator ()
{
  this->object_iteration_.iterator (this);
  this->context_iteration_.iterator (this);
  this->iteration_complete_.iterator (this);
  this->reset ();
}


void
ACE_Registry::Binding_Iterator::reset ()
{
  this->current_enumeration_ = &this->iteration_complete_;
  this->iteration_complete_.reset ();
  this->object_iteration_.reset ();
  this->context_iteration_.reset ();
}


void
ACE_Registry::Binding_Iterator::Iteration_State::reset ()
{
  this->index_ = 0;
}


void
ACE_Registry::Binding_Iterator::Iteration_State::iterator (Binding_Iterator *iter)
{
  this->parent_ = iter;
}


ACE_Registry::Binding_Iterator::Iteration_State::Iteration_State ()
  : index_ (0)
{
}


// Next entry
int
ACE_Registry::Binding_Iterator::next_one (Binding &binding)
{
  u_long how_many = 1;
  Binding_List list;

  // Get next n (where n is one)
  long result = this->next_n (how_many, list);

  if (result == 0)
    // Success
    binding = (*list.begin ());

  return result;
}


// Next <how_many> entries
int
ACE_Registry::Binding_Iterator::next_n (u_long how_many,
                                        Binding_List &list)
{
  // Make sure that the list is empty
  list = ace_binding_empty_list;

  return this->current_enumeration_->next_n (how_many, list);
}


// Destroy iterator
int
ACE_Registry::Binding_Iterator::destroy (void)
{
  this->reset ();
  return 0;
}


// Set/Get naming_context
void
ACE_Registry::Binding_Iterator::naming_context (Naming_Context &naming_context)
{
  this->naming_context_ = &naming_context;
}


ACE_Registry::Naming_Context &
ACE_Registry::Binding_Iterator::naming_context (void)
{
  return *this->naming_context_;
}


// Set/Get current enumeration
void
ACE_Registry::Binding_Iterator::current_enumeration (Iteration_State &current_enumeration)
{
  this->current_enumeration_ = &current_enumeration;
}


ACE_Registry::Binding_Iterator::Iteration_State &
ACE_Registry::Binding_Iterator::current_enumeration (void)
{
  return *this->current_enumeration_;
}


int
ACE_Registry::Binding_Iterator::Object_Iteration::next_n (u_long how_many,
                                                          Binding_List &list)
{
  // Make a copy
  u_long requested = how_many;

  // While there are more entries to be added to the list
  while (how_many > 0)
    {
      ACE_TCHAR string [ACE_Registry::Naming_Context::MAX_OBJECT_NAME_SIZE];
      u_long size = sizeof string / sizeof (ACE_TCHAR);
      long result = ACE_TEXT_RegEnumValue (this->parent_->naming_context ().key (),
                                           this->index_,
                                           string,
                                           &size,
                                           0,
                                           0,
                                           0,
                                           0);
      switch (result)
        {
        case ERROR_SUCCESS:
          // Object found
          {
            // Readjust counters
            this->index_++;
            how_many--;

            // Add to list
            // Create binding
            Binding binding (string, OBJECT);
            // Add to binding list
            list.insert (binding);
          }
        // Continue to add to list
        break;

        case ERROR_NO_MORE_ITEMS:
          // Enumeration of objects complete
          // Reset index
          this->index_ = 0;

          // Current enumeration will become CONTEXTS
          this->parent_->current_enumeration (this->parent_->context_iteration_);
          result = this->parent_->current_enumeration ().next_n (how_many,
                                                                 list);
          // If we were able to add objects
          if (requested != how_many)
            return 0;
          else
            return result;

        default:
          // Strange error
          // Reset index
          this->index_ = 0;
          // Current enumeration will become COMPLETE
          this->parent_->current_enumeration (this->parent_->iteration_complete_);
          // strange error
          return -1;
        }
    }
  // If we reach here, all of <how_many> pairs were added to the list
  // Since more entries may be available
  // current enumeration will remain OBJECTS
  return 0;
}


int
ACE_Registry::Binding_Iterator::Context_Iteration::next_n (u_long how_many,
                                                           Binding_List &list)
{
  // Make a copy
  u_long requested = how_many;

  // While there are more entries to be added to the list
  while (how_many > 0)
    {
      ACE_TCHAR string [ACE_Registry::Naming_Context::MAX_CONTEXT_NAME_SIZE];
      u_long size = sizeof string / sizeof (ACE_TCHAR);
      long result = ACE_TEXT_RegEnumKeyEx (this->parent_->naming_context (). key (),
                                           this->index_,
                                           string,
                                           &size,
                                           0,
                                           0,
                                           0,
                                           0);
      switch (result)
        {
        case ERROR_SUCCESS:
          // Object found
          {
            // Readjust counters
            this->index_++;
            how_many--;

            // Add to list
            // Create binding
            Binding binding (string, CONTEXT);
            // Add to binding list
            list.insert (binding);
          }
        // Continue to add to list
        break;

        case ERROR_NO_MORE_ITEMS:
          // Enumeration of objects complete

          /* FALL THROUGH */

        default:
          // Strange error

          // Reset index
          this->index_ = 0;
          // Current enumeration will become CONTEXTS
          this->parent_->current_enumeration (this->parent_->iteration_complete_);

          // If we were able to add contexts
          if (requested != how_many)
            return 0;
          else
            return -1;
        }
    }
  // If we reach here, all of <how_many> pairs were added to the list
  // Since more entries may be available
  // current enumeration will remain CONTEXTS
  return 0;
}


int
ACE_Registry::Binding_Iterator::Iteration_Complete::next_n (u_long how_many,
                                                            Binding_List &list)
{
        ACE_UNUSED_ARG(list);
        ACE_UNUSED_ARG(how_many);

        // No more values
        return -1;
}


// Factory method to connect to predefined registries
// This method works for both remote and local machines
// However, for remote machines CLASSES_ROOT and CURRENT_USER
// types are not allowed
/* static */
int
ACE_Predefined_Naming_Contexts::connect (ACE_Registry::Naming_Context &naming_context,
                                         HKEY predefined,
                                         const ACE_TCHAR *machine_name)
{
#if defined (ACE_HAS_WINCE)
  return -1;
#else
  long result = -1;

  if (machine_name != 0 && ACE_OS::strcmp (ACE_TEXT ("localhost"), machine_name) == 0)
    machine_name = 0;

  if (predefined == HKEY_LOCAL_MACHINE || predefined == HKEY_USERS)
    result =
      ACE_TEXT_RegConnectRegistry (const_cast<ACE_TCHAR *> (machine_name),
                                   predefined,
                                   &naming_context.key_);
  if (predefined == HKEY_CURRENT_USER || predefined == HKEY_CLASSES_ROOT)
    // Make sure that for these types, the machine is local
    if (machine_name == 0 ||
        ACE_Predefined_Naming_Contexts::is_local_host (machine_name))
      {
        naming_context.key_ = predefined;
        result = 0;
      }
    else
      result = -1;

  ACE_REGISTRY_CALL_RETURN (result);
#endif  // ACE_HAS_WINCE
}

// Check if <machine_name> is the local host
/* static */
int
ACE_Predefined_Naming_Contexts::is_local_host (const ACE_TCHAR *machine_name)
{
  ACE_TCHAR local_host[MAXHOSTNAMELEN];
  int result = ACE_OS::hostname (local_host, sizeof local_host / sizeof (ACE_TCHAR));
  if (result == 0)
    result = !ACE_OS::strcmp (local_host, machine_name);
  else
    result = 0;
  return result;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_WIN32 && !ACE_LACKS_WIN32_REGISTRY */
