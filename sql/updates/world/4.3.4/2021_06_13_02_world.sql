DROP TABLE IF EXISTS `world_states`;
CREATE TABLE `world_states` (
  `ID` INT(5) UNSIGNED NOT NULL,
  `DefaultValue` INT(8) NOT NULL DEFAULT 0,
  `MapID` INT(4) UNSIGNED NULL DEFAULT NULL,
  `Comment` varchar(255) NULL,
  PRIMARY KEY (`ID`)
);

INSERT INTO `world_states` (`ID`, `DefaultValue`, `MapID`, `Comment`) VALUES
(5644, 0, 669, 'Blackwing Descent - Omnotron Defense System - Achieve-a-tron'),
(5645, 0, 669, 'Blackwing Descent - Omnotron Defense System - Achieve-a-tron'),
(5646, 0, 669, 'Blackwing Descent - Omnotron Defense System - Achieve-a-tron'),
(5647, 0, 669, 'Blackwing Descent - Omnotron Defense System - Achieve-a-tron'),
(5117, 0, 670, 'Grim Batol - Erudax - Don\'t need to Break Eggs to Make an Omelet');
