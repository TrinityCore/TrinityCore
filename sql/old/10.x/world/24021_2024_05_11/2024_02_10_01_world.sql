-- Deprecated Quests in Camp Narache
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (3091, 3092, 3093, 3094);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,3091,0,'','','Deprecated Quest: Simple Note'),
(1,3092,0,'','','Deprecated Quest: Etched Note'),
(1,3093,0,'','','Deprecated Quest: Rune-Inscribed Note'),
(1,3094,0,'','','Deprecated Quest: Verdant Note');
