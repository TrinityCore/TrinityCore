/*ALTER TABLE character_db_version CHANGE COLUMN required_7251_02_characters_character_spell required_7255_01_characters_characters bit;*/

ALTER TABLE `characters`
  ADD COLUMN `bgid` int(10) unsigned NOT NULL default '0' AFTER `latency`,
  ADD COLUMN `bgteam` int(10) unsigned NOT NULL default '0' AFTER `bgid`,
  ADD COLUMN `bgmap` int(10) unsigned NOT NULL default '0' AFTER `bgteam`,
  ADD COLUMN `bgx` float NOT NULL default '0' AFTER `bgmap`,
  ADD COLUMN `bgy` float NOT NULL default '0' AFTER `bgx`,
  ADD COLUMN `bgz` float NOT NULL default '0' AFTER `bgy`,
  ADD COLUMN `bgo` float NOT NULL default '0' AFTER `bgz`;
