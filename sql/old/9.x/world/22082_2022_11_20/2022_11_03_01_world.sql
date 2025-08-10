SET @CGUID := 651367;
SET @NPCTEXTID := 560006;

DELETE FROM `creature` WHERE `guid` = @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 89362, 1220, 7334, 7364, '0', 5696, 0, 0, 1, -103.434028625488281, 6961.33251953125, 12.546875, 2.022709131240844726, 7200, 0, 0, 5099900, 0, 0, 0, 0, 0, 46366);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID, 0, 0, 0, 0, 0, 0, 0, 0, 3, '42459');

DELETE FROM `npc_text` WHERE `ID` = @NPCTEXTID;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID, 1, 0, 0, 0, 0, 0, 0, 0, 92343, 0, 0, 0, 0, 0, 0, 0, 46366);

DELETE FROM `gossip_menu` WHERE (`MenuID`=18054 AND `TextID`=@NPCTEXTID);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(18054, @NPCTEXTID, 46366);

UPDATE `creature_template` SET `gossip_menu_id` = 18054 WHERE `entry` = 89362;

DELETE FROM `phase_name` WHERE `ID` = 5696;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(5696, 'Cosmetic - See Kayn Sunfury');

DELETE FROM `phase_area` WHERE `AreaId` IN (7362, 7364) AND `PhaseId` = 5696;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7362, 5696, 'See Kayn Sunfury in Illidari Stand'),
(7364, 5696, 'See Kayn Sunfury in Illidari Stand');
