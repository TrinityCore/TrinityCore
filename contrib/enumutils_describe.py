from re import compile, MULTILINE
from os import walk, getcwd
from datetime import datetime

notice = ('''/*
 * Copyright (C) 2008-%d TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

''' % datetime.now().year)

if not getcwd().endswith('src'):
    print('Run this from the src directory!')
    print('(Invoke as \'python ../contrib/enumutils_describe.py\')')
    exit(1)

EnumPattern = compile(r'//\s*EnumUtils: DESCRIBE THIS\s+enum\s+([0-9A-Za-z]+)[^\n]*\s*{([^}]+)};')
EnumValuesPattern = compile(r'\s+[^,]+[^\n]*')
EnumValueNamePattern = compile(r'^\s*([a-zA-Z0-9_]+)', flags=MULTILINE)
EnumValueSkipLinePattern = compile(r'^\s*//')
EnumValueCommentPattern = compile(r'//[ \t]*([^\n]+)$')
CommentMatchFormat = compile(r'^(((TITLE +(.+?))|(DESCRIPTION +(.+?))) *){1,2}$')
CommentSkipFormat = compile(r'^SKIP *$')

def strescape(str):
    res = ''
    for char in str:
        if char in ('\\', '"') or not (32 <= ord(char) < 127):
            res += ('\\%03o' % ord(char))
        else:
            res += char
    return '"' + res + '"'

def processFile(path, filename):
    input = open('%s/%s.h' % (path, filename),'r')
    if input is None:
        print('Failed to open %s.h' % filename)
        return
        
    file = input.read()

    enums = []
    for enum in EnumPattern.finditer(file):
        name = enum.group(1)
        values = []
        for value in EnumValuesPattern.finditer(enum.group(2)):
            valueData = value.group(0)
            
            valueNameMatch = EnumValueNamePattern.search(valueData)
            if valueNameMatch is None:
                if EnumValueSkipLinePattern.search(valueData) is None:
                    print('Name of value not found: %s' % repr(valueData))
                continue
            valueName = valueNameMatch.group(1)
                
            valueCommentMatch = EnumValueCommentPattern.search(valueData)
            valueComment = None
            if valueCommentMatch:
                valueComment = valueCommentMatch.group(1)
            
            valueTitle = None
            valueDescription = None
            
            if valueComment is not None:
                if CommentSkipFormat.match(valueComment) is not None:
                    continue
                commentMatch = CommentMatchFormat.match(valueComment)
                if commentMatch is not None:
                    valueTitle = commentMatch.group(4)
                    valueDescription = commentMatch.group(6)
                else:
                    valueDescription = valueComment
            
            if valueTitle is None:
                valueTitle = valueName
            if valueDescription is None:
                valueDescription = ''
            
            values.append((valueName, valueTitle, valueDescription))
                
        enums.append((name, values))
        print('%s.h: Enum %s parsed with %d values' % (filename, name, len(values)))
        
    if not enums:
        return
        
    print('Done parsing %s.h (in %s)\n' % (filename, path))
    output = open('%s/enuminfo_%s.cpp' % (path, filename), 'w')
    if output is None:
        print('Failed to create enuminfo_%s.cpp' % filename)
        return

    # write output file
    output.write(notice)
    output.write('#include "%s.h"\n' % filename)
    output.write('#include "Define.h"\n')
    output.write('#include "SmartEnum.h"\n')
    output.write('#include <stdexcept>\n')
    output.write('\n')
    output.write('namespace Trinity\n')
    output.write('{\n')
    output.write('namespace Impl\n')
    output.write('{\n')
    for name, values in enums:
        tag = ('data for enum \'%s\' in \'%s.h\' auto-generated' % (name, filename))
        output.write('\n')
        output.write('/*' + ('*'*(len(tag)+2)) + '*\\\n')
        output.write('|* ' + tag + ' *|\n')
        output.write('\\*' + ('*'*(len(tag)+2)) + '*/\n')
        output.write('template <>\n')
        output.write('TC_API_EXPORT EnumText EnumUtils<%s>::ToString(%s value)\n' % (name, name))
        output.write('{\n')
        output.write('    switch (value)\n')
        output.write('    {\n')
        for label, title, description in values:
            output.write('        case %s: return { %s, %s, %s };\n' % (label, strescape(label), strescape(title), strescape(description)))
        output.write('        default: throw std::out_of_range("value");\n')
        output.write('    }\n')
        output.write('}\n')
        output.write('\n')
        output.write('template <>\n');
        output.write('TC_API_EXPORT size_t EnumUtils<%s>::Count() { return %d; }\n' % (name, len(values)))
        output.write('\n')
        output.write('template <>\n');
        output.write('TC_API_EXPORT %s EnumUtils<%s>::FromIndex(size_t index)\n' % (name, name))
        output.write('{\n')
        output.write('    switch (index)\n')
        output.write('    {\n')
        for i in range(len(values)):
            output.write('        case %d: return %s;\n' % (i, values[i][0]))
        output.write('        default: throw std::out_of_range("index");\n')
        output.write('    }\n')
        output.write('}\n')

    output.write('}\n')
    output.write('}\n')

FilenamePattern = compile(r'^(.+).h$')
for root, dirs, files in walk('.'):
    for n in files:
        nameMatch = FilenamePattern.match(n)
        if nameMatch is not None:
            processFile(root, nameMatch.group(1))
