-- Template
UPDATE `creature_template` SET `speed_walk`=4, `speed_run`=2.857142925262451171, `unit_flags3`=0x80000 WHERE `entry`=10682; -- Raider Kerr
UPDATE `creature_template` SET `speed_walk`=8, `speed_run`=2.857142925262451171, `unit_flags`=0x200, `VehicleId`=678 WHERE `entry`=39239; -- Durotar Riding Wolf

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (10682 /*10682 (Raider Kerr)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(10682, 0, 2326, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- 10682 (Raider Kerr)

-- Difficultie
UPDATE `creature_template_difficulty` SET `ContentTuningID`=70, `StaticFlags1`=0x0, `VerifiedBuild`=59679 WHERE (`Entry`=10682 AND `DifficultyID`=0); -- 10682 (Raider Kerr) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=70, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=39239 AND `DifficultyID`=0); -- 39239 (Durotar Riding Wolf) - CanSwim

-- Serverside spell
DELETE FROM `serverside_spell_effect` WHERE `SpellID`=73697 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(73697, 0, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73678, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0);

-- Raider Jhash smart ai
SET @ENTRY := 10676;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 2, 0, 100, 1, 0, 15, 0, 0, 0, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-15%% (once) - Self: Flee for assist', ''),
(@ENTRY, 0, 1, 0, 9, 0, 100, 0, 0, 20, 7000, 9000, 0, 11, 6533, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When victim in range 0 - 20 yards (cooldown 7000 - 9000 ms) - Self: Cast spell  Net (6533) on Victim', ''),
(@ENTRY, 0, 2, 3, 62, 0, 100, 0, 11189, 0, 0, 0, 0, 11, 73697, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 11189 selected - Self: Cast spell  Forcecast Summon Durotar Riding Wolf (73697) on Gossip player', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 11189 selected - Gossip player: Close gossip', '');

-- Durotar Riding Wolf smart ai
SET @ENTRY := 39239;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 58, 0, 100, 0, 33, 3923901, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 34 of path 3923901 ended - Self: Despawn in 1.5 s', ''),
(@ENTRY, 0, 1, 2, 58, 0, 100, 0, 10, 3923900, 0, 0, 0, 4, 6319, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 3923900 ended - Self: Play direct sound 6319 to every player in visibility range of Self', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 50, 203112, 10, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 3923900 ended - Self: Summon gameobject Accident (203112) at my position, moved by offset (0, 0, 0, 0) and despawn in 10 ms', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 3600, 3600, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 3923900 ended - Trigger timed event timedEvent[1] in 3600 - 3600 ms // -meta_wait', ''),
(@ENTRY, 0, 4, 0, 59, 0, 100, 0, 1, 0, 0, 0, 0, 53, 1, 3923901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Start path #3923901, run, do not repeat, Passive', ''),
(@ENTRY, 0, 5, 6, 63, 0, 100, 0, 0, 0, 0, 0, 0, 85, 46598, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just created - Owner/Summoner: Cast spell Ride Vehicle Hardcoded (46598) on self', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 1200, 1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On just created - Trigger timed event timedEvent[2] in 1200 - 1200 ms // -meta_wait', ''),
(@ENTRY, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 3, 2400, 2400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On just created - Trigger timed event timedEvent[3] in 2400 - 2400 ms // -meta_wait', ''),
(@ENTRY, 0, 8, 0, 59, 0, 100, 0, 2, 0, 0, 0, 0, 11, 76496, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[2] triggered - Self: Cast spell  Summon Raider Kerr (76496) on Self', ''),
(@ENTRY, 0, 9, 0, 59, 0, 100, 0, 3, 0, 0, 0, 0, 53, 1, 3923900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[3] triggered - Self: Start path #3923900, run, do not repeat, Passive', '');

-- Raider Kerr smart ai
SET @ENTRY := 10682;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Set react state to Passive', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 2400, 2400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On just created - Trigger timed event timedEvent[1] in 2400 - 2400 ms // -meta_wait', ''),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 1, 0, 0, 0, 0, 29, 2, 245, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Follow Owner/Summoner by distance 2, angle 245', '');

-- Path for Durotar Riding Wolf
SET @ENTRY := 39239;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Durotar Riding Wolf - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -787.17474, -4851.3213, 19.39965, NULL, 0),
(@PATH, 1, -757.42474, -4830.0713, 19.14965, NULL, 0),
(@PATH, 2, -741.17474, -4816.8213, 22.14965, NULL, 0),
(@PATH, 3, -728.17474, -4805.5713, 25.64965, NULL, 0),
(@PATH, 4, -716.92474, -4795.0713, 29.64965, NULL, 0),
(@PATH, 5, -701.67474, -4781.5713, 33.64965, NULL, 0),
(@PATH, 6, -680.17474, -4763.3213, 33.89965, NULL, 0),
(@PATH, 7, -663.17474, -4746.8213, 33.89965, NULL, 0),
(@PATH, 8, -641.92474, -4731.0713, 33.89965, NULL, 0),
(@PATH, 9, -621.17474, -4725.0713, 34.89965, NULL, 0),
(@PATH, 10, -606.2969, -4724.6807, 34.975567, NULL, 0);

-- Path for Durotar Riding Wolf
SET @ENTRY := 39239;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Durotar Riding Wolf - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -591.6059, -4735.144, 33.665752, NULL, 0),
(@PATH, 1, -555.9184, -4744.068, 33.234066, NULL, 0),
(@PATH, 2, -525.5868, -4756.0522, 32.855663, NULL, 0),
(@PATH, 3, -499.27258, -4766.0244, 32.308853, NULL, 0),
(@PATH, 4, -469.2396, -4774.019, 32.41078, NULL, 0),
(@PATH, 5, -441.07986, -4780.394, 32.71049, NULL, 0),
(@PATH, 6, -415.99652, -4791.224, 32.336918, NULL, 0),
(@PATH, 7, -392.15277, -4803.2847, 32.4044, NULL, 0),
(@PATH, 8, -372.15103, -4811.599, 32.27746, NULL, 0),
(@PATH, 9, -347.84375, -4812.674, 31.891449, NULL, 0),
(@PATH, 10, -318.05902, -4807.0244, 30.279812, NULL, 0),
(@PATH, 11, -292.33682, -4801.085, 29.608913, NULL, 0),
(@PATH, 12, -263.77258, -4795.033, 27.580912, NULL, 0),
(@PATH, 13, -229.80208, -4786.028, 25.215689, NULL, 0),
(@PATH, 14, -198.07812, -4774.9775, 23.743677, NULL, 0),
(@PATH, 15, -168.06944, -4764.528, 23.260315, NULL, 0),
(@PATH, 16, -132.8073, -4753.146, 22.50317, NULL, 0),
(@PATH, 17, -105.25347, -4747.0054, 21.853127, NULL, 0),
(@PATH, 18, -74.921875, -4746.309, 20.77988, NULL, 0),
(@PATH, 19, -41.083332, -4747.5625, 21.107523, NULL, 0),
(@PATH, 20, -17.038195, -4749.4062, 21.54498, NULL, 0),
(@PATH, 21, 16.567709, -4746.455, 22.036673, NULL, 0),
(@PATH, 22, 42.100697, -4743.7866, 20.907038, NULL, 0),
(@PATH, 23, 58.11111, -4744.434, 19.77512, NULL, 0),
(@PATH, 24, 82.65972, -4743.158, 17.746294, NULL, 0),
(@PATH, 25, 97.86285, -4746.3022, 16.802073, NULL, 0),
(@PATH, 26, 122.57639, -4760.184, 13.703508, NULL, 0),
(@PATH, 27, 141.44792, -4767.5835, 12.290229, NULL, 0),
(@PATH, 28, 156.29341, -4760.3853, 11.831441, NULL, 0),
(@PATH, 29, 182.73091, -4750.922, 11.399438, NULL, 0),
(@PATH, 30, 211.96875, -4745.9165, 10.375682, NULL, 0),
(@PATH, 31, 231.3125, -4739.2485, 10.102122, NULL, 0),
(@PATH, 32, 241.84029, -4736.7207, 10.102118, NULL, 0),
(@PATH, 33, 249.76042, -4737.877, 10.102122, NULL, 0);
