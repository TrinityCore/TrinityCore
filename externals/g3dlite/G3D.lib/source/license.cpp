/**
 @file license.cpp
 
 @author Morgan McGuire, graphics3d.com
 
 @created 2004-04-15
 @edited  2004-04-15
*/

#include "G3D/format.h"
#include <string>

namespace G3D {

std::string license() {
    return format(

"This software is based in part on the PNG Reference Library which is\n"
"Copyright (c) 2004 Glenn Randers-Pehrson\n\n"
"This software is based in part on the work of the Independent JPEG Group.\n\n"
"This software is based on part on the FFmpeg libavformat and libavcodec libraries\n" 
"(\"FFmpeg\", http://ffmpeg.mplayerhq.hu), which are included under the terms of the\n" 
"GNU Lesser General Public License (LGPL), (http://www.gnu.org/copyleft/lesser.html).\n\n"
"%s"
"This program uses the G3D Library (http://g3d-cpp.sf.net), which\n"
"is licensed under the \"BSD\" Open Source license.  The Graphics3D library\n"
"source code is Copyright © 2000-2008, Morgan McGuire, All rights reserved.\n"
"The BSD license requires the following statement regarding G3D:\n"
"\n"
"Redistribution and use in source and binary forms, with or without\n"
"modification, are permitted provided that the following conditions\n"
"are met:\n"
"\n"
"Redistributions of source code must retain the above copyright\n"
"notice, this list of conditions and the following disclaimer.\n"
"\n"
"Redistributions in binary form must reproduce the above copyright\n"
"notice, this list of conditions and the following disclaimer in the\n"
"documentation and/or other materials provided with the distribution.\n" 
"\n"
"Neither the name of Morgan McGuire, Brown University, Williams College, nor the names\n"
"of the G3D contributors may be used to endorse or promote products derived\n"
"from this software without specific prior written permission.\n"
"\n"
"THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS\n"
"\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT\n"
"LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR\n"
"A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT\n"
"OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,\n"
"SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT\n"
"LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,\n"
"DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY\n"
"THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n"
"(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n"
"OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n"
"\n\n"
"G3D VERSION %d\n", 

#ifdef G3D_WIN32
    "" // Win32 doesn't use SDL
#else
    "This software uses the Simple DirectMedia Layer library (\"SDL\",\n"
    "http://www.libsdl.org), which is included under the terms of the\n"
    "GNU Lesser General Public License, (http://www.gnu.org/copyleft/lesser.html).\n\n"
#endif
,
G3D_VER);
}

}
