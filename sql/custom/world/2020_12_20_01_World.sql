-- King Deepbeard https://www.wowhead.com/npc=91797/king-deepbeard

DELETE FROM `reference_loot_template` WHERE `entry` = 91797;
INSERT INTO `reference_loot_template` (`entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(91797, 134539, 0, 10.213556, 0, 1, 1, 1, 1, 'Braided Silver Ring'),
(91797, 134406, 0,  7.389353, 0, 1, 1, 1, 1, 'Mainsail Cloak'),
(91797, 137369, 0,  4.928815, 0, 1, 1, 1, 1, 'Giant Ornamental Pearl'),
(91797, 137371, 0,  4.611575, 0, 1, 1, 1, 1, 'Tumultuous Aftershock'),
(91797, 134456, 0,  3.791396, 0, 1, 1, 1, 1, 'Taut Halyard Waistband'),
(91797, 134428, 0,  3.172392, 0, 1, 1, 1, 1, 'Rising Ocean Legwraps'),
(91797, 137370, 0,  1.965336, 0, 1, 1, 1, 1, 'Heart of the Sea'),
(91797, 134514, 0,  2.429588, 0, 1, 1, 1, 1, 'Keelhauler Legplates'),
(91797, 137368, 0,  0.974930, 0, 1, 1, 1, 1, 'Breastplate of Ten Lashes');