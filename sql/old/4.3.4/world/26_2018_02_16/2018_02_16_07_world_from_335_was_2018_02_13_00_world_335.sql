/*
-- Remove unique items from reference table 24064
DELETE FROM `reference_loot_template` WHERE `Entry`=24064 AND `Item` IN (911, 920, 1076, 1406, 1455, 1459, 1461, 1462, 2034, 2232, 3429);

-- Add former items from reference table 24064 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (911, 920, 1076, 1406, 1455, 2034, 2232, 3429);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `Comment`) VALUES
(889,  911,  0.1, 0, "Splinter Fist Ogre - Ironwood Treebranch"),
(215,  920,  0.1, 0, "Defias Night Runner - Wicked Spiked Mace"),
(909,  920,  0.1, 0, "Defias Night Blade - Wicked Spiked Mace"),
(1706, 1076, 1,   0, "Defias Prisoner - Defias Renegade Ring"),
(1711, 1076, 1,   0, "Defias Convict - Defias Renegade Ring"),
(1715, 1076, 1,   0, "Defias Insurgent - Defias Renegade Ring"),
(1708, 1076, 1,   0, "Defias Inmate - Defias Renegade Ring"),
(1707, 1076, 1,   0, "Defias Captive - Defias Renegade Ring"),
(544,  1406, 0.1, 0, "Murloc Nightcrawler - Pearl-encrusted Spear"),
(435,  1455, 0.1, 0, "Blackrock Champion - Blackrock Champion's Axe"),
(4464, 1455, 0.1, 0, "Blackrock Gladiator - Blackrock Champion's Axe"),
(4809, 2034, 1,   0, "Twilight Acolyte - Scholarly Robes"),
(4811, 2034, 1,   0, "Twilight Aquamancer - Scholarly Robes"),
(4810, 2034, 1,   0, "Twilight Reaver - Scholarly Robes"),
(4814, 2034, 1,   0, "Twilight Elementalist - Scholarly Robes"),
(4813, 2034, 1,   0, "Twilight Shadowmage - Scholarly Robes"),
(4812, 2034, 1,   0, "Twilight Loreseeker - Scholarly Robes"),
(205,  2232, 0.1, 0, "Nightbane Dark Runner - Dark Runner Boots"),
(2427, 3429, 1,   0, "Jailor Eston - Guardsman Belt"),
(2428, 3429, 1,   0, "Jailor Marlgen - Guardsman Belt");
*/
