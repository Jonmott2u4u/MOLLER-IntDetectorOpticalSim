#!/bin/bash

cd "$(dirname "$0")"
rm -f command100
touch command100
python3 MacroSubmitter.py >> command100 2>&1
sh command100

#done
rm command100