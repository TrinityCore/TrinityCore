-- DB/Faction change: Add some missing items
DELETE FROM `player_factionchange_items` WHERE `alliance_id` IN (47711) AND horde_id IN (47870);
INSERT INTO `player_factionchange_items` (`race_A`,`alliance_id`,`commentA`,`race_H`,`horde_id`,`commentH`) VALUES 
(0,47711, 'Girdle of the Nether Champion',0,47870, 'Belt of the Nether Championt');
