from re import compile
from sys import argv, stdout, stderr
from os import walk, getcwd
from datetime import datetime

if not getcwd().endswith('src'):
    print('Run this from the src directory!')
    print('(Invoke as \'python ../contrib/describe_enum.py\')')
    exit(1)

MatchPreTag = compile(r'^ *// *ANNOTATE THIS *$') # state 0
MatchEnumName = compile(r'^ *enum +([0-9A-Za-z]+)') # state 1
MatchEnumStart = compile(r'^ *{ *$') # state 2
MatchEnumComment = compile(r' *(//.+)?$')
MatchEnumLine = compile(r'^ *([a-zA-Z0-9_]+)( *= *.+?)?,? *(// *([^\r\n]+))?$') # state 3
MatchEnumEnd = compile(r'^ *}; *$') # state 3
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
    
notice = '''/*
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

'''

def processFile(path, filename):
    enums = []
    state = 0
    # enum parsing
    enum = None
    input = open('%s/%s.h' % (path, filename),'r')
    if input is None:
        print('Failed to open %s.h' % filename)
        return

    for line in input:
        if state is 0:
            if MatchPreTag.match(line) is not None:
                state = 1
        elif state is 1:
            enumName = MatchEnumName.match(line)
            if enumName is not None:
                enum = (enumName.group(1), [])
                state = 2
            else:
                print('Unexpected line, expected enum name:')
                print(line)
                state = 0
        elif state is 2:
            if MatchEnumStart.match(line) is not None:
                state = 3
            else:
                print('Unexpected line, expected enum start:')
                print(line)
                state = 0
                enum = None
        elif state is 3:
            if MatchEnumEnd.match(line) is not None:
                enums.append(enum)
                print('Successfully parsed enum \'%s\' with %d elements' % (enum[0], len(enum[1])))
                state = 0
                enum = None
            elif MatchEnumComment.match(line) is not None:
                continue
            else:
                enumLine = MatchEnumLine.match(line)
                if enumLine is not None:
                    label = enumLine.group(1)
                    comment = enumLine.group(4)
                    
                    # do comment processing
                    title = None
                    description = None
                    if comment is not None:
                        if CommentSkipFormat.match(comment) is not None:
                            continue
                        commentMatch = CommentMatchFormat.match(comment)
                        if commentMatch is not None:
                            title = commentMatch.group(4)
                            description = commentMatch.group(6)
                        else:
                            description = comment
                            
                    # insert processed enum entry
                    if title is None:
                        title = label
                    if description is None:
                        description = ''
                    enum[1].append((label, title, description))
                else:
                    print('Unexpected line, expected enum line or enum end:')
                    print(line)
                    state = 0
                    enum = None
    
    if not enums:
        return
        
    print('Done parsing %s.h (in %s)' % (filename, path))
    output = open('%s/enuminfo_%s.cpp' % (path, filename), 'w')
    if output is None:
        print('Failed to create enuminfo_%s.cpp' % filename)
        return

    # write output file
    output.write(notice % datetime.now().year)
    output.write('#include "Define.h"\n')
    output.write('#include "SmartEnum.h"\n')
    output.write('#include "%s.h"\n' % filename)
    output.write('#include <stdexcept>\n')
    output.write('\n')
    for name, values in enums:
        tag = ('data for enum \'%s\' in \'%s.h\' auto-generated' % (name, filename))
        output.write('/*' + ('*'*(len(tag)+2)) + '*\\\n')
        output.write('|* ' + tag + ' *|\n')
        output.write('\\*' + ('*'*(len(tag)+2)) + '*/\n')
        output.write('template <>\n')
        output.write('TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<%s>::ToString(%s value)\n' % (name, name))
        output.write('{\n')
        output.write('    switch (value)\n')
        output.write('    {\n')
        for label, title, description in values:
            output.write('        case %s: return {%s, %s, %s};\n' % (label, strescape(label), strescape(title), strescape(description)))
        output.write('        default: throw std::out_of_range("value");\n')
        output.write('    }\n')
        output.write('}\n')
        output.write('template <>\n');
        output.write('TC_API_EXPORT size_t Trinity::Impl::EnumUtils<%s>::Count() { return %d; }\n' % (name, len(values)))
        output.write('template <>\n');
        output.write('TC_API_EXPORT %s Trinity::Impl::EnumUtils<%s>::FromIndex(size_t index)\n' % (name, name))
        output.write('{\n')
        output.write('    switch (index)\n')
        output.write('    {\n')
        for i in range(len(values)):
            output.write('        case %d: return %s;\n' % (i, values[i][0]))
        output.write('        default: throw std::out_of_range("index");\n')
        output.write('    }\n')
        output.write('}\n\n')

FilenamePattern = compile(r'^(.+).h$')
for root, dirs, files in walk('.'):
    for n in files:
        nameMatch = FilenamePattern.match(n)
        if nameMatch is not None:
            processFile(root, nameMatch.group(1))
