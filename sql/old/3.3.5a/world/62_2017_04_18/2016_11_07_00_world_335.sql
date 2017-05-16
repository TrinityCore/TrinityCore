DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=52212;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 52212, 64, '', '', 'Disable LoS for Spell Death and Decay');
