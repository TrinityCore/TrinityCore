ALTER TABLE character_db_version CHANGE COLUMN required_7198_01_characters_characters required_7207_03_characters_corpse bit;

ALTER TABLE corpse
  ADD COLUMN `phaseMask` smallint(5) unsigned NOT NULL default '1' AFTER `map`;
