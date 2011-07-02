-- GAME_TELE: Some missing areas
SET @id := 1419;
DELETE FROM `game_tele` WHERE `id` IN(@id,@id+1,@id+2)
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@id,5690.97,2141.074,798.0541,4.4344,571, 'TheFrozenHalls'),
(@id+1,8427.875,2706.33,655.095,5.743,571, 'TheShadowVault'),
(@id+2,3641.45,282.75,-120.145,3.325,571, 'ChamberOfAspects');
