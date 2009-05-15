/*ALTER TABLE character_db_version CHANGE COLUMN required_7802_01_characters_character_achievement required_7802_02_characters_character_achievement_progress bit;*/

ALTER TABLE character_achievement_progress
  CHANGE COLUMN guid guid int(11) unsigned NOT NULL,
  CHANGE COLUMN criteria criteria int(11) unsigned NOT NULL,
  CHANGE COLUMN counter counter int(11) unsigned NOT NULL,
  CHANGE COLUMN date date bigint(11) unsigned NOT NULL default '0';