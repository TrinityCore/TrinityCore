-- ALTER TABLE character_db_version CHANGE COLUMN required_8843_01_characters required_8874_01_characters_character_skills bit;

DROP TABLE IF EXISTS `character_skills`;
CREATE TABLE `character_skills` (
  `guid` int(11) unsigned NOT NULL COMMENT 'Global Unique Identifier',
  `skill` mediumint(9) unsigned NOT NULL,
  `value` int(11) unsigned NOT NULL,
  `max` mediumint(9) unsigned NOT NULL,
  i mediumint(9),
  PRIMARY KEY  (`guid`,`skill`,`i`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';


DROP TABLE IF EXISTS temp_skills;
CREATE TABLE temp_skills (
  i int(11) unsigned NOT NULL,
  PRIMARY KEY (i)
);

INSERT INTO temp_skills VALUES
( 0),( 1),( 2),( 3),( 4),( 5),( 6),( 7),( 8),( 9),(10),(11),(12),(13),(14),(15),(16),(17),(18),(19),
(20),(21),(22),(23),(24),(25),(26),(27),(28),(29),(30),(31),(32),(33),(34),(35),(36),(37),(38),(39),
(40),(41),(42),(43),(44),(45),(46),(47),(48),(49),(50),(51),(52),(53),(54),(55),(56),(57),(58),(59),
(60),(61),(62),(63),(64),(65),(66),(67),(68),(69),(70),(71),(72),(73),(74),(75),(76),(77),(78),(79),
(80),(81),(82),(83),(84),(85),(86),(87),(88),(89),(90),(91),(92),(93),(94),(95),(96),(97),(98),(99),
(100),(101),(102),(103),(104),(105),(106),(107),(108),(109),(110),(111),(112),(113),(114),(115),(116),(117),(118),(119),
(120),(121),(122),(123),(124),(125),(126),(127);

INSERT INTO character_skills SELECT
guid,
((SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 610+3*i))+2, length(SUBSTRING_INDEX(data, ' ', 610+3*i+1))- length(SUBSTRING_INDEX(data, ' ', 610+3*i)) - 1)) & 0xFFFF) as skill,
(SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 610+3*i+1))+2, length(SUBSTRING_INDEX(data, ' ', 610+3*i+2))- length(SUBSTRING_INDEX(data, ' ', 610+3*i+1)) - 1)) as value,
(0) as max,
i
FROM characters, temp_skills;

DELETE FROM character_skills WHERE skill = 0;
DROP TABLE IF EXISTS temp_skills;

UPDATE character_skills
  SET max = ((value & 0xFFFF0000) >> 16);

UPDATE character_skills
  SET value = (value & 0xFFFF);

ALTER IGNORE TABLE character_skills
  CHANGE COLUMN value value mediumint(9) unsigned NOT NULL,
  DROP PRIMARY KEY,
  ADD  PRIMARY KEY (guid,skill),
  DROP COLUMN i;