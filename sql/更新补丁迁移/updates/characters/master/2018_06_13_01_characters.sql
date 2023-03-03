ALTER TABLE `item_instance_modifiers`
    ADD COLUMN `challengeId` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `artifactKnowledgeLevel`,
    ADD COLUMN `challengeLevel` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeId`,
    ADD COLUMN `challengeAffix1` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeLevel`,
    ADD COLUMN `challengeAffix2` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeAffix1`,
    ADD COLUMN `challengeAffix3` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeAffix2`,
    ADD COLUMN `challengeIsCharged` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeAffix3`; 

ALTER TABLE `character_void_storage`
    ADD COLUMN `challengeId` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `artifactKnowledgeLevel`,
    ADD COLUMN `challengeLevel` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeId`,
    ADD COLUMN `challengeAffix1` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeLevel`,
    ADD COLUMN `challengeAffix2` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeAffix1`,
    ADD COLUMN `challengeAffix3` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeAffix2`,
    ADD COLUMN `challengeIsCharged` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `challengeAffix3`; 
