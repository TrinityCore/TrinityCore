--
DELETE FROM `game_event_creature` WHERE `guid` IN (136921,136922) AND `eventEntry`=24;
UPDATE `game_event_seasonal_questrelation` SET `eventEntry`=2 WHERE `questId` IN (6983,6984);
