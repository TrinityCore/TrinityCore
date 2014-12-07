#ifndef DoNotInitialize_h
#define DoNotInitialize_h

/** A special value that may be passed to overloaded constructors to 
    indicate that they should not be initialized.  Useful for optimizing
    code for classes like Matrix4 that might produce unnecessary 
    initialization in some contexts
  */
class DoNotInitialize {};

#endif
