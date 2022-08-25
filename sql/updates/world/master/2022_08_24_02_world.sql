SET @CGUID := 460687;
SET @OGUID := 395673;

SET @NPCTEXTID := 550031;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 80225, 1116, 7004, 0, '0', 3887, 0, 0, 1, 5572.51220703125, 4640.20751953125, 146.4850616455078125, 4.986562252044677734, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 45114), -- Skaggit (Area: 0 - Difficulty: 0)
(@CGUID+1, 63420, 1116, 7004, 0, '0', 3887, 0, 0, 0, 5567.82666015625, 4636.73095703125, 146.71600341796875, 0, 7200, 0, 0, 1989, 0, 0, 0, 0, 0, 45114), -- SLG Generic MoP (Area: 0 - Difficulty: 0)
(@CGUID+2, 80222, 1116, 7004, 0, '0', 3887, 0, 0, 1, 5563.8505859375, 4641.017578125, 147.0868072509765625, 5.23178863525390625, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 45114), -- Mr. Pleeb (Area: 0 - Difficulty: 0)
(@CGUID+3, 80223, 1116, 7004, 0, '0', 3887, 0, 0, 1, 5564.5849609375, 4639.666015625, 146.953125, 4.985915660858154296, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 45114), -- Lady Sena (Area: 0 - Difficulty: 0)
(@CGUID+4, 80221, 1116, 7004, 0, '0', 3887, 0, 0, 1, 5569.72216796875, 4641.03662109375, 146.6927032470703125, 5.053752899169921875, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 45114); -- Libby Wrenchwrecker (Area: 0 - Difficulty: 0)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 233664, 1116, 7004, 7004, '0', 3887, 0, 5567.4755859375, 4636.34912109375, 146.6606292724609375, 4.785277843475341796, 0, 0, -0.68087291717529296, 0.732401549816131591, 7200, 255, 0, 45114); -- Master Surveyor (Area: -Unknown- - Difficulty: 0)

-- Creature Template Data
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=63420; -- SLG Generic MoP
UPDATE `creature_template` SET `gossip_menu_id`=16474, `minlevel`=40, `maxlevel`=40 WHERE `entry`=80223; -- Lady Sena
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=80225; -- Skaggit
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=80222; -- Mr. Pleeb
UPDATE `creature_template` SET `gossip_menu_id`=16473 WHERE `entry`=80221; -- Libby Wrenchwrecker

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 85494, 0, 0, 0, 0, 0, 0, 0, 45114), -- 80221 (Libby Wrenchwrecker)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 85496, 0, 0, 0, 0, 0, 0, 0, 45114); -- 80223 (Lady Sena)

DELETE FROM `gossip_menu` WHERE (`MenuID`=16473 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=16474 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(16473, @NPCTEXTID+0, 45114), -- 80221 (Libby Wrenchwrecker)
(16474, @NPCTEXTID+1, 45114); -- 80223 (Lady Sena)

-- Phasing
DELETE FROM `phase_area` WHERE (`AreaId` = 7004 AND `PhaseId` = 3887);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7004, 3887, 'Cosmetic - See Master Surveyor');

DELETE FROM `phase_name` WHERE `ID` = 3887;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3887, 'Cosmetic - See Master Surveyor');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 3887 AND `SourceEntry` = 7004);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3887, 7004, 0, 0, 47, 0, 34378, 8, 0, 0, 'Player has Establish Your Garrison (34378) in state incomplete');
