SET @CGUID := 5000142;
SET @OGUID := 5000052;

-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=96568; -- Climbing Rope

DELETE FROM `creature_template_addon` WHERE `entry` IN (96765, 96637, 96568, 96545, 96538, 96536, 96535);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(96765, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191547'), -- 96765 (Dread Fertilizer)
(96637, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(96568, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '191279'), -- 96568 (Climbing Rope) - Rope Visual
(96545, 0, 0, 0, 0, 0, 1, 0, 429, 0, 0, 0, 0, ''), -- 96545 (Growing Squashling)
(96538, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96538 (Brackish Cultivator)
(96536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96536 (Salty Dreg)
(96535, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '171506'); -- 96535 (Captain Bonerender) - Pirate Hat Visual

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (96568,96765);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(96568, 0, 0, 1, 0, 0, 0, NULL),
(96765, 0, 0, 1, 1, 0, 0, NULL);

UPDATE `creature_equip_template` SET `VerifiedBuild`=51754 WHERE (`ID`=1 AND `CreatureID` IN (96637,96538,96536,96535));

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=96568;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(96568, 191253, 3, 0); -- Target position: -1191.3108 Y: -363.47745 Z: 5.717531 O: 3.03687286376953125

-- Difficulties
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (96765,96637,96568,96545,96538,96536,96535));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(96765, 0, 0, 0, 435, 9, 0.009999999776482582, 1, 97264, 2098192, 0, 51754), -- Dread Fertilizer
(96637, 0, 0, 0, 435, 9, 0.699999988079071044, 1, 97136, 0, 0, 51754), -- Boneship Reveler
(96568, 0, 0, 0, 425, 9, 1, 1, 97065, 1073742864, 6, 51754), -- Climbing Rope
(96545, 0, 0, 0, 435, 9, 2, 1, 97042, 0, 0, 51754), -- Growing Squashling
(96538, 0, 0, 0, 435, 9, 1.5, 1, 97035, 0, 0, 51754), -- Brackish Cultivator
(96536, 0, 0, 0, 435, 9, 1, 1, 97033, 0, 0, 51754), -- Salty Dreg
(96535, 0, 0, 0, 435, 9, 20, 1, 97032, 2147483720, 0, 51754); -- Captain Bonerender

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=51754 WHERE (`Idx`=0 AND `CreatureID` IN (87652,84933,84920,96535,84924,96536,78385,85092,82301,78033,6491,96538,85057,88975,84966,96637,84923,96765,78387,84921,84922,82196,88903,84930,96545,96568,88976)) OR (`Idx`=1 AND `CreatureID` IN (84933,84924,85092,82301,78033,85057,84923,84922,82196,88903,84930,96568)) OR (`Idx`=2 AND `CreatureID` IN (84924,84923));

UPDATE `creature_model_info` SET `VerifiedBuild`=51754 WHERE `DisplayID` IN (65295, 58951, 42109, 65292, 65294, 65293, 59861, 56803, 60891, 61206, 59970, 62783, 17877, 61536, 54816, 54820, 17101, 16946, 56886, 54483, 54509, 54235, 5233);
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400016546249389, `CombatReach`=1.80000007152557373, `VerifiedBuild`=51754 WHERE `DisplayID`=62760;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=51754 WHERE `DisplayID` IN (62757, 62756);
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=51754 WHERE `DisplayID`=62761;
UPDATE `creature_model_info` SET `BoundingRadius`=2.383842706680297851, `CombatReach`=1.20000004768371582, `VerifiedBuild`=51754 WHERE `DisplayID`=56927;

-- Gameobject templates
DELETE FROM `gameobject_template_addon` WHERE `entry`=243927;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(243927, 0, 1048608, 0, 0); -- Forgotten Ship

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+184;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 96535, 1116, 6719, 7258, '0', 0, 0, 0, 1, -1193.7100830078125, -328.161468505859375, 18.52200508117675781, 4.576361656188964843, 120, 0, 0, 2258380, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Captain Bonerender (Area: The Evanescent Sea - Difficulty: 0) CreateObject1 (Auras: 171506 - Pirate Hat Visual)
(@CGUID+1, 96536, 1116, 6719, 7258, '0', 0, 0, 0, 1, -1209.506591796875, -362.105133056640625, 4.499068260192871093, 0.110386960208415985, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: The Evanescent Sea - Difficulty: 0) CreateObject1
(@CGUID+2, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1203.921875, -340.23089599609375, 11.62828826904296875, 5.75540018081665039, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+3, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1203.5260009765625, -344.44964599609375, 11.14384269714355468, 0.528436124324798583, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+4, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1208.126708984375, -376.848968505859375, 12.10113143920898437, 1.544788956642150878, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+5, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1201.7100830078125, -377.39410400390625, 11.21275615692138671, 2.353273630142211914, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+6, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1106.4583740234375, -383.72222900390625, 2.966583728790283203, 0.325969517230987548, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+7, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1115.814208984375, -325.739593505859375, 1.604741096496582031, 1.739197611808776855, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+8, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1111.3038330078125, -322.395843505859375, 2.261497259140014648, 2.672877311706542968, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+9, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1079.2899169921875, -286.814239501953125, 2.343903064727783203, 5.261463165283203125, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+10, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1074.6875, -286, 2.458683967590332031, 4.077800750732421875, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+11, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1084.2864990234375, -374.935760498046875, 4.632270336151123046, 6.103878021240234375, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+12, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1095.0728759765625, -427.692718505859375, 2.026491403579711914, 3.898728370666503906, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1050.6007080078125, -405.015625, 10.52661418914794921, 1.113119840621948242, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+14, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1022.9149169921875, -468.008697509765625, 8.838909149169921875, 4.634902000427246093, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+15, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -910.888916015625, -415.046875, 7.366283893585205078, 2.809302330017089843, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+16, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -915.89239501953125, -349.548614501953125, 2.068488597869873046, 4.022851467132568359, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+17, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -938.01043701171875, -297.71527099609375, 1.082256197929382324, 0.353676319122314453, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+18, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -933.3663330078125, -295.44964599609375, 0.982174456119537353, 3.639851331710815429, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+19, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -919.5225830078125, -321.227447509765625, 4.767072677612304687, 1.001519083976745605, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+20, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -835.18231201171875, -364.296875, 2.845531940460205078, 2.182092666625976562, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+21, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -887.7882080078125, -494.796875, 4.016953468322753906, 2.763939380645751953, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+22, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -988.34722900390625, -530.8524169921875, 8.473195075988769531, 0.328159838914871215, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 96536, 1116, 6719, 7221, '0', 0, 0, 0, 1, -798.515625, -461.4288330078125, 0.810010850429534912, 1.176262259483337402, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+24, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -803.9617919921875, -456.336822509765625, 0.677557885646820068, 0.122052669525146484, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+25, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -782.06597900390625, -372.713531494140625, 0.444017648696899414, 3.776806831359863281, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+26, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -715.638916015625, -471.37152099609375, 2.981159687042236328, 6.2617645263671875, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+27, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -712.76910400390625, -467.102447509765625, 3.437993049621582031, 4.221546649932861328, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+28, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -786.01910400390625, -376.03125, 0.503575384616851806, 0.793695509433746337, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+29, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -737.70660400390625, -391.447906494140625, 1.889541029930114746, 1.034990668296813964, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+30, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -733.1875, -388.779510498046875, 1.781613469123840332, 2.990638256072998046, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+31, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -667.20831298828125, -237.185760498046875, 3.355466127395629882, 3.283962726593017578, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+32, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -664.42364501953125, -262.947906494140625, 5.226436614990234375, 5.090390682220458984, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+33, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -676.71356201171875, -381.7569580078125, 0.754504978656768798, 3.982931137084960937, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+34, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -639.732666015625, -372.7257080078125, 5.158214569091796875, 3.707249164581298828, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+35, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -628.01043701171875, -315.842010498046875, 2.38847208023071289, 5.979445934295654296, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+36, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -597.10418701171875, -388.21875, 3.921705007553100585, 2.412693023681640625, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+37, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -646.75, -434.986114501953125, 0.698956608772277832, 3.634465694427490234, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+38, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -609.703125, -421.5382080078125, 0.643545746803283691, 2.973299026489257812, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+39, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -692.6180419921875, -439.348968505859375, 6.077012538909912109, 5.000707626342773437, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+40, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -642.013916015625, -481.8663330078125, 8.386793136596679687, 2.629534006118774414, 120, 10, 0, 112919, 0, 1, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+41, 96536, 1116, 6719, 7220, '0', 0, 0, 0, 1, -711.1475830078125, -474.4444580078125, 3.194519996643066406, 2.14400339126586914, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Salty Dreg (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+42, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1186.9913330078125, -344.5538330078125, 11.28055953979492187, 6.103759765625, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+43, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1120.1458740234375, -409.7100830078125, 0.79177182912826538, 2.316029310226440429, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+44, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1120.954833984375, -403.8975830078125, 0.925347208976745605, 3.699538707733154296, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+45, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1116.4444580078125, -319.3663330078125, 1.548231840133666992, 5.278585433959960937, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+46, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1060.2760009765625, -328.32464599609375, 10.39146232604980468, 3.824581861495971679, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+47, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1083.734375, -370.010406494140625, 4.478267192840576171, 5.331806659698486328, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+48, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -960.98089599609375, -337.23785400390625, 9.695512771606445312, 2.525454044342041015, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+49, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -938.859375, -386.10589599609375, 8.844652175903320312, 4.583134651184082031, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+50, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -983.65625, -436.227447509765625, 10.77950382232666015, 1.283767938613891601, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+51, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -916.5850830078125, -354.899322509765625, 2.528637886047363281, 1.837605118751525878, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+52, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -883.79168701171875, -409.8350830078125, 2.401940345764160156, 4.253957748413085937, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+53, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -884.04339599609375, -417.133697509765625, 1.934554934501647949, 1.816419601440429687, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+54, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -848.7742919921875, -482.03125, 3.167809247970581054, 0.92781919240951538, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+55, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -841.96875, -480.295135498046875, 4.158066272735595703, 2.373423099517822265, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+56, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1059.7864990234375, -522.57989501953125, 8.707714080810546875, 2.928937911987304687, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+57, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1110.717041015625, -506.654510498046875, 0.968957245349884033, 4.084527492523193359, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+58, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1111.1961669921875, -514.029541015625, 1.001343727111816406, 1.550184488296508789, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+59, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1117.4739990234375, -510.473968505859375, 0.66840517520904541, 0.591766119003295898, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+60, 96538, 1116, 6719, 7221, '0', 0, 0, 0, 1, -819.70660400390625, -486.703125, 5.614330291748046875, 3.884082555770874023, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Isle of Shadows - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+61, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -806.545166015625, -360.321197509765625, 3.548784971237182617, 4.437572956085205078, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+62, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -746.1944580078125, -446.21527099609375, 2.34596109390258789, 4.253957271575927734, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+63, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -743.41668701171875, -451.326385498046875, 2.173023223876953125, 2.660516023635864257, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+64, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -675.14581298828125, -343.53472900390625, 1.028312325477600097, 5.39819192886352539, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+65, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -676.26214599609375, -351.588531494140625, 0.963738441467285156, 0.52176755666732788, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+66, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -673.30206298828125, -238.45660400390625, 2.950892210006713867, 0.152675822377204895, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+67, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -669.63714599609375, -347.895843505859375, 1.124920129776000976, 3.005897045135498046, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+68, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -660.25, -314.763885498046875, 2.731441974639892578, 6.0605926513671875, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+69, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -619.39410400390625, -284.19964599609375, 4.324260711669921875, 5.113718509674072265, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+70, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -608.6805419921875, -360.73089599609375, 3.162667036056518554, 2.640128135681152343, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+71, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -612.467041015625, -417.104156494140625, 0.774821996688842773, 4.020412921905517578, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+72, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -614.36981201171875, -423.645843505859375, 0.576269149780273437, 0.990790724754333496, 120, 0, 0, 135503, 7196, 0, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+73, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -646.982666015625, -412.5225830078125, 0.830386102199554443, 4.483406543731689453, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+74, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -619.060791015625, -459.7257080078125, 6.509813785552978515, 0.172185868024826049, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+75, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -686.97052001953125, -491.8350830078125, 4.987767696380615234, 4.004814624786376953, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+76, 96538, 1116, 6719, 7220, '0', 0, 0, 0, 1, -651.33856201171875, -514.7882080078125, 10.16422176361083984, 2.73183751106262207, 120, 10, 0, 135503, 7196, 1, NULL, NULL, NULL, NULL, 51754), -- Brackish Cultivator (Area: Forgotten Shore - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+77, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1078.342041015625, -317.744781494140625, 9.163714408874511718, 3.548194408416748046, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+78, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1032.3367919921875, -361.37152099609375, 19.72734832763671875, 2.722000837326049804, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+79, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1050.279541015625, -391.87847900390625, 10.37915229797363281, 3.684724092483520507, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+80, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1056.0694580078125, -418.232635498046875, 9.462332725524902343, 2.662836074829101562, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+81, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -996.79168701171875, -427.640625, 12.91129207611083984, 5.259998321533203125, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+82, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -971.00347900390625, -393.829864501953125, 11.00345039367675781, 5.76037454605102539, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+83, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1020.36981201171875, -453.576385498046875, 10.97628307342529296, 4.500080585479736328, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+84, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -974.65972900390625, -349.984375, 11.34560775756835937, 1.279561042785644531, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+85, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -917.07989501953125, -427.640625, 6.601091384887695312, 5.312909603118896484, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+86, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -941.0225830078125, -330.501739501953125, 7.858941078186035156, 2.313801288604736328, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+87, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -907.90277099609375, -397.55902099609375, 7.846124649047851562, 0.650418519973754882, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+88, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -831.39239501953125, -351.75, 5.219860076904296875, 4.121284008026123046, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+89, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -875.54339599609375, -503.9600830078125, 4.708648681640625, 4.087033271789550781, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+90, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1000.10589599609375, -514.98785400390625, 9.672871589660644531, 0.478303730487823486, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+91, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -971.935791015625, -542.92706298828125, 7.852010250091552734, 4.816001415252685546, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+92, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1071.2291259765625, -507.614593505859375, 8.411752700805664062, 1.053886890411376953, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+93, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1073.1163330078125, -541.11114501953125, 8.268064498901367187, 5.209440231323242187, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+94, 96545, 1116, 6719, 7221, '0', 0, 0, 0, 0, -818.24652099609375, -470.61285400390625, 4.3637847900390625, 0.929270088672637939, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+95, 96545, 1116, 6719, 7220, '0', 0, 0, 0, 0, -817.9913330078125, -368.532989501953125, 4.876975059509277343, 4.561427593231201171, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+96, 96545, 1116, 6719, 7220, '0', 0, 0, 0, 0, -643.9757080078125, -308.53125, 7.254978656768798828, 3.969005107879638671, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+97, 96545, 1116, 6719, 7220, '0', 0, 0, 0, 0, -625.8350830078125, -299.263885498046875, 6.365856170654296875, 5.817579269409179687, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+98, 96545, 1116, 6719, 7220, '0', 0, 0, 0, 0, -628.78643798828125, -361.829864501953125, 5.814889430999755859, 2.274991512298583984, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+99, 96545, 1116, 6719, 7220, '0', 0, 0, 0, 0, -593.5399169921875, -375.635406494140625, 5.387855052947998046, 0.087856620550155639, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+100, 96545, 1116, 6719, 7220, '0', 0, 0, 0, 0, -619.670166015625, -383.864593505859375, 6.732991218566894531, 3.981350660324096679, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+101, 96545, 1116, 6719, 7220, '0', 0, 0, 0, 0, -678.75177001953125, -433.376739501953125, 7.254546642303466796, 2.056625127792358398, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+102, 96545, 1116, 6719, 7220, '0', 0, 0, 0, 0, -637.623291015625, -463.170135498046875, 7.695683002471923828, 0.359033524990081787, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+103, 96545, 1116, 6719, 7220, '0', 0, 0, 0, 0, -665.52606201171875, -496.3819580078125, 9.412636756896972656, 4.815881729125976562, 120, 0, 0, 225838, 3155, 0, NULL, NULL, NULL, NULL, 51754), -- Growing Squashling (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+104, 96568, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1190.9947509765625, -363.623260498046875, -3.98762249946594238, 5.650606632232666015, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Climbing Rope (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: 191279 - Rope Visual)
(@CGUID+105, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1078.3958740234375, -376.26910400390625, 8.033085823059082031, 2.837015390396118164, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+106, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1076.94970703125, -289.989593505859375, 2.324862003326416015, 1.673211932182312011, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+107, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1080.6927490234375, -407.125, 3.986870527267456054, 3.744436502456665039, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+108, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1078.3125, -410.439239501953125, 4.249439239501953125, 3.086113691329956054, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+109, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1001.578125, -319.6007080078125, 2.645784854888916015, 1.777012825012207031, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+110, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1004.64410400390625, -321.1944580078125, 2.606362104415893554, 1.377916336059570312, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+111, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1006.015625, -315.44964599609375, 2.784274578094482421, 5.082476139068603515, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+112, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1002.50347900390625, -315.46527099609375, 2.862768888473510742, 4.09711313247680664, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+113, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1007.6771240234375, -319.177093505859375, 2.715655326843261718, 6.096836566925048828, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+114, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1065.064208984375, -448.782989501953125, 1.494293093681335449, 5.553370475769042968, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+115, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1060.0069580078125, -450.430572509765625, 1.434503793716430664, 3.397302627563476562, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+116, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1062.857666015625, -453.899322509765625, 0.979252815246582031, 1.438039898872375488, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+117, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -970.83856201171875, -454.873260498046875, 5.22081756591796875, 5.082390785217285156, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+118, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1022.07989501953125, -492.08160400390625, 12.28872203826904296, 1.315648913383483886, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+119, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -943.90972900390625, -432.446197509765625, 6.51710367202758789, 4.940755844116210937, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+120, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -976.57464599609375, -492.670135498046875, 2.018371105194091796, 0.465734660625457763, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+121, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -978.58856201171875, -488.87847900390625, 2.13736271858215332, 6.084416389465332031, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+122, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -920.29339599609375, -345.892364501953125, 5.584435939788818359, 5.00717926025390625, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+123, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -892.16839599609375, -375.171875, 1.618240714073181152, 0.599798738956451416, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+124, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -895.140625, -371.12847900390625, 1.389449477195739746, 6.150074958801269531, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+125, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -885.2899169921875, -439.567718505859375, 0.914905250072479248, 5.519081592559814453, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+126, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -967.52606201171875, -521.89581298828125, 7.110005378723144531, 1.073163866996765136, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+127, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -962.65277099609375, -515.61456298828125, 2.524995803833007812, 0.528108060359954833, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+128, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -970.592041015625, -518.890625, 7.234818458557128906, 0.155731543898582458, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+129, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1038.1649169921875, -547.6163330078125, 3.55426192283630371, 5.607976913452148437, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+130, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -1033.3524169921875, -542.875, 3.551939249038696289, 4.926537036895751953, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+131, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -949.576416015625, -562.41668701171875, 1.2536468505859375, 3.757236003875732421, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+132, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -954.890625, -563.25, 1.900114774703979492, 6.248692035675048828, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+133, 96637, 1116, 6719, 7221, '0', 0, 0, 0, 1, -952.76043701171875, -567.3194580078125, 1.003939270973205566, 0.907107830047607421, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+134, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -739.95489501953125, -415.76214599609375, 3.975337028503417968, 5.559958457946777343, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+135, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -735.9617919921875, -422.140625, 4.056735038757324218, 1.811505675315856933, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+136, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -735.96527099609375, -415.817718505859375, 4.080373287200927734, 4.318486690521240234, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+137, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -740.5711669921875, -420.4757080078125, 3.95074319839477539, 0.369277119636535644, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+138, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -733.54168701171875, -419.505218505859375, 4.0847930908203125, 3.1412506103515625, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+139, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -731.06768798828125, -308.977447509765625, 4.2524566650390625, 5.606479167938232421, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+140, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -685.7117919921875, -276.279510498046875, 2.0625, 4.37608194351196289, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+141, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -681.5555419921875, -278.782989501953125, 2.848958253860473632, 3.579832792282104492, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+142, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -686.40972900390625, -280.654510498046875, 1.581962227821350097, 0.750525653362274169, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+143, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -651.2117919921875, -277.336822509765625, 13.73784732818603515, 4.013784408569335937, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+144, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -704.83160400390625, -400.135406494140625, 3.635200977325439453, 1.293248534202575683, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+145, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -701.9600830078125, -398.520843505859375, 3.36073160171508789, 2.505532741546630859, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+146, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -595.89239501953125, -420.38714599609375, 5.131477832794189453, 2.982018232345581054, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+147, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -649.82989501953125, -440.751739501953125, 0.882757961750030517, 0.65892571210861206, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+148, 96637, 1116, 6719, 7220, '0', 0, 0, 0, 1, -652.84552001953125, -435.979156494140625, 1.078824281692504882, 6.242278099060058593, 120, 0, 0, 79043, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Boneship Reveler (Area: Forgotten Shore - Difficulty: 0) CreateObject1
(@CGUID+149, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1113.7535400390625, -331.3819580078125, 1.350438117980957031, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+150, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1073.6788330078125, -296.6788330078125, 8.295970916748046875, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+151, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1076.3853759765625, -371.57464599609375, 4.472421169281005859, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+152, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1105.3802490234375, -417.73089599609375, 1.990477681159973144, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+153, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1010.098876953125, -321.361114501953125, 3.050217628479003906, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+154, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -998.451416015625, -320.661468505859375, 2.721468925476074218, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+155, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -976.63714599609375, -408.227447509765625, 11.17830085754394531, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+156, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1009.01739501953125, -437.557281494140625, 12.76678276062011718, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+157, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -928.2882080078125, -422.9600830078125, 6.603029727935791015, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+158, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -966.451416015625, -460.743072509765625, 0.449305295944213867, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+159, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1019.6129150390625, -494.484375, 12.24233913421630859, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+160, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -918.18231201171875, -351.546875, 2.28778243064880371, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+161, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -933.5242919921875, -299.692718505859375, 0.687317967414855957, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+162, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -881.248291015625, -413.359375, 1.693491339683532714, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+163, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -887.0555419921875, -441.904510498046875, 0.965862095355987548, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+164, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -965.890625, -513.61456298828125, 2.33291935920715332, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+165, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -863.73956298828125, -486.883697509765625, 3.773625135421752929, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+166, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -834.4757080078125, -489.109375, 5.239371299743652343, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+167, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -835.96875, -491.548614501953125, 4.927405834197998046, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+168, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1036.421875, -543.4774169921875, 3.423050403594970703, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+169, 96765, 1116, 6719, 7221, '0', 0, 0, 0, 0, -1087.892333984375, -542.8992919921875, 7.751397132873535156, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Isle of Shadows - Difficulty: 0) CreateObject1
(@CGUID+170, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -807.08160400390625, -450.463531494140625, 0.359593540430068969, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+171, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -747.44793701171875, -442.5694580078125, 2.467395782470703125, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+172, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -780.97222900390625, -366.717010498046875, 0.615483403205871582, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+173, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -741.640625, -397.6632080078125, 2.612583637237548828, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+174, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -809.7742919921875, -345.50347900390625, 0.965236365795135498, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+175, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -733.546875, -311.505218505859375, 4.194929122924804687, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+176, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -673.08856201171875, -339.619781494140625, 0.989350497722625732, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+177, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -686.9132080078125, -270.446197509765625, 1.90123605728149414, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+178, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -673.2725830078125, -337.609375, 0.939092874526977539, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+179, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -675.01214599609375, -339.09027099609375, 1.009370088577270507, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+180, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -670.87847900390625, -234.42535400390625, 2.80073857307434082, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+181, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -605.66839599609375, -418.557281494140625, 0.753837347030639648, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+182, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -608.18402099609375, -427.614593505859375, 0.819979786872863769, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+183, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -696.81597900390625, -400.208343505859375, 3.226640939712524414, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+184, 96765, 1116, 6719, 7220, '0', 0, 0, 0, 0, -652.703125, -438.78125, 1.068488121032714843, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51754); -- Dread Fertilizer (Area: Forgotten Shore - Difficulty: 0) CreateObject1 (Auras: )

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+105 AND @CGUID+148;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+105, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+106, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+107, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+108, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+109, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+110, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+111, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+112, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+113, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+114, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+115, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+116, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+117, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+118, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+119, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+120, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+121, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+122, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+123, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+124, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+125, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+126, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+127, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+128, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+129, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+130, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+131, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+132, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+133, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+134, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+135, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+136, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+137, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+138, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+139, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+140, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+141, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+142, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+143, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+144, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+145, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+146, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+147, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 96637 (Boneship Reveler)
(@CGUID+148, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 96637 (Boneship Reveler)

UPDATE `creature` SET `position_x`=2916.5972, `position_y`=7685.8647, `position_z`=23.157822 WHERE `guid`=6000780;
UPDATE `creature` SET `position_x`=2953.3281, `position_y`=7694.014, `position_z`=25.029968 WHERE `guid`=6000782;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 243927, 1116, 6719, 7258, '0', 0, 0, -1255.6146240234375, -466.282989501953125, -1.33295881748199462, 1.963227391242980957, 0, 0, 0.831395149230957031, 0.55568164587020874, 120, 255, 1, 51754), -- Forgotten Ship (Area: The Evanescent Sea - Difficulty: 0) CreateObject1
(@OGUID+1, 243927, 1116, 6719, 7258, '0', 0, 0, -1239.529541015625, -207.458328247070312, -1.30294549465179443, 1.963227391242980957, 0, 0, 0.831395149230957031, 0.55568164587020874, 120, 255, 1, 51754), -- Forgotten Ship (Area: The Evanescent Sea - Difficulty: 0) CreateObject1
(@OGUID+2, 243927, 1116, 6719, 7258, '0', 0, 0, -1199.9427490234375, -355.876739501953125, -1.96816086769104003, 1.325668931007385253, 0, 0, 0.615353584289550781, 0.788251221179962158, 120, 255, 1, 51754); -- Forgotten Ship (Area: The Evanescent Sea - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+184;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0),
(12, @CGUID+1),
(12, @CGUID+2),
(12, @CGUID+3),
(12, @CGUID+4),
(12, @CGUID+5),
(12, @CGUID+6),
(12, @CGUID+7),
(12, @CGUID+8),
(12, @CGUID+9),
(12, @CGUID+10),
(12, @CGUID+11),
(12, @CGUID+12),
(12, @CGUID+13),
(12, @CGUID+14),
(12, @CGUID+15),
(12, @CGUID+16),
(12, @CGUID+17),
(12, @CGUID+18),
(12, @CGUID+19),
(12, @CGUID+20),
(12, @CGUID+21),
(12, @CGUID+22),
(12, @CGUID+23),
(12, @CGUID+24),
(12, @CGUID+25),
(12, @CGUID+26),
(12, @CGUID+27),
(12, @CGUID+28),
(12, @CGUID+29),
(12, @CGUID+30),
(12, @CGUID+31),
(12, @CGUID+32),
(12, @CGUID+33),
(12, @CGUID+34),
(12, @CGUID+35),
(12, @CGUID+36),
(12, @CGUID+37),
(12, @CGUID+38),
(12, @CGUID+39),
(12, @CGUID+40),
(12, @CGUID+41),
(12, @CGUID+42),
(12, @CGUID+43),
(12, @CGUID+44),
(12, @CGUID+45),
(12, @CGUID+46),
(12, @CGUID+47),
(12, @CGUID+48),
(12, @CGUID+49),
(12, @CGUID+50),
(12, @CGUID+51),
(12, @CGUID+52),
(12, @CGUID+53),
(12, @CGUID+54),
(12, @CGUID+55),
(12, @CGUID+56),
(12, @CGUID+57),
(12, @CGUID+58),
(12, @CGUID+59),
(12, @CGUID+60),
(12, @CGUID+61),
(12, @CGUID+62),
(12, @CGUID+63),
(12, @CGUID+64),
(12, @CGUID+65),
(12, @CGUID+66),
(12, @CGUID+67),
(12, @CGUID+68),
(12, @CGUID+69),
(12, @CGUID+70),
(12, @CGUID+71),
(12, @CGUID+72),
(12, @CGUID+73),
(12, @CGUID+74),
(12, @CGUID+75),
(12, @CGUID+76),
(12, @CGUID+77),
(12, @CGUID+78),
(12, @CGUID+79),
(12, @CGUID+80),
(12, @CGUID+81),
(12, @CGUID+82),
(12, @CGUID+83),
(12, @CGUID+84),
(12, @CGUID+85),
(12, @CGUID+86),
(12, @CGUID+87),
(12, @CGUID+88),
(12, @CGUID+89),
(12, @CGUID+90),
(12, @CGUID+91),
(12, @CGUID+92),
(12, @CGUID+93),
(12, @CGUID+94),
(12, @CGUID+95),
(12, @CGUID+96),
(12, @CGUID+97),
(12, @CGUID+98),
(12, @CGUID+99),
(12, @CGUID+100),
(12, @CGUID+101),
(12, @CGUID+102),
(12, @CGUID+103),
(12, @CGUID+104),
(12, @CGUID+105),
(12, @CGUID+106),
(12, @CGUID+107),
(12, @CGUID+108),
(12, @CGUID+109),
(12, @CGUID+110),
(12, @CGUID+111),
(12, @CGUID+112),
(12, @CGUID+113),
(12, @CGUID+114),
(12, @CGUID+115),
(12, @CGUID+116),
(12, @CGUID+117),
(12, @CGUID+118),
(12, @CGUID+119),
(12, @CGUID+120),
(12, @CGUID+121),
(12, @CGUID+122),
(12, @CGUID+123),
(12, @CGUID+124),
(12, @CGUID+125),
(12, @CGUID+126),
(12, @CGUID+127),
(12, @CGUID+128),
(12, @CGUID+129),
(12, @CGUID+130),
(12, @CGUID+131),
(12, @CGUID+132),
(12, @CGUID+133),
(12, @CGUID+134),
(12, @CGUID+135),
(12, @CGUID+136),
(12, @CGUID+137),
(12, @CGUID+138),
(12, @CGUID+139),
(12, @CGUID+140),
(12, @CGUID+141),
(12, @CGUID+142),
(12, @CGUID+143),
(12, @CGUID+144),
(12, @CGUID+145),
(12, @CGUID+146),
(12, @CGUID+147),
(12, @CGUID+148),
(12, @CGUID+149),
(12, @CGUID+150),
(12, @CGUID+151),
(12, @CGUID+152),
(12, @CGUID+153),
(12, @CGUID+154),
(12, @CGUID+155),
(12, @CGUID+156),
(12, @CGUID+157),
(12, @CGUID+158),
(12, @CGUID+159),
(12, @CGUID+160),
(12, @CGUID+161),
(12, @CGUID+162),
(12, @CGUID+163),
(12, @CGUID+164),
(12, @CGUID+165),
(12, @CGUID+166),
(12, @CGUID+167),
(12, @CGUID+168),
(12, @CGUID+169),
(12, @CGUID+170),
(12, @CGUID+171),
(12, @CGUID+172),
(12, @CGUID+173),
(12, @CGUID+174),
(12, @CGUID+175),
(12, @CGUID+176),
(12, @CGUID+177),
(12, @CGUID+178),
(12, @CGUID+179),
(12, @CGUID+180),
(12, @CGUID+181),
(12, @CGUID+182),
(12, @CGUID+183),
(12, @CGUID+184);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2);

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (96535, 96536, 96538, 96545, 96637);

SET @ACTIONLIST_SALTY_DREG := 96536 * 100;
SET @ACTIONLIST_BRACKISH_CULTIVATOR := 96538 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=96535 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (96536,-(@CGUID+1),-(@CGUID+2),-(@CGUID+3),-(@CGUID+4),-(@CGUID+5),-(@CGUID+7),-(@CGUID+8),-(@CGUID+9),-(@CGUID+10),-(@CGUID+11),-(@CGUID+16),-(@CGUID+17),-(@CGUID+18),-(@CGUID+23),-(@CGUID+24),-(@CGUID+25),-(@CGUID+26),-(@CGUID+27),-(@CGUID+28),-(@CGUID+29),-(@CGUID+30),-(@CGUID+31),-(@CGUID+37),-(@CGUID+38),-(@CGUID+41)) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (96538,-(@CGUID+42),-(@CGUID+43),-(@CGUID+44),-(@CGUID+45),-(@CGUID+47),-(@CGUID+51),-(@CGUID+52),-(@CGUID+53),-(@CGUID+54),-(@CGUID+55),-(@CGUID+57),-(@CGUID+58),-(@CGUID+59),-(@CGUID+62),-(@CGUID+63),-(@CGUID+64),-(@CGUID+65),-(@CGUID+66),-(@CGUID+67),-(@CGUID+71),-(@CGUID+72)) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=96545 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (96637,-(@CGUID+105),-(@CGUID+145)) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ACTIONLIST_SALTY_DREG, @ACTIONLIST_BRACKISH_CULTIVATOR) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(96535,0,0,0,0,0,100,0,12000,13000,17000,17000,0,'',11,150706,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Captain Bonerender - In combat (17 seconds) - Cast "Shadow Arc"'),

(-(@CGUID+7),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+8),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+9),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+10),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+11),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+16),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+17),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+18),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+23),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+24),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+25),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+26),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+27),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+28),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+29),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+30),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+31),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+37),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+38),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+41),0,0,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_SALTY_DREG,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Salty Dreg - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(@ACTIONLIST_SALTY_DREG,9,0,0,0,0,100,0,0,0,0,0,0,'',10,1,5,6,14,25,273,274,1,0,0,0,0,0,0,0,0,'Actionlist - Salty Dreg - Play random emote'),

(96538,0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+43),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+43),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+44),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+44),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+45),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+45),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+47),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+47),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+51),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+51),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+52),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+52),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+53),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+53),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+54),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+54),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+55),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+55),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+57),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+57),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+58),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+58),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+59),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+59),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+62),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+62),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+63),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+63),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+64),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+64),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+65),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+65),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+66),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+66),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+67),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+67),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+71),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+71),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(-(@CGUID+72),0,0,0,0,0,100,0,0,1500,6000,6000,0,'',11,191293,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Brackish Cultivator - In combat (6 seconds) - Cast "Arcane Missiles"'),
(-(@CGUID+72),0,1,0,1,0,100,0,0,10000,3500,8500,0,'',80,@ACTIONLIST_BRACKISH_CULTIVATOR,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Brackish Cultivator - Out of combat (3.5 - 8.5 seconds) - Call timed actionlist'),
(@ACTIONLIST_BRACKISH_CULTIVATOR,9,0,0,0,0,100,0,0,0,0,0,0,'',10,1,5,6,14,25,273,274,1,0,0,0,0,0,0,0,0,'Actionlist - Brackish Cultivator - Play random emote'),

(96545,0,0,0,2,0,100,0,0,75,6000,6000,0,'',11,22695,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Growing Squashling - Between 0-75% Health - Cast "Regrowth"'),

(96637,0,0,0,9,0,100,0,5,20,10000,10000,0,'',11,74759,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Boneship Reveler - Within 5-20 range - Cast "Bottle of Grog"'),
(96637,0,1,0,1,0,100,0,0,9000,6000,15000,0,'',128,2555,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Boneship Reveler - Out of combat (6-15 seconds) - Play oneshot anim kit 2555'),
(-(@CGUID+105),0,0,0,9,0,100,0,5,20,10000,10000,0,'',11,74759,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Boneship Reveler - Within 5-20 range - Cast "Bottle of Grog"'),
(-(@CGUID+105),0,1,0,1,0,100,0,0,9000,6000,15000,0,'',128,8675,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Boneship Reveler - Out of combat (6-15 seconds) - Play oneshot anim kit 8675'),
(-(@CGUID+145),0,0,0,9,0,100,0,5,20,10000,10000,0,'',11,74759,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,'Boneship Reveler - Within 5-20 range - Cast "Bottle of Grog"'),
(-(@CGUID+145),0,1,0,1,0,100,0,0,9000,6000,15000,0,'',128,8675,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Boneship Reveler - Out of combat (6-15 seconds) - Play oneshot anim kit 8675');
