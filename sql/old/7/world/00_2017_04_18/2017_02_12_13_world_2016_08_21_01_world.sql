--
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2 WHERE `entry`=30808;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|4 WHERE `entry` IN (33911,33910);
