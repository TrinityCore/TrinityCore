# Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
#
# Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

## Process this file with automake to produce Makefile.in

## Sub-directories to parse

## Additional files to include when running 'make dist'
#  Nothing yet.
#  Doxygen configuration files.
EXTRA_DIST = \
	DocStructure.dox \
	Doxyfile

DOC_DIR = .
DOXYFILE = $(DOC_DIR)/Doxyfile
DOC_HTML = $(DOC_OUT)/index.html
DOC_OUT_HTML = $(DOC_DIR)/html
DOXYGEN = @DOXYGEN@

if DOXYGEN_ENABLED
doc: $(DOC_HTML)
	@echo ""
	@echo "Type \"firefox $(DOC_OUT_HTML)/index.html\" to see the html document."
	@echo ""

$(DOC_HTML): $(DOXYFILE)
	$(DOXYGEN) $(DOXYFILE)
else
.PHONY: doc
doc:
	@echo "You must enable at configure time: ./configure --enable-doxygen"
endif

clean-local: 
	rm -rf $(DOC_OUT_HTML)
