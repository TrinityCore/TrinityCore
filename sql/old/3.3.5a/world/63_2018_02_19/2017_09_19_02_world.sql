-- Completion Event for Quest "Orendil's Cure"
DELETE FROM `creature_text` WHERE `CreatureID`=3892 AND `GroupID` IN (0,1);
DELETE FROM `creature_text` WHERE `CreatureID`=3894 AND `GroupID` IN (0,1,2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3894,0,0,"Here you are, Relara.  Take this...",12,7,100,0,0,0,1335,0,"Pelturas Whitemoon"),
(3894,1,0,"What?",12,7,100,0,0,0,1338,0,"Pelturas Whitemoon"),
(3894,2,0,"You\'re awake??  Your cure must have worked!  Thank you, $n.",12,7,100,0,0,0,1339,0,"Pelturas Whitemoon"),
(3892,0,0,"%s drinks the cure brought by $n.",16,0,100,0,0,0,1336,0,"Relara Whitemoon"),
(3892,1,0,"Uh... Father...?  Are you there?  I\'m hungry... can I have some stew?",12,7,100,0,0,0,1337,0,"Relara Whitemoon");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3894;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3894 AND `id` IN (0,1) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3894,0,0,1,20,0,100,0,1020,0,0,0,80,389400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Quest \'Orendil\'s Cure\' Finished - Run Script"),
(3894,0,1,0,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Quest \'Orendil\'s Cure\' Finished - Store Targetlist");

DELETE FROM `smart_scripts` WHERE `entryorguid`=389400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(389400,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Remove Npc Flag Questgiver"),
(389400,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389400,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 0"),
(389400,9,3,0,0,0,100,0,2000,2000,0,0,100,1,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Send Target"),
(389400,9,4,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Data"),
(389400,9,5,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389400,9,6,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 1 (Relara Whitemoon)"),
(389400,9,7,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 1"),
(389400,9,8,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,3892,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389400,9,9,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Say Line 2"),
(389400,9,10,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389400,9,11,0,0,0,100,0,0,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Play Emote Bow"),
(389400,9,12,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Set Orientation"),
(389400,9,13,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pelturas Whitemoon - On Script - Add Npc Flag Questgiver");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3892 AND `id`=1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3892,0,1,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Relara Whitemoon - On Data Set - Say Line 0");

UPDATE `smart_scripts` SET `action_param1`=46765 WHERE `entryorguid`=3892 AND `id`=0;
