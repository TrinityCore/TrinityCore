--
UPDATE `areatrigger_teleport` SET `VerifiedBuild` = 15882 WHERE `ID` IN (2547,2548,2549);

UPDATE `areatrigger_teleport` SET /*Zul'Gurub Exit*/ `target_position_x`=-11916.2, `target_position_y`=-1209.47, `target_position_z`=92.2873, `target_orientation`=1.57079, `VerifiedBuild`=15882 WHERE `ID`=3930; -- WSL 3995
UPDATE `areatrigger_teleport` SET /*Deeprun Tram - Ironforge Instance (Inside)*/ `target_position_x`=-4839.51, `target_position_y`=-1317.74, `target_position_z`=501.868, `target_orientation`=1.48352, `VerifiedBuild`=15882 WHERE `ID`=2166; -- WSL 3648
UPDATE `areatrigger_teleport` SET /*Deeprun Tram - Stormwind Instance*/ `target_position_x`=67.7607, `target_position_y`=2490.98, `target_position_z`=-4.29649, `target_orientation`=3.14159, `VerifiedBuild`=15882 WHERE `ID`=2173; -- WSL 3650
UPDATE `areatrigger_teleport` SET /*Deeprun Tram - Stormwind Instance*/ `target_position_x`=69.2277, `target_position_y`=10.3932, `target_position_z`=-4.29665, `target_orientation`=3.14159, `VerifiedBuild`=15882 WHERE `ID`=2175; -- WSL 3651
UPDATE `areatrigger_teleport` SET /*Stratholme - Eastern Plaguelands Instance*/ `target_position_x`=3590.87, `target_position_y`=-3643.22, `target_position_z`=138.491, `target_orientation`=5.49778, `VerifiedBuild`=15882 WHERE `ID`=2214; -- WSL 3652
UPDATE `areatrigger_teleport` SET /*Stratholme - Eastern Plaguelands Instance*/ `target_position_x`=3233.06, `target_position_y`=-4048.3, `target_position_z`=108.442, `target_orientation`=2.00712, `VerifiedBuild`=15882 WHERE `ID`=2221; -- WSL 3655
-- Sometimes Z position may look incorrect but it's correct https://youtu.be/2GxM9F192MA?t=18
UPDATE `areatrigger_teleport` SET /*Blackrock Mountain - Searing Gorge Instance*/ `target_position_x`=456.929, `target_position_y`=34.0923, `target_position_z`=-68.0896, `target_orientation`=4.71238, `VerifiedBuild`=15882 WHERE `ID`=1466; -- WSL 3643
UPDATE `areatrigger_teleport` SET /*Blackrock Spire - Searing Gorge Instance (Inside)*/ `target_position_x`=78.3534, `target_position_y`=-226.841, `target_position_z`=49.7662, `target_orientation`=4.71238, `VerifiedBuild`=15882 WHERE `ID`=1468; -- WSL 3644
UPDATE `areatrigger_teleport` SET /*Blackrock Spire - Searing Gorge Instance*/ `target_position_x`=-7524.65, `target_position_y`=-1229.13, `target_position_z`=285.731, `target_orientation`=2.09439, `VerifiedBuild`=15882 WHERE `ID`=1470; -- WSL 3645
UPDATE `areatrigger_teleport` SET /*Blackrock Dephts - Searing Gorge Instance*/ `target_position_x`=-7178.41, `target_position_y`=-922.152, `target_position_z`=166.092, `target_orientation`=2.00712, `VerifiedBuild`=15882 WHERE `ID`=1472; -- WSL 3646
UPDATE `areatrigger_teleport` SET /*Razorfen Downs Entrance*/ `target_position_x`=2593.68, `target_position_y`=1111.23, `target_position_z`=50.9518, `target_orientation`=4.71238, `VerifiedBuild`=15882 WHERE `ID`=442; -- WSL 3614
UPDATE `areatrigger_teleport` SET /*Gnomeregan Entrance*/ `target_position_x`=-329.484, `target_position_y`=-3.22991, `target_position_z`=-152.846, `target_orientation`=2.96705, `VerifiedBuild`=15882 WHERE `ID`=324; -- WSL 3613
UPDATE `areatrigger_teleport` SET /*Blackphantom Deeps Entrance*/ `target_position_x`=-150.234, `target_position_y`=106.594, `target_position_z`=-39.779, `target_orientation`=4.45058, `VerifiedBuild`=15882 WHERE `ID`=257; -- WSL 3608
UPDATE `areatrigger_teleport` SET /*Shadowfang Keep Entrance*/ `target_position_x`=-228.191, `target_position_y`=2111.41, `target_position_z`=76.8904, `target_orientation`=1.22173, `VerifiedBuild`=15882 WHERE `ID`=145; -- WSL 3602
UPDATE `areatrigger_teleport` SET /*DeadMines Instance Start*/ `target_position_x`=-11208, `target_position_y`=1676.41, `target_position_z`=24.5716, `target_orientation`=4.71238, `VerifiedBuild`=15882 WHERE `ID`=119; -- WSL 3601

-- 6.28319 is value converted from 360 degree, actually 0 is used
UPDATE `areatrigger_teleport` SET `target_orientation` = 0 WHERE `ID` IN (924,2410,2411,2547,2548,2549,3133,3185,3190,4131,4364,4397,4416,4468,4469,4470,4598,4619);

DELETE FROM `areatrigger_teleport` WHERE `ID` = 2068;
INSERT INTO `areatrigger_teleport` (`ID`,`Name`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`,`VerifiedBuild`) VALUES
(2068,"Blackrock Spire - Target - Shaft",0,-7558.39,-1309.43,248.454,1.57079,15882);
