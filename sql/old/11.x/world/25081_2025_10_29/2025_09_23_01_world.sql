ALTER TABLE `game_event` ADD `WorldStateId` INT DEFAULT NULL AFTER `holidayStage`;

DELETE FROM `world_state` WHERE `ID` IN (521, 522, 523, 524);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(521, 0, NULL, NULL, '', 'Season - Spring'),
(522, 0, NULL, NULL, '', 'Season - Summer'),
(523, 0, NULL, NULL, '', 'Season - Fall'),
(524, 0, NULL, NULL, '', 'Season - Winter');

SET @EENTRY := 90;
DELETE FROM `game_event` WHERE `eventEntry` BETWEEN @EENTRY+0 AND @EENTRY+3;
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`holidayStage`,`WorldStateId`,`description`,`world_event`,`announce`) VALUES
(@EENTRY+0, '2025-03-19 23:59:59', '2035-06-21 00:00:00', 525600, 133920, 0, 0, 521, 'Season - Spring', 0, 2),
(@EENTRY+1, '2025-06-20 23:59:59', '2035-09-22 00:00:00', 525600, 133920, 0, 0, 522, 'Season - Summer', 0, 2),
(@EENTRY+2, '2025-09-21 23:59:59', '2035-12-21 00:00:00', 525600, 131040, 0, 0, 523, 'Season - Fall', 0, 2),
(@EENTRY+3, '2025-12-20 23:59:59', '2036-03-20 00:00:00', 525600, 128160, 0, 0, 524, 'Season - Winter', 0, 2);
