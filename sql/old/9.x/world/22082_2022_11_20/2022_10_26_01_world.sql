SET @CGUID := 850705;
SET @NPCTEXTID := 570036;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1, 175138, 0, 1519, 0, '0', '0', 0, 0, 0, -8416.0224609375, 211.7239532470703125, 155.347137451171875, 0.69220137596130371, 120, 0, 0, 1179100, 1500, 0, 0, 0, 0, 45745),
(@CGUID+2, 175137, 0, 1519, 6292, '0', '16785', 0, 0, 0, -8361.42578125, 230.1649322509765625, 157.7021331787109375, 2.329087257385253906, 120, 0, 0, 14149200, 655000, 0, 0, 0, 0, 45745),
(@CGUID+3, 151255, 0, 1519, 6292, '0', '0', 0, 0, 0, -8268.0869140625, 248.0364532470703125, 155.43048095703125, 4.004129886627197265, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 45745),
(@CGUID+4, 151251, 0, 1519, 6292, '0', '0', 0, 0, 0, -8269.47265625, 246.5885467529296875, 155.4304656982421875, 4.339423656463623046, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745),
(@CGUID+5, 151249, 0, 1519, 6292, '0', '0', 0, 0, 0, -8269.87890625, 245.51910400390625, 155.4304656982421875, 4.070425033569335937, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745),
(@CGUID+6, 151249, 0, 1519, 6292, '0', '0', 0, 0, 0, -8270.48828125, 246.0850677490234375, 155.4304656982421875, 4.230201244354248046, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745),
(@CGUID+7, 151249, 0, 1519, 6292, '0', '0', 0, 0, 0, -8268.923828125, 245.685760498046875, 155.4304656982421875, 3.658530235290527343, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745),
(@CGUID+8, 151249, 0, 1519, 6292, '0', '0', 0, 0, 0, -8269.3974609375, 244.6666717529296875, 155.4304656982421875, 3.622267723083496093, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745),
(@CGUID+9, 151247, 0, 1519, 6292, '0', '0', 0, 0, 0, -8272.02734375, 244.086944580078125, 155.4755706787109375, 0.671950340270996093, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 45745),
(@CGUID+10, 93307, 0, 1519, 1519, '0', '0', 0, 0, 0, -8311.1787109375, 312.888885498046875, 158.051605224609375, 3.809809684753417968, 120, 0, 0, 294775, 0, 0, 0, 0, 0, 45745),
(@CGUID+11, 93296, 0, 1519, 1519, '0', '0', 0, 0, 0, -8312.470703125, 314.520843505859375, 158.051605224609375, 4.160883903503417968, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745),
(@CGUID+12, 143208, 0, 1519, 1519, '0', '0', 0, 0, 0, -8272.98828125, 229.6006927490234375, 155.4304962158203125, 2.236136436462402343, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 45745),
(@CGUID+13, 151256, 0, 1519, 1519, '0', '0', 0, 0, 0, -8270.8330078125, 244.7569427490234375, 155.347137451171875, 0.61206364631652832, 120, 10, 0, 11791, 0, 1, 0, 0, 0, 45745);

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 206706, 0, 0, 0, 0, 0, 0, 0, 45745),
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 206708, 0, 0, 0, 0, 0, 0, 0, 45745);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 257, 0, 0, 0, 0, 3, ''),
(@CGUID+2, 0, 0, 0, 256, 0, 0, 0, 0, 3, '344660'),
(@CGUID+4, 0, 0, 0, 1, 882, 0, 0, 0, 0, ''),
(@CGUID+5, 0, 0, 0, 1, 732, 0, 0, 0, 0, ''),
(@CGUID+6, 0, 0, 0, 1, 732, 0, 0, 0, 0, ''),
(@CGUID+7, 0, 0, 0, 1, 732, 0, 0, 0, 0, ''),
(@CGUID+8, 0, 0, 0, 1, 732, 0, 0, 0, 0, ''),
(@CGUID+9, 0, 0, 5, 1, 0, 0, 0, 0, 0, '292924'),
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, 0, '133464');

DELETE FROM `creature` WHERE `guid` IN (335505, 335508, 335480, 335506, 335507, 335478, 335479); -- Bunny npcs removed on retail
DELETE FROM `creature` WHERE `guid` = 314277; -- Anduin Wrynn (child)
DELETE FROM `creature` WHERE `guid` = 314282; -- Major Samuelson

UPDATE `creature` SET `curhealth` = 675, `MovementType` = 2 WHERE `guid` = 314270; -- Crithto
UPDATE `creature` SET `PhaseId` = 16013, `position_x` = -8375.669921875, `position_y` = 231.12847900390625, `position_z` = 155.4259490966796875, `orientation` = 1.675519824028015136, `spawntimesecs` = 120 WHERE `guid` = 452571; -- Grand Admiral Jes-Tereth
UPDATE `creature` SET `PhaseId` = 16013 WHERE `guid` IN (314305, 314304, 314298, 314299, 314291, 314289, 314290, 314286, 314287, 314288, 314284, 314281, 314283, 314278, 314285, 314276, 314272, 314271, 314268, 314266, 314267, 314265, 314269, 314273, 314275, 314295, 314303, 314296, 314297);
UPDATE `creature` SET `PhaseId` = 16013, `wander_distance` = 4, `MovementType` = 1 WHERE `guid` = 314302;
UPDATE `creature` SET `wander_distance` = 10, `MovementType` = 1 WHERE `guid` = 314279;
UPDATE `creature_template` SET `gossip_menu_id` = 26687, `minlevel` = 63, `maxlevel` = 63 WHERE `entry` = 175137;
UPDATE `creature_template` SET `gossip_menu_id` = 26684, `minlevel` = 63, `maxlevel` = 63 WHERE `entry` = 175138;
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60 WHERE `entry` = 93307;
UPDATE `creature_template` SET `minlevel` = 1, `maxlevel` = 1 WHERE `entry` = 51938;
UPDATE `creature_template` SET `unit_flags3` = 16777216 WHERE `entry` = 93296;

DELETE FROM `gossip_menu` WHERE (`MenuID`=26684 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=26687 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(26684, @NPCTEXTID+0, 45745),
(26687, @NPCTEXTID+1, 45745);

DELETE FROM `phase_name` WHERE `ID` IN (16013, 16785);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(16013, 'Cosmetic - Stormwind Keep - See Guards and Nobles'),
(16785, 'Cosmetic - Stormwind Keep - See Turalyon');

DELETE FROM `phase_area` WHERE `PhaseId` IN (16013, 16785);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 16013, 'Stormwind Keep - See Guards and Nobles inside the Keep'),
(6292, 16785, 'Stormwind Keep - See Turalyon in Throne');

DELETE FROM `creature_addon` WHERE `guid` = 314269;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(314269, 0, 0, 0, 0, 433, 0, 0, 0, 0, ''); -- Behsten

DELETE FROM `creature_template_addon` WHERE `entry` IN (93307, 93296, 151256);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(151256, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(93307, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(93296, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

UPDATE `gameobject` SET `position_x` = -8413.58203125, `position_y` = 217.5850677490234375, `position_z` = 157.1246337890625, `orientation` = 1.068230986595153808, `rotation2` = 0.509079933166503906, `rotation3` = 0.860719263553619384 WHERE `guid` = 220288;
UPDATE `gameobject` SET `position_x` = -8411.1025390625, `position_y` = 214.361114501953125, `position_z` = 157.132049560546875, `orientation` = 6.198384284973144531, `rotation2` = -0.04238796234130859, `rotation3` = 0.999101221561431884 WHERE `guid` = 220285;
