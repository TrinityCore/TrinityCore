ALTER TABLE `game_event_battleground_holiday`   
	CHANGE `eventEntry` `EventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'game_event EventEntry identifier',
	CHANGE `bgflag` `BattlegroundID` INT(3) UNSIGNED DEFAULT 0 NOT NULL;

TRUNCATE TABLE `game_event_battleground_holiday`;
INSERT INTO `game_event_battleground_holiday` (`EventEntry`, `BattlegroundID`) VALUES
(18, 1),
(19, 2),
(20, 3),
(21, 7),
(53, 9),
(54, 30),
(82, 120),
(83, 108);
