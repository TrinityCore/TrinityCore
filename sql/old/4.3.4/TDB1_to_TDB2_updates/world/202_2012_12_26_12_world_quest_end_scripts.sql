ALTER TABLE `quest_template` DROP `CompleteScript`;
DROP TABLE quest_end_scripts;

DELETE FROM `command` WHERE `name`='reload quest_end_scripts';
