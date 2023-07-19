SET @CGUID := 651363;
SET @NPCTEXTID:= 560003;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89257, 1220, 7334, 7599, '0', 4758, 0, 0, 0, -789.032958984375, 6105.03173828125, 4.645809650421142578, 4.830193042755126953, 7200, 10, 0, 3923, 0, 2, 0, 0, 0, 46366), -- Smart/Dynamic waypoints NYI
(@CGUID+1, 93466, 1220, 7334, 7599, '0', 4759, 0, 0, 0, -775.826416015625, 6120.900390625, 4.673097610473632812, 4.380776405334472656, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46366),
(@CGUID+2, 91457, 1220, 7334, 7599, '0', 4762, 0, 0, 0, -811.0850830078125, 6098.3427734375, 7.08855295181274414, 1.363109111785888671, 7200, 0, 0, 29423, 0, 0, 0, 0, 0, 46366),
(@CGUID+3, 91463, 1220, 7334, 7599, '0', 4764, 0, 0, 0, -784.72222900390625, 6128.3671875, 4.729145050048828125, 0.073092050850391387, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46366);

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+0, @CGUID+1, @CGUID+3);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+3, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 95166, 0, 0, 0, 0, 0, 0, 0, 46366),
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 121752, 0, 0, 0, 0, 0, 0, 0, 46366),
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 95169, 0, 0, 0, 0, 0, 0, 0, 46366);

DELETE FROM `gossip_menu` WHERE (`MenuID`=18451 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=20281 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=18452 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(18451, @NPCTEXTID+0, 46366),
(20281, @NPCTEXTID+1, 46366),
(18452, @NPCTEXTID+2, 46366);

UPDATE `creature_template` SET `minlevel` = 45, `maxlevel` = 45 WHERE `entry` IN (89257, 93466, 91457, 91463);
UPDATE `creature_template` SET `gossip_menu_id` = 18452 WHERE `entry` = 93466;
UPDATE `creature_template` SET `gossip_menu_id` = 18451 WHERE `entry` = 91457;
UPDATE `creature_template` SET `gossip_menu_id` = 20281 WHERE `entry` = 91463;

DELETE FROM `npc_vendor` WHERE `entry` = 91457;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`, `BonusListIDs`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(91457, 1, 35954, 0, 0, 0, 1, NULL, 0, 0, 22522),
(91457, 2, 128853, 0, 0, 0, 1, NULL, 0, 0, 22522),
(91457, 3, 138292, 0, 0, 0, 1, NULL, 0, 0, 22522),
(91457, 4, 138290, 0, 0, 0, 1, NULL, 0, 0, 22522),
(91457, 5, 138285, 0, 0, 0, 1, NULL, 0, 0, 22522),
(91457, 6, 128839, 0, 0, 0, 1, NULL, 0, 0, 22522),
(91457, 7, 128840, 0, 0, 0, 1, NULL, 0, 0, 22522),
(91457, 8, 128848, 0, 0, 0, 1, NULL, 0, 0, 22522),
(91457, 9, 128849, 0, 0, 0, 1, NULL, 0, 0, 22522);

DELETE FROM `creature_equip_template` WHERE `ID`=1 AND `CreatureID` = 93466;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(93466, 1, 2202, 0, 0, 0, 0, 0, 0, 0, 0, 46366);

DELETE FROM `creature_template_addon` WHERE `entry` = 91457;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(91457, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `phase_name` WHERE `ID` IN (4758, 4759, 4762, 4764);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4758, 'Cosmetic - See Cleave Thunderhill rescued'),
(4759, 'Cosmetic - See Seska Seafang rescued'),
(4762, 'Cosmetic - See Gentle Rosh rescued'),
(4764, 'Cosmetic - See Grace the Green rescued');

DELETE FROM `phase_area` WHERE `AreaId` = 7599 AND `PhaseId` IN (4758, 4759, 4762, 4764);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7599, 4758, 'See Cleave Thunderhill rescued in Shackle\'s Den'),
(7599, 4759, 'See Seska Seafang rescued in Shackle\'s Den'),
(7599, 4762, 'See Gentle Rosh rescued in Shackle\'s Den'),
(7599, 4764, 'See Grace the Green rescued in Shackle\'s Den');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (4758, 4759, 4762, 4764)  AND `SourceEntry` = 7599);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4759, 7599, 0, 0, 47, 0, 38857, 8 | 2 | 64, 0, 0, 'Apply Phase 4759 if Quest 38857 is in progress | complete | rewarded'),
(26, 4758, 7599, 0, 0, 47, 0, 38857, 2 | 64, 0, 0, 'Apply Phase 4758 if Quest 38857 is completed | rewarded'),
(26, 4758, 7599, 0, 1, 48, 0, 278523, 0, 1, 0, 'Apply Phase 4758 if player has quest objective done: Cleave Thunderhill rescued'),
(26, 4762, 7599, 0, 0, 47, 0, 38857, 2 | 64, 0, 0, 'Apply Phase 4762 if Quest 38857 is completed | rewarded'),
(26, 4762, 7599, 0, 1, 48, 0, 278524, 0, 1, 0, 'Apply Phase 4762 if player has quest objective done: Gentle Rosh rescued'),
(26, 4764, 7599, 0, 0, 47, 0, 38857, 2 | 64, 0, 0, 'Apply Phase 4764 if Quest 38857 is completed | rewarded'),
(26, 4764, 7599, 0, 1, 48, 0, 278525, 0, 1, 0, 'Apply Phase 4764 if player has quest objective done: Grace the Green rescued');
