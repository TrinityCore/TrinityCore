ALTER TABLE `areatrigger_data` CHANGE `visualId` `customEntry` INT(11) NOT NULL DEFAULT '0';
ALTER TABLE `areatrigger_data` ADD `isMoving` TINYINT(1) UNSIGNED NOT NULL DEFAULT '0' AFTER `radius2`;

REPLACE INTO `areatrigger_data` (`entry`, `radius`, `radius2`, `isMoving`, `activationDelay`, `updateDelay`, `maxCount`, `customVisualId`, `customEntry`, `comment`) VALUES 
('1316', '5', '5', '1', '0', '0', '0', '25607', '5302', 'spell 123986. ef.0'), 
('1315', '5', '5', '1', '0', '0', '0', '25607', '5300', 'spell 123986. ef.1');