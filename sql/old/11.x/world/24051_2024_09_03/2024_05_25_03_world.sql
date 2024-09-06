SET @CGUID := 7000545;

DELETE FROM `phase_name` WHERE `ID`=12868;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12868, 'Cosmetic: Kul Tiran Unlock Questline - Fled Wicker Beast with Keys');

DELETE FROM `phase_area` WHERE `PhaseId`=12868;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12868, 'Cosmetic: Kul Tiran Unlock Questline - Fled Wicker Beast with Keys - Bleak Hills Mine'),
(9432, 12868, 'Cosmetic: Kul Tiran Unlock Questline - Fled Wicker Beast with Keys - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12868));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12868, 0, 0, 0, 47, 0, 54729, 66, 0, '', 0, 'Player have The Bleak Hills (54729) in state complete, rewarded'),
(26, 12868, 0, 0, 0, 47, 0, 54732, 74, 0, '', 1, 'Player doesn\'t have Drop It! (54732) in state incomplete, complete, rewarded');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 150885, 1643, 8721, 9500, '0', 12868, 0, 0, 0, 96.92534637451171875, 3346.322021484375, 221.391387939453125, 2.496227741241455078, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Wicker Beast (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1 (Auras: 292403 - [DNT] Bang Keys)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+0);
INSERT INTO `creature_addon` (`guid`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '292403'); -- 150885 (Wicker Beast) - [DNT] Bang Keys

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=150885 AND `DifficultyID`=0); -- 150885 (Wicker Beast) - CanSwim
UPDATE `creature_template` SET `faction`=190, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=150885; -- Wicker Beast
