DROP TABLE IF EXISTS `locales_points_of_interest`;

DROP TABLE IF EXISTS `points_of_interest_locale`;
CREATE TABLE IF NOT EXISTS `points_of_interest_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Name` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

ALTER TABLE `points_of_interest_locale`
 ADD PRIMARY KEY (`ID`,`locale`);
