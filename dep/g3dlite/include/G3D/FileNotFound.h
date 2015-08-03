/** 
  \file FileNotFound.h
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
  \created 2011-12-31
  \edited  2011-12-31
 */
#ifndef G3D_FileNotFound_h
#define G3D_FileNotFound_h

#include "G3D/platform.h"
#include <string>

namespace G3D {

/** Thrown by various file opening routines if the file is not found. 

   \sa ParseError, System::findDataFile
*/
class FileNotFound {
public:
    std::string filename;
    std::string message;

    FileNotFound() {}
    FileNotFound(const std::string& f, const std::string& m) : filename(f), message(m) {}
    virtual ~FileNotFound(){};
};

} // G3D

#endif
