SET @Guid := 74948;

DELETE FROM `creature_text` WHERE `entry`=19228 AND `groupid`=0 AND `id`=5;
DELETE FROM `creature_text` WHERE `entry`=19228 AND `groupid`=17 AND `id` IN(3,4);
DELETE FROM `creature_text` WHERE `entry`=19228 AND `groupid`=28 AND `id`=4;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(19228, 0, 5, 'What a good looking crowd. The dwarven women even shaved.', 12, 0, 100, 21, 0, 0, 16648, 'Perry Gatner'),
(19228, 17, 3, 'Can I get a buff? I''m dying up here.', 12, 0, 100, 6, 0, 0, 16386, 'Perry Gatner'),
(19228, 17, 4, 'Come on!  These jokes are epic!', 12, 0, 100, 6, 0, 0, 16387, 'Perry Gatner'),
(19228, 28, 4, 'Thank you everyone!  And keep clapping, there is a fly in here and one of you are bound to get it!  Good night!', 12, 0, 100, 21, 0, 0, 16345, 'Perry Gatner');

DELETE FROM `creature`  WHERE `guid` IN(@GUID+0,@GUID+1,@GUID+2,@GUID+3) AND `id`=18152;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@GUID+0, 18152, 530, 0, 0, 1, 1, 15397, 0, 1177.666, 8130.762, 19.62192, 1.151917, 120, 0, 0, 247, 0, 0, 0, 0, 0, 0), -- 7853077
(@GUID+1, 18152, 530, 0, 0, 1, 1, 15394, 0, 1178.132, 8130.465, 19.65684, 1.117011, 120, 0, 0, 247, 0, 0, 0, 0, 0, 0), -- 16241685
(@GUID+2, 18152, 530, 0, 0, 1, 1, 15393, 0, 1178.688, 8130.183, 19.68922, 1.082104, 120, 0, 0, 247, 0, 0, 0, 0, 0, 0), -- 24630293
(@GUID+3, 18152, 530, 0, 0, 1, 1, 15396, 0, 1179.359, 8129.974, 19.69083, 1.012291, 120, 0, 0, 247, 0, 0, 0, 0, 0, 0); -- 33018901

DELETE FROM `event_scripts` WHERE  `id`=11424 AND `command`=10;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(11424, 3, 10, 19656, 10000, 0, 1176.53, 8130.83, 20.13, 1.86);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(1815200,1965602) AND `source_type`=9;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-@GUID-0,-@GUID-1,-@GUID-2,-@GUID-3) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =19656 AND `source_type`=0 AND `id`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(19656, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, 1965602, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - On Just Summoned - Run Script'),
(1965602, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @GUID+0, 18152, 0, 0, 0, 0, 0, 'Invisible Location Trigger Script - Respawn Baby Murloc #1'),
(1965602, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @GUID+1, 18152, 0, 0, 0, 0, 0, 'Invisible Location Trigger Script - Respawn Baby Murloc #2'),
(1965602, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @GUID+2, 18152, 0, 0, 0, 0, 0, 'Invisible Location Trigger Script - Respawn Baby Murloc #3'),
(1965602, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @GUID+3, 18152, 0, 0, 0, 0, 0, 'Invisible Location Trigger Script - Respawn Baby Murloc #4'),

(1965602, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID+0, 18152, 0, 0, 0, 0, 0, 'Invisible Location Trigger Script - Respawn Baby Murloc #1'),
(1965602, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID+1, 18152, 0, 0, 0, 0, 0, 'Invisible Location Trigger Script - Respawn Baby Murloc #2'),
(1965602, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID+2, 18152, 0, 0, 0, 0, 0, 'Invisible Location Trigger Script - Respawn Baby Murloc #3'),
(1965602, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID+3, 18152, 0, 0, 0, 0, 0, 'Invisible Location Trigger Script - Respawn Baby Murloc #4'),

(-@GUID-0, 0, 0, 0, 38, 0, 100, 0, 2, 2, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Data Set - Set Visible'),
(-@GUID-1, 0, 0, 0, 38, 0, 100, 0, 2, 2, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Data Set - Set Visible'),
(-@GUID-2, 0, 0, 0, 38, 0, 100, 0, 2, 2, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Data Set - Set Visible'),
(-@GUID-3, 0, 0, 0, 38, 0, 100, 0, 2, 2, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Data Set - Set Visible'),
(-@GUID-0, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 1815200, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Data Set - Start WP'),
(-@GUID-1, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 1815201, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Data Set - Start WP'),
(-@GUID-2, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 1815202, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Data Set - Start WP'),
(-@GUID-3, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 1815203, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Data Set - Start WP'),
(-@GUID-0, 0, 2, 3, 34, 0, 100, 0, 0, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.375614, 'Baby Murloc - On Reached WP1 - Set Orientation'),
(-@GUID-1, 0, 2, 3, 34, 0, 100, 0, 0, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.886922, 'Baby Murloc - On Reached WP1 - Set Orientation'),
(-@GUID-2, 0, 2, 3, 34, 0, 100, 0, 0, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.159046, 'Baby Murloc - On Reached WP1 - Set Orientation'),
(-@GUID-3, 0, 2, 3, 34, 0, 100, 0, 0, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.9147, 'Baby Murloc - On Reached WP1 - Set Orientation'),
(-@GUID-0, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1815200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Run Script'),
(-@GUID-1, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1815200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Run Script'),
(-@GUID-2, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1815200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Run Script'),
(-@GUID-3, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1815200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Run Script'),
(-@GUID-0, 0, 4, 5, 11, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Set Visible'),
(-@GUID-1, 0, 4, 5, 11, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Set Visible'),
(-@GUID-2, 0, 4, 5, 11, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Set Visible'),
(-@GUID-3, 0, 4, 5, 11, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Set Visible'),
(-@GUID-0, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Set Emote State'),
(-@GUID-1, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Set Emote State'),
(-@GUID-2, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Set Emote State'),
(-@GUID-3, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - On Respawn - Set Emote State'),

(1815200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 32040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - Script - Cast Scare Daggerfen'),
(1815200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - Script - Set Emote State'),
(1815200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 18000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Baby Murloc - Script - Despawn');

DELETE FROM `waypoints` WHERE `entry` BETWEEN 1815200 AND 1815203;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(1815200, 1, 1169.526, 8146.214, 19.41322, 'Baby Murloc'),
(1815201, 1, 1184.131, 8162.72, 18.72033, 'Baby Murloc'),
(1815202, 1, 1205.028, 8157.705, 18.43147, 'Baby Murloc'),
(1815203, 1, 1204.707, 8140.139, 18.77224, 'Baby Murloc');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND  `SourceGroup`=2 AND `SourceEntry`=19656;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=32040;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 32040, 0, 0, 31, 0, 3, 18115, 0, 0, 0, 0, '', 'Scare Daggerfen targets Daggerfen Muckdweller'),
(13, 1, 32040, 0, 1, 31, 0, 3, 18116, 0, 0, 0, 0, '', 'Scare Daggerfen targets Daggerfen Assasin'),
(22, 2, 19656, 0, 0, 23, 1, 3640, 0, 0, 0, 0, 0, '', '');
