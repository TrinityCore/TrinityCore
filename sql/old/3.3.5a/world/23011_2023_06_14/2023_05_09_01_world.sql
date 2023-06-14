-- Design: Infused Twilight Opal for Anub'arak in the Azjol-Nerub Heroic mode
DELETE FROM `creature_loot_template` WHERE `Entry`=31610 AND `Item`=41796;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(31610, 41796, 0, 17, 0, 1, 1, 1, 1, NULL);
