#!/bin/bash
set -e

echo "Codestyle check script:"
echo

regexChecks=("TC_LOG_.+GetCounter")

for check in ${regexChecks[@]}; do
    echo "  Checking RegEx: '${check}'"
    
    if grep -E -r ${check} src; then
        exit 1
    fi
done

echo "Everything looks good"
