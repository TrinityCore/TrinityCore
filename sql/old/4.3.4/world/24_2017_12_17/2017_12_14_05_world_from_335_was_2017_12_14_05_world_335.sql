/*
-- Draz'Zilb
DELETE FROM `creature_text` WHERE `CreatureID`=4501;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4501,0,0,"%s begins to cast a spell over the hearts and tongues.",16,0,100,0,0,0,1511,0,"Draz'Zilb"),
(4501,1,0,"The brood of Onyxia!",12,0,100,0,0,0,1512,0,"Draz'Zilb");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4501;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4501 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=450100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4501,0,0,0,20,0,100,0,1169,0,0,0,80,450100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draz'Zilb - On Quest 'Identifying the Brood' Finished - Run Script"),
(450100,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draz'Zilb - On Script - Remove Npc Flag Questgiver+Gossip"),
(450100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draz'Zilb - On Script - Say Line 0"),
(450100,9,2,0,0,0,100,0,0,0,0,0,11,6741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draz'Zilb - On Script - Cast Identify Brood"),
(450100,9,3,0,0,0,100,0,11000,11000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draz'Zilb - On Script - Say Line 1"),
(450100,9,4,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draz'Zilb - On Script - Add Npc Flag Questgiver+Gossip");
*/
