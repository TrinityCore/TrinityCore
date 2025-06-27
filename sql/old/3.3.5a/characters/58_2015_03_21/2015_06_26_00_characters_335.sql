-- `character_aura`
ALTER TABLE `character_aura`
CHANGE `caster_guid`      `casterGuid`      bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Full Global Unique Identifier',
CHANGE `item_guid`        `itemGuid`        bigint(20) unsigned NOT NULL DEFAULT '0',
CHANGE `effect_mask`      `effectMask`      tinyint(3) unsigned NOT NULL DEFAULT '0',
CHANGE `recalculate_mask` `recalculateMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
CHANGE `stackcount`       `stackCount`      tinyint(3) unsigned NOT NULL DEFAULT '1',
CHANGE `maxduration`      `maxDuration`     int(11) NOT NULL DEFAULT '0',
CHANGE `remaintime`       `remainTime`      int(11) NOT NULL DEFAULT '0',
CHANGE `remaincharges`    `remainCharges`   tinyint(3) unsigned NOT NULL DEFAULT '0';

-- `character_glyphs`
ALTER TABLE `character_glyphs`
CHANGE `spec` `talentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0';

-- `character_talent`
ALTER TABLE `character_talent`
CHANGE `spec` `talentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0';

-- `characters`
ALTER TABLE `characters`
CHANGE `speccount`  `talentGroupsCount` tinyint(3) unsigned NOT NULL DEFAULT '1',
CHANGE `activespec` `activeTalentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0';

-- `gm_subsurveys` -> `gm_subsurvey`
RENAME TABLE `gm_subsurveys` TO `gm_subsurvey`;
ALTER TABLE `gm_subsurvey`
CHANGE `subsurveyId` `questionId`    int(10) unsigned NOT NULL DEFAULT '0',
CHANGE `rank`        `answer`        int(10) unsigned NOT NULL DEFAULT '0',
CHANGE `comment`     `answerComment` text NOT NULL;

-- `gm_surveys` -> `gm_survey`
RENAME TABLE `gm_surveys` TO `gm_survey`;
ALTER TABLE `gm_survey`
CHANGE `overallComment` `comment` longtext NOT NULL;

-- `gm_tickets` -> `gm_ticket`
RENAME TABLE `gm_tickets` TO `gm_ticket`;
ALTER TABLE `gm_ticket`
CHANGE `ticketId`   `id`           int(10) unsigned NOT NULL AUTO_INCREMENT,
CHANGE `guid`       `playerGuid`   int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier of ticket creator',
CHANGE `message`    `description`  text NOT NULL,
CHANGE `haveTicket` `needMoreHelp` tinyint(3) unsigned NOT NULL DEFAULT '0';

-- `groups`
ALTER TABLE `groups`
CHANGE `raiddifficulty` `raidDifficulty` tinyint(3) unsigned NOT NULL DEFAULT '0';

-- `pet_aura`
ALTER TABLE `pet_aura`
CHANGE `caster_guid`      `casterGuid`      bigint(20) unsigned NOT NULL DEFAULT '0' COMMENT 'Full Global Unique Identifier',
CHANGE `effect_mask`      `effectMask`      tinyint(3) unsigned NOT NULL DEFAULT '0',
CHANGE `recalculate_mask` `recalculateMask` tinyint(3) unsigned NOT NULL DEFAULT '0',
CHANGE `stackcount`       `stackCount`      tinyint(3) unsigned NOT NULL DEFAULT '1',
CHANGE `maxduration`      `maxDuration`     int(11) NOT NULL DEFAULT '0',
CHANGE `remaintime`       `remainTime`      int(11) NOT NULL DEFAULT '0',
CHANGE `remaincharges`    `remainCharges`   tinyint(3) unsigned NOT NULL DEFAULT '0';
