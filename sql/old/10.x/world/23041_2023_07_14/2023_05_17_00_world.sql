SET @CGUID := 1051934;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 156942, 2175, 10424, 10568, '0', 13840, 0, 0, 0, 321.328125, -2173.98779296875, 106.3397369384765625, 0.351421147584915161, 120, 0, 0, 95, 382, 0, 0, 0, 0, 49570), -- Henry Garrick (Area: Darkmaul Bridge - Difficulty: 0) CreateObject1
(@CGUID+1, 156941, 2175, 10424, 10568, '0', 13840, 0, 0, 1, 323.26910400390625, -2174.829833984375, 106.3331069946289062, 0.565565943717956542, 120, 0, 0, 357, 0, 0, 0, 0, 0, 49570), -- Captain Garrick (Area: Darkmaul Bridge - Difficulty: 0) CreateObject1
(@CGUID+2, 156943, 2175, 10424, 10568, '0', 13840, 0, 0, 0, 324.26214599609375, -2176.76220703125, 106.33599853515625, 0.286636024713516235, 120, 0, 0, 95, 382, 0, 0, 0, 0, 49570), -- Meredy Huntswell (Area: Darkmaul Bridge - Difficulty: 0) CreateObject1
(@CGUID+3, 156944, 2175, 10424, 10568, '0', 13840, 0, 0, 0, 318.75347900390625, -2174.204833984375, 106.1277389526367187, 1.109427571296691894, 120, 0, 0, 95, 382, 0, 0, 0, 0, 49570); -- Ralia Dreamchaser (Area: Darkmaul Bridge - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `faction`=2618, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=153566; -- Captain Garrick
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=156948; -- Meredy Huntswell
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=153565; -- Henry Garrick
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry` IN (156947, 156944); -- Ralia Dreamchaser
UPDATE `creature_template` SET `faction`=1732, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=156943; -- Meredy Huntswell
UPDATE `creature_template` SET `faction`=1732, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=156941; -- Captain Garrick
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=156942; -- Henry Garrick

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=153566 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(153566, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0, 49570); -- Captain Garrick

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=156943 AND `MenuID`=24550);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(156943, 24550, 49570); -- Meredy Huntswell

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 13840;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(13840, 'Cosmetic - See Alliance Heroes near Darkmaul Citadel');

DELETE FROM `phase_area` WHERE `AreaId` = 10424 AND `PhaseId` = 13840;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(10424, 13840, 'Cosmetic - See Alliance Heroes near Darkmaul Citadel');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 13840 AND `SourceEntry` = 10424);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 13840, 10424, 0, 0, 47, 0, 56344, 2 | 8 | 64, 0, 0, 'Apply Phase 13840 if Quest 56344 is in progress | complete | rewarded'),
(26, 13840, 10424, 0, 0, 48, 0, 390131, 0, 1, 1, 'Apply Phase 13840 if Questobjective 390131 is not rewarded'),
(26, 13840, 10424, 0, 0, 47, 0, 55981, 2 | 64, 0, 1, 'Apply Phase 13840 if Quest 56344 is not complete | rewarded');

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (153566,156948,153565,156947));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(153566, 0, 0, 0, 1421, 49570),
(156948, 0, 0, 0, 741, 49570),
(153565, 0, 0, 0, 741, 49570),
(156947, 0, 0, 0, 741, 49570);

-- Spawngroup
DELETE FROM `spawn_group` WHERE `groupId` = 128 AND `spawnId` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(128, 0, @CGUID+0),
(128, 0, @CGUID+1),
(128, 0, @CGUID+2),
(128, 0, @CGUID+3);
