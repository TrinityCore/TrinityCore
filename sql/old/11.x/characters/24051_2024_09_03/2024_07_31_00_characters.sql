ALTER TABLE `groups` ADD `pingRestriction` tinyint AFTER `masterLooterGuid`;

UPDATE `groups` SET `pingRestriction`=0;

ALTER TABLE `groups` MODIFY `pingRestriction` tinyint NOT NULL;
