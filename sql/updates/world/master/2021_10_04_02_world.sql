-- 
DELETE FROM `trainer_spell` WHERE `TrainerId` IN (122,46,29,133,791,27,62,373,91,136,386,163,580,196,10,407,56,880,424,63,790,880);

-- 
-- Orgrimmar profession trainers
-- 
DELETE FROM `trainer` WHERE `Id`=12;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(12, 0, 'Zug Zug!', 38134);

UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=386;
UPDATE `trainer` SET `Greeting`='Hello! Can I teach you something?', `VerifiedBuild`=38134 WHERE `Id`=46;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=10;
UPDATE `trainer` SET `Greeting`='Hello! Can I teach you something?', `VerifiedBuild`=38134 WHERE `Id`=46;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=29;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=91;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=373;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=91;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `Greeting`='Hello! Can I teach you something?', `VerifiedBuild`=38134 WHERE `Id`=46;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=407;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=163;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=91;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=424;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=136;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=63;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=10;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=136;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=133;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=27;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=196;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=163;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=133;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=790;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=136;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=136;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=163;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=407;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=56;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=196;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=62;
UPDATE `trainer` SET `Greeting`='The herbs of this land can be brewed into powerful potions.', `VerifiedBuild`=38134 WHERE `Id`=122;

DELETE FROM `trainer_spell` WHERE (`TrainerId`=386 AND `SpellId` IN (90266,33389,33392,34092)) OR (`TrainerId`=46 AND `SpellId` IN (33392,33389)) OR (`TrainerId`=10 AND `SpellId` IN (271617,271663,271673,271659,271657,271661,271665)) OR (`TrainerId`=29 AND `SpellId` IN (264541,73622,99544,99543,99542,99541,99540,99539,73266,73270,73246,73268,73267,73243,73274,73250,73234,73281,73249,73241,73240,73279,73247,73239,73230,73226,73222,73225,73232,73228,73227,73223,73620,73496,73494,73478,73621,73497,73495,264533,36523,37818,32178,32179,31252,26928,26927,26926,25280,25278,25490,25287,25284,25283,32801,25617,25612,25610,36524,38175,25615,25613,25498,25321,25318,25317,25305,32807,34959,34955,26880,26876,63743,26874,26872,25621,25620,32809,32808,34961,34960,36526,36525,62941,26911,26908,26907,26903,26902,26885,26883)) OR (`TrainerId`=91 AND `SpellId` IN (265844,74537,84038,74530,74529,265838,2659,3304,2658,3569,3308,3307,10098,16153,10097,70524)) OR (`TrainerId`=27 AND `SpellId` IN (330158,330157,330156,330155,330154,264441,76179,76262,76281,76280,76180,76263,76291,76178,76474,76441,76438,76437,76436,76435,76434,76433,76293,76289,76288,76287,76286,76285,76283,76270,76269,76267,76266,76265,76264,76261,76260,76259,76258,76182,76181,330143,330142,330141,330140,330134,9983,3320,3319,3294,2739,2738,264435,8880,7408,3326,3324,3323,3293,3116,2666,2665,2661,2737,2662,9987,9986,9985,3491,3337,3333,3296,19667,19666,7817,6517,8768,3331,3328,3292,3117,2675,2674,2672,2670,2668,2742,2741,2740,2664,280671,9916,9993,15972,9918,19668,3508,3506,3502,9920,9921,9935,9926,9931,9928,7223,3501,16663,16647,16646,16730,16658,16657,16649,16641,16640,9968,9961,9959,16969,16644,16643,16642,16662,16653,16652,16971,10001,19669,16639)) OR (`TrainerId`=373 AND `SpellId` IN (158763,110394,89727,89725,89723,89726,89724,89129,80836)) OR (`TrainerId`=407 AND `SpellId` IN (12760,12718,12716,12717,8895,12715,12902,12905,12903,12899,12897,12895,12907,12759,12906,12908,12758,12754,12755,84413,95705,95707,84412,264484,95703,94748,84408,81720,84431,84415,84430,84406,84429,84421,81725,84428,84420,81724,81716,84411,84403,81715,84418,84410,81722,81714,84417,84409,84432,84416,264478,7430,3931,3929,3977,3925,3923,3922,3979,3958,15255,12603,12599,3962,3961,12595,12594,12591,12589,12590,12586,12585,3967,3965,3963,12615,3939,3956,9271,8334,6458,3955,3953,3950,3949,3946,3945,3942,3941,3978,3938,3937,3936,3934,3932,3973,12584,39895,12617,63750,12622,12619,12618,19788,23070,19791,19790,19825,19795,19794,23071,19792)) OR (`TrainerId`=163 AND `SpellId` IN (330241,330240,330239,330238,330237,264623,134585,99537,94743,75250,75264,75249,75247,74964,75248,75268,75260,75267,75263,75266,75262,75259,75261,75258,75265,75255,75292,75296,75290,75294,75269,75291,75295,75270,75297,75293,75141,75142,75145,75144,75146,75251,75252,75253,75254,75256,75257,330226,330225,330224,330223,330222,264617,3841,2394,2393,2392,2386,3840,2385,3914,8776,8465,7624,7623,3755,12046,12045,2402,2964,2396,3842,2397,2395,3852,3839,3859,8760,8758,8467,6690,3757,3813,6521,3845,63742,3855,3866,3850,3848,2406,2401,2399,3843,12071,12055,12052,3861,3865,8762,8764,3871,8791,8804,8799,8774,8772,8770,8766,12070,12069,12067,12065,12061,12053,12049,12050,12048,8489,8483,18453,18451,18442,18437,18424,18423,18411,18407,18403,12082,12076,18446,18444,18441,18438,18421,18420,18417,18416,18415,18402,18401,12092,12088,12079,12077,12074,12073,12072,18414,18413,18410,18409,18406,18450,18449)) OR (`TrainerId`=424 AND `SpellId` IN (2373,265820)) OR (`TrainerId`=136 AND `SpellId` IN (264639,88015,88006,264633,6412,6415,93741,6499,2544,2541,2539,37836,3399,6500,2546,3400,18238,4094,21175,46684,46688,18244,18243,18240)) OR (`TrainerId`=63 AND `SpellId` IN (264501,86654,89373,86653,89372,86652,89371,86643,86403,89370,86642,86402,89369,86649,86641,86609,86401,85785,89368,86648,86640,86616,86615,86375,86005,86004,264495,50598,50605,50612,52739,52843,48248,53462,58484,58472,92026,59478,59475,48247,58473,58485,57707,57706,57704,57703,58565,59480,59489,60336,59387,58476,58486,50599,50606,50614,59486,59484,57710,57709,57708,59491,59487,58478,58487,50600,50607,50616,59490,57712,57711,50609,50618,58480,58488,50601,50608,50617,59502,59494,59493)) OR (`TrainerId`=133 AND `SpellId` IN (265826,265820)) OR (`TrainerId`=196 AND `SpellId` IN (265862,265856)) OR (`TrainerId`=790 AND `SpellId` IN (264501,86654,89373,86653,89372,86652,89371,86643,86403,89370,86642,86402,89369,86649,86641,86609,86401,85785,89368,86648,86640,86616,86615,86375,86005,86004,92026,59478,59475,48247,58473,58485,57707,57706,57704,57703,58565,59480,59489,60336,59387,58476,58486,50599,50606,50614,59486,59484,57710,57709,57708,59491,59487,58478,58487,50600,50607,50616,59490,57712,57711,50609,50618,58480,58488,50601,50608,50617,59502,59494,59493,264495,50598,50605,50612,52739,52843,48248,53462,58484,58472,223940)) OR (`TrainerId`=56 AND `SpellId` IN (330200,330199,330198,330197,330196,264584,163218,163216,99536,99535,84950,78436,78427,78432,78423,78398,78437,78405,78428,78396,78380,78419,78410,78433,78424,78415,78399,78438,78406,78420,78388,78411,78379,78416,78439,78407,330185,330184,330183,330181,330180,264578,226106,226107,226105,9065,3759,2162,2161,3756,2160,3816,3753,2153,226120,226116,226125,226119,226112,226117,226111,226121,226114,226108,226118,226113,226123,226122,226110,226124,226109,226115,20649,20648,9145,9074,9068,7135,3780,3760,3818,3770,3768,2166,3764,2168,3766,2167,2165,3817,3761,2159,3763,226126,226129,226134,226128,226127,226137,226132,226130,226131,226135,226133,226136,20650,9206,9201,9198,9196,7156,7151,7147,6661,10518,10511,10507,10499,10487,10482,3776,3774,24654,36076,36075,10650,24655,10647,36074,10630,10632,22331,19103,19102,19098,19092,19091,19083,19082,19072,19071,19065,19055,19052,10558,10556,10552,10548,19058,19047)) OR (`TrainerId`=62 AND `SpellId` IN (264466,217645,104698,95471,74234,74202,74225,74193,74232,74200,74239,74223,74207,74191,74238,74230,74214,74198,74237,74229,74213,74197,74189,74236,74220,74212,74132,74235,74211,74195,74226,74201,74240,74192,74231,74199,264457,7426,7748,7457,7771,7420,14807,14293,13538,13529,13503,13501,13485,13421,7863,13626,13622,13607,13378,7779,7857,7788,7745,13646,13890,13887,13858,13836,13822,13815,13746,13700,13695,13693,13663,13661,13648,13644,13642,13640,13637,13631,13635,14810,14809,13659,63746,217637,13939,13937,13935,13917,13905,17181,17180,13948,13943,13941,20023,20013,20028,20016,20012,20008)) OR (`TrainerId`=122 AND `SpellId` IN (264244,96252,96254,96253,80477,80478,93935,94162,80726,80725,80508,80251,80250,80248,80247,80246,80245,80244,80243,80237,78866,80723,80721,80720,80719,80498,80497,80496,80493,80494,80495,80492,80491,80490,80488,80487,80486,80484,80482,80269,80481,80480,80479,264212,2331,2334,3170,2337,2332,7934,63732,7845,7841,7836,7837,7179,3447,3177,3176,3173,3171,3449,22808,7181,12609,11457,11448,11451,11450,11449,3452,3448,3450,114786,17551,17573,17572,17557,17556,17555,17553,17552,11478,11467,11465,11461,11460,15833));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(386, 90266, 50000000, 0, 0, 34090, 0, 0, 40, 38134), -- MoneyCost recalculated
(386, 33389, 10000, 0, 0, 0, 0, 0, 10, 38134), -- MoneyCost recalculated
(386, 33392, 500000, 0, 0, 33388, 0, 0, 20, 38134), -- MoneyCost recalculated
(386, 34092, 2500000, 0, 0, 33391, 0, 0, 30, 38134), -- MoneyCost recalculated
(46, 33392, 500000, 0, 0, 33388, 0, 0, 20, 38134), -- MoneyCost recalculated
(46, 33389, 10000, 0, 0, 0, 0, 0, 10, 38134), -- MoneyCost recalculated
(10, 271617, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(10, 271663, 10, 356, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(10, 271673, 10, 356, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(10, 271659, 10, 356, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(10, 271657, 10, 356, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(10, 271661, 10, 356, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(10, 271665, 10, 356, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(29, 264541, 10, 755, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(29, 73622, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 99544, 300, 2521, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 99543, 300, 2521, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 99542, 300, 2521, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 99541, 250, 2521, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 99540, 250, 2521, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 99539, 250, 2521, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73266, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73270, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73246, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73268, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73267, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73243, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73274, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73250, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73234, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73281, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73249, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73241, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73240, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73279, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73247, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73239, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73230, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73226, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73222, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73225, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73232, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73228, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73227, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73223, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73620, 30, 2521, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73496, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73494, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73478, 200, 2521, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73621, 150, 2521, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73497, 30, 2521, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 73495, 10, 2521, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 264533, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(29, 36523, 350, 2524, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 37818, 275, 2524, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 32178, 75, 2524, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 32179, 75, 2524, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 31252, 75, 755, 20, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(29, 26928, 115, 2524, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26927, 200, 2524, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26926, 15, 2524, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25280, 200, 2524, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25278, 200, 2524, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25490, 200, 2524, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25287, 300, 2524, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25284, 250, 2524, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25283, 115, 2524, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 32801, 200, 2524, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25617, 6500, 2524, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25612, 2500, 2524, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25610, 2000, 2524, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 36524, 1250, 2524, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 38175, 400, 2524, 80, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25615, 6500, 2524, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25613, 3500, 2524, 135, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25498, 1500, 2524, 110, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25321, 2000, 2524, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25318, 1000, 2524, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25317, 400, 2524, 80, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25305, 650, 2524, 90, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 32807, 1500, 2524, 110, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 34959, 36000, 2524, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 34955, 18000, 2524, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26880, 77500, 2524, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26876, 65000, 2524, 220, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 63743, 36000, 2524, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26874, 46000, 2524, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26872, 36000, 2524, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25621, 18000, 2524, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 25620, 13000, 2524, 170, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 32809, 77500, 2524, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 32808, 15500, 2524, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 34961, 560000, 2524, 290, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 34960, 460000, 2524, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 36526, 310000, 2524, 265, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 36525, 90000, 2524, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 62941, 660000, 2524, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26911, 560000, 2524, 290, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26908, 460000, 2524, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26907, 460000, 2524, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26903, 410000, 2524, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26902, 260000, 2524, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26885, 130000, 2524, 240, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(29, 26883, 77500, 2524, 235, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 265844, 10, 186, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(91, 74537, 200, 2569, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 84038, 10, 2569, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 74530, 100, 2569, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 74529, 350, 2569, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 265838, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(91, 2659, 200, 2572, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 3304, 200, 2572, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 2658, 275, 2572, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 3569, 2500, 2572, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 3308, 1750, 2572, 115, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 3307, 1000, 2572, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 10098, 10500, 2572, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 16153, 36000, 2572, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 10097, 6500, 2572, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(91, 70524, 180000, 2572, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330158, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330157, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330156, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330155, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330154, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 264441, 10, 164, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(27, 76179, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76262, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76281, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76280, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76180, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76263, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76291, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76178, 10, 2474, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76474, 75, 2474, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76441, 150, 2474, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76438, 100, 2474, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76437, 115, 2474, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76436, 115, 2474, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76435, 115, 2474, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76434, 75, 2474, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76433, 30, 2474, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76293, 75, 2474, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76289, 200, 2474, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76288, 150, 2474, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76287, 115, 2474, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76286, 115, 2474, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76285, 75, 2474, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76283, 30, 2474, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76270, 200, 2474, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76269, 200, 2474, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76267, 150, 2474, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76266, 115, 2474, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76265, 75, 2474, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76264, 30, 2474, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76261, 200, 2474, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76260, 150, 2474, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76259, 150, 2474, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76258, 115, 2474, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76182, 75, 2474, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 76181, 30, 2474, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330143, 10, 2477, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330142, 10, 2477, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330141, 10, 2477, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330140, 10, 2477, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 330134, 10, 2477, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9983, 115, 2477, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3320, 100, 2477, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3319, 75, 2477, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3294, 300, 2477, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2739, 100, 2477, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2738, 75, 2477, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 264435, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(27, 8880, 115, 2477, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 7408, 275, 2477, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3326, 350, 2477, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3324, 175, 2477, 45, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3323, 150, 2477, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3293, 130, 2477, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3116, 275, 2477, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2666, 300, 2477, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2665, 275, 2477, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2661, 130, 2477, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2737, 50, 2477, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2662, 10, 2477, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9987, 3500, 2477, 135, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9986, 3000, 2477, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9985, 2500, 2477, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3491, 1250, 2477, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3337, 2500, 2477, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3333, 3500, 2477, 135, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3296, 3000, 2477, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 19667, 6500, 2477, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 19666, 1000, 2477, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 7817, 775, 2477, 95, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 6517, 1500, 2477, 110, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 8768, 6500, 2477, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3331, 3000, 2477, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3328, 1500, 2477, 110, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3292, 775, 2477, 95, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3117, 2500, 2477, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2675, 5250, 2477, 145, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2674, 2500, 2477, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2672, 2000, 2477, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2670, 1250, 2477, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2668, 1250, 2477, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2742, 2000, 2477, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2741, 1750, 2477, 115, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2740, 1500, 2477, 110, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 2664, 650, 2477, 90, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 280671, 7750, 2477, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9916, 36000, 2477, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9993, 46000, 2477, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 15972, 18000, 2477, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9918, 36000, 2477, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 19668, 36000, 2477, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3508, 18000, 2477, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3506, 7750, 2477, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3502, 13000, 2477, 170, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9920, 36000, 2477, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9921, 36000, 2477, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9935, 52500, 2477, 215, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9926, 41000, 2477, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9931, 46000, 2477, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9928, 41000, 2477, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 7223, 21000, 2477, 185, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 3501, 10500, 2477, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16663, 660000, 2477, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16647, 310000, 2477, 265, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16646, 310000, 2477, 265, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16730, 660000, 2477, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16658, 610000, 2477, 295, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16657, 610000, 2477, 295, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16649, 360000, 2477, 270, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16641, 180000, 2477, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16640, 180000, 2477, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9968, 105000, 2477, 235, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9961, 90000, 2477, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 9959, 90000, 2477, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16969, 410000, 2477, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16644, 210000, 2477, 255, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16643, 180000, 2477, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16642, 180000, 2477, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16662, 660000, 2477, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16653, 460000, 2477, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16652, 460000, 2477, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16971, 460000, 2477, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 10001, 90000, 2477, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 19669, 410000, 2477, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(27, 16639, 180000, 2477, 250, 0, 0, 0, 0, 38134); -- MoneyCost recalculated

INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(373, 158763, 10, 0, 0, 110393, 0, 0, 5, 38134), -- MoneyCost recalculated
(373, 110394, 10, 0, 0, 89722, 0, 0, 5, 38134), -- MoneyCost recalculated
(373, 89727, 10, 0, 0, 89721, 0, 0, 5, 38134), -- MoneyCost recalculated
(373, 89725, 10, 0, 0, 89719, 0, 0, 5, 38134), -- MoneyCost recalculated
(373, 89723, 10, 0, 0, 88961, 0, 0, 5, 38134), -- MoneyCost recalculated
(373, 89726, 10, 0, 0, 89720, 0, 0, 5, 38134), -- MoneyCost recalculated
(373, 89724, 10, 0, 0, 89718, 0, 0, 5, 38134), -- MoneyCost recalculated
(373, 89129, 10, 0, 0, 78670, 0, 0, 5, 38134), -- MoneyCost recalculated
(373, 80836, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(407, 12760, 41000, 2506, 205, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12718, 41000, 2506, 205, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12716, 41000, 2506, 205, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12717, 41000, 2506, 205, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 8895, 77500, 2506, 225, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12715, 41000, 2506, 205, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12902, 46000, 2506, 210, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12905, 46000, 2506, 210, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12903, 52500, 2506, 215, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12899, 41000, 2506, 205, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12897, 52500, 2506, 215, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12895, 41000, 2506, 205, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12907, 105000, 2506, 235, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12759, 130000, 2506, 240, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12906, 90000, 2506, 230, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12908, 130000, 2506, 240, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12758, 155000, 2506, 245, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12754, 105000, 2506, 235, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12755, 90000, 2506, 230, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84413, 100, 2503, 25, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 95705, 200, 2503, 50, 20219, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 95707, 200, 2503, 50, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84412, 100, 2503, 25, 20222, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 264484, 10, 202, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(407, 95703, 10, 2503, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 94748, 10, 2503, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84408, 10, 2503, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 81720, 350, 2503, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84431, 350, 2503, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84415, 100, 2503, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84430, 250, 2503, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84406, 10, 2503, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84429, 225, 2503, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84421, 150, 2503, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 81725, 350, 2503, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84428, 275, 2503, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84420, 150, 2503, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 81724, 350, 2503, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 81716, 350, 2503, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84411, 50, 2503, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84403, 10, 2503, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 81715, 350, 2503, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84418, 100, 2503, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84410, 10, 2503, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 81722, 350, 2503, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 81714, 350, 2503, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84417, 175, 2503, 45, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84409, 15, 2503, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84432, 350, 2503, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 84416, 100, 2503, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 264478, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(407, 7430, 200, 2506, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3931, 275, 2506, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3929, 275, 2506, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3977, 250, 2506, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3925, 200, 2506, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3923, 115, 2506, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3922, 115, 2506, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3979, 18000, 2506, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3958, 9000, 2506, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 15255, 36000, 2506, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12603, 52500, 2506, 215, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12599, 52500, 2506, 215, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3962, 15500, 2506, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3961, 13000, 2506, 170, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12595, 41000, 2506, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12594, 41000, 2506, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12591, 36000, 2506, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12589, 31000, 2506, 195, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12590, 15500, 2506, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12586, 15500, 2506, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12585, 15500, 2506, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3967, 26000, 2506, 190, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3965, 21000, 2506, 185, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3963, 15500, 2506, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12615, 77500, 2506, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3939, 2000, 2506, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3956, 6500, 2506, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 9271, 6500, 2506, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 8334, 1000, 2506, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 6458, 3500, 2506, 135, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3955, 6500, 2506, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3953, 5250, 2506, 145, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3950, 4000, 2506, 140, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3949, 3000, 2506, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3946, 2500, 2506, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3945, 2500, 2506, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3942, 2500, 2506, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3941, 2000, 2506, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3978, 1500, 2506, 110, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3938, 1250, 2506, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3937, 1250, 2506, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3936, 1250, 2506, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3934, 1000, 2506, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3932, 525, 2506, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 3973, 650, 2506, 90, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12584, 6500, 2506, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 39895, 410000, 2506, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12617, 90000, 2506, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 63750, 180000, 2506, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12622, 155000, 2506, 245, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12619, 105000, 2506, 235, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 12618, 90000, 2506, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 19788, 180000, 2506, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 23070, 180000, 2506, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 19791, 260000, 2506, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 19790, 260000, 2506, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 19825, 560000, 2506, 290, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 19795, 410000, 2506, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 19794, 360000, 2506, 270, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 23071, 260000, 2506, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(407, 19792, 260000, 2506, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(163, 330241, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 330240, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 330239, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 330238, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 330237, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 264623, 10, 197, 1, 0, 0, 0, 5, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 134585, 275, 2537, 65, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 99537, 150, 2537, 40, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 94743, 350, 2537, 75, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75250, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75264, 115, 2537, 30, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75249, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75247, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 74964, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75248, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75268, 150, 2537, 40, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75260, 100, 2537, 25, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75267, 130, 2537, 35, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75263, 115, 2537, 30, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75266, 130, 2537, 35, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75262, 115, 2537, 30, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75259, 75, 2537, 20, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75261, 100, 2537, 25, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75258, 75, 2537, 20, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75265, 115, 2537, 30, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75255, 30, 2537, 10, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75292, 250, 2537, 60, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75296, 300, 2537, 70, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75290, 200, 2537, 50, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75294, 275, 2537, 65, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75269, 250, 2537, 60, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75291, 225, 2537, 55, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75295, 275, 2537, 65, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75270, 200, 2537, 50, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75297, 300, 2537, 70, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75293, 250, 2537, 60, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75141, 275, 2537, 65, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75142, 225, 2537, 55, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75145, 250, 2537, 60, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75144, 200, 2537, 50, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75146, 200, 2537, 50, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75251, 15, 2537, 5, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75252, 15, 2537, 5, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75253, 30, 2537, 10, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75254, 30, 2537, 10, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75256, 50, 2537, 15, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 75257, 50, 2537, 15, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 330226, 10, 2540, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 330225, 10, 2540, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 330224, 10, 2540, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 330223, 10, 2540, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 330222, 10, 2540, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 264617, 10, 0, 0, 0, 0, 0, 5, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3841, 250, 2540, 60, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2394, 150, 2540, 40, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2393, 10, 2540, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2392, 150, 2540, 40, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2386, 275, 2540, 65, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3840, 130, 2540, 35, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2385, 30, 2540, 10, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3914, 115, 2540, 30, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8776, 50, 2540, 15, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8465, 150, 2540, 40, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 7624, 115, 2540, 30, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 7623, 115, 2540, 30, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3755, 175, 2540, 45, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12046, 350, 2540, 75, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12045, 75, 2540, 20, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2402, 350, 2540, 75, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2964, 350, 2540, 75, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2396, 300, 2540, 70, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3842, 300, 2540, 70, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2397, 250, 2540, 60, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2395, 300, 2540, 70, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3852, 3000, 2540, 130, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3839, 2500, 2540, 125, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3859, 6500, 2540, 150, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8760, 5250, 2540, 145, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8758, 4000, 2540, 140, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8467, 1500, 2540, 110, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 6690, 3500, 2540, 135, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3757, 400, 2540, 80, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3813, 6500, 2540, 150, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 6521, 650, 2540, 90, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3845, 400, 2540, 80, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 63742, 2500, 2540, 125, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3855, 2500, 2540, 125, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3866, 1500, 2540, 110, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3850, 1500, 2540, 110, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3848, 1500, 2540, 110, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2406, 1000, 2540, 100, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2401, 775, 2540, 95, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 2399, 525, 2540, 85, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3843, 525, 2540, 85, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12071, 77500, 2540, 225, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12055, 52500, 2540, 215, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12052, 46000, 2540, 210, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3861, 21000, 2540, 185, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3865, 15500, 2540, 175, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8762, 9000, 2540, 160, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8764, 13000, 2540, 170, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 3871, 13000, 2540, 170, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8791, 21000, 2540, 185, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8804, 46000, 2540, 210, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8799, 31000, 2540, 195, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8774, 18000, 2540, 180, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8772, 15500, 2540, 175, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8770, 26000, 2540, 190, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8766, 15500, 2540, 175, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12070, 77500, 2540, 225, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12069, 77500, 2540, 225, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12067, 77500, 2540, 225, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12065, 77500, 2540, 225, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12061, 52500, 2540, 215, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12053, 52500, 2540, 215, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12049, 41000, 2540, 205, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12050, 46000, 2540, 210, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12048, 41000, 2540, 205, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8489, 15500, 2540, 175, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 8483, 9000, 2540, 160, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18453, 660000, 2540, 300, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18451, 660000, 2540, 300, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18442, 560000, 2540, 290, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18437, 510000, 2540, 285, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18424, 460000, 2540, 280, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18423, 460000, 2540, 280, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18411, 310000, 2540, 265, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18407, 260000, 2540, 260, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18403, 210000, 2540, 255, 0, 0, 0, 0, 38134); -- No Faction found! MoneyCost not recalculated!

INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(163, 12082, 130000, 2540, 240, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12076, 105000, 2540, 235, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18446, 660000, 2540, 300, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18444, 610000, 2540, 295, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18441, 560000, 2540, 290, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18438, 510000, 2540, 285, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18421, 410000, 2540, 275, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18420, 410000, 2540, 275, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18417, 410000, 2540, 275, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18416, 410000, 2540, 275, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18415, 360000, 2540, 270, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18402, 210000, 2540, 255, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18401, 180000, 2540, 250, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12092, 180000, 2540, 250, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12088, 155000, 2540, 245, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12079, 105000, 2540, 235, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12077, 105000, 2540, 235, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12074, 90000, 2540, 230, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12073, 90000, 2540, 230, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 12072, 90000, 2540, 230, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18414, 360000, 2540, 270, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18413, 360000, 2540, 270, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18410, 310000, 2540, 265, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18409, 310000, 2540, 265, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18406, 260000, 2540, 260, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18450, 660000, 2540, 300, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(163, 18449, 660000, 2540, 300, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(424, 2373, 200, 182, 50, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(424, 265820, 10, 0, 0, 0, 0, 0, 5, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 264639, 10, 185, 1, 0, 0, 0, 5, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 88015, 10, 2545, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 88006, 10, 2545, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 264633, 10, 0, 0, 0, 0, 0, 5, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 6412, 30, 2548, 10, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 6415, 200, 2548, 50, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 93741, 150, 2548, 40, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 6499, 200, 2548, 50, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 2544, 350, 2548, 75, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 2541, 200, 2548, 50, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 2539, 30, 2548, 10, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 37836, 10, 2548, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 3399, 6500, 2548, 150, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 6500, 2500, 2548, 125, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 2546, 400, 2548, 80, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 3400, 15500, 2548, 175, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 18238, 77500, 2548, 225, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 4094, 15500, 2548, 175, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 21175, 36000, 2548, 200, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 46684, 180000, 2548, 250, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 46688, 180000, 2548, 250, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 18244, 180000, 2548, 250, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 18243, 180000, 2548, 250, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(136, 18240, 130000, 2548, 240, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(63, 264501, 10, 773, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(63, 86654, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 89373, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86653, 275, 2511, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 89372, 30, 2511, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86652, 275, 2511, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 89371, 15, 2511, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86643, 250, 2511, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86403, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 89370, 75, 2511, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86642, 250, 2511, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86402, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 89369, 50, 2511, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86649, 225, 2511, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86641, 250, 2511, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86609, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86401, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 85785, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 89368, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86648, 115, 2511, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86640, 100, 2511, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86616, 100, 2511, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86615, 350, 2511, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86375, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86005, 100, 2511, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 86004, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 264495, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(63, 50598, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50605, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50612, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 52739, 130, 2514, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 52843, 10, 2514, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 48248, 130, 2514, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 53462, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58484, 50, 2514, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58472, 50, 2514, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 92026, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59478, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59475, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 48247, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58473, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58485, 400, 2514, 80, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 57707, 6500, 2514, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 57706, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 57704, 1000, 2514, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 57703, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58565, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59480, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59489, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 60336, 36000, 2514, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59387, 36000, 2514, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58476, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58486, 13000, 2514, 170, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50599, 10500, 2514, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50606, 9000, 2514, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50614, 7750, 2514, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59486, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59484, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 57710, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 57709, 36000, 2514, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 57708, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59491, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59487, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58478, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58487, 65000, 2514, 220, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50600, 52500, 2514, 215, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50607, 46000, 2514, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50616, 41000, 2514, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59490, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 57712, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 57711, 180000, 2514, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50609, 610000, 2514, 295, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50618, 560000, 2514, 290, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58480, 360000, 2514, 270, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 58488, 310000, 2514, 265, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50601, 260000, 2514, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50608, 210000, 2514, 255, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 50617, 180000, 2514, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59502, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59494, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(63, 59493, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(133, 265826, 10, 182, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(133, 265820, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(196, 265862, 10, 393, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(196, 265856, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(790, 264501, 10, 773, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(790, 86654, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 89373, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86653, 275, 2511, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 89372, 30, 2511, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86652, 275, 2511, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 89371, 15, 2511, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86643, 250, 2511, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86403, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 89370, 75, 2511, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86642, 250, 2511, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86402, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 89369, 50, 2511, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86649, 225, 2511, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86641, 250, 2511, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86609, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86401, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 85785, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 89368, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86648, 115, 2511, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86640, 100, 2511, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86616, 100, 2511, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86615, 350, 2511, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86375, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86005, 100, 2511, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 86004, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 92026, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59478, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59475, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 48247, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58473, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58485, 400, 2514, 80, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 57707, 6500, 2514, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 57706, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 57704, 1000, 2514, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 57703, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58565, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59480, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59489, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 60336, 36000, 2514, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59387, 36000, 2514, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58476, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58486, 13000, 2514, 170, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50599, 10500, 2514, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50606, 9000, 2514, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50614, 7750, 2514, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59486, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59484, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 57710, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 57709, 36000, 2514, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 57708, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59491, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59487, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58478, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58487, 65000, 2514, 220, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50600, 52500, 2514, 215, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50607, 46000, 2514, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50616, 41000, 2514, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59490, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 57712, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 57711, 180000, 2514, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50609, 610000, 2514, 295, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50618, 560000, 2514, 290, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58480, 360000, 2514, 270, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58488, 310000, 2514, 265, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50601, 260000, 2514, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50608, 210000, 2514, 255, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50617, 180000, 2514, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59502, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59494, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 59493, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 264495, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(790, 50598, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50605, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 50612, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 52739, 130, 2514, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 52843, 10, 2514, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 48248, 130, 2514, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 53462, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58484, 50, 2514, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 58472, 50, 2514, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(790, 223940, 10, 2508, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330200, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330199, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330198, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330197, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330196, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 264584, 10, 165, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(56, 163218, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 163216, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 99536, 200, 2529, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 99535, 200, 2529, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 84950, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78436, 130, 2529, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78427, 115, 2529, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78432, 130, 2529, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78423, 150, 2529, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78398, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78437, 130, 2529, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78405, 75, 2529, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78428, 115, 2529, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78396, 75, 2529, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78380, 30, 2529, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78419, 100, 2529, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78410, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78433, 130, 2529, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78424, 150, 2529, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78415, 15, 2529, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78399, 50, 2529, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78438, 175, 2529, 45, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78406, 100, 2529, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78420, 115, 2529, 30, 0, 0, 0, 0, 38134); -- MoneyCost recalculated

INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(56, 78388, 30, 2529, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78411, 100, 2529, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78379, 10, 2529, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78416, 15, 2529, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78439, 175, 2529, 45, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 78407, 50, 2529, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330185, 10, 2532, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330184, 10, 2532, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330183, 10, 2532, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330181, 10, 2532, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 330180, 10, 2532, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 264578, 10, 165, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(56, 226106, 300, 2532, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226107, 300, 2532, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226105, 225, 2532, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 9065, 300, 2532, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3759, 350, 2532, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 2162, 250, 2532, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 2161, 225, 2532, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3756, 225, 2532, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 2160, 150, 2532, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3816, 130, 2532, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3753, 100, 2532, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 2153, 50, 2532, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226120, 2500, 2532, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226116, 1250, 2532, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226125, 6500, 2532, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226119, 2000, 2532, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226112, 775, 2532, 95, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226117, 1500, 2532, 110, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226111, 1250, 2532, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226121, 3000, 2532, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226114, 525, 2532, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226108, 525, 2532, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226118, 1750, 2532, 115, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226113, 775, 2532, 95, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226123, 4000, 2532, 140, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226122, 3500, 2532, 135, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226110, 650, 2532, 90, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226124, 6500, 2532, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226109, 650, 2532, 90, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226115, 1000, 2532, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 20649, 6500, 2532, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 20648, 1000, 2532, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 9145, 2500, 2532, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 9074, 2000, 2532, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 9068, 775, 2532, 95, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 7135, 1750, 2532, 115, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3780, 6500, 2532, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3760, 6500, 2532, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3818, 6500, 2532, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3770, 3500, 2532, 135, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3768, 3000, 2532, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 2166, 2000, 2532, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3764, 5250, 2532, 145, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 2168, 1500, 2532, 110, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3766, 2500, 2532, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 2167, 1000, 2532, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 2165, 1000, 2532, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3817, 1000, 2532, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3761, 525, 2532, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 2159, 525, 2532, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3763, 400, 2532, 80, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226126, 1000, 2532, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226129, 10500, 2532, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226134, 26000, 2532, 190, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226128, 10500, 2532, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226127, 9000, 2532, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226137, 26000, 2532, 190, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226132, 21000, 2532, 185, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226130, 10500, 2532, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226131, 18000, 2532, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226135, 26000, 2532, 190, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226133, 21000, 2532, 185, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 226136, 26000, 2532, 190, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 20650, 36000, 2532, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 9206, 31000, 2532, 195, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 9201, 21000, 2532, 185, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 9198, 18000, 2532, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 9196, 15500, 2532, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 7156, 26000, 2532, 190, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 7151, 15500, 2532, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 7147, 1000, 2532, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 6661, 26000, 2532, 190, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10518, 46000, 2532, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10511, 46000, 2532, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10507, 41000, 2532, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10499, 41000, 2532, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10487, 36000, 2532, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10482, 36000, 2532, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3776, 18000, 2532, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 3774, 1000, 2532, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 24654, 660000, 2532, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 36076, 260000, 2532, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 36075, 260000, 2532, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10650, 210000, 2532, 255, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 24655, 460000, 2532, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10647, 180000, 2532, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 36074, 260000, 2532, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10630, 90000, 2532, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10632, 180000, 2532, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 22331, 180000, 2532, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19103, 660000, 2532, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19102, 660000, 2532, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19098, 660000, 2532, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19092, 660000, 2532, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19091, 660000, 2532, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19083, 560000, 2532, 290, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19082, 560000, 2532, 290, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19072, 460000, 2532, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19071, 460000, 2532, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19065, 410000, 2532, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19055, 360000, 2532, 270, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19052, 310000, 2532, 265, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10558, 105000, 2532, 235, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10556, 105000, 2532, 235, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10552, 90000, 2532, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 10548, 90000, 2532, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19058, 180000, 2532, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(56, 19047, 180000, 2532, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 264466, 10, 333, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(62, 217645, 200, 2491, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 104698, 275, 2491, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 95471, 75, 2491, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74234, 200, 2491, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74202, 50, 2491, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74225, 130, 2491, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74193, 10, 2491, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74232, 175, 2491, 45, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74200, 30, 2491, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74239, 250, 2491, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74223, 115, 2491, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74207, 50, 2491, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74191, 10, 2491, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74238, 250, 2491, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74230, 150, 2491, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74214, 100, 2491, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74198, 15, 2491, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74237, 225, 2491, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74229, 150, 2491, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74213, 100, 2491, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74197, 10, 2491, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74189, 10, 2491, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74236, 225, 2491, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74220, 115, 2491, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74212, 75, 2491, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74132, 10, 2491, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74235, 200, 2491, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74211, 75, 2491, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74195, 10, 2491, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74226, 130, 2491, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74201, 30, 2491, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74240, 250, 2491, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74192, 10, 2491, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74231, 175, 2491, 45, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 74199, 15, 2491, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 264457, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(62, 7426, 150, 2494, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 7748, 250, 2494, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 7457, 200, 2494, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 7771, 300, 2494, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 7420, 50, 2494, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 14807, 300, 2494, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 14293, 30, 2494, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13538, 4000, 2494, 140, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13529, 5250, 2494, 145, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13503, 4000, 2494, 140, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13501, 3000, 2494, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13485, 3000, 2494, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13421, 1750, 2494, 115, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 7863, 2500, 2494, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13626, 6500, 2494, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13622, 6500, 2494, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13607, 5250, 2494, 145, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13378, 1250, 2494, 105, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 7779, 400, 2494, 80, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 7857, 2000, 2494, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 7788, 650, 2494, 90, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 7745, 1000, 2494, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13646, 13000, 2494, 170, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13890, 77500, 2494, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13887, 77500, 2494, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13858, 65000, 2494, 220, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13836, 52500, 2494, 215, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13822, 46000, 2494, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13815, 46000, 2494, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13746, 41000, 2494, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13700, 36000, 2494, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13695, 36000, 2494, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13693, 31000, 2494, 195, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13663, 21000, 2494, 185, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13661, 18000, 2494, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13648, 13000, 2494, 170, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13644, 13000, 2494, 170, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13642, 10500, 2494, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13640, 9000, 2494, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13637, 9000, 2494, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13631, 7750, 2494, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13635, 7750, 2494, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 14810, 15500, 2494, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 14809, 7750, 2494, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13659, 18000, 2494, 180, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 63746, 77500, 2494, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 217637, 410000, 2494, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13939, 130000, 2494, 240, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13937, 130000, 2494, 240, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13935, 105000, 2494, 235, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13917, 90000, 2494, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13905, 90000, 2494, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 17181, 180000, 2494, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 17180, 180000, 2494, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13948, 180000, 2494, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13943, 155000, 2494, 245, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 13941, 155000, 2494, 245, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 20023, 610000, 2494, 295, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 20013, 610000, 2494, 295, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 20028, 560000, 2494, 290, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 20016, 460000, 2494, 280, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 20012, 360000, 2494, 270, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(62, 20008, 210000, 2494, 255, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 264244, 10, 171, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(122, 96252, 200, 2482, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 96254, 200, 2482, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 96253, 200, 2482, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80477, 10, 2482, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80478, 10, 2482, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 93935, 10, 2482, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 94162, 200, 2482, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80726, 350, 2482, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80725, 350, 2482, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80508, 200, 2482, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80251, 225, 2482, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80250, 250, 2482, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80248, 275, 2482, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80247, 300, 2482, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80246, 275, 2482, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80245, 350, 2482, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80244, 300, 2482, 70, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80243, 350, 2482, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80237, 350, 2482, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 78866, 130, 2482, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80723, 250, 2482, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80721, 250, 2482, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80720, 225, 2482, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80719, 200, 2482, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80498, 175, 2482, 45, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80497, 175, 2482, 45, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80496, 150, 2482, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80493, 150, 2482, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80494, 130, 2482, 35, 0, 0, 0, 0, 38134); -- MoneyCost recalculated

INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(122, 80495, 130, 2482, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80492, 115, 2482, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80491, 115, 2482, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80490, 100, 2482, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80488, 100, 2482, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80487, 75, 2482, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80486, 75, 2482, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80484, 50, 2482, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80482, 50, 2482, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80269, 30, 2482, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80481, 30, 2482, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80480, 15, 2482, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 80479, 15, 2482, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 264212, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(122, 2331, 100, 2485, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 2334, 200, 2485, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3170, 50, 2485, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 2337, 225, 2485, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 2332, 150, 2485, 40, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 7934, 400, 2485, 80, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 63732, 3500, 2485, 135, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 7845, 4000, 2485, 140, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 7841, 1000, 2485, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 7836, 400, 2485, 80, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 7837, 3000, 2485, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 7179, 650, 2485, 90, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3447, 1500, 2485, 110, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3177, 3000, 2485, 130, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3176, 2500, 2485, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3173, 2000, 2485, 120, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3171, 650, 2485, 90, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3449, 10500, 2485, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 22808, 52500, 2485, 215, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 7181, 7750, 2485, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 12609, 36000, 2485, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11457, 52500, 2485, 215, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11448, 41000, 2485, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11451, 41000, 2485, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11450, 31000, 2485, 195, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11449, 21000, 2485, 185, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3452, 9000, 2485, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3448, 10500, 2485, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 3450, 15500, 2485, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 114786, 660000, 2485, 300, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 17551, 180000, 2485, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 17573, 510000, 2485, 285, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 17572, 510000, 2485, 285, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 17557, 410000, 2485, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 17556, 410000, 2485, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 17555, 360000, 2485, 270, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 17553, 260000, 2485, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 17552, 210000, 2485, 255, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11478, 180000, 2485, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11467, 130000, 2485, 240, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11465, 105000, 2485, 235, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11461, 105000, 2485, 235, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 11460, 90000, 2485, 230, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(122, 15833, 90000, 2485, 230, 0, 0, 0, 0, 38134); -- MoneyCost recalculated


DELETE FROM `creature_trainer` WHERE (`CreatureId`=3355 AND `MenuID`=1012 AND `OptionIndex`=0) OR (`CreatureId`=174164 AND `MenuID`=0 AND `OptionIndex`=0) OR (`CreatureId`=47571 AND `MenuID`=12410 AND `OptionIndex`=0) OR (`CreatureId`=133239 AND `MenuID`=22125 AND `OptionIndex`=0) OR (`CreatureId`=133236 AND `MenuID`=0 AND `OptionIndex`=0) OR (`CreatureId`=133104 AND `MenuID`=22114 AND `OptionIndex`=0) OR (`CreatureId`=133261 AND `MenuID`=22124 AND `OptionIndex`=0) OR (`CreatureId`=44975 AND `MenuID`=12443 AND `OptionIndex`=0) OR (`CreatureId`=3399 AND `MenuID`=4747 AND `OptionIndex`=0) OR (`CreatureId`=44783 AND `MenuID`=4351 AND `OptionIndex`=0) OR (`CreatureId`=42506 AND `MenuID`=11637 AND `OptionIndex`=0) OR (`CreatureId`=11017 AND `MenuID`=4151 AND `OptionIndex`=0) OR (`CreatureId`=3365 AND `MenuID`=4209 AND `OptionIndex`=0) OR (`CreatureId`=3347 AND `MenuID`=4126 AND `OptionIndex`=0);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(3355, 27, 1012, 0),
(174164, 12, 0, 0),
(47571, 373, 12410, 0),
(133239, 163, 22125, 0),
(133236, 91, 0, 0),
(133104, 424, 22114, 0),
(133261, 136, 22124, 0),
(44975, 10, 12443, 0),
(3399, 136, 4747, 0),
(44783, 163, 4351, 0),
(42506, 136, 11637, 0),
(11017, 407, 4151, 0),
(3365, 56, 4209, 0),
(3347, 122, 4126, 0);

UPDATE `creature_trainer` SET `TrainerId`=27 WHERE (`CreatureId`=44781 AND `MenuID`=8521 AND `OptionIndex`=0);

-- 
-- Stormwind profession trainers
-- 
DELETE FROM `trainer` WHERE `Id` IN (880, 33);
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(880, 2, 'Here, let me show you how to bind those wounds....', 38134),
(33, 0, 'Sorry, friend.  I can only train rogues.', 38134);

UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=791;
UPDATE `trainer` SET `VerifiedBuild`=38134 WHERE `Id`=580;
UPDATE `trainer` SET `Greeting`='You must be \"this\" high to enter!', `VerifiedBuild`=38134 WHERE `Id`=148;

DELETE FROM `trainer_spell` WHERE (`TrainerId`=791 AND `SpellId` IN (264501,89373,86653,89372,89244,86652,89371,86643,86403,89370,86642,86402,89369,86649,86641,86609,86401,85785,89368,86648,86640,86616,86615,86375,86005,86004,92026,59478,59475,48247,58473,58485,57707,57706,57704,57703,58565,59480,59489,60336,59387,58476,58486,50599,50606,50614,59486,59484,57710,57709,57708,59491,59487,58478,58487,50600,50607,50616,59490,57712,57711,50609,50618,58480,58488,50601,50608,50617,59502,59494,59493,264495,50598,50605,50612,52739,52843,48248,53462,58484,58472,223941)) OR (`TrainerId`=580 AND `SpellId` IN (10707,125610));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(791, 264501, 10, 773, 1, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(791, 89373, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86653, 275, 2511, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 89372, 30, 2511, 10, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 89244, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86652, 275, 2511, 65, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 89371, 15, 2511, 5, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86643, 250, 2511, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86403, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 89370, 75, 2511, 20, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86642, 250, 2511, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86402, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 89369, 50, 2511, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86649, 225, 2511, 55, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86641, 250, 2511, 60, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86609, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86401, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 85785, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 89368, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86648, 115, 2511, 30, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86640, 100, 2511, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86616, 100, 2511, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86615, 350, 2511, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86375, 200, 2511, 50, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86005, 100, 2511, 25, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 86004, 10, 2511, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 92026, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59478, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59475, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 48247, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58473, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58485, 400, 2514, 80, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 57707, 6500, 2514, 150, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 57706, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 57704, 1000, 2514, 100, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 57703, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58565, 525, 2514, 85, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59480, 2500, 2514, 125, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59489, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 60336, 36000, 2514, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59387, 36000, 2514, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58476, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58486, 13000, 2514, 170, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50599, 10500, 2514, 165, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50606, 9000, 2514, 160, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50614, 7750, 2514, 155, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59486, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59484, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 57710, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 57709, 36000, 2514, 200, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 57708, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59491, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59487, 15500, 2514, 175, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58478, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58487, 65000, 2514, 220, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50600, 52500, 2514, 215, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50607, 46000, 2514, 210, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50616, 41000, 2514, 205, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59490, 77500, 2514, 225, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 57712, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 57711, 180000, 2514, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50609, 610000, 2514, 295, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50618, 560000, 2514, 290, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58480, 360000, 2514, 270, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58488, 310000, 2514, 265, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50601, 260000, 2514, 260, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50608, 210000, 2514, 255, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50617, 180000, 2514, 250, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59502, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59494, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 59493, 410000, 2514, 275, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 264495, 10, 0, 0, 0, 0, 0, 5, 38134), -- MoneyCost recalculated
(791, 50598, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50605, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 50612, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 52739, 130, 2514, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 52843, 10, 2514, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 48248, 130, 2514, 35, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 53462, 350, 2514, 75, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58484, 50, 2514, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 58472, 50, 2514, 15, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(791, 223941, 10, 2508, 1, 0, 0, 0, 0, 38134), -- MoneyCost recalculated
(580, 10707, 500, 0, 0, 119467, 0, 0, 0, 38134), -- MoneyCost recalculated
(580, 125610, 1000, 0, 0, 0, 0, 0, 1, 38134), -- MoneyCost recalculated
(880, 7928, 6500, 2540, 150, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 7929, 18000, 2540, 180, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 3278, 1750, 2540, 115, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 3277, 400, 2540, 80, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 74558, 350, 2537, 75, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 74556, 10, 2537, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 88893, 350, 2537, 75, 74558, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 74557, 100, 2537, 25, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 27033, 115, 2539, 30, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 27032, 10, 2539, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 45546, 50, 2538, 15, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 45545, 10, 2538, 1, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 3276, 150, 2540, 40, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 18630, 560000, 2540, 290, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 10840, 46000, 2540, 210, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 10841, 130000, 2540, 240, 0, 0, 0, 0, 38134), -- No Faction found! MoneyCost not recalculated!
(880, 18629, 260000, 2540, 260, 0, 0, 0, 0, 38134); -- No Faction found! MoneyCost not recalculated!


DELETE FROM `creature_trainer` WHERE (`CreatureId`=5502 AND `MenuID`=643 AND `OptionIndex`=0) OR (`CreatureId`=151287 AND `MenuID`=23967 AND `OptionIndex`=0) OR (`CreatureId`=63596 AND `MenuID`=14991 AND `OptionIndex`=0) OR (`CreatureId`=133369 AND `MenuID`=22177 AND `OptionIndex`=0) OR (`CreatureId`=4753 AND `MenuID`=0 AND `OptionIndex`=0) OR (`CreatureId`=164956 AND `MenuID`=0 AND `OptionIndex`=0) OR (`CreatureId`=133394 AND `MenuID`=22180 AND `OptionIndex`=0) OR (`CreatureId`=56796 AND `MenuID`=657 AND `OptionIndex`=0) OR (`CreatureId`=173819 AND `MenuID`=26430 AND `OptionIndex`=0) OR (`CreatureId`=133396 AND `MenuID`=22169 AND `OptionIndex`=0) OR (`CreatureId`=133322 AND `MenuID`=22176 AND `OptionIndex`=0) OR (`CreatureId`=133326 AND `MenuID`=22173 AND `OptionIndex`=0) OR (`CreatureId`=133411 AND `MenuID`=22124 AND `OptionIndex`=0) OR (`CreatureId`=133363 AND `MenuID`=22171 AND `OptionIndex`=0);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(5502, 133, 643, 0),
(151287, 56, 23967, 0),
(63596, 580, 14991, 0),
(133369, 91, 22177, 0),
(4753, 46, 0, 0),
(164956, 148, 0, 0),
(133394, 62, 22180, 0),
(56796, 880, 657, 0),
(173819, 33, 26430, 0),
(133396, 880, 22169, 0),
(133322, 27, 22176, 0),
(133326, 407, 22173, 0),
(133411, 136, 22124, 0),
(133363, 163, 22171, 0);
