-- Only one item added due to bad sorting
DELETE FROM `creature_loot_template` WHERE `entry` = 30633;
UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` = 30633;
