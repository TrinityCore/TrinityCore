-- Completion Event for Quest "The Ruins of Stardust"
DELETE FROM `creature_text` WHERE `CreatureID`=3894 AND `GroupID` IN (6,7);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3894,6,0,"%s places a poultice on Relara's head.",16,0,100,0,0,0,1443,0,"Pelturas Whitemoon"),
(3894,7,0,"%s breathes a sigh of relief.",16,0,100,0,0,0,1444,0,"Pelturas Whitemoon");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3894 AND `id`=3 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3894,0,3,0,20,0,100,0,1034,0,0,0,80,389402,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Quest \'The Ruins of Stardust\' Finished - Run Script");

DELETE FROM `smart_scripts` WHERE `entryorguid`=389402 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(389402,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Remove Npc Flag Questgiver"),
(389402,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Run Off"),
(389402,9,2,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,2682.65,-456.624,109.234,0,"Pelturas Whitemoon - On Script - Move to Position"),
(389402,9,3,0,0,0,100,0,1500,1500,0,0,66,0,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389402,9,4,0,0,0,100,0,1000,1000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 6"),
(389402,9,5,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,2682.14,-454.808,109.233,0,"Pelturas Whitemoon - On Script - Move to Position"),
(389402,9,6,0,0,0,100,0,1500,1500,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389402,9,7,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 7"),
(389402,9,8,0,0,0,100,0,1000,1000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Add Npc Flag Questgiver");
