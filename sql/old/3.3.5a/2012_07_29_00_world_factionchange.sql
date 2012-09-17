-- Faction change item conversion for Reins of the Traveler's Tundra Mammoth
DELETE FROM `player_factionchange_items` WHERE `alliance_id`=44235;
INSERT INTO `player_factionchange_items` (`race_A`, `alliance_id`, `commentA`, `race_H`, `horde_id`, `commentH`) VALUES
(0,44235,'Reins of the Traveler''s Tundra Mammoth',0,44234,'Reins of the Traveler''s Tundra Mammoth');

-- Faction change spell conversion for Reins of the Traveler's Tundra Mammoth
DELETE FROM `player_factionchange_spells` WHERE `alliance_id`=61425;
INSERT INTO `player_factionchange_spells` (`alliance_id`,`horde_id`) VALUES
(61425,61447);
