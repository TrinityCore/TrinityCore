--
UPDATE `game_event_creature` SET `eventEntry` = 87 WHERE `eventEntry` = 77 AND `guid` = 383796;

DELETE FROM `game_event` WHERE `eventEntry`=87;
INSERT INTO `game_event`(`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `holidayStage`, `description`, `world_event`, `announce`) VALUES
(87, NULL, NULL, 1440, 1440, 0, 0, 'Cataclysm Pre-Launch Deathwing Event', 0, 2);
