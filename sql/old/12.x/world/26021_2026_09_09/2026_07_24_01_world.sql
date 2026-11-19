SET @CGUID := 3000105;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 39887, 0, 4815, 5012, '0', 0, 0, 0, 0, -4440.33154296875, 3817.346435546875, -82.73834228515625, 3.298672199249267578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Captain Taylor (Area: The Briny Cutter - Difficulty: 0) CreateObject1 (Auras: 76152 - Transform Taylor, 60921 - Generic Quest Invisibility 3)
(@CGUID+1, 40680, 0, 4815, 5012, '0', 0, 0, 0, 1, -4440.76416015625, 3813.806396484375, -82.4865341186523437, 4.031710624694824218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Stormwind Soldier (Area: The Briny Cutter - Difficulty: 0) CreateObject1 (Auras: 60921 - Generic Quest Invisibility 3)
(@CGUID+2, 40680, 0, 4815, 5012, '0', 0, 0, 0, 1, -4461.63720703125, 3801.79248046875, -82.1959991455078125, 0.855211317539215087, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Stormwind Soldier (Area: The Briny Cutter - Difficulty: 0) CreateObject1 (Auras: 60921 - Generic Quest Invisibility 3)
(@CGUID+3, 40680, 0, 4815, 5012, '0', 0, 0, 0, 1, -4452.5849609375, 3803.5625, -81.7990951538085937, 2.600540637969970703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Stormwind Soldier (Area: The Briny Cutter - Difficulty: 0) CreateObject1 (Auras: 60921 - Generic Quest Invisibility 3)
(@CGUID+4, 40680, 0, 4815, 5012, '0', 0, 0, 0, 1, -4441.59033203125, 3810.9921875, -82.1044464111328125, 2.042035102844238281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Stormwind Soldier (Area: The Briny Cutter - Difficulty: 0) CreateObject1 (Auras: 60921 - Generic Quest Invisibility 3)
(@CGUID+5, 40680, 0, 4815, 5012, '0', 0, 0, 0, 1, -4463.53662109375, 3804.56689453125, -82.804779052734375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Stormwind Soldier (Area: The Briny Cutter - Difficulty: 0) CreateObject1 (Auras: 60921 - Generic Quest Invisibility 3)
(@CGUID+6, 40680, 0, 4815, 5012, '0', 0, 0, 0, 1, -4436.66845703125, 3815.68310546875, -82.4674835205078125, 2.670353651046752929, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68887); -- Stormwind Soldier (Area: The Briny Cutter - Difficulty: 0) CreateObject1 (Auras: 60921 - Generic Quest Invisibility 3)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '76152 60921'); -- Captain Taylor - 76152 - Transform Taylor, 60921 - Generic Quest Invisibility 3

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (40680 /*40680 (Stormwind Soldier) - Generic Quest Invisibility 3*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(40680, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '60921'); -- 40680 (Stormwind Soldier) - Generic Quest Invisibility 3

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000000, `VerifiedBuild`=68887 WHERE (`Entry`=40696 AND `DifficultyID`=0); -- 40696 (Stormwind Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000000, `VerifiedBuild`=68887 WHERE (`Entry`=40695 AND `DifficultyID`=0); -- 40695 (Stormwind Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000000, `VerifiedBuild`=68887 WHERE (`Entry`=40694 AND `DifficultyID`=0); -- 40694 (Stormwind Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000000, `VerifiedBuild`=68887 WHERE (`Entry`=40693 AND `DifficultyID`=0); -- 40693 (Stormwind Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000000, `VerifiedBuild`=68887 WHERE (`Entry`=40692 AND `DifficultyID`=0); -- 40692 (Stormwind Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000000, `VerifiedBuild`=68887 WHERE (`Entry`=40691 AND `DifficultyID`=0); -- 40691 (Stormwind Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000000, `VerifiedBuild`=68887 WHERE (`Entry`=40690 AND `DifficultyID`=0); -- 40690 (Captain Taylor) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x10000000, `VerifiedBuild`=68887 WHERE (`Entry`=40680 AND `DifficultyID`=0); -- 40680 (Stormwind Soldier) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=40680 AND `MenuID`=11423) OR (`CreatureID`=39887 AND `MenuID`=11424);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(40680, 11423, 68887), -- Stormwind Soldier
(39887, 11424, 68887); -- Captain Taylor

UPDATE `creature_template_gossip` SET `VerifiedBuild`=68887 WHERE (`CreatureID`=39887 AND `MenuID`=11305);

DELETE FROM `gossip_menu` WHERE (`MenuID`=11424 AND `TextID`=15908);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11424, 15908, 68887); -- 39887 (Captain Taylor)

-- SpellArea
DELETE FROM `spell_area` WHERE `spell` = 74146 AND `area` IN (5051,5052,5012);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUE
(74146, 5051, 25281, 25545, 0, 0, 2, 3, 64, 11), -- 74146 (Kelp Forest Quest Invisibility Detection 2)
(74146, 5052, 25281, 25545, 0, 0, 2, 3, 64, 11), -- 74146 (Kelp Forest Quest Invisibility Detection 2)
(74146, 5012, 25281, 25545, 0, 0, 2, 3, 64, 11); -- 74146 (Kelp Forest Quest Invisibility Detection 2)

DELETE FROM `spell_area` WHERE `spell` = 74147 AND `area` IN (5051,5052,5012);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUE
(74147, 5051, 25545, 0, 0, 0, 2, 3, 64, 11), -- 74147 (Kelp Forest Quest Invisibility Detection 3)
(74147, 5052, 25545, 0, 0, 0, 2, 3, 64, 11), -- 74147 (Kelp Forest Quest Invisibility Detection 3)
(74147, 5012, 25545, 0, 0, 0, 2, 3, 64, 11); -- 74147 (Kelp Forest Quest Invisibility Detection 3)
