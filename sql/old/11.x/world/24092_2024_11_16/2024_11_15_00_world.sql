SET @CGUID := 10004417;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+44;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 220899, 2552, 14717, 0, '0', 0, 0, 0, 0, 799.66143798828125, -2561.87158203125, 20.65064048767089843, 2.623001575469970703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Seagull (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+1, 227733, 2552, 14717, 0, '0', 0, 0, 0, 0, 886.44097900390625, -2529.40283203125, 41.38819503784179687, 4.027902603149414062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Salt-Ear Ferret (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+2, 220899, 2552, 14717, 0, '0', 0, 0, 0, 0, 803.03125, -2557.09375, 21.35396957397460937, 2.623001575469970703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Seagull (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+3, 220876, 2552, 14717, 0, '0', 0, 0, 0, 0, 793.795166015625, -2601.935791015625, 12.76518440246582031, 3.881206989288330078, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Frog (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+4, 227733, 2552, 14717, 0, '0', 0, 0, 0, 0, 848.03125, -2585.0556640625, 38.57397079467773437, 3.758396625518798828, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Salt-Ear Ferret (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+5, 220899, 2552, 14717, 0, '0', 0, 0, 0, 0, 772.80206298828125, -2597.713623046875, 16.83715057373046875, 0.256162017583847045, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Seagull (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+6, 222747, 2552, 14717, 0, '0', 0, 0, 0, 0, 797.52606201171875, -2582.677001953125, 12.91141796112060546, 2.062864303588867187, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mossy Snail (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+7, 220876, 2552, 14717, 0, '0', 0, 0, 0, 0, 800.00347900390625, -2584.217041015625, 13.39698696136474609, 5.633397102355957031, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Frog (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+8, 220899, 2552, 14717, 0, '0', 0, 0, 0, 0, 776.342041015625, -2596.6962890625, 16.84090805053710937, 3.43460392951965332, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Seagull (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+9, 227733, 2552, 14717, 0, '0', 0, 0, 0, 0, 827.79168701171875, -2608.44091796875, 40.0052947998046875, 5.296855926513671875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Salt-Ear Ferret (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+10, 220876, 2552, 14717, 0, '0', 0, 0, 0, 0, 820.15625, -2558.751708984375, 14.91111183166503906, 1.68007969856262207, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Frog (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+11, 220899, 2552, 14717, 0, '0', 0, 0, 0, 0, 804.49652099609375, -2554.4462890625, 20.65025901794433593, 2.623001575469970703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Seagull (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+12, 220876, 2552, 14717, 0, '0', 0, 0, 0, 0, 803.6632080078125, -2593.720458984375, 13.65040493011474609, 5.26945352554321289, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Frog (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+13, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 848.310791015625, -2764.345458984375, 55.42043685913085937, 1.001412510871887207, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+14, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 843.06597900390625, -2770.546875, 54.97251129150390625, 3.480160713195800781, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+15, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 891.63018798828125, -2849.0556640625, 46.78051376342773437, 2.158782005310058593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+16, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 810.74652099609375, -2810.91845703125, 41.42626571655273437, 5.339075088500976562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+17, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 843.02081298828125, -2850.489501953125, 38.89463424682617187, 0.358752965927124023, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+18, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 827.88714599609375, -2906.420166015625, 29.15522956848144531, 1.178097963333129882, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+19, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 765.11981201171875, -2800.970458984375, 33.39803695678710937, 1.178097963333129882, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+20, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 786.1007080078125, -2837.744873046875, 33.43233871459960937, 4.141002655029296875, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+21, 224800, 2552, 14717, 0, '0', 0, 0, 0, 0, 676.72222900390625, -2937.123291015625, 49.80184555053710937, 1.23749852180480957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Salty Gull (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+22, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 690.26910400390625, -2897.666748046875, 34.03921890258789062, 2.748334646224975585, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+23, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 703.07464599609375, -2863.701416015625, 30.19683265686035156, 1.076754450798034667, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+24, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 719.1319580078125, -2874.53466796875, 29.98130035400390625, 2.260166168212890625, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+25, 224800, 2552, 14717, 0, '0', 0, 0, 0, 0, 673.16143798828125, -2939.364501953125, 49.19343948364257812, 0.541967630386352539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Salty Gull (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+26, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 832.7100830078125, -2892.9775390625, 33.27056121826171875, 4.079567909240722656, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+27, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 759.625, -2898.9462890625, 27.27443885803222656, 2.480837583541870117, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+28, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 769.57989501953125, -2899.880126953125, 26.65032005310058593, 2.66583561897277832, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 876.91668701171875, -2954.013916015625, 29.43993186950683593, 0.218726336956024169, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+30, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 800.279541015625, -2945.13720703125, 17.69325065612792968, 4.468654155731201171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+31, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 803.77081298828125, -2962.755126953125, 17.66106986999511718, 0.260224640369415283, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+32, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 838.94268798828125, -2974.939208984375, 23.08091926574707031, 3.77590489387512207, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+33, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 901.6649169921875, -2987.630126953125, 25.41518211364746093, 4.278623580932617187, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+34, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 884.732666015625, -2934.380126953125, 31.20778465270996093, 0.630358755588531494, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+35, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 919.5538330078125, -2961.432373046875, 31.66045188903808593, 1.259275078773498535, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+36, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 976.68402099609375, -2956.90966796875, 44.7632598876953125, 3.430836200714111328, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+37, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 1028.314208984375, -2998.935791015625, 48.67584991455078125, 0.623264193534851074, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+38, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 1023.6024169921875, -3020.671875, 48.1097412109375, 4.080266952514648437, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+39, 221520, 2552, 14717, 0, '0', 0, 0, 0, 0, 1065.52783203125, -3121.2119140625, 38.14678192138671875, 4.849938869476318359, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Puddle Skipper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+40, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 1038.8541259765625, -3115.829833984375, 36.46039962768554687, 5.666009426116943359, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+41, 221519, 2552, 14717, 0, '0', 0, 0, 0, 0, 1061.4444580078125, -3107.375, 40.61419677734375, 1.178087353706359863, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Fluttering Sapphire (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+42, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 1027.3507080078125, -3052.8994140625, 43.94135284423828125, 6.248064041137695312, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+43, 221526, 2552, 14717, 0, '0', 0, 0, 0, 0, 1045.5364990234375, -3090.960205078125, 40.78774642944335937, 1.837699651718139648, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+44, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 1077.8055419921875, -3098.713623046875, 41.56877517700195312, 2.353130578994750976, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388); -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+44;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Seagull
(@CGUID+2, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Seagull
(@CGUID+5, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Seagull
(@CGUID+8, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Seagull
(@CGUID+11, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Seagull
(@CGUID+21, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Salty Gull
(@CGUID+25, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Salty Gull

-- Template
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=220899; -- Seagull
UPDATE `creature_template` SET `faction`=14, `speed_run`=0.992062866687774658, `BaseAttackTime`=1739, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=217670; -- Rotbark the Unfelled
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=222199; -- Spring Waddler
UPDATE `creature_template` SET `faction`=190, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222738; -- Troglofrog
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x4000000, `VehicleId`=8281 WHERE `entry`=212704; -- Mycotic Shalehorn
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=212736; -- Boskroot Brute
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=221520; -- Puddle Skipper
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=220874; -- Hermit Crab
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=214549; -- Seaborne Elemental
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x84000000 WHERE `entry`=224876; -- Scavenging Sandsnapper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x8000000 WHERE `entry`=224350; -- Voltscale Siltworm
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=224735; -- Tidehunter Gull
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=224799; -- Shimmering Hermit

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x30000000, `VerifiedBuild`=57388 WHERE (`Entry`=220899 AND `DifficultyID`=0); -- 220899 (Seagull) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=212704 AND `DifficultyID`=0); -- 212704 (Mycotic Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000100, `VerifiedBuild`=57388 WHERE (`Entry`=212736 AND `DifficultyID`=0); -- 212736 (Boskroot Brute) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=221520 AND `DifficultyID`=0); -- 221520 (Puddle Skipper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=220874 AND `DifficultyID`=0); -- 220874 (Hermit Crab) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=214549 AND `DifficultyID`=0); -- 214549 (Seaborne Elemental) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=224876 AND `DifficultyID`=0); -- 224876 (Scavenging Sandsnapper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=224350 AND `DifficultyID`=0); -- 224350 (Voltscale Siltworm) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=224735 AND `DifficultyID`=0); -- 224735 (Tidehunter Gull) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=224799 AND `DifficultyID`=0); -- 224799 (Shimmering Hermit) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=222199 AND `DifficultyID`=0); -- 222199 (Spring Waddler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=222738 AND `DifficultyID`=0); -- 222738 (Troglofrog) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (114840, 122158, 122162, 122166);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(114840, 2.101834774017333984, 3.60000014305114746, 0, 57388),
(122158, 1.366205096244812011, 1.75, 0, 57388),
(122162, 1.366205096244812011, 1.75, 0, 57388),
(122166, 1.366205096244812011, 1.75, 0, 57388);

UPDATE `creature_model_info` SET `VerifiedBuild`=57388 WHERE `DisplayID` IN (107853, 81058, 104165, 103831, 119087, 106564, 91872, 121445, 114818, 114653, 115238, 78832, 122175, 114814, 103812, 119497, 117491, 114304, 119076, 119170, 32789, 91870, 77407, 77406, 120662, 114794, 117497, 115109, 102533, 117481, 103904, 117494, 122169, 114823, 114791, 114817, 32790, 117487, 91868, 120661, 117484, 104045, 104043, 45880, 81086, 122170);
UPDATE `creature_model_info` SET `BoundingRadius`=0.670859098434448242, `VerifiedBuild`=57388 WHERE `DisplayID`=107365;
UPDATE `creature_model_info` SET `BoundingRadius`=1.366205096244812011, `CombatReach`=1.75, `VerifiedBuild`=57388 WHERE `DisplayID`=87605;
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599251747131347, `CombatReach`=1.75, `VerifiedBuild`=57388 WHERE `DisplayID`=114816;
UPDATE `creature_model_info` SET `BoundingRadius`=1.751528859138488769, `CombatReach`=3, `VerifiedBuild`=57388 WHERE `DisplayID`=91866;
