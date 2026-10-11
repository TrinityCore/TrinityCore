SET @CGUID := 7003169;
SET @OGUID := 7000611;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 144378, 1643, 8567, 8568, '0', 10832, 0, 0, 1, 753.0069580078125, -460.220489501953125, 23.72137069702148437, 1.366949439048767089, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Alliance Sailor (Area: Boralus - Difficulty: 0) CreateObject1
(@CGUID+1, 144378, 1643, 8567, 8568, '0', 10832, 0, 0, 1, 757.08856201171875, -489.9132080078125, 33.48966217041015625, 5.064807415008544921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Alliance Sailor (Area: Boralus - Difficulty: 0) CreateObject1
(@CGUID+2, 144378, 1643, 8567, 8568, '0', 10832, 0, 0, 1, 745.75518798828125, -421.40277099609375, 5.116611480712890625, 1.427061796188354492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Alliance Sailor (Area: Boralus - Difficulty: 0) CreateObject1
(@CGUID+3, 120922, 1643, 8567, 8568, '0', 10832, 0, 0, 1, 726.54864501953125, -442.84375, 15.10534954071044921, 5.142793655395507812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Lady Jaina Proudmoore (Area: Boralus - Difficulty: 0) CreateObject1
(@CGUID+4, 144378, 1643, 8567, 8568, '0', 10832, 0, 0, 1, 719.11456298828125, -402.55035400390625, 19.50927543640136718, 1.535100340843200683, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Alliance Sailor (Area: Boralus - Difficulty: 0) CreateObject1
(@CGUID+5, 144378, 1643, 8567, 8568, '0', 10832, 0, 0, 1, 744.671875, -472.260406494140625, 24.18316459655761718, 5.75142669677734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Alliance Sailor (Area: Boralus - Difficulty: 0) CreateObject1
(@CGUID+6, 144378, 1643, 8567, 8568, '0', 10832, 0, 0, 1, 738.76910400390625, -452.05035400390625, 13.23749065399169921, 2.008800506591796875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Alliance Sailor (Area: Boralus - Difficulty: 0) CreateObject1
(@CGUID+7, 144378, 1643, 8567, 8568, '0', 10832, 0, 0, 1, 726.7257080078125, -409.5, 13.24794387817382812, 5.064807415008544921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822); -- Alliance Sailor (Area: Boralus - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Alliance Sailor
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Alliance Sailor
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Alliance Sailor
(@CGUID+3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Lady Jaina Proudmoore
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Alliance Sailor
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Alliance Sailor
(@CGUID+6, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''), -- Alliance Sailor
(@CGUID+7, 0, 0, 0, 0, 0, 0, 0, 714, 0, 0, 0, 0, ''); -- Alliance Sailor

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 302842, 1643, 8567, 8568, '0', 10832, 0, 736.04339599609375, -438.50347900390625, -6.73204898834228515, 5.100135326385498046, 0, 0, -0.55762767791748046, 0.83009117841720581, 120, 255, 1, 60822); -- Jaina's Ship (Area: Boralus - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry`=302842;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(302842, 0, 0x100020, 0, 0); -- Jaina's Ship

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 10832;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(10832, 'Cosmetic - See Jaina and Ship arrived in Boralus');

DELETE FROM `phase_area` WHERE `PhaseId` = 10832;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8567, 10832, 'See Jaina and Ship arrived in Boralus');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 10832 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 10832, 0, 0, 0, 47, 0, 46728, 2|8|64, 0, 0, 'Apply Phase 10832 if Quest 46728 is in progress | complete | rewarded');

-- Spelltarget pos.
DELETE FROM `spell_target_position` WHERE (`ID`=276311 AND `EffectIndex`=0 AND `OrderIndex`=0) OR (`ID`=240876 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(276311, 0, 0, 1643, 727.8599853515625, -445.70001220703125, 19.32999992370605468, 60822), -- Spell: 276311 (Teleport to Jaina (Self)) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(240876, 0, 0, 1643, 727.8599853515625, -445.70001220703125, 14.93999958038330078, 60822); -- Spell: 240876 (Stormwind Harbor to Boralus Transition) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Spellscript names
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_stormwind_harbor_to_boralus_transition';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(240876, 'spell_stormwind_harbor_to_boralus_transition');

-- Quest
DELETE FROM `creature_questender` WHERE (`id`=120922 AND `quest`=46728);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(120922, 46728, 60822); -- The Nation of Kul Tiras ended by Lady Jaina Proudmoore
