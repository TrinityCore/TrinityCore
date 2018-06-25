DROP TABLE IF EXISTS `quest_poi_blob`;
CREATE TABLE `quest_poi_blob`(
    `ID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `MapId` SMALLINT(5) NOT NULL DEFAULT 0,
    `WorldMapAreaId` SMALLINT(5) NOT NULL DEFAULT 0,
    `NumPoints` TINYINT(3) NOT NULL DEFAULT 0,
    `Floor` TINYINT(3) NOT NULL DEFAULT 0,
    `PlayerConditionId` INT(10) NOT NULL DEFAULT 0,
    `QuestId` INT(10) NOT NULL DEFAULT 0,
    `ObjectiveIndex` INT(10) NOT NULL DEFAULT 0,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `quest_poi_point`;
CREATE TABLE `quest_poi_point`(
    `ID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `X` INT(10) NOT NULL DEFAULT 0,
    `Y` INT(10) NOT NULL DEFAULT 0,
    `QuestPoiBlobId` INT(10) NOT NULL DEFAULT 0,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `research_branch`;
CREATE TABLE `research_branch`(
    `ID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `Name` TEXT NOT NULL,
    `ItemId` INT(10) NOT NULL DEFAULT 0,
    `CurrencyId` SMALLINT(5) NOT NULL DEFAULT 0,
    `ResearchFieldId` TINYINT(3) NOT NULL DEFAULT 0,
    `TextureFileId` INT(10) NOT NULL DEFAULT 0,
    `BigTextureFileId` INT(10) NOT NULL DEFAULT 0,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `research_branch_locale`;
CREATE TABLE `research_branch_locale`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `locale` VARCHAR(4) NOT NULL,
    `Name_lang` TEXT,
    PRIMARY KEY (`ID`, `locale`)
);

DROP TABLE IF EXISTS `research_project`;
CREATE TABLE `research_project`(
    `Name` TEXT NOT NULL,
    `Description` TEXT NOT NULL,
    `SpellId` INT(10) NOT NULL DEFAULT 0,
    `ResearchBranchId` SMALLINT(5) NOT NULL DEFAULT 0,
    `Rarity` TINYINT(3) NOT NULL DEFAULT 0,
    `NumSockets` TINYINT(3) NOT NULL DEFAULT 0,
    `ID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `TextureFileId` INT(10) NOT NULL DEFAULT 0,
    `RequiredWeight` INT(10) NOT NULL DEFAULT 0,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `research_project_locale`;
CREATE TABLE `research_project_locale`(
    `ID` INT UNSIGNED NOT NULL,
    `locale` VARCHAR(4) NOT NULL,
    `Name_lang` TEXT NOT NULL,
    `Description_lang` TEXT NOT NULL,
    PRIMARY KEY (`ID`, `locale`)
);

DROP TABLE IF EXISTS `research_site`;
CREATE TABLE `research_site`(
    `ID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `Name` TEXT NOT NULL,
    `QuestPoiBlobId` INT(10) NOT NULL DEFAULT 0,
    `MapId` SMALLINT(5) NOT NULL DEFAULT 0,
    `AreaPOIIconEnum` INT(10) NOT NULL DEFAULT 0,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `research_site_locale`;
CREATE TABLE `research_site_locale`(
    `ID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `locale` VARCHAR(4) NOT NULL,
    `Name_lang` TEXT NOT NULL,
    PRIMARY KEY (`ID`, `locale`)
);
