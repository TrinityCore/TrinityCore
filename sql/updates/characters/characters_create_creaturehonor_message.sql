-- Apply this to your CHARACTER database
-- 
-- Creates a table that allows for tracking messages sent to players
--  from the player_creaturehonor.cpp script

DROP TABLE IF EXISTS `creaturehonor_message`;

CREATE TABLE `creaturehonor_message` (
  `guid` int(10) unsigned NOT NULL COMMENT 'characters.guid',
  `message_sent` int(1) unsigned DEFAULT '0' COMMENT 'Set to 0 to force message resend at login. Useful after CONF change.',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Tracks CreatureHonor script messages sent to characters.';
