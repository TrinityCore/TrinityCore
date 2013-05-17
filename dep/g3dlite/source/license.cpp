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
"This program uses the G3D Library (http://g3d.sf.net), which\n"
"is licensed under the \"Modified BSD\" Open Source license.  The G3D library\n"
"source code is Copyright © 2000-2010, Morgan McGuire, All rights reserved.\n"
"This program uses The OpenGL Extension Wrangler Library, which \n"
"is licensed under the \"Modified BSD\" Open Source license.  \n"
"The OpenGL Extension Wrangler Library source code is\n"
"Copyright (C) 2002-2008, Milan Ikits <milan ikits[]ieee org>\n"
"Copyright (C) 2002-2008, Marcelo E. Magallon <mmagallo[]debian org>\n"
"Copyright (C) 2002, Lev Povalahev\n"
"All rights reserved.\n\n"
"The Modified BSD license is below, and requires the following statement:\n"
"\n"
"Redistribution and use in source and binary forms, with or without \n"
"modification, are permitted provided that the following conditions are met:\n"
"\n"
"* Redistributions of source code must retain the above copyright notice, \n"
"  this list of conditions and the following disclaimer.\n"
"* Redistributions in binary form must reproduce the above copyright notice, \n"
"  this list of conditions and the following disclaimer in the documentation \n"
"  and/or other materials provided with the distribution.\n"
"* The name of the author may be used to endorse or promote products \n"
"  derived from this software without specific prior written permission.\n"
"\n"
"THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" \n"
"AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE \n"
"IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE\n"
"ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE \n"
"LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR \n"
"CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF \n"
"SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS\n"
"INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN\n"
"CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)\n"
"ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF\n"
"THE POSSIBILITY OF SUCH DAMAGE.\n"
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
