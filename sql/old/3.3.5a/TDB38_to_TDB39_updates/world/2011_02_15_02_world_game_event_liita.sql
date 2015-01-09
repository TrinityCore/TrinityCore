SET @GUID := 208789; -- creature.guid
DELETE FROM `creature` WHERE `guid` IN (86593,91690,91691,91692,91693,91694,91695,91696,91697,91698,91699,91700,91701,91702,79559,79560,12954);
DELETE FROM `creature_addon` WHERE `guid` IN (86593,91690,91691,91692,91693,91694,91695,91696,91697,91698,91699,91700,91701,91702,79559,79560,12954);
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+111 AND `id` IN (36272,36296,36565,36885,37172,37674,37675,37715,38035,38042,38043,38044,38045,38208,38295,38328,38340,38341,38342,38065,37917,37984,38006,38016,38023,38030,38032,37214);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
-- (@GUID,36272,33,1,1,0,0,-205.449,2219.56,79.7633,3.85724,86400,0,0,269000,0,0,0), -- Apothecary Frye
-- (@GUID+1,36296,33,1,1,0,0,-208.723,2218.5,79.7633,5.16886,86400,0,0,269000,0,0,0), -- Apothecary Hummel
-- (@GUID+2,36565,33,1,1,0,0,-209.602,2215.42,79.7633,0.723503,86400,0,0,269000,0,0,0), -- Apothecary Baxter -- commented out because they shouldn't be able to be killed more than once (also missing scripts)
(@GUID+3,36885,33,1,1,0,0,-207.869,2174.97,79.7664,0.661457,300,0,0,1,0,0,0), -- Crown Apothecary
(@GUID+4,36885,33,1,1,0,0,-200.286,2201.67,79.765,0.537364,300,0,0,1,0,0,0), -- Crown Apothecary
(@GUID+5,36885,33,1,1,0,0,-220.323,2207.68,79.7636,3.0687,300,0,0,1,0,0,0), -- Crown Apothecary
(@GUID+6,37172,1,1,1,0,0,1658.82,-4392.51,23.3589,4.6346,300,0,0,955,0,0,0), -- Detective Snap Snagglebolt
(@GUID+7,37674,530,1,1,0,0,-4005.55,-11844.8,1.43003,4.79643,600,0,0,1524,0,0,0), -- Lovely Merchant
(@GUID+8,37674,0,1,1,0,0,-4918.13,-982.624,502.699,2.499,600,0,0,1524,0,0,0), -- Lovely Merchant
(@GUID+9,37674,0,1,1,0,0,-8868.67,636.356,97.0308,0.908268,600,0,0,1524,0,0,0), -- Lovely Merchant
(@GUID+10,37674,1,1,1,0,0,9868.93,2492.6,1317.12,6.214,600,0,0,1524,0,0,0), -- Lovely Merchant
(@GUID+11,37674,530,1,1,0,0,9613.2,-7184.04,15.5297,1.871,600,0,0,1524,0,0,0), -- Lovely Merchant
(@GUID+12,37674,0,1,1,0,0,1629.43,239.687,65.095,0.0213735,600,0,0,1524,0,0,0), -- Lovely Merchant
(@GUID+13,37674,1,1,1,0,0,-1224.64,68.9846,130.974,3.13043,600,0,0,1524,0,0,0), -- Lovely Merchant
(@GUID+14,37674,1,1,1,0,0,1654.56,-4435.7,19.1524,1.54799,600,0,0,1524,0,0,0), -- Lovely Merchant
(@GUID+15,37675,1,1,1,0,0,-1224.81,67.5514,130.815,3.13043,300,0,0,1716,0,0,0), -- Public Relations Agent
(@GUID+16,37675,1,1,1,0,0,1651.95,-4436.06,19.1667,1.5205,300,0,0,1716,0,0,0), -- Public Relations Agent
(@GUID+17,37675,0,1,1,0,0,-8869.92,637.543,97.0305,0.751188,300,0,0,1716,0,0,0), -- Public Relations Agent
(@GUID+18,37675,1,1,1,0,0,9869.15,2493.99,1317.12,6.2572,300,0,0,1716,0,0,0), -- Public Relations Agent
(@GUID+19,37675,530,1,1,0,0,9611.19,-7184.62,15.5277,1.84743,300,0,0,1716,0,0,0), -- Public Relations Agent
(@GUID+20,37675,0,1,1,0,0,1629.41,241.08,65.0948,6.18282,300,0,0,1716,0,0,0), -- Public Relations Agent
(@GUID+21,37675,0,1,1,0,0,-4919.62,-983.631,502.699,2.24375,300,0,0,1716,0,0,0), -- Public Relations Agent
(@GUID+22,37675,530,1,1,0,0,-4003.71,-11844.7,1.44597,4.73753,300,0,0,1716,0,0,0), -- Public Relations Agent
(@GUID+23,37715,1,1,1,0,0,1349.47,-4641.45,53.5287,3.1282,300,0,0,1003,0,0,0), -- Snivel Rustrocket
(@GUID+24,37715,0,1,1,0,0,-8401.37,1246.34,5.2303,5.97131,300,0,0,1003,0,0,0), -- Snivel Rustrocket
(@GUID+25,38035,571,1,1,0,0,5525.21,35.5649,148.918,0.00558376,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+26,38035,571,1,1,0,0,5586.44,36.157,148.304,2.49451,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+27,38035,571,1,1,0,0,5610.19,67.2452,149.648,1.10907,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+28,38035,0,1,1,0,0,-51.7072,1147.06,66.2442,6.0002,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+29,38035,0,1,1,0,0,-9462.46,525.975,55.3952,4.44641,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+30,38035,1,1,1,0,0,1269.73,-4095.83,27.2461,0.383236,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+31,38035,530,1,1,0,0,-1800.57,4849.58,3.67941,0.732729,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+32,38035,1,1,1,0,0,6767.76,-4880.77,776.832,0.473977,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+33,38035,1,1,1,0,0,4851.07,137.164,52.3573,3.32611,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+34,38035,0,1,1,0,0,121.643,-2401.57,123.532,1.69738,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+35,38035,1,1,1,0,0,-3418.81,-4212.7,10.3292,0.932394,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+36,38035,0,1,1,0,0,-402.274,163.143,75.6627,3.65071,60,0,0,1,0,0,0), -- Chemical Wagon
(@GUID+37,38042,1,1,1,0,0,1648.48,-4434.6,17.6364,1.10031,300,0,0,42,0,0,0), -- Kwee Q. Peddlefeet
(@GUID+38,38043,530,1,1,0,0,9617.42,-7181.72,14.2958,2.39329,300,0,0,42,0,0,0), -- Kwee Q. Peddlefeet
(@GUID+39,38044,1,1,1,0,0,-1223.83,62.5435,129.123,3.29929,300,0,0,42,0,0,0), -- Kwee Q. Peddlefeet
(@GUID+40,38045,0,1,1,0,0,1630.48,236.085,63.2574,0.382657,300,0,0,42,0,0,0), -- Kwee Q. Peddlefeet
(@GUID+41,38208,33,1,1,0,0,-234.669,2154.3,90.6247,4.46749,300,0,0,1,0,0,0), -- Investigator Fezzen Brasstacks
(@GUID+42,38295,1,1,1,0,0,-1239.7,55.8489,127.02,0.969017,300,0,0,1,0,0,0), -- Junior Detective
(@GUID+43,38295,0,1,1,0,0,1637.74,256.223,62.5927,4.55312,300,0,0,1,0,0,0), -- Junior Detective
(@GUID+44,38295,530,1,1,0,0,9585.78,-7182.34,14.2411,0.268784,300,0,0,1,0,0,0), -- Junior Detective
(@GUID+45,38328,1,1,1,0,0,1776.14,-4507.72,27.7458,0.701323,300,0,0,1,0,0,0), -- Roka
(@GUID+46,38340,1,1,1,0,0,1619.91,-4376.93,12.2511,0.575657,300,0,0,1,0,0,0), -- [DND] Holiday - Love - Bank Bunny
(@GUID+47,38340,0,1,1,0,0,-8911.16,625.834,99.5227,3.65088,300,0,0,1,0,0,0), -- [DND] Holiday - Love - Bank Bunny
(@GUID+48,38341,0,1,1,0,0,-8806.15,664.605,96.2,1.56172,300,0,0,1,0,0,0), -- [DND] Holiday - Love - AH Bunny
(@GUID+49,38341,1,1,1,0,0,1674.65,-4440.01,19.1696,5.34538,300,0,0,1,0,0,0), -- [DND] Holiday - Love - AH Bunny
(@GUID+50,38342,0,1,1,0,0,-8754.09,657.778,105.091,0.199051,300,0,0,1,0,0,0), -- [DND] Holiday - Love - Barber Bunny
(@GUID+51,38342,1,1,1,0,0,1762.65,-4345.06,-7.83994,3.73924,300,0,0,1,0,0,0), -- [DND] Holiday - Love - Barber Bunny
(@GUID+52,38065,0,1,1,0,0,-9028.75,351.111,93.004,4.99164,180,0,0,12600,0,0,0), -- Crown Supply Sentry
(@GUID+53,38065,0,1,1,0,0,-9033.74,358.078,93.4561,3.12414,180,0,0,12600,0,0,0), -- Crown Supply Sentry
(@GUID+54,38065,0,1,1,0,0,-9033.66,352.778,93.0811,4.03171,180,0,0,12600,0,0,0), -- Crown Supply Sentry
(@GUID+55,37917,0,1,1,0,0,-78.1933,1155.44,64.1348,3.65579,30,0,0,356,0,0,0), -- Crown Thug
(@GUID+56,37917,0,1,1,0,0,-99.1899,1143.58,61.9249,3.65579,30,0,0,356,0,0,0), -- Crown Thug
(@GUID+57,37917,0,1,1,0,0,-70.0067,1126.23,65.5446,5.87061,30,0,0,356,0,0,0), -- Crown Thug
(@GUID+58,37917,0,1,1,0,0,-40.5129,1132.35,66.9879,0.2236,30,0,0,356,0,0,0), -- Crown Thug
(@GUID+59,37917,1,1,1,0,0,4861.5,143.397,53.5891,1.77494,30,0,0,356,0,0,0), -- Crown Thug
(@GUID+60,37917,1,1,1,0,0,4867.09,123.556,54.625,1.10736,30,0,0,356,0,0,0), -- Crown Thug
(@GUID+61,37917,1,1,1,0,0,4860,109.204,53.8496,0.467256,30,0,0,356,0,0,0), -- Crown Thug
(@GUID+62,37917,1,1,1,0,0,4844.9,102.68,50.0936,3.43999,30,0,0,356,0,0,0), -- Crown Thug
(@GUID+63,37917,1,1,1,0,0,4845.3,115.292,51.258,3.43999,30,0,0,356,0,0,0), -- Crown Thug
(@GUID+64,37984,0,1,1,0,0,-396.98,152.02,72.7445,0.0802893,30,0,0,356,0,0,0), -- Crown Duster
(@GUID+65,37984,0,1,1,0,0,-414.333,151.165,72.7544,5.28748,30,0,0,356,0,0,0), -- Crown Duster
(@GUID+66,37984,0,1,1,0,0,-421.118,161.632,73.0552,3.81093,30,0,0,356,0,0,0), -- Crown Duster
(@GUID+67,37984,0,1,1,0,0,-407.15,172.323,76.8851,3.50463,30,0,0,356,0,0,0), -- Crown Duster
(@GUID+68,37984,0,1,1,0,0,-382.121,161.213,77.0395,0.982712,30,0,0,356,0,0,0), -- Crown Duster
(@GUID+69,38006,1,1,1,0,0,-3408.24,-4205.45,11.7024,5.33848,30,0,0,356,0,0,0), -- Crown Hoodlum
(@GUID+70,38006,1,1,1,0,0,-3415.67,-4199.13,10.9447,0.380259,30,0,0,356,0,0,0), -- Crown Hoodlum
(@GUID+71,38006,1,1,1,0,0,-3425.3,-4205.48,11.087,0.747825,30,0,0,356,0,0,0), -- Crown Hoodlum
(@GUID+72,38006,1,1,1,0,0,-3407.75,-4217.59,11.4111,4.59863,30,0,0,356,0,0,0), -- Crown Hoodlum
(@GUID+73,38006,1,1,1,0,0,-3423.44,-4223.1,10.3878,3.34749,30,0,0,356,0,0,0), -- Crown Hoodlum
(@GUID+74,38016,0,1,1,0,0,107.836,-2394.64,123.766,1.71859,30,0,0,356,0,0,0), -- Crown Agent
(@GUID+75,38016,0,1,1,0,0,112.257,-2406.06,125.159,2.12857,30,0,0,356,0,0,0), -- Crown Agent
(@GUID+76,38016,0,1,1,0,0,117.312,-2415.86,124.574,1.81912,30,0,0,356,0,0,0), -- Crown Agent
(@GUID+77,38016,0,1,1,0,0,112.321,-2385.37,121.337,0.933974,30,0,0,356,0,0,0), -- Crown Agent
(@GUID+78,38016,0,1,1,0,0,122.685,-2379.58,120.969,0.401474,30,0,0,356,0,0,0), -- Crown Agent
(@GUID+79,38023,1,1,1,0,0,6777.68,-4889.84,776.667,0.746511,30,0,0,356,0,0,0), -- Crown Sprinkler
(@GUID+80,38023,1,1,1,0,0,6767.71,-4899.06,775.43,5.72986,30,0,0,356,0,0,0), -- Crown Sprinkler
(@GUID+81,38023,1,1,1,0,0,6754.64,-4890.56,774.717,4.87221,30,0,0,356,0,0,0), -- Crown Sprinkler
(@GUID+82,38023,1,1,1,0,0,6754.5,-4875.5,773.386,6.14062,30,0,0,356,0,0,0), -- Crown Sprinkler
(@GUID+83,38023,1,1,1,0,0,6763.25,-4871.99,775.183,0.473977,30,0,0,356,0,0,0), -- Crown Sprinkler
(@GUID+84,38030,530,1,1,0,0,-1792,4835.44,5.75526,4.05103,30,0,0,356,0,0,0), -- Crown Underling
(@GUID+85,38030,530,1,1,0,0,-1786.21,4846.14,3.9133,4.90948,30,0,0,356,0,0,0), -- Crown Underling
(@GUID+86,38030,530,1,1,0,0,-1789.11,4860.69,1.08418,5.7255,30,0,0,356,0,0,0), -- Crown Underling
(@GUID+87,38030,530,1,1,0,0,-1800.26,4865.74,1.76724,0.246567,30,0,0,356,0,0,0), -- Crown Underling
(@GUID+88,38030,530,1,1,0,0,-1809.55,4858.05,1.6643,0.850539,30,0,0,356,0,0,0), -- Crown Underling
(@GUID+89,38032,571,1,1,0,0,5562.6,52.7611,148.023,2.35235,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+90,38032,571,1,1,0,0,5577.75,75.6327,148.413,1.00147,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+91,38032,571,1,1,0,0,5578.91,93.6562,151.453,0.907219,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+92,38032,571,1,1,0,0,5604.51,73.2304,149.666,5.6039,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+93,38032,571,1,1,0,0,5576.47,21.2221,147.859,3.57051,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+94,38032,571,1,1,0,0,5545.75,7.1756,146.18,3.57051,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+95,38032,571,1,1,0,0,5517.56,0.325575,148.243,3.29483,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+96,38032,571,1,1,0,0,5493.37,1.40435,148.043,2.9414,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+97,38032,571,1,1,0,0,5483.65,-24.6906,148.632,4.41402,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+98,38032,571,1,1,0,0,5480.42,-46.4207,150.948,4.71797,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+99,38032,571,1,1,0,0,5490.42,25.9105,148.037,1.53711,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+100,38032,571,1,1,0,0,5517.81,39.9906,150.179,0.35901,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+101,38032,571,1,1,0,0,5560.51,26.0842,147.293,0.621334,30,0,0,9940,0,0,0), -- Crown Sprayer
(@GUID+102,37214,0,1,1,0,0,-9447.59,521.985,56.1219,4.45034,30,0,0,356,0,0,0), -- Crown Lackey
(@GUID+103,37214,0,1,1,0,0,-9461.04,512.112,55.8756,3.59818,30,0,0,356,0,0,0), -- Crown Lackey
(@GUID+104,37214,0,1,1,0,0,-9479.33,525.887,55.2184,2.14127,30,0,0,356,0,0,0), -- Crown Lackey
(@GUID+105,37214,0,1,1,0,0,-9471.57,536.639,54.108,0.793523,30,0,0,356,0,0,0), -- Crown Lackey
(@GUID+106,37214,0,1,1,0,0,-9459.73,534.487,54.9696,5.97165,30,0,0,356,0,0,0), -- Crown Lackey
(@GUID+107,37214,1,1,1,0,0,1278.46,-4095.97,28.5179,6.00276,30,0,0,356,0,0,0), -- Crown Lackey
(@GUID+108,37214,1,1,1,0,0,1273.4,-4103.99,27.8146,4.13351,30,0,0,356,0,0,0), -- Crown Lackey
(@GUID+109,37214,1,1,1,0,0,1263.1,-4104.66,26.5895,3.20674,30,0,0,356,0,0,0), -- Crown Lackey
(@GUID+110,37214,1,1,1,0,0,1252.12,-4093.07,24.2136,1.55034,30,0,0,356,0,0,0), -- Crown Lackey
(@GUID+111,37214,1,1,1,0,0,1261.55,-4082.01,24.5336,0.679332,30,0,0,356,0,0,0); -- Crown Lackey

-- Game_event_linking
DELETE FROM `game_event_creature` WHERE `guid` IN (86593,91690,91691,91692,91693,91694,91695,91696,91697,91698,91699,91700,91701,91702,79559,79560,12954) AND `event`=8;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @GUID+0 AND @GUID+111 AND `event`=8;
INSERT INTO `game_event_creature` (`guid`,`event`) VALUES
/*(@GUID+0,8),(@GUID+1,8),(@GUID+2,8),*/(@GUID+3,8),(@GUID+4,8),
(@GUID+5,8),(@GUID+6,8),(@GUID+7,8),(@GUID+8,8),(@GUID+9,8),
(@GUID+10,8),(@GUID+11,8),(@GUID+12,8),(@GUID+13,8),(@GUID+14,8),
(@GUID+15,8),(@GUID+16,8),(@GUID+17,8),(@GUID+18,8),(@GUID+19,8),
(@GUID+20,8),(@GUID+21,8),(@GUID+22,8),(@GUID+23,8),(@GUID+24,8),
(@GUID+25,8),(@GUID+26,8),(@GUID+27,8),(@GUID+28,8),(@GUID+29,8),
(@GUID+30,8),(@GUID+31,8),(@GUID+32,8),(@GUID+33,8),(@GUID+34,8),
(@GUID+35,8),(@GUID+36,8),(@GUID+37,8),(@GUID+38,8),(@GUID+39,8),
(@GUID+40,8),(@GUID+41,8),(@GUID+42,8),(@GUID+43,8),(@GUID+44,8),
(@GUID+45,8),(@GUID+46,8),(@GUID+47,8),(@GUID+48,8),(@GUID+49,8),
(@GUID+50,8),(@GUID+51,8),(@GUID+52,8),(@GUID+53,8),(@GUID+54,8),
(@GUID+55,8),(@GUID+56,8),(@GUID+57,8),(@GUID+58,8),(@GUID+59,8),
(@GUID+60,8),(@GUID+61,8),(@GUID+62,8),(@GUID+63,8),(@GUID+64,8),
(@GUID+65,8),(@GUID+66,8),(@GUID+67,8),(@GUID+68,8),(@GUID+69,8),
(@GUID+70,8),(@GUID+71,8),(@GUID+72,8),(@GUID+73,8),(@GUID+74,8),
(@GUID+75,8),(@GUID+76,8),(@GUID+77,8),(@GUID+78,8),(@GUID+79,8),
(@GUID+80,8),(@GUID+81,8),(@GUID+82,8),(@GUID+83,8),(@GUID+84,8),
(@GUID+85,8),(@GUID+86,8),(@GUID+87,8),(@GUID+88,8),(@GUID+89,8),
(@GUID+90,8),(@GUID+91,8),(@GUID+92,8),(@GUID+93,8),(@GUID+94,8),
(@GUID+95,8),(@GUID+96,8),(@GUID+97,8),(@GUID+98,8),(@GUID+99,8),
(@GUID+100,8),(@GUID+101,8),(@GUID+102,8),(@GUID+103,8),
(@GUID+104,8),(@GUID+105,8),(@GUID+106,8),(@GUID+107,8),
(@GUID+108,8),(@GUID+109,8),(@GUID+110,8),(@GUID+111,8);

DELETE FROM `creature_addon` WHERE `guid` IN (@GUID+56,@GUID+57);
INSERT INTO `creature_addon`(`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID+56,0,0,0,0,0, '68946 0'),
(@GUID+57,0,0,0,0,0, '68589 0');

SET @GUID:= 151771; -- gameobject.guid
DELETE FROM `gameobject` WHERE `id`=201716;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`animprogress`,`state`) VALUES
(@GUID+00,201716,571,1,1,5525.21,35.5649,148.918,0.00558376,180,0,0,0,1,100,1),
(@GUID+01,201716,571,1,1,5586.44,36.157,148.304,2.49451,180,0,0,0,1,100,1),
(@GUID+02,201716,571,1,1,5610.19,67.2452,149.648,1.10907,180,0,0,0,1,100,1),
(@GUID+03,201716,0,1,1,-51.7072,1147.06,66.2442,6.0002,180,0,0,0,1,100,1),
(@GUID+04,201716,0,1,1,-9462.46,525.975,55.3952,4.44641,180,0,0,0,1,100,1),
(@GUID+05,201716,1,1,1,1269.73,-4095.83,27.2461,0.383236,180,0,0,0,1,100,1),
(@GUID+06,201716,530,1,1,-1800.57,4849.58,3.67941,0.732729,180,0,0,0,1,100,1),
(@GUID+07,201716,1,1,1,4851.07,137.164,52.3573,3.32611,180,0,0,0,1,100,1),
(@GUID+08,201716,0,1,1,121.643,-2401.57,123.532,1.69738,180,0,0,0,1,100,1),
(@GUID+09,201716,1,1,1,-3418.81,-4212.7,10.3292,0.932394,180,0,0,0,1,100,1),
(@GUID+10,201716,0,1,1,-402.274,163.143,75.6627,3.65071,180,0,0,0,1,100,1),
(@GUID+11,201716,1,1,1,6767.76,-4880.77,776.832,0.473977,180,0,0,0,1,100,1);

-- Game_event_linking
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @GUID AND @GUID+11 AND `event`=8;
INSERT INTO `game_event_gameobject` (`guid`,`event`) VALUES
(@GUID+0,8),(@GUID+1,8),(@GUID+2,8),(@GUID+3,8),(@GUID+4,8),
(@GUID+5,8),(@GUID+6,8),(@GUID+7,8),(@GUID+8,8),(@GUID+9,8),
(@GUID+10,8),(@GUID+11,8);

-- remove Love Tokens from innkeepers
DELETE FROM `npc_vendor` WHERE `item`=21815;

-- Update Quests
UPDATE `quest_template` SET `MaxLevel`=13 WHERE `entry` IN (24638,24658);
UPDATE `quest_template` SET `MaxLevel`=22 WHERE `entry` IN (24659,24645);
UPDATE `quest_template` SET `MaxLevel`=31 WHERE `entry` IN (24660,24647);
UPDATE `quest_template` SET `MaxLevel`=40 WHERE `entry` IN (24662,24648);
UPDATE `quest_template` SET `MaxLevel`=50 WHERE `entry` IN (24663,24649);
UPDATE `quest_template` SET `MaxLevel`=60 WHERE `entry` IN (24664,24650);
UPDATE `quest_template` SET `MaxLevel`=70 WHERE `entry` IN (24665,24651);
UPDATE `quest_template` SET `MaxLevel`=80 WHERE `entry` IN (24666,24652);

-- Other Data
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14 WHERE `entry` IN (38032,37214,37917,37984,38006,38016,38023,38030);
UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16 WHERE `entry` IN (36296,36272,36568);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|1 WHERE `entry` IN (36272,36296,36565); -- Shadowfang Keep bosses
-- Missing questrelations
DELETE FROM `creature_questrelation` WHERE `id` IN (38066,37887,38041,38043,38066,38208) AND `quest` IN (24666,24597,24609,24615,24792,14488);
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES
(38066,24666),
(37887,24597),
(38041,24609),
(38043,24615),
(38066,24792),
(38208,14488);
DELETE FROM `creature_involvedrelation` WHERE `id` IN (38066,29611,2784,38208,36296) AND `quest` IN (24666,24597,24609,24792,14488);
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(38066,24666),
(29611,24597),
(2784,24609),
(38208,24792),
(36296,14488);

UPDATE `creature_template` SET `npcflag`=npcflag|2 WHERE `name`='Kwee Q. Peddlefeet'; -- 9 entries that should be questgivers
-- Set correct thrall id for quest A Gift for the Warchief
UPDATE `creature_involvedrelation` SET `id`=4949 WHERE `quest`=24612;

-- Loots
UPDATE `creature_template` SET `lootid`=36296 WHERE `entry`=36296;
DELETE FROM `creature_loot_template` WHERE `entry`=36296;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) values
-- Apothecary Hummel
(36296,1,100,1,0,-50010,1),  -- 1 from reference_epics
(36296,2,15,1,0,-50011,1), -- 1 from reference_blues
(36296,50320,10,1,0,1,1), -- Faded Lovely Greeting Card Ally
(36296,49641,10,1,0,1,1), -- Faded Lovely Greeting Card Horde
(36296,50250,0.1,1,0,1,1); -- Big Love Rocket
DELETE FROM `reference_loot_template` WHERE `entry` IN (50010,50011,50012);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(50010,51806,0,1,1,1,1), -- Shard of Pirouetting Happiness
(50010,51808,0,1,1,1,1), -- Choker of the Pure Heart
(50010,51805,0,1,1,1,1), -- Heartbreak Charm
(50010,51807,0,1,1,1,1), -- Sweet Perfume Broach
(50010,51804,0,1,1,1,1), -- Winking Eye of Love
(50011,50471,0,1,1,1,1), -- The Heartbreaker
(50011,50741,0,1,1,1,1), -- Vile Fumigator's Mask
(50011,50446,0,1,1,1,1), -- Toxic Wasteling
(50011,49715,0,1,1,1,1), -- Forever-Lovely Rose
-- Box of Chocolates_Reference
(50012,22237,0,1,1,1,1), -- Dark Desire
(50012,22239,0,1,1,1,1), -- Sweet Surprise
(50012,22238,0,1,1,1,1), -- Very Berry Cream
(50012,22236,0,1,1,1,1); -- Buttermilk Delight

DELETE FROM `item_loot_template` WHERE `entry` IN (49631,49909,50160,50161);
INSERT INTO `item_loot_template`(`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Standard Apothecary Serving Kit
(49631,49352,100,1,0,1,1),
(49631,49351,100,1,0,1,1),
(49631,49635,100,1,0,1,1),
-- Box of Chocolates
(49909,1,100,1,0,-50012,6), -- always 6 chocolates inside the box (out of 4 kinds)
-- Lovely Dress Box
(50160,22276,0,1,1,1,1), -- Lovely Red Dress
(50160,22278,0,1,1,1,1), -- Lovely Blue Dress
(50160,22279,0,1,1,1,1), -- Lovely Black Dress
(50160,22280,0,1,1,1,1), -- Lovely Purple Dress
-- Loot for Dinner Suit Box
(50161,22281,0,1,1,1,1), -- Blue Dinner Suit
(50161,22282,0,1,1,1,1), -- Purple Dinner Suit
(50161,22277,0,1,1,1,1); -- Red Dinner Suit

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=36296 AND `SourceEntry` IN (49641,50320);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(1,36296,49641,0,6,67,0,0,0, 'Faded Lovely Greeting Card Horde'),
(1,36296,50320,0,6,469,0,0,0, 'Faded Lovely Greeting Card Ally');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=12846 AND `type` in (16,18);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=12859 AND `type` in (5,15,18);
INSERT INTO `achievement_criteria_data`(`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
-- Set correct data for achievement Charming
(12846,16,335,0, ''),
-- Set correct data for achievement Flirt With Disaster (alliance)
(12859,5,26682,0, ''),
(12859,15,3,0, '');
