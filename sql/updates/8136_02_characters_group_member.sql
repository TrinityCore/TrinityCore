-- Create guid column
ALTER TABLE `group_member` ADD `guid` INT(11) NOT NULL FIRST;
-- populate column
UPDATE `group_member` SET `guid`=(SELECT `groups`.`guid` FROM `groups` WHERE `leaderGuid`=`group_member`.`leaderGuid`);
-- Remove index that will be same as pk
ALTER TABLE `group_member` DROP INDEX `Idx_memberGuid` ;
-- NOTE: if this one fails then u have a problem in your DB. Have a member in 2 groups, so fix it yourself and then re-run this one
ALTER TABLE `group_member` DROP `leaderGuid`;
