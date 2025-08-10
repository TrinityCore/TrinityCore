SET @CGUID := 7000963;

DELETE FROM `phase_name` WHERE `ID`=12630;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12630, 'Cosmetic: Kul Tiran Unlock Questline - Bound Sky Watchman''s Rise');

DELETE FROM `phase_area` WHERE `PhaseId`=12630;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12630, 'Cosmetic: Kul Tiran Unlock Questline - Bound Sky Watchman''s Rise - Bleak Hills Mine'),
(9432, 12630, 'Cosmetic: Kul Tiran Unlock Questline - Bound Sky Watchman''s Rise - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12630));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12630, 0, 0, 0, 47, 0, 54734, 1, 0, '', 0, 'Player have Summons from Dorian (54734) in state not taken'),
(26, 12630, 0, 0, 0, 47, 0, 54733, 64, 0, '', 0, 'Player have Make It Wright (54733) in state rewarded'),
(26, 12630, 0, 0, 0, 47, 0, 54731, 64, 0, '', 0, 'Player have Balance in All Things (54731) in state rewarded');

DELETE FROM `creature` WHERE `guid`=@CGUID+0; 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149252, 1643, 8721, 9432, '0', 12630, 0, 0, 0, 102.1736068725585937, 3408.8984375, 209.4611358642578125, 5.513571739196777343, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904); -- Bound Sky (Area: Watchman's Rise - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=149252; -- Bound Sky

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54904 WHERE (`Entry`=149252 AND `DifficultyID`=0); -- 149252 (Bound Sky) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54904 WHERE (`Entry`=149294 AND `DifficultyID`=0); -- 149294 (Arthur Tradewind) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54904 WHERE (`Entry`=149309 AND `DifficultyID`=0); -- 149309 (Arthur Tradewind) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54904 WHERE (`Entry`=150853 AND `DifficultyID`=0); -- 150853 (Ulfar) - CanSwim

UPDATE `creature_model_info` SET `BoundingRadius`=2.333333253860473632, `VerifiedBuild`=54904 WHERE `DisplayID`=81359;
UPDATE `creature_model_info` SET `BoundingRadius`=0.723333299160003662, `CombatReach`=2.333333253860473632, `VerifiedBuild`=54904 WHERE `DisplayID`=88467;
UPDATE `creature_model_info` SET `BoundingRadius`=2.338504791259765625, `CombatReach`=3.499999761581420898, `VerifiedBuild`=54904 WHERE `DisplayID`=83052;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579470038414001464, `VerifiedBuild`=54904 WHERE `DisplayID`=84893;
UPDATE `creature_model_info` SET `BoundingRadius`=0.685569643974304199, `CombatReach`=2.5, `VerifiedBuild`=54904 WHERE `DisplayID`=66292;
