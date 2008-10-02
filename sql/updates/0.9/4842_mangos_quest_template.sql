ALTER TABLE `quest_template` ADD COLUMN `SpecialFlags` tinyint(1) unsigned NOT NULL default '0' AFTER `QuestFlags`;
ALTER TABLE `quest_template` CHANGE COLUMN `QuestFlags` `QuestFlags` smallint(5) unsigned NOT NULL default '0';
UPDATE `quest_template` SET `SpecialFlags`=1 WHERE `Repeatable`=1;
ALTER TABLE `quest_template` DROP COLUMN `Repeatable`;
