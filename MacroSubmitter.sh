#!/bin/bash

rm -f command100
touch command100
python MacroSubmitter.py >> command100
sh command100

#done
rm command100