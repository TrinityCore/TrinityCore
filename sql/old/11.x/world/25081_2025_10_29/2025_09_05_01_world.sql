SET @CGUID := 10006838;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 245282, 2738, 15336, 0, '0', '0', 0, 0, 0, 1114.638916015625, 1123.673583984375, -75.5678253173828125, 1.375980257987976074, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62748); -- Warpweaver Lo'rant (Area: 0 - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `faction`=35, `npcflag`=268435585, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `VerifiedBuild`=62748 WHERE `entry`=245282; -- Warpweaver Lo'rant

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` = 245282);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(245282, 0, 0, 0, 3008, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62748); -- 245282 (Warpweaver Lo'rant) 

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=324678 WHERE (`Entry`=245282 AND `DifficultyID`=0); -- Warpweaver Lo'rant

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`MenuID`=21043 AND `CreatureID`=245282);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(245282, 21043, 62748); -- Warpweaver Lo'rant

UPDATE `gossip_menu_addon` SET `VerifiedBuild`=62748 WHERE `MenuID`=21043;
UPDATE `gossip_menu_option` SET `GossipOptionID`=46949, `GossipNpcOptionID`=32139, `VerifiedBuild`=62748 WHERE (`MenuID`=21043 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=46950, `OptionBroadcastTextID`=2583, `ActionMenuID`=0, `VerifiedBuild`=62748 WHERE (`MenuID`=21043 AND `OptionID`=1); -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967


DELETE FROM `npc_vendor` WHERE `entry`=245282;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(245282, 83, 237244, 0, 7855, 1, 0, 0, 62748), -- Banded Violet War Legwraps
(245282, 82, 237241, 0, 7855, 1, 0, 0, 62748), -- Banded Sunny War Legwraps
(245282, 81, 237242, 0, 7855, 1, 0, 0, 62748), -- Banded Snowy War Legwraps
(245282, 80, 237246, 0, 7855, 1, 0, 0, 62748), -- Banded Rosy War Legwraps
(245282, 79, 237245, 0, 7855, 1, 0, 0, 62748), -- Banded Plum War Legwraps
(245282, 78, 237255, 0, 7855, 1, 0, 0, 62748), -- Banded Midnight War Legwraps
(245282, 77, 237249, 0, 7855, 1, 0, 0, 62748), -- Banded Lively War Legwraps
(245282, 76, 237257, 0, 7855, 1, 0, 0, 62748), -- Banded Grassy War Legwraps
(245282, 75, 237248, 0, 7855, 1, 0, 0, 62748), -- Banded Faded War Legwraps
(245282, 74, 237252, 0, 7855, 1, 0, 0, 62748), -- Banded Deep War Legwraps
(245282, 73, 237256, 0, 7855, 1, 0, 0, 62748), -- Banded Crimson War Legwraps
(245282, 72, 237253, 0, 7855, 1, 0, 0, 62748), -- Banded Cloudy War Legwraps
(245282, 71, 237247, 0, 7855, 1, 0, 0, 62748), -- Banded Carrot War Legwraps
(245282, 70, 237251, 0, 7855, 1, 0, 0, 62748), -- Banded Camo War Legwraps
(245282, 69, 237250, 0, 7855, 1, 0, 0, 62748), -- Banded Brick War Legwraps
(245282, 68, 237254, 0, 7855, 1, 0, 0, 62748), -- Banded Azure War Legwraps
(245282, 67, 237243, 0, 7855, 1, 0, 0, 62748), -- Banded Aquatic War Legwraps
(245282, 66, 233154, 0, 7856, 1, 0, 0, 62748), -- Banded Sepia War Wraps
(245282, 65, 237240, 0, 7855, 1, 0, 0, 62748), -- Banded Sepia War Legwraps
(245282, 64, 233171, 0, 7855, 1, 0, 0, 62748), -- Banded Sepia War Slippers
(245282, 63, 233081, 0, 7856, 1, 0, 0, 62748), -- Short Sepia War Skirt
(245282, 62, 233120, 0, 6296, 1, 0, 0, 62748), -- Short Sepia War Skirt and Leg Wraps
(245282, 61, 233098, 0, 7856, 1, 0, 0, 62748), -- Long Sepia War Skirt
(245282, 60, 233137, 0, 6296, 1, 0, 0, 62748), -- Long Sepia War Skirt and Leg Wraps
(245282, 59, 235021, 0, 7856, 1, 0, 0, 62748), -- Vigilante's Sepia Mask
(245282, 58, 230035, 0, 7856, 1, 0, 0, 62748), -- Prowler's Sepia Shoulder Cape
(245282, 57, 230166, 0, 6188, 1, 0, 0, 62748), -- Ensemble: Prowler's Sepia Headgear
(245282, 56, 210850, 0, 7856, 1, 0, 0, 62748), -- Trader's Sepia Sarong
(245282, 55, 212626, 0, 7856, 1, 0, 0, 62748), -- Dueler's Sepia Shoulder Cape
(245282, 54, 213518, 0, 7856, 1, 0, 0, 62748), -- Classic Sepia Tabard
(245282, 53, 213441, 0, 7856, 1, 0, 0, 62748), -- Earth Mother's Sepia Gloves
(245282, 52, 213430, 0, 7856, 1, 0, 0, 62748), -- Duelist's Midnight Doublet
(245282, 51, 213437, 0, 7856, 1, 0, 0, 62748), -- Duelist's Marble Doublet
(245282, 50, 213435, 0, 7856, 1, 0, 0, 62748), -- Duelist's Crimson Doublet
(245282, 49, 213434, 0, 7856, 1, 0, 0, 62748), -- Duelist's Royal Doublet
(245282, 48, 213433, 0, 7856, 1, 0, 0, 62748), -- Duelist's Ivy Doublet
(245282, 47, 213432, 0, 7856, 1, 0, 0, 62748), -- Duelist's Cedar Doublet
(245282, 46, 213431, 0, 7856, 1, 0, 0, 62748), -- Duelist's Navy Doublet
(245282, 45, 202308, 0, 7856, 1, 0, 0, 62748), -- Alley Skulker's Bandana
(245282, 44, 202307, 0, 7856, 1, 0, 0, 62748), -- Well-Worn Tricorne
(245282, 43, 202306, 0, 7856, 1, 0, 0, 62748), -- Dread Captain's Chapeau
(245282, 42, 202305, 0, 7856, 1, 0, 0, 62748), -- Stevedore's Skullcap
(245282, 41, 202304, 0, 7856, 1, 0, 0, 62748), -- Green Beanie
(245282, 40, 202303, 0, 7856, 1, 0, 0, 62748), -- Crimson Beanie
(245282, 39, 202301, 0, 7854, 1, 0, 0, 62748), -- Focalized Mana Accelerator
(245282, 38, 202300, 0, 7854, 1, 0, 0, 62748), -- Zealot's Prayer Staff
(245282, 37, 202298, 0, 7856, 1, 0, 0, 62748), -- Trader's Bicorne
(245282, 36, 202297, 0, 7854, 1, 0, 0, 62748), -- Jade Arcus
(245282, 35, 202296, 0, 7854, 1, 0, 0, 62748), -- Deathmantle Ripper
(245282, 34, 202295, 0, 7854, 1, 0, 0, 62748), -- Anointed Crusader's Claymore
(245282, 33, 190888, 0, 7855, 1, 0, 0, 62748), -- Embrace of the Great Dark Beyond
(245282, 32, 190858, 0, 7855, 1, 0, 0, 62748), -- Girdle of Chilled Embers
(245282, 31, 190830, 0, 7855, 1, 0, 0, 62748), -- Mad Thief's Boots
(245282, 30, 190803, 0, 7855, 1, 0, 0, 62748), -- Lost Acolyte's Boots
(245282, 29, 190697, 0, 7855, 1, 0, 0, 62748), -- Boots of a Broken World
(245282, 28, 190686, 0, 7854, 1, 0, 0, 62748), -- Anetheron's Edge
(245282, 27, 190673, 0, 7855, 1, 0, 0, 62748), -- Waistguard of the Infernal Eye
(245282, 26, 190544, 0, 7855, 1, 0, 0, 62748), -- Ultramafic Girdle
(245282, 25, 190429, 0, 7855, 1, 0, 0, 62748), -- Clasp of Ursine Rage
(245282, 24, 190202, 0, 7855, 1, 0, 0, 62748), -- Scoundrel's Missing Boots
(245282, 23, 190167, 0, 7855, 1, 0, 0, 62748), -- Vault Stalker's Greaves
(245282, 22, 190064, 0, 7855, 1, 0, 0, 62748), -- Ymirjar Berserker's Girdle
(245282, 21, 189870, 0, 7855, 1, 0, 0, 62748), -- Arcanofire Wrap
(245282, 20, 188249, 0, 7234, 1, 0, 0, 62748), -- Freezing Footguards
(245282, 19, 188248, 0, 7234, 1, 0, 0, 62748), -- Searing Stompers
(245282, 18, 188244, 0, 7235, 1, 0, 0, 62748), -- Virulent Gravetreaders
(245282, 17, 188243, 0, 7235, 1, 0, 0, 62748), -- Shadow-Stitched Stalkers
(245282, 16, 188237, 0, 7236, 1, 0, 0, 62748), -- Conjuror's Slippers
(245282, 15, 188236, 0, 7236, 1, 0, 0, 62748), -- Patroller's Footwear
(245282, 14, 151116, 0, 6211, 1, 50225, 0, 62748), -- Fashionable Undershirt
(245282, 13, 151120, 0, 6188, 1, 9206, 0, 62748), -- Ensemble: Righteous Battleplate
(245282, 12, 151119, 0, 6188, 1, 4617, 0, 62748), -- Ensemble: Der'izu Armor
(245282, 11, 151118, 0, 6188, 1, 0, 0, 62748), -- Ensemble: Obsidian Prowler's Garb
(245282, 10, 151117, 0, 6188, 1, 4619, 0, 62748), -- Ensemble: Mana-Etched Regalia
(245282, 9, 157577, 0, 6188, 1, 9206, 0, 62748), -- Ensemble: Goldspine Plate
(245282, 8, 157576, 0, 6188, 1, 4617, 0, 62748), -- Ensemble: Crimson Sentinel Garb
(245282, 7, 157574, 0, 6188, 1, 0, 0, 62748), -- Ensemble: Tundraspite Armor
(245282, 6, 157573, 0, 6188, 1, 4619, 0, 62748), -- Ensemble: Mindwrack Raiment
(245282, 5, 164378, 0, 6444, 1, 0, 0, 62748), -- Letter from an Admirer
(245282, 4, 168061, 0, 6188, 1, 9206, 0, 62748), -- Ensemble: Amaranthine Path Armor
(245282, 3, 168060, 0, 6188, 1, 4617, 0, 62748), -- Ensemble: Chainmail of the Timeless Hunt
(245282, 2, 168059, 0, 6188, 1, 0, 0, 62748), -- Ensemble: Restless Dreambound Battlegear
(245282, 1, 168058, 0, 6188, 1, 4619, 0, 62748); -- Ensemble: Tranquil Spiritbind Regalia
