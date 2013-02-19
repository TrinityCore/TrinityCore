-- Change column QuestLevel to allowed -1 value.
ALTER TABLE `quest_template` CHANGE `QuestLevel` `QuestLeveltemp` INT(8);
ALTER TABLE `quest_template` ADD `QuestLevel` SMALLINT(3) AFTER `QuestLeveltemp`;
UPDATE `quest_template` SET `QuestLevel` = `QuestLeveltemp`;
ALTER TABLE `quest_template` DROP `QuestLeveltemp`;
