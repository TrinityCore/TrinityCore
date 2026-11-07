SET @CGUID := 10006841;

SET @NPCTEXTID := 600132;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 241507, 2738, 15336, 15792, '0', '0', 0, 0, 0, 1315.8004150390625, -1110.4617919921875, -105.091537475585937, 1.481648564338684082, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748); -- Om'volt (Area: The Oasis - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `faction`=35, `npcflag`=65665, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=241507; -- Om'volt

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` = 241507);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(241507, 0, 0, 0, 3008, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62748); -- 241507 (Om'volt) - CanSwim

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=320767 WHERE (`Entry`=241507 AND `DifficultyID`=0); -- Om'volt

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`MenuID`=38685 AND `CreatureID`=241507);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(241507, 38685, 62748); -- Om'volt

DELETE FROM `gossip_menu` WHERE (`MenuID`=38685 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38685, @NPCTEXTID+0, 62748); -- 241507 (Om'volt)

DELETE FROM `gossip_menu_option` WHERE `MenuID`=38685;
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(38685, 132910, 1, 1, 'I\'d like to browse your goods.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62748),
(38685, 132911, 0, 5, 'Make this inn your home.', 2822, 0, 0, 0, 0, 58815, 0, 0, NULL, 0, NULL, NULL, 62748); -- OptionBroadcastTextID: 2822 - 162070

-- NPC Text
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 286496, 0, 0, 0, 0, 0, 0, 0, 62748); -- 241507 (Om'volt)

-- Vendor
DELETE FROM `npc_vendor` WHERE `entry`=241507;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(241507, 9, 247882, 0, 0, 1, 0, 0, 62748), -- Phase Regulator
(241507, 8, 247699, 0, 0, 1, 0, 0, 62748), -- Coagulated "Milk" Protein
(241507, 7, 247700, 0, 0, 1, 0, 0, 62748), -- Genuine K'areshi Honey
(241507, 6, 247698, 0, 0, 1, 0, 0, 62748), -- Deep-Fired Devourer Legs
(241507, 5, 247696, 0, 0, 1, 0, 0, 62748), -- Pungent Smelling Salts
(241507, 4, 247694, 0, 0, 1, 0, 0, 62748), -- Snifted Void Essence
(241507, 3, 247695, 0, 0, 1, 0, 0, 62748), -- Sparkling Mana Supplement
(241507, 2, 247692, 0, 0, 1, 0, 0, 62748), -- K'areshi Grain Fluff
(241507, 1, 247693, 0, 0, 1, 0, 0, 62748); -- Fermented Warpstalker Niblets
