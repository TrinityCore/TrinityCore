-- Completion Event for Quest "Fallen Sky Lake"
DELETE FROM `creature_text` WHERE `CreatureID`=3892 AND `GroupID`=4;
DELETE FROM `creature_text` WHERE `CreatureID`=3894 AND `GroupID` IN (8,9,10,11,12,13);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3894,8,0,"%s crushes the moonstones into a cup of tea.",16,0,100,0,0,0,1346,0,"Pelturas Whitemoon"),
(3894,9,0,"Here you are, Relara.  Drink this...",12,7,100,16,0,0,1347,0,"Pelturas Whitemoon"),
(3894,10,0,"Relara... you're awake?",12,7,100,0,0,0,1350,0,"Pelturas Whitemoon"),
(3894,11,0,"Rest now, my daughter.",12,7,100,1,0,0,1351,0,"Pelturas Whitemoon"),
(3894,12,0,"%s looks at $n, and then weeps with joy.",16,0,100,0,0,0,1352,0,"Pelturas Whitemoon"),
(3894,13,0,"Relara is saved, $n.  Thank you.",12,7,100,18,0,0,1353,0,"Pelturas Whitemoon"),
(3892,4,0,"Mmh... my eyes are not so heavy now, father.  Can we go out and play?",12,7,100,0,0,0,1349,0,"Relara Whitemoon");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3894 AND `id`=4 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3894,0,4,0,20,0,100,0,1035,0,0,0,80,389403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Quest \'Fallen Sky Lake\' Finished - Run Script");

DELETE FROM `smart_scripts` WHERE `entryorguid`=389403 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(389403,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Remove Npc Flag Questgiver"),
(389403,9,1,0,0,0,100,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 8"),
(389403,9,2,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389403,9,3,0,0,0,100,0,500,500,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 9"),
(389403,9,4,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389403,9,5,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 4 (Relara Whitemoon)"),
(389403,9,6,0,0,0,100,0,3000,3000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 10"),
(389403,9,7,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389403,9,8,0,0,0,100,0,4000,4000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 11"),
(389403,9,9,0,0,0,100,0,2000,2000,0,0,1,12,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 12"),
(389403,9,10,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389403,9,11,0,0,0,100,0,0,0,0,0,1,13,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 13"),
(389403,9,12,0,0,0,100,0,2000,2000,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Play Emote Bow"),
(389403,9,13,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389403,9,14,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Add Npc Flag Questgiver");
