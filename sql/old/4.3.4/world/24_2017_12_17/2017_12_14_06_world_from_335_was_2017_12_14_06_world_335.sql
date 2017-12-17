/*
-- Piznik
UPDATE `smart_scripts` SET `action_param2`=2 WHERE `entryorguid`=4276 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=427600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(427600,9,0,0,0,0,100,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Remove UNIT_FLAG_IMMUNE_TO_NPC"),
(427600,9,1,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Remove Questgiver flag"),
(427600,9,2,0,0,0,100,0,0,0,0,0,2,42,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Change Faction"),
(427600,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Say Line 0"),
(427600,9,4,0,0,0,100,0,10000,10000,0,0,12,3998,4,20000,0,0,0,8,0,0,0,938.3,-257.35,-2.22,0,"Piznik - On Script - Summon Windshear Vermin"),
(427600,9,5,0,0,0,100,0,0,0,0,0,12,3998,4,20000,0,0,0,8,0,0,0,942.28,-254.49,-2.38,0,"Piznik - On Script - Summon Windshear Vermin"),
(427600,9,6,0,0,0,100,0,0,0,0,0,12,4001,4,20000,0,0,0,8,0,0,0,938.52,-253.2,-2.08,0,"Piznik - On Script - Summon Windshear Tunnel Rat"),
(427600,9,7,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,4001,0,0,0,0,0,0,"Piznik - On Script - Say Line 0 (Windshear Tunnel Rat)"),
(427600,9,8,0,0,0,100,0,75000,75000,0,0,12,4002,4,20000,0,0,0,8,0,0,0,924.96,-266.582,-1.32596,0.620443,"Piznik - On Script - Summon Windshear Stonecutter"),
(427600,9,9,0,0,0,100,0,0,0,0,0,12,4002,4,20000,0,0,0,8,0,0,0,928.351,-268.308,-1.57308,0.769668,"Piznik - On Script - Summon Windshear Stonecutter"),
(427600,9,10,0,0,0,100,0,0,0,0,0,12,4003,4,20000,0,0,0,8,0,0,0,928.377,-264.272,-1.36686,0.871769,"Piznik - On Script - Summon Windshear Geomancer"),
(427600,9,11,0,0,0,100,0,0,0,0,0,12,4003,4,20000,0,0,0,8,0,0,0,932.595,-265.232,-1.86839,0.918893,"Piznik - On Script - Summon Windshear Geomancer"),
(427600,9,12,0,0,0,100,0,0,0,0,0,12,4004,4,20000,0,0,0,8,0,0,0,933.813,-261.041,-2.12867,0.930675,"Piznik - On Script - Summon Windshear Overlord"),
(427600,9,13,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,4004,0,0,0,0,0,0,"Piznik - On Script - Say Line 0 (Windshear Overlord)"),
(427600,9,14,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Say Line 1"),
(427600,9,15,0,0,0,100,0,120000,120000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Say Line 2"),
(427600,9,16,0,0,0,100,0,5000,5000,0,0,12,4001,4,20000,0,0,0,8,0,0,0,938.3,-257.35,-2.22,0,"Piznik - On Script - Summon Windshear Tunnel Rat"),
(427600,9,17,0,0,0,100,0,0,0,0,0,12,4001,4,20000,0,0,0,8,0,0,0,942.28,-254.49,-2.38,0,"Piznik - On Script - Summon Windshear Tunnel Rat"),
(427600,9,18,0,0,0,100,0,0,0,0,0,12,4001,4,20000,0,0,0,8,0,0,0,938.52,-253.2,-2.08,0,"Piznik - On Script - Summon Windshear Tunnel Rat"),
(427600,9,19,0,0,0,100,0,0,0,0,0,12,4004,4,20000,0,0,0,8,0,0,0,939.51,-253.11,-2.02,0,"Piznik - On Script - Summon Windshear Overlord"),
(427600,9,20,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,4004,0,0,0,0,0,0,"Piznik - On Script - Say Line 1 (Windshear Overlord)"),
(427600,9,21,0,0,0,100,0,100000,100000,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Set UNIT_FLAG_IMMUNE_TO_NPC"),
(427600,9,22,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Add Questgiver flag"),
(427600,9,23,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Change Faction"),
(427600,9,24,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Piznik - On Script - Say Line 3"),
(427600,9,25,0,0,0,100,0,0,0,0,0,15,1090,0,0,0,0,0,12,1,0,0,0,0,0,0,"Piznik - On Script - Complete quest 'Gerenzo's Orders'");

-- Windshear Vermin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3998;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3998 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3998,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Windshear Vermin - Just Summoned - Start Attacking");

-- Windshear Tunnel Rat
DELETE FROM `smart_scripts` WHERE `entryorguid`=4001 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4001,0,1,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Windshear Tunnel Rat - Just Summoned - Start Attacking");

-- Windshear Stonecutter
DELETE FROM `smart_scripts` WHERE `entryorguid`=4002 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4002,0,1,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Windshear Stonecutter - Just Summoned - Start Attacking");

-- Windshear Geomancer
DELETE FROM `smart_scripts` WHERE `entryorguid`=4003 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4003,0,3,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Windshear Geomancer - Just Summoned - Start Attacking");

-- Windshear Overlord
DELETE FROM `smart_scripts` WHERE `entryorguid`=4004 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4004,0,3,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Windshear Overlord - Just Summoned - Start Attacking");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (4276, 4001, 4004);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4276,0,0,"All right, watch my back while I get you some of this ore.",12,0,100,0,0,0,1427,0,"Piznik"),
(4276,1,0,"Look out! It sounds like more of them!",12,0,100,0,0,0,1431,0,"Piznik"),
(4276,2,0,"Just a little while longer, I've almost got it!",12,0,100,0,0,0,1432,0,"Piznik"),
(4276,3,0,"There, I've got it!",12,0,100,0,0,0,1434,0,"Piznik"),
(4001,0,0,"Hey! You're not supposed to be here! C'mon boys!",12,0,100,0,0,0,1428,0,"Windshear Tunnel Rat"),
(4004,0,0,"I think the sounds came from over here. We'd better check it out.",12,0,100,0,0,0,1430,0,"Windshear Overlord"),
(4004,1,0,"What's going on here? Piznik! I knew we shouldn't have let you stick around!",12,0,100,0,0,0,1433,0,"Windshear Overlord");
*/
