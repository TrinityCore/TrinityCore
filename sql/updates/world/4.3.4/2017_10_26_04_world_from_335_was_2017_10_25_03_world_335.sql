/*
-- Mottled Boar
DELETE FROM `creature_loot_template` WHERE `Entry`=3098;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(3098, 4865, 0, 40, 0, 1, 0, 1, 2, "Ruined Pelt"), -- Ruined Pelt
(3098, 7098, 0, 40, 0, 1, 0, 1, 2, "Splintered Tusk"), -- Splintered Tusk
(3098, 117, 0, 14, 0, 1, 0, 1, 2, "Tough Jerky"), -- Tough Jerky
(3098, 24073, 24073, 5, 0, 1, 0, 1, 1, "Junk"), -- Junk
(3098, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags"); -- Bags

-- Vile Familiar
-- Also removes obsolete Vile Familiar Head quest item
DELETE FROM `creature_loot_template` WHERE `Entry`=3101;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(3101, 117, 0, 10, 0, 1, 0, 1, 1, "Tough Jerky"), -- Tough Jerky
(3101, 159, 0, 5, 0, 1, 0, 1, 1, "Refreshing Spring Water"), -- Refreshing Spring Water
(3101, 24073, 24073, 5, 0, 1, 0, 1, 1, "Junk"), -- Junk
(3101, 11111, 11111, 0.5, 0, 1, 0, 1, 1, "Bags"); -- Bags

-- Felstalker
DELETE FROM `creature_loot_template` WHERE `Entry`=3102;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(3102, 6640, 0, 100, 1, 1, 1, 1, 1, "Felstalker Hoof (quest"), -- Felstalker Hoof (quest)
(3102, 3300, 0, 14, 0, 1, 0, 1, 1, "Rabbit's Foot"), -- Rabbit's Foot
(3102, 7073, 0, 20, 0, 1, 0, 1, 2, "Broken Fang"), -- Broken Fang
(3102, 7074, 0, 20, 0, 1, 0, 1, 2, "Chipped Claw"), -- Chipped Claw
(3102, 4865, 0, 20, 0, 1, 0, 1, 2, "Ruined Pelt"), -- Ruined Pelt
(3102, 24073, 24073, 5, 0, 1, 0, 1, 1, "Junk"), -- Junk
(3102, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags"); -- Bags

-- Scorpid Worker
DELETE FROM `creature_loot_template` WHERE `Entry`=3124;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(3124, 4862, 0, 100, 1, 1, 1, 1, 1, "Scorpid Tail (quest)"), -- Scorpid Tail (quest)
(3124, 4867, 0, 22, 0, 1, 0, 1, 2, "Broken Scorpid Leg"), -- Broken Scorpid Leg
(3124, 7099, 0, 22, 0, 1, 0, 1, 2, "Severed Pincer"), -- Severed Pincer
(3124, 7101, 0, 22, 0, 1, 0, 1, 2, "Sticky Ichor"), -- Sticky Ichor
(3124, 7100, 0, 23, 0, 1, 0, 1, 2, "Bug Eye"), -- Bug Eye
(3124, 24073, 24073, 5, 0, 1, 0, 1, 1, "Junk"), -- Junk
(3124, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags"); -- Bags

-- Sarkoth
DELETE FROM `creature_loot_template` WHERE `Entry`=3281;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(3281, 4905, 0, 100, 1, 1, 1, 1, 1, "Sarkoth's Mangled Claw (quest)"), -- Sarkoth's Mangled Claw (quest)
(3281, 4867, 0, 15, 0, 1, 0, 1, 1, "Broken Scorpid Leg"), -- Broken Scorpid Leg
(3281, 7099, 0, 39, 0, 1, 0, 1, 1, "Severed Pincer"), -- Severed Pincer
(3281, 7101, 0, 20, 0, 1, 0, 1, 1, "Sticky Ichor"), -- Sticky Ichor
(3281, 7100, 0, 20, 0, 1, 0, 1, 1, "Bug Eye"), -- Bug Eye
(3281, 24073, 24073, 5, 0, 1, 0, 1, 1, "Junk"), -- Junk
(3281, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags"); -- Bags

-- Yarrog Baneshadow
DELETE FROM `creature_loot_template` WHERE `Entry`=3183;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(3183, 4859, 0, 100, 1, 1, 1, 1, 1, "Burning Blade Medallion (quest)"), -- Burning Blade Medallion (quest)
(3183, 117, 0, 10, 0, 1, 0, 1, 1, "Tough Jerky"), -- Tough Jerky
(3183, 159, 0, 5, 0, 1, 0, 1, 1, "Refreshing Spring Water"), -- Refreshing Spring Water
(3183, 24073, 24073, 5, 0, 1, 0, 1, 1, "Junk"), -- Junk
(3183, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags"); -- Bags
*/
