/*
-- Fel'zerul
DELETE FROM `creature_text` WHERE `CreatureID`=1443;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1443,0,0,"I hereby destroy these instruments of evil! For the Horde!",14,1,100,15,0,0,1949,0,"Fel'zerul");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1443;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1443 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=144300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1443,0,0,0,20,0,100,0,1445,0,0,0,80,144300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel'zerul - On Quest 'The Temple of Atal'Hakkar' Finished - Run Script"),
(144300,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel'zerul - On Script - Remove Npc Flag Questgiver"),
(144300,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel'zerul - On Script - Say Line 0"),
(144300,9,2,0,0,0,100,0,4000,4000,0,0,11,7437,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel'zerul - On Script - Cast 'Break Stuff'"),
(144300,9,3,0,0,0,100,0,3000,3000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel'zerul - On Script - Add Npc Flag Questgiver");
*/
