SET @CGUID := 7000964;

DELETE FROM `phase_name` WHERE `ID`=12649;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12649, 'Cosmetic: Kul Tiran Unlock Questline - Bound Sky Ulfars Den');

DELETE FROM `phase_area` WHERE `PhaseId`=12649;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9965, 12649, 'Cosmetic: Kul Tiran Unlock Questline - Bound Sky - Ulfars Den');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12649));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12649, 0, 0, 0, 47, 0, 54734, 1, 0, '', 0, 'Player have Summons from Dorian (54734) in state not taken'),
(26, 12649, 0, 0, 0, 47, 0, 54733, 64, 0, '', 0, 'Player have Make It Wright (54733) in state rewarded'),
(26, 12649, 0, 0, 0, 47, 0, 54731, 64, 0, '', 0, 'Player have Balance in All Things (54731) in state rewarded');

DELETE FROM `creature` WHERE `guid`=@CGUID+0; 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149252, 1643, 8721, 9965, '0', 12649, 0, 0, 0, -480.03125, 2697.6103515625, 282.93701171875, 2.246921777725219726, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904); -- Bound Sky (Area: Ulfar's Den - Difficulty: 0) CreateObject1
