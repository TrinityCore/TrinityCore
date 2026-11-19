SET @TEL_ID := 1940;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+10;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,958.281,2274.84,296.107,1.56147,870,'GateOfTheSettingSun'),
(@TEL_ID+1,1607.55,1953.59,260.496,5.90159,870,'GuoLaiHalls'),
(@TEL_ID+2,677.059,1587.95,386.817,0.0118775,870,'MistfallVillage'),
(@TEL_ID+3,1242.15,1752.91,365.388,0.642555,870,'RuinsOfGuoLai'),
(@TEL_ID+4,1399.13,429.131,548.286,5.45946,870,'SeatOfKnowledge'),
(@TEL_ID+5,721.304,1998.6,325.534,0.487039,870,'SettingSunGarrison'),
(@TEL_ID+6,1207.42,639.521,346.833,5.44453,870,'SiegeOfOrgrimmar'),
(@TEL_ID+7,1080.54,2082.74,311.462,5.67696,870,'TheFiveSisters'),
(@TEL_ID+8,1215.58,980.787,417.529,4.80915,870,'TheGoldenPagoda'),
(@TEL_ID+9,779.123,1276.12,468.065,0.0629218,870,'TuShenBurialGround'),
(@TEL_ID+10,1208.7,1376.73,363.665,2.29345,870,'WhitepetalLake');

-- ShrineOfTwoMoons
UPDATE `game_tele` SET `position_x` = '1570.2', `position_y` = '894.047', `position_z` = '473.6', `orientation` = '0.48004' WHERE (`id` = '1557');
