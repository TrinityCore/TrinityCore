SET @CGUID := 3000113;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 50089, 0, 4922, 4922, '0', 0, 0, 0, 0, -2451.816162109375, -5422.8681640625, 148.8532257080078125, 5.7662200927734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 69587); -- Julak-Doom (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 91334 - Boss Hittin' Ya)

DELETE FROM `creature` WHERE `guid` = 379721;
DELETE FROM `creature_addon` WHERE `guid` = 379721;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (51247 /*51247 (Julak-Doom) - Black Breath*/, 50089 /*50089 (Julak-Doom) - Boss Hittin' Ya*/, 50091 /*50091 (Julak-Doom) - Ride Vehicle*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(51247, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '94635'), -- 51247 (Julak-Doom) - Black Breath
(50089, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '91334'), -- 50089 (Julak-Doom) - Boss Hittin' Ya
(50091, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- 50091 (Julak-Doom) - Ride Vehicle

-- Template
UPDATE `creature_template` SET `speed_walk`=1.20000004768371582, `BaseAttackTime`=1500, `unit_flags`=0x40 WHERE `entry`=50089; -- Julak-Doom
UPDATE `creature_template` SET `speed_run`=1.357142806053161621, `unit_flags`=0x2000200, `unit_flags2`=0x20800 WHERE `entry`=50091; -- Julak-Doom
UPDATE `creature_template` SET `speed_walk`=2.20000004768371582, `speed_run`=0.785714268684387207, `unit_flags`=0x2000000, `unit_flags3`=0x40080001, `flags_extra` = 128 WHERE `entry`=51247; -- Julak-Doom

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'worldboss_julak_doom' WHERE `entry` = 50089;

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=56, `StaticFlags1`=0x10000000, `VerifiedBuild`=69587 WHERE (`Entry`=50089 AND `DifficultyID`=0); -- 50089 (Julak-Doom) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=56, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=69587 WHERE (`Entry`=50091 AND `DifficultyID`=0); -- 50091 (Julak-Doom) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=56, `StaticFlags1`=0x20000100, `VerifiedBuild`=69587 WHERE (`Entry`=51247 AND `DifficultyID`=0); -- 51247 (Julak-Doom) - Sessile, Floating

-- Spellproc
DELETE FROM `spell_proc` WHERE `SpellId` IN (93621);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(93621,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- Dark Whispers

-- ScriptName
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_julak_doom_dark_whisper';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93621, 'spell_julak_doom_dark_whisper');

-- Vehicles
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 50089;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(50089, 61791, 1, 0);

DELETE FROM `vehicle_template_accessory` WHERE (`seat_id`=0 AND `entry`=50089);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(50089, 50091, 0, 1, 'Julak-Doom - Julak-Doom', 8, 0); -- Julak-Doom - Julak-Doom

-- Path for Julak-Doom
SET @ENTRY := 50089;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Julak-Doom - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -2396.1807, -5441.4497, 140.16254, NULL, 0),
(@PATH, 1, -2372.4722, -5452.0957, 129.6178, NULL, 0),
(@PATH, 2, -2372.0972, -5478.788, 125.80329, NULL, 0),
(@PATH, 3, -2369.6528, -5517.988, 120.622086, NULL, 0),
(@PATH, 4, -2375.198, -5558.3145, 114.32381, NULL, 0),
(@PATH, 5, -2382.9045, -5607.5103, 108.78274, NULL, 61601),
(@PATH, 6, -2374.144, -5523.5156, 121.61144, NULL, 0),
(@PATH, 7, -2375.7778, -5499.488, 126.4896, NULL, 0),
(@PATH, 8, -2383.7551, -5476.1025, 132.48381, NULL, 0),
(@PATH, 9, -2403.677, -5456.7256, 142.08533, NULL, 0),
(@PATH, 10, -2440.8923, -5465.597, 147.89722, NULL, 0),
(@PATH, 11, -2469.6667, -5480.415, 146.06825, NULL, 0),
(@PATH, 12, -2499.7812, -5485.0366, 141.8139, NULL, 0),
(@PATH, 13, -2531.0215, -5469.1777, 150.58344, NULL, 0),
(@PATH, 14, -2547.7014, -5443.0835, 160.23291, NULL, 0),
(@PATH, 15, -2554.1614, -5412.335, 162.37889, NULL, 0),
(@PATH, 16, -2587.912, -5399.8887, 170.36353, NULL, 0),
(@PATH, 17, -2590.5261, -5376.8057, 173.48349, NULL, 0),
(@PATH, 18, -2585.2551, -5359.816, 174.70645, NULL, 0),
(@PATH, 19, -2582.6199, -5331.229, 171.61417, NULL, 0),
(@PATH, 20, -2584.7285, -5301.287, 168.13611, NULL, 0),
(@PATH, 21, -2587.2969, -5261.653, 161.69852, NULL, 0),
(@PATH, 22, -2559.684, -5233.059, 157.60756, NULL, 0),
(@PATH, 23, -2537.2534, -5203.241, 148.88406, NULL, 0),
(@PATH, 24, -2518.644, -5176.8784, 143.89433, NULL, 0),
(@PATH, 25, -2493.375, -5139.9165, 133.0672, NULL, 0),
(@PATH, 26, -2479.3489, -5108.901, 132.28502, NULL, 0),
(@PATH, 27, -2473.052, -5074.915, 132.90402, NULL, 0),
(@PATH, 28, -2420.4375, -5052.3994, 115.140915, NULL, 61056),
(@PATH, 29, -2443.7969, -5065.9097, 123.39856, NULL, 0),
(@PATH, 30, -2431.9824, -5085.631, 118.50279, NULL, 0),
(@PATH, 31, -2419.8542, -5110.604, 115.40777, NULL, 0),
(@PATH, 32, -2411.6824, -5136.1353, 112.77623, NULL, 0),
(@PATH, 33, -2410.231, -5167.1094, 109.52954, NULL, 0),
(@PATH, 34, -2418.8298, -5197.3335, 113.16438, NULL, 0),
(@PATH, 35, -2430.5798, -5244.6704, 122.15738, NULL, 60315),
(@PATH, 36, -2470.684, -5198.5767, 132.4703, NULL, 0),
(@PATH, 37, -2500.0989, -5181.222, 138.43855, NULL, 0),
(@PATH, 38, -2530.7449, -5190.2017, 147.05144, NULL, 0),
(@PATH, 39, -2545.323, -5223.5347, 153.60725, NULL, 0),
(@PATH, 40, -2556.7102, -5252.771, 159.27701, NULL, 0),
(@PATH, 41, -2565.7466, -5280.953, 163.85547, NULL, 0),
(@PATH, 42, -2568.7734, -5305.758, 168.57376, NULL, 0),
(@PATH, 43, -2562.2483, -5330.757, 170.93304, NULL, 0),
(@PATH, 44, -2549.2285, -5361.049, 170.17668, NULL, 0),
(@PATH, 45, -2554.5156, -5410.731, 162.51285, NULL, 0),
(@PATH, 46, -2536.2986, -5452.4287, 155.0878, NULL, 0),
(@PATH, 47, -2490.5435, -5435.182, 147.60214, NULL, 0),
(@PATH, 48, -2459.6372, -5418.422, 149.50963, NULL, 0),
(@PATH, 49, -2429.8455, -5435.3506, 146.86827, NULL, 0);

UPDATE `creature_template_addon` SET `PathId` = 5008900 WHERE `entry` = 50089;
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = @CGUID+0;
