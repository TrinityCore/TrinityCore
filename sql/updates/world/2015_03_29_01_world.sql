-- Taking Part
-- Fertile Mound Bunny SAI
SET @ENTRY := 36123;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,68355,0,0,0,33,36123,0,0,0,0,0,7,20,0,0,0,0,0,0,"Fertile Mound Bunny - On Spellhit 'Plant Seeds' - Quest Credit 'Taking Part'"),
(@ENTRY,0,1,2,61,0,100,0,68355,0,0,0,45,1,0,0,0,0,0,20,195687,10,0,0,0,0,0,"Fertile Mound Bunny - On Spellhit 'Plant Seeds' - Set Data 1 0"),
(@ENTRY,0,2,0,61,0,100,0,68355,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fertile Mound Bunny - On Spellhit 'Plant Seeds' - Despawn Instant");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=68355;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 68355, 0, 0, 31, 0, 3, 36123, 0, 0, 0, 0, '', 'Plant Seeds only targets Fertile Mound Bunny');

-- Fertile Mound SAI
SET @ENTRY := 195687;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,0,1,0,0,0,70,180,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fertile Mound - On Data Set 1 0 - Respawn Self");

DELETE FROM `gameobject_template` WHERE `entry`=300206;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES 
(300206, 8, 0, 'TEMP Fertile Mound', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 1631, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0);

SET @OGUID := 224765;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(@OGUID+0, 300206, 1, 0, 0, 1, 1, 0, 0, -1303.52, 1627.32, 64.5241, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+1, 300206, 1, 0, 0, 1, 1, 0, 0, -1303.77, 1593.97, 62.9723, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+2, 300206, 1, 0, 0, 1, 1, 0, 0, -1068.2, 1887.38, 60.2275, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+3, 300206, 1, 0, 0, 1, 1, 0, 0, -1231.54, 1473.07, 63.6275, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+4, 300206, 1, 0, 0, 1, 1, 0, 0, -1294.44, 1496.29, 62.857, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+5, 300206, 1, 0, 0, 1, 1, 0, 0, -1340.84, 1389.97, 63.9532, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+6, 300206, 1, 0, 0, 1, 1, 0, 0, -1266.05, 1404.07, 63.38, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+7, 300206, 1, 0, 0, 1, 1, 0, 0, -1308.6, 1384.82, 62.7546, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+8, 300206, 1, 0, 0, 1, 1, 0, 0, -1103.98, 1303.44, 90.5823, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+9, 300206, 1, 0, 0, 1, 1, 0, 0, -1084.24, 1416.61, 61.7715, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+10, 300206, 1, 0, 0, 1, 1, 0, 0, -1090.97, 1385.4, 61.9833, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+11, 300206, 1, 0, 0, 1, 1, 0, 0, -872.094, 1828.09, 62.0108, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+12, 300206, 1, 0, 0, 1, 1, 0, 0, -922.672, 1926.03, 60.8396, 0, 0, 0, 0, 1, 120, 255, 1, 0),
(@OGUID+13, 300206, 1, 0, 0, 1, 1, 0, 0, -1049.99, 1358.8, 65.7721, 0, 0, 0, 0, 1, 120, 255, 1, 0);
