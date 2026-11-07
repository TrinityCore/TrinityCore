SET @CGUID := 10006840;

SET @NPCTEXTID := 600131;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 244485, 2738, 15336, 15792, '0', '0', 0, 0, 1, 1333.6146240234375, -1009.57122802734375, -97.1505813598632812, 3.755923271179199218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62748); -- Distributor Ba'nacl (Area: The Oasis - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `faction`=35, `npcflag`=209, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=244485; -- Distributor Ba'nacl

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` = 244485);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(244485, 0, 0, 0, 3008, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62748); -- 244485 (Distributor Ba'nacl) - CanSwim

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=323830 WHERE (`Entry`=244485 AND `DifficultyID`=0); -- Distributor Ba'nacl

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`MenuID`=11905 AND `CreatureID`=244485);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(244485, 11905, 62748); -- Distributor Ba'nacl

DELETE FROM `gossip_menu` WHERE (`MenuID`=11905 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11905, @NPCTEXTID+0, 62748); -- 244485 (Distributor Ba'nacl)

DELETE FROM `gossip_menu_option` WHERE `MenuID`=11905;
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(11905, 38266, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62748),
(11905, 38267, 1, 1, 'Let me browse your goods.', 2823, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62748); -- OptionBroadcastTextID: 2823 - 7509 - 8097

-- Trainer
DELETE FROM `creature_trainer` WHERE (`CreatureID`=244485 AND `MenuID`=11905);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(244485, 10, 11905, 0);

-- NPC Text
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 45086, 0, 0, 0, 0, 0, 0, 0, 62748); -- 244485 (Distributor Ba'nacl)

-- Vendor
DELETE FROM `npc_vendor` WHERE `entry`=244485;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(244485, 8, 6533, 0, 0, 1, 0, 0, 62748), -- Aquadynamic Fish Attractor
(244485, 7, 6532, 0, 0, 1, 0, 0, 62748), -- Bright Baubles
(244485, 6, 6530, 0, 0, 1, 0, 0, 62748), -- Nightcrawlers
(244485, 5, 6529, 0, 0, 1, 0, 0, 62748), -- Shiny Bauble
(244485, 4, 136377, 0, 0, 1, 0, 0, 62748), -- Oversized Bobber
(244485, 3, 6365, 0, 0, 1, 0, 0, 62748), -- Strong Fishing Pole
(244485, 2, 6256, 0, 0, 1, 0, 0, 62748), -- Fishing Pole
(244485, 1, 228954, 0, 0, 1, 0, 0, 62748); -- Angler's Guide
