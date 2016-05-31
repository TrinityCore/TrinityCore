-- Despawned in 4.0.3a, their loot in tables no longer needed
-- Defias Thugs in Northshire Valley were replaced by Blackrock Orcs
UPDATE `creature_template` SET `lootid`=0, `pickpocketloot`=0 WHERE `entry`=38;
DELETE FROM `creature_loot_template` WHERE `entry`=38;
DELETE FROM `pickpocketing_loot_template` WHERE `entry`=38;
