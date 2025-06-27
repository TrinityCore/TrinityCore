-- Completion Event for Quest "Elune's Tear"
DELETE FROM `creature_text` WHERE `CreatureID`=3892 AND `GroupID` IN (2,3);
DELETE FROM `creature_text` WHERE `CreatureID`=3894 AND `GroupID` IN (3,4,5);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3894,3,0,"%s places the tear into a bowl of stew.",16,0,100,0,0,0,1438,0,"Pelturas Whitemoon"),
(3894,4,0,"Eat this, my daughter.  It will help you feel better.",12,7,100,0,0,0,1439,0,"Pelturas Whitemoon"),
(3894,5,0,"There you go...",12,7,100,0,0,0,1440,0,"Pelturas Whitemoon"),
(3892,2,0,"%s stirs from her delirium.",16,0,100,0,0,0,1441,0,"Relara Whitemoon"),
(3892,3,0,"Mmmmh...",12,0,100,0,0,0,1442,0,"Relara Whitemoon");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3894 AND `id`=2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3894,0,2,0,20,0,100,0,1033,0,0,0,80,389401,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Quest \'Elune\'s Tear\' Finished - Run Script");

DELETE FROM `smart_scripts` WHERE `entryorguid`=389401 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(389401,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Remove Npc Flag Questgiver"),
(389401,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 3"),
(389401,9,2,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Run Off"),
(389401,9,3,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,2682.65,-456.624,109.234,0,"Pelturas Whitemoon - On Script - Move to Position"),
(389401,9,4,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389401,9,5,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 4"),
(389401,9,6,0,0,0,100,0,4000,4000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 5"),
(389401,9,7,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,2682.14,-454.808,109.233,0,"Pelturas Whitemoon - On Script - Move to Position"),
(389401,9,8,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 2 (Relara Whitemoon)"),
(389401,9,9,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389401,9,10,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 3 (Relara Whitemoon)"),
(389401,9,11,0,0,0,100,0,1000,1000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Add Npc Flag Questgiver");
