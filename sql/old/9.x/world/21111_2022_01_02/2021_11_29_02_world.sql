-- 
SET @CGUID := 1050146;

-- Creature spawn Private Cole 160664
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 160664, 2261, 10424, 10639, '0', 13753, 0, 0, 0, -13.3162784576416015, 0.612700998783111572, 5.664855003356933593, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079); -- Private Cole (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 10639 AND `PhaseId` =13753;
INSERT INTO `phase_area`(`AreaId`, `PhaseId`, `Comment`) VALUES
(10639, 13753, 'Cosmetic: NPE - Private Cole on ship initial');

-- Condition
DELETE FROM `conditions` WHERE `SourceEntry` = 10639 AND `SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13753;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 13753, 10639, 0, 0, 8, 0, 58209, 0, 0, 1, 0, 0, '', 'Allow Phase 13753 if Quest 58209 IS NOT taken');

DELETE FROM `creature_model_info` WHERE `DisplayID` = 94939;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(94939, 0.305999994277954101, 1.5, 0, 41079);

UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=1732, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=160664; -- Private Cole

-- Queststarter & ender
DELETE FROM `creature_queststarter` WHERE `id` = 160664 AND `quest` IN (58209, 58208);
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES
(160664, 58209),
(160664, 58208);

DELETE FROM `creature_questender` WHERE (`id`=160664 AND `quest`=58209) OR (`id`=156280 AND `quest`=58208);
INSERT INTO `creature_questender`(`id`, `quest`) VALUES
(160664, 58209),
(156280, 58208);

DELETE FROM `quest_template_addon` WHERE `ID` IN (58209, 58208);
INSERT INTO `quest_template_addon`(`ID`, `PrevQuestID`) VALUES
(58209, 56775),
(58208, 58209);
