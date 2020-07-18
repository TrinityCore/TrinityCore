-- Incorrect/weird or drops from gameobjects or items
DELETE FROM `creature_loot_template` WHERE `Item` IN (6712,16747,16748,12533,22649,22650,21749);
-- Incorrect/weird
DELETE FROM `creature_loot_template` WHERE `Entry` = 23051 AND `Item` != 33838;
DELETE FROM `creature_loot_template` WHERE `Entry` = 14467 AND `Item` != 18625;
DELETE FROM `creature_loot_template` WHERE `Entry` = 11876 AND `Item` != 13542;
DELETE FROM `creature_loot_template` WHERE `Entry` = 868 AND `Item` = 19279;
-- These NPCs shouldn't have loot table
UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` IN (10387,10388,10389,17070,17462,20595);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (10387,10388,10389,17070);
