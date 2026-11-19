SET @TEL_ID := 2126;

DELETE FROM `game_tele` WHERE `id` BETWEEN @TEL_ID+0 AND @TEL_ID+7;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(@TEL_ID+0,2655.49,6229.89,4849.43,3.18203,2222,'Korthia'),
(@TEL_ID+1,3055.91,5886.62,4831.41,0.213223,2222,'ScholarsDen'),
(@TEL_ID+2,3142.97,6211.97,4868.08,0.566648,2222,'MaulersOutlook'),
(@TEL_ID+3,2741.86,6081.88,4841.65,3.15139,2222,'SeekersQuorum'),
(@TEL_ID+4,2164.27,6210.81,4869.58,0.00507402,2222,'VaultOfSecrets'),
(@TEL_ID+5,2675.64,6593.24,4813.28,0.814032,2222,'EstuaryOfAwakening'),
(@TEL_ID+6,2904.24,6561.42,4936.13,3.81033,2222,'HopesAscent'),
(@TEL_ID+7,3269.16,5787.51,4937.87,2.35422,2222,'KeepersRespite');
