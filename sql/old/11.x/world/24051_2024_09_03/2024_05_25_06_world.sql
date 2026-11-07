SET @CGUID := 7000551;

DELETE FROM `phase_name` WHERE `ID`=12886;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12886, 'Cosmetic: Kul Tiran Unlock Questline - Princess in front of Chelsea in Bleak Hills Mine');

DELETE FROM `phase_area` WHERE `PhaseId`=12886;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12886, 'Cosmetic: Kul Tiran Unlock Questline - Princess in front of Chelsea - Bleak Hills Mine'),
(9432, 12886, 'Cosmetic: Kul Tiran Unlock Questline - Princess in front of Chelsea - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12886));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12886, 0, 0, 0, 47, 0, 55136, 64, 0, '', 0, 'Player have Her Dog Days Are Over (55136) in state rewarded');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 150957, 1643, 8721, 9432, '0', 12886, 0, 0, 0, 98.34722137451171875, 3404.9609375, 208.9343109130859375, 5.546810626983642578, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- Princess (Area: Watchman's Rise - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=150957; -- Princess

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=150957 AND `DifficultyID`=0); -- 150957 (Princess) - CanSwim

-- 
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (322636 /*Worn Collar*/, 322637 /*Squeaky Toy*/, 322638 /*Gnawed Bone*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(322636, 0, 2113540, 0, 0), -- Worn Collar
(322637, 0, 2113540, 0, 0), -- Squeaky Toy
(322638, 0, 2113540, 0, 0); -- Gnawed Bone
