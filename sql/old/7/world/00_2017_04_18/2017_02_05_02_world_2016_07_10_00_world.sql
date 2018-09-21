--
DELETE FROM `creature_loot_template` WHERE `Item` IN (5058, 5359, 6083, 33348);
UPDATE `creature_template` SET `lootid`=0 WHERE `entry`=4661;
