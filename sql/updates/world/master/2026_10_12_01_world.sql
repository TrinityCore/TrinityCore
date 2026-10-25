SET @REFERENCEID := 350000;

-- Randolph Moloch
UPDATE `creature_template_difficulty` SET `LootID` = 46383, `GoldMin` = 55000, `GoldMax` = 75000 WHERE `Entry` = 46383;

DELETE FROM `creature_loot_template` WHERE `Entry` = 46383;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(46383, 1, @REFERENCEID+0, 100, 0, 1, 0, 1, 2, 'Reference Randolph Moloch Boss loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 63344, 0, 0, 1, 1, 1, 1, 'Standard Issue Prisoner Shoes'),
(@REFERENCEID+0, 0, 63345, 0, 0, 1, 1, 1, 1, 'Noble''s Robe'),
(@REFERENCEID+0, 0, 63346, 0, 0, 1, 1, 1, 1, 'Wicked Dagger'),
(@REFERENCEID+0, 0, 132570, 0, 0, 1, 1, 1, 1, 'Stolen Guards Chain Boots'),
(@REFERENCEID+0, 0, 151077, 0, 0, 1, 1, 1, 1, 'Cast Iron Waistplate');

-- Lord Overheat
UPDATE `creature_template_difficulty` SET `LootID` = 46264, `GoldMin` = 55000, `GoldMax` = 75000 WHERE `Entry` = 46264;

DELETE FROM `creature_loot_template` WHERE `Entry` = 46264;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(46264, 1, @REFERENCEID+1, 100, 0, 1, 0, 1, 2, 'Reference Lord Overheat Boss loot'),
(46264, 0, 62305, 100, 1, 1, 0, 1, 1, 'Lord Overheat''s Fiery Core');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+1;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+1, 0, 4676, 0, 0, 1, 1, 1, 1, 'Skeletal Gauntlets'),
(@REFERENCEID+1, 0, 1929, 0, 0, 1, 1, 1, 1, 'Silk-Threaded Trousers'),
(@REFERENCEID+1, 0, 5967, 0, 0, 1, 1, 1, 1, 'Girdle of Nobility'),
(@REFERENCEID+1, 0, 151075, 0, 0, 1, 1, 1, 1, 'Cinderstitch Tunic'),
(@REFERENCEID+1, 0, 151076, 0, 0, 1, 1, 1, 1, 'Fire-Hardened Shackles');

-- Hogger
UPDATE `creature_template_difficulty` SET `LootID` = 46254, `GoldMin` = 55000, `GoldMax` = 75000 WHERE `Entry` = 46254;

DELETE FROM `creature_loot_template` WHERE `Entry` = 46254;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(46254, 1, @REFERENCEID+2, 100, 0, 1, 0, 1, 2, 'Reference Hogger Boss loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+2;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+2, 0, 2168, 0, 0, 1, 1, 1, 1, 'Corpse Rompers'),
(@REFERENCEID+2, 0, 1934, 0, 0, 1, 1, 1, 1, 'Hogger''s Trousers'),
(@REFERENCEID+2, 0, 1959, 0, 0, 1, 1, 1, 1, 'Cold Iron Pick'),
(@REFERENCEID+2, 0, 132569, 0, 0, 1, 1, 1, 1, 'Stolen Jailer''s Greaves'),
(@REFERENCEID+2, 0, 151074, 0, 0, 1, 1, 1, 1, 'Turnkey''s Pauldrons');

-- Update Difficulty
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (46254,46264,46383) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46254 AND `DifficultyID`=1); -- 46254 (Hogger) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46264 AND `DifficultyID`=1); -- 46264 (Lord Overheat) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46383 AND `DifficultyID`=1); -- 46383 (Randolph Moloch) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46249 AND `DifficultyID`=1); -- 46249 (Riverpaw Slayer) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46375 AND `DifficultyID`=1); -- 46375 (Rowdy Troublemaker) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46250 AND `DifficultyID`=1); -- 46250 (Riverpaw Poacher) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46263 AND `DifficultyID`=1); -- 46263 (Slag Fury) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `StaticFlags3`=0x4, `VerifiedBuild`=69933 WHERE (`Entry`=46411 AND `DifficultyID`=1); -- 46411 (Lillian's Lightwell) - Sessile - DoNotFadeIn
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=69933 WHERE (`DifficultyID`=1 AND `Entry` IN (46410,46409,46300,46407,46417,46405));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46251 AND `DifficultyID`=1); -- 46251 (Riverpaw Looter) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46262 AND `DifficultyID`=1); -- 46262 (Rumbling Earth) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=-3, `VerifiedBuild`=69933 WHERE (`Entry`=46299 AND `DifficultyID`=1); -- 46299 (Imprisoned Thug) - 
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46482 AND `DifficultyID`=1); -- 46482 (Mortimer Moloch) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46261 AND `DifficultyID`=1); -- 46261 (Enraged Fire Elemental) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46252 AND `DifficultyID`=1); -- 46252 (Riverpaw Shaman) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46248 AND `DifficultyID`=1); -- 46248 (Riverpaw Basher) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=1, `VerifiedBuild`=69933 WHERE (`Entry`=46408 AND `DifficultyID`=1); -- 46408 (Injured Stockade Rifleman) - Amphibious
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2951, `StaticFlags1`=0x100, `VerifiedBuild`=69933 WHERE (`Entry`=53488 AND `DifficultyID`=0); -- 53488 (Summon Enabler Stalker) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46381 AND `DifficultyID`=1); -- 46381 (Shifty Thief) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `VerifiedBuild`=69933 WHERE (`Entry`=46406 AND `DifficultyID`=1); -- 46406 (Stockade Rifleman) - Amphibious
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46382 AND `DifficultyID`=1); -- 46382 (Petty Criminal) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46379 AND `DifficultyID`=1); -- 46379 (Vicious Thug) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=69933 WHERE (`Entry`=46260 AND `DifficultyID`=1); -- 46260 (Searing Destroyer) - Amphibious, CanSwim
