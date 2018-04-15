/*
-- Common Kitten
DELETE FROM `creature_text` WHERE `CreatureID` IN (9937,9936);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9937,0,0,"%s jumps into the moonwell, and goes underwater...",16,0,100,0,0,0,5939,0,"Common Kitten"),
(9936,1,0,"%s follows $n obediently.",16,0,100,0,0,0,5940,0,"Corrupted Kitten");

DELETE FROM `smart_scripts` WHERE `entryorguid`=9937 AND `source_type`=0 AND `id` IN (0,1,2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=993700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9937,0,0,0,54,0,100,0,0,0,0,0,80,993700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Common Kitten - On Just Summoned - Run Script"),
(993700,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Common Kitten - On Script - Set Rooted On"),
(993700,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Common Kitten - On Script - Say Line 0"),
(993700,9,2,0,0,0,100,0,4000,4000,0,0,36,9936,0,0,0,0,0,1,0,0,0,0,0,0,0,"Common Kitten - On Script - Update Template To 'Corrupted Kitten'"),
(993700,9,3,0,0,0,100,0,0,0,0,0,11,16510,0,0,0,0,0,1,0,0,0,0,0,0,0,"Common Kitten - On Script - Cast 'Corrupted Saber Visual (DND)'"),
(993700,9,4,0,0,0,100,0,0,0,0,0,3,10042,0,0,0,0,0,1,0,0,0,0,0,0,0,"Common Kitten - On Script - Morph to Entry 'Corrupted Kitten'"),
(993700,9,5,0,0,0,100,0,2000,2000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Common Kitten - On Script - Set Rooted Off"),
(993700,9,6,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Common Kitten - On Script - Say Line 1");

DELETE FROM `gossip_menu` WHERE `MenuID`=55002; -- Add Gossip Text
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(55002,3550,0);
*/
