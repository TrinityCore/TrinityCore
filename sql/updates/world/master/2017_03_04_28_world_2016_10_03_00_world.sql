--
UPDATE `creature_template` SET `lootid`=0, `flags_extra`=`flags_extra`|0x40 WHERE `entry`=17680;
DELETE FROM `creature_loot_template` WHERE `entry`=17680;
