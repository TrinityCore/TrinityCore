DROP TABLE IF EXISTS `battlefield_template`;
CREATE TABLE `battlefield_template` (
  `TypeId` tinyint(3) unsigned NOT NULL,
  `ScriptName` varchar(64) NOT NULL,
  `comment` text,
  PRIMARY KEY(`TypeId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

INSERT INTO `battlefield_template` (`TypeId`, `ScriptName`, `comment`) VALUES
(1, 'battlefield_wg', NULL),
(2, 'battlefield_tb', NULL);
