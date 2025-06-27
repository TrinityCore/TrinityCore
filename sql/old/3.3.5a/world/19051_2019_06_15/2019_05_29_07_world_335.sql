-- 
UPDATE `creature_template` SET `faction`=15, `MovementType`=2 WHERE `entry`=15571;
DELETE FROM `creature_template_addon` WHERE `entry`=15571;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `path_id`,`bytes2`) VALUES
(15571,0,155710,0);

DELETE FROM `waypoint_data` WHERE `id`=155710;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(155710, 1, 3561.725098, -6647.203613, -7.5, 0, 0, 0, 100, 0),
(155710, 2, 3569.491211, -6601.534668, -7.5, 0, 0, 0, 100, 0),
(155710, 3, 3567.581787, -6601.534668, -7.5, 0, 0, 0, 100, 0),
(155710, 4, 3556.089844, -6580.337402, -7.5, 0, 0, 0, 100, 0),
(155710, 5, 3535.929199, -6566.029785, -7.5, 0, 0, 0, 100, 0),
(155710, 6, 3512.707275, -6560.118164, -7.5, 0, 0, 0, 100, 0),
(155710, 7, 3481.141113, -6564.093262, -7.5, 0, 0, 0, 100, 0),
(155710, 8, 3471.087158, -6577.640137, -7.5, 0, 0, 0, 100, 0),
(155710, 9, 3457.589844, -6601.105957, -7.5, 0, 0, 0, 100, 0),
(155710, 10, 3455.857666, -6626.840820, -7.5, 0, 0, 0, 100, 0),
(155710, 11, 3464.808838, -6650.078613, -7.5, 0, 0, 0, 100, 0),
(155710, 12, 3482.844238, -6667.317383, -7.5, 0, 0, 0, 100, 0),
(155710, 13, 3506.620361, -6675.020020, -7.5, 0, 0, 0, 100, 0),
(155710, 14, 3525.413330, -6673.905273, -7.5, 0, 0, 0, 100, 0);

UPDATE `gameobject_template` SET `size`=4 WHERE `entry` IN (180669);
UPDATE `gameobject_template_addon` SET `flags`=16 WHERE `entry`=183356;
DELETE FROM `gameobject` WHERE `id`=183356 AND guid IN (8987, 8988, 8989, 8990, 8991, 9002);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(8987, 183356, 1, 1, 1, 3512.291111, -6618.081111, 0.011111, 5.12104, 0, 0, -0.548921, 0.835874, -1, 0, 1, 0),
(8988, 183356, 1, 1, 1, 3482.834473, -6614.127441, 0.001455, 5.12104, 0, 0, -0.548921, 0.835874, -1, 0, 1, 0),
(8989, 183356, 1, 1, 1, 3503.843994, -6587.510254, 0.001494, 5.12104, 0, 0, -0.548921, 0.835874, -1, 0, 1, 0),
(8990, 183356, 1, 1, 1, 3528.338623, -6595.350586, 0.001393, 5.12104, 0, 0, -0.548921, 0.835874, -1, 0, 1, 0),
(8991, 183356, 1, 1, 1, 3537.406738, -6615.951660, 0.001530, 5.12104, 0, 0, -0.548921, 0.835874, -1, 0, 1, 0),
(9002, 183356, 1, 1, 1, 3521.293457, -6643.015137, 0.001507, 5.12104, 0, 0, -0.548921, 0.835874, -1, 0, 1, 0);

DELETE FROM `event_scripts` WHERE `id`=9542;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(9542, 0, 10, 15571, 9000000, 0, 3561.73, -6647.2, -7.5, 0),
(9542, 0, 9, 8987, 60, 0, 0, 0, 0, 0),
(9542, 0, 9, 8988, 60, 0, 0, 0, 0, 0),
(9542, 0, 9, 8989, 60, 0, 0, 0, 0, 0),
(9542, 0, 9, 8990, 60, 0, 0, 0, 0, 0),
(9542, 0, 9, 8991, 60, 0, 0, 0, 0, 0),
(9542, 0, 9, 9002, 60, 0, 0, 0, 0, 0);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=183356;
DELETE FROM `smart_scripts` WHERE `entryorguid`=183356 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(183356,1,0,0,60,0,100,0,3000,6000,3000,6000,93,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - On Data Set - Increment Phase");

DELETE FROM `conditions` WHERE `SourceEntry`=25783 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(17,0,25783,0,0,29,0,15571,100,0,1,0,0,'Place Arcanite Buoy cannot be used if Maws is spawned');
