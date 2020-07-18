-- World Invisible Trigger
SET @GUID1 := 3828;
SET @GUID2 := 37624;
SET @GUID3 := 38824;
DELETE FROM `creature` WHERE `guid` IN (@GUID1,@GUID2,@GUID3);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID1,12999,1,0,0,1,1,0,0,-3759.97,-4557.44,9.0761,5.34286,300,0,0,7212,0,0,0,0,0,"",0),
(@GUID2,12999,1,0,0,1,1,0,0,-3758.24,-4556.73,11.3539,2.10228,300,0,0,7212,0,0,0,0,0,"",0),
(@GUID3,12999,1,0,0,1,1,0,0,-3758.42,-4551.63,10.8395,2.1337,300,0,0,7212,0,0,0,0,0,"",0);

-- Guard Lasiter
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=30458;
UPDATE `creature_addon` SET `path_id`=0, `bytes2`=2 WHERE `guid`=30458;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4973;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4973 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (497300,497301,497302,497303) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4973,0,0,0,25,0,100,0,0,0,0,0,0,53,0,4973,1,0,0,2,1,0,0,0,0,0,0,0,"Guard Lasiter - On Reset - Start Waypoint"),
(4973,0,1,0,40,0,100,0,1,4973,0,0,0,80,497300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Waypoint 1 Reached - Run Script"),
(4973,0,2,0,40,0,100,0,2,4973,0,0,0,80,497301,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Waypoint 2 Reached - Run Script"),
(4973,0,3,0,40,0,100,0,3,4973,0,0,0,80,497302,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Waypoint 3 Reached - Run Script"),
(4973,0,4,0,40,0,100,0,4,4973,0,0,0,80,497303,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Waypoint 4 Reached - Run Script"),
(4973,0,5,0,0,0,100,0,0,0,2000,4000,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Lasiter - In Combat - Cast Shoot"),
(4973,0,6,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Guard Lasiter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(497300,9,0,0,0,0,100,0,0,0,0,0,0,54,18000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Script - Pause Waypoint"),
(497300,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.36274,"Guard Lasiter - On Script - Set Orientation"),
(497300,9,2,0,0,0,100,0,2000,2000,0,0,0,11,45425,0,0,0,0,0,10,@GUID1,0,0,0,0,0,0,"Guard Lasiter - On Script - Cast 'Shoot'"),
(497300,9,3,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Script - Say Line 0"),
(497301,9,0,0,0,0,100,0,0,0,0,0,0,54,18000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Script - Pause Waypoint"),
(497301,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.36274,"Guard Lasiter - On Script - Set Orientation"),
(497301,9,2,0,0,0,100,0,2000,2000,0,0,0,11,45425,0,0,0,0,0,10,@GUID2,0,0,0,0,0,0,"Guard Lasiter - On Script - Cast 'Shoot'"),
(497301,9,3,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Script - Say Line 1"),
(497302,9,0,0,0,0,100,0,0,0,0,0,0,54,18000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Script - Pause Waypoint"),
(497302,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.36274,"Guard Lasiter - On Script - Set Orientation"),
(497302,9,2,0,0,0,100,0,2000,2000,0,0,0,11,45425,0,0,0,0,0,10,@GUID3,0,0,0,0,0,0,"Guard Lasiter - On Script - Cast 'Shoot'"),
(497302,9,3,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Script - Say Line 2"),
(497303,9,0,0,0,0,100,0,0,0,0,0,0,54,18000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Script - Pause Waypoint"),
(497303,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.36274,"Guard Lasiter - On Script - Set Orientation"),
(497303,9,2,0,0,0,100,0,2000,2000,0,0,0,11,45425,0,0,0,0,0,10,30524,0,0,0,0,0,0,"Guard Lasiter - On Script - Cast 'Shoot'"),
(497303,9,3,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Lasiter - On Script - Say Line 3");

DELETE FROM `creature_text` WHERE `CreatureID`=4973;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4973,0,0,"Oops! That was a bit off. I didn't even hit the target!",12,7,100,0,0,0,1792,0,"Guard Lasiter"),
(4973,1,0,"That was a nice shot... but not perfect. Maybe a bit more to the left.",12,7,100,0,0,0,1789,0,"Guard Lasiter"),
(4973,2,0,"Barely hit the target that time. Hmmm,... maybe I need to adjust back to the right.",12,7,100,0,0,0,1790,0,"Guard Lasiter"),
(4973,3,0,"Whoa! Look at that bullseye!",12,7,100,0,0,0,1791,0,"Guard Lasiter");

DELETE FROM `waypoint_data` WHERE `id`=304580;
DELETE FROM `waypoints` WHERE `entry`=4973;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(4973,1,-3775.88,-4535.66,11.7979,""),
(4973,2,-3772.62,-4533.36,11.5873,""),
(4973,3,-3770.08,-4531.74,11.5426,""),
(4973,4,-3772.62,-4533.36,11.5873,"");
