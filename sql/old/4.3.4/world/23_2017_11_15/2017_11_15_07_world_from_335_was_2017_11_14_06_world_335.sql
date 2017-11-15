/*
-- Kin'weelay
DELETE FROM `creature_text` WHERE `CreatureID`=2519;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2519,0,0,"%s presents the Mind's Eye and the Singing Crystals before him...",16,0,100,0,0,0,742,0,"Kin'weelay"),
(2519,1,0,"I have fashioned Yenniku's Soul Gem, $n...",12,1,100,1,0,0,743,0,"Kin'weelay");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2519 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=251900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2519,0,0,0,20,0,100,0,591,0,0,0,80,251900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Quest 'The Mind's Eye' finished - Run Script"),
(251900,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Remove Npc Flag Questgiver"),
(251900,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 0"),
(251900,9,2,0,0,0,100,0,2000,2000,0,0,11,2362,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Cast Create Spellstone"),
(251900,9,3,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 1"),
(251900,9,4,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Add Npc Flag Questgiver");
*/
