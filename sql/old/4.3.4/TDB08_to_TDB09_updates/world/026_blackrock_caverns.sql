SET @CGUID := 361655;
SET @OGUID := 225985;
SET @POOL1 := 645001; -- Twilight Torturer & Twilight Sadist (13 pools) Crazed Sadist & Mad Prisoner (5 pools)
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+230;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0,15214,645,3,1,0,178.8715,1073.939,206.14,0,7200,0,0), -- Invisible Stalker
(@CGUID+1,15214,645,3,1,0,191.7778,1110.024,205.7062,0,7200,0,0), -- Invisible Stalker
(@CGUID+2,15214,645,3,1,0,192.7813,1088.813,205.0071,0,7200,0,0), -- Invisible Stalker
(@CGUID+3,15214,645,3,1,0,209.6129,1095.269,208.0441,0,7200,0,0), -- Invisible Stalker
(@CGUID+4,15214,645,3,1,0,209.7934,1068.677,205.8642,0,7200,0,0), -- Invisible Stalker
(@CGUID+5,15214,645,3,1,0,223.8038,1086.13,205.7924,0,7200,0,0), -- Invisible Stalker
(@CGUID+6,15214,645,3,1,0,238.3438,1071.097,205.189,0,7200,0,0), -- Invisible Stalker
(@CGUID+7,15214,645,3,1,0,239.4288,1105.642,205.1713,0,7200,0,0), -- Invisible Stalker
(@CGUID+8,39665,645,3,1,0,230.0868,949.2327,192.8682,3.151758,7200,0,0), -- Rom'ogg Bonecrusher
(@CGUID+9,39679,645,3,1,0,573.4445,987.6875,155.4369,4.660029,7200,0,0), -- Corla  Herald of Twilight
(@CGUID+10,39698,645,3,1,0,233.47,794.755,95.99233,5.061455,7200,0,0), -- Karsh Steelbender
(@CGUID+11,39700,645,3,1,0,102.8576,583.9549,76.86975,6.143559,7200,0,0), -- Beauty
(@CGUID+12,39705,645,3,1,0,331.7101,554.4896,66.08983,3.141593,7200,0,0), -- Ascendant Lord Obsidius
(@CGUID+13,39708,645,3,1,0,172.7622,1086.165,206.1144,2.86234,7200,0,0), -- Twilight Flame Caller
(@CGUID+14,39708,645,3,1,0,197.3074,1000.168,195.5761,2.697475,7200,0,0), -- Twilight Flame Caller
(@CGUID+15,39708,645,3,1,0,199.9292,1008.22,197.0488,1.618152,7200,0,0), -- Twilight Flame Caller
(@CGUID+16,39708,645,3,1,0,247.5191,1081.444,206.4205,0.1396263,7200,0,0), -- Twilight Flame Caller
(@CGUID+17,39708,645,3,1,0,482.0609,936.3184,183.2706,1.608248,7200,0,0), -- Twilight Flame Caller
(@CGUID+18,39708,645,3,1,0,486.279,930.5712,182.9764,1.987982,7200,0,0), -- Twilight Flame Caller
(@CGUID+19,39842,645,3,1,0,205.4948,784.4097,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+20,39842,645,3,1,0,207.6684,774.2136,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+21,39842,645,3,1,0,207.7986,795.6493,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+22,39842,645,3,1,0,213.1719,805.592,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+23,39842,645,3,1,0,213.2448,764.5313,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+24,39842,645,3,1,0,221.2778,811.7691,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+25,39842,645,3,1,0,221.7882,757.158,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+26,39842,645,3,1,0,231.2656,753.4722,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+27,39842,645,3,1,0,231.6545,815.7239,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+28,39842,645,3,1,0,237.2951,784.7761,95.99241,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+29,39842,645,3,1,0,243.0799,815.8229,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+30,39842,645,3,1,0,243.2257,753.5799,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+31,39842,645,3,1,0,253.0851,812.4323,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+32,39842,645,3,1,0,253.1806,757.6215,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+33,39842,645,3,1,0,261.2986,805.4688,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+34,39842,645,3,1,0,261.5104,764.4323,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+35,39842,645,3,1,0,266.9705,774.1511,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+36,39842,645,3,1,0,267.1441,795.0695,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+37,39842,645,3,1,0,269.1563,784.8386,95.41864,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+38,39842,645,3,1,0,573.7118,905.1805,178.1542,0,7200,0,0), -- Invisible Stalker (Hostile Ignore Combat Float Uninteractible Large AOI)
(@CGUID+39,39978,645,3,1,0,191.1133,943.783,190.8844,5.22872,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+40,39978,645,3,1,0,239.2088,991.6777,191.0754,3.697115,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+41,39978,645,3,1,0,207.7162,919.74,190.905,4.258029,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+42,39978,645,3,1,0,193.1875,908.507,191.5111,6.073746,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+43,39978,645,3,1,0,210.7726,934.0781,191.1399,0.01745329,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+44,39978,645,3,1,0,250.5747,902.375,191.819,5.131268,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+45,39978,645,3,1,0,255.8194,993.3889,190.9622,3.508112,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+46,39978,645,3,1,0,256.6059,985.0452,191.0119,2.234021,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+47,39978,645,3,1,0,256.783,901.8055,191.3704,4.08407,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+48,39978,645,3,1,0,180.5017,951.7327,190.8433,1.919862,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+49,39978,645,3,1,0,185.2656,960.4393,190.8546,3.106686,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+50,39978,645,3,1,0,201.0903,912.9132,190.8805,4.34587,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+51,39978,645,3,1,0,212.2726,938.0886,191.1958,5.480334,7200,0,0), -- Twilight Torturer (Pooled with Twilight Sadist)
(@CGUID+52,39980,645,3,1,0,191.1133,943.783,190.8844,5.22872,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+53,39980,645,3,1,0,239.2088,991.6777,191.0754,3.697115,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+54,39980,645,3,1,0,207.7162,919.74,190.905,4.258029,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+55,39980,645,3,1,0,193.1875,908.507,191.5111,6.073746,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+56,39980,645,3,1,0,210.7726,934.0781,191.1399,0.01745329,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+57,39980,645,3,1,0,250.5747,902.375,191.819,5.131268,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+58,39980,645,3,1,0,255.8194,993.3889,190.9622,3.508112,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+59,39980,645,3,1,0,256.6059,985.0452,191.0119,2.234021,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+60,39980,645,3,1,0,256.783,901.8055,191.3704,4.08407,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+61,39980,645,3,1,0,180.5017,951.7327,190.8433,1.919862,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+62,39980,645,3,1,0,185.2656,960.4393,190.8546,3.106686,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+63,39980,645,3,1,0,201.0903,912.9132,190.8805,4.34587,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+64,39980,645,3,1,0,212.2726,938.0886,191.1958,5.480334,7200,0,0), -- Twilight Sadist (Pooled with Twilight Torturer)
(@CGUID+65,39982,645,3,1,0,215.7535,934.1233,191.2856,3.106686,7200,0,0), -- Crazed Sadist (Pooled with Mad Prisoner)
(@CGUID+66,39982,645,3,1,0,177.8681,960.441,190.7993,0,7200,0,0), -- Crazed Sadist (Pooled with Mad Prisoner)
(@CGUID+67,39982,645,3,1,0,199.2656,907.125,190.8895,1.710423,7200,0,0), -- Crazed Sadist (Pooled with Mad Prisoner)
(@CGUID+68,39982,645,3,1,0,250.559,991.1893,191.0155,0.03490658,7200,0,0), -- Crazed Sadist (Pooled with Mad Prisoner)
(@CGUID+69,39982,645,3,1,0,253.0122,897.257,191.4062,1.780236,7200,0,0), -- Crazed Sadist (Pooled with Mad Prisoner)
(@CGUID+70,39985,645,3,1,0,215.7535,934.1233,191.2856,3.106686,7200,0,0), -- Mad Prisoner (Pooled with Crazed Sadist)
(@CGUID+71,39985,645,3,1,0,177.8681,960.441,190.7993,0,7200,0,0), -- Mad Prisoner (Pooled with Crazed Sadist)
(@CGUID+72,39985,645,3,1,0,199.2656,907.125,190.8895,1.710423,7200,0,0), -- Mad Prisoner (Pooled with Crazed Sadist)
(@CGUID+73,39985,645,3,1,0,250.559,991.1893,191.0155,0.03490658,7200,0,0), -- Mad Prisoner (Pooled with Crazed Sadist)
(@CGUID+74,39985,645,3,1,0,253.0122,897.257,191.4062,1.780236,7200,0,0), -- Mad Prisoner (Pooled with Crazed Sadist)
(@CGUID+75,39987,645,3,1,0,292.0434,943.9462,190.9277,3.141593,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+76,39987,645,3,1,0,292.1788,958.434,191.0159,3.281219,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+77,39987,645,3,1,0,328.6337,810.2361,103.0259,0.08726646,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+78,39987,645,3,1,0,329.3524,820.4896,102.9514,6.230825,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+79,39987,645,3,1,0,336.1267,815.5347,102.8027,6.230825,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+80,39987,645,3,1,0,353.22,812.483,104.8403,0.08726646,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+81,39987,645,3,1,0,353.7153,943.1215,191.566,3.281219,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+82,39987,645,3,1,0,353.939,822.736,104.9963,6.230825,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+83,39987,645,3,1,0,360.714,817.781,105.3933,6.230825,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+84,39987,645,3,1,0,366.7708,952.5555,192.2504,3.228859,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+85,39987,645,3,1,0,375.005,811.738,104.9873,0.08726646,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+86,39987,645,3,1,0,375.724,821.995,104.9423,6.230825,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+87,39987,645,3,1,0,378.2986,944.5781,192.0129,3.281219,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+88,39987,645,3,1,0,380.589,817.248,104.4473,6.230825,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+89,39987,645,3,1,0,389.5208,952.5903,192.6917,3.281219,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+90,39987,645,3,1,0,399.1337,944.1719,193.5015,3.124139,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+91,39987,645,3,1,0,410.7188,951.9462,194.1848,3.281219,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+92,39987,645,3,1,0,436.4837,819.8177,108.4601,3.356542,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+93,39987,645,3,1,0,518.5664,864.7994,131.3015,3.12971,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+94,39987,645,3,1,0,548.9124,885.7015,170.4143,4.706097,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+95,39987,645,3,1,0,598.8642,914.7213,169.5081,1.577245,7200,0,0), -- Evolved Twilight Zealot
(@CGUID+96,39990,645,3,1,0,470.4028,908.0226,165.9179,5.899213,7200,0,0), -- Twilight Zealot
(@CGUID+97,39990,645,3,1,0,478.7969,894.8212,165.9179,0.7853982,7200,0,0), -- Twilight Zealot
(@CGUID+98,39990,645,3,1,0,506.4635,892.3976,161.659,3.752458,7200,0,0), -- Twilight Zealot
(@CGUID+99,39990,645,3,1,0,521.846,889.175,159.9603,2.80998,7200,0,0), -- Twilight Zealot
(@CGUID+100,39990,645,3,1,0,536.875,890.7153,157.6841,2.86234,7200,0,0), -- Twilight Zealot
(@CGUID+101,39990,645,3,1,0,551.156,899.227,155.4593,0.3141593,7200,0,0), -- Twilight Zealot
(@CGUID+102,39990,645,3,1,0,554.528,894.991,155.4593,1.37881,7200,0,0), -- Twilight Zealot
(@CGUID+103,39990,645,3,1,0,555.064,902.663,155.4583,5.445427,7200,0,0), -- Twilight Zealot
(@CGUID+104,39990,645,3,1,0,558.66,897.497,155.4593,2.478368,7200,0,0), -- Twilight Zealot
(@CGUID+105,39990,645,3,1,0,559.599,902.392,155.4583,3.769911,7200,0,0), -- Twilight Zealot
(@CGUID+106,39990,645,3,1,0,569.476,924.8527,155.3561,1.563055,7200,0,0), -- Twilight Zealot
(@CGUID+107,39990,645,3,1,0,569.644,848.913,175.6283,0.7679449,7200,0,0), -- Twilight Zealot
(@CGUID+108,39990,645,3,1,0,571.691,855.083,175.6283,4.974188,7200,0,0), -- Twilight Zealot
(@CGUID+109,39990,645,3,1,0,573.0263,930.8021,155.3593,1.562013,7200,0,0), -- Twilight Zealot
(@CGUID+110,39990,645,3,1,0,573.2552,946.663,155.3434,1.556364,7200,0,0), -- Twilight Zealot
(@CGUID+111,39990,645,3,1,0,576.4034,924.7527,155.3523,1.563057,7200,0,0), -- Twilight Zealot
(@CGUID+112,39990,645,3,1,0,577.561,855.535,175.6283,4.101524,7200,0,0), -- Twilight Zealot
(@CGUID+113,39990,645,3,1,0,578.6962,860.1371,155.5572,0,7200,0,0), -- Twilight Zealot
(@CGUID+114,39990,645,3,1,0,578.885,849.097,175.6283,2.373648,7200,0,0), -- Twilight Zealot
(@CGUID+115,39990,645,3,1,0,579.5712,868.316,155.5567,5.393067,7200,0,0), -- Twilight Zealot
(@CGUID+116,39990,645,3,1,0,579.863,896.743,155.4593,2.460914,7200,0,0), -- Twilight Zealot
(@CGUID+117,39990,645,3,1,0,581.288,910.3,155.4583,3.420845,7200,0,0), -- Twilight Zealot
(@CGUID+118,39990,645,3,1,0,583.7761,857.3611,155.5906,1.902409,7200,0,0), -- Twilight Zealot
(@CGUID+119,39990,645,3,1,0,588.3629,863.2864,155.5872,2.96706,7200,0,0), -- Twilight Zealot
(@CGUID+120,39994,645,3,1,0,242.3948,802.1101,95.90906,2.898611,7200,0,0), -- Conflagration
(@CGUID+121,39994,645,3,1,0,268.7686,787.3214,95.35321,1.517033,7200,0,0), -- Conflagration
(@CGUID+122,40004,645,3,1,0,196.6858,793.0156,96.03369,0,7200,0,0), -- Quicksilver
(@CGUID+123,40004,645,3,1,0,199.8767,764.9114,96.03369,0,7200,0,0), -- Quicksilver
(@CGUID+124,40004,645,3,1,0,200.4375,779.9636,95.41864,0,7200,0,0), -- Quicksilver
(@CGUID+125,40004,645,3,1,0,212.7344,812.1979,95.41864,0,7200,0,0), -- Quicksilver
(@CGUID+126,40004,645,3,1,0,213.0399,781.9358,95.99241,0,7200,0,0), -- Quicksilver
(@CGUID+127,40004,645,3,1,0,217.033,799.2239,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+128,40004,645,3,1,0,219.3698,767.6962,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+129,40004,645,3,1,0,222.375,822.7483,96.03369,0,7200,0,0), -- Quicksilver
(@CGUID+130,40004,645,3,1,0,227.1163,779.507,95.99241,0,7200,0,0), -- Quicksilver
(@CGUID+131,40004,645,3,1,0,231.5,796.5174,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+132,40004,645,3,1,0,232.8542,809.1702,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+133,40004,645,3,1,0,235.1875,759.4774,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+134,40004,645,3,1,0,238.6372,828.9219,96.01189,0,7200,0,0), -- Quicksilver
(@CGUID+135,40004,645,3,1,0,242.8524,747.8611,95.41864,0,7200,0,0), -- Quicksilver
(@CGUID+136,40004,645,3,1,0,247.2344,774.1042,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+137,40004,645,3,1,0,248.7205,805.9844,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+138,40004,645,3,1,0,249.3038,793.9028,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+139,40004,645,3,1,0,252.1354,762.092,95.99241,0,7200,0,0), -- Quicksilver
(@CGUID+140,40004,645,3,1,0,253.9653,820.5903,96.03365,0,7200,0,0), -- Quicksilver
(@CGUID+141,40004,645,3,1,0,259.2257,751.632,96.03369,0,7200,0,0), -- Quicksilver
(@CGUID+142,40004,645,3,1,0,261.1389,775.0191,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+143,40004,645,3,1,0,261.8594,793.2969,95.99237,0,7200,0,0), -- Quicksilver
(@CGUID+144,40004,645,3,1,0,268.007,813.3802,96.03365,0,7200,0,0), -- Quicksilver
(@CGUID+145,40004,645,3,1,0,270.6545,760.3351,96.03369,0,7200,0,0), -- Quicksilver
(@CGUID+146,40004,645,3,1,0,272.0208,796.4688,95.41864,0,7200,0,0), -- Quicksilver
(@CGUID+147,40004,645,3,1,0,272.8212,771.3333,95.41864,0,7200,0,0), -- Quicksilver
(@CGUID+148,40004,645,3,1,0,277.2813,782.6771,96.03369,0,7200,0,0), -- Quicksilver
(@CGUID+149,40008,645,3,1,0,116.3366,567.625,76.45014,3.499963,7200,6,1), -- Lucky
(@CGUID+150,40011,645,3,1,0,124.7781,577.5942,76.425,6.009925,7200,6,1), -- Spot
(@CGUID+151,40013,645,3,1,0,116.3156,592.5334,76.28657,4.005537,7200,6,1), -- Buster
(@CGUID+152,40015,645,3,1,0,84.46449,612.9581,76.87782,0.0431063,7200,6,1), -- Runty
(@CGUID+153,40017,645,3,1,0,137.1615,576.2795,76.46402,1.413717,7200,0,0), -- Twilight Element Warden
(@CGUID+154,40017,645,3,1,0,155.3264,584.0781,77.05341,5.410521,7200,0,0), -- Twilight Element Warden
(@CGUID+155,40017,645,3,1,0,176.7222,576.6285,76.26083,2.86234,7200,0,0), -- Twilight Element Warden
(@CGUID+156,40017,645,3,1,0,184.2656,587.5608,76.19287,3.351032,7200,0,0), -- Twilight Element Warden
(@CGUID+157,40017,645,3,1,0,194.3993,697.5729,106.9424,3.438299,7200,0,0), -- Twilight Element Warden
(@CGUID+158,40017,645,3,1,0,202.1076,633.3004,83.04056,3.193953,7200,0,0), -- Twilight Element Warden
(@CGUID+159,40017,645,3,1,0,225.809,711.4879,108.6302,0,7200,0,0), -- Twilight Element Warden
(@CGUID+160,40017,645,3,1,0,234.7795,584.0018,74.80123,1.343904,7200,0,0), -- Twilight Element Warden
(@CGUID+161,40017,645,3,1,0,238.033,582.0087,74.79556,1.186824,7200,0,0), -- Twilight Element Warden
(@CGUID+162,40017,645,3,1,0,258.967,542.0382,72.03625,0.5585054,7200,0,0), -- Twilight Element Warden
(@CGUID+163,40017,645,3,1,0,262.6892,549.507,71.39024,4.974188,7200,0,0), -- Twilight Element Warden
(@CGUID+164,40017,645,3,1,0,327.151,541.1458,66.14465,1.186824,7200,0,0), -- Twilight Element Warden (Auras: 74919 - Shadow Channeling)
(@CGUID+165,40017,645,3,1,0,327.3663,570.3507,66.08982,5.288348,7200,0,0), -- Twilight Element Warden (Auras: 74919 - Shadow Channeling)
(@CGUID+166,40017,645,3,1,0,333.0816,525.3073,66.08982,5.131268,7200,0,0), -- Twilight Element Warden (Auras: 74919 - Shadow Channeling)
(@CGUID+167,40017,645,3,1,0,334.8021,585.0452,66.08981,0.7330383,7200,0,0), -- Twilight Element Warden (Auras: 74919 - Shadow Channeling)
(@CGUID+168,40017,645,3,1,0,344.1354,547.618,66.08982,2.548181,7200,0,0), -- Twilight Element Warden (Auras: 74919 - Shadow Channeling)
(@CGUID+169,40017,645,3,1,0,344.8594,563.1111,66.08982,3.752458,7200,0,0), -- Twilight Element Warden (Auras: 74919 - Shadow Channeling)
(@CGUID+170,40017,645,3,1,0,364.0764,561.9757,66.08982,0.2094395,7200,0,0), -- Twilight Element Warden (Auras: 74919 - Shadow Channeling)
(@CGUID+171,40019,645,3,1,0,131.934,591.6805,76.48221,3.106686,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+172,40019,645,3,1,0,197.3455,692.7188,104.0543,3.351032,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+173,40019,645,3,1,0,197.5017,707.9722,108.5086,3.281219,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+174,40019,645,3,1,0,205.1094,639.257,84.54418,3.281219,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+175,40019,645,3,1,0,206.526,624.3542,79.72306,3.351032,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+176,40019,645,3,1,0,223.0486,702.0677,106.7712,0,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+177,40019,645,3,1,0,223.2014,717.3246,107.2943,0,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+178,40019,645,3,1,0,245.099,576.9496,73.50153,1.169371,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+179,40019,645,3,1,0,249.3403,583.2361,73.55111,3.595378,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+180,40019,645,3,1,0,268.5955,538.2917,70.13752,2.164208,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+181,40019,645,3,1,0,271.0903,544.408,69.71547,3.351032,7200,0,0), -- Twilight Obsidian Borer
(@CGUID+182,40021,645,3,1,0,194.4375,702.007,108.3205,3.193953,7200,0,0), -- Incendiary Spark
(@CGUID+183,40021,645,3,1,0,202.0694,628.8663,81.64723,3.438299,7200,0,0), -- Incendiary Spark
(@CGUID+184,40021,645,3,1,0,225.7726,707.0538,109.457,0,7200,0,0), -- Incendiary Spark
(@CGUID+185,40021,645,3,1,0,235.5104,590.8958,75.42557,4.485496,7200,0,0), -- Incendiary Spark
(@CGUID+186,40021,645,3,1,0,266.3924,550.0417,70.67946,4.537856,7200,0,0), -- Incendiary Spark
(@CGUID+187,40023,645,3,1,0,207.3153,681.6811,97.51474,1.90116,7200,0,0), -- Defiled Earth Rager
(@CGUID+188,40023,645,3,1,0,216.0372,680.9094,98.41308,5.042751,7200,0,0), -- Defiled Earth Rager
(@CGUID+189,40023,645,3,1,0,257.4845,565.0645,71.45449,0.1699704,7200,0,0), -- Defiled Earth Rager
(@CGUID+190,40023,645,3,1,0,264.7801,553.1334,70.93826,6.180038,7200,0,0), -- Defiled Earth Rager
(@CGUID+191,40084,645,3,1,0,188.4306,800.0469,96.03369,2.338741,7200,0,0), -- Bellows Slave
(@CGUID+192,40084,645,3,1,0,190.3351,774,96.03369,3.490659,7200,0,0), -- Bellows Slave
(@CGUID+193,40084,645,3,1,0,190.7865,769.0868,96.03369,2.687807,7200,0,0), -- Bellows Slave
(@CGUID+194,40084,645,3,1,0,198.2361,753.9653,96.03369,4.869469,7200,0,0), -- Bellows Slave
(@CGUID+195,40084,645,3,1,0,200.9549,824.6042,96.03369,1.53589,7200,0,0), -- Bellows Slave
(@CGUID+196,40084,645,3,1,0,214.2986,833.7049,95.96931,1.762783,7200,0,0), -- Bellows Slave
(@CGUID+197,40084,645,3,1,0,218.7743,837.1945,95.94936,2.827433,7200,0,0), -- Bellows Slave
(@CGUID+198,40084,645,3,1,0,251.901,842.1754,95.94706,0.2094395,7200,0,0), -- Bellows Slave
(@CGUID+199,40084,645,3,1,0,253.5451,839.882,95.95775,1.117011,7200,0,0), -- Bellows Slave
(@CGUID+200,40084,645,3,1,0,260.1945,739.0364,96.03369,4.782202,7200,0,0), -- Bellows Slave
(@CGUID+201,40084,645,3,1,0,262.0174,731.4479,96.03369,4.991642,7200,0,0), -- Bellows Slave
(@CGUID+202,40084,645,3,1,0,267.6371,740.7847,96.03369,6.003932,7200,0,0), -- Bellows Slave
(@CGUID+203,40084,645,3,1,0,269.026,735.7153,96.03369,0.9250245,7200,0,0), -- Bellows Slave
(@CGUID+204,40084,645,3,1,0,286.6111,754.4636,96.03369,4.625123,7200,0,0), -- Bellows Slave
(@CGUID+205,40084,645,3,1,0,289.342,751.7465,96.03369,3.246312,7200,0,0), -- Bellows Slave
(@CGUID+206,40084,645,3,1,0,295.0035,783.4705,96.03369,0.6108652,7200,0,0), -- Bellows Slave
(@CGUID+207,40084,645,3,1,0,297.3559,767.2153,96.03369,5.462881,7200,0,0), -- Bellows Slave
(@CGUID+208,40084,645,3,1,0,299.3368,779.8299,96.03369,1.727876,7200,0,0), -- Bellows Slave
(@CGUID+209,40343,645,3,1,0,174.1386,648.5196,114.2773,1.689243,7200,0,0), -- Channel Target
(@CGUID+210,40343,645,3,1,0,174.4709,650.2501,103.5642,1.538399,7200,0,0), -- Channel Target
(@CGUID+211,40343,645,3,1,0,176.22,714.8383,121.7261,1.468592,7200,0,0), -- Channel Target
(@CGUID+212,40343,645,3,1,0,187.9925,677.471,112.4013,4.865127,7200,0,0), -- Channel Target
(@CGUID+213,40343,645,3,1,0,235.2571,718.1427,145.1983,1.692821,7200,0,0), -- Channel Target
(@CGUID+214,40343,645,3,1,0,240.4132,717.788,115.9308,1.607007,7200,0,0), -- Channel Target
(@CGUID+215,49476,645,3,1,0,237.8299,1122.021,205.7137,2.426008,7200,0,0), -- Finkle Einhorn
(@CGUID+216,49526,645,3,1,0,541.3299,909.066,169.6451,0,7200,0,0), -- Corla Quest Bang
(@CGUID+217,49529,645,3,1,0,293.6771,815.5886,103.6035,0,7200,0,0), -- Karsh Quest Bang
(@CGUID+218,49530,645,3,1,0,200.4427,582.7188,76.05556,0,7200,0,0), -- Beauty Quest Bang
(@CGUID+219,49531,645,3,1,0,251.8142,562.7014,72.48589,0,7200,0,0), -- Obsidius Quest Bang
(@CGUID+220,50284,645,3,1,0,561.9618,983.0191,155.4369,1.553343,7200,0,0), -- Twilight Zealot
(@CGUID+221,50284,645,3,1,0,585.0278,982.8993,155.4369,1.500983,7200,0,0), -- Twilight Zealot
(@CGUID+222,51340,645,3,1,0,237.3038,1130.073,205.6521,3.630285,7200,0,0), -- Twilight Portal
(@CGUID+223,51340,645,3,1,0,289.3906,844.4028,96.00695,3.979351,7200,0,0), -- Twilight Portal
(@CGUID+224,53488,645,3,1,0,213.9306,1128.349,205.6521,0,7200,0,0); -- Summon Enabler Stalker

-- Pooling of Twilight Torturer with Twilight Sadist & Mad Prisoner with Crazed Sadist
DELETE FROM `pool_creature` WHERE `guid` BETWEEN @CGUID+39 AND @CGUID+74;
INSERT INTO `pool_creature` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(@CGUID+39,@POOL1+0,0, 'Twilight Torturer'),
(@CGUID+52,@POOL1+0,0, 'Twilight Sadist'),
(@CGUID+40,@POOL1+1,0, 'Twilight Torturer'),
(@CGUID+53,@POOL1+1,0, 'Twilight Sadist'),
(@CGUID+41,@POOL1+2,0, 'Twilight Torturer'),
(@CGUID+54,@POOL1+2,0, 'Twilight Sadist'),
(@CGUID+42,@POOL1+3,0, 'Twilight Torturer'),
(@CGUID+55,@POOL1+3,0, 'Twilight Sadist'),
(@CGUID+43,@POOL1+4,0, 'Twilight Torturer'),
(@CGUID+56,@POOL1+4,0, 'Twilight Sadist'),
(@CGUID+44,@POOL1+5,0, 'Twilight Torturer'),
(@CGUID+57,@POOL1+5,0, 'Twilight Sadist'),
(@CGUID+45,@POOL1+6,0, 'Twilight Torturer'),
(@CGUID+58,@POOL1+6,0, 'Twilight Sadist'),
(@CGUID+46,@POOL1+7,0, 'Twilight Torturer'),
(@CGUID+59,@POOL1+7,0, 'Twilight Sadist'),
(@CGUID+47,@POOL1+8,0, 'Twilight Torturer'),
(@CGUID+60,@POOL1+8,0, 'Twilight Sadist'),
(@CGUID+48,@POOL1+9,0, 'Twilight Torturer'),
(@CGUID+61,@POOL1+9,0, 'Twilight Sadist'),
(@CGUID+49,@POOL1+10,0, 'Twilight Torturer'),
(@CGUID+62,@POOL1+10,0, 'Twilight Sadist'),
(@CGUID+50,@POOL1+11,0, 'Twilight Torturer'),
(@CGUID+63,@POOL1+11,0, 'Twilight Sadist'),
(@CGUID+51,@POOL1+12,0, 'Twilight Torturer'),
(@CGUID+64,@POOL1+12,0, 'Twilight Sadist'),
(@CGUID+65,@POOL1+13,0, 'Mad Prisoner'),
(@CGUID+70,@POOL1+13,0, 'Crazed Sadist'),
(@CGUID+66,@POOL1+14,0, 'Mad Prisoner'),
(@CGUID+71,@POOL1+14,0, 'Crazed Sadist'),
(@CGUID+67,@POOL1+15,0, 'Mad Prisoner'),
(@CGUID+72,@POOL1+15,0, 'Crazed Sadist'),
(@CGUID+68,@POOL1+16,0, 'Mad Prisoner'),
(@CGUID+73,@POOL1+16,0, 'Crazed Sadist'),
(@CGUID+69,@POOL1+17,0, 'Mad Prisoner'),
(@CGUID+74,@POOL1+17,0, 'Crazed Sadist');

-- Add each pool to pool template
DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOL1 AND @POOL1+17;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOL1+0,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+1,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+2,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+3,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+4,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+5,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+6,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+7,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+8,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+9,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+10,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+11,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+12,1, 'Twilight Torturer / Twilight Sadist Spawnpoint'),
(@POOL1+13,1, 'Mad Prisoner / Crazed Sadist Spawnpoint'),
(@POOL1+14,1, 'Mad Prisoner / Crazed Sadist Spawnpoint'),
(@POOL1+15,1, 'Mad Prisoner / Crazed Sadist Spawnpoint'),
(@POOL1+16,1, 'Mad Prisoner / Crazed Sadist Spawnpoint'),
(@POOL1+17,1, 'Mad Prisoner / Crazed Sadist Spawnpoint');

-- Pathing for Rom'ogg Bonecrusher Entry: 39665
SET @NPC := @CGUID+8;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=214.854,`position_y`=949.078,`position_z`=191.1339 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,214.854,949.078,191.1339,0,0,0,0,100,0),
(@PATH,2,204.109,943.101,190.9295,0,0,0,0,100,0),
(@PATH,3,205.149,933.491,190.9829,0,0,0,0,100,0),
(@PATH,4,208.394,918.686,190.8661,0,0,0,0,100,0),
(@PATH,5,218.372,911.096,191.0219,0,0,0,0,100,0),
(@PATH,6,234.236,909.46,191.0063,0,0,0,0,100,0),
(@PATH,7,244.66,906.797,191.0049,0,0,0,0,100,0),
(@PATH,8,259.266,911.854,191.0516,0,10000,0,0,100,0),
(@PATH,9,240.503,907.26,190.9378,0,0,0,0,100,0),
(@PATH,10,230.382,910.533,191.0554,0,0,0,0,100,0),
(@PATH,11,213.3,913.29,190.9517,0,0,0,0,100,0),
(@PATH,12,206.092,928.054,190.9667,0,0,0,0,100,0),
(@PATH,13,206.747,939.877,190.9951,0,0,0,0,100,0),
(@PATH,14,210.877,947.825,191.0551,0,0,0,0,100,0),
(@PATH,15,219.627,949.323,191.2103,0,0,0,0,100,0),
(@PATH,16,228.863,949.438,192.7179,0,25000,0,0,100,0);
-- 0xF1309AF1000100D9 .go 214.854 949.078 191.1339

-- Pathing for Karsh Steelbender Entry: 39698
SET @NPC := @CGUID+10;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=246.208,`position_y`=789.674,`position_z`=95.90906 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,246.208,789.674,95.90906,0,0,0,0,100,0),
(@PATH,2,246.208,789.674,95.90906,3.368485,13000,0,0,100,0),
(@PATH,3,243.955,777.349,95.90906,0,0,0,0,100,0),
(@PATH,4,237.286,774.547,95.90906,0,0,0,0,100,0),
(@PATH,5,237.286,774.547,95.90906,1.413717,11000,0,0,100,0),
(@PATH,6,227.6367,783.0032,95.90906,0,0,0,0,100,0),
(@PATH,7,228.601,789.87,95.90906,0,0,0,0,100,0),
(@PATH,8,233.83,794.087,95.90906,0,0,0,0,100,0),
(@PATH,9,233.83,794.087,95.90906,5.061455,12000,0,0,100,0);
-- 0xF1309B12000100A8 .go 246.208 789.674 95.90906

-- Pathing for Twilight Flame Caller Entry: 39708
SET @NPC := @CGUID+14;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=198.4846,`position_y`=1003.721,`position_z`=196.2257 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,200.6576,1003.341,195.9137,0,0,0,0,100,0),
(@PATH,2,199.2066,1023.467,200.2262,0,0,0,0,100,0),
(@PATH,3,210.684,1043.625,203.9309,0,0,0,0,100,0),
(@PATH,4,210.1458,1056.205,205.8059,0,0,0,0,100,0),
(@PATH,5,209.599,1076.283,205.7519,0,0,0,0,100,0),
(@PATH,6,210.1411,1056.378,205.8421,0,0,0,0,100,0),
(@PATH,7,210.684,1043.625,203.9309,0,0,0,0,100,0),
(@PATH,8,199.2066,1023.467,200.2262,0,0,0,0,100,0);
-- 0xF1309B1C00010087 .go 210.684 1043.625 203.9309

-- Pathing for Twilight Flame Caller Entry: 39708
SET @NPC := @CGUID+15;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=200.6576,`position_y`=1003.341,`position_z`=195.9137 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,200.6576,1003.341,195.9137,0,0,0,0,100,0),
(@PATH,2,199.2066,1023.467,200.2262,0,0,0,0,100,0),
(@PATH,3,210.684,1043.625,203.9309,0,0,0,0,100,0),
(@PATH,4,210.1458,1056.205,205.8059,0,0,0,0,100,0),
(@PATH,5,209.599,1076.283,205.7519,0,0,0,0,100,0),
(@PATH,6,210.1411,1056.378,205.8421,0,0,0,0,100,0),
(@PATH,7,210.684,1043.625,203.9309,0,0,0,0,100,0),
(@PATH,8,199.2066,1023.467,200.2262,0,0,0,0,100,0);
-- 0xF1309B1C00010087 .go 210.684 1043.625 203.9309

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+15;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@CGUID+15,@CGUID+15,0,0,2,0,0),(@CGUID+15,@CGUID+14,2,270,2,4,8);

-- Pathing for Twilight Flame Caller Entry: 39708
SET @NPC := @CGUID+17;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=487.7131,`position_y`=915.9505,`position_z`=182.1529 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,488.7621,917.1805,182.1009,0,0,0,0,100,0),
(@PATH,2,500.6771,908.9601,181.4732,0,0,0,0,100,0),
(@PATH,3,525.4479,908.7518,173.7153,0,0,0,0,100,0),
(@PATH,4,500.8809,908.9584,181.3861,0,0,0,0,100,0),
(@PATH,5,488.7621,917.1805,182.1009,0,0,0,0,100,0),
(@PATH,6,482.4358,926.3125,182.475,0,0,0,0,100,0),
(@PATH,7,481.8889,940.908,183.6355,0,0,0,0,100,0),
(@PATH,8,470.3941,950.5399,188.7073,0,0,0,0,100,0),
(@PATH,9,450.6371,950.8177,195.9036,0,0,0,0,100,0),
(@PATH,10,470.3941,950.5399,188.7073,0,0,0,0,100,0),
(@PATH,11,481.8889,940.908,183.6355,0,0,0,0,100,0),
(@PATH,12,482.4358,926.3125,182.475,0,0,0,0,100,0);
-- 0xF1309B1C00010133 .go 488.7621 917.1805 182.1009

-- Pathing for Twilight Flame Caller Entry: 39708
SET @NPC := @CGUID+18;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=488.7621,`position_y`=917.1805,`position_z`=182.1009 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,488.7621,917.1805,182.1009,0,0,0,0,100,0),
(@PATH,2,500.6771,908.9601,181.4732,0,0,0,0,100,0),
(@PATH,3,525.4479,908.7518,173.7153,0,0,0,0,100,0),
(@PATH,4,500.8809,908.9584,181.3861,0,0,0,0,100,0),
(@PATH,5,488.7621,917.1805,182.1009,0,0,0,0,100,0),
(@PATH,6,482.4358,926.3125,182.475,0,0,0,0,100,0),
(@PATH,7,481.8889,940.908,183.6355,0,0,0,0,100,0),
(@PATH,8,470.3941,950.5399,188.7073,0,0,0,0,100,0),
(@PATH,9,450.6371,950.8177,195.9036,0,0,0,0,100,0),
(@PATH,10,470.3941,950.5399,188.7073,0,0,0,0,100,0),
(@PATH,11,481.8889,940.908,183.6355,0,0,0,0,100,0),
(@PATH,12,482.4358,926.3125,182.475,0,0,0,0,100,0);
-- 0xF1309B1C00010133 .go 488.7621 917.1805 182.1009

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+18;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@CGUID+18,@CGUID+18,0,0,2,0,0),(@CGUID+18,@CGUID+17,2,270,2,2,8);

-- Pathing for Twilight Torturer Entry: 39978
SET @NPC := @CGUID+39;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=196.0694,`position_y`=913.0052,`position_z`=191.4303 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,196.0694,913.0052,191.4303,0,0,0,0,100,0),
(@PATH,2,196.0694,913.0052,191.4303,5.218534,15000,0,0,100,0),
(@PATH,3,197.1215,935.618,191.4617,0,0,0,0,100,0),
(@PATH,4,185.309,954.3386,190.7749,0,0,0,0,100,0),
(@PATH,5,185.309,954.3386,190.7749,2.565634,15000,0,0,100,0),
(@PATH,6,197.2535,932.967,191.4638,0,0,0,0,100,0);
-- 0xF1309C2A00010095 .go 196.0694 913.0052 191.4303

-- Pathing for Twilight Torturer Entry: 39978
SET @NPC := @CGUID+40;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=182.566,`position_y`=966.7674,`position_z`=190.7432 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,182.566,966.7674,190.7432,0,0,0,0,100,0),
(@PATH,2,182.566,966.7674,190.7432,4.014257,15000,0,0,100,0),
(@PATH,3,219.5729,978.2986,190.9955,0,0,0,0,100,0),
(@PATH,4,249.1944,997.5781,191.1551,0,0,0,0,100,0),
(@PATH,5,249.1944,997.5781,191.1551,4.834562,12000,0,0,100,0),
(@PATH,6,218.908,979.0764,190.9712,0,0,0,0,100,0);
-- 0xF1309C2A00010086 .go 182.566 966.7674 190.7432

-- Pathing for Twilight Torturer Entry: 39978
SET @NPC := @CGUID+41;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=202.684,`position_y`=909.4375,`position_z`=190.8059 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,202.684,909.4375,190.8059,4.08407,15000,0,0,100,0),
(@PATH,2,212.934,929.7986,191.0911,0,0,0,0,100,0),
(@PATH,3,212.934,929.7986,191.0911,0.8377581,15000,0,0,100,0),
(@PATH,4,202.684,909.4375,190.8059,0,0,0,0,100,0);
-- 0xF1309C2C0001010B .go 202.684 909.4375 190.8059

-- Pathing for Twilight Sadist Entry: 39980
SET @NPC := @CGUID+52;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=196.0694,`position_y`=913.0052,`position_z`=191.4303 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,196.0694,913.0052,191.4303,0,0,0,0,100,0),
(@PATH,2,196.0694,913.0052,191.4303,5.218534,15000,0,0,100,0),
(@PATH,3,197.1215,935.618,191.4617,0,0,0,0,100,0),
(@PATH,4,185.309,954.3386,190.7749,0,0,0,0,100,0),
(@PATH,5,185.309,954.3386,190.7749,2.565634,15000,0,0,100,0),
(@PATH,6,197.2535,932.967,191.4638,0,0,0,0,100,0);
-- 0xF1309C2A00010095 .go 196.0694 913.0052 191.4303

-- Pathing for Twilight Sadist Entry: 39980
SET @NPC := @CGUID+53;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=182.566,`position_y`=966.7674,`position_z`=190.7432 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,182.566,966.7674,190.7432,0,0,0,0,100,0),
(@PATH,2,182.566,966.7674,190.7432,4.014257,15000,0,0,100,0),
(@PATH,3,219.5729,978.2986,190.9955,0,0,0,0,100,0),
(@PATH,4,249.1944,997.5781,191.1551,0,0,0,0,100,0),
(@PATH,5,249.1944,997.5781,191.1551,4.834562,12000,0,0,100,0),
(@PATH,6,218.908,979.0764,190.9712,0,0,0,0,100,0);
-- 0xF1309C2A00010086 .go 182.566 966.7674 190.7432

-- Pathing for Twilight Sadist Entry: 39980
SET @NPC := @CGUID+54;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=202.684,`position_y`=909.4375,`position_z`=190.8059 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,202.684,909.4375,190.8059,4.08407,15000,0,0,100,0),
(@PATH,2,212.934,929.7986,191.0911,0,0,0,0,100,0),
(@PATH,3,212.934,929.7986,191.0911,0.8377581,15000,0,0,100,0),
(@PATH,4,202.684,909.4375,190.8059,0,0,0,0,100,0);
-- 0xF1309C2C0001010B .go 202.684 909.4375 190.8059

-- Pathing for Evolved Twilight Zealot Entry: 39987
SET @NPC := @CGUID+92;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=437.0642,`position_y`=819.9445,`position_z`=108.634 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,437.0642,819.9445,108.634,0,0,0,0,100,0),
(@PATH,2,443.8438,818.0555,109.1003,0,0,0,0,100,0),
(@PATH,3,461.5885,813.0903,113.58,0,0,0,0,100,0),
(@PATH,4,478.9115,811.2952,113.8427,0,0,0,0,100,0),
(@PATH,5,461.5885,813.0903,113.58,0,0,0,0,100,0);
-- 0xF1309C33000100E5 .go 437.0642 819.9445 108.634

-- Pathing for Evolved Twilight Zealot Entry: 39987
SET @NPC := @CGUID+93;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=482.4063,`position_y`=865.3802,`position_z`=125.9629 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,482.4063,865.3802,125.9629,0,0,0,0,100,0),
(@PATH,2,502.1146,864.9948,128.3744,0,0,0,0,100,0),
(@PATH,3,538.3211,864.5647,137.2533,0,0,0,0,100,0),
(@PATH,4,559.1823,863.3906,145.8524,0,0,0,0,100,0),
(@PATH,5,538.6493,864.5608,137.2742,0,0,0,0,100,0),
(@PATH,6,502.1503,864.9944,128.3311,0,0,0,0,100,0);
-- 0xF1309C3300010136 .go 482.4063 865.3802 125.9629

-- Pathing for Evolved Twilight Zealot Entry: 39987
SET @NPC := @CGUID+94;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=564.4983,`position_y`=859.6597,`position_z`=175.5455 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,564.4983,859.6597,175.5455,0,0,0,0,100,0),
(@PATH,2,548.7483,859.6285,175.5455,0,0,0,0,100,0),
(@PATH,3,548.9299,888.4893,169.5474,0,0,0,0,100,0),
(@PATH,4,548.9029,916.0901,169.4919,0,0,0,0,100,0),
(@PATH,5,548.9305,888.5868,169.5618,0,0,0,0,100,0),
(@PATH,6,548.7483,859.6285,175.5455,0,0,0,0,100,0);
-- 0xF1309C33000100F1 .go 564.4983 859.6597 175.5455

-- Pathing for Evolved Twilight Zealot Entry: 39987
SET @NPC := @CGUID+95;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=597.4132,`position_y`=963.4583,`position_z`=155.3391 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,597.4132,963.4583,155.3391,0,0,0,0,100,0),
(@PATH,2,598.8177,921.9514,169.4209,0,0,0,0,100,0),
(@PATH,3,599.0471,886.2664,170.245,0,0,0,0,100,0),
(@PATH,4,598.7379,859.5486,175.5455,0,0,0,0,100,0),
(@PATH,5,582.7205,859.3629,175.5455,0,0,0,0,100,0),
(@PATH,6,598.7379,859.5486,175.5455,0,0,0,0,100,0),
(@PATH,7,599.0486,886.0261,170.2859,0,0,0,0,100,0),
(@PATH,8,598.8177,921.9514,169.4209,0,0,0,0,100,0);
-- 0xF1309C33000100F2 .go 597.4132 963.4583 155.3391

-- Pathing for Twilight Zealot Entry: 39990
SET @NPC := @CGUID+110;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=573.0608,`position_y`=919.9618,`position_z`=155.3706 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,573.0608,919.9618,155.3706,0,0,0,0,100,0),
(@PATH,2,572.6077,881.7958,155.4112,0,0,0,0,100,0),
(@PATH,3,572.9063,922.4861,155.3676,0,0,0,0,100,0),
(@PATH,4,573.533,965.9149,155.2293,0,0,0,0,100,0);
-- 0xF1309C36000100F3 .go 573.0608 919.9618 155.3706

-- Pathing for Twilight Zealot Entry: 39990 (16 yards behind @CGUID+110)
SET @NPC := @CGUID+109;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
-- UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=573.0608,`position_y`=919.9618,`position_z`=155.3706 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,573.0608,919.9618,155.3706,0,0,0,0,100,0),
(@PATH,2,572.6077,881.7958,155.4112,0,0,0,0,100,0),
(@PATH,3,572.9063,922.4861,155.3676,0,0,0,0,100,0),
(@PATH,4,573.533,965.9149,155.2293,0,0,0,0,100,0);
-- 0xF1309C36000100F3 .go 573.0608 919.9618 155.3706

-- Pathing for Conflagration Entry: 39994
SET @NPC := @CGUID+120;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=224.9271,`position_y`=799.3004,`position_z`=95.90906 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,224.9271,799.3004,95.90906,0,0,0,0,100,0),
(@PATH,2,219.5799,790.868,95.90906,0,0,0,0,100,0),
(@PATH,3,218.191,781.5156,95.90906,0,0,0,0,100,0),
(@PATH,4,222.4549,772.9028,95.90906,0,0,0,0,100,0),
(@PATH,5,228.5174,767.6424,95.90906,0,0,0,0,100,0),
(@PATH,6,236.9931,765.9827,95.90906,0,0,0,0,100,0),
(@PATH,7,246.7813,767.6215,95.90906,0,0,0,0,100,0),
(@PATH,8,253.2986,773.7743,95.90906,0,0,0,0,100,0),
(@PATH,9,256.9861,783.7083,95.90906,0,0,0,0,100,0),
(@PATH,10,254.4618,794.4861,95.90906,0,0,0,0,100,0),
(@PATH,11,247.0764,800.9496,95.90906,0,0,0,0,100,0),
(@PATH,12,234.8056,803.9913,95.90906,0,0,0,0,100,0);
-- 0xF1309C3A0001013F .go 224.9271 799.3004 95.90906

-- Pathing for Conflagration Entry: 39994
SET @NPC := @CGUID+121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=251.434,`position_y`=813.3768,`position_z`=95.356 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,251.434,813.3768,95.356,0,0,0,0,100,0),
(@PATH,2,237.7483,816.7483,95.3567,0,0,0,0,100,0),
(@PATH,3,223.3594,813.6754,95.35637,0,0,0,0,100,0),
(@PATH,4,213.6858,805.6042,95.35384,0,0,0,0,100,0),
(@PATH,5,206.6354,795.6858,95.35766,0,0,0,0,100,0),
(@PATH,6,205.658,784.5156,95.35373,0,0,0,0,100,0),
(@PATH,7,209.1302,769.566,95.35688,0,0,0,0,100,0),
(@PATH,8,217.9844,759.0087,95.35704,0,0,0,0,100,0),
(@PATH,9,229.9028,753.6788,95.35407,0,0,0,0,100,0),
(@PATH,10,246.8142,754.1702,95.35651,0,0,0,0,100,0),
(@PATH,11,261.967,763.9184,95.35499,0,0,0,0,100,0),
(@PATH,12,268.1649,776.1042,95.35583,0,0,0,0,100,0),
(@PATH,13,268.941,790.5243,95.3568,0,0,0,0,100,0),
(@PATH,14,262.6701,803.6268,95.35423,0,0,0,0,100,0);
-- 0xF1309C3A00010149 .go 251.434 813.3768 95.356

-- Pathing for Defiled Earth Rager Entry: 40023
SET @NPC := @CGUID+187;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=216.3906,`position_y`=655.217,`position_z`=90.25638 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,216.3906,655.217,90.25638,0,0,0,0,100,0),
(@PATH,2,214.2743,631.2239,82.40944,0,0,0,0,100,0),
(@PATH,3,207.6684,601.066,75.51769,0,0,0,0,100,0),
(@PATH,4,214.2743,631.2239,82.40944,0,0,0,0,100,0),
(@PATH,5,216.3906,655.217,90.25638,0,0,0,0,100,0),
(@PATH,6,205.7413,686.2708,99.24993,0,0,0,0,100,0);
-- 0xF1309C57000100BF .go 216.3906 655.217 90.25638

-- Pathing for Defiled Earth Rager Entry: 40023
SET @NPC := @CGUID+188;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=216.3906,`position_y`=655.217,`position_z`=90.25638 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,216.3906,655.217,90.25638,0,0,0,0,100,0),
(@PATH,2,214.2743,631.2239,82.40944,0,0,0,0,100,0),
(@PATH,3,207.6684,601.066,75.51769,0,0,0,0,100,0),
(@PATH,4,214.2743,631.2239,82.40944,0,0,0,0,100,0),
(@PATH,5,216.3906,655.217,90.25638,0,0,0,0,100,0),
(@PATH,6,205.7413,686.2708,99.24993,0,0,0,0,100,0);
-- 0xF1309C57000100BF .go 216.3906 655.217 90.25638

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+187;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@CGUID+187,@CGUID+187,0,0,2,0,0),(@CGUID+187,@CGUID+188,6,270,2,2,5);

-- Pathing for Defiled Earth Rager Entry: 40023
SET @NPC := @CGUID+189;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=291.2743,`position_y`=556.941,`position_z`=67.7907 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,291.2743,556.941,67.7907,0,0,0,0,100,0),
(@PATH,2,257.7969,565.118,71.41065,0,0,0,0,100,0),
(@PATH,3,219.7118,558.5816,75.38116,0,0,0,0,100,0),
(@PATH,4,257.7969,565.118,71.41065,0,0,0,0,100,0);
-- 0xF1309C57000100CF .go 291.2743 556.941 67.7907

-- Pathing for Defiled Earth Rager Entry: 40023
SET @NPC := @CGUID+190;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=291.2743,`position_y`=556.941,`position_z`=67.7907 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,291.2743,556.941,67.7907,0,0,0,0,100,0),
(@PATH,2,257.7969,565.118,71.41065,0,0,0,0,100,0),
(@PATH,3,219.7118,558.5816,75.38116,0,0,0,0,100,0),
(@PATH,4,257.7969,565.118,71.41065,0,0,0,0,100,0);
-- 0xF1309C57000100CF .go 291.2743 556.941 67.7907

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+189;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@CGUID+189,@CGUID+189,0,0,2,0,0),(@CGUID+189,@CGUID+190,6,270,2,2,4);

-- Pathing for Channel Target Entry: 40343
SET @NPC := @CGUID+209;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=177.276,`position_y`=694.7691,`position_z`=118.4533 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,177.276,694.7691,118.4533,0,0,0,0,100,0),
(@PATH,2,177.1476,694.1702,118.331,0,0,0,0,100,0),
(@PATH,3,175.8611,701.9236,121.7041,0,0,0,0,100,0),
(@PATH,4,176.0694,713.0139,121.9032,0,0,0,0,100,0),
(@PATH,5,176.8889,719.2813,120.7642,0,0,0,0,100,0),
(@PATH,6,176.4514,712.6476,121.3422,0,0,0,0,100,0),
(@PATH,7,176.2205,702.0139,121.3422,0,0,0,0,100,0);

-- Pathing for Channel Target Entry: 40343
SET @NPC := @CGUID+210;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=235.191,`position_y`=718.6893,`position_z`=145.2353 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,235.191,718.6893,145.2353,0,0,0,0,100,0),
(@PATH,2,235.1476,718.5399,145.2267,0,0,0,0,100,0),
(@PATH,3,236.7708,705.2083,144.2278,0,0,0,0,100,0),
(@PATH,4,236.6094,698.3854,140.3665,0,0,0,0,100,0),
(@PATH,5,236.7379,705.1111,144.1367,0,0,0,0,100,0);

-- Pathing for Channel Target Entry: 40343
SET @NPC := @CGUID+211;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=240.4028,`position_y`=718.5208,`position_z`=115.8364 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,240.4028,718.5208,115.8364,0,0,0,0,100,0),
(@PATH,2,240.9601,719.1771,116.0752,0,0,0,0,100,0),
(@PATH,3,240.934,710.809,116.6008,0,0,0,0,100,0),
(@PATH,4,240.7691,701.8333,116.6676,0,0,0,0,100,0),
(@PATH,5,240.375,696.6771,116.892,0,0,0,0,100,0),
(@PATH,6,240.5938,702.0261,116.8642,0,0,0,0,100,0),
(@PATH,7,240.7882,710.6493,116.9198,0,0,0,0,100,0);

-- Pathing for Channel Target Entry: 40343
SET @NPC := @CGUID+212;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=190.6806,`position_y`=674.4202,`position_z`=112.1149 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,190.6806,674.4202,112.1149,0,0,0,0,100,0),
(@PATH,2,190.4323,676.4948,111.5509,0,0,0,0,100,0),
(@PATH,3,191.6528,674.7292,107.9121,0,0,0,0,100,0),
(@PATH,4,190.349,678.6996,108.9954,0,0,0,0,100,0),
(@PATH,5,188.2326,678.5261,110.1169,0,0,0,0,100,0),
(@PATH,6,188.0868,677.0573,113.1149,0,0,0,0,100,0),
(@PATH,7,189.092,675.6823,114.365,0,0,0,0,100,0);

-- Pathing for Channel Target Entry: 40343
SET @NPC := @CGUID+213;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=178.2587,`position_y`=626.1962,`position_z`=92.3178 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,178.2587,626.1962,92.3178,0,0,0,0,100,0),
(@PATH,2,177.9965,630.1354,95.03739,0,0,0,0,100,0),
(@PATH,3,174.6823,638.4965,100.3082,0,0,0,0,100,0),
(@PATH,4,174.5208,651.8386,103.9844,0,0,0,0,100,0),
(@PATH,5,174.8872,648.0261,103.3734,0,0,0,0,100,0),
(@PATH,6,174.7101,638.3889,100.4012,0,0,0,0,100,0),
(@PATH,7,178.0191,629.7882,94.92894,0,0,0,0,100,0);

-- Pathing for Channel Target Entry: 40343
SET @NPC := @CGUID+214;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=177.5712,`position_y`=634.5712,`position_z`=112.938 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,177.5712,634.5712,112.938,0,0,0,0,100,0),
(@PATH,2,177.7014,634.658,113.0956,0,0,0,0,100,0),
(@PATH,3,175.3281,640.2274,111.6233,0,0,0,0,100,0),
(@PATH,4,174.0243,649.3489,114.5378,0,0,0,0,100,0),
(@PATH,5,174.7153,642.2552,111.3989,0,0,0,0,100,0);

UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=40164;

-- Quest Bangs, Summon Enabler, and Conflagration
DELETE FROM `creature_template_addon` WHERE `entry` IN (49529,49530,49531,53488,39994);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES
(49529,65536,1, '92282 92286'),(49530,65536,1, '92282 92288'),(49531,65536,1, '92282 92290'),(53488,0,1, '99201'),(39994,0,1, '75083, 75077');

UPDATE `creature` SET `unit_flags`=537166656 WHERE `guid` BETWEEN @CGUID+96 AND @CGUID+100;
UPDATE `creature` SET `unit_flags`=537166656 WHERE `guid` BETWEEN @CGUID+153 AND @CGUID+156;
UPDATE `creature` SET `unit_flags`=537166656 WHERE `guid`=@CGUID+171;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+96 AND @CGUID+100;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+153 AND @CGUID+156;
DELETE FROM `creature_addon` WHERE `guid`=@CGUID+171;
INSERT INTO `creature_addon` (`guid`,`bytes2`,`auras`) VALUES 
(@CGUID+96,1, '29266'), (@CGUID+97,1, '29266'), (@CGUID+98,1, '29266'), (@CGUID+99,1, '29266'), (@CGUID+100,1, '29266'),
(@CGUID+153,1, '29266'), (@CGUID+154,1, '29266'), (@CGUID+155,1, '29266'), (@CGUID+156,1, '29266'), (@CGUID+171,1, '29266');

-- *** AURA WORKS BUT PREVENTS SPELL 75645 "Drain Essence" from working
-- Invisible Stalker (Hostile, Ignore Combat, Float, Uninteractible, Large AOI)
-- DELETE FROM `creature_addon` WHERE `guid`=@CGUID+38;
-- INSERT INTO `creature_addon` (`guid`,`bytes2`,`auras`) VALUES (@CGUID+38,1, '75649');

DELETE FROM `creature_queststarter` WHERE `id`=49476 AND `quest` IN (28737,28738,28740,28741);
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `id`=28735;
-- Add quest to quest bangs
DELETE FROM `creature_queststarter` WHERE `id` IN (49526,49529,49530,49531);
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES
(49526,28737),(49529,28738),(49530,28740),(49531,28741);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 207412, 645, 3, 1, 0, 215.434, 1028.392, 202.5022, 5.724681, 0, 0, 0, 1, 7200, 255, 1), -- Stone Tablet
(@OGUID+1, 207331, 645, 3, 1, 0, 237.4462, 1121.582, 205.7974, 2.792518, 0, 0, 0, 1, 7200, 255, 1), -- Finkle's Helm
(@OGUID+2, 202718, 645, 3, 1, 0, 215.168, 1140.959, 204.5952, 1.570796, 0, 0, 0.7071066, 0.7071069, 7200, 255, 1), -- Instance Portal
(@OGUID+3, 202698, 645, 3, 1, 0, 215.168, 1140.959, 204.5952, 1.570796, 0, 0, 0.7071066, 0.7071069, 7200, 255, 1); -- Instance Portal Heroic

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (75610,75697,75645);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 75610, 0, 0, 31, 3, 50284, 0, 0, '', 'Evolution targets Twilight Zealot'),
(13, 1, 75697, 0, 0, 31, 3, 50284, 0, 0, '', 'Evolution targets Twilight Zealot'),
(13, 1, 75645, 0, 0, 31, 3, 39842, 0, 0, '', 'Drain Essence targets Invisible Stalker');

-- Add spell target condition for Bore
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75205;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 75205, 0, 0, 31, 3, 40343, 0, 0, '', 'Bore targets Channel Target');

-- Spell Leap from Cage
DELETE FROM `spell_target_position` WHERE `id`=79720;
INSERT INTO `spell_target_position` (`id`,`effIndex`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`,`VerifiedBuild`) VALUES
(79720,0,645,227.6,949.8,192.6,0,18414);

-- Spell Leap from Bridge
DELETE FROM `spell_target_position` WHERE `id`=80273;
INSERT INTO `spell_target_position` (`id`,`effIndex`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`,`VerifiedBuild`) VALUES
(80273,0,645,408.021,905.638,163.9,0,18414);

-- Add spell target condition for Aggro Nearby Targets
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=80196;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 80196, 0, 0, 31, 3, 39978, 0, 0, '', 'Aggro Nearby Targets targets Twilight Torturer'),
(13, 1, 80196, 0, 1, 31, 3, 39980, 0, 0, '', 'Aggro Nearby Targets targets Twilight Sadist'),
(13, 1, 80196, 0, 2, 31, 3, 39982, 0, 0, '', 'Aggro Nearby Targets targets Crazed Mage'),
(13, 1, 80196, 0, 3, 31, 3, 39985, 0, 0, '', 'Aggro Nearby Targets targets Mad Prisoner'),
(13, 1, 80196, 0, 4, 31, 3, 39987, 0, 0, '', 'Aggro Nearby Targets targets Evolved Twilight Zealot'),
(13, 1, 80196, 0, 4, 31, 3, 40017, 0, 0, '', 'Aggro Nearby Targets targets Twilight Element Warden');
