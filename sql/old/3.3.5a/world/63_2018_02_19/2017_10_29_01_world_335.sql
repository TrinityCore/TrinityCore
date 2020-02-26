DELETE FROM `command` WHERE `name`='reload quest_greeting';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload quest_greeting', 843, 'Syntax: .reload quest_greeting\nReload quest_greeting table.');

DELETE FROM `command` WHERE `name`='reload quest_greeting_locale';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload quest_greeting_locale', 867, 'Syntax: .reload quest_greeting_locale\nReload quest_greeting_locale table.');

DROP TABLE IF EXISTS `quest_greeting`;
CREATE TABLE `quest_greeting` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Type` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `GreetEmoteType` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
  `GreetEmoteDelay` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `Greeting` TEXT,
  `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`Type`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `quest_greeting_locale`;
CREATE TABLE `quest_greeting_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Type` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Greeting` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`ID`,`Type`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;
