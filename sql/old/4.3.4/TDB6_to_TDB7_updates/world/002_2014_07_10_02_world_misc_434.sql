DELETE FROM `player_factionchange_items` WHERE `alliance_id` IN (62473, 62474, 62475, 62476, 62477, 62478, 62479, 62468, 62469, 62470, 62471, 62472, 68739, 63355, 90897, 63141, 64998, 63039, 63391, 65175, 63144, 63145, 63379, 63377, 63517);
DELETE FROM `player_factionchange_items` WHERE `horde_id` IN (62463, 62464, 62465, 62466, 62467, 62454, 62455, 62456, 62457, 62458, 62459, 62460, 65356, 64997, 64994, 64993, 64996, 63376, 63378, 64995, 63518, 64999, 62176, 68740, 90898);
INSERT INTO `player_factionchange_items` (`race_A`, `alliance_id`, `commentA`, `race_H`, `horde_id`, `commentH`) VALUES
(0, 62473, 'Blade of the Fearless', 0, 62454, 'Blade of the Fearless'),
(0, 62474, 'Spear of Trailing Shadows', 0, 62455, 'Spear of Trailing Shadows'),
(0, 62475, 'Dagger of Restless Nights', 0, 62456, 'Dagger of Restless Nights'),
(0, 62476, 'Ravening Slicer', 0, 62457, 'Ravening Slicer'),
(0, 62477, 'Insidious Staff', 0, 62458, 'Insidious Staff'),
(0, 62478, 'Shimmering Morningstar', 0, 62459, 'Shimmering Morningstar'),
(0, 62479, 'Sky Piercer', 0, 62460, 'Sky Piercer'),
(0, 62468, 'Unsolvable Riddle', 0, 62463, 'Unsolvable Riddle'),
(0, 62469, 'Impatience of Youth', 0, 62464, 'Impatience of Youth'),
(0, 62470, 'Stump of Time', 0, 62465, 'Stump of Time'),
(0, 62471, 'Mirror of Broken Images', 0, 62466, 'Mirror of Broken Images'),
(0, 62472, 'Mandala of Stirring Patterns', 0, 62467, 'Mandala of Stirring Patterns'),
(0, 68739, 'Darkheart Hacker', 0, 68740, 'Darkheart Hacker'),
(0, 63355, 'Rustberg Gull', 0, 64996, 'Rustberg Gull'),
(0, 63141, 'Tol Barad Searchlight', 0, 64997, 'Tol Barad Searchlight'),
(0, 64998, 'Reins of the Spectral Steed', 0, 64999, 'Reins of the Spectral Wolf'),
(0, 63039, 'Reins of the Drake of the West Wind', 0, 65356, 'Reins of the Drake of the West Wind'),
(0, 63391, 'Baradin\'s Wardens Bandage', 0, 64995, 'Hellscream\'s Reach Bandage'),
(0, 65175, 'Baradin Footman\'s Tags', 0, 62176, 'Baradin Grunt\'s Talisman'),
(0, 63144, 'Baradin\'s Wardens Healing Potion', 0, 64994, 'Hellscream\'s Reach Healing Potion'),
(0, 63145, 'Baradin\'s Wardens Mana Potion', 0, 64993, 'Hellscream\'s Reach Mana Potion'),
(0, 63379, 'Baradin\'s Wardens Tabard', 0, 63378, 'Hellscream\'s Reach Tabard'),
(0, 63377, 'Baradin\'s Wardens Battle Standard', 0, 63376, 'Hellscream\'s Reach Battle Standard'),
(0, 63517, 'Baradin\'s Wardens Commendation', 0, 63518, 'Hellscream\'s Reach Commendation');

DELETE FROM `player_factionchange_reputations` WHERE `alliance_id`=1177 OR `horde_id`=1178;
INSERT INTO `player_factionchange_reputations` (`alliance_id`, `horde_id`) VALUES (1177, 1178);

-- Spectral Steed & Spectral Wolf mounts
DELETE FROM `player_factionchange_spells` WHERE `alliance_id`=92231 OR `horde_id`=92232;
INSERT INTO `player_factionchange_spells` (`alliance_id`, `horde_id`) VALUES (92231, 92232);
