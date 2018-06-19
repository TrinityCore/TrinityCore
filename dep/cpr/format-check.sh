#!/bin/bash


which clang-format-3.8
if [ $? -eq 0 ]
then
    format_command=clang-format-3.8
else
    format_command=clang-format
fi

format_error_exists=0

for DIRECTORY in include cpr
do
    for FILE in $DIRECTORY/*.h $DIRECTORY/*.cpp
    do
        if [ -e $FILE ]
        then
            $format_command -style=file -output-replacements-xml $FILE | grep -c "<replacement " >/dev/null
            if [ $? -ne 1 ]
            then
                echo "Please run clang-format on $FILE:"
                $format_command -style=file $FILE | diff - $FILE
                format_error_exists=1
            fi
        fi
    done
done

if [ $format_error_exists -ne 0 ]
then
    echo "Some files require formatting"
    exit 1
fi

exit 0
