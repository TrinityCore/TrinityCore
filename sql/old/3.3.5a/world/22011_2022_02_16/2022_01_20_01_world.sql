-- Add mapID 44 as valid instance
DELETE FROM `instance_template` WHERE `map`=44;
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES 
(44,0,'',0);

-- Add teleport location OldScarletMonastery
DELETE FROM `game_tele` WHERE `name`='OldScarletMonastery';
INSERT INTO `game_tele` (`position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES 
(79,-1,18.6778,0,44,'OldScarletMonastery');
