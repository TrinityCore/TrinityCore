SET @CGUID := 651361;
SET @NPCTEXTID := 560002;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89398, 1220, 7334, 7364, '0', '4462', 0, 0, 1, -90.15625, 6978.98876953125, 12.49817848205566406, 1.585586428642272949, 7200, 0, 0, 39230, 0, 0, 0, 0, 0, 46366),
(@CGUID+1, 90308, 1220, 7334, 7364, '0', '4462', 0, 0, 0, -90.923614501953125, 6983.765625, 12.53627777099609375, 4.52641153335571289, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46366);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 376, 0, 0, 0, 3, ''),
(@CGUID+1, 0, 0, 0, 1, 64, 0, 0, 0, 0, '');

DELETE FROM `npc_text` WHERE `ID` = @NPCTEXTID;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID, 1, 0, 0, 0, 0, 0, 0, 0, 121765, 0, 0, 0, 0, 0, 0, 0, 46366);

UPDATE `creature_template` SET `gossip_menu_id` = 20284 WHERE `entry` = 89398;

DELETE FROM `gossip_menu` WHERE (`MenuID`=20284 AND `TextID`=@NPCTEXTID);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(20284, @NPCTEXTID, 46366);

DELETE FROM `phase_name` WHERE `ID` = 4462;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4462, 'Cosmetic - See Allari the Souleater and Wrathguard Prisoner');

DELETE FROM `phase_area` WHERE `AreaId` IN (7362, 7364) AND `PhaseId` = 4462;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7362, 4462, 'See Allari the Souleater and Wrathguard Prisoner in Illidari Stand'),
(7364, 4462, 'See Allari the Souleater and Wrathguard Prisoner in Illidari Stand');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4462 AND `SourceEntry` IN (7362, 7364));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4462, 7362, 0, 0, 47, 0, 37660, 8 | 2, 0, 1, 'Apply Phase 4462 if Quest 37660 is not in progress | completed'),
(26, 4462, 7362, 0, 1, 48, 0, 277159, 0, 1, 0, 'Apply Phase 4764 if player has quest objective done: Arev\'naal compelled'),
(26, 4462, 7364, 0, 0, 47, 0, 37660, 8 | 2, 0, 1, 'Apply Phase 4764 if Quest 37660 is not in progress | completed'),
(26, 4462, 7364, 0, 1, 48, 0, 277159, 0, 1, 0, 'Apply Phase 4764 if player has quest objective done: Arev\'naal compelled');
