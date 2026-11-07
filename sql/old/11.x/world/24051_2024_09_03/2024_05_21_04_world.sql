SET @CGUID := 7000335;
SET @OGUID := 7000163;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+28;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 137039, 1643, 9042, 9626, '0', 0, 0, 0, 1, 3755.681396484375, -485.461822509765625, 37.06344985961914062, 2.305676937103271484, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Awakened Tideguard (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+1, 142194, 1643, 9042, 9626, '0', 0, 0, 0, 0, 3754.829833984375, -492.923614501953125, 38.96415328979492187, 3.880747556686401367, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Skittish Seagull (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1
(@CGUID+2, 137039, 1643, 9042, 9626, '0', 0, 0, 0, 1, 3755.521728515625, -478.270843505859375, 36.71664047241210937, 2.450761079788208007, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tideguard (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 142194, 1643, 9042, 9626, '0', 0, 0, 0, 0, 3773.49658203125, -514.68231201171875, 38.44319915771484375, 3.832850933074951171, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Skittish Seagull (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1
(@CGUID+4, 142194, 1643, 9042, 9626, '0', 0, 0, 0, 0, 3755.68408203125, -493.7725830078125, 39.22199249267578125, 4.122908592224121093, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Skittish Seagull (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1
(@CGUID+5, 137039, 1643, 9042, 9626, '0', 0, 0, 0, 1, 3749.25341796875, -484.29339599609375, 36.63306427001953125, 1.921743392944335937, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tideguard (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+6, 142194, 1643, 9042, 9626, '0', 0, 0, 0, 0, 3762.919189453125, -501.77777099609375, 40.64550018310546875, 4.378778934478759765, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Skittish Seagull (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1
(@CGUID+7, 134377, 1643, 9042, 9626, '0', 0, 0, 0, 0, 3775.802001953125, -574.13226318359375, 93.52033233642578125, 1.574845790863037109, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Slickbeak Osprey (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 136422, 1643, 9042, 9626, '0', 0, 0, 0, 0, 3790.881103515625, -512.48785400390625, 34.124176025390625, 0, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Cottontail (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 137039, 1643, 9042, 9626, '0', 0, 0, 0, 1, 3820.5166015625, -552.38543701171875, 21.1963348388671875, 5.083871364593505859, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tideguard (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+10, 137039, 1643, 9042, 9626, '0', 0, 0, 0, 1, 3821.741455078125, -555.888916015625, 20.29308700561523437, 1.851087570190429687, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tideguard (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+11, 136422, 1643, 9042, 9626, '0', 0, 0, 0, 0, 3805.596435546875, -557.19427490234375, 21.22417831420898437, 2.928831100463867187, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Cottontail (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 142168, 1643, 9042, 10033, '0', 0, 0, 0, 0, 3837.822509765625, -571.02923583984375, 17.352203369140625, 0.733493030071258544, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Squirrel (Area: Path of Storms - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+13, 137039, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3790.887939453125, -605.3680419921875, 4.198330402374267578, 0.834012150764465332, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tideguard (Area: Path of Storms - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+14, 137726, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3787.091064453125, -618.8992919921875, 0.942745804786682128, 4.97591257095336914, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Conscript (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+15, 137039, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3820.47998046875, -613.54864501953125, 4.198333263397216796, 1.944154620170593261, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tideguard (Area: Path of Storms - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+16, 137726, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3789.079833984375, -618.57464599609375, 1.071032047271728515, 4.673542976379394531, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Conscript (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+17, 54638, 1643, 9042, 10033, '0', 0, 0, 0, 0, 3797.712646484375, -639.9913330078125, 1.728608489036560058, 1.258543848991394042, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Generic Bunny (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+18, 137037, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3789.111083984375, -637.50347900390625, 1.728608965873718261, 6.028524398803710937, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tidesage (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+19, 137726, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3814.947998046875, -625.9913330078125, 0.695562958717346191, 3.69903421401977539, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Conscript (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+20, 137726, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3816.49658203125, -626.171875, 0.69555830955505371, 3.79045414924621582, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Conscript (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+21, 54638, 1643, 9042, 10033, '0', 0, 0, 0, 0, 3797.12158203125, -639.96527099609375, 1.728608489036560058, 1.276374220848083496, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Generic Bunny (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+22, 137726, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3816.646728515625, -632.56427001953125, 0.695555329322814941, 3.002608537673950195, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Conscript (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+23, 137726, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3817.643310546875, -628.27777099609375, 0.695553004741668701, 3.728364229202270507, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Conscript (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+24, 137037, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3806.216064453125, -642.47052001953125, 1.728608489036560058, 2.866831064224243164, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tidesage (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+25, 137037, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3789.942626953125, -644.5694580078125, 1.728608250617980957, 0.504748940467834472, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tidesage (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+26, 137037, 1643, 9042, 10033, '0', 0, 0, 0, 1, 3802.15625, -647.873291015625, 1.728608489036560058, 2.145909070968627929, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Awakened Tidesage (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+27, 54638, 1643, 9042, 10033, '0', 0, 0, 0, 0, 3788.731689453125, -672.38018798828125, 0.083333335816860198, 1.20302438735961914, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Generic Bunny (Area: Path of Storms - Difficulty: 0) CreateObject1
(@CGUID+28, 134377, 1643, 9042, 9626, '0', 0, 0, 0, 0, 3723.644287109375, -630.08819580078125, 24.94845390319824218, 1.935096144676208496, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762); -- Slickbeak Osprey (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1 (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+28;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Awakened Tideguard
(@CGUID+1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skittish Seagull
(@CGUID+3, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skittish Seagull
(@CGUID+2, 0, 0, 0, 0, 0, 1, 1, 716, 0, 0, 0, 0, ''), -- Awakened Tideguard
(@CGUID+4, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skittish Seagull
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 716, 0, 0, 0, 0, ''), -- Awakened Tideguard
(@CGUID+6, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skittish Seagull
(@CGUID+7, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Slickbeak Osprey
(@CGUID+9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Awakened Tideguard
(@CGUID+10, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Awakened Tideguard
(@CGUID+13, 0, 0, 0, 0, 0, 1, 1, 716, 0, 0, 0, 0, ''), -- Awakened Tideguard
(@CGUID+14, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Awakened Conscript
(@CGUID+15, 0, 0, 0, 0, 0, 1, 1, 716, 0, 0, 0, 0, ''), -- Awakened Tideguard
(@CGUID+16, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Awakened Conscript
(@CGUID+17, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Generic Bunny
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 15351, 0, 0, 0, ''), -- Awakened Tidesage
(@CGUID+19, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Awakened Conscript
(@CGUID+20, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Awakened Conscript
(@CGUID+21, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Generic Bunny
(@CGUID+22, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Awakened Conscript
(@CGUID+23, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Awakened Conscript
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 15351, 0, 0, 0, ''), -- Awakened Tidesage
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 0, 15351, 0, 0, 0, ''), -- Awakened Tidesage
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 0, 15351, 0, 0, 0, ''), -- Awakened Tidesage
(@CGUID+27, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Generic Bunny
(@CGUID+28, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Slickbeak Osprey

DELETE FROM `creature_template_addon` WHERE `entry` IN(137037, 137726, 137039);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(137037, 0, 0, 0, 0, 0, 1, 0, 0, 15351, 0, 0, 0, ''), -- 137037 (Awakened Tidesage)
(137726, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 137726 (Awakened Conscript)
(137039, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- 137039 (Awakened Tideguard)

UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=137037 AND `DifficultyID`=0); -- Awakened Tidesage
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=137726 AND `DifficultyID`=0); -- Awakened Conscript
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=137039 AND `DifficultyID`=0); -- Awakened Tideguard

UPDATE `creature_template_difficulty` SET `StaticFlags1`=`StaticFlags1`|0x20000000, `VerifiedBuild`=54762 WHERE (`Entry`=134377 AND `DifficultyID`=0); -- Slickbeak Osprey

UPDATE `creature_template` SET `unit_flags3`=67108864 WHERE `entry`=134377; -- Slickbeak Osprey
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=137039; -- Awakened Tideguard

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 137039;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN(-7000344, -7000345);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-7000344, 0, 0, 0, '', 1, 0, 100, 0, 5000, 7000, 5000, 7000, 10, 6, 273, 274, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 7 seconds (OOC) - Self: Play random emote: 6, 273, 274, 1,'),
(-7000345, 0, 0, 0, '', 1, 0, 100, 0, 5000, 7000, 5000, 7000, 10, 6, 273, 274, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 7 seconds (OOC) - Self: Play random emote: 6, 273, 274, 1,');

SET @ENTRY := 137039;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x1|0x2, 'Awakened Tideguard - Patrol');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3755.6814, -485.46182, 37.06345, NULL, 2314),
(@PATH, 1, 3758.3186, -488.0512, 37.839016, NULL, 0),
(@PATH, 2, 3760.5686, -490.5512, 38.589016, NULL, 0),
(@PATH, 3, 3763.0686, -493.0512, 39.339016, NULL, 0),
(@PATH, 4, 3765.3186, -495.8012, 39.589016, NULL, 0),
(@PATH, 5, 3767.8186, -498.5512, 39.589016, NULL, 0),
(@PATH, 6, 3770.5686, -501.3012, 39.339016, NULL, 0),
(@PATH, 7, 3773.5686, -504.8012, 38.339016, NULL, 0),
(@PATH, 8, 3776.5686, -508.0512, 37.589016, NULL, 0),
(@PATH, 9, 3779.0686, -510.8012, 37.089016, NULL, 0),
(@PATH, 10, 3781.0686, -512.8012, 36.339016, NULL, 0),
(@PATH, 11, 3783.0686, -515.0512, 35.589016, NULL, 0),
(@PATH, 12, 3785.0686, -516.8012, 34.839016, NULL, 0),
(@PATH, 13, 3787.3186, -518.8012, 34.089016, NULL, 0),
(@PATH, 14, 3789.8186, -521.0512, 33.089016, NULL, 0),
(@PATH, 15, 3792.5686, -523.0512, 32.089016, NULL, 0),
(@PATH, 16, 3795.0686, -525.3012, 30.339016, NULL, 0),
(@PATH, 17, 3797.3186, -527.3012, 29.339016, NULL, 0),
(@PATH, 18, 3799.8186, -529.5512, 28.839016, NULL, 0),
(@PATH, 19, 3802.0686, -531.8012, 28.089016, NULL, 0),
(@PATH, 20, 3804.3186, -534.3012, 27.339016, NULL, 0),
(@PATH, 21, 3806.8186, -536.5512, 26.089016, NULL, 0),
(@PATH, 22, 3808.8186, -539.0512, 25.339016, NULL, 0),
(@PATH, 23, 3810.8186, -541.8012, 24.339016, NULL, 0),
(@PATH, 24, 3812.8186, -544.8012, 23.589016, NULL, 0),
(@PATH, 25, 3814.3186, -547.5512, 22.839016, NULL, 0),
(@PATH, 26, 3815.3186, -550.3012, 21.839016, NULL, 0),
(@PATH, 27, 3816.0686, -553.3012, 21.089016, NULL, 0),
(@PATH, 28, 3817.0686, -556.5512, 20.089016, NULL, 0),
(@PATH, 29, 3817.8186, -559.3012, 19.339016, NULL, 0),
(@PATH, 30, 3818.0686, -562.3012, 18.339016, NULL, 0),
(@PATH, 31, 3818.0686, -565.5512, 17.589016, NULL, 0),
(@PATH, 32, 3817.8186, -568.8012, 16.589016, NULL, 0),
(@PATH, 33, 3817.3186, -572.0512, 15.589016, NULL, 0),
(@PATH, 34, 3816.8186, -575.8012, 14.339016, NULL, 0),
(@PATH, 35, 3816.0686, -579.3012, 13.339016, NULL, 0),
(@PATH, 36, 3815.3186, -582.5512, 12.089016, NULL, 0),
(@PATH, 37, 3814.4558, -586.6406, 10.614583, NULL, 2314);

UPDATE `creature` SET `position_x`=3755.6814, `position_y`=-485.46182, `position_z`=37.06345, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`=@CGUID+0;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+0, @PATH, 1);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 288430, 1643, 9042, 9626, '0', 0, 0, 3790.704833984375, -637.79864501953125, 3.032180309295654296, 2.919285058975219726, 0, 0, 0.993828773498535156, 0.11092504858970642, 120, 255, 1, 54762), -- Scroll of Tides (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1
(@OGUID+1, 288430, 1643, 9042, 9626, '0', 0, 0, 3791.48095703125, -643.578125, 3.032178878784179687, 3.719591856002807617, 0, 0, -0.95852947235107421, 0.284993380308151245, 120, 255, 1, 54762), -- Scroll of Tides (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1
(@OGUID+2, 288430, 1643, 9042, 9626, '0', 0, 0, 3801.54248046875, -646.890625, 3.032178878784179687, 5.24310302734375, 0, 0, -0.49691581726074218, 0.86779874563217163, 120, 255, 1, 54762), -- Scroll of Tides (Area: Tidebreak Foothills - Difficulty: 0) CreateObject1
(@OGUID+3, 288430, 1643, 9042, 9626, '0', 0, 0, 3804.646728515625, -641.88714599609375, 3.032178878784179687, 6.047809600830078125, 0, 0, -0.1174163818359375, 0.993082761764526367, 120, 255, 1, 54762); -- Scroll of Tides (Area: Tidebreak Foothills - Difficulty: 0) Creat

--
DELETE FROM `creature_model_info` WHERE `DisplayID`=90814;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(90814, 0.908434152603149414, 1.5, 0, 54762);

UPDATE `creature_model_info` SET `VerifiedBuild`=54762 WHERE `DisplayID` IN (6295, 30255, 42855, 83302, 1939, 83301, 86396, 38380, 65631, 981, 75365, 29756, 82550, 85468, 85471, 85470, 85467, 88679, 31773, 85469, 85466, 85339, 21936, 41326, 36357, 11686, 79043, 79042, 78928, 87594, 36700, 328, 79040, 64016, 82001, 88675, 88678, 58380, 83929, 4626, 36499, 88677, 79041, 83932, 84083, 76601);
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=54762 WHERE `DisplayID`=85204;
UPDATE `creature_model_info` SET `BoundingRadius`=1.050927042961120605, `CombatReach`=1.346153855323791503, `VerifiedBuild`=54762 WHERE `DisplayID`=75383;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=1.5, `VerifiedBuild`=54762 WHERE `DisplayID`=85192;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `VerifiedBuild`=54762 WHERE `DisplayID`=24964;
UPDATE `creature_model_info` SET `BoundingRadius`=2.788770675659179687, `CombatReach`=1, `VerifiedBuild`=54762 WHERE `DisplayID`=75702;
UPDATE `creature_model_info` SET `BoundingRadius`=1.399999976158142089, `CombatReach`=1.75, `VerifiedBuild`=54762 WHERE `DisplayID`=32024;
UPDATE `creature_model_info` SET `BoundingRadius`=58.802764892578125, `CombatReach`=11, `VerifiedBuild`=54762 WHERE `DisplayID`=85053;
UPDATE `creature_model_info` SET `BoundingRadius`=1.366205096244812011, `CombatReach`=1.75, `VerifiedBuild`=54762 WHERE `DisplayID`=87603;
UPDATE `creature_model_info` SET `BoundingRadius`=1.32942509651184082, `CombatReach`=1.60000002384185791, `VerifiedBuild`=54762 WHERE `DisplayID`=81269;
UPDATE `creature_model_info` SET `BoundingRadius`=0.546643853187561035, `CombatReach`=1.5, `VerifiedBuild`=54762 WHERE `DisplayID`=85200;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288985729217529296, `CombatReach`=2, `VerifiedBuild`=54762 WHERE `DisplayID`=27849;
UPDATE `creature_model_info` SET `BoundingRadius`=3.01638031005859375, `VerifiedBuild`=54762 WHERE `DisplayID`=90852;
