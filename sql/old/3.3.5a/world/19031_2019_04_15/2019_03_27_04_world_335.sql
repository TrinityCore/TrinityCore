-- Mottled Boar
DELETE FROM `creature_loot_template` WHERE `Entry`=3098;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(3098, 4865, 0, 40, 0, 1, 1, 1, 1, "Ruined Pelt"), -- Ruined Pelt
(3098, 7098, 0, 40, 0, 1, 1, 1, 2, "Splintered Tusk"), -- Splintered Tusk
(3098, 117, 0, 20, 0, 1, 1, 1, 1, "Tough Jerky"), -- Tough Jerky
(3098, 24073, 24073, 15, 0, 1, 0, 1, 1, "Junk"), -- Junk
(3098, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags"); -- Bags
