-- Create temporary table that holds the entry conversion data. (See corresponding world db update)
CREATE TABLE `game_event_temp` (
  `entryOld` TINYINT(3) UNSIGNED NOT NULL,
  `entryNew` TINYINT(3) UNSIGNED NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

-- Renumbered entry data
INSERT INTO `game_event_temp` (`entryOld`,`entryNew`) VALUES
(1,1),(2,2),(3,3),(4,4),(5,5),(6,6),(7,7),(8,8),(9,9),(10,10),(11,11),(12,12),(13,13),(14,14),(15,15),(16,16),(17,17),(18,18),(19,19),(20,20),(21,21),(22,22),
(23,23),(26,24),(27,25),(28,26),(29,27),(30,28),(31,29),(32,30),(33,31),(34,32),(35,33),(36,34),(37,35),(38,36),(39,37),(40,38),(41,39),(42,40),(43,41),(44,42),
(45,43),(46,44),(47,45),(48,46),(49,47),(50,48),(51,49),(52,50),(53,51),(54,52),(124,53),(125,54),(126,55),(127,56),(128,57),(129,58),(130,59),(131,60);

-- Update game_event_save
UPDATE `game_event_save`, `game_event_temp` SET `game_event_save`.`event_id` = `game_event_temp`.`entryNew` WHERE `game_event_save`.`event_id` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_save` CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL;

-- Update game_event_condition_save
UPDATE `game_event_condition_save`, `game_event_temp` SET `game_event_condition_save`.`event_id` = `game_event_temp`.`entryNew` WHERE `game_event_condition_save`.`event_id` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_condition_save` CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL;
