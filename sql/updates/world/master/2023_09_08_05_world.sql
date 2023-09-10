SET @TEL_ID := 2001;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+4;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,-2411.93,8960.02,-143.21,2.62184,1669,'DefiledPath'),
(@TEL_ID+1,-3237.33,8741.64,-150.743,4.35365,1669,'Terminus'),
(@TEL_ID+2,-3266.93,9194.16,-165.437,2.33517,1669,'FelfireArmory'),
(@TEL_ID+3,-2551.06,9284.29,-126.086,1.73669,1669,'TheSpiritCrucible'),
(@TEL_ID+4,-2899.77,8798.33,-229.117,0.84606,1669,'HopesLanding');
