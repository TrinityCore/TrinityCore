DROP TABLE IF EXISTS `lag_reports`;

ALTER TABLE `gm_surveys`
    RENAME TO `gm_survey`,
    CHANGE COLUMN `overallComment` `comment` LONGTEXT NOT NULL AFTER `mainSurvey`;
	
ALTER TABLE `gm_subsurveys`
    RENAME TO `gm_subsurvey`,
    CHANGE COLUMN `subsurveyId` `questionId` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `surveyId`,
	CHANGE COLUMN `rank` `answer` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `questionId`,
	CHANGE COLUMN `comment` `answerComment` TEXT NOT NULL AFTER `answer`;


ALTER TABLE `gm_tickets`
    RENAME TO `gm_ticket`,
    CHANGE COLUMN `ticketId` `id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT FIRST,
    CHANGE COLUMN `guid` `playerGuid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier of ticket creator' AFTER `id`,
    CHANGE COLUMN `message` `description` TEXT NOT NULL AFTER `playerGuid`,
    CHANGE COLUMN `haveTicket` `needMoreHelp` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `viewed`,
    DROP COLUMN `name`;

DROP TABLE IF EXISTS `gm_bug`;
CREATE TABLE `gm_bug` (
    `id` INT(10) UNSIGNED NOT NULL,
    `playerGuid` BIGINT(20) UNSIGNED NOT NULL,
    `note` TEXT NOT NULL,
    `createTime` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `mapId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `posX` FLOAT NOT NULL DEFAULT '0',
    `posY` FLOAT NOT NULL DEFAULT '0',
    `posZ` FLOAT NOT NULL DEFAULT '0',
    `facing` FLOAT NOT NULL DEFAULT '0',
    `closedBy` BIGINT(20) NOT NULL DEFAULT '0',
    `assignedTo` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'GUID of admin to whom ticket is assigned',
    `comment` TEXT NOT NULL,
    PRIMARY KEY (`id`)
)
COLLATE='utf8_general_ci'
ENGINE=InnoDB
;

DROP TABLE IF EXISTS `gm_complaint`;
CREATE TABLE `gm_complaint` (
    `id` INT(10) UNSIGNED NOT NULL,
    `playerGuid` BIGINT(20) UNSIGNED NOT NULL,
    `note` TEXT NOT NULL,
    `createTime` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `mapId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `posX` FLOAT NOT NULL DEFAULT '0',
    `posY` FLOAT NOT NULL DEFAULT '0',
    `posZ` FLOAT NOT NULL DEFAULT '0',
    `facing` FLOAT NOT NULL DEFAULT '0',
    `targetCharacterGuid` BIGINT(20) UNSIGNED NOT NULL,
    `complaintType` SMALLINT(5) UNSIGNED NOT NULL,
    `reportLineIndex` INT(10) NOT NULL,
    `closedBy` BIGINT(20) NOT NULL DEFAULT '0',
    `assignedTo` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'GUID of admin to whom ticket is assigned',
    `comment` TEXT NOT NULL,
    PRIMARY KEY (`id`)
)
COLLATE='utf8_general_ci'
ENGINE=InnoDB
;

DROP TABLE IF EXISTS `gm_complaint_chatlog`;
CREATE TABLE `gm_complaint_chatlog` (
    `complaintId` INT(10) UNSIGNED NOT NULL,
    `lineId` INT(10) UNSIGNED NOT NULL,
    `timestamp` INT(10) UNSIGNED NOT NULL,
    `text` TEXT NOT NULL,
    PRIMARY KEY (`complaintId`, `lineId`)
)
COLLATE='utf8_general_ci'
ENGINE=InnoDB
;

DROP TABLE IF EXISTS `gm_suggestion`;
CREATE TABLE `gm_suggestion` (
    `id` INT(10) UNSIGNED NOT NULL,
    `playerGuid` BIGINT(20) UNSIGNED NOT NULL,
    `note` TEXT NOT NULL,
    `createTime` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `mapId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `posX` FLOAT NOT NULL DEFAULT '0',
    `posY` FLOAT NOT NULL DEFAULT '0',
    `posZ` FLOAT NOT NULL DEFAULT '0',
    `facing` FLOAT NOT NULL DEFAULT '0',
    `closedBy` BIGINT(20) NOT NULL DEFAULT '0',
    `assignedTo` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'GUID of admin to whom ticket is assigned',
    `comment` TEXT NOT NULL,
    PRIMARY KEY (`id`)
)
COLLATE='utf8_general_ci'
ENGINE=InnoDB
;
