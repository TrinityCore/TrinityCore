-- Completion Event for Quest "The Tower of Althalaxx (Part 4)"
DELETE FROM `creature_text` WHERE `CreatureID`=3663;
DELETE FROM `creature_text` WHERE `CreatureID`=4509 AND `GroupID`=6;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3663,0,0,"A simple enough task to break this soulstone!",12,7,100,0,0,0,1459,0,"Delgren the Purifier"),
(3663,1,0,"Then we must put an end to Athrikus Narassin. Tell me, spirit, where might we find the other soulgems, to undo his magic?",12,7,100,6,0,0,1473,0,"Delgren the Purifier"),
(4509,6,0,"%s fades into the mist...",16,0,100,0,0,0,1476,0,"Sargath");

UPDATE `creature_template` SET `AIName`='' WHERE `entry`=4509;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4509 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3663 AND `id`=1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3663,0,1,0,20,0,100,0,970,0,0,0,80,366300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Quest \'The Tower of Althalaxx (Part 4)\' Finished - Run Script");

DELETE FROM `smart_scripts` WHERE `entryorguid`=366300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(366300,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Script - Remove Npc Flag Questgiver"),
(366300,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 0"),
(366300,9,2,0,0,0,100,0,4000,4000,0,0,12,4509,3,51000,0,0,0,8,0,0,0,3188.2,191.026,4.53698,3.6802,"Delgren the Purifier - On Script - Summon Sargath"),
(366300,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 0 (Sargath)"),
(366300,9,4,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 1 (Sargath)"),
(366300,9,5,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 2 (Sargath)"),
(366300,9,6,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 3 (Sargath)"),
(366300,9,7,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 4 (Sargath)"),
(366300,9,8,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 1"),
(366300,9,9,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 5 (Sargath)"),
(366300,9,10,0,0,0,100,0,7000,7000,0,0,1,6,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 6 (Sargath)"),
(366300,9,11,0,0,0,100,0,1000,1000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Script - Add Npc Flag Questgiver");
