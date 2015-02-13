DELETE FROM `petition` WHERE `type` NOT IN(10); -- delete all non guild petitions
ALTER TABLE `petition` DROP COLUMN `type`, DROP PRIMARY KEY, ADD PRIMARY KEY (`ownerguid`);

DELETE FROM `petition_sign` WHERE `type` NOT IN(10);  -- delete all non guild petition signs
ALTER TABLE `petition_sign` DROP COLUMN `type`;
