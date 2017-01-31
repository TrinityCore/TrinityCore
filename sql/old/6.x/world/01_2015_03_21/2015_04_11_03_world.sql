DROP TABLE IF EXISTS `locales_page_text`;

DROP TABLE IF EXISTS `page_text_locale`;
CREATE TABLE IF NOT EXISTS `page_text_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Text` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

ALTER TABLE `page_text_locale`
 ADD PRIMARY KEY (`ID`,`locale`);
