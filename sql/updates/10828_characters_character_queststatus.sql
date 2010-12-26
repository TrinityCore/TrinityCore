DELETE FROM character_queststatus WHERE `status` = 0;

DROP TABLE IF EXISTS `character_queststatus_rewarded`;
CREATE TABLE `character_queststatus_rewarded` (
  `guid` int(10) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL default '0' COMMENT 'Quest Identifier',
  PRIMARY KEY (`guid`,`quest`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

INSERT INTO character_queststatus_rewarded SELECT guid, quest FROM character_queststatus WHERE rewarded = 1;
DELETE FROM character_queststatus WHERE rewarded = 1;

ALTER TABLE character_queststatus DROP COLUMN rewarded;
