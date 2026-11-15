SET @CGUID := 10006923;
SET @OGUID := 10001969;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 248563, 2261, 10424, 10639, '0', 14349, 0, 0, 0, -46.4789009094238281, -32.8744163513183593, 6.017084121704101562, 3.142759323120117187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978), -- Wrathion (Area: The North Sea - Difficulty: 0) CreateObject1
(@CGUID+1, 248565, 2261, 10424, 10639, '0', 14349, 0, 0, 0, -85.268829345703125, 52.62434768676757812, 28.15319252014160156, 3.019754409790039062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 64978); -- Kalecgos (Area: The North Sea - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 3, 0, 1, 0, 0, 18508, 0, 0, 0, ''), -- Wrathion
(@CGUID+1, 0, 0, 0, 3, 0, 1, 0, 0, 18518, 0, 0, 0, ''); -- Kalecgos

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 400622, 2261, 10424, 10639, '0', 0, 0, 16.43217277526855468, -2.75934839248657226, 5.09879922866821289, 3.792928218841552734, 0, 0, -0.94743728637695312, 0.319941520690917968, 120, 255, 1, 64978), -- Barrel Stack (Area: The North Sea - Difficulty: 0) CreateObject1
(@OGUID+1, 400622, 2261, 10424, 10639, '0', 0, 0, 17.24248695373535156, -2.59982013702392578, 5.080300331115722656, 3.792928218841552734, 0, 0, -0.94743728637695312, 0.319941520690917968, 120, 255, 1, 64978); -- Barrel Stack (Area: The North Sea - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;

-- Delete old spawns
DELETE FROM `creature` WHERE `guid` IN (1050162,1050161);
DELETE FROM `creature_addon` WHERE `guid` IN (1050162,1050161);

-- Phase
UPDATE `phase_name` SET `Name` = 'Cosmetic - See Jaina - Wrathion and Kalecgos on lower deck' WHERE `ID` = 14349;

-- Template
DELETE FROM `creature_template` WHERE `entry` IN (248563 /*Wrathion*/, 248565 /*Kalecgos*/);
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `RequiredExpansion`, `VignetteID`, `unit_class`, `WidgetSetID`, `WidgetSetUnitConditionID`, `family`, `type`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(248563, 0, 0, 'Wrathion', NULL, 'The Black Prince', NULL, NULL, 0, 0, 1, 0, 0, 0, 2, 0, 0, 64978), -- Wrathion
(248565, 0, 0, 'Kalecgos', NULL, 'Blue Dragon Aspect', NULL, NULL, 0, 0, 1, 0, 0, 0, 2, 0, 0, 64978); -- Kalecgos

DELETE FROM `creature_template` WHERE `entry`=245371;
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `RequiredExpansion`, `VignetteID`, `unit_class`, `WidgetSetID`, `WidgetSetUnitConditionID`, `family`, `type`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(245371, 0, 0, 'Captain Garrick', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 0, 7, 0, 0, 64978); -- Captain Garrick

DELETE FROM `gameobject_template` WHERE `entry`=400622;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(400622, 5, 31566, 'Barrel Stack', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64978); -- Barrel Stack

UPDATE `creature_template` SET `faction`=3323, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=248565; -- Kalecgos
UPDATE `creature_template` SET `faction`=3276, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=248563; -- Wrathion
UPDATE `creature_template` SET `name`='Lady Jaina Proudmoore', `VerifiedBuild`=64978 WHERE `entry`=156280; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x10 WHERE `entry`=245371; -- Captain Garrick

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (156280 /*156280 (Lady Jaina Proudmoore)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(156280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 156280 (Lady Jaina Proudmoore)

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=156280 AND `ID`=2) OR (`ID`=1 AND `CreatureID` IN (245371,157051));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(156280, 2, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Lady Jaina Proudmoore
(245371, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0, 64978), -- Captain Garrick
(157051, 1, 108493, 0, 0, 0, 0, 0, 0, 0, 0, 64978); -- Alliance Sparring Partner

UPDATE `creature` SET `equipment_id` = 2 WHERE `guid` IN (1050145,1050589,1050176);

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (248565,248563));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(248565, 0, 0, 100, 1, 328100, 0x4, 0, 0), -- Kalecgos
(248563, 0, 0, 50, 1, 328098, 0x4, 0, 0); -- Wrathion

DELETE FROM `creature_template_difficulty` WHERE (`Entry`=245371 AND `DifficultyID`=0);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(245371, 0, 0, 1, 1, 324767, 0x0, 0, 0); -- Captain Garrick

UPDATE `creature_template_difficulty` SET `ContentTuningID`=741, `StaticFlags1`=0x30000000, `VerifiedBuild`=64978 WHERE (`Entry`=248565 AND `DifficultyID`=0); -- 248565 (Kalecgos) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=741, `StaticFlags1`=0x30000000, `VerifiedBuild`=64978 WHERE (`Entry`=248563 AND `DifficultyID`=0); -- 248563 (Wrathion) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1421, `VerifiedBuild`=64978 WHERE (`Entry`=245371 AND `DifficultyID`=0); -- 245371 (Captain Garrick) - 

-- Model
DELETE FROM `creature_template_model` WHERE (`Idx`=0 AND `CreatureID` IN (248565,248563,245371));
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(248565, 0, 105921, 1, 1, 64978), -- Kalecgos
(248563, 0, 107945, 1, 1, 64978), -- Wrathion
(245371, 0, 92690, 1, 1, 64978); -- Captain Garrick

UPDATE `creature_template_model` SET `VerifiedBuild`=64978 WHERE (`Idx`=1 AND `CreatureID` IN (160656,218646,152795,152794,162253,162251,162252,162250,162249,40725,40165,41200,156403,155125,167886,174971)) OR (`Idx`=0 AND `CreatureID` IN (160656,218646,218647,218977,156676,156986,151719,152568,152360,154148,153928,153898,152290,152359,153658,152552,152542,152545,152548,152795,151870,152682,152681,152397,152465,144644,152323,152567,152448,152553,152555,152414,152291,152756,152556,152464,152712,152361,152794,152416,152415,227442,225420,225421,227411,227335,227336,220720,193655,193650,193654,193653,193679,193678,193677,193675,193674,193652,193684,193680,193682,193686,193647,193644,193645,193648,162248,162245,162241,162253,162251,158706,162254,158531,162243,162247,158632,162244,162246,156709,159087,162290,162252,162250,162249,20222,65851,38695,63502,66151,33301,69067,53270,33030,35362,73780,52672,65011,77178,29929,305,80674,80651,71381,71486,70356,69831,69832,69219,69204,68288,68211,67437,66062,66063,66060,65078,65076,65074,65072,65071,65065,65063,65061,65060,65058,65016,65009,65007,65006,64996,64993,64986,63553,63552,63042,62454,62106,61809,60941,59101,59072,58169,56921,55272,54879,54741,54423,53276,52807,52756,48632,47841,47353,40725,40165,39209,39208,35168,33904,33892,25064,31239,32633,32206,32158,31851,31778,31698,31717,31695,29582,28363,27707,27684,28302,27152,24488,20850,20848,20849,20847,20846,19658,18362,18375,18376,18406,18359,18357,18360,17266,15715,15714,15666,14602,14547,14548,14546,14561,14560,14559,14553,14552,14551,14556,14555,14565,14505,14336,10180,11147,9158,7749,7739,7690,7687,6074,4779,4777,4710,4269,304,307,308,21354,76084,284,157046,157042,157044,160664,157049,41200,156403,155125,167886,157043,160737,174971)) OR (`Idx`=4 AND `CreatureID`=152795) OR (`Idx`=3 AND `CreatureID` IN (152795,167886)) OR (`Idx`=2 AND `CreatureID` IN (152795,167886));
UPDATE `creature_template_model` SET `CreatureDisplayID`=88316, `VerifiedBuild`=64978 WHERE (`CreatureID`=156280 AND `Idx`=0); -- Lady Jaina Proudmoore

UPDATE `creature_model_info` SET `VerifiedBuild`=64978 WHERE `DisplayID` IN (91997, 22661, 94939, 91995, 89868, 107945, 92804, 88316, 64062, 70861, 89870);
UPDATE `creature_model_info` SET `BoundingRadius`=19.52296829223632812, `VerifiedBuild`=64978 WHERE `DisplayID`=105921;
