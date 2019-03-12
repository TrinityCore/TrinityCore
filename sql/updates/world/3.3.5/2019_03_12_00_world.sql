DELETE FROM `disables` WHERE `sourceType` = 9 AND `entry` IN (6343,6345,6376);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`comment`) VALUES
(9,6343,2, 'Disable item 6343 for AH'),
(9,6345,2, 'Disable item 6345 for AH'),
(9,6376,2, 'Disable item 6376 for AH');
