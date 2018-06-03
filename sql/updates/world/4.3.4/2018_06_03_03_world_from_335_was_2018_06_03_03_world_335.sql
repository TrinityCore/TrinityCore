/*
-- Josef Gregorian
DELETE FROM `creature_text` WHERE `CreatureID`=4576;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4576,0,0,"One moment while I stitch this together...",12,1,100,0,0,0,2761,0,"Josef Gregorian"),
(4576,1,0,"There.  I am finished with your robe, $n.",12,1,100,1,0,0,2762,0,"Josef Gregorian");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4576;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4576 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=457600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4576,0,0,0,20,0,100,0,1961,0,0,0,80,457600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Josef Gregorian - On Quest 'Gathering Materials' Finished - Run Script"),
(457600,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Josef Gregorian - On Script - Remove Npc Flag Questgiver"),
(457600,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Josef Gregorian - On Script - Say Line 0"),
(457600,9,2,0,0,0,100,0,3000,3000,0,0,11,9157,0,0,0,0,0,1,0,0,0,0,0,0,0,"Josef Gregorian - On Script - Cast 'Create Mage's Robe'"),
(457600,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Josef Gregorian - On Script - Say Line 1"),
(457600,9,4,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Josef Gregorian - On Script - Add Npc Flag Questgiver");
*/
