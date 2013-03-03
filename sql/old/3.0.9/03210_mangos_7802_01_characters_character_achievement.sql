/*ALTER TABLE character_db_version CHANGE COLUMN required_7644_01_characters_character_pet required_7802_01_characters_character_achievement bit;*/

ALTER TABLE character_achievement
  CHANGE COLUMN guid guid int(11) unsigned NOT NULL,
  CHANGE COLUMN achievement achievement int(11) unsigned NOT NULL,
  CHANGE COLUMN date date bigint(11) unsigned NOT NULL default '0';
