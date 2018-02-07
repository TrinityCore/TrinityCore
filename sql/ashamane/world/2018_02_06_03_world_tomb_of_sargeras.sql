SET @CGUID := 21003949;
SET @OGUID := 21001442;

DELETE FROM `areatrigger_template` WHERE `Id` IN (15273, 15386, 15381, 13595, 14697, 14696);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(15273, 0, 16, 2, 2, 0, 0, 0, 0, 25961),
(15386, 0, 4, 2.5, 2.5, 0, 0, 0, 0, 25961),
(15381, 0, 0, 2.5, 2.5, 0, 0, 0, 0, 25961),
(13595, 0, 2, 7, 7, 0, 0, 0, 0, 25961),
(14697, 0, 2, 7, 7, 0, 0, 0, 0, 25961),
(14696, 4, 0, 23, 23, 100, 100, 0, 0, 25961);

UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=3282;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=10466;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=11692;
UPDATE `areatrigger_template` SET `Type`=4, `Flags`=0, `Data2`=7, `Data3`=7, `Data4`=2, `Data5`=2, `VerifiedBuild`=25961 WHERE `Id`=9482;

DELETE FROM `spell_areatrigger` WHERE (`AreaTriggerId`=5300) OR (`AreaTriggerId`=5302) OR (`SpellMiscId`=10415 AND `AreaTriggerId`=15273) OR (`SpellMiscId`=10533 AND `AreaTriggerId`=15386) OR (`SpellMiscId`=7240 AND `AreaTriggerId`=11692) OR (`SpellMiscId`=10528 AND `AreaTriggerId`=15381) OR (`SpellMiscId`=9615 AND `AreaTriggerId`=13595) OR (`SpellMiscId`=9775 AND `AreaTriggerId`=14697) OR (`AreaTriggerId`=14696);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(1315, 5300, 392, 0, 0, 0, 0, 1550, 1000, 25961), -- SpellId : 123986
(1316, 5302, 393, 0, 0, 0, 0, 1550, 1000, 25961), -- SpellId : 123986
(10415, 15273, 2994, 0, 0, 0, 0, 3406, 20000, 25961), -- SpellId : 246560
(10533, 15386, 2993, 0, 0, 0, 0, 0, 2999, 25961), -- SpellId : 242606
(7240, 11692, 0, 0, 0, 0, 0, 0, 30000, 25961), -- SpellId : 214420
(10528, 15381, 0, 0, 0, 0, 0, 0, 11000, 25961), -- SpellId : 242613
(9615, 13595, 0, 2648, 2645, 0, 0, 0, 6000, 25961), -- SpellId : 234917
(9775, 14697, 0, 2704, 2705, 0, 0, 0, 6000, 25961); -- SpellId : 236433
-- (UNKNOWN, 14696, 0, 0, 0, 0, 0, 0, 0, 25961); -- SpellId : 0

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=7267 AND `AreaTriggerId`=11721); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4928 AND `AreaTriggerId`=9645); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=8284 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12002 AND `AreaTriggerId`=16713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2252, `TimeToTargetScale`=2250, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2250, `TimeToTargetScale`=2250, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=1524 AND `AreaTriggerId`=5972); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2507, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9449 AND `AreaTriggerId`=13436); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=21751, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7044 AND `AreaTriggerId`=11513); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2809, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=2329 AND `AreaTriggerId`=6870); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=21694, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8990, `TimeToTargetScale`=2250, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8643, `TimeToTargetScale`=2250, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7376, `TimeToTargetScale`=2250, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7373, `TimeToTargetScale`=2250, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7375, `TimeToTargetScale`=2250, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8010, `TimeToTargetScale`=2250, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8989, `TimeToTargetScale`=2250, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=22121, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6006 AND `AreaTriggerId`=10698); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3106, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10837 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7068 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=11035 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1464, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4756 AND `AreaTriggerId`=9482); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1142, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4073, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4562, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2950, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2801, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3729, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6658 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=804, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=627, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=982, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=938, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3191, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1429, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1430, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1431, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=150, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10224 AND `AreaTriggerId`=15099); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=150, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10227 AND `AreaTriggerId`=15099); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=150, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10235 AND `AreaTriggerId`=15099); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=150, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10225 AND `AreaTriggerId`=15099); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=45359, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=4955 AND `Idx`=1) OR (`ConversationId`=4955 AND `Idx`=3) OR (`ConversationId`=4955 AND `Idx`=2) OR (`ConversationId`=4955 AND `Idx`=0) OR (`ConversationId`=4899 AND `Idx`=256) OR (`ConversationId`=4929 AND `Idx`=1) OR (`ConversationId`=4929 AND `Idx`=0);
-- INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
-- (4955, UNKNOWN, 1, 25961), -- Full: 0x0
-- (4955, UNKNOWN, 3, 25961), -- Full: 0x0
-- (4955, UNKNOWN, 2, 25961), -- Full: 0x0
-- (4955, UNKNOWN, 0, 25961), -- Full: 0x0
-- (4899, UNKNOWN, 256, 25961), -- Full: 0x2416E4D1807608C0005472000079AF77 Vehicle/0 R1465/S21618 Map: Tombe de Sargeras Entry: 120867 (Kil'jaeden) Low: 7974775
-- (4929, UNKNOWN, 1, 25961), -- Full: 0x2416E4D1807608C0005472000079B2CE Vehicle/0 R1465/S21618 Map: Tombe de Sargeras Entry: 120867 (Kil'jaeden) Low: 7975630
-- (4929, UNKNOWN, 0, 25961); -- Full: 0x2016E4D180765480005472000079B2D6 Creature/0 R1465/S21618 Map: Tombe de Sargeras Entry: Prophète Velen Low: 7975638


DELETE FROM `conversation_line_template` WHERE `Id` IN (11015, 11014, 11013, 11012, 11011, 11010, 11009, 11008, 11006, 11005, 11004, 10896, 10895, 10894, 10951, 10950);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(11015, 100134, 281886736, 1, 0, 25961),
(11014, 89748, 281886736, 3, 0, 25961),
(11013, 75600, 281886736, 1, 0, 25961),
(11012, 59846, 281886736, 1, 0, 25961),
(11011, 56911, 281886736, 3, 0, 25961),
(11010, 48589, 281886736, 2, 0, 25961),
(11009, 42088, 281886736, 3, 0, 25961),
(11008, 26864, 281886736, 0, 0, 25961),
(11006, 17594, 281886736, 2, 0, 25961),
(11005, 11694, 281886736, 1, 0, 25961),
(11004, 0, 281886736, 0, 0, 25961),
(10896, 30586, 4185844288, 256, 0, 25961),
(10895, 15535, 4185844288, 256, 0, 25961),
(10894, 0, 4185844288, 256, 0, 25961),
(10951, 8899, 1065353216, 1, 0, 25961),
(10950, 0, 1065353216, 0, 0, 25961);


DELETE FROM `conversation_template` WHERE `Id` IN (4955, 4929, 4899);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(4955, 11004, 108876, 25961),
(4929, 10950, 24267, 25961),
(4899, 10894, 41892, 25961);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (270027 /*7.2 Tomb Raid - Avatar Floor (test) - MRN*/, 269783 /*269783*/, 269792 /*269792*/, 269793 /*269793*/, 269789 /*269789*/, 269791 /*269791*/, 269794 /*269794*/, 269795 /*269795*/, 269788 /*269788*/, 269790 /*269790*/, 269784 /*269784*/, 269787 /*269787*/, 269785 /*269785*/, 269786 /*269786*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(270027, 0, 1048624), -- 7.2 Tomb Raid - Avatar Floor (test) - MRN
(269783, 0, 48), -- 269783
(269792, 0, 48), -- 269792
(269793, 0, 48), -- 269793
(269789, 0, 48), -- 269789
(269791, 0, 48), -- 269791
(269794, 0, 48), -- 269794
(269795, 0, 48), -- 269795
(269788, 0, 48), -- 269788
(269790, 0, 48), -- 269790
(269784, 0, 48), -- 269784
(269787, 0, 48), -- 269787
(269785, 0, 48), -- 269785
(269786, 0, 48); -- 269786


DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+642;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6283.226, -795.8445, 2893.366, 5.878805, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+1, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6285.088, -799.3212, 2893.36, 5.453745, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+2, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6283.04, -796.6533, 2893.36, 6.185876, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+3, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6283.007, -796.4288, 2893.36, 0.1134971, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+4, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6285.514, -798.7426, 2893.308, 6.154784, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+5, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6284.12, -798.6616, 2893.36, 5.131164, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+6, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6312.78, -778.8368, 2887.924, 5.631178, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+7, 121719, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6249.782, -795.6927, 2894.346, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+8, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6308.704, -795.6389, 2887.924, 0.003461044, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+9, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6319.055, -822.0035, 2887.924, 0.7594366, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+10, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6276.54, -796.0261, 2894.346, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+11, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6311.487, -808.9063, 2887.924, 0.4415335, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+12, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6353.929, -756.7674, 2887.924, 2.201104, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+13, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6350.107, -836.2047, 2887.96, 0.1384519, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+14, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6321.717, -766.4739, 2887.924, 5.468315, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+15, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6349.163, -836.0009, 2887.96, 0.3183635, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+16, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6334.478, -759.1268, 2887.924, 4.978112, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+17, 118894, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6348.198, -795.9496, 2888.741, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Center Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+18, 92879, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6221.518, -795.743, 2974.679, 3.079738, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- SLG Generic Stalker (Gigantic AOI) (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+19, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6340.248, -754.7552, 2887.924, 0.6666324, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+20, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6347.351, -759.007, 2887.924, 1.43951, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+21, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6332.15, -830.993, 2887.924, 1.130671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+22, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6345.908, -839.263, 2887.96, 4.289771, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+23, 120153, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6343.96, -836.2635, 2887.96, 2.354696, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eonic Defender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+24, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6337.897, -748.9722, 2887.924, 0.1535131, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+25, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6348.748, -836.0347, 2887.96, 0.4359936, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+26, 120153, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6347.692, -747.8246, 2887.924, 4.801034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eonic Defender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+27, 45396, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.654, -804.2136, 2978.831, 2.747211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 243149 -)
(@CGUID+28, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6347.878, -756.6893, 2887.924, 4.746, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+29, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6377, -769.0781, 2887.924, 3.899693, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+30, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6383.799, -810.9896, 2887.924, 2.730868, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+31, 118289, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6386.587, -795.8524, 2887.924, 3.069571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Maiden of Vigilance (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+32, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6387.068, -795.743, 2887.924, 3.151088, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+33, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6361.651, -832.125, 2887.924, 1.896501, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+34, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.276, -823.6962, 2887.924, 2.399195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+35, 120158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6356.901, -749.4583, 2887.924, 2.904703, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Volatile Corruption (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+36, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6347.893, -834.4097, 2887.924, 1.789966, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+37, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6384.579, -781.6684, 2887.924, 3.509645, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+38, 121630, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.654, -804.2136, 2981.715, 2.747211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegis of Aggramar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 154441 - Shadowy Ghost Cosmetic Spawn Spell)
(@CGUID+39, 118773, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6363.598, -759.7952, 2887.924, 4.315502, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Jump Target Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+40, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6098.388, -767.7761, 2971.804, 1.077174, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+41, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6137.22, -789.6702, 2971.804, 2.884756, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+42, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6113.585, -758.1024, 2971.627, 3.033364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+43, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6132.11, -833.8403, 2971.622, 4.409331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+44, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.604, -777.7604, 2971.454, 3.033364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+45, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6125.111, -835.6042, 2971.626, 3.502233, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+46, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.452, -816.3941, 2971.452, 3.730094, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+47, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6141.419, -809.5018, 2971.627, 3.033364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+48, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6101.764, -761.4219, 2971.804, 5.664975, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+49, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.361, -821.4358, 2971.45, 5.084475, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+50, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6112.878, -824.1702, 2971.907, 4.409331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+51, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.563, -868.1059, 2923.226, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240704 - Piège d'Aegwynn)
(@CGUID+52, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6131.063, -787.533, 2971.804, 5.616508, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+53, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6113.519, -764.0191, 2971.627, 4.409331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+54, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6128.159, -764.9114, 2971.627, 3.727708, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+55, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6087.649, -758.2188, 2971.627, 1.568148, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+56, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6079.385, -818.9132, 2972.021, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+57, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6037.701, -792.0191, 2971.804, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+58, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6060.813, -812.9688, 2971.627, 5.866366, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+59, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6069.898, -823.0643, 2971.627, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+60, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6231.766, -1003.892, 2923.65, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240825 - Piège d'Aegwynn)
(@CGUID+61, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6150.554, -1005.571, 2899.287, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+62, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6051.967, -808.8403, 2971.45, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+63, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6060.458, -798.6788, 2971.804, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+64, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6089.397, -768.8021, 2971.804, 0.597248, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+65, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6066.076, -790.1077, 2971.804, 0.9533232, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+66, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6063.499, -802.3073, 2971.804, 2.092449, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+67, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6058.344, -829.9254, 2971.448, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+68, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6043.811, -822.1858, 2971.456, 0.491619, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+69, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6055.779, -800.1649, 2971.804, 6.131253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+70, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5984.767, -793.4167, 2978.209, 6.224468, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+71, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6003.479, -789.5625, 2974.586, 1.792414, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+72, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6004.943, -803.0538, 2974.587, 0.6956571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+73, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6360.545, -1035.429, 2910.26, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+74, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5960.486, -803.2292, 2977.906, 5.506678, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+75, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6002.359, -800.7639, 2974.586, 5.690412, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+76, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5953.122, -790.507, 2978.21, 3.502233, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+77, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6000.962, -794.3854, 2974.586, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+78, 121718, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6363.712, -1037.087, 2908.148, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+79, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6100.988, -990.5469, 2959.747, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240700 - Piège d'Aegwynn)
(@CGUID+80, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6029.747, -800.2448, 2971.802, 4.192907, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+81, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5972.427, -797.7205, 2977.917, 0.964916, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+82, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6000.279, -787.1024, 2974.871, 3.966526, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+83, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6030.049, -769.2691, 2971.456, 0.2585418, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+84, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5965.971, -788.0243, 2977.914, 0.9858042, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+85, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6088.5, -1027.075, 2896.395, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240705 - Piège d'Aegwynn)
(@CGUID+86, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5951.07, -798.2222, 2978.209, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+87, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+88, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5883.807, -796.9496, 2954.368, 0.6418293, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+89, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+90, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+91, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5939.229, -794.5382, 2978.883, 3.308372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+92, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5925.53, -797.1736, 2972.766, 3.308372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+93, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+94, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+95, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5920.638, -797.8663, 2969.74, 0.4126073, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+96, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+97, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5892.022, -794.7518, 2954.404, 5.802555, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+98, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5876.856, -803.7639, 2954.368, 0.2438955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+99, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5882.648, -792.6979, 2954.368, 4.038858, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+100, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5888.283, -797.2257, 2954.382, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+101, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+102, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5921.882, -793.6736, 2970.474, 0.964916, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+103, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+104, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+105, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5893.361, -798.5382, 2954.41, 1.77362, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+106, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5906.289, -793.7708, 2961.23, 1.84227, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+107, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+108, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+109, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+110, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+111, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+112, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+113, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+114, 120867, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6564.467, -811.8802, 1663.666, 2.822959, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Kil'jaeden (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 245332 - Phase du Néant)
(@CGUID+115, 116939, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6606.668, -795.1215, 1665.607, 3.139052, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fallen Avatar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239847 - Intro)
(@CGUID+116, 125542, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6347.99, -795.1302, 1842.664, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- El-ahrairah (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 249161 -)
(@CGUID+117, 120449, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6425.785, -801.6512, 1647.76, 3.202665, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Defensive Countermeasure (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240130 - Apparition cosmétique) (possible waypoints or random movement)
(@CGUID+118, 120449, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6440.584, -790.0742, 1647.76, 3.725439, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Defensive Countermeasure (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240130 - Apparition cosmétique) (possible waypoints or random movement)
(@CGUID+119, 117279, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6547.43, -760.6458, 1662.983, 5.759586, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Containment Pylon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 233556 - Matrice corrompue)
(@CGUID+120, 121720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6420.158, -796.1077, 1647.844, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+121, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6380.09, -795.8524, 1649.49, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+122, 117279, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6572.728, -854.6563, 1662.983, 1.047198, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Containment Pylon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 233556 - Matrice corrompue)
(@CGUID+123, 117279, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6538.186, -795.1736, 1662.983, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Containment Pylon (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+124, 117279, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6572.559, -735.3646, 1662.983, 5.235988, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Containment Pylon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 233556 - Matrice corrompue)
(@CGUID+125, 117279, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6547.384, -829.5295, 1662.983, 0.5235988, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Containment Pylon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 233556 - Matrice corrompue)
(@CGUID+126, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6560.606, -757.4184, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+127, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6538.01, -831.6059, 1511.393, 0.0006764429, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+128, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6578.068, -754.5452, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+129, 119846, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6600.672, -806.7847, 1662.754, 4.18653, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Pylon Beam Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+130, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6548.375, -850.0191, 1510.218, 0.7890547, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+131, 119846, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6595.392, -801.7465, 1662.754, 3.662716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Pylon Beam Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+132, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6577.08, -736.9792, 1510.218, 4.767564, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+133, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6563.812, -814.0851, 1509.897, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+134, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6581.686, -814.1962, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+135, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6579.877, -774.4288, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+136, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6538.01, -774.618, 1511.41, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+137, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6597.762, -753.9375, 1510.04, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+138, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6538.01, -795.3802, 1511.401, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+139, 119846, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6600.382, -783.0712, 1662.752, 2.093218, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Pylon Beam Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+140, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6538.01, -754.9583, 1511.393, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+141, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6560.09, -775.0816, 1509.945, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+142, 119846, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6593.492, -795.3698, 1662.754, 3.134099, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Pylon Beam Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+143, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6538.01, -814.434, 1511.393, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+144, 119846, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6595.412, -788.4479, 1662.754, 2.614965, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Pylon Beam Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+145, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6561.227, -794.4861, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+146, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6540.411, -736.9792, 1510.727, 5.485149, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+147, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6582.953, -832.9757, 1509.906, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+148, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6557.966, -736.9792, 1510.218, 4.799655, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+149, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6581.596, -794.4792, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+150, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6567.325, -828.7761, 1509.933, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+151, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6600.417, -836.1424, 1509.928, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+152, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6614.619, -836.0868, 1509.943, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+153, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6596.424, -737.0608, 1510.646, 4.749039, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+154, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6620.757, -794.9358, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+155, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6635.915, -761.1545, 1509.99, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+156, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6619.108, -814.9323, 1510.024, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+157, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6617.95, -756.6805, 1509.976, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+158, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6638.893, -814.4323, 1509.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+159, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6600.467, -774.1927, 1509.947, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+160, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6600.422, -794.1805, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+161, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6620.226, -775.0486, 1509.988, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+162, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6631.49, -830.5347, 1509.948, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+163, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6620.341, -737.8229, 1510.646, 4.652302, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+164, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6600.843, -814.4896, 1510.036, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+165, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6642.624, -777.8542, 1509.976, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+166, 120705, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6642.01, -741.0139, 1511.533, 4.660134, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Achievement Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+167, 117679, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6642.132, -795.3143, 1509.97, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Grid Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+168, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6324.53, -774.0564, 2888.073, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+169, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6386.258, -795.7234, 2887.924, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+170, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6389.076, -801.1385, 2888.043, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+171, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6377.601, -770.1937, 2887.924, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+172, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+173, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+174, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+175, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+176, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+177, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+178, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+179, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+180, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+181, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+182, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+183, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+184, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+185, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+186, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+187, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+188, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+189, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+190, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+191, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+192, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+193, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+194, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+195, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+196, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+197, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+198, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+199, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+200, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+201, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+202, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+203, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+204, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+205, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+206, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+207, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+208, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+209, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+210, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+211, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+212, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+213, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+214, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+215, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+216, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+217, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+218, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+219, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+220, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+221, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+222, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+223, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+224, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+225, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+226, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+227, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+228, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+229, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+230, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+231, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+232, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6314.885, -795.5333, 2887.924, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+233, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+234, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+235, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+236, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+237, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+238, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+239, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+240, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+241, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+242, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+243, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+244, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+245, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+246, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+247, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+248, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+249, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+251, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+252, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+253, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+254, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+255, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+256, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+257, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+258, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+259, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+260, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+261, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+262, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+263, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+264, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+265, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+266, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+267, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+268, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+269, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+270, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+271, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+272, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+273, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+274, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+275, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+276, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+277, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+278, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+279, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+280, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+281, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+282, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+283, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+284, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+285, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+286, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+287, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+288, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+289, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+290, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+291, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+292, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+293, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+294, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+295, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+296, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+297, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+298, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+299, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.052, -792.7537, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+300, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.083, -798.7058, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+301, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.052, -792.7059, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+302, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.552, -792.8042, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+303, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.584, -798.8041, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+304, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6385.084, -798.7536, 2888.007, 3.146908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+305, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.095, -765.3174, 2888.044, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+306, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6382.752, -790.7455, 2887.924, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+307, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+308, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+309, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+310, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+311, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+312, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+313, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+314, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+315, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+316, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+317, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+318, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+319, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+320, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+321, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+322, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+323, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+324, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+325, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+326, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+327, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+328, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+329, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+330, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+331, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+332, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+333, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+334, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+335, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+336, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+337, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+338, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+339, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+340, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+341, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+342, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+343, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+344, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+345, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+346, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+347, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+348, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+349, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6311.69, -793.0215, 2887.924, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+350, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+351, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+352, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+353, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+354, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+355, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+356, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+357, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+358, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+359, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+360, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+361, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+362, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.728, -792.5839, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+363, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.681, -798.6545, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+364, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.18, -798.7293, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+365, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.681, -798.5837, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+366, 118640, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6320.228, -792.7295, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Creation (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+367, 118643, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.728, -792.6547, 2888.007, 6.275318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fragment of Obliteration (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 250500 - Fragments d'essence)
(@CGUID+368, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6310.309, -788.7406, 2887.924, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+369, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6314.065, -778.2394, 2888.044, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+370, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6312.338, -787.2746, 2887.924, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+371, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6307.913, -794.2369, 2887.924, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+372, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+373, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+374, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+375, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+376, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+377, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+378, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+379, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6276.452, -782.5972, 2894.262, 1.548665, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+380, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+381, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+382, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.207, -798.61, 2905.241, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+383, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+384, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+385, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6220.464, -791.747, 2910.996, 3.990119, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+386, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6230.296, -793.7001, 2904.723, 1.352576, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+387, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6222.097, -783.3685, 2915.653, 0.1283336, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+388, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+389, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+390, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6223.834, -788.1616, 2911.369, 3.538743, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+391, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+392, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+393, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+394, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+395, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6217.141, -784.0081, 2915.836, 0.1283294, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+396, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+397, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6240.38, -775.9503, 2939.929, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+398, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.507, -790.4643, 2964.228, 1.610753, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+399, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.414, -773.5775, 2928.06, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+400, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.906, -800.5346, 2963.863, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+401, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6241.946, -791.4736, 2953.289, 2.34881, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+402, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6226.531, -763.9268, 2928.941, 1.86101, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+403, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6245.459, -795.0383, 2953.912, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+404, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6215.172, -784.2621, 2916.332, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+405, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6235.296, -796.2595, 2958.719, 4.890471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+406, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+407, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+408, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.707, -795.4747, 2963.626, 1.610649, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+409, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.987, -799.6008, 2905.444, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+410, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.313, -764.9753, 2934.581, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+411, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6226.631, -786.9885, 2911.365, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+412, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.48, -787.9553, 2954.159, 2.348755, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+413, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6244.474, -773.1143, 2939.99, 0.9309577, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+414, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6247.436, -769.109, 2940.028, 0.9180007, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+415, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6236.817, -769.8001, 2934.275, 4.415707, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+416, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.957, -768.6993, 2928.068, 1.861258, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+417, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6235.399, -774.4395, 2935.274, 4.415784, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+418, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.394, -791.2507, 2958.987, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+419, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6236.176, -801.1525, 2959.625, 4.890569, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+420, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6216.122, -784.1395, 2916.07, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+421, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+422, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.015, -765.8972, 2934.376, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+423, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.132, -772.6355, 2927.897, 1.861031, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+424, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6241.289, -775.538, 2939.904, 0.4260426, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+425, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6224.791, -787.7604, 2911.323, 3.538797, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+426, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.569, -792.2252, 2958.923, 4.890471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+427, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.869, -799.5507, 2963.767, 1.610756, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+428, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+429, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6244.787, -794.3561, 2953.658, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+430, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.196, -798.6579, 2905.251, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+431, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6226.64, -786.9846, 2911.365, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+432, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.218, -790.2701, 2959.15, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+433, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+434, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.619, -764.0278, 2934.791, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+435, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.7, -774.5356, 2928.238, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+436, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6214.198, -784.3878, 2916.588, 0.1283695, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+437, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6246.164, -795.7544, 2953.989, 2.348658, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+438, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6239.457, -776.3694, 2939.98, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+439, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.93, -801.5399, 2964.017, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+440, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.768, -800.5871, 2905.552, 1.352403, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+441, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+442, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+443, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+444, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6245.456, -795.0349, 2953.911, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+445, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6225.687, -787.3842, 2911.403, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+446, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.619, -764.0302, 2934.79, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+447, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.396, -791.2579, 2958.986, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+448, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6215.172, -784.2621, 2916.332, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+449, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.411, -773.5681, 2928.058, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+450, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.987, -799.5984, 2905.443, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+451, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.906, -800.5297, 2963.863, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+452, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6240.394, -775.9441, 2939.928, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+453, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.869, -799.5482, 2963.767, 1.610756, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+454, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.014, -765.8995, 2934.375, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+455, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6216.122, -784.1395, 2916.07, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+456, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6224.783, -787.7633, 2911.322, 3.538797, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+457, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.198, -798.6507, 2905.25, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+458, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.571, -792.235, 2958.923, 4.890471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+459, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6241.301, -775.5327, 2939.904, 0.4260426, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+460, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.129, -772.6259, 2927.898, 1.861031, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+461, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6244.778, -794.3475, 2953.655, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+462, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.626, -764.0068, 2934.795, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+463, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6246.175, -795.7651, 2953.989, 2.348658, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+464, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.704, -774.5497, 2928.24, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+465, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.931, -801.5547, 2964.02, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+466, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6226.654, -786.9788, 2911.365, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+467, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6214.181, -784.39, 2916.589, 0.1283695, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+468, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6239.434, -776.3798, 2939.982, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+469, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.764, -800.6042, 2905.552, 1.352403, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+470, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.214, -790.2507, 2959.154, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+471, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.907, -800.5568, 2963.867, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+472, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6245.474, -795.0538, 2953.918, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+473, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6225.722, -787.3697, 2911.402, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+474, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.39, -791.2288, 2958.991, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+475, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6240.36, -775.9597, 2939.93, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+476, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.98, -799.6295, 2905.45, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+477, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6215.148, -784.2652, 2916.339, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+478, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.321, -764.9497, 2934.586, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+479, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.419, -773.5964, 2928.063, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+480, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+481, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+482, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.551, -786.6024, 2911.329, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+483, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6246.856, -796.4566, 2953.976, 2.348658, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+484, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.555, -801.5486, 2905.594, 1.352403, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+485, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6239.022, -777.0469, 2940.179, 1.437057, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+486, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.218, -790.2726, 2959.15, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+487, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.618, -764.0325, 2934.79, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+488, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6214.203, -784.3871, 2916.587, 0.1283695, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+489, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.696, -774.5238, 2928.236, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+490, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.93, -801.5325, 2964.016, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+491, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+492, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+493, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.768, -800.5871, 2905.552, 1.352403, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+494, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.414, -773.5799, 2928.06, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+495, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.393, -791.241, 2958.989, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+496, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6225.71, -787.3745, 2911.402, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+497, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6215.162, -784.2634, 2916.335, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+498, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.906, -800.5445, 2963.865, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+499, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6245.466, -795.0452, 2953.915, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+500, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6240.371, -775.9545, 2939.93, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+501, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.316, -764.9637, 2934.583, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+502, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+503, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+504, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.012, -765.9042, 2934.375, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+505, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6216.132, -784.1382, 2916.067, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+506, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6244.78, -794.3492, 2953.656, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+507, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.572, -792.2399, 2958.923, 4.890471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+508, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.199, -798.6459, 2905.249, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+509, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6241.308, -775.5296, 2939.904, 0.4260426, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+510, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6224.776, -787.7662, 2911.321, 3.538797, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+511, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.869, -799.5358, 2963.766, 1.610756, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+512, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.13, -772.6283, 2927.898, 1.861031, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+513, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+514, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+515, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.985, -799.608, 2905.445, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+516, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6215.167, -784.2628, 2916.334, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+517, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.395, -791.2531, 2958.987, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+518, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.414, -773.5775, 2928.06, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+519, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6225.708, -787.3755, 2911.402, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+520, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.906, -800.5469, 2963.865, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+521, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.316, -764.966, 2934.583, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+522, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6245.464, -795.0435, 2953.914, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+523, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6240.378, -775.9514, 2939.929, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+524, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+525, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+526, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.134, -772.6426, 2927.897, 1.861031, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+527, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.569, -792.2227, 2958.924, 4.890471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+528, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6241.289, -775.538, 2939.904, 0.4260426, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+529, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.87, -799.5532, 2963.767, 1.610756, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+530, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.016, -765.8926, 2934.377, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+531, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6216.12, -784.1398, 2916.071, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+532, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.196, -798.6579, 2905.251, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+533, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6244.787, -794.3561, 2953.658, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+534, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6224.788, -787.7614, 2911.322, 3.538797, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+535, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.767, -800.5944, 2905.552, 1.352403, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+536, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+537, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.931, -801.5449, 2964.018, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+538, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.622, -764.0208, 2934.792, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+539, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6239.447, -776.3736, 2939.981, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+540, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+541, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.217, -790.2677, 2959.151, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+542, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.7, -774.5356, 2928.238, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+543, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6214.188, -784.3891, 2916.589, 0.1283695, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+544, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6226.645, -786.9827, 2911.365, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+545, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6244.789, -794.3578, 2953.659, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+546, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+547, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+548, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.985, -799.6104, 2905.446, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+549, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.414, -773.5775, 2928.06, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+550, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.906, -800.5469, 2963.865, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+551, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6240.374, -775.9534, 2939.93, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+552, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6214.195, -784.3881, 2916.588, 0.1283695, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+553, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.393, -791.2458, 2958.988, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+554, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.316, -764.9637, 2934.583, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+555, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6245.466, -795.0452, 2953.915, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+556, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6225.704, -787.3774, 2911.403, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+557, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+558, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+559, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.016, -765.8926, 2934.377, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+560, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.195, -798.6603, 2905.251, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+561, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.569, -792.2252, 2958.923, 4.890471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+562, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.133, -772.6379, 2927.897, 1.861031, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+563, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.907, -800.5593, 2963.867, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+564, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6216.12, -784.1398, 2916.071, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+565, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6224.788, -787.7614, 2911.322, 3.538797, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+566, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6241.287, -775.539, 2939.904, 0.4260426, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+567, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6244.79, -794.3596, 2953.659, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+568, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.618, -764.0325, 2934.79, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+569, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6239.461, -776.3673, 2939.98, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+570, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6226.64, -786.9846, 2911.365, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+571, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6246.163, -795.7526, 2953.989, 2.348658, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+572, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6214.198, -784.3878, 2916.588, 0.1283695, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+573, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.768, -800.5895, 2905.552, 1.352403, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+574, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.698, -774.5309, 2928.237, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+575, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.93, -801.535, 2964.017, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+576, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+577, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+578, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.572, -792.2399, 2958.923, 4.890471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+579, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6275.88, -808.4063, 2894.346, 1.553034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+580, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.413, -773.5752, 2928.06, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+581, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6225.701, -787.3784, 2911.403, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+582, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.887, -782.118, 2894.346, 4.653744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+583, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6240.383, -775.9493, 2939.929, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+584, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.906, -800.5346, 2963.863, 1.595081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+585, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6245.46, -795.04, 2953.913, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+586, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.313, -764.973, 2934.581, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+587, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6215.172, -784.2621, 2916.332, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+588, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.396, -791.2604, 2958.985, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+589, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.768, -800.5871, 2905.552, 1.352403, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+590, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6224.788, -787.7614, 2911.322, 3.538797, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+591, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.014, -765.8995, 2934.375, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+592, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6241.296, -775.5348, 2939.904, 0.4260426, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+593, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.198, -798.6507, 2905.25, 1.352562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+594, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6244.785, -794.3544, 2953.657, 2.34874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+595, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.87, -799.5532, 2963.767, 1.610756, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+596, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6216.12, -784.1398, 2916.071, 0.1283254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+597, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.133, -772.6379, 2927.897, 1.861031, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+598, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.57, -792.23, 2958.923, 4.890471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+599, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6239.44, -776.3767, 2939.981, 0.4259224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+600, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.702, -774.5427, 2928.239, 1.86108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+601, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6246.171, -795.7615, 2953.989, 2.348658, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+602, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6228.768, -800.5895, 2905.552, 1.352403, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+603, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6238.621, -764.0231, 2934.792, 4.399548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+604, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6234.217, -790.2653, 2959.151, 4.890592, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+605, 120132, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6214.19, -784.3887, 2916.589, 0.1283695, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Fel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239361 -)
(@CGUID+606, 120131, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6226.638, -786.9855, 2911.365, 3.538716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aberrant Light (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239359 -)
(@CGUID+607, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.299, -805.6875, 1667.702, 2.228159, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+608, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.153, -784.191, 1667.702, 4.185196, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+609, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6592.858, -794.8507, 1667.702, 4.461135, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+610, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6587.506, -793.6616, 1663.666, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+611, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6590.228, -783.7354, 1663.667, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+612, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6586.152, -786.2405, 1663.601, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+613, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6589.656, -795.0878, 1663.666, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+614, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6592.858, -794.8507, 1667.702, 1.759288, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+615, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.299, -805.6875, 1667.702, 1.568394, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+616, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.153, -784.191, 1667.702, 2.478526, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+617, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6588.208, -777.4327, 1663.666, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+618, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6574.668, -800.1193, 1663.666, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+619, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.153, -784.191, 1667.702, 3.682813, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+620, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6592.858, -794.8507, 1667.702, 2.165882, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+621, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.299, -805.6875, 1667.702, 4.08428, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+622, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.299, -805.6875, 1667.702, 2.524533, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+623, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6592.858, -794.8507, 1667.702, 3.394589, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+624, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.153, -784.191, 1667.702, 3.410779, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+625, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6592.884, -813.2012, 1663.666, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+626, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6593.122, -778.7073, 1663.581, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+627, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6587.846, -813.6385, 1663.666, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+628, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6592.858, -794.8507, 1667.702, 1.415539, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+629, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.153, -784.191, 1667.702, 3.081639, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+630, 119158, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6598.299, -805.6875, 1667.702, 3.24188, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Corrupted Blade (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236577 - Lames ténébreuses)
(@CGUID+631, 120867, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6716.229, -782.2205, 1521.103, 4.074593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Kil'jaeden (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+632, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6560.292, -801.6304, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+633, 121171, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6515.735, -809.6979, 1663.67, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Archmage Khadgar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241084 - Disque de vol de Khadgar)
(@CGUID+634, 121170, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6515.987, -797.2882, 1663.67, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Prophète Velen (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241078 - Orbe de vol de Velen)
(@CGUID+635, 121169, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6514.167, -785.1441, 1663.67, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Illidan Hurlorage (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+636, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6580.638, -823.3154, 1509.907, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+637, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6639.077, -833.7528, 1509.948, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+638, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6618.787, -822.9153, 1510.024, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+639, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6603.748, -817.1086, 1510.036, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+640, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6575.945, -807.025, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+641, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6563.893, -790.3483, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+642, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6573.55, -761.0601, 1510.002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+642;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+17, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Center Stalker
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic Stalker (Gigantic AOI)
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Eonic Defender
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+26, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Eonic Defender
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, '243149'), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) - 243149 -
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Maiden of Vigilance
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Volatile Corruption
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+38, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'), -- Aegis of Aggramar - 154441 - Shadowy Ghost Cosmetic Spawn Spell
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jump Target Stalker
(@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+43, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, '240704'), -- Aegwynn's Trap - 240704 - Piège d'Aegwynn
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, '240825'), -- Aegwynn's Trap - 240825 - Piège d'Aegwynn
(@CGUID+61, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+66, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+69, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+70, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+73, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, '240700'), -- Aegwynn's Trap - 240700 - Piège d'Aegwynn
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+82, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, '240705'), -- Aegwynn's Trap - 240705 - Piège d'Aegwynn
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+87, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+88, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+89, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+90, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+91, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+100, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+102, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+103, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+104, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+107, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+108, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+110, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, '245332'), -- Kil'jaeden - 245332 - Phase du Néant
(@CGUID+115, 0, 0, 50331648, 1, 0, 0, 0, 0, '239847'), -- Fallen Avatar - 239847 - Intro
(@CGUID+116, 0, 0, 0, 1, 0, 0, 0, 0, '249161'), -- El-ahrairah - 249161 -
(@CGUID+117, 0, 0, 0, 1, 0, 0, 0, 0, '240130'), -- Defensive Countermeasure - 240130 - Apparition cosmétique
(@CGUID+118, 0, 0, 0, 1, 0, 0, 0, 0, '240130'), -- Defensive Countermeasure - 240130 - Apparition cosmétique
(@CGUID+119, 0, 0, 50331648, 1, 0, 0, 0, 0, '233556'), -- Containment Pylon - 233556 - Matrice corrompue
(@CGUID+120, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+121, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+122, 0, 0, 50331648, 1, 0, 0, 0, 0, '233556'), -- Containment Pylon - 233556 - Matrice corrompue
(@CGUID+123, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Containment Pylon
(@CGUID+124, 0, 0, 50331648, 1, 0, 0, 0, 0, '233556'), -- Containment Pylon - 233556 - Matrice corrompue
(@CGUID+125, 0, 0, 50331648, 1, 0, 0, 0, 0, '233556'), -- Containment Pylon - 233556 - Matrice corrompue
(@CGUID+126, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+127, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+128, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+129, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pylon Beam Stalker
(@CGUID+130, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+131, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pylon Beam Stalker
(@CGUID+132, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+133, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+134, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+135, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+136, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+137, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+138, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+139, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pylon Beam Stalker
(@CGUID+140, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+141, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+142, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pylon Beam Stalker
(@CGUID+143, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+144, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pylon Beam Stalker
(@CGUID+145, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+146, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+147, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+148, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+149, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+150, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+151, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+152, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+153, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+154, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+155, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+156, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+157, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+158, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+159, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+160, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+161, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+162, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+163, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+164, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+165, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+166, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Achievement Stalker
(@CGUID+167, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Grid Stalker
(@CGUID+168, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+169, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+170, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+171, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+172, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+175, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+176, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+177, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+178, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+179, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+181, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+182, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+183, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+184, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+186, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+187, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+188, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+189, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+190, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+192, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+193, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+195, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+196, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+197, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+199, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+200, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+201, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+202, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+203, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+204, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+205, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+206, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+207, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+208, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+209, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+210, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+211, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+215, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+216, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+220, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+221, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+222, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+223, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+224, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+225, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+226, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+227, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+228, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+229, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+230, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+231, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+232, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+233, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+234, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+235, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+238, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+239, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+240, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+241, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+242, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+245, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+246, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+249, 0, 0, 0, 1, 0, 0, 0, 0, '250500'); -- Fragment of Obliteration - 250500 - Fragments d'essence

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+251, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+252, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+253, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+254, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+255, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+256, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+257, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+258, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+259, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+260, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+263, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+264, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+267, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+269, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+270, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+271, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+273, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+274, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+275, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+279, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+280, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+282, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+284, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+285, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+286, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+287, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+288, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+289, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+290, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+291, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+292, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+293, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+294, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+295, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+296, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+297, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+298, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+299, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+300, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+301, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+302, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+303, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+304, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+305, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+306, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+307, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+308, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+309, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+310, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+311, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+312, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+315, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+316, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+317, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+319, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+320, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+321, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+322, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+323, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+324, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+325, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+326, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+327, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+328, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+329, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+330, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+331, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+332, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+333, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+335, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+337, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+338, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+339, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+340, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+341, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+342, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+343, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+344, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+345, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+346, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+347, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+348, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+349, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+350, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+351, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+352, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+353, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+354, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+355, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+356, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+357, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+358, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+359, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+360, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+361, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+362, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+363, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+364, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+366, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Creation - 250500 - Fragments d'essence
(@CGUID+367, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- Fragment of Obliteration - 250500 - Fragments d'essence
(@CGUID+368, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+369, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+370, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+371, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+373, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+374, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+379, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+380, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+381, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+382, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+383, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+384, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+385, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+386, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+387, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+389, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+391, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+392, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+393, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+394, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+395, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+397, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+398, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+400, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+401, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+402, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+403, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+404, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+405, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+406, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+407, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+408, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+410, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+412, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+414, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+415, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+416, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+417, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+418, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+420, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+421, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+422, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+423, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+424, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+425, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+426, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+427, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+428, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+429, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+430, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+431, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+432, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+433, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+434, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+435, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+436, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+437, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+438, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+439, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+440, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+441, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+442, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+443, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+444, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+445, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+446, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+447, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+448, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+449, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+450, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+451, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+452, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+453, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+454, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+455, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+456, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+457, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+458, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+459, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+460, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+461, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+462, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+463, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+464, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+465, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+466, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+467, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+468, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+469, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+470, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+471, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+472, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+473, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+474, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+475, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+476, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+477, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+478, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+479, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+480, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+481, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+482, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+483, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+484, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+485, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+486, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+487, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+488, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+489, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+490, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+491, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+492, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+493, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+494, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+495, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+496, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+497, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+498, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+499, 0, 0, 0, 1, 0, 0, 0, 0, '239361'); -- Aberrant Fel - 239361 -

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+500, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+501, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+502, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+503, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+504, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+505, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+506, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+507, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+508, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+509, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+510, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+511, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+512, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+513, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+514, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+515, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+516, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+517, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+518, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+519, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+520, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+521, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+522, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+523, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+524, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+525, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+526, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+527, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+528, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+529, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+530, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+531, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+532, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+533, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+534, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+535, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+536, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+537, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+538, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+539, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+540, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+541, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+542, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+543, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+544, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+545, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+546, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+547, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+548, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+549, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+550, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+551, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+552, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+553, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+554, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+555, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+556, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+557, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+558, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+559, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+560, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+561, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+562, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+563, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+564, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+565, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+566, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+567, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+568, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+569, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+570, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+571, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+572, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+573, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+574, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+575, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+576, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+577, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+578, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+579, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+580, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+581, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+582, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+583, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+584, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+585, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+586, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+587, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+588, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+589, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+590, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+591, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+592, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+593, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+594, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+595, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+596, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+597, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+598, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+599, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+600, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+601, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+602, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+603, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+604, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+605, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- Aberrant Fel - 239361 -
(@CGUID+606, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- Aberrant Light - 239359 -
(@CGUID+607, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+608, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+609, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+610, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+611, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+612, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+613, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+614, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+615, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+616, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+617, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+618, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+619, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+620, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+621, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+622, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+623, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+624, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+625, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+626, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+627, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+628, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+629, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+630, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- Corrupted Blade - 236577 - Lames ténébreuses
(@CGUID+631, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kil'jaeden
(@CGUID+632, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+633, 0, 0, 0, 1, 0, 0, 0, 0, '241084'), -- Archmage Khadgar - 241084 - Disque de vol de Khadgar
(@CGUID+634, 0, 0, 0, 1, 0, 0, 0, 0, '241078'), -- Prophète Velen - 241078 - Orbe de vol de Velen
(@CGUID+635, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Illidan Hurlorage
(@CGUID+636, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+637, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+638, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+639, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+640, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+641, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+642, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'); -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+76;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 269988, 1676, 8524, 8524, 245760, '0', 0, 6295.383, -795.3216, 2886.927, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+1, 269975, 1676, 8524, 8524, 245760, '0', 0, 6194.761, -795.798, 2973.522, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+2, 269164, 1676, 8524, 8524, 245760, '0', 0, 6221.104, -795.7595, 2974.113, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+3, 268579, 1676, 8524, 8524, 245760, '0', 0, 6341.295, -795.7725, 3037.665, 4.71239, 0, 0, -0.7071066, 0.7071069, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+4, 268580, 1676, 8524, 8524, 245760, '0', 0, 6289.381, -795.5262, 3029.027, 4.71239, 0, 0, -0.7071066, 0.7071069, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+5, 269780, 1676, 8524, 8524, 245760, '0', 0, 6402.042, -795.7916, 3011.507, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+6, 272802, 1676, 8524, 8524, 245760, '0', 0, 6112.376, -733.7028, 2984.274, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+7, 269842, 1676, 8524, 8524, 245760, '0', 0, 6260.061, -852.3503, 3041.751, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+8, 269839, 1676, 8524, 8524, 245760, '0', 0, 6146.559, -762.0251, 2970.903, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+9, 269838, 1676, 8524, 8524, 245760, '0', 0, 6112.478, -733.6039, 2984.402, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+10, 268750, 1676, 8524, 8524, 245760, '0', 0, 6188.131, -945.7178, 2892.065, 1.118474, 0, 0, 0.5305395, 0.8476602, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+11, 268366, 1676, 8524, 8524, 245760, '0', 0, 6133.625, -971.8979, 2959.992, 0.5235979, 0, 0, 0.2588186, 0.9659259, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+12, 269973, 1676, 8524, 8524, 245760, '0', 0, 6099.743, -856.0253, 2974.152, 4.71239, 0, 0, -0.7071066, 0.7071069, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+13, 269841, 1676, 8524, 8524, 245760, '0', 0, 6114.529, -927.6913, 2976.787, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+14, 269840, 1676, 8524, 8524, 245760, '0', 0, 6087.842, -927.6913, 2976.787, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+15, 268514, 1676, 8524, 8524, 245760, '0', 0, 6101.104, -919.1578, 2998.948, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+16, 268748, 1676, 8524, 8524, 245760, '0', 0, 6289.318, -985.2384, 2909.796, 5.680764, 0, 0, -0.2966766, 0.954978, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+17, 269045, 1676, 8524, 8524, 245760, '0', 0, 6169.401, -1012.846, 2913.108, 5.93412, 0, 0, -0.1736479, 0.9848078, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+18, 269258, 1676, 8524, 8524, 245760, '0', 0, 6132.23, -937.5658, 2901.712, 4.948084, 0.004547596, -0.003584862, -0.6190538, 0.7853272, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+19, 268819, 1676, 8524, 8524, 245760, '0', 0, 6243.467, -1001.754, 2923.611, 0.178153, -0.000004291534, 0.00005149841, 0.08895874, 0.9960353, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+20, 268365, 1676, 8524, 8524, 245760, '0', 0, 6133.636, -1009.464, 2959.992, 2.617989, 0, 0, 0.9659252, 0.2588213, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+21, 268364, 1676, 8524, 8524, 245760, '0', 0, 6068.479, -1009.354, 2959.992, 3.665196, 0, 0, -0.9659252, 0.2588213, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+22, 269974, 1676, 8524, 8524, 245760, '0', 0, 6010.043, -793.4874, 2973.959, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+23, 269781, 1676, 8524, 8524, 245760, '0', 0, 6385.965, -1052.795, 2902.235, 5.678986, 0, 0, -0.2975254, 0.9547139, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+24, 268751, 1676, 8524, 8524, 245760, '0', 0, 6152.908, -1083.313, 2892.168, 5.198888, 0, 0, -0.5159779, 0.8566019, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+25, 268749, 1676, 8524, 8524, 245760, '0', 0, 6354.415, -1030.835, 2909.796, 5.680764, 0, 0, -0.2966766, 0.954978, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+26, 269779, 1676, 8524, 8524, 245760, '0', 0, 6438.216, -1089.601, 2881.37, 2.529184, 0, 0, 0.9534845, 0.3014419, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+27, 269120, 1676, 8524, 8524, 245760, '0', 0, 5935.24, -949.2632, 2920.025, 0.5109373, 0, 0, 0.2526989, 0.967545, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+28, 268752, 1676, 8524, 8524, 245760, '0', 0, 5987.114, -1017.305, 2927.477, 3.77578, 0, 0, -0.9501457, 0.3118062, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+29, 269192, 1676, 8524, 8524, 245760, '0', 0, 5937.457, -879.8716, 2920.775, 2.420397, 0, 0, 0.9356861, 0.3528335, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+30, 269976, 1676, 8524, 8524, 245760, '0', 0, 5825.933, -1216.871, 2787.371, 0.8726639, 0, 0, 0.4226179, 0.9063079, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+31, 270940, 1676, 8524, 8524, 245760, '0', 0, 5950.437, -1095.415, 2912.443, 2.81584, 0, 0, 0.9867649, 0.1621574, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+32, 267934, 1676, 8524, 8524, 245760, '0', 0, 6607.75, -795.1597, 1661.2, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+33, 267701, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+34, 267707, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+35, 267704, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+36, 267711, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+37, 267709, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+38, 267708, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+39, 267712, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+40, 267716, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+41, 267723, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+42, 267722, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+43, 267724, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+44, 269262, 1676, 8524, 8524, 245760, '0', 0, 6486.747, -795.6044, 1664.717, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+45, 269261, 1676, 8524, 8524, 245760, '0', 0, 6389.573, -795.6044, 1652.382, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+46, 268574, 1676, 8524, 8524, 245760, '0', 0, 6348.021, -795.5745, 1650.51, 1.570796, 0, 0, 0.7071066, 0.7071069, 604800, 255, 24, 25961), -- 0 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+47, 253126, 1676, 8524, 8524, 245760, '0', 0, 5831.302, -796.2049, 2957.74, 0.004934316, 0, 0, 0.002467155, 0.999997, 604800, 255, 1, 25961), -- Instance Portal (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+48, 269987, 1676, 8524, 8524, 245760, '0', 0, 6676.665, -804.6313, 1527.098, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+49, 267703, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+50, 267702, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+51, 267700, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+52, 267706, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+53, 267705, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+54, 267710, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+55, 267715, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+56, 267714, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+57, 267713, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+58, 267719, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+59, 267718, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+60, 267717, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+61, 267721, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+62, 267720, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+63, 269786, 1676, 8524, 8524, 245760, '0', 0, 6529.752, -839.9936, 1717.042, 5.203736, 0, 0, -0.5138998, 0.8578502, 604800, 255, 1, 25961), -- 269786 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+64, 269785, 1676, 8524, 8524, 245760, '0', 0, 6529.879, -750.2708, 1716.884, 4.182384, 0, 0, -0.8676224, 0.4972237, 604800, 255, 1, 25961), -- 269785 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+65, 269787, 1676, 8524, 8524, 245760, '0', 0, 6561.049, -875.1705, 1714.647, 5.753181, 0, 0, -0.2619114, 0.9650919, 604800, 255, 1, 25961), -- 269787 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+66, 269784, 1676, 8524, 8524, 245760, '0', 0, 6561.286, -716.3622, 1714.76, 3.658791, 0, 0, -0.9667492, 0.2557264, 604800, 255, 1, 25961), -- 269784 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+67, 269790, 1676, 8524, 8524, 245760, '0', 0, 6607.794, -885.5158, 1717.038, 6.276779, 0, 0, -0.003203392, 0.9999949, 604800, 255, 1, 25961), -- 269790 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+68, 269788, 1676, 8524, 8524, 245760, '0', 0, 6608.119, -704.8473, 1717.129, 3.134827, 0, 0, 0.9999943, 0.003382912, 604800, 255, 1, 25961), -- 269788 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+69, 269795, 1676, 8524, 8524, 245760, '0', 0, 6609.039, -683.7684, 1718.977, 6.15863, 0.04687834, -0.002691269, -0.06217957, 0.9969598, 604800, 255, 1, 25961), -- 269795 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+70, 269794, 1676, 8524, 8524, 245760, '0', 0, 6608.834, -903.899, 1718.364, 3.085218, 0.000412941, 0.043787, 0.9986429, 0.02819269, 604800, 255, 1, 25961), -- 269794 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+71, 269791, 1676, 8524, 8524, 245760, '0', 0, 6654.841, -874.2771, 1714.609, 0.517191, 0, 0, 0.255723, 0.9667501, 604800, 255, 1, 25961), -- 269791 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+72, 269789, 1676, 8524, 8524, 245760, '0', 0, 6655.748, -716.1912, 1713.549, 2.611587, 0, 0, 0.9650917, 0.2619121, 604800, 255, 1, 25961), -- 269789 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+73, 269793, 1676, 8524, 8524, 245760, '0', 0, 6687.193, -750.5946, 1716.661, 2.087987, 0, 0, 0.864419, 0.5027722, 604800, 255, 1, 25961), -- 269793 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+74, 269792, 1676, 8524, 8524, 245760, '0', 0, 6686.939, -839.8639, 1716.484, 1.04079, 0, 0, 0.4972229, 0.8676228, 604800, 255, 1, 25961), -- 269792 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+75, 269783, 1676, 8524, 8524, 245760, '0', 0, 6753.295, -799.6613, 1535.791, 3.110741, -0.08682394, -0.08682346, 0.992403, 0.007716544, 604800, 255, 1, 25961), -- 269783 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+76, 270027, 1676, 8524, 8524, 245760, '0', 0, 6674.722, 278.8524, 150, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961); -- 7.2 Tomb Raid - Avatar Floor (test) - MRN (Area: Tombe de Sargeras - Difficulty: Outil Raids)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+76;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+1, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+2, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+3, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+4, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+5, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+6, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+7, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+8, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+9, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+10, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+11, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+12, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+13, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+14, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+15, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+16, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+17, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+18, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+19, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+20, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+21, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+22, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+23, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+24, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+25, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+26, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+27, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+28, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+29, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+30, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+31, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+32, 0, 0, 0, 1), -- -Unknown-
(@OGUID+33, 0, 0, 0, 1), -- -Unknown-
(@OGUID+34, 0, 0, 0, 1), -- -Unknown-
(@OGUID+35, 0, 0, 0, 1), -- -Unknown-
(@OGUID+36, 0, 0, 0, 1), -- -Unknown-
(@OGUID+37, 0, 0, 0, 1), -- -Unknown-
(@OGUID+38, 0, 0, 0, 1), -- -Unknown-
(@OGUID+39, 0, 0, 0, 1), -- -Unknown-
(@OGUID+40, 0, 0, 0, 1), -- -Unknown-
(@OGUID+41, 0, 0, 0, 1), -- -Unknown-
(@OGUID+42, 0, 0, 0, 1), -- -Unknown-
(@OGUID+43, 0, 0, 0, 1), -- -Unknown-
(@OGUID+44, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+45, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+46, 0, 0, 1, -0.00000004371139), -- 0
(@OGUID+48, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+49, 0, 0, 0, 1), -- -Unknown-
(@OGUID+50, 0, 0, 0, 1), -- -Unknown-
(@OGUID+51, 0, 0, 0, 1), -- -Unknown-
(@OGUID+52, 0, 0, 0, 1), -- -Unknown-
(@OGUID+53, 0, 0, 0, 1), -- -Unknown-
(@OGUID+54, 0, 0, 0, 1), -- -Unknown-
(@OGUID+55, 0, 0, 0, 1), -- -Unknown-
(@OGUID+56, 0, 0, 0, 1), -- -Unknown-
(@OGUID+57, 0, 0, 0, 1), -- -Unknown-
(@OGUID+58, 0, 0, 0, 1), -- -Unknown-
(@OGUID+59, 0, 0, 0, 1), -- -Unknown-
(@OGUID+60, 0, 0, 0, 1), -- -Unknown-
(@OGUID+61, 0, 0, 0, 1), -- -Unknown-
(@OGUID+62, 0, 0, 0, 1), -- -Unknown-
(@OGUID+63, 0, 0, 1, -0.00000004371139), -- 269786
(@OGUID+64, 0, 0, 1, -0.00000004371139), -- 269785
(@OGUID+65, 0, 0, 1, -0.00000004371139), -- 269787
(@OGUID+66, 0, 0, 1, -0.00000004371139), -- 269784
(@OGUID+67, 0, 0, 1, -0.00000004371139), -- 269790
(@OGUID+68, 0, 0, 1, -0.00000004371139), -- 269788
(@OGUID+69, 0, 0, 1, -0.00000004371139), -- 269795
(@OGUID+70, 0, 0, 1, -0.00000004371139), -- 269794
(@OGUID+71, 0, 0, 1, -0.00000004371139), -- 269791
(@OGUID+72, 0, 0, 1, -0.00000004371139), -- 269789
(@OGUID+73, 0, 0, 1, -0.00000004371139), -- 269793
(@OGUID+74, 0, 0, 1, -0.00000004371139), -- 269792
(@OGUID+75, 0, 0, 1, -0.00000004371139), -- 269783
(@OGUID+76, 0, 0, 0, 1); -- 7.2 Tomb Raid - Avatar Floor (test) - MRN

DELETE FROM `spell_target_position` WHERE (`ID`=251062 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(251062, 0, 1669, 403.8, 1449.06, 772.66, 25961); -- Spell: Pierre de foyer Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=25961 WHERE (`ID`=222695 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (121169 /*Illidan Hurlorage*/, 121170 /*Prophète Velen - Orbe de vol de Velen*/, 121171 /*121171 (Archmage Khadgar) - Disque de vol de Khadgar*/, 119158 /*119158 (Corrupted Blade) - Lames ténébreuses*/, 120132 /*120132 (Aberrant Fel)*/, 120131 /*120131 (Aberrant Light)*/, 118640 /*118640 (Fragment of Creation) - Fragments d'essence*/, 118643 /*118643 (Fragment of Obliteration) - Fragments d'essence*/, 119846 /*119846 (Pylon Beam Stalker)*/, 120705 /*120705 (Achievement Stalker)*/, 117679 /*117679 (Grid Stalker)*/, 121720 /*121720 (Thal'kiel)*/, 117279 /*117279 (Containment Pylon) - Matrice corrompue*/, 120449 /*120449 (Defensive Countermeasure) - Apparition cosmétique*/, 125542 /*125542 (El-ahrairah)*/, 116939 /*116939 (Fallen Avatar) - Intro*/, 120867 /*120867 (Kil'jaeden) - Phase du Néant*/, 118289 /*118289 (Maiden of Vigilance)*/, 120153 /*120153 (Eonic Defender)*/, 118894 /*118894 (Center Stalker)*/, 118773 /*118773 (Jump Target Stalker)*/, 120158 /*120158 (Volatile Corruption)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(121169, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Illidan Hurlorage
(121170, 0, 0, 0, 1, 0, 0, 0, 0, '241078'), -- Prophète Velen - Orbe de vol de Velen
(121171, 0, 0, 0, 1, 0, 0, 0, 0, '241084'), -- 121171 (Archmage Khadgar) - Disque de vol de Khadgar
(119158, 0, 0, 50331648, 1, 0, 0, 0, 0, '236577'), -- 119158 (Corrupted Blade) - Lames ténébreuses
(120132, 0, 0, 0, 1, 0, 0, 0, 0, '239361'), -- 120132 (Aberrant Fel)
(120131, 0, 0, 0, 1, 0, 0, 0, 0, '239359'), -- 120131 (Aberrant Light)
(118640, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- 118640 (Fragment of Creation) - Fragments d'essence
(118643, 0, 0, 0, 1, 0, 0, 0, 0, '250500'), -- 118643 (Fragment of Obliteration) - Fragments d'essence
(119846, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 119846 (Pylon Beam Stalker)
(120705, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 120705 (Achievement Stalker)
(117679, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 117679 (Grid Stalker)
(121720, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121720 (Thal'kiel)
(117279, 0, 0, 50331648, 1, 0, 0, 0, 0, '233556'), -- 117279 (Containment Pylon) - Matrice corrompue
(120449, 0, 0, 0, 1, 0, 0, 0, 0, '240130'), -- 120449 (Defensive Countermeasure) - Apparition cosmétique
(125542, 0, 0, 0, 1, 0, 0, 0, 0, '249161'), -- 125542 (El-ahrairah)
(116939, 0, 0, 50331648, 1, 0, 0, 0, 0, '239847'), -- 116939 (Fallen Avatar) - Intro
(120867, 0, 0, 0, 1, 0, 0, 0, 0, '245332'), -- 120867 (Kil'jaeden) - Phase du Néant
(118289, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 118289 (Maiden of Vigilance)
(120153, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120153 (Eonic Defender)
(118894, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 118894 (Center Stalker)
(118773, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 118773 (Jump Target Stalker)
(120158, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 120158 (Volatile Corruption)


DELETE FROM `creature_template_scaling` WHERE `Entry`=120784;
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(120784, 0, 25961);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (75688, 74894, 75781, 75723, 76011, 74875, 75655);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(75688, 0.5, 1, 0, 25961),
(74894, 3, 7.5, 0, 25961),
(75781, 1, 2, 0, 25961),
(75723, 10.56259, 27.5, 0, 25961),
(76011, 3.468549, 6.75, 0, 25961),
(74875, 2.220781, 10, 0, 25961),
(75655, 1.829097, 1.25, 0, 25961);

UPDATE `creature_model_info` SET `BoundingRadius`=1.876967, `VerifiedBuild`=25961 WHERE `DisplayID`=25217;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=27823;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=121169 AND `ID`=1) OR (`CreatureID`=121170 AND `ID`=1) OR (`CreatureID`=121171 AND `ID`=1) OR (`CreatureID`=116939 AND `ID`=1) OR (`CreatureID`=118289 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(121169, 1, 150732, 0, 0, 150732, 0, 0, 0, 0, 0), -- Illidan Hurlorage
(121170, 1, 35714, 0, 0, 0, 0, 0, 0, 0, 0), -- Prophète Velen
(121171, 1, 28067, 0, 0, 0, 0, 0, 0, 0, 0), -- Archmage Khadgar
(116939, 1, 115802, 0, 0, 0, 0, 0, 0, 0, 0), -- Fallen Avatar
(118289, 1, 146304, 0, 0, 0, 0, 0, 0, 0, 0); -- Maiden of Vigilance



UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2501, `speed_walk`=3.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=37750784 WHERE `entry`=121169; -- Illidan Hurlorage
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2263, `speed_walk`=3.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=37748736, `unit_flags3`=3 WHERE `entry`=121170; -- Prophète Velen
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2007, `speed_walk`=3.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=121171; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `speed_run`=10, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=119158; -- Corrupted Blade
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=120132; -- Aberrant Fel
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=120131; -- Aberrant Light
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=118640; -- Fragment of Creation
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=118643; -- Fragment of Obliteration
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=119846; -- Pylon Beam Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=120705; -- Achievement Stalker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=117679; -- Grid Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=121720; -- Thal'kiel
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=1375, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=69240832, `unit_flags3`=1 WHERE `entry`=117279; -- Containment Pylon
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=120449; -- Defensive Countermeasure
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=125542; -- El-ahrairah
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=6, `speed_run`=2.142857, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=16640, `unit_flags2`=4194304, `VehicleId`=5114 WHERE `entry`=116939; -- Fallen Avatar
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=37750784, `VehicleId`=5115 WHERE `entry`=120867; -- Kil'jaeden
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags2`=1073743872 WHERE `entry`=118289; -- Maiden of Vigilance
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=120153; -- Eonic Defender
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=118894; -- Center Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=118773; -- Jump Target Stalker
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=120158; -- Volatile Corruption


UPDATE `creature_template` SET `modelid1`=61871, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=200, `ManaModifier`=80, `movementId`=179, `VerifiedBuild`=25961 WHERE `entry`=121171; -- Archmage Khadgar
UPDATE `creature_template` SET `modelid1`=75059, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=268435460, `HealthModifier`=250, `movementId`=179, `VerifiedBuild`=25961 WHERE `entry`=121169; -- Illidan Hurlorage
UPDATE `creature_template` SET `modelid1`=75801, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=262208, `HealthModifier`=200, `ManaModifier`=15, `movementId`=179, `VerifiedBuild`=25961 WHERE `entry`=121170; -- Prophète Velen
UPDATE `creature_template` SET `modelid1`=16480, `modelid2`=11686, `HealthScalingExpansion`=6, `type`=10, `movementId`=601, `VerifiedBuild`=25961 WHERE `entry`=119158; -- Corrupted Blade
UPDATE `creature_template` SET `modelid1`=62217, `VerifiedBuild`=25961 WHERE `entry`=106336; -- Buse à queue rousse
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=53692; -- Hyjal Fuzzy Wuzzy
UPDATE `creature_template` SET `modelid1`=11686, `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=25961 WHERE `entry`=120132; -- Aberrant Fel
UPDATE `creature_template` SET `modelid1`=11686, `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=25961 WHERE `entry`=120131; -- Aberrant Light
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=102199; -- Stampede
UPDATE `creature_template` SET `modelid1`=11686, `type`=10, `VerifiedBuild`=25961 WHERE `entry`=118640; -- Fragment of Creation
UPDATE `creature_template` SET `modelid1`=11686, `type`=10, `VerifiedBuild`=25961 WHERE `entry`=118643; -- Fragment of Obliteration
UPDATE `creature_template` SET `modelid1`=16480, `modelid2`=11686, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1024, `VerifiedBuild`=25961 WHERE `entry`=117679; -- Grid Stalker
UPDATE `creature_template` SET `modelid1`=16480, `modelid2`=11686, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1024, `VerifiedBuild`=25961 WHERE `entry`=120705; -- Achievement Stalker
UPDATE `creature_template` SET `modelid1`=16480, `modelid2`=75688, `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=25961 WHERE `entry`=119846; -- Pylon Beam Stalker
UPDATE `creature_template` SET `modelid1`=74894, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=117279; -- Containment Pylon
UPDATE `creature_template` SET `modelid1`=29297, `modelid2`=11686, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=121720; -- Thal'kiel
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=75781, `HealthScalingExpansion`=6, `rank`=1, `type`=9, `type_flags`=2097224, `HealthModifier`=100, `VerifiedBuild`=25961 WHERE `entry`=120449; -- Defensive Countermeasure
UPDATE `creature_template` SET `modelid1`=4626, `modelid2`=27823, `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=25961 WHERE `entry`=125542; -- El-ahrairah
UPDATE `creature_template` SET `modelid1`=76011, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097260, `HealthModifier`=1684.31, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=120867; -- Kil'jaeden
UPDATE `creature_template` SET `modelid1`=74497, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=270532716, `type_flags2`=4224, `movementId`=197, `VerifiedBuild`=25961 WHERE `entry`=116939; -- Fallen Avatar
UPDATE `creature_template` SET `modelid1`=74875, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097260, `type_flags2`=128, `HealthModifier`=1400, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=118289; -- Maiden of Vigilance
UPDATE `creature_template` SET `modelid1`=4626, `modelid2`=27823, `type`=10, `VerifiedBuild`=25961 WHERE `entry`=118894; -- Center Stalker
UPDATE `creature_template` SET `modelid1`=25217, `HealthScalingExpansion`=6, `rank`=1, `type`=9, `type_flags`=2097224, `HealthModifier`=120, `VerifiedBuild`=25961 WHERE `entry`=120153; -- Eonic Defender
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25961 WHERE `entry`=29327; -- Frost Leopard
UPDATE `creature_template` SET `modelid1`=4626, `modelid2`=27823, `type`=10, `VerifiedBuild`=25961 WHERE `entry`=118773; -- Jump Target Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=21723; -- Blackwind Sabercat
UPDATE `creature_template` SET `modelid1`=75655, `HealthScalingExpansion`=6, `rank`=1, `type`=15, `HealthModifier`=30, `VerifiedBuild`=25961 WHERE `entry`=120158; -- Volatile Corruption
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=114991; -- Golden Arachnodrone


UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=21723 AND `Idx`=0); -- Blackwind Sabercat

DELETE FROM `gameobject_template` WHERE `entry`=270027;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(270027, 33, 40650, '7.2 Tomb Raid - Avatar Floor (test) - MRN', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- 7.2 Tomb Raid - Avatar Floor (test) - MRN

UPDATE `gameobject_template` SET `type`=10, `displayId`=42097, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269783; -- 269783
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269793; -- 269793
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269792; -- 269792
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269791; -- 269791
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269789; -- 269789
UPDATE `gameobject_template` SET `type`=10, `displayId`=42099, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269795; -- 269795
UPDATE `gameobject_template` SET `type`=10, `displayId`=42099, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269794; -- 269794
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269790; -- 269790
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269788; -- 269788
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269787; -- 269787
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269784; -- 269784
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269786; -- 269786
UPDATE `gameobject_template` SET `type`=10, `displayId`=42098, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269785; -- 269785

