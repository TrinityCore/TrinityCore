-- 
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (73870,99920,128650,129374,129879,129928,133990,138002,141493,141497,142486,143421,144167,144171,151297,151298,151299,153118,157425,197968,198497,199021,199023,199115,199561,201314,214661,216003,218315,218316,220152,220153,221213,222812,223818,223846,224021,224307,224308,224804,226254,229184,233409,233410,233413,233675,233681,233684,234034,234035,234038,234296,237275,238771,238772,238773,238885,238886,238888,238972,239196,239197,239198,239199,239202,239833,240481,240906,240908,240909,240910,240911,240912,240913,241024,241079,241081,241090,241102,241105,241106,241340,241344,241355,241698,241715,241717,241718,242016,242570,242837,244187)) OR (`ID`=2 AND `CreatureID` IN (238885,241102,241355)) OR (`ID`=3 AND `CreatureID` IN (238885,241102,241355)) OR (`ID`=4 AND `CreatureID` IN (238885,241102,241355)) OR (`ID`=5 AND `CreatureID` IN (238885,241102)) OR (`ID`=6 AND `CreatureID` IN (238885,241102)) OR (`ID`=7 AND `CreatureID`=238885) OR (`ID`=8 AND `CreatureID`=238885);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(73870, 1, 29630, 0, 0, 29637, 0, 0, 0, 0, 0, 61265), -- Ockbar the Wanderer
(99920, 1, 128361, 0, 0, 128369, 0, 0, 0, 0, 0, 61265), -- Sevis Brightflame
(128650, 1, 109166, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chopper Redhook
(129374, 1, 160423, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Scrimshaw Enforcer
(129879, 1, 164348, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Irontide Cleaver
(129928, 1, 0, 0, 0, 0, 0, 0, 108713, 0, 0, 61265), -- Irontide Powdershot
(133990, 1, 155764, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Scrimshaw Gutter
(138002, 1, 155764, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Scrimshaw Gutter
(141493, 1, 155757, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Taelia
(141497, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Jaina Proudmoore
(142486, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Jaina Proudmoore
(143421, 1, 155771, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Irontide Marauder
(144167, 1, 155690, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Kul Tiran Vanguard
(144171, 1, 155757, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Taelia
(151297, 1, 816, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Opportunistic Bandit
(151298, 1, 647, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Avarice
(151299, 1, 0, 0, 0, 0, 0, 0, 159130, 0, 0, 61265), -- Opportunistic Bandit
(153118, 1, 207793, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Lost Mind
(157425, 1, 207793, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Dark Delusion
(197968, 1, 180669, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Xagnus Everbane
(198497, 1, 163530, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Nathenaseth
(199021, 1, 0, 0, 0, 0, 0, 0, 45937, 0, 0, 61265), -- Patch
(199023, 1, 0, 0, 0, 0, 0, 0, 47523, 0, 0, 61265), -- Ticker
(199115, 1, 118560, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Gothal
(199561, 1, 35781, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Archmage Aethas Sunreaver
(201314, 1, 71739, 0, 0, 71741, 0, 0, 0, 0, 0, 61265), -- Warpweaver Zumzi
(214661, 1, 0, 0, 0, 0, 0, 0, 198335, 0, 0, 61265), -- Goldie Baronbottom
(216003, 1, 126937, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Distracted Technician
(218315, 1, 0, 0, 0, 0, 0, 0, 193022, 0, 0, 61265), -- Kaheti Sentry
(218316, 1, 214503, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Kaheti Vanguard
(220152, 1, 221770, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Sycophant
(220153, 1, 221769, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Threadmancer
(221213, 1, 115802, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Eroded Titan Construct
(222812, 1, 214501, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Kaheti Silkguard
(223818, 1, 192819, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Shadowblade Abductor
(223846, 1, 214477, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Wounded Emergency Militia
(224021, 1, 214477, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Emergency Militia
(224307, 1, 214501, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Corpse Relocator
(224308, 1, 221768, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Kib'kur
(224804, 1, 214477, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Emergency Militia
(226254, 1, 214501, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Corpse Relocator
(229184, 1, 221772, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Aspirant Kiipka
(233409, 1, 214503, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chitin Knight
(233410, 1, 0, 0, 0, 0, 0, 0, 212399, 0, 0, 61265), -- Sureki Silkbow
(233413, 1, 214501, 0, 0, 214501, 0, 0, 0, 0, 0, 61265), -- Sureki Darkblade
(233675, 1, 0, 0, 0, 0, 0, 0, 151781, 0, 0, 61265), -- Alleria Windrunner
(233681, 1, 125668, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Magister Umbric
(233684, 1, 47104, 0, 0, 47104, 0, 0, 0, 0, 0, 61265), -- Overlord Mathias Shaw
(234034, 1, 168268, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Thrall
(234035, 1, 59474, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Inquisitor Gnshal
(234038, 1, 10612, 0, 0, 10612, 0, 0, 0, 0, 0, 61265), -- Rexxar
(234296, 1, 238624, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Vinnie Sweets
(237275, 1, 38129, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Odo the Blindwatcher
(238771, 1, 221768, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Acolyte
(238772, 1, 239099, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Marauder
(238773, 1, 224511, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Eradicator
(238885, 1, 214436, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arathi Recruit
(238885, 2, 232795, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arathi Recruit
(238885, 3, 232798, 0, 0, 0, 0, 0, 232796, 0, 0, 61265), -- Arathi Recruit
(238885, 4, 232794, 0, 0, 0, 0, 0, 232796, 0, 0, 61265), -- Arathi Recruit
(238885, 5, 232797, 0, 0, 0, 0, 0, 232796, 0, 0, 61265), -- Arathi Recruit
(238885, 6, 214436, 0, 0, 0, 0, 0, 232796, 0, 0, 61265), -- Arathi Recruit
(238885, 7, 232794, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arathi Recruit
(238885, 8, 232798, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arathi Recruit
(238886, 1, 232799, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arathi Aeroknight
(238888, 1, 232798, 0, 0, 232793, 0, 0, 0, 0, 0, 61265), -- Arathi Knight
(238972, 1, 214502, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Swarmherder
(239196, 1, 239628, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Drone
(239197, 1, 221768, 0, 0, 0, 0, 0, 224487, 0, 0, 61265), -- Sureki Needler
(239198, 1, 224495, 0, 0, 224495, 0, 0, 0, 0, 0, 61265), -- Sureki Sentryblade
(239199, 1, 214503, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Overseer
(239202, 1, 221768, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Acolyte
(239833, 1, 220492, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Elaena Emberlanz
(240481, 1, 222466, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Consultant Wrexxle
(240906, 1, 232795, 0, 0, 232795, 0, 0, 232796, 0, 0, 61265), -- Arathi Sentry
(240908, 1, 232801, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arathi Crusader
(240909, 1, 214465, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arathi Volunteer
(240910, 1, 232795, 0, 0, 232792, 0, 0, 0, 0, 0, 61265), -- Arathi Priest
(240911, 1, 232797, 0, 0, 194330, 0, 0, 0, 0, 0, 61265), -- Arathi Adherent
(240912, 1, 232800, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arathi Cleric
(240913, 1, 232799, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arathi Knight
(241024, 1, 107955, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Big Keech
(241079, 1, 232799, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Orren Masyn
(241081, 1, 232794, 0, 0, 232793, 0, 0, 0, 0, 0, 61265), -- Aemyra Acton
(241090, 1, 232795, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Claryssa Paller
(241102, 1, 223495, 0, 0, 225346, 0, 0, 0, 0, 0, 61265), -- Machine Ordinant
(241102, 2, 226684, 0, 0, 225346, 0, 0, 0, 0, 0, 61265), -- Machine Ordinant
(241102, 3, 214494, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Machine Ordinant
(241102, 4, 214477, 0, 0, 225346, 0, 0, 0, 0, 0, 61265), -- Machine Ordinant
(241102, 5, 226685, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Machine Ordinant
(241102, 6, 216842, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Machine Ordinant
(241105, 1, 211256, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stormrider Reinforcement
(241106, 1, 211255, 0, 0, 217173, 0, 0, 0, 0, 0, 61265), -- Stormrider Gurnot
(241340, 1, 232799, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Meradyth Lacke
(241344, 1, 232795, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Auralia Steelstrike
(241355, 1, 224847, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Gundargaz Workhand
(241355, 2, 224825, 0, 0, 224874, 0, 0, 0, 0, 0, 61265), -- Gundargaz Workhand
(241355, 3, 224820, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Gundargaz Workhand
(241355, 4, 224821, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Gundargaz Workhand
(241698, 1, 1905, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Hogger
(241715, 1, 125158, 0, 0, 94500, 0, 0, 0, 0, 0, 61265), -- Vengeful Footman
(241717, 1, 0, 0, 0, 0, 0, 0, 128828, 0, 0, 61265), -- Vengeful Heartpiercer
(241718, 1, 124381, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Vengeful Voidspeaker
(242016, 1, 0, 0, 0, 198384, 0, 0, 0, 0, 0, 61265), -- Sacred Alchemist
(242570, 1, 236884, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Haymar the Devout
(242837, 1, 224511, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Sureki Eradicator
(244187, 1, 55064, 0, 0, 70216, 0, 0, 0, 0, 0, 61265); -- K'thir Mindcarver

UPDATE `creature_equip_template` SET `VerifiedBuild`=61265 WHERE (`ID`=1 AND `CreatureID` IN (68,94,116,331,338,348,382,415,423,426,430,445,446,474,518,615,648,649,650,651,652,656,711,712,732,790,791,793,812,859,900,903,932,933,934,935,936,956,957,1064,1070,1141,1146,1215,1218,1257,1275,1297,1298,1301,1308,1311,1312,1313,1316,1366,1367,1382,1387,1404,1415,1431,1472,1642,1678,1680,1976,2464,2465,2485,2497,2708,2857,3087,3088,3090,3144,3149,3216,3296,3310,3312,3313,3314,3323,3327,3328,3329,3331,3342,3345,3347,3348,3367,3368,3370,3412,3413,3624,3887,4047,4078,4311,4463,4959,4974,5188,5384,5386,5413,5493,5494,5498,5499,5500,5503,5506,5510,5511,5512,5516,5517,5566,5606,5607,5608,5609,5610,5611,5613,5614,5694,5814,5817,6367,6466,6566,6579,6929,6966,7009,7010,7485,7798,7853,8659,8962,8965,9564,10782,11017,11046,11066,11068,12136,12137,12789,12790,12791,12793,12794,12795,12796,12797,12798,14270,14271,14375,14376,14377,14392,14438,14497,14498,15116,16094,16096,17094,17264,17309,20407,23128,23635,24924,24926,24929,24930,24931,25080,25081,26537,29725,30713,31720,31723,31724,31725,31726,31727,32725,34723,34765,35068,37072,40891,41466,41731,41795,42288,42421,42506,43034,43080,43081,43094,43185,43197,43341,43369,44158,44236,44583,44723,44725,44743,44779,44851,44871,44872,44876,44877,44878,44919,45015,45226,45230,45244,45306,45337,45339,45347,45545,45563,45565,45566,45814,45822,46078,46080,46082,46140,46142,46180,46181,46357,46358,46359,46555,46556,46708,46709,46716,46741,46742,47233,47246,47247,47248,47253,47320,47321,47324,47325,47335,47336,47571,47663,48229,48445,49622,49701,49737,49750,50304,50323,50477,50488,51346,51348,51921,52031,52032,52423,53701,54216,54217,54218,55684,57801,58155,58193,58195,62194,62195,65153,69334,69977,69978,71100,72559,73151,74146,74148,74228,74373,74374,78135,80787,85026,88067,88696,88697,88701,88702,88703,89830,90417,90418,90431,90463,92183,92457,92489,92643,93127,93536,95844,96420,96441,96473,96494,96499,96500,96501,96502,96650,96652,96653,96655,96770,96771,96772,96778,96779,96780,96785,96786,96791,96792,96793,96794,96795,96802,96809,96888,96930,96931,96944,96945,96946,96947,96948,96949,96950,96951,96952,96953,96954,96955,96956,96957,96958,96959,96960,97012,97014,97034,97141,97213,97491,97500,97526,97529,97597,97598,97599,97601,97603,97604,97792,98157,98723,98724,99541,101397,101787,101788,101789,101790,102724,102726,102905,102906,102907,102909,104091,105339,106262,106263,106655,106930,107772,108628,109387,109390,109554,110019,111243,111246,112079,112720,113034,113211,113539,113551,113779,113780,113781,113782,113783,113784,113785,113873,113924,113927,114066,114067,116175,119226,119272,119486,119487,120168,120170,120174,120412,120413,120416,120417,120419,120420,120422,120423,120599,120687,120803,120899,120900,120949,120951,121017,121235,121239,121252,122072,122229,122452,122454,122689,122699,122872,122873,122919,123169,123243,123244,123264,123399,123641,124695,124805,125004,127031,128087,128286,128630,128651,128967,128969,129295,129308,129309,129366,129367,129369,129370,129371,129375,129376,129604,129627,129734,129875,129909,129981,129998,130039,130088,130094,130098,130230,130242,130368,130411,130491,130531,130790,130958,130983,131006,131216,131290,131477,131480,131481,131482,131483,131484,131494,131503,131506,131542,131610,131840,132639,132640,132641,132715,132968,132978,133127,133168,133185,133186,133206,133208,133218,133228,133271,133282,133327,133399,133433,133441,133536,133735,134346,134623,134631,134721,134722,134723,134725,134729,134838,134847,135000,135107,135213,135245,135258,135263,135432,135437,135603,135604,135605,135606,135612,135614,135618,135658,135668,135671,135675,135677,135678,135681,135690,135691,135792,135799,135889,136052,136061,136096,136102,136110,136158,136175,136343,136483,136633,137144,137146,137147,137262,137263,137264,137265,137266,137268,137269,137270,137273,137278,137282,137286,137293,137294,137295,137297,137298,137299,137300,137301,137302,137305,137315,137317,137367,137369,137370,137447,137510,137511,137516,137517,137521,137679,137755,137790,137797,137818,137821,137822,137823,137833,137920,137957,138004,138135,138138,138247,138254,138255,138283,138285,138287,138352,138464,138544,138949,139028,139089,139090,139113,139144,139177,139260,139375,139401,139402,140176,140284,140313,140350,140352,140363,140364,140482,140483,140515,140717,140904,140906,140935,141080,141085,141091,141274,141495,141555,141646,141698,141767,141772,141773,141804,141826,141845,141912,141920,141937,141938,141939,141961,142158,142159,142167,142179,142180,142185,142293,142294,142299,142306,142325,142371,142404,142450,142461,142490,142496,142502,142503,142607,142611,142619,142639,142644,142721,142754,142773,142954,142955,142961,142967,142993,142997,143098,143105,143109,143111,143112,143116,143128,143136,143138,143152,143156,143186,143248,143250,143263,143336,143396,143402,143493,143498,143541,143547,143559,143574,143614,143615,143626,143682,143737,143793,143842,143846,143848,143849,143851,143856,143864,143905,143919,143948,144071,144212,144213,144310,144320,144439,144493,144911,144958,144959,144981,145008,145028,145286,145287,145292,145366,145385,145728,145730,145731,145732,145734,145735,146027,146029,146335,146692,146762,146763,147137,147150,147168,147381,147542,147543,147656,147714,147741,147785,147972,147973,147974,147975,148124,148233,148242,148250,148263,148332,148333,148335,148336,148337,148338,148770,148795,148798,148914,148919,149045,149131,149270,149459,149471,149515,149519,149616,149626,149768,150122,150131,150433,151162,151173,151305,151307,152079,152080,152081,152112,152131,152184,152185,152194,152200,152201,152206,152209,152228,152324,152326,152328,152699,152722,152869,152870,152897,152908,152909,152993,153005,153020,153021,153022,153065,153084,153086,153087,153097,153760,154149,154150,154157,154161,154403,154524,155496,155528,155529,156146,156406,156524,156641,156642,156671,156697,156698,156794,156795,156820,156837,156949,157158,157609,157700,157811,157812,157813,157837,157838,158075,158092,158136,158146,158158,158371,158373,158437,158565,158575,158576,158690,158774,159275,159632,159633,160101,160458,161458,161565,162935,164596,164685,164803,168459,170557,171796,171822,173330,174146,174147,175050,175082,175138,176332,184168,184170,184286,185553,186180,189489,189535,189566,189591,195769,197244,197533,197631,197951,198579,201312,201492,202656,202700,205879,206694,206696,206697,206698,206704,206705,207353,207939,207940,207946,207949,210264,211289,211290,211291,211546,212464,212524,212528,212536,212542,212596,212629,212708,212826,212827,212831,212835,212839,212983,212986,212987,212988,213095,213129,213145,213197,213621,213622,213685,214252,214380,214429,214668,214780,214917,214939,214940,215236,215239,215243,215306,215335,215653,215663,215683,215684,215701,215727,215737,215750,216041,216088,216157,216248,216313,216314,216938,217128,217207,217247,217249,217395,217396,217429,217447,217450,217545,217578,217622,217658,217722,217730,217983,217985,217989,217990,217992,218078,218079,218163,218164,218168,218170,218173,218175,218180,218300,218372,218375,218378,218412,218431,218441,218487,218488,218502,218503,218508,218509,218658,218671,218723,219014,219053,219054,219070,219071,219072,219080,219097,219126,219150,219159,219166,219169,219186,219187,219213,219224,219228,219273,219314,219327,219339,219341,219343,219348,219392,219760,219761,219786,219788,219789,219933,219934,219935,219939,220141,220228,220232,220246,220249,220252,220253,220256,220313,220569,220712,220713,220881,220916,220946,220974,220977,220978,221002,221044,221166,221190,221302,221303,221363,221744,221760,221848,221957,221969,221971,222104,222120,222176,222242,222267,222270,222292,222303,222336,222631,222677,222688,222692,222693,222724,222867,223164,223301,223361,223363,223364,223365,223524,223605,223641,223644,223681,223842,223875,223918,223948,223989,224137,224149,224306,224332,224337,224381,224382,224424,224758,224832,224833,225483,225495,225496,225518,225555,225704,225760,225766,225972,225973,226217,226223,226270,226364,226418,226419,226458,226588,226591,226592,226727,226731,226744,226745,226746,226756,226783,226833,226834,226846,227073,227120,227126,227128,227134,227219,227318,227321,227412,227422,227427,227525,227563,227564,227566,227567,227568,228235,228649,228650,228651,229289,229299,229320,229591,230720,230734,230743,233325,235214,235409,242126)) OR (`ID`=2 AND `CreatureID` IN (68,580,3296,5515,17252,30611,44158,74228,74373,96494,120415,122452,123642,125005,126581,129909,130039,131503,134838,135606,135678,135792,135889,136633,137679,138135,138544,139088,142180,143263,143572,156642,213129,217450,219014,219982,225704)) OR (`ID`=4 AND `CreatureID` IN (1976,74373,135792,217450,219014,219982)) OR (`ID`=3 AND `CreatureID` IN (44158,74228,74373,123641,123642,126582,133325,134838,135509,135678,135792,138544,143336,156642,217450,219014,219982)) OR (`ID`=33 AND `CreatureID`=76168) OR (`ID`=5 AND `CreatureID` IN (135792,139088,217450,219014,219982)) OR (`ID`=6 AND `CreatureID` IN (135792,219014,219982)) OR (`ID`=9 AND `CreatureID`=135792) OR (`ID`=10 AND `CreatureID`=135792) OR (`ID`=8 AND `CreatureID`=139088) OR (`ID`=7 AND `CreatureID`=219014);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (90701 /*Cowardly Cheery Bombs*/, 86503 /*Who are the Dastardly Duos?*/, 83366 /*The World Awaits*/, 91205 /*Ultra Prime Deluxe Turbo-Boost: Powerhouse Challenges*/, 90731 /*Enhancing Corruption*/, 87328 /*Truly Horrific to Behold*/, 86706 /*Seeking Knowledge of the Past*/, 83436 /*Cinderbrew Meadery*/, 86801 /*Faceless Mask of Multitudes*/, 88903 /*Faceless Mask of Vengeance*/, 86153 /*Faceless Mask of the Dark Imagination*/, 86154 /*Faceless Mask of the Pained*/, 90719 /*Borrowing Corruption*/, 86155 /*Faceless Mask of the Long Night*/, 87336 /*Remembering Again and Again*/, 87335 /*Echoing Lessons*/, 87332 /*A Collection of Variables*/, 87329 /*Into the Darkest Memories*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(90701, 3, 0, 0, 0, 0, 0, 0, 0, 'Way to go, $n. You have to show those bombs who\'s boss, you know?', 61265), -- Cowardly Cheery Bombs
(86503, 3, 0, 0, 0, 0, 0, 0, 0, 'I saw your fight, good stuff. Here\'s your prize purse. Pleasure doing business.\n\nFeel free to sign up again. I\'ll remember to not bet against you next time.', 61265), -- Who are the Dastardly Duos?
(83366, 1, 0, 0, 0, 0, 0, 0, 0, 'News has come to me of your deeds among my people. Your name is spoken by earthen far and wide.', 61122), -- The World Awaits
(91205, 1005, 0, 0, 0, 0, 0, 0, 0, 'Thanks, pal. Undermine is a mess right now. We\'ll take all the help we can get.\n\nAnd hey, a deal\'s a deal. Here\'s what we owe.\n\nWe call this the jackpot reward for first time help. Check back again for more work!', 61122), -- Ultra Prime Deluxe Turbo-Boost: Powerhouse Challenges
(90731, 0, 0, 0, 0, 0, 0, 0, 0, 'Ok, this is promising... the coagulate catalyzes slower so the increased corruption is more contained... yes, this allows a higher yield of corrupted material without any negative side effects.\n\nAlas, I cannot keep it stable for long. These effects will not last. I am sorry adventurer but we should take advantage of the effects while we can. \n\nAgain, if you bring me additional displaced corrupted mementos I can make you more of these greater corruptions.', 61265), -- Enhancing Corruption
(87328, 0, 0, 0, 0, 0, 0, 0, 0, 'Excellent! There is no time to lose.', 61265), -- Truly Horrific to Behold
(86706, 1, 0, 0, 0, 0, 0, 0, 0, 'You are just in time as always! Let us speak of what brings me here.', 61265), -- Seeking Knowledge of the Past
(83436, 1, 0, 0, 0, 0, 0, 0, 0, 'Wenbrandt sent me the word. Well done. \n\nHere is your reward.', 61122), -- Cinderbrew Meadery
(86801, 0, 0, 0, 0, 0, 0, 0, 0, 'Satiated in the blood of multitudes now and forever. For our ranks will be endless and consume the world.', 61265), -- Faceless Mask of Multitudes
(88903, 0, 0, 0, 0, 0, 0, 0, 0, 'Be prepared to face the wrath of your enemies should you don this mask.', 61265), -- Faceless Mask of Vengeance
(86153, 0, 0, 0, 0, 0, 0, 0, 0, 'The risks at the edges of your sanity will now manifest if you so choose to engage them.', 61265), -- Faceless Mask of the Dark Imagination
(86154, 0, 0, 0, 0, 0, 0, 0, 0, 'As my madness and torment is not enough, feel free to invite even more pain in the future.', 61265), -- Faceless Mask of the Pained
(90719, 0, 0, 0, 0, 0, 0, 0, 0, 'Yes, by combining this residue with the displaced corrupted mementos I can... yeah just like so... and then with a bit of my bronze magic... there. Done.\n\nNow that I have a working knowledge I can also make more if you bring me additional displaced corrupted mementos. I will see if I can refine the process anymore. Check back with me later.', 61265), -- Borrowing Corruption
(86155, 0, 0, 0, 0, 0, 0, 0, 0, 'Taking a step towards the Longest Night is already acknowledging the sanity you have lost. Do you risk the rest on such a fools errand?', 61265), -- Faceless Mask of the Long Night
(87336, 0, 0, 0, 0, 0, 0, 0, 0, 'As Augermu told you--with the help of the hourglass, you can now enter the Horrific Visions as much as you like. \n\nOne more thing--we have identified some key memories within each of the visions. Through them, you will find additional boons specific to that vision that allow you to remain longer and explore more. \n\nI will add descriptions in the vision\'s Heart Chamber to help you find or unlock these boons.', 61265), -- Remembering Again and Again
(87335, 603, 0, 0, 0, 0, 0, 0, 0, 'The more echoes you make, the more mementos it\'ll take. \n\nIf you ever want to know how much you need for the next one, talk to me. I\'ll figure it out. \n\nThose visions are so creepy--but together I know we\'ll succeed, $c. The Void stands no chance against us.', 61265), -- Echoing Lessons
(87332, 1, 0, 0, 0, 0, 0, 0, 0, 'Hello there, $c. So you\'re our latest test subject--I mean, the one to revisit the visions of the past? \n\nI hear you have some displaced corrupted mementos from your last trip. \n\nPerfect! I\'ll show you what they can do.', 61265), -- A Collection of Variables
(87329, 0, 0, 0, 0, 0, 0, 0, 0, 'It\'s alright, $n. You are back. You\'ve done well. Remember, this was just a memory of a vision. \n\nWhile we will keep you safe from the past, the danger we are all in from the Void is still very real in the present.', 61265); -- Into the Darkest Memories

UPDATE `quest_offer_reward` SET `VerifiedBuild`=61265 WHERE `ID`=82679;
UPDATE `quest_offer_reward` SET `VerifiedBuild`=60822 WHERE `ID` IN (26519, 26512, 26510, 26505, 26503);

DELETE FROM `quest_greeting` WHERE (`ID`=226919 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(226919, 0, 0, 0, 'There is always more work to be done.', 61265); -- 226919

UPDATE `quest_greeting` SET `VerifiedBuild`=60822 WHERE (`Type`=0 AND `ID` IN (344,900));

DELETE FROM `quest_details` WHERE `ID` IN (86801 /*Faceless Mask of Multitudes*/, 88903 /*Faceless Mask of Vengeance*/, 87329 /*Into the Darkest Memories*/, 87328 /*Truly Horrific to Behold*/, 89039 /*Turbo-Boost: Powerhouse Challenges*/, 86706 /*Seeking Knowledge of the Past*/, 87424 /*Worldsoul: World Bosses*/, 82516 /*Worldsoul: Forging a Pact*/, 83105 /*Rush-order Requisition*/, 91205 /*Ultra Prime Deluxe Turbo-Boost: Powerhouse Challenges*/, 82706 /*Delves: Worldwide Research*/, 83436 /*Cinderbrew Meadery*/, 83366 /*The World Awaits*/, 82679 /*Archives: Seeking History*/, 86152 /*Faceless Mask of the Daredevil*/, 86151 /*Faceless Mask of the Burned Bridge*/, 86503 /*Who are the Dastardly Duos?*/, 90701 /*Cowardly Cheery Bombs*/, 83363 /*A Burning Path Through Time*/, 83358 /*The Arena Calls*/, 81610 /*What About the Children?*/, 53939 /*Breaching Boralus*/, 86153 /*Faceless Mask of the Dark Imagination*/, 86154 /*Faceless Mask of the Pained*/, 90731 /*Enhancing Corruption*/, 86155 /*Faceless Mask of the Long Night*/, 88803 /*Timely Assistance*/, 90719 /*Borrowing Corruption*/, 87336 /*Remembering Again and Again*/, 87335 /*Echoing Lessons*/, 87332 /*A Collection of Variables*/, 78713 /*The War Within*/, 72664 /*Eggs in Abundance*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86801, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Faceless Mask of Multitudes
(88903, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Faceless Mask of Vengeance
(87329, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Into the Darkest Memories
(87328, 1, 0, 0, 0, 0, 0, 0, 0, 61265), -- Truly Horrific to Behold
(89039, 1, 1, 0, 0, 0, 500, 0, 0, 61265), -- Turbo-Boost: Powerhouse Challenges
(86706, 1, 0, 0, 0, 0, 0, 0, 0, 61265), -- Seeking Knowledge of the Past
(87424, 1, 1, 0, 0, 0, 1000, 0, 0, 61122), -- Worldsoul: World Bosses
(82516, 1, 6, 0, 0, 0, 1000, 0, 0, 61122), -- Worldsoul: Forging a Pact
(83105, 1, 0, 0, 0, 0, 0, 0, 0, 61122), -- Rush-order Requisition
(91205, 1, 1, 0, 0, 0, 500, 0, 0, 61122), -- Ultra Prime Deluxe Turbo-Boost: Powerhouse Challenges
(82706, 1, 0, 0, 0, 0, 0, 0, 0, 61122), -- Delves: Worldwide Research
(83436, 1, 0, 0, 0, 0, 0, 0, 0, 61122), -- Cinderbrew Meadery
(83366, 1, 0, 0, 0, 0, 0, 0, 0, 61122), -- The World Awaits
(82679, 1, 0, 0, 0, 0, 0, 0, 0, 61122), -- Archives: Seeking History
(86152, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Faceless Mask of the Daredevil
(86151, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Faceless Mask of the Burned Bridge
(86503, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Who are the Dastardly Duos?
(90701, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Cowardly Cheery Bombs
(83363, 1, 0, 0, 0, 0, 0, 0, 0, 61265), -- A Burning Path Through Time
(83358, 1, 0, 0, 0, 0, 0, 0, 0, 61122), -- The Arena Calls
(81610, 1, 0, 0, 0, 0, 0, 0, 0, 60568), -- What About the Children?
(53939, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Breaching Boralus
(86153, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Faceless Mask of the Dark Imagination
(86154, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Faceless Mask of the Pained
(90731, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Enhancing Corruption
(86155, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Faceless Mask of the Long Night
(88803, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Timely Assistance
(90719, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Borrowing Corruption
(87336, 1, 0, 0, 0, 0, 0, 0, 0, 61265), -- Remembering Again and Again
(87335, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Echoing Lessons
(87332, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- A Collection of Variables
(78713, 1, 0, 0, 0, 0, 0, 0, 0, 61188), -- The War Within
(72664, 1, 0, 0, 0, 0, 0, 0, 0, 61122); -- Eggs in Abundance

UPDATE `quest_details` SET `VerifiedBuild`=60822 WHERE `ID` IN (65436, 26520, 26519, 26514, 26512, 26510, 26505, 26503, 26506, 26504, 26509, 26508);
UPDATE `quest_details` SET `VerifiedBuild`=61265 WHERE `ID`=43926;

DELETE FROM `quest_request_items` WHERE `ID` IN (91205 /*Ultra Prime Deluxe Turbo-Boost: Powerhouse Challenges*/, 83105 /*Rush-order Requisition*/, 84286 /*The Finer Things*/, 82706 /*Delves: Worldwide Research*/, 87424 /*Worldsoul: World Bosses*/, 85244 /*Defeating the Underpin*/, 82679 /*Archives: Seeking History*/, 86801 /*Faceless Mask of Multitudes*/, 26519 /*He Who Controls the Ettins*/, 26512 /*Tuning the Gnomecorder*/, 90731 /*Enhancing Corruption*/, 83436 /*Cinderbrew Meadery*/, 90719 /*Borrowing Corruption*/, 90701 /*Cowardly Cheery Bombs*/, 86155 /*Faceless Mask of the Long Night*/, 86154 /*Faceless Mask of the Pained*/, 86153 /*Faceless Mask of the Dark Imagination*/, 87335 /*Echoing Lessons*/, 87329 /*Into the Darkest Memories*/, 87328 /*Truly Horrific to Behold*/, 88903 /*Faceless Mask of Vengeance*/, 83366 /*The World Awaits*/, 83363 /*A Burning Path Through Time*/, 86503 /*Who are the Dastardly Duos?*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(91205, 0, 1, 0, 0, 'Yous looks out for us, and we return the favor. Right?', 61265), -- Ultra Prime Deluxe Turbo-Boost: Powerhouse Challenges
(83105, 0, 6, 0, 0, 'Do you have them? The smiths have been chewing my ear off.', 0), -- Rush-order Requisition
(84286, 0, 1, 0, 0, 'Fetch me the insignias from our Queen\'s guests and comrades. These have many uses within the city, and in exchange I will make you even deadlier to our foes within.', 0), -- The Finer Things
(82706, 0, 1, 0, 0, 'Dangerous exploration? Survivin\' by the skin of our teeth? Makes this ol\' dwarf feel alive!', 61265), -- Delves: Worldwide Research
(87424, 0, 1, 0, 0, 'I\'ve seen monsters shifting in the distant darkness of Hallowfall. Things that haunt my nightmares.', 61265), -- Worldsoul: World Bosses
(85244, 0, 0, 0, 0, '', 61265), -- Defeating the Underpin
(82679, 0, 0, 0, 0, 'Have ye found anythin\'?', 0), -- Archives: Seeking History
(86801, 0, 0, 0, 0, 'Place the Faceless Mask of Multitudes on the altar.', 0), -- Faceless Mask of Multitudes
(26519, 0, 0, 0, 0, '<The orb emanates powerful magic.>', 61265), -- He Who Controls the Ettins
(26512, 0, 6, 0, 0, 'What are you waiting around here for?', 61265), -- Tuning the Gnomecorder
(90731, 0, 0, 0, 0, 'Were you successful?', 61265), -- Enhancing Corruption
(83436, 0, 1, 0, 0, 'Any news are better than no news at all.\n\nDo not keep me waiting. Unlike the mountains, my patience is like that of a landslide.', 61265), -- Cinderbrew Meadery
(90719, 0, 0, 0, 0, 'Were you successful?', 61265), -- Borrowing Corruption
(90701, 0, 0, 0, 0, 'Those cheery bombs are asking for it, $n. Find one in a Dastardly Duos match and smack it!', 61265), -- Cowardly Cheery Bombs
(86155, 0, 0, 0, 0, 'Place the Faceless Mask of the Long Night on the altar.', 0), -- Faceless Mask of the Long Night
(86154, 0, 0, 0, 0, 'Place the Faceless Mask of the Pained on the altar.', 0), -- Faceless Mask of the Pained
(86153, 0, 0, 0, 0, 'Place the Faceless Mask of the Dark Imagination on the altar.', 0), -- Faceless Mask of the Dark Imagination
(87335, 0, 1, 0, 0, 'Were you able to slot in the first Echo of N\'Zoth?', 61265), -- Echoing Lessons
(87329, 0, 0, 0, 0, 'We must build on our past knowledge. Did you find something new?', 61265), -- Into the Darkest Memories
(87328, 0, 0, 0, 0, 'Are you ready to revisit these Horrific Visions?', 61265), -- Truly Horrific to Behold
(88903, 0, 0, 0, 0, 'Place the Faceless Mask of Vengeance on the altar.', 0), -- Faceless Mask of Vengeance
(83366, 0, 0, 0, 0, 'My people face a wide range of difficulties these days, as do yours. We can make the best of what\'s befallen us both.', 61265), -- The World Awaits
(83363, 0, 25, 0, 0, 'Some of my people may see the arrival of the outlanders as an invasion, but I am glad it was you who landed on our shoes, and not the Burning Legion.', 61265), -- A Burning Path Through Time
(86503, 0, 0, 0, 0, 'Speak with Xyggie Marou, do my tasks, and beat those Dastardly Duos!', 61265); -- Who are the Dastardly Duos?

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=61265 WHERE `ID`=26510; -- We Must Prepare!
UPDATE `quest_request_items` SET `VerifiedBuild`=61265 WHERE `ID`=26503;

DELETE FROM `quest_offer_reward_conditional` WHERE (`QuestId`=82679 AND `PlayerConditionId`=127542 AND `QuestgiverCreatureId`=226543 AND `locale`='enUS');
INSERT INTO `quest_offer_reward_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(82679, 127542, 226543, 'enUS', 'Thank ye, $p. Though I believe we\'ve recovered all of Archaedas\'s log entries, I\'d like tae continue repairing the archives.', 0, 61265); -- Archives: Seeking History


DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=2403 AND `QuestLineId` IN (5638,5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1267,1108,1107,1003,973,860,802,636,612,546,539,516,377,300,290,263,261,260,550,130)) OR (`UIMapId`=2404 AND `QuestLineId` IN (5638,5593,5519,5513,5511,5482,5382,5377,1289,1276,1267,1108,1030,957,926,858,576,546,539,526,300,289,262,240)) OR (`UIMapId`=2255 AND `QuestLineId` IN (5900,5776,5772,5741,5716,5694,5686,5685,5669,5668,5666,5663,5662,5661,5660,5659,5642,5641,5631,5630,5617,5615,5614)) OR (`UIMapId`=2215 AND `QuestLineId` IN (5900,5799,5776,5772,5741,5732,5716,5694,5686,5685,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5617,5615,5614)) OR (`UIMapId`=37 AND `QuestLineId` IN (5638,1267,1108)) OR (`UIMapId`=85 AND `QuestLineId` IN (5638,1267,1108)) OR (`UIMapId`=862 AND `QuestLineId` IN (5669,5631,5614,5380,623,622,614,604,318)) OR (`UIMapId`=2213 AND `QuestLineId`=5716) OR (`UIMapId`=863 AND `QuestLineId`=5380) OR (`UIMapId`=864 AND `QuestLineId`=5380) OR (`UIMapId`=1527 AND `QuestLineId` IN (5638,5513,5386,5385,5379,5377,5375,1030,947,923,785,743,612,545,511,290,289)) OR (`UIMapId`=895 AND `QuestLineId` IN (622,604)) OR (`UIMapId`=84 AND `QuestLineId` IN (5638,1267,1108)) OR (`UIMapId`=1 AND `QuestLineId` IN (5638,1267,1108,550,811)) OR (`UIMapId`=1961 AND `QuestLineId` IN (1259,1248,1247,1246,1234,1225,1224,1222,1221,1220,1219,1218)) OR (`UIMapId`=1543 AND `QuestLineId` IN (1267,1259,1258,1248,1246,1245,1244,1243,1242,1238,1234,1225,1224,1222,1221,1220,1218,1210,1108,1102,1098,1064,1062,1005)) OR (`UIMapId`=1970 AND `QuestLineId`=1002) OR (`UIMapId`=1670 AND `QuestLineId` IN (1135,1133,1063,1062,1057,1002)) OR (`UIMapId`=1163 AND `QuestLineId` IN (5387,5386,1030));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(2403, 5638, 61265),
(2403, 5593, 61265),
(2403, 5538, 61265),
(2403, 5519, 61265),
(2403, 5513, 61265),
(2403, 5504, 61265),
(2403, 5482, 61265),
(2403, 5459, 61265),
(2403, 5389, 61265),
(2403, 5387, 61265),
(2403, 1311, 61265),
(2403, 1295, 61265),
(2403, 1289, 61265),
(2403, 1267, 61265),
(2403, 1108, 61265),
(2403, 1107, 61265),
(2403, 1003, 61265),
(2403, 973, 61265),
(2403, 860, 61265),
(2403, 802, 61265),
(2403, 636, 61265),
(2403, 612, 61265),
(2403, 546, 61265),
(2403, 539, 61265),
(2403, 516, 61265),
(2403, 377, 61265),
(2403, 300, 61265),
(2403, 290, 61265),
(2403, 263, 61265),
(2403, 261, 61265),
(2403, 260, 61265),
(2403, 550, 61265),
(2403, 130, 61265),
(2404, 5638, 61265),
(2404, 5593, 61265),
(2404, 5519, 61265),
(2404, 5513, 61265),
(2404, 5511, 61265),
(2404, 5482, 61265),
(2404, 5382, 61265),
(2404, 5377, 61265),
(2404, 1289, 61265),
(2404, 1276, 61265),
(2404, 1267, 61265),
(2404, 1108, 61265),
(2404, 1030, 61265),
(2404, 957, 61265),
(2404, 926, 61265),
(2404, 858, 61265),
(2404, 576, 61265),
(2404, 546, 61265),
(2404, 539, 61265),
(2404, 526, 61265),
(2404, 300, 61265),
(2404, 289, 61265),
(2404, 262, 61265),
(2404, 240, 61265),
(2255, 5900, 61122),
(2255, 5776, 61122),
(2255, 5772, 61122),
(2255, 5741, 61122),
(2255, 5716, 61122),
(2255, 5694, 61122),
(2255, 5686, 61122),
(2255, 5685, 61122),
(2255, 5669, 61122),
(2255, 5668, 61122),
(2255, 5666, 61122),
(2255, 5663, 61122),
(2255, 5662, 61122),
(2255, 5661, 61122),
(2255, 5660, 61122),
(2255, 5659, 61122),
(2255, 5642, 61122),
(2255, 5641, 61122),
(2255, 5631, 61122),
(2255, 5630, 61122),
(2255, 5617, 61122),
(2255, 5615, 61122),
(2255, 5614, 61122),
(2215, 5900, 61122),
(2215, 5799, 61122),
(2215, 5776, 61122),
(2215, 5772, 61122),
(2215, 5741, 61122),
(2215, 5732, 61122),
(2215, 5716, 61122),
(2215, 5694, 61122),
(2215, 5686, 61122),
(2215, 5685, 61122),
(2215, 5669, 61122),
(2215, 5668, 61122),
(2215, 5666, 61122),
(2215, 5664, 61122),
(2215, 5663, 61122),
(2215, 5662, 61122),
(2215, 5661, 61122),
(2215, 5660, 61122),
(2215, 5659, 61122),
(2215, 5642, 61122),
(2215, 5641, 61122),
(2215, 5638, 61122),
(2215, 5631, 61122),
(2215, 5630, 61122),
(2215, 5617, 61122),
(2215, 5615, 61122),
(2215, 5614, 61122),
(37, 5638, 61122),
(37, 1267, 61122),
(37, 1108, 61122),
(85, 5638, 61122),
(85, 1267, 61122),
(85, 1108, 61122),
(862, 5669, 60822),
(862, 5631, 60822),
(862, 5614, 60822),
(862, 5380, 60822),
(862, 623, 60822),
(862, 622, 60822),
(862, 614, 60822),
(862, 604, 60822),
(862, 318, 60822),
(2213, 5716, 60568),
(863, 5380, 60490),
(864, 5380, 60490),
(1527, 5638, 60490),
(1527, 5513, 60490),
(1527, 5386, 60490),
(1527, 5385, 60490),
(1527, 5379, 60490),
(1527, 5377, 60490),
(1527, 5375, 60490),
(1527, 1030, 60490),
(1527, 947, 60490),
(1527, 923, 60490),
(1527, 785, 60490),
(1527, 743, 60490),
(1527, 612, 60490),
(1527, 545, 60490),
(1527, 511, 60490),
(1527, 290, 60490),
(1527, 289, 60490),
(895, 622, 60490),
(895, 604, 60490),
(84, 5638, 60490),
(84, 1267, 60490),
(84, 1108, 60490),
(1, 5638, 61265),
(1, 1267, 61265),
(1, 1108, 61265),
(1, 550, 61265),
(1, 811, 61188),
(1961, 1259, 60822),
(1961, 1248, 60822),
(1961, 1247, 60822),
(1961, 1246, 60822),
(1961, 1234, 60822),
(1961, 1225, 60822),
(1961, 1224, 60822),
(1961, 1222, 60822),
(1961, 1221, 60822),
(1961, 1220, 60822),
(1961, 1219, 60822),
(1961, 1218, 60822),
(1543, 1267, 60822),
(1543, 1259, 60822),
(1543, 1258, 60822),
(1543, 1248, 60822),
(1543, 1246, 60822),
(1543, 1245, 60822),
(1543, 1244, 60822),
(1543, 1243, 60822),
(1543, 1242, 60822),
(1543, 1238, 60822),
(1543, 1234, 60822),
(1543, 1225, 60822),
(1543, 1224, 60822),
(1543, 1222, 60822),
(1543, 1221, 60822),
(1543, 1220, 60822),
(1543, 1218, 60822),
(1543, 1210, 60822),
(1543, 1108, 60822),
(1543, 1102, 60822),
(1543, 1098, 60822),
(1543, 1064, 60822),
(1543, 1062, 60822),
(1543, 1005, 60822),
(1970, 1002, 60822),
(1670, 1135, 60822),
(1670, 1133, 60822),
(1670, 1063, 60822),
(1670, 1062, 60822),
(1670, 1057, 60822),
(1670, 1002, 60822),
(1163, 5387, 60490),
(1163, 5386, 60490),
(1163, 1030, 60490);

UPDATE `ui_map_quest_line` SET `VerifiedBuild`=61122 WHERE (`UIMapId`=2255 AND `QuestLineId` IN (5672,5598,5593,5558,5551,5550,5544,5534,5531,5530,5529,5526,5525,5523,5521,5520,5506)) OR (`UIMapId`=2215 AND `QuestLineId` IN (5711,5672,5671,5670,5627,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5606,5605,5597,5563)) OR (`UIMapId`=204 AND `QuestLineId` IN (541,539)) OR (`UIMapId`=205 AND `QuestLineId` IN (541,539)) OR (`UIMapId`=203 AND `QuestLineId` IN (541,539)) OR (`UIMapId`=37 AND `QuestLineId` IN (5593,5570,5519,5513,5511,5482,5458,5399,5382,5377,5372,1323,1289,1276,1226,1217,1030,1000,972,957,929,926,916,858,797,781,737,637,635,589,576,566,547,546,539,526,425,421,402,347,300,289,262,259,240,198,131)) OR (`UIMapId`=49 AND `QuestLineId` IN (1090,433,426,289)) OR (`UIMapId`=85 AND `QuestLineId` IN (5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1107,1003,973,860,802,636,612,546,539,516,377,300,290,263,261,260));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=60822 WHERE (`UIMapId`=862 AND `QuestLineId` IN (5427,5417,5411,5410,5391,5390,5389,5388,5387,5386,5384,5379,5378,1030,1003,945,939,935,932,931,910,908,905,903,902,897,888,881,873,856,851,848,842,841,839,838,802,785,747,736,629,627,626,625,620,617,612)) OR (`UIMapId`=539 AND `QuestLineId` IN (140,111,110,107,105,100,48,41,50,36)) OR (`UIMapId`=672 AND `QuestLineId` IN (5519,906,788,787,294,279,247,238,211,206,205,197,136)) OR (`UIMapId`=1543 AND `QuestLineId` IN (1269,1247,1219,1205,1204,1203,1202,1201,1123,1094,1087,1065,1014)) OR (`UIMapId`=1970 AND `QuestLineId` IN (1287,1266,1265,1264,1262,1260,1258,1250,1297,1296,1291,1288,1284)) OR (`UIMapId`=1670 AND `QuestLineId` IN (1295,1294,1287,1268,1265,1257,1248,1247,1246,1245,1244,1243,1242,1241,1240,1239,1237,1235,1225,1219,1216,1210,1205,1204,1203,1202,1201,1175,1138,1137,1136,1123,1102,1098,1090,1087,1065,1064,1014,1284)) OR (`UIMapId`=49 AND `QuestLineId` IN (1090,433,426,289)) OR (`UIMapId`=37 AND `QuestLineId` IN (5593,5570,5519,5513,5511,5482,5458,5399,5382,5377,5372,1323,1289,1276,1226,1217,1030,1000,972,957,929,926,916,858,797,781,737,637,635,589,576,566,547,546,539,526,425,421,402,347,300,289,262,259,240,198,131)) OR (`UIMapId`=84 AND `QuestLineId` IN (5593,5519,5513,5511,5497,5482,5458,5399,5382,5377,5372,1289,1276,1030,1000,972,957,929,926,916,858,797,781,737,637,635,589,576,547,546,539,526,421,347,300,289,262,259,240,198,131)) OR (`UIMapId`=1165 AND `QuestLineId` IN (5386,5384,5379,1030,881,873,851,785));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=60568 WHERE (`UIMapId`=2255 AND `QuestLineId` IN (5672,5598,5593,5558,5551,5550,5544,5534,5531,5530,5529,5526,5525,5523,5521,5520,5506)) OR (`UIMapId`=2213 AND `QuestLineId` IN (5672,5544,5506)) OR (`UIMapId`=539 AND `QuestLineId` IN (140,111,110,107,105,100,48,41,71,50,36)) OR (`UIMapId`=85 AND `QuestLineId` IN (5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1107,1003,973,860,802,636,612,546,539,516,377,300,290,263,261,260,550));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=60490 WHERE (`UIMapId`=1165 AND `QuestLineId` IN (5391,5390,5389,5387,5386,5384,5379,1030,1003,935,932,931,910,908,905,902,897,888,881,873,856,851,842,841,785,747)) OR (`UIMapId`=862 AND `QuestLineId` IN (5427,5417,5411,5410,5391,5390,5389,5388,5387,5386,5384,5379,5378,1030,1003,945,939,935,932,931,910,908,905,903,902,897,888,881,873,856,851,848,842,841,839,838,802,785,747,736,629,627,626,625,620,617,612)) OR (`UIMapId`=863 AND `QuestLineId` IN (5420,5417,5411,5391,5390,5389,5378,1102,935,888,841,5418)) OR (`UIMapId`=864 AND `QuestLineId` IN (5427,5420,5417,5411,5391,5390,5389,5378,1102,935,903,888,851,841,5418)) OR (`UIMapId`=1161 AND `QuestLineId` IN (5382,5380,5379,5378,5377,5376,5375,5374,1030,940,939,851,785,629,624,5372,5371,1004,1000,930,922,921,916,909,907,904,901,896,887,849,847,845,843,810,797,746,745,737,638,633,632,628,621,589,442)) OR (`UIMapId`=895 AND `QuestLineId` IN (5447,5388,5384,5382,5380,5379,5378,5377,5376,5375,5374,1104,1030,940,939,911,903,902,890,889,873,851,848,839,838,785,629,626,625,624,586)) OR (`UIMapId`=2213 AND `QuestLineId` IN (5672,5544,5506)) OR (`UIMapId`=942 AND `QuestLineId` IN (5452,5450,5388,5371,922,916,906,887,881,851,794,745,744,740,583,577,442,5451,5436,5435,738,591,582)) OR (`UIMapId`=84 AND `QuestLineId` IN (5593,5519,5513,5511,5497,5482,5458,5399,5382,5377,5372,1289,1276,1030,1000,972,957,929,926,916,858,797,781,737,637,635,589,576,547,546,539,526,421,347,300,289,262,259,240,198,131)) OR (`UIMapId`=2255 AND `QuestLineId` IN (5672,5598,5593,5558,5551,5550,5544,5534,5531,5530,5529,5526,5525,5523,5521,5520,5506)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5606,5605,5597,5563)) OR (`UIMapId`=85 AND `QuestLineId` IN (5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1107,1003,973,860,802,636,612,546,539,516,377,300,290,263,261,260,550));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=61265 WHERE (`UIMapId`=627 AND `QuestLineId` IN (5513,1251,364,359,333,332,331,330,329,328,327,326,325,324,323,322,321,302,297,294,291,280,257,256,255,254,253,252,251,250,221,211,206,205,181,180,179,178,177,175,97,96,95,94,295,275,152,144,130)) OR (`UIMapId`=1 AND `QuestLineId` IN (5593,5538,5519,5513,5504,5499,5459,5389,5387,5382,1311,1295,1289,1107,1003,973,860,802,636,612,546,539,516,377,300,290,263,261,260,1227,563,509,376,130)) OR (`UIMapId`=85 AND `QuestLineId` IN (5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1107,1003,973,860,802,636,612,546,539,516,377,300,290,263,261,260,550)) OR (`UIMapId`=84 AND `QuestLineId` IN (5593,5519,5513,5511,5497,5482,5382,5377,1289,1276,1030,957,926,858,576,546,539,526,300,289,262,240)) OR (`UIMapId`=37 AND `QuestLineId` IN (5593,5570,5519,5513,5511,5482,5382,5377,1323,1289,1276,1226,1217,1030,957,926,858,802,576,546,539,526,402,300,289,262,240));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=61188 WHERE (`UIMapId`=1 AND `QuestLineId` IN (5593,5538,5519,5513,5504,5499,5459,5389,5387,5382,1311,1295,1289,1107,1003,973,860,802,636,612,546,539,516,377,300,290,263,261,260,1227,563,509,376,346,130));

DELETE FROM `ui_map_quest` WHERE (`UIMapId`=2339 AND `QuestId`=82470) OR (`UIMapId`=2248 AND `QuestId` IN (86179,82519,84001,83827,85914,83532,82258,82470,83529)) OR (`UIMapId`=2255 AND `QuestId` IN (85962,85945,85914,85913,83532,82258,86178,86180,85554,82470,83538,84429,82518,82238,82254,81620)) OR (`UIMapId`=2215 AND `QuestId` IN (84001,83827,85962,85945,85914,85913,81692,83532,82258,84429,82518,83930)) OR (`UIMapId`=2214 AND `QuestId` IN (84001,83827,85914,82258,81691,84429,83930,86178,86180,85554,82470,82238));
INSERT INTO `ui_map_quest` (`UIMapId`, `QuestId`, `VerifiedBuild`) VALUES
(2339, 82470, 61122), -- Arcane Riddles
(2248, 86179, 61265), -- Side Gig: Lucky Break's Big Break
(2248, 82519, 61265), -- You Go Take Candle
(2255, 85962, 61122), -- Side Gig: Unseemly Reagents
(2255, 85945, 61122), -- Side Gig: Blood-B-Gone
(2255, 85914, 61122), -- Side Gig: Coolant Matters
(2255, 85913, 61122), -- Side Gig: Cleanup Detail
(2255, 83532, 61122), -- Hallowfall Fishing Derby
(2255, 82258, 61122), -- Sieging Siege Weapons
(2215, 84001, 61122), -- Cart Blanche
(2215, 83827, 61122), -- Silence the Song
(2215, 85962, 61122), -- Side Gig: Unseemly Reagents
(2215, 85945, 61122), -- Side Gig: Blood-B-Gone
(2215, 85914, 61122), -- Side Gig: Coolant Matters
(2215, 85913, 61122), -- Side Gig: Cleanup Detail
(2215, 81692, 61122), -- The Flame Within
(2215, 83532, 61122), -- Hallowfall Fishing Derby
(2215, 82258, 61122), -- Sieging Siege Weapons
(2214, 84001, 61122), -- Cart Blanche
(2214, 83827, 61122), -- Silence the Song
(2214, 85914, 61122), -- Side Gig: Coolant Matters
(2214, 82258, 61122), -- Sieging Siege Weapons
(2214, 81691, 61122), -- Special Assignment: Shadows Below
(2214, 84429, 61122), -- Construct Containment
(2214, 83930, 61122), -- Deworming Solution
(2215, 84429, 61122), -- Construct Containment
(2215, 82518, 61122), -- Pipe Patcher
(2215, 83930, 61122), -- Deworming Solution
(2248, 84001, 61122), -- Cart Blanche
(2248, 83827, 61122), -- Silence the Song
(2248, 85914, 61122), -- Side Gig: Coolant Matters
(2248, 83532, 61122), -- Hallowfall Fishing Derby
(2248, 82258, 61122), -- Sieging Siege Weapons
(2248, 82470, 61122), -- Arcane Riddles
(2255, 86178, 60568), -- Side Gig: Cleanin' the Coast
(2255, 86180, 60568), -- Side Gig: Infested Waters
(2255, 85554, 60568), -- Side Gig: It's Always Sunny Side Up
(2255, 82470, 60568), -- Arcane Riddles
(2255, 83538, 60568), -- Excavation Liberation
(2255, 84429, 60568), -- Construct Containment
(2255, 82518, 60568), -- Pipe Patcher
(2255, 82238, 60568), -- Lava Glob Lobbin'
(2255, 82254, 60568), -- Aquacalypse
(2255, 81620, 60568), -- Recovery Job
(2248, 83529, 61265), -- Hallowfall Fishing Derby
(2214, 86178, 60490), -- Side Gig: Cleanin' the Coast
(2214, 86180, 60490), -- Side Gig: Infested Waters
(2214, 85554, 60490), -- Side Gig: It's Always Sunny Side Up
(2214, 82470, 60490), -- Arcane Riddles
(2214, 82238, 60490); -- Lava Glob Lobbin'

UPDATE `ui_map_quest` SET `VerifiedBuild`=61265 WHERE (`UIMapId`=2248 AND `QuestId` IN (83538,82523,82288,83930));
UPDATE `ui_map_quest` SET `VerifiedBuild`=61122 WHERE (`UIMapId`=2248 AND `QuestId` IN (84429,83930));

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2534380 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534381 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534382 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534383 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534384 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534417 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534385 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534387 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534390 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534398 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534399 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2534379 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2477210 /*Map: 2601 (Khaz Algar) - Phase: 23921*/, 2492155 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2539149 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2539150 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2539151 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2491090 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2490584 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2492153 /*Map: 2601 (Khaz Algar) - Phase: 23546*/, 2492158 /*Map: 2601 (Khaz Algar) - Phase: 23546*/, 2492157 /*Map: 2601 (Khaz Algar) - Phase: 23546*/, 2490290 /*Map: 2601 (Khaz Algar) - Phase: 23546*/, 2512548 /*Map: 2601 (Khaz Algar) - Phase: 24234*/, 2505346 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2507750 /*Map: 2601 (Khaz Algar) - Phase: 24234*/, 2441763 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441794 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441770 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441769 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441804 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441793 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441768 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441759 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441798 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441716 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441792 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2441805 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2519272 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2519273 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2519266 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2519285 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2519287 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2519270 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2505454 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2505467 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2505468 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2505453 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2505473 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2505470 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2510220 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2510219 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2510215 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2510239 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2510237 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2510218 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2534380, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534381, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534382, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534383, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534384, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534417, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534385, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534387, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534390, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534398, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534399, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2534379, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2477210, 2601, 23921, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23921
(2492155, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2539149, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2539150, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2539151, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2491090, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2490584, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2492153, 2601, 23546, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23546
(2492158, 2601, 23546, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23546
(2492157, 2601, 23546, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23546
(2490290, 2601, 23546, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 23546
(2512548, 2601, 24234, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 24234
(2505346, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2507750, 2601, 24234, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 24234
(2441763, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441794, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441770, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441769, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441804, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441793, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441768, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441759, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441798, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441716, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441792, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2441805, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2519272, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2519273, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2519266, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2519285, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2519287, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2519270, 2601, 0, 0, 0, 61122), -- Map: 2601 (Khaz Algar) - Phase: 0
(2505454, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2505467, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2505468, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2505453, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2505473, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2505470, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2510220, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2510219, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2510215, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2510239, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2510237, 2552, 0, 0, 0, 61122), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2510218, 2552, 0, 0, 0, 61122); -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0

UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId` IN (2438711, 2779016, 2599201, 2472583, 2471092, 2478246, 2471188, 2505658, 2552281, 2704711, 2347280, 2779662, 2737295, 2559510, 2539844, 2524149, 2526564, 2524137, 2409748, 2358298, 2288924, 1498985, 1765170, 1480361, 1429777, 1289000, 1174116, 2674547, 2674548, 2721780, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2721717, 2721746, 2535890, 2528174, 1483928, 1174111, 1480298, 2721987, 2721596, 2722202, 2183902, 1215777, 1242641, 1844787, 1840703, 2674550, 2674549);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId`=2526510; -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId` IN (1051130, 1063686); -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId` IN (2675099, 2675098, 2675100, 2675101); -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId` IN (1386863, 1386861, 1387286); -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId` IN (2194169, 1674566, 1674584, 1674620, 1410010, 1410009, 208504, 490034, 487768, 474713, 474714, 475396, 475397, 467179, 465383, 2599201, 2472583, 2471092, 2478246, 2471188, 2505658, 2453169, 2779016, 2347280, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2537241, 2539844, 2535890, 2528174, 2438711, 2552281, 2704711, 2779662, 2737295, 2559510, 2524149, 2526564, 2524137, 2409748, 2358298, 2288924, 1765170, 1498985, 1480298, 1480361, 1174114, 2477190, 2492156, 2490118, 2472533, 2472534, 2472532, 2506045, 2505413, 2362905, 2352963, 1483872, 1578973, 1617992, 1538497, 1487658, 1476874, 431539, 430277, 430276, 431377, 11915, 32703, 1844787, 1840703);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId` IN (1429886, 1344952, 1351778, 1418359); -- Map: 1643 (Kul Tiras) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId`=2526510; -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId` IN (2183902, 2191720, 2191166, 2191167, 2180366, 2191168, 2191179, 2191173, 2191178, 2180364, 2191170, 2240785); -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId` IN (1387286, 1386863, 1386861); -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId`=1051130; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=60822 WHERE `SpawnTrackingId` IN (2438711, 2552281, 2524149, 2526564, 2524137, 2409748, 2358298, 2288924);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=60568 WHERE `SpawnTrackingId` IN (208504, 490034, 487768, 474713, 474714, 475396, 475397, 467179, 465383, 2438711, 2552281, 2524149, 2526564, 2524137, 2409748, 2358298, 2288924);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=60490 WHERE `SpawnTrackingId` IN (2438711, 2552281, 2524149, 2526564, 2524137, 2409748, 2358298, 2288924, 769274, 778842, 778866, 749350, 778844, 778870);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId`=1448534; -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId`=2505658; -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId` IN (2000629, 1920801); -- Map: 2222 (The Shadowlands) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61122 WHERE `SpawnTrackingId`=1927088; -- Map: 2222 (The Shadowlands) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId` IN (2000629, 1920801); -- Map: 2222 (The Shadowlands) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61265 WHERE `SpawnTrackingId`=1927088; -- Map: 2222 (The Shadowlands) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61188 WHERE `SpawnTrackingId` IN (2478299, 2412371, 2158408, 1823725, 2036622, 2016927, 1674359, 144608, 1498985, 1483928, 1578973, 1483872, 1429777, 1289000, 941427, 165624);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61188 WHERE `SpawnTrackingId` IN (1850485, 2062741, 2076469, 2066833, 2067395, 2060564, 2077255, 2067005, 1945541, 2008655, 2008791, 1922187, 2014763, 1926167, 2014762, 1962536, 1978804, 1871966, 1846018); -- Map: 2222 (The Shadowlands) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61188 WHERE `SpawnTrackingId` IN (1859331, 2017743); -- Map: 2222 (The Shadowlands) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61188 WHERE `SpawnTrackingId` IN (1267761, 1265660, 1218279, 1138394); -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61188 WHERE `SpawnTrackingId`=1387286; -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=61188 WHERE `SpawnTrackingId`=1174115; -- Map: 1220 (Broken Isles) - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`QuestObjectiveId`=461377 AND `SpawnTrackingId` IN (2675099,2675098,2674547,2674548)) OR (`QuestObjectiveId`=429236 AND `SpawnTrackingId`=2578532) OR (`QuestObjectiveId`=461291 AND `SpawnTrackingId` IN (2721987,2721596,2722202)) OR (`QuestObjectiveId`=448961 AND `SpawnTrackingId`=2477190) OR (`QuestObjectiveId`=451239 AND `SpawnTrackingId`=2472583) OR (`QuestObjectiveId`=449858 AND `SpawnTrackingId` IN (2492156,2490118)) OR (`QuestObjectiveId`=448667 AND `SpawnTrackingId`=2472534) OR (`QuestObjectiveId`=448580 AND `SpawnTrackingId`=2472532) OR (`QuestObjectiveId`=452291 AND `SpawnTrackingId`=2412371);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2675099, 461377, 61265), -- 2675099
(2675098, 461377, 61265), -- 2675098
(2674547, 461377, 61265), -- 2674547
(2674548, 461377, 61265), -- 2674548
(2578532, 429236, 60490), -- 2578532
(2721987, 461291, 61265), -- 2721987
(2721596, 461291, 61265), -- 2721596
(2722202, 461291, 61265), -- 2722202
(2477190, 448961, 61122), -- 2477190
(2472583, 451239, 61122), -- 2472583
(2492156, 449858, 61122), -- 2492156
(2490118, 449858, 61122), -- 2490118
(2472534, 448667, 61122), -- 2472534
(2472532, 448580, 61122), -- 2472532
(2412371, 452291, 61188); -- 2412371

UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=61265 WHERE (`QuestObjectiveId`=458129 AND `SpawnTrackingId`=2599201) OR (`QuestObjectiveId`=458128 AND `SpawnTrackingId` IN (2472583,2471092,2478246,2471188)) OR (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=456336 AND `SpawnTrackingId`=2704711) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450075 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450074 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=406756 AND `SpawnTrackingId` IN (1927088,1844787)) OR (`QuestObjectiveId`=406755 AND `SpawnTrackingId`=1840703) OR (`QuestObjectiveId`=461360 AND `SpawnTrackingId` IN (2675100,2675101,2674550,2674549));
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=61122 WHERE (`QuestObjectiveId`=386346 AND `SpawnTrackingId`=1674584) OR (`QuestObjectiveId`=353024 AND `SpawnTrackingId`=1674584) OR (`QuestObjectiveId`=341370 AND `SpawnTrackingId`=1429886) OR (`QuestObjectiveId`=458129 AND `SpawnTrackingId`=2599201) OR (`QuestObjectiveId`=458128 AND `SpawnTrackingId` IN (2472583,2471092,2478246,2471188)) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=456336 AND `SpawnTrackingId`=2704711) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450075 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450074 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985) OR (`QuestObjectiveId`=449942 AND `SpawnTrackingId`=2506045) OR (`QuestObjectiveId`=449930 AND `SpawnTrackingId`=2505413) OR (`QuestObjectiveId`=429854 AND `SpawnTrackingId`=2191179) OR (`QuestObjectiveId`=429853 AND `SpawnTrackingId`=2191173) OR (`QuestObjectiveId`=429852 AND `SpawnTrackingId`=2191178) OR (`QuestObjectiveId`=337578 AND `SpawnTrackingId`=1617992) OR (`QuestObjectiveId`=335371 AND `SpawnTrackingId`=1538497) OR (`QuestObjectiveId`=336295 AND `SpawnTrackingId`=1344952) OR (`QuestObjectiveId`=295018 AND `SpawnTrackingId`=1351778) OR (`QuestObjectiveId`=292653 AND `SpawnTrackingId`=1476874) OR (`QuestObjectiveId`=252598 AND `SpawnTrackingId` IN (430277,430276,431377)) OR (`QuestObjectiveId`=406756 AND `SpawnTrackingId` IN (1927088,1844787)) OR (`QuestObjectiveId`=406755 AND `SpawnTrackingId`=1840703);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=60822 WHERE (`QuestObjectiveId`=279765 AND `SpawnTrackingId`=1046990) OR (`QuestObjectiveId`=252598 AND `SpawnTrackingId` IN (430277,430276,431377)) OR (`QuestObjectiveId`=429854 AND `SpawnTrackingId`=2191179) OR (`QuestObjectiveId`=429853 AND `SpawnTrackingId`=2191173) OR (`QuestObjectiveId`=429852 AND `SpawnTrackingId`=2191178) OR (`QuestObjectiveId`=337578 AND `SpawnTrackingId`=1617992) OR (`QuestObjectiveId`=335371 AND `SpawnTrackingId`=1538497) OR (`QuestObjectiveId`=336295 AND `SpawnTrackingId`=1344952) OR (`QuestObjectiveId`=295018 AND `SpawnTrackingId`=1351778) OR (`QuestObjectiveId`=292653 AND `SpawnTrackingId`=1476874);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=60568 WHERE (`SpawnTrackingId`=1674584 AND `QuestObjectiveId` IN (386346,353024));
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=60490 WHERE (`SpawnTrackingId`=2191170 AND `QuestObjectiveId`=429238) OR (`SpawnTrackingId`=2196835 AND `QuestObjectiveId`=429236) OR (`SpawnTrackingId`=392137 AND `QuestObjectiveId` IN (265892,265891)) OR (`SpawnTrackingId`=1675769 AND `QuestObjectiveId`=386425) OR (`SpawnTrackingId`=1658329 AND `QuestObjectiveId`=386178) OR (`SpawnTrackingId`=1654937 AND `QuestObjectiveId` IN (385197,352994));
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=61188 WHERE (`QuestObjectiveId`=451884 AND `SpawnTrackingId`=2158408) OR (`QuestObjectiveId`=422461 AND `SpawnTrackingId`=1850485) OR (`QuestObjectiveId`=420622 AND `SpawnTrackingId` IN (2076469,2066833,2067395,2060564)) OR (`QuestObjectiveId`=408157 AND `SpawnTrackingId`=1859331) OR (`QuestObjectiveId`=406892 AND `SpawnTrackingId`=2008791) OR (`QuestObjectiveId`=406547 AND `SpawnTrackingId`=1922187) OR (`QuestObjectiveId`=406195 AND `SpawnTrackingId`=1922187) OR (`QuestObjectiveId`=406192 AND `SpawnTrackingId`=2014763) OR (`QuestObjectiveId`=406191 AND `SpawnTrackingId`=1926167) OR (`QuestObjectiveId`=406190 AND `SpawnTrackingId`=2014762) OR (`QuestObjectiveId`=409004 AND `SpawnTrackingId`=2036622) OR (`QuestObjectiveId`=398071 AND `SpawnTrackingId`=2016927) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985);

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (108279, 125394, 128986, 127538, 127552, 127910, 128484, 128411, 128410, 128404, 128406, 127554, 83279, 117470, 128147, 115097, 117064, 123339, 123342, 127539, 128467, 128144, 127553, 128494, 127542, 118861, 128153, 128443, 128151, 128141, 127457, 127550, 128215, 128142, 127533, 127544, 128212, 128213, 128214, 127547, 127459, 127548, 117280, 128570, 127458, 130204, 117259, 117275, 128567, 128696, 127582, 123338, 127578, 117406, 122638, 122639, 119712, 118146, 118390, 118603, 122118, 122636, 128218, 126209, 128220, 128219, 128175, 121404, 124612, 128459, 128599, 128420, 128421, 128629, 127570, 128647, 128630, 127573, 122155, 121071, 107796, 115279, 114770, 114658, 107725, 119766, 121355, 128635, 128644, 128601, 121406, 128651, 127546, 128602, 128451, 127537, 127576, 128595, 128596, 128603, 117404, 120276, 120277, 120278, 120565, 120560, 120525, 121712, 95229, 118924, 126208, 112548, 120562, 121713, 89265, 122164, 121998, 114437, 122160, 122171, 117278, 118577, 119092, 120656, 116460, 130103, 80864, 112484, 117290, 117288, 117291, 91384, 85520, 120938, 119456, 117975, 119659, 116214, 116154, 121137, 91677, 114144, 114145, 114599, 114601, 114143, 114141, 114147, 114600, 91676, 121942, 118174, 91931, 91619, 107801, 107794, 114104, 116200, 121699, 92750, 125823, 110513, 87013, 116199, 114788, 118259, 125079, 118207, 125804, 128433, 126259, 107802, 115741, 123057, 119054, 129659, 128227, 117937, 119053, 126181, 119277, 125103, 127842, 119402, 127845, 107799, 107798, 127527, 126059, 126060, 129364, 126463, 129366, 129367, 129365, 114216, 116649, 113256, 107800, 126223);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(108279, 0.79722219705581665, 0, 0, 61265),
(125394, 0.305999994277954101, 1.5, 0, 61265),
(128986, 0.305999994277954101, 1.5, 0, 61265),
(127538, 0.312499761581420898, 1.349999904632568359, 0, 61265),
(127552, 0.663779318332672119, 1.42500007152557373, 0, 61265),
(127910, 0.208000004291534423, 1.5, 0, 61265),
(128484, 0.347222000360488891, 1.5, 0, 61265),
(128411, 0.208000004291534423, 1.5, 0, 61265),
(128410, 0.305999994277954101, 1.5, 0, 61265),
(128404, 0.208000004291534423, 1.5, 0, 61265),
(128406, 0.384999990463256835, 1.65000009536743164, 0, 61265),
(127554, 0.656792223453521728, 1.409999966621398925, 0, 61265),
(83279, 0.208000004291534423, 1.5, 0, 61265),
(117470, 3.810822486877441406, 3, 0, 61265),
(128147, 0.208000004291534423, 1.5, 0, 61265),
(115097, 1.5, 1.5, 0, 61265),
(117064, 2.923198699951171875, 4.5, 0, 61265),
(123339, 0.208000004291534423, 1.5, 0, 61265),
(123342, 0.208000004291534423, 1.5, 0, 61265),
(127539, 0.329860895872116088, 1.42500007152557373, 0, 61265),
(128467, 0.208000004291534423, 1.5, 0, 61265),
(128144, 0.698715150356292724, 1.5, 0, 61265),
(127553, 0.642817974090576171, 1.380000114440917968, 0, 61265),
(128494, 0.208000004291534423, 1.5, 0, 61265),
(127542, 0.312499761581420898, 1.35000002384185791, 0, 61265),
(118861, 3.269280910491943359, 0, 0, 61265),
(128153, 0.305999994277954101, 1.5, 0, 61265),
(128443, 0.305999964475631713, 1.499999880790710449, 0, 61265),
(128151, 0.347222000360488891, 1.5, 0, 61265),
(128141, 0.305999994277954101, 1.5, 0, 61265),
(127457, 0.208000004291534423, 1.5, 0, 61265),
(127550, 0.305999994277954101, 1.5, 0, 61265),
(128215, 0.78264474868774414, 0.75, 0, 61265),
(128142, 0.305999994277954101, 1.5, 0, 61265),
(127533, 0.208000004291534423, 1.5, 0, 61265),
(127544, 0.305999994277954101, 1.5, 0, 61265),
(128212, 0.78264474868774414, 0.75, 0, 61265),
(128213, 0.78264474868774414, 0.75, 0, 61265),
(128214, 0.78264474868774414, 0.75, 0, 61265),
(127547, 0.663779377937316894, 1.424999952316284179, 0, 61265),
(127459, 0.347221970558166503, 1.499999880790710449, 0, 61265),
(127548, 0.663779377937316894, 1.424999952316284179, 0, 61265),
(117280, 0.347000002861022949, 1.5, 0, 61265),
(128570, 1, 1.5, 0, 61265),
(127458, 0.208000004291534423, 1.50000011920928955, 0, 61265),
(130204, 3.696048259735107421, 5, 0, 61265),
(117259, 0.347000002861022949, 1.5, 0, 61265),
(117275, 0.347000002861022949, 1.5, 0, 61265),
(128567, 1, 1.5, 0, 61265),
(128696, 0.296819984912872314, 1.455000042915344238, 0, 61265),
(127582, 0.260416507720947265, 1.125, 0, 61265),
(123338, 0.208000004291534423, 1.5, 0, 61265),
(127578, 0.187199994921684265, 1.349999904632568359, 0, 61265),
(117406, 1.029999971389770507, 1.5, 0, 61265),
(122638, 0.5, 1, 0, 61265),
(122639, 0.5, 1, 0, 61265),
(119712, 0.5, 1, 0, 61265),
(118146, 1.085000038146972656, 3.5, 0, 61265),
(118390, 0.483442813158035278, 0, 0, 61265),
(118603, 4.274016380310058593, 3.75, 0, 61265),
(122118, 5.84639739990234375, 9, 0, 61265),
(122636, 0.5, 1, 0, 61265),
(128218, 1.147878885269165039, 1.10000002384185791, 0, 61265),
(126209, 1.043526291847229003, 1, 0, 61265),
(128220, 1.147878885269165039, 1.10000002384185791, 0, 61265),
(128219, 1.147878885269165039, 1.10000002384185791, 0, 61265),
(128175, 0.5, 9, 0, 61265),
(121404, 0.347000002861022949, 1.5, 0, 61265),
(124612, 0.525000035762786865, 2.249999761581420898, 0, 61265),
(128459, 0.698715150356292724, 1.5, 0, 61265),
(128599, 0.347000002861022949, 1.5, 0, 61265),
(128420, 0.347222000360488891, 1.5, 0, 61265),
(128421, 0.305999994277954101, 1.5, 0, 61265),
(128629, 0.208000004291534423, 1.5, 0, 61265),
(127570, 0.296820014715194702, 1.455000042915344238, 0, 61265),
(128647, 0.305999994277954101, 1.5, 0, 61265),
(128630, 0.347222000360488891, 1.5, 0, 61265),
(127573, 0.558972179889678955, 1.20000004768371582, 0, 61265),
(122155, 1.366205096244812011, 1.75, 0, 61265),
(121071, 1.661781191825866699, 2, 0, 61265),
(107796, 0.382999986410140991, 1.5, 0, 61265),
(115279, 0.347000002861022949, 1.5, 0, 61265),
(114770, 0.5, 9, 0, 61265),
(114658, 1.65874183177947998, 2, 0, 61265),
(107725, 1.27764892578125, 2.5, 0, 61265),
(119766, 0.5, 1, 0, 61265),
(121355, 0.142894625663757324, 1.070000052452087402, 0, 61265),
(128635, 0.208000004291534423, 1.5, 0, 61265),
(128644, 0.208000004291534423, 1.5, 0, 61265),
(128601, 0.347000002861022949, 1.5, 0, 61265),
(121406, 0.347000002861022949, 1.5, 0, 61265),
(128651, 0.698715150356292724, 1.5, 0, 61265),
(127546, 0.663779377937316894, 1.424999952316284179, 0, 61265),
(128602, 0.347000002861022949, 1.5, 0, 61265),
(128451, 0.347221970558166503, 1.499999880790710449, 0, 61265),
(127537, 0.208000004291534423, 1.5, 0, 61265),
(127576, 0.593907892704010009, 1.27500009536743164, 0, 61265),
(128595, 0.347000002861022949, 1.5, 0, 61265),
(128596, 0.347000002861022949, 1.5, 0, 61265),
(128603, 0.347000002861022949, 1.5, 0, 61265),
(117404, 1.029999971389770507, 1.5, 0, 61265),
(120276, 0.45881056785583496, 0, 0, 61265),
(120277, 1.225103616714477539, 0, 0, 61265),
(120278, 0.477057248353958129, 0, 0, 61265),
(120565, 0.347000002861022949, 1.5, 0, 61265),
(120560, 0.347000002861022949, 1.5, 0, 61265),
(120525, 0.158240109682083129, 0.300000011920928955, 0, 61265),
(121712, 1.070488333702087402, 0, 0, 61265),
(95229, 0.300000011920928955, 1, 0, 61265),
(118924, 0.372000008821487426, 1.5, 0, 61265),
(126208, 0.826666653156280517, 2.666666507720947265, 0, 61265),
(112548, 0.978626847267150878, 2, 0, 61265),
(120562, 0.347000002861022949, 1.5, 0, 61265),
(121713, 1.070488333702087402, 0, 0, 61265),
(89265, 0.191469371318817138, 1, 0, 61265),
(122164, 1.366205096244812011, 1.75, 0, 61265),
(121998, 0.305999994277954101, 1.5, 0, 61265),
(114437, 1.623467206954956054, 0.60000002384185791, 0, 61265),
(122160, 1.366205096244812011, 1.75, 0, 61265),
(122171, 1.366205096244812011, 1.75, 0, 61265),
(117278, 0.347000002861022949, 1.5, 0, 61265),
(118577, 17.53167152404785156, 30, 0, 61265),
(119092, 0.208000004291534423, 1.5, 0, 61265),
(120656, 1.147879004478454589, 1.10000002384185791, 0, 61265),
(116460, 1.565289497375488281, 1.5, 0, 61265),
(130103, 0.150000005960464477, 16, 0, 61265),
(80864, 3.445848941802978515, 5, 0, 61265),
(112484, 0.310000002384185791, 1, 0, 61265),
(117290, 1, 1.5, 0, 61265),
(117288, 1, 1.5, 0, 61265),
(117291, 1, 1.5, 0, 61265),
(91384, 0.765362918376922607, 0, 0, 61265),
(85520, 0.310000002384185791, 1, 0, 61265),
(120938, 0.347000002861022949, 1.5, 0, 61265),
(119456, 0.347000002861022949, 1.5, 0, 61265),
(117975, 1.917696714401245117, 0, 0, 61265),
(119659, 21.91567802429199218, 45, 0, 61265),
(116214, 2.301241874694824218, 0, 0, 61265),
(116154, 0.41795814037322998, 0.25, 0, 61265),
(121137, 0.405544370412826538, 0, 0, 61265),
(91677, 0.305999994277954101, 1.5, 0, 61265),
(114144, 0.382999986410140991, 1.5, 0, 61265),
(114145, 0.382999986410140991, 1.5, 0, 61265),
(114599, 0.382999986410140991, 1.5, 0, 61265),
(114601, 0.382999986410140991, 1.5, 0, 61265),
(114143, 0.382999986410140991, 1.5, 0, 61265),
(114141, 0.382999986410140991, 1.5, 0, 61265),
(114147, 0.382999986410140991, 1.5, 0, 61265),
(114600, 0.382999986410140991, 1.5, 0, 61265),
(91676, 0.305999994277954101, 1.5, 0, 61265),
(121942, 0.382999986410140991, 1.5, 0, 61265),
(118174, 0.483442813158035278, 0, 0, 61265),
(91931, 0.310000002384185791, 2.5, 0, 61265),
(91619, 3.925986766815185546, 6, 0, 61265),
(107801, 0.382999986410140991, 1.5, 0, 61265),
(107794, 0.382999986410140991, 1.5, 0, 61265),
(114104, 0.108170777559280395, 0.450000017881393432, 0, 61265),
(116200, 1.105173707008361816, 2, 0, 61265),
(121699, 0.713658928871154785, 0, 0, 61265),
(92750, 13.1637735366821289, 0, 0, 61265),
(125823, 0.305999994277954101, 1.5, 0, 61265),
(110513, 0.687535762786865234, 0, 0, 61265),
(87013, 0.150000005960464477, 0, 0, 61265),
(116199, 1.105173707008361816, 2, 0, 61265),
(114788, 0.916329503059387207, 1, 0, 61265),
(118259, 3.302712678909301757, 2.599999904632568359, 0, 61265),
(125079, 0.310000002384185791, 1, 0, 61265),
(118207, 0.347000002861022949, 1.5, 0, 61265),
(125804, 0.305999994277954101, 1.5, 0, 61265),
(128433, 0.347000002861022949, 1.5, 0, 61265),
(126259, 0.158240109682083129, 0.300000011920928955, 0, 61265),
(107802, 0.305999994277954101, 1.5, 0, 61265),
(115741, 1.227306604385375976, 1.20000004768371582, 0, 61265),
(123057, 3.75, 3.75, 0, 61265),
(119054, 0.948864340782165527, 1.80000007152557373, 0, 61265),
(129659, 0.305999994277954101, 1.5, 0, 61265),
(128227, 0.305999994277954101, 1.5, 0, 61265),
(117937, 0.948864400386810302, 1.80000007152557373, 0, 61265),
(119053, 0.948864340782165527, 1.80000007152557373, 0, 61265),
(126181, 1.277637600898742675, 2.5, 0, 61265),
(119277, 0.310000002384185791, 1, 0, 61265),
(125103, 0.815703630447387695, 1.125, 0, 61265),
(127842, 2.861786365509033203, 3, 0, 61265),
(119402, 0.150000005960464477, 0.150000005960464477, 0, 61265),
(127845, 2.861786365509033203, 3, 0, 61265),
(107799, 0.382999986410140991, 1.5, 0, 61265),
(107798, 0.305999994277954101, 1.5, 0, 61265),
(127527, 0.100000001490116119, 0, 0, 61265),
(126059, 0.604059219360351562, 1.5, 0, 61265),
(126060, 0.604059219360351562, 1.5, 0, 61265),
(129364, 0.300000011920928955, 1, 0, 61265),
(126463, 0.58709186315536499, 0, 0, 61265),
(129366, 0.300000011920928955, 1, 0, 61265),
(129367, 0.300000011920928955, 1, 0, 61265),
(129365, 0.300000011920928955, 1, 0, 61265),
(114216, 1.755318164825439453, 2.999999761581420898, 0, 61265),
(116649, 21.00568580627441406, 2.15000009536743164, 0, 61265),
(113256, 30.27434349060058593, 28, 0, 61265),
(107800, 0.382999986410140991, 1.5, 0, 61265),
(126223, 0.27383655309677124, 0, 0, 61265);

UPDATE `creature_model_info` SET `VerifiedBuild`=61265 WHERE `DisplayID` IN (120822, 119914, 119916, 119915, 119917, 116476, 109635, 109642, 56814, 116356, 119255, 118051, 121076, 116349, 120411, 121800, 116354, 115751, 119256, 119243, 119758, 121040, 116538, 119254, 122040, 121115, 121117, 121116, 114655, 90726, 115369, 115365, 121534, 38185, 117464, 86476, 62404, 119706, 115120, 101145, 120321, 114131, 120320, 121185, 116519, 122303, 118137, 120453, 120318, 122305, 122304, 120319, 115359, 115361, 119988, 104517, 114961, 104523, 114964, 115473, 114918, 115410, 115431, 114962, 117524, 115472, 115526, 115527, 115207, 115208, 115213, 109361, 118220, 115575, 115214, 115576, 115198, 115199, 115370, 115093, 114626, 118402, 112712, 115344, 115358, 115577, 121162, 116444, 116346, 116445, 115722, 121160, 121165, 117754, 121161, 119788, 121141, 118700, 117312, 88695, 117316, 115708, 116478, 117311, 116673, 116355, 8840, 114921, 120495, 116517, 116520, 64392, 54643, 120970, 119989, 121865, 53782, 117755, 121535, 119418, 119840, 118172, 118142, 122682, 119423, 117228, 122694, 118001, 119409, 120470, 119425, 122704, 122943, 117884, 122709, 121132, 122707, 119428, 119431, 122711, 119432, 119433, 118864, 119427, 119407, 119424, 115031, 104516, 115032, 122702, 122703, 122680, 121045, 121046, 122706, 115758, 104520, 122701, 122700, 119419, 120593, 122684, 119417, 122678, 120036, 117227, 37127, 117044, 118339, 116278, 117463, 122708, 119413, 119416, 122710, 118635, 122695, 122696, 122697, 122668, 122691, 103811, 122669, 122685, 122667, 122674, 116276, 117882, 117879, 115596, 119765, 117877, 118186, 115288, 122944, 117240, 117876, 121359, 116368, 121369, 121730, 122705, 70050, 122693, 122692, 71577, 104631, 104634, 120917, 84680, 84987, 84934, 115342, 115496, 115488, 115111, 117471, 115616, 115504, 115482, 115501, 115502, 115498, 115492, 115503, 104496, 118363, 115497, 115424, 115112, 115499, 115500, 115491, 119649, 115413, 115417, 115125, 117752, 104505, 115460, 115012, 115461, 114484, 33920, 114483, 112726, 79809, 119987, 119990, 108088, 114146, 111899, 114305, 115073, 68303, 67658, 119502, 122635, 120931, 117915, 122637, 122649, 119042, 116428, 116788, 119522, 121738, 118090, 104521, 104518, 110431, 107720, 117120, 112488, 114722, 114741, 114701, 118080, 112389, 114705, 120809, 117399, 117113, 117400, 122630, 114525, 114735, 114697, 114732, 117893, 111900, 122631, 117920, 112396, 112384, 114699, 117914, 114700, 112393, 117913, 117917, 117919, 117918, 114767, 114164, 117916, 114089, 114801, 114738, 118914, 59243, 118057, 114726, 114157, 118059, 114723, 114745, 114757, 114720, 114743, 114721, 114696, 114691, 114803, 117062, 118053, 114758, 40225, 33011, 114718, 35319, 114841, 115015, 114550, 115094, 112724, 114897, 114551, 114549, 115100, 66843, 66844, 118388, 116829, 118585, 107719, 110442, 119711, 115099, 40543, 119774, 118389, 112485, 119896, 112486, 117869, 118630, 79780, 117851, 40976, 119795, 119797, 68057, 91868, 115096, 69105, 118087, 117460, 117462, 72764, 117441, 114361, 119174, 118548, 118547, 37551, 45021, 117577, 37550, 120999, 75598, 118229, 117558, 115717, 120553, 120935, 120554, 120556, 120352, 120412, 117318, 121802, 114656, 120413, 115777, 115082, 115076, 115080, 104519, 115339, 115332, 115013, 117889, 90736, 90730, 117402, 117446, 117437, 73697, 36464, 90830, 117256, 117255, 115350, 120579, 89910, 42449, 120576, 75345, 121889, 114939, 114938, 114936, 121445, 114654, 121425, 120472, 117612, 120437, 122462, 120438, 120439, 119327, 120473, 119076, 110061, 121457, 33293, 119410, 119412, 33720, 119239, 117951, 118317, 114789, 120442, 120443, 120440, 120441, 16259, 26759, 117483, 83699, 117496, 70178, 118006, 117485, 119066, 119067, 115226, 114563, 117489, 115211, 114830, 117069, 115401, 115212, 115399, 108199, 114659, 90583, 114916, 114930, 115190, 83616, 115242, 117490, 114800, 114304, 119087, 45880, 114821, 108505, 114840, 103969, 114839, 114543, 67819, 121356, 121363, 117887, 115594, 122699, 115033, 122679, 121366, 14501, 117241, 114927, 114928, 102508, 117481, 121448, 108269, 106562, 115351, 114569, 15381, 54756, 54848, 53748, 66223, 121287, 88201, 114943, 121019, 28815, 117888, 115011, 122713, 115593, 121352, 117759, 115023, 122425, 122420, 118912, 122424, 122419, 117403, 115340, 115034, 115155, 118454, 118467, 118231, 118468, 118465, 117445, 110445, 118466, 110447, 110446, 118082, 103338, 58535, 110444, 103340, 115095, 110448, 121884, 55644, 57548, 92704, 109505, 112397, 78851, 112398, 103342, 117940, 117995, 117939, 118892, 115706, 118099, 70179, 75347, 70154, 114087, 114694, 117541, 122660, 122659, 114570, 114709, 121642, 122656, 121643, 115614, 117232, 114650, 118214, 119280, 114646, 121446, 95789, 119857, 120564, 120563, 37410, 37297, 66693, 81841, 81837, 78163, 82314, 20042, 75966, 75971, 17049, 32263, 32264, 32265, 20307, 76019, 81013, 81109, 81847, 82141, 66698, 47306, 48213, 82595, 82609, 88124, 78762, 95014, 95015, 95017, 78761, 78759, 78855, 69203, 85825, 87384, 91499, 90077, 81248, 75378, 80520, 80266, 76532, 73854, 87507, 86203, 84915, 86204, 86073, 88522, 86205, 86198, 88687, 63276, 80521, 80522, 88832, 83556, 83557, 88830, 81455, 80802, 81115, 81117, 81268, 43127, 85697, 51256, 35111, 83690, 85703, 83784, 41405, 82207, 87624, 80716, 85694, 85245, 87623, 82396, 87382, 87383, 82405, 79853, 60962, 84291, 21899, 86455, 82406, 82407, 60963, 83686, 82390, 33655, 82395, 77186, 82629, 82389, 81044, 81049, 38261, 81007, 81002, 6412, 28252, 81039, 81006, 76020, 4622, 81041, 81033, 9710, 81038, 81057, 30945, 82542, 4534, 81524, 81052, 81030, 28261, 38008, 81066, 81047, 81045, 81110, 81012, 81014, 81088, 78832, 81010, 81026, 80938, 6411, 81062, 81046, 65052, 77187, 76657, 82707, 81244, 86399, 85534, 82193, 87003, 88444, 87005, 87001, 82329, 82062, 86996, 87679, 86995, 81830, 86998, 82182, 82066, 82079, 78286, 87837, 87841, 85371, 47311, 80358, 80998, 90750, 82022, 82023, 91358, 35951, 93574, 118989, 59223, 46575, 29101, 63690, 91239, 93229, 91066, 63429, 82155, 66795, 31605, 26364, 33878, 71764, 69152, 84341, 84342, 82119, 42280, 81886, 81862, 81839, 81914, 81848, 80997, 81853, 76409, 82081, 87667, 82705, 87516, 76391, 82328, 82706, 82065, 81979, 87660, 82638, 82327, 79372, 82059, 77063, 82158, 82159, 82157, 82190, 82331, 80517, 82130, 82641, 82330, 80537, 82060, 82630, 82642, 82332, 82333, 67941, 82255, 87385, 82241, 77061, 55922, 79062, 84870, 77060, 84867, 84869, 80514, 80516, 80535, 86603, 84747, 84746, 79512, 86605, 79773, 79771, 1974, 10991, 83648, 66777, 77148, 83126, 77125, 77149, 77127, 79921, 79411, 79920, 77126, 77137, 5244, 78260, 110046, 100536, 80673, 80900, 76565, 75596, 78697, 86302, 82392, 86244, 42407, 78160, 77967, 47934, 78162, 58745, 86243, 86245, 55923, 86282, 77475, 77477, 84196, 76736, 76734, 74268, 81973, 47234, 80611, 47994, 51277, 85252, 47887, 81189, 85251, 2609, 91019, 55697, 81121, 81124, 37604, 83844, 81138, 43155, 10825, 1105, 79861, 33963, 9734, 551, 558, 6040, 4449, 6030, 6036, 36848, 80840, 123097, 121109, 121102, 75599, 80491, 10824, 85559, 85556, 34612, 37288, 88491, 87054, 87049, 78964, 85659, 85512, 85516, 61531, 120561, 81747, 78846, 79887, 79971, 119715, 76548, 120013, 75368, 104049, 113897, 30244, 121146, 90152, 90153, 80265, 114540, 90154, 30263, 78241, 36595, 74697, 81953, 81951, 74698, 75699, 120631, 77689, 78218, 82908, 21975, 66812, 122166, 104092, 63972, 82887, 24929, 82019, 80591, 78240, 78243, 75701, 86139, 88693, 88696, 76516, 9392, 8572, 70574, 106818, 77591, 52580, 85440, 52574, 85507, 93454, 81152, 78633, 80983, 81153, 81151, 79801, 80745, 80744, 82957, 82960, 84726, 45491, 76888, 83866, 82785, 82780, 84088, 88616, 39726, 81745, 79059, 82955, 82954, 16213, 47105, 103280, 93449, 93452, 114795, 114792, 114102, 114823, 35519, 18236, 17051, 87818, 87833, 87831, 88065, 87823, 87824, 87825, 87820, 87821, 87822, 87819, 87826, 87814, 87690, 90439, 19785, 81188, 84583, 84581, 84577, 82315, 87815, 19181, 80049, 93450, 108956, 82540, 87392, 85658, 85631, 85639, 85655, 85595, 85642, 85640, 85557, 85638, 85513, 85558, 85554, 85654, 85636, 85619, 85637, 85535, 85537, 85622, 85620, 86621, 86618, 85621, 86620, 85623, 85510, 87062, 88193, 85515, 88195, 88155, 87052, 85661, 88488, 87907, 76550, 88489, 87051, 87659, 88151, 88156, 88503, 88250, 83264, 104046, 84290, 46243, 84430, 88960, 88406, 59513, 88306, 88404, 84619, 88303, 88403, 88311, 88153, 77040, 88307, 78475, 84413, 82612, 87947, 84336, 78326, 87632, 87636, 87622, 88824, 82134, 1551, 66195, 37140, 21209, 83028, 75339, 75330, 87017, 75328, 75340, 86168, 122170, 84584, 80767, 77489, 82988, 85641, 81160, 102533, 93317, 73844, 75910, 84139, 81312, 64714, 88828, 83524, 83051, 81313, 83523, 83045, 84898, 88055, 91011, 53108, 32681, 84166, 87806, 94459, 91067, 94462, 165, 87628, 87803, 91012, 91009, 88050, 87761, 89353, 87808, 84173, 90165, 89355, 84174, 87782, 87805, 87807, 83056, 55345, 89354, 83057, 87811, 87810, 88881, 88490, 88492, 88827, 15275, 87698, 87804, 87800, 87801, 89352, 88837, 63627, 86738, 87638, 85396, 86704, 86638, 44575, 89604, 42178, 84812, 86641, 84142, 87602, 81589, 90653, 86923, 87565, 83303, 85657, 85653, 87948, 85261, 79313, 87757, 85281, 85347, 85406, 85332, 85329, 79390, 87568, 87395, 87394, 85307, 87668, 87582, 87972, 85306, 45263, 87670, 53517, 89751, 85273, 85283, 85271, 85301, 85315, 88302, 88484, 84339, 88485, 85268, 85267, 76518, 85266, 77055, 85493, 85437, 52582, 85547, 77041, 102531, 85550, 81366, 85439, 88292, 93466, 85549, 85548, 114815, 114825, 102530, 114819, 1130, 93451, 113610, 104126, 37298, 30261, 373, 30262, 24998, 14334, 37302, 86849, 87926, 87685, 87684, 87688, 88043, 88080, 88072, 88075, 88070, 88081, 33184, 33395, 80777, 80746, 80750, 115144, 78835, 83295, 9897, 86287, 79804, 85232, 85230, 80753, 80854, 46930, 80747, 81802, 87686, 87687, 87909, 87928, 81749, 87910, 78993, 88044, 88079, 88073, 88074, 81207, 87817, 87689, 80846, 78806, 87924, 87030, 87925, 93318, 93455, 109788, 61020, 88054, 85044, 61019, 87417, 85045, 94595, 79066, 87678, 82676, 82677, 88279, 85892, 78466, 93453, 88186, 87596, 88263, 77498, 85368, 88200, 31840, 88283, 77053, 88139, 85369, 92705, 84201, 15652, 83079, 19182, 15136, 80247, 85898, 81352, 84437, 81353, 83909, 89042, 89037, 89035, 85900, 84064, 88411, 85896, 83834, 77052, 84470, 80858, 78483, 85890, 88141, 85656, 42365, 88456, 83889, 88557, 77051, 88135, 85894, 82340, 88140, 88550, 88446, 85895, 88134, 88137, 88450, 81351, 88445, 85893, 85897, 81354, 84084, 88451, 88136, 90947, 83890, 85400, 88295, 87699, 88278, 122163, 83883, 83862, 88192, 91343, 120498, 115113, 103904, 91387, 104117, 88495, 40905, 122175, 77054, 65, 88291, 22776, 88304, 88172, 88150, 77043, 78962, 82543, 82544, 80178, 78479, 88621, 104165, 88308, 78469, 78963, 78965, 82541, 78624, 82665, 88481, 82546, 88247, 87849, 87872, 87844, 88199, 88189, 88482, 37706, 60826, 87891, 87877, 87876, 88190, 114807, 119070, 84263, 121450, 114806, 114805, 120015, 114804, 119283, 91383, 91386, 84086, 104797, 114986, 119005, 117772, 123899, 117473, 118481, 118997, 117938, 114542, 115748, 120497, 117449, 43223, 114411, 122208, 99860, 81535, 31841, 88962, 87901, 83799, 79559, 84469, 82338, 117177, 80180, 114544, 89238, 115774, 37620, 5243, 506, 386, 114988, 116456, 116453, 114987, 114415, 114413, 115738, 120226, 117390, 106374, 56187, 115205, 114561, 117376, 115189, 116457, 75346, 120271, 120272, 120270, 117378, 117377, 118403, 106598, 32404, 120400, 120450, 120446, 120448, 120449, 117751, 119205, 114113, 115465, 121848, 51048, 27855, 115398, 116475, 83268, 83267, 118856, 114627, 78481, 78632, 80182, 56813, 115707, 116477, 114362, 110198, 81540, 89815, 66688, 101603, 83275, 84548, 89812, 64466, 89813, 81742, 76971, 84085, 79805, 119530, 112729, 112730, 116439, 116441, 116482, 90123, 116084, 88944, 114989, 75967, 103218, 85799, 36953, 83201, 88670, 88654, 88655, 114826, 10699, 86090, 36955, 62247, 70444, 112490, 116589, 115251, 10054, 113980, 31596, 85519, 4960, 118074, 22611, 25906, 119707, 82892, 119479, 122644, 122624, 117972, 118365, 117971, 122643, 117783, 120315, 122625, 122641, 117784, 122640, 115252, 91864, 115257, 114837, 103499, 119068, 119764, 116216, 117068, 109354, 106691, 109350, 117085, 106699, 106700, 115110, 115253, 117067, 102523, 116616, 122121, 46938, 82231, 114920, 114919, 37352, 115147, 501, 113982, 32409, 102512, 57498, 114365, 109507, 42659, 80912, 82795, 70450, 112388, 115403, 80897, 86991, 80906, 81743, 80907, 81828, 115406, 122634, 80911, 86992, 83677, 81748, 82797, 81753, 81689, 81623, 82236, 109510, 122632, 122627, 115404, 40089, 119708, 115408, 75377, 75372, 118218, 115250, 115407, 115405, 122633, 112386, 115409, 122629, 116611, 85664, 117859, 115262, 102375, 1939, 82550, 39109, 83296, 83304, 83301, 84592, 120915, 86388, 84594, 117580, 114703, 117141, 78630, 84023, 84593, 82339, 83302, 114706, 117443, 102556, 116435, 112455, 115969, 114731, 114733, 55913, 30256, 88185, 88203, 78151, 103500, 103831, 102554, 114724, 116434, 117440, 114727, 117438, 117439, 117140, 114730, 114725, 117581, 114729, 117579, 88547, 117442, 117444, 102555, 114092, 117436, 117447, 78478, 82693, 49764, 84091, 112454, 88187, 86855, 88371, 88498, 89811, 88191, 84547, 90122, 84545, 60755, 85483, 72524, 81539, 112458, 117787, 90121, 118894, 89198, 89207, 89755, 77047, 89004, 35424, 89150, 64184, 89002, 83343, 42408, 83342, 78967, 84546, 82492, 82888, 88949, 89001, 89003, 90119, 88947, 76549, 23136, 83316, 83315, 9829, 112459, 85817, 77039, 82853, 88370, 42744, 88945, 59821, 112411, 89148, 59820, 85482, 88943, 112456, 59822, 89140, 72525, 88367, 81534, 89816, 44997, 66723, 64329, 78390, 121424, 85811, 118270, 20024, 30760, 114794, 89704, 91636, 60766, 114117, 114817, 104531, 104031, 114107, 89251, 114822, 114110, 115720, 115108, 47511, 89014, 23647, 59660, 119017, 8014, 42183, 37088, 39910, 36726, 35192, 45862, 82490, 30763, 58499, 61250, 117811, 36638, 119026, 119020, 119441, 121087, 118000, 114514, 119459, 119028, 118076, 121036, 121034, 119032, 119023, 121055, 117818, 119033, 119034, 119445, 121056, 117828, 116429, 118999, 119018, 119021, 118068, 119013, 36116, 36117, 36114, 36115, 119030, 120557, 121058, 108585, 119437, 124003, 118003, 74917, 119460, 119019, 121037, 118004, 119015, 118378, 119022, 121035, 121064, 100041, 12191, 121061, 120746, 45864, 45865, 15352, 45863, 93637, 32323, 9256, 37154, 114425, 92438, 109512, 101440, 94915, 3367, 2150, 123797, 366, 56950, 489, 487, 23482, 56990, 54483, 56985, 56991, 56987, 19291, 54407, 53741, 54386, 54509, 55521, 14550, 55938, 17173, 38693, 53764, 54406, 54411, 60891, 57009, 118518, 67019, 67176, 40169, 66720, 61912, 62750, 63967, 72961, 65683, 69986, 69988, 60550, 64416, 69987, 62779, 73011, 16269, 63144, 63986, 61732, 60079, 61734, 64767, 73010, 66396, 61698, 90314, 32803, 118443, 118332, 66682, 105425, 59970, 80595, 46940, 39809, 99449, 42386, 104831, 16795, 29371, 10186, 27686, 14415, 121020, 49630, 102218, 108987, 107069, 102032, 104935, 55561, 109760, 106904, 104949, 105104, 104958, 65070, 93738, 49631, 104921, 100702, 104379, 104943, 104926, 104932, 104171, 74405, 3375, 33290, 3373, 33288, 25596, 79000, 25598, 32703, 108159, 104251, 110931, 108137, 108145, 104222, 108144, 104925, 104224, 108136, 101643, 108151, 108135, 108153, 102690, 105528, 105511, 2318, 72476, 71451, 35739, 82147, 86129, 85570, 85477, 26651, 32724, 43517, 36342, 3450, 500, 45557, 45556, 3364, 3446, 3035, 2151, 5768, 5752, 3362, 92824, 36323, 3359, 32124, 93635, 88785, 94063, 94064, 93731, 32786, 66687, 3258, 31728, 31601, 90249, 80837, 5769, 32706, 42906, 1006, 5770, 11415, 37338, 99817, 1387, 983, 104727, 380, 35382, 90255, 1137, 95102, 26365, 87919, 78130, 31809, 32565, 80838, 70201, 70903, 33161, 33166, 6297, 78193, 100693, 33618, 5526, 3257, 33163, 33164, 5086, 42279, 33559, 109774, 17200, 30098, 72948, 3237, 3269, 25613, 75080, 26378, 25644, 71622, 15505, 35704, 26376, 26335, 25616, 28152, 28145, 80839, 69196, 2428, 1386, 99812, 65236, 65229, 65450, 74072, 66706, 17250, 4469, 12923, 20545, 14499, 17703, 17697, 25878, 25608, 29834, 26321, 29835, 14431, 110175, 17717, 46026, 25609, 86028, 37372, 33468, 33518, 1437, 1436, 1450, 1431, 36213, 5545, 5444, 90312, 118523, 99814, 74272, 123803, 123802, 104845, 88570, 90334, 37647, 24980, 111677, 1425, 90332, 19744, 90360, 17694, 17696, 80594, 82324, 83233, 112157, 72181, 112000, 72186, 1060, 60713, 60711, 28067, 46929, 48000, 2974, 3133, 51453, 72178, 65453, 45874, 45875, 45870, 99401, 117753, 120831, 90254, 82852, 30758, 87011, 91079, 91081, 91080, 82843, 65631, 33520, 1444, 79892, 79889, 84390, 2357, 2358, 35074, 33162, 1525, 93633, 4051, 3886, 36758, 90339, 107063, 24778, 90357, 115077, 86114, 86138, 82844, 28296, 82846, 82845, 27159, 27161, 27158, 27160, 27157, 25880, 65164, 109889, 93636, 1595, 27963, 93634, 76023, 27965, 27949, 27944, 69097, 69094, 67195, 65834, 63776, 61947, 80319, 67193, 72985, 25604, 2177, 25622, 26390, 67402, 61955, 38491, 85463, 1070, 87892, 90148, 90149, 8550, 90814, 8714, 90999, 87519, 88619, 7763, 29756, 24916, 71171, 79042, 83933, 83929, 84083, 83932, 79040, 52520, 83643, 88705, 84013, 85053, 36894, 23672, 69528, 36893, 47056, 93725, 33974, 33977, 88704, 87594, 41326, 81201, 86176, 86175, 79043, 79406, 85339, 79404, 79041, 83934, 118532, 72947, 36883, 66838, 29735, 27449, 25621, 65226, 85042, 3058, 72952, 27958, 25602, 26068, 64782, 74437, 26310, 86307, 85041, 65663, 70701, 27962, 27956, 65174, 25594, 25655, 65234, 65172, 82103, 81202, 81282, 88697, 86306, 64814, 86308, 65083, 26311, 68004, 65253, 27999, 106884, 81203, 86311, 65256, 28149, 28153, 28150, 28154, 68022, 68019, 68021, 68020, 66652, 25610, 25635, 26070, 65171, 72114, 81283, 78223, 86312, 82100, 86309, 26075, 25645, 36499, 88739, 27782, 28433, 63050, 82003, 83292, 64016, 81198, 81269, 75344, 97943, 30415, 45425, 25648, 25619, 25618, 56737, 73438, 69151, 69155, 65357, 65424, 60156, 52659, 20833, 45437, 40674, 27882, 11709, 91289, 27486, 25650, 25620, 25611, 72956, 26413, 70532, 63051, 80475, 69682, 35280, 64586, 26339, 69780, 28146, 28163, 72235, 68480, 73730, 65345, 74532, 65106, 26442, 26300, 26437, 26347, 32991, 35818, 72465, 48278, 71596, 65242, 63038, 65257, 18052, 26330, 80015, 68059, 52277, 57554, 82909, 82000, 37510, 34180, 49070, 66696, 72945, 25882, 71597, 28144, 28148, 75912, 87579, 81861, 68483, 68484, 26396, 78398, 71942, 72078, 65451, 65173, 65477, 93517, 72074, 72478, 41887, 30302, 1743, 94902, 3382, 1745, 95028, 123806, 72805, 72794, 3377, 3379, 3378, 3380, 3381, 3638, 3370, 3453, 3641, 4944, 1741, 3369, 3447, 9255, 5407, 3361, 58265, 72809, 58677, 58462, 58369, 72791, 73052, 3376, 33285, 3360, 3368, 73050, 72781, 72803, 56716, 34208, 72800, 72779, 72787, 72783, 72765, 73051, 72804, 72796, 72793, 72799, 72807, 72802, 72786, 73054, 56567, 73053, 72789, 72784, 72795, 72792, 29310, 73121, 72778, 34207, 72808, 44315, 45692, 16812, 33274, 60896, 34222, 28212, 87440, 87473, 87450, 609, 33276, 33272, 33284, 33277, 3366, 33273, 55831, 81877, 81355, 27952, 704, 87435, 87474, 46130, 33286, 33287, 36990, 24978, 34973, 31805, 71628, 31807, 88929, 87441, 90313, 66644, 87461, 40021, 30245, 54959, 40077, 90301, 40025, 90257, 6271, 101255, 856, 5008, 5007, 5006, 5005, 5004, 5003, 1753, 857, 3356, 3363, 3455, 3384, 3353, 5009, 10789, 6378, 3358, 30500, 33266, 3454, 1748, 81779, 84559, 84554, 87631, 93838, 93518, 28157, 87183, 88049, 88493, 41667, 79015, 82767, 25073, 85758, 77523, 26353, 78869, 84069, 58202, 76552, 88608, 88594, 41408, 55344, 86472, 82950, 85767, 88051, 60256, 85771, 86471, 53107, 74885, 90317, 21936, 109886, 99139, 99138, 82763, 82793, 87601, 90161, 77936, 87649, 77496, 87549, 52723, 80857, 83532, 76907, 83093, 85228, 87630, 82234, 33519, 80177, 87796, 87795, 78480, 84092, 82148, 80751, 88502, 76547, 88548, 81372, 87050, 87634, 86950, 27681, 87581, 87614, 77940, 41325, 87611, 87600, 84110, 77851, 76515, 84555, 84551, 83531, 83533, 82814, 88528, 86443, 84415, 82539, 88318, 88317, 88262, 84412, 87495, 85964, 86764, 82545, 229, 81345, 81363, 79970, 87648, 76871, 86640, 32778, 39631, 80893, 86763, 82813, 87613, 87612, 85536, 87599, 87713, 88690, 84557, 84544, 38801, 90788, 88609, 79969, 88612, 88606, 87053, 87647, 88825, 87422, 83521, 82995, 82026, 82025, 82024, 90661, 88264, 87790, 87794, 88614, 80754, 93865, 74793, 81194, 87793, 87792, 87788, 87780, 85962, 88604, 87791, 85963, 28047, 83812, 83664, 88610, 61205, 88605, 81807, 77698, 88607, 78631, 88615, 88611, 78482, 78472, 82538, 88271, 88613, 88152, 61206, 87797, 81321, 80752, 81166, 87583, 87584, 24052, 34450, 73128, 48527, 100500, 48526, 82725, 34555, 34841, 86338, 48528, 82816, 82713, 86688, 48525, 60779, 32937, 81261, 34842, 79475, 93436, 93420, 34421, 104833, 34568, 34567, 34593, 34693, 29968, 93434, 93429, 64304, 34694, 27164, 34843, 82732, 83225, 93418, 66298, 22602, 34695, 99374, 86336, 12677, 12676, 12675, 35250, 35249, 37725, 37723, 83227, 28300, 98009, 36170, 36169, 82748, 82820, 99513, 82896, 72239, 93422, 12679, 24877, 12680, 12672, 12671, 82726, 83226, 66245, 34566, 19217, 82819, 82803, 82746, 81424, 1328, 1327, 99460, 86393, 1329, 16883, 55989, 43497, 15918, 27682, 6295, 1004, 27657, 25607, 1669, 5777, 25791, 58842, 65101, 64048, 26074, 74087, 1924, 71088, 71017, 28147, 28156, 28161, 28162, 28160, 28155, 28159, 25595, 25674, 25673, 27955, 71019, 27954, 25605, 77656, 27960, 27616, 25807, 26440, 26441, 25806, 25983, 27915, 26307, 26299, 28151, 34635, 33542, 36907, 70773, 65714, 26073, 70638, 74200, 74199, 74194, 59729, 72344, 25041, 64759, 15180, 47999, 67043, 65975, 41568, 66672, 61971, 67760, 69542, 66159, 76630, 67016, 64939, 30869, 56704, 69790, 71943, 75130, 65252, 46697, 46696, 46694, 69926, 72104, 72103, 3585, 27448, 26394, 26071, 75302, 75301, 3714, 71599, 26072, 69149, 69156, 27720, 27287, 25955, 25875, 26395, 27822, 65412, 27592, 65371, 65355, 69627, 23337, 47997, 69575, 67808, 65422, 54441, 53093, 55376, 116640, 116639, 104840, 85459, 107470, 30312, 30313, 30314, 30316, 30315, 15237, 79071, 51098, 12678, 82765, 82781, 85460, 49781, 14612, 12673, 89771, 89772, 29028, 24164, 27685, 27684, 29396, 27687, 3314, 3315, 10569, 26067, 79068, 79069, 1381, 99807, 110184, 38418, 110606, 42389, 35499, 99458, 110605, 35500, 104841, 99430, 26069, 22743, 15471, 79070, 79554, 79553, 22750, 22746, 22745, 22744, 22740, 22739, 22873, 89419, 90197, 1480, 17514, 1484, 89777, 17241, 119124, 7117, 34157, 34156, 34154, 34155, 82779, 38134, 82768, 3606, 100444, 99385, 26770, 120334, 114935, 14530, 39733, 39732, 17689, 99821, 82773, 90341, 86800, 10578, 1368, 23574, 38421, 90326, 93401, 94739, 117719, 120823, 117713, 117714, 117716, 117712, 117720, 27627, 121435, 121434, 121401, 117774, 120820, 90338, 94062, 90358, 4602, 90302, 104836, 109887, 88927, 89342, 4231, 51000, 91736, 57830, 73565, 91739, 92620, 88701, 91702, 88928, 92619, 90742, 85427, 91698, 115742, 76222, 76336, 122745, 79320, 118998, 120104, 73864, 118855, 94060, 94239, 1498, 93404, 94237, 94238, 118343, 118193, 118995, 118994, 28143, 1500, 65163, 27799, 121240, 119429, 114775, 121365, 122066, 119735, 118853, 122065, 86801, 80554, 85714, 103812, 122444, 111755, 111756, 118849, 112494, 118247, 118846, 118233, 4072, 93403, 79401, 72013, 119905, 81326, 78378, 93358, 78384, 80904, 81328, 86223, 93402, 5082, 5549, 118854, 114026, 116506, 116509, 33735, 116208, 116283, 86891, 33733, 33736, 80338, 116187, 117313, 82334, 93360, 78383, 1765, 16624, 93359, 78386, 93361, 76339, 78387, 56815, 115411, 123791, 61872, 115487, 115419, 104498, 89785, 25375, 89786, 3292, 89933, 25777, 82891, 115464, 89932, 37874, 90104, 88689, 85790, 5073, 90201, 89931, 3010, 90207, 37884, 37879, 37878, 104187, 99421, 90208, 19803, 37883, 1491, 89930, 16910, 90206, 90209, 37881, 28302, 114558, 40024, 67053, 18930, 111078, 46209, 1494, 58478, 99415, 56857, 19619, 344, 99420, 87530, 99418, 1473, 1472, 12310, 89885, 57081, 2968, 58785, 99416, 59145, 5076, 83528, 83530, 81116, 24381, 3295, 2181, 99424, 99422, 110154, 110153, 14492, 99425, 3298, 3444, 3445, 99423, 93617, 1489, 99417, 93520, 93516, 87578, 54859, 77081, 76903, 119262, 112723, 80458, 112722, 112383, 38872, 19670, 1432, 1502, 104839, 134, 1433, 1443, 67624, 39637, 117042, 107716, 117045, 79064, 84262, 79382, 78195, 30223, 30221, 63719, 42409, 46458, 81204, 7991, 7992, 83236, 118255, 120454, 120451, 83545, 77188, 110176, 99615, 1447, 913, 1445, 1427, 83232, 1438, 5552, 5551, 1423, 1439, 1446, 90770, 36411, 36816, 36814, 99498, 36786, 36790, 2850, 85210, 88674, 33948, 37087, 34070, 39532, 99497, 83231, 14500, 44604, 77076, 35929, 83526, 38420, 8632, 38626, 19091, 15921, 10131, 1357, 58003, 116345, 114051, 116455, 116437, 116454, 114049, 114050, 70261, 85834, 38684, 38688, 99164, 38422, 39184, 38596, 99399, 38686, 38683, 38685, 2363, 114541, 115237, 118065, 116458, 117375, 117327, 77189, 87566, 81249, 90164, 87816, 3309, 5378, 4997, 6844, 99392, 5043, 26450, 3310, 3306, 3307, 82925, 82919, 34396, 719, 5570, 82928, 10477, 99390, 3311, 116204, 118230, 118709, 76902, 33088, 76913, 114416, 115750, 114408, 115734, 120592, 115733, 79774, 87588, 33740, 33838, 33839, 33497, 33496, 33494, 19598, 99393, 33495, 48989, 117340, 115755, 120368, 115740, 105241, 80524, 83767, 76071, 80525, 80523, 83854, 115739, 118563, 114423, 115771, 121438, 24806, 120227, 116491, 114421, 121414, 114941, 61036, 114809, 121325, 87669, 81418, 87771, 79847, 51197, 34107, 61024, 114302, 106698, 83698, 117387, 117394, 114422, 108917, 60927, 87515, 87742, 80063, 76792, 54354, 54237, 51200, 3609, 7137, 3605, 3604, 61023, 119918, 115743, 112727, 117326, 117329, 119962, 115018, 112188, 60924, 60926, 15012, 87732, 34340, 33191, 35545, 47711, 116832, 114529, 116259, 119921, 119920, 115010, 117374, 119714, 112728, 123261, 81086, 114511, 114512, 114510, 111509, 114531, 114537, 114772, 14996, 87739, 87746, 87512, 33194, 35544, 35538, 114052, 116269, 116652, 116833, 117371, 114412, 114528, 44820, 115772, 117373, 117370, 115735, 114530, 116448, 116157, 117372, 114418, 116449, 31424, 120662, 108918, 114536, 114533, 114538, 35044, 100995, 105126, 101054, 101048, 104860, 24698, 101985, 98973, 98818, 101986, 46126, 32173, 32170, 4366, 19017, 32171, 32172, 81246, 78824, 87748, 82453, 87376, 116492, 115747, 121213, 117538, 116447, 116390, 119889, 116158, 116160, 118127, 116490, 116159, 21999, 114268, 116446, 118033, 47467, 1072, 47980, 47710, 41281, 4558, 36620, 112189, 109358, 120664, 115745, 115746, 116469, 45873, 38459, 31174, 257, 46986, 87513, 116831, 111365, 43722, 43720, 42352, 45877, 39641, 32938, 2956, 100158, 91667, 2954, 116493, 115736, 116834, 117858, 112187, 118472, 49288, 43725, 43724, 42250, 109799, 100157, 38631, 117494, 117491, 117487, 114942, 117484, 35204, 117497, 57526, 53296, 54238, 116681, 115770, 99811, 34059, 26747, 108808, 124105, 12829, 51613, 54894, 94494, 34045, 18269, 30501, 9391, 99822, 42385, 83228, 99820, 34047, 110618, 99426, 99072, 4356, 78748, 76422, 87378, 80364, 79720, 87543, 86079, 82783, 76072, 81234, 80362, 85966, 80450, 73116, 78416, 87379, 85967, 81482, 77185, 77184, 78652, 81128, 78593, 77691, 82787, 15003, 81126, 80481, 64074, 87738, 87733, 79565, 87745, 707, 76052, 76054, 76047, 77686, 82399, 82397, 61527, 77410, 77694, 80451, 82577, 82398, 47243, 85968, 78159, 82777, 80258, 82784, 87375, 94612, 95253, 92385, 96637, 96331, 95258, 95325, 95042, 94469, 2141, 100150, 108455, 108456, 95464, 43717, 43723, 34336, 63522, 18054, 35540, 35539, 35537, 43721, 43719, 43718, 78345, 43726, 10008, 26741, 26748, 109888, 119062, 122995, 90303, 96084, 101418, 14589, 99815, 14616, 90242, 90315, 75973, 90243, 90321, 110620, 35498, 70992, 90366, 83765, 92464, 25423, 83764, 118596, 92463, 90133, 104198, 25436, 90245, 20988, 86332, 90130, 20985, 86333, 90129, 90246, 16238, 35504, 1313, 90244, 16235, 10732, 37023, 118543, 4601, 83248, 89937, 89935, 35237, 34184, 30413, 1390, 262, 80, 17721, 99808, 86650, 64781, 34185, 33700, 61911, 69982, 61907, 60791, 110069, 104334, 81849, 59272, 58618, 108156, 108155, 107779, 108142, 108147, 108146, 108141, 28227, 109472, 102137, 108045, 105787, 108157, 108148, 102808, 72253, 102138, 104209, 110432, 102140, 108915, 3608, 9133, 66213, 86735, 86651, 89159, 342, 86348, 85498, 86737, 86645, 85503, 85793, 86642, 85797, 78928, 85495, 85497, 86736, 86643, 86652, 85504, 85499, 85514, 85745, 85502, 85501, 85798, 85804, 1393, 47165, 5905, 99809, 4386, 35244, 87564, 110191, 110183, 82770, 33701, 17699, 34932, 12229, 17722, 17719, 99810, 35241, 1394, 99823, 7136, 37437, 37020, 31760, 38047, 6894, 1311, 93505, 901, 81476, 8848, 33699, 17701, 17720, 99452, 28048, 35242, 99818, 33698, 6839, 38398, 1366, 15470, 110583, 110614, 32936, 5705, 64307, 10589, 10472, 36598, 17700, 25256, 14554, 104253, 105401, 104206, 102693, 61908, 40075, 58380, 24964, 66292, 30257, 82890, 56590, 75343, 237, 84725, 81084, 113669, 111430, 102677, 104207, 108158, 38795, 69983, 64414, 31737, 108140, 110686, 64417, 69985, 9129, 64766, 33303, 37850, 108143, 104208, 105893, 106872, 104933, 104175, 110855, 110932, 14414, 1694, 104920, 81407, 86280, 86281, 55924, 60862, 55921, 55233, 104929, 121937, 4382, 4514, 49770, 110760, 24982, 110794, 89418, 14369, 106964, 21264, 35053, 82821, 99462, 14413, 99453, 1319, 14370, 89801, 1358, 82930, 35140, 35141, 8001, 99451, 34139, 82764, 111496, 36585, 73093, 79383, 109709, 1323, 37643, 106345, 110514, 40012, 34412, 35052, 107469, 25871, 36559, 36615, 99507, 34136, 8000, 92900, 35133, 35148, 37724, 29569, 5706, 35051, 31988, 34406, 36583, 110138, 22493, 106967, 110187, 37329, 37138, 82115, 35695, 1312, 1314, 1392, 3128, 34144, 116250, 8971, 34143, 83223, 34141, 5205, 37330, 1310, 1320, 1318, 4259, 37331, 37328, 4260, 31738, 16850, 118442, 104726, 111719, 83235, 22903, 127822, 69491, 89274, 80264, 79014, 25587, 981, 89287, 89747, 3285, 99381, 99379, 106966, 99185, 45881, 99383, 37311, 32928, 5446, 37310, 3167, 99186, 1477, 110234, 221, 338, 99391, 27261, 28507, 5081, 104842, 10591, 99389, 36656, 94706, 83108, 99193, 1486, 110242, 110231, 110173, 106965, 110111, 99496, 3302, 109492, 72724, 99187, 5080, 93590, 96326, 100187, 96325, 96329, 96330, 96332, 95529, 96587, 96714, 96744, 93598, 96642, 96086, 93584, 1544, 95081, 96591, 94472, 96328, 96614, 95260, 95948, 93232, 96625, 96196, 94449, 95286, 95511, 94613, 97029, 95252, 93216, 9018, 66210, 68169, 59610, 66377, 64294, 64029, 22769, 78867, 93234, 88149, 31159, 29281, 29280, 22778, 95660, 94020, 97879, 96281, 96712, 47166, 104924, 109761, 102777, 104922, 109849, 104934, 104451, 103508, 106911, 103055, 63703, 104927, 102202, 106903, 103479, 100197, 106945, 100847, 106788, 107026, 113531, 111423, 24746, 105894, 105600, 105601, 105602, 102940, 70287, 26375, 102647, 112292, 106449, 106946, 106489, 104931, 113479, 106494, 108926, 106481, 102746, 107700, 104947, 104939, 106901, 107025, 96559, 108418, 104323, 109141, 106487, 108433, 102365, 57521, 106905, 107010, 109442, 109473, 103825, 103828, 34533, 106416, 106902, 104308, 106426, 106367, 101210, 39211, 105218, 110235, 110344, 104133, 117262, 115766, 106565, 106646, 104923, 116648, 92146, 106647, 107024, 104928, 108452, 104178, 104930, 54897, 32791, 36671, 3519, 6308, 12230, 4353, 4343, 32789, 16847, 4372, 4388, 7036, 87407, 4369, 1868, 4365, 4371, 4389, 4292, 32977, 32976, 7102, 4569, 20995, 42509, 10747, 4364, 9352, 4377, 11375, 4368, 4376, 4373, 3027, 7511, 1206, 36584, 2732, 4515, 1560, 193, 1959, 171, 53295, 53294, 58623, 54895, 53293, 54896, 29886, 83982, 86639, 83985, 79380, 42872, 78471, 2176, 84284, 77532, 79065, 81291, 84072, 77466, 81286, 86026, 86742, 86027, 84504, 84075, 83983, 86025, 78196, 83984, 84328, 84529, 79067, 84073, 83892, 30222, 84327, 83893, 82547, 81869, 79373, 87361, 83850, 87533, 81491, 82085, 81840, 82325, 30272, 88069, 87639, 79564, 73853, 82342, 81832, 81854, 81838, 81885, 81870, 81884, 81906, 81649, 25502, 81509, 86219, 81846, 85906, 87363, 81843, 82335, 80740, 77692, 81836, 82336, 75972, 81855, 87360, 79947, 81098, 81860, 81859, 82142, 81912, 80925, 81865, 67214, 81651, 88068, 85218, 82337, 41199, 44816, 86679, 81863, 81652, 87781, 81911, 89907, 77065, 81650, 82353, 87592, 87591, 20923, 120395, 26740, 76889);
UPDATE `creature_model_info` SET `CombatReach`=10.80000019073486328, `VerifiedBuild`=61265 WHERE `DisplayID`=115721;
UPDATE `creature_model_info` SET `BoundingRadius`=0.683102548122406005, `CombatReach`=0.875, `VerifiedBuild`=61265 WHERE `DisplayID`=115109;
UPDATE `creature_model_info` SET `BoundingRadius`=0.212530314922332763, `CombatReach`=0.366666674613952636, `VerifiedBuild`=61265 WHERE `DisplayID`=118868;
UPDATE `creature_model_info` SET `BoundingRadius`=0.405739665031433105, `CombatReach`=0.699999988079071044, `VerifiedBuild`=61265 WHERE `DisplayID`=119876;
UPDATE `creature_model_info` SET `BoundingRadius`=7, `CombatReach`=10, `VerifiedBuild`=61265 WHERE `DisplayID`=58183;
UPDATE `creature_model_info` SET `BoundingRadius`=6.026553153991699218, `CombatReach`=8, `VerifiedBuild`=61265 WHERE `DisplayID`=96784;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `VerifiedBuild`=61265 WHERE `DisplayID`=100942;
UPDATE `creature_model_info` SET `BoundingRadius`=0.375, `CombatReach`=0.625, `VerifiedBuild`=61265 WHERE `DisplayID`=115963;
UPDATE `creature_model_info` SET `BoundingRadius`=0.420002311468124389, `VerifiedBuild`=61265 WHERE `DisplayID` IN (114832, 114833);
UPDATE `creature_model_info` SET `BoundingRadius`=0.727682173252105712, `VerifiedBuild`=61265 WHERE `DisplayID`=114619;
UPDATE `creature_model_info` SET `BoundingRadius`=1.83896946907043457, `CombatReach`=2, `VerifiedBuild`=61265 WHERE `DisplayID`=116612;
UPDATE `creature_model_info` SET `BoundingRadius`=1.25, `CombatReach`=2.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (85199, 43935);
UPDATE `creature_model_info` SET `BoundingRadius`=1.633910298347473144, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=114509;
UPDATE `creature_model_info` SET `BoundingRadius`=0.280177772045135498, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=81387;
UPDATE `creature_model_info` SET `BoundingRadius`=2.771951198577880859, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID` IN (32406, 32407);
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599251747131347, `CombatReach`=1.75, `VerifiedBuild`=61265 WHERE `DisplayID`=114816;
UPDATE `creature_model_info` SET `BoundingRadius`=1.081180095672607421, `CombatReach`=1.10000002384185791, `VerifiedBuild`=61265 WHERE `DisplayID`=66717;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=0.25, `VerifiedBuild`=61265 WHERE `DisplayID`=71611;
UPDATE `creature_model_info` SET `BoundingRadius`=5.723157882690429687, `CombatReach`=5, `VerifiedBuild`=61265 WHERE `DisplayID`=95767;
UPDATE `creature_model_info` SET `BoundingRadius`=0.869742810726165771, `CombatReach`=1.20000004768371582, `VerifiedBuild`=61265 WHERE `DisplayID`=94908;
UPDATE `creature_model_info` SET `BoundingRadius`=0.940629899501800537, `CombatReach`=2.5, `VerifiedBuild`=61265 WHERE `DisplayID`=86799;
UPDATE `creature_model_info` SET `BoundingRadius`=1.469839215278625488, `CombatReach`=2.200000286102294921, `VerifiedBuild`=61265 WHERE `DisplayID`=78853;
UPDATE `creature_model_info` SET `BoundingRadius`=1.469839096069335937, `CombatReach`=2.200000286102294921, `VerifiedBuild`=61265 WHERE `DisplayID`=78650;
UPDATE `creature_model_info` SET `BoundingRadius`=0.421299993991851806, `CombatReach`=1.649999976158142089, `VerifiedBuild`=61265 WHERE `DisplayID`=64374;
UPDATE `creature_model_info` SET `BoundingRadius`=4.371407985687255859, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=67155;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (88829, 94912, 92734);
UPDATE `creature_model_info` SET `BoundingRadius`=0.579470038414001464, `VerifiedBuild`=61265 WHERE `DisplayID` IN (59014, 60964);
UPDATE `creature_model_info` SET `BoundingRadius`=1.973609089851379394, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=83645;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=29505;
UPDATE `creature_model_info` SET `CombatReach`=2.5, `VerifiedBuild`=61265 WHERE `DisplayID`=83052;
UPDATE `creature_model_info` SET `BoundingRadius`=1.62948763370513916, `VerifiedBuild`=61265 WHERE `DisplayID`=88158;
UPDATE `creature_model_info` SET `BoundingRadius`=1.075765132904052734, `CombatReach`=2, `VerifiedBuild`=61265 WHERE `DisplayID` IN (83617, 83610);
UPDATE `creature_model_info` SET `CombatReach`=2, `VerifiedBuild`=61265 WHERE `DisplayID` IN (83603, 89586, 116215);
UPDATE `creature_model_info` SET `BoundingRadius`=0.81474381685256958, `VerifiedBuild`=61265 WHERE `DisplayID`=88157;
UPDATE `creature_model_info` SET `BoundingRadius`=0.234999999403953552, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=21955;
UPDATE `creature_model_info` SET `BoundingRadius`=0.340000003576278686, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=84868;
UPDATE `creature_model_info` SET `BoundingRadius`=11.44631576538085937, `CombatReach`=11, `VerifiedBuild`=61265 WHERE `DisplayID`=42532;
UPDATE `creature_model_info` SET `BoundingRadius`=2.018417835235595703, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=47620;
UPDATE `creature_model_info` SET `BoundingRadius`=2.472550630569458007, `CombatReach`=2.5, `VerifiedBuild`=61265 WHERE `DisplayID`=839;
UPDATE `creature_model_info` SET `BoundingRadius`=0.174999997019767761, `CombatReach`=0.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (86531, 86530, 86532);
UPDATE `creature_model_info` SET `BoundingRadius`=13.45328330993652343, `CombatReach`=4, `VerifiedBuild`=61265 WHERE `DisplayID`=86694;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409618377685546, `VerifiedBuild`=61265 WHERE `DisplayID`=80898;
UPDATE `creature_model_info` SET `BoundingRadius`=8.290376663208007812, `CombatReach`=7, `VerifiedBuild`=61265 WHERE `DisplayID`=85567;
UPDATE `creature_model_info` SET `BoundingRadius`=10.29815196990966796, `CombatReach`=9, `VerifiedBuild`=61265 WHERE `DisplayID`=94163;
UPDATE `creature_model_info` SET `BoundingRadius`=0.629890918731689453, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=1534;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=80465;
UPDATE `creature_model_info` SET `BoundingRadius`=0.928049981594085693, `CombatReach`=1.724999904632568359, `VerifiedBuild`=61265 WHERE `DisplayID`=36851;
UPDATE `creature_model_info` SET `BoundingRadius`=2.997969865798950195, `CombatReach`=2.624999761581420898, `VerifiedBuild`=61265 WHERE `DisplayID`=31460;
UPDATE `creature_model_info` SET `BoundingRadius`=4.357944965362548828, `CombatReach`=8.75, `VerifiedBuild`=61265 WHERE `DisplayID`=55454;
UPDATE `creature_model_info` SET `BoundingRadius`=5.644835948944091796, `VerifiedBuild`=61265 WHERE `DisplayID` IN (79900, 81799);
UPDATE `creature_model_info` SET `BoundingRadius`=0.588740706443786621, `CombatReach`=0, `VerifiedBuild`=61265 WHERE `DisplayID`=68899;
UPDATE `creature_model_info` SET `BoundingRadius`=0.670859098434448242, `VerifiedBuild`=61265 WHERE `DisplayID`=107365;
UPDATE `creature_model_info` SET `BoundingRadius`=0.227499991655349731, `CombatReach`=0.649999976158142089, `VerifiedBuild`=61265 WHERE `DisplayID` IN (104050, 104047);
UPDATE `creature_model_info` SET `BoundingRadius`=1.211121082305908203, `VerifiedBuild`=61265 WHERE `DisplayID`=19139;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=61265 WHERE `DisplayID`=88407;
UPDATE `creature_model_info` SET `BoundingRadius`=3.978777408599853515, `CombatReach`=2, `VerifiedBuild`=61265 WHERE `DisplayID`=80474;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `VerifiedBuild`=61265 WHERE `DisplayID`=30211;
UPDATE `creature_model_info` SET `BoundingRadius`=1.60000002384185791, `CombatReach`=1.60000002384185791, `VerifiedBuild`=61265 WHERE `DisplayID`=75047;
UPDATE `creature_model_info` SET `BoundingRadius`=1.158940076828002929, `VerifiedBuild`=61265 WHERE `DisplayID` IN (52598, 96674, 52600, 62863);
UPDATE `creature_model_info` SET `BoundingRadius`=0.678850829601287841, `CombatReach`=1.60000002384185791, `VerifiedBuild`=61265 WHERE `DisplayID`=87760;
UPDATE `creature_model_info` SET `BoundingRadius`=0.927152097225189208, `VerifiedBuild`=61265 WHERE `DisplayID`=75814;
UPDATE `creature_model_info` SET `BoundingRadius`=0.708257257938385009, `VerifiedBuild`=61265 WHERE `DisplayID`=54854;
UPDATE `creature_model_info` SET `BoundingRadius`=1.60000002384185791, `VerifiedBuild`=61265 WHERE `DisplayID`=105588;
UPDATE `creature_model_info` SET `BoundingRadius`=0.217223197221755981, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=68729;
UPDATE `creature_model_info` SET `BoundingRadius`=0.666666626930236816, `VerifiedBuild`=61265 WHERE `DisplayID`=63870;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (93521, 93508, 89032, 89031, 89178, 89179, 89139, 84386, 93638, 86431, 84385, 93427, 85144);
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.499999880790710449, `VerifiedBuild`=61265 WHERE `DisplayID`=89034;
UPDATE `creature_model_info` SET `CombatReach`=13.5, `VerifiedBuild`=61265 WHERE `DisplayID`=119886;
UPDATE `creature_model_info` SET `BoundingRadius`=0.293149203062057495, `CombatReach`=0.400000005960464477, `VerifiedBuild`=61265 WHERE `DisplayID`=83641;
UPDATE `creature_model_info` SET `BoundingRadius`=0.828504681587219238, `CombatReach`=0.666666626930236816, `VerifiedBuild`=61265 WHERE `DisplayID` IN (117450, 117448, 117451);
UPDATE `creature_model_info` SET `CombatReach`=9, `VerifiedBuild`=61265 WHERE `DisplayID` IN (115731, 115729);
UPDATE `creature_model_info` SET `BoundingRadius`=0.919602870941162109, `CombatReach`=2.299999952316284179, `VerifiedBuild`=61265 WHERE `DisplayID`=105444;
UPDATE `creature_model_info` SET `BoundingRadius`=1.153696298599243164, `CombatReach`=3.5, `VerifiedBuild`=61265 WHERE `DisplayID`=92689;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3896104097366333, `VerifiedBuild`=61265 WHERE `DisplayID`=44453;
UPDATE `creature_model_info` SET `BoundingRadius`=1.179847955703735351, `CombatReach`=0, `VerifiedBuild`=61265 WHERE `DisplayID`=38749;
UPDATE `creature_model_info` SET `BoundingRadius`=1.049999952316284179, `CombatReach`=1.75, `VerifiedBuild`=61265 WHERE `DisplayID`=114624;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (89142, 89143, 89144, 70963, 93440, 86086);
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID` IN (85523, 92229);
UPDATE `creature_model_info` SET `BoundingRadius`=0.459742367267608642, `VerifiedBuild`=61265 WHERE `DisplayID`=116615;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID` IN (112387, 92232);
UPDATE `creature_model_info` SET `BoundingRadius`=1.072551846504211425, `CombatReach`=1.142857193946838378, `VerifiedBuild`=61265 WHERE `DisplayID`=78242;
UPDATE `creature_model_info` SET `BoundingRadius`=2.811197280883789062, `CombatReach`=4.285714149475097656, `VerifiedBuild`=61265 WHERE `DisplayID`=75593;
UPDATE `creature_model_info` SET `BoundingRadius`=0.344427824020385742, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=86480;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (89146, 89153, 89147, 89185, 89184, 89149, 89186, 88579, 93439, 93438);
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=61265 WHERE `DisplayID` IN (89030, 91043, 86649, 86648, 86647);
UPDATE `creature_model_info` SET `BoundingRadius`=1.973609209060668945, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=83647;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (89141, 84138, 84158);
UPDATE `creature_model_info` SET `BoundingRadius`=0.874500036239624023, `CombatReach`=1.65000009536743164, `VerifiedBuild`=61265 WHERE `DisplayID`=9951;
UPDATE `creature_model_info` SET `BoundingRadius`=0.873393952846527099, `VerifiedBuild`=61265 WHERE `DisplayID`=82792;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698715150356292724, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (89151, 88542, 84068, 92784, 84074, 86006, 86007);
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=89177;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `VerifiedBuild`=61265 WHERE `DisplayID` IN (88691, 44996, 92891, 93922);
UPDATE `creature_model_info` SET `BoundingRadius`=2.490811109542846679, `CombatReach`=2.75, `VerifiedBuild`=61265 WHERE `DisplayID` IN (77488, 77464);
UPDATE `creature_model_info` SET `BoundingRadius`=0.413480490446090698, `CombatReach`=0.200000002980232238, `VerifiedBuild`=61265 WHERE `DisplayID` IN (81217, 81216);
UPDATE `creature_model_info` SET `BoundingRadius`=2.590443611145019531, `CombatReach`=2.860000133514404296, `VerifiedBuild`=61265 WHERE `DisplayID`=81342;
UPDATE `creature_model_info` SET `BoundingRadius`=4.071453094482421875, `CombatReach`=5.800000190734863281, `VerifiedBuild`=61265 WHERE `DisplayID` IN (90724, 85193);
UPDATE `creature_model_info` SET `CombatReach`=24, `VerifiedBuild`=61265 WHERE `DisplayID`=29487;
UPDATE `creature_model_info` SET `BoundingRadius`=1.27500009536743164, `CombatReach`=1.06250011920928955, `VerifiedBuild`=61265 WHERE `DisplayID`=74051;
UPDATE `creature_model_info` SET `BoundingRadius`=1.815921545028686523, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=92905;
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400016546249389, `CombatReach`=1.80000007152557373, `VerifiedBuild`=61265 WHERE `DisplayID`=53720;
UPDATE `creature_model_info` SET `BoundingRadius`=0.521065711975097656, `CombatReach`=0.738775491714477539, `VerifiedBuild`=61265 WHERE `DisplayID`=54409;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305555999279022216, `CombatReach`=3, `VerifiedBuild`=61265 WHERE `DisplayID`=85055;
UPDATE `creature_model_info` SET `CombatReach`=3.60000014305114746, `VerifiedBuild`=61265 WHERE `DisplayID`=106906;
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=61265 WHERE `DisplayID`=2330;
UPDATE `creature_model_info` SET `BoundingRadius`=0.546643853187561035, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (85836, 88700);
UPDATE `creature_model_info` SET `BoundingRadius`=1.182767391204833984, `VerifiedBuild`=61265 WHERE `DisplayID` IN (32585, 32474);
UPDATE `creature_model_info` SET `BoundingRadius`=1.281331300735473632, `VerifiedBuild`=61265 WHERE `DisplayID`=32584;
UPDATE `creature_model_info` SET `BoundingRadius`=1.525103449821472167, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=85008;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305555999279022216, `CombatReach`=18, `VerifiedBuild`=61265 WHERE `DisplayID`=86691;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305555999279022216, `CombatReach`=7, `VerifiedBuild`=61265 WHERE `DisplayID`=88448;
UPDATE `creature_model_info` SET `BoundingRadius`=0.658634364604949951, `CombatReach`=1.20000004768371582, `VerifiedBuild`=61265 WHERE `DisplayID`=92568;
UPDATE `creature_model_info` SET `BoundingRadius`=58.80276107788085937, `CombatReach`=20, `VerifiedBuild`=61265 WHERE `DisplayID`=87990;
UPDATE `creature_model_info` SET `BoundingRadius`=1.991492748260498046, `VerifiedBuild`=61265 WHERE `DisplayID`=88494;
UPDATE `creature_model_info` SET `BoundingRadius`=0.207999989390373229, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (84384, 86436);
UPDATE `creature_model_info` SET `BoundingRadius`=4.211787700653076171, `CombatReach`=6, `VerifiedBuild`=61265 WHERE `DisplayID`=67541;
UPDATE `creature_model_info` SET `BoundingRadius`=3.429596900939941406, `VerifiedBuild`=61265 WHERE `DisplayID`=33826;
UPDATE `creature_model_info` SET `BoundingRadius`=2.290692567825317382, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=91910;
UPDATE `creature_model_info` SET `BoundingRadius`=4.653089523315429687, `CombatReach`=6.628571987152099609, `VerifiedBuild`=61265 WHERE `DisplayID`=90723;
UPDATE `creature_model_info` SET `BoundingRadius`=0.51841282844543457, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=91810;
UPDATE `creature_model_info` SET `BoundingRadius`=0.973670184612274169, `CombatReach`=2, `VerifiedBuild`=61265 WHERE `DisplayID`=92569;
UPDATE `creature_model_info` SET `BoundingRadius`=0.662404596805572509, `CombatReach`=1.20000004768371582, `VerifiedBuild`=61265 WHERE `DisplayID`=94911;
UPDATE `creature_model_info` SET `BoundingRadius`=1.46478128433227539, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID` IN (92609, 92608);
UPDATE `creature_model_info` SET `CombatReach`=10.5, `VerifiedBuild`=61265 WHERE `DisplayID`=73028;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698715090751647949, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (84067, 85456);
UPDATE `creature_model_info` SET `BoundingRadius`=1.545806407928466796, `VerifiedBuild`=61265 WHERE `DisplayID`=84891;
UPDATE `creature_model_info` SET `BoundingRadius`=0.795000016689300537, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=918;
UPDATE `creature_model_info` SET `BoundingRadius`=0.851515471935272216, `VerifiedBuild`=61265 WHERE `DisplayID`=72174;
UPDATE `creature_model_info` SET `BoundingRadius`=1.298434972763061523, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=94246;
UPDATE `creature_model_info` SET `BoundingRadius`=0.260250002145767211, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=94242;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999964475631713, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (79079, 84136);
UPDATE `creature_model_info` SET `BoundingRadius`=6.022189617156982421, `CombatReach`=10, `VerifiedBuild`=61265 WHERE `DisplayID`=76655;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288985729217529296, `CombatReach`=2, `VerifiedBuild`=61265 WHERE `DisplayID` IN (85426, 85922);
UPDATE `creature_model_info` SET `BoundingRadius`=0.582650959491729736, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=84382;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=92735;
UPDATE `creature_model_info` SET `BoundingRadius`=0.782324552536010742, `VerifiedBuild`=61265 WHERE `DisplayID`=75898;
UPDATE `creature_model_info` SET `BoundingRadius`=0.43016788363456726, `VerifiedBuild`=61265 WHERE `DisplayID`=79506;
UPDATE `creature_model_info` SET `BoundingRadius`=2.174365997314453125, `CombatReach`=2, `VerifiedBuild`=61265 WHERE `DisplayID`=75493;
UPDATE `creature_model_info` SET `BoundingRadius`=0.15328998863697052, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=86231;
UPDATE `creature_model_info` SET `BoundingRadius`=1.333333373069763183, `VerifiedBuild`=61265 WHERE `DisplayID`=76046;
UPDATE `creature_model_info` SET `BoundingRadius`=0.954134941101074218, `VerifiedBuild`=61265 WHERE `DisplayID`=80553;
UPDATE `creature_model_info` SET `BoundingRadius`=0.14490702748298645, `CombatReach`=0.25, `VerifiedBuild`=61265 WHERE `DisplayID`=118863;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `VerifiedBuild`=61265 WHERE `DisplayID`=87182;
UPDATE `creature_model_info` SET `BoundingRadius`=0.297600001096725463, `CombatReach`=1.199999928474426269, `VerifiedBuild`=61265 WHERE `DisplayID`=87944;
UPDATE `creature_model_info` SET `BoundingRadius`=0.427800029516220092, `CombatReach`=1.72500002384185791, `VerifiedBuild`=61265 WHERE `DisplayID` IN (83861, 83860);
UPDATE `creature_model_info` SET `BoundingRadius`=0.816432178020477294, `VerifiedBuild`=61265 WHERE `DisplayID`=98816;
UPDATE `creature_model_info` SET `BoundingRadius`=2.671835660934448242, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=98838;
UPDATE `creature_model_info` SET `BoundingRadius`=0.400000005960464477, `VerifiedBuild`=61265 WHERE `DisplayID`=105286;
UPDATE `creature_model_info` SET `BoundingRadius`=3.489071846008300781, `VerifiedBuild`=61265 WHERE `DisplayID`=101783;
UPDATE `creature_model_info` SET `BoundingRadius`=1.553661823272705078, `VerifiedBuild`=61265 WHERE `DisplayID` IN (103751, 103756);
UPDATE `creature_model_info` SET `BoundingRadius`=0.271400004625320434, `CombatReach`=1.72500002384185791, `VerifiedBuild`=61265 WHERE `DisplayID` IN (83858, 83859);
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.499999880790710449, `VerifiedBuild`=61265 WHERE `DisplayID` IN (89086, 89367, 89085, 88839, 88890);
UPDATE `creature_model_info` SET `BoundingRadius`=0.423275411128997802, `CombatReach`=1.574999928474426269, `VerifiedBuild`=61265 WHERE `DisplayID` IN (83830, 83831);
UPDATE `creature_model_info` SET `BoundingRadius`=1.034090876579284667, `CombatReach`=2.954545259475708007, `VerifiedBuild`=61265 WHERE `DisplayID`=86529;
UPDATE `creature_model_info` SET `BoundingRadius`=0.667549669742584228, `CombatReach`=1.574999928474426269, `VerifiedBuild`=61265 WHERE `DisplayID` IN (83833, 83832);
UPDATE `creature_model_info` SET `BoundingRadius`=1.205108404159545898, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID` IN (98194, 105361, 96624);
UPDATE `creature_model_info` SET `BoundingRadius`=0.699441432952880859, `CombatReach`=1.25, `VerifiedBuild`=61265 WHERE `DisplayID`=97425;
UPDATE `creature_model_info` SET `BoundingRadius`=1.213969588279724121, `VerifiedBuild`=61265 WHERE `DisplayID`=91484;
UPDATE `creature_model_info` SET `BoundingRadius`=1.724869012832641601, `VerifiedBuild`=61265 WHERE `DisplayID`=64762;
UPDATE `creature_model_info` SET `BoundingRadius`=1.026380538940429687, `VerifiedBuild`=61265 WHERE `DisplayID`=99478;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.649999976158142089, `VerifiedBuild`=61265 WHERE `DisplayID`=110071;
UPDATE `creature_model_info` SET `BoundingRadius`=1.805753946304321289, `VerifiedBuild`=61265 WHERE `DisplayID`=68157;
UPDATE `creature_model_info` SET `BoundingRadius`=0.171312570571899414, `CombatReach`=0.150000005960464477, `VerifiedBuild`=61265 WHERE `DisplayID` IN (15468, 15467);
UPDATE `creature_model_info` SET `BoundingRadius`=0.060000002384185791, `VerifiedBuild`=61265 WHERE `DisplayID`=79541;
UPDATE `creature_model_info` SET `BoundingRadius`=1.981377959251403808, `VerifiedBuild`=61265 WHERE `DisplayID`=68258;
UPDATE `creature_model_info` SET `BoundingRadius`=0.393504679203033447, `CombatReach`=3, `VerifiedBuild`=61265 WHERE `DisplayID`=104789;
UPDATE `creature_model_info` SET `BoundingRadius`=1.100270390510559082, `CombatReach`=2.25, `VerifiedBuild`=61265 WHERE `DisplayID`=97006;
UPDATE `creature_model_info` SET `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=95466;
UPDATE `creature_model_info` SET `BoundingRadius`=1.495757341384887695, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=90739;
UPDATE `creature_model_info` SET `BoundingRadius`=6.538715839385986328, `CombatReach`=7.5, `VerifiedBuild`=61265 WHERE `DisplayID`=90395;
UPDATE `creature_model_info` SET `BoundingRadius`=1.275775551795959472, `CombatReach`=3, `VerifiedBuild`=61265 WHERE `DisplayID`=90719;
UPDATE `creature_model_info` SET `BoundingRadius`=0.947728335857391357, `CombatReach`=2.5, `VerifiedBuild`=61265 WHERE `DisplayID`=94837;
UPDATE `creature_model_info` SET `BoundingRadius`=0.611999988555908203, `CombatReach`=3, `VerifiedBuild`=61265 WHERE `DisplayID`=97347;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306000024080276489, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=84137;
UPDATE `creature_model_info` SET `BoundingRadius`=0.756469249725341796, `CombatReach`=0.5, `VerifiedBuild`=61265 WHERE `DisplayID`=84821;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.50000011920928955, `VerifiedBuild`=61265 WHERE `DisplayID`=84160;
UPDATE `creature_model_info` SET `BoundingRadius`=0.346999973058700561, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=86085;
UPDATE `creature_model_info` SET `BoundingRadius`=0.975292801856994628, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=86349;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698715150356292724, `CombatReach`=1.50000011920928955, `VerifiedBuild`=61265 WHERE `DisplayID`=84134;
UPDATE `creature_model_info` SET `BoundingRadius`=0.280000001192092895, `CombatReach`=0.400000005960464477, `VerifiedBuild`=61265 WHERE `DisplayID`=35804;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=1, `VerifiedBuild`=61265 WHERE `DisplayID`=87368;
UPDATE `creature_model_info` SET `BoundingRadius`=1.590161681175231933, `CombatReach`=1.5, `VerifiedBuild`=61265 WHERE `DisplayID`=79566;

UPDATE `quest_template` SET `VerifiedBuild`=61265 WHERE `ID` IN (55892, 51043, 43638, 58781, 58438, 52936, 67026, 42783, 70413, 57968, 51466, 64432, 70529, 59902, 41091, 66896, 69987, 49043, 69942, 70021, 42788, 81811, 60533, 43721, 74988, 50619, 51806, 51038, 43615, 56016, 75657, 42062, 45806, 51890, 43091, 61220, 44012, 44291, 51462, 58422, 43347, 51239, 76251, 73080, 51763, 50866, 70639, 41267, 41686, 50571, 81816, 54353, 52780, 70582, 70620, 70564, 75573, 70559, 70545, 66890, 63858, 54355, 42820, 51118, 51048, 10794, 2996, 43475);
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=56022; -- Runelocked Chest
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=52929; -- Arathi Donations: Monelite Ore
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=53257; -- Arathi Donations: Versatile Kyanite
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=51782; -- Captain Razorspine
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=42806; -- DANGER: Fjorlag, the Grave's Chill
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=43432; -- WANTED: Normantis the Deposed
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=50870; -- G'Naat
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=54333; -- Darkshore Donations: Storm Silver Ore
UPDATE `quest_template` SET `FlagsEx`=0x0, `RewardChoiceItemID1`=224752, `RewardChoiceItemID2`=225771, `RewardChoiceItemID3`=225770, `RewardChoiceItemQuantity1`=2, `RewardChoiceItemQuantity2`=2, `RewardChoiceItemQuantity3`=2, `TimeAllowed`=3600, `RewardCurrencyQty1`=10, `VerifiedBuild`=61265 WHERE `ID`=83529; -- Hallowfall Fishing Derby
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=61265 WHERE `ID`=51287; -- Tol Dagor: Sealed Supplies
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=54334; -- Darkshore Donations: Electroshock Mount Motivator
UPDATE `quest_template` SET `FlagsEx`=0x0, `RewardChoiceItemID1`=224752, `RewardChoiceItemID2`=225771, `RewardChoiceItemID3`=225770, `RewardChoiceItemQuantity1`=2, `RewardChoiceItemQuantity2`=2, `RewardChoiceItemQuantity3`=2, `TimeAllowed`=3600, `RewardCurrencyQty1`=10, `VerifiedBuild`=61265 WHERE `ID`=83529; -- Hallowfall Fishing Derby
UPDATE `quest_template` SET `VerifiedBuild`=61122 WHERE `ID` IN (1364, 1244, 52950, 70413, 60533, 50519, 41428, 58438, 52229, 42783, 46505, 51117, 52953, 50867, 41700, 51659, 44289, 76251, 52169, 70545, 83532, 81816, 81650, 51042, 51462, 58422, 64432, 41844, 43175);
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61122 WHERE `ID`=51508; -- Vicemaul
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61122 WHERE `ID`=43426; -- WANTED: Brogozog
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61122 WHERE `ID`=44193; -- DANGER: Sea King Tidross
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=61122 WHERE `ID`=51296; -- Tol Dagor: The Overseer's Pride
UPDATE `quest_template` SET `VerifiedBuild`=60822 WHERE `ID` IN (42788, 52792, 52163, 50867, 69987, 51050, 52958, 46504, 43091, 59902, 43475, 70413, 66896);
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=50566; -- Lost Scroll
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=53008; -- Sage Wisdom
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51848; -- Captain Wintersail
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41610; -- Huge Cursed Queenfish
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=52928; -- Arathi Donations: Coarse Leather
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=60822 WHERE `ID`=53246; -- Arathi Donations: Monel-Hardened Stirrups
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=53255; -- Arathi Donations: Gloom Dust
UPDATE `quest_template` SET `VerifiedBuild`=60568 WHERE `ID` IN (1940, 6285, 1274, 8417, 13369, 10490, 1861, 66896, 81811, 52302, 50633, 56016, 50512, 51502, 51997, 5727, 3121, 7732);
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `Expansion`=-2, `VerifiedBuild`=60568 WHERE `ID`=1642; -- The Tome of Divinity
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60568 WHERE `ID`=1786; -- The Tome of Divinity
UPDATE `quest_template` SET `VerifiedBuild`=60490 WHERE `ID` IN (81811, 52302, 50633, 56016, 66896, 50512, 51502, 51997, 1940, 6285, 1861, 1274, 8417, 13369, 10490, 60533, 50619, 52454, 41090, 76251, 49043);
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=44013; -- WANTED: Guardian Thor'el
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=53253; -- Arathi Donations: Enchant Ring - Seal of Versatility
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=42991; -- DANGER: Runeseer Sigvid
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `Expansion`=-2, `VerifiedBuild`=60490 WHERE `ID`=1642; -- The Tome of Divinity
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60490 WHERE `ID`=1786; -- The Tome of Divinity
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=52199; -- Rum- Paaaage!
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=43759; -- Where's the Reef?
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=44024; -- WANTED: Shal'an
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=51468; -- Bonesquall
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=52928; -- Arathi Donations: Coarse Leather
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=53365; -- Arathi Donations: Battle Flag: Rallying Swiftness
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=52463; -- Haegol the Hammer
UPDATE `quest_template` SET `FlagsEx`=0x0, `RewardChoiceItemID1`=224752, `RewardChoiceItemID2`=225771, `RewardChoiceItemID3`=225770, `RewardChoiceItemQuantity1`=2, `RewardChoiceItemQuantity2`=2, `RewardChoiceItemQuantity3`=2, `TimeAllowed`=3600, `RewardCurrencyQty1`=10, `VerifiedBuild`=61265 WHERE `ID`=83529; -- Hallowfall Fishing Derby
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=63829; -- No One Floats Down Here
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=54338; -- Darkshore Donations: Thermo-Accelerated Plague Spreader
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61265 WHERE `ID`=51848; -- Captain Wintersail
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61122 WHERE `ID`=54692; -- Magister Crystalynn
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60568 WHERE `ID`=44013; -- WANTED: Guardian Thor'el
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60568 WHERE `ID`=53253; -- Arathi Donations: Enchant Ring - Seal of Versatility
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60568 WHERE `ID`=42991; -- DANGER: Runeseer Sigvid
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=56022; -- Runelocked Chest
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=44193; -- DANGER: Sea King Tidross
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=61265 WHERE `ID`=32; -- Rise of the Silithid
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=61265 WHERE `ID`=8254; -- Cenarion Aid
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=61265 WHERE `ID`=53247; -- Arathi Donations: Battle Flag: Spirit of Freedom
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=61265 WHERE `ID`=52929; -- Arathi Donations: Monelite Ore
UPDATE `quest_template` SET `FlagsEx`=0x0, `RewardChoiceItemID1`=224752, `RewardChoiceItemID2`=225771, `RewardChoiceItemID3`=225770, `RewardChoiceItemQuantity1`=2, `RewardChoiceItemQuantity2`=2, `RewardChoiceItemQuantity3`=2, `TimeAllowed`=3600, `RewardCurrencyQty1`=10, `VerifiedBuild`=61265 WHERE `ID`=83529; -- Hallowfall Fishing Derby
UPDATE `quest_template` SET `FlagsEx`=0x0, `RewardChoiceItemID1`=224752, `RewardChoiceItemID2`=225771, `RewardChoiceItemID3`=225770, `RewardChoiceItemQuantity1`=2, `RewardChoiceItemQuantity2`=2, `RewardChoiceItemQuantity3`=2, `TimeAllowed`=3600, `RewardCurrencyQty1`=10, `VerifiedBuild`=61265 WHERE `ID`=83529; -- Hallowfall Fishing Derby
UPDATE `quest_template` SET `VerifiedBuild`=61188 WHERE `ID` IN (812, 827, 26951, 70410, 51806, 52458, 46505, 53983, 70071, 58661, 54468, 56550, 52953, 42062, 70529, 44293, 41844, 51850, 43475, 52169);
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61188 WHERE `ID`=46161; -- Felcaller Thalezra
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61188 WHERE `ID`=51886; -- Pinku'shon
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61188 WHERE `ID`=44113; -- DANGER: Achronos
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61188 WHERE `ID`=43722; -- Sacred Bones
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61122 WHERE `ID`=51977; -- Sabertron
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=61122 WHERE `ID`=44027; -- WANTED: Magister Phaedris
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60568 WHERE `ID`=8254; -- Cenarion Aid
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=54332; -- Darkshore Donations: Star Moss
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=54342; -- Darkshore Donations: Potion of Bursting Blood
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=54337; -- Darkshore Donations: Umbra Shard
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=54340; -- Darkshore Donations: Enchant Ring - Seal of Haste
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=54335; -- Darkshore Donations: Unstable Temporal Time Shifter
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60490 WHERE `ID`=53248; -- Arathi Donations: Battle Flag: Phalanx Defense


UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=254703; -- 254703
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=436523; -- 436523
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=255097; -- 255097

UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=255436; -- 255436
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=255470; -- 255470
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=256078; -- 256078
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=256446; -- 256446
UPDATE `quest_objectives` SET `VerifiedBuild`=60568 WHERE `ID`=256997; -- 256997
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=293571; -- 293571
UPDATE `quest_objectives` SET `VerifiedBuild`=60568 WHERE `ID`=258892; -- 258892
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=259049; -- 259049
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=405418; -- 405418
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=405419; -- 405419
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=405420; -- 405420
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=405421; -- 405421
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=405422; -- 405422
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=405426; -- 405426
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=405433; -- 405433
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=332914; -- 332914
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=332921; -- 332921
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=333107; -- 333107
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=333125; -- 333125
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405867; -- 405867
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405868; -- 405868
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405869; -- 405869
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405870; -- 405870
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405871; -- 405871
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405872; -- 405872
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405873; -- 405873
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405874; -- 405874
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405875; -- 405875
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405876; -- 405876
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=405877; -- 405877
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=333367; -- 333367
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=333390; -- 333390
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=334129; -- 334129
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=334133; -- 334133
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=334576; -- 334576
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=334580; -- 334580
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=334581; -- 334581
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=334588; -- 334588
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=334783; -- 334783
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=334785; -- 334785
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=335229; -- 335229
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=335304; -- 335304
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=335305; -- 335305
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=335342; -- 335342
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=335343; -- 335343
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=335945; -- 335945
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=336039; -- 336039
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=336640; -- 336640
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=337078; -- 337078
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=337147; -- 337147
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=337158; -- 337158
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=337374; -- 337374
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=337378; -- 337378
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=337384; -- 337384
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=337450; -- 337450
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=337640; -- 337640
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=337710; -- 337710
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=337711; -- 337711
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=337811; -- 337811
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=337863; -- 337863
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=338211; -- 338211
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=338312; -- 338312
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=338353; -- 338353
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=338354; -- 338354
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=338355; -- 338355
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=338417; -- 338417
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=338418; -- 338418
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=338684; -- 338684
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=338696; -- 338696
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=339022; -- 339022
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=339023; -- 339023
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=339033; -- 339033
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=339034; -- 339034
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=339046; -- 339046
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=448580; -- 448580
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=448667; -- 448667
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=448846; -- 448846
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=339789; -- 339789
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=339790; -- 339790
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=448853; -- 448853
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=339849; -- 339849
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=340110; -- 340110
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=340111; -- 340111
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=340112; -- 340112
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=340278; -- 340278
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=340279; -- 340279
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=340303; -- 340303
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=340304; -- 340304
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=340305; -- 340305
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=340306; -- 340306
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=340308; -- 340308
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=340378; -- 340378
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=340395; -- 340395
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=340559; -- 340559
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=340560; -- 340560
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=340561; -- 340561
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=340562; -- 340562
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=340563; -- 340563
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=340995; -- 340995
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=340996; -- 340996
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=340997; -- 340997
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=341004; -- 341004
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=341006; -- 341006
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=341008; -- 341008
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=341296; -- 341296
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=341772; -- 341772
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=451134; -- 451134
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=451135; -- 451135
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=451136; -- 451136
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=451143; -- 451143
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=451144; -- 451144
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=451145; -- 451145
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=273866; -- 273866
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=419907; -- 419907
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=420017; -- 420017
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=420935; -- 420935
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=420936; -- 420936
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=421009; -- 421009
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=421118; -- 421118
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=421119; -- 421119
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=421120; -- 421120
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=421121; -- 421121
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=421122; -- 421122
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=386960; -- 386960
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=386962; -- 386962
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=386964; -- 386964
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=386966; -- 386966
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=386970; -- 386970
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=386972; -- 386972
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=386976; -- 386976
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=386980; -- 386980
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=387247; -- 387247
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=388023; -- 388023
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=388729; -- 388729
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=389849; -- 389849
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=390062; -- 390062
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=390073; -- 390073
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=281823; -- 281823
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=281824; -- 281824
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=281825; -- 281825
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=281826; -- 281826
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=282147; -- 282147
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=282462; -- 282462
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=282463; -- 282463
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=282565; -- 282565
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=282653; -- 282653
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=282696; -- 282696
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=428311; -- 428311
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=428332; -- 428332
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=428333; -- 428333
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=428781; -- 428781
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=428782; -- 428782
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=428783; -- 428783
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=428784; -- 428784
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=283479; -- 283479
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=429598; -- 429598
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=429821; -- 429821
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=429879; -- 429879
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=284740; -- 284740
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=284741; -- 284741
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=284751; -- 284751
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=284752; -- 284752
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=393812; -- 393812
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=284781; -- 284781
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=284806; -- 284806
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=430401; -- 430401
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=430404; -- 430404
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=285000; -- 285000
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=430583; -- 430583
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=394233; -- 394233
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=430603; -- 430603
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=430611; -- 430611
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=430619; -- 430619
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=430630; -- 430630
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=285254; -- 285254
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=285260; -- 285260
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=430674; -- 430674
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=430750; -- 430750
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=285552; -- 285552
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=430965; -- 430965
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=430966; -- 430966
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=430967; -- 430967
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=285703; -- 285703
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=285704; -- 285704
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=431129; -- 431129
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=431130; -- 431130
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=431131; -- 431131
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=431132; -- 431132
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=431133; -- 431133
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=431134; -- 431134
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=431135; -- 431135
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=285760; -- 285760
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=394945; -- 394945
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=286110; -- 286110
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=286112; -- 286112
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=286125; -- 286125
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=286128; -- 286128
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=286286; -- 286286
UPDATE `quest_objectives` SET `VerifiedBuild`=60490 WHERE `ID`=286374; -- 286374
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=286513; -- 286513
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=286527; -- 286527
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=286783; -- 286783
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=432904; -- 432904
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=251742; -- 251742
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=397201; -- 397201
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=288641; -- 288641
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=288642; -- 288642
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=288643; -- 288643
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=288644; -- 288644
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=289008; -- 289008
UPDATE `quest_objectives` SET `VerifiedBuild`=60822 WHERE `ID`=289321; -- 289321
UPDATE `quest_objectives` SET `VerifiedBuild`=61122 WHERE `ID`=289322; -- 289322
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=435623; -- 435623
UPDATE `quest_objectives` SET `VerifiedBuild`=61265 WHERE `ID`=435706; -- 435706
UPDATE `quest_objectives` SET `VerifiedBuild`=61188 WHERE `ID`=254198; -- 254198


UPDATE `quest_visual_effect` SET `VerifiedBuild`=61265 WHERE (`ID`=390073 AND `Index`=0) OR (`ID`=285578 AND `Index`=0) OR (`ID`=285577 AND `Index`=0) OR (`ID`=394945 AND `Index` IN (14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)) OR (`ID`=394286 AND `Index` IN (2,1,0)) OR (`ID`=394285 AND `Index` IN (2,1,0)) OR (`ID`=284741 AND `Index`=0) OR (`ID`=420936 AND `Index`=0) OR (`ID`=421009 AND `Index`=0) OR (`ID`=284781 AND `Index`=0) OR (`ID`=428333 AND `Index`=0) OR (`ID`=428332 AND `Index`=0) OR (`ID`=429598 AND `Index` IN (1,0)) OR (`ID`=430205 AND `Index`=0) OR (`ID`=429670 AND `Index`=0) OR (`ID`=284752 AND `Index`=0) OR (`ID`=284751 AND `Index`=0) OR (`ID`=434674 AND `Index`=0) OR (`ID`=434673 AND `Index`=0) OR (`ID`=333367 AND `Index`=0) OR (`ID`=335305 AND `Index`=0) OR (`ID`=390062 AND `Index`=0) OR (`ID`=435706 AND `Index` IN (3,2,1,0)) OR (`ID`=288644 AND `Index`=0) OR (`ID`=288643 AND `Index`=0) OR (`ID`=288642 AND `Index`=0) OR (`ID`=288641 AND `Index` IN (1,0)) OR (`ID`=285037 AND `Index`=0) OR (`ID`=405418 AND `Index` IN (4,3,2,1,0)) OR (`ID`=405426 AND `Index` IN (1,0)) OR (`ID`=335976 AND `Index`=0) OR (`ID`=338355 AND `Index`=0) OR (`ID`=285223 AND `Index`=0) OR (`ID`=337078 AND `Index`=0) OR (`ID`=333125 AND `Index`=0) OR (`ID`=339790 AND `Index`=0) OR (`ID`=428311 AND `Index` IN (73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)) OR (`ID`=419907 AND `Index` IN (3,2,1,0)) OR (`ID`=284806 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=61122 WHERE (`Index`=0 AND `ID` IN (336039,282463,282462,394286,394285,284741,289322,338211,286374,335343,448580,335976,420936,421009,285072)) OR (`Index`=2 AND `ID` IN (394286,394285)) OR (`Index`=1 AND `ID` IN (394286,394285,448580));
UPDATE `quest_visual_effect` SET `VerifiedBuild`=60822 WHERE (`Index`=0 AND `ID` IN (284752,284751,338312,333107,429598,289321,285037,428333,428332)) OR (`Index`=1 AND `ID`=429598);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=60568 WHERE (`Index`=0 AND `ID` IN (428333,428332,338696,338684,333390,390062,393812,340112,340111,340110,337863,337811,337711,337710,285000)) OR (`Index`=2 AND `ID`=333390) OR (`Index`=1 AND `ID`=333390);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=60490 WHERE (`Index`=0 AND `ID` IN (338696,338684,333390,390062,428333,428332,393812,340112,340111,340110,337863,337811,337711,337710,285000,390073,333367,339023,339022,281824,286374)) OR (`Index`=2 AND `ID`=333390) OR (`Index`=1 AND `ID`=333390);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=61188 WHERE (`Index`=0 AND `ID` IN (339034,339033,289322,386631,385354,429821,429879,387247,391145,337384,338211,286286)) OR (`Index`=2 AND `ID`=391145) OR (`Index`=1 AND `ID`=391145);

DELETE FROM `quest_treasure_pickers` WHERE (`QuestID`=81793 AND `TreasurePickerID`=3873);
INSERT INTO `quest_treasure_pickers` (`QuestID`, `TreasurePickerID`, `OrderIndex`) VALUES
(81793, 3873, 2); -- Sparks of War: Isle of Dorn


DELETE FROM `gameobject_template` WHERE `entry` IN (527088 /*Dastardly Banner*/, 516591 /*Food 4*/, 516590 /*Food 3*/, 516588 /*Food 1*/, 516519 /*Crate*/, 516517 /*Control Panel*/, 516515 /*Cola Can 01*/, 516509 /*Streetlight*/, 516508 /*BBQ*/, 516504 /*Take Out Box 02*/, 525637 /*11.1.5 - Dastardly Duos - Dornogal Hub Props*/, 525627 /*11.1.5 - Dastardly Duos - Dornogal Hub Props*/, 525607 /*11.1.5 - Dastardly Duos - Dornogal Hub Props*/, 525540 /*11.1.5 - Dastardly Duos - Dornogal Hub Props*/, 525515 /*11.1.5 - Dastardly Duos - Dornogal Hub Props*/, 516604 /*Rug 02*/, 516603 /*Rug 01*/, 516586 /*Table*/, 516578 /*Umbrella*/, 516516 /*Cola Can 03*/, 516512 /*Bean Bag Chair*/, 516503 /*Take Out Box 01*/, 499031 /*Corrupted Chest*/, 499022 /*Corrupted Chest*/, 493978 /*Stone Bench*/, 486011 /*Stone Bench*/, 494217 /*Stone Bench*/, 494175 /*Stone Bench*/, 494171 /*Stone Bench*/, 494160 /*Stone Bench*/, 494157 /*Stone Bench*/, 494141 /*Stone Bench*/, 494112 /*Stone Bench*/, 494107 /*Stone Bench*/, 494105 /*Stone Bench*/, 494104 /*Stone Bench*/, 494100 /*Stone Bench*/, 494083 /*Stone Bench*/, 494071 /*Stone Bench*/, 494065 /*Stone Bench*/, 494064 /*Stone Bench*/, 494029 /*Stone Bench*/, 494022 /*Stone Bench*/, 493995 /*Stone Bench*/, 493972 /*Stone Bench*/, 493952 /*Stone Bench*/, 493944 /*Stone Bench*/, 493924 /*Stone Bench*/, 493920 /*Stone Bench*/, 500274 /*Reclaimed Spoils Stash*/, 500098 /*Black Empire Cache*/, 500099 /*Black Empire Cache*/, 500100 /*Black Empire Cache*/, 494044 /*Bench*/, 499028 /*Corrupted Chest*/, 494082 /*Bench*/, 494239 /*Bench*/, 494225 /*Bench*/, 494015 /*Bench*/, 494008 /*Bench*/, 493998 /*Bench*/, 494099 /*Bench*/, 517349 /*Cursed Horseshoe*/, 494218 /*Cookpot*/, 527691 /*WANTED: Hogger!!*/, 516142 /*Ripped Note*/, 516146 /*Ripped Note*/, 517348 /*Cursed Horseshoe*/, 499029 /*Corrupted Chest*/, 527781 /*Post*/, 517350 /*Cursed Horseshoe*/, 499026 /*Corrupted Chest*/, 499038 /*Portal to Cathedral District*/, 517344 /*Cursed Horseshoe*/, 494237 /*Bench*/, 494143 /*Bench*/, 495367 /*Corrupted Chest*/, 523456 /*Trash*/, 523457 /*Trash*/, 494050 /*7.0 Stormwind - Lion's Rest - Phased WMO*/, 523452 /*Trash*/, 493974 /*Mailbox*/, 494167 /*Waters of Farseeing*/, 524737 /*11.0 Dungeon - Brewery - Boss 4 - Door - ML*/, 539206 /*Collision Object*/, 529919 /*Children's Week Baloon Wreath Stand*/, 529920 /*Children's Week Hanging Short Streamer*/, 529917 /*Balloon Cluster [DNT]*/, 529914 /*Murloc Toy*/, 529937 /*Wooden Alliance Shield Toy*/, 529934 /*Wooden Sword Toy*/, 529918 /*Children's Week Baloon Wreath (.3)*/, 531510 /*Children's Week Hanging Banner*/, 529931 /*Children's Week Crate*/, 529932 /*Children's Week Kite*/, 529913 /*Elekk Plush*/, 536474 /*Children's Week Toy Boat*/, 451388 /*Meeting Stone*/, 385544 /*Fishing Bobber*/, 529922 /*Children's Week Hanging Long Streamer*/, 529930 /*Children's Week Crate*/, 529929 /*Children's Week Baloon Ground Banner*/, 529928 /*Children's Week Ground Streamer*/, 529923 /*Children's Week Hanging Long Streamer*/, 529912 /*Children's Week Cart*/, 499954 /*Corrupted Chest*/, 499958 /*Corrupted Chest*/, 487652 /*Brazier*/, 487524 /*Brazier*/, 487535 /*Forge*/, 499957 /*Corrupted Chest*/, 487776 /*Brazier*/, 487664 /*Brazier*/, 487773 /*Guild Vault*/, 487690 /*Bonfire*/, 519559 /*Bag of Wolf Tack*/, 487797 /*Brazier*/, 487752 /*Forge*/, 487680 /*Brazier*/, 487643 /*Anvil*/, 487560 /*Bonfire*/, 487480 /*Brazier*/, 487452 /*Brazier*/, 499960 /*Corrupted Chest*/, 487681 /*Barrel*/, 487679 /*Barrel*/, 487734 /*Brazier*/, 487715 /*Brazier*/, 487727 /*Brazier*/, 487600 /*Brazier*/, 487450 /*Brazier*/, 487537 /*Brazier*/, 487533 /*Brazier*/, 487757 /*Bonfire*/, 487579 /*Brazier*/, 487770 /*Brazier*/, 487505 /*Brazier*/, 487521 /*Brazier*/, 487484 /*Brazier*/, 487722 /*Brazier*/, 487758 /*Brazier*/, 487710 /*Brazier*/, 487673 /*Brazier*/, 487628 /*Brazier*/, 519487 /*Worn Wolf Saddle*/, 487584 /*Brazier*/, 487530 /*Brazier*/, 487437 /*Brazier*/, 487656 /*Brazier*/, 487443 /*Brazier*/, 487792 /*Brazier*/, 487711 /*Brazier*/, 487607 /*Brazier*/, 487603 /*Brazier*/, 487428 /*Brazier*/, 487409 /*Brazier*/, 499956 /*Corrupted Chest*/, 487737 /*Brazier*/, 487774 /*Brazier*/, 487438 /*Brazier*/, 487610 /*Brazier*/, 487731 /*Brazier*/, 487761 /*Brazier*/, 487471 /*Brazier*/, 487639 /*Brazier*/, 487597 /*Brazier*/, 487461 /*Brazier*/, 487539 /*Brazier*/, 487538 /*Brazier*/, 516402 /*Bone Pile*/, 487687 /*Campfire*/, 516400 /*Bone Pile*/, 487660 /*Brazier*/, 487462 /*Brazier*/, 487791 /*Brazier*/, 487594 /*Brazier*/, 487494 /*Brazier*/, 487655 /*Brazier*/, 487592 /*Brazier*/, 487721 /*Brazier*/, 487749 /*Brazier*/, 487518 /*Brazier*/, 487588 /*Brazier*/, 487435 /*Smoker*/, 487424 /*Brazier*/, 487785 /*Brazier*/, 487707 /*Brazier*/, 487689 /*Brazier*/, 527705 /*Gamon's Axe*/, 487714 /*Brazier*/, 487661 /*Brazier*/, 487625 /*Brazier*/, 487432 /*Brazier*/, 487659 /*Bonfire*/, 487495 /*Brazier*/, 487572 /*Brazier*/, 487650 /*Brazier*/, 487796 /*Gooblin Boat*/, 487723 /*Waters of Farseeing*/, 523458 /*Trash*/, 516141 /*Ripped Note*/, 516145 /*Ripped Note*/, 479294 /*Chair*/, 526932 /*Porter*/, 524391 /*Prize Chest*/, 537241 /*11.1.5 Dastardly Duos - Goblin Zapper Bot Waypoint*/, 537240 /*Animatronic Gear*/, 505680 /*Animatronic Gear*/, 517269 /*Glubtok Bonfire*/, 517125 /*Beefy Burger*/, 479439 /*Fancy Chair*/, 479375 /*Chair*/, 473871 /*Door*/, 478044 /*Door*/, 479292 /*Chair*/, 524105 /*Bottle of Invisibility*/, 475388 /*Door*/, 503145 /*Junkyard Gate*/, 479433 /*Fancy Chair*/, 479209 /*Stool*/, 488278 /*Door*/, 479286 /*Chair*/, 479382 /*Chair*/, 517160 /*Banana Bunch*/, 473859 /*Door*/, 479427 /*Fancy Chair*/, 479203 /*Fancy Chair*/, 516577 /*Bookshelf*/, 517149 /*Cake from a Fan*/, 473872 /*Door*/, 479376 /*Fancy Chair*/, 516782 /*Gate (Cosmetic)*/, 478045 /*Door*/, 479421 /*Fancy Chair*/, 524106 /*Vial of Healing*/, 479197 /*Chair*/, 479293 /*Chair*/, 516923 /*Long Table*/, 503146 /*Alliance Gate*/, 479434 /*Fancy Chair*/, 479210 /*Chair*/, 517192 /*Arrow*/, 479383 /*Stool*/, 473873 /*Door*/, 479441 /*Fancy Chair*/, 479281 /*Chair*/, 479377 /*Stool*/, 516879 /*Wall (Cosmetic)*/, 479422 /*Fancy Chair*/, 479198 /*Stool*/, 503147 /*Alliance Gate*/, 479435 /*Fancy Chair*/, 479371 /*Chair*/, 479192 /*Bean Bag Chair*/, 479288 /*Chair*/, 479384 /*Chair*/, 479378 /*Stool*/, 473861 /*Door*/, 479429 /*Fancy Chair*/, 473874 /*Door*/, 479442 /*Stool*/, 479282 /*Chair*/, 478047 /*Door*/, 479295 /*Chair*/, 503148 /*Alliance Gate*/, 479436 /*Fancy Chair*/, 479212 /*Bean Bag Chair*/, 479372 /*Stool*/, 517162 /*DNT Haunch Left*/, 479385 /*Stool*/, 517163 /*DNT Haunch Right*/, 479430 /*Fancy Chair*/, 473862 /*Door*/, 479283 /*Chair*/, 479379 /*Fancy Chair*/, 473875 /*Door*/, 478048 /*Door*/, 479424 /*Fancy Chair*/, 479296 /*Chair*/, 503149 /*Alliance Gate*/, 479437 /*Fancy Chair*/, 479213 /*Chair*/, 479373 /*Stool*/, 479194 /*Chair*/, 479290 /*Chair*/, 479386 /*Fancy Chair*/, 517208 /*Arrow Sign*/, 473863 /*Door*/, 479207 /*Chair*/, 516901 /*Chair*/, 473876 /*Door*/, 479444 /*Fancy Chair*/, 479284 /*Chair*/, 479380 /*Fancy Chair*/, 503150 /*Alliance Gate*/, 478049 /*Door*/, 479425 /*Fancy Chair*/, 473870 /*Door*/, 479438 /*Fancy Chair*/, 479214 /*Bean Bag Chair*/, 479374 /*Stool*/, 516756 /*Bench*/, 478043 /*Door*/, 524104 /*Can of Amps*/, 479195 /*Chair*/, 479291 /*Chair*/, 517185 /*String Lights*/, 503144 /*Junkyard Gate*/, 479208 /*Chair*/, 479285 /*Chair*/, 479381 /*Fancy Chair*/, 516883 /*Oil Drum*/, 503151 /*11.1 Raid - Undermine - Boss- Promoter- Door*/, 516589 /*Food 2*/, 516618 /*Food 5*/, 524751 /*11.1.5 - Dastardly Duos - Orgrimmar Hub*/, 524662 /*11.1.5 - Dastardly Duos - Orgrimmar Hub*/, 524752 /*11.1.5 - Dastardly Duos - Orgrimmar Hub*/, 452407 /*Portal to Dornogal*/, 524754 /*11.1.5 - Dastardly Duos - Orgrimmar Hub*/, 524753 /*11.1.5 - Dastardly Duos - Orgrimmar Hub*/, 516505 /*Stanchion with line*/, 516518 /*Teleporter*/, 516506 /*Stanchion*/, 507757 /*Fire*/, 507756 /*Fire*/, 523679 /*Chair*/, 495491 /*Chair*/, 495490 /*Chair*/, 495489 /*Chair*/, 527409 /*Suspicious Document*/, 519855 /*Swarm Tunnel*/, 519854 /*Pulsing Swarm Sac*/, 519777 /*Maturing Swarm Cluster*/, 527404 /*Sureki Weapon Crate*/, 527398 /*Suspicious Document*/, 403492 /*Duskrise Acreage Keyflame*/, 454077 /*Sporefused Blessing Blossom*/, 445609 /*Portal to the Surface*/, 444130 /*[DNT] Boss Entrance Portal Smoke 2*/, 444095 /*[DNT] Boss Entrance Cosmetic*/, 444072 /*[DNT] Boss Entrance*/, 444241 /*Shadowseam*/, 444121 /*Earthen Drill Sparks [DNT]*/, 444575 /*[DNT] Drill Spin Beam*/, 444114 /*[DNT] Drill Spin Effect*/, 446580 /*Radiant Fuel Cache*/, 446579 /*[DNT] Shadowseam Wall*/, 451222 /*Radiant Fuel Cache*/, 446373 /*[DNT] Void Trap Decal*/, 446372 /*[DNT] Void Trap*/, 517070 /*Gutterside Rocket Drill*/, 527178 /*Chair*/, 527179 /*Chair*/, 527180 /*Chair*/, 527181 /*Chair*/, 456826 /*Alliance Landing Skiff*/, 457331 /*Supplies*/, 499299 /*Challenger's Cache*/, 469490 /*Challenge Mode - Start Door v2 (Dome 3.0)*/, 536077 /*Chair*/, 536076 /*Chair*/, 523403 /*Aqirite Barricade*/, 536078 /*Bench*/, 536075 /*Bench*/, 536074 /*Bench*/, 531506 /*A Spark of Radiant Flames*/, 531491 /*Carpet*/, 528379 /*Pheramone Infuser*/, 523399 /*Sureki Supply Cache*/, 499302 /*Challenger's Cache*/, 463963 /*Challenge Mode - Start Door v2 (Line 3.0)*/, 443518 /*Melted Candle*/, 441954 /*Earthen Spear*/, 441952 /*Earthen Axe*/, 441950 /*Waxed Wooden Plank*/, 441949 /*Kobold Skeleton*/, 434528 /*Stormrider Storage*/, 423433 /*Earthen Storage Chest*/, 441955 /*Earthen Shield*/, 392665 /*10OC_Orc_Ship_HingedDoor01*/, 386640 /*6OR_GARRISON_STOOL02*/, 386639 /*6OR_GARRISON_STOOL01*/, 386638 /*6OR_GARRISON_STOOL01*/, 386637 /*6OR_GARRISON_STOOL02*/, 386636 /*6OR_GARRISON_STOOL01*/, 449528 /*Opal-Mining Tools*/, 517130 /*Kaja'Coast Rocket Drill*/, 452029 /*Earthen*/, 529925 /*Children's Week Hanging Banner*/, 529936 /*Wooden Horde Shield Toy*/, 531505 /*Children's Week Baloon Wreath*/, 531513 /*Children's Week Baloon Wreath*/, 541716 /*Murloc Toy*/, 529924 /*Children's Week Hanging Banner*/, 454272 /*Nerubian Statue*/, 455778 /*Gerald*/, 307032 /*Stack of Blight Barrels*/, 307429 /*Stack of Blight Barrels*/, 516666 /*Porter*/, 516143 /*Ripped Note*/, 454261 /*Grand Splicer Xini'tith*/, 454270 /*Queen Yz*/, 454260 /*Xevex*/, 454265 /*Nerubian Statue*/, 454332 /*Treatise on Forms: Sages*/, 454330 /*Treatise on Forms: Skitterlings*/, 454320 /*Queen Anub'izek*/, 454313 /*Queen Xekatha*/, 454264 /*Nerubian Statue*/, 454263 /*Nerubian Statue*/, 454316 /*Queen Zaltra*/, 454268 /*Nerubian Statue*/, 454269 /*Queen Zaltra*/, 464734 /*[DNT] Bungee Jump Skeleton*/, 457195 /*Rappelling Anchor*/, 454416 /*Alfritha's Plaque*/, 455119 /*Earthen Tool*/, 465093 /*Sewer Grate*/, 433364 /*Sewer Grate*/, 437333 /*Power Station Console*/, 419789 /*Salvage Pile*/, 529938 /*Children's Week Cart*/, 529935 /*Wooden Axe Toy*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(527088, 5, 102616, 'Dastardly Banner', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Dastardly Banner
(516591, 5, 101191, 'Food 4', '', '', '', 1.25, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Food 4
(516590, 5, 97740, 'Food 3', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Food 3
(516588, 5, 96192, 'Food 1', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Food 1
(516519, 5, 92679, 'Crate', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Crate
(516517, 5, 99657, 'Control Panel', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Control Panel
(516515, 5, 101170, 'Cola Can 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Cola Can 01
(516509, 5, 101186, 'Streetlight', '', '', '', 0.400000005960464477, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Streetlight
(516508, 5, 95234, 'BBQ', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- BBQ
(516504, 5, 98645, 'Take Out Box 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Take Out Box 02
(525637, 43, 102733, '11.1.5 - Dastardly Duos - Dornogal Hub Props', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Dornogal Hub Props
(525627, 43, 102732, '11.1.5 - Dastardly Duos - Dornogal Hub Props', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Dornogal Hub Props
(525607, 43, 102732, '11.1.5 - Dastardly Duos - Dornogal Hub Props', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Dornogal Hub Props
(525540, 43, 102732, '11.1.5 - Dastardly Duos - Dornogal Hub Props', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Dornogal Hub Props
(525515, 43, 89175, '11.1.5 - Dastardly Duos - Dornogal Hub Props', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Dornogal Hub Props
(516604, 5, 101194, 'Rug 02', '', '', '', 1.10000002384185791, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Rug 02
(516603, 5, 101193, 'Rug 01', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Rug 01
(516586, 5, 96163, 'Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Table
(516578, 5, 101185, 'Umbrella', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Umbrella
(516516, 5, 101171, 'Cola Can 03', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Cola Can 03
(516512, 7, 97767, 'Bean Bag Chair', '', '', '', 1.5, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bean Bag Chair
(516503, 5, 96774, 'Take Out Box 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Take Out Box 01
(499031, 3, 58318, 'Corrupted Chest', '', 'Opening', '', 1, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3083, 0, 1, 0, 0, 129285, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(499022, 3, 58162, 'Corrupted Chest', '', 'Opening', '', 1.5, 57, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3081, 304950, 1, 0, 0, 129280, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(493978, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(486011, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494217, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494175, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494171, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494160, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494157, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494141, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494112, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494107, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494105, 7, 622, 'Stone Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494104, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494100, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494083, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494071, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494065, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494064, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494029, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(494022, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(493995, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(493972, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(493952, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(493944, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(493924, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(493920, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stone Bench
(500274, 3, 58162, 'Reclaimed Spoils Stash', 'questinteract', '', '', 0.5, 3125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 129570, 0, 0, 0, 0, 0, 737, 61265), -- Reclaimed Spoils Stash
(500098, 3, 58162, 'Black Empire Cache', 'questinteract', '', '', 0.5, 3125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 129550, 0, 0, 0, 0, 0, 737, 61265), -- Black Empire Cache
(500099, 3, 58162, 'Black Empire Cache', 'questinteract', '', '', 0.5, 3125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 129551, 0, 0, 0, 0, 0, 737, 61265), -- Black Empire Cache
(500100, 3, 58162, 'Black Empire Cache', 'questinteract', '', '', 0.5, 3125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 129552, 0, 0, 0, 0, 0, 737, 61265), -- Black Empire Cache
(494044, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(499028, 3, 58318, 'Corrupted Chest', '', 'Opening', '', 1, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3085, 0, 1, 0, 0, 129283, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(494082, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(494239, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(494225, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(494015, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(494008, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(493998, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(494099, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(517349, 10, 66667, 'Cursed Horseshoe', '', '', '', 1, 2124, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 1221158, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Cursed Horseshoe
(494218, 8, 8661, 'Cookpot', '', '', '', 0.300000011920928955, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Cookpot
(527691, 10, 15, 'WANTED: Hogger!!', 'questinteract', 'Reading', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 181116, 0, 0, 0, 0, 38711, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3617, 61265), -- WANTED: Hogger!!
(516142, 9, 15781, 'Ripped Note', 'questinteract', '', '', 1, 9910, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Ripped Note
(516146, 9, 15781, 'Ripped Note', 'questinteract', '', '', 1, 9914, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Ripped Note
(517348, 10, 66667, 'Cursed Horseshoe', '', '', '', 1, 2124, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 1221157, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Cursed Horseshoe
(499029, 3, 58318, 'Corrupted Chest', '', 'Opening', '', 1, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3084, 0, 1, 0, 0, 129284, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(527781, 5, 43597, 'Post', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Post
(517350, 10, 66667, 'Cursed Horseshoe', '', '', '', 1, 2124, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 1221159, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Cursed Horseshoe
(499026, 3, 58318, 'Corrupted Chest', '', 'Opening', '', 1, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3082, 0, 1, 0, 0, 129282, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(499038, 10, 20938, 'Portal to Cathedral District', '', 'Activating', '', 1, 3170, 0, 0, 1, 0, 0, 0, 0, 0, 0, 471271, 0, 0, 0, 27700, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Portal to Cathedral District
(517344, 10, 66667, 'Cursed Horseshoe', '', '', '', 1, 2124, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 1221153, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Cursed Horseshoe
(494237, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(494143, 7, 622, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(495367, 3, 58162, 'Corrupted Chest', '', 'Opening', '', 0.800000011920928955, 57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 129210, 0, 0, 0, 0, 0, 737, 61265), -- Corrupted Chest
(523456, 10, 102085, 'Trash', 'inspect', '', '', 1, 4008, 0, 0, 0, 0, 0, 65535, 0, 0, 0, 1223435, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Trash
(523457, 10, 87011, 'Trash', 'inspect', '', '', 1, 4008, 0, 0, 0, 0, 0, 65535, 0, 0, 0, 1223435, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Trash
(494050, 43, 37760, '7.0 Stormwind - Lion\'s Rest - Phased WMO', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 864, 61265), -- 7.0 Stormwind - Lion's Rest - Phased WMO
(523452, 10, 101241, 'Trash', 'inspect', '', '', 1, 4008, 0, 0, 0, 0, 0, 65535, 0, 0, 0, 1223435, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Trash
(493974, 10, 1907, 'Mailbox', '', '', '', 1, 3150, 0, 0, 0, 0, 0, 65535, 0, 0, 0, 312859, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Mailbox
(494167, 22, 445, 'Waters of Farseeing', '', '', '', 2.029997110366821289, 94687, -1, 0, 0, 1, 11723, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53, 61265), -- Waters of Farseeing
(524737, 0, 90923, '11.0 Dungeon - Brewery - Boss 4 - Door - ML', '', '', '', 1.20000004768371582, 0, 0, 10000, 0, 0, 0, 0, 5793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- 11.0 Dungeon - Brewery - Boss 4 - Door - ML
(539206, 5, 37971, 'Collision Object', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Collision Object
(529919, 5, 93536, 'Children\'s Week Baloon Wreath Stand', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Baloon Wreath Stand
(529920, 5, 93531, 'Children\'s Week Hanging Short Streamer', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Hanging Short Streamer
(529917, 5, 52484, 'Balloon Cluster [DNT]', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Balloon Cluster [DNT]
(529914, 5, 36950, 'Murloc Toy', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Murloc Toy
(529937, 5, 104437, 'Wooden Alliance Shield Toy', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Wooden Alliance Shield Toy
(529934, 5, 47024, 'Wooden Sword Toy', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Wooden Sword Toy
(529918, 5, 93535, 'Children\'s Week Baloon Wreath (.3)', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Baloon Wreath (.3)
(531510, 5, 94307, 'Children\'s Week Hanging Banner', '', '', '', 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Hanging Banner
(529931, 5, 93538, 'Children\'s Week Crate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Crate
(529932, 5, 93527, 'Children\'s Week Kite', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Kite
(529913, 5, 15105, 'Elekk Plush', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Elekk Plush
(536474, 5, 93534, 'Children\'s Week Toy Boat', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Toy Boat
(451388, 23, 92048, 'Meeting Stone', '', '', '', 1, 1, 60, 14980, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2723, 60490), -- Meeting Stone
(385544, 17, 10948, 'Fishing Bobber', 'Fishing', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Fishing Bobber
(529922, 5, 93533, 'Children\'s Week Hanging Long Streamer', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Children's Week Hanging Long Streamer
(529930, 5, 93526, 'Children\'s Week Crate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Children's Week Crate
(529929, 5, 91502, 'Children\'s Week Baloon Ground Banner', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Children's Week Baloon Ground Banner
(529928, 5, 93522, 'Children\'s Week Ground Streamer', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Children's Week Ground Streamer
(529923, 5, 93532, 'Children\'s Week Hanging Long Streamer', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Children's Week Hanging Long Streamer
(529912, 5, 15093, 'Children\'s Week Cart', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Children's Week Cart
(499954, 3, 58162, 'Corrupted Chest', '', 'Opening', '', 1.5, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3086, 0, 1, 0, 0, 129517, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(499958, 3, 58318, 'Corrupted Chest', '', 'Opening', '', 1, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3090, 0, 1, 0, 0, 129520, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(487652, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487524, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487535, 8, 9948, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Forge
(499957, 3, 58318, 'Corrupted Chest', '', 'Opening', '', 1, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3089, 0, 1, 0, 0, 129519, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(487776, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487664, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487773, 34, 7616, 'Guild Vault', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Guild Vault
(487690, 8, 1967, 'Bonfire', '', '', '', 1.25, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bonfire
(519559, 10, 14316, 'Bag of Wolf Tack', '', '', '', 1, 2124, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 1221879, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Bag of Wolf Tack
(487797, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487752, 8, 305, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 103829, 0, 30092, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Forge
(487680, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487643, 8, 273, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 103828, 0, 30091, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Anvil
(487560, 8, 1967, 'Bonfire', '', '', '', 1.460000038146972656, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bonfire
(487480, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487452, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(499960, 3, 58318, 'Corrupted Chest', '', 'Opening', '', 1, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3088, 0, 1, 0, 0, 129521, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(487681, 8, 10142, 'Barrel', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Barrel
(487679, 8, 10142, 'Barrel', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Barrel
(487734, 8, 201, 'Brazier', '', '', '', 1.171470046043395996, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487715, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487727, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487600, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487450, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487537, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487533, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487757, 8, 17690, 'Bonfire', '', '', '', 0.270000010728836059, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bonfire
(487579, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487770, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487505, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487521, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487484, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487722, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487758, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487710, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487673, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487628, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(519487, 10, 35979, 'Worn Wolf Saddle', '', '', '', 1, 2124, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 1221859, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Worn Wolf Saddle
(487584, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487530, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487437, 8, 9688, 'Brazier', '', '', '', 3.109999895095825195, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487656, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487443, 8, 9688, 'Brazier', '', '', '', 3.109999895095825195, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487792, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487711, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487607, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487603, 8, 9688, 'Brazier', '', '', '', 3.109999895095825195, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487428, 8, 9688, 'Brazier', '', '', '', 3.109999895095825195, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487409, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(499956, 3, 58318, 'Corrupted Chest', '', 'Opening', '', 1, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3087, 0, 1, 0, 0, 129518, 0, 2, 0, 0, 0, 737, 61265), -- Corrupted Chest
(487737, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487774, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487438, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487610, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487731, 8, 9688, 'Brazier', '', '', '', 3.109999895095825195, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487761, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487471, 8, 9688, 'Brazier', '', '', '', 3.109999895095825195, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487639, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487597, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487461, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487539, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487538, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(516402, 5, 79791, 'Bone Pile', '', '', '', 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Bone Pile
(487687, 8, 192, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Campfire
(516400, 5, 75055, 'Bone Pile', '', '', '', 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Bone Pile
(487660, 8, 474, 'Brazier', '', '', '', 1.110000014305114746, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487462, 8, 474, 'Brazier', '', '', '', 1.110000014305114746, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487791, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487594, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487494, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487655, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487592, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487721, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487749, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487518, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487588, 8, 9688, 'Brazier', '', '', '', 2.779999971389770507, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487435, 8, 409, 'Smoker', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Smoker
(487424, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487785, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487707, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487689, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(527705, 10, 103845, 'Gamon\'s Axe', 'questinteract', 'Investigating', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 193761, 0, 0, 0, 0, 38714, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3617, 61265), -- Gamon's Axe
(487714, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487661, 8, 9688, 'Brazier', '', '', '', 2.779999971389770507, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487625, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487432, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487659, 8, 6193, 'Bonfire', '', '', '', 1.679999947547912597, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bonfire
(487495, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487572, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487650, 8, 9687, 'Brazier', '', '', '', 1.169999957084655761, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Brazier
(487796, 33, 9580, 'Gooblin Boat', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Gooblin Boat
(487723, 22, 445, 'Waters of Farseeing', '', '', '', 2.029997110366821289, 94687, -1, 0, 0, 1, 11735, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53, 61265), -- Waters of Farseeing
(523458, 10, 95662, 'Trash', 'inspect', '', '', 1, 4008, 0, 0, 0, 0, 0, 65535, 0, 0, 0, 1223435, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 737, 61265), -- Trash
(516141, 9, 15781, 'Ripped Note', 'questinteract', '', '', 1, 9909, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Ripped Note
(516145, 9, 15781, 'Ripped Note', 'questinteract', '', '', 1, 9913, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Ripped Note
(479294, 7, 92626, 'Chair', '', '', '', 0.999999165534973144, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(526932, 22, 98347, 'Porter', 'directions', '', '', 0.5, 1226767, 0, 0, 0, 0, 136930, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Porter
(524391, 3, 96167, 'Prize Chest', '', '', '', 1, 1634, 0, 0, 0, 0, 0, 0, 526930, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 132288, 0, 0, 0, 0, 0, 3361, 61265), -- Prize Chest
(537241, 6, 105257, '11.1.5 Dastardly Duos - Goblin Zapper Bot Waypoint', '', '', '', 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3361, 61265), -- 11.1.5 Dastardly Duos - Goblin Zapper Bot Waypoint
(537240, 10, 56648, 'Animatronic Gear', '', '', '', 0.5, 0, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 1234245, 0, 537241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 61265), -- Animatronic Gear
(505680, 22, 56648, 'Animatronic Gear', '', '', '', 0.5, 1217637, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Animatronic Gear
(517269, 5, 17690, 'Glubtok Bonfire', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Glubtok Bonfire
(517125, 10, 96192, 'Beefy Burger', '', '', '', 1.25, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, 1221113, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 61265), -- Beefy Burger
(479439, 7, 89571, 'Fancy Chair', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479375, 7, 92626, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(473871, 0, 96872, 'Door', '', '', '', 1.077180862426757812, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(478044, 0, 96872, 'Door', '', '', '', 1.31764078140258789, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479292, 7, 92626, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(524105, 10, 47700, 'Bottle of Invisibility', '', '', '', 0.85000002384185791, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, 1220621, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3361, 61265), -- Bottle of Invisibility
(475388, 0, 96878, 'Door', '', '', '', 0.775741219520568847, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(503145, 0, 97769, 'Junkyard Gate', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Junkyard Gate
(479433, 7, 89571, 'Fancy Chair', '', '', '', 0.999999403953552246, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479209, 7, 92627, 'Stool', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stool
(488278, 0, 96874, 'Door', '', '', '', 0.999999761581420898, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479286, 7, 92626, 'Chair', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479382, 7, 92626, 'Chair', '', '', '', 0.999999284744262695, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(517160, 5, 101230, 'Banana Bunch', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Banana Bunch
(473859, 0, 96872, 'Door', '', '', '', 1.036341309547424316, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479427, 7, 89571, 'Fancy Chair', '', '', '', 0.999999284744262695, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479203, 7, 89571, 'Fancy Chair', '', '', '', 0.999999403953552246, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(516577, 5, 99436, 'Bookshelf', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bookshelf
(517149, 10, 8232, 'Cake from a Fan', '', '', '', 0.5, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, 1221117, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 61265), -- Cake from a Fan
(473872, 0, 96872, 'Door', '', '', '', 1.030496716499328613, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479376, 7, 89571, 'Fancy Chair', '', '', '', 0.99999934434890747, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(516782, 5, 100705, 'Gate (Cosmetic)', '', '', '', 0.375, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Gate (Cosmetic)
(478045, 0, 96872, 'Door', '', '', '', 1.29011392593383789, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479421, 7, 89571, 'Fancy Chair', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(524106, 10, 101412, 'Vial of Healing', '', '', '', 0.550000011920928955, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, 1220625, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3361, 61265), -- Vial of Healing
(479197, 7, 92626, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479293, 7, 92626, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(516923, 5, 93340, 'Long Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Long Table
(503146, 0, 97769, 'Alliance Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Alliance Gate
(479434, 7, 89571, 'Fancy Chair', '', '', '', 0.99999934434890747, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479210, 7, 92626, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(517192, 5, 101714, 'Arrow', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arrow
(479383, 7, 92627, 'Stool', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stool
(473873, 0, 96874, 'Door', '', '', '', 1.033001184463500976, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479441, 7, 89571, 'Fancy Chair', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479281, 7, 92626, 'Chair', '', '', '', 0.999999582767486572, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479377, 7, 92627, 'Stool', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stool
(516879, 5, 101713, 'Wall (Cosmetic)', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Wall (Cosmetic)
(479422, 7, 89571, 'Fancy Chair', '', '', '', 0.99999934434890747, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479198, 7, 92627, 'Stool', '', '', '', 0.999999225139617919, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265); -- Stool

INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(503147, 0, 81602, 'Alliance Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Alliance Gate
(479435, 7, 89571, 'Fancy Chair', '', '', '', 0.999999284744262695, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479371, 7, 92626, 'Chair', '', '', '', 0.999999225139617919, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479192, 7, 97337, 'Bean Bag Chair', '', '', '', 0.99999934434890747, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bean Bag Chair
(479288, 7, 92626, 'Chair', '', '', '', 0.999999403953552246, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479384, 7, 92626, 'Chair', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479378, 7, 92627, 'Stool', '', '', '', 0.999999225139617919, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stool
(473861, 0, 96874, 'Door', '', '', '', 0.999999523162841796, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479429, 7, 89571, 'Fancy Chair', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(473874, 0, 96878, 'Door', '', '', '', 0.769019484519958496, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479442, 7, 92627, 'Stool', '', '', '', 0.999999284744262695, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stool
(479282, 7, 92626, 'Chair', '', '', '', 0.999999403953552246, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(478047, 0, 96872, 'Door', '', '', '', 1.291923165321350097, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479295, 7, 92626, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(503148, 0, 81602, 'Alliance Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Alliance Gate
(479436, 7, 89571, 'Fancy Chair', '', '', '', 0.99999934434890747, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479212, 7, 97767, 'Bean Bag Chair', '', '', '', 0.999999463558197021, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bean Bag Chair
(479372, 7, 92627, 'Stool', '', '', '', 0.999999582767486572, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stool
(517162, 5, 101709, 'DNT Haunch Left', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 5703, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- DNT Haunch Left
(479385, 7, 92627, 'Stool', '', '', '', 0.99999934434890747, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stool
(517163, 5, 101710, 'DNT Haunch Right', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 5703, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- DNT Haunch Right
(479430, 7, 89571, 'Fancy Chair', '', '', '', 0.999999284744262695, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(473862, 0, 96874, 'Door', '', '', '', 0.999999523162841796, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479283, 7, 92626, 'Chair', '', '', '', 0.999999225139617919, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479379, 7, 89571, 'Fancy Chair', '', '', '', 0.999999225139617919, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(473875, 0, 96878, 'Door', '', '', '', 1.004589080810546875, 0, 0, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(478048, 0, 96872, 'Door', '', '', '', 1.310572385787963867, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479424, 7, 89571, 'Fancy Chair', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479296, 7, 92626, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(503149, 0, 81602, 'Alliance Gate', '', '', '', 1.080000042915344238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Alliance Gate
(479437, 7, 89571, 'Fancy Chair', '', '', '', 0.999999523162841796, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479213, 7, 92626, 'Chair', '', '', '', 0.999999403953552246, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479373, 7, 92627, 'Stool', '', '', '', 0.999999523162841796, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stool
(479194, 7, 92626, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479290, 7, 92626, 'Chair', '', '', '', 0.999999284744262695, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479386, 7, 89571, 'Fancy Chair', '', '', '', 0.99999934434890747, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(517208, 5, 97570, 'Arrow Sign', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Arrow Sign
(473863, 0, 96872, 'Door', '', '', '', 1.115803241729736328, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479207, 7, 92626, 'Chair', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(516901, 7, 89571, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(473876, 0, 96874, 'Door', '', '', '', 1.036242961883544921, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479444, 7, 89571, 'Fancy Chair', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479284, 7, 92626, 'Chair', '', '', '', 0.999999284744262695, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479380, 7, 89571, 'Fancy Chair', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(503150, 0, 81602, 'Alliance Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Alliance Gate
(478049, 0, 96872, 'Door', '', '', '', 1.276549816131591796, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479425, 7, 89571, 'Fancy Chair', '', '', '', 0.99999934434890747, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(473870, 0, 96878, 'Door', '', '', '', 0.731711387634277343, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(479438, 7, 89571, 'Fancy Chair', '', '', '', 0.999999403953552246, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(479214, 7, 97337, 'Bean Bag Chair', '', '', '', 0.999999463558197021, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bean Bag Chair
(479374, 7, 92627, 'Stool', '', '', '', 0.999999284744262695, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stool
(516756, 7, 93731, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Bench
(478043, 0, 96872, 'Door', '', '', '', 1.183219552040100097, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Door
(524104, 10, 101170, 'Can of Amps', '', '', '', 1, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, 1220620, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3361, 61265), -- Can of Amps
(479195, 7, 92626, 'Chair', '', '', '', 0.999999642372131347, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479291, 7, 92626, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(517185, 5, 96686, 'String Lights', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- String Lights
(503144, 0, 97769, 'Junkyard Gate', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Junkyard Gate
(479208, 7, 92626, 'Chair', '', '', '', 0.999999403953552246, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479285, 7, 92626, 'Chair', '', '', '', 0.999999642372131347, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Chair
(479381, 7, 89571, 'Fancy Chair', '', '', '', 0.99999934434890747, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Fancy Chair
(516883, 5, 99108, 'Oil Drum', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Oil Drum
(503151, 0, 97769, '11.1 Raid - Undermine - Boss- Promoter- Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1 Raid - Undermine - Boss- Promoter- Door
(516589, 5, 101190, 'Food 2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Food 2
(516618, 5, 8232, 'Food 5', '', '', '', 0.5, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Food 5
(524751, 43, 102732, '11.1.5 - Dastardly Duos - Orgrimmar Hub', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Orgrimmar Hub
(524662, 43, 89175, '11.1.5 - Dastardly Duos - Orgrimmar Hub', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Orgrimmar Hub
(524752, 43, 102732, '11.1.5 - Dastardly Duos - Orgrimmar Hub', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Orgrimmar Hub
(452407, 22, 92603, 'Portal to Dornogal', '', '', '', 0.999999761581420898, 446540, -1, 0, 0, 0, 124420, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Portal to Dornogal
(524754, 43, 102733, '11.1.5 - Dastardly Duos - Orgrimmar Hub', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Orgrimmar Hub
(524753, 43, 102732, '11.1.5 - Dastardly Duos - Orgrimmar Hub', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- 11.1.5 - Dastardly Duos - Orgrimmar Hub
(516505, 5, 101168, 'Stanchion with line', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stanchion with line
(516518, 5, 98347, 'Teleporter', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Teleporter
(516506, 5, 101169, 'Stanchion', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Stanchion
(507757, 8, 70622, 'Fire', '', '', '', 1.099609136581420898, 4, 10, 249358, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Fire
(507756, 8, 70622, 'Fire', '', '', '', 1.099609136581420898, 4, 10, 249358, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Fire
(523679, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(495491, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(495490, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(495489, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(527409, 10, 85232, 'Suspicious Document', '', 'Investigating', '', 1, 43, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 1227396, 0, 0, 0, 193761, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 61122), -- Suspicious Document
(519855, 10, 92009, 'Swarm Tunnel', 'questinteract', '', '', 0.5, 4068, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 61122), -- Swarm Tunnel
(519854, 10, 87609, 'Pulsing Swarm Sac', 'questinteract', '', '', 1, 4067, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Pulsing Swarm Sac
(519777, 10, 87239, 'Maturing Swarm Cluster', 'questinteract', '', '', 1, 4065, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Maturing Swarm Cluster
(527404, 5, 94046, 'Sureki Weapon Crate', '', '', '', 1.399999976158142089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Sureki Weapon Crate
(527398, 10, 90308, 'Suspicious Document', '', 'Investigating', '', 0.5, 43, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 1227389, 0, 0, 0, 193761, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 61122), -- Suspicious Document
(403492, 22, 87639, 'Duskrise Acreage Keyflame', '', '', '', 0.949999988079071044, 412635, 0, 0, 0, 0, 120203, 1, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Duskrise Acreage Keyflame
(454077, 50, 93131, 'Sporefused Blessing Blossom', '', '', '', 1, 3682, 120689, 0, 0, 100, 110, 30, 0, 0, 0, 0, 0, 0, 1, 427986, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 25182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 61122), -- Sporefused Blessing Blossom
(445609, 10, 55042, 'Portal to the Surface', 'questinteract', 'Leaving', '', 2, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 464305, 0, 0, 0, 93214, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Portal to the Surface
(444130, 5, 90883, '[DNT] Boss Entrance Portal Smoke 2', '', '', '', 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- [DNT] Boss Entrance Portal Smoke 2
(444095, 5, 84930, '[DNT] Boss Entrance Cosmetic', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- [DNT] Boss Entrance Cosmetic
(444072, 5, 65249, '[DNT] Boss Entrance', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- [DNT] Boss Entrance
(444241, 10, 55042, 'Shadowseam', 'questinteract', 'Entering', '', 3, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 448317, 0, 0, 0, 92854, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Shadowseam
(444121, 5, 90880, 'Earthen Drill Sparks [DNT]', '', '', '', 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Earthen Drill Sparks [DNT]
(444575, 5, 91035, '[DNT] Drill Spin Beam', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- [DNT] Drill Spin Beam
(444114, 5, 77527, '[DNT] Drill Spin Effect', '', '', '', 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- [DNT] Drill Spin Effect
(446580, 3, 86320, 'Radiant Fuel Cache', 'questinteract', 'Opening', '', 1.5, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37521, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 125582, 1, 0, 0, 0, 0, 2869, 61122), -- Radiant Fuel Cache
(446579, 5, 61145, '[DNT] Shadowseam Wall', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- [DNT] Shadowseam Wall
(451222, 3, 86320, 'Radiant Fuel Cache', 'questinteract', 'Opening', '', 1.5, 43, 0, 1, 0, 0, 0, 0, 0, 81691, 0, 0, 0, 0, 0, 37521, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124226, 1, 0, 0, 0, 0, 2869, 61122), -- Radiant Fuel Cache
(446373, 5, 90872, '[DNT] Void Trap Decal', '', '', '', 0.60000002384185791, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- [DNT] Void Trap Decal
(446372, 5, 60022, '[DNT] Void Trap', '', '', '', 0.60000002384185791, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- [DNT] Void Trap
(517070, 5, 92678, 'Gutterside Rocket Drill', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Gutterside Rocket Drill
(527178, 7, 88246, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(527179, 7, 88246, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(527180, 7, 88246, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(527181, 7, 88246, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(456826, 5, 44134, 'Alliance Landing Skiff', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Alliance Landing Skiff
(457331, 5, 16092, 'Supplies', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Supplies
(499299, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 2848, 0, 1, 0, 0, 129464, 0, 5, 129341, 0, 0, 1279, 61122), -- Challenger's Cache
(469490, 0, 95195, 'Challenge Mode - Start Door v2 (Dome 3.0)', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Challenge Mode - Start Door v2 (Dome 3.0)
(536077, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(536076, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Chair
(523403, 10, 90304, 'Aqirite Barricade', 'questinteract', '', '', 2, 2668, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1223358, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Aqirite Barricade
(536078, 7, 88281, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Bench
(536075, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Bench
(536074, 7, 87769, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Bench
(531506, 10, 90313, 'A Spark of Radiant Flames', 'inspect', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 9973, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- A Spark of Radiant Flames
(531491, 5, 87935, 'Carpet', '', '', '', 0.449999988079071044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Carpet
(528379, 5, 90744, 'Pheramone Infuser', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Pheramone Infuser
(523399, 10, 87879, 'Sureki Supply Cache', 'questinteract', '', '', 1, 2668, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1223360, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Sureki Supply Cache
(499302, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 2930, 0, 1, 0, 0, 129461, 0, 5, 129341, 0, 0, 1279, 61122), -- Challenger's Cache
(463963, 0, 95193, 'Challenge Mode - Start Door v2 (Line 3.0)', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Challenge Mode - Start Door v2 (Line 3.0)
(443518, 5, 85336, 'Melted Candle', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Melted Candle
(441954, 10, 86954, 'Earthen Spear', 'questinteract', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 446522, 0, 0, 0, 0, 0, 0, 0, 0, 34705, 1, 0, 121565, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Earthen Spear
(441952, 10, 88555, 'Earthen Axe', 'questinteract', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 446521, 0, 0, 0, 0, 0, 0, 0, 0, 34704, 1, 0, 121564, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Earthen Axe
(441950, 10, 90482, 'Waxed Wooden Plank', 'questinteract', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 446529, 0, 0, 0, 0, 0, 0, 0, 0, 34710, 1, 0, 121571, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Waxed Wooden Plank
(441949, 10, 88319, 'Kobold Skeleton', 'questinteract', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 446526, 0, 0, 0, 0, 0, 0, 0, 0, 34708, 1, 0, 121569, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Kobold Skeleton
(434528, 10, 89303, 'Stormrider Storage', 'questinteract', '', '', 1.509764552116394042, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 446527, 0, 0, 0, 0, 0, 0, 0, 0, 34709, 0, 0, 121570, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Stormrider Storage
(423433, 5, 84464, 'Earthen Storage Chest', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2462, 61122), -- Earthen Storage Chest
(441955, 10, 90485, 'Earthen Shield', 'questinteract', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 446523, 0, 0, 0, 0, 0, 0, 0, 0, 34706, 1, 0, 121566, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- Earthen Shield
(392665, 5, 80946, '10OC_Orc_Ship_HingedDoor01', '', '', '', 0.999999761581420898, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- 10OC_Orc_Ship_HingedDoor01
(386640, 7, 15984, '6OR_GARRISON_STOOL02', '', '', '', 0.999999821186065673, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- 6OR_GARRISON_STOOL02
(386639, 7, 16151, '6OR_GARRISON_STOOL01', '', '', '', 0.999999821186065673, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- 6OR_GARRISON_STOOL01
(386638, 7, 16151, '6OR_GARRISON_STOOL01', '', '', '', 0.999999761581420898, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- 6OR_GARRISON_STOOL01
(386637, 7, 15984, '6OR_GARRISON_STOOL02', '', '', '', 0.999999821186065673, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- 6OR_GARRISON_STOOL02
(386636, 7, 16151, '6OR_GARRISON_STOOL01', '', '', '', 0.999999761581420898, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61122), -- 6OR_GARRISON_STOOL01
(449528, 3, 88022, 'Opal-Mining Tools', 'questinteract', '', '', 1, 1690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124790, 0, 0, 0, 0, 0, 2838, 61122), -- Opal-Mining Tools
(517130, 5, 92678, 'Kaja\'Coast Rocket Drill', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60822), -- Kaja'Coast Rocket Drill
(452029, 10, 92532, 'Earthen', 'inspect', '', '', 0.649999976158142089, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 453208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Earthen
(529925, 5, 93529, 'Children\'s Week Hanging Banner', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Hanging Banner
(529936, 5, 104436, 'Wooden Horde Shield Toy', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Wooden Horde Shield Toy
(531505, 5, 93535, 'Children\'s Week Baloon Wreath', '', '', '', 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Baloon Wreath
(531513, 5, 93535, 'Children\'s Week Baloon Wreath', '', '', '', 0.899999976158142089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Baloon Wreath
(541716, 5, 38131, 'Murloc Toy', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Murloc Toy
(529924, 5, 94307, 'Children\'s Week Hanging Banner', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60568), -- Children's Week Hanging Banner
(454272, 10, 93272, 'Nerubian Statue', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 60568), -- Nerubian Statue
(455778, 5, 29635, 'Gerald', '', '', '', 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 877, 60490), -- Gerald
(307032, 10, 7470, 'Stack of Blight Barrels', 'questinteract', 'Destroying', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 282719, 0, 0, 0, 24585, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 706, 60490), -- Stack of Blight Barrels
(307429, 10, 7470, 'Stack of Blight Barrels', 'questinteract', 'Destroying', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 282719, 0, 0, 0, 24585, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 706, 60490), -- Stack of Blight Barrels
(516666, 22, 98347, 'Porter', 'directions', '', '', 0.5, 1219714, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Porter
(516143, 9, 15781, 'Ripped Note', 'questinteract', '', '', 1, 9911, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265), -- Ripped Note
(454261, 10, 93272, 'Grand Splicer Xini\'tith', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 9492, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 60490), -- Grand Splicer Xini'tith
(454270, 10, 93272, 'Queen Yz', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 9507, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 60490), -- Queen Yz
(454260, 10, 93272, 'Xevex', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 9514, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 60490), -- Xevex
(454265, 10, 93272, 'Nerubian Statue', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 60490), -- Nerubian Statue
(454332, 10, 93282, 'Treatise on Forms: Sages', 'inspect', 'Reading', '', 1, 43, 0, 0, 0, 0, 0, 0, 9435, 0, 1, 0, 0, 0, 0, 24589, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Treatise on Forms: Sages
(454330, 10, 93282, 'Treatise on Forms: Skitterlings', 'inspect', 'Reading', '', 1, 43, 0, 0, 0, 0, 0, 0, 9431, 0, 1, 0, 0, 0, 0, 24589, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Treatise on Forms: Skitterlings
(454320, 10, 93282, 'Queen Anub\'izek', 'inspect', 'Reading', '', 1, 43, 0, 0, 0, 0, 0, 0, 9366, 0, 8, 0, 0, 0, 0, 24589, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Queen Anub'izek
(454313, 10, 93282, 'Queen Xekatha', 'inspect', 'Reading', '', 1, 43, 0, 0, 0, 0, 0, 0, 9359, 0, 8, 0, 0, 0, 0, 24589, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Queen Xekatha
(454264, 10, 93272, 'Nerubian Statue', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 60490), -- Nerubian Statue
(454263, 10, 93272, 'Nerubian Statue', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 60490), -- Nerubian Statue
(454316, 10, 93282, 'Queen Zaltra', 'inspect', 'Reading', '', 1, 43, 0, 0, 0, 0, 0, 0, 9362, 0, 8, 0, 0, 0, 0, 24589, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Queen Zaltra
(454268, 10, 93272, 'Nerubian Statue', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 60490), -- Nerubian Statue
(454269, 10, 93272, 'Queen Zaltra', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 9489, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 60490), -- Queen Zaltra
(464734, 5, 95408, '[DNT] Bungee Jump Skeleton', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- [DNT] Bungee Jump Skeleton
(457195, 10, 94526, 'Rappelling Anchor', '', 'Jumping', '', 0.75, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 460384, 0, 0, 0, 269577, 0, 0, 0, 0, 0, 1, 0, 126644, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Rappelling Anchor
(454416, 10, 214, 'Alfritha\'s Plaque', 'inspect', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 9341, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Alfritha's Plaque
(455119, 10, 88554, 'Earthen Tool', 'questinteract', '', '', 1, 2124, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 457422, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Earthen Tool
(465093, 10, 64353, 'Sewer Grate', 'questinteract', '', '', 0.349999994039535522, 0, 79024, 0, 3000, 0, 0, 0, 0, 0, 0, 442336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Sewer Grate
(433364, 10, 64353, 'Sewer Grate', 'questinteract', '', '', 0.349999994039535522, 0, 79024, 0, 3000, 0, 0, 0, 0, 0, 0, 440541, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Sewer Grate
(437333, 10, 88789, 'Power Station Console', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5793, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Power Station Console
(419789, 5, 87011, 'Salvage Pile', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Salvage Pile
(529938, 5, 54083, 'Children\'s Week Cart', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490), -- Children's Week Cart
(529935, 5, 104435, 'Wooden Axe Toy', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60490); -- Wooden Axe Toy

UPDATE `gameobject_template` SET `VerifiedBuild`=61265 WHERE `entry` IN (176499, 327017, 311875, 327123, 327122, 327100, 327099, 327098, 327097, 327088, 327087, 327086, 327085, 327084, 327082, 327081, 327080, 327079, 327078, 327083, 327063, 327052, 327047, 327044, 327064, 327062, 327065, 327102, 327129, 327106, 327128, 327118, 327116, 327104, 327101, 327096, 327095, 327092, 327130, 327121, 327120, 327117, 327115, 327105, 327103, 327091, 327089, 327046, 327124, 327110, 327108, 327107, 273683, 327125, 327119, 327111, 327109, 327094, 327093, 327090, 332128, 327127, 327126, 327114, 327113, 327112, 327061, 327060, 327059, 327058, 327057, 327056, 327055, 327051, 327072, 327071, 327050, 327073, 327070, 327074, 327045, 327075, 327076, 327054, 327049, 327077, 327069, 327068, 327048, 327067, 327066, 326795, 326794, 326745, 338611, 338608, 338607, 338606, 338605, 338604, 338603, 338602, 334897, 326768, 326767, 326766, 326765, 326764, 326763, 326762, 326761, 326760, 326754, 326742, 326740, 326746, 326739, 338691, 338690, 338689, 338688, 326741, 326752, 326750, 326749, 326748, 326777, 326776, 326775, 326774, 326772, 326771, 326770, 326769, 326738, 338192, 326773, 326757, 326756, 326791, 326790, 326789, 326788, 326787, 326792, 326759, 326743, 334859, 326751, 273834, 326793, 326786, 326744, 326753, 326785, 326784, 326783, 326782, 326781, 326780, 326779, 326778, 326758, 326985, 326747, 200323, 200322, 200321, 200320, 200319, 200318, 200317, 200331, 200330, 200329, 200326, 200316, 200328, 200327, 334846, 200314, 200313, 200310, 200307, 200315, 200312, 200311, 200306, 326962, 326961, 326960, 326956, 326955, 326929, 326925, 200309, 200308, 339999, 337224, 336854, 326969, 326968, 326967, 326966, 326965, 326964, 326963, 326959, 326958, 326957, 326954, 326927, 326926, 326928, 326953, 326952, 326915, 326939, 326912, 326914, 336802, 336434, 334913, 326931, 326922, 326921, 326919, 326916, 326910, 326938, 326923, 326920, 326918, 326913, 326940, 326911, 326945, 326941, 326951, 326950, 326949, 326948, 326947, 326946, 326944, 326943, 326942, 326937, 326936, 326935, 326934, 326933, 326932, 326930, 326917, 326861, 339190, 326878, 326886, 326884, 326883, 326885, 326882, 326881, 326880, 326879, 326894, 326893, 326870, 326869, 326868, 326867, 326866, 326865, 326864, 326863, 326862, 326909, 326908, 326907, 326906, 326905, 326904, 326897, 326896, 326895, 326903, 326901, 326900, 326899, 326898, 326902, 326887, 326889, 349578, 326892, 326891, 326890, 326888, 326859, 326856, 326857, 326858, 326852, 326853, 339269, 326854, 326874, 326855, 339266, 339267, 326875, 326876, 326877, 326871, 326872, 326873, 340001, 326860, 349577, 327463, 334903, 327003, 327002, 327016, 327034, 327015, 326983, 327004, 326998, 326999, 327006, 326987, 327000, 327013, 327007, 334860, 327001, 341883, 341882, 341406, 339246, 339245, 339240, 327011, 327010, 327009, 327008, 327005, 326997, 326996, 326995, 326992, 326991, 326990, 326994, 326993, 326989, 326988, 326970, 327033, 326975, 326984, 326982, 327036, 343667, 341342, 327035, 327032, 326986, 326981, 326980, 326979, 326978, 326977, 326976, 327027, 327040, 327021, 327028, 327041, 327022, 326971, 327029, 327042, 327023, 326972, 327030, 327024, 327037, 326973, 334845, 327018, 327031, 327012, 327025, 327038, 327019, 327026, 327039, 327020, 327014, 339270, 321685, 332597, 334492, 332151, 332301, 453747, 453367, 444197, 336086, 204641, 336085, 204642, 197309, 197314, 197311, 197307, 197286, 197285, 50805, 50803, 50804, 3301, 206548, 206547, 197322, 197280, 197278, 206549, 197276, 207148, 207147, 207149, 207150, 207146, 207101, 207099, 204625, 204624, 204620, 197257, 207100, 207098, 204626, 207094, 204627, 202717, 207097, 207096, 204628, 204623, 204621, 204622, 204640, 204639, 204611, 204605, 202590, 342271, 207107, 204638, 338481, 204637, 204636, 204635, 230983, 204643, 202812, 204615, 316770, 204617, 204618, 204941, 202814, 202813, 202811, 202810, 197260, 197259, 204940, 202815, 204616, 202816, 204619, 197261, 204614, 204613, 202817, 204612, 204937, 202808, 202805, 202804, 202803, 202802, 208270, 208269, 204939, 204938, 204936, 202809, 202800, 197315, 202801, 202799, 202798, 206546, 206545, 206539, 206538, 206529, 197323, 197313, 197279, 204634, 197287, 197284, 206530, 204633, 204632, 204631, 204606, 210059, 210058, 204607, 204604, 204610, 204609, 204608, 204603, 204602, 341362, 204601, 204600, 204663, 332129, 204651, 204664, 332130, 204645, 204658, 323853, 204666, 204647, 332127, 204655, 323849, 204662, 204650, 327163, 223739, 289318, 223814, 206608, 206610, 206609, 21680, 453878, 494486, 494730, 494487, 494481, 494731, 494488, 494482, 494483, 494484, 494478, 494485, 428845, 428844, 190549, 269949, 206995, 204209, 175080, 377216, 281340, 206725, 204657, 204214, 204210, 204207, 205109, 204213, 323855, 204201, 207414, 204163, 204208, 204656, 179965, 204202, 323850, 204215, 186238, 206110, 323851, 210181, 383583, 323852, 206726, 204646, 204211, 206727, 205108, 204212, 203969, 205142, 379126, 381187, 381186, 381185, 381184, 381183, 381182, 383588, 383589, 383585, 409027, 383604, 383603, 381149, 381146, 402891, 386381, 386380, 386379, 383613, 383605, 383602, 383587, 383586, 381148, 381147, 386477, 383601, 383600, 383612, 383610, 383609, 383608, 383599, 383592, 378264, 381086, 380974, 379022, 378878, 383614, 383598, 382267, 379019, 380987, 380971, 383611, 383595, 381035, 382261, 381032, 380984, 378888, 380453, 381029, 380981, 378885, 382271, 382274, 379330, 378882, 381026, 380978, 380975, 378879, 383615, 380454, 380988, 382182, 380972, 381030, 378876, 383596, 383593, 380986, 381033, 380982, 380985, 378889, 380970, 378886, 383606, 383590, 381027, 384275, 382275, 380451, 379027, 380448, 380979, 378883, 378880, 380976, 379024, 390256, 380973, 383597, 383594, 380455, 381034, 378890, 380452, 381031, 378868, 380983, 378871, 384276, 405380, 384968, 405489, 386474, 376927, 401758, 409010, 377123, 386475, 382168, 410348, 405593, 376833, 380823, 401759, 376417, 377118, 413963, 401760, 410356, 406385, 376753, 376418, 409034, 401761, 405378, 381736, 384744, 386389, 421718, 255306, 378263, 381653, 386473, 381679, 378887, 382276, 383607, 383591, 381028, 380980, 382260, 378884, 380449, 379329, 377022, 381025, 380977, 268054, 268047, 251212, 251211, 251210, 251209, 250417, 250407, 250406, 250405, 250404, 250403, 250401, 250396, 250402, 250398, 250400, 250399, 250395, 250397, 266129, 259820, 253968, 259240, 226911, 253969, 250391, 250390, 248842, 268368, 252663, 248843, 245355, 245368, 248522, 268079, 248523, 248841, 248933, 250387, 247848, 248822, 247849, 250389, 268060, 250392, 250388, 269969, 259375, 248860, 248859, 248858, 248857, 248855, 248852, 247579, 247572, 247564, 247558, 268066, 259377, 259374, 259369, 250394, 250393, 247571, 259373, 259372, 251304, 259371, 259376, 259370, 259359, 259379, 259358, 259361, 259362, 259352, 248856, 259355, 259365, 259354, 259357, 259360, 259356, 259378, 259368, 259367, 259364, 259353, 250304, 250308, 250309, 259366, 259363, 259285, 250312, 250311, 250310, 250307, 250306, 250305, 250303, 250302, 250301, 250261, 250260, 250259, 250258, 242030, 242029, 369303, 259834, 248844, 245353, 242220, 242127, 242639, 242050, 242640, 248093, 252331, 245661, 259351, 242128, 242641, 245662, 259390, 259345, 244824, 242648, 259346, 242636, 242637, 259284, 242638, 245691, 268067, 268057, 249919, 259387, 259380, 259349, 251286, 250514, 250435, 246002, 242054, 242049, 382535, 382534, 382533, 382532, 382531, 269037, 268065, 259348, 258330, 250513, 247691, 245663, 242123, 242048, 242047, 188215, 242228, 250337, 242216, 268046, 251105, 241512, 242037, 246945, 241921, 250510, 259381, 254236, 251585, 242126, 250497, 250459, 246465, 241953, 259265, 259304, 250517, 241947, 250460, 250318, 259272, 250331, 246261, 243374, 250299, 241948, 242235, 259310, 251624, 259278, 250478, 259835, 241966, 250350, 242172, 251592, 250523, 249730, 241506, 250504, 250524, 250472, 266619, 259291, 241960, 250491, 250357, 242043, 242236, 250344, 235099, 242229, 268072, 259343, 259336, 250453, 250216, 245832, 250332, 250300, 244950, 246466, 259311, 241954, 369301, 259279, 268053, 250485, 259317, 268073, 250479, 259394, 250338, 248079, 235100, 250217, 259266, 241922, 259426, 250498, 250313, 245833, 250351, 244560, 251311, 241513, 250511, 241967, 250319, 242223, 259344, 269967, 266761, 259305, 259273, 244534, 251593, 250512, 259382, 250473, 241961, 259286, 250505, 259350, 247337, 242198, 251305, 249731, 200297, 250345, 242038, 259337, 250320, 242051, 369302, 242224, 268086, 250518, 266736, 246262, 242230, 259312, 250454, 250358, 259280, 250499, 250467, 268061, 250480, 250339, 194115, 241968, 242045, 259383, 280797, 259267, 241955, 250352, 259395, 259287, 246941, 245623, 267991, 268087, 251312, 259293, 250218, 259415, 242237, 246154, 268048, 250576, 250487, 251581, 250493, 242199, 250314, 250461, 246013, 242218, 242039, 241949, 250525, 250333, 249732, 268081, 268049, 268074, 242052, 258327, 259338, 259306, 250519, 259396, 259274, 251594, 241943, 250506, 259268, 250474, 247018, 250359, 250346, 250436, 242231, 266851, 248516, 250455, 244561, 242366, 242046, 250449, 250500, 259275, 250468, 242129, 241956, 250340, 251595, 250353, 250507, 250526, 250321, 247019, 246001, 242225, 241969, 250347, 266705, 250481, 246257, 259281, 244536, 246942, 259384, 259294, 259288, 247797, 259262, 241950, 251582, 242040, 250494, 250462, 259339, 250334, 259307, 250315, 244562, 250219, 244651, 251992, 241963, 241419, 250520, 246008, 268043, 247858, 250360, 250328, 250482, 242232, 250456, 259269, 246258, 241951, 250469, 259416, 258328, 242200, 247013, 241944, 250495, 241970, 259397, 249362, 250341, 250463, 250501, 250354, 246463, 269989, 241957, 242226, 241445, 259282, 250450, 242130, 268044, 250322, 259308, 259391, 250335, 259276, 250527, 250508, 244537, 242175, 259334, 246943, 250316, 242041, 250476, 259295, 258329, 250348, 268051, 260236, 242118, 250297, 241964, 242201, 247692, 241945, 241958, 246944, 241920, 250457, 246009, 242169, 241446, 250521, 250329, 242233, 259289, 259347, 259270, 250323, 250470, 250438, 250214, 250342, 250483, 250502, 259398, 259341, 250355, 247693, 251584, 242227, 259283, 250496, 250451, 241971, 250317, 250515, 242131, 250464, 242215, 241453, 241952, 241511, 259392, 241959, 250336, 242042, 259264, 259335, 242176, 259296, 268045, 250528, 241447, 250452, 259309, 259277, 250477, 241965, 250349, 266618, 250509, 259290, 242125, 242044, 250324, 250490, 249729, 250298, 241620, 242202, 259303, 267068, 235098, 250458, 259271, 241946, 242234, 250631, 242170, 250522, 250471, 268078, 250215, 242177, 250516, 250343, 241480, 250484, 251580, 246708, 250503, 246260, 247015, 268059, 259292, 241972, 259342, 268052, 259393, 278574, 250492, 250356, 242132, 257685, 257684, 257683, 257682, 257681, 257680, 257679, 257677, 257676, 257675, 257674, 257670, 257667, 257666, 257665, 257664, 257663, 257662, 257661, 257660, 257658, 251254, 257678, 257720, 257723, 259138, 257707, 257704, 257646, 257630, 257614, 257691, 257598, 257582, 258975, 257829, 257826, 251195, 257810, 257779, 257659, 257643, 257813, 257627, 257611, 257595, 257579, 257794, 257823, 257797, 257778, 257781, 257807, 257833, 257672, 257762, 257656, 257791, 257763, 257640, 257765, 257746, 257608, 257592, 257749, 257688, 257836, 257733, 251250, 257717, 257817, 257775, 257730, 257701, 257714, 257759, 257669, 257820, 257653, 257698, 257637, 257743, 257621, 257830, 257605, 257589, 257801, 257727, 251251, 257804, 257650, 257747, 257711, 257634, 257618, 257788, 257602, 257586, 257695, 257785, 257814, 257772, 257769, 257756, 257740, 257647, 257753, 257631, 257615, 257724, 257599, 257583, 257798, 259120, 257708, 257692, 257782, 257737, 257721, 257766, 257644, 257628, 257750, 257612, 257705, 257596, 257580, 257731, 257834, 257689, 257673, 257821, 257734, 259146, 251253, 257818, 257715, 257657, 257805, 257824, 257641, 257718, 259121, 257609, 257702, 257593, 257808, 257802, 257699, 257789, 255931, 257792, 257773, 258974, 257654, 257638, 257776, 257622, 257606, 257590, 257686, 257757, 257786, 251255, 257760, 257825, 257741, 257744, 257770, 255930, 257728, 257809, 257651, 257831, 257754, 257635, 257725, 257619, 257712, 257603, 257587, 257738, 257815, 257709, 257696, 257722, 257693, 257799, 257793, 257648, 257706, 257822, 257632, 257783, 257832, 257616, 257690, 257600, 257777, 257584, 257806, 257761, 257767, 257645, 251252, 257790, 257629, 257613, 257597, 257581, 257745, 257751, 257642, 257816, 257828, 257626, 257735, 257610, 257729, 257594, 375041, 257812, 257719, 257578, 257713, 257827, 257703, 257835, 257697, 257796, 257774, 257687, 257800, 257671, 257780, 257655, 257819, 257758, 257764, 257811, 257639, 257623, 257748, 257607, 257591, 257742, 257803, 257732, 257716, 257784, 257726, 257787, 257700, 257649, 257668, 257768, 257652, 257633, 257636, 257620, 257604, 257588, 257795, 257771, 257752, 257755, 257710, 259137, 257736, 257617, 257601, 257739, 257585, 254942, 251289, 257694, 152614, 204193, 204665, 204179, 206737, 259122, 259136, 205230, 205371, 204728, 206734, 252303, 251028, 281107, 268690, 203977, 243460, 206733, 273293, 298892, 273286, 243459, 307614, 206709, 339344, 206708, 273300, 279294, 243462, 243461, 179707, 279295, 204729, 204730, 278281, 350063, 204710, 203979, 206735, 204723, 204722, 184633, 206732, 204725, 204724, 204709, 203378, 204198, 204199, 204194, 204197, 206736, 206741, 175788, 204191, 204192, 175787, 204196, 204205, 204200, 207646, 208534, 206729, 204695, 204693, 204204, 204203, 204195, 204719, 403736, 207633, 207630, 204720, 204696, 204681, 186722, 207631, 204707, 204694, 206738, 197312, 105576, 293684, 212212, 206739, 205056, 204708, 204706, 204680, 197310, 197207, 195222, 193981, 205091, 207634, 207687, 204721, 207690, 207635, 206730, 204727, 204698, 204678, 207686, 208054, 207688, 206509, 204699, 204726, 204679, 207689, 206508, 204700, 204688, 206740, 209049, 237942, 209050, 209045, 207632);
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry` IN (341376, 341375, 341373, 341374, 341371, 341372, 341369, 341370, 341368, 341367); -- Odd Crystal
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=334130; -- Detonator
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=334122; -- Bomb Location
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=341340; -- Vial of Mysterious Purple Liquid
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=341339; -- Vial of Mysterious Green Liquid
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=341338; -- Vial of Mysterious Blue Liquid
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=341337; -- Vial of Mysterious Black Liquid
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=341341; -- Vial of Mysterious Red Liquid
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry` IN (327053, 326755, 326974, 326924, 339410, 339462); -- Mailbox
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry` IN (326606, 336708); -- Torment Cell
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry` IN (334120, 334121); -- Supplies
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry` IN (334812, 334813, 334807, 335499, 334811, 334809, 334808, 334810); -- Vision Barrier
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry` IN (336907, 336908); -- Security Monolith
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=316396; -- Wall
UPDATE `gameobject_template` SET `VerifiedBuild`=61122 WHERE `entry` IN (254094, 281339, 278802, 202003, 201999, 201992, 197190, 197189, 197188, 197187, 197135, 197122, 197028, 197020, 254089, 197012, 202260, 254113, 254102, 201996, 207416, 197180, 202004, 323844, 209297, 197140, 197092, 254110, 197097, 197025, 254115, 197017, 197177, 254107, 197009, 201993, 323846, 207661, 197193, 254099, 202257, 197185, 197086, 197089, 197038, 201998, 254118, 254123, 197030, 254106, 197182, 197022, 259008, 197134, 202011, 202006, 197126, 197010, 197027, 311875, 254104, 254114, 197091, 201987, 254088, 202002, 197179, 197096, 197099, 197123, 270011, 197011, 202259, 197026, 254112, 254101, 197088, 197024, 254093, 254122, 197032, 197008, 254109, 197192, 202256, 197176, 254117, 197184, 197136, 197018, 197029, 197181, 197178, 197021, 197125, 202005, 205553, 202253, 197093, 197098, 197013, 201989, 254103, 202258, 254111, 197090, 197186, 197087, 203978, 197082, 197015, 202010, 197138, 254116, 197031, 197023, 254108, 201983, 254100, 197183, 254105, 197191, 197119, 254092, 335930, 105175, 375073, 175729, 206110, 175758, 279608, 209692, 203800, 210181, 140911, 322639, 386352, 377200, 1561, 105174, 250672, 203762, 193981, 440284, 429397, 429365, 429378, 444271, 408879, 441647, 429391, 429359, 429372, 429385, 429353, 429366, 429379, 444272, 408880, 429392, 429360, 437341, 429373, 429386, 429354, 429367, 429380, 415780, 408881, 429393, 429361, 429374, 454731, 429387, 429355, 429368, 429381, 415781, 408882, 429394, 429362, 410143, 437503, 429375, 429388, 429356, 429369, 429382, 415782, 429363, 429376, 429389, 429357, 441645, 429370, 429383, 429396, 429364, 440897, 429377, 441646, 429390, 429358, 429371, 429384, 175080, 1732, 2551, 195586, 1967, 176492, 2076, 176489, 176790, 51702, 176496, 94186, 176490, 51703, 50983, 176493, 163645, 143979, 176491, 176488, 176504, 1623, 205056, 278347, 208333, 293684, 204828, 1624, 216761, 452628, 451977, 440283, 454472, 451986, 451984, 452630, 455720, 451976, 454343, 451679, 449810, 444797, 449808, 411881, 441625, 463855, 424246, 435963, 452004, 439331, 439330, 439329, 437428, 437425, 437424, 437421, 437420, 437416, 437415, 437414, 437413, 433952, 437427, 437426, 437423, 437422, 437419, 437418, 437417, 437411, 434838, 434836, 434835, 434834, 434833, 434832, 462185, 462184, 437429, 435979, 435978, 434837, 431905, 431904, 431903, 431902, 463895, 416310, 453287, 453283, 454797, 453358, 453357, 453356, 453950, 433320, 462197, 453753, 439498, 463857, 433615, 433614, 443498, 443497, 439408, 439407, 439491, 423376, 453749, 423377, 423402, 423401, 423400, 423399, 454681, 435962, 435961, 435960, 464211, 464132, 455657, 455658, 379324, 444798, 436050, 455675, 455661, 455659, 455656, 455655, 457239, 436049, 436048, 436052, 436047, 459404, 430332, 461505, 461504, 461503, 461502, 461501, 461500, 430322, 430321, 430312, 430311, 466980, 436023, 436020, 436008, 436006, 436005, 435926, 435925, 435924, 435923, 435922, 435921, 435920, 435919, 430326, 430325, 466981, 436022, 436017, 436004, 434859, 434858, 507758, 423888, 422404, 436921, 435965, 435964, 435957, 435955, 433886, 430319, 457062, 437437, 435977, 435976, 435974, 435956, 435947, 435946, 435945, 435944, 435943, 435942, 435975, 435954, 440953, 437440, 437439, 435973, 435972, 435971, 435970, 435969, 434962, 434961, 434959, 434958, 434957, 434956, 434955, 434951, 434950, 434949, 434947, 430328, 430327, 437762, 436920, 434960, 434954, 434953, 434952, 434948, 434946, 504398, 465082, 461509, 461508, 453971, 437438, 435968, 435967, 435966, 435958, 433026, 430333, 453937, 446617, 437840, 437837, 437836, 437834, 437832, 437831, 435949, 435948, 440899, 507759, 462407, 462406, 437397, 436013, 436011, 436010, 436009, 434856, 434853, 434851, 434848, 434845, 431576, 431575, 437824, 437823, 437822, 436025, 436024, 436021, 436019, 436018, 436016, 436015, 436014, 436012, 436007, 434844, 434841, 434840, 434839, 431577, 431572, 431571, 431570, 455704, 453755, 437527, 435941, 435940, 435939, 435938, 435937, 435936, 435935, 435934, 435933, 435932, 435931, 435930, 435929, 435928, 435927, 431574, 456065, 456051, 444804, 440926, 416262, 437528, 418863, 433956, 437433, 437432, 415563, 415017, 433117, 415797, 415562, 414962, 415804, 415796, 411322, 415806, 414911, 452697, 456060, 441577, 445061, 433984, 430561, 430559, 430563, 449547, 417311, 420020, 420014, 422878, 411876, 454174, 446035, 446034, 445523, 430558, 430560, 430562, 454405, 441604, 434033, 445073, 445072, 444342, 434001, 441344, 441338, 434031, 433996, 423581, 446495, 423995, 423994, 423993, 424452, 424454, 423435, 423424, 422901, 449455, 422559, 454537, 454536, 444101, 444102, 439744, 446458, 451483, 420117, 449566, 445602, 455816, 445513, 444105, 423578, 421820, 446409, 311520, 449556, 449555, 437727, 434830, 467007, 467006, 457231, 452386, 452385, 441017, 444863, 439318, 437576, 434817, 407761, 178088, 418844, 454729, 428397, 457145, 417951, 451798, 420076, 451678, 456283, 456281, 455716, 454463, 434305, 429687, 429692, 429691, 429690, 429689, 429688, 463632, 441278, 441239, 441238, 446201, 446200, 466214, 466213, 466210, 466216, 466215, 466212, 466211, 466209, 463992, 459427, 446257, 446251, 446248, 446243, 446238, 446234, 446195, 433039, 433036, 466678, 466677, 466676, 465869, 446261, 446259, 446256, 446255, 446253, 446250, 446249, 446247, 446245, 446244, 446242, 446240, 446239, 446237, 446236, 446235, 446233, 433038, 446258, 446254, 446246, 446205, 446204, 422668, 464019, 446260, 446252, 446241, 446159, 446158, 446157, 446156, 446155, 446154, 433037, 433035, 456743, 466229, 447478, 449579, 447480, 447479, 446374, 439457, 282465, 411121, 446584, 455074, 445210, 428972, 428845, 428844, 423946, 423948, 464021, 423903, 433148, 433147, 433146, 422870, 465223, 434167, 434263, 434148, 434212, 434209, 434190, 434238, 465224, 434251, 434219, 434235, 434139, 428891, 423947, 434216, 428888, 465221, 434149, 434197, 434159, 434207, 465247, 434140, 434236, 465225, 434185, 434137, 428889, 434182, 465222, 434166, 434259, 434147, 465248, 434192, 434141, 434170, 465226, 428890, 434154, 434138, 424343, 435959, 433028, 433022, 430315, 467004, 467003, 455694, 423684, 455038, 439492, 455889, 455690, 437830, 437829, 437828, 435918, 435917, 435916, 435914, 435913, 435912, 431406, 424415, 424414, 424413, 424412, 424411, 424410, 424409, 424408, 424407, 424406, 424405, 424403, 423860, 453751, 435911, 435910, 443317, 443316, 439378, 439377, 435996, 424404, 424401, 424400, 423864, 423863, 423862, 423861, 423544, 423540, 423543, 423542, 415734, 423541, 415362, 451871, 441637, 455276, 452698, 452695, 454550, 457144, 418837, 419696, 433994, 451266, 451264, 451263, 451262, 451261, 433989, 433987, 451265, 449934, 449933, 449931, 449928, 437133, 433995, 433993, 433992, 454407, 456167, 411624, 411622, 444301, 444300, 444299, 444281, 444279, 411623, 451647, 466233, 466232, 424377, 424375, 424378, 453734, 453729, 463137, 463135, 463134, 463994, 446165, 446164, 446163, 446162, 446161, 446160, 433145, 433144, 433143, 423370, 451671, 454052, 462501, 462500, 462494, 462493, 462492, 462488, 462487, 462483, 462480, 462479, 462498, 462497, 462496, 462495, 462491, 462489, 462486, 462485, 462484, 462482, 462481, 462490, 462478, 452039, 444065, 379246, 451677, 441232, 441231, 475277, 444066, 428859, 451669, 443754, 446148, 441195, 441194, 441183, 451670, 432990, 432989, 432988, 432987, 432986, 432985, 431819, 431818, 431815, 431814, 431810, 431809, 431808, 452652, 452651, 452650, 452649, 454394, 429698, 429697, 429696, 429695, 429694, 429693, 429686, 453062, 451672, 463887, 453747, 453367, 444197, 243307, 204356, 203695, 203700, 203702, 203701, 203694, 203698, 203696, 375181, 204962, 214501, 207871, 207870, 203692, 203623, 203616, 203691, 203693, 207872, 207869, 203454, 207656, 207657, 202748, 204862, 204861, 204860, 204859, 203985, 203418, 202749, 202788, 203137, 202897, 202736, 203218, 203399, 203400, 204851, 203735, 203398, 203402, 204848, 204850, 203397, 203401, 203372, 205144, 281205, 250568, 232235, 232234, 232224, 281204, 281164, 278311, 273282, 271723, 232225, 227909, 227908, 227907, 227906, 273855, 278328, 298865, 278333, 278325, 278324, 452030, 339222, 316736, 278332, 278331, 278330, 278329, 278327, 278326, 278310, 273853, 350063, 203751, 218719, 294556, 296065, 214405, 204281, 214404, 207693, 207691, 206594, 281118, 207695, 207694, 207692, 201690, 201685, 201678, 201677, 201658, 201650, 201655, 190536, 201652, 201688, 201657, 201659, 201651, 201656, 201822, 201665, 201664, 201663, 201662, 201661, 201660, 175753, 201654, 201653, 201649, 201648, 201647, 201646, 201645, 201644, 201643, 201642, 201641, 180665, 175761, 175752, 175746, 175738, 175735, 175730, 175727, 21583, 21582, 21581, 2657, 321748, 3800, 3799, 206987, 1940, 1731, 206373, 1617, 209571, 179964, 180026, 179965, 1733, 1807, 1619, 265575, 3817, 1620, 149424, 22668, 22667, 22666, 22665, 22662, 22661, 22660, 22659, 3819, 3818, 3816, 3815, 2489, 22544, 22543, 22541, 22540, 3802, 3801, 204368, 112235, 204371, 112241, 179780, 92703, 112236, 112237, 2015, 112231, 47, 112215, 112205, 22835, 204364, 204367, 112232, 112204, 112201, 204363, 60, 32, 112200, 204365, 22832, 22833, 204370, 179781, 204366, 142093, 179779, 204369, 37118, 204362, 179778, 2062, 112238, 22836, 2014, 1726, 112234, 22834, 22831, 112239, 204350, 204395, 180655, 175739, 204355, 204442, 154357, 289682, 278575, 180663, 203838, 204441, 204582, 204352, 312345, 175745, 1621, 204435, 204344, 206509, 205090, 204689, 3301, 207690, 206739, 206738, 205091, 204722, 197257, 50805, 50804, 50803, 207689, 206732, 206508, 204720, 204719, 204192, 204191, 202717, 197278, 206539, 207687, 204706, 204698, 202814, 208270, 202798, 197323, 197310, 204614, 206546, 204632, 197307, 204643, 202813, 197312, 206538, 197259, 204727, 210059, 206530, 204679, 204635, 207631, 204695, 204619, 202803, 202811, 204939, 197315, 204634, 197280, 204700, 197322, 206740, 204608, 206549, 204196, 202816, 197314, 204204, 204941, 204708, 197261, 204684, 204936, 204938, 202808, 204637, 202800, 204616, 204613, 204721, 197309, 206729, 202805, 207633, 204681, 202802, 207414, 207686, 210058, 204726, 204618, 204678, 204631, 208054, 207630, 207646, 208534, 204694, 202810, 197311, 197287, 207635, 197279, 204195, 197285, 204699, 204607, 206548, 204203, 204707, 202815, 197207, 204615, 202799, 207688, 197284, 204688, 197276, 204680, 204940, 202812, 207632, 204696, 204200, 197260, 204636, 204612, 202804, 206545, 206529, 204693, 204633, 197313, 202817, 204937, 202809, 204617, 202801, 208269, 223739, 186722, 195222, 209045, 237942, 208806, 403736, 339239, 105576, 384744, 209049, 212212, 208807, 186238, 209050, 203969, 206608, 207889, 223814, 206547, 196837, 197286, 152614, 207634, 206609, 204205, 206730, 206610, 382266, 410356, 410348, 381653, 380455, 380454, 380453, 380449, 379330, 379329, 379019, 377118, 382276, 380452, 380448, 376833, 384275, 379027, 378880, 382267, 382274, 381736, 382271, 380451, 381086, 378876, 384276, 382275, 378868, 402891, 401761, 401760, 401759, 401758, 386477, 386475, 386474, 386473, 386389, 386381, 386380, 386379, 383589, 383588, 383587, 383585, 409010, 384963, 384962, 383599, 383592, 383591, 383590, 383586, 382306, 382261, 378882, 378879, 378878, 376187, 382260, 379024, 381031, 378890, 378889, 378887, 378886, 378885, 378883, 390256, 378888, 378884, 379126, 383605, 381033, 380985, 405378, 383602, 409034, 382182, 381030, 380982, 255306, 383615, 381027, 380979, 381187, 383596, 380976, 383612, 381146, 381184, 383593, 376417, 380986, 421718, 405593, 383609, 381149, 380973, 383606, 380970, 381034, 378871, 380983, 409027, 383603, 383594, 376746, 381028, 383600, 378264, 380980, 383597, 376753, 379022, 383613, 381025, 380977, 381185, 380974, 377123, 381182, 413963, 381147, 383607, 380987, 380971, 381035, 405380, 383610, 381032, 383604, 380984, 405489, 383601, 381029, 376418, 380981, 381026, 380978, 383614, 383598, 376927, 381186, 382168, 380975, 383611, 383595, 381183, 380823, 378263, 381148, 383608, 380988, 380972, 268690, 206733, 204624, 243460, 273293, 298892, 273286, 204625, 206709, 243459, 207101, 307614, 207099, 204620, 339344, 206708, 204723, 207100, 279295, 279294, 273300, 243462, 207098, 207097, 207096, 207094, 204724, 204627, 204626, 179707, 204729, 204628, 204725, 243461, 206741, 204730, 204621, 204623, 206735, 204622, 204710, 204640, 203979, 278281, 206736, 204709, 204197, 204606, 204639, 204198, 204605, 204194, 175788, 175787, 204610, 206995, 204609, 204604, 269949, 204611, 204209, 204199, 203378, 202590, 184633, 204603, 204602, 377216, 281340, 206725, 204657, 204601, 204600, 204214, 204210, 204207, 323852, 204662, 323849, 206726, 204646, 204208, 204163, 204656, 204211, 323853, 204202, 206727, 204215, 323850, 204650, 204663, 204647, 205108, 204212, 323851, 204651, 204664, 205109, 204213, 205142, 204655, 383583, 323855, 204201, 179881, 495326, 495325);
UPDATE `gameobject_template` SET `VerifiedBuild`=60822 WHERE `entry` IN (375062, 375659, 373472, 375344, 370409, 375213, 375661, 375066, 375540, 375251, 370390, 375482, 375069, 375203, 375248, 375060, 370494, 375252, 370500, 375032, 375058, 375208, 373502, 370014, 375343, 375061, 375483, 370411, 375068, 373592, 373471, 375253, 375529, 357293, 357277, 365154, 365155, 365157, 365156, 352745, 352746, 369536, 369533, 353485, 354922, 369530, 369527, 353479, 357271, 353476, 357300, 364497, 353489, 354923, 369531, 369534, 367758, 353483, 357275, 357291, 369528, 353480, 353477, 353493, 353490, 369535, 375407, 353487, 357263, 354924, 369532, 357292, 345444, 353822, 364423, 374520, 345445, 353406, 353823, 364424, 374521, 374518, 367754, 364422, 374519, 357095, 364499, 364419, 369529, 354921, 353481, 369526, 353750, 353478, 353494, 357270, 320950, 284701, 327231, 294168, 327230, 302766, 290623, 296905, 281869, 292904, 293983, 282771, 292584, 289332, 290811, 277419, 281560, 276616, 290815, 289529, 289558, 281867, 316905, 252237, 244916, 246567, 244439, 244604, 242987, 244601, 254867, 244440, 244441, 246280, 254868, 246566, 242990, 242989, 254865, 243873, 245170, 245686, 254866, 246401, 244692, 244694, 246485, 246486, 290416, 292908, 284440, 290418, 240018, 240017, 236209, 236208, 236207, 236189, 234023, 234119, 237486, 224707, 234022, 227271, 236143, 227071, 232552, 240009, 234110, 223508, 224359, 228571, 225924, 227272, 236912, 237485, 234111, 222690, 234109, 234021, 349278, 204388, 204351, 204403, 204295, 1804, 1733, 1801, 1732, 1805, 204384, 204383, 207485, 1806, 204350, 204425, 204424, 1820, 204346, 1819, 204349, 177253, 177049, 177048, 177047, 176901, 259235, 259236, 259234, 177252, 177251, 177250, 177249, 177246, 177245, 1809, 184164, 178572, 177248, 177247, 177203, 176633, 176578, 32, 260287, 207208, 204347, 179487, 289682, 176579, 176577, 204355, 176694, 176580, 37118, 278575, 179781, 179779, 179778, 175739, 154357, 112236, 112235, 112234, 112232, 112231, 112204, 112201, 2062, 2015, 2014, 112205, 60, 312345, 204371, 204369, 204367, 204366, 204365, 204362, 180655, 179780, 112241, 112239, 112238, 112237, 112215, 112200, 92703, 22836, 22831, 1622, 204370, 204368, 204364, 204363, 204345, 175745, 157968, 142093, 22835, 22834, 22833, 22832, 22544, 22543, 22541, 22540, 1808, 1726, 1620, 47, 265574, 204352, 149424, 22668, 22667, 22666, 22665, 22662, 22661, 22660, 22659, 3819, 3818, 3817, 3816, 3815, 2489, 1807, 180663, 3802, 3801, 1621, 204441, 203838, 204582, 204442, 265575, 204435, 204395, 204344, 175751, 170351, 170350, 170349, 170348, 170347, 22638, 22623, 22622, 22606, 22605, 22604, 22603, 22602, 1562, 180025, 22538, 22537, 22536, 22535, 178526, 56, 176793, 20923, 1948, 170073, 3800, 1731, 1618, 3799, 1617, 1619, 197145, 197144, 197143, 197141, 197137, 197124, 202010, 197142, 197133, 197132, 197131, 278802, 202004, 201989, 197193, 197192, 197191, 197190, 197189, 197188, 197187, 197173, 197172, 197139, 197122, 197118, 197138, 197126, 197121, 197120, 197116, 281339, 197175, 197174, 197147, 197146, 197134, 197117, 270011, 250672, 205107, 203978, 202260, 202259, 202258, 202257, 202256, 202253, 197150, 197149, 197148, 197140, 197135, 197123, 205106, 203800, 197186, 197185, 197180, 197179, 197119, 205553, 197184, 197183, 197182, 197181, 197178, 197177, 197176, 197136, 197125, 403736, 254112, 254109, 197018, 254111, 386352, 377200, 254123, 254122, 207661, 197099, 197098, 197097, 197024, 197023, 197022, 197021, 175758, 175729, 197010, 197042, 197074, 254086, 197087, 197055, 197036, 1561, 197068, 294556, 254080, 197081, 197017, 197049, 323846, 197030, 197062, 203801, 197043, 197011, 197075, 259008, 332224, 197088, 323840, 197056, 197037, 197069, 335930, 197082, 197050, 398823, 197031, 197063, 254068, 212212, 197076, 197044, 197012, 254081, 243297, 197025, 197089, 323841, 197057, 197038, 355054, 197070, 254082, 197083, 197051, 197096, 197064, 197032, 197013, 197077, 197045, 323842, 197026, 197090, 197058, 197039, 197007, 322639, 197071, 209692, 243324, 197020, 197084, 197052, 243305, 197033, 197065, 105174, 197014, 197078, 197046, 245923, 243299, 323843, 197027, 311875, 197091, 197059, 253168, 197040, 197072, 197008, 193981, 197085, 197053, 197034, 197066, 243294, 197015, 254084, 197079, 105175, 197047, 243300, 197028, 323844, 197092, 197060, 253169, 197041, 197009, 197073, 254085, 206110, 197086, 383582, 197054, 197035, 197067, 243295, 279608, 207416, 421496, 197080, 197048, 203762, 210181, 243301, 197029, 197093, 323845, 197061, 252281, 250403, 250406, 250396, 268047, 251212, 251209, 250417, 250405, 250402, 250401, 250400, 250399, 250398, 251210, 250407, 250404, 250395, 269969, 268054, 259375, 251211, 250397, 248855, 247564, 248852, 247558, 248858, 247579, 259369, 250390, 244950, 250391, 259377, 259374, 259373, 259372, 248860, 248859, 248857, 247572, 266129, 259358, 259371, 248933, 259365, 250387, 259359, 247571, 250303, 259361, 268079, 268060, 268368, 250389, 259362, 369303, 248522, 248523, 251304, 248822, 250388, 250312, 250304, 259352, 259355, 259354, 259360, 250311, 259376, 250308, 250392, 259370, 250309, 259357, 259364, 259356, 259353, 259367, 242030, 250307, 250310, 242029, 259366, 259379, 259378, 259368, 259363, 250393, 250306, 250305, 250302, 250301, 250261, 250260, 250259, 250258, 253969, 248856, 226911, 250394, 259240, 268066, 253968, 252663, 248842, 248843, 245355, 259345, 259351, 245368, 244824, 242648, 248844, 259346, 242220, 259284, 259834, 259285, 247848, 242639, 248841, 247849, 245353, 242640, 242127, 248093, 242641, 242638, 242050, 242637, 245661, 242128, 245662, 259390, 249919, 246002, 250514, 242636, 268057, 245691, 268067, 382535, 382534, 382533, 382532, 382531, 269037, 268065, 259387, 259380, 259349, 259348, 258330, 250513, 250435, 247691, 245663, 242123, 242054, 242049, 242048, 242047, 188215, 266851, 242045, 250499, 259383, 250467, 194115, 280797, 268048, 259395, 250339, 259287, 246941, 245623, 250320, 242224, 241949, 250218, 266736, 250519, 259312, 250525, 259280, 246154, 250480, 241968, 268087, 250333, 241943, 259415, 259293, 242237, 268074, 250455, 251581, 250493, 259338, 250461, 246013, 268081, 268049, 259306, 250359, 259274, 251594, 242231, 249732, 250506, 250474, 247018, 242052, 250346, 250314, 242218, 250487, 244561, 250500, 242366, 242199, 250468, 242039, 242046, 267991, 259396, 258327, 266705, 250340, 241419, 246942, 250481, 259268, 241956, 252331, 246257, 250436, 251582, 248516, 250494, 242129, 250462, 250353, 259281, 250449, 250526, 250321, 246001, 242225, 241969, 244536, 268043, 259384, 259275, 250334, 251595, 259288, 250507, 242040, 259294, 247019, 259262, 241950, 247858, 242200, 250347, 241944, 244562, 259339, 259307, 250315, 250219, 244651, 241963, 251992, 250520, 246008, 250456, 269989, 250322, 250360, 241951, 250328, 241957, 242232, 241445, 259416, 258328, 246943, 250482, 259269, 250469, 247013, 250501, 246258, 259397, 250341, 241970, 242130, 247692, 250495, 249362, 250463, 250354, 242226, 246463, 259282, 250450, 250527, 268044, 259391, 259276, 250335, 242175, 250508, 259295, 259334, 244537, 259308, 242041, 250476, 259289, 242118, 260236, 258329, 241958, 250316, 250297, 250348, 241964, 242201, 241945, 242227, 184633, 250457, 241446, 259283, 246009, 250521, 250451, 250329, 242233, 242169, 259296, 241971, 250528, 259270, 250470, 250438, 250214, 250502, 259398, 259347, 250342, 259341, 259392, 250323, 247693, 242044, 268051, 250336, 241965, 250483, 242215, 250515, 242131, 259264, 250355, 241959, 242176, 246944, 250509, 250631, 241920, 242125, 250516, 250349, 242042, 251584, 250496, 250464, 241952, 250471, 250484, 235098, 247797, 250215, 250317, 241453, 250458, 246708, 241946, 250503, 268045, 259309, 250522, 259277, 250477, 246260, 242234, 247015, 242170, 259335, 241480, 250343, 266618, 241972, 259290, 250490, 250298, 242202, 268078, 249729, 268052, 241511, 242132, 241921, 241447, 251580, 250356, 259303, 259271, 259342, 251585, 242228, 268059, 259310, 250497, 250452, 246465, 259278, 242216, 250492, 250478, 250324, 241620, 241953, 241966, 241512, 242037, 245832, 278574, 259393, 259381, 250460, 250337, 268046, 259265, 242177, 250510, 251105, 246945, 235099, 242126, 267068, 250350, 250459, 241948, 369301, 241947, 250318, 259304, 243374, 250523, 268053, 250524, 259272, 250485, 259292, 250331, 251624, 250299, 266619, 251592, 242235, 259317, 259835, 254236, 259291, 250491, 242043, 250517, 250504, 249730, 246261, 250472, 241960, 259343, 250453, 250344, 241506, 268072, 259336, 250216, 250319, 242223, 241922, 259426, 269967, 250357, 242229, 250498, 250217, 246466, 241513, 241954, 250313, 245833, 259394, 259311, 250338, 259279, 259266, 242236, 250479, 268086, 248079, 250332, 250300, 268073, 250511, 266761, 250351, 251311, 241967, 249731, 259305, 259273, 244560, 242172, 251593, 244534, 235100, 250473, 259344, 259382, 241961, 200297, 259286, 250505, 247337, 259350, 242051, 251305, 250512, 250345, 242198, 242038, 259337, 250576, 259267, 369302, 250518, 241955, 246262, 250454, 250358, 242230, 250352, 268061, 251312, 239174, 291276, 316841, 303133, 187376, 316680, 295670, 295668, 298939, 298916, 298903, 298902, 290461, 290460, 290459, 290458, 281455, 298900, 298899, 295677, 295676, 295675, 295674, 295673, 295672, 295671, 295667, 295666, 295665, 295664, 294368, 294021, 290736, 282450, 269178, 295678, 298943, 298901, 369894, 298947, 298942, 298946, 298944, 298941, 298940, 297749, 296060, 297718, 297719, 297745, 295684, 297714, 295680, 295564, 297721, 297717, 297715, 297762, 319233, 319229, 297758, 297754, 297720, 296061, 295685, 297750, 295681, 297716, 297746, 297722, 297763, 319230, 297759, 297712, 297755, 297760, 295682, 297751, 295562, 295818, 297747, 297756, 299267, 233778, 269026, 334950, 272799, 299268, 319231, 297752, 297713, 297761, 295683, 295679, 297757, 295563, 295819, 297748, 297753, 319232);
UPDATE `gameobject_template` SET `Data13`=3000, `VerifiedBuild`=60822 WHERE `entry`=375348; -- Door
UPDATE `gameobject_template` SET `ContentTuningId`=835, `VerifiedBuild`=60822 WHERE `entry`=322725; -- SI:7 Listening Device
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=60822 WHERE `entry` IN (293842, 293839); -- Ordinary Pebble
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=60822 WHERE `entry`=277313; -- Spirit Obelisk
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=60822 WHERE `entry`=280348; -- The Word of Zul I
UPDATE `gameobject_template` SET `VerifiedBuild`=60568 WHERE `entry` IN (323844, 197038, 197037, 197033, 254110, 197089, 254099, 201993, 197017, 197193, 202257, 259008, 323846, 197086, 201998, 254118, 254104, 197030, 254123, 197126, 254088, 197182, 197022, 202011, 197134, 202006, 254101, 197096, 197027, 197179, 254093, 254112, 197099, 197123, 197088, 254109, 270011, 202259, 197011, 311875, 197091, 202003, 201987, 254117, 197024, 207661, 201992, 197176, 197029, 197136, 197032, 197008, 254106, 197192, 202256, 197184, 197010, 201989, 197013, 197093, 254114, 202002, 197181, 254103, 197021, 197125, 197026, 202005, 202253, 254095, 197178, 209692, 1561, 190536, 206110, 105175, 322639, 279608, 250672, 294556, 210181, 386352, 377200, 175758, 193981, 203800, 208377, 175729, 335930, 140911, 208379, 203762, 105174, 208378, 197098, 202258, 197186, 254111, 254122, 254116, 197018, 197090, 202010, 197138, 197087, 197015, 254108, 201999, 197031, 254100, 197023, 201983, 254105, 197183, 197191, 254089, 254092, 197028, 254113, 197020, 209297, 197180, 201996, 197097, 197140, 197012, 202260, 197025, 202004, 197092, 197185, 254115, 254102, 207416, 205553, 254094, 254107, 197009, 197177, 186238, 298892, 273293, 243460, 207101, 207100, 207099, 206733, 206709, 204723, 204625, 204624, 197280, 197276, 339344, 243459, 206538, 197284, 307614, 204626, 204620, 273286, 243462, 197287, 273300, 206708, 207098, 206549, 207094, 204204, 279294, 243461, 204627, 197257, 179707, 197323, 206546, 206539, 207097, 204633, 279295, 207096, 197279, 206545, 204634, 204724, 204632, 204729, 204725, 204631, 204730, 206741, 204628, 202717, 206530, 204621, 204623, 206735, 206729, 204195, 204203, 204622, 204192, 278281, 350063, 203979, 204640, 204191, 206736, 204710, 204709, 204196, 204200, 204205, 204607, 204197, 204606, 204610, 204194, 204605, 175787, 204639, 175788, 204198, 204608, 204609, 184633, 204611, 203378, 204604, 206995, 202590, 204209, 204199, 269949, 204603, 204602, 204214, 204210, 377216, 281340, 206725, 204657, 204601, 204600, 204207, 206737, 204666, 204665, 204658, 204645, 204193, 204179, 205109, 204213, 204655, 323855, 204201, 323849, 207414, 204662, 204163, 204208, 204656, 204202, 323850, 204650, 204215, 204663, 323851, 204651, 204664, 203969, 383583, 323852, 223814, 206726, 204646, 204211, 323853, 206727, 204647, 205108, 204212, 175080, 205142, 179881, 223739, 206608, 206609, 206610, 495326, 428859, 455720, 451976, 451986, 451984, 451977, 452630, 452628, 440283, 465187, 411881, 449808, 423641, 441347, 433775, 443312, 443311, 445103, 443309, 451670, 451662, 410834, 463876, 463864, 454579, 453921, 463884, 463875, 454562, 454561, 453052, 453046, 453042, 453036, 453035, 453033, 422477, 454701, 453051, 453050, 453049, 453047, 453045, 453044, 453043, 453041, 453040, 453038, 453037, 453034, 451661, 451660, 453048, 453039, 463883, 463882, 463881, 463880, 463877, 454560, 454557, 463878, 410287, 463879, 454583, 454581, 454577, 451698, 454584, 454578, 451773, 451692, 451796, 451559, 442669, 455631, 452847, 452015, 438047, 466716, 465100, 456236, 452844, 437052, 465097, 456089, 452505, 456086, 455734, 453814, 453782, 453190, 455731, 453779, 445075, 444355, 455632, 452016, 466717, 456237, 452845, 438045, 465098, 456234, 452506, 456087, 453815, 453191, 452503, 445076, 455732, 453780, 455633, 466718, 452846, 438046, 466715, 456088, 465099, 456235, 434501, 349097, 454472, 453816, 453192, 452504, 435013, 455733, 453813, 453781, 453189, 437234, 453573, 455634, 452018, 449810, 238047, 231913, 232588, 232582, 232591, 232586, 232358, 229069, 228493, 232587, 236416, 232589, 238046, 236415, 236414, 232356, 232355, 232354, 232583, 231215, 232359, 232357, 228571, 234023, 239326, 234022, 227071, 228563, 237485, 224359, 223508, 234111, 237486, 227271, 234021, 236143, 227272, 232552, 240009, 222690, 234109, 236912, 224707, 225924, 234110, 251028, 203977, 209124, 268690, 281107, 209114, 179965, 207889, 196837, 152614, 206529);
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=454072; -- Sporefused Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=454055; -- Luredrop
UPDATE `gameobject_template` SET `VerifiedBuild`=60490 WHERE `entry` IN (455731, 453779, 452844, 455632, 466717, 456237, 452505, 453190, 465098, 456234, 456087, 453815, 455732, 452016, 453780, 455633, 454472, 452845, 452506, 466718, 466715, 465099, 456235, 453191, 452503, 456088, 453816, 455733, 453813, 453781, 434501, 466716, 452846, 455634, 465100, 456236, 455631, 465097, 456089, 453192, 452504, 349097, 453189, 453573, 456086, 455734, 452018, 453814, 453782, 452847, 452015, 441292, 435020, 441289, 435017, 435014, 444013, 441290, 435018, 441287, 435015, 441291, 435019, 441288, 435016, 435013, 445179, 452122, 444011, 444012, 454747, 443864, 443865, 441734, 441710, 444779, 445024, 449810, 445076, 453147, 453144, 453138, 453137, 453135, 453134, 453133, 445075, 438047, 438046, 438045, 453141, 453140, 453136, 453139, 453918, 444355, 451920, 445007, 437234, 437233, 437232, 437231, 437052, 437049, 422811, 322188, 322682, 317061, 322187, 317062, 317060, 317058, 317053, 317050, 317048, 317047, 316864, 316789, 276234, 282470, 291210, 282469, 282468, 328429, 281703, 296877, 294713, 294712, 294711, 291132, 280915, 282255, 282256, 280917, 280912, 187376, 292545, 280587, 280648, 280647, 279578, 296850, 296851, 296849, 296852, 279335, 278405, 278506, 276242, 296878, 295800, 295799, 295798, 278402, 276619, 276240, 296838, 296836, 296834, 296856, 296839, 296837, 296835, 294716, 295064, 280546, 296831, 295068, 295065, 295062, 296832, 295069, 295066, 295063, 281079, 295060, 296833, 295070, 296830, 295067, 296827, 296858, 296829, 296828, 295071, 295061, 296859, 296857, 327231, 327230, 296244, 281778, 281701, 276616, 276239, 290623, 284701, 322681, 253126, 277419, 292902, 292901, 295778, 276238, 321755, 321735, 321733, 321732, 312156, 301134, 321724, 321719, 321753, 321734, 321754, 321730, 321721, 321720, 321718, 317398, 294490, 239174, 294491, 294489, 316424, 299322, 294887, 299265, 294951, 302791, 295399, 292871, 295054, 299342, 365070, 311171, 316430, 295086, 294900, 301127, 299259, 302945, 295361, 293844, 316904, 272925, 295048, 365064, 295022, 294485, 299253, 295093, 288469, 296155, 293838, 298882, 294856, 294888, 294952, 292872, 295432, 295055, 365071, 299343, 295087, 299260, 323548, 294492, 325968, 293552, 302946, 295362, 365065, 281065, 295049, 295023, 301135, 294543, 299254, 295094, 302940, 325967, 294275, 321795, 294857, 294889, 302857, 294953, 301129, 295056, 312208, 299344, 295088, 298915, 294998, 295414, 281609, 299261, 294493, 292547, 302947, 295363, 295050, 239178, 304023, 365066, 278570, 292695, 298914, 295024, 294896, 294544, 298909, 323383, 298883, 299255, 295095, 294973, 302941, 295357, 309572, 298980, 294954, 295018, 301130, 294890, 302858, 288433, 294481, 295089, 295057, 297145, 294999, 298910, 294807, 303018, 303146, 299262, 294948, 302948, 295364, 295051, 239179, 365067, 323531, 299008, 295025, 294897, 295409, 294545, 321797, 298884, 295096, 299256, 294974, 296478, 302942, 295358, 369893, 298885, 294891, 295019, 301131, 313618, 299250, 295090, 229465, 282246, 281647, 287435, 188215, 298911, 299263, 299257, 294949, 302949, 292869, 295052, 365068, 303145, 299009, 294898, 294546, 295097, 316429, 294905, 294975, 298886, 282258, 316422, 306854, 293132, 296460, 279586, 316427, 299251, 295091, 316423, 302839, 295417, 295481, 321760, 297937, 295053, 299264, 298912, 294950, 302790, 295398, 292870, 302950, 279717, 365069, 298881, 280662, 298913, 282465, 294963, 294899, 295411, 293965, 299258, 295098, 294976, 302944, 295360, 303207, 295469, 294484, 303017, 299252, 295092, 403736, 398823, 190536, 197043, 421496, 197042, 197039, 197040, 197034, 197041, 197035, 212212, 323845, 197036, 197037, 323841, 197038, 355054, 197077, 323842, 197033, 197078, 323843, 383582, 332224, 323846, 323844, 323840, 197055, 197054, 197052, 197015, 197010, 197007, 197053, 197057, 197061, 197073, 197056, 197051, 197059, 197050, 197087, 197071, 197070, 197047, 197060, 197075, 197076, 197044, 197046, 197072, 197058, 197086, 197063, 197049, 197048, 197065, 197062, 197074, 197064, 197088, 197066, 197045, 197069, 197067, 197068, 208564, 208384, 208385, 208567, 208566, 208565, 208383, 254114, 254113, 254112, 254108, 1561, 197014, 197079, 197084, 197085, 254110, 197080, 197083, 254111, 197081, 254123, 197082, 197093, 105174, 197092, 197096, 311875, 197017, 105175, 197089, 197091, 197090, 197009, 254109, 335930, 322639, 254122, 254118, 254117, 205107, 205106, 197097, 197020, 197013, 197012, 197008, 197120, 197172, 197025, 197147, 197173, 197026, 197174, 197027, 197149, 197028, 258986, 197118, 197032, 197150, 197175, 197146, 197030, 197148, 197029, 193981, 197031, 197011, 207661, 175729, 175758, 197024, 197023, 197125, 197098, 386352, 377200, 197099, 197119, 197186, 201982, 201513, 197117, 197018, 197021, 197022, 202011, 197135, 197183, 197176, 197181, 197182, 197178, 197184, 197179, 197177, 197180, 197185, 209297, 197116, 203978, 197132, 140911, 197133, 197131, 205553, 270011, 202260, 202259, 202258, 202257, 202256, 202253, 197140, 197136, 197134, 197123, 197121, 201506, 202053, 201509, 201508, 202054, 202001, 202000, 201999, 201998, 207720, 201514, 197122, 197137, 250672, 197139, 202002, 197138, 201989, 197126, 197191, 197192, 197193, 197190, 197189, 197188, 197187, 202005, 201986, 202047, 202060, 201983, 201503, 201500, 207721, 207718, 201987, 201523, 202058, 202010, 202052, 202004, 202059, 202056, 207723, 207719, 202055, 202051, 202006, 202003, 201996, 201994, 201993, 201992, 201985, 202050, 202063, 202064, 202061, 202045, 201997, 384744, 278802, 207722, 201991, 202049, 202062, 202046, 201995, 202048, 202028, 202027, 202026, 202025, 202024, 202023, 201512, 201511, 202018, 201980, 202035, 202019, 202013, 201981, 202014, 202036, 202020, 202021, 202034, 202033, 202016, 202022, 202017, 202030, 202032, 202015, 202031, 202029, 206623, 202012, 202008, 202009, 202007, 231870, 201422, 281304, 1684, 201494, 201496, 209042, 201493, 201488, 201489, 201495, 201492, 209049, 201490, 201491, 209043, 209053, 209051, 209050, 209048, 209047, 209046, 209045, 209044, 209041, 209040, 202758, 209101, 209054, 209052, 201460, 201459, 201458, 201457, 201456, 201455, 201454, 175739, 206560, 203762, 202274, 202273, 202272, 202271, 202270, 202267, 201421, 201420, 201419, 201418, 201417, 201416, 201415, 92011, 218719, 204988, 203976, 281339, 204987, 203801, 201682, 201681, 201450, 201449, 193585, 193584, 193583, 180047, 201689, 201684, 201683, 201675, 201674, 201672, 201478, 201477, 201453, 201452, 201451, 201448, 201447, 201446, 201445, 201694, 201693, 201692, 201691, 201690, 201673, 201479, 201476, 201475, 201474, 201680, 201679, 201676, 201484, 201482, 205105, 205104, 204281, 201485, 201483, 201481, 201480, 201463, 201462, 201461, 201686, 201678, 201654, 201646, 201659, 207695, 201651, 201643, 3800, 207692, 201688, 201656, 201648, 201685, 201677, 2657, 201653, 201645, 201658, 207694, 201650, 201642, 296065, 206110, 21582, 271817, 203800, 210181, 175752, 292763, 214404, 206594, 175761, 281118, 175727, 21583, 208377, 180665, 214405, 251289, 175730, 175746, 208378, 21581, 175738, 293701, 175735, 294556, 208379, 209692, 279608, 207691, 3799, 201687, 201655, 201647, 207416, 201652, 259008, 201644, 207693, 201657, 201649, 201641, 295562, 295563, 298836, 298835, 295598, 297685, 312290, 312223, 312222, 281872, 310705, 326210, 316497, 297722, 297721, 288591, 291273, 291157, 291156, 291155, 239176, 298916, 298943, 369894, 298939, 298947, 316680, 298946, 298944, 298942, 298941, 298940, 298903, 298902, 298901, 298900, 298899, 297760, 297759, 297758, 294021, 297757, 297756, 297755, 297754, 297753, 297752, 297751, 297749, 327189, 316841, 303133, 297763, 297762, 297761, 297750, 297748, 297747, 297746, 297745, 291276, 269026, 319233, 319232, 319230, 319229, 290461, 290460, 290459, 290458, 281455, 272799, 295679, 299267, 295680, 294368, 295595, 295681, 295596, 295597, 269178, 297713, 297715, 297718, 297717, 297719, 297714, 299268, 319231, 297720, 297716, 297712, 296061, 296060, 295685, 295684, 295683, 295682, 290736, 282450, 295678, 295675, 295674, 295677, 295676, 295672, 295673, 295665, 295666, 295664, 295671, 295667, 365073, 295670, 295669, 295668, 365074, 365075, 295577, 365076, 295575, 295576, 334950, 269179, 303132, 295568, 297802, 295569, 297803, 295570, 297804, 297805, 268897, 297806, 297794, 297807, 297801, 297800, 297799, 297798, 297797, 297796, 297795, 295553, 295552, 295551, 295550, 295549, 292803, 292802, 278554, 269110, 269108, 194431, 290679, 334890, 334868, 334884, 328382, 289522, 233778, 334882, 334892, 334867, 325654, 280948, 289521, 289697, 281073, 180904, 281071, 281072, 281077, 325722, 281074, 281078, 281075, 281076, 302975, 302974, 327526, 293344, 289326, 279684, 279682, 290705, 327525, 298838, 298837, 298822, 298821, 298819, 298818, 279675, 298810, 298820, 301078, 298812, 298814, 298805, 298815, 298811, 301073, 301083, 301079, 298816, 298817, 301075, 301087, 301084, 298823, 301076, 301081, 298803, 301085, 298839, 298840, 301082, 218387, 290816, 298804, 298824, 298834, 298832, 298831, 298828, 298827, 298826, 298825, 298813, 298809, 298808, 298807, 298806, 298798, 298797, 298796, 298795, 298794, 298793, 298792, 298791, 296293, 290848, 310516, 304055, 302859, 298833, 298830, 298829, 298802, 298801, 298800, 298799, 298790, 298789, 298788, 298787, 298786, 298785, 298784, 298783, 291115, 302976, 302973, 298844, 298843, 298842, 298841, 290812, 303219, 290706, 280640, 299065, 299049, 299064, 299050, 296883, 299051, 299048, 322601, 301123, 309703, 296889, 296888, 296895, 303130, 296891, 296882, 316746, 316747, 316745, 316744, 299054, 299053, 299052, 299047, 296880, 316984, 316983, 316982, 279674, 272677, 295648, 295647, 295646, 295657, 295656, 295556, 289558, 280525, 279351, 280528, 280527, 280526, 280533, 280517, 295662, 280524, 295663, 289529, 292584, 287147, 280529, 280523, 279690, 279605, 279340, 278177, 303131, 295661, 295660, 295659, 280536, 280521, 280520, 280519, 299063, 299033, 299032, 299031, 299030, 280518, 279339, 271111, 299062, 276618, 292904, 287154, 287153, 287150, 280601, 278790, 278789, 295574, 295573, 295572, 295571, 290678, 290703, 272401, 325476, 278404, 296666, 296665, 296664, 296663, 296662, 296661, 296660, 296659, 282771, 292816, 252237, 299037, 281869, 296682, 289332, 316905, 299038, 325471, 290811, 296683, 281560, 293983, 290815, 276620, 293849, 292825, 281177, 293831, 293829, 281166, 277858, 271943, 281870, 282221, 282248, 282229, 282249, 282230, 282231, 282199, 282193, 282206, 282200, 282213, 282194, 282207, 282218, 282217, 282208, 282216, 282215, 282205, 282234, 282235, 282201, 282195, 282196, 282222, 282227, 282226, 282219, 282198, 282223, 282224, 282214, 282197, 282236, 282212, 291001, 282237, 282233, 282232, 282228, 282225, 282220, 282211, 282210, 282209, 282204, 282203, 282202, 281210, 281189, 276237, 276186, 277857, 287256, 291057, 291058, 281868, 281867, 292916, 292914, 292911, 293962, 271866, 292917, 276621, 325418, 280992, 302780, 294530, 294529, 294528, 302838, 236184, 277717, 277415, 294837, 277427, 294838, 277386, 294925, 295115, 287404, 327519, 297573, 297572, 297571, 297570, 297569, 297568, 297567, 297566, 297564, 297563, 297562, 293775, 293759, 290974, 281638, 297574, 297565, 294922, 294895, 294894, 294811, 207453, 278695, 207440, 207438, 294726, 294934, 294933, 294932, 294931, 294855, 294853, 294852, 294850, 294828, 294824, 294823, 294822, 294821, 294820, 294819, 294815, 294741, 294730, 294386, 294373, 294372, 294371, 294370, 294829, 294827, 294826, 294825, 294818, 294816, 294814, 294812, 294804, 294849, 294851, 294813, 295430, 294854, 294848, 295449, 295431, 294846, 294845, 294844, 294806, 294805, 294736, 294399, 294398, 301053, 295484, 295474, 294727, 294401, 294397, 294396, 294402, 294400, 299318, 299317, 299306, 303143, 303142, 303051, 299315, 299314, 299313, 299309, 299308, 299307, 298873, 297784, 297724, 296952, 294390, 294389, 266403, 293749, 303044, 294743, 294724, 294723, 299320, 299312, 299311, 299310, 295520, 295519, 295518, 295517, 241319, 299316, 294369, 294382, 294383, 299319, 301052, 301051, 301050, 297273, 296949, 294395, 294393, 294392, 294391, 294377, 294375, 294374, 301043, 297215, 297197, 294403, 294379, 294376, 301045, 301044, 301042, 297526, 297525, 297179, 297177, 297176, 312127, 296566, 214679, 298888, 320928, 298889, 298880, 298879, 298878, 298876, 295408, 284447, 281308, 298877, 303048, 303050, 303054, 316428, 303073, 303062, 303058, 302797, 295002, 294967, 302796, 294964, 302799, 295003, 295010, 295008, 302801, 302798, 302800, 302802, 302803, 295418, 295043, 295040, 295039, 295038, 295037, 295036, 294908, 294907, 294909, 295032, 295031, 295030, 295029, 294971, 294966, 294965, 294882, 294881, 294865, 294970, 281464, 295460, 295114, 295113, 295112, 295111, 295110, 294959, 294947, 294927, 294926, 294937, 281909, 303084, 294936, 294924, 294835, 288641, 294906, 279318, 279319, 301133, 301132, 295486, 295476, 295020, 294977, 294960, 303085, 295473, 295471, 295470, 295462, 294946, 295487, 295461, 295028, 297905, 295415, 294969, 294968, 294238, 294237, 294248, 295717, 295718, 295719, 295720, 295401, 295402, 294246, 294247, 294239, 295467, 294253, 295021, 294240, 294961, 294245, 294243, 294847, 294244, 294242, 294241, 294944, 294858, 303001, 303008, 303002, 302996, 303009, 303003, 295478, 302997, 303004, 302999, 303006, 303000, 302994, 303007, 316675, 303013, 303012, 303011, 303010, 303005, 302998, 302995, 301137, 301136, 295479, 294916, 294915, 294914, 294913, 294912, 294911, 294910, 294904, 294903, 294902, 302795, 295121, 295120, 269098, 213637, 302793, 292915, 302794, 293755, 297635, 294957, 335633, 335632, 335631, 302792, 294958, 279593, 335634, 290675, 321725, 335630, 294901, 295715, 295714, 295365, 295017, 295016, 295015, 294997, 294996, 294993, 294992, 294956, 294930, 294234, 294233, 294232, 294231, 292910, 288632, 295716, 294995, 294994, 301128, 294972, 294955, 295013, 302952, 302951, 295734, 295733, 295732, 295730, 295729, 295728, 295727, 295726, 295725, 295724, 295723, 295722, 295721, 295475, 295464, 295420, 295419, 295109, 295108, 295107, 295012, 295011, 295731, 287123, 294962, 295400, 294874, 294880, 294869, 294878, 294877, 294862, 294873, 294876, 294861, 294879, 296223, 295457, 295456, 295454, 295080, 295079, 294982, 294979, 294943, 294875, 294872, 294871, 294867, 294808, 295453, 295026, 294988, 294987, 292913, 294990, 294866, 295027, 294840, 294942, 294938, 281095, 299281, 299282, 299283, 299284, 303043, 299280, 297169, 303057, 303056, 303053, 303047, 303045, 303041, 303040, 299285, 298977, 298976, 298974, 298973, 298972, 298971, 298970, 295468, 295001, 295000, 294940, 294860, 294859, 303128, 303127, 303126, 303125, 303122, 303060, 298975, 298969, 298968, 292912, 279594, 295075, 279587, 303121, 298990, 303063, 303052, 303064, 303055, 303077, 303076, 303075, 303074, 303067, 303066, 303065, 303061, 303059, 303049, 303042, 299288, 299287, 299286, 299279, 298994, 298993, 298992, 298991, 298989, 294935, 294834, 294833, 294831, 297178, 295129, 295142, 294830, 295130, 295131, 295144, 295145, 294832, 295132, 295128, 295154, 295153, 295152, 295151, 295150, 295149, 295148, 295147, 295146, 295143, 295141, 295127, 295126, 295125, 295119, 295118, 295117, 295116, 297283, 297257, 297224, 297173, 297160, 294465, 294464, 298986, 298985, 298984, 297228, 297214, 294463, 294462, 298988, 298987, 298983, 297275, 297263, 297252, 297249, 297240, 297234, 297233, 297232, 297231, 297167, 297163, 297278, 297277, 297268, 297254, 297253, 297250, 297241, 297236, 297230, 297229, 297192, 297251, 297248, 297208, 295078, 295077, 295076, 298982, 298981, 295529, 295422, 295532, 295322, 295161, 295160, 295159, 295158, 295157, 295156, 295155, 281551, 302971, 302970, 302969, 302968, 294794, 294793, 294792, 294790, 294783, 294764, 294763, 302963, 302962, 302958, 294791, 294789, 302967, 302966, 302965, 302964, 302961, 302960, 302959, 302957, 302956, 290803, 296095, 296094, 296093, 296082, 296068, 295797, 295796, 295795, 295353, 278399, 278479, 295331, 281230, 295325, 295324, 294745, 294739, 294734, 294732, 294731, 297479, 294737, 276622, 278571, 292686, 292673, 266281, 294738, 295085, 284469, 284463, 299305, 299298, 299297, 299296, 299295, 299292, 299290, 295531, 295530, 295769, 295763, 295406, 295770, 295413, 295758, 295765, 295759, 299293, 295766, 299294, 295403, 295767, 299289, 295404, 295768, 295762, 295405, 299321, 299304, 299303, 299302, 299301, 299300, 299299, 299291, 297906, 295777, 295776, 295775, 295774, 295773, 295771, 295764, 295761, 295760, 295757, 295756, 295426, 284453, 295772, 295755, 295753, 295526, 295427, 295754, 295433, 295074, 295073, 295072, 295528, 295425, 295424, 295423, 287328, 311196, 296133, 296132, 296129, 295525, 295429, 294291, 294288, 294287, 294283, 294278, 292676, 279347, 295412, 294290, 294289, 294282, 294281, 294280, 294279, 294277, 294276, 311193, 296126, 295527, 311195, 298979, 298978, 296125, 294506, 294505, 294504, 294503, 294502, 294501, 294500, 294499, 294498, 294497, 294496, 294495, 294494, 296127, 296114, 296112, 296123, 303523, 307430, 307431, 296111, 294758, 295123, 295122, 294800, 294785, 295124, 294766, 294765, 294762, 294788, 294787, 294786, 294761, 294754, 294753, 295814, 295813, 295812, 295811, 295810, 278406, 296153, 295804, 295803, 307257, 304010, 294784, 294760, 294759, 294757, 307490, 295428, 294755, 294752, 281674, 292873, 215396, 271621, 271626, 320324, 296138, 296136, 294782, 296131, 296130, 294756, 320325, 296154, 296137, 296106, 271623, 297140, 296135, 271619, 271616, 321747, 311565, 311561, 320513, 319256, 307784, 296139, 273917, 276617, 276236, 294214, 320323, 294221, 294215, 296143, 294222, 311876, 294216, 297141, 296144, 294223, 295708, 294217, 321840, 296158, 295709, 311878, 320326, 293846, 294218, 295710, 294219, 289572, 293120, 295711, 294220, 311881, 282483, 245975, 294273, 294257, 297041, 294262, 297000, 294267, 297051, 297035, 297701, 297077, 294264, 294274, 294258, 294261, 297045, 297042, 294255, 297039, 294265, 294268, 297036, 297049, 297046, 297152, 294259, 297072, 294254, 294272, 294256, 297040, 296998, 233789, 294266, 297037, 297050, 296999, 297073, 294263, 294260, 298935, 298930, 298933, 298932, 298934, 298931, 444800, 454578, 463637, 410396, 463879, 463878, 463863, 463883, 463882, 463881, 463877, 463876, 454701, 454580, 454560, 454557, 453048, 453040, 453039, 453034, 451661, 451660, 410834, 463875, 454561, 453051, 453050, 453049, 453047, 453045, 453044, 453043, 453042, 453041, 453038, 453037, 463884, 463864, 454562, 453921, 453052, 453046, 453036, 453035, 453033, 451662, 422477, 454579, 445103, 443309, 452985, 452984, 452627, 452626, 451987, 451979, 451978, 451985, 451983, 451981, 454343, 449808, 423641, 411881, 451670, 454394, 402903, 402901, 398822, 398821, 376713, 441563, 439390, 452697, 434912, 434914, 419787, 419786, 418844, 451669, 452706, 441558, 441557, 441556, 441555, 433776, 433774, 457120, 454223, 454414, 454222, 454187, 451937, 445552, 437119, 437116, 433912, 423350, 433911, 423428, 451675, 422548, 429060, 429059, 376979, 384308, 202805, 207889, 204186, 204180, 204164, 204177, 206574, 204190, 204174, 204187, 204184, 204181, 204165, 204178, 126050, 1617, 203471, 206575, 204175, 204188, 204189, 204185, 126051, 204166, 252071, 204176, 152614, 204941, 204940, 202816, 202817, 207690, 207688, 207687, 207686, 207635, 206508, 205091, 204689, 202814, 202813, 202812, 202811, 50805, 50803, 3301, 208054, 206739, 206738, 205090, 204706, 204678, 204643, 50804, 204680, 204679, 190549, 175080, 281183, 281182, 204694, 202804, 202803, 252303, 281107, 268690, 251028, 208396, 339344, 307614, 298892, 273300, 273293, 273286, 243462, 243461, 243460, 243459, 206709, 206708, 203977, 204729, 279294, 279295, 206734, 204730, 204620, 204624, 207101, 207099, 204627, 207100, 204700, 207094, 204726, 204727, 204721, 204625, 202815, 207634, 207098, 204698, 202810, 179707, 204699, 207632, 207097, 207096, 197261, 207148, 237942, 207149, 197260, 207147, 204626, 204719, 207150, 204688, 207146, 206733, 204720, 204681, 206730, 204722, 202802, 206740, 206732, 204723, 204937, 197307, 293684, 205056, 197259, 204696, 204695, 204938, 204936, 207633, 208270, 202808, 204939, 202809, 197285, 208269, 186722, 197286, 197311, 197309, 206547, 197314, 206548, 197322, 197310, 197278, 197207, 197276, 197257, 197315, 202800, 202801, 197312, 197280, 206529, 204724, 204628, 197313, 105576, 207630, 204725, 206549, 206538, 202799, 197279, 197287, 197284, 202798, 197323, 206539, 206546, 206545, 208534, 204693, 202717, 210058, 204633, 204634, 206741, 204623, 204631, 204632, 204621, 206735, 206530, 204622, 210059, 207646, 204204, 204192, 204203, 350063, 278281, 206729, 204195, 206736, 204196, 204709, 204197, 203979, 204191, 204710, 204640, 204607, 204606, 204200, 204198, 204205, 204608, 204610, 204194, 204604, 204611, 204605, 203378, 175787, 204639, 175788, 206995, 204609, 269949, 204603, 204209, 204199, 202590, 184633, 204602, 377216, 204214, 281340, 206725, 204657, 204601, 204600, 204210, 204207, 206737, 204666, 204665, 204658, 204645, 204193, 204179, 205109, 204213, 204655, 323855, 204201, 323849, 207414, 204662, 204163, 204208, 204656, 204202, 323850, 204650, 204215, 204663, 323851, 204651, 186238, 204664, 383583, 323852, 203969, 223814, 206726, 204646, 204211, 323853, 206727, 204647, 205108, 204212, 205142, 179881, 223739, 206608, 206609, 206610, 113771, 113768, 113769, 415058, 113770);
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=454076; -- Mycobloom
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry` IN (291246, 291244); -- Small Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=282153; -- Sunken Strongbox
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=296853; -- Forge
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=296848; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296845; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296844; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296843; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296842; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296840; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=60490 WHERE `entry` IN (293842, 293839); -- Ordinary Pebble
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=296847; -- Forge
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=280927; -- Thundershot Rifle
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296841; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=280925; -- Tidal Blade
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=296739; -- Forge
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=280545; -- Harpoons
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=296738; -- Forge
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=280926; -- Abyssal Spear
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=290537; -- Help Wanted
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=280727; -- Charred Note
UPDATE `gameobject_template` SET `ContentTuningId`=705, `VerifiedBuild`=60490 WHERE `entry`=291257; -- Small Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry` IN (281213, 280754); -- Honey Soaked Boot
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=280646; -- Brewmaster's Treatise Vol. 1
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=281235; -- Crystalized Honey Fragment
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=280929; -- Rough Map
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=296162; -- Bee Pheromones
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=298774; -- Raimond's Secret Ingredient
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=280736; -- Bee Hive
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry`=302954; -- Blacktooth Brawler Stash
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294488; -- Chair
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294486; -- Chair
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294487; -- Chair
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294482; -- Chair
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294483; -- Chair
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=60490 WHERE `entry`=251222; -- Tent
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=60490 WHERE `entry`=251045; -- Alliance Banner
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=340451; -- Ethereal Portal
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=337225; -- Gusting Winds Totem
UPDATE `gameobject_template` SET `Data0`=466601, `Data5`=131923, `VerifiedBuild`=61265 WHERE `entry`=332214; -- Portal to Caverns of Time
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry` IN (329915, 329912, 329913, 329914, 329911, 327425); -- Barricade
UPDATE `gameobject_template` SET `ContentTuningId`=737, `VerifiedBuild`=61265 WHERE `entry`=334390; -- Catapult
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61265 WHERE `entry`=414338; -- Irradiated Blessing Blossom
UPDATE `gameobject_template` SET `Data10`=445022, `VerifiedBuild`=61265 WHERE `entry`=386349; -- Trading Post Post
UPDATE `gameobject_template` SET `Data0`=466601, `Data5`=131923, `VerifiedBuild`=61265 WHERE `entry`=332214; -- Portal to Caverns of Time
UPDATE `gameobject_template` SET `ContentTuningId`=2651, `VerifiedBuild`=61265 WHERE `entry`=355229; -- Portal to Oribos
UPDATE `gameobject_template` SET `Data5`=127988, `VerifiedBuild`=61265 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414327; -- Crystallized Orbinid
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454055; -- Luredrop
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454076; -- Mycobloom
UPDATE `gameobject_template` SET `Data2`=1, `VerifiedBuild`=61122 WHERE `entry`=463979; -- Lightspark Sky Academy Gradebook
UPDATE `gameobject_template` SET `Data11`=1, `VerifiedBuild`=61122 WHERE `entry`=411930; -- Blackpowder Barrel
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454086; -- Blessing Blossom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454070; -- Lush Mycobloom
UPDATE `gameobject_template` SET `Data2`=6, `Data3`=8, `VerifiedBuild`=61122 WHERE `entry`=451680; -- Royal Ripple
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414336; -- Irradiated Luredrop
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454079; -- Irradiated Blessing Blossom
UPDATE `gameobject_template` SET `Data18`=0, `VerifiedBuild`=61122 WHERE `entry`=444345; -- Hitching Post
UPDATE `gameobject_template` SET `Data18`=0, `VerifiedBuild`=61122 WHERE `entry`=434009; -- Hitching Post
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=423368; -- Sporefused Orbinid
UPDATE `gameobject_template` SET `Data18`=0, `VerifiedBuild`=61122 WHERE `entry`=444352; -- Hitching Post
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414329; -- Crystallized Arathor's Spear
UPDATE `gameobject_template` SET `Data2`=0, `VerifiedBuild`=61122 WHERE `entry`=430596; -- Crusher
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414324; -- Lush Arathor's Spear
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414321; -- Lush Luredrop
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414326; -- Crystallized Luredrop
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=413875; -- Rich Aqirite
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454010; -- Luredrop
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=413047; -- Aqirite
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454069; -- Irradiated Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=430351; -- Webbed Ore Deposit
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=413895; -- EZ-Mine Aqirite
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=430335; -- Webbed Ore Deposit
UPDATE `gameobject_template` SET `size`=1, `VerifiedBuild`=61122 WHERE `entry` IN (429587, 429586, 429579, 429573, 429572, 429568, 429578, 429569); -- Bench
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414317; -- Orbinid
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=413880; -- Bismuth Seam
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414323; -- Lush Blessing Blossom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414322; -- Lush Orbinid
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454071; -- Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454064; -- Sporefused Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414315; -- Mycobloom
UPDATE `gameobject_template` SET `name`='Notes On The Machine Speakers II', `VerifiedBuild`=61122 WHERE `entry`=455274; -- Notes On The Machine Speakers: Fragment II
UPDATE `gameobject_template` SET `Data10`=121783, `VerifiedBuild`=61122 WHERE `entry`=443532; -- Rusted Lever
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414339; -- Irradiated Arathor's Spear
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=413900; -- Crystallized Ironclaw
UPDATE `gameobject_template` SET `type`=3, `Data0`=3585, `Data1`=0, `Data2`=1, `Data6`=0, `Data13`=1, `Data17`=0, `Data18`=0, `Data23`=0, `Data26`=469343, `Data29`=6262, `Data30`=123993, `Data31`=1, `VerifiedBuild`=61122 WHERE `entry`=444773; -- Jade Pearl
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414319; -- Arathor's Spear
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=413905; -- EZ-Mine Ironclaw
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=125891, `VerifiedBuild`=61122 WHERE `entry`=454502; -- Radiant Prism Crystal
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414338; -- Irradiated Blessing Blossom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=413049; -- Ironclaw
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=430352; -- Webbed Ore Deposit
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=454062; -- Lush Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414335; -- Irradiated Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=413883; -- Crystallized Bismuth
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=61122 WHERE `entry`=414325; -- Crystallized Mycobloom
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203699; -- Ancient Conduit
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203622; -- Falling Rocks
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203456; -- Stonespeaker's Luring Totem
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28630, `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=202896; -- Sambino's Air Valve
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203395; -- Alliance S.E.A.L. Equipment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29511, `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203032; -- Glimmerdeep Clam
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=202871; -- Sunken Crate
UPDATE `gameobject_template` SET `IconName`='questinteract', `Data1`=0, `Data22`=89801, `VerifiedBuild`=61122 WHERE `entry`=202766; -- Braided Rope
UPDATE `gameobject_template` SET `Data1`=0, `Data18`=683, `Data30`=39344, `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=207542; -- Runestone Treasure Chest
UPDATE `gameobject_template` SET `Data26`=1, `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203212; -- Highborne Tablet
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203305; -- Crucible of Nazsharin
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29644, `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203373; -- Idra'kess Weapon Rack
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203309; -- Nespirah Abscess
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=202916; -- Sandy Mound
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203391; -- High Priestess Siralen
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203388; -- Queen Azshara
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203386; -- Lestharia Vashj
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry` IN (203213, 203210, 203211); -- Highborne Tablet
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203390; -- Ranger Valarian
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=203301; -- Naga Tridents
UPDATE `gameobject_template` SET `ContentTuningId`=53, `VerifiedBuild`=61122 WHERE `entry`=202887; -- Air Source
UPDATE `gameobject_template` SET `Data5`=923, `ContentTuningId`=482, `VerifiedBuild`=61122 WHERE `entry`=206595; -- Portal to Tol Barad
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=60822 WHERE `entry`=293970; -- Azerite Chunk
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=60822 WHERE `entry`=281904; -- Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=60822 WHERE `entry` IN (224708, 224705, 224706); -- Tribal Stone
UPDATE `gameobject_template` SET `Data10`=445022, `VerifiedBuild`=60568 WHERE `entry`=386349; -- Trading Post Post
UPDATE `gameobject_template` SET `Data0`=466601, `Data5`=131923, `VerifiedBuild`=60568 WHERE `entry`=332214; -- Portal to Caverns of Time
UPDATE `gameobject_template` SET `ContentTuningId`=2651, `VerifiedBuild`=60568 WHERE `entry`=355229; -- Portal to Oribos
UPDATE `gameobject_template` SET `Data5`=127988, `VerifiedBuild`=60568 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60568 WHERE `entry`=454076; -- Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60568 WHERE `entry`=414325; -- Crystallized Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60568 WHERE `entry`=413047; -- Aqirite
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60568 WHERE `entry`=413892; -- Weeping Aqirite
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60568 WHERE `entry`=454072; -- Sporefused Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60568 WHERE `entry`=454055; -- Luredrop
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=60490 WHERE `entry`=277313; -- Spirit Obelisk
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=60490 WHERE `entry`=278461; -- Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=60490 WHERE `entry`=297493; -- Tales of de Loa: Shadra
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=299017; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=299018; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=60490 WHERE `entry`=279522; -- Sethrak Cage
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=60490 WHERE `entry`=279352; -- Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=191, `VerifiedBuild`=60490 WHERE `entry` IN (291008, 273992); -- Terrace Fountain
UPDATE `gameobject_template` SET `ContentTuningId`=336, `VerifiedBuild`=60490 WHERE `entry`=268635; -- Campfire
UPDATE `gameobject_template` SET `ContentTuningId`=191, `VerifiedBuild`=60490 WHERE `entry`=287238; -- Ancient Altar
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry`=278361; -- Discarded Rucksack
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry`=278359; -- Roughneck Axe
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry`=278357; -- Bloodied Boot
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=60490 WHERE `entry`=296066; -- Personal Anchor
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry`=293852; -- Buried Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry`=278809; -- Roughneck Supplies
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry` IN (290782, 290781, 290780, 290777); -- Ball and Chain
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=294978; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=294920; -- Anvil
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294488; -- Chair
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294487; -- Chair
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294486; -- Chair
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294483; -- Chair
UPDATE `gameobject_template` SET `Data4`=69068, `VerifiedBuild`=60490 WHERE `entry`=294482; -- Chair
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=294918; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=294917; -- Forge
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry`=293131; -- Pepe
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry` IN (292674, 292675, 292677); -- A Damp Scroll
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=60490 WHERE `entry`=293978; -- Azerite Node
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=60490 WHERE `entry`=281485; -- Stormsong Mead
UPDATE `gameobject_template` SET `ContentTuningId`=467, `VerifiedBuild`=60490 WHERE `entry`=292826; -- Portal to Plunder Harbor
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=60490 WHERE `entry`=304011; -- Totem of Fair Wind
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296110; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=296156; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296109; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296107; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=60490 WHERE `entry`=293973; -- Azerite Chunk
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=60490 WHERE `entry`=278495; -- Stack of Blight Barrels
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=60490 WHERE `entry`=307029; -- Blight Barrel
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=296145; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=294774; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=294799; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=294776; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=294775; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=60490 WHERE `entry`=294773; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60490 WHERE `entry`=296108; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=60490 WHERE `entry`=311543; -- Alliance Azerite Cache
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=93992, `ContentTuningId`=706, `VerifiedBuild`=60490 WHERE `entry`=307028; -- Azerite Grenades
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=60490 WHERE `entry`=312155; -- Gallywix's Getaway Pack
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=60490 WHERE `entry`=307837; -- Weapon Rack
UPDATE `gameobject_template` SET `ContentTuningId`=1241, `VerifiedBuild`=60490 WHERE `entry`=288639; -- Treasure Rich Flotsam
UPDATE `gameobject_template` SET `ContentTuningId`=830, `VerifiedBuild`=60490 WHERE `entry`=296479; -- Lord Admiral's Footlocker
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=61265 WHERE `entry` IN (257849, 257852, 257850, 257853, 257854, 257851); -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `Data0`=466601, `Data5`=131923, `VerifiedBuild`=61265 WHERE `entry`=332214; -- Portal to Caverns of Time
UPDATE `gameobject_template` SET `Data5`=127988, `VerifiedBuild`=61265 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `Data10`=445022, `VerifiedBuild`=61265 WHERE `entry`=386349; -- Trading Post Post
UPDATE `gameobject_template` SET `Data5`=923, `ContentTuningId`=482, `VerifiedBuild`=61265 WHERE `entry`=206595; -- Portal to Tol Barad
UPDATE `gameobject_template` SET `VerifiedBuild`=61188 WHERE `entry` IN (1618, 190549, 186238, 21680, 204183, 204182, 207889, 375041, 383583, 323853, 323850, 210181, 204664, 204663, 323851, 323849, 223814, 223739, 204662, 204657, 204656, 204655, 204651, 204650, 204646, 203969, 204178, 204185, 204665, 206737, 204177, 126050, 204193, 206574, 204166, 204190, 204174, 126051, 204179, 204165, 204187, 204666, 204184, 204176, 204186, 204645, 203471, 204658, 206575, 1617, 252071, 204647, 323855, 204175, 205108, 204189, 204188, 204180, 204181, 204164, 323852, 206608, 152614, 206609, 206610);
UPDATE `gameobject_template` SET `ContentTuningId`=2651, `VerifiedBuild`=61188 WHERE `entry`=355229; -- Portal to Oribos
UPDATE `gameobject_template` SET `Data5`=127988, `VerifiedBuild`=61188 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `Data0`=466601, `Data5`=131923, `VerifiedBuild`=61188 WHERE `entry`=332214; -- Portal to Caverns of Time
UPDATE `gameobject_template` SET `Data10`=445022, `VerifiedBuild`=61122 WHERE `entry`=386349; -- Trading Post Post
UPDATE `gameobject_template` SET `ContentTuningId`=2651, `VerifiedBuild`=61122 WHERE `entry`=355229; -- Portal to Oribos
UPDATE `gameobject_template` SET `Data0`=466601, `Data5`=131923, `VerifiedBuild`=61122 WHERE `entry`=332214; -- Portal to Caverns of Time
UPDATE `gameobject_template` SET `Data5`=127988, `VerifiedBuild`=61122 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `ContentTuningId`=73, `VerifiedBuild`=60822 WHERE `entry`=55; -- A half-eaten body
UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=60568 WHERE `entry`=230644; -- Power Crystal
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=63, `VerifiedBuild`=60568 WHERE `entry`=236755; -- Dusty Lockbox
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=63, `VerifiedBuild`=60568 WHERE `entry`=226861; -- Ronokk's Belongings
UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=60568 WHERE `entry` IN (224708, 224705, 224706); -- Tribal Stone
UPDATE `gameobject_template` SET `Data5`=127988, `VerifiedBuild`=60568 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `Data10`=445022, `VerifiedBuild`=60568 WHERE `entry`=386349; -- Trading Post Post
UPDATE `gameobject_template` SET `Data5`=127988, `VerifiedBuild`=60568 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `Data10`=445022, `VerifiedBuild`=60568 WHERE `entry`=386349; -- Trading Post Post
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=413890; -- Crystallized Aqirite
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=413047; -- Aqirite
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=454075; -- Lush Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=454076; -- Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=413875; -- Rich Aqirite
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=413883; -- Crystallized Bismuth
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=414322; -- Lush Orbinid
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=454072; -- Sporefused Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=430351; -- Webbed Ore Deposit
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=414325; -- Crystallized Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=413905; -- EZ-Mine Ironclaw
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=414324; -- Lush Arathor's Spear
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=414336; -- Irradiated Luredrop
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=414319; -- Arathor's Spear
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=414337; -- Irradiated Orbinid
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=414315; -- Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=413049; -- Ironclaw
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=454064; -- Sporefused Mycobloom
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=413900; -- Crystallized Ironclaw
UPDATE `gameobject_template` SET `Data10`=121783, `VerifiedBuild`=60490 WHERE `entry`=443532; -- Rusted Lever
UPDATE `gameobject_template` SET `Data23`=0, `VerifiedBuild`=60490 WHERE `entry`=414317; -- Orbinid
UPDATE `gameobject_template` SET `Data5`=923, `ContentTuningId`=482, `VerifiedBuild`=60490 WHERE `entry`=206595; -- Portal to Tol Barad
UPDATE `gameobject_template` SET `Data10`=445022, `VerifiedBuild`=60490 WHERE `entry`=386349; -- Trading Post Post
UPDATE `gameobject_template` SET `Data0`=466601, `Data5`=131923, `VerifiedBuild`=60490 WHERE `entry`=332214; -- Portal to Caverns of Time
UPDATE `gameobject_template` SET `ContentTuningId`=2651, `VerifiedBuild`=60490 WHERE `entry`=355229; -- Portal to Oribos
UPDATE `gameobject_template` SET `Data5`=127988, `VerifiedBuild`=60490 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `VerifiedBuild`=60428 WHERE `entry` IN (204658, 204189, 204165, 55615, 252071, 204193, 204175, 204188, 204177, 204187, 204186, 204176, 204164, 203855, 204166, 204174, 204184, 204190, 152614, 204185, 206575, 206574, 204181, 126051, 126050, 204183, 204178, 204182, 203471, 1618, 1731, 375041, 1617);

DELETE FROM `gameobject_questitem` WHERE (`Idx`=10 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=9 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=8 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=7 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=6 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=5 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=4 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=3 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=2 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=1 AND `GameObjectEntry` IN (499022,499954)) OR (`Idx`=0 AND `GameObjectEntry` IN (499022,415584,425875,499954,524391,416310,411930,422559,421820,424343,411624,411622,411623,454502,449528));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(499022, 10, 225741, 61265), -- Corrupted Chest
(499022, 9, 225741, 61265), -- Corrupted Chest
(499022, 8, 225741, 61265), -- Corrupted Chest
(499022, 7, 225741, 61265), -- Corrupted Chest
(499022, 6, 225741, 61265), -- Corrupted Chest
(499022, 5, 225741, 61265), -- Corrupted Chest
(499022, 4, 225741, 61265), -- Corrupted Chest
(499022, 3, 225741, 61265), -- Corrupted Chest
(499022, 2, 225741, 61265), -- Corrupted Chest
(499022, 1, 225741, 61265), -- Corrupted Chest
(499022, 0, 225741, 61265), -- Corrupted Chest
(415584, 0, 211863, 61122), -- Sizzling Magma Core
(425875, 0, 216720, 60490), -- Priority Transport Crate
(499954, 10, 225741, 61265), -- Corrupted Chest
(499954, 9, 225741, 61265), -- Corrupted Chest
(499954, 8, 225741, 61265), -- Corrupted Chest
(499954, 7, 225741, 61265), -- Corrupted Chest
(499954, 6, 225741, 61265), -- Corrupted Chest
(499954, 5, 225741, 61265), -- Corrupted Chest
(499954, 4, 225741, 61265), -- Corrupted Chest
(499954, 3, 225741, 61265), -- Corrupted Chest
(499954, 2, 225741, 61265), -- Corrupted Chest
(499954, 1, 225741, 61265), -- Corrupted Chest
(499954, 0, 225741, 61265), -- Corrupted Chest
(524391, 0, 225741, 61265), -- Prize Chest
(416310, 0, 215446, 61122), -- Kobyss Chest
(411930, 0, 213630, 61122), -- Blackpowder Barrel
(422559, 0, 213209, 61122), -- Grub Eggs
(421820, 0, 213209, 61122), -- Grub Eggs
(424343, 0, 216687, 61122), -- Medical Supplies
(411624, 0, 210734, 61122), -- Machinist Plinth
(411622, 0, 210732, 61122), -- Machinist Plinth
(411623, 0, 210733, 61122), -- Machinist Plinth
(454502, 0, 225663, 61122), -- Radiant Prism Crystal
(449528, 0, 224074, 61122); -- Opal-Mining Tools

UPDATE `gameobject_questitem` SET `VerifiedBuild`=61265 WHERE (`Idx`=0 AND `GameObjectEntry` IN (250417,245368,244824,266619,250576,249729,203977,203979,203969));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=61188 WHERE (`GameObjectEntry`=203969 AND `Idx`=0);
UPDATE `gameobject_questitem` SET `VerifiedBuild`=61122 WHERE (`Idx`=0 AND `GameObjectEntry` IN (203979,203969,202896,203032,203373,205144,203751,203800,344604,321748,32,204350,154357,204352,278802,105175,140911,105174,203762));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=60822 WHERE (`Idx`=1 AND `GameObjectEntry`=204388) OR (`Idx`=0 AND `GameObjectEntry` IN (204388,204350,204425,204424,204346,32,204347,154357,204345,204352,1562,176793,278802,203800,203801,105174,105175,203762,250417,245368,244824,249729,266619,250576,223508));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=60568 WHERE (`Idx`=0 AND `GameObjectEntry` IN (223508,203977,203979,203969,105175,203800,140911,203762,105174));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=60490 WHERE (`Idx`=0 AND `GameObjectEntry` IN (203977,203979,203969,316746,316747,316745,316744,325476,292917,277427,316430,316424,316423,316422,313618,323548,323383,312208,281909,312155,280927,280925,280545,280926,280646,280754,298774,280736,105174,105175,140911,278802,203762,203801,203800)) OR (`Idx`=1 AND `GameObjectEntry`=280736);


UPDATE `page_text` SET `VerifiedBuild`=60822 WHERE `ID` IN (3650, 3649, 3648);

