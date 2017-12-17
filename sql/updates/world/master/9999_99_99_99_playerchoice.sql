DELETE FROM `command` WHERE `name` IN ('debug send playerchoice');
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('debug send playerchoice', 869, 'Syntax: .debug send playerchoice $choiceId\r\nSend given choice to player.');

DROP TABLE IF EXISTS `playerchoice`;
CREATE TABLE `playerchoice` (
  `ChoiceID` INT (10) NOT NULL,
  `Question` VARCHAR (255),
  PRIMARY KEY (`ChoiceID`)
);

INSERT INTO playerchoice VALUES (231, "TODO");

DROP TABLE IF EXISTS `playerchoice_locale`;
CREATE TABLE `playerchoice_locale` (
  `ChoiceID` INT (10) NOT NULL,
  `locale` VARCHAR (4) NOT NULL,
  `Question` VARCHAR (255),
  PRIMARY KEY (`ChoiceID`, `locale`)
);

INSERT INTO playerchoice_locale VALUES (231, "frFR", "Quelle spécialisation de chasseur de démons voulez-vous apprendre ?");

DROP TABLE IF EXISTS `playerchoice_response`;
CREATE TABLE `playerchoice_response` (
  `ChoiceID` INT (10) NOT NULL,
  `ResponseID` INT (10) NOT NULL,
  `ChoiceArtFileID` INT (10),
  `Header` TEXT,
  `Answer` TEXT,
  `Description` TEXT,
  `Confirmation` TEXT,
  PRIMARY KEY (`ChoiceID`, `ResponseID`)
);

INSERT INTO playerchoice_response VALUES
(231, 478, 1274664, "TODO", "TODO", "TODO", ""),
(231, 479, 1274665, "TODO", "TODO", "TODO", "");

DROP TABLE IF EXISTS `playerchoice_response_locale`;
CREATE TABLE `playerchoice_response_locale` (
  `ChoiceID` INT (10) NOT NULL,
  `ResponseID` INT (10) NOT NULL,
  `locale` VARCHAR (4) NOT NULL,
  `Header` TEXT,
  `Answer` TEXT,
  `Description` TEXT,
  `Confirmation` TEXT,
  PRIMARY KEY (`ChoiceID`, `ResponseID`, `locale`)
);

INSERT INTO playerchoice_response_locale VALUES
(231, 478, "frFR", "Dévastation", "Dévastation", "Conserver votre spécialisation : Dévastation.

Les chasseurs de démons Dévastation peuvent utiliser Métamorphose pour se transformer en démons ailés. Ils se concentrent sur les dégâts en mêlée.

Choisir Dévastation confère |cFFFF0000|Hspell:162264|h[Métamorphose]|h|r et |cFFFF0000|Hspell:185164|h[Maîtrise : Présence démoniaque]|h|r.", ""),
(231, 479, "frFR", "Vengeance", "Vengeance", "Changer de spécialisation : Vengeance.

Les chasseurs de démons Vengeance peuvent utiliser Métamorphose pour se transformer en démons couverts de pointes. Ils se concentrent sur le rôle de tank.

Choisir Vengeance confère |cFFFF0000|Hspell:187827|h[Métamorphose]|h|r et |cFFFF0000|Hspell:203747|h[Maîtrise : Gangresang]|h|r.

Votre technique |cFFFF0000|Hspell:193921|h[Rayon accablant]|h|r est remplacée par |cFFFF0000|Hspell:203720|h[Pointes démoniaques]|h|r.", "");

DROP TABLE IF EXISTS `playerchoice_response_reward`;
CREATE TABLE `playerchoice_response_reward` (
  `ChoiceID` INT (10) NOT NULL,
  `ResponseID` INT (10) NOT NULL,
  `TitleID` INT (10),
  `PackageID` INT (10),
  `SkillLineID` INT (10) UNSIGNED,
  `SkillPointCount` INT (10) UNSIGNED,
  `ArenaPointCount` INT (10) UNSIGNED,
  `HonorPointCount` INT (10) UNSIGNED,
  `Money` BIGINT (20) UNSIGNED,
  `Xp` INT (10) UNSIGNED,
  PRIMARY KEY (`ChoiceID`, `ResponseID`)
);

INSERT INTO playerchoice_response_reward VALUES
(231, 478, 0, 0, 0, 0, 0, 0, 0, 0),
(231, 479, 0, 0, 0, 0, 0, 0, 0, 0);
