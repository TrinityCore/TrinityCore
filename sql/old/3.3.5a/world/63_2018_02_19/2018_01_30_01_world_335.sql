-- Mindless Zombie
DELETE FROM `creature_loot_template` WHERE `Entry`=1501;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1501, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1501, 4604, 0, 15, 0, 1, 0, 1, 1, NULL), -- Forest Mushroom Cap
(1501, 24073, 24073, 5, 0, 1, 0, 1, 1, NULL), -- Junk
(1501, 11111, 11111, 0.5, 0, 1, 0, 1, 1, NULL); -- Bags

-- Wretched Ghoul
DELETE FROM `creature_loot_template` WHERE `Entry`=1502;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1502, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1502, 4604, 0, 15, 0, 1, 0, 1, 1, NULL), -- Forest Mushroom Cap
(1502, 24073, 24073, 5, 0, 1, 0, 1, 1, NULL), -- Junk
(1502, 11111, 11111, 0.5, 0, 1, 0, 1, 1, NULL); -- Bags

-- Rattlecage Skeleton
DELETE FROM `creature_loot_template` WHERE `Entry`=1890;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1890, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1890, 4604, 0, 15, 0, 1, 0, 1, 1, NULL), -- Forest Mushroom Cap
(1890, 3262, 0, 1, 0, 1, 0, 1, 1, NULL), -- Putrid Wooden Hammer (unique)
(1890, 6281, 0, 100, 1, 1, 0, 1, 1, NULL), -- Rattlecage Skull (quest)
(1890, 24073, 24073, 5, 0, 1, 0, 1, 1, NULL), -- Junk
(1890, 11111, 11111, 0.1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Young Nightweb Spider
DELETE FROM `creature_loot_template` WHERE `Entry`=1504;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1504, 1476, 0, 25, 0, 1, 1, 1, 2, NULL), -- Snapped Spider Limb
(1504, 7100, 0, 25, 0, 1, 1, 1, 2, NULL), -- Sticky Ichor
(1504, 7101, 0, 25, 0, 1, 1, 1, 2, NULL), -- Bug Eye
(1504, 24073, 24073, 2, 0, 1, 0, 1, 1, NULL), -- Junk
(1504, 11111, 11111, 0.1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Nightweb Spider
DELETE FROM `creature_loot_template` WHERE `Entry`=1505;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1505, 1476, 0, 25, 0, 1, 1, 1, 2, NULL), -- Snapped Spider Limb
(1505, 7100, 0, 25, 0, 1, 1, 1, 2, NULL), -- Sticky Ichor
(1505, 7101, 0, 25, 0, 1, 1, 1, 2, NULL), -- Bug Eye
(1505, 3263, 0, 1, 0, 1, 0, 1, 1, NULL), -- Webbed Pants (unique)
(1505, 24073, 24073, 2, 0, 1, 0, 1, 1, NULL), -- Junk
(1505, 11111, 11111, 0.1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Nightweb Matriach
DELETE FROM `creature_loot_template` WHERE `Entry`=1688;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1688, 1476, 0, 25, 0, 1, 1, 1, 1, NULL), -- Snapped Spider Limb
(1688, 7100, 0, 25, 0, 1, 1, 1, 1, NULL), -- Sticky Ichor
(1688, 7101, 0, 25, 0, 1, 1, 1, 1, NULL), -- Bug Eye
(1688, 3261, 0, 100, 0, 1, 0, 1, 1, NULL); -- Webbed Cloak (unique)

-- Scarlet Convert
DELETE FROM `creature_loot_template` WHERE `Entry`=1506;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1506, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1506, 2070, 0, 15, 0, 1, 0, 1, 1, NULL), -- Darnassian Bleu
(1506, 2754, 0, 1, 0, 1, 0, 1, 1, NULL), -- Tarnished Bastard Sword (unique)
(1506, 3266, 0, 100, 1, 1, 0, 1, 1, NULL), -- Scarlet Armband (quest)
(1506, 24073, 24073, 20, 0, 1, 0, 1, 1, NULL), -- Junk
(1506, 11111, 11111, 0.5, 0, 1, 0, 1, 1, NULL); -- Bags

-- Scarlet Initiate
-- Adds missing robe
DELETE FROM `creature_loot_template` WHERE `Entry`=1507;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1507, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1507, 2070, 0, 15, 0, 1, 0, 1, 1, NULL), -- Darnassian Bleu
(1507, 3260, 0, 1, 0, 1, 0, 1, 1, NULL), -- Scarlet Initiate Robes (unique)
(1507, 3266, 0, 100, 1, 1, 0, 1, 1, NULL), -- Scarlet Armband (quest)
(1507, 24073, 24073, 20, 0, 1, 0, 1, 1, NULL), -- Junk
(1507, 11111, 11111, 0.5, 0, 1, 0, 1, 1, NULL); -- Bags

-- Young Scavenger
DELETE FROM `creature_loot_template` WHERE `Entry`=1508;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1508, 3300, 0, 25, 0, 1, 1, 1, 1, NULL), -- Rabbit's Foot
(1508, 7074, 0, 25, 0, 1, 1, 1, 2, NULL), -- Chipped Claw
(1508, 4865, 0, 25, 0, 1, 1, 1, 2, NULL), -- Ruined Pelt
(1508, 7073, 0, 25, 0, 1, 1, 1, 2, NULL), -- Broken Fang
(1508, 3265, 0, 100, 1, 1, 0, 1, 1, NULL), -- Scavenger Paw (quest)
(1508, 24073, 24073, 2, 0, 1, 0, 1, 1, NULL), -- Junk
(1508, 11111, 11111, 0.1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Ragged Scavenger
DELETE FROM `creature_loot_template` WHERE `Entry`=1509;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1509, 3300, 0, 25, 0, 1, 1, 1, 1, NULL), -- Rabbit's Foot
(1509, 7074, 0, 25, 0, 1, 1, 1, 2, NULL), -- Chipped Claw
(1509, 4865, 0, 25, 0, 1, 1, 1, 2, NULL), -- Ruined Pelt
(1509, 7073, 0, 25, 0, 1, 1, 1, 2, NULL), -- Broken Fang
(1509, 3265, 0, 100, 1, 1, 0, 1, 1, NULL), -- Scavenger Paw (quest)
(1509, 24073, 24073, 2, 0, 1, 0, 1, 1, NULL), -- Junk
(1509, 11111, 11111, 0.1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Duskbat
DELETE FROM `creature_loot_template` WHERE `Entry`=1512;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1512, 6296, 0, 25, 0, 1, 1, 1, 1, NULL), -- Patch of Bat Hair
(1512, 7074, 0, 15, 0, 1, 1, 1, 2, NULL), -- Chipped Claw
(1512, 4865, 0, 15, 0, 1, 1, 1, 2, NULL), -- Ruined Pelt
(1512, 7073, 0, 15, 0, 1, 1, 1, 2, NULL), -- Broken Fang
(1512, 3264, 0, 100, 1, 1, 0, 1, 1, NULL), -- Duskbat Wing (quest)
(1512, 24073, 24073, 2, 0, 1, 0, 1, 1, NULL), -- Junk
(1512, 11111, 11111, 0.1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Mangy Duskbat
DELETE FROM `creature_loot_template` WHERE `Entry`=1513;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1513, 6296, 0, 25, 0, 1, 1, 1, 1, NULL), -- Patch of Bat Hair
(1513, 7074, 0, 15, 0, 1, 1, 1, 2, NULL), -- Chipped Claw
(1513, 4865, 0, 15, 0, 1, 1, 1, 2, NULL), -- Ruined Pelt
(1513, 7073, 0, 15, 0, 1, 1, 1, 2, NULL), -- Broken Fang
(1513, 3264, 0, 100, 1, 1, 0, 1, 1, NULL), -- Duskbat Wing (quest)
(1513, 24073, 24073, 2, 0, 1, 0, 1, 1, NULL), -- Junk
(1513, 11111, 11111, 0.1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Meven Korgal
DELETE FROM `creature_loot_template` WHERE `Entry`=1667;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1667, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1667, 2070, 0, 15, 0, 1, 0, 1, 1, NULL), -- Darnassian Bleu
(1667, 2885, 0, 100, 1, 1, 0, 1, 1, NULL), -- Scarlet Crusade Documents (quest)
(1667, 3266, 0, 100, 1, 1, 0, 1, 1, NULL), -- Scarlet Armband (quest)
(1667, 24073, 24073, 35, 0, 1, 0, 1, 1, NULL), -- Junk
(1667, 11111, 11111, 1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Stephen Bhartec
DELETE FROM `creature_loot_template` WHERE `Entry`=1916;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1916, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1916, 4604, 0, 15, 0, 1, 0, 1, 1, NULL), -- Forest Mushroom Cap
(1916, 3296, 0, 1, 0, 1, 0, 1, 1, NULL), -- Deadman Dagger (unique)
(1916, 24073, 24073, 20, 0, 1, 0, 1, 1, NULL), -- Junk
(1916, 11111, 11111, 1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Daniel Ulfman
DELETE FROM `creature_loot_template` WHERE `Entry`=1917;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1917, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1917, 4604, 0, 15, 0, 1, 0, 1, 1, NULL), -- Forest Mushroom Cap
(1917, 3293, 0, 1, 0, 1, 0, 1, 1, NULL), -- Deadman Cleaver (unique)
(1917, 24073, 24073, 20, 0, 1, 0, 1, 1, NULL), -- Junk
(1917, 11111, 11111, 1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Karrel Grayves
DELETE FROM `creature_loot_template` WHERE `Entry`=1918;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1918, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1918, 4604, 0, 15, 0, 1, 0, 1, 1, NULL), -- Forest Mushroom Cap
(1918, 3294, 0, 1, 0, 1, 0, 1, 1, NULL), -- Deadman Club (unique)
(1918, 24073, 24073, 20, 0, 1, 0, 1, 1, NULL), -- Junk
(1918, 11111, 11111, 1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Samuel Fipps
DELETE FROM `creature_loot_template` WHERE `Entry`=1919;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1919, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(1919, 4604, 0, 15, 0, 1, 0, 1, 1, NULL), -- Forest Mushroom Cap
(1919, 3295, 0, 1, 0, 1, 0, 1, 1, NULL), -- Deadman Blade (unique)
(1919, 16333, 0, 100, 1, 1, 0, 1, 1, NULL), -- Samuel's Remains (quest)
(1919, 24073, 24073, 20, 0, 1, 0, 1, 1, NULL), -- Junk
(1919, 11111, 11111, 1, 0, 1, 0, 1, 1, NULL); -- Bags
