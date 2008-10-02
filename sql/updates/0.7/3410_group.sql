RENAME TABLE `raidgroup` TO `group` ;
ALTER TABLE `group` COMMENT = 'Groups';
ALTER TABLE `group` ADD `isRaid` TINYINT( 1 ) NOT NULL;
UPDATE `group` SET `isRaid` = 1;

RENAME TABLE `raidgroup_member` TO `group_member`;
ALTER TABLE `group_member` COMMENT = 'Groups';
