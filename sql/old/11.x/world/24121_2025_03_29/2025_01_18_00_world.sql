SET @CGUID := 4000329;
SET @OGUID := 4000114;
SET @ATID := 104;
SET @ATPROPERTIESID := 95;
SET @ATSPAWNID := 108;

-- Areatrigger templates
DELETE FROM `areatrigger_template` WHERE `Id`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 0, 0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID+0, 1, 0, 347277, 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATPROPERTIESID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 1, 1, 186.9, 159.4, 20, 186.9, 159.4, 20, 0, 0, 0);

UPDATE `areatrigger_create_properties` SET `Speed`=1 WHERE `Id` IN (91, 92, 93, 94);

DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWNID+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATPROPERTIESID+0, 1, 870, '0', 3124.4888, -721.27606, 270, 0.3616, 0, 1664, 0, 'The Jade Forest - Hellscream''s Fist - Player Catcher', 0);

-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=55135; -- General Nazgrim
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=64856; -- Sky Master Corpora
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=64867; -- Kor'kron Shin
UPDATE `creature_template` SET `unit_flags`=0x0, `unit_flags2`=0x800 WHERE `entry`=64868; -- Kor'kron Dubs
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=64869; -- Kor'kron Jo'mag
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=64870; -- Kor'kron Spisak
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=64871; -- Warbringer Ho'Gan
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=64872; -- Sky Marshal Schwind
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=64873; -- Cannoneer Powell
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=64874; -- Cannoneer Buczacki
UPDATE `creature_template` SET `unit_flags3`=0x41000001 WHERE `entry` IN (66677, 66676, 66674, 66183); -- Gunship Turret
UPDATE `creature_template` SET `unit_flags3`=0x40000000 WHERE `entry`=66795; -- Gunship Fire Bunny
UPDATE `creature_template` SET `unit_flags3`=0x41000000, `flags_extra`=`flags_extra`|128 WHERE `entry`=67129; -- Rapelling Manfred
UPDATE `creature_template` SET `unit_flags3`=0x41000000, `flags_extra`=`flags_extra`|128 WHERE `entry`=67136; -- Exploding Manfred

DELETE FROM `creature_template_addon` WHERE `entry` IN (55135,64856,64867,64868,64869,64870,64871,64872,64873,64874,65148,66183,66667,66674,66676,66677,66793,66795,67129,67131,67136);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(55135, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 55135 (General Nazgrim)
(64856, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 64856 (Sky Master Corpora)
(64867, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 64867 (Kor'kron Shin)
(64868, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 64868 (Kor'kron Dubs)
(64869, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 64869 (Kor'kron Jo'mag)
(64870, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 64870 (Kor'kron Spisak)
(64871, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 64871 (Warbringer Ho'Gan)
(64872, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 64872 (Sky Marshal Schwind)
(64873, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 64873 (Cannoneer Powell)
(64874, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 64874 (Cannoneer Buczacki)
(65148, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 65148 (Shikyo)
(66183, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 66183 (Gunship Turret)
(66667, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 66667 (Rivett Clutchpop)
(66674, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 66674 (Gunship Turret)
(66676, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 66676 (Gunship Turret)
(66677, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 66677 (Gunship Turret)
(66793, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 66793 (Hellscream's Fist Engineer)
(66795, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 66795 (Gunship Fire Bunny)
(67129, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 67129 (Rapelling Manfred)
(67131, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 67131 (Hellscream's Vanguard)
(67136, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 67136 (Exploding Manfred)

UPDATE `creature_equip_template` SET `VerifiedBuild`=58630 WHERE (`ID`=1 AND `CreatureID` IN (66979,66948,66917,66915,66911,66793,66694,66667,66650,66649,66648,66647,66347,66346,66291,66237,66235,66219,66200,65840,65779,64874,64873,64872,64871,64870,64869,64868,64867,64856,58945,58943,55555,55509,55470)) OR (`ID`=2 AND `CreatureID`=66793);
UPDATE `creature_quest_currency` SET `VerifiedBuild`=58630 WHERE (`CurrencyId`=738 AND `CreatureId` IN (58945,55555,63467,62930,61446,66750,65779,66928,66948,66425,66426,56199,56198,59782,55238,54988,55509,58943,62537,55470,66917,65840)) OR (`CurrencyId`=2778 AND `CreatureId` IN (58945,55555,63467,62930,61446,66750,65779,66928,66948,66425,66426,56199,56198,59782,55238,54988,55509,58943,62537,55470,66917,65840));

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=58630 WHERE `DisplayID` IN (32200, 45526, 45525, 45524, 45499, 39810, 45664, 45665, 45663, 45666, 45336, 39044, 45518, 44985, 44986, 44984, 45144, 45142, 45141, 45112, 45115, 45114, 45125, 45128, 45131, 45095, 41677, 44411, 17188, 44983, 44995, 44928, 44895, 44894, 44893, 44892, 44891, 44890, 44889, 44888, 44887, 44886, 44885, 44883, 44882, 44880, 44879, 44878, 44877, 44876, 44875, 44872, 44868, 45101, 59356, 85277, 85292, 44864, 44863, 44861, 44862, 44851, 44634, 28038, 41102, 1829, 45501, 45502, 45503, 30511, 14360, 39276, 43194, 43311, 6296, 43199, 40692, 40691, 35802, 40093, 42681, 41903, 42145, 45047, 6297, 23985, 27883, 40716, 40713, 6303, 2957, 36578, 2955, 10828, 45423, 45682, 42528, 41120, 41044, 41064, 41066, 41063, 39117, 39116, 39588, 42562, 39579, 11686, 24890, 24895, 24898, 26622, 21342);
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=58630 WHERE `DisplayID`=40625;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=0.75, `VerifiedBuild`=58630 WHERE `DisplayID`=42147;

UPDATE `creature_template_model` SET `VerifiedBuild`=58630 WHERE (`Idx`=1 AND `CreatureID` IN (63059,58945,62992,59357,63467,63420,62545,29888,28960,61125,66948,66742,66688,66649,66648,66647,66477,66650,62167,66336,56198,66654,67017,58943,62536,62537,67018,55463,61535,55464,66916,67019,55470,55392,55388,55383,55379,66214,66347,66917,66346,66554,66382,63919,64774,67136,64761,59312,40789,32520,67129,66793,66291,63715,63004,66202,66795,66200,40725,40165)) OR (`Idx`=0 AND `CreatureID` IN (63059,58945,55555,62992,59357,63467,62930,63420,62545,29888,62383,62384,61446,62381,66750,28960,61120,61125,65779,66928,66948,66742,66688,66649,66648,66647,66477,66425,66650,66426,62167,66336,56199,56198,66654,13445,80673,59782,55238,54988,55509,67017,58943,62536,62537,67018,55463,61535,55464,66916,67019,66911,55470,55392,55388,55383,55379,66214,66218,66265,66237,66235,66228,66230,66665,66220,66223,66236,66347,66238,66219,66430,66917,66346,66234,66233,66232,66225,66979,66981,66980,66239,66231,66227,66222,63003,55403,61507,55404,66694,66226,64776,66554,66915,66382,63919,64774,59666,67136,64761,64775,59312,65843,65840,66676,66667,64872,64870,64869,67131,66677,40789,66674,62994,55135,32520,64873,65148,67129,66793,66291,64867,63715,66183,64871,63004,64868,64856,66203,66202,64874,66795,66200,66210,21354,33030,18365,65851,63502,35362,65011,69066,64993,305,80651,71486,70356,69219,68288,65016,63042,59072,56921,54879,54741,54423,47654,40725,40625,40165,356,25064,32944,32158,31717,28363,28302,18379,14505,60941,31698,304)) OR (`Idx`=3 AND `CreatureID` IN (29888,66948,66649,66648,66650,66346,59312,66793,66291,66200)) OR (`Idx`=2 AND `CreatureID` IN (29888,66948,66649,66648,66650,66654,62537,61535,55464,55470,66917,66346,59312,66793,66291,66202,66200));

-- Difficulties
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=58630 WHERE (`DifficultyID`=0 AND `Entry` IN (67131,66688,66667,66430,66347,66346,64776,64775,64774,63919,63003,62167,55403,40789,32520,28960));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=55135 AND `DifficultyID`=0); -- 55135 (General Nazgrim) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=58630 WHERE (`Entry`=65148 AND `DifficultyID`=0); -- 65148 (Shikyo) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=64874 AND `DifficultyID`=0); -- 64874 (Cannoneer Buczacki) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=64873 AND `DifficultyID`=0); -- 64873 (Cannoneer Powell) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=64872 AND `DifficultyID`=0); -- 64872 (Sky Marshal Schwind) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=64871 AND `DifficultyID`=0); -- 64871 (Warbringer Ho'Gan) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=64870 AND `DifficultyID`=0); -- 64870 (Kor'kron Spisak) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=64869 AND `DifficultyID`=0); -- 64869 (Kor'kron Jo'mag) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=64868 AND `DifficultyID`=0); -- 64868 (Kor'kron Dubs) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=64867 AND `DifficultyID`=0); -- 64867 (Kor'kron Shin) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=58630 WHERE (`Entry`=64856 AND `DifficultyID`=0); -- 64856 (Sky Master Corpora) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=58630 WHERE (`Entry`=66183 AND `DifficultyID`=0); -- 66183 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=58630 WHERE (`Entry`=66674 AND `DifficultyID`=0); -- 66674 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=58630 WHERE (`Entry`=66676 AND `DifficultyID`=0); -- 66676 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=58630 WHERE (`Entry`=66677 AND `DifficultyID`=0); -- 66677 (Gunship Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=58630 WHERE (`Entry`=66793 AND `DifficultyID`=0); -- 66793 (Hellscream's Fist Engineer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20080100, `VerifiedBuild`=58630 WHERE (`Entry`=66795 AND `DifficultyID`=0); -- 66795 (Gunship Fire Bunny) - Sessile, Amphibious, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=58630 WHERE (`Entry`=67129 AND `DifficultyID`=0); -- 67129 (Rapelling Manfred) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=58630 WHERE (`Entry`=67136 AND `DifficultyID`=0); -- 67136 (Exploding Manfred) - Sessile, Floating
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (55135,65148,64874,64873,64872,64871,64870,64869,64868,64867,64856,66183,66674,66676,66677,66793,66795,67129,67136,67131,66688,66667,66430,66347,66346,64776,64775,64774,63919,63003,62167,55403,40789,32520,28960) AND `DifficultyID`!=0;

UPDATE `creature_questitem` SET `VerifiedBuild`=58630 WHERE (`CreatureEntry`=62930 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=65779 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=55470 AND `DifficultyID`=0 AND `Idx`=3) OR (`CreatureEntry`=55470 AND `DifficultyID`=0 AND `Idx`=2) OR (`CreatureEntry`=55470 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=55470 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=66917 AND `DifficultyID`=0 AND `Idx`=3) OR (`CreatureEntry`=66917 AND `DifficultyID`=0 AND `Idx`=2) OR (`CreatureEntry`=66917 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=66917 AND `DifficultyID`=0 AND `Idx`=0);
DELETE FROM `creature_questitem` WHERE `CreatureEntry` IN (62930,65779,55470,66917) AND `DifficultyID`!=0;

-- Gossips
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=4342 AND `SourceEntry`=7;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,4342,7,0,0,47,0,29690,10,0,'',0,0,0,'','Show gossip option if quest 29690 is taken | complete'),
(15,4342,7,0,1,47,0,31853,10,0,'',0,0,0,'','Show gossip option if quest 31853 is taken | complete');

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=58630 WHERE `entry` IN (212191, 212193, 211990, 209906, 209905, 209816, 209578, 215882, 215695, 215692, 215691, 215690, 212174, 209354, 215588, 209550, 212325, 212185, 215693, 209780, 215859, 215860, 212969, 212181, 215564, 215563, 215562, 215423, 215422, 215035, 215036, 215031, 214791, 214864, 214723, 215844, 215038, 215037, 215034, 215033, 215032, 212589, 212570, 212561, 212578, 212562, 212582, 212592, 212579, 212563, 212591, 212559, 212576, 212571, 212594, 212590, 212560, 212587, 212588, 212569, 212593, 212583, 214987, 212595, 212586, 212585, 212584, 212581, 212580, 212572, 212568, 212567, 212566, 212565, 212564, 278457, 209328, 219095, 213446, 214567, 214566, 215647, 215681, 215649, 215650, 215646, 214894, 210804, 214893, 214570, 214569, 212621, 216302, 212623, 212622, 215684, 215845, 259114, 215967, 215683, 215689, 215766, 215686, 209353, 215711, 215767, 215709, 209349, 215702, 209311, 200296, 212171, 215687, 215718, 212182, 212926, 215391, 212183, 211668, 210868, 212184, 212924, 212624, 214988, 214568, 191640, 212925, 212625, 216301, 212186);

UPDATE `gameobject_questitem` SET `VerifiedBuild`=58630 WHERE (`GameObjectEntry`=209825 AND `Idx`=0);

-- Phases
DELETE FROM `phase_area` WHERE `PhaseId` IN (1664, 1729, 1730, 1731, 1767, 1867);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(5866, 1664, 'The Jade Forest - Ascent of Swirling Winds: Horde Gunship - Intact - Shooting Gallery'),
(6050, 1664, 'The Jade Forest - Spiritsong River: Horde Gunship - Intact - Shooting Gallery'),
(6521, 1664, 'The Jade Forest - Honeydew Village: Horde Gunship - Intact - Shooting Gallery'),
(6522, 1664, 'The Jade Forest - Honeydew Glade: Horde Gunship - Intact - Shooting Gallery'),
(6523, 1664, 'The Jade Forest - Honeydew Farm: Horde Gunship - Intact - Shooting Gallery'),
(6524, 1664, 'The Jade Forest - Thunder Hold: Horde Gunship - Intact - Shooting Gallery'),
(5785, 1729, 'The Jade Forest: "Cosmetic - Gunship Turret, Left"'),
(5785, 1730, 'The Jade Forest: "Cosmetic - Gunship Turret, Middle"'),
(5785, 1731, 'The Jade Forest: "Cosmetic - Gunship Turret, Right"'),
(5785, 1767, 'The Jade Forest: "Cosmetic - Nazgrim, Horde Gunship"'),
(5785, 1867, 'The Jade Forest: Cosmetic - Hellscream''s Fist Spawns');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (1664, 1729, 1730, 1731, 1767, 1867);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 1664, 0, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply phase 1664 if player is Horde'),
(26, 1664, 0, 0, 0, 47, 0, 31765, 64, 0, 1, 0, 0, '', 'Apply phase 1664 if quest 31765 is not rewarded'),
(26, 1729, 0, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply phase 1729 if player is Horde'),
(26, 1729, 0, 0, 0, 1, 0, 130996, 1, 0, 1, 0, 0, '', 'Apply phase 1729 if aura 130996 is not applied'),
(26, 1729, 0, 0, 0, 47, 0, 31765, 64, 0, 1, 0, 0, '', 'Apply phase 1729 if quest 31765 is not rewarded'),
(26, 1730, 0, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply phase 1730 if player is Horde'),
(26, 1730, 0, 0, 0, 1, 0, 130997, 1, 0, 1, 0, 0, '', 'Apply phase 1730 if aura 130997 is not applied'),
(26, 1730, 0, 0, 0, 47, 0, 31765, 64, 0, 1, 0, 0, '', 'Apply phase 1730 if quest 31765 is not rewarded'),
(26, 1731, 0, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply phase 1731 if player is Horde'),
(26, 1731, 0, 0, 0, 1, 0, 130998, 1, 0, 1, 0, 0, '', 'Apply phase 1731 if aura 130998 is not applied'),
(26, 1731, 0, 0, 0, 47, 0, 31765, 64, 0, 1, 0, 0, '', 'Apply phase 1731 if quest 31765 is not rewarded'),
(26, 1767, 0, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply phase 1767 if player is Horde'),
(26, 1767, 0, 0, 0, 47, 0, 31765, 2 | 64, 0, 1, 0, 0, '', 'Apply phase 1767 if quest 31765 is not complete | rewarded'),
(26, 1867, 0, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply phase 1867 if player is Horde'),
(26, 1867, 0, 0, 0, 1, 0, 130996, 1, 0, 1, 0, 0, '', 'Apply phase 1867 if aura 130996 is not applied'),
(26, 1867, 0, 0, 0, 1, 0, 130997, 1, 0, 1, 0, 0, '', 'Apply phase 1867 if aura 130997 is not applied'),
(26, 1867, 0, 0, 0, 1, 0, 130998, 1, 0, 1, 0, 0, '', 'Apply phase 1867 if aura 130998 is not applied'),
(26, 1867, 0, 0, 0, 47, 0, 31769, 2 | 64, 0, 1, 0, 0, '', 'Apply phase 1867 if quest 31769 is not complete | rewarded');

-- Spells
DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (131469,347277));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(131469, 0, 870, 3171.4599609375, -687.301025390625, 321.024993896484375, 58630), -- Spell: 131469 (Gunship Portal Click) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(347277, 0, 870, 3176.080078125, -698.92999267578125, 321.029998779296875, 58630); -- Spell: 347277 (Teleport Player) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (131202, 131992);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 131202, 0, 0, 31, 0, 3, 66795, 0, 0, 0, 0, '', 'Spell "Douse Flames" targets Gunship Fire Bunny'),
(13, 1, 131992, 0, 0, 31, 0, 3, 67129, 0, 0, 0, 0, '', 'Spell "Rappelling Rope Aura" targets Rapelling Manfred');

-- Spawn tracking
UPDATE `spawn_tracking_template` SET `PhaseId`=4158, `VerifiedBuild`=57388 WHERE `SpawnTrackingId`=603742; -- Map: 1 (Kalimdor) - Phase: 4158
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=56819 WHERE (`QuestObjectiveId`=397649 AND `SpawnTrackingId`=603742);
UPDATE `spawn_tracking_template` SET `PhaseId`=16013, `VerifiedBuild`=57534 WHERE `SpawnTrackingId`=32703; -- Map: 0 (Eastern Kingdoms) - Phase: 16013 (Cosmetic - Stormwind Keep - See Guards and Nobles)
UPDATE `spawn_tracking_template` SET `PhaseId`=1687, `VerifiedBuild`=57689 WHERE `SpawnTrackingId`=609102; -- Map: 0 (Eastern Kingdoms) - Phase: 1687 (See Rell Nightwind)
UPDATE `spawn_tracking_template` SET `PhaseId`=1686, `VerifiedBuild`=57689 WHERE `SpawnTrackingId`=715068; -- Map: 0 (Eastern Kingdoms) - Phase: 1686 (Stormwind - 5.0 Phased Terrain Master)
UPDATE `spawn_tracking_template` SET `PhaseUseFlags`=1, `VerifiedBuild`=57689 WHERE `SpawnTrackingId`=2165473; -- Map: 0 (Eastern Kingdoms) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=57689 WHERE `SpawnTrackingId` IN (2165492, 673553, 672538, 1943799, 1309110, 1348225, 1617494, 1348218);
UPDATE `spawn_tracking_template` SET `PhaseId`=19168, `VerifiedBuild`=57689 WHERE `SpawnTrackingId`=2194169; -- Map: 0 (Eastern Kingdoms) - Phase: 19168

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+117;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 40789, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3122.640625, -718.41839599609375, 335.801513671875, 3.516840457916259765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Generic Controller Bunny (CSA) (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (Auras: 132224 - FX_Hordegunship_Idle_Loop)
(@CGUID+1, 40789, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3135.407958984375, -749.25, 301.890625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Generic Controller Bunny (CSA) (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+2, 40789, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3167.3525390625, -737.9774169921875, 301.855804443359375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Generic Controller Bunny (CSA) (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+3, 40789, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3154.994873046875, -743.20660400390625, 300.970977783203125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Generic Controller Bunny (CSA) (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+4, 55135, 870, 5785, 6525, '0', 1767, 0, 1076, 0, 0, 3178.838623046875, -696.8819580078125, 321.108062744140625, 3.499312639236450195, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- General Nazgrim (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+5, 64856, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3182.303955078125, -707.55035400390625, 321.10809326171875, 4.065783977508544921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Sky Master Corpora (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+6, 64867, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3111.1962890625, -750.40106201171875, 325.445220947265625, 4.472012519836425781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Kor'kron Shin (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+7, 64868, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3163.8515625, -735.076416015625, 327.083984375, 5.001268863677978515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Kor'kron Dubs (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+8, 64869, 870, 5785, 6525, '0', 1767, 0, 1076, 0, 1, 3175.04345703125, -696.890625, 321.108062744140625, 6.238652706146240234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Kor'kron Jo'mag (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+9, 64870, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3180.912353515625, -706.34027099609375, 321.108062744140625, 5.557407379150390625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Kor'kron Spisak (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+10, 64871, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3163.647705078125, -701.76214599609375, 300.803070068359375, 0.350155621767044067, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Warbringer Ho'Gan (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+11, 64872, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3137.83154296875, -711.90106201171875, 296.838623046875, 5.428248882293701171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Sky Marshal Schwind (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+12, 64873, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3158.2109375, -731.6163330078125, 326.203125, 4.240667343139648437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Cannoneer Powell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+13, 64874, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3137.971435546875, -678.7725830078125, 326.872100830078125, 2.072447538375854492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Cannoneer Buczacki (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+14, 65148, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3177.955810546875, -683.24652099609375, 321.10809326171875, 4.567292690277099609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Shikyo (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+15, 66183, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3114.389892578125, -683.69793701171875, 301.579071044921875, 1.951011538505554199, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+16, 66183, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3139.1103515625, -674.1475830078125, 301.575592041015625, 1.90030074119567871, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+17, 66183, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3126.709228515625, -678.92535400390625, 300.99676513671875, 1.952864050865173339, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+18, 66183, 870, 5785, 6525, '0', 1683, 0, 1076, 0, 0, 3139.80908203125, -749.76739501953125, 301.575927734375, 5.198672771453857421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+19, 66183, 870, 5785, 6525, '0', 1683, 0, 1076, 0, 0, 3164.598876953125, -740.26739501953125, 301.586273193359375, 4.955898761749267578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+20, 66183, 870, 5785, 6525, '0', 1683, 0, 1076, 0, 0, 3152.18310546875, -745.01043701171875, 300.9998779296875, 5.034642219543457031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+21, 66667, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3139.37841796875, -713.71527099609375, 296.86041259765625, 2.335260868072509765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Rivett Clutchpop (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+22, 66674, 870, 5785, 6525, '0', 1729, 0, 1076, 0, 0, 3164.598876953125, -740.26739501953125, 301.586273193359375, 4.955898761749267578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+23, 66676, 870, 5785, 6525, '0', 1730, 0, 1076, 0, 0, 3152.18310546875, -745.01043701171875, 300.9998779296875, 5.034642219543457031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+24, 66677, 870, 5785, 6525, '0', 1731, 0, 1076, 0, 0, 3139.80908203125, -749.76739501953125, 301.575927734375, 5.198672771453857421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Turret (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+25, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3133.085205078125, -687.03125, 325.900146484375, 1.047097444534301757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+26, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3109.911376953125, -736.48089599609375, 302.4320068359375, 5.671357154846191406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+27, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3138.0478515625, -675.90106201171875, 301.46002197265625, 1.023198246955871582, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+28, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3115.57373046875, -733.3507080078125, 301.126708984375, 4.867597579956054687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+29, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3127.950439453125, -680.1961669921875, 301.022308349609375, 2.504512310028076171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+30, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3140.412353515625, -675.70831298828125, 301.65924072265625, 2.20569610595703125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+31, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3123.9619140625, -708.30035400390625, 325.763671875, 3.994185447692871093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+32, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 1, 3117.9462890625, -733.40802001953125, 325.612274169921875, 1.984817743301391601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+33, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3179.954, -703.46875, 301.2275, 5.767270088195800781, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3174.6814, -691.76215, 301.203, 1.339192628860473632, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+35, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3181.3628, -698.69617, 301.35123, 0.779110968112945556, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3179.0852, -693.5833, 301.25284, 0.197102010250091552, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+37, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3172.8706, -710.1476, 301.26895, 5.137327194213867187, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+38, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3164.1962890625, -697.38543701171875, 300.90008544921875, 2.457499504089355468, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+39, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3162.4368, -719.0139, 299.97116, 5.073873043060302734, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+40, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3112.1104, -728.6285, 300.7873, 5.042895317077636718, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3134.638, -698.4583, 299.4983, 0.963338613510131835, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+42, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3103.1848, -719.3264, 301.82843, 1.149220108985900878, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3090.639, -737.2049, 303.88928, 2.581154823303222656, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+44, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3105.7778, -733.5382, 302.30133, 6.213864803314208984, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+45, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3170.2925, -693.07294, 301.15195, 0.88222593069076538, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3131.1614, -705.1893, 324.9966, 3.827762603759765625, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3195.5295, -685.441, 330.20355, 5.37598419189453125, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+48, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3198.7605, -699.6875, 329.98904, 1.151488661766052246, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+49, 66793, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3135.9697, -728.6094, 324.86078, 2.322982549667358398, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Fist Engineer (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+50, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3173.170166015625, -718.4757080078125, 330.16033935546875, 4.629849433898925781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+51, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3139.8681640625, -710.0625, 325.27685546875, 1.025738358497619628, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+52, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3114.428955078125, -683.578125, 301.5673828125, 5.231370925903320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+53, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3156.1337890625, -734.38714599609375, 326.13824462890625, 5.231370925903320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+54, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3126.6796875, -716.6961669921875, 333.84051513671875, 0.068900234997272491, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+55, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3108.093017578125, -709.515625, 303.793701171875, 4.161460399627685546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+56, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3126.864501953125, -711.01910400390625, 327.400177001953125, 1.6653214693069458, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+57, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3200.9296875, -691.45489501953125, 330.338134765625, 1.025738358497619628, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+58, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3120.654541015625, -719.2430419921875, 336.23455810546875, 0.202970147132873535, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+59, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3120.8046875, -723.37152099609375, 335.1923828125, 6.090559005737304687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+60, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3126.108642578125, -722.248291015625, 333.315093994140625, 5.8039398193359375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+61, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3174.1015625, -716.248291015625, 301.615386962890625, 2.089220046997070312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+62, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3186.19873046875, -705.045166015625, 301.56414794921875, 2.767685890197753906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+63, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3121.233642578125, -730.15625, 326.187255859375, 4.6066741943359375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+64, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3095.893310546875, -734.52777099609375, 330.950103759765625, 5.29395294189453125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+65, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3142.95751953125, -727.326416015625, 325.377105712890625, 5.252596378326416015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+66, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3125.056396484375, -736.92706298828125, 300.146270751953125, 1.172957897186279296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+67, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3125.48779296875, -725.03302001953125, 332.080047607421875, 5.433604240417480468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+68, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3128.341064453125, -718.3194580078125, 332.408935546875, 0.120946928858757019, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+69, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3129.28466796875, -721.78643798828125, 330.4046630859375, 5.252596378326416015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+70, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3151.15283203125, -707.04339599609375, 377.102996826171875, 5.87807464599609375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+71, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3164.708251953125, -724.03302001953125, 300.825439453125, 2.329629898071289062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+72, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3139.185791015625, -674.03302001953125, 301.580322265625, 5.231370925903320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+73, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3167.453125, -713.578125, 304.441192626953125, 1.464406728744506835, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+74, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3198.27783203125, -691.87152099609375, 330.199951171875, 1.025738358497619628, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+75, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3158.22998046875, -689.0399169921875, 306.52703857421875, 1.657482743263244628, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+76, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3126.876708984375, -726.58160400390625, 327.066925048828125, 5.567425251007080078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+77, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3112.385498046875, -735.1475830078125, 302.44573974609375, 2.63104557991027832, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+78, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3172.166748046875, -690, 301.38623046875, 4.442363739013671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+79, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3137.942626953125, -692.140625, 300.382080078125, 1.803129911422729492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+80, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3109.998291015625, -711.39410400390625, 326.361785888671875, 2.692724227905273437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+81, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3176.677001953125, -687.25518798828125, 301.503326416015625, 4.284981727600097656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+82, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3182.22314453125, -692, 301.365386962890625, 3.713284969329833984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+83, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3175.37939453125, -729.02606201171875, 380.78082275390625, 5.98911285400390625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+84, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3162.584228515625, -685.62677001953125, 301.615966796875, 5.148231029510498046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+85, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3185.40185546875, -703.67535400390625, 311.3604736328125, 1.803129911422729492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+86, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3170.603271484375, -701.592041015625, 314.765380859375, 0.098666921257972717, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+87, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3124.142333984375, -727.77081298828125, 341.532318115234375, 0.120946928858757019, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+88, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3187.56591796875, -697.3819580078125, 301.4295654296875, 3.319091320037841796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+89, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3182.98876953125, -684.9757080078125, 304.232269287109375, 3.312250137329101562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+90, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3142.993896484375, -704.4149169921875, 375.726318359375, 5.231370925903320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+91, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3120.036376953125, -708.1024169921875, 325.708770751953125, 2.41710209846496582, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+92, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3118.0390625, -730.1788330078125, 300.243408203125, 2.92035222053527832, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+93, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3172.9228515625, -682.15277099609375, 304.186798095703125, 3.654000759124755859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+94, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3180.487060546875, -690.467041015625, 310.37353515625, 4.43589019775390625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+95, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3181.786376953125, -714.51214599609375, 304.23779296875, 2.047478675842285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+96, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3139.791748046875, -691.8211669921875, 299.73406982421875, 0.545274257659912109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+97, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3166.259521484375, -707.14581298828125, 300.77691650390625, 2.416874170303344726, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+98, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3126.61376953125, -678.9444580078125, 300.9949951171875, 5.231370925903320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+99, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3177.64404296875, -686.8350830078125, 312.035400390625, 3.508243799209594726, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+100, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3105.61279296875, -711.8194580078125, 305.6153564453125, 4.161460399627685546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+101, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3118.4375, -731.8038330078125, 326.337982177734375, 5.284794330596923828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+102, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3181.828125, -706.701416015625, 301.491851806640625, 2.400733232498168945, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+103, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3186.817626953125, -692.28643798828125, 301.453521728515625, 3.560613870620727539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+104, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3117.354248046875, -710.54864501953125, 341.450836181640625, 0.120946928858757019, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+105, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3166.201416015625, -722.23956298828125, 299.778076171875, 2.404274225234985351, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+106, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3135.59033203125, -746.73089599609375, 324.97235107421875, 4.764931201934814453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+107, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3122.829833984375, -712.82989501953125, 332.80322265625, 1.062540531158447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+108, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3189.553955078125, -695.75, 304.306304931640625, 3.436961650848388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+109, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3119.9375, -716.21875, 335.516082763671875, 0.543004155158996582, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+110, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3087.2119140625, -734.546875, 332.558624267578125, 4.243958950042724609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+111, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3081.15625, -728.24652099609375, 306.1644287109375, 0.294585555791854858, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+112, 66795, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3083.5546875, -734.39410400390625, 304.306610107421875, 0.646560132503509521, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Gunship Fire Bunny (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+113, 67129, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3139.744873046875, -750.107666015625, 301.575836181640625, 1.914035201072692871, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Rapelling Manfred (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@CGUID+114, 67129, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3167.6484375, -738.07293701171875, 301.826324462890625, 1.914035201072692871, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Rapelling Manfred (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+115, 67129, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3155.197021484375, -743.279541015625, 300.9739990234375, 1.956923246383666992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Rapelling Manfred (Area: Hellscream's Fist - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+116, 67131, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3142.599853515625, -683.42706298828125, 300.86077880859375, 5.195370674133300781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608), -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject2 (Auras: 131992 - Rappelling Rope Aura)
(@CGUID+117, 67131, 870, 5785, 6525, '0', 1867, 0, 1076, 0, 0, 3129.830810546875, -687.6632080078125, 300.317626953125, 5.110759735107421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58608); -- Hellscream's Vanguard (Area: Hellscream's Fist - Difficulty: 0) CreateObject2 (Auras: 131992 - Rappelling Rope Aura)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+117;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '132224'), -- Generic Controller Bunny (CSA) - 132224 - FX_Hordegunship_Idle_Loop
(@CGUID+5, 0, 0, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sky Master Corpora
(@CGUID+6, 0, 0, 0, 0, 0, 1, 1, 27, 0, 0, 0, 0, ''), -- Kor'kron Shin
(@CGUID+7, 0, 0, 8, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Kor'kron Dubs
(@CGUID+9, 0, 0, 8, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Kor'kron Spisak
(@CGUID+12, 0, 0, 0, 0, 0, 1, 1, 69, 0, 0, 0, 0, ''), -- Cannoneer Powell
(@CGUID+14, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Shikyo
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 233, 0, 0, 0, 0, ''); -- Hellscream's Fist Engineer

-- Paths
SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 66793;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3178.8618, -702.70557, 301.17157, NULL, 0),
(@PATH, 1, 3178.6392, -702.54987, 301.3298, NULL, 0),
(@PATH, 2, 3177.5269, -701.7727, 301.33267, NULL, 0),
(@PATH, 3, 3177.304, -701.6169, 301.18817, NULL, 0),
(@PATH, 4, 3170.6868, -696.99304, 301.08566, NULL, 0),
(@PATH, 5, 3169.314, -696.40295, 301.0619, NULL, 0),
(@PATH, 6, 3167.8577, -695.7771, 301.21216, NULL, 0),
(@PATH, 7, 3166.8577, -695.3472, 301.0619, NULL, 0),
(@PATH, 8, 3164.216, -695.658, 301.03152, NULL, 2500),
(@PATH, 9, 3179.954, -703.46875, 301.2275, NULL, 150),
(@PATH, 10, 3179.954, -703.46875, 301.2275, 5.767270088195800781, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+34;
SET @ENTRY := 66793;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3174.6926, -702.47394, 301.12518, NULL, 2500),
(@PATH, 1, 3174.6814, -691.76215, 301.203, NULL, 150),
(@PATH, 2, 3174.6814, -691.76215, 301.203, 1.339192628860473632, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+35;
SET @ENTRY := 66793;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3177.2258, -702.78125, 301.3175, NULL, 2500),
(@PATH, 1, 3181.3628, -698.69617, 301.35123, NULL, 150),
(@PATH, 2, 3181.3628, -698.69617, 301.35123, 0.779110968112945556, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 66793;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3164.4626, -696.5035, 300.95416, NULL, 2500),
(@PATH, 1, 3179.0852, -693.5833, 301.25284, NULL, 150),
(@PATH, 2, 3179.0852, -693.5833, 301.25284, 0.197102010250091552, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+37;
SET @ENTRY := 66793;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3164.1963, -697.38544, 300.9001, NULL, 2500),
(@PATH, 1, 3172.8706, -710.1476, 301.26895, NULL, 150),
(@PATH, 2, 3172.8706, -710.1476, 301.26895, 5.137327194213867187, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+38;
SET @ENTRY := 66793;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3172.8706, -710.1476, 301.26895, NULL, 150),
(@PATH, 1, 3172.8706, -710.1476, 301.26895, 5.137327194213867187, 500),
(@PATH, 2, 3164.1963, -697.38544, 300.9001, NULL, 2500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+39;
SET @ENTRY := 66793;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3162.67, -718.36804, 300.3549, NULL, 0), -- Splines
(@PATH, 1, 3161.67, -717.11804, 299.3549, NULL, 0), -- Splines
(@PATH, 2, 3161.17, -716.11804, 299.3549, NULL, 0), -- Splines
(@PATH, 3, 3159.67, -713.86804, 298.3549, NULL, 0), -- Splines
(@PATH, 4, 3159.17, -713.36804, 298.1049, NULL, 0), -- Splines
(@PATH, 5, 3157.17, -710.61804, 298.1049, NULL, 0), -- Splines
(@PATH, 6, 3159.17, -709.86804, 299.1049, NULL, 0), -- Splines
(@PATH, 7, 3159.67, -709.36804, 299.3549, NULL, 0), -- Splines
(@PATH, 8, 3160.42, -708.36804, 299.6049, NULL, 0), -- Splines
(@PATH, 9, 3161.92, -706.61804, 300.3549, NULL, 0), -- Splines
(@PATH, 10, 3162.42, -706.36804, 300.6049, NULL, 0), -- Splines
(@PATH, 11, 3163.42, -705.86804, 300.6049, NULL, 0), -- Splines
(@PATH, 12, 3164.42, -705.11804, 300.8549, NULL, 0), -- Splines
(@PATH, 13, 3165.4028, -704.7222, 300.73862, NULL, 0),
(@PATH, 14, 3171.8838, -704.42017, 301.21063, NULL, 0),
(@PATH, 15, 3174.1362, -704.7726, 301.11615, NULL, 2500),
(@PATH, 16, 3173.4292, -704.7899, 301.3324, NULL, 0), -- Splines
(@PATH, 17, 3172.6792, -704.7899, 301.3324, NULL, 0), -- Splines
(@PATH, 18, 3169.6792, -704.7899, 301.3324, NULL, 0), -- Splines
(@PATH, 19, 3168.4292, -704.7899, 301.3324, NULL, 0), -- Splines
(@PATH, 20, 3168.1792, -704.7899, 301.0824, NULL, 0), -- Splines
(@PATH, 21, 3166.1792, -704.7899, 300.8324, NULL, 0), -- Splines
(@PATH, 22, 3164.9292, -705.2899, 300.8324, NULL, 0), -- Splines
(@PATH, 23, 3164.1792, -705.5399, 300.5824, NULL, 0), -- Splines
(@PATH, 24, 3163.4292, -705.7899, 300.8324, NULL, 0), -- Splines
(@PATH, 25, 3162.4292, -706.2899, 300.5824, NULL, 0), -- Splines
(@PATH, 26, 3161.4292, -706.5399, 300.3324, NULL, 0), -- Splines
(@PATH, 27, 3159.9292, -708.2899, 299.5824, NULL, 0), -- Splines
(@PATH, 28, 3159.1792, -709.2899, 299.3324, NULL, 0), -- Splines
(@PATH, 29, 3158.7222, -709.8073, 298.5486, NULL, 0),
(@PATH, 30, 3156.8486, -710.40295, 298.06348, NULL, 0), -- Splines
(@PATH, 31, 3157.3486, -710.90295, 298.06348, NULL, 0), -- Splines
(@PATH, 32, 3159.8486, -713.15295, 298.31348, NULL, 0), -- Splines
(@PATH, 33, 3160.8486, -714.15295, 298.56348, NULL, 0), -- Splines
(@PATH, 34, 3161.0986, -714.40295, 298.56348, NULL, 0), -- Splines
(@PATH, 35, 3161.5986, -715.90295, 299.31348, NULL, 0), -- Splines
(@PATH, 36, 3162.0986, -717.15295, 299.56348, NULL, 0), -- Splines
(@PATH, 37, 3162.5986, -718.40295, 300.31348, NULL, 0), -- Splines
(@PATH, 38, 3162.4368, -719.0139, 299.97116, NULL, 150),
(@PATH, 39, 3162.4368, -719.0139, 299.97116, 5.073873043060302734, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+40;
SET @ENTRY := 66793;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3115.7148, -724.29254, 300.02246, NULL, 0), -- Splines
(@PATH, 1, 3116.2148, -723.54254, 300.02246, NULL, 0), -- Splines
(@PATH, 2, 3117.4648, -722.79254, 299.52246, NULL, 0), -- Splines
(@PATH, 3, 3120.2148, -721.54254, 298.77246, NULL, 0), -- Splines
(@PATH, 4, 3123.4648, -720.04254, 297.77246, NULL, 0), -- Splines
(@PATH, 5, 3123.8196, -719.9566, 297.25766, NULL, 0),
(@PATH, 6, 3132.515, -716.4549, 296.78513, NULL, 0),
(@PATH, 7, 3143.3352, -711.94794, 296.77005, NULL, 0),
(@PATH, 8, 3153.1511, -707.7344, 297.2125, NULL, 0),
(@PATH, 9, 3162.436, -704.21594, 300.58252, NULL, 0),
(@PATH, 10, 3167.6067, -703.3403, 300.9987, NULL, 0),
(@PATH, 11, 3173.9844, -703.9583, 301.25085, NULL, 2500),
(@PATH, 12, 3172.474, -703.69446, 301.40344, NULL, 0), -- Splines
(@PATH, 13, 3171.974, -703.69446, 301.15344, NULL, 0), -- Splines
(@PATH, 14, 3169.224, -703.44446, 301.15344, NULL, 0), -- Splines
(@PATH, 15, 3168.974, -703.19446, 301.40344, NULL, 0), -- Splines
(@PATH, 16, 3167.974, -703.19446, 301.40344, NULL, 0), -- Splines
(@PATH, 17, 3167.724, -703.19446, 301.15344, NULL, 0), -- Splines
(@PATH, 18, 3164.474, -704.19446, 300.90344, NULL, 0), -- Splines
(@PATH, 19, 3163.724, -704.44446, 300.65344, NULL, 0), -- Splines
(@PATH, 20, 3162.974, -704.69446, 300.65344, NULL, 0), -- Splines
(@PATH, 21, 3161.974, -705.19446, 300.65344, NULL, 0), -- Splines
(@PATH, 22, 3161.224, -705.44446, 300.40344, NULL, 0), -- Splines
(@PATH, 23, 3155.4636, -707.43054, 297.55606, NULL, 0),
(@PATH, 24, 3146.427, -710.7153, 296.83755, NULL, 0),
(@PATH, 25, 3136.573, -714.3177, 296.76065, NULL, 0),
(@PATH, 26, 3126.1301, -718.58856, 296.88498, NULL, 0),
(@PATH, 27, 3118.7388, -721.40454, 298.67133, NULL, 0),
(@PATH, 28, 3113.567, -723.38367, 300.32114, NULL, 0),
(@PATH, 29, 3112.1104, -728.6285, 300.7873, NULL, 150),
(@PATH, 30, 3112.1104, -728.6285, 300.7873, 5.042895317077636718, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+41;
SET @ENTRY := 66793;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3123.9192, -715.2934, 297.0991, NULL, 0),
(@PATH, 1, 3119.9854, -719.2448, 298.04785, NULL, 0),
(@PATH, 2, 3112.713, -722.27405, 300.3257, NULL, 0),
(@PATH, 3, 3101.1016, -725.2031, 302.25034, NULL, 0),
(@PATH, 4, 3094.711, -723.32294, 303.12006, NULL, 0),
(@PATH, 5, 3092.75, -714.01215, 305.6346, NULL, 0),
(@PATH, 6, 3098.934, -707.6893, 309.59998, NULL, 0),
(@PATH, 7, 3104.165, -703.07294, 313.1158, NULL, 0),
(@PATH, 8, 3113.2925, -697.43054, 319.5992, NULL, 0),
(@PATH, 9, 3121.822, -693.7049, 324.84756, NULL, 0),
(@PATH, 10, 3131.1423, -691.11456, 325.53925, NULL, 0),
(@PATH, 11, 3140.802, -691.17535, 325.77365, NULL, 0),
(@PATH, 12, 3147.1077, -693.55206, 325.8339, NULL, 2500),
(@PATH, 13, 3128.9202, -690.691, 325.43625, NULL, 0),
(@PATH, 14, 3121.5183, -693.2778, 324.79327, NULL, 0),
(@PATH, 15, 3115.9636, -695.9028, 321.4212, NULL, 0),
(@PATH, 16, 3105.5842, -701.40106, 314.31802, NULL, 0),
(@PATH, 17, 3098.7683, -707.184, 309.7238, NULL, 0),
(@PATH, 18, 3091.9895, -714.5903, 305.49234, NULL, 0),
(@PATH, 19, 3089.4697, -719.05554, 303.81284, NULL, 0),
(@PATH, 20, 3097.5251, -724.1441, 302.8299, NULL, 0),
(@PATH, 21, 3106.9575, -723.21704, 301.27625, NULL, 0),
(@PATH, 22, 3114.566, -721.3125, 300.01523, NULL, 0),
(@PATH, 23, 3123.0173, -713.94794, 297.3325, NULL, 0),
(@PATH, 24, 3126.6233, -709.09894, 297.03662, NULL, 0),
(@PATH, 25, 3132.7456, -701.18054, 298.48578, NULL, 0),
(@PATH, 26, 3134.638, -698.4583, 299.4983, NULL, 150),
(@PATH, 27, 3134.638, -698.4583, 299.4983, 0.963338613510131835, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+42;
SET @ENTRY := 66793;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3096.9426, -737.90454, 303.55487, NULL, 0),
(@PATH, 1, 3101.072, -740.3455, 304.49875, NULL, 0),
(@PATH, 2, 3114.4192, -742.69617, 310.675, NULL, 0),
(@PATH, 3, 3122.9473, -742.31067, 315.249, NULL, 0),
(@PATH, 4, 3130.289, -740.6029, 319.86392, NULL, 0),
(@PATH, 5, 3138.9202, -737.96906, 324.89044, NULL, 0),
(@PATH, 6, 3146.9426, -733.0643, 325.51962, NULL, 0),
(@PATH, 7, 3153.751, -726.1441, 325.71072, NULL, 0),
(@PATH, 8, 3156.309, -720.3299, 325.7394, NULL, 2500),
(@PATH, 9, 3138.9558, -738.0617, 324.88416, NULL, 0),
(@PATH, 10, 3131.5105, -740.55383, 320.5496, NULL, 0),
(@PATH, 11, 3122.8582, -742.0617, 315.23114, NULL, 0),
(@PATH, 12, 3107.248, -742.21545, 306.58652, NULL, 0),
(@PATH, 13, 3097.6206, -739.8351, 303.764, NULL, 0),
(@PATH, 14, 3099.9565, -726.52606, 302.44708, NULL, 0),
(@PATH, 15, 3103.1848, -719.3264, 301.82843, NULL, 150),
(@PATH, 16, 3103.1848, -719.3264, 301.82843, 1.149220108985900878, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+43;
SET @ENTRY := 66793;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3108.5503, -744.44794, 307.92252, NULL, 0),
(@PATH, 1, 3115.7031, -744.65625, 311.37607, NULL, 0),
(@PATH, 2, 3123.4324, -743.9149, 315.30493, NULL, 0),
(@PATH, 3, 3131.5486, -742.2118, 320.22263, NULL, 0),
(@PATH, 4, 3139.7058, -740.22394, 324.85938, NULL, 0),
(@PATH, 5, 3146.9514, -735.77606, 325.48978, NULL, 0),
(@PATH, 6, 3152.6484, -730.02954, 325.77118, NULL, 0),
(@PATH, 7, 3156.9827, -724.3542, 325.88287, NULL, 0),
(@PATH, 8, 3157.342, -720.3299, 325.80847, NULL, 2500),
(@PATH, 9, 3153.5894, -728.4881, 325.75726, NULL, 0),
(@PATH, 10, 3153.4888, -728.7066, 325.77878, NULL, 0),
(@PATH, 11, 3149.6016, -732.8054, 325.7014, NULL, 0),
(@PATH, 12, 3147.6667, -734.8455, 325.54996, NULL, 0),
(@PATH, 13, 3139.5928, -739.7255, 324.88403, NULL, 0),
(@PATH, 14, 3130.7925, -742.30554, 319.78925, NULL, 0),
(@PATH, 15, 3123.947, -743.6424, 315.61853, NULL, 0),
(@PATH, 16, 3111.1008, -744.49304, 309.12152, NULL, 0),
(@PATH, 17, 3108.6233, -744.2309, 307.83032, NULL, 0),
(@PATH, 18, 3096.515, -740.8924, 303.94733, NULL, 0),
(@PATH, 19, 3091.7954, -737.93066, 303.79773, NULL, 0),
(@PATH, 20, 3090.639, -737.2049, 303.88928, NULL, 150),
(@PATH, 21, 3090.639, -737.2049, 303.88928, 2.581154823303222656, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+44;
SET @ENTRY := 66793;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3103.0803, -735.9983, 303.297, NULL, 0), -- Splines
(@PATH, 1, 3100.8303, -737.7483, 303.797, NULL, 0), -- Splines
(@PATH, 2, 3101.3303, -737.9983, 303.797, NULL, 0), -- Splines
(@PATH, 3, 3104.5803, -739.2483, 305.047, NULL, 0), -- Splines
(@PATH, 4, 3106.0803, -739.7483, 305.797, NULL, 0), -- Splines
(@PATH, 5, 3109.8828, -740.4583, 308.29266, NULL, 0),
(@PATH, 6, 3116.5842, -740.79517, 311.81973, NULL, 0),
(@PATH, 7, 3130.0999, -738.7726, 320.0483, NULL, 0),
(@PATH, 8, 3138.0833, -736.2969, 324.81482, NULL, 0),
(@PATH, 9, 3144.9653, -730.9774, 325.41223, NULL, 0),
(@PATH, 10, 3150.4905, -725.4549, 325.58545, NULL, 0),
(@PATH, 11, 3155.632, -719.71356, 325.67914, NULL, 2500),
(@PATH, 12, 3141.9348, -733.7066, 325.19528, NULL, 0),
(@PATH, 13, 3137.539, -735.60767, 324.70612, NULL, 0),
(@PATH, 14, 3123.4915, -740.19965, 315.80072, NULL, 0),
(@PATH, 15, 3114.8716, -740.67706, 310.8567, NULL, 0),
(@PATH, 16, 3111.1536, -740.2448, 308.9957, NULL, 0),
(@PATH, 17, 3104.2483, -739.46875, 304.67432, NULL, 0),
(@PATH, 18, 3100.716, -738.0955, 303.40298, NULL, 0),
(@PATH, 19, 3100.758, -736.3524, 303.18372, NULL, 0),
(@PATH, 20, 3100.7908, -734.99304, 303.06015, NULL, 0),
(@PATH, 21, 3101.8171, -734.2189, 302.94302, NULL, 0),
(@PATH, 22, 3102.9775, -733.34375, 302.71616, NULL, 0),
(@PATH, 23, 3105.7778, -733.5382, 302.30133, NULL, 150),
(@PATH, 24, 3105.7778, -733.5382, 302.30133, 6.213864803314208984, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+45;
SET @ENTRY := 66793;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3167.682, -695.2917, 301.34268, NULL, 0), -- Splines
(@PATH, 1, 3165.432, -697.2917, 301.34268, NULL, 0), -- Splines
(@PATH, 2, 3162.182, -699.7917, 300.84268, NULL, 0), -- Splines
(@PATH, 3, 3161.432, -700.7917, 300.84268, NULL, 0), -- Splines
(@PATH, 4, 3160.432, -701.2917, 300.59268, NULL, 0), -- Splines
(@PATH, 5, 3154.682, -704.0417, 298.09268, NULL, 0), -- Splines
(@PATH, 6, 3154.0713, -704.51044, 297.53342, NULL, 0),
(@PATH, 7, 3142.376, -708.6927, 296.8795, NULL, 0),
(@PATH, 8, 3132.7024, -712.8455, 296.77863, NULL, 0),
(@PATH, 9, 3121.843, -718.6094, 297.41663, NULL, 0),
(@PATH, 10, 3107.2466, -725.1893, 301.32214, NULL, 0),
(@PATH, 11, 3096.2249, -726.8143, 302.9845, NULL, 0),
(@PATH, 12, 3087.2048, -719.3073, 304.06464, NULL, 0),
(@PATH, 13, 3089.8862, -714.36456, 305.99255, NULL, 0),
(@PATH, 14, 3096.179, -706.9393, 308.85007, NULL, 0),
(@PATH, 15, 3104.5479, -699.8264, 314.24677, NULL, 0),
(@PATH, 16, 3104.68, -699.74603, 314.3191, NULL, 0),
(@PATH, 17, 3106.2073, -698.81757, 315.36374, NULL, 0),
(@PATH, 18, 3107.6665, -697.93036, 316.32236, NULL, 0),
(@PATH, 19, 3108.1345, -697.6458, 316.66364, NULL, 0),
(@PATH, 20, 3110.2327, -696.5301, 318.1483, NULL, 0),
(@PATH, 21, 3115.6406, -693.65454, 321.71692, NULL, 0),
(@PATH, 22, 3120.9668, -691.2051, 324.88828, NULL, 0),
(@PATH, 23, 3128.7786, -688.9948, 325.47485, NULL, 0),
(@PATH, 24, 3138.1206, -688.0156, 325.86853, NULL, 0),
(@PATH, 25, 3146.5269, -689.8507, 326.0236, NULL, 0),
(@PATH, 26, 3148.093, -693.04865, 325.89233, NULL, 2500),
(@PATH, 27, 3132.5356, -688.9531, 325.69116, NULL, 0),
(@PATH, 28, 3120.5435, -691.4132, 324.69275, NULL, 0),
(@PATH, 29, 3113.5461, -694.7205, 320.34717, NULL, 0),
(@PATH, 30, 3107.843, -697.6024, 316.51352, NULL, 0),
(@PATH, 31, 3100.2883, -703.7465, 311.44507, NULL, 0),
(@PATH, 32, 3095.343, -707.92535, 308.1361, NULL, 0),
(@PATH, 33, 3086.8655, -719.71875, 304.07944, NULL, 0),
(@PATH, 34, 3089.4436, -724.5781, 303.60257, NULL, 0),
(@PATH, 35, 3104.639, -725.6268, 301.69766, NULL, 0),
(@PATH, 36, 3113.2588, -723.0208, 300.33487, NULL, 0),
(@PATH, 37, 3122.192, -719.0347, 297.3768, NULL, 0),
(@PATH, 38, 3132.7014, -713.2917, 296.7661, NULL, 0),
(@PATH, 39, 3142.0166, -709.1268, 296.8654, NULL, 0),
(@PATH, 40, 3152.6963, -704.9149, 297.3709, NULL, 0),
(@PATH, 41, 3161.1868, -701.86115, 300.54065, NULL, 0),
(@PATH, 42, 3170.2925, -693.07294, 301.15195, NULL, 150),
(@PATH, 43, 3170.2925, -693.07294, 301.15195, 0.88222593069076538, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+46;
SET @ENTRY := 66793;
SET @PATHOFFSET := 13;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3146.692, -695.90625, 325.68912, NULL, 2500),
(@PATH, 1, 3131.1614, -705.1893, 324.9966, NULL, 150),
(@PATH, 2, 3131.1614, -705.1893, 324.9966, 3.827762603759765625, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+47;
SET @ENTRY := 66793;
SET @PATHOFFSET := 14;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3175.962, -678.2292, 328.22104, NULL, 0),
(@PATH, 1, 3166.4993, -678.6389, 327.57764, NULL, 0),
(@PATH, 2, 3157.9072, -681.25867, 327.1335, NULL, 0),
(@PATH, 3, 3153.843, -685.73785, 326.55307, NULL, 0),
(@PATH, 4, 3149.6077, -693.44446, 325.9166, NULL, 2500),
(@PATH, 5, 3158.1362, -681.27954, 327.14215, NULL, 0),
(@PATH, 6, 3175.7048, -678.2882, 328.19913, NULL, 0),
(@PATH, 7, 3185.4314, -679.5278, 329.1588, NULL, 0),
(@PATH, 8, 3192.9749, -682.17365, 330.14795, NULL, 0),
(@PATH, 9, 3195.5295, -685.441, 330.20355, NULL, 150),
(@PATH, 10, 3195.5295, -685.441, 330.20355, 5.37598419189453125, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+48;
SET @ENTRY := 66793;
SET @PATHOFFSET := 15;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3189.6416, -712.1215, 328.2832, NULL, 0),
(@PATH, 1, 3181.244, -719.30206, 327.54248, NULL, 0),
(@PATH, 2, 3173.381, -722.2847, 327.11417, NULL, 0),
(@PATH, 3, 3164.131, -722.9722, 326.32675, NULL, 0),
(@PATH, 4, 3158.6946, -719.92706, 325.889, NULL, 2500),
(@PATH, 5, 3167.3315, -720.9036, 326.68097, NULL, 0), -- Splines
(@PATH, 6, 3169.5815, -721.4036, 326.93097, NULL, 0), -- Splines
(@PATH, 7, 3172.0815, -721.9036, 327.18097, NULL, 0), -- Splines
(@PATH, 8, 3179.9688, -719.8802, 327.47293, NULL, 0),
(@PATH, 9, 3186.6746, -715.1875, 327.9659, NULL, 0),
(@PATH, 10, 3193.087, -709.2726, 328.72906, NULL, 0),
(@PATH, 11, 3196.8135, -704.05554, 329.39456, NULL, 0),
(@PATH, 12, 3198.7605, -699.6875, 329.98904, NULL, 150),
(@PATH, 13, 3198.7605, -699.6875, 329.98904, 1.151488661766052246, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

SET @MOVERGUID := @CGUID+49;
SET @ENTRY := 66793;
SET @PATHOFFSET := 16;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, NULL, 'Hellscream''s Fist Engineer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3144.7744, -729.7483, 325.4256, NULL, 0), -- Splines
(@PATH, 1, 3149.6362, -724.7622, 325.77582, NULL, 0), -- Splines
(@PATH, 2, 3151.8862, -722.2622, 325.77582, NULL, 0), -- Splines
(@PATH, 3, 3152.3862, -721.5122, 325.77582, NULL, 0), -- Splines
(@PATH, 4, 3154.9983, -719.27606, 325.62607, NULL, 2500),
(@PATH, 5, 3151.842, -722.5017, 325.69995, NULL, 0), -- Splines
(@PATH, 6, 3146.1843, -728.13086, 325.6704, NULL, 0), -- Splines
(@PATH, 7, 3144.1843, -729.13086, 325.6704, NULL, 0), -- Splines
(@PATH, 8, 3142.6843, -729.88086, 325.4204, NULL, 0), -- Splines
(@PATH, 9, 3139.4343, -729.88086, 325.1704, NULL, 0), -- Splines
(@PATH, 10, 3135.9697, -728.6094, 324.86078, NULL, 150),
(@PATH, 11, 3135.9697, -728.6094, 324.86078, 2.322982549667358398, 500);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+54;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 191640, 870, 5785, 6525, '0', 1867, 0, 1076, 3171.574951171875, -684.0234375, 301.584747314453125, 4.61110687255859375, -0.00413036346435546, 0.004570960998535156, -0.74197959899902343, 0.670394182205200195, 120, 255, 1, 58608), -- Anvil (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+1, 200296, 870, 5785, 6525, '0', 1867, 0, 1076, 3162.55126953125, -696.40972900390625, 300.819610595703125, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Washing Tub (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+2, 200296, 870, 5785, 6525, '0', 1867, 0, 1076, 3175.835205078125, -704.44268798828125, 301.161102294921875, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Washing Tub (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+3, 200296, 870, 5785, 6525, '0', 1867, 0, 1076, 3148.170166015625, -695.2430419921875, 325.78997802734375, 3.503525257110595703, 0, 0, -0.98367023468017578, 0.179980158805847167, 120, 255, 1, 58608), -- Washing Tub (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+4, 200296, 870, 5785, 6525, '0', 1867, 0, 1076, 3156.974853515625, -718.4930419921875, 325.77508544921875, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Washing Tub (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+5, 215689, 870, 5785, 6525, '0', 1867, 0, 1076, 3154.564208984375, -742.4375, 300.90399169921875, 2.427403450012207031, 0, 0, 0.936916351318359375, 0.349553614854812622, 120, 255, 1, 58608), -- Rappelling Rope (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+6, 215689, 870, 5785, 6525, '0', 1867, 0, 1076, 3166.864501953125, -737.23956298828125, 301.774078369140625, 2.512194633483886718, 0, 0, 0.95088958740234375, 0.309530258178710937, 120, 255, 1, 58608), -- Rappelling Rope (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+7, 215689, 870, 5785, 6525, '0', 1867, 0, 1076, 3135.21875, -748.388916015625, 301.812347412109375, 2.113138675689697265, 0, 0, 0.870673179626464843, 0.491861999034881591, 120, 255, 1, 58608), -- Rappelling Rope (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+8, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3181.0087890625, -689.02081298828125, 330.96807861328125, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+9, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3127.642333984375, -708.09027099609375, 326.574127197265625, 1.877011895179748535, 0.591058731079101562, 0.806253433227539062, -0.02440738677978515, 0.003039526287466287, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+10, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3184.202392578125, -701.47052001953125, 330.6539306640625, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+11, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3103.890625, -735.19268798828125, 303.491973876953125, 2.253200769424438476, -0.42945289611816406, -0.89914321899414062, 0.081819534301757812, 0.020426269620656967, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+12, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3165.697998046875, -706.11456298828125, 301.37823486328125, 1.831625938415527343, 0.607793807983398437, 0.79107666015625, 0.056016921997070312, 0.040577318519353866, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+13, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3133.264892578125, -722.90277099609375, 326.51202392578125, 1.877011895179748535, 0.591058731079101562, 0.806253433227539062, -0.02440738677978515, 0.003039526287466287, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+14, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3121.817626953125, -737.47052001953125, 326.558380126953125, 1.751460552215576171, -0.63903284072875976, -0.76787757873535156, 0.00095367431640625, 0.044723071157932281, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+15, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3163.04248046875, -698.375, 301.38116455078125, 1.448637366294860839, 0.748787403106689453, 0.661646842956542968, 0.036532402038574218, 0.014362857677042484, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+16, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3151.09716796875, -697.796875, 330.212066650390625, 2.020828485488891601, 0.506585121154785156, 0.824388504028320312, 0.193157196044921875, 0.162620559334754943, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+17, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3109.509521484375, -704.67535400390625, 326.539825439453125, 1.900437831878662109, 0.581652164459228515, 0.812654495239257812, -0.03504371643066406, 0.006739342585206031, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+18, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3137.111083984375, -688.060791015625, 310.185455322265625, 3.606259584426879882, -0.29188251495361328, 0.728184700012207031, 0.620077133178710937, 0.007485209964215755, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+19, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3125.2978515625, -692.61285400390625, 310.185455322265625, 3.606259584426879882, -0.29188251495361328, 0.728184700012207031, 0.620077133178710937, 0.007485209964215755, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+20, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3141.94091796875, -735.9774169921875, 310.05841064453125, 0.449155539274215698, 0.730448246002197265, 0.28617095947265625, -0.01221275329589843, 0.620001971721649169, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+21, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3097.635498046875, -718.5069580078125, 303.531158447265625, 1.857052564620971679, -0.59472131729125976, -0.79787254333496093, 0.067020416259765625, 0.072209104895591735, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+22, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3157.525146484375, -714.7274169921875, 330.172210693359375, 2.00492715835571289, 0.517224311828613281, 0.825951576232910156, 0.165752410888671875, 0.151026785373687744, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+23, 215711, 870, 5785, 6525, '0', 1867, 0, 1076, 3153.6806640625, -731.41143798828125, 310.300933837890625, 0.449155539274215698, 0.730448246002197265, 0.28617095947265625, -0.01221275329589843, 0.620001971721649169, 120, 255, 1, 58608), -- Hellscream's Fist Alarm (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+24, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3166.013916015625, -722.045166015625, 299.729522705078125, 3.50999617576599121, 0, 0, -0.98308277130126953, 0.18316178023815155, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+25, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3197.603271484375, -691.59375, 330.079010009765625, 2.214626312255859375, 0, 0, 0.894500732421875, 0.447066485881805419, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+26, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3199.046875, -691.7882080078125, 330.15478515625, 1.684982180595397949, 0, 0, 0.746303558349609375, 0.665605723857879638, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+27, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3119.471435546875, -708.20831298828125, 325.617095947265625, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+28, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3164.4931640625, -723.82464599609375, 300.076141357421875, 1.851815342903137207, 0, 0, 0.799166679382324218, 0.601109445095062255, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+29, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3083.494873046875, -733.82464599609375, 304.19873046875, 1.395388007164001464, 0, 0, 0.642452239990234375, 0.766325712203979492, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+30, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3084.8134765625, -733.76043701171875, 304.09393310546875, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+31, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3139.848876953125, -711.125, 325.17987060546875, 5.813859462738037109, 0, 0, -0.23251533508300781, 0.972592711448669433, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+32, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3139.193603515625, -709.78472900390625, 325.172210693359375, 2.214626312255859375, 0, 0, 0.894500732421875, 0.447066485881805419, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+33, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3143.880126953125, -727.40277099609375, 325.339752197265625, 6.186269283294677734, 0, 0, -0.04843902587890625, 0.998826146125793457, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+34, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3140.63720703125, -709.97918701171875, 325.222564697265625, 1.684982180595397949, 0, 0, 0.746303558349609375, 0.665605723857879638, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+35, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3138.5390625, -691.57464599609375, 299.624053955078125, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+36, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3081.545166015625, -728.0711669921875, 305.49896240234375, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+37, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3166.239501953125, -723.46356201171875, 299.715240478515625, 2.385704517364501953, 0, 0, 0.929425239562988281, 0.369010448455810546, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+38, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3199.72998046875, -693.232666015625, 330.21343994140625, 5.141817092895507812, 0, 0, -0.5402078628540039, 0.841531574726104736, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+39, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3142.576416015625, -728.00518798828125, 325.287445068359375, 2.455902576446533203, 0, 0, 0.941802024841308593, 0.336167991161346435, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+40, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3082.193603515625, -727.29339599609375, 304.240631103515625, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+41, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3201.286376953125, -690.88714599609375, 330.27447509765625, 1.75868844985961914, 0, 0, 0.770320892333984375, 0.637656450271606445, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+42, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3198.2587890625, -692.93402099609375, 330.1376953125, 5.813859462738037109, 0, 0, -0.23251533508300781, 0.972592711448669433, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+43, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3139.966064453125, -691.17364501953125, 299.660430908203125, 4.978403568267822265, 0, 0, -0.60708808898925781, 0.794634580612182617, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+44, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3082.23095703125, -728.7586669921875, 304.2330322265625, 0.685652434825897216, 0, 0, 0.336150169372558593, 0.94180840253829956, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+45, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3124.9931640625, -736.95489501953125, 300.06011962890625, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+46, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3120.952392578125, -708.2725830078125, 325.635040283203125, 2.455902576446533203, 0, 0, 0.941802024841308593, 0.336167991161346435, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+47, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3137.1884765625, -692.2586669921875, 299.58697509765625, 1.435833096504211425, 0, 0, 0.657816886901855468, 0.753177881240844726, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+48, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3117.064208984375, -728.78643798828125, 300.195281982421875, 3.678322792053222656, 0, 0, -0.96420574188232421, 0.265155255794525146, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+49, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3084.217041015625, -734.92706298828125, 304.19952392578125, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+50, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3138.439208984375, -693.0625, 299.608642578125, 4.978403568267822265, 0, 0, -0.60708808898925781, 0.794634580612182617, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+51, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3142.56689453125, -726.55731201171875, 325.261138916015625, 2.42987370491027832, 0, 0, 0.937347412109375, 0.348396122455596923, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+52, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3200.40185546875, -691.9913330078125, 330.22613525390625, 3.477173566818237304, 0, 0, -0.98595619201660156, 0.167004138231277465, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+53, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3117.802001953125, -729.97052001953125, 300.191314697265625, 0, 0, 0, 0, 1, 120, 255, 1, 58608), -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1
(@OGUID+54, 215718, 870, 5785, 6525, '0', 1867, 0, 1076, 3118.109375, -731.2882080078125, 300.410552978515625, 2.987270116806030273, 0, 0, 0.9970245361328125, 0.077084675431251525, 120, 255, 1, 58608); -- Hellscream's Fist Fuel Cell (Area: Hellscream's Fist - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+54;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.182235538959503173, 0.983254969120025634, 0, 0); -- Anvil

-- Smart scripts
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (55135, 64869, 64872, 66793, 66795, 67131);

DELETE FROM `smart_scripts` WHERE `entryorguid`=55135 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(55135,0,0,0,'',11,0,100,0,0,0,0,0,0,'',11,46905,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'General Nazgrim - On respawn - Cast ''Summon Collision Object''');

DELETE FROM `smart_scripts` WHERE `entryorguid`=64869 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(64869,0,0,0,'',1,0,100,0,0,1200,3600,4800,0,'',10,1,5,6,273,274,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Kor''kron Jo''mag - Out of combat (3.6s-4.8s) - Play random emote');

DELETE FROM `smart_scripts` WHERE `entryorguid`=64872 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(64872,0,0,0,'',1,0,100,0,0,1200,3600,4800,0,'',10,1,5,6,273,274,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Sky Marshal Schwind - Out of combat (3.6s-4.8s) - Play random emote');

SET @ENTRY := 66793;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
SET @ACTIONLIST := 66793 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=66793 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ACTIONLIST+0, @ACTIONLIST+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66793,0,0,0,'',40,0,100,0,8,@PATH+0,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 1 node 8 reached - Call timed actionlist 1'),
(66793,0,1,0,'',40,0,100,0,10,@PATH+0,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 1 node 10 reached - Call timed actionlist 2'),
(66793,0,2,0,'',40,0,100,0,0,@PATH+1,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 2 node 0 reached - Call timed actionlist 1'),
(66793,0,3,0,'',40,0,100,0,2,@PATH+1,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 2 node 2 reached - Call timed actionlist 2'),
(66793,0,4,0,'',40,0,100,0,0,@PATH+2,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 3 node 0 reached - Call timed actionlist 1'),
(66793,0,5,0,'',40,0,100,0,2,@PATH+2,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 3 node 2 reached - Call timed actionlist 2'),
(66793,0,6,0,'',40,0,100,0,0,@PATH+3,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 4 node 0 reached - Call timed actionlist 1'),
(66793,0,7,0,'',40,0,100,0,2,@PATH+3,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 4 node 2 reached - Call timed actionlist 2'),
(66793,0,8,0,'',40,0,100,0,0,@PATH+4,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 5 node 0 reached - Call timed actionlist 1'),
(66793,0,9,0,'',40,0,100,0,2,@PATH+4,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 5 node 2 reached - Call timed actionlist 2'),
(66793,0,10,0,'',40,0,100,0,1,@PATH+5,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 6 node 1 reached - Call timed actionlist 2'),
(66793,0,11,0,'',40,0,100,0,2,@PATH+5,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 6 node 2 reached - Call timed actionlist 1'),
(66793,0,12,0,'',40,0,100,0,15,@PATH+6,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 7 node 15 reached - Call timed actionlist 1'),
(66793,0,13,0,'',40,0,100,0,39,@PATH+6,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 7 node 39 reached - Call timed actionlist 2'),
(66793,0,14,0,'',40,0,100,0,11,@PATH+7,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 8 node 11 reached - Call timed actionlist 1'),
(66793,0,15,0,'',40,0,100,0,30,@PATH+7,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 8 node 30 reached - Call timed actionlist 2'),
(66793,0,16,0,'',40,0,100,0,12,@PATH+8,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 9 node 12 reached - Call timed actionlist 1'),
(66793,0,17,0,'',40,0,100,0,27,@PATH+8,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 9 node 27 reached - Call timed actionlist 2'),
(66793,0,18,0,'',40,0,100,0,8,@PATH+9,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 10 node 8 reached - Call timed actionlist 1'),
(66793,0,19,0,'',40,0,100,0,16,@PATH+9,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 10 node 16 reached - Call timed actionlist 2'),
(66793,0,20,0,'',40,0,100,0,8,@PATH+10,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 11 node 8 reached - Call timed actionlist 1'),
(66793,0,21,0,'',40,0,100,0,21,@PATH+10,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 11 node 21 reached - Call timed actionlist 2'),
(66793,0,22,0,'',40,0,100,0,11,@PATH+11,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 12 node 11 reached - Call timed actionlist 1'),
(66793,0,23,0,'',40,0,100,0,24,@PATH+11,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 12 node 24 reached - Call timed actionlist 2'),
(66793,0,24,0,'',40,0,100,0,26,@PATH+12,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 13 node 26 reached - Call timed actionlist 1'),
(66793,0,25,0,'',40,0,100,0,43,@PATH+12,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 13 node 43 reached - Call timed actionlist 2'),
(66793,0,26,0,'',40,0,100,0,0,@PATH+13,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 14 node 0 reached - Call timed actionlist 1'),
(66793,0,27,0,'',40,0,100,0,2,@PATH+13,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 14 node 2 reached - Call timed actionlist 2'),
(66793,0,28,0,'',40,0,100,0,4,@PATH+14,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 15 node 4 reached - Call timed actionlist 1'),
(66793,0,29,0,'',40,0,100,0,10,@PATH+14,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 15 node 10 reached - Call timed actionlist 2'),
(66793,0,30,0,'',40,0,100,0,4,@PATH+15,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 16 node 4 reached - Call timed actionlist 1'),
(66793,0,31,0,'',40,0,100,0,13,@PATH+15,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 16 node 13 reached - Call timed actionlist 2'),
(66793,0,32,0,'',40,0,100,0,4,@PATH+16,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 17 node 4 reached - Call timed actionlist 1'),
(66793,0,33,0,'',40,0,100,0,11,@PATH+16,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Fist Engineer - On cosmetic path 17 node 11 reached - Call timed actionlist 2'),
(@ACTIONLIST+0,9,0,0,'',0,0,100,0,0,0,0,0,0,'',5,432,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Play emote'),
(@ACTIONLIST+0,9,1,0,'',0,0,100,0,1500,1500,0,0,0,'',71,2,1,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Set equipment'),
(@ACTIONLIST+1,9,0,0,'',0,0,100,0,50,50,0,0,0,'',11,131202,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Cast ''Douse Flames'''),
(@ACTIONLIST+1,9,1,0,'',0,0,100,0,0,0,0,0,0,'',71,0,1,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Fist Engineer - Remove equipment');

SET @ACTIONLIST := 66795 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=66795 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ACTIONLIST AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66795,0,0,0,'',1,0,100,0,0,12000,11000,12000,0,'',80,@ACTIONLIST+0,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Gunship Fire Bunny - Out of combat (11s-12s) - Call timed actionlist'),
(@ACTIONLIST+0,9,0,0,'',0,0,100,0,0,0,0,0,0,'',137,29458,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Gunship Fire Bunny - Play spell visual kit 29458'),
(@ACTIONLIST+0,9,1,0,'',0,0,100,0,0,0,0,0,0,'',137,29457,4,8000,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Gunship Fire Bunny - Play spell visual kit 29457');

UPDATE `creature` SET `StringId`='JumpFirstPosition' WHERE `guid`=@CGUID+116 AND `id`=67131;
UPDATE `creature` SET `StringId`='JumpSecondPosition' WHERE `guid`=@CGUID+117 AND `id`=67131;

SET @ENTRY := 67131;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
SET @ACTIONLIST := 67131 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=67131 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` BETWEEN @ACTIONLIST+0 AND @ACTIONLIST+1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(67131,0,0,0,'',11,0,100,0,0,0,0,0,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Vanguard - On respawn - Call timed actionlist 1'),
(67131,0,1,0,'',11,0,100,0,0,0,0,0,0,'',80,@ACTIONLIST+1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Hellscream''s Vanguard - On respawn - Call timed actionlist 2'),
(@ACTIONLIST+0,9,0,0,'',0,0,100,0x20,0,0,0,0,0,'',53,0,@PATH+0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Start scripted path 1'),
(@ACTIONLIST+0,9,1,0,'',0,0,100,0x20,250,250,0,0,0,'',97,8,0,0,1,1,0,0,NULL,8,0,0,0,0,NULL,3170.39,-740.576,295,0,'Actionlist - Hellscream''s Vanguard - Jump to position 1'),
(@ACTIONLIST+0,9,2,0,'',0,0,100,0,0,0,0,0,0,'',11,131992,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Cast ''Rappelling Rope Aura'''),
(@ACTIONLIST+0,9,3,0,'',0,0,100,0,0,0,0,0,0,'',60,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Disable gravity'),
(@ACTIONLIST+0,9,4,0,'',0,0,100,0,0,0,0,0,0,'',128,2357,1,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Set AI anim kit 2357'),
(@ACTIONLIST+0,9,5,0,'',0,0,100,0x20,50,50,0,0,0,'',114,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,-55,0,'Actionlist - Hellscream''s Vanguard - Move offset'),
(@ACTIONLIST+0,9,6,0,'',0,0,100,0,0,0,0,0,0,'',28,131992,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Remove aura ''Rappelling Rope Aura'''),
(@ACTIONLIST+0,9,7,0,'',0,0,100,0,0,0,0,0,0,'',128,0,1,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Remove AI anim kit'),
(@ACTIONLIST+0,9,8,0,'',0,0,100,0x20,50,50,0,0,0,'',97,8,0,0,1,2,0,0,NULL,8,0,0,0,0,NULL,3168.45,-734.832,230.641,0,'Actionlist - Hellscream''s Vanguard - Jump to position 2'),
(@ACTIONLIST+0,9,9,0,'',0,0,100,0,0,0,0,0,0,'',60,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Enable gravity'),
(@ACTIONLIST+0,9,10,0,'',0,0,100,0,0,0,0,0,0,'',11,132002,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Cast ''Fiery Explosion w/ Projectile'''),
(@ACTIONLIST+0,9,11,0,'',0,0,100,0x20,0,0,0,0,0,'',53,0,@PATH+1,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Start scripted path 2'),
(@ACTIONLIST+0,9,12,0,'',0,0,100,0,0,0,0,0,0,'',11,130966,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Cast ''Permanent Feign Death'''),
(@ACTIONLIST+0,9,13,0,'',0,0,100,0,5000,5000,0,0,0,'',41,0,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Despawn'),
(@ACTIONLIST+1,9,0,0,'',0,0,100,0x20,0,0,0,0,0,'',53,0,@PATH+2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Start scripted path 1'),
(@ACTIONLIST+1,9,1,0,'',0,0,100,0x20,250,250,0,0,0,'',97,8,0,0,1,1,0,0,NULL,8,0,0,0,0,NULL,3157.64,-745.943,290,0,'Actionlist - Hellscream''s Vanguard - Jump to position 1'),
(@ACTIONLIST+1,9,2,0,'',0,0,100,0,0,0,0,0,0,'',11,131992,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Cast ''Rappelling Rope Aura'''),
(@ACTIONLIST+1,9,3,0,'',0,0,100,0,0,0,0,0,0,'',60,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Disable gravity'),
(@ACTIONLIST+1,9,4,0,'',0,0,100,0,0,0,0,0,0,'',128,2357,1,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Set AI anim kit 2357'),
(@ACTIONLIST+1,9,5,0,'',0,0,100,0x20,50,50,0,0,0,'',114,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,-55,0,'Actionlist - Hellscream''s Vanguard - Move offset'),
(@ACTIONLIST+1,9,6,0,'',0,0,100,0,0,0,0,0,0,'',28,131992,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Remove aura ''Rappelling Rope Aura'''),
(@ACTIONLIST+1,9,7,0,'',0,0,100,0,0,0,0,0,0,'',128,0,1,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Remove AI anim kit'),
(@ACTIONLIST+1,9,8,0,'',0,0,100,0x20,50,50,0,0,0,'',97,8,0,0,1,2,0,0,NULL,8,0,0,0,0,NULL,3155.6,-747.953,227.616,0,'Actionlist - Hellscream''s Vanguard - Jump to position 2'),
(@ACTIONLIST+1,9,9,0,'',0,0,100,0,0,0,0,0,0,'',60,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Enable gravity'),
(@ACTIONLIST+1,9,10,0,'',0,0,100,0,0,0,0,0,0,'',11,132002,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Cast ''Fiery Explosion w/ Projectile'''),
(@ACTIONLIST+1,9,11,0,'',0,0,100,0x20,0,0,0,0,0,'',53,0,@PATH+3,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Start scripted path 2'),
(@ACTIONLIST+1,9,12,0,'',0,0,100,0,0,0,0,0,0,'',11,130966,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Cast ''Permanent Feign Death'''),
(@ACTIONLIST+1,9,13,0,'',0,0,100,0,5000,5000,0,0,0,'',41,0,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Hellscream''s Vanguard - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=67131;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,67131,0,0,58,1,0,0,0,'JumpFirstPosition',0,0,0,'','Trigger smart event if object has StringId ''JumpFirstPosition'''),
(22,2,67131,0,0,58,1,0,0,0,'JumpSecondPosition',0,0,0,'','Trigger smart event if object has StringId ''JumpSecondPosition''');

DELETE FROM `waypoint_path` WHERE `PathId` BETWEEN @PATH+0 AND @PATH+3;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH+0, 1, 0, NULL, 'Hellscream''s Vanguard - Scripted Path'),
(@PATH+1, 1, 0x2, NULL, 'Hellscream''s Vanguard - Scripted Path'),
(@PATH+2, 1, 0, NULL, 'Hellscream''s Vanguard - Scripted Path'),
(@PATH+3, 1, 0x2, NULL, 'Hellscream''s Vanguard - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId` BETWEEN @PATH+0 AND @PATH+3;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH+0, 0, 3151.1711, -705.7292, 297.06512, NULL, 0),
(@PATH+0, 1, 3155.2449, -714.8472, 297.46194, NULL, 0),
(@PATH+0, 2, 3161.8672, -733.2222, 300.83136, NULL, 0),
(@PATH+0, 3, 3164.1223, -739.0208, 301.52005, NULL, 0),
(@PATH+1, 0, 3169.2861, -735.52277, 231.31735, NULL, 0), -- Splines
(@PATH+1, 1, 3170.7861, -737.02277, 231.31735, NULL, 0), -- Splines
(@PATH+1, 2, 3171.0361, -737.52277, 231.31735, NULL, 0), -- Splines
(@PATH+1, 3, 3171.7861, -738.27277, 231.56735, NULL, 0), -- Splines
(@PATH+1, 4, 3173.2861, -739.52277, 231.56735, NULL, 0), -- Splines
(@PATH+1, 5, 3174.2861, -741.77277, 231.56735, NULL, 0), -- Splines
(@PATH+1, 6, 3176.0361, -745.02277, 231.56735, NULL, 0), -- Splines
(@PATH+1, 7, 3176.7861, -746.27277, 231.56735, NULL, 0), -- Splines
(@PATH+1, 8, 3179.5361, -746.77277, 231.81735, NULL, 0), -- Splines
(@PATH+1, 9, 3180.2861, -747.02277, 231.81735, NULL, 0), -- Splines
(@PATH+1, 10, 3181.2861, -747.27277, 232.06735, NULL, 0), -- Splines
(@PATH+1, 11, 3185.2861, -748.27277, 232.06735, NULL, 0), -- Splines
(@PATH+1, 12, 3186.0361, -748.52277, 232.31735, NULL, 0), -- Splines
(@PATH+1, 13, 3189.0361, -749.27277, 232.81735, NULL, 0), -- Splines
(@PATH+1, 14, 3190.0361, -749.52277, 233.06735, NULL, 0), -- Splines
(@PATH+1, 15, 3191.6223, -750.21356, 232.94028, NULL, 0),
(@PATH+1, 16, 3202.1467, -750.9167, 236.5856, NULL, 0),
(@PATH+2, 0, 3139.429, -711.42017, 296.791, NULL, 0),
(@PATH+2, 1, 3144.4263, -724.0191, 298.72473, NULL, 0),
(@PATH+2, 2, 3146.837, -731.63196, 300.1581, NULL, 0),
(@PATH+2, 3, 3149.3489, -738.36456, 300.2587, NULL, 0),
(@PATH+2, 4, 3153.4749, -742.21356, 300.93054, NULL, 0),
(@PATH+3, 0, 3173.362, -758.5035, 227.64145, NULL, 0),
(@PATH+3, 1, 3189.7388, -763.7483, 227.32822, NULL, 0);
