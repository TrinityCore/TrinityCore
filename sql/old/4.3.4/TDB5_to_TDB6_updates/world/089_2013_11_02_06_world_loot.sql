--
DELETE FROM `creature_loot_template` WHERE `entry` =8996;
UPDATE `creature_template` SET `lootid`=0, `mingold`=0, `maxgold`=0 WHERE `entry`=8996;
