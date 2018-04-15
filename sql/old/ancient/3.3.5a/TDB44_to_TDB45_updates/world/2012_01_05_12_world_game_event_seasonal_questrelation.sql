UPDATE `game_event_seasonal_questrelation` SET `event`=8 WHERE `event`=-1;

ALTER TABLE `game_event_seasonal_questrelation`
  CHANGE `quest` `questId` int(10) unsigned NOT NULL COMMENT 'Quest Identifier',
  CHANGE `event` `eventEntry` mediumint(8) unsigned NOT NULL DEFAULT 0 COMMENT 'Entry of the game event';
