#!/bin/bash
set -e

echo "Codestyle check script:"
echo

singleLineRegexChecks=(
    "TC_LOG_.+GetCounter"
    "[[:blank:]]$"
    "\t"
)
for check in ${singleLineRegexChecks[@]}; do
    echo "  Checking RegEx: '${check}'"
    
    if grep -P -r -I -n ${check} src; then
        exit 1
    fi
done

multiLineRegexChecks=(
    "TC_LOG_[^;]+GetCounter"
)
for check in ${multiLineRegexChecks[@]}; do
    echo "  Checking RegEx: '${check}'"
    
    if grep -Pzo -r -I ${check} src; then
        exit 1
    fi
done

echo "Everything looks good"
