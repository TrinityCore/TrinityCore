SET @CGUID := 7003589;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 121603, 1643, 8721, 8852, '0', 8671, 0, 0, 0, -236.394821166992187, 2171.9453125, 64.43473052978515625, 2.813721895217895507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163); -- Abby Lewis (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 13110, 0, 0, ''); -- Abby Lewis

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=121603 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63163 WHERE (`Entry`=121603 AND `DifficultyID`=0); -- 121603 (Abby Lewis) - CanSwim

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 8671;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(8671, 'Cosmetic - See Abby Lewis walking in Glenbrook Homestead');

DELETE FROM `phase_area` WHERE `PhaseId` = 8671;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 8671, 'See Abby Lewis walking in Glenbrook Homestead');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 8671 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 8671, 0, 0, 0, 47, 0, 47289, 2|8|64, 0, 1, 'Apply Phase 8671 if Quest 47289 is not in progress|complete|rewarded');

-- Quest
DELETE FROM `quest_details` WHERE `ID`=47289;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47289, 1, 0, 0, 0, 0, 0, 0, 0, 63163); -- Teddies and Tea

DELETE FROM `creature_queststarter` WHERE (`id`=121603 AND `quest`=47289);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(121603, 47289, 63163); -- Teddies and Tea offered by Abby Lewis

-- Path for Abby Lewis
SET @MOVERGUID := @CGUID+0;
SET @ENTRY := 121603;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Abby Lewis - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -242.73785, 2177.8281, 64.8019, NULL, 0),
(@PATH, 1, -240.68404, 2184.2883, 64.26467, NULL, 0),
(@PATH, 2, -236.36285, 2187.6685, 64.159386, NULL, 0),
(@PATH, 3, -230.15799, 2186.2275, 64.10291, NULL, 0),
(@PATH, 4, -227.91145, 2181.2102, 64.0858, NULL, 0),
(@PATH, 5, -230.05208, 2175.2344, 64.31818, NULL, 0),
(@PATH, 6, -234.25348, 2171.217, 64.31387, NULL, 0),
(@PATH, 7, -241.69618, 2173.75, 64.807434, NULL, 0);

UPDATE `creature` SET `position_x`=-242.73785, `position_y`=2177.8281, `position_z`=64.8019, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId` = @PATH WHERE `guid` = @MOVERGUID;
