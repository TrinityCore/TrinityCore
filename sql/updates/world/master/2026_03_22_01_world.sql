SET @CGUID := 11000392;
SET @OGUID := 11000006;

SET @NPCTEXTID := 610007;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 249187, 0, 1519, 9171, '0', 0, 0, 0, 1, -8138.8662109375, 787.34027099609375, 72.63970947265625, 2.819438457489013671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66527); -- Envoy Manat (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''); -- Envoy Manat

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 574613, 0, 1519, 9171, '0', 0, 0, -8137.0244140625, 788.015625, 72.4526214599609375, 2.387194633483886718, 0, 0, 0.929699897766113281, 0.368317902088165283, 120, 255, 1, 66527); -- Haranir (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` = 574613;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(574613, 0, 0x40000, 0, 0); -- Haranir

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=249187; -- Envoy Manat

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=249187 AND `MenuID`=40543);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(249187, 40543, 66527); -- Envoy Manat

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 300131, 0, 0, 0, 0, 0, 0, 0, 66527), -- 249187 (Envoy Manat)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 300128, 0, 0, 0, 0, 0, 0, 0, 66527); -- 249187 (Envoy Manat)

DELETE FROM `gossip_menu` WHERE (`MenuID`=40542 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=40543 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(40542, @NPCTEXTID+0, 66527), -- 249187 (Envoy Manat)
(40543, @NPCTEXTID+1, 66527); -- 249187 (Envoy Manat)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=40543 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(40543, 135803, 0, 0, 'Why is the Harandar banner not inside with the rest of them?', 0, 0, 0, 40542, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66527);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2145, `StaticFlags1`=0x10000000, `VerifiedBuild`=66527 WHERE (`Entry`=249187 AND `DifficultyID`=0); -- 249187 (Envoy Manat) - CanSwim
