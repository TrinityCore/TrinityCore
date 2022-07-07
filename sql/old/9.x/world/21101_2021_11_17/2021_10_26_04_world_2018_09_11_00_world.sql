-- 
DELETE FROM `player_factionchange_spells` WHERE `alliance_id` IN (16056, 16055);
INSERT INTO `player_factionchange_spells` (`alliance_id`, `horde_id`) VALUES 
(16056, 18991), (16055, 18992);

DELETE FROM `player_factionchange_items` WHERE `alliance_id` IN (12302,12303);
INSERT INTO `player_factionchange_items` (`race_A`, `alliance_id`, `commentA`, `race_H`, `horde_id`, `commentH`) VALUE
(0, 12302, 'Reins of the Ancient Frostsaber', 0, 15292, 'Green Kodo'),
(0, 12303, 'Reins of the Nightsaber', 0, 15293, 'Teal Kodo');
