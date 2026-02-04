SET @CGUID := 10003717;
SET @OGUID := 10000994;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 221294, 0, 1519, 10523, '0', 24506, 0, 0, 0, -9071.8095703125, 1009.5242919921875, 73.67437744140625, 1.353640079498291015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Earthen Runeweaver (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1 (Auras: 443618 - Dornogal Portal Cosmetic [DNT])
(@CGUID+1, 221294, 0, 1519, 10523, '0', 24506, 0, 0, 0, -9066.25, 1013.4879150390625, 73.6744842529296875, 3.002710819244384765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819); -- Earthen Runeweaver (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1 (Auras: 443618 - Dornogal Portal Cosmetic [DNT])

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 452405, 0, 1519, 10523, '0', 24506, 0, -9070.51953125, 1013.7852783203125, 74.3186187744140625, 5.366888046264648437, 0, 0, -0.44228839874267578, 0.896872878074645996, 120, 255, 1, 56819); -- Portal to Dornogal (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503); -- Portal to Dornogal

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry`=221294;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(221294, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '443618'); -- 221294 (Earthen Runeweaver) - Dornogal Portal Cosmetic [DNT]

DELETE FROM `gameobject_template_addon` WHERE `entry` = 452405; -- Portal to Dornogal
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(452405, 1732, 0, 0, 3503); -- Portal to Dornogal

-- Template
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=1500, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=221294; -- Earthen Runeweaver

DELETE FROM `gameobject_template` WHERE `entry` = 452405; -- Portal to Dornogal
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(452405, 22, 92603, 'Portal to Dornogal', '', '', '', 0.999999761581420898, 446540, -1, 0, 0, 0, 124420, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56819); -- Portal to Dornogal

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 24506;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(24506, 'Cosmetic - See Portal to Dornogal');

DELETE FROM `phase_area` WHERE `PhaseId` = 24506; 
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 24506, 'Cosmetic - See Portal to Dornogal');

-- Seplltarget
DELETE FROM `spell_target_position` WHERE (`ID`=446540 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(446540, 0, 2552, 2915.679931640625, -2400.330078125, 265.8599853515625, 56819); -- Spell: 446540 (Teleport: Dornogal) Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (118597, 118596);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(118597, 0.347000002861022949, 1.5, 0, 56819),
(118596, 0.347000002861022949, 1.5, 0, 56819);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2837, `VerifiedBuild`=56819 WHERE (`Entry`=221294 AND `DifficultyID`=0); -- 221294 (Earthen Runeweaver) - 
