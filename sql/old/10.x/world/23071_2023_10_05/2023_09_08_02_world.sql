SET @TEL_ID := 1968;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+14;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,-722.815,-5459.96,117.844,0.608825,870,'FirewalkersPath'),
(@TEL_ID+1,-650.014,-4841.71,2.26187,4.7086,870,'TimelessIsle'),
(@TEL_ID+2,-650.035,-4719.86,2.44988,4.72038,870,'TheTimelessShore'),
(@TEL_ID+3,-948.374,-5674.58,1.51772,0.620605,870,'CroakingHollow'),
(@TEL_ID+4,-500.167,-5373.79,3.20337,4.72433,870,'RedStoneRun'),
(@TEL_ID+5,-250.829,-4773.86,4.84312,1.31097,870,'TheMistyStrand'),
(@TEL_ID+6,-326.764,-4924.19,15.6992,0.0504057,870,'ThreeBreezeTerrace'),
(@TEL_ID+7,-128.262,-5385.53,150.104,2.92889,870,'OrdonSanctuary'),
(@TEL_ID+8,-466.758,-5749.63,90.0504,0.992104,870,'TheBlazingWay'),
(@TEL_ID+9,-1010.65,-5331.68,52.5452,5.30236,870,'FirewalkerRuins'),
(@TEL_ID+10,-951.218,-5005.06,2.0567,2.75297,870,'OldPiJiu'),
(@TEL_ID+11,-683.739,-5181.44,-0.0694875,5.46261,870,'MossgreenLake'),
(@TEL_ID+12,-649.989,-4907.94,2.05611,4.69685,870,'TheCelestialCourt'),
(@TEL_ID+13,-909.685,-4640.49,4.84981,3.44101,870,'TushuiLanding'),
(@TEL_ID+14,-418.108,-4605.38,4.05569,4.18085,870,'HuojinLanding');
