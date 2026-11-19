SET @CGUID := 7000558;
SET @NPCTEXTID := 570040;

DELETE FROM `phase_name` WHERE `ID`=12634;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12634, 'Cosmetic: Kul Tiran Unlock Questline - Arthur Tradewind Cat Form');

DELETE FROM `phase_area` WHERE `PhaseId`=12634;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9134, 12634, 'Cosmetic: Kul Tiran Unlock Questline - Arthur Tradewind Cat Form - Gol Koval');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12634));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12634, 0, 0, 0, 47, 0, 54727, 64, 0, '', 0, 'Player have Team Carry (54727) in state rewarded'),
(26, 12634, 0, 0, 0, 48, 0, 388208, 0, 1, '', 1, 'Player doesn\'t have quest objective 388208 == 1');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149293, 1643, 8721, 9134, '0', 12634, 0, 0, 0, -1006.2603759765625, 1755.6302490234375, 124.049346923828125, 4.171336650848388671, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- Arthur Tradewind (Area: Gol Koval - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid`=@CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Arthur Tradewind

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=54847 WHERE (`Entry`=149293 AND `DifficultyID`=0); -- 149293 (Arthur Tradewind) - CanSwim - CannotTurn
UPDATE `creature_template` SET `faction`=3011, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=149293; -- Arthur Tradewind

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=149293 AND `MenuID`=23768);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(149293, 23768, 54847); -- Arthur Tradewind

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+4;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 168210, 0, 0, 0, 0, 0, 0, 0, 54847); -- 149293 (Arthur Tradewind)

DELETE FROM `gossip_menu` WHERE (`MenuID`=23768 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23768, @NPCTEXTID+0, 54847); -- 149293 (Arthur Tradewind)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=23768 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(23768, 50185, 0, 0, 'Can you take me to the High Thornspeaker?', 168211, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 54847);
