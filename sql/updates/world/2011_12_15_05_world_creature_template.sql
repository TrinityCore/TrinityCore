-- Culling of Stratholme Hemotoxin SAI spell fix version written by nelegalno.
-- Closes https://github.com/TrinityCore/TrinityCore/issues/3747

SET @ENTRY := 28199;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=@ENTRY);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY);
INSERT INTO `smart_scripts` VALUES
(@ENTRY, 0, 0, 0, 9, 0, 25, 2, 0, 20, 5000, 8000, 11, 52522, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tomb Stalker - Cast Hemotoxin Normal'),
(@ENTRY, 0, 1, 0, 9, 0, 40, 4, 0, 20, 5000, 8000, 11, 58782, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tomb Stalker - Cast Hemotoxin Heroic');