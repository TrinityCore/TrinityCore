ALTER TABLE `custom_character_deathmatch`
ADD COLUMN `deads`  int(11) unsigned NOT NULL COMMENT 'how many deads on DM' AFTER `kills`,
ADD COLUMN `countmatch`  int(11) unsigned NOT NULL COMMENT 'how many was DM' AFTER `deads`;

/*  с откатами потерялся скуль, так что сюда
CREATE TABLE `custom_character_deathmatch` (
  `guid` int(11) unsigned NOT NULL COMMENT 'guid player',
  `kills` int(11) unsigned NOT NULL COMMENT 'how many kills on DM'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='custom table for deathmatch';
*/