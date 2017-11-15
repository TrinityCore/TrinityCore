/*
-- Apothecary Lydon
DELETE FROM `creature_text` WHERE `CreatureID`=2216;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2216,0,0,"%s creates his toxin...",16,0,100,0,0,0,1421,0,"Apothecary Lydon"),
(2216,1,0,"There we are, $n.  The toxin is ready.",12,1,100,1,0,0,1422,0,"Apothecary Lydon");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2216;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2216 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=221600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2216,0,0,0,20,0,100,0,1066,0,0,0,80,221600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Quest 'Blood of Innocents' Finished - Run Script"),
(221600,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Script - Remove Npc Flag Questgiver"),
(221600,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Script - Say Line 0"),
(221600,9,2,0,0,0,100,0,0,0,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Script - Set Emote State 133"),
(221600,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Script - Set Emote State 0"),
(221600,9,4,0,0,0,100,0,500,500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Script - Say Line 1"),
(221600,9,5,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Script - Add Npc Flag Questgiver");
*/
