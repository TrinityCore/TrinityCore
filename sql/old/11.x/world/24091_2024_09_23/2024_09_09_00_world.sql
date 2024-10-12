SET @CGUID := 10001817;

SET @NPCTEXTID := 600017;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2477.444580078125, -2434.788330078125, 181.548736572265625, 3.126145124435424804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+1, 221044, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2571.868896484375, -2516.278564453125, 200.225830078125, 1.7486954927444458, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56461), -- Stablehand (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+2, 221074, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2526.43408203125, -2465.314208984375, 200.225799560546875, 3.802732467651367187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Assistant Darragh Irongut (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+3, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 2, 2616.013916015625, -2486.77783203125, 224.11517333984375, 5.448974609375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+4, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 2, 2452.895751953125, -2455.57470703125, 181.547027587890625, 0.035277295857667922, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+5, 219243, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2516.252685546875, -2469.13720703125, 200.433135986328125, 5.441492080688476562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Teha (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+6, 221077, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2504.768310546875, -2475.085205078125, 200.321868896484375, 6.2657318115234375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Assistant Ula Threadstrong (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+7, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2571.8984375, -2530.294677734375, 200.225799560546875, 2.357314348220825195, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+8, 221848, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2568.43408203125, -2480.864501953125, 201.71588134765625, 3.646671772003173828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Warpweaver Voxin (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+9, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 5, 2475.8056640625, -2455.03466796875, 181.548858642578125, 3.296581029891967773, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+10, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 5, 2605.529541015625, -2477.53466796875, 228.673614501953125, 2.325949430465698242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+11, 219244, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2513.618896484375, -2472.49658203125, 200.4332122802734375, 5.951020717620849609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Andee Seabraid (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+12, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 6, 2608.296142578125, -2494.53466796875, 224.11517333984375, 5.635158061981201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+13, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 4, 2451.942626953125, -2434.59716796875, 181.548736572265625, 0.000698813470080494, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+14, 221044, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2530.66162109375, -2477.180908203125, 200.2257843017578125, 5.302254199981689453, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56461), -- Stablehand (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+15, 221002, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2536.747314453125, -2477.109375, 200.2257843017578125, 0.852846980094909667, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Khole (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+16, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 3, 2624.38720703125, -2528.085205078125, 219.7344207763671875, 4.719389915466308593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+17, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2635.33251953125, -2528.0712890625, 219.7344207763671875, 4.638683319091796875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461); -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Assistant Darragh Irongut
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''); -- Assistant Ula Threadstrong

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (439315 /*Collector's Cache*/, 454424 /*Dormant Rock Giant*/, 441162 /*Dormant Rock Giant*/, 441164 /*Dormant Rock Giant*/, 441170 /*Dormant Rock Giant*/, 433851 /*Alliance Storehouse*/, 433467 /*Alliance Transport*/, 433471 /*Alliance Transport*/, 456778 /*Horde Transport*/, 456777 /*Alliance Transport*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(439315, 0, 262144, 0, 0), -- Collector's Cache
(454424, 0, 1048608, 0, 0), -- Dormant Rock Giant
(441162, 0, 1048608, 0, 0), -- Dormant Rock Giant
(441164, 0, 1048608, 0, 0), -- Dormant Rock Giant
(441170, 0, 1048608, 0, 0), -- Dormant Rock Giant
(433851, 0, 1048608, 0, 0), -- Alliance Storehouse
(433467, 0, 1048608, 0, 0), -- Alliance Transport
(433471, 0, 1048608, 0, 0), -- Alliance Transport
(456778, 0, 1048608, 0, 0), -- Horde Transport
(456777, 0, 1048608, 0, 0); -- Alliance Transport

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=222160; -- Wildhammer Skyfighter
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67108864, `unit_flags3`=1090551809 WHERE `entry` IN (222217, 222238); -- Crusher
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217207; -- Unbound Worker
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=220307; -- Holiday Enthusiast
UPDATE `creature_template` SET `faction`=3397, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=226919; -- Archivist Frithrun
UPDATE `creature_template` SET `faction`=35, `npcflag`=268435585, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=221848; -- Warpweaver Voxin
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226751; -- Reginald Arcfire
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=225496; -- Warsong Grunt
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219099; -- Thermalseer Arhdas
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219098; -- Supply Foreman Drezmol
UPDATE `creature_template` SET `faction`=3407, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223533; -- Custodian Khubon
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=221077; -- Assistant Ula Threadstrong
UPDATE `creature_template` SET `faction`=3364, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223875; -- Faerin Lothar
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=222303; -- Gnome Technician
UPDATE `creature_template` SET `faction`=3438, `npcflag`=2, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226511; -- High Speaker Brinthe
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1073741824 WHERE `entry`=220968; -- Mannequin
UPDATE `creature_template` SET `faction`=35, `npcflag`=2251799813685251, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=219243; -- Teha
UPDATE `creature_template` SET `faction`=3397, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217704; -- Gundargaz Foreman
UPDATE `creature_template` SET `faction`=3407, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212369; -- Breem
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=16777216, `VehicleId`=8673 WHERE `entry`=230100; -- Wall Climb Vehicle
UPDATE `creature_template` SET `faction`=3364, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=227422; -- Arathi Stalwart
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219126; -- Oathsworn Citizen
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=221074; -- Assistant Darragh Irongut
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1090519040 WHERE `entry` IN (225664, 225654); -- Boost
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=230098; -- Spindle
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215658; -- Swift Cloudrook
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=221044; -- Stablehand
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1090519040 WHERE `entry`=199602; -- [DND] Fireworks
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219103; -- Kronzon
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215520; -- Edothir
UPDATE `creature_template` SET `faction`=3407, `npcflag`=80, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219104; -- Athodas
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=226237; -- Dalaran Survivor
UPDATE `creature_template` SET `faction`=3407, `npcflag`=65667, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212370; -- Ronesh
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=221007; -- [DNT] Coreway Mech Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=227252; -- Mouser
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=220943; -- Reliquary Researcher
UPDATE `creature_template` SET `faction`=3407, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226623; -- Biergoth
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=18432, `unit_flags3`=1090519040 WHERE `entry`=227998; -- Catalyst
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=221002; -- Khole
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=223793; -- [DNT] Forgegrounds Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1090519040 WHERE `entry`=183978; -- Important Camera Dog
UPDATE `creature_template` SET `faction`=3364, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=227417; -- Dedicated Sailor
UPDATE `creature_template` SET `faction`=35, `npcflag`=2251799813685251, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=219244; -- Andee Seabraid
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226752; -- Brassbolt Mechawrench
UPDATE `creature_template` SET `faction`=3364, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=225766; -- Stalwart Aeroknight

DELETE FROM `gameobject_template` WHERE `entry` IN (433851 /*Alliance Storehouse*/, 433467 /*Alliance Transport*/, 456778 /*Horde Transport*/, 433469 /*Horde Transport*/, 433471 /*Alliance Transport*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(433851, 43, 89004, 'Alliance Storehouse', '', '', '', 1, -1, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56461), -- Alliance Storehouse
(433467, 43, 48224, 'Alliance Transport', '', '', '', 1, -1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56461), -- Alliance Transport
(456778, 43, 88875, 'Horde Transport', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56461), -- Horde Transport
(433469, 43, 88875, 'Horde Transport', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56461), -- Horde Transport
(433471, 43, 48224, 'Alliance Transport', '', '', '', 1, -1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56461); -- Alliance Transport

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=23258 AND `DifficultyID`=0); -- 23258 (Egbert) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219103 AND `DifficultyID`=0); -- 219103 (Kronzon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=215520 AND `DifficultyID`=0); -- 215520 (Edothir) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219104 AND `DifficultyID`=0); -- 219104 (Athodas) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226237 AND `DifficultyID`=0); -- 226237 (Dalaran Survivor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=56461 WHERE (`Entry`=212370 AND `DifficultyID`=0); -- 212370 (Ronesh) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=536870912, `VerifiedBuild`=56461 WHERE (`Entry`=221007 AND `DifficultyID`=0); -- 221007 ([DNT] Coreway Mech Stalker) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=227252 AND `DifficultyID`=0); -- 227252 (Mouser) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2677, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=220943 AND `DifficultyID`=0); -- 220943 (Reliquary Researcher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2892, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226623 AND `DifficultyID`=0); -- 226623 (Biergoth) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=536871168, `StaticFlags3`=262144, `VerifiedBuild`=56461 WHERE (`Entry`=227998 AND `DifficultyID`=0); -- 227998 (Catalyst) - Sessile, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=221002 AND `DifficultyID`=0); -- 221002 (Khole) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=227417 AND `DifficultyID`=0); -- 227417 (Dedicated Sailor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=866, `VerifiedBuild`=56461 WHERE (`Entry`=219244 AND `DifficultyID`=0); -- 219244 (Andee Seabraid) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226752 AND `DifficultyID`=0); -- 226752 (Brassbolt Mechawrench) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=225766 AND `DifficultyID`=0); -- 225766 (Stalwart Aeroknight) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=222160 AND `DifficultyID`=0); -- 222160 (Wildhammer Skyfighter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=217207 AND `DifficultyID`=0); -- 217207 (Unbound Worker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=866, `VerifiedBuild`=56461 WHERE (`Entry`=219244 AND `DifficultyID`=0); -- 219244 (Andee Seabraid) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226752 AND `DifficultyID`=0); -- 226752 (Brassbolt Mechawrench) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=225766 AND `DifficultyID`=0); -- 225766 (Stalwart Aeroknight) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=222160 AND `DifficultyID`=0); -- 222160 (Wildhammer Skyfighter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=217207 AND `DifficultyID`=0); -- 217207 (Unbound Worker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=877, `VerifiedBuild`=56461 WHERE (`Entry`=220307 AND `DifficultyID`=0); -- 220307 (Holiday Enthusiast) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=56461 WHERE (`Entry`=226919 AND `DifficultyID`=0); -- 226919 (Archivist Frithrun) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `VerifiedBuild`=56461 WHERE (`Entry`=221848 AND `DifficultyID`=0); -- 221848 (Warpweaver Voxin) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `VerifiedBuild`=56461 WHERE (`Entry`=226751 AND `DifficultyID`=0); -- 226751 (Reginald Arcfire) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=225496 AND `DifficultyID`=0); -- 225496 (Warsong Grunt) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=56461 WHERE (`Entry`=219099 AND `DifficultyID`=0); -- 219099 (Thermalseer Arhdas) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219098 AND `DifficultyID`=0); -- 219098 (Supply Foreman Drezmol) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=56461 WHERE (`Entry`=223533 AND `DifficultyID`=0); -- 223533 (Custodian Khubon) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=221077 AND `DifficultyID`=0); -- 221077 (Assistant Ula Threadstrong) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=56461 WHERE (`Entry`=223875 AND `DifficultyID`=0); -- 223875 (Faerin Lothar) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=222303 AND `DifficultyID`=0); -- 222303 (Gnome Technician) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226511 AND `DifficultyID`=0); -- 226511 (High Speaker Brinthe) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=181, `StaticFlags1`=536871168, `VerifiedBuild`=56461 WHERE (`Entry`=220968 AND `DifficultyID`=0); -- 220968 (Mannequin) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=866, `VerifiedBuild`=56461 WHERE (`Entry`=219243 AND `DifficultyID`=0); -- 219243 (Teha) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2832, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=217704 AND `DifficultyID`=0); -- 217704 (Gundargaz Foreman) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `StaticFlags3`=262144, `VerifiedBuild`=56461 WHERE (`Entry`=212369 AND `DifficultyID`=0); -- 212369 (Breem) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=227422 AND `DifficultyID`=0); -- 227422 (Arathi Stalwart) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219126 AND `DifficultyID`=0); -- 219126 (Oathsworn Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=221074 AND `DifficultyID`=0); -- 221074 (Assistant Darragh Irongut) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=215658 AND `DifficultyID`=0); -- 215658 (Swift Cloudrook) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `VerifiedBuild`=56461 WHERE (`Entry`=221044 AND `DifficultyID`=0); -- 221044 (Stablehand) - 

-- Creature equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=221044 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(221044, 1, 3367, 0, 0, 0, 0, 0, 0, 0, 0, 56461); -- Stablehand

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=221848 AND `MenuID`=21043) OR (`CreatureID`=221074 AND `MenuID`=34471) OR (`CreatureID`=219243 AND `MenuID`=34391) OR (`CreatureID`=219244 AND `MenuID`=34385) OR (`CreatureID`=221077 AND `MenuID`=34472) OR (`CreatureID`=221002 AND `MenuID`=34381);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(221848, 21043, 56461), -- Warpweaver Voxin
(221074, 34471, 56461), -- Assistant Darragh Irongut
(219243, 34391, 56461), -- Teha
(219244, 34385, 56461), -- Andee Seabraid
(221077, 34472, 56461), -- Assistant Ula Threadstrong
(221002, 34381, 56461); -- Khole

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+4;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 260946, 0, 0, 0, 0, 0, 0, 0, 56461), -- 219244 (Andee Seabraid)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 260974, 0, 0, 0, 0, 0, 0, 0, 56461), -- 219243 (Teha)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 261308, 0, 0, 0, 0, 0, 0, 0, 56461), -- 221074 (Assistant Darragh Irongut)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 261309, 0, 0, 0, 0, 0, 0, 0, 56461), -- 221077 (Assistant Ula Threadstrong)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 260903, 0, 0, 0, 0, 0, 0, 0, 56461); -- 221002 (Khole)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34385 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=34391 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=34471 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=34472 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=34381 AND `TextID`=@NPCTEXTID+4);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34385, @NPCTEXTID+0, 56461), -- 219244 (Andee Seabraid)
(34391, @NPCTEXTID+1, 56461), -- 219243 (Teha)
(34471, @NPCTEXTID+2, 56461), -- 221074 (Assistant Darragh Irongut)
(34472, @NPCTEXTID+3, 56461), -- 221077 (Assistant Ula Threadstrong)
(34381, @NPCTEXTID+4, 56461); -- 221002 (Khole)

UPDATE `gossip_menu` SET `VerifiedBuild`=56461 WHERE (`MenuID`=21043 AND `TextID`=31799);

DELETE FROM `gossip_menu_addon` WHERE `MenuID`=21043;
INSERT INTO `gossip_menu_addon` (`MenuID`, `FriendshipFactionID`, `LfgDungeonsID`, `VerifiedBuild`) VALUES
(21043, 0, 1515, 56461); -- 221848 (Warpweaver Voxin)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (34391,34385));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(34391, 121672, 0, 47, 'I\'d like to see what you have to offer this month.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(34385, 121665, 0, 47, 'I\'d like to see what you have to offer this month.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=221848 AND `item`=210850 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=212626 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=213518 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=213441 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=213430 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=213437 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=213435 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=213434 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=213433 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=213432 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=213431 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=202308 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=202307 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=202306 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=202305 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=202304 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=202303 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=202301 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=221848 AND `item`=202300 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=221848 AND `item`=202298 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=221848 AND `item`=202297 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=221848 AND `item`=202296 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=221848 AND `item`=202295 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=221848 AND `item`=190888 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190858 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190830 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190803 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190697 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190686 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=221848 AND `item`=190673 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190544 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190429 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190202 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190167 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=190064 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=189870 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=221848 AND `item`=188249 AND `ExtendedCost`=7234 AND `type`=1) OR (`entry`=221848 AND `item`=188248 AND `ExtendedCost`=7234 AND `type`=1) OR (`entry`=221848 AND `item`=188244 AND `ExtendedCost`=7235 AND `type`=1) OR (`entry`=221848 AND `item`=188243 AND `ExtendedCost`=7235 AND `type`=1) OR (`entry`=221848 AND `item`=188237 AND `ExtendedCost`=7236 AND `type`=1) OR (`entry`=221848 AND `item`=188236 AND `ExtendedCost`=7236 AND `type`=1) OR (`entry`=221848 AND `item`=151116 AND `ExtendedCost`=6211 AND `type`=1) OR (`entry`=221848 AND `item`=151120 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=151119 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=151118 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=151117 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=157577 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=157576 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=157574 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=157573 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=164378 AND `ExtendedCost`=6444 AND `type`=1) OR (`entry`=221848 AND `item`=168061 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=168060 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=168059 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=221848 AND `item`=168058 AND `ExtendedCost`=6188 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(221848, 56, 210850, 0, 7856, 1, 0, 0, 56461), -- Trader's Sepia Sarong
(221848, 55, 212626, 0, 7856, 1, 0, 0, 56461), -- Dueler's Sepia Shoulder Cape
(221848, 54, 213518, 0, 7856, 1, 0, 0, 56461), -- Classic Sepia Tabard
(221848, 53, 213441, 0, 7856, 1, 0, 0, 56461), -- Earth Mother's Sepia Gloves
(221848, 52, 213430, 0, 7856, 1, 0, 0, 56461), -- Duelist's Midnight Doublet
(221848, 51, 213437, 0, 7856, 1, 0, 0, 56461), -- Duelist's Marble Doublet
(221848, 50, 213435, 0, 7856, 1, 0, 0, 56461), -- Duelist's Crimson Doublet
(221848, 49, 213434, 0, 7856, 1, 0, 0, 56461), -- Duelist's Royal Doublet
(221848, 48, 213433, 0, 7856, 1, 0, 0, 56461), -- Duelist's Ivy Doublet
(221848, 47, 213432, 0, 7856, 1, 0, 0, 56461), -- Duelist's Cedar Doublet
(221848, 46, 213431, 0, 7856, 1, 0, 0, 56461), -- Duelist's Navy Doublet
(221848, 45, 202308, 0, 7856, 1, 0, 0, 56461), -- Alley Skulker's Bandana
(221848, 44, 202307, 0, 7856, 1, 0, 0, 56461), -- Well-Worn Tricorne
(221848, 43, 202306, 0, 7856, 1, 0, 0, 56461), -- Dread Captain's Chapeau
(221848, 42, 202305, 0, 7856, 1, 0, 0, 56461), -- Stevedore's Skullcap
(221848, 41, 202304, 0, 7856, 1, 0, 0, 56461), -- Green Beanie
(221848, 40, 202303, 0, 7856, 1, 0, 0, 56461), -- Crimson Beanie
(221848, 39, 202301, 0, 7854, 1, 0, 0, 56461), -- Focalized Mana Accelerator
(221848, 38, 202300, 0, 7854, 1, 0, 0, 56461), -- Zealot's Prayer Staff
(221848, 37, 202298, 0, 7856, 1, 0, 0, 56461), -- Trader's Bicorne
(221848, 36, 202297, 0, 7854, 1, 0, 0, 56461), -- Jade Arcus
(221848, 35, 202296, 0, 7854, 1, 0, 0, 56461), -- Deathmantle Ripper
(221848, 34, 202295, 0, 7854, 1, 0, 0, 56461), -- Anointed Crusader's Claymore
(221848, 33, 190888, 0, 7855, 1, 0, 0, 56461), -- Embrace of the Great Dark Beyond
(221848, 32, 190858, 0, 7855, 1, 0, 0, 56461), -- Girdle of Chilled Embers
(221848, 31, 190830, 0, 7855, 1, 0, 0, 56461), -- Mad Thief's Boots
(221848, 30, 190803, 0, 7855, 1, 0, 0, 56461), -- Lost Acolyte's Boots
(221848, 29, 190697, 0, 7855, 1, 0, 0, 56461), -- Boots of a Broken World
(221848, 28, 190686, 0, 7854, 1, 0, 0, 56461), -- Anetheron's Edge
(221848, 27, 190673, 0, 7855, 1, 0, 0, 56461), -- Waistguard of the Infernal Eye
(221848, 26, 190544, 0, 7855, 1, 0, 0, 56461), -- Ultramafic Girdle
(221848, 25, 190429, 0, 7855, 1, 0, 0, 56461), -- Clasp of Ursine Rage
(221848, 24, 190202, 0, 7855, 1, 0, 0, 56461), -- Scoundrel's Missing Boots
(221848, 23, 190167, 0, 7855, 1, 0, 0, 56461), -- Vault Stalker's Greaves
(221848, 22, 190064, 0, 7855, 1, 0, 0, 56461), -- Ymirjar Berserker's Girdle
(221848, 21, 189870, 0, 7855, 1, 0, 0, 56461), -- Arcanofire Wrap
(221848, 20, 188249, 0, 7234, 1, 0, 0, 56461), -- Freezing Footguards
(221848, 19, 188248, 0, 7234, 1, 0, 0, 56461), -- Searing Stompers
(221848, 18, 188244, 0, 7235, 1, 0, 0, 56461), -- Virulent Gravetreaders
(221848, 17, 188243, 0, 7235, 1, 0, 0, 56461), -- Shadow-Stitched Stalkers
(221848, 16, 188237, 0, 7236, 1, 0, 0, 56461), -- Conjuror's Slippers
(221848, 15, 188236, 0, 7236, 1, 0, 0, 56461), -- Patroller's Footwear
(221848, 14, 151116, 0, 6211, 1, 50225, 0, 56461), -- Fashionable Undershirt
(221848, 13, 151120, 0, 6188, 1, 9206, 0, 56461), -- Ensemble: Righteous Battleplate
(221848, 12, 151119, 0, 6188, 1, 4617, 0, 56461), -- Ensemble: Der'izu Armor
(221848, 11, 151118, 0, 6188, 1, 17097, 0, 56461), -- Ensemble: Obsidian Prowler's Garb
(221848, 10, 151117, 0, 6188, 1, 0, 0, 56461), -- Ensemble: Mana-Etched Regalia
(221848, 9, 157577, 0, 6188, 1, 9206, 0, 56461), -- Ensemble: Goldspine Plate
(221848, 8, 157576, 0, 6188, 1, 4617, 0, 56461), -- Ensemble: Crimson Sentinel Garb
(221848, 7, 157574, 0, 6188, 1, 17097, 0, 56461), -- Ensemble: Tundraspite Armor
(221848, 6, 157573, 0, 6188, 1, 0, 0, 56461), -- Ensemble: Mindwrack Raiment
(221848, 5, 164378, 0, 6444, 1, 0, 0, 56461), -- Letter from an Admirer
(221848, 4, 168061, 0, 6188, 1, 9206, 0, 56461), -- Ensemble: Amaranthine Path Armor
(221848, 3, 168060, 0, 6188, 1, 4617, 0, 56461), -- Ensemble: Chainmail of the Timeless Hunt
(221848, 2, 168059, 0, 6188, 1, 17097, 0, 56461), -- Ensemble: Restless Dreambound Battlegear
(221848, 1, 168058, 0, 6188, 1, 0, 0, 56461); -- Ensemble: Tranquil Spiritbind Regalia

-- Path for Oathsworn Peacekeeper
SET @MOVERGUID := @CGUID+7;
SET @ENTRY := 219014;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Peacekeeper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2533.2822, -2491.658, 200.22583, NULL, 5989),
(@PATH, 1, 2549.947, -2508.3923, 200.2258, NULL, 0),
(@PATH, 2, 2574.829, -2533.2188, 200.2258, NULL, 3391),
(@PATH, 3, 2549.947, -2508.3923, 200.2258, NULL, 0);

UPDATE `creature` SET `position_x`=2533.2822, `position_y`=-2491.658, `position_z`=200.22583, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Khole
SET @MOVERGUID := @CGUID+15;
SET @ENTRY := 221002;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Khole - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2580.8142, -2519.2083, 200.22583, 0.6638, 14024),
(@PATH, 1, 2574.8645, -2524.9028, 200.22583, NULL, 38405),
(@PATH, 2, 2528.0496, -2478.8264, 200.22578, NULL, 0),
(@PATH, 3, 2524.9783, -2475.1216, 200.22578, 3.8833, 82413),
(@PATH, 4, 2536.7473, -2477.1094, 200.22578, 0.7408, 13186),
(@PATH, 5, 2532.2473, -2482.0503, 200.22578, 3.9133, 57581),
(@PATH, 6, 2543.2075, -2485.0034, 200.22578, 1.7567, 12065),
(@PATH, 7, 2540.8447, -2491.1008, 200.22583, 3.9093, 39886),
(@PATH, 8, 2561.3994, -2512.1702, 200.22583, 3.8761, 70547);

UPDATE `creature` SET `position_x`=2580.8142, `position_y`=-2519.2083, `position_z`=200.22583, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
