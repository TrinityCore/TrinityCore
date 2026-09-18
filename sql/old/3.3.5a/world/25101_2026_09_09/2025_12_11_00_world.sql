-- Remove Gal'darah disarm immunity
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`&~4 WHERE `entry` IN (31368, 29306);
