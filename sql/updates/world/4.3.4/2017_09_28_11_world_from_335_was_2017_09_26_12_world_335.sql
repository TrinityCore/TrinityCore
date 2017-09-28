/*
-- Quest "Deaths in the Family" --> Add completion event
DELETE FROM `creature_text` WHERE `CreatureID`=1500;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1500,0,0,"Hah!  Eternal undeath to the cursed Agamands!",14,1,100,11,0,0,2631,0,"Coleman Farthing"),
(1500,1,0,"Thank you, $n.  You have tempered the cold rage in my heart.",12,1,100,1,0,0,2632,0,"Coleman Farthing");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1500 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1500,0,0,0,20,0,100,0,354,0,0,0,80,150000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coleman Farthing - On Quest \'Deaths in the Family\' Finished - Run Script");

DELETE FROM `smart_scripts` WHERE `entryorguid`=150000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(150000,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coleman Farthing - On Script - Remove Npc Flag Questgiver"),
(150000,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Coleman Farthing - On Script - Say Line 0"),
(150000,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Coleman Farthing - On Script - Say Line 1"),
(150000,9,3,0,0,0,100,0,4000,4000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coleman Farthing - On Script - Add Npc Flag Questgiver");
*/
