#include "ace/Parse_Node.h"

#if (ACE_USES_CLASSIC_SVC_CONF == 1)

#include "ace/Service_Config.h"
#include "ace/Service_Repository.h"
#include "ace/Service_Types.h"
#include "ace/Task.h"
#include "ace/DLL.h"
#include "ace/ACE.h"
#include "ace/OS_NS_string.h"
#include "ace/ARGV.h"

ACE_RCSID (ace,
           Parse_Node,
           "$Id: Parse_Node.cpp 81245 2008-04-05 13:37:47Z johnnyw $")


  ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_Stream_Node)

// Provide the class hierarchy that defines the parse tree of Service
// Nodes.

  void
ACE_Stream_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Stream_Node::dump");
#endif /* ACE_HAS_DUMP */
}

void
ACE_Stream_Node::apply (ACE_Service_Gestalt *config, int &yyerrno)
{
  ACE_TRACE ("ACE_Stream_Node::apply");

  const ACE_Service_Type *sst = this->node_->record (config);
  if (sst == 0)
    const_cast<ACE_Static_Node *> (this->node_)->apply (config, yyerrno);

  if (yyerrno != 0) return;

  sst = this->node_->record (config);
  ACE_Stream_Type *st =
      dynamic_cast<ACE_Stream_Type *> (const_cast<ACE_Service_Type_Impl *> (sst->type ()));

  for (const ACE_Static_Node *module = dynamic_cast<const ACE_Static_Node*> (this->mods_);
       module != 0;
       module = dynamic_cast<ACE_Static_Node*> (module->link()))
    {
      ACE_ARGV args (module->parameters ());

      const ACE_Service_Type *mst = module->record (config);
      if (mst == 0)
        const_cast<ACE_Static_Node *> (module)->apply (config, yyerrno);

      if (yyerrno != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("dynamic initialization failed for Module %s\n"),
                      module->name ()));
          ++yyerrno;
        }

      ACE_Module_Type const * const mt1 =
        static_cast <ACE_Module_Type const *> (module->record (config)->type());

      ACE_Module_Type *mt = const_cast<ACE_Module_Type *>(mt1);

      if (st->push (mt) == -1)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("dynamic initialization failed for Stream %s\n"),
                      this->node_->name ()));
          ++yyerrno;
        }

    }

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) Did stream on %s, error = %d\n"),
                this->node_->name (),
                yyerrno));
#endif /* ACE_NLOGGING */
}

ACE_ALLOC_HOOK_DEFINE (ACE_Parse_Node)

  void
ACE_Parse_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Parse_Node::dump");
#endif /* ACE_HAS_DUMP */
}

const ACE_TCHAR *
ACE_Parse_Node::name (void) const
{
  ACE_TRACE ("ACE_Parse_Node::name");
  return this->name_;
}

ACE_Parse_Node *
ACE_Parse_Node::link (void) const
{
  ACE_TRACE ("ACE_Parse_Node::link");
  return this->next_;
}

void
ACE_Parse_Node::link (ACE_Parse_Node *n)
{
  ACE_TRACE ("ACE_Parse_Node::link");

  // Find the last list entry (if any) ...
  ACE_Parse_Node *t = this;
  while (t->next_ != 0)
      t = t->next_;

  // ... and insert n there.
  t->next_ = n;
}

ACE_Stream_Node::ACE_Stream_Node (const ACE_Static_Node *str_ops,
                                  const ACE_Parse_Node *str_mods)
    : ACE_Parse_Node ((str_ops == 0 ? ACE_TEXT ("<unknown>") : str_ops->name ())),
      node_ (str_ops),
      mods_ (str_mods)
{
  ACE_TRACE ("ACE_Stream_Node::ACE_Stream_Node");
}


ACE_Stream_Node::~ACE_Stream_Node (void)
{
  ACE_TRACE ("ACE_Stream_Node::~ACE_Stream_Node");
  ACE_Static_Node *n = const_cast<ACE_Static_Node *> (this->node_);
  delete n;
  ACE_Parse_Node *m = const_cast<ACE_Parse_Node *> (this->mods_);
  delete m;
}

ACE_Parse_Node::ACE_Parse_Node (void)
  : name_ (0),
    next_ (0)
{
  ACE_TRACE ("ACE_Parse_Node::ACE_Parse_Node");
}


ACE_Parse_Node::ACE_Parse_Node (const ACE_TCHAR *nm)
  : name_ (ACE::strnew (nm)),
    next_ (0)
{
  ACE_TRACE ("ACE_Parse_Node::ACE_Parse_Node");
}

void
ACE_Parse_Node::print (void) const
{
  ACE_TRACE ("ACE_Parse_Node::print");

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("svc = %s\n"),
              this->name ()));

  if (this->next_)
    this->next_->print ();
}


ACE_Parse_Node::~ACE_Parse_Node (void)
{
  ACE_TRACE ("ACE_Parse_Node::~ACE_Parse_Node");
  delete[] const_cast<ACE_TCHAR*> (this->name_);
  delete this->next_;
}

ACE_ALLOC_HOOK_DEFINE (ACE_Suspend_Node)

  void
ACE_Suspend_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Suspend_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Suspend_Node::ACE_Suspend_Node (const ACE_TCHAR *name)
  : ACE_Parse_Node (name)
{
  ACE_TRACE ("ACE_Suspend_Node::ACE_Suspend_Node");
}

ACE_Suspend_Node::~ACE_Suspend_Node (void)
{
}

ACE_ALLOC_HOOK_DEFINE (ACE_Resume_Node)

  void
ACE_Resume_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Resume_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Resume_Node::ACE_Resume_Node (const ACE_TCHAR *name)
  : ACE_Parse_Node (name)
{
  ACE_TRACE ("ACE_Resume_Node::ACE_Resume_Node");
}

ACE_Resume_Node::~ACE_Resume_Node (void)
{
}

void
ACE_Suspend_Node::apply (ACE_Service_Gestalt *config, int &yyerrno)
{
  ACE_TRACE ("ACE_Suspend_Node::apply");

  if (config->suspend (this->name ()) == -1)
    ++yyerrno;

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("did suspend on %s, error = %d\n"),
                this->name (),
                yyerrno));
#endif /* ACE_NLOGGING */
}

void
ACE_Resume_Node::apply (ACE_Service_Gestalt *config, int &yyerrno)
{
  ACE_TRACE ("ACE_Resume_Node::apply");

  if (config->resume (this->name ()) == -1)
    ++yyerrno;

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("did resume on %s, error = %d\n"),
                this->name (),
                yyerrno));
#endif /* ACE_NLOGGING */
}

ACE_ALLOC_HOOK_DEFINE (ACE_Remove_Node)

  void
ACE_Remove_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Remove_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Remove_Node::ACE_Remove_Node (const ACE_TCHAR *name)
  : ACE_Parse_Node (name)
{
  ACE_TRACE ("ACE_Remove_Node::ACE_Remove_Node");
}

ACE_Remove_Node::~ACE_Remove_Node (void)
{
}

void
ACE_Remove_Node::apply (ACE_Service_Gestalt *config, int &yyerrno)
{
  ACE_TRACE ("ACE_Remove_Node::apply");

  if (config->remove (this->name ()) == -1)
    ++yyerrno;

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) Remove_Node::apply")
                ACE_TEXT (" - did remove on %s, error = %d\n"),
                this->name (),
                yyerrno));
#endif /* ACE_NLOGGING */
}


ACE_Dynamic_Node::ACE_Dynamic_Node (ACE_Service_Type_Factory const *stf,
                                    ACE_TCHAR *parms)
  : ACE_Static_Node (stf->name (), parms)
  , factory_ (stf)
{
  ACE_TRACE ("ACE_Dynamic_Node::ACE_Dynamic_Node");
}

void
ACE_Dynamic_Node::apply (ACE_Service_Gestalt *config, int &yyerrno)
{
  ACE_TRACE ("ACE_Dynamic_Node::apply");

  if (config->initialize (this->factory_.get (),
                          this->parameters ()) == -1)
    ++yyerrno;

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) Dynamic_Node::apply")
                ACE_TEXT (" - Did dynamic on %s (yyerrno=%d)\n"),
                this->name (),
                yyerrno));
#endif /* ACE_NLOGGING */
}

ACE_ALLOC_HOOK_DEFINE (ACE_Dynamic_Node)

  void
ACE_Dynamic_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Dynamic_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Dynamic_Node::~ACE_Dynamic_Node (void)
{
  ACE_TRACE ("ACE_Dynamic_Node::~ACE_Dynamic_Node");
}

ACE_ALLOC_HOOK_DEFINE (ACE_Static_Node)

  void
ACE_Static_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Static_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Static_Node::ACE_Static_Node (const ACE_TCHAR *nm,
                                  ACE_TCHAR *params)
  : ACE_Parse_Node (nm),
    parameters_ (ACE::strnew (params))
{
  ACE_TRACE ("ACE_Static_Node::ACE_Static_Node");
}

const ACE_Service_Type *
ACE_Static_Node::record (const ACE_Service_Gestalt *config) const
{
  ACE_TRACE ("ACE_Static_Node::record");
  ACE_Service_Type *sr = 0;

  if (config->find (this->name (), (const ACE_Service_Type **) &sr) == -1)
    return 0;

  return sr;
}

ACE_TCHAR *
ACE_Static_Node::parameters (void) const
{
  ACE_TRACE ("ACE_Static_Node::parameters");
  return this->parameters_;
}

void
ACE_Static_Node::apply (ACE_Service_Gestalt *config, int &yyerrno)
{
  ACE_TRACE ("ACE_Static_Node::apply");
  if (config->initialize (this->name (),
        this->parameters ()) == -1)
    ++yyerrno;

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) Static_Node::apply -")
                ACE_TEXT (" Did static on %s (yyerrno=%d)\n"),
                this->name (),
                yyerrno));
#endif /* ACE_NLOGGING */
}

ACE_Static_Node::~ACE_Static_Node (void)
{
  ACE_TRACE ("ACE_Static_Node::~ACE_Static_Node");
  delete[] this->parameters_;
}


ACE_ALLOC_HOOK_DEFINE (ACE_Location_Node)

  void
ACE_Location_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Location_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Location_Node::ACE_Location_Node (void)
  : pathname_ (0),
    dll_ (),
    symbol_ (0)
{
  ACE_TRACE ("ACE_Location_Node::ACE_Location_Node");
}

ACE_Location_Node::~ACE_Location_Node (void)
{
  ACE_TRACE ("ACE_Location_Node::~ACE_Location_Node");
}

const ACE_DLL &
ACE_Location_Node::dll (void)
{
  return this->dll_;
}

const ACE_TCHAR *
ACE_Location_Node::pathname (void) const
{
  ACE_TRACE ("ACE_Location_Node::pathname");
  return this->pathname_;
}

void
ACE_Location_Node::pathname (const ACE_TCHAR *p)
{
  ACE_TRACE ("ACE_Location_Node::pathname");
  this->pathname_ = p;
}

int
ACE_Location_Node::dispose (void) const
{
  ACE_TRACE ("ACE_Location_Node::dispose");
  return this->must_delete_;
}

int
ACE_Location_Node::open_dll (int & yyerrno)
{
  ACE_TRACE ("ACE_Location_Node::open_dll");

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("ACE (%P|%t) LN::open_dll - path=%s\n"),
                this->pathname ()));
#endif /* ACE_NLOGGING */

  if (-1 == this->dll_.open (this->pathname ()))
    {
      ++yyerrno;

#ifndef ACE_NLOGGING
      ACE_TCHAR *errmsg = this->dll_.error ();
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("ACE (%P|%t) LN::open_dll - Failed to open %s: %s\n"),
                  this->pathname (),
                  errmsg ? errmsg : ACE_TEXT ("no error reported")));
#endif /* ACE_NLOGGING */

      return -1;
    }

  return 0;

}

void
ACE_Location_Node::set_symbol (void *s)
{
  ACE_TRACE ("ACE_Location_Node::set_symbol");
  this->symbol_ = s;
}

ACE_ALLOC_HOOK_DEFINE (ACE_Object_Node)

  void
ACE_Object_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Object_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Object_Node::ACE_Object_Node (const ACE_TCHAR *path,
                                  const ACE_TCHAR *obj_name)
  : object_name_ (ACE::strnew (obj_name))
{
  ACE_TRACE ("ACE_Object_Node::ACE_Object_Node");
  this->pathname (ACE::strnew (path));
  this->must_delete_ = 0;
}

void *
ACE_Object_Node::symbol (ACE_Service_Gestalt *,
                         int &yyerrno,
                         ACE_Service_Object_Exterminator *)
{
  ACE_TRACE ("ACE_Object_Node::symbol");
  if (this->open_dll (yyerrno) == 0)
    {
      ACE_TCHAR *object_name = const_cast<ACE_TCHAR *> (this->object_name_);

      this->symbol_ = this->dll_.symbol (object_name);
      if (this->symbol_ == 0)
        {
          ++yyerrno;

#ifndef ACE_NLOGGING
          ACE_TCHAR *errmsg = this->dll_.error ();
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("ACE (%P|%t) DLL::symbol -")
                      ACE_TEXT (" Failed for object %s: %s\n"),
                      object_name,
                      errmsg ? errmsg : ACE_TEXT ("no error reported")));
#endif /* ACE_NLOGGING */

          return 0;
        }

      return this->symbol_;
    }

  return 0;
}

ACE_Object_Node::~ACE_Object_Node (void)
{
  ACE_TRACE ("ACE_Object_Node::~ACE_Object_Node");
  delete[] const_cast<ACE_TCHAR *> (this->object_name_);
}

ACE_ALLOC_HOOK_DEFINE (ACE_Function_Node)

  void
ACE_Function_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Function_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Function_Node::ACE_Function_Node (const ACE_TCHAR *path,
                                      const ACE_TCHAR *func_name)
  : function_name_ (make_func_name (func_name))
{
  ACE_TRACE ("ACE_Function_Node::ACE_Function_Node");
  this->pathname (ACE::strnew (path));
  this->must_delete_ = 1;
}

ACE_TCHAR *
ACE_Function_Node::make_func_name (ACE_TCHAR const * func_name)
{
  // Preprocessor symbols will not be expanded if they are
  // stringified.  Force the preprocessor to expand them during the
  // argument prescan by calling a macro that itself calls another
  // that performs the actual stringification.
#if defined (ACE_HAS_VERSIONED_NAMESPACE) && ACE_HAS_VERSIONED_NAMESPACE == 1
# define ACE_MAKE_VERSIONED_NAMESPACE_NAME_STRING_IMPL(NAME) #NAME
# define ACE_MAKE_VERSIONED_NAMESPACE_NAME_STRING(NAME) ACE_MAKE_VERSIONED_NAMESPACE_NAME_STRING_IMPL(NAME)
# define ACE_VERSIONED_NAMESPACE_NAME_STRING ACE_MAKE_VERSIONED_NAMESPACE_NAME_STRING(ACE_VERSIONED_NAMESPACE_NAME)

  // Check if function is using the ACE naming convention.  If so,
  // it is likely that the ACE factory function macros
  // (e.g. ACE_FACTORY_DECLARE) were used to declare and define it, so
  // mangle the function name to include the ACE versioned namespace
  // name as is done in the ACE macros.  Otherwise, leave the function
  // name as is.

  static ACE_TCHAR const make_prefix[] = ACE_TEXT ("_make_");
  static size_t const make_prefix_len =
    sizeof (make_prefix) / sizeof (make_prefix[0]) - 1;

  if (ACE_OS::strncmp (make_prefix, func_name, make_prefix_len) == 0)
    {
      static ACE_TCHAR const versioned_namespace_name[] =
        ACE_TEXT (ACE_VERSIONED_NAMESPACE_NAME_STRING) ACE_TEXT("_") ;

      // Null terminator included in versioned_namespace_name_len since
      // it is static constant.
      static size_t const versioned_namespace_name_len =
        sizeof (versioned_namespace_name)
        / sizeof (versioned_namespace_name[0]); // - 1;

      size_t const len =
        ACE_OS::strlen (func_name)
        + versioned_namespace_name_len;
      // + 1;  // Null terminator.

      ACE_TCHAR * mangled_func_name;
      ACE_NEW_RETURN (mangled_func_name,
                      ACE_TCHAR[len],
                      0);

      ACE_Auto_Basic_Array_Ptr<ACE_TCHAR> safe (mangled_func_name);

      ACE_OS::snprintf (mangled_func_name,
                        len,
                        ACE_TEXT ("%s%s%s"),
                        make_prefix,
                        versioned_namespace_name,
                        func_name + make_prefix_len);

      return safe.release ();
    }
#endif  /* ACE_HAS_VERSIONED_NAMESPACE == 1 */

  return ACE::strnew (func_name);
}

void *
ACE_Function_Node::symbol (ACE_Service_Gestalt *,
                           int &yyerrno,
                           ACE_Service_Object_Exterminator *gobbler)
{
  typedef ACE_Service_Object *(*ACE_Service_Factory_Ptr)
    (ACE_Service_Object_Exterminator *);

  ACE_TRACE ("ACE_Function_Node::symbol");
  if (this->open_dll (yyerrno) == 0)
    {
      this->symbol_ = 0;

      // Locate the factory function <function_name> in the shared
      // object.
      ACE_TCHAR * const function_name =
        const_cast<ACE_TCHAR *> (this->function_name_);

      void * const func_p = this->dll_.symbol (function_name);
      if (func_p == 0)
        {
          ++yyerrno;

#ifndef ACE_NLOGGING
          ACE_TCHAR * const errmsg = this->dll_.error ();
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("DLL::symbol failed for function %s: ")
                      ACE_TEXT ("%s\n"),
                      function_name,
                      errmsg ? errmsg : ACE_TEXT ("no error reported")));
#endif /* ACE_NLOGGING */

          return 0;
        }

#if defined (ACE_OPENVMS) && (!defined (__INITIAL_POINTER_SIZE) || (__INITIAL_POINTER_SIZE < 64))
      int const temp_p = reinterpret_cast<int> (func_p);
#else
      intptr_t const temp_p = reinterpret_cast<intptr_t> (func_p);
#endif

      ACE_Service_Factory_Ptr func =
        reinterpret_cast<ACE_Service_Factory_Ptr> (temp_p);

      // Invoke the factory function and record it's return value.
      this->symbol_ = (*func) (gobbler);

      if (this->symbol_ == 0)
        {
          ++yyerrno;
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%p\n"),
                             this->function_name_),
                            0);
        }
    }
  return this->symbol_;
}

ACE_Function_Node::~ACE_Function_Node (void)
{
  ACE_TRACE ("ACE_Function_Node::~ACE_Function_Node");
  delete[] const_cast<ACE_TCHAR *> (function_name_);
  delete[] const_cast<ACE_TCHAR *> (pathname_);
}

ACE_ALLOC_HOOK_DEFINE (ACE_Dummy_Node)

  void
ACE_Dummy_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Dummy_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Dummy_Node::ACE_Dummy_Node (const ACE_Static_Node *static_node,
                                const ACE_Parse_Node *str_mods)
  : ACE_Parse_Node (static_node->name ()),
    node_ (static_node),
    mods_ (str_mods)
{
  ACE_TRACE ("ACE_Dummy_Node::ACE_Dummy_Node");
}

void
ACE_Dummy_Node::apply (ACE_Service_Gestalt *, int &yyerrno)
{
  ACE_TRACE ("ACE_Dummy_Node::apply");

#ifndef ACE_NLOGGING
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("did operations on stream %s, error = %d\n"),
                this->name (),
                yyerrno));
#else
  ACE_UNUSED_ARG (yyerrno);
#endif /* ACE_NLOGGING */
}

ACE_Dummy_Node::~ACE_Dummy_Node (void)
{
  ACE_TRACE ("ACE_Dummy_Node::~ACE_Dummy_Node");
  ACE_Static_Node *n = const_cast<ACE_Static_Node *> (this->node_);
  delete n;
  ACE_Parse_Node *m = const_cast<ACE_Parse_Node *> (this->mods_);
  delete m;
}

ACE_ALLOC_HOOK_DEFINE (ACE_Static_Function_Node)

  void
ACE_Static_Function_Node::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Static_Function_Node::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Static_Function_Node::ACE_Static_Function_Node (const ACE_TCHAR *func_name)
  : function_name_ (ACE::strnew (func_name))
{
  ACE_TRACE ("ACE_Static_Function_Node::ACE_Static_Function_Node");
  this->must_delete_ = 1;
}

void *
ACE_Static_Function_Node::symbol (ACE_Service_Gestalt *config,
                                  int &yyerrno,
                                  ACE_Service_Object_Exterminator *gobbler)
{
  ACE_TRACE ("ACE_Static_Function_Node::symbol");

  this->symbol_ = 0;

  // Locate the factory function <function_name> in the statically
  // linked svcs.

  ACE_Static_Svc_Descriptor *ssd = 0;
  if (config->find_static_svc_descriptor (this->function_name_, &ssd) == -1)
    {
      ++yyerrno;
      ACE_ERROR_RETURN ((LM_ERROR,
       ACE_TEXT ("(%P|%t) No static service ")
       ACE_TEXT ("registered for function %s\n"),
       this->function_name_),
      0);
    }

  if (ssd->alloc_ == 0)
    {
      ++yyerrno;

      if (this->symbol_ == 0)
        {
          ++yyerrno;

          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("(%P|%t) No static service factory ")
                             ACE_TEXT ("function registered for function %s\n"),
                             this->function_name_),
          0);
        }
    }

  // Invoke the factory function and record it's return value.
  this->symbol_ = (*ssd->alloc_) (gobbler);

  if (this->symbol_ == 0)
    {
      ++yyerrno;
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         this->function_name_),
                        0);
    }

  return this->symbol_;
}

ACE_Static_Function_Node::~ACE_Static_Function_Node (void)
{
  ACE_TRACE ("ACE_Static_Function_Node::~ACE_Static_Function_Node");
  delete[] const_cast<ACE_TCHAR *> (this->function_name_);
}

ACE_ALLOC_HOOK_DEFINE (ACE_Service_Type_Factory)

ACE_Service_Type_Factory::ACE_Service_Type_Factory (ACE_TCHAR const *name,
                                                    int type,
                                                    ACE_Location_Node *location,
                                                    int active)
  : name_ (name)
  , type_ (type)
  , location_ (location)
  , is_active_ (active)
{
}


ACE_Service_Type_Factory::~ACE_Service_Type_Factory (void)
{
}


ACE_Service_Type *
ACE_Service_Type_Factory::make_service_type (ACE_Service_Gestalt *cfg) const
{
  ACE_TRACE ("ACE_Service_Type_Factory::make_service_type");

  u_int flags = ACE_Service_Type::DELETE_THIS
    | (this->location_->dispose () == 0 ? 0 : ACE_Service_Type::DELETE_OBJ);

  int yyerrno = 0;
  ACE_Service_Object_Exterminator gobbler = 0;

  void *sym = this->location_->symbol (cfg, yyerrno, &gobbler);

  if (sym != 0)
    {
      ACE_Service_Type_Impl *stp =
        ACE_Service_Config::create_service_type_impl (this->name (),
                                                      this->type_,
                                                      sym,
                                                      flags,
                                                      gobbler);
      if (stp == 0)
        ++yyerrno;

      ACE_Service_Type *tmp = 0;
      ACE_NEW_RETURN (tmp,
                      ACE_Service_Type (this->name (),
                                        stp,
                                        this->location_->dll (),
                                        this->is_active_),
                      0);
      return tmp;
    }

#ifndef ACE_NLOGGING
  ACE_ERROR ((LM_ERROR,
              ACE_TEXT ("ACE (%P|%t) Unable to create ")
              ACE_TEXT ("service object for %s\n"),
              this->name ()));
#endif
  ++yyerrno;
  return 0;
}

ACE_TCHAR const*
ACE_Service_Type_Factory::name (void) const
{
  return name_.c_str ();
}


ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_USES_CLASSIC_SVC_CONF == 1 */

