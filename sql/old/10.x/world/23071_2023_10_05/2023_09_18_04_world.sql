SET @CGUID := 5000091;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 84929, 0, 4, 0, '0', 3972, 0, 1190, 0, 0, -11282.7099609375, -3095.782958984375, 3.182274818420410156, 5.280431270599365234, 120, 0, 0, 800000, 1283, 0, NULL, NULL, 50791); -- Vindicator Maraad (Area: 0 - Difficulty: 0) CreateObject1

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` =84929);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(84929, 1, 30802, 0, 0, 0, 0, 0, 0, 0, 0, 50791); -- Vindicator Maraad

UPDATE `creature_queststarter` SET `VerifiedBuild`=50791 WHERE (`id`=84929 AND `quest` IN (36941,35500,35495,35488,35492,35486));
UPDATE `creature_questender` SET `VerifiedBuild`=50791 WHERE (`id`=84929 AND `quest` IN (35500,35495,35488,35486,35492,36307));

UPDATE `creature_template` SET `faction`=84, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=84929; -- Vindicator Maraad

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3972 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3972, 0, 0, 0, 47, 0, 37677, 64, 0, 0, 'Apply Phase 3972 if Quest 37677 is rewarded'),
(26, 3972, 0, 0, 0, 47, 0, 36307, 8 | 2 | 64, 0, 0, 'Apply Phase 3972 if Quest 36307 is in progress | complete | rewarded');

DELETE FROM `phase_name` WHERE `ID`=3972;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3972, 'Cosmetic - Vindicator Maraad at Dreadmaul in Blasted Lands');

DELETE FROM `phase_area` WHERE `AreaId`=4 AND `PhaseId` = 3972;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(4, 3972, 'See Vindicator Maraad at Dreadmaul in Blasted Lands');
