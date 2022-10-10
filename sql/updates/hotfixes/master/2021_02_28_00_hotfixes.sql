ALTER TABLE `hotfix_data` ADD `Status` tinyint(3) unsigned NOT NULL DEFAULT '3' AFTER `Deleted`;

UPDATE `hotfix_data` SET `Status`=1 WHERE `Deleted`=0;
UPDATE `hotfix_data` SET `Status`=2 WHERE `Deleted`=1;

ALTER TABLE `hotfix_data` DROP `Deleted`;
