-- 
DELETE FROM `spell_ranks` WHERE `first_spell_id` = 34453 AND `rank` IN (1,2);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2 WHERE `entry` IN (32117,37440,32113,37436,32116,37439,32115,37438,32114,37437,32118,37441);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (22582);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|130 WHERE `entry` IN (30780,30782,30784,30786);
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|80358666 WHERE `entry` IN (37283,37444);
