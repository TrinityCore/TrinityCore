-- Disable Priest class quests "Learning the Word", removed in 7.0.3
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (26970, 10072, 14279, 26949, 27066, 26919);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1, 26970, 0, '', '', 'Quest removed in patch 7.0.3: Learning the Word - Draenei'),
(1, 10072, 0, '', '', 'Quest removed in patch 7.0.3: Learning the Word - Blood Elf'),
(1, 14279, 0, '', '', 'Quest removed in patch 7.0.3: Learning the Word - Worgen'),
(1, 26949, 0, '', '', 'Quest removed in patch 7.0.3: Learning the Word - Night Elf'),
(1, 27066, 0, '', '', 'Quest removed in patch 7.0.3: Learning the Word - Tauren'),
(1, 26919, 0, '', '', 'Quest removed in patch 7.0.3: Learning the Word - Human');
