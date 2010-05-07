-- Create guid column
ALTER TABLE `group_instance` ADD `guid` INT(11) NOT NULL FIRST;
-- populate column
UPDATE `group_instance` SET `guid`=(SELECT `groups`.`guid` FROM `groups` WHERE `leaderGuid`=`group_instance`.`leaderGuid`);
-- Update pk
ALTER TABLE `group_instance` DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`, `instance`);
-- Remove unused column leaderguid
ALTER TABLE `group_instance` DROP `leaderGuid`;
