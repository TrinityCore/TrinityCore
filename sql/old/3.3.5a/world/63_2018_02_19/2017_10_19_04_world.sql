-- 
SET @GUID := 52124;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `MovementType`, `spawntimesecs`) VALUES
(@GUID   , 24014, 571, 2822.969, -3821.093, 250.2894, 5.283523, 2, 180),
(@GUID+1 , 23991, 571, 2827.572, -3878.741, 244.6476, 0.5759587, 0, 180),
(@GUID+2 , 23991, 571, 2860.433, -3828.301, 244.6628, 3.700098, 0, 180),
(@GUID+3 , 23991, 571, 2873.868, -3847.195, 244.6476, 3.857178, 0, 180),
(@GUID+4 , 23989, 571, 2841.556, -3848.825, 250.2405, 2.234021, 0, 180),
(@GUID+5 , 23991, 571, 2815.462, -3858.984, 244.6625, 0.5934119, 0, 180),
(@GUID+6 , 24014, 571, 2793.005, -3798.1, 255.5297, 1.850049, 0, 180),
(@GUID+7 , 24014, 571, 2811.807, -3785.855, 255.2564, 2.426008, 0, 180),
(@GUID+8 , 23992, 571, 2770.91, -3814.297, 255.1113, 0.6981317, 0, 180),
(@GUID+9 , 23992, 571, 2834.249, -3770.08, 255.1043, 3.630285, 0, 180),
(@GUID+10, 23990, 571, 2896.34, -3891.98, 248.537, 2.16955, 0, 180),
(@GUID+11, 23990, 571, 2861.66, -3916.08, 248.537, 2.15934, 0, 180),
(@GUID+12, 24014, 571, 2864.88, -3898.45, 248.492, 5.31899, 0, 180),
(@GUID+13, 24014, 571, 2879.18, -3888.82, 248.493, 5.32292, 0, 180),
(@GUID+14, 23989, 571, 2887.71, -3881.55, 248.53, 5.3025, 2, 180);

DELETE FROM `creature_addon` WHERE `guid` IN (@GUID, @GUID+14);
INSERT INTO `creature_addon` (`guid`, `path_id`) VALUES
(@GUID, 521240),
(@GUID+14, 521380);

DELETE FROM `waypoint_data` WHERE `id` IN (521380, 521240);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(521380, 1, 2892.08, -3887.31, 248.54),
(521380, 2, 2859.36, -3909.38, 248.54),
(521380, 3, 2855.12, -3903.63, 248.53),
(521380, 4, 2859.36, -3909.38, 248.54),
(521380, 5, 2892.08, -3887.31, 248.54),
(521380, 6, 2887.71, -3881.55, 248.53),
(521240, 1, 2822.969, -3821.093, 250.2894),
(521240, 2, 2836.028, -3838.971, 244.5654),
(521240, 3, 2860.475, -3838.368, 244.5757),
(521240, 4, 2870.012, -3852.968, 244.5758),
(521240, 5, 2875.005, -3861.569, 244.5763),
(521240, 6, 2858.624, -3839.253, 244.5774),
(521240, 7, 2836.028, -3838.971, 244.5654);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24023, 2402300, -74518, -74519, -74520, 2401400, 24014) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24023, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 11, 44473, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, "Queen Angerboda - OOC - Cast 'Queen Angerboda: Soul Beam'"),
(24023, 0, 1, 2, 4, 0, 100, 0, 0, 0, 0, 0, 92, 0, 44473, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Queen Angerboda - On Aggro - Interupt Cast"),
(24023, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42808, 0, 0, 0, 0, 0, 19, 24014, 17, 0, 0, 0, 0, 0, "Queen Angerboda - On Aggro - Cast 'Queen Angerboda's On Reaction 2 Beam'"),
(24023, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Queen Angerboda - On Aggro - Say Line 0"),
(24023, 0, 4, 5, 6, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Queen Angerboda - On Death - Say Line 1"),
(24023, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 29394, 1, 60000, 0, 0, 0, 8, 0, 0, 0, 2850.26, -3872.01, 248.613, 1.41372, "Queen Angerboda - On Death - Summon 'The Lich King'"),
(24023, 0, 6, 7, 25, 0, 100, 512, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, 74518, 24014, 0, 0, 0, 0, 0, "Queen Angerboda - On Reset - Respawn Necrolord 1"),
(24023, 0, 7, 8, 61, 0, 100, 512, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, 74519, 24014, 0, 0, 0, 0, 0, "Queen Angerboda - On Reset - Respawn Necrolord 2"),
(24023, 0, 8, 0, 61, 0, 100, 512, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, 74520, 24014, 0, 0, 0, 0, 0, "Queen Angerboda - On Reset - Respawn Necrolord 3"),
(24023, 0, 10, 0, 1, 0, 100, 0, 0, 45000, 45000, 90000, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Queen Angerboda - OOC - Say Line 2"),
(24023, 0, 11, 0, 0, 0, 100, 0, 2000, 2000, 3000, 3500, 11, 9053, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Queen Angerboda - IC - Cast Fireball"),
(24023, 0, 12, 0, 0, 0, 100, 0, 4000, 5000, 12000, 15000, 11, 43560, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Queen Angerboda - IC - Cast Anger of Gjalerbron"),
(24023, 0, 13, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 11831, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Queen Angerboda - IC - Cast Frost Nova"),
(-74518, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On Respawn - Set Root On"),
(-74518, 0, 1, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On Aggro - Say Line 0"),
(-74518, 0, 2, 0, 1, 0, 100, 0, 0, 0, 3000, 3000, 11, 44473, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, "Necrolord - OOC - Cast Queen Angerboda: Soul Beam"),
(-74518, 0, 3, 0, 8, 0, 100, 1, 42808, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On Data Set - Die"),
(-74518, 0, 4, 0, 0, 0, 100, 0, 2000, 3000, 3000, 3500, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Cast Shadow Bolt"),
(-74518, 0, 5, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 17173, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Drain Life"),
(-74518, 0, 6, 0, 0, 0, 100, 0, 5000, 8000, 25000, 30000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Curse of Weakness"),
(-74519, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On Respawn - Set Root On"),
(-74519, 0, 1, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On Aggro - Say Line 0"),
(-74519, 0, 2, 0, 1, 0, 100, 0, 0, 0, 3000, 3000, 11, 44473, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, "Necrolord - OOC - Cast Queen Angerboda: Soul Beam"),
(-74519, 0, 3, 0, 8, 0, 100, 1, 42808, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On Data Set - Die"),
(-74519, 0, 4, 0, 0, 0, 100, 0, 2000, 3000, 3000, 3500, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Cast Shadow Bolt"),
(-74519, 0, 5, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 17173, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Drain Life"),
(-74519, 0, 6, 0, 0, 0, 100, 0, 5000, 8000, 25000, 30000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Curse of Weakness"),
(-74520, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On Respawn - Set Root On"),
(-74520, 0, 1, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On Aggro - Say Line 0"),
(-74520, 0, 2, 0, 1, 0, 100, 0, 0, 0, 3000, 3000, 11, 44473, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, "Necrolord - OOC - Cast Queen Angerboda: Soul Beam"),
(-74520, 0, 3, 0, 8, 0, 100, 1, 42808, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On Data Set - Die"),
(-74520, 0, 4, 0, 0, 0, 100, 0, 2000, 3000, 3000, 3500, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Cast Shadow Bolt"),
(-74520, 0, 5, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 17173, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Drain Life"),
(-74520, 0, 6, 0, 0, 0, 100, 0, 5000, 8000, 25000, 30000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Curse of Weakness"),
(24014, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Necrolord - On aggro - Say text 0"),
(24014, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 3000, 3500, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Cast Shadow Bolt"),
(24014, 0, 2, 0, 0, 0, 100, 0, 3000, 7000, 10000, 20000, 11, 17173, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Drain Life"),
(24014, 0, 3, 0, 0, 0, 100, 0, 5000, 8000, 25000, 30000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Necrolord - IC - Curse of Weakness");

DELETE FROM `creature_template_addon` WHERE `entry`=29393;
INSERT INTO `creature_template_addon` (`entry`, `emote`) VALUES
(29393, 417);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(42808);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 42808, 0, 0, 31, 0, 3, 24014, 74518, 0, 0, 0, '', 'Queen Angerbodas On Reaction 2 Beam - Targets Necrolord'),
(13, 1, 42808, 0, 1, 31, 0, 3, 24014, 74519, 0, 0, 0, '', 'Queen Angerbodas On Reaction 2 Beam - Targets Necrolord'),
(13, 1, 42808, 0, 2, 31, 0, 3, 24014, 74520, 0, 0, 0, '', 'Queen Angerbodas On Reaction 2 Beam - Targets Necrolord');
