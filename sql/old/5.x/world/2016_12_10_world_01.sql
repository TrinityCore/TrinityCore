-- Quest 26271 Feeding the Hungry and the Hopeless
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='79450');
INSERT INTO `spell_linked_spell` VALUES (79450, 62464, 0, 'spell credit');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='42384');
-- DELETE FROM `smart_scripts` WHERE (`entryorguid`='42384');   already done by quest 26209 above
REPLACE INTO `smart_scripts` VALUES (42384, 0, 1, 2, 8, 0, 100, 0, 62464, 0, 0, 0, 33, 42617, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'credit');
REPLACE INTO `smart_scripts` VALUES (42384, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'despawn');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='42386');
DELETE FROM `smart_scripts` WHERE (`entryorguid`='42386');   
REPLACE INTO `smart_scripts` VALUES (42386, 0, 1, 2, 8, 0, 100, 0, 62464, 0, 0, 0, 33, 42617, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'credit');
REPLACE INTO `smart_scripts` VALUES (42386, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'despawn');
