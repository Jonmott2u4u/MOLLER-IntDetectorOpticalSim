#!/bin/bash
#p=200
#for j in {1..4400..200}
#do
rm command100
touch command100
python MacroSubmitter.py >> command100
sh command100
#sleep 20
#done
rm command100
#rm slurm*
# 
# cd ../Col6At3ndBlkHead_Lin_asym_ep/
# for j in {1..4400..200}
# do
# rm command300
# touch command300
# python MacroSubmitter.py "" "" "" $j $((j + p)) >> command300
# sh command300
# sleep 20
# done
# 
# rm command300
# rm slurm*