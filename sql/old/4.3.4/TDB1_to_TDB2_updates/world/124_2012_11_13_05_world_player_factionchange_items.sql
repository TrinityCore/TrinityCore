DELETE FROM `player_factionchange_items` WHERE `alliance_id` IN (15198, 47937);
INSERT INTO `player_factionchange_items` (`race_A`, `alliance_id`, `commentA`, `race_H`, `horde_id`, `commentH`) VALUES
(0, 15198, 'Knight\'s Colors', 0, 15199, 'Stone Guard\'s Herald'),
(0, 47937, 'Girdle of the Nether Champion', 0, 48009, 'Belt of the Nether Champion');
