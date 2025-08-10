SET @CGUID := 10001637;

SET @NPCTEXTID := 600005;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2531.778564453125, -2785.2119140625, 202.451690673828125, 4.965769767761230468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+1, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2538.271728515625, -2705.467041015625, 200.157867431640625, 2.831913948059082031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 459180 - [DNT] Earthen Laborer Carry Cosmetic)
(@CGUID+2, 219321, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2547.689208984375, -2757.390625, 205.054229736328125, 2.113895893096923828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Grotir (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+3, 229379, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2511.3916015625, -2726.677001953125, 204.5569915771484375, 0.809943974018096923, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Villager (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+4, 219108, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2517.9697265625, -2775.71533203125, 202.197052001953125, 4.850820541381835937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Roldira (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+5, 219043, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2521.35595703125, -2787.467041015625, 202.251220703125, 1.61567699909210205, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Clerk Ardran (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 397053 - Crafting Order Vendor Controller, 182641 - Game Object Despawn Periodic)
(@CGUID+6, 215258, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2509.623291015625, -2753.30029296875, 204.5971221923828125, 1.510008096694946289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Clerk Gretal (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 397053 - Crafting Order Vendor Controller, 182641 - Game Object Despawn Periodic)
(@CGUID+7, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2517.455078125, -2750.0693359375, 204.5970306396484375, 4.256670475006103515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+8, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2494.052001953125, -2745.560791015625, 204.841888427734375, 2.289359331130981445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+9, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2541.282958984375, -2743.163330078125, 204.5569915771484375, 5.91660308837890625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+10, 219048, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2518.5087890625, -2788.529541015625, 202.2886962890625, 2.318159103393554687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Clerk Pordaz (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 397053 - Crafting Order Vendor Controller, 182641 - Game Object Despawn Periodic)
(@CGUID+11, 219050, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2508.9296875, -2788.151123046875, 202.479522705078125, 5.519165992736816406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Aisha (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+12, 229379, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2482.288330078125, -2737.916748046875, 200.157867431640625, 0.77998131513595581, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Villager (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 122236 - Read Scroll)
(@CGUID+13, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2492.06591796875, -2745.901123046875, 205.513458251953125, 0.722091615200042724, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+14, 228177, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2526.248291015625, -2775.638916015625, 202.268096923828125, 3.911191940307617187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Kala Clayhoof (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+15, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2505.693603515625, -2765.126708984375, 205.078399658203125, 2.732352018356323242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+16, 219319, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2554.1884765625, -2756.901123046875, 205.054229736328125, 5.423876762390136718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Yorda (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+17, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2542.3359375, -2743.796875, 204.5569915771484375, 2.732352018356323242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+18, 226744, 2552, 14771, 15043, '0', 0, 0, 0, 1, 2529.81689453125, -2711.428955078125, 204.78851318359375, 4.214966297149658203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Ranger Selone (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+19, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2532.201416015625, -2786.9150390625, 202.451690673828125, 1.904890894889831542, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+20, 219051, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2510.170166015625, -2789.63720703125, 202.479522705078125, 2.294265270233154296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Lyrendal (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+21, 226745, 2552, 14771, 15043, '0', 0, 0, 0, 1, 2527.17529296875, -2712.4619140625, 204.6619873046875, 0.399299442768096923, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Pathstalker Ralsir (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+22, 229927, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2492.826416015625, -2743.84716796875, 204.841888427734375, 5.3529510498046875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+23, 226746, 2552, 14771, 15043, '0', 0, 0, 0, 1, 2529.346435546875, -2713.369873046875, 204.78851318359375, 2.103442907333374023, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Rulen Lightsreap (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+24, 219223, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2527.27685546875, -2753.263916015625, 204.6282501220703125, 2.209727048873901367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Mahra Treebender (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+25, 229379, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2512.802978515625, -2725.194580078125, 204.55902099609375, 3.95153665542602539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Villager (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+26, 214947, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2518.346435546875, -2737.708251953125, 206.7676239013671875, 0, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56461), -- Eye of Topaz (Area: The Forgegrounds - Difficulty: 0) CreateObject2
(@CGUID+27, 214947, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2516.509521484375, -2728.4375, 206.909088134765625, 0, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56461); -- Eye of Topaz (Area: The Forgegrounds - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459180'), -- Unbound Crafter - 459180 - [DNT] Earthen Laborer Carry Cosmetic
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '435518'), -- Unbound Villager - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '122236'), -- Unbound Villager - 122236 - Read Scroll
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Unbound Crafter
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 25374, 0, 0, 0, ''), -- Unbound Crafter
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''); -- Yorda

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (226746 /*226746 (Rulen Lightsreap)*/, 226745 /*226745 (Pathstalker Ralsir)*/, 226744 /*226744 (Ranger Selone)*/, 219048 /*219048 (Clerk Pordaz) - Crafting Order Vendor Controller, Game Object Despawn Periodic*/, 215258 /*215258 (Clerk Gretal) - Crafting Order Vendor Controller, Game Object Despawn Periodic*/, 219043 /*219043 (Clerk Ardran) - Crafting Order Vendor Controller, Game Object Despawn Periodic*/, 219108 /*219108 (Roldira)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(226746, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 226746 (Rulen Lightsreap)
(226745, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 226745 (Pathstalker Ralsir)
(226744, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 226744 (Ranger Selone)
(219048, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '397053'), -- 219048 (Clerk Pordaz) - Crafting Order Vendor Controller, Game Object Despawn Periodic
(215258, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '397053'), -- 215258 (Clerk Gretal) - Crafting Order Vendor Controller, Game Object Despawn Periodic
(219043, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '397053'), -- 219043 (Clerk Ardran) - Crafting Order Vendor Controller, Game Object Despawn Periodic
(219108, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- 219108 (Roldira)

-- Template
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=223095; -- Bedrock Stonecharger
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219317; -- Kornak
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=228485; -- Crafting Orders - Credit
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=228177; -- Kala Clayhoof
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219050; -- Aisha
UPDATE `creature_template` SET `faction`=3407, `npcflag`=4503599627370497, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219048; -- Clerk Pordaz
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219076; -- Kornd
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry` IN (219151, 219150); -- Oathsworn Citizen
UPDATE `creature_template` SET `faction`=3407, `npcflag`=4503599627370497, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215258; -- Clerk Gretal
UPDATE `creature_template` SET `faction`=3407, `npcflag`=4503599627370497, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219043; -- Clerk Ardran
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219097; -- Tarib
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry` IN (219392, 219391); -- Forgegrounds Worker
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219108; -- Roldira
UPDATE `creature_template` SET `faction`=3407, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219096; -- Gareb
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223642; -- Forgegrounds Machinesmith
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219080; -- Marbb
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=226785; -- Kondal Huntsworn
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=219223; -- Mahra Treebender
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226746; -- Rulen Lightsreap
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219181; -- Coreling
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226745; -- Pathstalker Ralsir
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219051; -- Lyrendal
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226744; -- Ranger Selone
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219083; -- Ginnad
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219082; -- Kradan

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226785 AND `DifficultyID`=0); -- 226785 (Kondal Huntsworn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219223 AND `DifficultyID`=0); -- 219223 (Mahra Treebender) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226746 AND `DifficultyID`=0); -- 226746 (Rulen Lightsreap) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219181 AND `DifficultyID`=0); -- 219181 (Coreling) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226745 AND `DifficultyID`=0); -- 226745 (Pathstalker Ralsir) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219051 AND `DifficultyID`=0); -- 219051 (Lyrendal) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226744 AND `DifficultyID`=0); -- 226744 (Ranger Selone) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219083 AND `DifficultyID`=0); -- 219083 (Ginnad) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219082 AND `DifficultyID`=0); -- 219082 (Kradan) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=56461 WHERE (`Entry`=223642 AND `DifficultyID`=0); -- 223642 (Forgegrounds Machinesmith) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219080 AND `DifficultyID`=0); -- 219080 (Marbb) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=536870912, `VerifiedBuild`=56461 WHERE (`Entry`=228485 AND `DifficultyID`=0); -- 228485 (Crafting Orders - Credit) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=228177 AND `DifficultyID`=0); -- 228177 (Kala Clayhoof) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219050 AND `DifficultyID`=0); -- 219050 (Aisha) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219048 AND `DifficultyID`=0); -- 219048 (Clerk Pordaz) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219076 AND `DifficultyID`=0); -- 219076 (Kornd) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219151 AND `DifficultyID`=0); -- 219151 (Oathsworn Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=215258 AND `DifficultyID`=0); -- 215258 (Clerk Gretal) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219043 AND `DifficultyID`=0); -- 219043 (Clerk Ardran) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219097 AND `DifficultyID`=0); -- 219097 (Tarib) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219392 AND `DifficultyID`=0); -- 219392 (Forgegrounds Worker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219108 AND `DifficultyID`=0); -- 219108 (Roldira) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219391 AND `DifficultyID`=0); -- 219391 (Forgegrounds Worker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219096 AND `DifficultyID`=0); -- 219096 (Gareb) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=223095 AND `DifficultyID`=0); -- 223095 (Bedrock Stonecharger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219317 AND `DifficultyID`=0); -- 219317 (Kornak) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=219050 AND `MenuID` = 36557) OR (`CreatureID`=219048 AND `MenuID`=30243) OR (`CreatureID`=219043 AND `MenuID`=30243) OR (`CreatureID`=215258 AND `MenuID`=30243) OR (`CreatureID`=219223 AND `MenuID` = 28690);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(219050, 36557, 56461), -- Aisha
(219048, 30243, 56461), -- Clerk Pordaz
(219043, 30243, 56461), -- Clerk Ardran
(215258, 30243, 56461), -- Clerk Gretal
(219223, 28690, 56461); -- Mahra Treebender

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+4;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 224784, 0, 0, 0, 0, 0, 0, 0, 56461), -- 219050 (Aisha)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 233826, 0, 0, 0, 0, 0, 0, 0, 56461), -- 219223 (Mahra Treebender)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 225012, 0, 0, 0, 0, 0, 0, 0, 56461), -- 219223 (Mahra Treebender)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 224788, 0, 0, 0, 0, 0, 0, 0, 56461), -- 219050 (Aisha)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 224790, 0, 0, 0, 0, 0, 0, 0, 56461); -- 219050 (Aisha)

DELETE FROM `gossip_menu` WHERE (`MenuID`=36557 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30351 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=28690 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=28661 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=28663 AND `TextID`=@NPCTEXTID+4);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(36557, @NPCTEXTID+0, 56461), -- 219050 (Aisha)
(30351, @NPCTEXTID+1, 56461), -- 219223 (Mahra Treebender)
(28690, @NPCTEXTID+2, 56461), -- 219223 (Mahra Treebender)
(28661, @NPCTEXTID+3, 56461), -- 219050 (Aisha)
(28663, @NPCTEXTID+4, 56461); -- 219050 (Aisha)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30243 AND `TextID`=233159);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30243, 233159, 56461); -- 219048 (Clerk Pordaz)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (28663,28690,28661,36557,30351,30243)) OR (`OptionID`=1 AND `MenuID`=36557) OR (`OptionID`=4 AND `MenuID`=30351) OR (`OptionID`=2 AND `MenuID`=30351);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(28663, 55661, 0, 0, 'I want to talk about something else.', 0, 0, 0, 36557, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(28690, 107892, 0, 0, 'I would like to talk about my profession equipment.', 0, 0, 0, 30351, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(36557, 124502, 1, 0, 'Tell me about the Artisan\'s Consortium.', 0, 0, 0, 28661, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(28661, 55658, 0, 0, 'I want to talk about something else.', 0, 0, 0, 36557, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(30351, 107894, 4, 0, 'Limit how much I see my fishing equipment. Only show my fishing rod while fishing.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(36557, 124504, 0, 0, 'Tell me about crafting orders.', 0, 0, 0, 28663, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(30351, 107891, 0, 0, 'Limit how much I see my crafting equipment. Hide my accessories and only show my tool while crafting.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(30351, 107896, 2, 0, 'Limit how much I see my gathering equipment. Hide my accessories and only show my tool while gathering.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(30243, 107733, 0, 50, 'I\'d like to create a crafting order.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461);

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (120827, 120825);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(120827, 0.347000002861022949, 1.5, 0, 56461),
(120825, 0.347000002861022949, 1.5, 0, 56461);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=219051 AND `item`=228337 AND `ExtendedCost`=9103 AND `type`=1) OR (`entry`=219051 AND `item`=227682 AND `ExtendedCost`=9103 AND `type`=1) OR (`entry`=219051 AND `item`=227681 AND `ExtendedCost`=9103 AND `type`=1) OR (`entry`=219051 AND `item`=227676 AND `ExtendedCost`=9103 AND `type`=1) OR (`entry`=219051 AND `item`=227675 AND `ExtendedCost`=9103 AND `type`=1) OR (`entry`=219051 AND `item`=224420 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=224421 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=224422 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223104 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223110 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223109 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223108 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223107 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223106 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=228329 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=228379 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223091 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223092 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223090 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223089 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223066 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223070 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223067 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223065 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223069 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223071 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223068 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223113 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223132 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223131 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223130 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223129 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223124 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223037 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223052 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223050 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223054 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223053 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219051 AND `item`=223049 AND `ExtendedCost`=9102 AND `type`=1) OR (`entry`=219319 AND `item`=188152 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=138293 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=10498 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=6219 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=6218 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=222701 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=222700 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=222699 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=222697 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=222696 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=222695 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=224764 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=200860 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219319 AND `item`=211806 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(219051, 72, 228337, 0, 9103, 1, 0, 0, 56461), -- Satchel of Surplus Dust
(219051, 71, 227682, 0, 9103, 1, 0, 0, 56461), -- Satchel of Surplus Cloth
(219051, 70, 227681, 0, 9103, 1, 0, 0, 56461), -- Satchel of Surplus Leather
(219051, 69, 227676, 0, 9103, 1, 0, 0, 56461), -- Satchel of Surplus Ore
(219051, 68, 227675, 0, 9103, 1, 0, 0, 56461), -- Satchel of Surplus Herbs
(219051, 67, 224420, 0, 9102, 1, 0, 0, 56461), -- Pattern: Artisan Gardening Hat
(219051, 66, 224421, 0, 9102, 1, 0, 0, 56461), -- Pattern: Artisan Fishing Cap
(219051, 65, 224422, 0, 9102, 1, 0, 0, 56461), -- Pattern: Artisan Enchanter's Hat
(219051, 64, 223104, 0, 9102, 1, 0, 0, 56461), -- Pattern: Defender's Armor Kit
(219051, 63, 223110, 0, 9102, 1, 0, 0, 56461), -- Pattern: Arathi Leatherworker's Smock
(219051, 62, 223109, 0, 9102, 1, 0, 0, 56461), -- Pattern: Earthen Jeweler's Cover
(219051, 61, 223108, 0, 9102, 1, 0, 0, 56461), -- Pattern: Stonebound Herbalist's Pack
(219051, 60, 223107, 0, 9102, 1, 0, 0, 56461), -- Pattern: Charged Scrapmaster's Gauntlets
(219051, 59, 223106, 0, 9102, 1, 0, 0, 56461), -- Pattern: Earthen Forgemaster's Apron
(219051, 58, 228329, 0, 9102, 1, 0, 0, 56461), -- Design: Remembrance Stone
(219051, 57, 228379, 0, 9102, 1, 0, 0, 56461), -- Design: Captured Starlight
(219051, 56, 223091, 0, 9102, 1, 0, 0, 56461), -- Design: Forger's Font Inspector
(219051, 55, 223092, 0, 9102, 1, 0, 0, 56461), -- Design: Novelist's Specs
(219051, 54, 223090, 0, 9102, 1, 0, 0, 56461), -- Design: Enchanter's Crystal
(219051, 53, 223089, 0, 9102, 1, 0, 0, 56461), -- Design: Extravagant Loupes
(219051, 52, 223066, 0, 9102, 1, 0, 0, 56461), -- Technique: Algari Missive of Resourcefulness
(219051, 51, 223070, 0, 9102, 1, 0, 0, 56461), -- Technique: Algari Missive of Perception
(219051, 50, 223067, 0, 9102, 1, 0, 0, 56461), -- Technique: Algari Missive of Multicraft
(219051, 49, 223065, 0, 9102, 1, 0, 0, 56461), -- Technique: Algari Missive of Ingenuity
(219051, 48, 223069, 0, 9102, 1, 0, 0, 56461), -- Technique: Algari Missive of Finesse
(219051, 47, 223071, 0, 9102, 1, 0, 0, 56461), -- Technique: Algari Missive of Deftness
(219051, 46, 223068, 0, 9102, 1, 0, 0, 56461), -- Technique: Algari Missive of Crafting Speed
(219051, 45, 223113, 0, 9102, 1, 0, 0, 56461), -- Formula: Enchant Boots - Cavalry's March
(219051, 44, 223132, 0, 9102, 1, 0, 0, 56461), -- Formula: Enchant Tool - Algari Resourcefulness
(219051, 43, 223131, 0, 9102, 1, 0, 0, 56461), -- Formula: Enchant Tool - Algari Perception
(219051, 42, 223130, 0, 9102, 1, 0, 0, 56461), -- Formula: Enchant Tool - Algari Finesse
(219051, 41, 223129, 0, 9102, 1, 0, 0, 56461), -- Formula: Enchant Tool - Algari Deftness
(219051, 40, 223124, 0, 9102, 1, 0, 0, 56461), -- Formula: Runed Null Stone Rod
(219051, 39, 223037, 0, 9102, 1, 0, 0, 56461), -- Plans: Charged Facesmasher
(219051, 38, 223052, 0, 9102, 1, 0, 0, 56461), -- Plans: Artisan Needle Set
(219051, 37, 223050, 0, 9102, 1, 0, 0, 56461), -- Plans: Artisan Pickaxe
(219051, 36, 223054, 0, 9102, 1, 0, 0, 56461), -- Plans: Artisan Leatherworker's Toolset
(219051, 35, 223053, 0, 9102, 1, 0, 0, 56461), -- Plans: Artisan Leatherworker's Knife
(219051, 34, 223049, 0, 9102, 1, 0, 0, 56461), -- Plans: Artisan Sickle
(219319, 23, 188152, 0, 0, 1, 0, 0, 56461), -- Gateway Control Shard
(219319, 22, 64670, 0, 0, 1, 0, 0, 56461), -- Vanishing Powder
(219319, 21, 138293, 0, 0, 1, 0, 0, 56461), -- Explorer's Pack
(219319, 20, 85663, 0, 0, 1, 0, 0, 56461), -- Herbalist's Spade
(219319, 19, 2901, 0, 0, 1, 0, 0, 56461), -- Mining Pick
(219319, 18, 7005, 0, 0, 1, 0, 0, 56461), -- Skinning Knife
(219319, 17, 39505, 0, 0, 1, 0, 0, 56461), -- Virtuoso Inking Set
(219319, 16, 6256, 0, 0, 1, 0, 0, 56461), -- Fishing Pole
(219319, 15, 10498, 0, 0, 1, 0, 0, 56461), -- Gyromatic Micro-Adjustor
(219319, 14, 6219, 0, 0, 1, 0, 0, 56461), -- Arclight Spanner
(219319, 13, 20815, 0, 0, 1, 0, 0, 56461), -- Jeweler's Toolset
(219319, 12, 6218, 0, 0, 1, 0, 0, 56461), -- Runed Copper Rod
(219319, 11, 5956, 0, 0, 1, 0, 0, 56461), -- Blacksmith Hammer
(219319, 10, 222701, 0, 0, 1, 0, 0, 56461), -- Clumped Flour
(219319, 9, 222700, 0, 0, 1, 0, 0, 56461), -- Granulated Spices
(219319, 8, 222699, 0, 0, 1, 0, 0, 56461), -- Khaz Algar Tomato
(219319, 7, 222697, 0, 0, 1, 0, 0, 56461), -- Coreway Dust
(219319, 6, 222696, 0, 0, 1, 0, 0, 56461), -- Crunchy Peppers
(219319, 5, 222695, 0, 0, 1, 0, 0, 56461), -- Twined Herbs
(219319, 4, 224764, 0, 0, 1, 0, 0, 56461), -- Mosswool Thread
(219319, 3, 38682, 0, 0, 1, 0, 0, 56461), -- Enchanting Vellum
(219319, 2, 200860, 0, 0, 1, 0, 0, 56461), -- Draconic Stopper
(219319, 1, 211806, 0, 0, 1, 0, 0, 56461); -- Gilded Vial

-- Path for Unbound Crafter
SET @MOVERGUID := @CGUID+7;
SET @ENTRY := 229927;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Unbound Crafter - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2516.8484, -2753.4312, 205.17563, NULL, 0),
(@PATH, 1, 2517.117, -2752.605, 204.99939, NULL, 0),
(@PATH, 2, 2518.2285, -2750.5215, 204.47366, NULL, 0),
(@PATH, 3, 2519.2354, -2749.8142, 204.47366, NULL, 0),
(@PATH, 4, 2522.1008, -2746.908, 204.47366, NULL, 0),
(@PATH, 5, 2526.144, -2745.7622, 204.47366, NULL, 0),
(@PATH, 6, 2529.9792, -2745.0886, 204.47366, NULL, 0),
(@PATH, 7, 2535.8638, -2745.9307, 204.47366, NULL, 0),
(@PATH, 8, 2540.5642, -2747.916, 204.47366, NULL, 0),
(@PATH, 9, 2543.3132, -2750.6948, 205.18445, NULL, 0),
(@PATH, 10, 2545.882, -2753.4844, 205.13246, NULL, 0),
(@PATH, 11, 2546.7578, -2755.389, 204.98132, NULL, 6164),
(@PATH, 12, 2516.888, -2786.4548, 202.11372, NULL, 5236),
(@PATH, 13, 2510.8125, -2782.3855, 202.59071, NULL, 0),
(@PATH, 14, 2507.7778, -2779.816, 202.59071, NULL, 0),
(@PATH, 15, 2506.6562, -2776.8728, 202.82677, NULL, 0),
(@PATH, 16, 2506.5027, -2771.6562, 205.18445, NULL, 0),
(@PATH, 17, 2507.0598, -2768.3906, 205.18445, NULL, 0),
(@PATH, 18, 2509.587, -2765.2727, 205.09015, NULL, 0),
(@PATH, 19, 2511.7466, -2765.481, 205.18445, NULL, 0),
(@PATH, 20, 2515.934, -2764.2292, 205.18445, NULL, 0),
(@PATH, 21, 2516.4468, -2758.1318, 205.14728, NULL, 0),
(@PATH, 22, 2516.2727, -2755.2014, 205.18445, NULL, 0);

UPDATE `creature` SET `position_x`=2516.8484, `position_y`=-2753.4312, `position_z`=205.17563, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
