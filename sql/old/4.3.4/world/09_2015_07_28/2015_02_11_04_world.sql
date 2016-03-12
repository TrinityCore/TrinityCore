--
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=26191;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(26191, 46978, 2, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=26191 AND `SourceEntry`=46978;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 26191, 46978, 0, 0, 9, 0, 11956, 0, 0, 0, 0, 0, '', 'Required quest ''Finding the Phylactery'' active for spellclick');

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `rank`=3, `speed_walk`=2.5, `speed_run`=2.5 WHERE `entry`=28182;

-- Dusk SAI
SET @ENTRY := 28182;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,28182,0,0,0,0,1,0,0,0,0,0,0,0,"Dusk - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,21,28182,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dusk - On Waypoint 21 Reached - Despawn Instant"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dusk - On Just Summoned - Set Reactstate Passive"),
(@ENTRY,0,3,0,28,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dusk - On Passenger Removed - Despawn Instant");

DELETE FROM `waypoints` WHERE `entry`=28182;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(28182, 1,3137.103,3835.605,23.80482, 'Dusk'),
(28182, 2,3151.105,3841.837,26.15598, 'Dusk'),
(28182, 3,3190.882,3844.668,28.8679, 'Dusk'),
(28182, 4,3232.1,3838.992,27.33721, 'Dusk'),
(28182, 5,3282.762,3832.855,27.20968, 'Dusk'),
(28182, 6,3307.908,3829.667,28.43119, 'Dusk'),
(28182, 7,3340.627,3826.012,25.35527, 'Dusk'),
(28182, 8,3352.079,3823.348,27.22523, 'Dusk'),
(28182, 9,3399.218,3818.613,27.66385, 'Dusk'),
(28182, 10,3439.386,3828.509,27.79152, 'Dusk'),
(28182, 11,3456.517,3835.027,29.58427, 'Dusk'),
(28182, 12,3482.749,3841.445,32.40864, 'Dusk'),
(28182, 13,3531.002,3843.39,33.53048, 'Dusk'),
(28182, 14,3549.508,3830.051,39.22393, 'Dusk'),
(28182, 15,3561.163,3818.268,40.28746, 'Dusk'),
(28182, 16,3573.922,3785.856,36.752, 'Dusk'),
(28182, 17,3574.622,3781.316,36.74898, 'Dusk'),
(28182, 18,3583.712,3758.963,36.55262, 'Dusk'),
(28182, 19,3603.148,3712.664,36.74012, 'Dusk'),
(28182, 20,3605.655,3702.697,36.80239, 'Dusk'),
(28182, 21,3618.601,3670.745,35.97186, 'Dusk');
