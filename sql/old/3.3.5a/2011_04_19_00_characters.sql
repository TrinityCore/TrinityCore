ALTER TABLE gm_subsurveys
    CHANGE `surveyid` `surveyId` int(10) unsigned NOT NULL AUTO_INCREMENT,
    CHANGE `subsurveyid` `subsurveyId` int(10) unsigned NOT NULL DEFAULT '0';

ALTER TABLE gm_subsurveys
    DROP PRIMARY KEY,
    ADD PRIMARY KEY(`surveyId`,`subsurveyId`);

ALTER TABLE gm_surveys
    CHANGE `surveyid` `surveyId` int(10) unsigned NOT NULL AUTO_INCREMENT,
    CHANGE `player` `guid` int(10) unsigned NOT NULL DEFAULT '0',
    CHANGE `overall_comment` `overallComment` longtext NOT NULL,
    CHANGE `timestamp` `createTime` int(10) unsigned NOT NULL DEFAULT '0';

ALTER TABLE gm_surveys
    DROP PRIMARY KEY,
    ADD PRIMARY KEY (`surveyId`);

ALTER TABLE gm_tickets
    CHANGE `guid` `ticketId` int(10) unsigned NOT NULL AUTO_INCREMENT,
    CHANGE `playerGuid` `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier of ticket creator',
    CHANGE `name` `name` varchar(12) NOT NULL COMMENT 'Name of ticket creator',
    CHANGE `createtime` `createTime` int(10) unsigned NOT NULL DEFAULT '0',
    CHANGE `map` `mapId` smallint(5) unsigned NOT NULL DEFAULT '0',
    CHANGE `timestamp` `lastModifiedTime` int(10) unsigned NOT NULL DEFAULT '0',
    CHANGE `closed` `closedBy` int(10) NOT NULL DEFAULT '0',
    CHANGE `assignedto` `assignedTo` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'GUID of admin to whom ticket is assigned';

ALTER TABLE gm_tickets
    DROP PRIMARY KEY,
    ADD PRIMARY KEY (`ticketId`);

ALTER TABLE lag_reports
    CHANGE `report_id` `reportId` int(10) unsigned NOT NULL AUTO_INCREMENT,
    CHANGE `player` `guid` int(10) unsigned NOT NULL DEFAULT '0',
    CHANGE `lag_type` `lagType` tinyint(3) unsigned NOT NULL DEFAULT '0',
    CHANGE `map` `mapId` smallint(5) unsigned NOT NULL DEFAULT '0';

ALTER TABLE lag_reports
    DROP PRIMARY KEY,
    ADD PRIMARY KEY (`reportId`);
