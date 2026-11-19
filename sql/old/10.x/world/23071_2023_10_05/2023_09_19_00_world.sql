SET @CGUID := 5000092;
SET @OGUID := 5000048;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+39;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
-- Alliance
(@CGUID+0, 85142, 1265, 7025, 7041, '0', 3208, 0, 0, 0, 3974.267333984375, -2640.453125, 55.90972137451171875, 3.047555446624755859, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+1, 85142, 1265, 7025, 7041, '0', 3208, 0, 0, 0, 3973.665771484375, -2638.882080078125, 55.734375, 2.603512763977050781, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+2, 85142, 1265, 7025, 7041, '0', 3208, 0, 0, 0, 3975.05908203125, -2638.657958984375, 55.73090362548828125, 2.319417238235473632, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+3, 85142, 1265, 7025, 7041, '0', 3208, 0, 0, 0, 3972.487060546875, -2639.5244140625, 55.77430343627929687, 2.370105743408203125, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+4, 85142, 1265, 7025, 7041, '0', 3208, 0, 0, 0, 3973.314208984375, -2637.632080078125, 55.609375, 2.503822088241577148, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+5, 82871, 1265, 7025, 7041, '0', 3207, 0, 0, 0, 3830.212646484375, -2522.029541015625, 68.27951812744140625, 5.741931438446044921, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+6, 82871, 1265, 7025, 7041, '0', 3207, 0, 0, 0, 3831.06689453125, -2522.3525390625, 67.84201812744140625, 5.731770515441894531, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+7, 82871, 1265, 7025, 7041, '0', 3207, 0, 0, 0, 3831.48779296875, -2521.276123046875, 67.90451812744140625, 5.66200876235961914, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+8, 82871, 1265, 7025, 7041, '0', 3207, 0, 0, 0, 3831.4931640625, -2523.178955078125, 67.46575927734375, 5.76322031021118164, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+9, 82871, 1265, 7025, 7041, '0', 3207, 0, 0, 0, 3832.510498046875, -2522.04345703125, 67.271453857421875, 5.663929462432861328, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Karabor Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+10, 85146, 1265, 7025, 7041, '0', 3910, 0, 0, 0, 3850.137939453125, -2762.779541015625, 94.17014312744140625, 5.025075435638427734, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+11, 85146, 1265, 7025, 7041, '0', 3910, 0, 0, 0, 3850.669189453125, -2764.776123046875, 94.08160400390625, 1.775573134422302246, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+12, 85146, 1265, 7025, 7041, '0', 3910, 0, 0, 0, 3833.14404296875, -2783.694580078125, 93.92535400390625, 2.246114253997802734, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+13, 85146, 1265, 7025, 7041, '0', 3910, 0, 0, 0, 3832.3212890625, -2782.10595703125, 93.92464447021484375, 5.025075435638427734, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+14, 85146, 1265, 7025, 7041, '0', 3910, 0, 0, 0, 3846.061767578125, -2785.36279296875, 94.01271820068359375, 5.492753028869628906, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+15, 80804, 1265, 7025, 7041, '0', 4010, 0, 0, 0, 3832.7587890625, -2768.546875, 93.89159393310546875, 5.580752372741699218, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+16, 80804, 1265, 7025, 7041, '0', 4010, 0, 0, 0, 3848.165771484375, -2770.2587890625, 94.17138671875, 5.295882701873779296, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+17, 80804, 1265, 7025, 7041, '0', 4010, 0, 0, 0, 3830.84716796875, -2769.451416015625, 94.09824371337890625, 5.6405487060546875, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+18, 80804, 1265, 7025, 7041, '0', 4010, 0, 0, 0, 3847.046875, -2773.826416015625, 93.99353790283203125, 4.831473827362060546, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+19, 80804, 1265, 7025, 7041, '0', 4010, 0, 0, 0, 3846.5859375, -2776.986083984375, 93.92467498779296875, 1.540499091148376464, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Karabor Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
-- Horde
(@CGUID+20, 78529, 1265, 7025, 7041, '0', 3210, 0, 0, 0, 3973.665771484375, -2638.882080078125, 55.734375, 2.603512763977050781, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+21, 78529, 1265, 7025, 7041, '0', 3210, 0, 0, 0, 3973.627685546875, -2638.916748046875, 55.73611068725585937, 2.503822088241577148, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+22, 78529, 1265, 7025, 7041, '0', 3210, 0, 0, 0, 3972.487060546875, -2639.5244140625, 55.77430343627929687, 2.370105743408203125, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+23, 78529, 1265, 7025, 7041, '0', 3210, 0, 0, 0, 3974.267333984375, -2640.453125, 55.90972137451171875, 3.047555446624755859, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+24, 78529, 1265, 7025, 7041, '0', 3210, 0, 0, 0, 3975.05908203125, -2638.657958984375, 55.73090362548828125, 2.319417238235473632, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+25, 85141, 1265, 7025, 7041, '0', 3209, 0, 0, 0, 3831.48779296875, -2521.276123046875, 67.90451812744140625, 5.66200876235961914, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+26, 85141, 1265, 7025, 7041, '0', 3209, 0, 0, 0, 3831.06689453125, -2522.3525390625, 67.84201812744140625, 5.731770515441894531, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+27, 85141, 1265, 7025, 7041, '0', 3209, 0, 0, 0, 3832.510498046875, -2522.04345703125, 67.271453857421875, 5.663929462432861328, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+28, 85141, 1265, 7025, 7041, '0', 3209, 0, 0, 0, 3830.212646484375, -2522.029541015625, 68.27951812744140625, 5.741931438446044921, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+29, 85141, 1265, 7025, 7041, '0', 3209, 0, 0, 0, 3831.4931640625, -2523.178955078125, 67.46575927734375, 5.76322031021118164, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Frostwolf Slave (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+30, 80803, 1265, 7025, 7041, '0', 3911, 0, 0, 0, 3850.669189453125, -2764.776123046875, 94.08160400390625, 1.775573134422302246, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+31, 80803, 1265, 7025, 7041, '0', 3911, 0, 0, 0, 3846.061767578125, -2785.36279296875, 94.01271820068359375, 5.492753028869628906, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+32, 80803, 1265, 7025, 7041, '0', 3911, 0, 0, 0, 3833.14404296875, -2783.694580078125, 93.92535400390625, 2.246114253997802734, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+33, 80803, 1265, 7025, 7041, '0', 3911, 0, 0, 0, 3850.137939453125, -2762.779541015625, 94.17014312744140625, 5.025075435638427734, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+34, 80803, 1265, 7025, 7041, '0', 3911, 0, 0, 0, 3832.3212890625, -2782.10595703125, 93.92464447021484375, 5.025075435638427734, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+35, 85145, 1265, 7025, 7041, '0', 4011, 0, 0, 0, 3846.5859375, -2776.986083984375, 93.92467498779296875, 1.540499091148376464, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+36, 85145, 1265, 7025, 7041, '0', 4011, 0, 0, 0, 3848.165771484375, -2770.2587890625, 94.17138671875, 5.295882701873779296, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+37, 85145, 1265, 7025, 7041, '0', 4011, 0, 0, 0, 3830.84716796875, -2769.451416015625, 94.09824371337890625, 5.6405487060546875, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+38, 85145, 1265, 7025, 7041, '0', 4011, 0, 0, 0, 3847.046875, -2773.826416015625, 93.99353790283203125, 4.831473827362060546, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791), -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+39, 85145, 1265, 7025, 7041, '0', 4011, 0, 0, 0, 3832.7587890625, -2768.546875, 93.89159393310546875, 5.580752372741699218, 120, 0, 0, 4000, 0, 0, NULL, NULL, 50791); -- Liberated Frostwolf Prisoner (Area: Heartblood - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+39;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Liberated Karabor Prisoner
(@CGUID+19, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Liberated Karabor Prisoner
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Liberated Frostwolf Prisoner
(@CGUID+35, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Liberated Frostwolf Prisoner

-- Gameobject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Alliance
(@OGUID+0, 229352, 1265, 7025, 7041, '0', 3793, 0, 3831.09716796875, -2522.029541015625, 67.823760986328125, 5.693089962005615234, 0.033244609832763671, 0.112518310546875, -0.28867435455322265, 0.950211286544799804, 120, 255, 1, 50791), -- Bleeding Hollow Cage (Area: Heartblood - Difficulty: 0) CreateObject1
(@OGUID+1, 229353, 1265, 7025, 7041, '0', 3793, 0, 3973.627685546875, -2638.916748046875, 55.65277862548828125, 2.613238334655761718, -0.02734136581420898, -0.03424930572509765, 0.964563369750976562, 0.260186344385147094, 120, 255, 1, 50791), -- Bleeding Hollow Cage (Area: Heartblood - Difficulty: 0) CreateObject1
-- Horde
(@OGUID+2, 229350, 1265, 7025, 7041, '0', 3794, 0, 3973.627685546875, -2638.916748046875, 55.65277862548828125, 2.613238334655761718, -0.02734136581420898, -0.03424930572509765, 0.964563369750976562, 0.260186344385147094, 120, 255, 1, 50791), -- Bleeding Hollow Cage (Area: Heartblood - Difficulty: 0) CreateObject1
(@OGUID+3, 229325, 1265, 7025, 7041, '0', 3794, 0, 3831.09716796875, -2522.029541015625, 67.823760986328125, 5.6930999755859375, 0.033244132995605468, 0.112517356872558593, -0.28866958618164062, 0.95021289587020874, 120, 255, 1, 50791); -- Bleeding Hollow Cage (Area: Heartblood - Difficulty: 0) CreateObject1

UPDATE `gameobject_template_addon` SET `flags`=262176 WHERE `entry` IN (229353, 229352, 229325, 229350); -- Bleeding Hollow Cage
UPDATE `gameobject_template` SET `ContentTuningId`=178, `VerifiedBuild`=50791 WHERE `entry` IN (229325, 229350, 229352, 229353); -- Bleeding Hollow Cage

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (3910, 4010, 3911, 4011, 3793, 3794);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3910, 'Cosmetic - Liberated Slaves 02'),
(4010, 'Cosmetic - Liberated Slaves 01'),
(3911, 'Cosmetic - Liberated Slaves 04'),
(4011, 'Cosmetic - Liberated Slaves 03'),
(3793, 'Cosmetic - Bleeding Hollow Cage (A)'),
(3794, 'Cosmetic - Bleeding Hollow Cage (H)');

DELETE FROM `phase_area` WHERE `AreaId` IN (7039, 7041) AND `PhaseId` IN (3207, 3208, 3209, 3210, 3910, 4010, 3911, 4011, 3793, 3794);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7041, 3207, 'See Bleeding Hollow Slaves 01'),
(7041, 3208, 'See Bleeding Hollow Slaves 02'),
(7041, 3209, 'See Bleeding Hollow Slaves 03'),
(7041, 3210, 'See Bleeding Hollow Slaves 04'),
(7041, 3910, 'See liberated slaves 02'),
(7041, 4010, 'See liberated slaves 01'),
(7041, 3911, 'See liberated slaves 04'),
(7041, 4011, 'See liberated slaves 03'),
(7041, 3793, 'See Bleeding Hollow Cage (A)'),
(7041, 3794, 'See Bleeding Hollow Cage (H)'),
(7039, 3207, 'See Bleeding Hollow Slaves 01'),
(7039, 3208, 'See Bleeding Hollow Slaves 02'),
(7039, 3209, 'See Bleeding Hollow Slaves 03'),
(7039, 3210, 'See Bleeding Hollow Slaves 04'),
(7039, 3910, 'See liberated slaves 02'),
(7039, 4010, 'See liberated slaves 01'),
(7039, 3911, 'See liberated slaves 04'),
(7039, 4011, 'See liberated slaves 03'),
(7039, 3793, 'See Bleeding Hollow Cage (A)'),
(7039, 3794, 'See Bleeding Hollow Cage (H)');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3207 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3207, 0, 0, 0, 47, 0, 35240, 8, 0, 0, 'Apply Phase 3207 if Quest 35240 is in progress'),
(26, 3207, 0, 0, 0, 48, 0, 273639, 0, 1, 1, 'Apply phase 3207 if quest objective 273639 is not done');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3208 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3208, 0, 0, 0, 47, 0, 35240, 8, 0, 0, 'Apply Phase 3208 if Quest 35240 is in progress'),
(26, 3208, 0, 0, 0, 48, 0, 273640, 0, 1, 1, 'Apply phase 3208 if quest objective 273640 is not done');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3209 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3209, 0, 0, 0, 47, 0, 34421, 8, 0, 0, 'Apply Phase 3209 if Quest 34421 is in progress'),
(26, 3209, 0, 0, 0, 48, 0, 272710, 0, 1, 1, 'Apply phase 3209 if quest objective 272710 is not done');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3210 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3210, 0, 0, 0, 47, 0, 34421, 8, 0, 0, 'Apply Phase 3210 if Quest 34421 is in progress'),
(26, 3210, 0, 0, 0, 48, 0, 272692, 0, 1, 1, 'Apply phase 3210 if quest objective 272692 is not done');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3910 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3910, 0, 0, 0, 47, 0, 35240, 2 | 8 | 64, 0, 0, 'Apply Phase 3910 if Quest 35240 is complete | in progress | rewarded'),
(26, 3910, 0, 0, 0, 48, 0, 273640, 0, 1, 0, 'Apply phase 3910 if quest objective 273640 is not done'),
(26, 3910, 0, 0, 0, 1, 0, 159126, 0, 0, 1, 'Apply Phase 3910 if has no aura 159126');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4010 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4010, 0, 0, 0, 47, 0, 35240, 2 | 8 | 64, 0, 0, 'Apply Phase 4010 if Quest 35240 is complete | in progress | rewarded'),
(26, 4010, 0, 0, 0, 48, 0, 273639, 0, 1, 0, 'Apply phase 4010 if quest objective 273640 is not done'),
(26, 4010, 0, 0, 0, 1, 0, 159127, 0, 0, 1, 'Apply Phase 4010 if has no aura 159127');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3911 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3911, 0, 0, 0, 47, 0, 34421, 2 | 8 | 64, 0, 0, 'Apply Phase 3911 if Quest 34421 is complete | in progress | rewarded'),
(26, 3911, 0, 0, 0, 48, 0, 272692, 0, 1, 0, 'Apply phase 3911 if quest objective 272692 is not done'),
(26, 3911, 0, 0, 0, 1, 0, 159126, 0, 0, 1, 'Apply Phase 3911 if has no aura 159126');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4011 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4011, 0, 0, 0, 47, 0, 34421, 2 | 8 | 64, 0, 0, 'Apply Phase 4011 if Quest 34421 is complete | in progress | rewarded'),
(26, 4011, 0, 0, 0, 48, 0, 272710, 0, 1, 0, 'Apply phase 4011 if quest objective 272710 is not done'),
(26, 4011, 0, 0, 0, 1, 0, 159127, 0, 0, 1, 'Apply Phase 4011 if has no aura 159127');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3793 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3793, 0, 0, 0, 6, 0, 67, 0, 0, 0, 'Apply phase 3793 if Team Horde');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3794 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3794, 0, 0, 0, 6, 0, 469, 0, 0, 0, 'Apply phase 3794 if Team Alliance');

-- Scene
UPDATE `scene_template` SET `ScriptName` = 'SmartScene' WHERE `SceneId` IN (624, 625);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (624, 625) AND `source_type`=10 AND `id` IN (0, 1, 2) AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(624, 10, 0, 0, 78, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 82238, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On Scene Start - Self: Cast spell 82238 with flags triggered on self'),
(624, 10, 1, 0, 80, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 82238, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On Scene Cancel - Self: Cast spell 82238 with flags triggered on self'),
(624, 10, 2, 0, 81, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 82238, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On Scene Complete - Self: Cast spell 82238 with flags triggered on self'),
(625, 10, 0, 0, 78, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 82238, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On Scene Start - Self: Cast spell 82238 with flags triggered on self'),
(625, 10, 1, 0, 80, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 82238, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On Scene Cancel - Self: Cast spell 82238 with flags triggered on self'),
(625, 10, 2, 0, 81, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 82238, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'On Scene Complete - Self: Cast spell 82238 with flags triggered on self');

-- Serverside spells
DELETE FROM `serverside_spell` WHERE `Id` IN (158636, 158691) AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(158636, 0, 0, 0, 0, (0x00000180), 0, (0x10000000), 0, (0x00000080), 0, (0x00000004), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, -1, 0, 0, 0, '(Serverside/Non-DB2) Bleeding Hollow Cage Credit - Southern Cage', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(158691, 0, 0, 0, 0, (0x00000180), 0, (0x10000000), 0, (0x00000080), 0, (0x00000004), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, -1, 0, 0, 0, '(Serverside/Non-DB2) Bleeding Hollow Cage Credit - Eastern Cage', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (158636, 158691) AND `EffectIndex` IN (0, 1) AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(158691, 0, 0, 90, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85142, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(158691, 1, 0, 90, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 78529, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(158636, 0, 0, 90, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 82871, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(158636, 1, 0, 90, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85141, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Quest objectives
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID`IN (272710, 272692, 273639, 273640);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(272710, NULL, 159127, NULL, 0, 0),
(273639, NULL, 159127, NULL, 0, 0),
(272692, NULL, 159126, NULL, 0, 0),
(273640, NULL, 159126, NULL, 0, 0);
