-- 
DELETE FROM `creature_loot_template` WHERE `Entry`=118;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(118, 2672, 0, 85, 0, 1, 0, 1, 1, "Stringy wolf meat"), -- Stringy wolf meat
(118, 62328, 0, 85, 0, 1, 1, 1, 1, "Shed fur"), -- Shed fur
(118, 3299, 0, 15, 0, 1, 1, 1, 1, "Fractured canine"), -- Fractured canine
(118, 24073, 24073, 2, 0, 1, 2, 1, 1, "Junk"), -- Junk
(118, 24074, 24074, 1, 0, 1, 2, 1, 1, "Greens ilvl 10-11"), -- Greens ilvl 10-11
(118, 24075, 24075, 0.5, 0, 1, 2, 1, 1, "Greens ilvl 12-13"), -- Greens ilvl 12-13
(118, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags"); -- Bags
