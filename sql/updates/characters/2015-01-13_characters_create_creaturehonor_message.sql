-- Apply this to your CHARACTER database
-- 
-- Creates a table that allows for tracking messages sent to players
--  from the player_creaturehonor.cpp script

DROP TABLE IF EXISTS `creaturehonor_message`;

CREATE TABLE `creaturehonor_message` (
  `guid` int(10) unsigned NOT NULL COMMENT 'characters.guid',
  `message_checksum` int(10) unsigned DEFAULT '0' COMMENT 'Checksum of CreatureHonor config rules. Script sends mail to player when config changes.',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Tracks CreatureHonor script messages sent to characters.';
