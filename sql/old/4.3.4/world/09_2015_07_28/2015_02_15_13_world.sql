--
SET @CGUID := 56502; -- needs 3
DELETE FROM `creature` WHERE `guid` IN (@CGUID+0, @CGUID+1, @CGUID+2);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 26620, 600, 3, 1, -522.7039, -605.9083, 1.299988, 2.6529, 7200, 0, 0), -- 26620 (Area: 4196) (Auras: 47503 - 47503)
(@CGUID+1, 26620, 600, 3, 1, -518.0062, -599.1102, 1.10835, 3.054326, 7200, 0, 0), -- 26620 (Area: 4196) (Auras: 47503 - 47503)
(@CGUID+2, 26626, 600, 3, 1, -511.0887, -602.5585, 2.56744, 3.193953, 7200, 0, 0); -- 26626 (Area: 4196)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+0, @CGUID+1);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@CGUID+0, 0, 0, 0, 0, 0, '47503'),
(@CGUID+1, 0, 0, 0, 0, 0, '47503');

UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=26626 AND `source_type`=0 AND `id`=0 AND `link`=1;

-- Scourge Reanimator SAI
SET @GUID := -@CGUID+2;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26626;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,2,25,0,100,1,0,0,0,0,80,2662600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Reset - Run Script (No Repeat)"),
(@GUID,0,1,0,40,0,100,0,1,2662600,0,0,80,2662601,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Waypoint 1 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 2662600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,53,1,2662600,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 2662601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,@CGUID,26620,0,0,0,0,0,"Scourge Reanimator - On Script - Set Data 1 1"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,@CGUID+1,26620,0,0,0,0,0,"Scourge Reanimator - On Script - Set Data 1 1"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,11,48597,0,0,0,0,0,10,@CGUID+1,26620,0,0,0,0,0,"Scourge Reanimator - On Script - Cast 'Raise Dead'"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,12,26635,3,600000,0,0,0,8,0,0,0,-536.830505,-578.793091,1.91333,1.774444,"Scourge Reanimator - On Script - Summon Creature 'Risen Drakkari Warrior'"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,11,48597,0,0,0,0,0,10,@CGUID,26620,0,0,0,0,0,"Scourge Reanimator - On Script - Cast 'Raise Dead'"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,12,26635,3,600000,0,0,0,8,0,0,0,-543.121582,-582.083313,1.025425,2.120673,"Scourge Reanimator - On Script - Summon Creature 'Risen Drakkari Warrior'"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Say Line 2"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,11,47506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Cast 'Teleport'"),
(@ENTRY,9,8,0,0,0,100,0,1500,1500,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Despawn Instant");

DELETE FROM `waypoints` WHERE `entry`=2662600;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2662600, 1, -533.262695, -591.052856, 2.484161, 'Scourge Reanimator');

-- Drakkari Guardian SAI
SET @GUID := -@CGUID; 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,1,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-543.121582,-582.083313,1.025425,2.120673,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(@GUID,0,1,0,38,0,100,0,1,1,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Kill Self");

-- Drakkari Guardian SAI   
SET @GUID := -@CGUID+1; 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,1,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-536.830505,-578.793091,1.913330,1.774444,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(@GUID,0,1,0,38,0,100,0,1,1,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Kill Self");

-- Risen Drakkari Warrior SAI
SET @ENTRY := 26635;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,5000,9500,11,36093,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast 'Ghost Strike' (Dungeon)"),
(@ENTRY,0,1,0,0,0,100,6,1000,3000,7250,10000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast 'Crush Armor' (Dungeon)"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Just Summoned - Start Random Movement");

DELETE FROM `creature_text` WHERE `entry`=26626;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(26626, 0, 0, 'Don''t be so quick to escape! I have a parting gift....', 14, 0, 100, 0, 0, 0, 26474, 0, 'Scourge Reanimator'),
(26626, 1, 0, 'Rise my warriors and fight for your new liege!', 14, 0, 100, 0, 0, 0, 26464, 0, 'Scourge Reanimator'),
(26626, 2, 0, 'Please enjoy their company, the Lich King sends his regards!', 14, 0, 100, 0, 0, 0, 26473, 0, 'Scourge Reanimator');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=48597;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 48597, 0, 0, 31, 0, 3, 26620, 0, 0, 0, 0, '', 'Raise Dead - only targets Drakkari Guardian');

DELETE FROM `creature` WHERE `guid` IN (127436, 127437);
