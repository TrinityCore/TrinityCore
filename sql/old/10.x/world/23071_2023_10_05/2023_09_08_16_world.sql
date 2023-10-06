SET @TEL_ID := 2134;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+16;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,-4190.35,99.5429,-113.636,6.26059,2374,'ZerethMortis'),
(@TEL_ID+1,-3985.07,100.207,-128.146,0.0245337,2374,'ForgeOfAfterlives'),
(@TEL_ID+2,-4449.32,351.827,-36.5242,4.61522,2374,'GenesisFields'),
(@TEL_ID+3,-3829.25,621.377,-65.0128,4.69142,2374,'TheGreatVeldt'),
(@TEL_ID+4,-4464.38,54.2804,-83.0372,4.25709,2374,'DimensionalFalls'),
(@TEL_ID+5,-4959.15,-105.385,-20.1231,3.75757,2374,'CatalystGardens'),
(@TEL_ID+6,-3829.49,-1404.43,120.544,4.70947,2374,'TheSepulcherOfTheFirstOnesArea'),
(@TEL_ID+7,-3735.71,-590.548,-7.67937,0.519376,2374,'PilgrimsGrace'),
(@TEL_ID+8,-3113.38,-869.02,-114.824,5.29695,2374,'ArrangmentIndex'),
(@TEL_ID+9,-3102.68,-374.189,-96.9124,5.37234,2374,'DesertedOverlook'),
(@TEL_ID+10,-2690.82,-573.659,-145.087,0.543721,2374,'TheDreadPortal'),
(@TEL_ID+11,-3391.32,526.827,-104.401,6.03287,2374,'TerraceOfFormation'),
(@TEL_ID+12,-2506.55,103.871,-85.7851,5.99124,2374,'AntecedentIsle'),
(@TEL_ID+13,-3573.12,710.307,-45.2196,5.24199,2374,'ExilesHollow'),
(@TEL_ID+14,-3833.66,1049.13,15.408,1.59774,2374,'PathOfInception'),
(@TEL_ID+15,-4235.67,770.848,-43.5488,5.21057,2374,'Haven'),
(@TEL_ID+16,-3577.44,631.64,-44.9028,1.24587,2374,'FaithsRepose');
