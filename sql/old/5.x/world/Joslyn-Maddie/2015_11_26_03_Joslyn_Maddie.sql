-- Script names for Celestrials on timeless isle and add teleport.

-- Add Xuen's scriptname.
UPDATE `creature_template`  SET `ScriptName` = 'boss_xuen'  WHERE `entry` = 71953 ;

-- Add Niuzao's scriptname.
UPDATE `creature_template`  SET `ScriptName` = 'boss_niuzao'  WHERE `entry` = 71954 ;

-- Add Yu'lon's scriptname.
UPDATE `creature_template`  SET `ScriptName` = 'boss_yu_lon'  WHERE `entry` = 71955 ;

-- Add tele for Timeless Isle.
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES ('1694', '-650.169', '-4905.01', '2.05659', '4.70888', '870', 'timelessisle');
