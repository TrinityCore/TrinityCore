SET @CGUID := 651507;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89975, 1220, 7334, 7346, '0', 4438, 0, 0, 0, 634.654541015625, 6679.65966796875, 54.34073257446289062, 3.335079908370971679, 120, 0, 0, 3923000, 0, 0, 0, 0, 0, 46455), -- Senegos
(@CGUID+1, 100482, 1220, 7334, 7621, '0', 4439, 0, 0, 0, 664.2725830078125, 6673.7431640625, 55.78749465942382812, 5.376341819763183593, 120, 0, 0, 3923000, 1534, 0, 0, 0, 0, 46455); -- Senegos

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 7733, 0, 0, 4, ''), -- Senegos
(@CGUID+1, 0, 0, 0, 1, 0, 7763, 0, 0, 4, ''); -- Senegos

UPDATE `creature_template` SET `gossip_menu_id`=18171 WHERE `entry`=89975; -- Senegos
UPDATE `creature_template` SET `gossip_menu_id`=18171, `minlevel`=45, `maxlevel`=45 WHERE `entry`=100482; -- Senegos

DELETE FROM `creature_queststarter` WHERE `id`=100482 AND `quest`=37690;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(100482, 37690, 46455); -- Those Who Remember offered Senegos

UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37690; -- Those Who Remember
UPDATE `quest_details` SET `VerifiedBuild`=46455 WHERE `ID` = 37690;

DELETE FROM `phase_name` WHERE `ID` IN (4438, 4439);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4438, 'Cosmetic - See Senegos in pain'),
(4439, 'Cosmetic - See Senegos healed');

DELETE FROM `phase_area` WHERE `AreaId` = 7334 AND `PhaseId` IN (4438, 4439);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7334, 4438, 'See Senegos in pain in Azurewing Repose'),
(7334, 4439, 'See Senegos healed in Azurewing Repose');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (4438, 4439) AND `SourceEntry` = 7334);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4438, 7334, 0, 0, 47, 0, 37861, 64, 0, 1, 'Apply Phase 4438 if Quest 37861 is not rewarded'),
(26, 4439, 7334, 0, 1, 47, 0, 37861, 64, 0, 0, 'Apply Phase 4439 if Quest 37861 is rewarded'),
(26, 4439, 7334, 0, 0, 47, 0, 37862, 2 | 64, 0, 1, 'Apply Phase 4439 if Quest 37862 is not completed | rewarded'),
(26, 4439, 7334, 0, 1, 47, 0, 42756, 2 | 64, 0, 0, 'Apply Phase 4439 if Quest 42756 is completed | rewarded');
