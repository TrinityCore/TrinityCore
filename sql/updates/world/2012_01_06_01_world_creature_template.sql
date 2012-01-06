-- spell interrupt is loaded from DBC so can be removed from mechanic_immune_mask 
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask` &~33554432;
