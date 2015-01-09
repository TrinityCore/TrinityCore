ALTER TABLE `quest_template` DROP `StartScript`;
DROP TABLE quest_start_scripts;

DELETE FROM `command` WHERE `name`='reload quest_start_scripts';
