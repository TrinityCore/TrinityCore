-- Removing obsolete quest 960, which was replaced by quest 961
DELETE FROM `creature_questrelation` WHERE `quest`=960;
DELETE FROM `creature_involvedrelation` WHERE `quest`=960;

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=960;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1, 960, 0, '', '', 'Deprecated quest');
