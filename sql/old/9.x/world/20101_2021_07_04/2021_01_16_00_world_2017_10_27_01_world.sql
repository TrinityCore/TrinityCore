ALTER TABLE `game_event` ADD COLUMN `holidayStage` TINYINT UNSIGNED NOT NULL DEFAULT '0' AFTER `holiday`;

UPDATE `game_event` SET `holiday` = 424 WHERE `eventEntry` = 64; -- Correct Kalu'ak Fishing Derby
UPDATE `game_event` SET `holiday` = 0 WHERE `eventEntry` = 63;
UPDATE `game_event` SET `holiday` = 374 WHERE `eventEntry` = 23;  -- Darkmoon construction
-- UPDATE `game_event` SET `holiday` = 375 WHERE `eventEntry` = 110;
UPDATE `game_event` SET `holiday` = 376 WHERE `eventEntry` = 62;
UPDATE `game_event` SET `holidayStage` = 1 WHERE `eventEntry` IN (1, 2, 7, 8, 9, 10, 11, 12, 18, 19, 20, 21, 23, 26, 50, 51, 53, 54, 62/*, 110*/);
UPDATE `game_event` SET `holidayStage` = 2 WHERE `eventEntry` IN (3, 4, 5, 24);
