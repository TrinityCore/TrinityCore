/*
-- Blood Elf Defender
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8581;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8581 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=858100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8581,0,0,0,0,0,100,0,7000,12000,11000,14000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Defender - In Combat - Cast 'Shield Block'"),
(8581,0,1,0,0,0,100,0,5000,9000,8000,13000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Elf Defender - In Combat - Cast 'Revenge'"),
(8581,0,2,0,11,0,100,0,0,0,0,0,80,858100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Defender - On Respawn - Run Script"),
(858100,9,0,0,0,0,100,0,0,0,0,0,11,51347,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Defender - On Script - Cast 'Teleport Visual Only'"),
(858100,9,1,0,0,0,100,0,2000,2000,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Blood Elf Defender - On Script - Start Attacking"),
(858100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Defender - On Script - Say Line 0"),
(858100,9,3,0,0,0,100,0,10000,10000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Defender - On Script - Say Line 1"),
(858100,9,4,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Elf Defender - On Script - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID`=8581;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8581,0,0,"Who dares?! I will destroy you!",12,0,100,0,0,0,4502,0,"Blood Elf Defender"),
(8581,1,0,"Mistress!! They seek to destroy your work!!",12,0,100,0,0,0,4491,0,"Blood Elf Defender"),
(8581,2,0,"Ha! Now your death is ensured!",12,0,100,0,0,0,4492,0,"Blood Elf Defender");

-- Magus Rimtori
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8578;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8578 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8578,0,0,0,0,0,100,0,0,0,3000,5000,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Magus Rimtori - In Combat - Cast 'Fireball'"),
(8578,0,1,0,9,0,100,0,0,8,13000,16000,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magus Rimtori - Within 0-8 Range - Cast 'Frost Nova'"),
(8578,0,2,0,11,0,100,0,0,0,0,0,11,51347,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magus Rimtori - On Respawn - Cast 'Teleport Visual Only'"),
(8578,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magus Rimtori - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=8578;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8578,0,0,"You dare! Now feel my wrath!",14,0,100,0,0,0,4495,0,"Magus Rimtori");
*/
