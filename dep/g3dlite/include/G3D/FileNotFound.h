/** 
  \file FileNotFound.h
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
  \created 2011-12-31
  \edited  2011-12-31
 */
#ifndef G3D_FileNotFound_h
#define G3D_FileNotFound_h

#include "G3D/platform.h"
#include "G3D/G3DString.h"

namespace G3D {

/** Thrown by various file opening routines if the file is not found. 

   \sa ParseError, System::findDataFile
*/
class FileNotFound {
public:
    String filename;
    String message;

    FileNotFound() {}
    FileNotFound(const String& f, const String& m) : filename(f), message(m) {}
    virtual ~FileNotFound(){};
};

} // G3D

#endif
