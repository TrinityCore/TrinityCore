-- quest_template_addon

DELETE FROM `quest_template_addon` WHERE `ID` = 13583;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestId`, `ExclusiveGroup`) VALUES (13583, 13582, 13586, -13581);
DELETE FROM `quest_template_addon` WHERE `ID` = 13902;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES (13902, 13588);
DELETE FROM `quest_template_addon` WHERE `ID` = 13588;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES (13588, 13940);
DELETE FROM `quest_template_addon` WHERE `ID` = 13581;
INSERT INTO `quest_template_addon` (`ID`, `NextQuestId`, `ExclusiveGroup`) VALUES (13581, 13586, -13581);
DELETE FROM `quest_template_addon` WHERE `ID` = 13585;
INSERT INTO `quest_template_addon` (`ID`, `NextQuestId`, `ExclusiveGroup`) VALUES (13585, 13586, -13581);

-- creature_template_model

DELETE FROM `creature_template_model` WHERE `CreatureID`=32985 AND `Idx`=0;
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES (32985, 0, 5494, 1, 0, 59538);


-- creature_loot_template

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`) VALUES
(32935, 44863, 40, 1), -- Corrupted Tide Crawler Flesh
(32935, 2674, 41, 0), -- Crawler Meat
(32935, 2675, 39, 0), -- Crawler Claw
(32935, 774, 0.4, 0), -- Malachite
(32935, 818, 0.3, 0), -- Tigerseye
(32935, 727, 0.14, 0), -- Notched Shortsword
(32935, 14086, 0.13, 0), -- Beaded Sandals
(32935, 14089, 0.13, 0), -- Beaded Gloves
(32935, 8180, 0.13, 0), -- Hunting Bow
(32935, 8178, 0.13, 0), -- Training Sword
(32935, 4562, 0.13, 0), -- Severing Axe
(32935, 15473, 0.12, 0), -- Charger's Boots
(32935, 4672, 0.12, 0), -- Ancestral Belt
(32935, 2140, 0.12, 0), -- Carving Knife

(33009, 44913, 33, 1), -- Corrupted Thistle Bear Guts
(33009, 3173, 41, 0), -- Bear Meat
(33009, 11415, 10, 0), -- Mixed Berries
(33009, 774, 0.4, 0), -- Malachite
(33009, 818, 0.3, 0), -- Tigerseye
(33009, 727, 0.15, 0), -- Notched Shortsword
(33009, 4562, 0.15, 0), -- Severing Axe
(33009, 8178, 0.15, 0), -- Training Sword

(33905, 44913, 33, 1), -- Corrupted Thistle Bear Guts
(33905, 3173, 41, 0), -- Bear Meat
(33905, 11415, 10, 0), -- Mixed Berries
(33905, 774, 0.4, 0), -- Malachite
(33905, 818, 0.3, 0), -- Tigerseye
(33905, 727, 0.15, 0), -- Notched Shortsword
(33905, 4562, 0.15, 0), -- Severing Axe
(33905, 8178, 0.15, 0), -- Training Sword

(33311, 67229, 48, 0), -- Stag Flank
(33311, 774, 0.11, 0), -- Malachite
(33311, 818, 0.3, 0), -- Tigerseye
(33311, 3288, 0.3, 0), -- Tribal Vest
(33311, 4577, 0.3, 0), -- Compact Shotgun
(33311, 5069, 0.11, 0), -- Compact Shotgun

(33277, 5523, 53, 0), -- Small Barnacled Clam
(33277, 5784, 33, 0), -- Slimy Murloc Scale
(33277, 5784, 10, 0), -- Raw Longjaw Mud Snapper
(33277, 858, 4, 0), -- Lesser Healing Potion
(33277, 1179, 2, 0), -- Ice Cold Milk
(33277, 730, 45, 0), -- Murloc Eye

(33262, 5523, 53, 0), -- Small Barnacled Clam
(33262, 5784, 33, 0), -- Slimy Murloc Scale
(33262, 5784, 10, 0), -- Raw Longjaw Mud Snapper
(33262, 858, 4, 0), -- Lesser Healing Potion
(33262, 1179, 2, 0), -- Ice Cold Milk
(33262, 730, 45, 0), -- Murloc Eye

(32861, 44830, 10, 1), -- Highborne Relic
(32861, 2589, 71, 0), -- Linen Cloth
(32861, 2287, 9, 0), -- Haunch of Meat
(32861, 1179, 4, 0), -- Ice Cold Milk
(32861, 2592, 4, 0), -- Wool Cloth
(32861, 858, 2, 0), -- Lesser Healing Potion
(32861, 2455, 1.1, 0), -- Minor Mana Potion
(32861, 3770, 0.7, 0), -- Mutton Chop
(32861, 818, 0.4, 0), -- Tigerseye

(33071, 44942, 83, 1), -- Tigerseye
(33071, 2589, 42, 0), -- Linen Cloth
(33071, 2287, 5, 0), -- Haunch of Meat
(33071, 1179, 2, 0), -- Ice Cold Milk
(33071, 2592, 2, 0), -- Wool Cloth
(33071, 858, 1.5, 0), -- Lesser Healing Potion
(33071, 2455, 0.7, 0), -- Minor Mana Potion
(33071, 818, 0.3, 0), -- Tigerseye
(33071, 3770, 0.2, 0), -- Mutton Chop

(34046, 2589, 65, 0), -- Linen Cloth
(34046, 4605, 8, 0), -- Red-Speckled Mushroom
(34046, 1179, 4, 0), -- Ice Cold Milk
(34046, 2592, 3, 0), -- Wool Cloth
(34046, 858, 2, 0), -- Lesser Healing Potion
(34046, 2455, 1.2, 0), -- Minor Mana Potion
(34046, 818, 0.7, 0), -- Tigerseye
(34046, 3770, 0.2, 0), -- Mutton Chop

(34033, 2589, 49, 0), -- Linen Cloth
(34033, 4605, 6, 0), -- Red-Speckled Mushroom
(34033, 1179, 3, 0), -- Ice Cold Milk
(34033, 2592, 1.9, 0), -- Wool Cloth
(34033, 858, 1.7, 0), -- Lesser Healing Potion
(34033, 2455, 1, 0), -- Minor Mana Potion
(34033, 818, 0.6, 0), -- Tigerseye

(32863, 44979, 50, 0), -- Overseer's Orders
(32863, 2589, 51, 0), -- Linen Cloth
(32863, 2287, 6, 0), -- Haunch of Meat
(32863, 1179, 3, 0), -- Ice Cold Milk
(32863, 2592, 3, 0), -- Wool Cloth
(32863, 858, 1.6, 0), -- Lesser Healing Potion
(32863, 2455, 0.7, 0), -- Minor Mana Potion
(32863, 3770, 0.4, 0), -- Mutton Chop
(32863, 818, 0.4, 0), -- Tigerseye

(32869, 2589, 51, 0), -- Linen Cloth
(32869, 2287, 6, 0), -- Haunch of Meat
(32869, 1179, 3, 0), -- Ice Cold Milk
(32869, 2592, 3, 0), -- Wool Cloth
(32869, 858, 1.6, 0), -- Lesser Healing Potion
(32869, 2455, 0.7, 0), -- Minor Mana Potion
(32869, 3770, 0.4, 0), -- Mutton Chop

(32970, 45040, 98, 0), -- Shatterspear Torturer's Cage Key
(32970, 2589, 36, 0), -- Linen Cloth
(32970, 2287, 4, 0), -- Haunch of Meat
(32970, 1179, 1.8, 0), -- Ice Cold Milk
(32970, 2592, 1.1, 0), -- Wool Cloth
(32970, 858, 1, 0), -- Lesser Healing Potion
(32970, 3770, 0.8, 0), -- Mutton Chop
(32970, 2455, 0.6, 0), -- Minor Mana Potion
(32970, 929, 0.4, 0), -- Healing Potion
(32970, 13446, 0.3, 0), -- Major Healing Potion

(34248, 2589, 51, 0), -- Linen Cloth
(34248, 2287, 6, 0), -- Haunch of Meat
(34248, 1179, 3, 0), -- Ice Cold Milk
(34248, 2592, 3, 0), -- Wool Cloth
(34248, 858, 1.6, 0), -- Lesser Healing Potion
(34248, 2455, 0.7, 0), -- Minor Mana Potion
(34248, 3770, 0.4, 0), -- Mutton Chop

(32859, 2589, 51, 0), -- Linen Cloth
(32859, 2287, 6, 0), -- Haunch of Meat
(32859, 1179, 3, 0), -- Ice Cold Milk
(32859, 2592, 3, 0), -- Wool Cloth
(32859, 858, 1.6, 0), -- Lesser Healing Potion
(32859, 2455, 0.7, 0), -- Minor Mana Potion
(32859, 3770, 0.4, 0), -- Mutton Chop

(33021, 44966, 34, 1), -- Foul Ichor
(33021, 774, 0.15, 0), -- Malachite

(33022, 44966, 34, 1), -- Foul Ichor
(33022, 44927, 34, 0), -- Corruptor's Master Key
(33022, 774, 0.12, 0), -- Malachite

(33020, 44966, 23, 1), -- Foul Ichor
(33020, 44927, 7, 0), -- Corruptor's Master Key
(33020, 2589, 42, 0), -- Linen Cloth
(33020, 2592, 1.2, 0), -- Wool Cloth
(33020, 4561, 0.4, 0), -- Scalping Tomahawk
(33020, 774, 0.3, 0), -- Malachite

(33180, 2589, 75, 0), -- Linen Cloth
(33180, 2592, 3, 0), -- Wool Cloth
(33180, 12808, 0.5, 0), -- Essence of Undeath
(33180, 818, 0.5, 0), -- Tigerseye
(33180, 14090, 0.3, 0), -- Beaded Britches
(33180, 5069, 0.3, 0), -- Fire Wand

(33179, 2589, 75, 0), -- Linen Cloth
(33179, 2592, 3, 0), -- Wool Cloth
(33179, 12808, 0.5, 0), -- Essence of Undeath
(33179, 818, 0.5, 0), -- Tigerseye
(33179, 14090, 0.3, 0), -- Beaded Britches
(33179, 5069, 0.3, 0), -- Fire Wand

(33206, 2589, 52, 0), -- Linen Cloth
(33206, 5523, 52, 0), -- Small Barnacled Clam
(33206, 6289, 6, 0), -- Raw Longjaw Mud Snapper
(33206, 1179, 3, 0), -- Ice Cold Milk
(33206, 2592, 3, 0), -- Wool Cloth
(33206, 858, 1.7, 0), -- Lesser Healing Potion
(33206, 5069, 0.3, 0), -- Fire Wand

(33207, 2589, 52, 0), -- Linen Cloth
(33207, 5523, 52, 0), -- Small Barnacled Clam
(33207, 6289, 6, 0), -- Raw Longjaw Mud Snapper
(33207, 1179, 3, 0), -- Ice Cold Milk
(33207, 2592, 3, 0), -- Wool Cloth
(33207, 858, 1.7, 0), -- Lesser Healing Potion
(33207, 5069, 0.3, 0), -- Fire Wand

(34304, 6889, 64, 0), -- Small Egg
(34304, 2589, 28, 0), -- Linen Cloth
(34304, 17056, 9, 0), -- Light Feather
(34304, 2592, 9, 0), -- Wool Cloth
(34304, 2287, 4, 0), -- Haunch of Meat
(34304, 1179, 1.9, 0), -- Ice Cold Milk
(34304, 858, 1.2, 0), -- Lesser Healing Potion
(34304, 2455, 1.2, 0), -- Minor Mana Potion

(34385, 6889, 64, 0), -- Small Egg
(34385, 2589, 28, 0), -- Linen Cloth
(34385, 17056, 9, 0), -- Light Feather
(34385, 2592, 9, 0), -- Wool Cloth
(34385, 2287, 4, 0), -- Haunch of Meat
(34385, 1179, 1.9, 0), -- Ice Cold Milk
(34385, 858, 1.2, 0), -- Lesser Healing Potion
(34385, 2455, 1.2, 0), -- Minor Mana Potion

(33083, 7067, 1.2, 0), -- Elemental Earth
(33083, 7075, 0.4, 0), -- Core of Earth
(33083, 7076, 0.3, 0), -- Essence of Earth
(33083, 1210, 0.17, 0), -- Shadowgem
(33083, 818, 0.17, 0), -- Tigerseye

(33057, 2589, 46, 0), -- Linen Cloth
(33057, 2592, 15, 0), -- Wool Cloth
(33057, 414, 7, 0), -- Dalaran Sharp
(33057, 1179, 3, 0), -- Ice Cold Milk
(33057, 858, 2, 0), -- Lesser Healing Potion
(33057, 2455, 0.7, 0), -- Minor Mana Potion

(32890, 7070, 1.5, 0), -- Elemental Water
(32890, 7079, 0.5, 0), -- Globe of Water

(32888, 44968, 0.12, 1), -- Twilight Plans
(32888, 2589, 67, 0), -- Linen Cloth
(32888, 414, 8, 0), -- Dalaran Sharp
(32888, 1179, 3, 0), -- Ice Cold Milk
(32888, 2592, 3, 0), -- Wool Cloth
(32888, 858, 2, 0), -- Lesser Healing Potion
(32888, 2455, 1, 0), -- Minor Mana Potion

(33127, 7074, 78, 0), -- Chipped Claw
(33127, 5134, 13, 0), -- Small Furry Paw
(33127, 4865, 3, 0), -- Ruined Pelt
(33127, 818, 0.3, 0), -- Tigerseye
(33127, 818, 0.14, 0), -- Short Bastard Sword
(33127, 4569, 0.14, 0), -- Staunch Hammer
(33127, 774, 0.11, 0), -- Malachite

(32989, 44968, 0.12, 1), -- Twilight Plans
(32989, 2589, 67, 0), -- Linen Cloth
(32989, 414, 8, 0), -- Dalaran Sharp
(32989, 1179, 3, 0), -- Ice Cold Milk
(32989, 2592, 3, 0), -- Wool Cloth
(32989, 858, 2, 0), -- Lesser Healing Potion
(32989, 2455, 1, 0), -- Minor Mana Potion

(34302, 7073, 62, 0), -- Broken Fang
(34302, 3173, 42, 0), -- Bear Meat
(34302, 11407, 25, 0), -- Torn Bear Pelt
(34302, 2940, 3, 0), -- Bloody Bear Paw
(34302, 3169, 2, 0), -- Chipped Bear Tooth
(34302, 11406, 2, 0), -- Rotting Bear Carcass

(32997, 44886, 79, 1), -- Fleetfoot's Tailfeathers
(32997, 7096, 54, 0), -- Plucked Feather
(32997, 5469, 40, 0), -- Strider Meat
(32997, 5115, 23, 0), -- Broken Wishbone
(32997, 17056, 8, 0), -- Light Feather
(32997, 4775, 3, 0), -- Cracked Bill
(32997, 11416, 2, 0), -- Delicate Ribcage
(32997, 4776, 1.5, 0), -- Ruffled Feather
(32997, 5114, 1.2, 0), -- Severed Talon

(33044, 2589, 41, 0), -- Linen Cloth
(33044, 2592, 31, 0), -- Wool Cloth
(33044, 1179, 4, 0), -- Ice Cold Milk
(33044, 858, 2, 0), -- Lesser Healing Potion
(33044, 2455, 0.9, 0), -- Minor Mana Potion

(32860, 44942, 83, 1), -- Shatterspear Amulet
(32860, 2589, 41, 0), -- Linen Cloth
(32860, 2592, 31, 0), -- Wool Cloth
(32860, 1179, 4, 0), -- Ice Cold Milk
(32860, 858, 2, 0), -- Lesser Healing Potion
(32860, 2455, 0.9, 0), -- Minor Mana Potion

(33043, 2589, 41, 0), -- Linen Cloth
(33043, 2592, 31, 0), -- Wool Cloth
(33043, 1179, 4, 0), -- Ice Cold Milk
(33043, 858, 2, 0), -- Lesser Healing Potion
(33043, 2455, 0.9, 0), -- Minor Mana Potion

(34413, 2589, 20, 0), -- Linen Cloth
(34413, 2592, 18, 0), -- Wool Cloth
(34413, 4605, 4, 0), -- Red-Speckled Mushroom
(34413, 1179, 2, 0), -- Ice Cold Milk
(34413, 858, 1.2, 0), -- Lesser Healing Potion
(34413, 1708, 1, 0), -- Sweet Nectar
(34413, 2455, 0.5, 0), -- Minor Mana Potion

(34405, 2589, 31, 0), -- Linen Cloth
(34405, 2592, 25, 0), -- Wool Cloth
(34405, 2287, 5, 0), -- Haunch of Meat
(34405, 1179, 2, 0), -- Ice Cold Milk
(34405, 858, 1.3, 0), -- Lesser Healing Potion
(34405, 2455, 0.8, 0), -- Minor Mana Potion

(2237, 7074, 75, 0), -- Chipped Claw
(2237, 5135, 21, 0), -- Thin Black Claw
(2237, 4813, 0.7, 0), -- Thin Black Claw

(2071, 7074, 75, 0), -- Chipped Claw
(2071, 5135, 21, 0), -- Thin Black Claw
(2071, 4813, 0.7, 0), -- Thin Black Claw

(2070, 7074, 75, 0), -- Chipped Claw
(2070, 5135, 21, 0), -- Thin Black Claw
(2070, 4813, 0.7, 0), -- Thin Black Claw

(34339, 1468, 42, 0),
(34339, 2589, 27, 0),
(34339, 5523, 26, 0),
(34339, 2592, 21, 0),
(34339, 6289, 5, 0),
(34339, 5785, 4, 0),
(34339, 1179, 2, 0),

(34350, 54632, 78, 0), -- Torn Flipper
(34350, 54632, 10, 0), -- Broken Jaws
(34350, 56051, 6, 0), -- Half-Digested Roe
(34350, 56052, 3, 0), -- Quivering Flipper
(34350, 56053, 0.9, 0), -- Dead Tangled Kelp
(34350, 62268, 0.8, 0), -- Mangled Flipper

(32996, 2589, 25, 0), -- Linen Cloth
(32996, 2592, 20, 0), -- Wool Cloth
(32996, 2287, 4, 0), -- Haunch of Meat
(32996, 1179, 2, 0), -- Ice Cold Milk
(32996, 858, 1.2, 0), -- Lesser Healing Potion
(32996, 929, 0.8, 0), -- Healing potion
(32996, 2455, 0.6, 0), -- Minor Mana Potion
(32996, 1205, 0.5, 0), -- Melon juice
(32996, 3312, 0.4, 0), -- Ceremonial Leather Bracers

(33079, 5523, 52, 0), -- Small Barnacled Clam
(33079, 2589, 31, 0), -- Linen Cloth
(33079, 2592, 25, 0), -- Wool Cloth
(33079, 6289, 6, 0), -- Raw Longjaw Mud Snapper
(33079, 1179, 3, 0), -- Ice Cold Milk
(33079, 858, 1.7, 0), -- Lesser Healing Potion
(33079, 2455, 0.9, 0), -- Minor Mana Potion
(33079, 6308, 0.6, 0), -- Raw Bristle Whisker Catfish
(33079, 8959, 0.4, 0), -- Raw Spinefin Halibut

(32868, 5523, 52, 0), -- Small Barnacled Clam
(32868, 2589, 31, 0), -- Linen Cloth
(32868, 2592, 25, 0), -- Wool Cloth
(32868, 1179, 3, 0), -- Ice Cold Milk
(32868, 858, 1.7, 0), -- Lesser Healing Potion
(32868, 2455, 0.9, 0), -- Minor Mana Potion

(33980, 5523, 52, 0), -- Small Barnacled Clam
(33980, 2589, 31, 0), -- Linen Cloth
(33980, 2592, 25, 0), -- Wool Cloth
(33980, 1179, 3, 0), -- Ice Cold Milk
(33980, 858, 1.7, 0), -- Lesser Healing Potion
(33980, 2455, 0.9, 0), -- Minor Mana Potion

(32928, 55983, 78, 0), -- Inert Elemental Scintilla
(32928, 7070, 0.8, 0), -- Elemental Water
(32928, 774, 0.6, 0), -- Malachite
(32928, 60485, 0.5, 0), -- Crackling Crystals
(32928, 7079, 0.4, 0), -- Globe of Water
(32928, 7080, 0.3, 0), -- Essence of Water
(32928, 2075, 1.8, 0), -- Heavy Mace

(32862, 46318, 52, 1), -- Hellscream's Missive
(32862, 5523, 52, 0), -- Small Barnacled Clam
(32862, 2589, 31, 0), -- Linen Cloth
(32862, 2592, 25, 0), -- Wool Cloth
(32862, 1179, 3, 0), -- Ice Cold Milk
(32862, 858, 1.7, 0), -- Lesser Healing Potion
(32862, 2455, 0.9, 0), -- Minor Mana Potion

(32899, 5523, 52, 0), -- Small Barnacled Clam
(32899, 2589, 31, 0), -- Linen Cloth
(32899, 2592, 25, 0), -- Wool Cloth
(32899, 1179, 3, 0), -- Ice Cold Milk
(32899, 858, 1.7, 0), -- Lesser Healing Potion
(32899, 2455, 0.9, 0) -- Minor Mana Potion
;


-- creature_template_difficulty

UPDATE `creature_template_difficulty` SET `LootID`=32935 WHERE `Entry`=32935 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33009 WHERE `Entry`=33009 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33905 WHERE `Entry`=33905 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33311 WHERE `Entry`=33311 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33277, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=33277 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33262, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=33262 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32861, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=32861 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33071, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=33071 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=34046, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=34046 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=34033, `GoldMin`=12, `GoldMax`=35 WHERE `Entry`=34033 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32863, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=32863 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32869, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=32869 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32970, `GoldMin`=12, `GoldMax`=35 WHERE `Entry`=32970 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=34248, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=34248 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32859, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=32859 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33021, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=33021 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33022, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=33022 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33020, `GoldMin`=12, `GoldMax`=35 WHERE `Entry`=33020 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33180, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=33180 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33179, `GoldMin`=8, `GoldMax`=24 WHERE `Entry`=33179 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33206, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=33206 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33207, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=33207 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=34304, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=34304 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=34385, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=34385 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33083 WHERE `Entry`=33083 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33057, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=33057 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32890 WHERE `Entry`=32890 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32888, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=32888 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33127 WHERE `Entry`=33127 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32989, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=32989 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=34302 WHERE `Entry`=34302 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32997 WHERE `Entry`=32997 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33044, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=33044 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33043, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=33043 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=34413 WHERE `Entry`=34413 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=34405, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=34405 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=2237 WHERE `Entry`=2237 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=2071 WHERE `Entry`=2071 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=2070 WHERE `Entry`=2070 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=34339, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=34339 AND `DifficultyID`=0;


UPDATE `creature_template_difficulty` SET `LootID`=34350 WHERE `Entry`=34350 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32996, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=32996 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33079, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=33079 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32928 WHERE `Entry`=32928 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32860, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=32860 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32868, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=32868 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=33980, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=33980 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32862, `GoldMin`=14, `GoldMax`=29 WHERE `Entry`=32862 AND `DifficultyID`=0;

UPDATE `creature_template_difficulty` SET `LootID`=32899, `GoldMin`=10, `GoldMax`=26 WHERE `Entry`=32899 AND `DifficultyID`=0;


-- creature

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES (10800002, 32960, 1, 0, 0, '0', 0, 0, 0, -1, 0, 0, 7445.79, -276.892, 13.6994, 1.61637, 300, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 0);
