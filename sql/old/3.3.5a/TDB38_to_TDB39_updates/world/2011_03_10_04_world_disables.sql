-- disable untill it can be properly scripted
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (7020,7021);
INSERT INTO `disables`
(`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`)
VALUES
(4,7020,0, '', '', 'disable Not In My House'),
(4,7021,0, '', '', 'disable Not In My House');
