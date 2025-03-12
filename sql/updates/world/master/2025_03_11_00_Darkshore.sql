-- quest_template_addon

INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestId`, `ExclusiveGroup`)
VALUES (13583, 13582, 13586, -13581)
ON DUPLICATE KEY UPDATE
    `PrevQuestID` = new_data.`PrevQuestID`,
    `NextQuestId` = new_data.`NextQuestId`,
    `ExclusiveGroup` = new_data.`ExclusiveGroup`;

INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`)
VALUES (13902, 13588)
ON DUPLICATE KEY UPDATE
    `PrevQuestID` = new_data.`PrevQuestID`;

INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`)
VALUES (13588, 13940)
ON DUPLICATE KEY UPDATE
    `PrevQuestID` = new_data.`PrevQuestID`;

INSERT INTO `quest_template_addon` (`ID`, `NextQuestId`, `ExclusiveGroup`)
VALUES (13581, 13586, -13581)
ON DUPLICATE KEY UPDATE
    `NextQuestId` = new_data.`NextQuestId`,
    `ExclusiveGroup` = new_data.`ExclusiveGroup`;

INSERT INTO `quest_template_addon` (`ID`, `NextQuestId`, `ExclusiveGroup`)
VALUES (13585, 13586, -13581)
ON DUPLICATE KEY UPDATE
    `NextQuestId` = new_data.`NextQuestId`,
    `ExclusiveGroup` = new_data.`ExclusiveGroup`;


-- creature_template_model

INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`)
VALUES (32985, 0, 5494, 1, 0, 59538)
ON DUPLICATE KEY UPDATE
    `CreatureDisplayID` = new_data.`CreatureDisplayID`,
    `DisplayScale` = new_data.`DisplayScale`,
    `Probability` = new_data.`Probability`,
    `VerifiedBuild` = new_data.`VerifiedBuild`;


-- creature_loot_template

INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`)
VALUES
(32935, 0, 44863, 40, 1), -- Corrupted Tide Crawler Flesh
(32935, 0, 2674, 41, 0), -- Crawler Meat
(32935, 0, 2675, 39, 0), -- Crawler Claw
(32935, 0, 774, 0.4, 0), -- Malachite
(32935, 0, 818, 0.3, 0), -- Tigerseye
(32935, 0, 727, 0.14, 0), -- Notched Shortsword
(32935, 0, 14086, 0.13, 0), -- Beaded Sandals
(32935, 0, 14089, 0.13, 0), -- Beaded Gloves
(32935, 0, 8180, 0.13, 0), -- Hunting Bow
(32935, 0, 8178, 0.13, 0), -- Training Sword
(32935, 0, 4562, 0.13, 0), -- Severing Axe
(32935, 0, 15473, 0.12, 0), -- Charger's Boots
(32935, 0, 4672, 0.12, 0), -- Ancestral Belt
(32935, 0, 2140, 0.12, 0), -- Carving Knife

(33009, 0, 44913, 33, 1), -- Corrupted Thistle Bear Guts
(33009, 0, 3173, 41, 0), -- Bear Meat
(33009, 0, 11415, 10, 0), -- Mixed Berries
(33009, 0, 774, 0.4, 0), -- Malachite
(33009, 0, 818, 0.3, 0), -- Tigerseye
(33009, 0, 727, 0.15, 0), -- Notched Shortsword
(33009, 0, 4562, 0.15, 0), -- Severing Axe
(33009, 0, 8178, 0.15, 0), -- Training Sword

(33905, 0, 44913, 33, 1), -- Corrupted Thistle Bear Guts
(33905, 0, 3173, 41, 0), -- Bear Meat
(33905, 0, 11415, 10, 0), -- Mixed Berries
(33905, 0, 774, 0.4, 0), -- Malachite
(33905, 0, 818, 0.3, 0), -- Tigerseye
(33905, 0, 727, 0.15, 0), -- Notched Shortsword
(33905, 0, 4562, 0.15, 0), -- Severing Axe
(33905, 0, 8178, 0.15, 0), -- Training Sword

(33311, 0, 67229, 48, 0), -- Stag Flank
(33311, 0, 774, 0.11, 0), -- Malachite
(33311, 0, 818, 0.3, 0), -- Tigerseye
(33311, 0, 3288, 0.3, 0), -- Tribal Vest
(33311, 0, 4577, 0.3, 0), -- Compact Shotgun
(33311, 0, 5069, 0.11, 0), -- Compact Shotgun

(33277, 0, 5523, 53, 0), -- Small Barnacled Clam
(33277, 0, 5784, 33, 0), -- Slimy Murloc Scale
(33277, 0, 5784, 10, 0), -- Raw Longjaw Mud Snapper
(33277, 0, 858, 4, 0), -- Lesser Healing Potion
(33277, 0, 1179, 2, 0), -- Ice Cold Milk
(33277, 0, 730, 45, 0), -- Murloc Eye

(33262, 0, 5523, 53, 0), -- Small Barnacled Clam
(33262, 0, 5784, 33, 0), -- Slimy Murloc Scale
(33262, 0, 5784, 10, 0), -- Raw Longjaw Mud Snapper
(33262, 0, 858, 4, 0), -- Lesser Healing Potion
(33262, 0, 1179, 2, 0), -- Ice Cold Milk
(33262, 0, 730, 45, 0), -- Murloc Eye

(32861, 0, 44830, 10, 1), -- Highborne Relic
(32861, 0, 2589, 71, 0), -- Linen Cloth
(32861, 0, 2287, 9, 0), -- Haunch of Meat
(32861, 0, 1179, 4, 0), -- Ice Cold Milk
(32861, 0, 2592, 4, 0), -- Wool Cloth
(32861, 0, 858, 2, 0), -- Lesser Healing Potion
(32861, 0, 2455, 1.1, 0), -- Minor Mana Potion
(32861, 0, 3770, 0.7, 0), -- Mutton Chop
(32861, 0, 818, 0.4, 0), -- Tigerseye

(33071, 0, 44942, 83, 1), -- Tigerseye
(33071, 0, 2589, 42, 0), -- Linen Cloth
(33071, 0, 2287, 5, 0), -- Haunch of Meat
(33071, 0, 1179, 2, 0), -- Ice Cold Milk
(33071, 0, 2592, 2, 0), -- Wool Cloth
(33071, 0, 858, 1.5, 0), -- Lesser Healing Potion
(33071, 0, 2455, 0.7, 0), -- Minor Mana Potion
(33071, 0, 818, 0.3, 0), -- Tigerseye
(33071, 0, 3770, 0.2, 0), -- Mutton Chop

(34046, 0, 2589, 65, 0), -- Linen Cloth
(34046, 0, 4605, 8, 0), -- Red-Speckled Mushroom
(34046, 0, 1179, 4, 0), -- Ice Cold Milk
(34046, 0, 2592, 3, 0), -- Wool Cloth
(34046, 0, 858, 2, 0), -- Lesser Healing Potion
(34046, 0, 2455, 1.2, 0), -- Minor Mana Potion
(34046, 0, 818, 0.7, 0), -- Tigerseye
(34046, 0, 3770, 0.2, 0), -- Mutton Chop

(34033, 0, 2589, 49, 0), -- Linen Cloth
(34033, 0, 4605, 6, 0), -- Red-Speckled Mushroom
(34033, 0, 1179, 3, 0), -- Ice Cold Milk
(34033, 0, 2592, 1.9, 0), -- Wool Cloth
(34033, 0, 858, 1.7, 0), -- Lesser Healing Potion
(34033, 0, 2455, 1, 0), -- Minor Mana Potion
(34033, 0, 818, 0.6, 0), -- Tigerseye

(32863, 0, 44979, 50, 0), -- Overseer's Orders
(32863, 0, 2589, 51, 0), -- Linen Cloth
(32863, 0, 2287, 6, 0), -- Haunch of Meat
(32863, 0, 1179, 3, 0), -- Ice Cold Milk
(32863, 0, 2592, 3, 0), -- Wool Cloth
(32863, 0, 858, 1.6, 0), -- Lesser Healing Potion
(32863, 0, 2455, 0.7, 0), -- Minor Mana Potion
(32863, 0, 3770, 0.4, 0), -- Mutton Chop
(32863, 0, 818, 0.4, 0), -- Tigerseye

(32869, 0, 2589, 51, 0), -- Linen Cloth
(32869, 0, 2287, 6, 0), -- Haunch of Meat
(32869, 0, 1179, 3, 0), -- Ice Cold Milk
(32869, 0, 2592, 3, 0), -- Wool Cloth
(32869, 0, 858, 1.6, 0), -- Lesser Healing Potion
(32869, 0, 2455, 0.7, 0), -- Minor Mana Potion
(32869, 0, 3770, 0.4, 0), -- Mutton Chop

(32970, 0, 45040, 98, 0), -- Shatterspear Torturer's Cage Key
(32970, 0, 2589, 36, 0), -- Linen Cloth
(32970, 0, 2287, 4, 0), -- Haunch of Meat
(32970, 0, 1179, 1.8, 0), -- Ice Cold Milk
(32970, 0, 2592, 1.1, 0), -- Wool Cloth
(32970, 0, 858, 1, 0), -- Lesser Healing Potion
(32970, 0, 3770, 0.8, 0), -- Mutton Chop
(32970, 0, 2455, 0.6, 0), -- Minor Mana Potion
(32970, 0, 929, 0.4, 0), -- Healing Potion
(32970, 0, 13446, 0.3, 0), -- Major Healing Potion

(34248, 0, 2589, 51, 0), -- Linen Cloth
(34248, 0, 2287, 6, 0), -- Haunch of Meat
(34248, 0, 1179, 3, 0), -- Ice Cold Milk
(34248, 0, 2592, 3, 0), -- Wool Cloth
(34248, 0, 858, 1.6, 0), -- Lesser Healing Potion
(34248, 0, 2455, 0.7, 0), -- Minor Mana Potion
(34248, 0, 3770, 0.4, 0), -- Mutton Chop

(32859, 0, 2589, 51, 0), -- Linen Cloth
(32859, 0, 2287, 6, 0), -- Haunch of Meat
(32859, 0, 1179, 3, 0), -- Ice Cold Milk
(32859, 0, 2592, 3, 0), -- Wool Cloth
(32859, 0, 858, 1.6, 0), -- Lesser Healing Potion
(32859, 0, 2455, 0.7, 0), -- Minor Mana Potion
(32859, 0, 3770, 0.4, 0), -- Mutton Chop

(33021, 0, 44966, 34, 1), -- Foul Ichor
(33021, 0, 774, 0.15, 0), -- Malachite

(33022, 0, 44966, 34, 1), -- Foul Ichor
(33022, 0, 44927, 34, 0), -- Corruptor's Master Key
(33022, 0, 774, 0.12, 0), -- Malachite

(33020, 0, 44966, 23, 1), -- Foul Ichor
(33020, 0, 44927, 7, 0), -- Corruptor's Master Key
(33020, 0, 2589, 42, 0), -- Linen Cloth
(33020, 0, 2592, 1.2, 0), -- Wool Cloth
(33020, 0, 4561, 0.4, 0), -- Scalping Tomahawk
(33020, 0, 774, 0.3, 0), -- Malachite

(33180, 0, 2589, 75, 0), -- Linen Cloth
(33180, 0, 2592, 3, 0), -- Wool Cloth
(33180, 0, 12808, 0.5, 0), -- Essence of Undeath
(33180, 0, 818, 0.5, 0), -- Tigerseye
(33180, 0, 14090, 0.3, 0), -- Beaded Britches
(33180, 0, 5069, 0.3, 0), -- Fire Wand

(33179, 0, 2589, 75, 0), -- Linen Cloth
(33179, 0, 2592, 3, 0), -- Wool Cloth
(33179, 0, 12808, 0.5, 0), -- Essence of Undeath
(33179, 0, 818, 0.5, 0), -- Tigerseye
(33179, 0, 14090, 0.3, 0), -- Beaded Britches
(33179, 0, 5069, 0.3, 0), -- Fire Wand

(33206, 0, 2589, 52, 0), -- Linen Cloth
(33206, 0, 5523, 52, 0), -- Small Barnacled Clam
(33206, 0, 6289, 6, 0), -- Raw Longjaw Mud Snapper
(33206, 0, 1179, 3, 0), -- Ice Cold Milk
(33206, 0, 2592, 3, 0), -- Wool Cloth
(33206, 0, 858, 1.7, 0), -- Lesser Healing Potion
(33206, 0, 5069, 0.3, 0), -- Fire Wand

(33207, 0, 2589, 52, 0), -- Linen Cloth
(33207, 0, 5523, 52, 0), -- Small Barnacled Clam
(33207, 0, 6289, 6, 0), -- Raw Longjaw Mud Snapper
(33207, 0, 1179, 3, 0), -- Ice Cold Milk
(33207, 0, 2592, 3, 0), -- Wool Cloth
(33207, 0, 858, 1.7, 0), -- Lesser Healing Potion
(33207, 0, 5069, 0.3, 0), -- Fire Wand

(34304, 0, 6889, 64, 0), -- Small Egg
(34304, 0, 2589, 28, 0), -- Linen Cloth
(34304, 0, 17056, 9, 0), -- Light Feather
(34304, 0, 2592, 9, 0), -- Wool Cloth
(34304, 0, 2287, 4, 0), -- Haunch of Meat
(34304, 0, 1179, 1.9, 0), -- Ice Cold Milk
(34304, 0, 858, 1.2, 0), -- Lesser Healing Potion
(34304, 0, 2455, 1.2, 0), -- Minor Mana Potion

(34385, 0, 46692, 100, 1), -- Elune's Torch
(34385, 0, 6889, 64, 0), -- Small Egg
(34385, 0, 2589, 28, 0), -- Linen Cloth
(34385, 0, 17056, 9, 0), -- Light Feather
(34385, 0, 2592, 9, 0), -- Wool Cloth
(34385, 0, 2287, 4, 0), -- Haunch of Meat
(34385, 0, 1179, 1.9, 0), -- Ice Cold Milk
(34385, 0, 858, 1.2, 0), -- Lesser Healing Potion
(34385, 0, 2455, 1.2, 0), -- Minor Mana Potion

(33083, 0, 7067, 1.2, 0), -- Elemental Earth
(33083, 0, 7075, 0.4, 0), -- Core of Earth
(33083, 0, 7076, 0.3, 0), -- Essence of Earth
(33083, 0, 1210, 0.17, 0), -- Shadowgem
(33083, 0, 818, 0.17, 0), -- Tigerseye

(33057, 0, 2589, 46, 0), -- Linen Cloth
(33057, 0, 2592, 15, 0), -- Wool Cloth
(33057, 0, 414, 7, 0), -- Dalaran Sharp
(33057, 0, 1179, 3, 0), -- Ice Cold Milk
(33057, 0, 858, 2, 0), -- Lesser Healing Potion
(33057, 0, 2455, 0.7, 0), -- Minor Mana Potion

(32890, 0, 7070, 1.5, 0), -- Elemental Water
(32890, 0, 7079, 0.5, 0), -- Globe of Water

(32888, 0, 44968, 0.12, 1), -- Twilight Plans
(32888, 0, 2589, 67, 0), -- Linen Cloth
(32888, 0, 414, 8, 0), -- Dalaran Sharp
(32888, 0, 1179, 3, 0), -- Ice Cold Milk
(32888, 0, 2592, 3, 0), -- Wool Cloth
(32888, 0, 858, 2, 0), -- Lesser Healing Potion
(32888, 0, 2455, 1, 0), -- Minor Mana Potion

(33127, 0, 7074, 78, 0), -- Chipped Claw
(33127, 0, 5134, 13, 0), -- Small Furry Paw
(33127, 0, 4865, 3, 0), -- Ruined Pelt
(33127, 0, 818, 0.3, 0), -- Tigerseye
(33127, 0, 818, 0.14, 0), -- Short Bastard Sword
(33127, 0, 4569, 0.14, 0), -- Staunch Hammer
(33127, 0, 774, 0.11, 0), -- Malachite

(32989, 0, 44968, 0.12, 1), -- Twilight Plans
(32989, 0, 2589, 67, 0), -- Linen Cloth
(32989, 0, 414, 8, 0), -- Dalaran Sharp
(32989, 0, 1179, 3, 0), -- Ice Cold Milk
(32989, 0, 2592, 3, 0), -- Wool Cloth
(32989, 0, 858, 2, 0), -- Lesser Healing Potion
(32989, 0, 2455, 1, 0), -- Minor Mana Potion

(34302, 0, 7073, 62, 0), -- Broken Fang
(34302, 0, 3173, 42, 0), -- Bear Meat
(34302, 0, 11407, 25, 0), -- Torn Bear Pelt
(34302, 0, 2940, 3, 0), -- Bloody Bear Paw
(34302, 0, 3169, 2, 0), -- Chipped Bear Tooth
(34302, 0, 11406, 2, 0), -- Rotting Bear Carcass

(32997, 0, 44886, 79, 1), -- Fleetfoot's Tailfeathers
(32997, 0, 7096, 54, 0), -- Plucked Feather
(32997, 0, 5469, 40, 0), -- Strider Meat
(32997, 0, 5115, 23, 0), -- Broken Wishbone
(32997, 0, 17056, 8, 0), -- Light Feather
(32997, 0, 4775, 3, 0), -- Cracked Bill
(32997, 0, 11416, 2, 0), -- Delicate Ribcage
(32997, 0, 4776, 1.5, 0), -- Ruffled Feather
(32997, 0, 5114, 1.2, 0), -- Severed Talon

(33044, 0, 2589, 41, 0), -- Linen Cloth
(33044, 0, 2592, 31, 0), -- Wool Cloth
(33044, 0, 1179, 4, 0), -- Ice Cold Milk
(33044, 0, 858, 2, 0), -- Lesser Healing Potion
(33044, 0, 2455, 0.9, 0), -- Minor Mana Potion

(32860, 0, 44942, 83, 1), -- Shatterspear Amulet
(32860, 0, 2589, 41, 0), -- Linen Cloth
(32860, 0, 2592, 31, 0), -- Wool Cloth
(32860, 0, 1179, 4, 0), -- Ice Cold Milk
(32860, 0, 858, 2, 0), -- Lesser Healing Potion
(32860, 0, 2455, 0.9, 0), -- Minor Mana Potion

(33043, 0, 2589, 41, 0), -- Linen Cloth
(33043, 0, 2592, 31, 0), -- Wool Cloth
(33043, 0, 1179, 4, 0), -- Ice Cold Milk
(33043, 0, 858, 2, 0), -- Lesser Healing Potion
(33043, 0, 2455, 0.9, 0), -- Minor Mana Potion

(34413, 0, 2589, 20, 0), -- Linen Cloth
(34413, 0, 2592, 18, 0), -- Wool Cloth
(34413, 0, 4605, 4, 0), -- Red-Speckled Mushroom
(34413, 0, 1179, 2, 0), -- Ice Cold Milk
(34413, 0, 858, 1.2, 0), -- Lesser Healing Potion
(34413, 0, 1708, 1, 0), -- Sweet Nectar
(34413, 0, 2455, 0.5, 0), -- Minor Mana Potion

(34405, 0, 2589, 31, 0), -- Linen Cloth
(34405, 0, 2592, 25, 0), -- Wool Cloth
(34405, 0, 2287, 5, 0), -- Haunch of Meat
(34405, 0, 1179, 2, 0), -- Ice Cold Milk
(34405, 0, 858, 1.3, 0), -- Lesser Healing Potion
(34405, 0, 2455, 0.8, 0), -- Minor Mana Potion

(2237, 0, 7074, 75, 0), -- Chipped Claw
(2237, 0, 5135, 21, 0), -- Thin Black Claw
(2237, 0, 4813, 0.7, 0), -- Thin Black Claw

(2071, 0, 7074, 75, 0), -- Chipped Claw
(2071, 0, 5135, 21, 0), -- Thin Black Claw
(2071, 0, 4813, 0.7, 0), -- Thin Black Claw

(2070, 0, 7074, 75, 0), -- Chipped Claw
(2070, 0, 5135, 21, 0), -- Thin Black Claw
(2070, 0, 4813, 0.7, 0), -- Thin Black Claw

(34339, 0, 1468, 42, 0),
(34339, 0, 2589, 27, 0),
(34339, 0, 5523, 26, 0),
(34339, 0, 2592, 21, 0),
(34339, 0, 6289, 5, 0),
(34339, 0, 5785, 4, 0),
(34339, 0, 1179, 2, 0),

(34350, 0, 54632, 78, 0), -- Torn Flipper
(34350, 0, 54632, 10, 0), -- Broken Jaws
(34350, 0, 56051, 6, 0), -- Half-Digested Roe
(34350, 0, 56052, 3, 0), -- Quivering Flipper
(34350, 0, 56053, 0.9, 0), -- Dead Tangled Kelp
(34350, 0, 62268, 0.8, 0), -- Mangled Flipper

(32996, 0, 2589, 25, 0), -- Linen Cloth
(32996, 0, 2592, 20, 0), -- Wool Cloth
(32996, 0, 2287, 4, 0), -- Haunch of Meat
(32996, 0, 1179, 2, 0), -- Ice Cold Milk
(32996, 0, 858, 1.2, 0), -- Lesser Healing Potion
(32996, 0, 929, 0.8, 0), -- Healing potion
(32996, 0, 2455, 0.6, 0), -- Minor Mana Potion
(32996, 0, 1205, 0.5, 0), -- Melon juice
(32996, 0, 3312, 0.4, 0), -- Ceremonial Leather Bracers

(33079, 0, 5523, 52, 0), -- Small Barnacled Clam
(33079, 0, 2589, 31, 0), -- Linen Cloth
(33079, 0, 2592, 25, 0), -- Wool Cloth
(33079, 0, 6289, 6, 0), -- Raw Longjaw Mud Snapper
(33079, 0, 1179, 3, 0), -- Ice Cold Milk
(33079, 0, 858, 1.7, 0), -- Lesser Healing Potion
(33079, 0, 2455, 0.9, 0), -- Minor Mana Potion
(33079, 0, 6308, 0.6, 0), -- Raw Bristle Whisker Catfish
(33079, 0, 8959, 0.4, 0), -- Raw Spinefin Halibut

(32868, 0, 5523, 52, 0), -- Small Barnacled Clam
(32868, 0, 2589, 31, 0), -- Linen Cloth
(32868, 0, 2592, 25, 0), -- Wool Cloth
(32868, 0, 1179, 3, 0), -- Ice Cold Milk
(32868, 0, 858, 1.7, 0), -- Lesser Healing Potion
(32868, 0, 2455, 0.9, 0), -- Minor Mana Potion

(33980, 0, 5523, 52, 0), -- Small Barnacled Clam
(33980, 0, 2589, 31, 0), -- Linen Cloth
(33980, 0, 2592, 25, 0), -- Wool Cloth
(33980, 0, 1179, 3, 0), -- Ice Cold Milk
(33980, 0, 858, 1.7, 0), -- Lesser Healing Potion
(33980, 0, 2455, 0.9, 0), -- Minor Mana Potion

(32928, 0, 55983, 78, 0), -- Inert Elemental Scintilla
(32928, 0, 7070, 0.8, 0), -- Elemental Water
(32928, 0, 774, 0.6, 0), -- Malachite
(32928, 0, 60485, 0.5, 0), -- Crackling Crystals
(32928, 0, 7079, 0.4, 0), -- Globe of Water
(32928, 0, 7080, 0.3, 0), -- Essence of Water
(32928, 0, 2075, 1.8, 0), -- Heavy Mace

(32862, 0, 46318, 52, 1), -- Hellscream's Missive
(32862, 0, 5523, 52, 0), -- Small Barnacled Clam
(32862, 0, 2589, 31, 0), -- Linen Cloth
(32862, 0, 2592, 25, 0), -- Wool Cloth
(32862, 0, 1179, 3, 0), -- Ice Cold Milk
(32862, 0, 858, 1.7, 0), -- Lesser Healing Potion
(32862, 0, 2455, 0.9, 0), -- Minor Mana Potion

(32899, 0, 5523, 52, 0), -- Small Barnacled Clam
(32899, 0, 2589, 31, 0), -- Linen Cloth
(32899, 0, 2592, 25, 0), -- Wool Cloth
(32899, 0, 1179, 3, 0), -- Ice Cold Milk
(32899, 0, 858, 1.7, 0), -- Lesser Healing Potion
(32899, 0, 2455, 0.9, 0) -- Minor Mana Potion
ON DUPLICATE KEY UPDATE
    `Chance` = new_data.`Chance`,
    `QuestRequired` = new_data.`QuestRequired`;


-- creature_template_difficulty

INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LootID`)
VALUES
(32935, 0, 32935),
(33009, 0, 33009),
(33905, 0, 33905),
(33311, 0, 33311),
(33083, 0, 33083),
(32890, 0, 32890),
(33127, 0, 33127),
(34302, 0, 34302),
(32997, 0, 32997),
(34413, 0, 34413),
(2237, 0, 2237),
(2071, 0, 2071),
(2070, 0, 2070),
(34350, 0, 34350),
(32928, 0, 32928)
AS new_data
ON DUPLICATE KEY UPDATE
    `LootID` = new_data.`LootID`;

INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LootID`, `GoldMin`, `GoldMax`)
VALUES
(33277, 0, 33277, 8, 24),
(33262, 0, 33262, 8, 24),
(32861, 0, 32861, 8, 24),
(33071, 0, 33071, 2, 24),
(34046, 0, 34046, 2, 24),
(34033, 0, 34033, 2, 24),
(32863, 0, 32863, 2, 24),
(32869, 0, 32869, 2, 24),
(32970, 0, 32970, 2, 24),
(34248, 0, 34248, 2, 24),
(32859, 0, 32859, 2, 24),
(33021, 0, 33021, 2, 24),
(33022, 0, 33022, 2, 24),
(33020, 0, 33020, 12, 35),
(33180, 0, 33180, 2, 24),
(33179, 0, 33179, 2, 24),
(33206, 0, 33206, 10, 26),
(33207, 0, 33207, 10, 26),
(34304, 0, 34304, 10, 26),
(34385, 0, 34385, 10, 26),
(33057, 0, 33057, 10, 26),
(32888, 0, 32888, 10, 26),
(32989, 0, 32989, 10, 26),
(33044, 0, 33044, 10, 26),
(33043, 0, 33043, 10, 26),
(34405, 0, 34405, 10, 26),
(32996, 0, 32996, 10, 26),
(33079, 0, 33079, 10, 26),
(34339, 0, 34339, 10, 26),
(32860, 0, 32860, 10, 26),
(32868, 0, 32868, 10, 26),
(33980, 0, 33980, 10, 26),
(32862, 0, 32862, 10, 26),
(32899, 0, 32899, 10, 26)
AS new_data
ON DUPLICATE KEY UPDATE
    `LootID` = new_data.`LootID`,
    `GoldMin` = new_data.`GoldMin`,
    `GoldMax` = new_data.`GoldMax`;


-- creature

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`)
VALUES (10800002, 32960, 1, 0, 0, '0', 0, 0, 0, -1, 0, 0, 7445.79, -276.892, 13.6994, 1.61637, 300, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', NULL, 0)
ON DUPLICATE KEY UPDATE
    `id` = new_data.`id`,
    `map` = new_data.`map`,
    `zoneId` = new_data.`zoneId`,
    `areaId` = new_data.`areaId`,
    `spawnDifficulties` = new_data.`spawnDifficulties`,
    `phaseUseFlags` = new_data.`phaseUseFlags`,
    `PhaseId` = new_data.`PhaseId`,
    `PhaseGroup` = new_data.`PhaseGroup`,
    `terrainSwapMap` = new_data.`terrainSwapMap`,
    `modelid` = new_data.`modelid`,
    `equipment_id` = new_data.`equipment_id`,
    `position_x` = new_data.`position_x`,
    `position_y` = new_data.`position_y`,
    `position_z` = new_data.`position_z`,
    `orientation` = new_data.`orientation`,
    `spawntimesecs` = new_data.`spawntimesecs`,
    `wander_distance` = new_data.`wander_distance`,
    `currentwaypoint` = new_data.`currentwaypoint`,
    `curHealthPct` = new_data.`curHealthPct`,
    `MovementType` = new_data.`MovementType`,
    `npcflag` = new_data.`npcflag`,
    `unit_flags` = new_data.`unit_flags`,
    `unit_flags2` = new_data.`unit_flags2`,
    `unit_flags3` = new_data.`unit_flags3`,
    `ScriptName` = new_data.`ScriptName`,
    `StringId` = new_data.`StringId`,
    `VerifiedBuild` = new_data.`VerifiedBuild`;
