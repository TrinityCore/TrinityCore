ALTER TABLE `quest_template` ADD COLUMN `ZoneOrSort` int(11) NOT NULL default '0' AFTER `entry` ;
UPDATE `quest_template` SET `ZoneOrSort` = `ZoneId` WHERE `ZoneId` < 2147483647 ;
UPDATE `quest_template` SET `ZoneOrSort` = -(4294967295 - `ZoneId` + 1 )  WHERE `ZoneId` >= 2147483647 ;
UPDATE `quest_template` SET `ZoneOrSort` = -`questsort` WHERE `questsort` > 0 ;
ALTER TABLE `quest_template` DROP `questsort`, DROP `ZoneId`;