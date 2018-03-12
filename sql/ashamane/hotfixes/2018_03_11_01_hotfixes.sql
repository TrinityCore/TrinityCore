DROP TABLE IF EXISTS `artifact_tier`;
CREATE TABLE `artifact_tier`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `ArtifactTier` INT(10) UNSIGNED NOT NULL,
    `MaxNumTraits` INT(10) UNSIGNED NOT NULL,
    `MaxArtifactKnowledge` INT(10) UNSIGNED NOT NULL,
    `KnowledgePlayerCondition` INT(10) UNSIGNED NOT NULL,
    `MinimumEmpowerKnowledge` INT(10) UNSIGNED NOT NULL,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `artifact_unlock`;
CREATE TABLE `artifact_unlock`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `ItemBonusListID` SMALLINT(5) UNSIGNED NOT NULL,
    `PowerRank` TINYINT(3) UNSIGNED NOT NULL,
    `PowerID` INT(10) UNSIGNED NOT NULL,
    `PlayerConditionID` INT(10) UNSIGNED NOT NULL,
    `ArtifactID` TINYINT(3) UNSIGNED NOT NULL,
    PRIMARY KEY (`ID`)
);
