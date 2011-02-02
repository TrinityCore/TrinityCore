DELETE FROM `spell_script_target` WHERE `entry` IN (62056,63985);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(63985, 1, 32934), # Stone Grip
(62056, 1, 32934);
