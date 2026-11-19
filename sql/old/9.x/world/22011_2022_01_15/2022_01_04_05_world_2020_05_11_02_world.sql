-- These shouldn't have loot table
DELETE FROM `creature_loot_template` WHERE `Entry` IN (7052,7056,7307);
UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` IN (7052,7056,7307);
-- Already drops from items or gameobjects
DELETE FROM `creature_loot_template` WHERE `Reference` = 0 AND `Item` IN (5140,5173,5374,5601,5602,6457,10839,10840,21156,24231,24232,29572,29573,29574,29577,30508,32728,5397,7146);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (5846,5854) AND (`Reference` = 0 AND `Item` = 10575);
DELETE FROM `creature_loot_template` WHERE `Entry` NOT IN (2156,2157) AND (`Reference` = 0 AND `Item` = 5568);
