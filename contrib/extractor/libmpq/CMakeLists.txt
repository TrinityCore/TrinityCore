# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_library (libmpq common.cpp  explode.cpp  extract.cpp  huffman.cpp  mpq.cpp  parser.cpp  wave.cpp )
# link libmpq with zlib
target_link_libraries (libmpq z)
