-- 
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (94927,100876,107024,114251,114284,115022,123120,161088,177716,180640,197255,198611,198918,208623,210792,211063,211087,211261,211262,211263,213892,213893,213894,213895,213932,213934,214761,214762,215203,215407,216333,216364,219034,221203,223819,223821,223994,223995,224340,224342,224343,225605,225606,225663,227474,227487,228386,228537,228538,228539,228540,232388,232733,235700,235707,238187,241342,241343,241384,242616,243146,243552,244101,244111,244113,244115,244137,244410,244411,244415,244416,244418,245510,245967,246212,246285,247046,247409,247457,247458,247478,248453,248539)) OR (`ID`=2 AND `CreatureID` IN (208623,248453)) OR (`ID`=3 AND `CreatureID`=208623);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(94927, 1, 116913, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Crusher
(100876, 1, 40497, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Val'kyr Battlemaiden
(107024, 1, 139007, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Fel Lord
(114251, 1, 31038, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Galindre
(114284, 1, 25587, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Elfyra
(115022, 1, 92961, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- The Monkey King
(123120, 1, 2705, 0, 0, 3756, 0, 0, 0, 0, 0, 63305), -- Bloodsail Drunk
(161088, 1, 230658, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Hologram
(177716, 1, 184571, 0, 0, 184571, 0, 0, 0, 0, 0, 63305), -- So' Cartel Assassin
(180640, 1, 108956, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Stormbound Breaker
(197255, 1, 0, 0, 0, 0, 0, 0, 200629, 0, 0, 63305), -- Shikari Eilakar
(198611, 1, 65492, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Marshal Joan Cleardawn
(198918, 1, 10823, 0, 0, 18825, 0, 0, 0, 0, 0, 63305), -- Maximillian of Northshire
(208623, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Brewfest Celebrant
(208623, 2, 33022, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Brewfest Celebrant
(208623, 3, 2202, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Brewfest Celebrant
(210792, 1, 0, 0, 0, 95495, 0, 0, 0, 0, 0, 63305), -- Professor Instructaur
(211063, 1, 118560, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Fungal Podling
(211087, 1, 72296, 0, 0, 107813, 0, 0, 0, 0, 0, 63305), -- Speaker Shadowcrown
(211261, 1, 185434, 0, 0, 72585, 0, 0, 0, 0, 0, 63305), -- Ascendant Vis'coxria
(211262, 1, 61370, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Ixkreten the Unbreakable
(211263, 1, 185383, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Deathscreamer Iken'tak
(213892, 1, 197816, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Shadowmage
(213893, 1, 176599, 0, 0, 176586, 0, 0, 0, 0, 0, 63305), -- Nightfall Darkcaster
(213894, 1, 138757, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Curseblade
(213895, 1, 169044, 0, 0, 169044, 0, 0, 0, 0, 0, 63305), -- Nightfall Shadowalker
(213932, 1, 222910, 0, 0, 222915, 0, 0, 0, 0, 0, 63305), -- Sureki Militant
(213934, 1, 220499, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Tactician
(214761, 1, 159930, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Ritualist
(214762, 1, 220501, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Commander
(215203, 1, 220694, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Wildhammer Gryphon Rider
(215407, 1, 221769, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Ki'katal the Harvester
(216333, 1, 50227, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Bloodstained Assistant
(216364, 1, 214502, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Blood Overseer
(219034, 1, 222912, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Web Marauder
(221203, 1, 221768, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Balaxir the Bully
(223819, 1, 208978, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Izo'ratne Abductor
(223821, 1, 180157, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Ritualist
(223994, 1, 197816, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Shadowmage
(223995, 1, 138757, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Curseblade
(224340, 1, 1959, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Minertaur
(224342, 1, 62484, 0, 0, 46861, 0, 0, 0, 0, 0, 63305), -- Herbataur
(224343, 1, 7005, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Skinnaur
(225605, 1, 176599, 0, 0, 176586, 0, 0, 0, 0, 0, 63305), -- Nightfall Darkcaster
(225606, 1, 169044, 0, 0, 169044, 0, 0, 0, 0, 0, 63305), -- Nightfall Shadowalker
(225663, 1, 208978, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Ascension Enforcer
(227474, 1, 222911, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Ascension Researcher
(227487, 1, 224497, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Underkeep Technician
(228386, 1, 155763, 0, 0, 155791, 0, 0, 0, 0, 0, 63305), -- Brother Pike
(228537, 1, 169044, 0, 0, 169044, 0, 0, 0, 0, 0, 63305), -- Nightfall Shadowalker
(228538, 1, 138757, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Curseblade
(228539, 1, 176599, 0, 0, 176586, 0, 0, 0, 0, 0, 63305), -- Nightfall Darkcaster
(228540, 1, 197816, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nightfall Shadowmage
(232388, 1, 13612, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Riftwalker Tarrowyn
(232733, 1, 13612, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Riftwalker Ailaya
(235700, 1, 126937, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Bilgewater Worker
(235707, 1, 126937, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Bilgewater Worker
(238187, 1, 232997, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Lash'ir
(241342, 1, 214455, 0, 0, 0, 0, 0, 232796, 0, 0, 63305), -- Andryck Carltyn
(241343, 1, 214455, 0, 0, 0, 0, 0, 232796, 0, 0, 63305), -- Eoghan Knatley
(241384, 1, 233000, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Oath-Breaker Desamirah
(242616, 1, 71332, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Brew Thief
(243146, 1, 24094, 0, 0, 34675, 0, 0, 0, 0, 0, 63305), -- Alessia Brightshield
(243552, 1, 240508, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Phase Image
(244101, 1, 232994, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Shadowguard Phasecutter
(244111, 1, 240500, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Shadowguard Void Adept
(244113, 1, 240499, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Shadowguard Soulbreaker
(244115, 1, 240479, 0, 0, 240487, 0, 0, 0, 0, 0, 63305), -- Shadowguard Null Bastion
(244137, 1, 238393, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Shadowguard Arcanotech
(244410, 1, 233002, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Pactsworn Sandreaver
(244411, 1, 240521, 0, 0, 240527, 0, 0, 0, 0, 0, 63305), -- Pactsworn Arcanist
(244415, 1, 240471, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Pactsworn Dustblade
(244416, 1, 233002, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Pactsworn Sandreaver
(244418, 1, 240477, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Pactsworn Wildcaller
(245510, 1, 71332, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Barrel Bandit
(245967, 1, 117379, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Gorgrum Kegfist
(246212, 1, 48663, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Keggor the Fermented
(246285, 1, 185334, 0, 0, 185334, 0, 0, 0, 0, 0, 63305), -- Bazaar Overseer
(247046, 1, 178498, 0, 0, 178349, 0, 0, 0, 0, 0, 63305), -- Cartel Zo Phase Guardian
(247409, 1, 238393, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Zoological Specimen Handler
(247457, 1, 50431, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Tomb-Raider Drywhisker
(247458, 1, 156987, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Mirror Master Murkna
(247478, 1, 76746, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Speaker Halven
(248453, 1, 160207, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Adventurer's Echo
(248453, 2, 0, 0, 0, 0, 0, 0, 225356, 0, 0, 63305), -- Adventurer's Echo
(248539, 1, 184569, 0, 0, 0, 0, 0, 0, 0, 0, 63305); -- Contracted Mercenary

UPDATE `creature_equip_template` SET `VerifiedBuild`=63305 WHERE (`ID`=1 AND `CreatureID` IN (68,331,338,376,908,928,1141,1297,1298,1301,1308,1311,1312,1313,1316,1348,1351,1366,1367,1411,1415,1416,1431,1444,1493,1863,1907,1976,2485,2486,2488,2490,2491,2496,2499,2502,2541,2594,2622,2626,2663,2664,2708,2834,2836,2837,2838,2839,2840,2842,2843,2845,2847,2848,2857,2858,2859,3084,3144,3189,3216,3296,3310,3312,3313,3314,3323,3327,3328,3329,3331,3342,3347,3348,3350,3351,3366,3367,3368,3370,3412,3413,4047,4078,4311,4624,4631,5188,5386,5484,5489,5491,5492,5493,5494,5498,5499,5500,5503,5504,5506,5509,5510,5513,5514,5518,5519,5566,5606,5609,5610,5611,5613,5614,5639,5694,5811,5817,5910,6171,6466,6566,6579,6929,6986,6987,7010,7088,7232,7406,7798,8659,8891,8892,8893,8894,8895,8896,8897,8898,8899,8900,8901,8902,8904,8913,8914,8916,8920,8983,9024,9033,9041,9056,9156,9319,9499,9503,9543,9545,9547,9554,9559,9564,9681,10043,10782,11017,11026,11046,11068,12022,12136,12379,12380,12790,12791,12796,12797,12798,12944,13417,14375,14376,14377,14392,14423,14438,14439,14497,14498,15078,16076,17249,18255,21045,23128,23603,23605,23635,23685,23795,23872,24510,24924,24926,24929,24930,24931,25078,25080,25081,25082,25089,25093,25095,25097,25098,26309,26537,26764,26776,26822,28048,28049,28050,28051,28052,28180,28209,28210,29712,29880,30632,30713,32251,32252,32725,34765,35068,36674,37072,37937,40891,42288,42421,42506,42594,44158,44395,44723,44725,44726,44740,44743,44779,44780,44781,44851,44871,44872,44876,44877,44878,44919,45230,45244,45306,45337,45339,45815,45817,45824,46140,46142,46180,46357,46358,46359,46555,46556,46622,46708,46709,46716,46741,46742,47233,47246,47247,47248,47253,47321,47335,47336,47571,47663,48808,49622,49635,49636,49701,49737,49748,49750,50304,50323,50341,50349,50354,50356,50359,50477,50488,50739,50749,51346,51348,52031,52032,52409,53187,53209,54232,54401,54402,54442,54443,57444,57800,58155,58193,58408,58412,58460,58465,58466,58467,58470,58471,59410,59414,59416,59424,59430,59758,59797,59969,60030,60397,60398,61334,61989,62193,62194,62195,62196,62197,62397,62402,62405,62408,62511,62543,62563,62980,63030,63032,63036,63048,63049,63101,63556,63570,63592,63593,63695,63820,63974,63976,64260,64263,64339,64340,64341,64353,64355,64357,64358,64453,64454,64458,64536,64542,64714,64720,64890,64902,64916,64917,65134,65498,65500,65501,65840,66200,66219,66235,66237,66291,66346,66347,66694,66979,67160,68980,69791,69978,71100,72559,73151,73914,74228,88067,88696,88697,88701,88702,88703,89830,90417,90418,90431,90463,92183,92457,92489,92643,93520,93536,95844,96444,96698,96708,96770,96771,96772,96778,96779,96780,96785,96786,96791,96792,96794,96795,96801,96802,96803,96804,96809,96944,96945,96946,96947,96948,96949,96950,96951,96952,96953,96954,96955,96956,96957,96958,96959,96960,97012,97141,97213,97491,97493,97500,97513,97515,97529,97532,97533,97792,98723,98724,99541,102124,102134,104091,105339,106262,106263,106655,106930,107772,107968,108628,109387,109390,109554,110019,111243,111246,112079,112720,112912,113211,113779,113780,113781,113782,113783,113784,113785,113873,114208,114232,114246,114262,114310,114312,114314,114316,114317,114319,114320,114350,114581,114584,114619,114629,114631,114636,114637,114667,114714,114715,114716,114799,114801,114802,114803,114815,114821,115029,115038,115068,115070,115076,115077,115107,115164,115486,115489,115490,115496,115501,115757,115967,115976,115984,116002,116175,116573,116784,117078,117079,119226,119272,119484,119486,119487,120412,120413,120416,120417,120419,120420,120422,120423,120687,121235,121239,123169,124695,124805,124882,125005,126310,126478,126581,126621,126717,126724,127558,127739,128286,128494,129604,129749,130368,130491,130554,130695,131048,131216,131302,131446,131610,131627,132642,133185,133186,133218,133271,133282,133340,133431,133433,133441,133536,133675,134058,134060,134063,134137,134139,134150,134338,134417,134418,134425,134514,134722,134725,134729,134838,134847,134853,135107,135213,135509,135511,135584,135585,135604,135612,135614,135618,135620,135658,135675,135677,135678,135681,135690,135691,135776,135785,135792,135812,135813,135814,135883,135889,135985,136007,136052,136061,136102,136157,136186,136196,136214,136222,136226,136318,136337,136421,136439,136584,136587,136633,136756,136766,136767,137039,137144,137146,137147,137202,137212,137215,137262,137265,137266,137268,137282,137293,137294,137295,137298,137317,137440,137441,137530,137797,137822,138027,138032,138104,138352,138544,138856,138858,138860,138868,138876,139028,139084,139089,139090,139144,139260,139375,139570,139799,139800,140313,140350,140514,140531,140771,140796,140904,140906,141080,141083,141085,141087,141091,141177,141274,141485,141510,141519,141522,141552,141646,141698,141772,141773,141912,141920,141961,142158,142159,142167,142180,142276,142371,142462,142463,142502,142607,142611,142644,142646,142710,142721,142754,142773,142784,142967,142993,142997,143015,143128,143152,143186,143248,143250,143263,143281,143283,143285,143286,143287,143289,143291,143294,143302,143310,143336,143396,143402,143495,143498,143535,143541,143559,143574,143593,143614,143615,143626,143664,143737,143793,143842,143846,143856,143892,143905,143919,143948,144212,144213,144310,144333,144493,144961,145728,147714,147741,147785,147972,147973,147974,147975,148124,148233,148242,148250,148263,148770,148795,149045,149131,149270,149519,149616,149626,150122,150131,150433,152112,152302,152324,152326,152328,152722,153016,153070,153072,153075,153084,153086,153087,153105,153118,153760,154313,155034,155269,156264,156524,156641,156642,156794,156795,156820,156837,156949,157158,157700,157811,157812,157813,157837,157838,158075,158092,158136,158146,158158,158371,158373,158437,158690,158774,158928,159027,159275,159632,159633,160101,160385,160458,161565,163041,163634,164562,165414,165415,165515,165529,166568,167611,167612,167615,167876,168459,169472,169476,173819,174146,174147,175616,175663,175806,176394,176438,176534,176551,176563,176705,177807,177808,177816,177996,178139,178141,178142,178163,178171,178388,178392,178394,179269,179334,179386,179388,179551,179821,179840,179893,180335,180336,180348,180431,180485,180612,180617,180751,184666,196470,197245,197290,197951,197968,198497,198518,198579,199015,199016,199017,199018,199115,199277,199280,199561,201312,201314,202438,205353,205879,206694,206696,206697,206698,206704,206705,207450,207454,207456,207468,207481,207939,207940,207946,207949,209299,209790,210759,211289,211290,211291,211751,212077,212464,212697,212826,212827,212831,212835,212839,214016,214251,214338,214343,214780,214917,215170,215335,215708,215711,215755,215777,215980,216199,216248,216301,216313,216314,216441,217133,217207,217241,217247,217249,217295,217395,217396,217429,217545,217578,217658,217716,217717,217718,217744,217747,217749,217845,217985,218084,218087,218163,218164,218168,218170,218173,218175,218180,218300,218315,218316,218372,218378,218502,218503,219014,219053,219054,219068,219080,219097,219118,219126,219150,219159,219166,219169,219186,219187,219189,219213,219224,219228,219273,219314,219327,219339,219348,219373,219392,219760,219761,219786,219788,219789,219982,220073,220152,220712,220713,220721,220722,220723,220724,220725,220726,220814,220916,220974,220976,220977,220978,221002,221044,221074,221190,221302,221303,221380,221632,221633,221634,221635,221744,221760,221769,221842,221848,221957,221969,221971,222120,222139,222160,222242,222267,222270,222292,222303,222336,222631,222867,223164,223361,223363,223364,223377,223594,223605,223644,223875,223918,223944,224137,224306,224307,224308,224332,224758,224762,224832,224833,224898,225148,225254,225256,225257,225347,225483,225489,225495,225496,225518,225534,225580,225704,225766,225823,225826,225827,225851,225853,225854,225972,225973,226223,226239,226240,226254,226270,226364,226418,226419,226516,226517,226591,226592,226656,226731,226744,226745,226746,226750,226754,226756,226783,226833,226834,227073,227118,227128,227129,227134,227216,227219,227318,227321,227422,227427,227525,227702,227758,228121,228144,228323,228324,229136,229184,229212,229250,229251,229320,229591,229686,230352,230353,230354,230474,230609,230617,230618,230619,230620,230621,230624,230720,230733,230734,230743,230748,230769,230772,230776,230777,230781,230823,230927,230940,230944,230960,230961,230963,230966,230969,230985,231288,231312,231385,231394,231449,231452,231475,231483,231484,231496,231549,231584,231586,231587,231588,231689,231694,232018,232330,232367,232403,232508,232642,232732,232812,233019,233325,233409,233410,233413,233456,233457,233511,233536,233539,233541,233542,233628,233629,233630,233632,233640,233675,233681,233684,233700,233861,233862,234032,234033,234050,234134,234138,234190,234307,234308,234332,234333,234334,234403,234405,234425,234428,234429,234452,234453,234455,234467,234533,234562,234563,234602,234872,234933,234955,234957,234962,235144,235176,235203,235214,235335,235408,235805,235807,235862,236527,236632,236881,236907,237132,237215,237233,237262,237263,237264,237285,237660,237661,237662,237763,237790,238073,238090,238103,238266,238312,238314,238318,238387,238463,238465,238466,238520,238544,238545,238546,238885,238886,238972,239264,239275,239332,239404,239454,239834,239836,240162,240485,240842,240906,240908,240911,240913,240935,240938,240974,241090,241242,241304,241355,241383,241666,241715,241717,241718,241736,241737,241798,241800,241801,241905,241958,242116,242117,242126,242155,242157,242234,242235,242236,242238,242273,242356,242456,242517,242526,242570,242631,242648,242649,242705,242707,242730,243199,243371,243372,243373,244109,244385,244485,245338,245347,245353,245361,245601,245782,245980,246148,246374,246735,247030,247937,247939,248626,248728,248802,249628,250692)) OR (`ID`=2 AND `CreatureID` IN (68,3296,4624,17252,30243,44158,63556,69792,74228,114801,114803,120415,122130,123642,125004,126581,134838,135509,135678,135792,136633,136766,138544,139088,143892,153070,153074,153075,153082,155034,156642,169476,177996,216138,219014,219982,224337,225148,225704,229250,237661,239332,246735)) OR (`ID`=4 AND `CreatureID` IN (1976,135792,155034,217450,219014,219982,241102,241355)) OR (`ID`=5 AND `CreatureID` IN (19175,64263,135792,139088,155034,219014,219982,238885,241102)) OR (`ID`=3 AND `CreatureID` IN (44158,74228,96793,123641,126582,132642,133325,134838,135678,138544,155034,156642,217450,219014,219982,229250,241102,241355)) OR (`ID`=18 AND `CreatureID`=76168) OR (`ID`=29 AND `CreatureID`=76168) OR (`ID`=33 AND `CreatureID`=76168) OR (`ID`=6 AND `CreatureID` IN (135792,139088,155034,219014,219982,241102)) OR (`ID`=8 AND `CreatureID`=139088) OR (`ID`=7 AND `CreatureID`=219014);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (90776 /*Ancient Curiosity: Combat*/, 90778 /*Ancient Curiosity: Utility*/, 83739 /*Notorious with The General*/, 79196 /*Renowned with The Severed Threads*/, 83740 /*Notorious with The Vizier*/, 91855 /*Worldsoul: K'aresh World Quests*/, 91483 /*Hacking the Mainframe*/, 91481 /*Speed Siphoner*/, 86152 /*Faceless Mask of the Daredevil*/, 86151 /*Faceless Mask of the Burned Bridge*/, 91781 /*Seasonal Reminder*/, 91780 /*Ethereal Delves*/, 91068 /*Serving with Style*/, 91066 /*Brewmaster's Kitchen*/, 91067 /*Gathering the Grub*/, 42758 /*You're Gonna Need A Bigger Boat!*/, 57637 /*Disturbance Detected: Firelands*/, 91420 /*Swap Meet*/, 91525 /*Head Hunting: Loom'ithar*/, 86365 /*Crest Transmutation*/, 87417 /*Worldsoul: Dungeons*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(90776, 0, 0, 0, 0, 0, 0, 0, 0, '', 63305), -- Ancient Curiosity: Combat
(90778, 0, 0, 0, 0, 0, 0, 0, 0, '', 63305), -- Ancient Curiosity: Utility
(83739, 5, 0, 0, 0, 0, 0, 0, 0, 'Here! Accept these gifts as a tribute to your strength!\n\nIgitith ik tak\'na!', 62748), -- Notorious with The General
(79196, 6, 0, 0, 0, 0, 0, 0, 0, 'For services rendered and services yet to be rendered, accept this with The Weaver\'s compliments.', 62748), -- Renowned with The Severed Threads
(83740, 6, 0, 0, 0, 0, 0, 0, 0, 'The Vizier\'s compliments should be a more than sufficient gift for you...\n\nBut I suppose these goods would simply go to waste if not for his generosity. Take them. Be grateful.\n\nAnd do try to remain alive, overcrawler.', 62748), -- Notorious with The Vizier
(91855, 1, 0, 0, 0, 0, 0, 0, 0, 'You are a credit to heroes everywhere. Thank you.', 62748), -- Worldsoul: K'aresh World Quests
(91483, 0, 0, 0, 0, 0, 0, 0, 0, 'There are consoles inside the Manaforge that keep the flow of energy running smoothly within the facility. We\'ve cracked security on the first set of them, allowing you to turn the tables on enemies near Loom\'ithar and Soulbinder Naazindrhi. You\'ll only be able to use one, but sabotaging them should allow you an edge in battle. Good luck in there.', 62748), -- Hacking the Mainframe
(91481, 1, 0, 0, 0, 0, 0, 0, 0, 'Zo\'ropo brings you a new weapon. Use this to feed off of the Manaforge\'s arcane radiation and turn their energies against them.', 62748), -- Speed Siphoner
(86152, 0, 0, 0, 0, 0, 0, 0, 0, 'The path of the Daredevil is available to you if you dare.', 62493), -- Faceless Mask of the Daredevil
(86151, 0, 0, 0, 0, 0, 0, 0, 0, 'The treacherous path of the Burned Bridge will be available to you if you wish to tread it.', 62493), -- Faceless Mask of the Burned Bridge
(91781, 1, 0, 0, 0, 0, 0, 0, 0, 'Right, on to that wee problem I mentioned.', 62493), -- Seasonal Reminder
(91780, 4, 0, 0, 0, 0, 0, 0, 0, 'Good tae see ye! We\'ve got plenty tae discuss.', 62493), -- Ethereal Delves
(91068, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'d say you\'ve earned yourself a break and a strong brew after all that work. But don\'t go getting soft on me! Brewfest isn\'t over, and there\'s still plenty of work to be done.', 63305), -- Serving with Style
(91066, 1, 0, 0, 0, 0, 0, 0, 0, 'Hah! I can smell those pretzels from here. You\'ve cooked up a feast fit to silence even the grumbling of dwarves!', 63305), -- Brewmaster's Kitchen
(91067, 1, 0, 0, 0, 0, 0, 0, 0, 'You\'ve done it! The cooks will be pleased.', 63305), -- Gathering the Grub
(42758, 0, 0, 0, 0, 0, 0, 0, 0, 'Blimey! This one still has blood on it! Looks like he got a good bite on ye good, lad!', 63163), -- You're Gonna Need A Bigger Boat!
(57637, 1, 5, 0, 0, 0, 400, 0, 0, 'Oh no, time-locking?! Who knows how long this had been there before we were able to detect it! This is far worse than I had imagined...', 62958), -- Disturbance Detected: Firelands
(91420, 1, 0, 0, 0, 0, 0, 0, 0, '<Om\'myuz takes a closer look at the ore.>\n\nThat is quite the intriguing rock you\'ve found. I would like to inspect it further, and any others you find. What say you to a trade?\n\nOther Cartel Om members in the Veiled Market may also be interested in trading wares, should you come across them.', 62493), -- Swap Meet
(91525, 0, 0, 0, 0, 0, 0, 0, 0, 'Its quality is unlike anything I\'ve ever seen! I\'ll get to work right away. Now, let\'s discuss your payment.', 62493), -- Head Hunting: Loom'ithar
(86365, 0, 0, 0, 0, 0, 0, 0, 0, 'Remarkable!\n\nKeep in mind I can only transmute Crests into a higher tier when you have outgrown their usefulness, and it will be a costly process. Thank you for all of your help!', 62876), -- Crest Transmutation
(87417, 1005, 0, 0, 0, 0, 0, 0, 0, 'Thank you for bringing all people of Khaz Algar a glimmer of hope.', 62438); -- Worldsoul: Dungeons

UPDATE `quest_offer_reward` SET `VerifiedBuild`=63305 WHERE `ID` IN (55660, 82679, 84370, 82706);
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=63305 WHERE `ID`=11447; -- Welcome to Brewfest!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=62748 WHERE `ID` IN (83738, 83366, 91093);
UPDATE `quest_offer_reward` SET `VerifiedBuild`=62493 WHERE `ID` IN (91093, 89345, 89344, 89343, 89380, 91624);
UPDATE `quest_offer_reward` SET `RewardText`='Ah, so Direbrew finally submitted his brew.  What a pity he had to die to do it...$B$BOh, well.  Bottoms up, eh?', `VerifiedBuild`=63305 WHERE `ID`=12492; -- Direbrew's Dire Brew
UPDATE `quest_offer_reward` SET `VerifiedBuild`=62876 WHERE `ID` IN (82679, 86364, 86363);
UPDATE `quest_offer_reward` SET `VerifiedBuild`=62438 WHERE `ID`=82679;


UPDATE `quest_poi` SET `VerifiedBuild`=63305 WHERE (`QuestID`=42233 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48642 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48642 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48642 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42421 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=63163 WHERE (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42421 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=63003 WHERE (`QuestID`=48642 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48642 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48642 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42233 AND `BlobIndex`=1 AND `Idx1`=1);
UPDATE `quest_poi` SET `VerifiedBuild`=62876 WHERE (`QuestID`=42421 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42233 AND `BlobIndex`=1 AND `Idx1`=1);
UPDATE `quest_poi` SET `VerifiedBuild`=62748 WHERE (`QuestID`=48642 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48642 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48642 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42233 AND `BlobIndex`=1 AND `Idx1`=1);
UPDATE `quest_poi` SET `VerifiedBuild`=62706 WHERE (`QuestID`=48642 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48642 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48642 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=62801 WHERE (`QuestID`=42421 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=62680 WHERE (`QuestID`=48642 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48642 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48642 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=62958 WHERE (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48642 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=48642 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48642 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42233 AND `BlobIndex`=1 AND `Idx1`=1);


DELETE FROM `quest_greeting` WHERE (`Type`=0 AND `ID` IN (238221,245349,232642,234483));
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(238221, 0, 0, 0, 'Got your tankard ready, $n?', 63305), -- 238221
(245349, 0, 0, 0, 'Need an upgrade, my friend?', 62748), -- 245349
(232642, 0, 0, 0, 'Strike its head, and the body will fall.', 62438), -- 232642
(234483, 0, 0, 0, 'Yes? Have something on your mind?', 62438); -- 234483

UPDATE `quest_greeting` SET `VerifiedBuild`=63305 WHERE (`ID`=226919 AND `Type`=0);

DELETE FROM `quest_details` WHERE `ID` IN (87374 /*C.H.E.T.T.ing In*/, 90776 /*Ancient Curiosity: Combat*/, 90778 /*Ancient Curiosity: Utility*/, 91067 /*Gathering the Grub*/, 87341 /*Barreling Down*/, 83362 /*A Shrouded Path Through Time*/, 83345 /*A Call to Battle*/, 91483 /*Hacking the Mainframe*/, 91481 /*Speed Siphoner*/, 91782 /*Repossessed!*/, 91781 /*Seasonal Reminder*/, 83365 /*A Frozen Path Through Time*/, 83104 /*Identifying Ironclaw*/, 87349 /*Bubbling Brews*/, 56748 /*Brewfest Chowdown*/, 83587 /*Our Chance to Strike*/, 83459 /*The Dawnbreaker*/, 91855 /*Worldsoul: K'aresh World Quests*/, 86365 /*Crest Transmutation*/, 78881 /*The Eastern Kingdoms Cup Begins*/, 83457 /*The Stonevault*/, 83432 /*The Rookery*/, 87417 /*Worldsoul: Dungeons*/, 91068 /*Serving with Style*/, 91539 /*A Radiant Echo*/, 91066 /*Brewmaster's Kitchen*/, 12191 /*Chug and Chuck!*/, 77839 /*The Eastern Kingdoms Cup Circuit*/, 57637 /*Disturbance Detected: Firelands*/, 83359 /*A Shattered Path Through Time*/, 83458 /*Priory of the Sacred Flame*/, 91476 /*Behind Enemy Lines*/, 91420 /*Swap Meet*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(87374, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- C.H.E.T.T.ing In
(90776, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Ancient Curiosity: Combat
(90778, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Ancient Curiosity: Utility
(91067, 1, 0, 0, 0, 0, 0, 0, 0, 63305), -- Gathering the Grub
(87341, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Barreling Down
(83362, 1, 0, 0, 0, 0, 0, 0, 0, 63305), -- A Shrouded Path Through Time
(83345, 1, 0, 0, 0, 0, 0, 0, 0, 62876), -- A Call to Battle
(91483, 0, 0, 0, 0, 0, 0, 0, 0, 62748), -- Hacking the Mainframe
(91481, 0, 0, 0, 0, 0, 0, 0, 0, 62748), -- Speed Siphoner
(91782, 603, 1, 0, 0, 0, 0, 0, 0, 62493), -- Repossessed!
(91781, 603, 1, 0, 0, 0, 0, 0, 0, 62493), -- Seasonal Reminder
(83365, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- A Frozen Path Through Time
(83104, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- Identifying Ironclaw
(87349, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Bubbling Brews
(56748, 1, 1, 0, 0, 0, 300, 0, 0, 63305), -- Brewfest Chowdown
(83587, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Our Chance to Strike
(83459, 1, 0, 0, 0, 0, 0, 0, 0, 63003), -- The Dawnbreaker
(91855, 1, 1, 0, 0, 0, 1000, 0, 0, 63003), -- Worldsoul: K'aresh World Quests
(86365, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Crest Transmutation
(78881, 0, 0, 0, 0, 0, 0, 0, 0, 62801), -- The Eastern Kingdoms Cup Begins
(83457, 1, 0, 0, 0, 0, 0, 0, 0, 62801), -- The Stonevault
(83432, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Rookery
(87417, 1, 1, 0, 0, 0, 500, 0, 0, 62438), -- Worldsoul: Dungeons
(91068, 1, 0, 0, 0, 0, 0, 0, 0, 63305), -- Serving with Style
(91539, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- A Radiant Echo
(91066, 1, 0, 0, 0, 0, 0, 0, 0, 63305), -- Brewmaster's Kitchen
(12191, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Chug and Chuck!
(77839, 0, 0, 0, 0, 0, 0, 0, 0, 62958), -- The Eastern Kingdoms Cup Circuit
(57637, 1, 5, 0, 0, 0, 0, 0, 0, 62958), -- Disturbance Detected: Firelands
(83359, 1, 0, 0, 0, 0, 0, 0, 0, 62958), -- A Shattered Path Through Time
(83458, 1, 0, 0, 0, 0, 0, 0, 0, 62958), -- Priory of the Sacred Flame
(91476, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Behind Enemy Lines
(91420, 0, 0, 0, 0, 0, 0, 0, 0, 62438); -- Swap Meet

UPDATE `quest_details` SET `VerifiedBuild`=63305 WHERE `ID` IN (84956, 91780, 78713, 84365, 90705, 84370, 82706, 82679, 83347, 90779, 12492);
UPDATE `quest_details` SET `VerifiedBuild`=63163 WHERE `ID` IN (48622, 42758);
UPDATE `quest_details` SET `VerifiedBuild`=62493 WHERE `ID` IN (88803, 82706, 83436, 91093, 89345, 89344, 89343, 89380, 90705);
UPDATE `quest_details` SET `VerifiedBuild`=63003 WHERE `ID`=84776;
UPDATE `quest_details` SET `VerifiedBuild`=62876 WHERE `ID` IN (86364, 91093);
UPDATE `quest_details` SET `VerifiedBuild`=62801 WHERE `ID`=82679;
UPDATE `quest_details` SET `VerifiedBuild`=62438 WHERE `ID` IN (82679, 83358, 82690);
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=63305 WHERE `ID`=11409; -- Now This is Ram Racing... Almost.
UPDATE `quest_details` SET `VerifiedBuild`=62958 WHERE `ID` IN (82706, 84638);
UPDATE `quest_details` SET `VerifiedBuild`=62748 WHERE `ID` IN (83443, 83366);

DELETE FROM `quest_request_items` WHERE `ID` IN (91782 /*Repossessed!*/, 91781 /*Seasonal Reminder*/, 86152 /*Faceless Mask of the Daredevil*/, 86151 /*Faceless Mask of the Burned Bridge*/, 87417 /*Worldsoul: Dungeons*/, 83104 /*Identifying Ironclaw*/, 57637 /*Disturbance Detected: Firelands*/, 56748 /*Brewfest Chowdown*/, 87349 /*Bubbling Brews*/, 87341 /*Barreling Down*/, 83459 /*The Dawnbreaker*/, 83458 /*Priory of the Sacred Flame*/, 83457 /*The Stonevault*/, 83443 /*Darkflame Cleft*/, 83365 /*A Frozen Path Through Time*/, 83362 /*A Shrouded Path Through Time*/, 83359 /*A Shattered Path Through Time*/, 86365 /*Crest Transmutation*/, 83347 /*Emissary of War*/, 86363 /*The Better Part of Valorstones*/, 91068 /*Serving with Style*/, 91067 /*Gathering the Grub*/, 91066 /*Brewmaster's Kitchen*/, 42758 /*You're Gonna Need A Bigger Boat!*/, 91855 /*Worldsoul: K'aresh World Quests*/, 88803 /*Timely Assistance*/, 90517 /*My Part of the Deal*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(91782, 0, 0, 0, 0, 'Has it always been this breezy in Dornogal?', 0), -- Repossessed!
(91781, 0, 0, 0, 0, '', 63305), -- Seasonal Reminder
(86152, 0, 0, 0, 0, 'Place the Faceless Mask of the Daredevil on the altar.', 0), -- Faceless Mask of the Daredevil
(86151, 0, 0, 0, 0, 'Place the Faceless Mask of the Burned Bridge on the altar.', 0), -- Faceless Mask of the Burned Bridge
(87417, 0, 1, 0, 0, 'How goes the mission?', 63305), -- Worldsoul: Dungeons
(83104, 0, 274, 0, 0, 'Trust me, you can\'t miss it.', 0), -- Identifying Ironclaw
(57637, 0, 0, 0, 0, 'Bring me the temporal anomaly as soon as you can, so we can get back to yesterday\'s problems tomorrow.', 63305), -- Disturbance Detected: Firelands
(56748, 0, 0, 0, 0, 'Eat a sausage, drink some brew, then eat some more!', 63305), -- Brewfest Chowdown
(87349, 0, 0, 0, 0, 'Have you filled up the barrel?', 63305), -- Bubbling Brews
(87341, 0, 0, 0, 0, 'Careful with the barrels! You shouldn\'t jostle a good ale.', 63305), -- Barreling Down
(83459, 0, 1, 0, 0, 'I know ceremonies are not your cup of cinderbrew. They are not mine either, but our job is important.', 63305), -- The Dawnbreaker
(83458, 0, 1, 0, 0, 'I am not sure if you are still here or already back.', 63305), -- Priory of the Sacred Flame
(83457, 0, 1, 0, 0, 'Any news I can report to High Speaker Brinthe?', 63305), -- The Stonevault
(83443, 0, 1, 0, 0, 'Let me know if you figure out what this darkness is all about.', 63305), -- Darkflame Cleft
(83365, 0, 25, 0, 0, 'Much has happened in the greater world while we worked in this place. I hear you had a hand in quite a bit of those tales.', 63305), -- A Frozen Path Through Time
(83362, 0, 25, 0, 0, 'I wonder what it is like to be covered in fur like a pandaren. I hear there are many floating places to visit in those lands. May they all stay afloat.', 63305), -- A Shrouded Path Through Time
(83359, 0, 25, 0, 0, 'Only the titans should reshape the world.', 63305), -- A Shattered Path Through Time
(86365, 0, 0, 0, 0, 'If you lose those Carved Ethereal Crests, you can find more from powerful creatures around K\'aresh. I\'ve heard there\'s quite a variety of them!', 63305), -- Crest Transmutation
(83347, 0, 0, 0, 0, 'By pressing ourselves to the extreme we can truly test our skills.', 63305), -- Emissary of War
(86363, 0, 0, 0, 0, 'There\'s no need to hurry. But if you wouldn\'t mind hurrying anyway...', 63305), -- The Better Part of Valorstones
(91068, 0, 0, 0, 0, 'Remember to serve with a smile!', 63305), -- Serving with Style
(91067, 0, 0, 0, 0, 'The feast won\'t come together without those ingredients!', 63305), -- Gathering the Grub
(91066, 0, 0, 0, 0, 'Start the fire and get to work!', 63305), -- Brewmaster's Kitchen
(42758, 0, 0, 0, 0, 'I require thirty-three Razor-Sharp Shark Teeth. Do not try to short me, lad.', 63305), -- You're Gonna Need A Bigger Boat!
(91855, 0, 1005, 0, 0, 'Our allies resist valiantly on a dead and shattered world. I admire them.', 63305), -- Worldsoul: K'aresh World Quests
(88803, 0, 0, 0, 0, 'I hope you find this useful.', 63305), -- Timely Assistance
(90517, 0, 1, 0, 0, 'The Reshii Ribbons are a means to get you and your allies to Dimensius. You will need at least two more if this plan is going to work.', 63305); -- My Part of the Deal

UPDATE `quest_request_items` SET `VerifiedBuild`=63305 WHERE `ID` IN (84883, 84879, 84869, 84867, 84862, 84861, 82706, 84860, 84859, 84858, 84856, 84838, 84834, 84831, 84827, 84776, 86495, 83436, 83366, 91093, 85039, 89345, 89344, 89343, 85032, 85003, 84967, 84965, 84964, 84963, 84961, 84960, 84959, 84958, 84910);


UPDATE `quest_offer_reward_conditional` SET `VerifiedBuild`=63305 WHERE (`QuestId`=82679 AND `PlayerConditionId`=127542 AND `QuestgiverCreatureId`=226543 AND `locale`='enUS');
UPDATE `quest_offer_reward_conditional` SET `VerifiedBuild`=62876 WHERE (`QuestId`=82679 AND `PlayerConditionId`=127542 AND `QuestgiverCreatureId`=226543 AND `locale`='enUS');
UPDATE `quest_offer_reward_conditional` SET `VerifiedBuild`=62438 WHERE (`QuestId`=82679 AND `PlayerConditionId`=127542 AND `QuestgiverCreatureId`=226543 AND `locale`='enUS');

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=942 AND `QuestLineId` IN (5693,5673,614)) OR (`UIMapId`=895 AND `QuestLineId`=5673) OR (`UIMapId`=896 AND `QuestLineId`=604) OR (`UIMapId`=2214 AND `QuestLineId` IN (5953,5906,5770,5715,5683,5903)) OR (`UIMapId`=2255 AND `QuestLineId` IN (5906,5803,5791,5782,5780,5779,5770,5763,5744,5742,5735,5734,5733,5717,5715,5705,5703,5699,5696,5695,5693,5690,5683,5903)) OR (`UIMapId`=2404 AND `QuestLineId` IN (5697,5691,5673)) OR (`UIMapId`=2215 AND `QuestLineId` IN (5953,5906,5803,5791,5782,5780,5779,5770,5763,5744,5742,5735,5734,5733,5717,5715,5705,5696,5693,5690,5683,5903)) OR (`UIMapId`=1525 AND `QuestLineId` IN (5691,1038,1005,998,996,995,994,985)) OR (`UIMapId`=2216 AND `QuestLineId`=5716) OR (`UIMapId`=2016 AND `QuestLineId`=1235);
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(942, 5693, 63305),
(942, 5673, 63305),
(942, 614, 63305),
(895, 5673, 63305),
(896, 604, 63305),
(2214, 5953, 62876),
(2214, 5906, 62876),
(2214, 5770, 62876),
(2214, 5715, 62876),
(2214, 5683, 62876),
(2255, 5906, 62748),
(2255, 5803, 62748),
(2255, 5791, 62748),
(2255, 5782, 62748),
(2255, 5780, 62748),
(2255, 5779, 62748),
(2255, 5770, 62748),
(2255, 5763, 62748),
(2255, 5744, 62748),
(2255, 5742, 62748),
(2255, 5735, 62748),
(2255, 5734, 62748),
(2255, 5733, 62748),
(2255, 5717, 62748),
(2255, 5715, 62748),
(2255, 5705, 62748),
(2255, 5703, 62748),
(2255, 5699, 62748),
(2255, 5696, 62748),
(2255, 5695, 62748),
(2255, 5693, 62748),
(2255, 5690, 62748),
(2255, 5683, 62748),
(2404, 5697, 62493),
(2404, 5691, 62493),
(2404, 5673, 62493),
(2214, 5903, 62493),
(2215, 5953, 63305),
(2215, 5906, 63305),
(2215, 5803, 63305),
(2215, 5791, 63305),
(2215, 5782, 63305),
(2215, 5780, 63305),
(2215, 5779, 63305),
(2215, 5770, 63305),
(2215, 5763, 63305),
(2215, 5744, 63305),
(2215, 5742, 63305),
(2215, 5735, 63305),
(2215, 5734, 63305),
(2215, 5733, 63305),
(2215, 5717, 63305),
(2215, 5715, 63305),
(2215, 5705, 63305),
(2215, 5696, 63305),
(2215, 5693, 63305),
(2215, 5690, 63305),
(2215, 5683, 63305),
(1525, 5691, 62438),
(1525, 1038, 62438),
(1525, 1005, 62438),
(1525, 998, 62438),
(1525, 996, 62438),
(1525, 995, 62438),
(1525, 994, 62438),
(1525, 985, 62438),
(2215, 5903, 62438),
(2255, 5903, 62438),
(2216, 5716, 63305),
(2016, 1235, 62493);

UPDATE `ui_map_quest_line` SET `VerifiedBuild`=63305 WHERE (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5542,5540,5539,5533,5531,5525,5523,5513,5509,1416,5709)) OR (`UIMapId`=942 AND `QuestLineId` IN (5388,906,894,881,851,627,577)) OR (`UIMapId`=895 AND `QuestLineId` IN (5447,5388,5384,5382,5380,5379,5378,5377,5376,5375,5374,1104,1030,940,939,911,903,902,890,889,873,851,848,839,838,785,629,626,625,624,622,604,586)) OR (`UIMapId`=896 AND `QuestLineId` IN (5673,5447,5388,5384,5376,1104,940,911,903,902,890,889,851,839,838,626,625)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416,5903,5710,5655,5654,5653,5652,5651,5648,5647,5644,5634,5628,5626,5625,5624,5623,5622,5621,5620,5619,5611,5610,5608,5607,5603,5601,5600,5596,5591,5590,5574,5565,5562,5559,5552,5542,5532,5527,5524,5522,5512,5509,5709)) OR (`UIMapId`=1 AND `QuestLineId` IN (5638,5593,5538,5519,5513,5504,5499,5459,5389,5387,5382,1311,1295,1289,1267,1108,1107,1003,973,802,636,612,546,539,516,377,300,290,263,261,260,5430,1227,563,550,509,376,130)) OR (`UIMapId`=2255 AND `QuestLineId` IN (5900,5776,5772,5741,5716,5694,5686,5685,5672,5669,5668,5666,5663,5662,5661,5660,5659,5642,5641,5631,5630,5617,5615,5614,5598,5593,5558,5551,5550,5544,5534,5531,5530,5529,5526,5525,5523,5521,5520,5506)) OR (`UIMapId`=2215 AND `QuestLineId` IN (5900,5799,5776,5772,5741,5732,5716,5711,5697,5694,5691,5686,5685,5684,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5900,5803,5799,5791,5782,5780,5779,5776,5772,5763,5744,5742,5741,5736,5734,5733,5732,5717,5716,5711,5705,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5678,5673,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=422 AND `QuestLineId` IN (5499,5495,5493,5492,5490,5489,5386,5377,562,559,290,289,561,558)) OR (`UIMapId`=390 AND `QuestLineId` IN (5557,5503,5502,5501,5500,5499,5497,5496,5493,5492,5491,5489,5386,5377,562,560,316,290,289,561,558)) OR (`UIMapId`=388 AND `QuestLineId` IN (5502,5501,5500,5499,5497,5496,5493,5492,5491,562,560,316,561)) OR (`UIMapId`=379 AND `QuestLineId` IN (5546,5502,5501,5500,5499,5497,5496,5494,5492,5491,5488,5386,5377,560,316,290,289,561,554,553,550)) OR (`UIMapId`=371 AND `QuestLineId` IN (5557,5546,5536,5503,5502,5501,5500,5499,5497,5496,5495,5494,5491,5490,5489,5488,5386,5377,1402,947,560,559,316,290,289,558,555,554,553,550)) OR (`UIMapId`=862 AND `QuestLineId` IN (5673,5669,5631,5614,5427,5417,5411,5410,5391,5390,5389,5388,5387,5386,5384,5380,5379,5378,1030,1003,945,939,935,932,931,910,908,905,903,902,897,888,881,873,856,851,848,842,841,839,838,802,785,747,736,629,627,626,625,623,622,620,617,614,612,604,318)) OR (`UIMapId`=210 AND `QuestLineId` IN (1401,403)) OR (`UIMapId`=627 AND `QuestLineId` IN (5638,5513,1251,364,359,333,332,331,330,329,328,327,326,325,324,323,322,321,302,297,294,291,280,257,256,255,254,253,252,251,250,247,221,211,206,205,181,180,179,178,177,175,97,96,95,94,309,278,176,152,144,130)) OR (`UIMapId`=2216 AND `QuestLineId` IN (5672,5544,5506)) OR (`UIMapId`=2213 AND `QuestLineId` IN (5716,5672,5544,5506)) OR (`UIMapId`=85 AND `QuestLineId` IN (5697,5691,5673,5638,5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1267,1108,1107,1003,973,802,636,612,546,539,516,377,300,290,263,261,260,550));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=63163 WHERE (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=84 AND `QuestLineId` IN (5697,5691,5673,5638,5593,5519,5513,5511,5497,5482,5458,5399,5382,5377,5372,1289,1276,1267,1108,1030,1000,972,957,929,926,916,858,797,781,737,637,635,589,576,547,546,539,526,421,347,300,289,262,259,240,198,131)) OR (`UIMapId`=896 AND `QuestLineId` IN (5673,5449,5447,5432,5388,5384,5376,5373,5372,5371,1104,1000,940,922,916,911,903,901,887,851,847,845,843,745,592,442,5448,5446,5443,5441,5440,5437,5435,5433,591)) OR (`UIMapId`=895 AND `QuestLineId` IN (5449,5447,5432,5388,5384,5382,5380,5379,5378,5377,5376,5375,5374,5373,5372,5371,1104,1030,1004,1000,940,939,930,929,922,921,916,911,909,907,904,903,901,896,887,873,851,849,848,847,845,843,810,797,785,746,745,737,638,633,632,628,624,621,619,616,613,603,592,589,583,442,5448,5446,5443,5441,5440,5437,5436,5435,5434,5433,5431,591,586)) OR (`UIMapId`=1161 AND `QuestLineId` IN (5382,5380,5379,5378,5377,5376,5375,5374,5372,5371,1030,1004,1000,940,939,930,922,921,916,909,907,904,901,896,887,851,849,847,845,843,810,797,785,746,745,737,638,633,632,628,624,621,589,442)) OR (`UIMapId`=210 AND `QuestLineId` IN (1401,403)) OR (`UIMapId`=50 AND `QuestLineId` IN (5504,414,403,289)) OR (`UIMapId`=2371 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5703,5699,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2472 AND `QuestLineId` IN (5780,5703,5699,5695,5690)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62876 WHERE (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5900,5803,5799,5791,5782,5780,5779,5776,5772,5763,5744,5742,5741,5736,5734,5733,5732,5717,5716,5711,5705,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5678,5673,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2371 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5703,5699,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2472 AND `QuestLineId` IN (5780,5703,5699,5695,5690));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62748 WHERE (`UIMapId`=2255 AND `QuestLineId` IN (5900,5776,5772,5741,5716,5694,5686,5685,5672,5669,5668,5666,5663,5662,5661,5660,5659,5642,5641,5631,5630,5617,5615,5614,5598,5593,5558,5551,5550,5544,5534,5531,5530,5529,5526,5525,5523,5521,5520,5506)) OR (`UIMapId`=2213 AND `QuestLineId` IN (5716,5672,5544,5506)) OR (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=2371 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5703,5699,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2472 AND `QuestLineId` IN (5780,5703,5699,5695,5690));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62706 WHERE (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=2346 AND `QuestLineId` IN (5900,5776,5772,5741,5694,5686,5685,5669,5668,5663,5662,5661,5660,5659,5642,5641,5631,5615,5614));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62493 WHERE (`UIMapId`=2371 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5703,5699,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5602,5598,5593,5572,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416,5903)) OR (`UIMapId`=2472 AND `QuestLineId` IN (5780,5703,5699,5695,5690)) OR (`UIMapId`=2339 AND `QuestLineId` IN (5799,5697,5691,5690,5684,5673,5617)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5717,5715,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5669,5668,5663,5662,5661,5660,5659,5642,5641,5631,5617,5615,5614,5903)) OR (`UIMapId`=2404 AND `QuestLineId` IN (5638,5593,5519,5513,5511,5482,5382,5377,1289,1276,1267,1108,1030,957,926,858,576,546,539,526,300,289,262,240)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5900,5803,5799,5791,5782,5780,5779,5776,5772,5763,5744,5742,5741,5736,5734,5733,5732,5717,5716,5711,5705,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5678,5673,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=896 AND `QuestLineId` IN (5673,5449,5447,5432,5388,5384,5376,5373,5372,5371,1104,1000,940,922,916,911,903,901,887,851,847,845,843,745,592,442,5448,5446,5443,5441,5440,5437,5435,5433,591)) OR (`UIMapId`=895 AND `QuestLineId` IN (5449,5447,5432,5388,5384,5382,5380,5379,5378,5377,5376,5375,5374,5373,5372,5371,1104,1030,1004,1000,940,939,930,929,922,921,916,911,909,907,904,903,901,896,887,873,851,849,848,847,845,843,810,797,785,746,745,737,638,633,632,628,624,621,619,616,613,603,592,589,583,442,5448,5446,5443,5441,5440,5437,5436,5435,5434,5433,5431,591,586)) OR (`UIMapId`=1161 AND `QuestLineId` IN (5382,5380,5379,5378,5377,5376,5375,5374,5372,5371,1030,1004,1000,940,939,930,922,921,916,909,907,904,901,896,887,851,849,847,845,843,810,797,785,746,745,737,638,633,632,628,624,621,589,442));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=63003 WHERE (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62801 WHERE (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62680 WHERE (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62438 WHERE (`UIMapId`=85 AND `QuestLineId` IN (5697,5691,5673,5638,5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1267,1108,1107,1003,973,802,636,612,546,539,516,377,300,290,263,261,260,550)) OR (`UIMapId`=1525 AND `QuestLineId` IN (1257,1256,1252,1247,1245,1241,1235,1221,1220,1210,1204,1193,1190,1185,1184,1183,1182,1180,1172,1137,1121,1092,1069,1065,1041,1040,1039,1026,1024,1018,1017)) OR (`UIMapId`=2215 AND `QuestLineId` IN (5900,5799,5776,5772,5741,5732,5716,5711,5697,5694,5691,5686,5685,5684,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2213 AND `QuestLineId` IN (5716,5672,5544,5506)) OR (`UIMapId`=2255 AND `QuestLineId` IN (5900,5776,5772,5741,5716,5694,5686,5685,5672,5669,5668,5666,5663,5662,5661,5660,5659,5642,5641,5631,5630,5617,5615,5614,5598,5593,5558,5551,5550,5544,5534,5531,5530,5529,5526,5525,5523,5521,5520,5506)) OR (`UIMapId`=2346 AND `QuestLineId` IN (5900,5776,5772,5741,5694,5686,5685,5669,5668,5663,5662,5661,5660,5659,5642,5641,5631,5615,5614));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62958 WHERE (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=85 AND `QuestLineId` IN (5697,5691,5673,5638,5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1267,1108,1107,1003,973,802,636,612,546,539,516,377,300,290,263,261,260,550)) OR (`UIMapId`=1 AND `QuestLineId` IN (5638,5593,5538,5519,5513,5504,5499,5459,5389,5387,5382,1311,1295,1289,1267,1108,1107,1003,973,802,636,612,546,539,516,377,300,290,263,261,260,5430,1227,563,550,509,376,130));

DELETE FROM `ui_map_quest` WHERE (`UIMapId`=2214 AND `QuestId` IN (86707,83048,80208,86800,82448,82552)) OR (`UIMapId`=2255 AND `QuestId` IN (86610,80208,82552,86707,86800,83048)) OR (`UIMapId`=2371 AND `QuestId` IN (84001,83827,80208,82523,82519,81767,86179,82470,82238,80323,83532)) OR (`UIMapId`=2215 AND `QuestId` IN (86707,86800,86180,83048,82580,80208,83538)) OR (`UIMapId`=2248 AND `QuestId` IN (80208,79232,83530,86610)) OR (`UIMapId`=2472 AND `QuestId`=86610);
INSERT INTO `ui_map_quest` (`UIMapId`, `QuestId`, `VerifiedBuild`) VALUES
(2214, 86707, 62876), -- The Shadowguard Resurgence
(2214, 83048, 62876), -- Wayward Walkers
(2255, 86610, 62748), -- Nor Void of Night
(2255, 80208, 62748), -- Digging into Trouble
(2255, 82552, 62748), -- All Worked Up
(2371, 84001, 62748), -- Cart Blanche
(2371, 83827, 62748), -- Silence the Song
(2371, 80208, 62748), -- Digging into Trouble
(2371, 82523, 62748), -- Candle Kingbreaker
(2371, 82519, 62748), -- You Go Take Candle
(2371, 81767, 62748), -- Scrounge that Scrap!
(2214, 80208, 62493), -- Digging into Trouble
(2255, 86707, 63305), -- The Shadowguard Resurgence
(2255, 86800, 63305), -- Swipe 'Em
(2255, 83048, 63305), -- Wayward Walkers
(2215, 86707, 63305), -- The Shadowguard Resurgence
(2215, 86800, 63305), -- Swipe 'Em
(2215, 86180, 63305), -- Side Gig: Infested Waters
(2215, 83048, 63305), -- Wayward Walkers
(2215, 82580, 63305), -- Courier Mission: Ore Recovery
(2215, 80208, 63305), -- Digging into Trouble
(2214, 86800, 63305), -- Swipe 'Em
(2248, 80208, 63305), -- Digging into Trouble
(2371, 86179, 62876), -- Side Gig: Lucky Break's Big Break
(2214, 82448, 62493), -- Book It to the Library
(2214, 82552, 62493), -- All Worked Up
(2371, 82470, 62493), -- Arcane Riddles
(2371, 82238, 62493), -- Lava Glob Lobbin'
(2371, 80323, 62493), -- Foggy Faceoff
(2215, 83538, 62438), -- Excavation Liberation
(2248, 79232, 63305), -- Those Who Fell
(2248, 83530, 63305), -- Hallowfall Fishing Derby
(2472, 86610, 63163), -- Nor Void of Night
(2248, 86610, 63163), -- Nor Void of Night
(2371, 83532, 62876); -- Hallowfall Fishing Derby

UPDATE `ui_map_quest` SET `VerifiedBuild`=63305 WHERE (`UIMapId`=2248 AND `QuestId` IN (85051,86707,86800,86178,86180,85554,81692,83101,83079,83028,81750,82258,83048,82580,82518,84680,84248,85960,85945,85944,85914,82470,83537,80323,82523,83930,82288,82448)) OR (`UIMapId`=2339 AND `QuestId` IN (82448,82470)) OR (`UIMapId`=2255 AND `QuestId` IN (86178,86180,85554,83079,82580,82518,82258)) OR (`UIMapId`=2215 AND `QuestId` IN (85051,86178,85554,81692,83079,82518,82258)) OR (`UIMapId`=2214 AND `QuestId` IN (85051,86178,86180,85554,81692,83079,82580,82518,82258)) OR (`UIMapId`=371 AND `QuestId`=30134);
UPDATE `ui_map_quest` SET `VerifiedBuild`=62876 WHERE (`UIMapId`=2214 AND `QuestId` IN (84680,84248,86179,86178,86177,85554,81692,83537,83101,83028,82258)) OR (`UIMapId`=2339 AND `QuestId`=81854) OR (`UIMapId`=2248 AND `QuestId` IN (84680,84248,86179,86178,86177,85554,81692,83101,83028,82552,81656,82258,81620,81854,86707,83532,83537,83048)) OR (`UIMapId`=2371 AND `QuestId` IN (84680,84248,86178,86177,85554,81692,81854,83101,83028,82552,81656,82258,81620,83537,83048));
UPDATE `ui_map_quest` SET `VerifiedBuild`=62748 WHERE (`UIMapId`=2255 AND `QuestId` IN (85962,85960,85945,85913,82523,82519,81767)) OR (`UIMapId`=2371 AND `QuestId` IN (86610,85962,85960,85945,85913,81692,82552)) OR (`UIMapId`=2248 AND `QuestId` IN (84001,83827,85962,85960,85945,85913,81692,83538,82552,82523,83930,82519,81767));
UPDATE `ui_map_quest` SET `VerifiedBuild`=62706 WHERE (`UIMapId`=2339 AND `QuestId`=82470) OR (`UIMapId`=2346 AND `QuestId` IN (85962,85960,85945,85913));
UPDATE `ui_map_quest` SET `VerifiedBuild`=62493 WHERE (`UIMapId`=2371 AND `QuestId` IN (81692,82448,84680,84248,85962,85960,85945,85913,83028,82518,82288,82258,82254,83538)) OR (`UIMapId`=2472 AND `QuestId`=86800) OR (`UIMapId`=2339 AND `QuestId` IN (82448,82470)) OR (`UIMapId`=2248 AND `QuestId` IN (86707,86800,81692,82448,81656,84680,84248,85962,85960,85945,85913,83028,82580,82518,82288,82258,82254)) OR (`UIMapId`=2214 AND `QuestId` IN (84680,84248,85962,85960,85945,85913,81692,83028,82580,82518,81656,82288,82258,82254,85051,86178,86177,86180,85554,82470,81854,83538,82238,80323));
UPDATE `ui_map_quest` SET `VerifiedBuild`=63003 WHERE (`UIMapId`=2248 AND `QuestId` IN (84001,83827,86179,86178,85554,81692,83079,83048,83028,82254));
UPDATE `ui_map_quest` SET `VerifiedBuild`=62801 WHERE (`UIMapId`=2248 AND `QuestId` IN (84680,84248,86707,86179,86178,86177,85554,81692,83538,83028,82523,83930));
UPDATE `ui_map_quest` SET `VerifiedBuild`=62680 WHERE (`UIMapId`=2339 AND `QuestId` IN (82470,82448));
UPDATE `ui_map_quest` SET `VerifiedBuild`=62438 WHERE (`UIMapId`=2248 AND `QuestId` IN (83538,81656,82288)) OR (`UIMapId`=2215 AND `QuestId` IN (84680,84248,85962,85960,85945,85913,81692,83028,82518,81656,82254,81620,82288)) OR (`UIMapId`=2255 AND `QuestId` IN (85962,85960,85945,85913,83538,83028,82518,81656,82288,82254,81620)) OR (`UIMapId`=2346 AND `QuestId` IN (85962,85960,85945,85913));
UPDATE `ui_map_quest` SET `VerifiedBuild`=63163 WHERE (`UIMapId`=2371 AND `QuestId` IN (86178,85554,81692,81854,82552,82256,86610)) OR (`UIMapId`=2339 AND `QuestId`=81854) OR (`UIMapId`=2248 AND `QuestId` IN (84001,83827,86179,86178,85554,81692,81854,80323,82552,82519,81767,82256));
UPDATE `ui_map_quest` SET `VerifiedBuild`=62958 WHERE (`UIMapId`=2339 AND `QuestId` IN (82470,81854)) OR (`UIMapId`=2248 AND `QuestId` IN (85051,85945,85944,85914,85913,81692,82470,81854,83538,83028,80323,82518,81656,81620));

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2669754 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 24888 (Cosmetic - See Locus-Walker in Foundation Hall, Dornogal)*/, 2909446 /*Map: 2738 (K'aresh) - Phase: 0*/, 2909441 /*Map: 2738 (K'aresh) - Phase: 0*/, 2909443 /*Map: 2738 (K'aresh) - Phase: 0*/, 2909444 /*Map: 2738 (K'aresh) - Phase: 0*/, 2909440 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 27185*/, 2773498 /*Map: 2738 (K'aresh) - Phase: 0*/, 2774046 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722730 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722630 /*Map: 1 (Kalimdor) - Phase: 0*/, 2722647 /*Map: 1 (Kalimdor) - Phase: 0*/, 2852189 /*Map: 1 (Kalimdor) - Phase: 0*/, 2852192 /*Map: 1 (Kalimdor) - Phase: 0*/, 2852191 /*Map: 1 (Kalimdor) - Phase: 0*/, 2844416 /*Map: 1 (Kalimdor) - Phase: 0*/, 2844283 /*Map: 1 (Kalimdor) - Phase: 0*/, 2738042 /*Map: 2738 (K'aresh) - Phase: 0*/, 2738041 /*Map: 2738 (K'aresh) - Phase: 0*/, 2738036 /*Map: 2738 (K'aresh) - Phase: 0*/, 2738034 /*Map: 2738 (K'aresh) - Phase: 0*/, 2738039 /*Map: 2738 (K'aresh) - Phase: 0*/, 2737965 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680707 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680732 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680731 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680711 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680704 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680703 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680722 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680724 /*Map: 2738 (K'aresh) - Phase: 0*/, 2795428 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2792153 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792158 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792165 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792164 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792166 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792148 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792151 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792146 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792147 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792145 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792144 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792143 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2834477 /*Map: 2738 (K'aresh) - Phase: 0*/, 2786958 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2784580 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2771385 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2713427 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2713428 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2774664 /*Map: 2738 (K'aresh) - Phase: 0*/, 2714359 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2715937 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2714355 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2715936 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2715468 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2715505 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2714352 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2714354 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2710038 /*Map: 2738 (K'aresh) - Phase: 0*/, 2710039 /*Map: 2738 (K'aresh) - Phase: 0*/, 2710033 /*Map: 2738 (K'aresh) - Phase: 0*/, 2781393 /*Map: 2738 (K'aresh) - Phase: 0*/, 2693580 /*Map: 2738 (K'aresh) - Phase: 0*/, 2693521 /*Map: 2738 (K'aresh) - Phase: 0*/, 2693582 /*Map: 2738 (K'aresh) - Phase: 0*/, 2693575 /*Map: 2738 (K'aresh) - Phase: 0*/, 2693578 /*Map: 2738 (K'aresh) - Phase: 0*/, 2714418 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2714410 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2714357 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2714356 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2713749 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2713762 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2791089 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2791090 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2800005 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2773819 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2813780 /*Map: 2738 (K'aresh) - Phase: 0*/, 2773420 /*Map: 2738 (K'aresh) - Phase: 26196 (Cosmetic - See Shadanis at the Oasis)*/, 2735439 /*Map: 2738 (K'aresh) - Phase: 0*/, 2670195 /*Map: 2738 (K'aresh) - Phase: 0*/, 2735437 /*Map: 2738 (K'aresh) - Phase: 0*/, 2670176 /*Map: 2738 (K'aresh) - Phase: 0*/, 2670186 /*Map: 2738 (K'aresh) - Phase: 0*/, 2735433 /*Map: 2738 (K'aresh) - Phase: 0*/, 2725560 /*Map: 2738 (K'aresh) - Phase: 0*/, 2670184 /*Map: 2738 (K'aresh) - Phase: 0*/, 2670185 /*Map: 2738 (K'aresh) - Phase: 0*/, 2670177 /*Map: 2738 (K'aresh) - Phase: 0*/, 2670196 /*Map: 2738 (K'aresh) - Phase: 0*/, 2735436 /*Map: 2738 (K'aresh) - Phase: 0*/, 2713424 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2713734 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2713733 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2771291 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2834476 /*Map: 2738 (K'aresh) - Phase: 0*/, 3037469 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692568 /*Map: 2738 (K'aresh) - Phase: 0*/, 3037470 /*Map: 2738 (K'aresh) - Phase: 0*/, 3037471 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692558 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692554 /*Map: 2738 (K'aresh) - Phase: 0*/, 2682116 /*Map: 2738 (K'aresh) - Phase: 0*/, 2682095 /*Map: 2738 (K'aresh) - Phase: 0*/, 2682111 /*Map: 2738 (K'aresh) - Phase: 0*/, 2682117 /*Map: 2738 (K'aresh) - Phase: 0*/, 2682112 /*Map: 2738 (K'aresh) - Phase: 0*/, 2682108 /*Map: 2738 (K'aresh) - Phase: 0*/, 2682107 /*Map: 2738 (K'aresh) - Phase: 0*/, 2682106 /*Map: 2738 (K'aresh) - Phase: 0*/, 2581131 /*Map: 2738 (K'aresh) - Phase: 25181*/, 2783096 /*Map: 2738 (K'aresh) - Phase: 0*/, 2783178 /*Map: 2738 (K'aresh) - Phase: 26330*/, 2717982 /*Map: 2738 (K'aresh) - Phase: 25557 (Cosmetic - See Xal'atath in the Serrated Peaks)*/, 2686569 /*Map: 2738 (K'aresh) - Phase: 25257*/, 2588481 /*Map: 2738 (K'aresh) - Phase: 0*/, 2581130 /*Map: 2738 (K'aresh) - Phase: 25180 (Cosmetic - See Venari, Locus-Walker and Xal'atath at the Eco-Dome: Primus)*/, 2671415 /*Map: 2738 (K'aresh) - Phase: 25305*/, 2671878 /*Map: 2738 (K'aresh) - Phase: 0*/, 2671915 /*Map: 2738 (K'aresh) - Phase: 0*/, 2671906 /*Map: 2738 (K'aresh) - Phase: 0*/, 2671892 /*Map: 2738 (K'aresh) - Phase: 0*/, 2679928 /*Map: 2738 (K'aresh) - Phase: 0*/, 2679930 /*Map: 2738 (K'aresh) - Phase: 0*/, 2679929 /*Map: 2738 (K'aresh) - Phase: 0*/, 2679925 /*Map: 2738 (K'aresh) - Phase: 0*/, 2678038 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692116 /*Map: 2738 (K'aresh) - Phase: 25333*/, 2678036 /*Map: 2738 (K'aresh) - Phase: 0*/, 2678035 /*Map: 2738 (K'aresh) - Phase: 0*/, 2581751 /*Map: 2738 (K'aresh) - Phase: 0*/, 2581745 /*Map: 2738 (K'aresh) - Phase: 0*/, 2715864 /*Map: 2738 (K'aresh) - Phase: 0*/, 2715862 /*Map: 2738 (K'aresh) - Phase: 0*/, 2715859 /*Map: 2738 (K'aresh) - Phase: 0*/, 2715860 /*Map: 2738 (K'aresh) - Phase: 0*/, 2701828 /*Map: 2738 (K'aresh) - Phase: 0*/, 2715858 /*Map: 2738 (K'aresh) - Phase: 0*/, 2678063 /*Map: 2738 (K'aresh) - Phase: 0*/, 2689545 /*Map: 2738 (K'aresh) - Phase: 0*/, 2689525 /*Map: 2738 (K'aresh) - Phase: 0*/, 2678043 /*Map: 2738 (K'aresh) - Phase: 0*/, 2678061 /*Map: 2738 (K'aresh) - Phase: 0*/, 2581750 /*Map: 2738 (K'aresh) - Phase: 0*/, 2686020 /*Map: 2738 (K'aresh) - Phase: 25186 (Cosmetic - See Alleria, Locus-Walker and Xal'atath in Overlook ZoShuul)*/, 2581132 /*Map: 2738 (K'aresh) - Phase: 25180 (Cosmetic - See Venari, Locus-Walker and Xal'atath at the Eco-Dome: Primus)*/, 2683508 /*Map: 2738 (K'aresh) - Phase: 25186 (Cosmetic - See Alleria, Locus-Walker and Xal'atath in Overlook ZoShuul)*/, 2703940 /*Map: 2738 (K'aresh) - Phase: 0*/, 2703907 /*Map: 2738 (K'aresh) - Phase: 0*/, 2725487 /*Map: 2738 (K'aresh) - Phase: 25623*/, 2780998 /*Map: 2738 (K'aresh) - Phase: 0*/, 2703289 /*Map: 2738 (K'aresh) - Phase: 0*/, 2581137 /*Map: 2738 (K'aresh) - Phase: 25440*/, 2680585 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680588 /*Map: 2738 (K'aresh) - Phase: 25286 (Cosmetic - See dead Scout Yanhal)*/, 2680587 /*Map: 2738 (K'aresh) - Phase: 25285 (Cosmetic - See dead Scout Loshah)*/, 2596287 /*Map: 2738 (K'aresh) - Phase: 25125 (Cosmetic - See Alleria, Locus-Walker and Xal'atath at The Glided Landing)*/, 2596658 /*Map: 2738 (K'aresh) - Phase: 25179*/, 2596288 /*Map: 2738 (K'aresh) - Phase: 25125 (Cosmetic - See Alleria, Locus-Walker and Xal'atath at The Glided Landing)*/, 2783374 /*Map: 2738 (K'aresh) - Phase: 0*/, 2783343 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692122 /*Map: 2738 (K'aresh) - Phase: 25338 (Cosmetic - See Locus-Walker at the entrance of Myzas Oasis)*/, 2595117 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2781529 /*Map: 2738 (K'aresh) - Phase: 26305 (Cosmetic - See Alleria and Locus-Walker before Xal'atath allied in Myzas Oasis)*/, 2690976 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2690974 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2690973 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2690968 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2690969 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691891 /*Map: 2738 (K'aresh) - Phase: 25327 (Cosmetic - See Alleria Windrunner at The Lap of Luxury)*/, 2691549 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691547 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691584 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691567 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691552 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2714584 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691583 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691585 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691586 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691553 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691587 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691588 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691556 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691546 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691589 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691582 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2691893 /*Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)*/, 2690683 /*Map: 2738 (K'aresh) - Phase: 25298 (Cosmetic - See Alleria Windrunner and Locus-Walker near Omen)*/, 2691430 /*Map: 2738 (K'aresh) - Phase: 25496 (Personal - The P.O.S.T Void Presence)*/, 2595666 /*Map: 2738 (K'aresh) - Phase: 25496 (Personal - The P.O.S.T Void Presence)*/, 2691825 /*Map: 2738 (K'aresh) - Phase: 25324*/, 2691187 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2597023 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2597022 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2594366 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2689582 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2779738 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2779731 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2779730 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2689590 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2689595 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2689569 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2690171 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2594365 /*Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)*/, 2592030 /*Map: 2738 (K'aresh) - Phase: 25322 (Cosmetic - See Omen at the entrance of Tazavesh, Karesh)*/, 2670576 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2850267 /*Map: 1 (Kalimdor) - Phase: 26788*/, 2850266 /*Map: 1 (Kalimdor) - Phase: 26788*/, 2505451 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2505507 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2505474 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2522286 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2522303 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2526150 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2526148 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2705125 /*Map: 2738 (K'aresh) - Phase: 25395*/, 2741901 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2742156 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2680719 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680718 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680708 /*Map: 2738 (K'aresh) - Phase: 0*/, 2499116 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2499158 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2499124 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2494802 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2494609 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2494605 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2499160 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2499123 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2499816 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2499817 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2494610 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2499125 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2499131 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2494607 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2494606 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2494614 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2494608 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2680749 /*Map: 2738 (K'aresh) - Phase: 0*/, 2778612 /*Map: 2738 (K'aresh) - Phase: 0*/, 2581593 /*Map: 2738 (K'aresh) - Phase: 25122*/, 2590644 /*Map: 2738 (K'aresh) - Phase: 24940 (Cosmetic - See Xal'atath, Soul-Scribes and her Oracles in The Oasis)*/, 2671837 /*Map: 2738 (K'aresh) - Phase: 0*/, 2590648 /*Map: 2738 (K'aresh) - Phase: 0*/, 2671817 /*Map: 2738 (K'aresh) - Phase: 0*/, 2687253 /*Map: 2738 (K'aresh) - Phase: 0*/, 2590645 /*Map: 2738 (K'aresh) - Phase: 24940 (Cosmetic - See Xal'atath, Soul-Scribes and her Oracles in The Oasis)*/, 2671956 /*Map: 2738 (K'aresh) - Phase: 0*/, 2581591 /*Map: 2738 (K'aresh) - Phase: 25122*/, 2583940 /*Map: 2738 (K'aresh) - Phase: 0*/, 2583918 /*Map: 2738 (K'aresh) - Phase: 0*/, 2671950 /*Map: 2738 (K'aresh) - Phase: 0*/, 2669400 /*Map: 2738 (K'aresh) - Phase: 0*/, 2583926 /*Map: 2738 (K'aresh) - Phase: 0*/, 2668918 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722057 /*Map: 2738 (K'aresh) - Phase: 0*/, 2583925 /*Map: 2738 (K'aresh) - Phase: 0*/, 2668916 /*Map: 2738 (K'aresh) - Phase: 0*/, 2722055 /*Map: 2738 (K'aresh) - Phase: 0*/, 2583915 /*Map: 2738 (K'aresh) - Phase: 0*/, 2780890 /*Map: 2738 (K'aresh) - Phase: 0*/, 2668935 /*Map: 2738 (K'aresh) - Phase: 0*/, 2580670 /*Map: 2738 (K'aresh) - Phase: 25255 (Cosmetic - See Xal'atath in Soul-Scribes camp in Castigaar)*/, 2671180 /*Map: 2738 (K'aresh) - Phase: 25136*/, 2581590 /*Map: 2738 (K'aresh) - Phase: 25631 (Cosmetic - See Ve'nari in The Oasis)*/, 2686648 /*Map: 2738 (K'aresh) - Phase: 25270 (Cosmetic - See Narathe near the Camp in Castigaar)*/, 2580364 /*Map: 2738 (K'aresh) - Phase: 25255 (Cosmetic - See Xal'atath in Soul-Scribes camp in Castigaar)*/, 2692109 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692114 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692111 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692112 /*Map: 2738 (K'aresh) - Phase: 0*/, 2706230 /*Map: 2738 (K'aresh) - Phase: 0*/, 2706215 /*Map: 2738 (K'aresh) - Phase: 0*/, 2706200 /*Map: 2738 (K'aresh) - Phase: 0*/, 2580546 /*Map: 2738 (K'aresh) - Phase: 25156 (Cosmetic - Xal'atath in Castigaar)*/, 2727543 /*Map: 2738 (K'aresh) - Phase: 0*/, 2581549 /*Map: 2738 (K'aresh) - Phase: 25073 (Cosmetic - See Soul-Scribe at Castigaar)*/, 2682298 /*Map: 2738 (K'aresh) - Phase: 24853 (Cosmetic - See Xal'atath in The Tempest Fields)*/, 2580523 /*Map: 2738 (K'aresh) - Phase: 0*/, 2678107 /*Map: 2738 (K'aresh) - Phase: 24855*/, 2579016 /*Map: 2738 (K'aresh) - Phase: 0*/, 2578980 /*Map: 2738 (K'aresh) - Phase: 0*/, 2578975 /*Map: 2738 (K'aresh) - Phase: 0*/, 2578974 /*Map: 2738 (K'aresh) - Phase: 0*/, 2578965 /*Map: 2738 (K'aresh) - Phase: 0*/, 2578978 /*Map: 2738 (K'aresh) - Phase: 0*/, 2580318 /*Map: 2738 (K'aresh) - Phase: 25065 (Cosmetic - See Venari, Xal'atath and Locus-Walker at Eco-Dome: Rovan)*/, 2577447 /*Map: 2738 (K'aresh) - Phase: 24779 (Cosmetic - See Venari, Xal'atath and Locus-Walker at Eco-Dome: Rovan)*/, 2710105 /*Map: 2738 (K'aresh) - Phase: 25501 (Cosmetic - Locus-Walker, Om'resh, Xal'atath near Stacked Stolen Crates in Eco-Dome: Rhovan)*/, 2710106 /*Map: 2738 (K'aresh) - Phase: 25501 (Cosmetic - Locus-Walker, Om'resh, Xal'atath near Stacked Stolen Crates in Eco-Dome: Rhovan)*/, 2686064 /*Map: 2738 (K'aresh) - Phase: 25330*/, 2580319 /*Map: 2738 (K'aresh) - Phase: 25065 (Cosmetic - See Venari, Xal'atath and Locus-Walker at Eco-Dome: Rovan)*/, 2684359 /*Map: 2738 (K'aresh) - Phase: 0*/, 2684363 /*Map: 2738 (K'aresh) - Phase: 0*/, 2684361 /*Map: 2738 (K'aresh) - Phase: 0*/, 2684364 /*Map: 2738 (K'aresh) - Phase: 0*/, 2684362 /*Map: 2738 (K'aresh) - Phase: 0*/, 2577449 /*Map: 2738 (K'aresh) - Phase: 24779 (Cosmetic - See Venari, Xal'atath and Locus-Walker at Eco-Dome: Rovan)*/, 2579843 /*Map: 2738 (K'aresh) - Phase: 0*/, 2579799 /*Map: 2738 (K'aresh) - Phase: 25066*/, 2579826 /*Map: 2738 (K'aresh) - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2669754, 2552, 24888, 0, 0, 63305), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 24888 (Cosmetic - See Locus-Walker in Foundation Hall, Dornogal)
(2909446, 2738, 0, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 0
(2909441, 2738, 0, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 0
(2909443, 2738, 0, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 0
(2909444, 2738, 0, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 0
(2909440, 2552, 27185, 0, 0, 63305), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 27185
(2773498, 2738, 0, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 0
(2774046, 2738, 0, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 0
(2722730, 2738, 0, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 0
(2722630, 1, 0, 0, 0, 63305), -- Map: 1 (Kalimdor) - Phase: 0
(2722647, 1, 0, 0, 0, 63305), -- Map: 1 (Kalimdor) - Phase: 0
(2852189, 1, 0, 0, 0, 63305), -- Map: 1 (Kalimdor) - Phase: 0
(2852192, 1, 0, 0, 0, 63305), -- Map: 1 (Kalimdor) - Phase: 0
(2852191, 1, 0, 0, 0, 63305), -- Map: 1 (Kalimdor) - Phase: 0
(2844416, 1, 0, 0, 0, 63305), -- Map: 1 (Kalimdor) - Phase: 0
(2844283, 1, 0, 0, 0, 63305), -- Map: 1 (Kalimdor) - Phase: 0
(2738042, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2738041, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2738036, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2738034, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2738039, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2737965, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2680707, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2680732, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2680731, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2680711, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2680704, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2680703, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2680722, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2680724, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2795428, 2738, 25157, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2792153, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792158, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792165, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792164, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792166, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792148, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792151, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792146, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792147, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792145, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792144, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2792143, 2738, 26414, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 26414
(2834477, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2786958, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2784580, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2771385, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2713427, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2713428, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2774664, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2714359, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2715937, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2714355, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2715936, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2715468, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2715505, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2714352, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2714354, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2710038, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2710039, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2710033, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2781393, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2693580, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2693521, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2693582, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2693575, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2693578, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2714418, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2714410, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2714357, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2714356, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2713749, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2713762, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2791089, 2738, 26414, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 26414
(2791090, 2738, 26414, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 26414
(2800005, 2738, 26414, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 26414
(2773819, 2738, 25157, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2813780, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2773420, 2738, 26196, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 26196 (Cosmetic - See Shadanis at the Oasis)
(2735439, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2670195, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2735437, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2670176, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2670186, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2735433, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2725560, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2670184, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2670185, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2670177, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2670196, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2735436, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2713424, 2738, 25157, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2713734, 2738, 25157, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2713733, 2738, 25157, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2771291, 2738, 25157, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2834476, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(3037469, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2692568, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(3037470, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(3037471, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2692558, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2692554, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2682116, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2682095, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2682111, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2682117, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2682112, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2682108, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2682107, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2682106, 2738, 0, 0, 0, 62493), -- Map: 2738 (K'aresh) - Phase: 0
(2581131, 2738, 25181, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25181
(2783096, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2783178, 2738, 26330, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 26330
(2717982, 2738, 25557, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25557 (Cosmetic - See Xal'atath in the Serrated Peaks)
(2686569, 2738, 25257, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25257
(2588481, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2581130, 2738, 25180, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25180 (Cosmetic - See Venari, Locus-Walker and Xal'atath at the Eco-Dome: Primus)
(2671415, 2738, 25305, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25305
(2671878, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2671915, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2671906, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2671892, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2679928, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2679930, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2679929, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2679925, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2678038, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2692116, 2738, 25333, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25333
(2678036, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2678035, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2581751, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2581745, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2715864, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2715862, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2715859, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2715860, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2701828, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2715858, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2678063, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2689545, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2689525, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2678043, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2678061, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2581750, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2686020, 2738, 25186, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25186 (Cosmetic - See Alleria, Locus-Walker and Xal'atath in Overlook ZoShuul)
(2581132, 2738, 25180, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25180 (Cosmetic - See Venari, Locus-Walker and Xal'atath at the Eco-Dome: Primus)
(2683508, 2738, 25186, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25186 (Cosmetic - See Alleria, Locus-Walker and Xal'atath in Overlook ZoShuul)
(2703940, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2703907, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2725487, 2738, 25623, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25623
(2780998, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2703289, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2581137, 2738, 25440, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25440
(2680585, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2680588, 2738, 25286, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25286 (Cosmetic - See dead Scout Yanhal)
(2680587, 2738, 25285, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25285 (Cosmetic - See dead Scout Loshah)
(2596287, 2738, 25125, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25125 (Cosmetic - See Alleria, Locus-Walker and Xal'atath at The Glided Landing)
(2596658, 2738, 25179, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25179
(2596288, 2738, 25125, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25125 (Cosmetic - See Alleria, Locus-Walker and Xal'atath at The Glided Landing)
(2783374, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2783343, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2692122, 2738, 25338, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25338 (Cosmetic - See Locus-Walker at the entrance of Myzas Oasis)
(2595117, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2781529, 2738, 26305, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 26305 (Cosmetic - See Alleria and Locus-Walker before Xal'atath allied in Myzas Oasis)
(2690976, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2690974, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2690973, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2690968, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2690969, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691891, 2738, 25327, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25327 (Cosmetic - See Alleria Windrunner at The Lap of Luxury)
(2691549, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691547, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691584, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691567, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691552, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2714584, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691583, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691585, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691586, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691553, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691587, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691588, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691556, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691546, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691589, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691582, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2691893, 2738, 25289, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25289 (Tazavesh - Dimensius Invaders)
(2690683, 2738, 25298, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25298 (Cosmetic - See Alleria Windrunner and Locus-Walker near Omen)
(2691430, 2738, 25496, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25496 (Personal - The P.O.S.T Void Presence)
(2595666, 2738, 25496, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25496 (Personal - The P.O.S.T Void Presence)
(2691825, 2738, 25324, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25324
(2691187, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2597023, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2597022, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2594366, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2689582, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2779738, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2779731, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2779730, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2689590, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2689595, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2689569, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2690171, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2594365, 2738, 25195, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25195 (Tazavesh - Darkness Among Us)
(2592030, 2738, 25322, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25322 (Cosmetic - See Omen at the entrance of Tazavesh, Karesh)
(2670576, 2552, 0, 0, 0, 62438), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2850267, 1, 26788, 0, 0, 63305), -- Map: 1 (Kalimdor) - Phase: 26788
(2850266, 1, 26788, 0, 0, 63305), -- Map: 1 (Kalimdor) - Phase: 26788
(2505451, 2552, 0, 0, 0, 63305), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2505507, 2552, 0, 0, 0, 63305), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2505474, 2552, 0, 0, 0, 63305), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2522286, 2552, 0, 0, 0, 63305), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2522303, 2552, 0, 0, 0, 63305), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2526150, 2552, 0, 0, 0, 63305), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2526148, 2552, 0, 0, 0, 63305), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2705125, 2738, 25395, 0, 0, 63163), -- Map: 2738 (K'aresh) - Phase: 25395
(2741901, 2738, 25157, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2742156, 2738, 25157, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2680719, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2680718, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2680708, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2499116, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2499158, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2499124, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2494802, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2494609, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2494605, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2499160, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2499123, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2499816, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2499817, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2494610, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2499125, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2499131, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2494607, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2494606, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2494614, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2494608, 2552, 0, 0, 0, 62748), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2680749, 2738, 0, 0, 0, 62748), -- Map: 2738 (K'aresh) - Phase: 0
(2778612, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2581593, 2738, 25122, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25122
(2590644, 2738, 24940, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 24940 (Cosmetic - See Xal'atath, Soul-Scribes and her Oracles in The Oasis)
(2671837, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2590648, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2671817, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2687253, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2590645, 2738, 24940, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 24940 (Cosmetic - See Xal'atath, Soul-Scribes and her Oracles in The Oasis)
(2671956, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2581591, 2738, 25122, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25122
(2583940, 2738, 0, 0, 0, 62438); -- Map: 2738 (K'aresh) - Phase: 0

INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2583918, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2671950, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2669400, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2583926, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2668918, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2722057, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2583925, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2668916, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2722055, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2583915, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2780890, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2668935, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2580670, 2738, 25255, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25255 (Cosmetic - See Xal'atath in Soul-Scribes camp in Castigaar)
(2671180, 2738, 25136, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25136
(2581590, 2738, 25631, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25631 (Cosmetic - See Ve'nari in The Oasis)
(2686648, 2738, 25270, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25270 (Cosmetic - See Narathe near the Camp in Castigaar)
(2580364, 2738, 25255, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25255 (Cosmetic - See Xal'atath in Soul-Scribes camp in Castigaar)
(2692109, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2692114, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2692111, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2692112, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2706230, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2706215, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2706200, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2580546, 2738, 25156, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25156 (Cosmetic - Xal'atath in Castigaar)
(2727543, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2581549, 2738, 25073, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25073 (Cosmetic - See Soul-Scribe at Castigaar)
(2682298, 2738, 24853, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 24853 (Cosmetic - See Xal'atath in The Tempest Fields)
(2580523, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2678107, 2738, 24855, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 24855
(2579016, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2578980, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2578975, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2578974, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2578965, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2578978, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2580318, 2738, 25065, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25065 (Cosmetic - See Venari, Xal'atath and Locus-Walker at Eco-Dome: Rovan)
(2577447, 2738, 24779, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 24779 (Cosmetic - See Venari, Xal'atath and Locus-Walker at Eco-Dome: Rovan)
(2710105, 2738, 25501, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25501 (Cosmetic - Locus-Walker, Om'resh, Xal'atath near Stacked Stolen Crates in Eco-Dome: Rhovan)
(2710106, 2738, 25501, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25501 (Cosmetic - Locus-Walker, Om'resh, Xal'atath near Stacked Stolen Crates in Eco-Dome: Rhovan)
(2686064, 2738, 25330, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25330
(2580319, 2738, 25065, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25065 (Cosmetic - See Venari, Xal'atath and Locus-Walker at Eco-Dome: Rovan)
(2684359, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2684363, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2684361, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2684364, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2684362, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2577449, 2738, 24779, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 24779 (Cosmetic - See Venari, Xal'atath and Locus-Walker at Eco-Dome: Rovan)
(2579843, 2738, 0, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 0
(2579799, 2738, 25066, 0, 0, 62438), -- Map: 2738 (K'aresh) - Phase: 25066
(2579826, 2738, 0, 0, 0, 62438); -- Map: 2738 (K'aresh) - Phase: 0

UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (2513652, 2566037, 2513682, 2487509, 2526510); -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (2478299, 2347280, 2598992, 2577108, 2839851, 2165492, 2454148, 1525592, 2834475, 2552281, 2595709, 2779662, 2737295, 2559510, 2539844, 2524149, 2526564, 2524137, 2438711, 2409748, 2358298, 2288924, 1780509, 1765170, 1498985, 1480361, 1578973, 1483872, 1174114, 1289000, 1483928, 1174116, 1174111, 1429777, 2505658, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2535890, 2528174, 1480298, 1215777, 2194169, 1674566, 1674584, 1674620, 1410010, 1410009, 208504, 490034, 487768, 474713, 474714, 475396, 475397, 467179, 465383, 2526510, 2505413, 2505470, 2505453, 2505473, 2526145, 2522300, 2522284, 2526142, 2522287, 2526154, 2522299, 2522283, 2522281, 2522282, 2522305, 2526153, 2522279, 2526157, 2522298, 2518048, 2518047, 2522297, 2526162, 2518044, 2526149, 1744419);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (2412371, 1448534); -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseGroup`=1445, `VerifiedBuild`=63305 WHERE `SpawnTrackingId`=2552578; -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId`=1174115; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (2505658, 2839851, 2535890); -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=24825, `VerifiedBuild`=63305 WHERE `SpawnTrackingId`=2598992; -- Map: 1 (Kalimdor) - Phase: 24825
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (1387286, 1386863, 1386861); -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (1063686, 1051130); -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2834475, 2347280, 2598992, 2577108, 2552281, 2595709, 2779662, 2737295, 2539844, 2559510, 2524149, 2526564, 2524137, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2438711, 2409748, 2358298, 2288924, 1578973, 1483872, 1498985, 1429777, 1480361, 1289000, 1063686, 1476874, 1429886, 1617992, 1538497, 1487658, 1344952, 1351778, 1418359, 431539, 430277, 430276, 431377, 11915, 240658, 2505658, 2839851, 1483928, 1174111, 2475980, 2478351, 2478325, 2478254, 2478011, 2478523, 2537241, 1765170, 1174114, 1174116);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2505658, 2839851); -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId`=2526510; -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2183902, 2191720, 2191166, 2191167, 2180366, 2191168, 2191179, 2191173, 2191178, 2180364, 2191170, 2240785); -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (1386863, 1386861); -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (1344952, 1351778, 1418359); -- Map: 1643 (Kul Tiras) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2362905, 2352963, 32703); -- Map: 0 (Eastern Kingdoms) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63003 WHERE `SpawnTrackingId` IN (2475980, 2478351, 2478325, 2478254, 2478011, 2478523, 2834475, 2347280, 2598992, 2577108, 2839851, 2552281, 2595709, 2779662, 2737295, 2559510, 2537241, 2539844, 2524149, 2526564, 2524137, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2438711, 2409748, 2358298, 2288924, 1765170, 1498985, 1480298, 1429777, 2505658, 1480361, 1483928, 1215777, 1578973, 1483872, 1174114);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63003 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63003 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63003 WHERE `SpawnTrackingId`=2526510; -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63003 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63003 WHERE `SpawnTrackingId` IN (1387286, 1386863, 1386861); -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63003 WHERE `SpawnTrackingId`=1174115; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2347280, 2598992, 2577108, 2552281, 2595709, 2779662, 2737295, 2559510, 2537241, 2524149, 2526564, 2524137, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2528174, 2438711, 2409748, 2358298, 2288924, 1483928, 1498985, 1480361, 1429777, 1174116, 2839851, 2453932, 2535890, 1765170, 1289000, 2475980, 2478351, 2478325, 2478254, 2478011, 2478523, 2834475, 1480298, 1174111, 1922839, 1915178, 1834576, 1538494, 1533947, 165624);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2839851, 2535890); -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId`=2526510; -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId`=1063686; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (1386863, 1386861); -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62748 WHERE `SpawnTrackingId` IN (2537241, 2347280, 2598992, 2577108, 2438711, 2453932, 2552281, 2595709, 2779662, 2737295, 2559510, 2524149, 2526564, 2524137, 2539844, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2409748, 2358298, 2288924, 1498985, 1765170, 1480361, 1429777, 1174114, 2839851, 1483928, 1578973, 1483872, 1215777, 1174111, 2505658);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62748 WHERE `SpawnTrackingId` IN (2505658, 2839851); -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62748 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62748 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62748 WHERE `SpawnTrackingId` IN (2513652, 2566037, 2513682, 2526510); -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62748 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62748 WHERE `SpawnTrackingId`=1387286; -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62748 WHERE `SpawnTrackingId`=1174115; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62706 WHERE `SpawnTrackingId` IN (2347280, 2598992, 2577108, 2839851, 2438711, 2453932, 2552281, 2595709, 2779662, 2737295, 2559510, 2539844, 2524149, 2526564, 2524137, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2409748, 2358298, 2288924, 1498985, 1578973, 1483872, 1480361, 1289000);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62706 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62706 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62706 WHERE `SpawnTrackingId` IN (2513652, 2566037, 2513682, 2526510); -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62706 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62706 WHERE `SpawnTrackingId`=1448534; -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62706 WHERE `SpawnTrackingId`=1387286; -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62706 WHERE `SpawnTrackingId`=1051130; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId` IN (2347280, 2598992, 2577108, 2839851, 2438711, 2453932, 2552281, 2595709, 2779662, 2737295, 2559510, 2537241, 2539844, 2524149, 2526564, 2524137, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2409748, 2358298, 2288924, 1765170, 1498985, 1480361, 1429777, 1174114, 2475980, 2478351, 2478325, 2478254, 2478011, 2478523, 1578973, 1483872, 1480298, 1215777, 1174116, 2453169, 1174111, 2496880, 2194169, 1674566, 1674584, 1674620, 1410010, 1410009, 208504, 490034, 487768, 474713, 474714, 475396, 475397, 467179, 465383, 2362905, 2352963, 1617992, 1538497, 1487658, 1476874, 431539, 430277, 430276, 431377, 11915, 32703);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId` IN (2513652, 2566037, 2513682, 2526510); -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId` IN (2183902, 2191720, 2191166, 2191167, 2180366, 2191168, 2191179, 2191173, 2191178, 2180364, 2191170, 2240785); -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId` IN (1387286, 1386863, 1386861); -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId`=1448534; -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId`=1051130; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId`=1174115; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId`=2839851; -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId`=1429886; -- Map: 1643 (Kul Tiras) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=24825, `VerifiedBuild`=63305 WHERE `SpawnTrackingId`=2577108; -- Map: 0 (Eastern Kingdoms) - Phase: 24825
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (1448534, 2158408); -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId`=1174115; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId`=95166; -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2029417, 1871966, 2034510, 2007682, 2037613); -- Map: 2222 (The Shadowlands) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId`=1507180; -- Map: 1643 (Kul Tiras) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62801 WHERE `SpawnTrackingId` IN (2537241, 2535890, 2528174, 2347280, 2598992, 2577108, 2839851, 2453932, 2552281, 2595709, 2779662, 2737295, 2559510, 2524149, 2526564, 2524137, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2438711, 2409748, 2358298, 2288924, 1498985, 1578973, 1483872, 1483928, 1215777, 1174111);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62801 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62801 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62801 WHERE `SpawnTrackingId`=2526510; -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62801 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62801 WHERE `SpawnTrackingId`=1448534; -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62801 WHERE `SpawnTrackingId`=1063686; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62680 WHERE `SpawnTrackingId` IN (2347280, 2577108, 2438711, 2453932, 2552281, 2595709, 2779662, 2737295, 2559510, 2537241, 2539844, 2524149, 2526564, 2524137, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 2409748, 2358298, 2288924, 1765170, 1498985, 1480361, 1578973, 1483872, 1174114);
UPDATE `spawn_tracking_template` SET `PhaseId`=24825, `VerifiedBuild`=62680 WHERE `SpawnTrackingId`=2598992; -- Map: 1 (Kalimdor) - Phase: 24825
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62680 WHERE `SpawnTrackingId`=2839851; -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62680 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62680 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62680 WHERE `SpawnTrackingId` IN (2513652, 2566037, 2513682, 2526510); -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62680 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62680 WHERE `SpawnTrackingId`=1387286; -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62680 WHERE `SpawnTrackingId`=1051130; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId` IN (2453932, 2496880, 2397210, 2535890, 2528174, 2505658, 2598992, 2577108, 2438711, 2552281, 2595709, 2779662, 2737295, 2559510, 2524149, 2526564, 2524137, 2409748, 2358298, 2288924, 1498985, 1480298, 1429777, 1480361, 1174116, 1174111, 2678019, 2592094, 2720672, 1483928, 1765170, 1289000);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId` IN (2839851, 2552578, 2779016); -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId` IN (2513652, 2566037, 2513682, 2526510); -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId` IN (1051130, 1063686); -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseGroup`=1445, `VerifiedBuild`=62438 WHERE `SpawnTrackingId`=2552578; -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId`=1448534; -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId` IN (1386863, 1386861); -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId`=1063686; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62958 WHERE `SpawnTrackingId` IN (2347280, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084, 1838594, 2539844, 2537241, 2834475, 2598992, 2577108, 2839851, 2552281, 2595709, 2779662, 2737295, 2559510, 2524149, 2526564, 2524137, 2438711, 2409748, 2358298, 2288924, 1498985, 1480298, 1765170, 1429777);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62958 WHERE `SpawnTrackingId` IN (2678019, 2720672); -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62958 WHERE `SpawnTrackingId`=2592094; -- Map: 2706 (Undermine) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62958 WHERE `SpawnTrackingId`=2526510; -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62958 WHERE `SpawnTrackingId`=2183902; -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62958 WHERE `SpawnTrackingId` IN (1386863, 1386861, 1387286); -- Map: 1669 (Argus) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62958 WHERE `SpawnTrackingId`=1174115; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62493 WHERE `SpawnTrackingId` IN (1429886, 1344952, 1351778, 1418359); -- Map: 1643 (Kul Tiras) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=24825, `VerifiedBuild`=62493 WHERE `SpawnTrackingId`=2577108; -- Map: 0 (Eastern Kingdoms) - Phase: 24825
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62438 WHERE `SpawnTrackingId`=1174115; -- Map: 1220 (Broken Isles) - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=2909446 AND `QuestObjectiveId`=463473) OR (`SpawnTrackingId`=2909441 AND `QuestObjectiveId`=463472) OR (`SpawnTrackingId`=2909443 AND `QuestObjectiveId`=463471) OR (`SpawnTrackingId`=2909444 AND `QuestObjectiveId`=463470) OR (`SpawnTrackingId`=2909440 AND `QuestObjectiveId`=463459) OR (`SpawnTrackingId`=2722647 AND `QuestObjectiveId`=457870) OR (`SpawnTrackingId`=2852189 AND `QuestObjectiveId`=462146) OR (`SpawnTrackingId`=2852192 AND `QuestObjectiveId`=462141) OR (`SpawnTrackingId`=2852191 AND `QuestObjectiveId`=462138) OR (`SpawnTrackingId`=2844283 AND `QuestObjectiveId`=462150) OR (`SpawnTrackingId`=2795428 AND `QuestObjectiveId`=461265) OR (`SpawnTrackingId`=2784580 AND `QuestObjectiveId`=461043) OR (`SpawnTrackingId`=2771385 AND `QuestObjectiveId`=460049) OR (`SpawnTrackingId`=2774664 AND `QuestObjectiveId`=460258) OR (`SpawnTrackingId`=2710038 AND `QuestObjectiveId`=463825) OR (`SpawnTrackingId`=2710039 AND `QuestObjectiveId`=457293) OR (`SpawnTrackingId`=2710033 AND `QuestObjectiveId`=463824) OR (`SpawnTrackingId`=2773819 AND `QuestObjectiveId`=460214) OR (`SpawnTrackingId`=2813780 AND `QuestObjectiveId`=462101) OR (`SpawnTrackingId`=2771291 AND `QuestObjectiveId`=460051) OR (`SpawnTrackingId`=2783096 AND `QuestObjectiveId`=460976) OR (`SpawnTrackingId`=2686569 AND `QuestObjectiveId`=457616) OR (`SpawnTrackingId`=2588481 AND `QuestObjectiveId`=453353) OR (`SpawnTrackingId`=2671915 AND `QuestObjectiveId`=454974) OR (`SpawnTrackingId`=2671906 AND `QuestObjectiveId`=454973) OR (`SpawnTrackingId`=2671892 AND `QuestObjectiveId`=454966) OR (`SpawnTrackingId`=2671415 AND `QuestObjectiveId`=454911) OR (`SpawnTrackingId`=2671878 AND `QuestObjectiveId`=454951) OR (`SpawnTrackingId`=2581751 AND `QuestObjectiveId`=456927) OR (`SpawnTrackingId`=2581745 AND `QuestObjectiveId`=456929) OR (`SpawnTrackingId`=2678038 AND `QuestObjectiveId`=455643) OR (`SpawnTrackingId`=2692116 AND `QuestObjectiveId`=456534) OR (`SpawnTrackingId`=2678036 AND `QuestObjectiveId`=455641) OR (`SpawnTrackingId`=2678035 AND `QuestObjectiveId`=455640) OR (`SpawnTrackingId`=2678063 AND `QuestObjectiveId`=455632) OR (`SpawnTrackingId`=2689545 AND `QuestObjectiveId`=456292) OR (`SpawnTrackingId`=2689525 AND `QuestObjectiveId`=456291) OR (`SpawnTrackingId`=2678043 AND `QuestObjectiveId`=455627) OR (`SpawnTrackingId`=2678061 AND `QuestObjectiveId`=455629) OR (`SpawnTrackingId`=2581750 AND `QuestObjectiveId`=453338) OR (`SpawnTrackingId`=2703940 AND `QuestObjectiveId`=457027) OR (`SpawnTrackingId`=2703907 AND `QuestObjectiveId`=457025) OR (`SpawnTrackingId`=2725487 AND `QuestObjectiveId`=458049) OR (`SpawnTrackingId`=2683508 AND `QuestObjectiveId` IN (457158,458853)) OR (`SpawnTrackingId`=2780998 AND `QuestObjectiveId`=460802) OR (`SpawnTrackingId`=2703289 AND `QuestObjectiveId`=456975) OR (`SpawnTrackingId`=2680585 AND `QuestObjectiveId`=455720) OR (`SpawnTrackingId`=2680588 AND `QuestObjectiveId`=456277) OR (`SpawnTrackingId`=2680587 AND `QuestObjectiveId`=456276) OR (`SpawnTrackingId`=2596288 AND `QuestObjectiveId`=458836) OR (`SpawnTrackingId`=2783374 AND `QuestObjectiveId`=456910) OR (`SpawnTrackingId`=2783343 AND `QuestObjectiveId`=456902) OR (`SpawnTrackingId`=2595117 AND `QuestObjectiveId`=456544) OR (`SpawnTrackingId`=2691430 AND `QuestObjectiveId`=453600) OR (`SpawnTrackingId`=2595666 AND `QuestObjectiveId`=456341) OR (`SpawnTrackingId`=2597022 AND `QuestObjectiveId`=453710) OR (`SpawnTrackingId`=2594365 AND `QuestObjectiveId`=456132) OR (`SpawnTrackingId`=2594366 AND `QuestObjectiveId`=453593) OR (`SpawnTrackingId`=2597023 AND `QuestObjectiveId`=453592) OR (`SpawnTrackingId`=2850267 AND `QuestObjectiveId`=462154) OR (`SpawnTrackingId`=2850266 AND `QuestObjectiveId`=462153) OR (`SpawnTrackingId`=2705125 AND `QuestObjectiveId`=457123) OR (`SpawnTrackingId`=2742156 AND `QuestObjectiveId`=459314) OR (`SpawnTrackingId`=2774046 AND `QuestObjectiveId`=461981) OR (`SpawnTrackingId`=2778612 AND `QuestObjectiveId`=460498) OR (`SpawnTrackingId`=2590644 AND `QuestObjectiveId`=454938) OR (`SpawnTrackingId`=2671837 AND `QuestObjectiveId`=454950) OR (`SpawnTrackingId`=2590648 AND `QuestObjectiveId`=454949) OR (`SpawnTrackingId`=2671817 AND `QuestObjectiveId`=454948) OR (`SpawnTrackingId`=2687253 AND `QuestObjectiveId`=456238) OR (`SpawnTrackingId`=2671956 AND `QuestObjectiveId`=455005) OR (`SpawnTrackingId`=2671180 AND `QuestObjectiveId`=454837) OR (`SpawnTrackingId`=2580670 AND `QuestObjectiveId`=460525) OR (`SpawnTrackingId`=2686648 AND `QuestObjectiveId`=454559) OR (`SpawnTrackingId`=2727543 AND `QuestObjectiveId`=458127) OR (`SpawnTrackingId`=2580546 AND `QuestObjectiveId`=455726) OR (`SpawnTrackingId`=2581549 AND `QuestObjectiveId` IN (455725,460520)) OR (`SpawnTrackingId`=2580523 AND `QuestObjectiveId`=453239) OR (`SpawnTrackingId`=2678107 AND `QuestObjectiveId`=453238) OR (`SpawnTrackingId`=2580318 AND `QuestObjectiveId` IN (458122,457941)) OR (`SpawnTrackingId`=2710105 AND `QuestObjectiveId`=458120) OR (`SpawnTrackingId`=2710106 AND `QuestObjectiveId`=457413) OR (`SpawnTrackingId`=2686064 AND `QuestObjectiveId`=456121) OR (`SpawnTrackingId`=2579843 AND `QuestObjectiveId`=453218) OR (`SpawnTrackingId`=2579799 AND `QuestObjectiveId`=453216) OR (`SpawnTrackingId`=2579826 AND `QuestObjectiveId`=453215);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2909446, 463473, 63305), -- 2909446
(2909441, 463472, 63305), -- 2909441
(2909443, 463471, 63305), -- 2909443
(2909444, 463470, 63305), -- 2909444
(2909440, 463459, 63305), -- 2909440
(2722647, 457870, 63305), -- 2722647
(2852189, 462146, 63305), -- 2852189
(2852192, 462141, 63305), -- 2852192
(2852191, 462138, 63305), -- 2852191
(2844283, 462150, 63305), -- 2844283
(2795428, 461265, 62748), -- 2795428
(2784580, 461043, 62493), -- 2784580
(2771385, 460049, 62493), -- 2771385
(2774664, 460258, 62493), -- 2774664
(2710038, 463825, 62493), -- 2710038
(2710039, 457293, 62493), -- 2710039
(2710033, 463824, 62493), -- 2710033
(2773819, 460214, 62493), -- 2773819
(2813780, 462101, 62493), -- 2813780
(2771291, 460051, 62748), -- 2771291
(2783096, 460976, 62438), -- 2783096
(2686569, 457616, 62438), -- 2686569
(2588481, 453353, 62438), -- 2588481
(2671915, 454974, 62438), -- 2671915
(2671906, 454973, 62438), -- 2671906
(2671892, 454966, 62438), -- 2671892
(2671415, 454911, 62438), -- 2671415
(2671878, 454951, 62438), -- 2671878
(2581751, 456927, 62438), -- 2581751
(2581745, 456929, 62438), -- 2581745
(2678038, 455643, 62438), -- 2678038
(2692116, 456534, 62438), -- 2692116
(2678036, 455641, 62438), -- 2678036
(2678035, 455640, 62438), -- 2678035
(2678063, 455632, 62438), -- 2678063
(2689545, 456292, 62438), -- 2689545
(2689525, 456291, 62438), -- 2689525
(2678043, 455627, 62438), -- 2678043
(2678061, 455629, 62438), -- 2678061
(2581750, 453338, 62438), -- 2581750
(2703940, 457027, 62438), -- 2703940
(2703907, 457025, 62438), -- 2703907
(2725487, 458049, 62438), -- 2725487
(2683508, 457158, 62438), -- 2683508
(2780998, 460802, 62438), -- 2780998
(2703289, 456975, 62438), -- 2703289
(2683508, 458853, 62438), -- 2683508
(2680585, 455720, 62438), -- 2680585
(2680588, 456277, 62438), -- 2680588
(2680587, 456276, 62438), -- 2680587
(2596288, 458836, 62438), -- 2596288
(2783374, 456910, 62438), -- 2783374
(2783343, 456902, 62438), -- 2783343
(2595117, 456544, 62438), -- 2595117
(2691430, 453600, 62438), -- 2691430
(2595666, 456341, 62438), -- 2595666
(2597022, 453710, 62438), -- 2597022
(2594365, 456132, 62438), -- 2594365
(2594366, 453593, 62438), -- 2594366
(2597023, 453592, 62438), -- 2597023
(2850267, 462154, 63305), -- 2850267
(2850266, 462153, 63305), -- 2850266
(2705125, 457123, 63163), -- 2705125
(2742156, 459314, 62876), -- 2742156
(2774046, 461981, 62438), -- 2774046
(2778612, 460498, 62438), -- 2778612
(2590644, 454938, 62438), -- 2590644
(2671837, 454950, 62438), -- 2671837
(2590648, 454949, 62438), -- 2590648
(2671817, 454948, 62438), -- 2671817
(2687253, 456238, 62438), -- 2687253
(2671956, 455005, 62438), -- 2671956
(2671180, 454837, 62438), -- 2671180
(2580670, 460525, 62438), -- 2580670
(2686648, 454559, 62438), -- 2686648
(2727543, 458127, 62438), -- 2727543
(2580546, 455726, 62438), -- 2580546
(2581549, 455725, 62438), -- 2581549
(2581549, 460520, 62438), -- 2581549
(2580523, 453239, 62438), -- 2580523
(2678107, 453238, 62438), -- 2678107
(2580318, 458122, 62438), -- 2580318
(2580318, 457941, 62438), -- 2580318
(2710105, 458120, 62438), -- 2710105
(2710106, 457413, 62438), -- 2710106
(2686064, 456121, 62438), -- 2686064
(2579843, 453218, 62438), -- 2579843
(2579799, 453216, 62438), -- 2579799
(2579826, 453215, 62438); -- 2579826

UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=63305 WHERE (`QuestObjectiveId`=452291 AND `SpawnTrackingId`=2412371) OR (`QuestObjectiveId`=337036 AND `SpawnTrackingId`=1525592) OR (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=386346 AND `SpawnTrackingId`=1674584) OR (`QuestObjectiveId`=353024 AND `SpawnTrackingId`=1674584) OR (`QuestObjectiveId`=341370 AND `SpawnTrackingId`=1429886) OR (`QuestObjectiveId`=449930 AND `SpawnTrackingId`=2505413);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=63163 WHERE (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985) OR (`QuestObjectiveId`=336295 AND `SpawnTrackingId`=1344952) OR (`QuestObjectiveId`=295018 AND `SpawnTrackingId`=1351778) OR (`QuestObjectiveId`=292653 AND `SpawnTrackingId`=1476874) OR (`QuestObjectiveId`=429854 AND `SpawnTrackingId`=2191179) OR (`QuestObjectiveId`=429853 AND `SpawnTrackingId`=2191173) OR (`QuestObjectiveId`=429852 AND `SpawnTrackingId`=2191178) OR (`QuestObjectiveId`=341370 AND `SpawnTrackingId`=1429886) OR (`QuestObjectiveId`=337578 AND `SpawnTrackingId`=1617992) OR (`QuestObjectiveId`=335371 AND `SpawnTrackingId`=1538497) OR (`QuestObjectiveId`=252598 AND `SpawnTrackingId` IN (430277,430276,431377)) OR (`QuestObjectiveId`=449025 AND `SpawnTrackingId`=2478351) OR (`QuestObjectiveId`=449020 AND `SpawnTrackingId`=2478325) OR (`QuestObjectiveId`=449010 AND `SpawnTrackingId`=2478254) OR (`QuestObjectiveId`=449005 AND `SpawnTrackingId`=2478011) OR (`QuestObjectiveId`=449040 AND `SpawnTrackingId`=2475980) OR (`QuestObjectiveId`=449028 AND `SpawnTrackingId`=2478523);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=63003 WHERE (`QuestObjectiveId`=449025 AND `SpawnTrackingId`=2478351) OR (`QuestObjectiveId`=449020 AND `SpawnTrackingId`=2478325) OR (`QuestObjectiveId`=449010 AND `SpawnTrackingId`=2478254) OR (`QuestObjectiveId`=449005 AND `SpawnTrackingId`=2478011) OR (`QuestObjectiveId`=449040 AND `SpawnTrackingId`=2475980) OR (`QuestObjectiveId`=449028 AND `SpawnTrackingId`=2478523) OR (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=62876 WHERE (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985) OR (`QuestObjectiveId`=449025 AND `SpawnTrackingId`=2478351) OR (`QuestObjectiveId`=449020 AND `SpawnTrackingId`=2478325) OR (`QuestObjectiveId`=449010 AND `SpawnTrackingId`=2478254) OR (`QuestObjectiveId`=449005 AND `SpawnTrackingId`=2478011) OR (`QuestObjectiveId`=449040 AND `SpawnTrackingId`=2475980) OR (`QuestObjectiveId`=449028 AND `SpawnTrackingId`=2478523) OR (`QuestObjectiveId`=451884 AND `SpawnTrackingId`=2158408) OR (`QuestObjectiveId`=396463 AND `SpawnTrackingId`=1915178) OR (`QuestObjectiveId`=336869 AND `SpawnTrackingId`=1533947);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=62748 WHERE (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=450075 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450074 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=62706 WHERE (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=450075 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450074 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=62493 WHERE (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=450075 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450074 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985) OR (`QuestObjectiveId`=449025 AND `SpawnTrackingId`=2478351) OR (`QuestObjectiveId`=449020 AND `SpawnTrackingId`=2478325) OR (`QuestObjectiveId`=449010 AND `SpawnTrackingId`=2478254) OR (`QuestObjectiveId`=449005 AND `SpawnTrackingId`=2478011) OR (`QuestObjectiveId`=449040 AND `SpawnTrackingId`=2475980) OR (`QuestObjectiveId`=449028 AND `SpawnTrackingId`=2478523) OR (`QuestObjectiveId`=386346 AND `SpawnTrackingId`=1674584) OR (`QuestObjectiveId`=353024 AND `SpawnTrackingId`=1674584) OR (`QuestObjectiveId`=341370 AND `SpawnTrackingId`=1429886) OR (`QuestObjectiveId`=429854 AND `SpawnTrackingId`=2191179) OR (`QuestObjectiveId`=429853 AND `SpawnTrackingId`=2191173) OR (`QuestObjectiveId`=429852 AND `SpawnTrackingId`=2191178) OR (`QuestObjectiveId`=337578 AND `SpawnTrackingId`=1617992) OR (`QuestObjectiveId`=335371 AND `SpawnTrackingId`=1538497) OR (`QuestObjectiveId`=336295 AND `SpawnTrackingId`=1344952) OR (`QuestObjectiveId`=295018 AND `SpawnTrackingId`=1351778) OR (`QuestObjectiveId`=292653 AND `SpawnTrackingId`=1476874) OR (`QuestObjectiveId`=252598 AND `SpawnTrackingId` IN (430277,430276,431377));
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=62801 WHERE (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=62680 WHERE (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=450075 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450074 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=62438 WHERE (`SpawnTrackingId`=2552281 AND `QuestObjectiveId`=456254) OR (`SpawnTrackingId`=2592094 AND `QuestObjectiveId`=457308) OR (`SpawnTrackingId`=2524149 AND `QuestObjectiveId`=450656) OR (`SpawnTrackingId`=2526564 AND `QuestObjectiveId`=450654) OR (`SpawnTrackingId`=2524137 AND `QuestObjectiveId`=450653) OR (`SpawnTrackingId`=2409748 AND `QuestObjectiveId` IN (450075,450074,450069,450068)) OR (`SpawnTrackingId`=1498985 AND `QuestObjectiveId`=341368);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=62958 WHERE (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084)) OR (`QuestObjectiveId`=456254 AND `SpawnTrackingId`=2552281) OR (`QuestObjectiveId`=457308 AND `SpawnTrackingId`=2592094) OR (`QuestObjectiveId`=450656 AND `SpawnTrackingId`=2524149) OR (`QuestObjectiveId`=450654 AND `SpawnTrackingId`=2526564) OR (`QuestObjectiveId`=450653 AND `SpawnTrackingId`=2524137) OR (`QuestObjectiveId`=450069 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=450068 AND `SpawnTrackingId`=2409748) OR (`QuestObjectiveId`=341368 AND `SpawnTrackingId`=1498985);

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (124428, 101886, 131933, 131926, 131916, 128284, 128236, 106174, 119398, 101757, 124135, 80598, 117532, 120714, 122124, 128448, 127545, 123194, 123199, 99858, 125628, 123121, 116464, 128375, 128712, 129965, 131904, 124090, 117873, 119392, 124133, 131902, 128362, 131925, 129131, 102521, 123141, 131914, 129485, 129214, 129934, 125918, 131309, 117381, 131920, 126558, 123654, 123650, 123656, 123658, 124239, 124238, 127549, 128150, 128157, 129015, 129014, 123811, 122367, 123460, 114596, 118349, 123447, 117668, 120297, 117826, 129741, 120116, 111370, 123444, 119789, 115756, 115757, 120167, 123446, 117807, 131539, 113165, 131901, 131923, 111442, 129159, 115825, 131310, 113401, 121335, 123171, 129910, 121338, 129348, 131937, 121400, 123116, 131931, 131909, 123175, 114589, 130292, 112132, 136827, 136826, 136312, 136319, 136315, 131311, 129690, 129693, 106189, 136313, 106175, 136311, 136325, 136324, 115507, 114590, 123177, 121399, 122795, 122794, 122793, 114315, 121337, 121398, 121397, 120366, 129349, 123172, 123178, 129999, 119943, 128416, 123180, 119942, 114595, 114587, 123921, 124092, 129158, 131992, 123928, 124095, 126796, 128370, 114311, 122195, 123118, 123124, 111311, 130395, 123176, 114584, 136565, 123179, 121336, 124762, 115582, 114583, 131942, 127490, 123127, 111911, 121393, 123119, 113398, 116383, 121395, 115826, 123126, 121958, 121389, 121391, 120032, 121956, 123120, 131918, 131917, 136519, 136518, 123125, 114593, 119950, 123173, 123174, 128365, 130291, 123122, 123130, 127853, 127881, 127880, 127883, 127478, 136032, 129851, 129347, 129451, 126390, 127751, 128722, 123138, 117704, 123135, 123137, 123128, 121419, 123916, 130283, 123911, 130281, 123134, 128501, 123813, 123555, 117864, 115934, 118153, 111503, 109478, 119948, 123136, 123816, 123132, 125861, 124618, 124532, 123131, 121320, 113609, 119949, 129242, 117941, 113656, 123875, 111099, 120330, 123129, 117531, 91248, 121176, 131409, 118211, 130097, 131305, 79442, 81679, 107689, 107917, 108185, 124766, 124421, 129133, 131428, 131429, 115337, 116638, 128011, 131537, 129163, 129832, 116968, 130469);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(124428, 0.697013258934020996, 0, 0, 63305),
(101886, 0.310000002384185791, 0, 0, 63305),
(131933, 0.208000004291534423, 1.5, 0, 63305),
(131926, 0.382999986410140991, 1.5, 0, 63305),
(131916, 0.347222000360488891, 1.5, 0, 63305),
(128284, 0.305999994277954101, 1.5, 0, 63305),
(128236, 0.722000002861022949, 2, 0, 63305),
(106174, 1.132115364074707031, 1.5, 0, 63305),
(119398, 2.062685966491699218, 0, 0, 63305),
(101757, 0.318779021501541137, 0, 0, 63305),
(124135, 1.314831852912902832, 0, 0, 63305),
(80598, 1.010885000228881835, 1.5, 0, 63305),
(117532, 0.347000002861022949, 1.5, 0, 63305),
(120714, 0.282763808965682983, 0.25, 0, 63305),
(122124, 0.310000002384185791, 0, 0, 63305),
(128448, 0.207999989390373229, 1.5, 0, 63305),
(127545, 0.305999994277954101, 1.5, 0, 63305),
(123194, 0.722000002861022949, 3, 0, 63305),
(123199, 0.698000013828277587, 3, 0, 63305),
(99858, 0.927166938781738281, 0.60000002384185791, 0, 63305),
(125628, 0.724423766136169433, 0, 0, 63305),
(123121, 0.305999994277954101, 1.5, 0, 63305),
(116464, 1.565289497375488281, 1.5, 0, 63305),
(128375, 0.966191768646240234, 0, 0, 63305),
(128712, 0.382999986410140991, 1.5, 0, 63305),
(129965, 1.477756977081298828, 1.875, 0, 63305),
(131904, 0.305999994277954101, 1.5, 0, 63305),
(124090, 0.836416006088256835, 0, 0, 63305),
(117873, 2.921630620956420898, 4.02500009536743164, 0, 63305),
(119392, 3.302712678909301757, 4.549999713897705078, 0, 63305),
(124133, 1.314831852912902832, 0, 0, 63305),
(131902, 0.347000002861022949, 1.5, 0, 63305),
(128362, 0.966191768646240234, 0, 0, 63305),
(131925, 0.388999998569488525, 1.5, 0, 63305),
(129131, 0.060000002384185791, 0.440000027418136596, 0, 63305),
(102521, 1.081571221351623535, 2, 0, 63305),
(123141, 0.722000002861022949, 3, 0, 63305),
(131914, 0.305999994277954101, 1.5, 0, 63305),
(129485, 0.349999994039535522, 1.5, 0, 63305),
(129214, 0.200000002980232238, 1, 0, 63305),
(129934, 2.328607559204101562, 0, 0, 63305),
(125918, 7.17758941650390625, 8, 0, 63305),
(131309, 3.125, 2.699999809265136718, 0, 63305),
(117381, 3.302712678909301757, 2.599999904632568359, 0, 63305),
(131920, 0.388999998569488525, 1.5, 0, 63305),
(126558, 4.659317970275878906, 0, 0, 63305),
(123654, 0.147745028138160705, 0, 0, 63305),
(123650, 0.147745028138160705, 0, 0, 63305),
(123656, 0.147745311260223388, 0, 0, 63305),
(123658, 0.147745311260223388, 0, 0, 63305),
(124239, 3.746803998947143554, 0, 0, 63305),
(124238, 3.746803998947143554, 0, 0, 63305),
(127549, 0.305999994277954101, 1.5, 0, 63305),
(128150, 0.347222000360488891, 1.50000011920928955, 0, 63305),
(128157, 0.698715090751647949, 1.5, 0, 63305),
(129015, 0.305999994277954101, 1.5, 0, 63305),
(129014, 0.305999994277954101, 1.5, 0, 63305),
(123811, 0.74140477180480957, 0, 0, 63305),
(122367, 0.5, 1, 0, 63305),
(123460, 0.649800002574920654, 1.799999952316284179, 0, 63305),
(114596, 0.542177200317382812, 1, 0, 63305),
(118349, 0.347000002861022949, 1.5, 0, 63305),
(123447, 0.649800002574920654, 1.799999952316284179, 0, 63305),
(117668, 1.265152454376220703, 2.399999856948852539, 0, 63305),
(120297, 1.857579588890075683, 5, 0, 63305),
(117826, 8.850650787353515625, 5.25, 0, 63305),
(129741, 1.809256196022033691, 2.274999856948852539, 0, 63305),
(120116, 0.347222000360488891, 1.5, 0, 63305),
(111370, 0.5, 1.5, 0, 63305),
(123444, 0.649800002574920654, 1.799999952316284179, 0, 63305),
(119789, 0.659023046493530273, 1, 0, 63305),
(115756, 0.948864400386810302, 1.80000007152557373, 0, 63305),
(115757, 0.948864400386810302, 1.80000007152557373, 0, 63305),
(120167, 1.426948308944702148, 0, 0, 63305),
(123446, 0.649800002574920654, 1.799999952316284179, 0, 63305),
(117807, 0.649800002574920654, 1.799999952316284179, 0, 63305),
(131539, 10, 0, 0, 63305),
(113165, 0.347222000360488891, 1.5, 0, 63305),
(131901, 1, 1.5, 0, 63305),
(131923, 0.305999994277954101, 1.5, 0, 63305),
(111442, 0.344729483127593994, 0.300000011920928955, 0, 63305),
(129159, 0.697013258934020996, 0, 0, 63305),
(115825, 0.372000008821487426, 1.5, 0, 63305),
(131310, 3.125, 2.699999809265136718, 0, 63305),
(113401, 0.305999994277954101, 1.5, 0, 63305),
(121335, 3.302712917327880859, 2.599999904632568359, 0, 63305),
(123171, 0.372000008821487426, 1.5, 0, 63305),
(129910, 0.460308820009231567, 1, 0, 63305),
(121338, 0.919484734535217285, 0.925000011920928955, 0, 63305),
(129348, 0.300000011920928955, 0, 0, 63305),
(131937, 0.347000002861022949, 1.5, 0, 63305),
(121400, 0.208000004291534423, 1.5, 0, 63305),
(123116, 0.305999994277954101, 1.5, 0, 63305),
(131931, 0.388999998569488525, 1.5, 0, 63305),
(131909, 0.722000002861022949, 3, 0, 63305),
(123175, 0.372000008821487426, 1.5, 0, 63305),
(114589, 0.542177200317382812, 1, 0, 63305),
(130292, 1.888888955116271972, 2, 0, 63305),
(112132, 3.415512561798095703, 4.374999523162841796, 0, 63305),
(136827, 1.469839096069335937, 2.20000004768371582, 0, 63305),
(136826, 2.421499967575073242, 2.20000004768371582, 0, 63305),
(136312, 2.418807268142700195, 0, 0, 63305),
(136319, 4.459519863128662109, 0, 0, 63305),
(136315, 4.399278163909912109, 5.399999618530273437, 0, 63305),
(131311, 3.125, 2.699999809265136718, 0, 63305),
(129690, 0.668075323104858398, 1, 0, 63305),
(129693, 1, 0, 0, 63305),
(106189, 1.132115364074707031, 1.5, 0, 63305),
(136313, 3.027236223220825195, 4.5, 0, 63305),
(106175, 1.132115364074707031, 1.5, 0, 63305),
(136311, 6.666667461395263671, 3.60000014305114746, 0, 63305),
(136325, 4.375827312469482421, 0, 0, 63305),
(136324, 1.064284563064575195, 2, 0, 63305),
(115507, 2.711948871612548828, 3.599999904632568359, 0, 63305),
(114590, 0.542177200317382812, 1, 0, 63305),
(123177, 0.236000001430511474, 1.5, 0, 63305),
(121399, 0.305999994277954101, 1.5, 0, 63305),
(122795, 1.186080455780029296, 2.25, 0, 63305),
(122794, 1.138637304306030273, 2.160000085830688476, 0, 63305),
(122793, 1.138637304306030273, 2.160000085830688476, 0, 63305),
(114315, 1.227306723594665527, 1.20000004768371582, 0, 63305),
(121337, 2.360051631927490234, 2.099999904632568359, 0, 63305),
(121398, 0.312499791383743286, 1.349999904632568359, 0, 63305),
(121397, 0.208000004291534423, 1.5, 0, 63305),
(120366, 0.5, 1, 0, 63305),
(129349, 0.329305171966552734, 0, 0, 63305),
(123172, 0.372000008821487426, 1.5, 0, 63305),
(123178, 0.236000001430511474, 1.5, 0, 63305),
(129999, 2.919695854187011718, 6, 0, 63305),
(119943, 0.372000008821487426, 1.5, 0, 63305),
(128416, 0.366853713989257812, 0.5, 0, 63305),
(123180, 0.236000001430511474, 1.5, 0, 63305),
(119942, 0.236000001430511474, 1.5, 0, 63305),
(114595, 0.542177200317382812, 1, 0, 63305),
(114587, 0.542177200317382812, 1, 0, 63305),
(123921, 1.46560370922088623, 0.550000011920928955, 0, 63305),
(124092, 0.889685750007629394, 0, 0, 63305),
(129158, 0.74140477180480957, 0, 0, 63305),
(131992, 1.193256378173828125, 0, 0, 63305),
(123928, 1.46560370922088623, 0.550000011920928955, 0, 63305),
(124095, 0.83641594648361206, 0, 0, 63305),
(126796, 0.5, 1, 0, 63305),
(128370, 0.966191768646240234, 0, 0, 63305),
(114311, 0.416000008583068847, 3, 0, 63305),
(122195, 0.539612531661987304, 0, 0, 63305),
(123118, 0.305999994277954101, 1.5, 0, 63305),
(123124, 0.305999994277954101, 1.5, 0, 63305),
(111311, 0.297494709491729736, 0, 0, 63305),
(130395, 2.266666889190673828, 2.40000009536743164, 0, 63305),
(123176, 0.236000001430511474, 1.5, 0, 63305),
(114584, 0.542177200317382812, 1, 0, 63305),
(136565, 0.372887372970581054, 0, 0, 63305),
(123179, 0.236000001430511474, 1.5, 0, 63305),
(121336, 3.302712678909301757, 2.599999904632568359, 0, 63305),
(124762, 2.833333253860473632, 1.27500009536743164, 0, 63305),
(115582, 0.663779318332672119, 1.424999952316284179, 0, 63305),
(114583, 0.542177200317382812, 1, 0, 63305),
(131942, 1.888888955116271972, 2, 0, 63305),
(127490, 2.533876657485961914, 4, 0, 63305),
(123127, 0.305999994277954101, 1.5, 0, 63305),
(111911, 0.817594408988952636, 0, 0, 63305),
(121393, 0.663779318332672119, 1.424999952316284179, 0, 63305),
(123119, 0.305999994277954101, 1.5, 0, 63305),
(113398, 0.305999994277954101, 1.5, 0, 63305),
(116383, 1, 1.5, 0, 63305),
(121395, 0.698715090751647949, 1.5, 0, 63305),
(115826, 0.236000001430511474, 1.5, 0, 63305),
(123126, 0.305999994277954101, 1.5, 0, 63305),
(121958, 0.64753502607345581, 0, 0, 63305),
(121389, 0.208000004291534423, 1.5, 0, 63305),
(121391, 0.305999994277954101, 1.5, 0, 63305),
(120032, 0.276269584894180297, 0, 0, 63305),
(121956, 0.539612531661987304, 0, 0, 63305),
(123120, 0.305999994277954101, 1.5, 0, 63305),
(131918, 0.347222000360488891, 1.5, 0, 63305),
(131917, 0.372000008821487426, 1.5, 0, 63305),
(136519, 9.318635940551757812, 0, 0, 63305),
(136518, 9.318635940551757812, 0, 0, 63305),
(123125, 0.305999994277954101, 1.5, 0, 63305),
(114593, 0.542177200317382812, 1, 0, 63305),
(119950, 0.305999994277954101, 1.5, 0, 63305),
(123173, 0.372000008821487426, 1.5, 0, 63305),
(123174, 0.372000008821487426, 1.5, 0, 63305),
(128365, 0.966191768646240234, 0, 0, 63305),
(130291, 1.888888955116271972, 2, 0, 63305),
(123122, 0.305999994277954101, 1.5, 0, 63305),
(123130, 0.305999994277954101, 1.5, 0, 63305),
(127853, 0.382999986410140991, 1.5, 0, 63305),
(127881, 0.305999994277954101, 1.5, 0, 63305),
(127880, 0.372000008821487426, 1.5, 0, 63305),
(127883, 0.283200025558471679, 1.80000007152557373, 0, 63305),
(127478, 2.919695615768432617, 6, 0, 63305),
(136032, 0.659132659435272216, 0.225000008940696716, 0, 63305),
(129851, 0.372000008821487426, 1.5, 0, 63305),
(129347, 0.788936018943786621, 0, 0, 63305),
(129451, 0.937548458576202392, 0, 0, 63305),
(126390, 0.372000008821487426, 1.5, 0, 63305),
(127751, 1, 0, 0, 63305),
(128722, 5, 3, 0, 63305),
(123138, 0.305999994277954101, 1.5, 0, 63305),
(117704, 0.240027263760566711, 0, 0, 63305),
(123135, 0.305999994277954101, 1.5, 0, 63305),
(123137, 0.305999994277954101, 1.5, 0, 63305),
(123128, 0.305999994277954101, 1.5, 0, 63305),
(121419, 1.451149702072143554, 0, 0, 63305),
(123916, 2.93120741844177246, 1.10000002384185791, 0, 63305),
(130283, 1.888888955116271972, 2, 0, 63305),
(123911, 2.93120741844177246, 1.10000002384185791, 0, 63305),
(130281, 1.888888955116271972, 2, 0, 63305),
(123134, 0.305999994277954101, 1.5, 0, 63305),
(128501, 0.178749561309814453, 0.450000017881393432, 0, 63305),
(123813, 0.889685750007629394, 0, 0, 63305),
(123555, 0.347222000360488891, 1.5, 0, 63305),
(117864, 0.347222000360488891, 1.5, 0, 63305),
(115934, 0.12163611501455307, 0, 0, 63305),
(118153, 0.12163611501455307, 0, 0, 63305),
(111503, 0.12163611501455307, 0, 0, 63305),
(109478, 0.382999986410140991, 1.5, 0, 63305),
(119948, 0.305999994277954101, 1.5, 0, 63305),
(123136, 0.305999994277954101, 1.5, 0, 63305),
(123816, 0.74140477180480957, 0, 0, 63305),
(123132, 0.305999994277954101, 1.5, 0, 63305),
(125861, 0.310000002384185791, 1, 0, 63305),
(124618, 0.310000002384185791, 1, 0, 63305),
(124532, 0.399838954210281372, 0.75, 0, 63305),
(123131, 0.305999994277954101, 1.5, 0, 63305),
(121320, 0.5, 0, 0, 63305),
(113609, 0.853075742721557617, 1.049999952316284179, 0, 63305),
(119949, 0.305999994277954101, 1.5, 0, 63305),
(129242, 1.477756977081298828, 1.875, 0, 63305),
(117941, 1.107008337974548339, 2.099999904632568359, 0, 63305),
(113656, 0.347000002861022949, 1.5, 0, 63305),
(123875, 0.697013258934020996, 0, 0, 63305),
(111099, 0.300000011920928955, 0, 0, 63305),
(120330, 0.370499968528747558, 0.324999988079071044, 0, 63305),
(123129, 0.305999994277954101, 1.5, 0, 63305),
(117531, 1, 1.5, 0, 63305),
(91248, 0.310000002384185791, 3, 0, 63305),
(121176, 0.387746483087539672, 0.5, 0, 63305),
(131409, 0.71274733543395996, 1.5, 0, 63305),
(118211, 0.347000002861022949, 1.5, 0, 63305),
(130097, 0.5, 0.5, 0, 63305),
(131305, 1.564759492874145507, 1, 0, 63305),
(79442, 1.157104849815368652, 1, 0, 63305),
(81679, 0.801885426044464111, 1.111111044883728027, 0, 63305),
(107689, 2.165999889373779296, 9, 0, 63305),
(107917, 2.166000127792358398, 9, 0, 63305),
(108185, 2.093999862670898437, 9, 0, 63305),
(124766, 2.165999889373779296, 9, 0, 63305),
(124421, 0.697013258934020996, 0, 0, 63305);

INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(129133, 0.060000002384185791, 0.440000027418136596, 0, 63305),
(131428, 1.443062067031860351, 0, 0, 63305),
(131429, 1.443062067031860351, 0, 0, 63305),
(115337, 2.529685735702514648, 1.65000009536743164, 0, 63305),
(116638, 0.921893417835235595, 1.5, 0, 63305),
(128011, 0.750786304473876953, 0.800000011920928955, 0, 63305),
(131537, 2.592274665832519531, 0, 0, 63305),
(129163, 2, 2, 0, 63305),
(129832, 0.863881826400756835, 7, 0, 63305),
(116968, 11.80086803436279296, 7, 0, 63305),
(130469, 2.763879060745239257, 0, 0, 63305);

UPDATE `creature_model_info` SET `VerifiedBuild`=63305 WHERE `DisplayID` IN (130708, 118171, 33665, 129445, 101439, 121707, 113755, 122387, 125179, 28151, 101993, 128331, 93759, 129136, 128286, 124011, 104595, 92985, 93662, 93686, 117761, 117763, 68671, 57780, 55366, 108710, 101574, 116186, 116188, 116171, 116189, 131764, 128735, 146, 127916, 116796, 117256, 117255, 70154, 91383, 119451, 117812, 117814, 109918, 119449, 117815, 117813, 92204, 46043, 55246, 20308, 77063, 29539, 80750, 21192, 58943, 111268, 128123, 114437, 121018, 121019, 121017, 121022, 37396, 121020, 65230, 130276, 130382, 55077, 58232, 37352, 42203, 30753, 68067, 130385, 130277, 121023, 121024, 100871, 33733, 100007, 26452, 123420, 105328, 32670, 131785, 131300, 130275, 49845, 56316, 75078, 99467, 123198, 36665, 26417, 100590, 101543, 101567, 99072, 101569, 101568, 101571, 101572, 121011, 121010, 121006, 121009, 121007, 121008, 118878, 121318, 123196, 120878, 121012, 69493, 51279, 121016, 119933, 101545, 101547, 120848, 121005, 120847, 120849, 121014, 121013, 121015, 120987, 120988, 118877, 121004, 120023, 118876, 118874, 118872, 118870, 118873, 118867, 121003, 121002, 118879, 117092, 121001, 122698, 121367, 117889, 115546, 115593, 117762, 117759, 119424, 119433, 117760, 115594, 122666, 119409, 122713, 115543, 123200, 115339, 128420, 124612, 128647, 128629, 128630, 121407, 121404, 128651, 127537, 128635, 128644, 128603, 128468, 122425, 128602, 128601, 128596, 128421, 117402, 115340, 122424, 118912, 117441, 128160, 115155, 110444, 110447, 118231, 118468, 118467, 30507, 118466, 118465, 108406, 131590, 102304, 69708, 77060, 78748, 102053, 117404, 65236, 123195, 76762, 122722, 61128, 84558, 113200, 123193, 101461, 55367, 49368, 60003, 72454, 100778, 86891, 100674, 129239, 119939, 45896, 123197, 123846, 42109, 101356, 123840, 101954, 101542, 101270, 101544, 94068, 101573, 117405, 116347, 71859, 116476, 65229, 123192, 93753, 119938, 123201, 77396, 129569, 116482, 119744, 122066, 122065, 121311, 121308, 121848, 120488, 119503, 2956, 118066, 114537, 120273, 65206, 116481, 112634, 115709, 120274, 120271, 116452, 116459, 120445, 120599, 120448, 119458, 118964, 112428, 117328, 22779, 89262, 117327, 43722, 43726, 124358, 129772, 27159, 27157, 35185, 35183, 14415, 110165, 35187, 35184, 85697, 94596, 94598, 15988, 15984, 5846, 1388, 94597, 99816, 1316, 93637, 744, 1372, 99819, 1387, 99817, 42388, 42387, 42384, 86338, 110186, 110185, 35186, 119886, 99822, 101799, 110615, 110611, 110616, 5770, 5769, 111659, 110181, 1338, 10824, 23513, 14575, 129591, 128867, 115749, 118997, 118481, 120497, 99860, 119005, 117938, 117772, 114542, 104797, 114988, 122208, 115748, 115731, 123899, 113940, 65452, 76788, 87593, 128378, 136673, 117473, 94543, 70334, 30736, 101481, 101763, 75299, 61947, 71830, 72076, 79714, 42629, 44551, 58170, 69083, 71848, 43865, 37527, 110619, 93581, 93596, 99465, 93600, 101473, 101476, 101475, 100406, 19287, 29834, 26321, 25608, 19744, 25878, 65083, 25609, 29835, 3058, 72952, 25655, 65171, 114543, 90787, 115729, 119054, 117937, 119053, 115720, 120656, 114415, 114413, 120403, 118065, 114416, 115741, 118230, 114408, 117329, 117377, 115205, 115733, 115750, 116455, 100878, 118403, 119262, 112723, 117042, 114772, 23962, 115488, 115487, 114558, 104498, 18274, 76758, 76760, 124469, 27217, 94226, 98513, 101953, 99205, 101951, 118854, 123363, 118846, 101044, 76789, 56815, 109286, 70927, 118855, 114178, 25644, 63776, 69194, 101952, 101039, 86791, 100882, 14951, 76790, 94227, 65253, 47441, 30098, 119391, 71961, 129615, 130339, 129658, 27854, 27957, 123997, 65240, 4590, 27853, 27852, 99936, 65451, 26311, 65250, 65226, 91712, 21871, 100041, 65356, 64331, 16883, 27719, 1924, 115723, 90258, 64971, 55989, 65412, 65371, 58822, 27667, 119394, 120866, 117870, 117607, 61763, 130296, 116349, 123147, 80595, 66705, 123797, 120860, 117872, 10256, 117871, 120867, 127717, 120864, 120858, 116485, 119393, 101459, 120856, 116483, 120863, 120862, 120865, 93591, 125243, 124414, 123144, 28456, 101598, 93592, 93601, 100891, 99170, 100889, 100885, 101639, 101595, 101596, 123234, 73708, 4588, 1130, 91271, 101734, 93576, 93599, 93595, 123788, 6121, 81444, 36611, 36595, 127367, 121267, 125339, 123985, 125752, 125426, 125776, 125382, 19995, 85981, 125384, 125768, 125377, 125244, 128709, 36544, 15470, 123887, 90786, 107794, 114789, 4587, 67149, 75082, 123236, 123308, 52459, 63835, 1160, 63834, 2536, 65222, 62644, 9829, 63622, 63833, 72695, 72710, 118444, 52230, 123233, 122056, 91931, 40358, 85008, 123238, 36577, 94173, 38614, 78854, 106365, 21864, 130387, 1425, 17696, 3133, 17694, 36638, 2974, 45423, 33520, 1444, 36758, 93638, 33974, 33977, 32323, 1445, 93725, 93951, 19288, 31588, 102054, 97936, 101434, 97651, 98510, 68547, 100407, 97658, 93950, 100564, 101327, 35490, 46735, 97649, 100722, 99094, 19285, 91330, 100408, 97650, 73353, 131795, 38340, 82239, 17723, 70050, 92438, 94915, 81320, 98267, 115534, 115576, 92750, 74269, 23257, 117840, 116129, 119793, 119787, 81322, 36576, 81324, 106909, 892, 46052, 13099, 40000, 51292, 73330, 29407, 45092, 15405, 69545, 118572, 123867, 99952, 75012, 94281, 120841, 90426, 116588, 117119, 120876, 120242, 130256, 130386, 66718, 128399, 129482, 119714, 119962, 119889, 115746, 116460, 115743, 116832, 116454, 117387, 117340, 115739, 121414, 106374, 117375, 121438, 115734, 114528, 116456, 115740, 115237, 117376, 66720, 116204, 56187, 114541, 114627, 112383, 115736, 117326, 120227, 91113, 56814, 79805, 119743, 56813, 116457, 116458, 115230, 115187, 115100, 115231, 118408, 116480, 49630, 110198, 93633, 117045, 116918, 112730, 116690, 112728, 114987, 112727, 103811, 118009, 118157, 113231, 103372, 103384, 91521, 113602, 114511, 102568, 90702, 90698, 114986, 115344, 127332, 125421, 125595, 125720, 127328, 112266, 127354, 125744, 125509, 125832, 125661, 125669, 125381, 40663, 125670, 125736, 127326, 125660, 125648, 125572, 112712, 115121, 111899, 115377, 114509, 112724, 115359, 79809, 117517, 108088, 115378, 90321, 118133, 115042, 115039, 115381, 121834, 121833, 121836, 115040, 121835, 118875, 104843, 100419, 100363, 122142, 130242, 131464, 130254, 136197, 130255, 121838, 121837, 1006, 114964, 114961, 117717, 131989, 115034, 80591, 59071, 75085, 119791, 119765, 121039, 115022, 115021, 115031, 115020, 118865, 114484, 117064, 117754, 128144, 116275, 65234, 116478, 118868, 127550, 115096, 112726, 127533, 120412, 117758, 127538, 116274, 115023, 117755, 115095, 100870, 128141, 116355, 127547, 115708, 115097, 123341, 116673, 117316, 119706, 116278, 119416, 62404, 123824, 92689, 65422, 44578, 59537, 59102, 25900, 69151, 69153, 65254, 27682, 11709, 86194, 59799, 127528, 101462, 84891, 101460, 80340, 101470, 101651, 101469, 101468, 101929, 123886, 90498, 70208, 45042, 123823, 78791, 41766, 59229, 123885, 66721, 37913, 53762, 123838, 123839, 129724, 129917, 132016, 123239, 93593, 119910, 116490, 120183, 115541, 119912, 116461, 119515, 119913, 119509, 119516, 119517, 119510, 119511, 119514, 115413, 103430, 115415, 115491, 101140, 115419, 115492, 23501, 101139, 114529, 114538, 117044, 114128, 119504, 114531, 115464, 120104, 122444, 119735, 116187, 93074, 93073, 73864, 27799, 118853, 114050, 115742, 118856, 116208, 119905, 114775, 79320, 118998, 114051, 118193, 118995, 118994, 118343, 118259, 121240, 94739, 121434, 121435, 117712, 117683, 27627, 117716, 117708, 117720, 82235, 121401, 117719, 117721, 117774, 117715, 117714, 117713, 122745, 120820, 117691, 136281, 136279, 131588, 29423, 125821, 117727, 123791, 64621, 115524, 124774, 118442, 100725, 118404, 27824, 123237, 30762, 119519, 46020, 116683, 115157, 127920, 118976, 116684, 118399, 127921, 117448, 80458, 127923, 117449, 118401, 105131, 127922, 117451, 118397, 118051, 114770, 115751, 86532, 107796, 54439, 114418, 113756, 99456, 115759, 104831, 55290, 117043, 78130, 26365, 87919, 95102, 73858, 73859, 73857, 117830, 120153, 73157, 129843, 118709, 128654, 48114, 77759, 116453, 115772, 114989, 115738, 115099, 115760, 116438, 115019, 116283, 116345, 121800, 116436, 115770, 116506, 121799, 131997, 136073, 132002, 116259, 115735, 115745, 119918, 119920, 116157, 115747, 119921, 123261, 115771, 114268, 116509, 117373, 116159, 116492, 116681, 114412, 115018, 74362, 74365, 114530, 115762, 119273, 114468, 114029, 116448, 92243, 116158, 114049, 96296, 69902, 116444, 117370, 117312, 117313, 114026, 117393, 74363, 121213, 117311, 117314, 119725, 116445, 114469, 116538, 116390, 118033, 114552, 115761, 66697, 114556, 116160, 114052, 118127, 117372, 116652, 116269, 117371, 114414, 116469, 116831, 114533, 116449, 120368, 120224, 120226, 119911, 117378, 118410, 116491, 116834, 114422, 116833, 117389, 117388, 116446, 120401, 114423, 118563, 120357, 118413, 117374, 115755, 114421, 116493, 104630, 116447, 115465, 115417, 115424, 118250, 104634, 115411, 117538, 132001, 14499, 128319, 84934, 10472, 7136, 99818, 4386, 14616, 99815, 1381, 35242, 35241, 35237, 1393, 1390, 110184, 1394, 6839, 99808, 99807, 99809, 131441, 56271, 129736, 112548, 23574, 123803, 123789, 73834, 16905, 44898, 44901, 73944, 16907, 16838, 44899, 12345, 14254, 19330, 44539, 31096, 82767, 82803, 82819, 83227, 66245, 12672, 12680, 12679, 83225, 4546, 51098, 56327, 12678, 12673, 14612, 99459, 16841, 62185, 137104, 99460, 1328, 1327, 43164, 86393, 99449, 75080, 35500, 99458, 1329, 110605, 35499, 42386, 124064, 66687, 126050, 57899, 109400, 109474, 109495, 108418, 108064, 91421, 108065, 109401, 77899, 109399, 90252, 2330, 71451, 2318, 72476, 67214, 3257, 94064, 94063, 49631, 93738, 35739, 93636, 86129, 82147, 92824, 83914, 54918, 107063, 24982, 83223, 82768, 74885, 98524, 114652, 93635, 111496, 90141, 93634, 3258, 93731, 99427, 8572, 43143, 42279, 94765, 93854, 26748, 131370, 33921, 129629, 66707, 87013, 78770, 26747, 124283, 83913, 44466, 54920, 70963, 123235, 43998, 116852, 70071, 129844, 235, 43788, 59802, 123169, 128328, 128081, 128326, 128327, 114788, 64582, 119932, 1284, 19075, 46516, 30758, 36990, 34973, 93518, 31807, 116376, 127481, 54959, 31805, 30245, 71628, 72478, 6271, 100063, 105893, 100546, 102137, 94724, 93517, 120686, 94246, 72239, 126889, 94242, 10569, 29028, 126116, 115530, 126559, 86437, 95767, 54041, 122799, 123167, 47257, 110031, 114908, 122613, 17689, 28010, 129660, 100894, 100895, 128366, 119944, 85426, 38420, 92784, 122835, 125079, 93401, 93403, 94062, 94060, 86223, 94239, 93427, 93402, 5082, 94237, 94238, 93359, 93404, 93361, 76339, 16624, 78387, 92232, 78378, 93360, 78390, 78386, 79506, 91484, 1765, 93438, 93439, 93358, 123232, 94542, 43630, 124536, 44399, 43670, 43639, 2716, 128401, 123241, 123240, 30783, 93574, 47820, 84987, 116377, 45898, 43578, 44617, 44618, 43644, 36617, 43642, 53781, 126550, 114830, 57495, 45254, 44093, 45930, 43459, 44540, 48861, 136796, 45931, 45255, 124313, 25733, 123162, 37566, 44785, 129656, 44786, 44351, 41870, 41868, 41867, 41793, 41869, 41794, 41796, 43519, 43138, 27987, 25627, 43529, 43819, 43820, 43814, 43505, 43409, 43629, 43405, 124444, 43396, 43403, 5052, 44400, 43397, 43398, 43399, 43401, 122847, 122846, 43406, 42023, 45786, 44286, 42026, 42021, 45398, 45399, 44452, 44451, 45400, 40276, 42949, 48104, 105294, 85561, 45745, 43567, 43137, 42950, 101671, 45715, 43586, 45713, 44616, 45717, 44352, 45716, 44068, 44053, 45714, 42725, 42724, 39673, 44054, 44051, 39672, 39671, 40274, 45719, 42726, 42723, 39674, 39756, 45712, 44065, 39757, 42728, 101979, 68512, 40182, 42710, 40175, 40181, 40608, 44590, 40763, 39578, 40177, 40178, 126463, 129364, 93216, 95466, 90739, 78867, 93234, 129366, 129367, 129365, 85922, 29281, 29280, 22778, 93440, 90719, 87372, 92229, 87371, 94837, 92608, 90395, 81561, 81461, 100875, 43236, 42825, 42823, 45999, 128374, 40877, 123883, 40875, 4440, 3248, 40876, 40950, 41202, 40934, 19405, 42824, 41200, 69430, 61531, 40786, 41018, 40789, 44349, 41126, 44513, 40787, 124181, 41085, 40788, 40808, 44844, 78240, 81799, 28998, 41017, 44841, 41019, 84273, 41676, 44850, 41183, 40695, 48708, 64754, 41199, 42455, 85637, 47776, 88195, 25204, 41000, 158, 40638, 28292, 45162, 88151, 87051, 88241, 88489, 87897, 87394, 87395, 85636, 88153, 85307, 40905, 84339, 85406, 85332, 85261, 75047, 53517, 87668, 89751, 85329, 82665, 85281, 88302, 44443, 43485, 36388, 88446, 88141, 83641, 85897, 88451, 87699, 85898, 85894, 85895, 85896, 88450, 85900, 85890, 88294, 93455, 44480, 15136, 42365, 81353, 80247, 88139, 88134, 81351, 84084, 22776, 90653, 165, 87801, 84173, 87800, 87698, 87810, 87804, 87811, 26353, 32681, 72253, 88051, 62093, 85249, 31159, 87912, 85758, 78869, 77523, 58202, 89352, 55344, 38773, 38774, 81807, 90356, 130695, 18322, 38255, 124410, 14511, 90340, 13030, 12231, 38738, 124398, 90360, 35201, 38019, 130000, 29538, 38223, 7008, 38740, 6844, 5378, 34396, 3306, 122471, 99396, 99395, 3315, 3314, 14375, 36597, 99394, 75598, 38733, 112173, 117208, 117224, 56658, 117942, 37875, 38149, 38404, 35803, 38018, 38012, 36702, 36019, 20265, 33553, 38731, 38789, 38788, 37539, 116116, 115965, 119080, 19335, 33528, 33529, 99397, 74513, 109485, 4998, 46544, 109484, 6007, 107469, 1500, 1526, 1498, 109706, 1524, 64222, 61764, 28507, 1368, 110618, 99821, 10578, 99820, 30756, 31994, 75347, 107725, 96887, 67673, 119951, 120825, 90354, 121448, 49288, 35204, 25880, 65164, 27161, 27158, 78164, 52417, 27160, 27965, 27963, 25604, 27949, 27944, 61959, 69097, 69094, 1595, 61955, 75300, 74437, 38491, 67193, 36894, 36893, 47056, 68022, 68019, 68021, 68020, 68004, 72985, 25621, 72114, 68666, 28150, 28154, 27958, 25602, 27962, 27956, 26310, 23672, 36883, 69528, 66838, 29735, 27449, 64782, 26068, 65252, 71171, 26070, 24916, 65174, 25594, 65256, 35704, 26335, 25616, 72947, 25613, 65172, 65163, 70701, 28149, 28153, 69197, 15505, 2428, 71622, 25622, 26390, 26376, 26378, 67403, 27999, 28152, 28145, 66652, 25610, 25635, 33718, 25645, 27782, 26075, 63050, 32408, 110063, 37282, 62382, 97943, 65244, 65243, 91289, 30415, 45425, 56737, 28433, 25618, 25650, 25648, 25619, 25620, 73438, 65239, 18052, 65242, 115147, 32404, 75083, 98158, 65173, 91674, 121827, 121826, 15918, 27882, 1004, 59729, 65372, 65354, 25595, 27955, 24862, 53093, 55376, 56042, 69150, 69154, 71599, 26074, 27448, 26394, 67043, 65975, 41568, 66672, 61971, 67760, 69542, 66159, 76630, 67016, 64939, 30869, 28212, 65255, 3718, 129035, 129033, 59223, 123882, 127858, 118521, 121856, 121858, 114924, 117788, 93590, 101790, 68973, 127526, 129992, 53291, 131362, 128576, 128577, 129062, 123953, 123952, 123222, 123231, 123858, 41390, 41389, 53768, 4960, 123841, 117315, 121828, 73840, 124447, 121383, 95581, 114623, 32938, 122180, 51894, 120684, 42328, 31379, 41965, 119764, 123888, 123822, 109354, 109350, 120662, 106691, 106699, 106700, 42644, 41892, 41893, 115110, 91676, 121943, 114601, 114141, 114603, 121942, 114145, 114147, 114144, 114600, 81389, 114599, 114143, 32405, 121941, 114602, 91677, 88653, 74313, 116851, 116627, 108502, 32407, 88506, 116850, 116628, 75079, 119724, 116607, 116606, 116629, 108503, 90873, 85519, 85520, 123168, 119945, 114839, 107716, 103969, 114840, 121071, 81443, 108917, 115010, 74319, 73371, 102555, 117438, 117440, 123164, 124182, 41918, 41155, 40607, 114938, 114791, 127503, 121442, 112454, 127502, 122475, 124782, 127501, 44283, 67320, 77264, 79505, 75346, 24806, 100158, 100157, 91667, 18269, 38631, 87513, 118895, 99403, 34046, 32937, 99429, 901, 14589, 15322, 34059, 34047, 34049, 30501, 34045, 111077, 82821, 9392, 40077, 86751, 29396, 108165, 24164, 112183, 99811, 33699, 110606, 120674, 25283, 119170, 39457, 131246, 81746, 109247, 87332, 112455, 73804, 114941, 40006, 46095, 44184, 41271, 122330, 87340, 123165, 124538, 125203, 124173, 123161, 41910, 7118, 89803, 74558, 82851, 86749, 86759, 87753, 41913, 41914, 41909, 41912, 41907, 80249, 49242, 87341, 40020, 81458, 81460, 87339, 81459, 87336, 80402, 87338, 87337, 40021, 70444, 37643, 40025, 79068, 79069, 36547, 79070, 19272, 15469, 74075, 4268, 29101, 78151, 79071, 77482, 123884, 123872, 123871, 123870, 100364, 126474, 123826, 100059, 82853, 70450, 94225, 43199, 63016, 85811, 123820, 44872, 6303, 75345, 123966, 87373, 118472, 124088, 131410, 44875, 82888, 82846, 83315, 120395, 2955, 40093, 82844, 83316, 82887, 24929, 92990, 93104, 96111, 93857, 93108, 94233, 93663, 95822, 117858, 28038, 129692, 132000, 125691, 129713, 129726, 130232, 128087, 124446, 124224, 136037, 45095, 44995, 44983, 44928, 44894, 44892, 44891, 44886, 44885, 44883, 44878, 44879, 44877, 44876, 44893, 45525, 45526, 45524, 45518, 45101, 44864, 42562, 44851, 44863, 85292, 44861, 59356, 44862, 44868, 121449, 121238, 88491, 118036, 128111, 68714, 68244, 87062, 85658, 87049, 85659, 85654, 85657, 85661, 85640, 85653, 87052, 85655, 104726, 127998, 119068, 114942, 129115, 26079, 121889, 121888, 118006, 76135, 87054, 87907, 88149, 88503, 85510, 85515, 85513, 85509, 85512, 85516, 84074, 84073, 84072, 84075, 90293, 129114, 115282, 115013, 115014, 117752, 115528, 117751, 114424, 115539, 115012, 115011, 66845, 76871, 63870, 87757, 87582, 87568, 79390, 85347, 85368, 77498, 85369, 45263, 77052, 54854, 68729, 75814, 87670, 105588, 96674, 88557, 85893, 88192, 88550, 82340, 88456, 88445, 88498, 88140, 85892, 85045, 81352, 89042, 89037, 89035, 85656, 78630, 88135, 88137, 83834, 83909, 88411, 84470, 78466, 77051, 78482, 85400, 84504, 84437, 88136, 88263, 83983, 83984, 82845, 82843, 79066, 82852, 79065, 76023, 94595, 87678, 87417, 109788, 82676, 82677, 88054, 61019, 61020, 83883, 83890, 88187, 87602, 76549, 77055, 87565, 77041, 79381, 15275, 83056, 90165, 89354, 87782, 84812, 83057, 89604, 5565, 122097, 87807, 87808, 87761, 121955, 88049, 42178, 85277, 88050, 85293, 85280, 126964, 22902, 22890, 22889, 22888, 22887, 22893, 22892, 22886, 22879, 123815, 126962, 124178, 124734, 126963, 126961, 32777, 131397, 79100, 123861, 120035, 37541, 85180, 100896, 93588, 93580, 93585, 100055, 93577, 93589, 100874, 100056, 100049, 100438, 100460, 101501, 100872, 15435, 120318, 120451, 120321, 101541, 124070, 100892, 93583, 95931, 93586, 101505, 100873, 100054, 101594, 81323, 101512, 101511, 101510, 93587, 93579, 91811, 101517, 93578, 120453, 122303, 116368, 120320, 117240, 122305, 120454, 120495, 116517, 120446, 116519, 116520, 121185, 120450, 122304, 120449, 107942, 120319, 118137, 129657, 100876, 105440, 100877, 129664, 128367, 128373, 93597, 124760, 131500, 125238, 105293, 129663, 128372, 128368, 124756, 122179, 94387, 124111, 100910, 100925, 93855, 96716, 95807, 107799, 124409, 124415, 79787, 126567, 124112, 98561, 124720, 124759, 82401, 127742, 127740, 127741, 117854, 117852, 136096, 117186, 117094, 18275, 118332, 30757, 126484, 124539, 127743, 125562, 82400, 136097, 136098, 116644, 82402, 120125, 82403, 108856, 29849, 129837, 101301, 126549, 131385, 124314, 124332, 124359, 131381, 131383, 131382, 122867, 122888, 124689, 126383, 124732, 120369, 122084, 122753, 124211, 124729, 122215, 123036, 118217, 126200, 121696, 114527, 124724, 122083, 124177, 81674, 114621, 124735, 122887, 112448, 51525, 122082, 121293, 120779, 124731, 122754, 122752, 94282, 75850, 125461, 122080, 122755, 122881, 126613, 122085, 121297, 122098, 73342, 73343, 73338, 73341, 73302, 62128, 6894, 99197, 99196, 104841, 94541, 109614, 60700, 104842, 123204, 47231, 125148, 39809, 109621, 119931, 73152, 1503, 99401, 30284, 4885, 88841, 100164, 100162, 5548, 98599, 13049, 110164, 3283, 110174, 4887, 1495, 100173, 34160, 86439, 100169, 100186, 100177, 100171, 100163, 86440, 100180, 100175, 100161, 24992, 83604, 81304, 81303, 117497, 22891, 131499, 124067, 73699, 46936, 123224, 113854, 60711, 93415, 93411, 81533, 87971, 82867, 110141, 41667, 83233, 82897, 72181, 30462, 93416, 93412, 93409, 15813, 83230, 71286, 93413, 98008, 82899, 82928, 80978, 83234, 46929, 24877, 100179, 107472, 72186, 18889, 83231, 82875, 83221, 82895, 18890, 130406, 124054, 19732, 99398, 1659, 82925, 3313, 3308, 66717, 39501, 83229, 10131, 18054, 1525, 83113, 82932, 1501, 1499, 1357, 3289, 3284, 3282, 36792, 36791, 14493, 82919, 5549, 85210, 88674, 1544, 14500, 8632, 58003, 262, 19091, 36786, 36790, 33948, 80, 14472, 36814, 36816, 1427, 34070, 1438, 5552, 99615, 110176, 7992, 7991, 1447, 1446, 83232, 123170, 5444, 5545, 94544, 1443, 83236, 1433, 57224, 57222, 49365, 57781, 55368, 57221, 49366, 60002, 52012, 55365, 57223, 52743, 60001, 52020, 56038, 49367, 17461, 52372, 54388, 73635, 60004, 108569, 114766, 103500, 55913, 114732, 114727, 116435, 117439, 114726, 114715, 117141, 114702, 117579, 129623, 99424, 3295, 99425, 54756, 117444, 117580, 114730, 114724, 114706, 117581, 117447, 117445, 102554, 24994, 73284, 97003, 3298, 45436, 73262, 73156, 73607, 112459, 116631, 114711, 114696, 114695, 116634, 114088, 120415, 123166, 114716, 119550, 112388, 118892, 118575, 99433, 117687, 117831, 109512, 101442, 90336, 120504, 114714, 42735, 90317, 121938, 118543, 3010, 99422, 1489, 1432, 99423, 3445, 1502, 99417, 2181, 3444, 4482, 6191, 97468, 88530, 5073, 99421, 6190, 89267, 117446, 87578, 54859, 93520, 93516, 1491, 110154, 110153, 93617, 117443, 117436, 129356, 116130, 114092, 90337, 129835, 91659, 92190, 22480, 89785, 89771, 90209, 116640, 89930, 89932, 17241, 26067, 99430, 90201, 1494, 1480, 99420, 89933, 89772, 1484, 90206, 90207, 67053, 89931, 89786, 89777, 56857, 89885, 3292, 25777, 57090, 2968, 58785, 25375, 99416, 57081, 19803, 37874, 19619, 344, 59145, 5076, 58478, 257, 99415, 90197, 116639, 26069, 90208, 18930, 90104, 87530, 85628, 70075, 118438, 107795, 34450, 41408, 86764, 88881, 87803, 80264, 85771, 88490, 53107, 86472, 85767, 88827, 88492, 86471, 88837, 15663, 84069, 87805, 87806, 89353, 89355, 80893, 24052, 88690, 55345, 76222, 127480, 127479, 86638, 38801, 88493, 21876, 22490, 22492, 21875, 92055, 84502, 21873, 7358, 91660, 91713, 91584, 91705, 92257, 92280, 21855, 21877, 91707, 123205, 123206, 22630, 51672, 92218, 91723, 91709, 91655, 91725, 21874, 92224, 91661, 91758, 92228, 4728, 22162, 24860, 22628, 22631, 21870, 24757, 22487, 20546, 4366, 19017, 92423, 91772, 4515, 22498, 84023, 87367, 86550, 87366, 84818, 124452, 114526, 87365, 85641, 81516, 86027, 88264, 92725, 114713, 114158, 114712, 100869, 101262, 100888, 101154, 100880, 21838, 21857, 21866, 118894, 112447, 112453, 118223, 84817, 118533, 79405, 79403, 31330, 125907, 118893, 118902, 86549, 79404, 112456, 73613, 41446, 91710, 21872, 112412, 112449, 108857, 112446, 112457, 114536, 112411, 112414, 115254, 103831, 112410, 95944, 97860, 95964, 15660, 114618, 117193, 112413, 105213, 119969, 137416, 117477, 119696, 117475, 119705, 108830, 30782, 117458, 108832, 119694, 114968, 119704, 108831, 117519, 114686, 117970, 117476, 121443, 114532, 117459, 117694, 120990, 90303, 123217, 124408, 116913, 116911, 117456, 114756, 64918, 7186, 40689, 97001, 97004, 93033, 94572, 93680, 94571, 93681, 93032, 93682, 93814, 94570, 93815, 93683, 93813, 95707, 93034, 94573, 97002, 93035, 119000, 81302, 129921, 130322, 126420, 31174, 124413, 100455, 123163, 30759, 119937, 9346, 9234, 8799, 8822, 120306, 33312, 99017, 114495, 98461, 24993, 103501, 119954, 121940, 118828, 129620, 129621, 127993, 129622, 121165, 130077, 137102, 130078, 105301, 136033, 131308, 131307, 124535, 62127, 136036, 125272, 88583, 122247, 120917, 109622, 119989, 113757, 118700, 121141, 119788, 118214, 71887, 22791, 101478, 124534, 130280, 38697, 20016, 37595, 85203, 128369, 130314, 130303, 85204, 128504, 127563, 127558, 127562, 132005, 129624, 136672, 136675, 121697, 123880, 89421, 89419, 36572, 36571, 33534, 91016, 33676, 87141, 87143, 87142, 85200, 84083, 24980, 14369, 25070, 25069, 77210, 25074, 25073, 25075, 25076, 25054, 130332, 124754, 122503, 86444, 123878, 123220, 130468, 125629, 124755, 31773, 75702, 69224, 25182, 109889, 25047, 3146, 25081, 25055, 64965, 100571, 130298, 124109, 130301, 124721, 11566, 36279, 25036, 70774, 67494, 67614, 2179, 123801, 100248, 130316, 97765, 78050, 124051, 124066, 41363, 70790, 123494, 78053, 124401, 78948, 117862, 124062, 124406, 82261, 982, 122579, 129836, 122577, 122576, 101474, 130300, 125928, 130321, 99116, 124752, 86904, 77901, 45149, 90300, 130326, 126441, 126442, 126443, 126438, 126439, 126440, 66304, 64601, 79038, 129740, 130327, 126552, 123352, 126155, 130299, 130278, 101477, 130282, 130324, 123787, 124396, 82954, 82956, 30255, 82955, 130318, 130319, 123917, 100680, 84287, 94717, 130320, 126410, 84319, 88701, 88700, 79042, 130302, 130305, 124922, 70668, 44816, 80957, 78048, 123812, 16816, 84369, 86538, 124718, 128282, 128283, 130286, 46941, 21160, 123215, 82382, 45906, 26774, 45598, 123821, 130323, 24717, 99466, 84368, 123851, 4923, 4343, 6189, 52835, 60055, 76595, 81441, 123876, 130251, 124716, 100058, 83771, 84831, 83768, 79614, 81154, 123314, 98508, 84567, 83769, 64978, 43647, 70722, 122121, 27710, 130288, 42407, 40674, 36599, 120826, 120824, 70440, 51297, 42241, 42239, 80936, 52598, 66239, 88680, 88682, 88676, 88679, 88677, 88675, 88681, 122496, 36671, 116525, 79956, 130252, 24932, 81086, 78473, 68091, 52601, 52599, 68093, 119179, 88678, 21999, 92987, 95821, 93689, 100183, 94766, 93659, 93106, 95823, 65129, 65130, 95824, 96492, 53092, 525, 123794, 81373, 90315, 127454, 122505, 47848, 81665, 29756, 98505, 38552, 86531, 57480, 127188, 126152, 614, 25092, 118443, 30076, 119201, 85053, 105247, 119837, 117124, 14501, 84725, 8797, 45446, 81658, 109888, 126144, 90316, 118532, 125865, 125866, 125868, 120532, 82312, 125863, 125864, 121853, 125607, 126332, 125867, 128496, 83698, 122718, 69, 127330, 125757, 127327, 127530, 125747, 125764, 122717, 38419, 125641, 127324, 126907, 122715, 127321, 125335, 125655, 122714, 70442, 116853, 126331, 125646, 125336, 127389, 68387, 123986, 125811, 126333, 125659, 121285, 123983, 123984, 126906, 122721, 127348, 125735, 112279, 111723, 125780, 125582, 125726, 125581, 125745, 40840, 117184, 125590, 106518, 125647, 125858, 125767, 126718, 125771, 114302, 106698, 17067, 17069, 17076, 18261, 17068, 17187, 17079, 17550, 127448, 127352, 125608, 126042, 40841, 127449, 121296, 125743, 81964, 81966, 29669, 44819, 38484, 127303, 122996, 120822, 117442, 38745, 4476, 4479, 6853, 7161, 4477, 125753, 120819, 125756, 29633, 29667, 120474, 125741, 126735, 125912, 127190, 127477, 120818, 127337, 127333, 127334, 125644, 130245, 126154, 124047, 126153, 130259, 124717, 130287, 130257, 130249, 130247, 130244, 101328, 130258, 130248, 75591, 130260, 124719, 124730, 130250, 70448, 90302, 7179, 7176, 7177, 1060, 7170, 1403, 4489, 127302, 29632, 123046, 125666, 127476, 29630, 126009, 120823, 29666, 125673, 125667, 29631, 127370, 124010, 125651, 125427, 120701, 127516, 125665, 125569, 126782, 126783, 125650, 125805, 127485, 125424, 125640, 87043, 87047, 87039, 87040, 85788, 127371, 121703, 125429, 125579, 127362, 125425, 123344, 125428, 127369, 127484, 125412, 125663, 125653, 127483, 127482, 127487, 125434, 75344, 70451, 82001, 75343, 6710, 7181, 7178, 79800, 122595, 122594, 120057, 121532, 30760, 30500, 21828, 9349, 9290, 9236, 81083, 125594, 120694, 127181, 121712, 125258, 39458, 125643, 70445, 7174, 7187, 125405, 123456, 39466, 121295, 125136, 122824, 125652, 120518, 125664, 126768, 126767, 126766, 123451, 123459, 16259, 26759, 18720, 125779, 123448, 125793, 123359, 122832, 76889, 104835, 123326, 125332, 125770, 125338, 121085, 125400, 125774, 126062, 125772, 124459, 125766, 99435, 125769, 126125, 120528, 126007, 127189, 125712, 125759, 123060, 126170, 124274, 124277, 124278, 124275, 124276, 124184, 124460, 122856, 120514, 123829, 123879, 125862, 125591, 125229, 126171, 127274, 124273, 124210, 124186, 125777, 125380, 124463, 127896, 126487, 131473, 127837, 130206, 126444, 125401, 122719, 125775, 125286, 127054, 126314, 127659, 52746, 127084, 125737, 127063, 123809, 38418, 125276, 126012, 125287, 122457, 125834, 127660, 125809, 127658, 120527, 125280, 125257, 125611, 66341, 36700, 126044, 122833, 120526, 125853, 120522, 127185, 87594, 86136, 121382, 123202, 123208, 77696, 122589, 125319, 126784, 105422, 120829, 120828, 122517, 125404, 123569, 125403, 126006, 127309, 126724, 125578, 124187, 82795, 79900, 84086, 82568, 4488, 58380, 42855, 12945, 20995, 7184, 4481, 1546, 125568, 72245, 125575, 125593, 126999, 120796, 126978, 127009, 127366, 127020, 127014, 120720, 127030, 16198, 73194, 73195, 73197, 16540, 73198, 18039, 16958, 73162, 16517, 16496, 73466, 73357, 73358, 73355, 73356, 73348, 73354, 73324, 73325, 73359, 104651, 104653, 16441, 16537, 73417, 73811, 16397, 16536, 73337, 74237, 16553, 16544, 16454, 74335, 61850, 17121, 16497, 73420, 73465, 10698, 17053, 73344, 74238, 16166, 16554, 16546, 16048, 16548, 73458, 16165, 16417, 73470, 16399, 16531, 16535, 55144, 73454, 104620, 104652, 16515, 16495, 73418, 73472, 73468, 61125, 1954, 9074, 16052, 104656, 16545, 16455, 16460, 104614, 104649, 104654, 74235, 16550, 16437, 16398, 16530, 16525, 62387, 16457, 16458, 16516, 73419, 26404, 16459, 100576, 73336, 73313, 16557, 16558, 16407, 74236, 16456, 16461, 16465, 16464, 16467, 16551, 16543, 16549, 16466, 16408, 16440, 16524, 16556, 16555, 9756, 16050, 104615, 7893, 104655, 125794, 125592, 120723, 126663, 120792, 126981, 80846, 122515, 120722, 122460, 125812, 122725, 120789, 125316, 125656, 89308, 126990, 125721, 30257, 22903, 1925, 4717, 10754, 5146, 32791, 7168, 7105, 7172, 7180, 7163, 1282, 4491, 9284, 122459, 125437, 122458, 122509, 125438, 31757, 125814, 125320, 125269, 125449, 125268, 125264, 125255, 123802, 78241, 127379, 127325, 127329, 125521, 125827, 125232, 125266, 126317, 126008, 125606, 126316, 125323, 127661, 125511, 125748, 125520, 127364, 125262, 125798, 125263, 125725, 125813, 125256, 125259, 120185, 125261, 120711, 40692, 125267, 127375, 7167, 4490, 12938, 7162, 7165, 19071, 40690, 120744, 120743, 120745, 120299, 30761, 125576, 125315, 124032, 123924, 129937, 120712, 125510, 125454, 127662, 127178, 125649, 125671, 125609, 124019, 125402, 125512, 127284, 85935, 82890, 85617, 125662, 125420, 125795, 125657, 127301, 125587, 125828, 15200, 15236, 15235, 108267, 117680, 117679, 120746, 117775, 121454, 117692, 117681, 120661, 120827, 7183, 4478, 30781, 125840, 125807, 126732, 125765, 125346, 127372, 125837, 125819, 125762, 124203, 32178, 84547, 125760, 125397, 125808, 108881, 117776, 117777, 7160, 67486, 19073, 765, 81928, 32177, 85725, 7993, 7337, 7190, 1667, 1928, 7429, 79557, 62722, 10771, 10826, 108811, 1960, 35844, 28048, 23521, 27700, 35843, 36956, 79211, 118168, 90257, 73486, 73482, 73484, 123951, 2327, 247, 23515, 207, 2328, 79560, 79559, 78046, 79074, 78861, 85560, 78049, 81079, 78047, 85562, 85476, 85475, 77955, 39810, 85518, 85446, 85584, 78947, 85568, 85522, 78950, 78949, 85517, 85521, 79076, 80962, 78052, 79871, 79039, 118441, 118437, 117746, 99915, 104534, 65644, 86734, 27510, 107802, 123834, 86735, 86737, 86736, 36944, 101978, 92726, 79406, 118518, 30256, 36952, 36957, 16946, 79058, 123855, 123877, 86574, 85649, 124537, 82019, 9492, 14574, 66025, 66026, 86066, 40089, 86120, 85588, 84548, 58023, 82891, 86122, 84545, 85729, 85716, 60855, 45865, 64016, 86119, 56590, 81269, 84546, 85589, 85733, 14573, 86121, 44634, 40024, 123808, 33065, 34885, 93451, 79801, 80983, 130377, 44604, 78215, 78193, 82537, 79952, 78999, 79001, 78210, 78212, 78468, 238, 76857, 77040, 79496, 78993, 117778, 117682, 123835, 123854, 82541, 78469, 78467, 82579, 78990, 82960, 128247, 130488, 123211, 123891, 123892, 123893, 17188, 82936, 75339, 78216, 78214, 78211, 78965, 76548, 82796, 85213, 77043, 77046, 88481, 82797, 81742, 84085, 80744, 80745, 82957, 82798, 64814, 47166, 81748, 128246, 78844, 78845, 91169, 124094, 124425, 82612, 78994, 82544, 88616, 77053, 79382, 78964, 26741, 137413, 124294, 46131, 124462, 81743, 80845, 81747, 117990, 121042, 121044, 120658, 93594, 82540, 45490, 78967, 76552, 78835, 87959, 42408, 78962, 45491, 87960, 58717, 93453, 88321, 124399, 124394, 121936, 73691, 17641, 73612, 17645, 73483, 68767, 65834, 17123, 67195, 13950, 13953, 13951, 103803, 73802, 13949, 12431, 4449, 68766, 5047, 12430, 67516, 73485, 73487, 68765, 64480, 13952, 65688, 66854, 102298, 94692, 95386, 58656, 95384, 95959, 95961, 95962, 95943, 95957, 97865, 95963, 120648, 122495, 120635, 120633, 130304, 125631, 120654, 120649, 120646, 117800, 120651, 120681, 120650, 120647, 120653, 122231, 39726, 81957, 76870, 76880, 237, 88594, 88191, 88283, 85044, 93454, 88495, 88279, 92705, 87771, 88839, 83858, 88890, 81418, 121969, 90164, 87588, 83854, 122494, 120543, 117797, 120742, 121939, 124255, 229, 76855, 81953, 35244, 87689, 87924, 88073, 79064, 88185, 81207, 87817, 78992, 85214, 88079, 88044, 87928, 87925, 79067, 87891, 87687, 78806, 87686, 87909, 87910, 124453, 99810, 26749, 110583, 117711, 100574, 89367, 83830, 83526, 81245, 87944, 83831, 89085, 87816, 83832, 89086, 83833, 77188, 70446, 70449, 76856, 75328, 85246, 86849, 78471, 78478, 21936, 87688, 87684, 87926, 88081, 78475, 81802, 88074, 88075, 88070, 88043, 38626, 80177, 80751, 78963, 75340, 87685, 88080, 88072, 76550, 81372, 124081, 124412, 124426, 127310, 22873, 22746, 22745, 22743, 22740, 22739, 100247, 118749, 81204, 90770, 46458, 77184, 85339, 85906, 88200, 88190, 75699, 81084, 75372, 75701, 42744, 15880, 77489, 83889, 84284, 75377, 29414, 83862, 88621, 83892, 83985, 83982, 84529, 84262, 83893, 86639, 79313, 78632, 124422, 34184, 33700, 22750, 30413, 122746, 12229, 26375, 33698, 4368, 110614, 34185, 81476, 33701, 64307, 22744, 31760, 37020, 37437, 38047, 86168, 78223, 60256, 80180, 79015, 85797, 79014, 88548, 17701, 60051, 17721, 17700, 17699, 47165, 17719, 17722, 110183, 110191, 5705, 25052, 17720, 5905, 42389, 15471, 1311, 20923, 82693, 87613, 87614, 116854, 81291, 88547, 84091, 86443, 46710, 88610, 82814, 84584, 76907, 32778, 82950, 64329, 84415, 119745, 24058, 121937, 120730, 120729, 120689, 120683, 120685, 120645, 120636, 129647, 129646, 129648, 120687, 89802, 88825, 87050, 84092, 80857, 84412, 86950, 5233, 82764, 82779, 127287, 39353, 121985, 81145, 87370, 63732, 63733, 75365, 87422, 86641, 25039, 25050, 117781, 117780, 76072, 124533, 124108, 63731, 71979, 99507, 24043, 80521, 123212, 47243, 78593, 86198, 87507, 63276, 88687, 64374, 86219, 39637, 67624, 87566, 85790, 70261, 73854, 72013, 84915, 88689, 89342, 81128, 72015, 54893, 86073, 64074, 86202, 63719, 80266, 88522, 86079, 75374, 67155, 80522, 76532, 81651, 81482, 73116, 61527, 82578, 85799, 86203, 39109, 42409, 81649, 81650, 75378, 75730, 81652, 80258, 86204, 83521, 78480, 85228, 83093, 76890, 82995, 82539, 78631, 82538, 83812, 90788, 90661, 10186, 125802, 27681, 87647, 65, 85635, 7106, 7102, 7212, 11353, 7104, 8847, 12812, 1929, 797, 32814, 7103, 121241, 120835, 120837, 120836, 121246, 88201, 28047, 81166, 38615, 31848, 41326, 49781, 16795, 108879, 79707, 125309, 126785, 114303, 82770, 83183, 35760, 87796, 78483, 123203, 123209, 125817, 125815, 117801, 53316, 121860, 123221, 121664, 55644, 13069, 42449, 53719, 131474, 123859, 124124, 124125, 123874, 123833, 124254, 126804, 82026, 82025, 83532, 84110, 85962, 33519, 88609, 77851, 76515, 81188, 81160, 78633, 77936, 77039, 88528, 77691, 78928, 82024, 52723, 83533, 82988, 87648, 87183, 87788, 87769, 87791, 86640, 74793, 76422, 81168, 87628, 87630, 77940, 41325, 87581, 79059, 39631, 80752, 88605, 77532, 87781, 77698, 88613, 33719, 87549, 77466, 87794, 87786, 80858, 81363, 84263, 93865, 88604, 87792, 61206, 86025, 81194, 87790, 87780, 88608, 88606, 77054, 87631, 87649, 90161, 87611, 87612, 87601, 80754, 86763, 88152, 84554, 84544, 93838, 80767, 87599, 87376, 88614, 77496, 85642, 87793, 87795, 88482, 87713, 87053, 86028, 87583, 87584, 80753, 82545, 81345, 85963, 79969, 80178, 87634, 84555, 84557, 84551, 87797, 84583, 84577, 84559, 88615, 88317, 87600, 87375, 88271, 88265, 85967, 61205, 83531, 88611, 88612, 85964, 88502, 88607, 82148, 81366, 78472, 79970, 76547, 88318, 82315, 81321, 82813, 88262, 1939, 85664, 32646, 981, 82550, 121830, 86546, 65233, 122498, 122497, 125630, 124338, 21841, 21867, 21840, 21869, 91753, 120832, 118340, 81397, 16356, 16358, 79477, 79951, 77902, 342, 32546, 80619, 16357, 91518, 120603, 120608, 119739, 120480, 117785, 72183, 120604, 114923, 117685, 120605, 119740, 118482, 117486, 123521, 124202, 118169, 129792, 121384, 124205, 119092, 100675, 123806, 123799, 104840, 124437, 124339, 111078, 90301, 107471, 4602, 136045, 127696, 120675, 9289, 8684, 8815, 8776, 8813, 8826, 8801, 8777, 9233, 8805, 8681, 14666, 21826, 25212, 25210, 25209, 8772, 9288, 8823, 8332, 8330, 8350, 8821, 21827, 8773, 8803, 8675, 9212, 8896, 8820, 9069, 8828, 8654, 2834, 8652, 8683, 8667, 8674, 9049, 9051, 11553, 8679, 9071, 9235, 8804, 8796, 8682, 8673, 21829, 8752, 8270, 8181, 8897, 9072, 9347, 8774, 8179, 8178, 8177, 8800, 8755, 8751, 8794, 5488, 8814, 8759, 1204, 12162, 8750, 9019, 9089, 8756, 5781, 8762, 8895, 1070, 8795, 8704, 8329, 8753, 8718, 8757, 8894, 2172, 8289, 8798, 8812, 8806, 9070, 8180, 8793, 8678, 8680, 8676, 32172, 124764, 124436, 123207, 119979, 108456, 38211, 108777, 38212, 106457, 136048, 136823, 136824, 136794, 102126, 124432, 116544, 124183, 26064, 328, 114185, 117678, 120749, 120741, 120740, 120747, 107950, 124605, 116140, 117912);
UPDATE `creature_model_info` SET `VerifiedBuild`=63305 WHERE `DisplayID` IN (117779, 123216, 74899, 117277, 117271, 117270, 128500, 32170, 49835, 129933, 123804, 123795, 121986, 109539, 27849, 119065, 119046, 118377, 36833, 120334, 126300, 30764, 121177, 120679, 121983, 121991, 137415, 121988, 121987, 120748, 114926, 120738, 131875, 90249, 92621, 122177, 101300, 124290, 124411, 97643, 124091, 124454, 123927, 119100, 117276, 119091, 120736, 120735, 120737, 36880, 36882, 36881, 136038, 124407, 101570, 122176, 128503, 63716, 38213, 119123, 118523, 704, 123213, 124292, 92168, 124400, 118448, 90313, 10015, 28647, 90256, 113934, 109886, 82773, 90320, 84775, 84776, 84774, 80060, 123925, 126845, 56304, 104198, 119212, 120678, 120680, 119675, 116523, 124300, 129936, 122488, 90254, 125824, 77501, 120831, 123218, 90314, 123825, 111084, 11746, 11747, 119222, 30358, 117733, 119090, 117732, 124554, 117740, 114752, 117739, 117753, 114753, 117738, 114751, 117729, 117731, 114749, 117737, 117736, 117728, 117741, 117726, 117743, 117742, 117730, 125389, 117422, 137414, 109964, 123219, 35312, 119220, 120902, 113853, 120341, 120901, 124473, 122178, 44336, 125806, 129627, 123796, 61892, 57027, 120676, 121379, 120659, 111097, 118989, 120338, 120903, 121935, 72447, 19893, 119468, 82884, 119936, 123210, 124397, 120754, 114932, 121103, 77061, 6295, 79774, 82576, 77058, 87700, 81234, 79773, 85352, 79771, 82577, 119217, 120337, 119221, 125924, 120643, 122491, 120751, 123790, 123805, 120668, 78195, 115285, 40658, 40657, 61024, 61023, 3606, 7137, 30784, 121970, 30763, 107853, 65463, 117799, 125823, 120757, 121968, 127838, 121981, 121982, 117642, 121468, 125237, 42373, 121467, 99448, 32703, 31596, 37338, 95557, 119101, 116167, 38800, 87778, 82973, 123214, 38551, 32171, 14492, 119047, 125804, 107363, 24995, 32173, 46130, 125803, 24778, 64802, 83664, 84418, 57772, 40075, 66292, 81417, 85192, 36499, 38380, 83292, 10699, 7763, 121971, 120802, 121973, 121979, 193, 116524, 4356, 116378, 114794, 100362, 120540, 78479, 82234, 82543, 104043, 115264, 115258, 117481, 134, 4626, 120756, 100573, 136040, 77262, 120900, 128505, 42941, 121989, 121992, 121990, 99418, 1473, 1472, 22769, 104836, 1694, 33303, 37850, 121088, 121974, 19670, 122120, 108805, 119099, 9990, 122490, 125825, 117418, 120335, 124531, 119057, 78196, 112186, 118384, 118411, 118415, 117653, 101036, 120732, 120957, 117423, 118385, 120952, 117659, 30409, 121104, 121972, 5555, 120333, 100444, 14414, 14413, 51613, 1320, 9133, 29569, 106964, 83224, 37647, 35695, 8848, 16850, 4382, 1319, 49770, 42385, 82765, 106967, 37724, 34144, 34141, 37138, 34136, 1358, 24981, 92900, 35140, 35133, 8000, 34143, 34139, 1310, 1318, 99462, 73093, 79383, 25871, 21264, 35052, 36615, 35148, 36559, 31737, 109709, 99385, 40012, 8001, 110794, 3609, 3608, 3605, 3604, 82746, 82781, 110760, 116250, 82930, 3128, 89420, 106345, 35141, 35053, 1323, 1312, 14370, 89418, 22493, 7117, 1392, 35051, 34406, 4514, 110514, 26770, 82115, 1314, 34412, 43668, 5706, 84124, 40693, 42372, 123434, 83605, 83621, 83597, 112490, 83620, 118549, 83594, 83598, 104633, 83593, 83613, 116384, 112458, 118557, 84036, 120339, 16587, 118461, 120331, 118450, 112632, 73697, 118552, 5205, 82769, 104187, 31738, 109887, 90246, 16235, 10732, 20988, 86333, 25436, 20985, 86332, 90129, 110620, 75972, 90242, 89937, 35504, 90245, 4601, 90243, 90130, 4259, 90133, 35498, 92464, 90244, 16238, 90366, 83765, 92463, 99452, 37023, 75973, 83764, 89935, 1313, 118596, 70992, 25423, 70623, 104515, 114831, 104517, 114561, 104518, 114833, 104516, 114829, 45880, 54643, 104521, 104523, 118073, 117198, 108862, 88424, 119125, 118353, 119062, 84065, 117357, 37310, 91755, 91719, 21879, 21839, 21868, 21854, 21880, 21881, 88619, 46940, 36583, 21878, 1986, 2732, 118445, 118446, 37154, 120951, 120948, 119975, 120733, 125394, 105394, 102553, 2216, 23761, 23760, 23765, 109867, 23763, 12033, 107697, 108114, 90757, 23780, 24028, 23757, 120811, 23762, 24019, 23759, 23659, 24031, 17200, 73139, 73140, 73143, 45881, 118464, 43666, 108812, 122122, 117658, 119978, 117430, 125822, 119058, 122489, 117347, 117427, 120629, 119045, 124431, 120611, 118451, 119048, 72085, 121381, 129695, 122123, 65251, 47677, 120641, 42721, 10992, 120920, 119193, 119124, 118457, 108870, 119218, 45304, 122493, 119098, 119060, 119102, 119052, 121976, 121977, 117416, 117411, 46034, 115036, 119016, 118460, 117419, 120615, 119305, 119122, 121105, 117660, 117654, 72948, 91167, 78839, 91178, 28830, 90874, 91951, 68290, 91176, 91123, 90865, 91631, 121157, 119051, 118267, 117412, 125826, 120639, 122492, 120625, 120640, 118458, 108869, 108810, 120610, 42350, 119215, 120727, 117657, 118181, 120628, 125395, 117420, 111667, 117656, 115038, 108867, 111138, 117756, 30272, 110987, 94494, 2141, 13341, 33191, 31988, 15468, 36585, 34108, 34340, 32936, 110607, 15467, 63690, 35538, 35545, 35544, 9391, 34107, 99451, 33194, 63703, 8971, 105169, 102033, 7511, 99426, 37328, 37331, 99453, 36598, 21072, 100150, 37330, 117487, 114656, 114304, 104045, 114562, 115263, 107365, 117491, 115238, 117223, 107366, 114653, 117494, 115262, 103812, 117484, 114563, 118222, 79043, 79041, 118648, 123792, 103813, 123793, 122461, 124737, 118463, 120541, 120750, 121049, 120671, 120753, 105161, 120752, 114814, 117127, 118887, 121980, 126344, 117794, 120670, 120755, 128770, 120830, 121734, 123940, 123939, 118452, 120669, 120672, 118650, 120673, 108813, 120726, 120725, 117676, 117675, 117424, 117360, 120621, 112141, 118429, 126362, 117671, 117666, 118447, 117415, 120609, 120622, 120336, 125913, 59303, 43328, 112165, 125801, 117355, 117353, 110229, 114796, 120613, 19283, 120618, 106349, 122117, 118459, 121154, 121155, 116218, 52318, 125391, 117655, 121169, 119059, 125318, 120949, 43667, 120617, 117673, 117667, 119216, 120620, 119120, 121153, 121156, 119103, 117426, 84789, 65631, 124337, 22452, 136044, 75589, 124429, 124395, 124434, 124405, 125880, 26103, 25596, 28317, 62155, 62151, 52602, 70201, 124302, 124404, 84637, 84713, 84714, 84715, 100727, 88525, 84716, 119061, 115035, 117338, 128002, 121951, 118269, 117348, 120953, 120954, 120637, 131516, 126177, 120627, 115037, 120384, 34556, 33479, 117689, 108868, 85555, 129142, 124793, 120630, 118268, 117413, 120619, 121108, 112806, 120981, 120332, 110227, 108778, 117806, 120642, 117421, 121106, 121975, 117425, 122301, 119976, 117417, 120914, 121052, 110362, 119656, 120614, 120623, 117757, 121978, 117200, 117695, 117428, 117696, 121148, 118386, 110225, 108808, 118182, 120612, 117343, 120644, 117238, 120739, 28282, 28111, 121107, 119121, 117346, 120340, 120616, 122119, 117697, 43965, 55878, 120606, 118597, 117199, 118319, 117431, 121065, 120626, 120624, 119977, 111028, 117690, 118376, 88423, 119049, 117410, 117414, 104042, 120607, 119663, 117409, 117201, 121053, 117408, 111139, 107560, 88792, 115505, 74845, 83302, 84796, 81779, 79040, 12191, 83303, 80996, 51409, 83304, 84416, 60766, 74072, 84638, 84337, 84679, 83273, 83301, 88636, 117337, 27961, 79000, 25598, 128019, 115426, 116642, 116637, 113936, 90736, 116641, 83789, 136039, 101299, 100575, 131544, 126557, 131546, 97761, 100060, 99883, 75597, 128506, 131545, 116325, 115125, 34157, 34155, 119050, 118072, 85924, 124299, 117349, 39555, 72104, 5080, 1756, 110111, 110173, 110242, 110231, 27261, 15921, 109492, 99186, 1486, 99379, 72724, 119672, 129384, 3167, 106965, 221, 338, 99193, 1477, 99383, 99496, 5446, 5081, 86636, 105546, 129382, 38804, 21342, 106966, 36656, 37311, 3302, 99506, 99381, 99391, 10591, 99389, 104846, 99185, 110234, 3285, 99187, 83235, 32928, 129628, 124540, 131656, 130297, 97642, 98507, 129747, 129749, 129748, 98509, 87871, 74904, 120317, 116815, 120588, 117344, 114918, 125439, 32790, 53782, 104519, 114832, 125513, 117725, 125852, 125570, 121772, 70903, 125516, 125514, 125525, 125523, 114104, 16925, 124363, 125574, 125573, 125524, 114920, 115109, 32789, 104522, 124288, 125567, 115111, 114102, 104520, 114107, 125515, 125577, 115112, 114110, 125435, 125436, 114113, 114912, 125522, 114919, 114117, 114921, 27486, 60926, 60927, 109774, 26413, 72956, 63051, 25611, 70532, 117356, 34156, 34154, 69682, 60924, 65345, 28146, 28163, 35280, 64586, 26339, 72235, 120516, 127296, 125818, 127288, 127374, 125625, 127297, 125396, 126005, 125797, 127283, 127282, 125321, 93505, 14554, 78509, 119214, 119213, 4260, 128325, 129994, 127984, 128498, 131618, 131817, 131999, 129107, 107538, 25801, 26904, 2177, 27200, 25799, 25800, 26650, 62385, 128502, 127290, 120521, 127291, 120515, 126002, 126045, 127294, 127295, 127289, 125799, 127292, 125411, 122364, 122365, 125345, 127285, 125796, 125758, 127298, 127299, 127286, 120520, 126004, 125816, 120523, 125308, 119497, 125324, 123059, 125820, 126000, 127293, 122724, 120075, 125800, 104021, 37329, 36584, 1987, 65228, 65714, 61986, 23337, 65453, 69790, 70638, 69780, 3585, 16910, 77656, 2954, 27657, 74200, 74199, 74194, 74087, 65450, 71088, 71017, 71019, 68480, 73730, 56704, 65477, 15180, 65424, 65413, 65370, 65357, 27720, 65101, 6302, 27881, 1072, 27680, 5448, 5586, 5585, 28147, 28156, 28143, 28161, 28144, 28148, 25674, 25882, 27952, 25673, 27287, 27954, 25605, 46697, 46696, 48000, 46694, 27960, 28162, 28160, 28155, 28159, 25955, 25983, 27915, 26307, 26299, 25875, 22003, 27616, 27959, 27019, 25807, 26440, 26441, 25806, 25947, 26396, 26395, 26437, 26347, 65106, 28158, 36906, 34635, 32991, 33542, 35818, 36907, 36905, 36904, 17170, 26442, 26300, 25607, 25791, 74532, 20833, 5554, 47999, 70773, 60156, 29056, 72078, 72074, 72103, 42872, 71943, 71942, 43497, 64759, 65257, 27592, 46925, 78398, 71596, 5556, 71597, 26071, 75912, 69575, 52659, 26330, 72945, 1669, 5777, 68483, 68484, 27822, 63038, 913, 58842, 64049, 64048, 72465, 65232, 75302, 75301, 45437, 48278, 47997, 75130, 72344, 3714, 26072, 6296, 69627, 26073, 28157, 65227, 25041, 69926, 67808, 104597, 129618, 73709, 110138, 110187, 115277, 28118, 28120, 77687, 77690, 121139, 121140, 117339, 77404, 1560, 1959, 1206, 3027, 5561, 171, 78766, 117429, 120956, 122774, 122773, 63419, 48520, 47618, 73838, 18718, 56765, 73839, 16241, 62384, 19097, 73492, 48519, 74223, 73837, 48521, 117649, 127663, 117345, 117786, 94881, 95173, 117342, 126363, 118440, 126359, 126357, 126360, 126427, 108160, 107803, 126571, 117651, 119074, 118449, 117336, 116265, 119703, 104040, 128242, 128241, 128244, 128243, 116266, 116263, 117359, 4959, 94231, 117650, 117352, 120638, 118439, 121380, 114500, 117358, 117354, 116915, 120016, 117341, 117351, 118462, 117350, 106697, 104041, 117652, 118195, 126358, 94232, 114929, 124072, 124052, 27823, 124071, 124074, 125205, 130285, 128017, 127967, 128495, 124059, 130384, 124073, 130253, 130289, 136042, 130383, 128020, 130284, 128018, 128021, 130381, 124430, 98506, 129439, 123535, 90740, 31985, 125923, 77402, 119366, 119367, 119368, 119365, 127715, 77403, 121288, 81442, 120682, 127716, 99475, 118750, 80182, 87030, 78481, 82546, 87756, 81640, 79280, 60446, 87017, 75330, 5369, 2176, 75329, 87596, 304);
UPDATE `creature_model_info` SET `BoundingRadius`=0.340000003576278686, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID`=33656;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID`=24111;
UPDATE `creature_model_info` SET `BoundingRadius`=0.660452723503112792, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=37168;
UPDATE `creature_model_info` SET `BoundingRadius`=0.386561989784240722, `CombatReach`=0.75, `VerifiedBuild`=63305 WHERE `DisplayID`=64799;
UPDATE `creature_model_info` SET `BoundingRadius`=1.146589040756225585, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=69835;
UPDATE `creature_model_info` SET `BoundingRadius`=0.267503082752227783, `VerifiedBuild`=63305 WHERE `DisplayID`=101025;
UPDATE `creature_model_info` SET `BoundingRadius`=1.21804666519165039, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID`=95749;
UPDATE `creature_model_info` SET `BoundingRadius`=0.629890918731689453, `CombatReach`=1.499999880790710449, `VerifiedBuild`=63305 WHERE `DisplayID`=2711;
UPDATE `creature_model_info` SET `BoundingRadius`=0.346528172492980957, `VerifiedBuild`=63305 WHERE `DisplayID`=86806;
UPDATE `creature_model_info` SET `BoundingRadius`=0.588740706443786621, `VerifiedBuild`=63305 WHERE `DisplayID`=68901;
UPDATE `creature_model_info` SET `BoundingRadius`=2.644444465637207031, `CombatReach`=2.799999952316284179, `VerifiedBuild`=63305 WHERE `DisplayID`=101581;
UPDATE `creature_model_info` SET `BoundingRadius`=0.37800803780555725, `CombatReach`=1.399999976158142089, `VerifiedBuild`=63305 WHERE `DisplayID`=101583;
UPDATE `creature_model_info` SET `BoundingRadius`=0.334566444158554077, `CombatReach`=1.399999976158142089, `VerifiedBuild`=63305 WHERE `DisplayID`=101582;
UPDATE `creature_model_info` SET `BoundingRadius`=1.888888955116271972, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID` IN (101566, 101271, 102052, 100737);
UPDATE `creature_model_info` SET `BoundingRadius`=2.068859815597534179, `CombatReach`=2.624999761581420898, `VerifiedBuild`=63305 WHERE `DisplayID`=101576;
UPDATE `creature_model_info` SET `BoundingRadius`=0.810143113136291503, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID`=95375;
UPDATE `creature_model_info` SET `BoundingRadius`=2.266666889190673828, `CombatReach`=2.40000009536743164, `VerifiedBuild`=63305 WHERE `DisplayID`=102057;
UPDATE `creature_model_info` SET `BoundingRadius`=0.213175013661384582, `VerifiedBuild`=63305 WHERE `DisplayID`=101746;
UPDATE `creature_model_info` SET `BoundingRadius`=0.282392948865890502, `VerifiedBuild`=63305 WHERE `DisplayID`=101021;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID` IN (100076, 102085);
UPDATE `creature_model_info` SET `BoundingRadius`=2.910524368286132812, `VerifiedBuild`=63305 WHERE `DisplayID`=88119;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID`=100728;
UPDATE `creature_model_info` SET `CombatReach`=6.75, `VerifiedBuild`=63305 WHERE `DisplayID`=118996;
UPDATE `creature_model_info` SET `BoundingRadius`=0.927166938781738281, `CombatReach`=0.60000002384185791, `VerifiedBuild`=63305 WHERE `DisplayID`=99864;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID` IN (55067, 43527, 43528, 43539, 43526);
UPDATE `creature_model_info` SET `BoundingRadius`=1.177400112152099609, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=93756;
UPDATE `creature_model_info` SET `BoundingRadius`=0.629890918731689453, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID`=96898;
UPDATE `creature_model_info` SET `BoundingRadius`=0.45667356252670288, `CombatReach`=0.5, `VerifiedBuild`=63305 WHERE `DisplayID`=58825;
UPDATE `creature_model_info` SET `BoundingRadius`=1.146589279174804687, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=66790;
UPDATE `creature_model_info` SET `BoundingRadius`=0.442157119512557983, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID`=101153;
UPDATE `creature_model_info` SET `BoundingRadius`=0.400000005960464477, `CombatReach`=0.755999982357025146, `VerifiedBuild`=63305 WHERE `DisplayID`=90745;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID` IN (117860, 117884, 117885, 118339);
UPDATE `creature_model_info` SET `BoundingRadius`=0.329317212104797363, `CombatReach`=0.60000002384185791, `VerifiedBuild`=63305 WHERE `DisplayID`=8869;
UPDATE `creature_model_info` SET `BoundingRadius`=2.777777910232543945, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=99097;
UPDATE `creature_model_info` SET `BoundingRadius`=1.888889193534851074, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID`=101670;
UPDATE `creature_model_info` SET `BoundingRadius`=1.888888835906982421, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID`=101669;
UPDATE `creature_model_info` SET `CombatReach`=2.625, `VerifiedBuild`=63305 WHERE `DisplayID`=101668;
UPDATE `creature_model_info` SET `BoundingRadius`=0.99199610948562622, `VerifiedBuild`=63305 WHERE `DisplayID`=94752;
UPDATE `creature_model_info` SET `BoundingRadius`=1.146590232849121093, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=66794;
UPDATE `creature_model_info` SET `BoundingRadius`=0.95922398567199707, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=99386;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID` IN (112722, 43161, 44128, 43269, 44129, 44130);
UPDATE `creature_model_info` SET `BoundingRadius`=0.405739665031433105, `CombatReach`=0.699999988079071044, `VerifiedBuild`=63305 WHERE `DisplayID`=118863;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698715090751647949, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID` IN (101458, 101457);
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID` IN (101383, 84517, 84417);
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID` IN (101464, 87923, 87852, 28516);
UPDATE `creature_model_info` SET `BoundingRadius`=0.14490702748298645, `CombatReach`=0.25, `VerifiedBuild`=63305 WHERE `DisplayID`=116279;
UPDATE `creature_model_info` SET `BoundingRadius`=3.125, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=93072;
UPDATE `creature_model_info` SET `BoundingRadius`=1.954756975173950195, `CombatReach`=1.27500009536743164, `VerifiedBuild`=63305 WHERE `DisplayID` IN (90738, 90733);
UPDATE `creature_model_info` SET `BoundingRadius`=0.898650646209716796, `CombatReach`=0.82500004768371582, `VerifiedBuild`=63305 WHERE `DisplayID`=114512;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID` IN (91662, 87906, 87855, 85633, 85634);
UPDATE `creature_model_info` SET `BoundingRadius`=0.372827142477035522, `CombatReach`=0.300000011920928955, `VerifiedBuild`=63305 WHERE `DisplayID`=117450;
UPDATE `creature_model_info` SET `BoundingRadius`=8.751654624938964843, `VerifiedBuild`=63305 WHERE `DisplayID`=96853;
UPDATE `creature_model_info` SET `BoundingRadius`=1.049999952316284179, `CombatReach`=1.75, `VerifiedBuild`=63305 WHERE `DisplayID`=114624;
UPDATE `creature_model_info` SET `BoundingRadius`=0.150000005960464477, `VerifiedBuild`=63305 WHERE `DisplayID` IN (96323, 43223);
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=40886;
UPDATE `creature_model_info` SET `BoundingRadius`=7.021739482879638671, `CombatReach`=7, `VerifiedBuild`=63305 WHERE `DisplayID`=42730;
UPDATE `creature_model_info` SET `BoundingRadius`=5.702445030212402343, `CombatReach`=8.75, `VerifiedBuild`=63305 WHERE `DisplayID`=44140;
UPDATE `creature_model_info` SET `BoundingRadius`=2.5, `CombatReach`=2.5, `VerifiedBuild`=63305 WHERE `DisplayID` IN (43158, 43552, 43521, 43520, 43262, 43265, 43676);
UPDATE `creature_model_info` SET `BoundingRadius`=4.5, `CombatReach`=4.5, `VerifiedBuild`=63305 WHERE `DisplayID` IN (43554, 43141, 42645);
UPDATE `creature_model_info` SET `BoundingRadius`=0.917214155197143554, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID`=100495;
UPDATE `creature_model_info` SET `BoundingRadius`=3.5, `CombatReach`=7, `VerifiedBuild`=63305 WHERE `DisplayID`=43126;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465000003576278686, `CombatReach`=4.5, `VerifiedBuild`=63305 WHERE `DisplayID`=44982;
UPDATE `creature_model_info` SET `BoundingRadius`=1.10000002384185791, `CombatReach`=9.625, `VerifiedBuild`=63305 WHERE `DisplayID`=43456;
UPDATE `creature_model_info` SET `BoundingRadius`=3.815388917922973632, `CombatReach`=3.299999952316284179, `VerifiedBuild`=63305 WHERE `DisplayID`=93829;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID` IN (42640, 43263, 43261, 44150, 44149, 43267);
UPDATE `creature_model_info` SET `BoundingRadius`=5, `CombatReach`=5, `VerifiedBuild`=63305 WHERE `DisplayID`=43674;
UPDATE `creature_model_info` SET `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID` IN (64854, 83595);
UPDATE `creature_model_info` SET `BoundingRadius`=8, `CombatReach`=24, `VerifiedBuild`=63305 WHERE `DisplayID`=45084;
UPDATE `creature_model_info` SET `BoundingRadius`=15, `CombatReach`=12, `VerifiedBuild`=63305 WHERE `DisplayID`=46007;
UPDATE `creature_model_info` SET `BoundingRadius`=10, `VerifiedBuild`=63305 WHERE `DisplayID`=42368;
UPDATE `creature_model_info` SET `BoundingRadius`=3, `CombatReach`=3, `VerifiedBuild`=63305 WHERE `DisplayID` IN (43160, 43675);
UPDATE `creature_model_info` SET `BoundingRadius`=4.134673595428466796, `CombatReach`=0.686075985431671142, `VerifiedBuild`=63305 WHERE `DisplayID`=117037;
UPDATE `creature_model_info` SET `BoundingRadius`=1.549999952316284179, `CombatReach`=1.549999952316284179, `VerifiedBuild`=63305 WHERE `DisplayID`=44125;
UPDATE `creature_model_info` SET `BoundingRadius`=1.45000004768371582, `CombatReach`=1.45000004768371582, `VerifiedBuild`=63305 WHERE `DisplayID`=44124;
UPDATE `creature_model_info` SET `BoundingRadius`=2.500000238418579101, `CombatReach`=2.500000238418579101, `VerifiedBuild`=63305 WHERE `DisplayID`=43522;
UPDATE `creature_model_info` SET `BoundingRadius`=0.611119985580444335, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID` IN (44135, 44134);
UPDATE `creature_model_info` SET `BoundingRadius`=0.340000003576278686, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=86793;
UPDATE `creature_model_info` SET `BoundingRadius`=4.453600883483886718, `CombatReach`=11.25, `VerifiedBuild`=63305 WHERE `DisplayID`=42807;
UPDATE `creature_model_info` SET `BoundingRadius`=1.250213503837585449, `CombatReach`=2.25, `VerifiedBuild`=63305 WHERE `DisplayID`=85626;
UPDATE `creature_model_info` SET `BoundingRadius`=1.776800990104675292, `CombatReach`=3.5, `VerifiedBuild`=63305 WHERE `DisplayID`=107075;
UPDATE `creature_model_info` SET `BoundingRadius`=2.5, `CombatReach`=3.75, `VerifiedBuild`=63305 WHERE `DisplayID` IN (43087, 43086, 43085);
UPDATE `creature_model_info` SET `BoundingRadius`=4, `CombatReach`=4, `VerifiedBuild`=63305 WHERE `DisplayID`=43266;
UPDATE `creature_model_info` SET `BoundingRadius`=1.75, `CombatReach`=3.5, `VerifiedBuild`=63305 WHERE `DisplayID`=43176;
UPDATE `creature_model_info` SET `BoundingRadius`=0.155000001192092895, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=44433;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=3, `VerifiedBuild`=63305 WHERE `DisplayID`=44428;
UPDATE `creature_model_info` SET `CombatReach`=2.660000085830688476, `VerifiedBuild`=63305 WHERE `DisplayID`=75493;
UPDATE `creature_model_info` SET `BoundingRadius`=2.403360366821289062, `CombatReach`=1.60000002384185791, `VerifiedBuild`=63305 WHERE `DisplayID`=74061;
UPDATE `creature_model_info` SET `BoundingRadius`=0.400000005960464477, `CombatReach`=0.60000002384185791, `VerifiedBuild`=63305 WHERE `DisplayID`=45297;
UPDATE `creature_model_info` SET `BoundingRadius`=0.28326532244682312, `CombatReach`=2.478571414947509765, `VerifiedBuild`=63305 WHERE `DisplayID`=44870;
UPDATE `creature_model_info` SET `BoundingRadius`=0.413480490446090698, `CombatReach`=0.200000002980232238, `VerifiedBuild`=63305 WHERE `DisplayID`=81210;
UPDATE `creature_model_info` SET `BoundingRadius`=5.580212593078613281, `CombatReach`=7, `VerifiedBuild`=63305 WHERE `DisplayID`=40809;
UPDATE `creature_model_info` SET `BoundingRadius`=0.750575423240661621, `VerifiedBuild`=63305 WHERE `DisplayID`=72767;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=40664;
UPDATE `creature_model_info` SET `BoundingRadius`=1.805753946304321289, `VerifiedBuild`=63305 WHERE `DisplayID`=22255;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=63305 WHERE `DisplayID`=72178;
UPDATE `creature_model_info` SET `BoundingRadius`=0.342625141143798828, `CombatReach`=0.300000011920928955, `VerifiedBuild`=63305 WHERE `DisplayID`=38739;
UPDATE `creature_model_info` SET `BoundingRadius`=0.958624064922332763, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=67358;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `VerifiedBuild`=63305 WHERE `DisplayID` IN (101785, 101788, 101789, 101786);
UPDATE `creature_model_info` SET `BoundingRadius`=0.124000005424022674, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID`=29151;
UPDATE `creature_model_info` SET `BoundingRadius`=3.611507892608642578, `VerifiedBuild`=63305 WHERE `DisplayID`=22321;
UPDATE `creature_model_info` SET `BoundingRadius`=0.695999979972839355, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID` IN (42677, 43047);
UPDATE `creature_model_info` SET `BoundingRadius`=4.514384746551513671, `VerifiedBuild`=63305 WHERE `DisplayID`=40914;
UPDATE `creature_model_info` SET `BoundingRadius`=0.181637585163116455, `VerifiedBuild`=63305 WHERE `DisplayID`=36549;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `VerifiedBuild`=63305 WHERE `DisplayID` IN (30211, 87182);
UPDATE `creature_model_info` SET `BoundingRadius`=2.5, `CombatReach`=1.20000004768371582, `VerifiedBuild`=63305 WHERE `DisplayID` IN (93107, 93687, 93105);
UPDATE `creature_model_info` SET `BoundingRadius`=1.20000004768371582, `VerifiedBuild`=63305 WHERE `DisplayID`=79541;
UPDATE `creature_model_info` SET `BoundingRadius`=0.361746400594711303, `CombatReach`=1.60000002384185791, `VerifiedBuild`=63305 WHERE `DisplayID`=44820;
UPDATE `creature_model_info` SET `BoundingRadius`=1.066666722297668457, `VerifiedBuild`=63305 WHERE `DisplayID`=79380;
UPDATE `creature_model_info` SET `BoundingRadius`=2.229759931564331054, `VerifiedBuild`=63305 WHERE `DisplayID`=96260;
UPDATE `creature_model_info` SET `BoundingRadius`=1.777777910232543945, `VerifiedBuild`=63305 WHERE `DisplayID`=87972;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2504291832447052, `CombatReach`=0.150000005960464477, `VerifiedBuild`=63305 WHERE `DisplayID`=48056;
UPDATE `creature_model_info` SET `BoundingRadius`=1.770069241523742675, `CombatReach`=1.625, `VerifiedBuild`=63305 WHERE `DisplayID`=114510;
UPDATE `creature_model_info` SET `BoundingRadius`=1.428551435470581054, `CombatReach`=2, `VerifiedBuild`=63305 WHERE `DisplayID`=94868;
UPDATE `creature_model_info` SET `BoundingRadius`=1.466426014900207519, `CombatReach`=1.799999833106994628, `VerifiedBuild`=63305 WHERE `DisplayID`=98764;
UPDATE `creature_model_info` SET `BoundingRadius`=1.036973834037780761, `CombatReach`=2.20000004768371582, `VerifiedBuild`=63305 WHERE `DisplayID` IN (93163, 93160);
UPDATE `creature_model_info` SET `BoundingRadius`=5.101937294006347656, `CombatReach`=3.75, `VerifiedBuild`=63305 WHERE `DisplayID`=95706;
UPDATE `creature_model_info` SET `BoundingRadius`=1.399999976158142089, `CombatReach`=1.75, `VerifiedBuild`=63305 WHERE `DisplayID`=32024;
UPDATE `creature_model_info` SET `BoundingRadius`=0.186000004410743713, `CombatReach`=1.80000007152557373, `VerifiedBuild`=63305 WHERE `DisplayID`=29152;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236743569374084472, `VerifiedBuild`=63305 WHERE `DisplayID`=84379;
UPDATE `creature_model_info` SET `BoundingRadius`=0.309916138648986816, `VerifiedBuild`=63305 WHERE `DisplayID`=83643;
UPDATE `creature_model_info` SET `BoundingRadius`=5.23212289810180664, `CombatReach`=2.5, `VerifiedBuild`=63305 WHERE `DisplayID`=68024;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=0.25, `VerifiedBuild`=63305 WHERE `DisplayID` IN (81097, 27678);
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID` IN (88555, 87857, 87851, 87854, 87850, 87908, 87842);
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=3, `VerifiedBuild`=63305 WHERE `DisplayID`=84375;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579470038414001464, `VerifiedBuild`=63305 WHERE `DisplayID` IN (62863, 60964, 52600);
UPDATE `creature_model_info` SET `BoundingRadius`=0.367199987173080444, `CombatReach`=1.799999952316284179, `VerifiedBuild`=63305 WHERE `DisplayID`=84374;
UPDATE `creature_model_info` SET `BoundingRadius`=1.432240724563598632, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID` IN (94280, 94278);
UPDATE `creature_model_info` SET `BoundingRadius`=0.716120362281799316, `CombatReach`=0.5, `VerifiedBuild`=63305 WHERE `DisplayID`=94528;
UPDATE `creature_model_info` SET `BoundingRadius`=0.33000001311302185, `CombatReach`=1.10000002384185791, `VerifiedBuild`=63305 WHERE `DisplayID`=19607;
UPDATE `creature_model_info` SET `BoundingRadius`=0.174999997019767761, `CombatReach`=0.5, `VerifiedBuild`=63305 WHERE `DisplayID`=87763;
UPDATE `creature_model_info` SET `BoundingRadius`=3.76745772361755371, `CombatReach`=3, `VerifiedBuild`=63305 WHERE `DisplayID`=86974;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=63305 WHERE `DisplayID` IN (87853, 87856);
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=63305 WHERE `DisplayID`=87847;
UPDATE `creature_model_info` SET `BoundingRadius`=0.938482880592346191, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID`=78242;
UPDATE `creature_model_info` SET `BoundingRadius`=1.136063933372497558, `CombatReach`=1.20000004768371582, `VerifiedBuild`=63305 WHERE `DisplayID` IN (95376, 95392);
UPDATE `creature_model_info` SET `BoundingRadius`=1.917108058929443359, `CombatReach`=2.02500009536743164, `VerifiedBuild`=63305 WHERE `DisplayID`=95379;
UPDATE `creature_model_info` SET `BoundingRadius`=1.706397056579589843, `CombatReach`=4, `VerifiedBuild`=63305 WHERE `DisplayID`=105439;
UPDATE `creature_model_info` SET `BoundingRadius`=0.625500023365020751, `CombatReach`=2.25, `VerifiedBuild`=63305 WHERE `DisplayID`=75808;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=63305 WHERE `DisplayID`=77464;
UPDATE `creature_model_info` SET `BoundingRadius`=1.142857193946838378, `VerifiedBuild`=63305 WHERE `DisplayID`=30221;
UPDATE `creature_model_info` SET `BoundingRadius`=0.324999988079071044, `CombatReach`=0.974999964237213134, `VerifiedBuild`=63305 WHERE `DisplayID`=28734;
UPDATE `creature_model_info` SET `BoundingRadius`=0.616391122341156005, `CombatReach`=2.20000004768371582, `VerifiedBuild`=63305 WHERE `DisplayID`=87564;
UPDATE `creature_model_info` SET `BoundingRadius`=2.123496532440185546, `CombatReach`=1.399999976158142089, `VerifiedBuild`=63305 WHERE `DisplayID`=72014;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520500004291534423, `CombatReach`=2.25, `VerifiedBuild`=63305 WHERE `DisplayID` IN (21824, 23769);
UPDATE `creature_model_info` SET `BoundingRadius`=2.702535867691040039, `VerifiedBuild`=63305 WHERE `DisplayID`=87024;
UPDATE `creature_model_info` SET `BoundingRadius`=0.63454526662826538, `VerifiedBuild`=63305 WHERE `DisplayID`=78159;
UPDATE `creature_model_info` SET `BoundingRadius`=3.039358377456665039, `VerifiedBuild`=63305 WHERE `DisplayID`=109489;
UPDATE `creature_model_info` SET `BoundingRadius`=3.158333301544189453, `VerifiedBuild`=63305 WHERE `DisplayID`=109494;
UPDATE `creature_model_info` SET `BoundingRadius`=0.489999979734420776, `CombatReach`=1.399999976158142089, `VerifiedBuild`=63305 WHERE `DisplayID`=86699;
UPDATE `creature_model_info` SET `BoundingRadius`=2.165999889373779296, `CombatReach`=9, `VerifiedBuild`=63305 WHERE `DisplayID`=21471;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `DisplayID_Other_Gender`=0, `VerifiedBuild`=63305 WHERE `DisplayID`=3562;
UPDATE `creature_model_info` SET `BoundingRadius`=0.424281775951385498, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID`=87760;
UPDATE `creature_model_info` SET `BoundingRadius`=0.106929928064346313, `CombatReach`=1, `VerifiedBuild`=63305 WHERE `DisplayID` IN (75356, 75355, 75350);
UPDATE `creature_model_info` SET `BoundingRadius`=0.441019505262374877, `VerifiedBuild`=63305 WHERE `DisplayID` IN (114622, 114778);
UPDATE `creature_model_info` SET `BoundingRadius`=0.683102548122406005, `CombatReach`=0.875, `VerifiedBuild`=63305 WHERE `DisplayID` IN (115108, 115113);
UPDATE `creature_model_info` SET `BoundingRadius`=0.075000002980232238, `CombatReach`=0.25, `VerifiedBuild`=63305 WHERE `DisplayID`=42297;
UPDATE `creature_model_info` SET `BoundingRadius`=1.513355016708374023, `CombatReach`=1.870000123977661132, `VerifiedBuild`=63305 WHERE `DisplayID`=76951;
UPDATE `creature_model_info` SET `BoundingRadius`=0.233667284250259399, `VerifiedBuild`=63305 WHERE `DisplayID`=85209;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306255877017974853, `CombatReach`=0.800000011920928955, `VerifiedBuild`=63305 WHERE `DisplayID`=36357;
UPDATE `creature_model_info` SET `BoundingRadius`=2.648418426513671875, `CombatReach`=1.25, `VerifiedBuild`=63305 WHERE `DisplayID`=29150;
UPDATE `creature_model_info` SET `BoundingRadius`=2.666666507720947265, `VerifiedBuild`=63305 WHERE `DisplayID`=76046;

UPDATE `quest_template` SET `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=63305 WHERE `ID`=54342; -- Darkshore Donations: Potion of Bursting Blood
UPDATE `quest_template` SET `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=63305 WHERE `ID`=54346; -- Darkshore Donations: Gold
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=63305 WHERE `ID`=54356; -- Darkshore Donations: Quick Golden Beryl
UPDATE `quest_template` SET `VerifiedBuild`=63305 WHERE `ID` IN (48732, 49048, 82088, 47561, 71164, 82041, 83538, 67006, 69913, 52953, 81808, 66896, 75970, 70638, 67062, 59016, 81823, 66070, 48466, 82206, 83532, 76269, 81615, 70701, 81811, 56163, 61813, 75119, 58981, 60533, 75182, 83106, 70410, 58781, 56148, 41089, 70172, 56076, 52229, 46073, 74988, 51116, 69916, 41944, 41705, 75971, 69927, 54528, 55973, 51623, 44290, 57379, 43324, 56178, 56056, 55300, 55466, 58679, 58776, 75288, 72090, 75280, 51611, 46507, 41696, 58661, 62400, 70075, 51379, 43642, 75384, 63100, 49046, 43455, 78434, 66833, 58471, 51792, 51124, 51765, 56074, 61088, 58779, 71156, 67014, 59902, 54793, 58952, 58990, 41700, 51646, 81630, 55898, 52169, 58662, 63775, 44113, 70415, 50695, 54802, 81816, 58463, 51081, 48374, 62615, 51841, 56064, 74571, 73178, 63822, 57565, 41351, 46236, 41836, 82258, 63965, 41237, 45542, 41695, 52295, 76394, 45035, 46198, 57585, 70984, 69929, 40298, 73084, 41703, 75307, 72030, 53246, 56121, 43618, 61814, 70071, 55827, 51491, 50592, 71181, 52163, 52454, 46506, 55825, 83048, 70618, 70110, 81813, 81819, 70072, 75372, 49345, 59234, 50867, 51970, 70421, 50492, 70625, 52958, 83102, 69990, 51627, 48698, 51102, 73179, 81621, 44302, 41274, 44010, 40978, 43427, 43605, 50513, 51098, 51039, 41316, 43453, 51462, 58761, 50619, 55787, 51496, 73698, 50872, 42015, 56009, 58993, 46707, 56020, 51466, 41701, 76076, 52280, 55888, 41240, 75062, 48286, 51654, 51759, 51737, 58755, 63781, 39462, 55895, 51296, 42176, 81750, 64271, 42743, 812, 827, 830, 58975, 51997, 64015, 74515, 55834, 70427, 44013, 54346, 41428, 55524, 49044, 51977, 51378, 56032, 75835, 70529, 58481, 70057, 52007, 63793, 41269, 50957, 70662, 54360, 48725, 51988, 59771, 70442, 69987, 62263, 64964, 51890, 44802, 50717, 52370, 63937, 71205, 91205, 89039, 58667, 64016, 57146, 41273, 75024, 50287, 65264, 61815, 81796, 56090, 52387, 82234, 41980, 43428, 69930, 51429, 56889, 43347, 58676, 46505, 52196, 54791, 75060, 43434, 77761, 51330, 51529, 58780, 45797, 52952, 43612, 70037, 75301, 54722, 52321, 58470, 51659, 56381, 45473, 58961, 70617, 50571, 51848, 49043, 54801, 82470, 52832, 70539, 85928, 75026, 63792, 58442, 61220, 42764, 63823, 52944, 829, 6081, 51508, 57588, 56400, 51097, 52986, 55899, 42062, 51629, 52063, 60837, 52476, 50518, 43630, 54467, 58438, 48175, 54789, 82584, 41826, 49045, 52346, 51047, 67039, 51653, 58974, 63794, 51610, 60476, 41616, 51874, 42442, 41955, 51322, 47135, 52300, 52350, 50857, 56802, 41011, 58465, 58469, 54648, 41318, 43476, 49054, 41014, 57650);
UPDATE `quest_template` SET `ContentTuningID`=1279, `QuestInfoID`=0, `Expansion`=10, `VerifiedBuild`=63305 WHERE `ID`=55660; -- Time Trials
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=63305 WHERE `ID`=51501; -- Kings' Rest: Malfunction Junction
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=63305 WHERE `ID`=41597; -- Lively Highmountain Salmon
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=63305 WHERE `ID`=53247; -- Arathi Donations: Battle Flag: Spirit of Freedom
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=63305 WHERE `ID`=43040; -- DANGER: Valakar the Thirsty
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=63305 WHERE `ID`=1842; -- Satyr Hooves
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=63305 WHERE `ID`=54333; -- Darkshore Donations: Storm Silver Ore
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=63305 WHERE `ID`=44029; -- WANTED: Hertha Grimdottir
UPDATE `quest_template` SET `VerifiedBuild`=63163 WHERE `ID` IN (63956, 74515, 46236, 64016, 75119, 56013, 75024, 55359, 52476, 51098, 57235, 69941, 41237, 61815, 81796, 75182, 70701, 57234, 56148, 58438, 56076, 69930, 45924, 45035, 82519, 46198, 55973, 41826, 51623, 51051, 49048, 47561, 56056, 58420, 73084, 71164, 55466, 75280, 46505, 51844, 52196, 70712, 70429, 46707, 67113, 43642, 41280, 43620, 75384, 55355, 55827, 70639, 51491, 56177, 78434, 58471, 65798, 56074, 75835, 81805, 54796, 52952, 49888, 52007, 59902, 81819, 55888, 55354, 60476, 48725, 75301, 51988, 42067, 57375, 42442, 57650, 61353, 54536, 43621, 62263, 51322, 41278, 47135, 70617, 50571, 70160, 83102, 59016, 52874, 52832, 55357, 67010, 70539, 44193, 58469, 75026, 50717, 81615, 58442, 81750, 56064, 70612, 74571, 73178, 52063, 63823, 57562, 46021, 48466, 67026, 72090, 67039, 70417, 67014, 54380, 70110, 70625, 43475, 66070, 71205, 91205, 89039, 57219, 75990, 57443, 52463, 58288, 58423, 49055, 54509, 41705, 57379, 51664, 56121, 56391, 51527, 58321, 50511, 51117, 65244, 44294, 54797, 51791, 50975, 48733, 56099, 82206, 64964, 42018, 51629, 41824, 54806, 43429, 51905, 54521, 51737, 51081, 63959, 58283, 54800, 55895, 54154, 58975, 41699, 51811, 46164, 54467, 75308, 55524, 74988, 48175, 76394, 70984, 58487, 82088, 55300, 41703, 75025, 42015, 63031, 51444, 50592, 43455, 40278, 51765, 76076, 58481, 50957, 50510, 75372, 59234, 82256, 41240, 81854, 51890, 75304, 46504, 44802, 52300, 60249, 54801, 85928, 61075, 42176, 81802);
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=63163 WHERE `ID`=54366; -- Darkshore Donations: Winter's Kiss
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=63163 WHERE `ID`=54376; -- Darkshore Donations: Potion of Replenishment
UPDATE `quest_template` SET `QuestSessionBonus`=1271, `VerifiedBuild`=63163 WHERE `ID`=46021; -- Thel'draz
UPDATE `quest_template` SET `VerifiedBuild`=63003 WHERE `ID` IN (89039, 91205, 50854, 67009, 61813, 54340, 64016, 75119, 52954, 56090, 56400, 70427, 54346, 56148, 70172, 74988, 69916, 43627, 69927, 82584, 56889, 52181, 58468, 56178, 56056, 67026, 46166, 55466, 58679, 52306, 58676, 75280, 42953, 56121, 46503, 75060, 51287, 77761, 83538, 59003, 67039, 70639, 50592, 58782, 78434, 57968, 51461, 41881, 51653, 56074, 41701, 44748, 70057, 48733, 61352, 70618, 41090, 75286, 51610, 70072, 56099, 54360, 50867, 58660, 67012, 51970, 70421, 50512, 69987, 81630, 58961, 81854, 73083, 58662, 83102, 59016, 49043, 72029, 82470, 52832, 70539, 52940, 58463, 51627, 41935, 48374, 63792, 62615, 48698, 58442, 74992, 51102, 56064, 70612, 66070, 51216, 63822, 57565, 58975, 43624, 51665, 51528, 60533, 75308, 76394, 45035, 57585, 70984, 51378, 75025, 49800, 70075, 56032, 51444, 63785, 81805, 70529, 83048, 81808, 70654, 56801, 46192, 75372, 48725, 49345, 59234, 61353, 70625, 42018, 52248, 75304, 70064, 53245, 50571, 46504, 60249, 69942, 52310, 64080, 61607, 40280, 50717, 43460, 71205, 63823, 43431, 43098, 41267, 43429, 74515, 73080, 55359, 69941, 50519, 48732, 46169, 51512, 50461, 58438, 57379, 82088, 43324, 58285, 58420, 72090, 53246, 43618, 50868, 70071, 58290, 50511, 67006, 57218, 51239, 42062, 51957, 70110, 54091, 55354, 82256, 56381, 62263, 48286, 44292, 52371, 51905, 51759, 70415, 53713, 55357, 50574, 67010, 50695, 56802, 54119, 69990, 81816, 55358, 55790, 42176, 57215, 70021, 57562);
UPDATE `quest_template` SET `VerifiedBuild`=62876 WHERE `ID` IN (81811, 48466, 64240, 82258, 70426, 54724, 51098, 54805, 65264, 83106, 41274, 52229, 41705, 55973, 69929, 43324, 47561, 40298, 75288, 43426, 50872, 51611, 42015, 61814, 51379, 42927, 53832, 44054, 71181, 64040, 44158, 53759, 51791, 52459, 71156, 43714, 46502, 70618, 63960, 54499, 70782, 54091, 81621, 70622, 50566, 51874, 51646, 73190, 70625, 51322, 42018, 43475, 52248, 75304, 54792, 44292, 51654, 52874, 51049, 70539, 49054, 44027, 86853, 48374, 43460, 55790, 62615, 52370, 74992, 44190, 74571, 71205, 83048, 63822, 58975, 50854, 51042, 41836, 50513, 52880, 45922, 45542, 51779, 45035, 69916, 51623, 89039, 91205, 51844, 70075, 63031, 51745, 54797, 52882, 65798, 56799, 51765, 58481, 61352, 70654, 81819, 55888, 60476, 51970, 70064, 73083, 61609, 50501, 83532, 54801, 52832, 54521, 51627, 61075, 55895, 56021, 48698, 81802, 70636, 51763, 50571, 74515, 51811, 43453, 54346, 57585, 52306, 42953, 56121, 54253, 51287, 51444, 64065, 43620, 51330, 56016, 63100, 50592, 40278, 51096, 61088, 60655, 54357, 42148, 48725, 59771, 50492, 62263, 81854, 64964, 51890, 52805, 76269, 63989, 2981, 2479, 5727, 48175, 60837, 43457, 43434, 50633, 53406);
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=62876 WHERE `ID`=51856; -- The Underrot: Rotmaw
UPDATE `quest_template` SET `VerifiedBuild`=62748 WHERE `ID` IN (89039, 91205, 46500, 58667, 75119, 57146, 83106, 56148, 57379, 56056, 56121, 59003, 56177, 56180, 78434, 58471, 56020, 56074, 75835, 76076, 52953, 58974, 58990, 57375, 58961, 60257, 70617, 58662, 59016, 60249, 54801, 54521, 58465, 86853, 56064, 48175, 48698, 82584, 82519, 82206, 82088, 81808, 81615, 75280, 69930, 70662, 69942, 70712, 70442, 70410, 70037, 66833, 53994, 52936, 52459, 51905, 51468, 51043, 49888, 51850, 52248, 52169, 51791, 51379, 50854, 50717, 50492, 46707, 45473, 44294, 43455, 43091, 42211, 41944, 41696, 58776, 58781, 58778, 55466, 64065, 63989, 59234, 60655, 61815, 60533, 63822, 63823, 57565, 45542, 56163, 64016, 58423, 58981, 44302, 49055, 51462, 54112, 55524, 56076, 50866, 45988, 46184, 47561, 40298, 58420, 73698, 43426, 56391, 54791, 62400, 82041, 53875, 83538, 56550, 52209, 60531, 58952, 56099, 51505, 51895, 53808, 41955, 48624, 51457, 75062, 51629, 47135, 44802, 51759, 43175, 56003, 54119, 51037, 58469, 51627, 63959, 42176);
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62748 WHERE `ID`=44194; -- DANGER: Torrentius
UPDATE `quest_template` SET `RewardXPDifficulty`=5, `RewardMoneyDifficulty`=0, `Flags`=0x2790100, `VerifiedBuild`=62748 WHERE `ID`=89294; -- Special Assignment: Aligned Views
UPDATE `quest_template` SET `VerifiedBuild`=62706 WHERE `ID` IN (43427, 43802, 42018, 43612, 89039, 91205, 58975, 46236, 57443, 57146, 58423, 58464, 43628, 57235, 51847, 61815, 46164, 56090, 70701, 70427, 58422, 48732, 83106, 46161, 56148, 82238, 58438, 69930, 52199, 57379, 47561, 56056, 55466, 75280, 42953, 75060, 44012, 62241, 77761, 67113, 83538, 55355, 70639, 57218, 63785, 56177, 51239, 70417, 65798, 51096, 57223, 52953, 55670, 42062, 50861, 58282, 52238, 81813, 82206, 51850, 70622, 53359, 52299, 43621, 60257, 64964, 52248, 52169, 70617, 48286, 58287, 70160, 59016, 60249, 51905, 82470, 64080, 50574, 85928, 51037, 81816, 86853, 41935, 48374, 51296, 81615, 62615, 51841, 58442, 81750, 46500, 56064, 55360, 63823, 57562);
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62706 WHERE `ID`=53244; -- Arathi Donations: Shimmerscale
UPDATE `quest_template` SET `VerifiedBuild`=62493 WHERE `ID` IN (70701, 65798, 89039, 91205, 55892, 81811, 48466, 64016, 73080, 57588, 75182, 50496, 75308, 41687, 82238, 41089, 55524, 45924, 46948, 41705, 52936, 51972, 83103, 43426, 53983, 56009, 70429, 46707, 83538, 50511, 75384, 63100, 54468, 52163, 75657, 61088, 75835, 44748, 58481, 44293, 50861, 48733, 51782, 70662, 66896, 75372, 75301, 59234, 51036, 82206, 51659, 43432, 67012, 51895, 70625, 81854, 52248, 52958, 70617, 44119, 44802, 72029, 53707, 82470, 52832, 69990, 51627, 51081, 81823, 39462, 55895, 51296, 74992, 51102, 58476, 61220, 73178, 42743, 63962, 52372, 43608, 55834, 56800, 51779, 50461, 45988, 43627, 51429, 52199, 58487, 43324, 50872, 56121, 42211, 62241, 82041, 63031, 67039, 65244, 56020, 51466, 49056, 60531, 43762, 82778, 42442, 56381, 51654, 43429, 51905, 51453, 43175, 52388, 56003, 41011, 51737, 50717, 41935, 61075, 51893, 65269, 46236, 70427, 51116, 58760, 70712, 50633, 51491, 70440, 70413, 71181, 51653, 81805, 81813, 81819, 69987, 51742, 46190, 85928, 52805, 74515, 64240, 82258, 52476, 54342, 54346, 43638, 48175, 51623, 51123, 44304, 41252, 43434, 64040, 52454, 51765, 55888, 50510, 81621, 42148, 60476, 49345, 52321, 51874, 62263, 51050, 42991, 44027, 44192, 54353, 55790, 51155, 51892, 63823, 57219, 64015, 61813, 58288, 70426, 50513, 51847, 45542, 56090, 56148, 70172, 58438, 76394, 69927, 70984, 56056, 58420, 73084, 55466, 75307, 73698, 72030, 75280, 52196, 51118, 46507, 70075, 51444, 51745, 56177, 51529, 56180, 58471, 56074, 51791, 52952, 70529, 70618, 75286, 70654, 52385, 51505, 57375, 61353, 81630, 75062, 70064, 59016, 52874, 57217, 55357, 50574, 40280, 58469, 55358, 48698, 63937, 56064, 55360, 73179, 57215, 70636, 63822, 57562, 50571, 83100, 52007, 51098, 51811, 51508, 53256, 51611, 51844, 51330, 56799, 50975, 53008, 61609, 63775, 52310, 61342, 53406, 82992, 58909, 325, 1861, 1274, 1921, 52944, 54671, 53886);
UPDATE `quest_template` SET `QuestSortID`=15336, `VerifiedBuild`=62493 WHERE `ID`=90781; -- Sparks of War: K'aresh
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=53364; -- Arathi Donations: Drums of the Maelstrom
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=62493 WHERE `ID`=51501; -- Kings' Rest: Malfunction Junction
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62493 WHERE `ID`=44194; -- DANGER: Torrentius
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62493 WHERE `ID`=44029; -- WANTED: Hertha Grimdottir
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=54333; -- Darkshore Donations: Storm Silver Ore
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=54355; -- Darkshore Donations: Mistscale
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=54329; -- Darkshore Donations: War Resources
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62493 WHERE `ID`=46189; -- Shel'zuul
UPDATE `quest_template` SET `RewardXPDifficulty`=5, `RewardMoneyDifficulty`=0, `Flags`=0x2790100, `VerifiedBuild`=62493 WHERE `ID`=89294; -- Special Assignment: Aligned Views
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=54333; -- Darkshore Donations: Storm Silver Ore
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=54355; -- Darkshore Donations: Mistscale
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=54329; -- Darkshore Donations: War Resources
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=63305 WHERE `ID`=53247; -- Arathi Donations: Battle Flag: Spirit of Freedom
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=63305 WHERE `ID`=51578; -- The Sea Runs Red
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=63003 WHERE `ID`=47061; -- Apocron
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=63003 WHERE `ID`=52928; -- Arathi Donations: Coarse Leather
UPDATE `quest_template` SET `RewardXPDifficulty`=5, `RewardMoneyDifficulty`=0, `Flags`=0x2790100, `VerifiedBuild`=62876 WHERE `ID`=89294; -- Special Assignment: Aligned Views
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62876 WHERE `ID`=54341; -- Darkshore Donations: Enchant Ring - Seal of Mastery
UPDATE `quest_template` SET `VerifiedBuild`=62801 WHERE `ID` IN (89039, 91205, 56392, 56400, 83106, 41428, 51763, 48175, 49044, 69916, 41944, 58487, 69929, 52346, 65265, 73698, 52306, 75288, 51118, 61814, 70075, 82041, 83538, 64065, 43455, 54531, 44158, 55899, 52459, 54796, 71156, 46502, 49888, 48733, 63793, 61352, 70618, 70654, 60531, 81819, 50510, 54722, 82206, 51874, 51646, 41240, 42442, 43621, 73190, 70625, 42018, 75062, 51890, 47135, 75304, 70064, 73083, 50571, 54806, 51742, 43175, 52350, 70539, 43452, 56802, 86853, 81615, 74992, 63989, 81802, 74571, 71205, 70636, 63822);
UPDATE `quest_template` SET `VerifiedBuild`=62680 WHERE `ID` IN (89039, 91205, 81811, 74515, 73080, 57443, 60837, 40978, 57588, 43802, 75182, 52115, 56400, 70701, 51097, 75308, 82238, 41089, 48175, 75971, 41268, 83103, 57585, 46942, 58487, 53257, 51611, 56121, 75060, 70429, 77761, 83538, 55725, 64065, 50633, 75384, 56016, 43455, 53250, 52163, 51124, 65798, 75835, 41844, 70662, 66896, 75372, 75301, 41298, 52321, 82206, 50867, 59771, 50566, 67012, 45473, 70625, 62263, 64964, 51890, 47135, 52958, 44028, 70617, 44119, 72029, 82470, 52940, 69990, 81823, 51774, 51296, 81615, 74992, 81750, 63989, 73178, 42743);
UPDATE `quest_template` SET `QuestSortID`=15336, `VerifiedBuild`=62680 WHERE `ID`=90781; -- Sparks of War: K'aresh
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=62680 WHERE `ID`=51501; -- Kings' Rest: Malfunction Junction
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=53364; -- Arathi Donations: Drums of the Maelstrom
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=52928; -- Arathi Donations: Coarse Leather
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=54333; -- Darkshore Donations: Storm Silver Ore
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=54355; -- Darkshore Donations: Mistscale
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=54329; -- Darkshore Donations: War Resources
UPDATE `quest_template` SET `QuestSortID`=15336 WHERE `ID`=90781;
UPDATE `quest_template` SET `VerifiedBuild`=62438 WHERE `ID` IN (50571, 55892, 75990, 50854, 45048, 58288, 63965, 56400, 54346, 41089, 70172, 49045, 57379, 55300, 42783, 41078, 73698, 43618, 62241, 70075, 83538, 70413, 41881, 57223, 55670, 70529, 48733, 63794, 51610, 81621, 51212, 66896, 55354, 42799, 52321, 58470, 67012, 57650, 51997, 51050, 75062, 51629, 70064, 55356, 57243, 43452, 58465, 55358, 81823, 70636, 63823, 57562, 52007, 51665, 41836, 58981, 54724, 51462, 58422, 41272, 50866, 42820, 51429, 58679, 58993, 55725, 50633, 51239, 56550, 44030, 56020, 54804, 54499, 41955, 54792, 48286, 51102, 61220, 52063, 50513, 55359, 52309, 57235, 55834, 45542, 48732, 41282, 49044, 54349, 46707, 64065, 57218, 51124, 52004, 63793, 52382, 54360, 59771, 51654, 58463, 55895, 63989, 52373, 57215);
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62438 WHERE `ID`=54348; -- Darkshore Donations: Deep Sea Satin
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62438 WHERE `ID`=54352; -- Darkshore Donations: Shimmerscale Diving Suit
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62438 WHERE `ID`=44018; -- WANTED: Magister Phaedris
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62438 WHERE `ID`=41611; -- Huge Cursed Queenfish
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=63305 WHERE `ID`=53247; -- Arathi Donations: Battle Flag: Spirit of Freedom
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `RewardCurrencyID3`=1602, `RewardCurrencyQty3`=5000, `VerifiedBuild`=63305 WHERE `ID`=81795; -- Sparks of War: Hallowfall
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=63163 WHERE `ID`=54170; -- Ormin Rocketbop
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=63003 WHERE `ID`=41612; -- Huge Mossgill Perch
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=63003 WHERE `ID`=53364; -- Arathi Donations: Drums of the Maelstrom
UPDATE `quest_template` SET `VerifiedBuild`=62958 WHERE `ID` IN (84084, 89039, 91205, 50854, 67009, 61813, 54340, 64016, 75119, 52954, 50287, 56090, 56400, 70427, 54346, 56148, 70172, 74988, 69916, 43627, 69927, 82584, 56889, 52181, 58468, 56178, 56056, 67026, 46166, 55466, 58679, 52306, 58676, 75280, 42953, 56121, 46503, 75060, 51287, 77761, 83538, 59003, 67039, 70639, 50592, 58782, 78434, 57968, 51461, 41881, 51653, 56074, 41701, 44748, 70057, 48733, 61352, 70618, 41090, 75286, 51610, 70072, 56099, 54360, 50867, 58660, 67012, 51970, 70421, 50512, 69987, 81630, 58961, 81854, 73083, 58662, 83102, 59016, 49043, 72029, 82470, 52832, 70539, 52940, 58463, 51627, 41935, 48374, 63792, 62615, 48698, 58442, 74992, 51102, 56064, 70612, 66070, 51216, 63822, 57565);
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=62748 WHERE `ID`=46189; -- Shel'zuul
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=52928; -- Arathi Donations: Coarse Leather
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62493 WHERE `ID`=52928; -- Arathi Donations: Coarse Leather
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=62438 WHERE `ID`=54329; -- Darkshore Donations: War Resources


UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=290863; -- 290863
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=436340; -- 436340
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=436344; -- 436344
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=436345; -- 436345

UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=436443; -- 436443
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=436447; -- 436447
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=254703; -- 254703
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=436592; -- 436592
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=436593; -- 436593
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=436594; -- 436594
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=436998; -- 436998
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=436999; -- 436999
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=437000; -- 437000
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=437318; -- 437318
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=437319; -- 437319
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=437320; -- 437320
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=437321; -- 437321
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=437324; -- 437324
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=437325; -- 437325
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=437500; -- 437500
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=437513; -- 437513
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=437514; -- 437514
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=255890; -- 255890
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=437669; -- 437669
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=292571; -- 292571
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=438025; -- 438025
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=438026; -- 438026
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=256264; -- 256264
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=256298; -- 256298
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=256299; -- 256299
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=438094; -- 438094
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=256446; -- 256446
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=292831; -- 292831
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=292833; -- 292833
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=293571; -- 293571
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=293573; -- 293573
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=293575; -- 293575
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=293577; -- 293577
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=293581; -- 293581
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=293595; -- 293595
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=293597; -- 293597
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=293601; -- 293601
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=295285; -- 295285
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=295286; -- 295286
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=404427; -- 404427
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=404428; -- 404428
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=404429; -- 404429
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=404430; -- 404430
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=404431; -- 404431
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=404547; -- 404547
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=295503; -- 295503
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=295504; -- 295504
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=405172; -- 405172
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=405186; -- 405186
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=405418; -- 405418
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=405419; -- 405419
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=405420; -- 405420
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=405421; -- 405421
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=405422; -- 405422
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=405426; -- 405426
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=405433; -- 405433
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=332868; -- 332868
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=332886; -- 332886
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=332897; -- 332897
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=332912; -- 332912
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=332913; -- 332913
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=332914; -- 332914
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=332915; -- 332915
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=332920; -- 332920
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=332921; -- 332921
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=405674; -- 405674
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=405675; -- 405675
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=405680; -- 405680
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=405681; -- 405681
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=405682; -- 405682
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=405683; -- 405683
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=333107; -- 333107
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=333125; -- 333125
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=333141; -- 333141
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405867; -- 405867
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405868; -- 405868
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405869; -- 405869
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405870; -- 405870
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405871; -- 405871
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405872; -- 405872
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405873; -- 405873
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405874; -- 405874
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405875; -- 405875
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405876; -- 405876
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=405877; -- 405877
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=333224; -- 333224
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406032; -- 406032
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406033; -- 406033
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406034; -- 406034
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406035; -- 406035
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406036; -- 406036
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406037; -- 406037
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406038; -- 406038
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406039; -- 406039
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406040; -- 406040
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406041; -- 406041
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406042; -- 406042
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=333367; -- 333367
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=333390; -- 333390
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=333558; -- 333558
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=333559; -- 333559
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=333595; -- 333595
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=333601; -- 333601
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=406388; -- 406388
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406392; -- 406392
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=406638; -- 406638
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=406640; -- 406640
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=406729; -- 406729
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=406731; -- 406731
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=334115; -- 334115
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=334117; -- 334117
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334124; -- 334124
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=334128; -- 334128
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=334129; -- 334129
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=334130; -- 334130
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334142; -- 334142
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=334334; -- 334334
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=334335; -- 334335
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=443403; -- 443403
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=443404; -- 443404
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=443405; -- 443405
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=443406; -- 443406
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=443407; -- 443407
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=443408; -- 443408
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334481; -- 334481
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334482; -- 334482
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334574; -- 334574
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=334575; -- 334575
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=334577; -- 334577
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=334580; -- 334580
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=334581; -- 334581
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=334585; -- 334585
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=334587; -- 334587
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=334588; -- 334588
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=334589; -- 334589
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334591; -- 334591
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334606; -- 334606
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334607; -- 334607
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334608; -- 334608
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334690; -- 334690
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=334743; -- 334743
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=334745; -- 334745
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334747; -- 334747
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=334753; -- 334753
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334781; -- 334781
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=334783; -- 334783
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334785; -- 334785
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334797; -- 334797
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=334799; -- 334799
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=407521; -- 407521
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=407522; -- 407522
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=407536; -- 407536
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=407545; -- 407545
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=407546; -- 407546
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=407553; -- 407553
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=407554; -- 407554
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=407555; -- 407555
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=407556; -- 407556
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=334879; -- 334879
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=407588; -- 407588
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=407589; -- 407589
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=407658; -- 407658
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=407661; -- 407661
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=407666; -- 407666
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=407667; -- 407667
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=407669; -- 407669
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=407670; -- 407670
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=407671; -- 407671
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=407698; -- 407698
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=407700; -- 407700
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=407701; -- 407701
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=407702; -- 407702
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=407703; -- 407703
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=407708; -- 407708
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=335041; -- 335041
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=335146; -- 335146
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=335147; -- 335147
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=335148; -- 335148
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=335149; -- 335149
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=335165; -- 335165
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=335169; -- 335169
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=335229; -- 335229
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=335304; -- 335304
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=335305; -- 335305
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=335342; -- 335342
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=335343; -- 335343
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=335416; -- 335416
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=335433; -- 335433
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=335434; -- 335434
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=335627; -- 335627
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=335628; -- 335628
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=335629; -- 335629
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=335630; -- 335630
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=335862; -- 335862
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=335874; -- 335874
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=335903; -- 335903
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=335904; -- 335904
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=335930; -- 335930
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=335934; -- 335934
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=335943; -- 335943
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=335945; -- 335945
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=335976; -- 335976
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=335977; -- 335977
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=335978; -- 335978
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=336035; -- 336035
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=336036; -- 336036
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=336039; -- 336039
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=336061; -- 336061
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=336062; -- 336062
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=336067; -- 336067
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=408962; -- 408962
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=408963; -- 408963
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=409030; -- 409030
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=336345; -- 336345
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=336346; -- 336346
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=336347; -- 336347
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=336348; -- 336348
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=409054; -- 409054
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=336349; -- 336349
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=336350; -- 336350
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=336351; -- 336351
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=336352; -- 336352
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=409075; -- 409075
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=409083; -- 409083
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=336454; -- 336454
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=336458; -- 336458
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=409170; -- 409170
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=409171; -- 409171
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=336552; -- 336552
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=336598; -- 336598
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=336631; -- 336631
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=336634; -- 336634
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=336640; -- 336640
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=336654; -- 336654
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=336656; -- 336656
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=336958; -- 336958
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=336959; -- 336959
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=336960; -- 336960
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=337078; -- 337078
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337111; -- 337111
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337112; -- 337112
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337113; -- 337113
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337114; -- 337114
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=337141; -- 337141
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=337147; -- 337147
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337151; -- 337151
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337158; -- 337158
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337176; -- 337176
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=337177; -- 337177
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337241; -- 337241
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337242; -- 337242
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337366; -- 337366
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337372; -- 337372
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=337374; -- 337374
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=337378; -- 337378
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=337384; -- 337384
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=337419; -- 337419
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=337420; -- 337420
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=337466; -- 337466
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337470; -- 337470
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337472; -- 337472
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337476; -- 337476
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=337614; -- 337614
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=337628; -- 337628
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=337640; -- 337640
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=337690; -- 337690
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337710; -- 337710
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337711; -- 337711
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337737; -- 337737
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337738; -- 337738
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337756; -- 337756
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337757; -- 337757
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337758; -- 337758
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337811; -- 337811
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337840; -- 337840
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337863; -- 337863
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=337884; -- 337884
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=337935; -- 337935
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=337949; -- 337949
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=338004; -- 338004
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338066; -- 338066
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338067; -- 338067
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338068; -- 338068
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338069; -- 338069
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338071; -- 338071
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338087; -- 338087
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338088; -- 338088
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338089; -- 338089
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338090; -- 338090
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338091; -- 338091
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338131; -- 338131
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=338211; -- 338211
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=338260; -- 338260
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338312; -- 338312
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338353; -- 338353
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338354; -- 338354
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338355; -- 338355
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=338417; -- 338417
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=338418; -- 338418
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338536; -- 338536
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=338565; -- 338565
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=338573; -- 338573
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338615; -- 338615
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338616; -- 338616
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338668; -- 338668
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=338674; -- 338674
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=338675; -- 338675
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338692; -- 338692
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=338722; -- 338722
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=338726; -- 338726
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338735; -- 338735
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=338773; -- 338773
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=338821; -- 338821
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=338825; -- 338825
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=338852; -- 338852
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=338854; -- 338854
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338856; -- 338856
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=338858; -- 338858
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=338869; -- 338869
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=338879; -- 338879
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=338881; -- 338881
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=339022; -- 339022
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=339023; -- 339023
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=339035; -- 339035
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=339046; -- 339046
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=339250; -- 339250
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=448466; -- 448466
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=448752; -- 448752
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=448753; -- 448753
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=448832; -- 448832
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=448834; -- 448834
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=448841; -- 448841
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=448844; -- 448844
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=448846; -- 448846
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=448848; -- 448848
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=448853; -- 448853
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=448856; -- 448856
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=448859; -- 448859
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=448922; -- 448922
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449005; -- 449005
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449010; -- 449010
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449020; -- 449020
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449025; -- 449025
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449028; -- 449028
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449040; -- 449040
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340006; -- 340006
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340007; -- 340007
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340116; -- 340116
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340155; -- 340155
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449215; -- 449215
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340156; -- 340156
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449216; -- 449216
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340157; -- 340157
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449217; -- 449217
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340158; -- 340158
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340159; -- 340159
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340160; -- 340160
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340161; -- 340161
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=340185; -- 340185
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=340203; -- 340203
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=340204; -- 340204
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340278; -- 340278
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340303; -- 340303
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340304; -- 340304
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340305; -- 340305
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340306; -- 340306
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340308; -- 340308
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=340318; -- 340318
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=449392; -- 449392
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=449393; -- 449393
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=449395; -- 449395
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340356; -- 340356
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=340378; -- 340378
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=340380; -- 340380
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340395; -- 340395
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=340437; -- 340437
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=340506; -- 340506
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=340507; -- 340507
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=340508; -- 340508
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449617; -- 449617
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340559; -- 340559
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340560; -- 340560
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340561; -- 340561
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340562; -- 340562
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=340563; -- 340563
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=449942; -- 449942
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=449950; -- 449950
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=340993; -- 340993
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=340994; -- 340994
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=340995; -- 340995
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=340996; -- 340996
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=341000; -- 341000
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=341007; -- 341007
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=341008; -- 341008
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=341194; -- 341194
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=341206; -- 341206
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=450311; -- 450311
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=450312; -- 450312
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=450313; -- 450313
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=341289; -- 341289
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=341295; -- 341295
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=341343; -- 341343
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=341344; -- 341344
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=341431; -- 341431
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=450535; -- 450535
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=450622; -- 450622
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=450625; -- 450625
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=450627; -- 450627
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=450632; -- 450632
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=450633; -- 450633
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=341704; -- 341704
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=341772; -- 341772
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=341826; -- 341826
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=451143; -- 451143
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=451144; -- 451144
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=451145; -- 451145
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=342093; -- 342093
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=342119; -- 342119
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=342127; -- 342127
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=342195; -- 342195
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=342198; -- 342198
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=342199; -- 342199
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=451318; -- 451318
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=451322; -- 451322
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=451324; -- 451324
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=451325; -- 451325
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=451400; -- 451400
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=451401; -- 451401
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=451402; -- 451402
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=451722; -- 451722
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=455947; -- 455947
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=419741; -- 419741
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=419748; -- 419748
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=419752; -- 419752
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=419765; -- 419765
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=419767; -- 419767
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=419769; -- 419769
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=419882; -- 419882
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=419883; -- 419883
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420189; -- 420189
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420217; -- 420217
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=420271; -- 420271
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=420277; -- 420277
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=420279; -- 420279
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420283; -- 420283
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420289; -- 420289
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420298; -- 420298
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420307; -- 420307
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420308; -- 420308
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420309; -- 420309
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420310; -- 420310
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420311; -- 420311
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420312; -- 420312
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420349; -- 420349
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420401; -- 420401
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420402; -- 420402
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420403; -- 420403
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420404; -- 420404
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420413; -- 420413
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420427; -- 420427
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420428; -- 420428
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420470; -- 420470
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420534; -- 420534
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420535; -- 420535
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=420536; -- 420536
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420552; -- 420552
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420611; -- 420611
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420612; -- 420612
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420613; -- 420613
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=420614; -- 420614
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420774; -- 420774
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420797; -- 420797
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420801; -- 420801
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420803; -- 420803
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420804; -- 420804
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=420805; -- 420805
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=420806; -- 420806
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=420807; -- 420807
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=420808; -- 420808
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=420809; -- 420809
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420811; -- 420811
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=420846; -- 420846
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=457488; -- 457488
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=385354; -- 385354
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=385380; -- 385380
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=385381; -- 385381
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=385408; -- 385408
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=385409; -- 385409
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=421788; -- 421788
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385451; -- 385451
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385452; -- 385452
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385453; -- 385453
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385454; -- 385454
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385455; -- 385455
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385456; -- 385456
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385457; -- 385457
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=421814; -- 421814
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=421815; -- 421815
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=421816; -- 421816
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=421817; -- 421817
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=421818; -- 421818
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=385721; -- 385721
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=385734; -- 385734
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=385748; -- 385748
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385758; -- 385758
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385759; -- 385759
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=385760; -- 385760
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=386029; -- 386029
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=386055; -- 386055
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=386087; -- 386087
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=422488; -- 422488
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=422632; -- 422632
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=422641; -- 422641
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=422642; -- 422642
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=422647; -- 422647
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=386297; -- 386297
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=422662; -- 422662
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=386321; -- 386321
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=386340; -- 386340
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=386631; -- 386631
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=386633; -- 386633
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=386676; -- 386676
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=386677; -- 386677
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=386726; -- 386726
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=386796; -- 386796
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=386797; -- 386797
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=386798; -- 386798
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=423209; -- 423209
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=386954; -- 386954
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=386962; -- 386962
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=386976; -- 386976
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=386978; -- 386978
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=386980; -- 386980
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=386988; -- 386988
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=386992; -- 386992
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=386994; -- 386994
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=387000; -- 387000
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=387002; -- 387002
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=387006; -- 387006
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387008; -- 387008
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=387010; -- 387010
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=387016; -- 387016
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=387028; -- 387028
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=423386; -- 423386
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=387048; -- 387048
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=387056; -- 387056
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=387245; -- 387245
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=387246; -- 387246
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=387247; -- 387247
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=387299; -- 387299
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=387300; -- 387300
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=387301; -- 387301
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=387302; -- 387302
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=387314; -- 387314
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=387459; -- 387459
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=387460; -- 387460
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=387462; -- 387462
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387483; -- 387483
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387484; -- 387484
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387485; -- 387485
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387486; -- 387486
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387487; -- 387487
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387488; -- 387488
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387489; -- 387489
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=387507; -- 387507
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=423861; -- 423861
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=423862; -- 423862
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=423863; -- 423863
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=387550; -- 387550
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=387551; -- 387551
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=387569; -- 387569
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=387604; -- 387604
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387853; -- 387853
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387854; -- 387854
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387855; -- 387855
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387856; -- 387856
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387857; -- 387857
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387858; -- 387858
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=387859; -- 387859
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=387926; -- 387926
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=388139; -- 388139
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=388159; -- 388159
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=388160; -- 388160
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=388161; -- 388161
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=388162; -- 388162
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=388163; -- 388163
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=388165; -- 388165
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=388228; -- 388228
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=388230; -- 388230
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=388236; -- 388236
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=388238; -- 388238
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=388254; -- 388254
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=388274; -- 388274
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=388277; -- 388277
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=388281; -- 388281
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=388283; -- 388283
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=388308; -- 388308
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=388309; -- 388309
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=388310; -- 388310
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=388381; -- 388381
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=461265; -- 461265
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=461266; -- 461266
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=461315; -- 461315
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=388997; -- 388997
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=388998; -- 388998
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=389057; -- 389057
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=389059; -- 389059
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=389060; -- 389060
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=389061; -- 389061
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=389062; -- 389062
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=389063; -- 389063
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=352741; -- 352741
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=352743; -- 352743
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=280043; -- 280043
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=352749; -- 352749
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=352750; -- 352750
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=352782; -- 352782
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=352810; -- 352810
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=389231; -- 389231
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=389232; -- 389232
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=389233; -- 389233
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=352915; -- 352915
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=352916; -- 352916
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=352922; -- 352922
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=352955; -- 352955
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=389480; -- 389480
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=389550; -- 389550
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=280583; -- 280583
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=280585; -- 280585
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=389665; -- 389665
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=389671; -- 389671
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=280633; -- 280633
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=389730; -- 389730
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=389750; -- 389750
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=389751; -- 389751
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=389841; -- 389841
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=389849; -- 389849
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=389855; -- 389855
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=389863; -- 389863
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=390042; -- 390042
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=390059; -- 390059
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=390062; -- 390062
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=390065; -- 390065
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=390071; -- 390071
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=390072; -- 390072
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=390076; -- 390076
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=390092; -- 390092
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=390281; -- 390281
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=281274; -- 281274
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=281540; -- 281540
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=281541; -- 281541
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=281542; -- 281542
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=281597; -- 281597
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=427035; -- 427035
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=281652; -- 281652
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=281653; -- 281653
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=281660; -- 281660
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=390730; -- 390730
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=390750; -- 390750
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=390752; -- 390752
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=390768; -- 390768
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=281772; -- 281772
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=281804; -- 281804
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=281806; -- 281806
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=281820; -- 281820
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=281821; -- 281821
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=281823; -- 281823
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=281824; -- 281824
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=281859; -- 281859
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=281925; -- 281925
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391145; -- 391145
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=282092; -- 282092
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=282098; -- 282098
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=282120; -- 282120
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=282147; -- 282147
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=282148; -- 282148
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=282149; -- 282149
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=282152; -- 282152
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=282153; -- 282153
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=282154; -- 282154
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=282158; -- 282158
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=282160; -- 282160
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=282162; -- 282162
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=282178; -- 282178
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=282208; -- 282208
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=282210; -- 282210
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=282242; -- 282242
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=391363; -- 391363
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=391365; -- 391365
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=391367; -- 391367
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=391369; -- 391369
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=282349; -- 282349
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=391445; -- 391445
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=282462; -- 282462
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=282463; -- 282463
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=282552; -- 282552
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=282566; -- 282566
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=282567; -- 282567
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=282571; -- 282571
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=282658; -- 282658
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=282679; -- 282679
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=428103; -- 428103
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=282692; -- 282692
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=428104; -- 428104
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=282696; -- 282696
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=282697; -- 282697
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=282698; -- 282698
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=282699; -- 282699
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=282703; -- 282703
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391770; -- 391770
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=391777; -- 391777
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391781; -- 391781
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391782; -- 391782
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=391783; -- 391783
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391785; -- 391785
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=391787; -- 391787
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=391857; -- 391857
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=391870; -- 391870
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391908; -- 391908
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391911; -- 391911
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=391922; -- 391922
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391927; -- 391927
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=391928; -- 391928
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391930; -- 391930
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=282889; -- 282889
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=282892; -- 282892
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=282901; -- 282901
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=391963; -- 391963
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=391964; -- 391964
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391966; -- 391966
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=391967; -- 391967
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=282916; -- 282916
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=428332; -- 428332
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=428333; -- 428333
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=464740; -- 464740
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=283000; -- 283000
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=283134; -- 283134
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=283135; -- 283135
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=283163; -- 283163
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=283192; -- 283192
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=283196; -- 283196
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=283198; -- 283198
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=392279; -- 392279
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=392281; -- 392281
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=392282; -- 392282
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=428707; -- 428707
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=428708; -- 428708
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=428709; -- 428709
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=428710; -- 428710
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=428719; -- 428719
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=428720; -- 428720
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=428727; -- 428727
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=428728; -- 428728
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=428729; -- 428729
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=428781; -- 428781
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=428782; -- 428782
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=428783; -- 428783
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=428784; -- 428784
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=283381; -- 283381
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=428872; -- 428872
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=428873; -- 428873
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=428874; -- 428874
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=283479; -- 283479
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=392645; -- 392645
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=392687; -- 392687
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=392693; -- 392693
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=283771; -- 283771
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=392836; -- 392836
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=283857; -- 283857
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=429417; -- 429417
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=429425; -- 429425
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=429485; -- 429485
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=429486; -- 429486
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=429519; -- 429519
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=429521; -- 429521
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=429598; -- 429598
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=429616; -- 429616
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=284226; -- 284226
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=429670; -- 429670
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=429695; -- 429695
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=393389; -- 393389
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=429765; -- 429765
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=429821; -- 429821
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=429823; -- 429823
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=429829; -- 429829
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=429879; -- 429879
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=430010; -- 430010
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=430011; -- 430011
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430054; -- 430054
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=284674; -- 284674
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=284722; -- 284722
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=284723; -- 284723
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=284740; -- 284740
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=284741; -- 284741
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=393813; -- 393813
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=430179; -- 430179
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=284770; -- 284770
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=430202; -- 430202
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=430203; -- 430203
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=430205; -- 430205
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=284806; -- 284806
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=284915; -- 284915
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=430401; -- 430401
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=394049; -- 394049
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=394050; -- 394050
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430404; -- 430404
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=394054; -- 394054
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=430407; -- 430407
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285000; -- 285000
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=430413; -- 430413
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=394061; -- 394061
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=394062; -- 394062
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=394067; -- 394067
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430420; -- 430420
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430422; -- 430422
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=285021; -- 285021
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=285037; -- 285037
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430452; -- 430452
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=285041; -- 285041
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430471; -- 430471
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430472; -- 430472
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430473; -- 430473
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430474; -- 430474
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430475; -- 430475
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430476; -- 430476
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430477; -- 430477
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=430480; -- 430480
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=430481; -- 430481
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285072; -- 285072
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=430518; -- 430518
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=394227; -- 394227
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430583; -- 430583
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=394233; -- 394233
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=430589; -- 430589
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=285223; -- 285223
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=394285; -- 394285
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=394286; -- 394286
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430648; -- 430648
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285254; -- 285254
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=285255; -- 285255
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430667; -- 430667
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=285256; -- 285256
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285257; -- 285257
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430669; -- 430669
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430670; -- 430670
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430671; -- 430671
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285260; -- 285260
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430672; -- 430672
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285261; -- 285261
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=430675; -- 430675
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=430676; -- 430676
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=430677; -- 430677
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=430678; -- 430678
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=430680; -- 430680
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=394331; -- 394331
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=394332; -- 394332
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430685; -- 430685
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=394336; -- 394336
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=394337; -- 394337
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=394343; -- 394343
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=285284; -- 285284
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=285285; -- 285285
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=285287; -- 285287
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=285289; -- 285289
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=285292; -- 285292
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=394355; -- 394355
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=430747; -- 430747
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=430748; -- 430748
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=430750; -- 430750
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430837; -- 430837
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430861; -- 430861
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430862; -- 430862
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430884; -- 430884
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430885; -- 430885
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430886; -- 430886
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430887; -- 430887
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430888; -- 430888
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430889; -- 430889
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430890; -- 430890
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430893; -- 430893
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=430899; -- 430899
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=285542; -- 285542
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285545; -- 285545
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=285549; -- 285549
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430963; -- 430963
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=430965; -- 430965
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=430966; -- 430966
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=430967; -- 430967
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=285555; -- 285555
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=285557; -- 285557
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=285558; -- 285558
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=285561; -- 285561
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285564; -- 285564
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=285565; -- 285565
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=285567; -- 285567
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285577; -- 285577
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285578; -- 285578
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430991; -- 430991
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=430995; -- 430995
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=394653; -- 394653
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=394654; -- 394654
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=285624; -- 285624
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=431046; -- 431046
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=431059; -- 431059
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=394709; -- 394709
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=394710; -- 394710
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=394722; -- 394722
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=431076; -- 431076
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=394723; -- 394723
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=285689; -- 285689
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=285690; -- 285690
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=431129; -- 431129
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=431130; -- 431130
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=431131; -- 431131
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=431132; -- 431132
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=431133; -- 431133
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=431134; -- 431134
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=431135; -- 431135
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=431149; -- 431149
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=431150; -- 431150
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285764; -- 285764
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=285765; -- 285765
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=394864; -- 394864
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=394868; -- 394868
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=285820; -- 285820
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=285821; -- 285821
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=394891; -- 394891
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=394896; -- 394896
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=394902; -- 394902
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=394904; -- 394904
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=394933; -- 394933
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=394943; -- 394943
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=394945; -- 394945
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=394946; -- 394946
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431346; -- 431346
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431347; -- 431347
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431348; -- 431348
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=395033; -- 395033
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=395145; -- 395145
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=431509; -- 431509
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=431510; -- 431510
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=431511; -- 431511
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=431512; -- 431512
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=431513; -- 431513
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=431514; -- 431514
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=286104; -- 286104
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=286110; -- 286110
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=286112; -- 286112
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=286116; -- 286116
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=431533; -- 431533
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=286128; -- 286128
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=286129; -- 286129
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=286130; -- 286130
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=286131; -- 286131
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=395193; -- 395193
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=395194; -- 395194
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431549; -- 431549
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431550; -- 431550
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431565; -- 431565
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=395212; -- 395212
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=395213; -- 395213
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431570; -- 431570
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431571; -- 431571
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431572; -- 431572
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431573; -- 431573
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431574; -- 431574
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431575; -- 431575
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=431589; -- 431589
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=395236; -- 395236
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=395247; -- 395247
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=395248; -- 395248
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=286191; -- 286191
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=286192; -- 286192
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=286193; -- 286193
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=286195; -- 286195
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=286203; -- 286203
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=286204; -- 286204
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=431635; -- 431635
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=395297; -- 395297
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=431688; -- 431688
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=286286; -- 286286
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=286292; -- 286292
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=286309; -- 286309
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=286371; -- 286371
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=286373; -- 286373
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=286374; -- 286374
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=286375; -- 286375
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=286514; -- 286514
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=286528; -- 286528
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=286529; -- 286529
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=286530; -- 286530
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=286553; -- 286553
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=286779; -- 286779
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=432307; -- 432307
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396098; -- 396098
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396099; -- 396099
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396100; -- 396100
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396101; -- 396101
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396102; -- 396102
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396103; -- 396103
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=396110; -- 396110
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=396111; -- 396111
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=396112; -- 396112
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=396113; -- 396113
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=396114; -- 396114
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=396115; -- 396115
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=396116; -- 396116
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=432469; -- 432469
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=396117; -- 396117
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=396118; -- 396118
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=396119; -- 396119
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=396120; -- 396120
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=432498; -- 432498
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=432499; -- 432499
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=432500; -- 432500
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=396199; -- 396199
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=287410; -- 287410
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=432904; -- 432904
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=432906; -- 432906
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396702; -- 396702
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=433141; -- 433141
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=287730; -- 287730
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=433143; -- 433143
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396818; -- 396818
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396820; -- 396820
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=433198; -- 433198
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=433199; -- 433199
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=433262; -- 433262
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396922; -- 396922
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396927; -- 396927
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=396931; -- 396931
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=433307; -- 433307
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=288111; -- 288111
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=288112; -- 288112
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=288113; -- 288113
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=397201; -- 397201
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=433937; -- 433937
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=288549; -- 288549
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=288557; -- 288557
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=288709; -- 288709
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=288710; -- 288710
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=288734; -- 288734
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=288736; -- 288736
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=288777; -- 288777
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=288778; -- 288778
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=434202; -- 434202
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=288806; -- 288806
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=288852; -- 288852
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=288853; -- 288853
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=288854; -- 288854
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=288855; -- 288855
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=288861; -- 288861
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=434320; -- 434320
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=288971; -- 288971
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=398052; -- 398052
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=398065; -- 398065
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=289008; -- 289008
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=289013; -- 289013
UPDATE `quest_objectives` SET `VerifiedBuild`=62748 WHERE `ID`=289055; -- 289055
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=289060; -- 289060
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=289061; -- 289061
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=289063; -- 289063
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=289067; -- 289067
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=289071; -- 289071
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=289104; -- 289104
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=289127; -- 289127
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=434673; -- 434673
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=434674; -- 434674
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=434681; -- 434681
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=398340; -- 398340
UPDATE `quest_objectives` SET `VerifiedBuild`=62706 WHERE `ID`=289318; -- 289318
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=289319; -- 289319
UPDATE `quest_objectives` SET `VerifiedBuild`=62958 WHERE `ID`=289320; -- 289320
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=289321; -- 289321
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=289322; -- 289322
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=289323; -- 289323
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=289402; -- 289402
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=289403; -- 289403
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=434845; -- 434845
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=253088; -- 253088
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=434885; -- 434885
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=434889; -- 434889
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=434919; -- 434919
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=434920; -- 434920
UPDATE `quest_objectives` SET `VerifiedBuild`=62438 WHERE `ID`=434921; -- 434921
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=434928; -- 434928
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=434929; -- 434929
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=434930; -- 434930
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=434968; -- 434968
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=434992; -- 434992
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=435229; -- 435229
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=289848; -- 289848
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=289849; -- 289849
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=435267; -- 435267
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=289856; -- 289856
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=435268; -- 435268
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=289857; -- 289857
UPDATE `quest_objectives` SET `VerifiedBuild`=62680 WHERE `ID`=289858; -- 289858
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=289872; -- 289872
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=435301; -- 435301
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=435302; -- 435302
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=435303; -- 435303
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=435304; -- 435304
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=435305; -- 435305
UPDATE `quest_objectives` SET `VerifiedBuild`=62801 WHERE `ID`=435306; -- 435306
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=435308; -- 435308
UPDATE `quest_objectives` SET `VerifiedBuild`=63003 WHERE `ID`=289933; -- 289933
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=289938; -- 289938
UPDATE `quest_objectives` SET `VerifiedBuild`=62876 WHERE `ID`=290186; -- 290186
UPDATE `quest_objectives` SET `VerifiedBuild`=63163 WHERE `ID`=290294; -- 290294
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=435706; -- 435706
UPDATE `quest_objectives` SET `VerifiedBuild`=62493 WHERE `ID`=435934; -- 435934
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=254198; -- 254198
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=254326; -- 254326
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=436102; -- 436102
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=436103; -- 436103
UPDATE `quest_objectives` SET `VerifiedBuild`=63305 WHERE `ID`=254391; -- 254391


UPDATE `quest_visual_effect` SET `VerifiedBuild`=63305 WHERE (`Index`=0 AND `ID` IN (449393,431533,449217,449216,449215,451402,428708,429417,428333,428332,437319,436443,436103,436102,427035,423863,423862,423861,449559,436594,436592,436593,432500,432499,432498,430861,395248,395247,434968,394945,281821,289938,434674,434673,429425,283163,282717,437321,436447,436345,436344,392282,392281,391763,394279,390152,388998,388997,394723,394722,431727,435193,435118,289324,407698,429829,430648,341206,335630,285590,435267,428103,394318,394317,394316,341704,391719,394270,405186,431635,395194,395193,395291,336598,338211,393813,340116,419741,286286,408052,390411,390169,390162,390161,433143,433141,420032,420021,419913,419997,289104,449667,449666,420289,289127,338692,338668,445159,445158,436834,289882,289881,289880,280633,431690,429821,429879,333224,431575,431574,431573,431572,431571,431570,431565,431549,338312,339023,339022,289323,450575,430525,429835,430179,396199,337627,429616,336548,433112,433678,433676,285021,335976,333367,389665,336035,433262,283381,390059,396702,390071,282699,437514,436340,437513,434921,434920,434919,292571,336959,394904,419748,335343,448753,448752,286779,284674,337863,337811,337711,337710,433937,434202,282463,282462,335628,335627,435934,337757,419767,334334,431348,431347,431346,396931,430518,430481,430480,429598,407670,407667,407661,407669,407666,407658,407589,407588,421817,421788,287730,431589,432307,394677,394676,420413,391787,282153,434885,312149,423209,422642,422641,422632,391766,449612,449611,449613,285223,394710,394709,289322,338316,434930,434929,434928,443404,443403,335416,429695,388159,394868,333125,449942,340045,434889,419765,394299,394298,405418,405426,284723,284722,420311,420310,420308,420309,420428,420427,420307,419882,336039,336552,340437,337935,292360,292354,290816,452658,290999,387246,394286,394285,293134,293116,451304,451317,428874,428873,428872,419769,398340,282571,284226,283198,335434,335433,290863,281634,394864,341194,336345,387853,280043,281652)) OR (`Index`=3 AND `ID` IN (449217,428708,423863,395248,394945,429425,435118,394317,394316,390169,390161,420032,396199,433262,394904,431348,394868,405418)) OR (`Index`=2 AND `ID` IN (449217,451402,428708,423863,395248,394945,429425,435193,435118,394318,394317,394316,390169,390161,420032,333224,430179,396199,336035,433262,434921,394904,431348,421817,420413,282153,434885,449612,434930,394868,394299,394298,405418,387246,394286,394285,293134,451317)) OR (`Index`=1 AND `ID` IN (449217,449216,451402,428708,427035,423863,423862,395248,394945,429425,282717,436345,435193,435118,335630,394318,394317,394316,390169,390161,420032,445158,436834,289881,333224,431549,430179,396199,429616,336035,433262,434921,434920,394904,433937,335627,431348,431347,429598,421817,287730,420413,282153,434885,422641,449612,434930,434929,335416,394868,434889,394299,394298,405418,405426,420311,420310,420308,420309,420427,292360,292354,290816,290999,387246,394286,394285,293134,451317,419769)) OR (`Index`=14 AND `ID`=394945) OR (`Index`=13 AND `ID`=394945) OR (`Index`=12 AND `ID` IN (394945,435118)) OR (`Index`=11 AND `ID` IN (394945,435118)) OR (`Index`=10 AND `ID` IN (394945,435118,396199)) OR (`Index`=9 AND `ID` IN (394945,435118,396199)) OR (`Index`=8 AND `ID` IN (394945,435118,396199)) OR (`Index`=7 AND `ID` IN (394945,435118,396199)) OR (`Index`=6 AND `ID` IN (394945,435118,390161,396199)) OR (`Index`=5 AND `ID` IN (394945,435118,390169,390161,396199,394904,394868)) OR (`Index`=4 AND `ID` IN (394945,435118,390169,390161,396199,394904,394868,405418));
UPDATE `quest_visual_effect` SET `VerifiedBuild`=63163 WHERE (`Index`=0 AND `ID` IN (280043,292354,292360,290816,290999,290294,290186,420271,433937,434202,289104,420413,390065,434885,391782,389062,391967,391966,434968,432500,432499,432498,430861,391964,391963,394286,394285,289882,289881,289880,390152,431533,435193,435118,289322,338316,285590,282160,435267,391857,391744,394278,394318,394317,394316,430837,391719,394270,435934,295504,295503,337757,389057,398340,392279,284226,409083,387551,387550,407670,407667,407661,407669,407666,407658,407589,407588,335434,335433,282158,290863,333125,430011,430010,340045,391777,389060,428716,428715,286374,394864,434889,394299,394298,448753,448752,390411,390169,390162,390161,433143,433141,340437,337935,420311,420310,420308,420309,420428,420427,420307,419882,431727,428874,428873,428872,430525,429835,427035,423863,423862,423861,431589,432307,391928,437325,437000,437500,436998,392429,392436,394331,394300,282717,392282,392281,336061,422488,449559,421817,421788,283523,283502,283500,283390,336552,387460,336959,420277,386297,387246,434674,434673,293134,293116,445159,445158,436834,394891,449393,388998,388997,434845,283381,335874,333224,280583,341704,437514,436340,437513,334334,396199,449651,449650,449040,449028,289321,287730)) OR (`Index`=1 AND `ID` IN (292354,292360,290816,290999,433937,420413,434885,394286,394285,289881,435193,435118,394318,394317,394316,430837,428716,434889,394299,394298,390169,390161,420311,420310,420308,420309,420427,427035,423863,423862,392429,394331,394300,282717,421817,387246,293134,445158,436834,394891,333224,396199,287730)) OR (`Index`=2 AND `ID` IN (420413,434885,394286,394285,435193,435118,394318,394317,394316,430837,394299,394298,390169,390161,423863,392429,394331,394300,421817,387246,293134,394891,333224,396199)) OR (`Index`=12 AND `ID` IN (435118,394331)) OR (`Index`=11 AND `ID` IN (435118,394331,394300)) OR (`Index`=10 AND `ID` IN (435118,394331,394300,396199)) OR (`Index`=9 AND `ID` IN (435118,394331,394300,396199)) OR (`Index`=8 AND `ID` IN (435118,394331,394300,396199)) OR (`Index`=7 AND `ID` IN (435118,394331,394300,396199)) OR (`Index`=6 AND `ID` IN (435118,390161,394331,394300,394891,396199)) OR (`Index`=5 AND `ID` IN (435118,390169,390161,394331,394300,394891,396199)) OR (`Index`=4 AND `ID` IN (435118,390169,390161,394331,394300,394891,396199)) OR (`Index`=3 AND `ID` IN (435118,394317,394316,390169,390161,423863,392429,394331,394300,394891,396199)) OR (`Index`=22 AND `ID`=394331) OR (`Index`=21 AND `ID`=394331) OR (`Index`=20 AND `ID`=394331) OR (`Index`=19 AND `ID`=394331) OR (`Index`=18 AND `ID`=394331) OR (`Index`=17 AND `ID`=394331) OR (`Index`=16 AND `ID`=394331) OR (`Index`=15 AND `ID`=394331) OR (`Index`=14 AND `ID`=394331) OR (`Index`=13 AND `ID`=394331);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=63003 WHERE (`Index`=1 AND `ID` IN (428709,420413,429425,451317,435193,435118,434930,434929,451402,333224,394926,405674,430179,428719,429598,394299,394298,434681,390169,390161,427035,423863,423862,420032,445158,436834,289881,335627,420189,430914,430926,396199,338536,420552,420311,420310,420308,420309,420427,433937,394286,394285,394332,428708,333141,428716,429616,389671)) OR (`Index`=0 AND `ID` IN (428709,420413,391766,434674,434673,429425,451304,451317,338260,391763,394279,390152,394723,394722,394710,394709,435193,435118,284915,289320,434930,434929,434928,335305,443404,443403,451402,395316,395315,428874,428873,428872,333224,394926,391719,394270,282699,286912,409054,405675,405674,281824,430179,428719,337627,429598,449040,449028,431688,449942,340045,336548,283135,283134,419765,408052,394299,394298,434681,390411,390169,390162,390161,427035,423863,423862,423861,335169,335165,420032,420021,419913,419997,445159,445158,436834,289882,289881,289880,335628,335627,434845,295286,295285,429829,430648,335874,420189,289933,450575,430914,430926,430920,396199,409083,283523,283502,283500,283390,338536,430893,430890,333125,289321,420552,406640,280585,431589,432307,420311,420310,420308,420309,420428,420427,420307,419882,285041,433937,434202,391782,389062,394286,394285,392282,392281,449393,431727,429821,429879,394332,428708,391927,430525,429835,389057,449651,449650,407670,407667,407661,407669,407666,407658,407589,407588,292571,386633,342119,391777,389060,333141,428716,428715,429616,391781,389061,389671,391911,391908,430205,429670)) OR (`Index`=2 AND `ID` IN (420413,429425,451317,435193,435118,434930,451402,333224,394926,430179,428719,394299,394298,390169,390161,423863,420032,430914,396199,394286,394285,394332,428708,333141)) OR (`Index`=3 AND `ID` IN (429425,435118,394926,428719,390169,390161,423863,420032,430914,396199,394332,428708)) OR (`Index`=12 AND `ID` IN (435118,394332)) OR (`Index`=11 AND `ID` IN (435118,394332)) OR (`Index`=10 AND `ID` IN (435118,396199,394332)) OR (`Index`=9 AND `ID` IN (435118,396199,394332)) OR (`Index`=8 AND `ID` IN (435118,396199,394332)) OR (`Index`=7 AND `ID` IN (435118,394926,396199,394332)) OR (`Index`=6 AND `ID` IN (435118,394926,428719,390161,396199,394332)) OR (`Index`=5 AND `ID` IN (435118,394926,428719,390169,390161,396199,394332)) OR (`Index`=4 AND `ID` IN (435118,394926,428719,390169,390161,396199,394332)) OR (`Index`=13 AND `ID`=394332);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=62876 WHERE (`Index`=1 AND `ID` IN (420797,420846,420811,422641,282717,335630,431549,420470,286309,338536,389671,434681,420032,289881,429425,430837,405674,430914,430926,433937,335416,333224,421817,420349,293134,333390,292360,292354,290816,290999)) OR (`Index`=0 AND `ID` IN (420797,420846,420811,420774,449667,449666,423209,422642,422641,422632,282717,280633,283381,341206,335630,284907,352810,352782,431575,431574,431573,431572,431571,431570,431565,431549,420470,286309,342195,431635,285690,285689,289319,420279,387314,337420,337419,430678,430677,430676,333107,336598,335434,335433,283523,283502,283500,283390,338536,389671,408052,434681,286371,431589,432307,450575,420032,420021,419913,419997,289127,289882,289881,289880,429425,429829,430648,430837,341704,409054,405675,405674,430914,430926,430920,398340,337627,430893,430890,406638,340045,387460,336548,390072,337078,333125,461315,461265,433937,434202,284915,335305,335874,335416,390062,333224,280583,405186,404431,396931,407670,407667,407661,407669,407666,407658,407589,407588,449040,449028,421817,421788,436594,436592,436593,420349,293134,293116,333390,290186,292360,341344,341343,292354,290816,452658,290999)) OR (`Index`=3 AND `ID` IN (420470,420032,429425,430914,420349)) OR (`Index`=2 AND `ID` IN (420470,286309,420032,429425,430837,430914,333224,421817,420349,293134,333390));
UPDATE `quest_visual_effect` SET `VerifiedBuild`=62748 WHERE (`Index`=0 AND `ID` IN (289318,394677,394676,391787,392282,392281,390152,395316,395315,391744,394278,394318,394317,394316,390071,391719,394270,435934,437514,436340,437513,395291,392279,387460,390411,390169,390162,390161,293134,293116,451304,451317,449559,449393,435193,435118,431348,431347,431346,430518,430481,430480,429695,428103,295504,295503,337384,338536,338211,341206,335630,286375,285037,283922,283163,394945,420349,396199,404431,461315,461265,420032,420021,419913,419997,420311,420310,420308,420309,420428,420427,420307,419882,452658,290999,289127,420413,394300,395248,395247,335976,288778,280633,433262,407698,449217,449216,449215,385760,352922,352916,352915,451402,391145,338383,395194,395193,352741,283198,292658,434921,434920,434919,336552,290863,287730,285072,390042,394864,336548,420277,292354,290816)) OR (`Index`=2 AND `ID` IN (394318,394317,394316,390169,390161,293134,451317,435193,435118,431348,394945,420349,396199,420032,420413,394300,395248,433262,449217,451402,391145,434921)) OR (`Index`=1 AND `ID` IN (394318,394317,394316,390169,390161,293134,451317,435193,435118,431348,431347,338536,335630,394945,420349,396199,420032,420311,420310,420308,420309,420427,290999,420413,394300,395248,433262,449217,449216,451402,391145,434921,434920,287730,292354,290816)) OR (`Index`=3 AND `ID` IN (394317,394316,390169,390161,435118,431348,394945,420349,396199,420032,394300,395248,433262,449217)) OR (`Index`=5 AND `ID` IN (390169,390161,435118,394945,396199,394300)) OR (`Index`=4 AND `ID` IN (390169,390161,435118,394945,396199,394300)) OR (`Index`=6 AND `ID` IN (390161,435118,394945,396199,394300)) OR (`Index`=12 AND `ID` IN (435118,394945)) OR (`Index`=11 AND `ID` IN (435118,394945,394300)) OR (`Index`=10 AND `ID` IN (435118,394945,396199,394300)) OR (`Index`=9 AND `ID` IN (435118,394945,396199,394300)) OR (`Index`=8 AND `ID` IN (435118,394945,396199,394300)) OR (`Index`=7 AND `ID` IN (435118,394945,396199,394300)) OR (`Index`=14 AND `ID`=394945) OR (`Index`=13 AND `ID`=394945);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=62706 WHERE (`Index`=0 AND `ID` IN (283523,283502,283500,283390,289104,392429,392436,391787,394300,391967,391966,391766,432500,432499,432498,430861,449617,394286,394285,338355,392282,392281,390152,435193,435118,284915,434930,434929,434928,407546,407556,407521,443404,443403,451402,391857,391927,420189,391744,394278,430837,391930,391785,389480,338573,338565,449559,337384,430678,430677,430676,421817,421788,338536,338211,292571,430011,430010,449942,420552,333141,283135,283134,335343,408052,394299,394298,448753,448752,289318,390411,390169,390162,390161,391783,389063,420311,420310,420308,420309,420428,420427,420307,419882)) OR (`Index`=3 AND `ID` IN (392429,394300,435118,390169,390161)) OR (`Index`=2 AND `ID` IN (392429,394300,394286,394285,435193,435118,434930,451402,430837,421817,333141,394299,394298,390169,390161)) OR (`Index`=1 AND `ID` IN (392429,394300,394286,394285,435193,435118,434930,434929,451402,420189,430837,391785,389480,421817,338536,420552,333141,394299,394298,390169,390161,420311,420310,420308,420309,420427)) OR (`Index`=11 AND `ID` IN (394300,435118)) OR (`Index`=10 AND `ID` IN (394300,435118)) OR (`Index`=9 AND `ID` IN (394300,435118)) OR (`Index`=8 AND `ID` IN (394300,435118)) OR (`Index`=7 AND `ID` IN (394300,435118)) OR (`Index`=6 AND `ID` IN (394300,435118,390161)) OR (`Index`=5 AND `ID` IN (394300,435118,390169,390161)) OR (`Index`=4 AND `ID` IN (394300,435118,390169,390161)) OR (`Index`=12 AND `ID`=435118);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=62493 WHERE (`Index`=0 AND `ID` IN (432500,432499,432498,430861,430837,420413,434968,282658,449617,281821,289872,282717,337628,386631,385354,390059,451402,435267,387247,338312,435706,405186,435934,286912,431348,431347,431346,428333,428332,396199,449559,428719,449040,449028,338536,393813,340116,286292,287730,431688,342093,449942,340045,286375,429616,336548,335343,434681,405418,405426,433143,433141,286779,284674,420283,288778,338355,394891,283922,407546,407556,407521,449217,449216,449215,428874,428873,428872,422488,390071,285765,285764,284226,285072,390042,281634,336959,283135,283134,289104,333390,430452,431575,431574,431573,431572,431571,431570,431565,431549,429598,433937,434202,420797,420846,420811,420774,449667,449666,285578,285577,293134,293116,282120,420470,339023,339022,341704,398340,407670,407667,407661,407669,407666,407658,407589,407588,285000,286373,389671,420311,420310,420308,420309,420428,420427,420307,419882,391928,394331,289127,391766,394286,394285,445159,445158,436834,390152,433262,431690,435193,435118,338316,289324,429829,430648,335874,391744,394278,394318,394317,394316,391719,394270,430914,430926,430920,392279,409083,434921,434920,434919,430893,430890,391922,391777,389060,333141,280585,394864,391781,389061,390411,390169,390162,390161,391783,389063,433112,433678,433676,391911,391908,420032,420021,419913,419997,461315,461265,281597,333125,337757,336039,335416,406638,419741,405633,405634,452658,341344,341343,292360,292354,290999,290816,395145,387926,385734,385721)) OR (`Index`=2 AND `ID` IN (430837,420413,451402,435706,431348,396199,428719,405418,394891,449217,333390,293134,420470,394331,394286,394285,433262,435193,435118,394318,394317,394316,430914,434921,333141,390169,390161,420032,405634)) OR (`Index`=1 AND `ID` IN (430837,420413,282717,451402,435706,431348,431347,396199,428719,338536,287730,429616,434681,405418,405426,394891,449217,449216,333390,431549,429598,433937,420797,420846,420811,293134,420470,389671,420311,420310,420308,420309,420427,394331,394286,394285,445158,436834,433262,435193,435118,394318,394317,394316,430914,430926,434921,434920,333141,390169,390161,420032,335416,405634,292360,292354,290999,290816)) OR (`Index`=3 AND `ID` IN (435706,431348,396199,428719,405418,394891,449217,420470,394331,433262,435118,394317,394316,430914,390169,390161,420032,405634)) OR (`Index`=10 AND `ID` IN (396199,394331,435118)) OR (`Index`=9 AND `ID` IN (396199,394331,435118)) OR (`Index`=8 AND `ID` IN (396199,394331,435118)) OR (`Index`=7 AND `ID` IN (396199,394331,435118)) OR (`Index`=6 AND `ID` IN (396199,428719,394891,394331,435118,390161,405634)) OR (`Index`=5 AND `ID` IN (396199,428719,394891,394331,435118,390169,390161,405634)) OR (`Index`=4 AND `ID` IN (396199,428719,405418,394891,394331,435118,390169,390161,405634)) OR (`Index`=22 AND `ID`=394331) OR (`Index`=21 AND `ID`=394331) OR (`Index`=20 AND `ID`=394331) OR (`Index`=19 AND `ID`=394331) OR (`Index`=18 AND `ID`=394331) OR (`Index`=17 AND `ID`=394331) OR (`Index`=16 AND `ID`=394331) OR (`Index`=15 AND `ID`=394331) OR (`Index`=14 AND `ID`=394331) OR (`Index`=13 AND `ID`=394331) OR (`Index`=12 AND `ID` IN (394331,435118)) OR (`Index`=11 AND `ID` IN (394331,435118));
UPDATE `quest_visual_effect` SET `VerifiedBuild`=62801 WHERE (`Index`=0 AND `ID` IN (282463,282462,337078,293134,293116,429425,283163,394891,422647,433262,429829,430648,449217,449216,449215,451402,286309,431635,289319,295504,295503,419767,409054,405675,405674,430914,430926,430920,388159,449559,336598,284226,283523,283502,283500,283390,434921,434920,434919,290863,430893,430890,333125,285072,434681,420349,431589,432307,420032,420021,419913,419997)) OR (`Index`=2 AND `ID` IN (293134,429425,394891,433262,449217,451402,286309,430914,434921,420349,420032)) OR (`Index`=1 AND `ID` IN (293134,429425,394891,422647,433262,449217,449216,451402,286309,405674,430914,430926,434921,434920,434681,420349,420032)) OR (`Index`=3 AND `ID` IN (429425,394891,433262,449217,430914,420349,420032)) OR (`Index`=6 AND `ID`=394891) OR (`Index`=5 AND `ID`=394891) OR (`Index`=4 AND `ID`=394891);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=62680 WHERE (`Index`=1 AND `ID` IN (433937,392429,293134,436345,394891,434930,434929,451402,333390,430837,431348,431347,428719,421817,429616,434681,420349)) OR (`Index`=0 AND `ID` IN (433937,434202,392429,392436,434968,432500,432499,432498,430861,449617,281821,293134,293116,437321,436447,436345,436344,289856,394891,434930,434929,434928,443404,443403,451402,389550,333390,435267,390062,338312,430837,435934,431348,431347,431346,428333,428332,449559,396931,333107,428719,407670,407667,407661,407669,407666,407658,407589,407588,421817,421788,290863,393813,340116,286292,431688,449942,429616,335343,434681,448753,448752,420349,433143,433141,286779,284674)) OR (`Index`=3 AND `ID` IN (392429,394891,431348,428719,420349)) OR (`Index`=2 AND `ID` IN (392429,293134,394891,434930,451402,333390,430837,431348,428719,421817,420349)) OR (`Index`=6 AND `ID` IN (394891,428719)) OR (`Index`=5 AND `ID` IN (394891,428719)) OR (`Index`=4 AND `ID` IN (394891,428719));
UPDATE `quest_visual_effect` SET `VerifiedBuild`=62438 WHERE (`Index`=0 AND `ID` IN (333125,437325,437000,437500,436998,287410,288971,394331,420289,281821,392282,392281,388998,388997,284741,281859,281804,433262,407546,407556,407521,429829,430648,451402,391930,391785,389480,419769,335149,335146,428333,428332,389057,284770,394868,428719,337863,337811,337711,337710,434921,434920,434919,336552,430893,430890,391770,389059,395213,395212,391781,389061,420311,420310,420308,420309,420428,420427,420307,419882,337757,395248,395247,335976,284806,394723,394722,396702,389550,333390,391145,390071,387314,283198,292571,405418,405426,340437,337935,391782,389062,391967,391966,289127,391927,419767,396931,420349,391911,391908)) OR (`Index`=22 AND `ID`=394331) OR (`Index`=21 AND `ID`=394331) OR (`Index`=20 AND `ID`=394331) OR (`Index`=19 AND `ID`=394331) OR (`Index`=18 AND `ID`=394331) OR (`Index`=17 AND `ID`=394331) OR (`Index`=16 AND `ID`=394331) OR (`Index`=15 AND `ID`=394331) OR (`Index`=14 AND `ID`=394331) OR (`Index`=13 AND `ID`=394331) OR (`Index`=12 AND `ID`=394331) OR (`Index`=11 AND `ID`=394331) OR (`Index`=10 AND `ID`=394331) OR (`Index`=9 AND `ID`=394331) OR (`Index`=8 AND `ID`=394331) OR (`Index`=7 AND `ID`=394331) OR (`Index`=6 AND `ID` IN (394331,428719)) OR (`Index`=5 AND `ID` IN (394331,394868,428719)) OR (`Index`=4 AND `ID` IN (394331,394868,428719,405418)) OR (`Index`=3 AND `ID` IN (394331,433262,394868,428719,395248,405418,420349)) OR (`Index`=2 AND `ID` IN (394331,433262,451402,394868,428719,434921,395248,333390,391145,405418,420349)) OR (`Index`=1 AND `ID` IN (394331,433262,451402,391785,389480,419769,394868,428719,434921,434920,420311,420310,420308,420309,420427,395248,333390,391145,405418,405426,420349));
UPDATE `quest_visual_effect` SET `VerifiedBuild`=62958 WHERE (`Index`=1 AND `ID` IN (428709,420413,429425,451317,435193,435118,434930,434929,451402,333224,394926,405674,430179,428719,429598,394299,394298,434681,390169,390161,427035,423863,423862,420032)) OR (`Index`=0 AND `ID` IN (428709,420413,312149,391766,434674,434673,429425,451304,451317,338260,391763,394279,390152,394723,394722,394710,394709,435193,435118,284915,289320,434930,434929,434928,335305,443404,443403,451402,395316,395315,428874,428873,428872,333224,394926,391719,394270,282699,286912,409054,405675,405674,281824,430179,428719,337627,429598,449040,449028,431688,449942,340045,336548,283135,283134,419765,408052,394299,394298,434681,390411,390169,390162,390161,427035,423863,423862,423861,335169,335165,420032,420021,419913,419997)) OR (`Index`=2 AND `ID` IN (420413,429425,451317,435193,435118,434930,451402,333224,394926,430179,428719,394299,394298,390169,390161,423863,420032)) OR (`Index`=3 AND `ID` IN (429425,435118,394926,428719,390169,390161,423863,420032)) OR (`Index`=12 AND `ID`=435118) OR (`Index`=11 AND `ID`=435118) OR (`Index`=10 AND `ID`=435118) OR (`Index`=9 AND `ID`=435118) OR (`Index`=8 AND `ID`=435118) OR (`Index`=7 AND `ID` IN (435118,394926)) OR (`Index`=6 AND `ID` IN (435118,394926,428719,390161)) OR (`Index`=5 AND `ID` IN (435118,394926,428719,390169,390161)) OR (`Index`=4 AND `ID` IN (435118,394926,428719,390169,390161));


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=63305 WHERE (`Idx`=0 AND `QuestID` IN (82679,6081));
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=63163 WHERE (`QuestID`=82679 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=63003 WHERE (`Idx`=0 AND `QuestID` IN (82679,61607));
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=62876 WHERE (`Idx`=0 AND `QuestID` IN (82679,61609,53406));
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=62706 WHERE (`QuestID`=82679 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=62493 WHERE (`Idx`=0 AND `QuestID` IN (82679,90781,61609,53406));
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=62801 WHERE (`QuestID`=82679 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=62748 WHERE (`QuestID`=82679 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=62680 WHERE (`QuestID`=90781 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=62958 WHERE (`QuestID`=82679 AND `Idx`=0);


UPDATE `quest_treasure_pickers` SET `OrderIndex`=1 WHERE (`QuestID`=90781 AND `TreasurePickerID`=4133); -- Sparks of War: K'aresh
UPDATE `quest_treasure_pickers` SET `OrderIndex`=0 WHERE (`QuestID`=84856 AND `TreasurePickerID`=3977); -- Where the Void Gathers

DELETE FROM `gameobject_template` WHERE `entry` IN (529883 /*Challenge Mode - Start Door v2 (Dome 1.75)*/, 463977 /*Hearty Feast of the Midnight Masquerade*/, 292874 /*Altar of the Abyss*/, 457168 /*Bar Tab Barrel*/, 564836 /*Phaseblood Potion*/, 564839 /*Mercenary Contract*/, 564837 /*Hunger From Beyond*/, 578955 /*|cff0070ddFlickering Spoils*/, 503871 /*|cff889D9DNemesis Strongbox*/, 373465 /*Forgotten Gravestone*/, 543701 /*Routing Station*/, 543700 /*Secure Storage*/, 543394 /*11FX_Raid3_Automaton_Arcane_Sieve*/, 543393 /*11FX_Raid3_Automaton_Arcane_Sieve*/, 413882 /*Ironclaw Seam*/, 549968 /*Serving Table*/, 548718 /*Prep Table*/, 532193 /*Cutting Board*/, 549969 /*Serving Table*/, 549348 /*Stove*/, 549973 /*Salt*/, 549350 /*Stove*/, 549349 /*Brew Prep Table*/, 527133 /*DNT - campfire*/, 526951 /*Challenger's Cache*/, 469491 /*Challenge Mode - Start Door v2 (Dome 2.25)*/, 499099 /*Entropic Egg*/, 531961 /*Untethered Xy'bucha*/, 529537 /*Efrat's Forgotten Bulwark*/, 516626 /*Phase-Lost Pocket-Storage*/, 558106 /*Boulder*/, 465681 /*Rostrum of Transformation*/, 494120 /*Stone Bench*/, 504404 /*Phase-Lost Platform*/, 459375 /*Door*/, 457183 /*Bar Tab Barrel*/, 473934 /*Property of Cooktholomew*/, 562180 /*Force Field*/, 476259 /*Broker Crate*/, 417109 /*Dragon Saddle*/, 417360 /*Race Flag Overhead*/, 499292 /*[DNT] Broker Cage - Round*/, 499105 /*[DNT] Broker Cage*/, 499296 /*Unchecked Cargo*/, 526979 /*Challenger's Cache*/, 526972 /*Challenger's Cache*/, 526980 /*Challenger's Cache*/, 409990 /*Door*/, 409974 /*Door*/, 409984 /*Door*/, 409973 /*Door*/, 409968 /*Timeways*/, 409967 /*Timeways*/, 529529 /*Toy Duck*/, 409987 /*Timeways*/, 528335 /*Eterni-tea*/, 529750 /*Magnifying Glass*/, 529160 /*Portal to Dornogal*/, 409969 /*Timeways*/, 409995 /*Timeways*/, 409998 /*Timeways*/, 529374 /*Dragon Figurine*/, 409993 /*Timeways*/, 409994 /*Timeways*/, 409985 /*Timeways*/, 381115 /*Dragon Book Pile*/, 409992 /*Timeways*/, 409971 /*Timeways*/, 409970 /*Timeways*/, 409976 /*Timeways*/, 409975 /*Infinite Oathstone*/, 381114 /*Dragon Book Pile*/, 409980 /*Timeways*/, 409991 /*Timeways*/, 409988 /*Timeways*/, 409978 /*Timeways*/, 409979 /*Timeways*/, 465300 /*Thalen Songweaver's Notes*/, 465295 /*Medivh's Karazhan Schematics*/, 465294 /*Antonidas' Introduction to Arcane Magic*/, 465279 /*Arcane Box*/, 446146 /*Recovered Nightfall Relics*/, 465580 /*Light Oil*/, 465551 /*Crystal*/, 465505 /*Arathi Airship*/, 465497 /*Crystal*/, 465588 /*Bench*/, 465576 /*Chair*/, 465527 /*Chair*/, 465511 /*Chair*/, 465506 /*Bench*/, 465498 /*Bench*/, 465490 /*Bench*/, 465472 /*Bench*/, 465562 /*Chair*/, 465468 /*Bench*/, 465585 /*Bench*/, 465586 /*Bench*/, 465513 /*Bench*/, 465571 /*Bench*/, 465556 /*Chair*/, 465547 /*Bench*/, 465494 /*Chair*/, 457086 /*Mereldar Holdouts*/, 465520 /*Mailbox*/, 465526 /*Bench*/, 465499 /*Bench*/, 465483 /*Bench*/, 465481 /*Bench*/, 465480 /*Bench*/, 465469 /*Bench*/, 465570 /*Bench*/, 465566 /*Bench*/, 465558 /*Bench*/, 465553 /*Oil*/, 465508 /*Bench*/, 465482 /*Bench*/, 457085 /*Mereldar Holdouts*/, 465575 /*Bench*/, 465560 /*Bench*/, 465542 /*Bench*/, 465523 /*Bench*/, 465514 /*Bench*/, 465568 /*Bench*/, 452633 /*Barricade*/, 457084 /*Mereldar Holdouts*/, 452632 /*Barricade*/, 467505 /*The Dawnbreaker*/, 469316 /*Respawn Location*/, 409355 /*The Dawnbreaker*/, 465569 /*Chair*/, 465541 /*Chair*/, 465524 /*Bench*/, 465492 /*Bench*/, 465488 /*Chair*/, 465557 /*Bench*/, 465555 /*Bench*/, 465504 /*Bench*/, 465485 /*Bench*/, 465476 /*Bench*/, 469315 /*Respawn Location*/, 428542 /*Collision*/, 409468 /*Ambush Airship B*/, 409366 /*Ambush Airship A*/, 439338 /*Arathi Supplies*/, 552255 /*Soup*/, 572915 /*Particle 2 [DNT]*/, 552251 /*Particle 2 [DNT]*/, 572913 /*Particle 1 [DNT]*/, 552250 /*Particle 1 [DNT]*/, 552253 /*Pretzel*/, 549972 /*Dough*/, 549971 /*Dough*/, 455509 /*|cff1EFF00Sturdy Chest*/, 444045 /*East Wing Door 02*/, 455488 /*|cff1EFF00Sturdy Chest*/, 444043 /*West Door 03*/, 444037 /*East Door 1*/, 444046 /*East Wing Door 03*/, 455579 /*|cff1EFF00Sturdy Chest*/, 444036 /*West door 01*/, 444044 /*West Door 04*/, 444041 /*West Door 05*/, 455568 /*|cff1EFF00Sturdy Chest*/, 444038 /*Central Door*/, 432983 /*Treasure Room Door*/, 444039 /*Door03*/, 444040 /*East Wing Door 05*/, 444042 /*West Door 02*/, 444047 /*East Wing Door 04*/, 437053 /*Nerubian Door*/, 449716 /*Web Wall*/, 433524 /*Generic Pedestal*/, 457176 /*Bar Tab Barrel*/, 567703 /*Curio Container*/, 449583 /*Dead Beast*/, 455557 /*|cff1EFF00Sturdy Chest*/, 455589 /*|cff1EFF00Sturdy Chest*/, 456183 /*Explorers' League Rope*/, 455493 /*|cff1EFF00Sturdy Chest*/, 455574 /*|cff1EFF00Sturdy Chest*/, 421190 /*Rock Wall*/, 564838 /*Sandstorm*/, 384762 /*Ancient Skeleton*/, 398728 /*Chair*/, 398727 /*Chair*/, 398726 /*Chair*/, 398725 /*Chair*/, 398724 /*Chair*/, 398723 /*Chair*/, 398722 /*Chair*/, 398721 /*Chair*/, 398720 /*Chair*/, 398719 /*Chair*/, 548010 /*Phaseblade of the Void Marches*/, 338224 /*Cache of the Fire Lord*/, 417363 /*Wyvern Roost*/, 558112 /*The Facets of K'aresh*/, 505415 /*Uncracked Cold Ones*/, 526977 /*Challenger's Cache*/, 558117 /*I Have Become Void!*/, 558365 /*Shadowguard Blade*/, 558108 /*Multiversal Energy Dynamics and the Murmuration Paradox*/, 467175 /*Coalesced Void Energy*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(529883, 0, 95195, 'Challenge Mode - Start Door v2 (Dome 1.75)', '', '', '', 1.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Challenge Mode - Start Door v2 (Dome 1.75)
(463977, 22, 93678, 'Hearty Feast of the Midnight Masquerade', 'interact', '', '', 0.800000011920928955, 454094, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Hearty Feast of the Midnight Masquerade
(292874, 8, 50326, 'Altar of the Abyss', '', '', '', 0.25, 1953, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 63305), -- Altar of the Abyss
(457168, 2, 56590, 'Bar Tab Barrel', '', '', '', 0.5, 0, 27692, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 298, 63305), -- Bar Tab Barrel
(564836, 56, 9510, 'Phaseblood Potion', '', '', '', 1.5, 0, 88053, 0, 822, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- Phaseblood Potion
(564839, 56, 9510, 'Mercenary Contract', '', '', '', 1.5, 0, 70239, 0, 822, 73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- Mercenary Contract
(564837, 56, 9510, 'Hunger From Beyond', '', '', '', 1.5, 0, 66692, 0, 822, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- Hunger From Beyond
(578955, 3, 7235, '|cff0070ddFlickering Spoils', 'lootall', '', '', 1, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 133722, 0, 0, 0, 1, 0, 2677, 63305), -- |cff0070ddFlickering Spoils
(503871, 3, 56773, '|cff889D9DNemesis Strongbox', 'lootall', '', '', 0.800000011920928955, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 130395, 0, 0, 0, 1, 0, 2677, 63305), -- |cff889D9DNemesis Strongbox
(373465, 64, 49194, 'Forgotten Gravestone', 'inspect', '', '', 1, 2, 0, 39860, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Forgotten Gravestone
(543701, 0, 103932, 'Routing Station', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Routing Station
(543700, 0, 103932, 'Secure Storage', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Secure Storage
(543394, 5, 105716, '11FX_Raid3_Automaton_Arcane_Sieve', '', '', '', 0.55999988317489624, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- 11FX_Raid3_Automaton_Arcane_Sieve
(543393, 5, 105716, '11FX_Raid3_Automaton_Arcane_Sieve', '', '', '', 0.55999988317489624, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- 11FX_Raid3_Automaton_Arcane_Sieve
(413882, 50, 89950, 'Ironclaw Seam', '', '', '', 1, 3681, 120476, 0, 0, 90, 100, 30, 0, 0, 0, 0, 0, 0, 1, 427983, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2734, 63305), -- Ironclaw Seam
(549968, 5, 56640, 'Serving Table', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Serving Table
(548718, 10, 56640, 'Prep Table', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1240502, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141338, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Prep Table
(532193, 5, 96937, 'Cutting Board', '', '', '', 0.5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Cutting Board
(549969, 5, 56640, 'Serving Table', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Serving Table
(549348, 3, 48901, 'Stove', 'interact', '', '', 1, 2160, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 141335, 0, 0, 0, 0, 0, 0, 0, 0, 1240503, 0, 0, 0, 133746, 1, 0, 0, 0, 0, 2068, 63305), -- Stove
(549973, 10, 29729, 'Salt', '', '', '', 0.5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1240505, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141367, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Salt
(549350, 10, 48901, 'Stove', 'interact', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1240474, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141334, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2068, 63305), -- Stove
(549349, 10, 56640, 'Brew Prep Table', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1240480, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141339, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Brew Prep Table
(527133, 5, 75250, 'DNT - campfire', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- DNT - campfire
(526951, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 3054, 0, 1, 0, 0, 132336, 0, 5, 132337, 0, 0, 1279, 62876), -- Challenger's Cache
(469491, 0, 95195, 'Challenge Mode - Start Door v2 (Dome 2.25)', '', '', '', 2.25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Challenge Mode - Start Door v2 (Dome 2.25)
(499099, 3, 83570, 'Entropic Egg', 'questinteract', '', '', 0.400000005960464477, 4148, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 129307, 1, 0, 0, 0, 0, 3008, 62748), -- Entropic Egg
(531961, 3, 92922, 'Untethered Xy\'bucha', '', 'Collecting', '', 1.5, 1969, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 257503, 0, 0, 34450, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 132895, 0, 0, 0, 0, 0, 3008, 62748), -- Untethered Xy'bucha
(529537, 3, 105606, 'Efrat\'s Forgotten Bulwark', '', 'Collecting', '', 1, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 19676, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1244044, 0, 0, 6921, 132755, 0, 0, 0, 0, 0, 3008, 62748), -- Efrat's Forgotten Bulwark
(516626, 50, 55860, 'Phase-Lost Pocket-Storage', '', '', '', 0.75, 1690, 133763, 0, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 1244044, 0, 0, 6768, 40, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3008, 62748), -- Phase-Lost Pocket-Storage
(558106, 5, 47594, 'Boulder', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62748), -- Boulder
(465681, 5, 89555, 'Rostrum of Transformation', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2832, 62706), -- Rostrum of Transformation
(494120, 7, 622, 'Stone Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Stone Bench
(504404, 5, 99811, 'Phase-Lost Platform', '', '', '', 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3008, 62493), -- Phase-Lost Platform
(459375, 0, 85630, 'Door', '', '', '', 1.25, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Door
(457183, 2, 56590, 'Bar Tab Barrel', '', '', '', 0.5, 0, 27701, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 298, 63305), -- Bar Tab Barrel
(473934, 3, 334, 'Property of Cooktholomew', 'openhandglow', '', '', 1, 3485, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 129429, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 128613, 0, 0, 0, 0, 0, 888, 63305), -- Property of Cooktholomew
(562180, 0, 68422, 'Force Field', '', '', '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Force Field
(476259, 10, 101718, 'Broker Crate', 'questinteract', 'Destroying', '', 0.300000011920928955, 2741, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1221333, 0, 0, 0, 24585, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Broker Crate
(417109, 5, 77592, 'Dragon Saddle', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2796, 62876), -- Dragon Saddle
(417360, 5, 11183, 'Race Flag Overhead', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2796, 62876), -- Race Flag Overhead
(499292, 5, 65015, '[DNT] Broker Cage - Round', '', '', '', 0.400000005960464477, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62748), -- [DNT] Broker Cage - Round
(499105, 5, 66588, '[DNT] Broker Cage', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62748), -- [DNT] Broker Cage
(499296, 10, 71411, 'Unchecked Cargo', 'questinteract', '', '', 1, 3930, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62748), -- Unchecked Cargo
(526979, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 2381, 0, 1, 0, 0, 132377, 0, 5, 132337, 0, 0, 1279, 62680), -- Challenger's Cache
(526972, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 2437, 0, 1, 0, 0, 132365, 0, 5, 132337, 0, 0, 1279, 62493), -- Challenger's Cache
(526980, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 3109, 0, 1, 0, 0, 132383, 0, 5, 132337, 0, 0, 1279, 62493), -- Challenger's Cache
(409990, 0, 80936, 'Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Door
(409974, 0, 79793, 'Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Door
(409984, 0, 79793, 'Door', '', '', '', 1.220000028610229492, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Door
(409973, 0, 79793, 'Door', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Door
(409968, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409967, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(529529, 10, 79619, 'Toy Duck', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Toy Duck
(409987, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(528335, 22, 74456, 'Eterni-tea', '', '', '', 0.5, 1232236, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Eterni-tea
(529750, 10, 76897, 'Magnifying Glass', '', '', '', 0.75, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Magnifying Glass
(529160, 22, 83738, 'Portal to Dornogal', '', '', '', 1, 462618, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Portal to Dornogal
(409969, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409995, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409998, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(529374, 10, 76402, 'Dragon Figurine', '', '', '', 0.5, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Dragon Figurine
(409993, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409994, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409985, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(381115, 5, 76810, 'Dragon Book Pile', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Dragon Book Pile
(409992, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409971, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409970, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409976, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409975, 10, 80406, 'Infinite Oathstone', '', '', '', 1, 0, 0, 0, 2147483647, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Infinite Oathstone
(381114, 5, 76809, 'Dragon Book Pile', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Dragon Book Pile
(409980, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409991, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409988, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409978, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(409979, 10, 82117, 'Timeways', '', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Timeways
(465300, 3, 29137, 'Thalen Songweaver\'s Notes', 'questinteract', 'Collecting', '', 1, 2124, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127716, 0, 0, 0, 0, 0, 2462, 62438), -- Thalen Songweaver's Notes
(465295, 3, 77820, 'Medivh\'s Karazhan Schematics', 'questinteract', 'Collecting', '', 1, 2124, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127715, 0, 0, 0, 0, 0, 2462, 62438), -- Medivh's Karazhan Schematics
(465294, 3, 25779, 'Antonidas\' Introduction to Arcane Magic', 'questinteract', 'Collecting', '', 0.800000011920928955, 2124, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127714, 0, 0, 0, 0, 0, 2462, 62438), -- Antonidas' Introduction to Arcane Magic
(465279, 3, 29694, 'Arcane Box', 'questinteract', 'Collecting', '', 1.5, 2124, 127712, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2462, 62438), -- Arcane Box
(446146, 3, 89117, 'Recovered Nightfall Relics', 'questinteract', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2839, 0, 1, 0, 0, 123765, 0, 2, 131232, 0, 0, 2718, 62438), -- Recovered Nightfall Relics
(465580, 5, 89640, 'Light Oil', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Light Oil
(465551, 1, 88671, 'Crystal', '', '', '', 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 5703, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Crystal
(465505, 43, 84768, 'Arathi Airship', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Arathi Airship
(465497, 5, 88671, 'Crystal', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Crystal
(465588, 7, 87769, 'Bench', '', '', '', 1.10000002384185791, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465576, 7, 88246, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chair
(465527, 7, 88246, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chair
(465511, 7, 88246, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chair
(465506, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465498, 7, 87769, 'Bench', '', '', '', 1.10000002384185791, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465490, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465472, 7, 87769, 'Bench', '', '', '', 1.10000002384185791, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465562, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chair
(465468, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465585, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465586, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465513, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465571, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465556, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chair
(465547, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465494, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chair
(457086, 10, 9147, 'Mereldar Holdouts', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Mereldar Holdouts
(465520, 19, 84996, 'Mailbox', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Mailbox
(465526, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465499, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465483, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465481, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465480, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465469, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465570, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465566, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465558, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465553, 1, 89048, 'Oil', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Oil
(465508, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465482, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(457085, 10, 9147, 'Mereldar Holdouts', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Mereldar Holdouts
(465575, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465560, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465542, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465523, 7, 88718, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465514, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465568, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(452633, 5, 92664, 'Barricade', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Barricade
(457084, 10, 9147, 'Mereldar Holdouts', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Mereldar Holdouts
(452632, 5, 89038, 'Barricade', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Barricade
(467505, 36, 9147, 'The Dawnbreaker', '', '', '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 6584, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Dawnbreaker
(469316, 36, 9147, 'Respawn Location', '', '', '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 6574, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Respawn Location
(409355, 15, 96809, 'The Dawnbreaker', '', '', '', 1, 9457, 10, 5, 0, 0, 0, 2672, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Dawnbreaker
(465569, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chair
(465541, 7, 86167, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chair
(465524, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465492, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465488, 7, 88246, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chair
(465557, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465555, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465504, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465485, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(465476, 7, 87769, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bench
(469315, 36, 9147, 'Respawn Location', '', '', '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 6573, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Respawn Location
(428542, 0, 10403, 'Collision', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Collision
(409468, 15, 84768, 'Ambush Airship B', '', '', '', 1, 9467, 20, 10, 0, 0, 61, 2674, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Ambush Airship B
(409366, 15, 84768, 'Ambush Airship A', '', '', '', 1, 9459, 20, 10, 0, 0, 0, 2673, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Ambush Airship A
(439338, 50, 86666, 'Arathi Supplies', 'questinteract', '', '', 1, 2124, 122868, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2809, 62438), -- Arathi Supplies
(552255, 5, 4136, 'Soup', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Soup
(572915, 5, 8316, 'Particle 2 [DNT]', '', '', '', 0.100000001490116119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Particle 2 [DNT]
(552251, 5, 1308, 'Particle 2 [DNT]', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Particle 2 [DNT]
(572913, 5, 8315, 'Particle 1 [DNT]', '', '', '', 0.100000001490116119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Particle 1 [DNT]
(552250, 5, 263, 'Particle 1 [DNT]', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Particle 1 [DNT]
(552253, 5, 105785, 'Pretzel', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Pretzel
(549972, 10, 105685, 'Dough', '', '', '', 2.5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1240504, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141342, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Dough
(549971, 10, 105685, 'Dough', '', '', '', 2.5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1240514, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 141341, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Dough
(455509, 3, 84464, '|cff1EFF00Sturdy Chest', 'lootall', '', '', 0.699999988079071044, 1634, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 457213, 0, 0, 0, 125907, 0, 0, 0, 1, 0, 2677, 63305), -- |cff1EFF00Sturdy Chest
(444045, 0, 90851, 'East Wing Door 02', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- East Wing Door 02
(455488, 3, 84464, '|cff1EFF00Sturdy Chest', 'lootall', '', '', 0.699999988079071044, 1634, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 457232, 0, 0, 0, 125909, 0, 0, 0, 1, 0, 2677, 63305), -- |cff1EFF00Sturdy Chest
(444043, 0, 90851, 'West Door 03', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- West Door 03
(444037, 0, 90851, 'East Door 1', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- East Door 1
(444046, 0, 90851, 'East Wing Door 03', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- East Wing Door 03
(455579, 5, 84464, '|cff1EFF00Sturdy Chest', '', '', '', 0.699999988079071044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- |cff1EFF00Sturdy Chest
(444036, 0, 90851, 'West door 01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- West door 01
(444044, 0, 90851, 'West Door 04', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- West Door 04
(444041, 0, 90850, 'West Door 05', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- West Door 05
(455568, 5, 84464, '|cff1EFF00Sturdy Chest', '', '', '', 0.699999988079071044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- |cff1EFF00Sturdy Chest
(444038, 0, 90850, 'Central Door', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Central Door
(432983, 0, 90851, 'Treasure Room Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Treasure Room Door
(444039, 0, 90850, 'Door03', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Door03
(444040, 0, 90850, 'East Wing Door 05', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- East Wing Door 05
(444042, 0, 90851, 'West Door 02', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- West Door 02
(444047, 0, 90851, 'East Wing Door 04', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- East Wing Door 04
(437053, 5, 85068, 'Nerubian Door', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Nerubian Door
(449716, 5, 92117, 'Web Wall', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Web Wall
(433524, 5, 88856, 'Generic Pedestal', '', '', '', 1, 0, 1, 0, 0, 0, 0, 5703, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- Generic Pedestal
(457176, 2, 56590, 'Bar Tab Barrel', '', '', '', 0.5, 0, 27698, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 298, 63305), -- Bar Tab Barrel
(567703, 56, 9510, 'Curio Container', '', '', '', 0.60000002384185791, 0, 71057, 0, 822, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- Curio Container
(449583, 5, 42997, 'Dead Beast', '', '', '', 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Dead Beast
(455557, 5, 84464, '|cff1EFF00Sturdy Chest', '', '', '', 0.699999988079071044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- |cff1EFF00Sturdy Chest
(455589, 5, 84464, '|cff1EFF00Sturdy Chest', '', '', '', 0.699999988079071044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- |cff1EFF00Sturdy Chest
(456183, 10, 77771, 'Explorers\' League Rope', 'questinteract', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 459223, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Explorers' League Rope
(455493, 3, 84464, '|cff1EFF00Sturdy Chest', 'lootall', '', '', 0.699999988079071044, 1634, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 457238, 0, 0, 0, 125909, 0, 0, 0, 1, 0, 2677, 63305), -- |cff1EFF00Sturdy Chest
(455574, 5, 84464, '|cff1EFF00Sturdy Chest', '', '', '', 0.699999988079071044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- |cff1EFF00Sturdy Chest
(421190, 0, 90658, 'Rock Wall', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Rock Wall
(564838, 56, 9510, 'Sandstorm', '', '', '', 1.5, 0, 87800, 0, 822, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2677, 63305), -- Sandstorm
(384762, 10, 78664, 'Ancient Skeleton', 'questinteract', '', '', 0.60000002384185791, 3492, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 105565, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1281, 63305), -- Ancient Skeleton
(398728, 7, 20088, 'Chair', '', '', '', 0.999999582767486572, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(398727, 7, 20088, 'Chair', '', '', '', 0.999999582767486572, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(398726, 7, 15617, 'Chair', '', '', '', 0.999998986721038818, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(398725, 7, 15617, 'Chair', '', '', '', 0.999999225139617919, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(398724, 7, 15617, 'Chair', '', '', '', 0.999999284744262695, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(398723, 7, 15617, 'Chair', '', '', '', 0.999999403953552246, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(398722, 7, 15617, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(398721, 7, 15617, 'Chair', '', '', '', 0.999999523162841796, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(398720, 7, 15617, 'Chair', '', '', '', 0.999999463558197021, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(398719, 7, 15617, 'Chair', '', '', '', 0.999999582767486572, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Chair
(548010, 3, 106686, 'Phaseblade of the Void Marches', '', 'Collecting', '', 1, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 19676, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1244044, 0, 0, 6967, 133559, 0, 0, 0, 0, 0, 3008, 63163), -- Phaseblade of the Void Marches
(338224, 3, 10684, 'Cache of the Fire Lord', '', '', '', 3.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 1203, 1215762, 1, 0, 0, 89618, 0, 2, 0, 0, 0, 1029, 62958), -- Cache of the Fire Lord
(417363, 5, 6939, 'Wyvern Roost', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62958), -- Wyvern Roost
(558112, 10, 72340, 'The Facets of K\'aresh', 'openhandglow', '', '', 0.800000011920928955, 0, 0, 0, 3000, 0, 0, 0, 10067, 0, 1, 1244518, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 7123, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 62876), -- The Facets of K'aresh
(505415, 22, 97591, 'Uncracked Cold Ones', '', '', '', 0.75, 1215373, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Uncracked Cold Ones
(526977, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 2442, 0, 1, 0, 0, 132371, 0, 5, 132337, 0, 0, 1279, 62748), -- Challenger's Cache
(558117, 10, 95634, 'I Have Become Void!', 'openhandglow', '', '', 0.800000011920928955, 0, 0, 0, 3000, 0, 0, 0, 10077, 0, 1, 1244521, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 7125, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 62493), -- I Have Become Void!
(558365, 5, 98492, 'Shadowguard Blade', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Shadowguard Blade
(558108, 10, 15595, 'Multiversal Energy Dynamics and the Murmuration Paradox', 'openhandglow', '', '', 0.800000011920928955, 0, 0, 0, 3000, 0, 0, 0, 10054, 0, 1, 1244512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 7120, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 62493), -- Multiversal Energy Dynamics and the Murmuration Paradox
(467175, 10, 96100, 'Coalesced Void Energy', 'questinteract', 'Placing Void Energy', '', 1, 2173, 84838, 0, 3000, 0, 1, 0, 0, 0, 0, 467384, 0, 0, 0, 271373, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3008, 62438); -- Coalesced Void Energy

UPDATE `gameobject_template` SET `VerifiedBuild`=63305 WHERE `entry` IN (544149, 456468, 463963, 542637, 539740, 539742, 526098, 369888, 369464, 368939, 365063, 369259, 375003, 369465, 368943, 368942, 368991, 368940, 369892, 375002, 368941, 368356, 368358, 361352, 361348, 361320, 361319, 368360, 368359, 368357, 361361, 233282, 466997, 439920, 439919, 463872, 452647, 465671, 361353, 361342, 361339, 361338, 361336, 361334, 294275, 368361, 361379, 361301, 361297, 295096, 359890, 359885, 295098, 295097, 368362, 359859, 368355, 359892, 359883, 359843, 359841, 359900, 359893, 359888, 359881, 359878, 359870, 359866, 359864, 359862, 359860, 359855, 359850, 359848, 359846, 359845, 298980, 368367, 368354, 368353, 368352, 368351, 368350, 368349, 368348, 359898, 359896, 359887, 359886, 359880, 359871, 359861, 359857, 368366, 359895, 359877, 359875, 359865, 359854, 368363, 368364, 363581, 359891, 368365, 527975, 369106, 369105, 367994, 369103, 369104, 365355, 364413, 179944, 303147, 194108, 246779, 558109, 402605, 503837, 504088, 569031, 566479, 566480, 566478, 500806, 502524, 558090, 566477, 563295, 566476, 324067, 503864, 500402, 503828, 505638, 503821, 369891, 369744, 368246, 365353, 368580, 368249, 368247, 343702, 368250, 368577, 368578, 365352, 368938, 365351, 368579, 368581, 303148, 369258, 252248, 369890, 368248, 369317, 326155, 369260, 441861, 466998, 456697, 452653, 445209, 428996, 467066, 428997, 433873, 415584, 428931, 467000, 466999, 452648, 433720, 429000, 428999, 428934, 428932, 428927, 428925, 428923, 428922, 428853, 351915, 384274, 385387, 442746, 454774, 384273, 259114, 464140, 454734, 464147, 454764, 384272, 454735, 245436, 454736, 454769, 428729, 454771, 454760, 454759, 428728, 194212, 429084, 428933, 429086, 473902, 428928, 429074, 567763, 441164, 441781, 442368, 428915, 440938, 441766, 441768, 429085, 433869, 429076, 428998, 428974, 452658, 432823, 428875, 428929, 428916, 428924, 441162, 441169, 433870, 428926, 441782, 441771, 428973, 441163, 488282, 428977, 429001, 429075, 428930, 441170, 429077, 488283, 433850, 428918, 441764, 441762, 454424, 441769, 441785, 441761, 441770, 441778, 428874, 429083, 428917, 452657, 441166, 433871, 459302, 466206, 459298, 452646, 465667, 465666, 452644, 452643, 452645, 459299, 459301, 494552, 494546, 494549, 494550, 494545, 494551, 494547, 428990, 446166, 428862, 428860, 428863, 434125, 429034, 429033, 446168, 466853, 415760, 428864, 466851, 428857, 441968, 266354, 293699, 266885, 216056, 277358, 230537, 292653, 292654, 249386, 290414, 301122, 296908, 288522, 289574, 288590, 288589, 288517, 288430, 278406, 281703, 295060, 295064, 295061, 295071, 295063, 295069, 295062, 295070, 295065, 295066, 295121, 295067, 295068, 295120, 295119, 295118, 295117, 295116, 302805, 296619, 296059, 295124, 295123, 295122, 284463, 284453, 284464, 296591, 294274, 294273, 294272, 294268, 294267, 294266, 294265, 294264, 294263, 294262, 294261, 294260, 294259, 294258, 294256, 294255, 294254, 284472, 284465, 294257, 294714, 287192, 287156, 298909, 296230, 293842, 295053, 295049, 295051, 295057, 295056, 296865, 295052, 253126, 295048, 287188, 295050, 295054, 295055, 296229, 296228, 287085, 278425, 294168, 295905, 295904, 295903, 292657, 291050, 276618, 291052, 291051, 291049, 296861, 296860, 299009, 281892, 281158, 294209, 298911, 296866, 295778, 328429, 327231, 320950, 296613, 296590, 327230, 297142, 299008, 298912, 297143, 296614, 296612, 298914, 298915, 297709, 276620, 302766, 297149, 297148, 290623, 289357, 290129, 289355, 289358, 284701, 296271, 276619, 297136, 297132, 294125, 278813, 276238, 292547, 278402, 278778, 282250, 281718, 289310, 287404, 295321, 295303, 295302, 295301, 295300, 295299, 295298, 295297, 295296, 295295, 295294, 295293, 295292, 295225, 295224, 295223, 295222, 295216, 295215, 295214, 295213, 295212, 295211, 277514, 295208, 295269, 295268, 295266, 295210, 295209, 295207, 295267, 295265, 295264, 295263, 295262, 295220, 295219, 295218, 295217, 278399, 278252, 276234, 281079, 279703, 276621, 276239, 280992, 276622, 280693, 207438, 276617, 309572, 278361, 278359, 278809, 293844, 207453, 277419, 302839, 293838, 287435, 207440, 279318, 302838, 279319, 292873, 278571, 276616, 297937, 278357, 303017, 278695, 297479, 276242, 303027, 303033, 276236, 288490, 303035, 303028, 289569, 303030, 303034, 276240, 288489, 325418, 303037, 288488, 291044, 303029, 303032, 289564, 278405, 289563, 278295, 288491, 291042, 277515, 303031, 289568, 289565, 277459, 303036, 441897, 467460, 446169, 446167, 428970, 428955, 428953, 428858, 421632, 467463, 467461, 467457, 467456, 466852, 466850, 466205, 459300, 446172, 446171, 446170, 428958, 467458, 467462, 467459, 428992, 429066, 35591, 428976, 428852, 428851, 428850, 459274, 459272, 459271, 459276, 459273, 452669, 452668, 452667, 452666, 452665, 452664, 452663, 452662, 429073, 429072, 429062, 428965, 428963, 428962, 428961, 474124, 474123, 474122, 459275, 428951, 428881, 428878, 428877, 429065, 428952, 428950, 428948, 447138, 429067, 414149, 428954, 428097, 402552, 389674, 385537, 377531, 377308, 377117, 428949, 428936, 446366, 455781, 446368, 446367, 428935, 428921, 459278, 459285, 430486, 459279, 459287, 454772, 459283, 459282, 459286, 459284, 459280, 428880, 428879, 459281, 446223, 446215, 428876, 428901, 434054, 429738, 467002, 446207, 459315, 428898, 446212, 428868, 505397, 446211, 428900, 446224, 428867, 446222, 428894, 428910, 446228, 446221, 439916, 439315, 529989, 428764, 529988, 456208, 470037, 465668, 439316, 495190, 454737, 566856, 454762, 464722, 563555, 446209, 428869, 446213, 446219, 430482, 428896, 456777, 459314, 433470, 465705, 428895, 428975, 439918, 446217, 428919, 446225, 434052, 439917, 452661, 446229, 428870, 439915, 467001, 446230, 446220, 446214, 446218, 428913, 428892, 446210, 428904, 446232, 428912, 428902, 459313, 446227, 446216, 428897, 428909, 428907, 428893, 428903, 428943, 434053, 428911, 446226, 459312, 428906, 433469, 430484, 433471, 429002, 433851, 428905, 446231, 446208, 326705, 204179, 326139, 327165, 326138, 204193, 186680, 204665, 206737, 204666, 204658, 204645, 452407, 355229, 332214, 323855, 323853, 323852, 323851, 323850, 323849, 204657, 204656, 204646, 383583, 210059, 175080, 207646, 206529, 197313, 206545, 204605, 204625, 204633, 197280, 207101, 204608, 204627, 269949, 204626, 204632, 204212, 206549, 204710, 206735, 207099, 223814, 202590, 207097, 206538, 204200, 204725, 204628, 204655, 205109, 204601, 184633, 210181, 377216, 179707, 179881, 339344, 190549, 279294, 186238, 206110, 281340, 279295, 203378, 298892, 195253, 203979, 273293, 175787, 195273, 350063, 195265, 175788, 195263, 205142, 386349, 195266, 452029, 307614, 273286, 273300, 195256, 203969, 195260, 186717, 206610, 197287, 204729, 204215, 204606, 204602, 204604, 207098, 204201, 197284, 204192, 207094, 204723, 206708, 204603, 206729, 204709, 204205, 204199, 207889, 243461, 204651, 206539, 204662, 223739, 206995, 197323, 204209, 197276, 204163, 204202, 204191, 204198, 206736, 207414, 204208, 204210, 204194, 243459, 206726, 206530, 196837, 204211, 204611, 204204, 204600, 206725, 206733, 204634, 204664, 203471, 204650, 204607, 152614, 204623, 204621, 323854, 202717, 206727, 204213, 197279, 204622, 204195, 204207, 204639, 206609, 204609, 204196, 204647, 206546, 243462, 204203, 197257, 204624, 206608, 204640, 205108, 204663, 278281, 207100, 206709, 207096, 204197, 204620, 204724, 204214, 204730, 204610, 243460, 204631, 206741, 414321, 414317, 413952, 503868, 414597, 413905, 451674, 414316, 441966, 409747, 430335, 454394, 414325, 414335, 414318, 454063, 299336, 413900, 433643, 413049, 413880, 451669, 404550, 299330, 430477, 299333, 433898, 422154, 408132, 408111, 409748, 478443, 414315, 415042, 455576, 485669, 454062, 455495, 407408, 455561, 408227, 413046, 454093, 451672, 404325, 455583, 422916, 456778, 433467, 412078, 423605, 413017, 423968, 414379, 423606, 412080, 423604, 413020, 413874, 413877, 442814, 184663, 358877, 358876, 358874, 358875, 355452, 353390, 353392, 358871, 353633, 365674, 358872, 355424, 353391, 364864, 355451, 364863, 375890, 353389, 352110, 358873, 357092, 364865, 375041, 329743, 329742, 204178, 204183, 268919, 327133, 239938, 186187, 279239, 326072, 186185, 326078, 268917, 180749, 279243, 250563, 186229, 326104, 326067, 327539, 327541, 326077, 327540, 288421, 250564, 231654, 279362, 279361, 326051, 250566, 325994, 325995, 186737, 221481, 186681, 288422, 265545, 327182, 326076, 259240, 279592, 325998, 239935, 326073, 326712, 1618, 1731, 328424, 211694, 221482, 282271, 326708, 186709, 326106, 326105, 186682, 1617, 326711, 292549, 279363, 327538, 186186, 326714, 326709, 326710, 209654, 206575, 204185, 126051, 204181, 204182, 126050, 326715, 259880, 368426, 204164, 206574, 204189, 204177, 204187, 204175, 204180, 191083, 204166, 21680, 204184, 204188, 204176, 204186, 204165, 195264, 428866, 428859, 428865, 428861, 184664, 525795, 516620, 516614, 516611, 516609, 516606, 516613, 437758, 437756, 437755, 437595, 437594, 437592, 437591, 437590, 429061, 429058, 437593, 437600, 437586, 437601, 437584, 437585, 453182, 437554, 437550, 443320, 437761, 432948, 437757, 437551, 437589, 437596, 437582, 437599, 437583, 437588, 437602, 452670, 437603, 437587, 429071, 429070, 299260, 299259, 299264, 299263, 299253, 299254, 299343, 299265, 297144, 299258, 299256, 299250, 299262, 299261, 299251, 299344, 299257, 299252, 296728, 299342, 299255, 281339, 278802, 202003, 201992, 197190, 197189, 197188, 197187, 197135, 197122, 332224, 197119, 197085, 197083, 197081, 197080, 197079, 323844, 203978, 197186, 197082, 202258, 197087, 201998, 254114, 197096, 197030, 202257, 197123, 197015, 197017, 197023, 197032, 209297, 202004, 202260, 197033, 311875, 197022, 254094, 197018, 197138, 197020, 254108, 197036, 254113, 197092, 197029, 197089, 254095, 197012, 254104, 197099, 254111, 197027, 201987, 197193, 254119, 254105, 197013, 197093, 197178, 254089, 254107, 197091, 254110, 202259, 197025, 254112, 197177, 197011, 197097, 202006, 202253, 270011, 254088, 254106, 197031, 197086, 254100, 197008, 323846, 197038, 254115, 197034, 201999, 254116, 207416, 197181, 197098, 254120, 197140, 197010, 197028, 197182, 197192, 197126, 202256, 197037, 197184, 197125, 197179, 197176, 254093, 259008, 197026, 202011, 254103, 197024, 254123, 254099, 254102, 207661, 205553, 202010, 254101, 197180, 202002, 197136, 201996, 254118, 197191, 201993, 197134, 197090, 254109, 197021, 197088, 254122, 202005, 197183, 254117, 197185, 254092, 197009, 201989, 279608, 377200, 294556, 193981, 195257, 175729, 250672, 335930, 209692, 175758, 322639, 1561, 140911, 386352, 203800, 105174, 209039, 195259, 105175, 367977, 201983, 203762, 367978, 452904, 451696, 445075, 463912, 463910, 463864, 453921, 422478, 441554, 441793, 466136, 453573, 433914, 463909, 451327, 437052, 444355, 452985, 452984, 349097, 438047, 438046, 454055, 438045, 434501, 452627, 452626, 451987, 451979, 451978, 413047, 456086, 465097, 453813, 454472, 455631, 452505, 453782, 466715, 453191, 456235, 452018, 452845, 455731, 452844, 453189, 453781, 455732, 452504, 452016, 456234, 466717, 456088, 453816, 465100, 455634, 466716, 456237, 465098, 452846, 453779, 452503, 455633, 453192, 456087, 466718, 465099, 456236, 456089, 455734, 455733, 455632, 453815, 453814, 453780, 453190, 452847, 452506, 452015, 455720, 422531, 451976, 452630, 451977, 411881, 449810, 449808, 451986, 252247, 454076, 451984, 452628, 440283, 452659, 428993, 428846, 454317, 428849, 428848, 428847, 428978, 428940, 428937, 428941, 428942, 446188, 446187, 428991, 446194, 446193, 446192, 446191, 446190, 446189, 441772, 466237, 466234, 459270, 459269, 459268, 441780, 441779, 441777, 441773, 441765, 441776, 441775, 441760, 441774, 433328, 428885, 428882, 441767, 441763, 429063, 428886, 428884, 433640, 433639, 433632, 433631, 433630, 433629, 428964, 428959, 433626, 433625, 433638, 433637, 433628, 433627, 433633, 433635, 433636, 433634, 467043, 428967, 428966, 428855, 429064, 428957, 428956, 428960, 452660, 433327, 428968, 447142, 447140, 446181, 446180, 446179, 446178, 446183, 447139, 446177, 447141, 446182, 446176, 415377, 428989, 187265, 185899, 459294, 459293, 459296, 459295, 459292, 459291, 459290, 459289, 429081, 429080, 429078, 429079, 453747, 453183, 453367, 444197, 455920, 439252, 437751, 437749, 437743, 437617, 437616, 437615, 437614, 437613, 437612, 437608, 437609, 437604, 437611, 437610, 437618, 437605, 437746, 437606, 437621, 437607, 452655, 437625, 437624, 437623, 437622, 452656, 452654, 429069, 517352, 429068, 429737, 212349, 215700, 214442, 214978, 213409, 214292, 214544, 213433, 213434, 213428, 213427, 213302, 213444, 213435, 213431, 213430, 213429, 212641, 209312, 278492, 215076, 214991, 213432, 214818, 214907, 212738, 214428, 213377, 213378, 213376, 213374, 215412, 215077, 215910, 215893, 213314, 214281, 214645, 212016, 213195, 212899, 212048, 212047, 214064, 209353, 221993, 221992, 214063, 213812, 213084, 213082, 212955, 213083, 212954, 221991, 213159, 211305, 213157, 213397, 221755, 221759, 213155, 221663, 221754, 214900, 214380, 213396, 214398, 221761, 221245, 221753, 212976, 221679, 221446, 213162, 221677, 221678, 214895, 222679, 214896, 211662, 215366, 222682, 211665, 221760, 222681, 222810, 208903, 212975, 213156, 221752, 213398, 221751, 215365, 214899, 221620, 221676, 215130, 221757, 212876, 222683, 222680, 212883, 214471, 216060, 221447, 222809, 213166, 222811, 215363, 221758, 212870, 221750, 221756, 211663, 212927, 213395, 213347, 210680, 213349, 215364, 212874, 213167, 211664, 214531, 213165, 213164, 213161, 213160, 212882, 212881, 212880, 212879, 212878, 209313, 212690, 212691, 212483, 212481, 212479, 212652, 212651, 211220, 214746, 211657, 211656, 211148, 211143, 210929, 211568, 209328, 215963, 211539, 211172, 212487, 211175, 211124, 278676, 215966, 215965, 215964, 215382, 213379, 215381, 214530, 211274, 211763, 211760, 211757, 211523, 211212, 211269, 211264, 211772, 211762, 211761, 211755, 211754, 211688, 211270, 211540, 211325, 211324, 211213, 211209, 211205, 211204, 214540, 211794, 211516, 211323, 211273, 211268, 211266, 211210, 209351, 212860, 211770, 211759, 211758, 211756, 211567, 211541, 211446, 211328, 211311, 214497, 214696, 213247, 213940, 213946, 213373, 213939, 213529, 214526, 213245, 213951, 213955, 213244, 213285, 213246, 213947, 213528, 213950, 213527, 213954, 213948, 213945, 213944, 213953, 213942, 213941, 213943, 213949, 213506, 213248, 213952, 214452, 213258, 213937, 213938, 211702, 214441, 187084, 214961, 215869, 213511, 210565, 211615, 210869, 211229, 215391, 211241, 212903, 211508, 211228, 210870, 211230, 214464, 211240, 211231, 211530, 211693, 211531, 211614, 210868, 215699, 211668, 212175, 212969, 209780, 215860, 215859, 215693, 215564, 215563, 215562, 215423, 215422, 212181, 209311, 215689, 209349, 191640, 215718, 200296, 212624, 212924, 214893, 215766, 212621, 212591, 212182, 212592, 212590, 212576, 212582, 212623, 212183, 212561, 215767, 212594, 212926, 212184, 212625, 212569, 214894, 210804, 212581, 212578, 212622, 214566, 212571, 212580, 212567, 214987, 214570, 216302, 212595, 212565, 212186, 212564, 212572, 212579, 215845, 278457, 215711, 215683, 215687, 212588, 214988, 212925, 212562, 212568, 212563, 212583, 215686, 214568, 212566, 212587, 212584, 214569, 212585, 216301, 214567, 215684, 212589, 212586, 212559, 212560, 212593, 212570, 268690, 252303, 251028, 188508, 174465, 170559, 174514, 174438, 170460, 174500, 140378, 174556, 170446, 158680, 174493, 174516, 174531, 174555, 174554, 140439, 170452, 161522, 174489, 190367, 140397, 174506, 173234, 174546, 170561, 174526, 174562, 140394, 140373, 158546, 174498, 170457, 158581, 140372, 174455, 158548, 170459, 174534, 186763, 174471, 174541, 172911, 140401, 174536, 161495, 174520, 174472, 174523, 157923, 170448, 170567, 170565, 161516, 207103, 158572, 174436, 174539, 174470, 174440, 165554, 174466, 207403, 174548, 158580, 161525, 170456, 174411, 161461, 140376, 140387, 170467, 158558, 174519, 174457, 160845, 170445, 174483, 161457, 174524, 170575, 140380, 140399, 174528, 158550, 170447, 174529, 170461, 170584, 174504, 174475, 174545, 174497, 174428, 175739, 174496, 140384, 174442, 190395, 174501, 174451, 174448, 174533, 174507, 174558, 170444, 173232, 158569, 170580, 174485, 158678, 174419, 164688, 170583, 174426, 174521, 140383, 174435, 140389, 174434, 170579, 170453, 207402, 174439, 174566, 174530, 170450, 174537, 170581, 174467, 174425, 174502, 174473, 174452, 174492, 174525, 170454, 170471, 174510, 174550, 140385, 174503, 174464, 174427, 140386, 158552, 174480, 164821, 174560, 174476, 175725, 174518, 174563, 158557, 174544, 170441, 174509, 179552, 174446, 174487, 170563, 174413, 140400, 140395, 174432, 181019, 140374, 174463, 158582, 174460, 170557, 174437, 174512, 174479, 170570, 175736, 170458, 170449, 170442, 174462, 158583, 174494, 190368, 170572, 140375, 170571, 174486, 158553, 174430, 174505, 174412, 170577, 158551, 170560, 170443, 164911, 170556, 174540, 170469, 174461, 170569, 174421, 170568, 174429, 174481, 170573, 174527, 158545, 170470, 174564, 174445, 174453, 174517, 170466, 174433, 174559, 174491, 161524, 174515, 140388, 170463, 174443, 170464, 188498, 158584, 170574, 174441, 170468, 174469, 140392, 174511, 170562, 174444, 140381, 174552, 174499, 174414, 170558, 174495, 170582, 170566, 140382, 174553, 174542, 174561, 170578, 174543, 174454, 170576, 174415, 174477, 174490, 161460, 174431, 174565, 174547, 170465, 207088, 174482, 174551, 207401, 174458, 174450, 207165, 174535, 174549, 174468, 174459, 158549, 140398, 161462, 174532, 174474, 174449, 174478, 170555, 158554, 158570, 170564, 174508, 170451, 174456, 170607, 158679, 174513, 174557, 165658, 174538, 174484, 174522, 160836, 174488, 165739, 161523, 165738, 207145, 140379, 174447, 190386, 170455, 203855, 204174, 252071, 204190, 213197, 213196, 174863, 160410, 160409, 214229, 219396, 219395, 245767, 249825, 245762, 245770, 245765, 245781, 245763, 245768, 245769, 245766, 250431, 250430, 376125, 376861, 376876, 376866, 376877, 381618, 381620, 379282, 381619, 455354, 525461, 525463, 455349, 525462, 455359, 455353, 499166, 525466, 525468, 455357, 499164, 455355, 455361, 499202, 455358, 525464, 455356, 499163, 525465, 499165, 499251, 525467, 455360, 455351, 455352, 499160, 499159, 525469, 3931, 3924, 3923, 3922, 3929, 185136, 3932, 3912, 3934, 182156, 260459, 3845, 260466, 260470, 260468, 3843, 260448, 182160, 182158, 260458, 182157, 3840, 184303, 260456, 260473, 260460, 3925, 260454, 3841, 260465, 3913, 260471, 3927, 260461, 182155, 260472, 3921, 260467, 3926, 260449, 260527, 3844, 260451, 3920, 260528, 182161, 260453, 174953, 260450, 260469, 3842, 3919, 3915, 260463, 182162, 260462, 260464, 260452, 182159, 260474, 260455, 260457, 3839, 353497, 353495, 352927, 293195, 330151, 330150, 330149, 330148, 296907, 296274, 296380, 322090, 322181, 241914, 290530, 322355, 291054, 298910, 297492, 290719, 291131, 239296, 281348, 293278, 287414, 327232, 322356, 298913, 290739, 297745, 303133, 290458, 319230, 290459, 319233, 272799, 290461, 290460, 319232, 291276, 239174, 281455, 319229, 297749, 292904, 316841, 233778, 278212, 288591, 292672, 298899, 297763, 187376, 298947, 297757, 298941, 297756, 369894, 290815, 298940, 298902, 298903, 298901, 297748, 290811, 298942, 297760, 278211, 297761, 297759, 298944, 291157, 239176, 312128, 297752, 297754, 298946, 298900, 327189, 297755, 334950, 297762, 292584, 281560, 298943, 298939, 289332, 297751, 297746, 294021, 277313, 297747, 293983, 297758, 316680, 293970, 289529, 298916, 297753, 289558, 297750, 291156, 316905, 291273, 291155, 329787, 329786, 495326, 433868, 298780, 298781, 420130, 265571, 266086, 266083, 266457, 266463, 266514, 266458, 184396, 184395, 266462, 266082, 265569, 266459, 266461, 266084, 266085, 398729, 20808, 59858, 59857, 59856, 59851, 59850, 59517, 56901, 60438, 59864, 59518, 148914, 144127, 148894, 144126, 148902, 56911, 59852, 59847, 61918, 59861, 59854, 148900, 59848, 59855, 148891, 91692, 56903, 148906, 148898, 2083, 148899, 59859, 148886, 148888, 148887, 60395, 148892, 148889, 148911, 60439, 59863, 278574, 175854, 204578, 175756, 175732, 2046, 180391, 178204, 175855, 270848, 187299, 208420, 175856, 270882, 21582, 270854, 175757, 1735, 59853, 2575, 148904, 56898, 56905, 2574, 148885, 59860, 59862, 148909, 56897, 148915, 148893, 148901, 148884, 56910, 59845, 148905, 59865, 148903, 148910, 21678, 74091, 148895, 60440, 59846, 1984, 148912, 148913, 3933, 3930, 3928, 3918, 3917, 3916, 3914, 185918, 22708, 38495, 22710, 22563, 38493, 38491, 185917, 22707, 22709, 22712, 22566, 38492, 22567, 38494, 22565, 22564, 3797, 22711, 3798, 181886, 281107, 253968, 226911, 252663, 259285, 245353, 245355, 248842, 248844, 248843, 245368, 247849, 248841, 247848, 242127, 259834, 242220, 259346, 244824, 242128, 242648, 259351, 259345, 242640, 259284, 248093, 242639, 242050, 242641, 242638, 242637, 245661, 259390, 249919, 245691, 245662, 242636, 242054, 251286, 242049, 259349, 268067, 250514, 246002, 268057, 259387, 382535, 382534, 382533, 382532, 382531, 268065, 259380, 259348, 258330, 250513, 250435, 247691, 245663, 242123, 242048, 242047, 188215, 250298, 242042, 259309, 242199, 250506, 242198, 250358, 242234, 250472, 250461, 242215, 259835, 242235, 250215, 259383, 241920, 250516, 250490, 241949, 250509, 250515, 242228, 249730, 250455, 248079, 250511, 242125, 245623, 250218, 259271, 250491, 242226, 250217, 242041, 250498, 259283, 250348, 251593, 259307, 249729, 250336, 248516, 254236, 250352, 242039, 259398, 259275, 250464, 242223, 250331, 250354, 259391, 246465, 250315, 250492, 246945, 242043, 250520, 250322, 246944, 259295, 250460, 247018, 259335, 241419, 259384, 241513, 250484, 250471, 250356, 247015, 249362, 250454, 259308, 260236, 250500, 245833, 241972, 251311, 259397, 241943, 242225, 259296, 250518, 258328, 247692, 259279, 235100, 268052, 250459, 259415, 259281, 259262, 241968, 242118, 266736, 259289, 241946, 259416, 244562, 251592, 250319, 259278, 250494, 250355, 250351, 241947, 250499, 250324, 259337, 194115, 259311, 241961, 268044, 268061, 268081, 268043, 242236, 268073, 266761, 250482, 251305, 251992, 259303, 259276, 259264, 268087, 259347, 245832, 250350, 244537, 242201, 269989, 268051, 247337, 250502, 251584, 259288, 250334, 242175, 241453, 259287, 251585, 246466, 244534, 259426, 242052, 244950, 268072, 242126, 250214, 241953, 259266, 244560, 246943, 267068, 242170, 250359, 250219, 259382, 242237, 250451, 244561, 250467, 250357, 241965, 250496, 241512, 250452, 241971, 259282, 259267, 259306, 266618, 259317, 241950, 242132, 241511, 246257, 251624, 250344, 250495, 241954, 241960, 268086, 250483, 250469, 258327, 250314, 269967, 242040, 242176, 250456, 250329, 251580, 250360, 252331, 250512, 242172, 259274, 242232, 250485, 259290, 250504, 259310, 267991, 250576, 242169, 250474, 246013, 242037, 246262, 246708, 250449, 250347, 250340, 250481, 246260, 241480, 250468, 250216, 250631, 242230, 259269, 250525, 250353, 250313, 250508, 241446, 259342, 415412, 242231, 250335, 250503, 259304, 250528, 268049, 259339, 251594, 250338, 241951, 250342, 259395, 259270, 242202, 250478, 242233, 250333, 259341, 259277, 259286, 268053, 250505, 242051, 251105, 242224, 251581, 259393, 242177, 241959, 242045, 241922, 235098, 241957, 259350, 246258, 242130, 259305, 242038, 251312, 250450, 259392, 241445, 259272, 268059, 266851, 259312, 258329, 250507, 250480, 266619, 241970, 247858, 250436, 250457, 242216, 259268, 250316, 259394, 250487, 259338, 250300, 200297, 259336, 241921, 246941, 247019, 241969, 241944, 250346, 250349, 250510, 241447, 241945, 241955, 241963, 268074, 246463, 246154, 369301, 241967, 250320, 259344, 250493, 268078, 244651, 242200, 241952, 250453, 259291, 259396, 259343, 242227, 250524, 259273, 266705, 246009, 250438, 268048, 242131, 269037, 235099, 249732, 259334, 246001, 268046, 241966, 241958, 250318, 250345, 250323, 247693, 247013, 280797, 242129, 268045, 242044, 249731, 250463, 259293, 246261, 369302, 242218, 246942, 250458, 250477, 241620, 259292, 250317, 250297, 246520, 242229, 259381, 250526, 241956, 242366, 241948, 250521, 250479, 250476, 250517, 250332, 250523, 250501, 241506, 250497, 250341, 250339, 241964, 259280, 251582, 250470, 250519, 250527, 243374, 246008, 259265, 250321, 250337, 250462, 250343, 250328, 242046, 250473, 244536, 259294, 250522, 250299, 251595, 444098, 454272, 453716, 463911, 454075, 434318, 413883, 451692, 451559, 442669, 451796, 455332, 455288, 451773, 444567, 423908, 423907, 410355, 454584, 445076, 454583, 451913, 451912, 451911, 451910, 451768, 451767, 451766, 451765, 451698, 439468, 454752, 454582, 453372, 453370, 451797, 451779, 451778, 451777, 451776, 451695, 439556, 439555, 410394, 451879, 506498, 503870, 413590, 299329, 299328, 299078, 504311, 443526, 423367, 451671, 414322, 503869, 409302, 429592, 413022, 453093, 445371, 445210, 423948, 434154, 434263, 465248, 465247, 465222, 465221, 434259, 434251, 434238, 434236, 434219, 434212, 434209, 434197, 434192, 434190, 434182, 434170, 434167, 434166, 434159, 434148, 434147, 434141, 434140, 434138, 453694, 445525, 445524, 445227, 445226, 445224, 445223, 445222, 445220, 445218, 445217, 445216, 445215, 445214, 445213, 434216, 434207, 434185, 434139, 434137, 465226, 465225, 465224, 465223, 445449, 445221, 434235, 434149, 428891, 428890, 428889, 428888, 423947, 453092, 428972, 428971, 428845, 428844, 423946, 441195, 441183, 441194, 414323, 446148, 454502, 392665, 386640, 386639, 386638, 386637, 386636, 457335, 294494, 294503, 294496, 294495, 294499, 294500, 294501, 294498, 294497, 294502, 294504, 294505, 294506, 294493, 294492, 294491, 294490, 294489, 294488, 282465, 459266, 457333, 457332, 457331, 294487, 294486, 294485, 294484, 294483, 294482, 294481, 411121, 446584, 429698, 429697, 429696, 429695, 429694, 429693, 429686, 453062, 429579, 455716, 454463, 429587, 429573, 429572, 429568, 429586, 429578, 429569, 463887, 1619);
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=63305 WHERE `entry`=359882; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63305 WHERE `entry`=359852; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=63305 WHERE `entry`=359847; -- Forge
UPDATE `gameobject_template` SET `Data3`=0, `VerifiedBuild`=63305 WHERE `entry`=369107; -- Titan Console
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry` IN (291255, 291254); -- Small Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=289536; -- Ritual Censer
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry` IN (289538, 289537); -- Foul Tidewater
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=284448; -- Hidden Scholar's Chest
UPDATE `gameobject_template` SET `ContentTuningId`=705, `VerifiedBuild`=63305 WHERE `entry` IN (291267, 291258, 291263, 291201); -- Small Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry` IN (287190, 287196, 287193, 287187, 287191); -- Rebel Weaponry
UPDATE `gameobject_template` SET `ContentTuningId`=708, `VerifiedBuild`=63305 WHERE `entry`=326165; -- Prospectable Rock
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=293499; -- Nesingwary's Campfire
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=288157; -- Wanted: Yarsel'ghun
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=88617, `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=292656; -- Long Forgotten Rum
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=278824; -- Horde Explosive
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry` IN (287468, 287467, 287463); -- Old Ship Part
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=278827; -- Sack of Grain
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=280552; -- Battered Sword
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=244983; -- Dirty Pocketwatch
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=280553; -- Tarnished Locket
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry` IN (294535, 294536, 294537, 282457); -- Brambleguard Totem
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=281912; -- Simmering Cauldron
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=278433; -- Earthen Pillar
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=63305 WHERE `entry`=293350; -- Carved Wooden Chest
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=282478; -- Empty Crate
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=281888; -- Pot of Viscous Goop
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=281482; -- Preserved Bramble Spores
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=281911; -- Bubbling Cauldron
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=281887; -- Stinky Potion
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=281486; -- Quill Venom
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=282477; -- Stolen Stormsong Supplies
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=63305 WHERE `entry`=281473; -- Giant-Sized Totem
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=63305 WHERE `entry`=276262; -- Trogg Cage
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=63305 WHERE `entry`=291045; -- Alliance Banner
UPDATE `gameobject_template` SET `Data30`=129754, `VerifiedBuild`=63305 WHERE `entry`=451830; -- |cff1EFF00Heavy Trunk
UPDATE `gameobject_template` SET `Data30`=129756, `VerifiedBuild`=63305 WHERE `entry`=413563; -- |cff1EFF00Heavy Trunk
UPDATE `gameobject_template` SET `VerifiedBuild`=63163 WHERE `entry` IN (467043, 446183, 446182, 446181, 446180, 446179, 446178, 446177, 446176, 433631, 433630, 433629, 428957, 433632, 428960, 433625, 245436, 433626, 463872, 459302, 433640, 433639, 433638, 433637, 433636, 433635, 433634, 433633, 433628, 433627, 428989, 466206, 459298, 428958, 452646, 459301, 459299, 459300, 428996, 466205, 452644, 452643, 465667, 452645, 465666, 428936, 467002, 428935, 429738, 459275, 439918, 459272, 459274, 430482, 459276, 459271, 430486, 456208, 439915, 459273, 439916, 428919, 439316, 439315, 439917, 467001, 446368, 446366, 429065, 414149, 377531, 377117, 429067, 377308, 402552, 385537, 459282, 459285, 389674, 428868, 446367, 459286, 459280, 459279, 428870, 459278, 452661, 459287, 459283, 428867, 459284, 459281, 428892, 428893, 190942, 428943, 428869, 428901, 428903, 428907, 428911, 429002, 428913, 428912, 428910, 428900, 191605, 428905, 428904, 428897, 428895, 428921, 446232, 505397, 494546, 446231, 446211, 494552, 494550, 446222, 494549, 428896, 446210, 446228, 428906, 446213, 428097, 563555, 465705, 459315, 459314, 459313, 459312, 446230, 446227, 446220, 446219, 446217, 446214, 446209, 434054, 434053, 434052, 428909, 428902, 428898, 428894, 428764, 566856, 494545, 446229, 446226, 446225, 446224, 446221, 446216, 446212, 446207, 494551, 494547, 455781, 447138, 446218, 446208, 441897, 428965, 446223, 446215, 428990, 428963, 428961, 428876, 452664, 467456, 428850, 466853, 446171, 467463, 428955, 440938, 428954, 428860, 452668, 446168, 466852, 421632, 428949, 428881, 428950, 495190, 428976, 415760, 428877, 428863, 446170, 428953, 474123, 474124, 467461, 452665, 428962, 428952, 446169, 467457, 429062, 428879, 428880, 452667, 466850, 441785, 474122, 467458, 428970, 434125, 428851, 467459, 442746, 428948, 428862, 452666, 452653, 428729, 428728, 428951, 452663, 429034, 442368, 446166, 428858, 446167, 466851, 473902, 467462, 428992, 467460, 452669, 446172, 452662, 432823, 428857, 35591, 429073, 429072, 429066, 428852, 429033, 428864, 428878, 206995, 259114, 204603, 204602, 204209, 529988, 386349, 377216, 281340, 269949, 206725, 204657, 204601, 204600, 204214, 204210, 204207, 329787, 329786, 326705, 206737, 204666, 204665, 204658, 204645, 204193, 204179, 186717, 190549, 332214, 206610, 452407, 204212, 204208, 204211, 205108, 323849, 210181, 470037, 206727, 204163, 323851, 323853, 204215, 204656, 204663, 323852, 204650, 529989, 204202, 204647, 204662, 355229, 323850, 223739, 206609, 323854, 204201, 207414, 203969, 206608, 223814, 204655, 204213, 205142, 206110, 204651, 206726, 204646, 383583, 323855, 204664, 205109, 252663, 250525, 259335, 259274, 241954, 250218, 241920, 251593, 250333, 250480, 259393, 242225, 259296, 248843, 242233, 259280, 241921, 250527, 250473, 250483, 241966, 241948, 241959, 259344, 250502, 246261, 259336, 250339, 242226, 250503, 258330, 250478, 242040, 250331, 242123, 246262, 242224, 250504, 259291, 245832, 259345, 259415, 250481, 259395, 250450, 250341, 250346, 242223, 258328, 250454, 246941, 242235, 259382, 259341, 259381, 246942, 248844, 250498, 259310, 259276, 242045, 250469, 250508, 242050, 242227, 246943, 241972, 250358, 250482, 259384, 259264, 259312, 250343, 259391, 250453, 259284, 250515, 250337, 242176, 259287, 242202, 259343, 259294, 259270, 250314, 235100, 247015, 268046, 268067, 246013, 244562, 241506, 269037, 242638, 251105, 244536, 200297, 268045, 246463, 245355, 245368, 246008, 235098, 268086, 249729, 244534, 242648, 188215, 247858, 369301, 268074, 243374, 268051, 241445, 244537, 247693, 246520, 415412, 268081, 268078, 241511, 244950, 245623, 266618, 247013, 246001, 382532, 249730, 268061, 268044, 242641, 269989, 194115, 241446, 369302, 241419, 250631, 268072, 246466, 247692, 246002, 247018, 382534, 266619, 206603, 246465, 248093, 250576, 268052, 246154, 249731, 249732, 382535, 242639, 268073, 247019, 246009, 244561, 266705, 266736, 252331, 245353, 235099, 266761, 247849, 245691, 251992, 242636, 241620, 268087, 247691, 242366, 241513, 278574, 251624, 268065, 184633, 267991, 244651, 268048, 382533, 268043, 247848, 268059, 244824, 244560, 241453, 254236, 251305, 249362, 246708, 382531, 268057, 247337, 247797, 268049, 241480, 200296, 241512, 268053, 278457, 269967, 242637, 242640, 266851, 241447, 242125, 250350, 248079, 259278, 259305, 259350, 250506, 242046, 259306, 250355, 250471, 241943, 251592, 248841, 259267, 259304, 241965, 242198, 242231, 259349, 250349, 250356, 242228, 250219, 250495, 259282, 259416, 242048, 250451, 241958, 250340, 259285, 245662, 251595, 250324, 250215, 248516, 242172, 241967, 241944, 242037, 242200, 250499, 250320, 250513, 259279, 259275, 241953, 242130, 250449, 242043, 250217, 250300, 241947, 259339, 259262, 250315, 250494, 250316, 250360, 250528, 245661, 259269, 260236, 250313, 280797, 242170, 250299, 250470, 250344, 250336, 251582, 250354, 242216, 250347, 242215, 250348, 250452, 245663, 250332, 259347, 259404, 258329, 242236, 259338, 259308, 250522, 246257, 254276, 250214, 259438, 259293, 251580, 250509, 250472, 250438, 259351, 259380, 250514, 242218, 250523, 250338, 242175, 259398, 259272, 259311, 250353, 251594, 249919, 242042, 250484, 250516, 242234, 249516, 259835, 250328, 259392, 254145, 259265, 250507, 259342, 259394, 259317, 259348, 259334, 250493, 250456, 241949, 259268, 241951, 250298, 259289, 242229, 267068, 242126, 246944, 250497, 242230, 258327, 241957, 250517, 242199, 242047, 250318, 259426, 250459, 259277, 250496, 241955, 246945, 241960, 250319, 242049, 259288, 248842, 259397, 242044, 250436, 250487, 250519, 259283, 259286, 242038, 250457, 242051, 241970, 250500, 259292, 259273, 250505, 250521, 250345, 259400, 250435, 241964, 242201, 242127, 241971, 241945, 250323, 250460, 250317, 250462, 250352, 250511, 250467, 259346, 250464, 259390, 241968, 250477, 250524, 250492, 265469, 250461, 242177, 259387, 246260, 250322, 241952, 241922, 250455, 241946, 251584, 259290, 242054, 241956, 251581, 250510, 250490, 259309, 250359, 250463, 241950, 250335, 250334, 259929, 241961, 250479, 250501, 250526, 245833, 242237, 250468, 250357, 242220, 259281, 241963, 259266, 242039, 250342, 250297, 254238, 259303, 242118, 259396, 250485, 242232, 242169, 250491, 251585, 250458, 250520, 250476, 242128, 250518, 259271, 250474, 241969, 259307, 242132, 242129, 259435, 250512, 259383, 250216, 242052, 259295, 250329, 246258, 242131, 259337, 250321, 250351, 242041, 259834, 293191, 276618, 325418, 295330, 295804, 295340, 295803, 295341, 295332, 303137, 295328, 303138, 295345, 295344, 295339, 295336, 295335, 294208, 294206, 294207, 278919, 276619, 297177, 294379, 297240, 303042, 303056, 295420, 295419, 301128, 295400, 295408, 205104, 201446, 201448, 201453, 201445, 201447, 201451, 201452, 201450, 249424, 268047, 251212, 251209, 269969, 250303, 250311, 250406, 242030, 250405, 259375, 250312, 250307, 259358, 259359, 250304, 259362, 259365, 259372, 259361, 250395, 250310, 259360, 250309, 250404, 250397, 250400, 250417, 250403, 259354, 250402, 250399, 250308, 251210, 268054, 250396, 250398, 251211, 250407, 250401, 259377, 259374, 259373, 259371, 259369, 259367, 259364, 259363, 259357, 259356, 259355, 259353, 259352, 250306, 250305, 250302, 248858, 248855, 248852, 247579, 247564, 247558, 242029, 248860, 259366, 248857, 250301, 248859, 251304, 247572, 247571, 259368, 259370, 250261, 250258, 259376, 250260, 250259, 250391, 259378, 268060, 259379, 248523, 268368, 250389, 266129, 250390, 268079, 259820, 250392, 250388, 250387, 248933, 248822, 248522, 250393, 253969, 250394, 259240, 268066, 226911, 253968, 248856, 251286, 369303, 251311, 251312, 276515, 302838, 303159, 303158, 292852, 297465, 297463, 297464, 293402, 297475, 297138, 276238, 297478, 303070, 303069, 303068, 295333, 295327, 295784, 295783, 295782, 295348, 295347, 295346, 295343, 295342, 295338, 295337, 295334, 281079, 276242, 278406, 276616, 276234, 276617, 276621, 294726, 294730, 293846, 301053, 295484, 295474, 295449, 294736, 294727, 301052, 301051, 301050, 299319, 299316, 299308, 296949, 294401, 277419, 294375, 294376, 302802, 297479, 297178, 294382, 299309, 302803, 302801, 302800, 302799, 302798, 302797, 302796, 299318, 299317, 299315, 299311, 294403, 294395, 294383, 294374, 299312, 299310, 299307, 299306, 297784, 297724, 294402, 294400, 294397, 294396, 294377, 294263, 266403, 294392, 294256, 297179, 294274, 299320, 294265, 297197, 294262, 297176, 296952, 294393, 294391, 294390, 294389, 294273, 294272, 294268, 294267, 294266, 294264, 294261, 294260, 294259, 294258, 294257, 294255, 294254, 297273, 297215, 294743, 294369, 241319, 293131, 294463, 298988, 294462, 303143, 303142, 299313, 298983, 298873, 297214, 295520, 295519, 295518, 295517, 294723, 294465, 294464, 294291, 294289, 294288, 294287, 294283, 294282, 294281, 294280, 294279, 294278, 294276, 299314, 294724, 294290, 294277, 303044, 298987, 298986, 298985, 298984, 297283, 297275, 297263, 297257, 297228, 297224, 297173, 297163, 297160, 321747, 297635, 292913, 292915, 293755, 213637, 269098, 303077, 303076, 303075, 303074, 303054, 303051, 303050, 303048, 295154, 295153, 295152, 295151, 295150, 295149, 295148, 295147, 295146, 295145, 295144, 295143, 295142, 295141, 288632, 316428, 294971, 303062, 303058, 303073, 303066, 303063, 303065, 303064, 303043, 303041, 303047, 303053, 294966, 303045, 294882, 303060, 294865, 294968, 294965, 294969, 294879, 295478, 294875, 303057, 294944, 294878, 295479, 294874, 303121, 294872, 294873, 294880, 303127, 298974, 298977, 298975, 294876, 294869, 303040, 303122, 298971, 298968, 298972, 298973, 294990, 298970, 303125, 298969, 303126, 298976, 295126, 294877, 301137, 303128, 302795, 301136, 295132, 295131, 295130, 295129, 295128, 295127, 295125, 294962, 294958, 294957, 294918, 294916, 294915, 294914, 294913, 294912, 294911, 294910, 294871, 294867, 294862, 294861, 302793, 302792, 302794, 294917, 294860, 294859, 294943, 296223, 295079, 295109, 295080, 295468, 299282, 297169, 295108, 294972, 299281, 295027, 299280, 299285, 299283, 295107, 299284, 294866, 295001, 295026, 295000, 302952, 295454, 295453, 295120, 295011, 294988, 294987, 294942, 294940, 294938, 294840, 302951, 279593, 295464, 295119, 295475, 295121, 295456, 335633, 294808, 335631, 295118, 335634, 335632, 294979, 294982, 295117, 295457, 295116, 335630, 295085, 303085, 294234, 294993, 292910, 294231, 294232, 295123, 295715, 294995, 295017, 295124, 294992, 295714, 278571, 294233, 295122, 295365, 294997, 295716, 295016, 294996, 294994, 295766, 295765, 295470, 295461, 295161, 295157, 295028, 295012, 294946, 281095, 295758, 295759, 295762, 295156, 295769, 295763, 295770, 295768, 295760, 295158, 295767, 295155, 295761, 295776, 295756, 295773, 295160, 295774, 295757, 295775, 294930, 295015, 297905, 295731, 301132, 295777, 295764, 295721, 295724, 295732, 295733, 295734, 294246, 295402, 294248, 294253, 294247, 295401, 294245, 294242, 295013, 294239, 295720, 294243, 294244, 294241, 295778, 295772, 295771, 295755, 295754, 295753, 295730, 295729, 295723, 295722, 295719, 295718, 295717, 295473, 295471, 295467, 295462, 295021, 294240, 294238, 294237, 295727, 295487, 295728, 295726, 295725, 320928, 301133, 295159, 294955, 295476, 295486, 295020, 294961, 302998, 303005, 303007, 302995, 303013, 302996, 294858, 303011, 302997, 303012, 303001, 303010, 303008, 295415, 303004, 302994, 294903, 303009, 316675, 294904, 303006, 294902, 294901, 303002, 303000, 302999, 303003, 294906, 294956, 294847, 290675, 321755, 301134, 294977, 321732, 321753, 321735, 321734, 321733, 321725, 321724, 321721, 321719, 312156, 266152, 254114, 254113, 254090, 254096, 254099, 254091, 254102, 254108, 254098, 254107, 254097, 254118, 254117, 254116, 254115, 254106, 254105, 254104, 254103, 254101, 254100, 254095, 254094, 254093, 254092, 254089, 254088, 254121, 254120, 254119, 205144, 201619, 197196, 203988, 203987, 214405, 271723, 223202, 227906, 273282, 205105, 227908, 281164, 227907, 227909, 203751, 278329, 452030, 278331, 278328, 316736, 273853, 339222, 273855, 298865, 278330, 278327, 278326, 278333, 278332, 203953, 218719, 278310, 232235, 281864, 232224, 232234, 278325, 232225, 281205, 278324, 350063, 281204, 278311, 250568, 203955, 203952, 201462, 203951, 201485, 201484, 201474, 201449, 201475, 201476, 204281, 201463, 201479, 201461, 231870, 281304, 201478, 201483, 203954, 201482, 201481, 201480, 204988, 204987, 203950, 203949, 203948, 201477, 193585, 193584, 193583, 180047, 201488, 201492, 201495, 201496, 203976, 202271, 202273, 202272, 201489, 201490, 201493, 175739, 202270, 202267, 202274, 201491, 201494, 206560, 201419, 201415, 201416, 201420, 92011, 201417, 201418, 203925, 203926, 203946, 203927, 203924, 203939, 203947, 201421, 203935, 203940, 203931, 201460, 203945, 203944, 203943, 203942, 203941, 203938, 203937, 203936, 203934, 203933, 203932, 203930, 203929, 203928, 201459, 201458, 201457, 201456, 201455, 201454, 202061, 202043, 202060, 202062, 202059, 202044, 202057, 209051, 209053, 202758, 209052, 209101, 209046, 209047, 209044, 209048, 202063, 209045, 202064, 209040, 202052, 202050, 202058, 209041, 202047, 202049, 209054, 209050, 209049, 209043, 209042, 207720, 207719, 207718, 202056, 202055, 202054, 202053, 202051, 202048, 202046, 202045, 201986, 201985, 201982, 1684, 201980, 202020, 207721, 202018, 202012, 202019, 202013, 202021, 202016, 202007, 201514, 202031, 202017, 202014, 207723, 202015, 202022, 207722, 202000, 202001, 258986, 202029, 202011, 202009, 206623, 202036, 202035, 202034, 202033, 202032, 202030, 202008, 201999, 201998, 201981, 202002, 209297, 203800, 201991, 202023, 140911, 202024, 201996, 201994, 201983, 201997, 202003, 201992, 201995, 201993, 202028, 202027, 202026, 202025, 201987, 202010, 202006, 202005, 202004, 197190, 197187, 197139, 197137, 197133, 197132, 197131, 278802, 197189, 197173, 197188, 197172, 197193, 197191, 197192, 197118, 201989, 197122, 197121, 197120, 197116, 281339, 197138, 197134, 197126, 197117, 203978, 202259, 202257, 202253, 197175, 197174, 197150, 197149, 197148, 197147, 197146, 270011, 250672, 205107, 205106, 202260, 202258, 202256, 197186, 197185, 197140, 197135, 197123, 197119, 254110, 197180, 197179, 197177, 197178, 205553, 197184, 197183, 197182, 197181, 197176, 197136, 197125, 403736, 386352, 254122, 254112, 254111, 254109, 197018, 377200, 254123, 207661, 197099, 197098, 197097, 197024, 197023, 197022, 197021, 175758, 175729, 197089, 209039, 197060, 197020, 421496, 197075, 197011, 197039, 254084, 197015, 207416, 197086, 243299, 323840, 197030, 197032, 197058, 197080, 197049, 197071, 197092, 243301, 197082, 197051, 197076, 197083, 197084, 190536, 197093, 197062, 197065, 398823, 197043, 197055, 197042, 197038, 197007, 197036, 197074, 197013, 197064, 197026, 243324, 197073, 197063, 197014, 254081, 243305, 193981, 197017, 197078, 279608, 197056, 197047, 197040, 197008, 355054, 323843, 105174, 197046, 1561, 243297, 197028, 197031, 254082, 197066, 323844, 254086, 197072, 197025, 311875, 383582, 254080, 197079, 197052, 197034, 212212, 245923, 322639, 197037, 253169, 197091, 197053, 197035, 254085, 197087, 209692, 197054, 197057, 332224, 197081, 197067, 197045, 197077, 197085, 197012, 203762, 197033, 197044, 197068, 335930, 323845, 197061, 323841, 197009, 197090, 197069, 323842, 197010, 197096, 197050, 197048, 197029, 259008, 375073, 323846, 252281, 197059, 197070, 253168, 197088, 243295, 243294, 197027, 243300, 254068, 105175, 197041, 203801, 321754, 321730, 321720, 321718, 317398, 294857, 294856, 239174, 295025, 294490, 295022, 294973, 294491, 294488, 294807, 295023, 294492, 294489, 294493, 295024, 295398, 295399, 294905, 295019, 294999, 294486, 294998, 294487, 294482, 294484, 302790, 302791, 294481, 365071, 294483, 365070, 295018, 294485, 365066, 365069, 365067, 365068, 365064, 303146, 365065, 323531, 293965, 312208, 323383, 313618, 323548, 295417, 295057, 295049, 295048, 294975, 295052, 295050, 295051, 214679, 295053, 295054, 295056, 295055, 294974, 294948, 289693, 295092, 298885, 294275, 294952, 292695, 295096, 294954, 296155, 299344, 316427, 298914, 299342, 369893, 309572, 294949, 294889, 316904, 282465, 299250, 294888, 299343, 299255, 294544, 298883, 299251, 302941, 301135, 298886, 302940, 295094, 292872, 294898, 295361, 293552, 302858, 279717, 281609, 299265, 295357, 294887, 293844, 239179, 299254, 298915, 299256, 282258, 321795, 299253, 294891, 298882, 299262, 295409, 295358, 295362, 294976, 316422, 302950, 295097, 302947, 302839, 294953, 299264, 293838, 295469, 316424, 298881, 303145, 298980, 299259, 316423, 280662, 292869, 296566, 229465, 299263, 316429, 292547, 302948, 298912, 301127, 299260, 288469, 297145, 288433, 303207, 295432, 295087, 294897, 299009, 282246, 302857, 266354, 295095, 295364, 295360, 294556, 298909, 294546, 295414, 292871, 299257, 296460, 295093, 302942, 302944, 294890, 298884, 299258, 298910, 306854, 295091, 287435, 295090, 294545, 294543, 325967, 295089, 301129, 253128, 294950, 278570, 298913, 294899, 281647, 297937, 301131, 292873, 294896, 279586, 325968, 295411, 293132, 302946, 295088, 321760, 292870, 295086, 299261, 294951, 298911, 295363, 239178, 316430, 294963, 302945, 296478, 302949, 295098, 281065, 299322, 299252, 295481, 301130, 303017, 294900, 321797, 299008, 303018, 295083, 295081, 296709, 296708, 278295, 296694, 295082, 295084, 296697, 296710, 296711, 296696, 296707, 296627, 296705, 296704, 296695, 276236, 291223, 273522, 276239, 276486, 293972, 273814, 276240, 288166, 276471, 278405, 273766, 59857, 59858, 59850, 59856, 59851, 180391, 175856, 175855, 175854, 175732, 61918, 59865, 59864, 59848, 59517, 56901, 56897, 21678, 2574, 59854, 59863, 60395, 148912, 175756, 148913, 148910, 148902, 56910, 60439, 60440, 60438, 59860, 148904, 59862, 148905, 59853, 56898, 2575, 148906, 148909, 175757, 148911, 144127, 74091, 148898, 148895, 59855, 59852, 148893, 148892, 148891, 148915, 148889, 59861, 148914, 148887, 148899, 148885, 148900, 21582, 148903, 148886, 148888, 148884, 148894, 148901, 59859, 270854, 270848, 204578, 144126, 59846, 190363, 187299, 59847, 180043, 56911, 91692, 270882, 208420, 59845, 59518, 56905, 56903, 251355, 185437, 178204, 2083, 1984, 204909, 2046, 2041, 759, 216764, 207486, 204336, 205111, 180901, 216761, 2043, 1735, 1733, 398729, 2042, 20808, 278347, 176790, 176496, 208333, 176491, 176488, 2045, 204828, 2744, 143979, 349791, 349790, 351926, 351925, 351924, 351923, 351921, 351920, 351919, 351430, 207641, 204704, 351918, 351922, 349789, 349788, 207637, 204714, 204712, 204711, 204683, 204682, 204638, 187376, 207645, 207638, 204718, 204717, 204715, 204713, 204703, 204702, 204637, 207640, 207639, 207636, 204716, 204705, 204701, 204692, 204685, 207642, 204684, 204616, 339239, 204635, 204618, 204636, 205090, 204689, 207690, 207689, 207688, 207687, 207686, 206739, 206738, 206595, 206509, 206508, 205091, 204615, 50805, 50804, 50803, 204617, 204614, 207635, 204721, 204619, 195222, 204719, 202812, 204727, 204941, 202813, 204720, 204940, 202814, 204643, 202816, 207631, 202811, 204700, 204708, 202817, 204707, 208054, 204678, 204726, 204688, 207634, 204699, 204613, 204679, 204706, 204612, 202810, 204698, 202815, 197260, 237942, 204723, 204680, 204722, 204694, 207632, 202805, 202804, 197261, 206732, 202803, 206730, 197307, 197285, 202802, 197286, 197311, 206547, 204681, 197314, 197259, 197309, 204937, 204695, 204696, 204938, 207633, 204936, 208270, 204939, 206740, 186722, 208269, 202808, 202809, 384744, 293684, 205056, 197312, 197310, 206548, 197278, 197322, 197315, 197207, 207630, 206549, 206529, 204724, 202801, 202800, 197280, 197276, 197257, 105576, 197323, 204623, 197284, 204634, 197279, 204628, 206538, 206539, 206546, 197313, 197287, 202799, 204725, 210058, 204693, 206545, 204633, 206735, 204632, 202798, 204631, 202717, 208534, 204622, 204621, 210059, 206530, 207646, 204640, 206736, 402852, 206741, 204204, 204192, 204191, 204203, 206729, 204195, 278281, 204710, 204709, 204607, 204606, 204205, 204200, 204197, 204196, 203979, 204608, 204198, 204639, 204610, 204605, 204194, 175788, 175787, 204611, 204609, 204604, 204199, 203378, 202590, 186238, 175080, 428866, 428865, 428859, 428861, 495326, 441164, 454424, 441162, 433471, 433470, 456778, 441169, 355518, 231252, 231251, 258962, 258961, 258956, 258955, 258952, 251517, 245311, 243275, 243240, 258958, 245310, 258959, 243247, 248974, 248969, 248967, 248965, 527623, 506584, 467264, 548694, 548693, 548690, 548689, 503267, 500238, 500376, 500375, 500277, 527734, 500678, 500250, 500234, 500728, 500727, 546744, 527488, 558090, 527987, 527984, 527983, 523491, 569033, 569032, 558115, 547547, 434796, 517405, 532323, 532322, 532321, 532318, 532317, 476423, 476313, 476306, 476302, 517410, 517407, 516995, 434789, 517000, 516991, 516730, 349389, 348931, 434790, 475886, 500652, 500649, 434799, 500701, 500700, 500699, 500645, 369312, 358158, 504201, 506610, 470338, 558105, 504088, 420130, 455920, 439252, 437751, 437749, 459294, 459292, 459291, 437746, 437743, 437617, 437616, 437615, 437614, 437613, 437604, 437603, 437601, 441294, 437618, 437612, 437605, 437608, 437606, 459290, 437624, 437621, 437607, 459289, 437610, 437611, 437609, 459293, 453182, 452656, 452655, 452654, 443320, 437625, 437623, 437622, 437554, 437551, 432948, 437550, 429079, 429069, 517352, 459296, 459295, 429081, 429080, 429078, 429061, 429058, 525795, 516620, 516614, 516613, 516611, 516609, 516606, 452670, 429068, 429071, 447140, 428968, 447142, 415377, 447139, 447141, 429737, 429070, 488283, 428977, 433868, 488282, 452648, 433873, 433720, 452658, 452657, 441768, 433871, 433870, 433869, 430484, 429000, 428997, 428999, 441968, 544149, 527975, 456468, 463963, 194108, 246779, 526098, 539742, 252248, 539740, 542637, 303148, 179944, 566478, 563295, 564548, 503837, 566477, 564546, 566480, 505419, 558109, 566476, 566479, 502524, 500403, 502452, 505458, 569031, 500806, 503821, 564545, 402605, 516444, 505638, 324067, 505451, 503864, 503828, 428993, 233282, 429001, 467066, 441782, 441771, 441764, 441762, 428915, 428975, 428916, 428853, 567763, 466999, 466998, 466997, 439920, 428998, 428974, 428973, 428918, 428875, 428874, 467000, 439919, 428928, 428926, 428924, 428917, 415584, 428934, 428933, 428932, 428930, 428929, 428925, 441861, 452647, 445209, 428931, 428927, 428923, 428922, 433467, 433469, 441166);
UPDATE `gameobject_template` SET `ContentTuningId`=184, `VerifiedBuild`=63163 WHERE `entry`=267540; -- Pirate Sails
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=63163 WHERE `entry`=293688; -- Vigil Hill Documents
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=63163 WHERE `entry`=296699; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63163 WHERE `entry`=296700; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=63003 WHERE `entry` IN (445209, 466998, 439919, 466997, 439920, 430484, 437757, 437584, 437583, 441294, 437599, 437585, 437603, 437602, 437601, 437600, 429070, 429068, 443320, 437551, 429737, 429081, 429071, 454063, 433851, 433471, 433470, 433469, 413874, 437613, 437608, 516620, 452655, 437615, 455920, 437614, 459292, 437618, 437606, 437624, 437616, 437609, 516606, 429058, 437610, 517352, 437612, 516611, 437625, 437554, 432948, 437751, 437611, 429080, 516613, 429069, 453182, 437746, 437617, 429079, 452654, 459289, 459291, 437622, 452656, 429078, 437607, 437749, 429061, 439252, 437550, 437621, 459290, 437743, 516609, 525795, 516614, 437605, 437623, 437604, 377531, 447138, 389674, 377308, 446366, 377117, 385537, 402552, 428097, 452670, 428990, 428975, 421632, 430486, 430482, 473902, 428877, 428895, 439918, 428900, 494551, 446218, 428903, 428912, 446368, 446215, 459281, 434054, 439915, 446211, 428902, 428764, 495190, 566856, 259114, 442746, 455781, 441861, 428728, 529988, 439315, 439316, 470037, 529989, 563555, 428729, 456208, 505397, 428879, 446228, 441162, 428950, 428913, 494545, 428906, 494549, 446225, 428954, 446222, 428894, 446224, 428901, 465705, 428905, 446208, 440938, 428867, 428881, 446223, 459313, 428898, 428904, 446210, 459279, 446212, 467002, 428869, 446227, 428949, 456778, 446207, 459284, 428896, 428911, 456777, 459315, 446219, 442368, 434053, 434052, 459282, 429002, 454424, 459287, 441785, 446209, 459285, 446213, 446216, 429738, 439917, 446231, 494550, 446214, 428909, 459283, 428893, 446220, 428878, 428910, 433467, 494552, 428897, 467001, 494547, 446221, 446367, 428870, 428951, 428948, 428921, 432823, 459314, 441164, 428919, 428876, 428952, 428892, 459280, 459286, 446226, 441169, 428880, 494546, 446232, 428943, 428907, 439916, 459278, 446217, 452661, 446229, 459312, 428868, 446230, 488283, 428977, 488282, 441771, 441764, 428915, 452658, 441768, 429001, 433868, 452657, 441762, 441782, 433871, 433870, 452648, 433873, 433869, 433720, 428999, 429000, 428997, 434125, 428863, 428860, 446172, 446168, 446167, 446166, 441897, 446169, 446171, 446170, 466850, 467456, 467457, 467460, 467458, 428858, 428955, 467461, 467459, 428953, 428970, 467463, 429066, 35591, 428976, 428992, 428850, 428852, 466852, 467462, 428851, 428916, 567763, 467066, 428853, 429072, 429062, 429073, 452659, 428993, 466999, 428874, 428974, 428875, 428998, 428973, 415584, 467000, 428918, 428924, 428934, 428933, 428932, 428929, 428928, 428926, 428925, 428917, 428930, 452647, 428931, 428927, 428923, 428922, 446181, 446180, 446179, 446178, 433640, 433639, 433636, 433635, 433634, 433633, 433632, 433631, 433630, 433629, 433628, 433627, 433626, 433625, 428965, 428960, 474124, 474123, 474122, 459302, 459298, 433638, 433637, 428989, 428963, 428962, 428961, 452666, 452665, 452664, 466206, 452669, 452668, 452667, 428958, 466205, 459301, 459300, 459299, 452663, 452662, 245436, 463872, 459276, 459275, 459274, 459273, 459272, 459271, 452646, 452645, 452644, 428996, 452643, 452653, 414149, 428935, 441166, 465667, 429067, 429065, 465666, 428936, 303148, 466851, 429034, 415760, 429033, 441968, 355590, 355589, 527975, 349098, 349099, 469490, 353049, 353178, 353179, 353286, 353056, 353262, 349294, 353302, 353301, 353291, 353180, 355592, 353300, 353783, 353276, 349935, 353274, 353284, 353271, 353280, 353275, 353297, 353287, 353290, 353277, 353304, 355593, 353048, 353261, 355591, 349933, 352524, 349931, 353269, 349295, 353782, 349936, 353298, 246779, 352503, 352504, 358281, 352052, 352056, 339994, 352053, 352487, 352508, 352469, 352501, 351993, 358270, 358275, 352050, 358282, 358299, 358274, 358276, 358278, 358273, 358269, 358272, 352483, 352486, 358548, 358271, 352465, 352001, 352610, 352507, 358277, 354206, 352522, 352010, 352608, 352467, 352575, 358280, 352015, 352480, 352463, 352006, 339238, 358279, 352502, 352054, 352016, 352482, 352008, 352506, 352051, 365226, 352470, 352471, 352049, 352462, 352505, 344794, 353378, 352468, 339853, 334915, 353174, 337226, 272724, 351997, 353175, 352484, 327444, 358300, 466853, 428866, 428865, 428864, 428862, 428859, 428857, 467043, 429064, 428956, 433327, 428968, 428957, 447142, 447141, 447140, 447139, 446183, 446182, 446177, 446176, 415377);
UPDATE `gameobject_template` SET `VerifiedBuild`=62876 WHERE `entry` IN (259958, 266593, 266576, 266577, 266656, 259959, 266592, 266295, 265489, 267190, 265488, 266826, 259969, 266895, 266878, 259977, 259979, 259966, 259968, 259986, 266806, 259981, 259971, 259985, 259982, 259972, 259976, 266896, 266510, 259973, 259978, 259984, 259970, 259974, 266894, 259975, 259983, 259980, 259967, 266846, 260313, 260312, 260311, 259693, 259692, 259691, 259696, 259695, 259599, 259678, 259661, 259676, 259640, 259709, 259601, 259527, 259711, 259551, 259644, 259671, 259629, 259568, 259611, 259542, 259597, 259531, 259710, 259552, 259589, 259656, 266804, 259572, 259614, 259556, 265602, 259534, 269977, 259712, 259683, 259545, 259560, 259730, 259655, 266905, 259587, 259579, 259538, 259610, 259647, 259659, 259561, 259600, 259567, 269904, 259652, 259574, 259524, 259577, 259628, 259596, 259536, 259638, 259630, 259604, 259664, 259657, 259643, 259718, 259719, 259583, 259565, 259582, 259634, 259543, 259586, 259648, 259580, 259674, 259666, 259650, 259528, 265605, 259585, 259646, 259662, 259541, 259609, 259668, 259615, 259563, 259687, 259727, 259623, 259554, 259690, 259679, 259685, 259654, 259670, 259721, 259637, 259626, 259715, 266803, 259672, 259573, 259553, 259725, 259607, 259708, 259617, 259716, 259724, 259660, 259576, 259540, 259631, 259723, 259529, 259525, 259703, 265603, 259689, 259707, 259713, 259613, 265597, 265599, 259641, 259694, 259698, 259624, 259532, 259665, 259675, 259537, 259699, 259535, 259616, 259570, 259635, 259559, 259622, 259603, 259717, 259686, 259928, 259566, 259722, 259593, 259636, 259619, 259608, 259621, 259539, 259530, 259682, 259571, 259547, 259602, 265604, 259578, 259550, 259555, 259627, 259588, 259642, 259633, 259704, 266858, 259584, 259681, 259673, 259605, 259625, 259697, 259706, 259658, 259663, 266904, 259606, 259649, 259700, 259526, 259702, 259544, 266508, 259581, 259720, 259546, 267924, 259688, 259620, 259651, 259533, 259564, 259714, 259591, 269978, 259728, 259680, 259618, 259684, 259598, 259612, 259592, 259701, 259595, 259705, 259645, 259575, 259653, 259594, 259632, 259590, 259569, 259548, 259557, 266903, 259562, 259549, 265600, 259639, 259726, 259558, 408808, 408807, 246402, 176558, 160866, 177247, 177252, 265595, 177249, 266848, 176580, 177251, 160867, 177250, 160868, 265574, 177253, 176577, 176633, 177248, 184463, 184164, 177245, 259236, 207208, 265581, 177246, 181963, 176578, 266746, 260287, 246709, 258978, 265578, 176901, 259235, 176694, 160871, 265594, 265590, 265575, 259234, 177047, 160869, 265580, 177049, 408860, 265588, 204344, 160870, 176579, 177203, 245855, 246660, 265589, 177048, 203838, 203289, 503446, 505399, 571702, 527489, 527955, 571703, 527488, 516444, 470362, 433632, 433631, 433630, 433629, 433628, 433627, 433626, 433625, 433640, 433639, 433637, 433636, 433635, 433634, 433633, 433638, 428857, 503568, 508125, 527975, 299078, 489974, 528436, 503552, 233282, 467142, 467093, 246779, 467110, 467165, 507972, 467099, 467155, 467122, 467106, 467135, 465030, 467107, 467143, 467137, 467158, 467147, 502540, 467105, 502539, 467109, 467131, 467124, 507783, 467125, 467119, 467150, 467123, 467116, 467162, 507968, 467114, 467113, 467126, 508146, 502538, 467154, 467129, 507960, 467102, 467111, 467098, 467115, 467112, 467159, 467151, 505620, 467134, 467136, 433643, 413900, 179944, 451675, 422548, 446174, 422531, 446175, 446173, 422491, 439251, 479606, 452706, 451676, 454064, 439312, 444333, 444332, 444322, 444321, 444317, 444313, 444298, 444295, 444294, 444292, 444291, 444290, 444288, 444287, 444286, 444283, 444282, 444331, 444330, 444329, 444328, 444327, 444326, 444323, 444320, 444319, 444318, 444316, 444315, 444314, 444312, 444311, 444289, 444284, 444285, 444337, 444335, 444325, 444324, 444304, 444280, 444278, 465243, 465242, 465241, 464938, 444340, 444339, 444338, 444336, 444334, 444307, 430556, 421128, 421127, 417152, 421121, 421126, 444310, 455610, 444309, 444308, 430555, 452945, 452944, 452943, 411623, 455269, 414597, 441968, 413874, 494956, 413886, 452680, 411498, 411497, 457361, 411381, 455603, 425875, 439777, 443532, 433369, 449751, 432835, 250825, 414337, 451440, 252248, 459336, 459292, 459291, 459290, 459289, 420130, 459296, 459295, 459294, 459293, 456778, 456777, 453183, 433851, 433471, 433467, 413877, 437602, 437622, 429078, 437603, 437623, 429081, 429080, 429079, 453182, 452656, 452655, 452654, 443320, 437554, 437551, 437550, 432948, 429069, 517352, 429061, 429058, 452659, 428993, 428977, 452660, 433327, 429064, 429063, 428967, 428966, 428956, 428855, 447140, 446181, 446180, 446178, 428968, 428957, 447142, 446179, 428960, 488283, 428989, 459302, 459298, 447139, 446183, 446177, 415377, 447141, 446182, 446176, 525795, 516606, 516620, 516614, 516613, 516611, 516609, 452670, 429071, 429068, 429737, 429070, 433873, 428999, 452648, 441768, 441771, 433869, 430484, 428997, 433720, 488282, 433871, 452658, 433870, 441764, 429000, 452657, 433868, 429001, 441861, 441782, 441762, 428915, 467066, 428853, 428916, 428975, 494552, 494546, 466998, 428974, 428875, 445209, 428874, 415584, 467000, 439920, 466999, 466997, 439919, 567763, 428973, 428998, 428934, 428933, 428932, 428930, 428929, 428928, 428926, 428925, 428924, 428918, 428917, 428923, 428927, 428922, 452647, 428931, 529988, 439316, 439315, 429738, 245436, 463872, 452646, 428996, 452644, 428936, 465666, 452645, 452643, 465667, 430482, 428919, 467002, 439918, 439917, 439916, 439915, 428935, 467001, 466206, 459299, 456208, 259114, 430486, 466205, 459301, 459300, 428958, 428893, 428892, 428901, 428903, 459271, 459276, 428868, 459274, 459272, 428870, 428867, 446368, 459280, 452661, 459286, 470037, 529989, 428907, 428869, 459273, 459285, 428911, 459282, 459275, 459279, 459278, 446366, 428913, 428912, 428910, 428900, 428943, 459287, 459284, 459283, 459281, 446367, 429002, 377308, 377117, 428905, 414149, 402552, 389674, 377531, 505397, 446232, 446231, 428897, 446211, 428904, 428895, 385537, 446213, 446210, 429067, 429065, 428906, 428896, 494550, 459313, 446230, 428921, 465705, 459312, 563555, 494549, 459315, 459314, 446220, 446217, 434054, 428898, 428894, 428764, 566856, 494545, 446222, 446219, 446209, 434053, 434052, 428909, 428902, 446228, 446227, 446224, 446221, 446216, 446214, 446212, 446207, 428097, 494551, 494547, 446229, 446226, 446225, 446208, 446218, 455781, 447138, 446223, 446215, 441897, 428990, 428965, 428963, 428876, 428860, 421632, 434125, 452668, 467458, 446171, 467460, 428954, 467457, 428970, 429062, 452664, 429073, 466852, 428850, 428976, 441785, 428862, 473902, 466851, 452662, 429066, 466853, 428852, 446166, 428879, 428961, 467459, 432823, 428951, 446168, 428851, 474122, 429034, 474124, 429033, 415760, 35591, 428729, 495190, 428728, 442746, 474123, 452665, 467461, 428949, 428880, 467463, 428952, 428950, 428881, 446172, 429072, 433469, 452666, 428992, 467462, 452669, 428948, 428962, 452667, 467456, 428877, 428955, 433470, 428863, 446170, 440938, 454424, 466850, 452653, 441169, 442368, 428878, 446169, 428953, 452663, 446167, 428858, 428864, 441164, 428866, 429085, 429084, 429074, 429083, 429076, 441781, 441778, 441770, 441769, 441766, 441761, 467043, 441162, 453747, 441163, 414379, 453367, 444197, 413020, 441166, 441170, 413017, 441294, 455920, 439252, 437761, 437758, 437756, 437755, 437751, 437749, 437743, 437617, 437616, 437615, 437614, 437613, 437612, 437609, 437608, 437604, 437595, 437594, 437593, 437592, 437591, 437590, 437757, 437746, 437621, 437618, 437611, 437610, 437607, 437606, 437605, 437599, 437596, 437589, 437588, 437587, 437586, 437584, 437583, 437582, 437625, 437624, 437601, 437600, 437585, 368356, 361381, 361348, 361320, 368358, 361361, 361352, 361319, 368357, 368360, 368359, 361353, 361342, 361339, 361338, 361336, 361334, 294275, 368361, 361379, 361301, 361297, 295096, 295097, 359890, 359885, 295098, 368362, 359892, 359883, 359859, 368355, 359878, 359862, 359843, 359841, 298980, 359900, 359893, 359888, 359881, 359870, 359866, 359864, 359860, 359855, 359850, 359848, 359846, 368351, 368350, 368348, 359898, 359896, 359886, 359880, 359861, 359845, 368367, 368354, 368353, 368352, 368349, 359887, 359871, 359857, 359895, 359877, 359875, 359865, 368366, 359854, 368363, 363581, 368364, 368365, 359891, 369106, 369105, 369104, 369103, 365355, 364413, 369892, 368381, 368382, 370083, 368383, 369888, 368942, 375003, 375002, 368941, 368940, 369465, 369464, 368991, 368943, 368939, 365063, 369887, 369259, 368937, 369889, 369466, 369467, 369316, 369315, 369258, 365353, 368249, 369744, 368581, 369260, 369890, 343702, 368246, 369891, 369317, 368938, 368248, 368580, 365351, 368250, 368577, 368579, 326155, 365352, 368578, 368247, 194342, 434791, 349389, 348931, 558115, 532317, 517000, 517407, 517405, 547547, 532323, 532322, 532321, 532318, 527987, 527984, 527983, 516995, 434796, 569033, 569032, 517410, 558090, 546744, 505419, 504088, 564548, 564546, 564545, 505451, 505458, 569031, 558109, 563295, 505638, 523512, 502452, 503837, 502524, 500403, 500806, 548694, 548693, 402605, 502471, 503363, 503361, 566480, 566477, 566476, 503828, 566479, 566478, 503821, 503864, 324067, 469901, 527765, 523491, 508124, 507956, 506583, 548690, 548689, 499097, 503267, 205056, 293684, 197315, 197309, 197310, 197207, 351926, 351921, 351430, 210058, 351923, 351925, 351924, 351922, 349788, 208534, 204693, 202801, 202799, 202798, 349789, 207630, 204695, 202800, 207633, 204712, 204711, 186722, 207637, 205142, 205108, 204939, 204714, 204696, 204683, 204682, 204638, 202805, 202804, 202803, 202802, 187376, 204715, 204692, 204938, 204716, 202809, 208270, 204681, 204703, 207645, 204713, 193981, 205109, 207638, 202808, 204694, 204718, 204717, 208269, 204936, 204702, 204937, 339239, 281340, 269949, 245190, 207642, 207640, 207639, 207636, 207631, 204707, 204705, 204701, 204685, 204684, 204637, 204619, 204618, 204616, 204614, 204635, 204617, 204612, 384744, 278802, 209049, 207632, 204708, 204706, 204680, 204636, 204615, 204613, 202817, 197259, 195222, 209050, 209045, 204698, 202816, 197261, 208054, 204941, 204940, 202815, 2061, 190549, 175080, 186238, 204679, 206740, 204643, 205091, 207634, 204700, 206608, 197260, 197307, 206595, 237942, 206508, 207686, 206730, 223814, 202814, 206110, 202810, 384511, 204719, 204688, 207414, 210181, 207690, 50804, 207689, 202811, 206610, 206738, 207635, 205090, 204678, 202813, 207688, 207687, 206739, 204721, 204720, 3301, 206609, 203969, 204699, 204726, 50805, 202812, 206509, 223739, 204689, 204727, 50803, 193024, 193027, 192861, 192858, 525866, 507876, 191083, 553513, 506585, 504210, 494777, 477615, 551887, 477617, 467439, 467437, 467436, 551893, 551884, 551890, 336432, 303147, 194108, 526898, 526897, 555410, 531547, 556388, 565734, 529162, 531251, 556445, 525867, 526838, 531217, 556437, 531216, 507877, 525872, 525871, 556447, 536835, 525300, 525305, 525304, 525302, 525301, 253130, 303148, 527841, 528026, 544155, 528029, 544154, 527130, 553593, 527427, 529703, 528012, 525727, 532325, 532527, 531546, 555790, 527129, 536147, 573364, 529706, 528027, 528031, 528028, 532065, 528017, 532524, 532062, 528013, 544157, 525726, 528011, 529705, 544156, 532525, 532063, 528010, 528033, 528032, 532523, 528030, 532526, 528016, 532066, 532064, 527840, 527128, 528009, 528020, 529704, 500707, 290129, 527507, 562348, 565748, 563467, 527953, 567300, 567298, 567199, 476423, 476313, 476306, 476302, 434799, 434794, 516991, 516730, 487811, 434795, 434790, 434789, 487808, 487810, 487809, 475886, 369312, 358158, 500701, 500700, 500699, 500652, 500649, 500645, 504201, 506610, 470338, 558105, 265598, 266354, 455073, 527623, 506584, 508145, 504074, 557649, 557647, 506586);
UPDATE `gameobject_template` SET `Data12`=682, `ContentTuningId`=682, `VerifiedBuild`=62876 WHERE `entry`=269940; -- Legion Cache
UPDATE `gameobject_template` SET `VerifiedBuild`=62748 WHERE `entry` IN (413047, 452627, 452626, 451985, 451983, 451981, 454072, 414317, 451327, 466136, 433914, 463909, 441793, 422478, 463912, 441554, 451913, 451912, 451779, 451778, 451777, 451776, 451767, 451765, 463910, 451797, 451695, 439555, 463880, 454752, 454582, 453372, 453370, 410394, 410287, 451698, 454584, 454583, 454581, 451773, 451692, 454055, 451796, 442669, 451559, 441710, 437233, 453137, 435019, 453136, 435018, 453140, 453134, 435015, 445007, 437232, 435020, 422811, 435014, 453138, 443864, 441287, 445024, 437234, 453133, 445179, 435013, 453147, 453141, 444012, 444011, 453918, 444779, 441292, 435017, 452122, 441290, 441291, 451920, 444013, 437049, 443865, 441734, 453139, 437231, 454747, 453135, 435016, 441288, 441289, 453144, 433370, 290129, 451388, 454076, 413875, 454272, 454260, 454265, 454577, 454332, 454330, 454320, 454313, 454264, 454578, 454316, 454268, 454269, 463637, 410396, 463879, 463878, 463863, 445076, 463883, 463882, 463881, 463877, 454701, 454580, 454560, 454557, 453048, 453039, 451660, 453040, 453044, 453034, 451661, 463876, 453049, 453038, 453047, 453045, 453043, 453050, 453051, 410834, 453041, 453037, 453036, 463875, 453033, 454561, 453052, 453046, 453042, 453035, 422477, 454562, 463884, 445075, 463864, 454579, 453921, 451662, 413884, 453573, 443309, 437052, 444355, 443311, 445103, 443312, 438047, 438046, 349097, 441347, 433775, 438045, 434501, 413046, 423641, 453813, 456235, 466715, 455731, 453191, 453782, 453781, 452016, 453816, 452845, 455631, 452505, 456088, 466717, 465097, 456086, 452018, 452504, 466716, 465100, 465099, 465098, 456237, 456236, 456234, 456089, 456087, 455734, 455732, 455634, 455633, 455632, 453815, 453780, 453779, 453192, 453189, 452847, 452846, 452844, 452506, 452503, 452015, 466718, 465187, 455733, 454472, 453814, 453190, 422531, 449810, 440283, 452628, 452630, 414379, 451984, 455720, 449808, 252247, 451976, 451977, 451986, 411881, 456778, 456777, 433471, 433467, 433627, 433633, 433638, 433640, 433630, 433637, 433635, 433632, 433639, 433626, 433628, 433629, 433625, 433634, 433636, 433631, 452659, 428993, 428974, 428918, 428875, 428976, 428850, 428851, 429062, 429072, 429073, 466206, 428958, 459302, 459298, 428852, 474124, 474123, 474122, 459300, 459299, 452669, 452668, 452667, 452666, 452665, 452664, 428965, 428963, 428962, 428961, 459301, 466205, 459271, 452663, 452662, 567763, 428997, 428916, 429000, 430484, 428999, 428874, 428853, 467066, 428975, 428926, 428924, 428973, 428928, 466999, 428998, 466998, 467000, 466997, 415584, 439920, 439919, 459276, 459275, 459274, 459273, 459272, 452647, 445209, 428934, 428933, 428932, 428931, 428930, 428929, 428927, 428925, 428923, 428922, 428917, 245436, 452646, 463872, 452645, 452644, 452643, 452653, 465666, 465667, 428996, 429065, 428936, 428935, 429067, 414149, 377531, 377117, 402552, 385537, 377308, 446366, 389674, 446368, 430486, 194108, 441861, 467002, 446367, 529988, 459314, 446227, 459278, 429738, 439918, 428898, 494550, 447138, 428904, 446215, 446228, 428901, 440938, 428870, 428858, 439315, 428869, 428868, 459283, 452661, 446226, 456208, 428919, 428911, 441785, 428951, 446207, 459285, 494549, 428910, 428878, 494552, 428879, 428912, 428900, 428949, 428897, 429002, 446214, 428913, 446218, 428990, 428909, 529989, 467001, 446225, 428903, 439316, 428880, 259114, 434053, 446216, 455781, 428729, 428881, 494545, 459312, 563555, 442368, 428948, 428876, 432823, 446209, 428952, 459279, 465705, 428905, 428867, 446219, 442746, 470037, 428728, 473902, 439916, 428906, 446221, 428902, 428764, 428097, 446232, 428895, 428921, 428907, 439917, 446222, 428877, 446213, 446231, 494547, 428970, 428892, 494546, 459286, 428896, 446211, 428950, 434052, 459313, 446229, 459282, 459281, 446230, 428954, 428943, 421632, 446208, 446210, 428893, 459287, 494551, 430482, 434054, 505397, 439915, 566856, 428894, 495190, 446223, 459315, 446224, 446217, 446212, 459280, 446220, 459284, 527955, 503446, 571703, 571702, 505399, 470362, 517336, 502961, 502960, 502959, 523794, 523783, 499097, 500678, 500250, 500234, 500238, 500376, 500375, 500277, 527734, 469681, 502524, 467264, 503837, 523512, 469901, 548693, 503363, 503361, 502471, 191083, 500403, 402605, 500806, 527489, 499334, 566478, 548690, 509464, 324067, 527488, 516444, 566477, 566476, 566480, 503267, 509463, 548689, 509461, 523491, 503828, 566479, 487842, 548694, 503864, 503821, 536835, 525300, 525301, 525302, 525304, 525305, 527975, 573364, 555790, 553593, 544157, 544155, 544154, 532325, 527841, 527840, 527130, 527129, 527128, 525727, 525726, 253130, 556388, 532523, 532062, 529706, 529704, 528033, 528032, 528031, 528029, 528028, 528027, 528026, 528020, 528017, 528016, 528012, 528011, 556445, 532064, 532063, 529705, 529703, 528030, 528013, 528010, 527427, 531546, 544156, 532066, 532065, 525866, 507876, 532527, 532526, 532525, 532524, 525867, 500707, 565734, 556437, 536147, 528009, 525872, 525871, 507877, 303148, 508124, 507956, 506583, 527623, 506584, 499281, 527868, 499275, 494646, 499273, 494647, 558372, 529419, 499270, 502381, 499262, 569143, 502382, 502374, 529425, 516463, 495513, 181886, 556447, 508145, 557649, 504074, 557647, 506586, 526898, 526897, 555410, 531547, 531251, 531216, 531217, 526838, 529162, 233282, 452670, 433851, 441767, 441776, 441774, 441780, 414318, 453725, 451647, 451640, 445215, 415852, 445218, 445226, 445223, 445220, 445222, 413049, 445449, 445213, 445214, 453694, 413017, 413020, 454424, 445525, 445216, 445524, 413022, 445227, 445221, 445217, 445224, 444104, 454062, 383637, 544149, 463963, 456468, 539740, 539742, 526098, 542637, 502452, 546744, 564548, 564546, 564545, 505458, 505451, 505419, 569031, 558109, 447141, 447139, 369888, 369465, 368942, 368941, 375003, 369259, 375002, 368943, 368991, 369892, 368940, 368939, 369464, 365063, 368357, 368360, 368359, 361353, 361342, 361339, 361338, 361336, 361334, 294275, 368361, 361379, 361301, 361297, 359890, 295097, 295096, 359885, 295098, 368362, 359859, 368355, 359892, 359883, 359878, 359843, 359841, 359900, 359893, 359888, 359881, 359866, 359864, 359862, 359860, 359855, 359850, 359848, 359846, 298980, 368367, 368354, 368353, 368352, 368351, 368350, 368349, 368348, 359898, 359896, 359887, 359886, 359880, 359871, 359870, 359861, 359857, 359845, 359895, 368366, 359877, 359875, 359865, 359854, 368364, 368365, 359891, 368363, 363581, 369106, 369105, 369104, 369103, 365355, 364413, 368246, 368581, 369258, 326155, 369891, 365351, 252248, 368580, 368579, 343702, 368577, 368247, 369260, 368249, 368938, 365353, 246779, 369744, 369890, 369317, 368248, 365352, 368578, 368250, 505638, 558090, 563295, 504088, 404357, 403656, 403669, 403657, 403699, 404615, 403659, 403697, 403667, 404662, 404614, 404621, 404816, 403671, 516609, 377604, 404789, 404788, 403816, 403662, 403698, 404616, 403668, 403670, 403644, 403658, 403696, 403700, 404663, 404622, 404620, 403666, 403661, 446177, 446176, 467043, 446183, 446182, 446180, 446179, 446181, 415377, 428989, 35591, 428960, 428957, 446178, 441771, 441764, 441782, 441762, 428915, 433469, 441164, 441169, 441166, 441162, 433470, 527987, 527984, 527983, 558115, 516961, 434796, 434791, 567300, 567298, 567199, 517410, 517407, 516995, 476423, 476313, 476306, 476302, 434794, 516991, 516730, 434795, 487811, 434789, 487810, 487808, 434799, 434790, 475886, 487809, 358158, 504201, 500701, 500700, 500699, 500652, 500649, 500645, 369312, 506610, 470338, 558105, 428866, 428861, 428859, 429034, 429033, 428865, 428864, 428862, 428857, 466853, 415760, 428860, 466851, 434125, 428863, 446172, 446166, 446168, 446170, 441897, 467456, 428953, 467457, 467460, 446171, 428955, 467461, 446169, 446167, 466850, 467463, 467462, 467459, 467458, 466852, 429066, 428992, 433873, 433720, 452648, 434263, 434251, 434219, 434197, 434192, 434190, 434170, 434154, 434140, 434138, 423948, 434159, 428889, 434212, 434148, 434207, 428891, 423946, 434141, 428890, 434259, 434216, 441163, 445371, 428971, 465221, 428888, 434147, 434185, 428972, 453093, 434236, 434238, 465247, 434235, 434149, 434167, 434139, 465225, 434182, 433369, 465223, 465248, 465224, 465222, 453092, 434209, 434166, 465226, 423947, 434137, 445210, 428845, 428844, 429083, 429086, 429085, 429084, 429077, 429075, 441766, 429076, 429074, 441781, 441778, 441769, 441761, 433869, 452657, 433870, 488282, 452658, 441770, 441768, 433871, 429001, 428977, 488283);
UPDATE `gameobject_template` SET `Data13`=1, `VerifiedBuild`=62748 WHERE `entry`=499093; -- Forlorn Wind Chime
UPDATE `gameobject_template` SET `VerifiedBuild`=62706 WHERE `entry` IN (191164, 191605, 428864, 429034, 429033, 340644, 525795, 516606, 516620, 516614, 516613, 516611, 516609, 290129, 479243, 479238, 414315, 508717, 495269, 495263, 495261, 495258, 495257, 495255, 495254, 495253, 495267, 495259, 495256, 454064, 459294, 459293, 429081, 459296, 459295, 429068, 469858, 495285, 495213, 479387, 479318, 495242, 495240, 479348, 479338, 494989, 495088, 495202, 479298, 479356, 479337, 495201, 479391, 503699, 479404, 507438, 495192, 479408, 479344, 479327, 507424, 479409, 495295, 517133, 479107, 474287, 494991, 479129, 508776, 474273, 495308, 495022, 495205, 479341, 479328, 507874, 495056, 495089, 469449, 494990, 479215, 508719, 495203, 479418, 505314, 479352, 479390, 479353, 495304, 495231, 479343, 474307, 524230, 507412, 479219, 479325, 495301, 479420, 479402, 495210, 495310, 479324, 495111, 524232, 495058, 524258, 479106, 524233, 479305, 495302, 508773, 507431, 479319, 495063, 495225, 479316, 495282, 479301, 479299, 524229, 474186, 479411, 479414, 479109, 479308, 495228, 507436, 479347, 495078, 479350, 473862, 479351, 479307, 495195, 479297, 524228, 473865, 495287, 495227, 508779, 479340, 495223, 495023, 507407, 495280, 507427, 479332, 495061, 495216, 459336, 495003, 479323, 476312, 479302, 479336, 479313, 495002, 479326, 479309, 479403, 495226, 507420, 495208, 524226, 479130, 495235, 479102, 495191, 507410, 495207, 479132, 507418, 507416, 479354, 495206, 495289, 479339, 479131, 524244, 495220, 479320, 402605, 495212, 524231, 479357, 507434, 473876, 495001, 495296, 495288, 495090, 479355, 495021, 479419, 495199, 479303, 473863, 479317, 488278, 479358, 520268, 479113, 495020, 479311, 520310, 495300, 495143, 479127, 479221, 495283, 479334, 495229, 507439, 508780, 494608, 523846, 508720, 516464, 495241, 495284, 522156, 473861, 479346, 473866, 502902, 495234, 479103, 509490, 461478, 495074, 253127, 479345, 495293, 495309, 479112, 414320, 479128, 474212, 495198, 495217, 495076, 473874, 495224, 474200, 479335, 504152, 495221, 479388, 479304, 495218, 479314, 495004, 495209, 479417, 479329, 495232, 479392, 495073, 456854, 316772, 495303, 525769, 524227, 495281, 479300, 495059, 520336, 524245, 479321, 479315, 454456, 508415, 495196, 495077, 495075, 479322, 479310, 479389, 495194, 495062, 500810, 479331, 479349, 495204, 479114, 495087, 508778, 479108, 495193, 467447, 495239, 495000, 520337, 446145, 473870, 517663, 473872, 473871, 495268, 495230, 473875, 508416, 495233, 520312, 479306, 456792, 479333, 479330, 495215, 475388, 469448, 473873, 429071, 428866, 428862, 452660, 429064, 428855, 433327, 428956, 413020, 413017, 441170, 413877, 441163, 466851, 466853, 415760, 428968, 447140, 447142, 447141, 447139, 434125, 428860, 446166, 446168, 446172, 446167, 441897, 446169, 467463, 467461, 467460, 467459, 467458, 467457, 467456, 466852, 466850, 446171, 446170, 428955, 428953, 428863, 467462, 428976, 428850, 35591, 429066, 428852, 428992, 428851, 429086, 429085, 429084, 429077, 429076, 429075, 429074, 433851, 433470, 433467, 429083, 441781, 441778, 441769, 441766, 441761, 429737, 429070, 433720, 452648, 433873, 433868, 429062, 429072, 429073, 428997, 430484, 488282, 467066, 452658, 452657, 441768, 433871, 433870, 433869, 429000, 428999, 428975, 441770, 488283, 466998, 466997, 441771, 439920, 439919, 429001, 428977, 428916, 428853, 415584, 466999, 441762, 441782, 441764, 445209, 428915, 567763, 467000, 428874, 452659, 441861, 428998, 428993, 428974, 428973, 428875, 428933, 428929, 428928, 428926, 428924, 428918, 428917, 428930, 452647, 428934, 428932, 428931, 428927, 428925, 428923, 428922, 190942, 428858, 428970, 452670, 428990, 421632, 494552, 494551, 494550, 494549, 494547, 494546, 494545, 428881, 428878, 428877, 428951, 428952, 428950, 428948, 467043, 446183, 446182, 446177, 446176, 428957, 415377, 474124, 446181, 446180, 446179, 446178, 433632, 433631, 433630, 433629, 433627, 433626, 433625, 428965, 428962, 428960, 474123, 474122, 459302, 433640, 433639, 433638, 433637, 433636, 433635, 433634, 433633, 433628, 428989, 428963, 428961, 466206, 459298, 452669, 452666, 452665, 452664, 452668, 452667, 428958, 245436, 466205, 459301, 459300, 459299, 452663, 452662, 446211, 446224, 446230, 446212, 459274, 428911, 428904, 428919, 446222, 439918, 459314, 446368, 428903, 446232, 459280, 428921, 442368, 428996, 439917, 446207, 465667, 452643, 452644, 473902, 428870, 459273, 459278, 428943, 446218, 467001, 439315, 456208, 442746, 259114, 529989, 402552, 455781, 563555, 566856, 439316, 428764, 377531, 529988, 428729, 428728, 377308, 470037, 377117, 385537, 495190, 389674, 414149, 459284, 446227, 446220, 459287, 459276, 505397, 428907, 446228, 459279, 428879, 434053, 452661, 446213, 459281, 428949, 434054, 428913, 440938, 446209, 428867, 459282, 428876, 441164, 428097, 428880, 428912, 446229, 433471, 459271, 452645, 459312, 428896, 456777, 433469, 428894, 429067, 446226, 456778, 467002, 446231, 446366, 428906, 434052, 428901, 459272, 428905, 459313, 428954, 459285, 428935, 429002, 430486, 428869, 441785, 452653, 459315, 446214, 428897, 465666, 428936, 439916, 428895, 459283, 446216, 446217, 428900, 428909, 428893, 447138, 459275, 446367, 432823, 428902, 429738, 441169, 441162, 428898, 459286, 452646, 446221, 439915, 446223, 465705, 463872, 441166, 446215, 454424, 429065, 446225, 430482, 446208, 428892, 428868, 446210, 446219, 428910);
UPDATE `gameobject_template` SET `VerifiedBuild`=62493 WHERE `entry` IN (210059, 207646, 298892, 273293, 243460, 206733, 206529, 204624, 197280, 204625, 243459, 307614, 204620, 207099, 207101, 206709, 452029, 273286, 204723, 206708, 339344, 207100, 197276, 273300, 243462, 197287, 197284, 204626, 206538, 207098, 207094, 279294, 206549, 243461, 204627, 179707, 279295, 207097, 207096, 206546, 206545, 206539, 204725, 204724, 204634, 204633, 204632, 204631, 204628, 204204, 202717, 197323, 197279, 197257, 206741, 206735, 206729, 206530, 204730, 204729, 204623, 204621, 204203, 204195, 204192, 278281, 206736, 204710, 204709, 204640, 204622, 204607, 204200, 204197, 204196, 204191, 203979, 350063, 204639, 204610, 204608, 204606, 204605, 204205, 204198, 204194, 175788, 175787, 206995, 204609, 204604, 204611, 204209, 204199, 203378, 202590, 184633, 269949, 204603, 204602, 386349, 377216, 281340, 206725, 204657, 204601, 204600, 204214, 204210, 204207, 206737, 204666, 204665, 204658, 204645, 204193, 204179, 323854, 204212, 204163, 204202, 205109, 206727, 204647, 206610, 355229, 204650, 204656, 223739, 204651, 204663, 204201, 206110, 204662, 323855, 204664, 204211, 332214, 204208, 323851, 204646, 223814, 205108, 190549, 205142, 206726, 210181, 206609, 204213, 186238, 206608, 323852, 207414, 323853, 323849, 452407, 204655, 179881, 323850, 383583, 203969, 204215, 495326, 495325, 428859, 218870, 563555, 502959, 508124, 507956, 551890, 551884, 502547, 477617, 477615, 467439, 467437, 467436, 553513, 551887, 502452, 505638, 569031, 558109, 569033, 569032, 546744, 505458, 505451, 505419, 547547, 532323, 532322, 532321, 532318, 532317, 517405, 517410, 517407, 517000, 516995, 516991, 516730, 487808, 434790, 475886, 500701, 500700, 500699, 500652, 500649, 500645, 434799, 504201, 567736, 506610, 470338, 527489, 566479, 503837, 566476, 500806, 558105, 527488, 566477, 502524, 402605, 500403, 566480, 504088, 566478, 503821, 503828, 503864, 567763, 428997, 517352, 516611, 516606, 516609, 516614, 525795, 516613, 516620, 499031, 499022, 493978, 486011, 494217, 494175, 494171, 494160, 494157, 494141, 494112, 494107, 494105, 494104, 494100, 494083, 494071, 494065, 494064, 494029, 494022, 493995, 493972, 493952, 493944, 493924, 493920, 500274, 499028, 311875, 327123, 327122, 327099, 327096, 327118, 327106, 327102, 327101, 327100, 327098, 327097, 327088, 494239, 494225, 494015, 494008, 493998, 327087, 327086, 327085, 327084, 327080, 327079, 327078, 494099, 327083, 327082, 327081, 327047, 327052, 327063, 341376, 327129, 327064, 327062, 327044, 327065, 327128, 327116, 327104, 327095, 327092, 327130, 327121, 327120, 327117, 327115, 327105, 327103, 327091, 327089, 327046, 327124, 327110, 327109, 327108, 327107, 327094, 327093, 273683, 332128, 327127, 327126, 327125, 327119, 327114, 327113, 327112, 327111, 327090, 327061, 327060, 327059, 327058, 327057, 327056, 327055, 327051, 517349, 327073, 327072, 327071, 327070, 327050, 327074, 341375, 327045, 494218, 327076, 327075, 327054, 327068, 327049, 327077, 327069, 327048, 527691, 327067, 327066, 326745, 338611, 338608, 338607, 338606, 338605, 338604, 338603, 338602, 516143, 341374, 326795, 326794, 326746, 326767, 326742, 334897, 326768, 326766, 326765, 326764, 326763, 326762, 326761, 326760, 326754, 326740, 516145, 338688, 326739, 338691, 338690, 338689, 326741, 517348, 326777, 326776, 326775, 326774, 326769, 326752, 326750, 326749, 326748, 338192, 326773, 326772, 326771, 326770, 326756, 326738, 326757, 326789, 326788, 326787, 326790, 334859, 326792, 326791, 326786, 326759, 326751, 326743, 273834, 326793, 326753, 326744, 341373, 326785, 326784, 326783, 326782, 326781, 326780, 326779, 326778, 326758, 499029, 200320, 200318, 200331, 200330, 200329, 200328, 200327, 200326, 200323, 200322, 200321, 200319, 327017, 527781, 326965, 326962, 326961, 326960, 326959, 326958, 326957, 326956, 326955, 326954, 200317, 200316, 339999, 334846, 326969, 326968, 326967, 326966, 326964, 326963, 326926, 326925, 326929, 341372, 200312, 326927, 326928, 200313, 200307, 337224, 336854, 200314, 200308, 200306, 200315, 200311, 200310, 200309, 326953, 326952, 326915, 341371, 326945, 326944, 326943, 326942, 326941, 326940, 326939, 326938, 326912, 326937, 326936, 326914, 517350, 326951, 326950, 326949, 326948, 326947, 326946, 326935, 326934, 326933, 336802, 326931, 326930, 326923, 326920, 326918, 326917, 326911, 326910, 336434, 334913, 326922, 326921, 326919, 326916, 326932, 326913, 499026, 499038, 326861, 339190, 326886, 326884, 326878, 326885, 326883, 334130, 326882, 326881, 326880, 326879, 341370, 326865, 326863, 326894, 326893, 326870, 326869, 326868, 326867, 326866, 326864, 326862, 326909, 326907, 326905, 326904, 326897, 326896, 326895, 326908, 326906, 326903, 326900, 326898, 326899, 326901, 326902, 326889, 326887, 349578, 326892, 326891, 326890, 326888, 326859, 334122, 326857, 326853, 326852, 326856, 339269, 339266, 326858, 326854, 339267, 326877, 326876, 326875, 340001, 326874, 326873, 326872, 326871, 326855, 326860, 349577, 341369, 334903, 327034, 327016, 334860, 327015, 327013, 327007, 327006, 327004, 326987, 326983, 341406, 327005, 326992, 326990, 326997, 326991, 327008, 327009, 339246, 341883, 341882, 339245, 326996, 327010, 327011, 326995, 326989, 326994, 326993, 326988, 327463, 339240, 327003, 327002, 327001, 327000, 326999, 326998, 326747, 326985, 326970, 500098, 327033, 326975, 517344, 500099, 341367, 500100, 327036, 326984, 326982, 326976, 343667, 341342, 341340, 341339, 341337, 327035, 327032, 326986, 326981, 326980, 326979, 326978, 326977, 327030, 341338, 327040, 326971, 327041, 494143, 327024, 326973, 334845, 327020, 327037, 341341, 327028, 327019, 327027, 326972, 327042, 327026, 327025, 327038, 494237, 341368, 327014, 327039, 327022, 327012, 327023, 327031, 327021, 327029, 327018, 495367, 332151, 336708, 326755, 327053, 326924, 339270, 332597, 336907, 326974, 334813, 336908, 523457, 523452, 523456, 335499, 494167, 493974, 334807, 316396, 494050, 334492, 334120, 321685, 334812, 332301, 326606, 334121, 548693, 503363, 503361, 502891, 506584, 527623, 523794, 523783, 508145, 467522, 504075, 504074, 557649, 557647, 506586, 500376, 500375, 500277, 527734, 502382, 502381, 502374, 529425, 499276, 499262, 529435, 529419, 495513, 507470, 469681, 467264, 499082, 473920, 433369, 487842, 509464, 509463, 509461, 499334, 543787, 191605, 208607, 503568, 508125, 299078, 489974, 528436, 503552, 467105, 467107, 467124, 467154, 467143, 467093, 507968, 467109, 467137, 467158, 502538, 507783, 505620, 467129, 467155, 467159, 467110, 467150, 467136, 467131, 467098, 467134, 467135, 502539, 467099, 508146, 467115, 467125, 467102, 467119, 467113, 502540, 467114, 467123, 467126, 467162, 507960, 467112, 467106, 467116, 467147, 467111, 467151, 465030, 507972, 467122, 467165, 467142, 446175, 446174, 446173, 422491, 413877, 444298, 444294, 444295, 479606, 439251, 417152, 449707, 439312, 437085, 433643, 413883, 452706, 451674, 444310, 444309, 444307, 430555, 422531, 421126, 421121, 455610, 444308, 444300, 411623, 452945, 452944, 452943, 455269, 494956, 452680, 411497, 411498, 457361, 425875, 411381, 455603, 439777, 449751, 250825, 414317, 459336, 414315, 451440, 443532, 432835, 454063, 453183, 413049, 441968, 369892, 368381, 368382, 370083, 368383, 368942, 369888, 375003, 375002, 368941, 368940, 369465, 369464, 368991, 368943, 368939, 365063, 369887, 369259, 368937, 369889, 369466, 369467, 369316, 369315, 369891, 369890, 326155, 343702, 368578, 368577, 368579, 368581, 368580, 365352, 368248, 369260, 368250, 369317, 368246, 365353, 368938, 368247, 369258, 369744, 368249, 365351, 367994, 544149, 463963, 563295, 558090, 527987, 527984, 527983, 558115, 434796, 476423, 476313, 476306, 476302, 507058, 434789, 487809, 452659, 414325, 422548, 446285, 446287, 446297, 446282, 446290, 446280, 446276, 446286, 446298, 446283, 446284, 413713, 446275, 446291, 446293, 424429, 446292, 446277, 413694, 446295, 444293, 444296, 444297, 444291, 444332, 444283, 444282, 444290, 444288, 444286, 444292, 444333, 444287, 444317, 444313, 444322, 444321, 444319, 444312, 444331, 444330, 444329, 444328, 444327, 444326, 444323, 444320, 444318, 444316, 444315, 444314, 444311, 444289, 444285, 444284, 444338, 444337, 444336, 444335, 444325, 444324, 444304, 444280, 444278, 194999, 444340, 465243, 430556, 444339, 464938, 465242, 465241, 444334, 421127, 421128, 414597, 413886, 414316, 454081, 502485, 504082, 504073, 504081, 504084, 441166, 500727, 500728, 500678, 500250, 500234, 516463, 500238, 495605, 495603, 516961, 525662, 434791, 567300, 567298, 567199, 434794, 434795, 487811, 487810, 454062, 414318, 197085, 197084, 197083, 197082, 197081, 197080, 197079, 197014, 190536, 197188, 203978, 202003, 197189, 197119, 278802, 270011, 202260, 202259, 202258, 202257, 202256, 202253, 202006, 201996, 201993, 197193, 197192, 197191, 197186, 197185, 197138, 197134, 197033, 197008, 254093, 254102, 202005, 254120, 254110, 197028, 197029, 205553, 254095, 201983, 254088, 197032, 254113, 202011, 254112, 197010, 201999, 201998, 197099, 254114, 254100, 197093, 202002, 197035, 197088, 197126, 254122, 259008, 197092, 197098, 197012, 197021, 197031, 197179, 197037, 197011, 197030, 197176, 254092, 209297, 323846, 197181, 197123, 197041, 201987, 254103, 254116, 197125, 197183, 197026, 197089, 202010, 254109, 197025, 254108, 197036, 197009, 197013, 202004, 254123, 197039, 279608, 377200, 335930, 294556, 1561, 140911, 105175, 209692, 175758, 203800, 203801, 322639, 193981, 386352, 175729, 250672, 203762, 105174, 197023, 197038, 254104, 254111, 197182, 197136, 197020, 332224, 207661, 254094, 197042, 197090, 254099, 254105, 197086, 254089, 197024, 323844, 197018, 197184, 254119, 254118, 197097, 197017, 197087, 254098, 254115, 197040, 197034, 197096, 254117, 197177, 197091, 197027, 197015, 197180, 254106, 254107, 201989, 254101, 197178, 197140, 197022, 207416, 254121, 361342, 361339, 361338, 361336, 361334, 294275, 368361, 361379, 361301, 361297, 359890, 359885, 295098, 295097, 295096, 368362, 359859, 368355, 359892, 359883, 359843, 359841, 359900, 359893, 359888, 359881, 359878, 359870, 359866, 359864, 359862, 359860, 359855, 359850, 359848, 359846, 298980, 368354, 368353, 368352, 368351, 368350, 368349, 368348, 359898, 359896, 359887, 359886, 359880, 359871, 359861, 359845, 368367, 359895, 359875, 359857, 368366, 359877, 359865, 359854, 368365, 368364, 363581, 359891, 368363, 369106, 369105, 369103, 369104, 364413, 365355, 190942, 296695, 296694, 296697, 296696, 296709, 296710, 296711, 288166, 296708, 296707, 291223, 273814, 296705, 296704, 295084, 295083, 295082, 295081, 273766, 296627, 273522, 293191, 276486, 276471, 296701, 278521, 290754, 272792, 272755, 293840, 295800, 295799, 295798, 303028, 303027, 278507, 278482, 278406, 277515, 276200, 276201, 278528, 276242, 276203, 288489, 276206, 276202, 279289, 276204, 278295, 276205, 290145, 288488, 290146, 288490, 288491, 279703, 272201, 272200, 280693, 295269, 295268, 295267, 295266, 295265, 295264, 295263, 295262, 276622, 295218, 295219, 295217, 278252, 295902, 295901, 295900, 295899, 295898, 295802, 295801, 295778, 295321, 295313, 295271, 295270, 295261, 295260, 295259, 295258, 295221, 295200, 289310, 282250, 281718, 280992, 296390, 295227, 295226, 295275, 295274, 295273, 295272, 295247, 295246, 295206, 294477, 294476, 294475, 295277, 295276, 276621, 297479, 287404, 278402, 278399, 273956, 292917, 278361, 271866, 292916, 292914, 292912, 292911, 278405, 278359, 302838, 294922, 294895, 294894, 294811, 278357, 276618, 278809, 294967, 277717, 207438, 278695, 207453, 207440, 294907, 302802, 302797, 302799, 302798, 302796, 294908, 290781, 294964, 302803, 294909, 295002, 295003, 277415, 302801, 302800, 277386, 295008, 295010, 277427, 295039, 295418, 295037, 290782, 276616, 295043, 276234, 294881, 295036, 295038, 295040, 295032, 295031, 295030, 295029, 294971, 294970, 294959, 294926, 294925, 294838, 294837, 290780, 276619, 276617, 276239, 294969, 293755, 297635, 277419, 269098, 295460, 295115, 295114, 295113, 295112, 295111, 295110, 294978, 294968, 294960, 294937, 294924, 294920, 294835, 290777, 288641, 281079, 292913, 279319, 279318, 213637, 292915, 276236, 295716, 294995, 294997, 292910, 294994, 295715, 295714, 294993, 294996, 288632, 294232, 294234, 294231, 294233, 294992, 303084, 281230, 294936, 294490, 295365, 294493, 294492, 294491, 294489, 294488, 295016, 295017, 295015, 294930, 278571, 276240, 303085, 303013, 303012, 303011, 303010, 303005, 302995, 295765, 295758, 295028, 294946, 294253, 294246, 294242, 302998, 295770, 294245, 294244, 295766, 295402, 295470, 295759, 295461, 294241, 294247, 294248, 294243, 295769, 295401, 294240, 294239, 295768, 295767, 295021, 295720, 295719, 295762, 303007, 295776, 297905, 295718, 295467, 295773, 295717, 294903, 302996, 295763, 295774, 295777, 295775, 302997, 295760, 316675, 294904, 294238, 295764, 303001, 303009, 295761, 303008, 294237, 294902, 303006, 295756, 303004, 302994, 295757, 295771, 295753, 294858, 295772, 295755, 295754, 301132, 295473, 295471, 295462, 295487, 321724, 321725, 303002, 294961, 303000, 301133, 321753, 321754, 321734, 321730, 321721, 321720, 321719, 321718, 317398, 312156, 303003, 302999, 295486, 295476, 295415, 295020, 294847, 294487, 294486, 294485, 294484, 294483, 294482, 294481, 365071, 365070, 302791, 302790, 295399, 295398, 295019, 295018, 294999, 294998, 294977, 294973, 294906, 294857, 294856, 365069, 365068, 365067, 365066, 365065, 365064, 323531, 303146, 295025, 295024, 295023, 295022, 294905, 294807, 292873, 293965, 313618, 295049, 295057, 312208, 323548, 295417, 323383, 295056, 295055, 295054, 295053, 295052, 295051, 295050, 295048, 294975, 294974, 294948, 289693, 214679, 295364, 294954, 298884, 316904, 295411, 299257, 321760, 316427, 295469, 369893, 302948, 301129, 301127, 295362, 302839, 298886, 302945, 298882, 294949, 294546, 294898, 292872, 299260, 288469, 299254, 292547, 302940, 294888, 296478, 295088, 299261, 316423, 325968, 294887, 292871, 295357, 301130, 295087, 299262, 293552, 298881, 303145, 299009, 298911, 295363, 239178, 302857, 298883, 301131, 316422, 281609, 298912, 298909, 295089, 293838, 298913, 293844, 294952, 321797, 295090, 288433, 296155, 316430, 295409, 295094, 302941, 302947, 301135, 295432, 294544, 298914, 295086, 239179, 299008, 299258, 298910, 302942, 299265, 312127, 294900, 278570, 316429, 302950, 302946, 295414, 280662, 294899, 295360, 292695, 295481, 294963, 293132, 294951, 295093, 299344, 299263, 298885, 299250, 294953, 299253, 302858, 294950, 294891, 299252, 295358, 299343, 299322, 295095, 282465, 299255, 299259, 303207, 292869, 294897, 321795, 294976, 302944, 229465, 297937, 295092, 294890, 294543, 253128, 309572, 296460, 299342, 306854, 295361, 282258, 299264, 325967, 299251, 299256, 302949, 297145, 281647, 294889, 292870, 316424, 287435, 281065, 298915, 294545, 303018, 294896, 282246, 279717, 279586, 188215, 295091, 303017, 207870, 204962, 207872, 207869, 207657, 203691, 214501, 203218, 203456, 203454, 203623, 203388, 203693, 203622, 203213, 203616, 202887, 207871);
UPDATE `gameobject_template` SET `Data13`=1, `VerifiedBuild`=62493 WHERE `entry`=499093; -- Forlorn Wind Chime
UPDATE `gameobject_template` SET `Data13`=1, `VerifiedBuild`=62493 WHERE `entry`=499093; -- Forlorn Wind Chime
UPDATE `gameobject_template` SET `Data13`=1, `VerifiedBuild`=62493 WHERE `entry`=499093; -- Forlorn Wind Chime
UPDATE `gameobject_template` SET `displayId`=85943, `VerifiedBuild`=63305 WHERE `entry`=187267; -- Romantic Basket
UPDATE `gameobject_template` SET `ContentTuningId`=1033, `VerifiedBuild`=63305 WHERE `entry`=212386; -- Weapon Rack
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=212943; -- Heart of Fear - Zor'lok - Final Phase Doors
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=212916; -- Heart of Fear - Zor'lok - Arena Wall
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=213277; -- The Empress' Chamber
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214488; -- Doodad_Mantid_Door_025
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=213276; -- Mantid Queen Ceiling
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214493; -- Doodad_Mantid_Door_033
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214491; -- Doodad_Mantid_Door_031
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214634; -- Garalon Door (Upper)
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214490; -- Doodad_Mantid_Door_027
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214492; -- Doodad_Mantid_Door_032
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214489; -- Doodad_Mantid_Door_026
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214483; -- Doodad_Mantid_Door_017
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214485; -- Doodad_Mantid_Door_021
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214487; -- Doodad_Mantid_Door_024
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214484; -- Doodad_Mantid_Door_020
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=214486; -- Doodad_Mantid_Door_022
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=63305 WHERE `entry`=212695; -- Garalon Door
UPDATE `gameobject_template` SET `Data6`=0, `Data26`=1, `ContentTuningId`=62, `VerifiedBuild`=63305 WHERE `entry`=215761; -- East Feeder
UPDATE `gameobject_template` SET `Data6`=0, `Data26`=1, `ContentTuningId`=62, `VerifiedBuild`=63305 WHERE `entry`=215703; -- North Feeder
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=63305 WHERE `entry`=212524; -- Inactive Sonic Relay
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=63305 WHERE `entry`=213250; -- Silent Beacon
UPDATE `gameobject_template` SET `ContentTuningId`=173, `VerifiedBuild`=63305 WHERE `entry`=213303; -- He's Poison Trap
UPDATE `gameobject_template` SET `ContentTuningId`=173, `VerifiedBuild`=63305 WHERE `entry` IN (213289, 214948); -- Shao-Tien Cage
UPDATE `gameobject_template` SET `ContentTuningId`=173, `VerifiedBuild`=63305 WHERE `entry`=213180; -- Guo-Lai Runestone
UPDATE `gameobject_template` SET `ContentTuningId`=173, `VerifiedBuild`=63305 WHERE `entry`=214901; -- Shao-Tien Stormcaller
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=41520, `ContentTuningId`=60, `VerifiedBuild`=63305 WHERE `entry`=211312; -- Explosives Barrel
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63305 WHERE `entry`=211171; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=63305 WHERE `entry`=211170; -- Forge
UPDATE `gameobject_template` SET `Data19`=2, `Data26`=0, `ContentTuningId`=60, `VerifiedBuild`=63305 WHERE `entry`=213770; -- Stolen Sprite Treasure
UPDATE `gameobject_template` SET `ContentTuningId`=344, `VerifiedBuild`=63305 WHERE `entry`=268813; -- Moon Lily
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=63305 WHERE `entry`=290478; -- Forge
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=63305 WHERE `entry`=291106; -- Barricade
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63305 WHERE `entry`=289738; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=63305 WHERE `entry`=289737; -- Forge
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=62876 WHERE `entry`=359882; -- Forge
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=62876 WHERE `entry`=359847; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=62876 WHERE `entry`=359852; -- Anvil
UPDATE `gameobject_template` SET `Data3`=0, `VerifiedBuild`=62876 WHERE `entry`=369107; -- Titan Console
UPDATE `gameobject_template` SET `ContentTuningId`=51, `VerifiedBuild`=62876 WHERE `entry`=192774; -- Lock Gate
UPDATE `gameobject_template` SET `ContentTuningId`=51, `VerifiedBuild`=62876 WHERE `entry`=191820; -- Vrykul Banner
UPDATE `gameobject_template` SET `ContentTuningId`=51, `VerifiedBuild`=62876 WHERE `entry`=193028; -- War Horn of Jotunheim
UPDATE `gameobject_template` SET `ContentTuningId`=51, `VerifiedBuild`=62876 WHERE `entry`=192135; -- Jotunheim Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=62801 WHERE `entry` IN (428864, 428862, 429034, 429033, 466853, 466851, 415760, 402852, 452659, 428993, 447140, 447142, 447139, 447141, 415377, 429075, 429077, 429074, 429085, 429076, 429086, 429084, 456777, 433851, 433469, 433467, 441781, 441778, 441769, 441766, 441761, 429083, 428977, 441770, 428860, 446172, 446169, 446168, 446167, 446166, 441897, 434125, 428863, 467461, 467460, 467457, 467456, 428970, 428955, 428953, 428858, 467462, 466852, 429066, 428976, 428992, 428850, 467463, 35591, 446171, 467458, 446170, 467459, 466850, 428852, 428851, 429062, 488283, 488282, 441764, 441771, 441768, 452658, 452657, 433871, 433870, 452648, 433873, 433869, 433720, 429001, 428999, 429072, 429073, 459292, 459291, 459296, 459295, 459294, 459293, 459290, 459289, 429081, 429080, 455920, 439252, 437751, 437749, 437743, 437617, 437616, 437615, 437614, 437613, 437612, 429079, 429078, 429069, 437610, 437606, 437609, 437608, 437604, 437611, 437605, 437618, 452655, 437746, 452656, 452654, 437625, 437624, 437623, 437622, 437621, 437607, 437755, 437595, 437594, 428990, 437590, 437756, 437591, 437758, 421632, 437761, 437757, 437603, 437602, 437601, 437600, 437599, 437596, 437593, 437592, 437589, 437588, 437587, 437586, 437585, 437584, 437583, 437582, 437554, 432948, 453182, 437550, 443320, 437551, 517352, 429061, 525795, 516620, 516614, 516613, 516611, 516609, 516606, 452670, 429068, 429058, 433868, 429737, 429071, 429070, 429000, 428997, 430484, 441782, 441762, 428915, 428916, 428974, 428875, 567763, 467066, 428975, 428874, 428853, 428973, 428926, 428924, 428918, 428917, 466999, 466998, 428998, 428928, 467000, 439920, 428934, 428933, 428932, 428929, 428925, 415584, 428930, 428923, 452647, 428931, 428927, 428922, 445209, 446177, 446176, 467043, 446183, 446182, 446181, 446180, 446179, 446178, 433632, 433631, 433630, 433629, 433627, 433626, 433625, 428960, 428957, 433640, 433639, 433628, 428965, 459302, 459298, 433638, 433637, 433636, 433635, 433634, 433633, 428989, 428963, 466206, 428958, 245436, 463872, 452646, 474124, 474123, 452666, 452665, 452664, 428962, 428961, 452669, 474122, 452667, 459300, 452668, 452662, 459299, 452663, 466205, 459301, 452644, 452643, 465667, 452645, 459276, 459275, 459274, 459273, 459272, 459271, 439919, 466997, 494551, 465666, 429065, 494552, 494550, 494549, 494547, 494546, 494545, 428952, 428951, 428950, 428948, 428881, 428878, 428877, 428909, 428912, 441785, 459285, 429738, 467002, 446230, 434052, 428913, 428869, 428903, 446212, 459280, 428893, 446213, 428896, 459314, 428996, 446216, 428921, 459282, 465705, 446229, 446217, 428949, 429002, 446226, 430486, 446231, 428880, 459286, 452653, 446208, 459279, 428943, 428895, 459287, 446215, 428868, 446209, 446220, 446227, 447138, 446219, 428907, 442746, 563555, 439316, 439315, 259114, 455781, 402552, 377117, 428764, 389674, 414149, 529988, 470037, 377308, 441861, 566856, 190942, 428729, 529989, 377531, 385537, 495190, 456208, 428728, 446222, 446210, 505397, 428901, 446214, 446232, 429067, 432823, 446223, 428870, 428898, 446218, 439916, 446224, 446207, 428911, 434053, 459281, 428910, 459312, 446228, 456778, 428954, 428097, 446211, 459284, 439918, 439915, 428935, 428892, 428879, 428905, 446368, 459278, 454424, 441162, 430482, 433470, 446367, 428906, 459283, 441164, 428919, 428876, 473902, 440938, 428904, 467001, 459313, 428894, 446225, 433471, 446366, 434054, 459315, 442368, 428900, 452661, 428897, 446221, 428902, 428936, 428867, 439917);
UPDATE `gameobject_template` SET `VerifiedBuild`=62680 WHERE `entry` IN (190942, 429737, 429071, 429070, 433868, 452659, 428993, 447140, 446181, 446180, 446179, 446178, 446177, 428957, 447142, 447139, 428960, 428989, 446182, 446183, 466206, 459302, 459298, 447141, 415377, 446176, 459300, 459299, 428958, 459301, 441761, 430484, 452648, 441781, 441778, 441770, 441769, 433873, 433720, 428997, 488282, 433870, 428977, 433871, 452657, 433869, 488283, 452658, 441768, 429000, 428999, 441771, 428975, 429001, 467066, 441764, 428853, 441762, 441782, 428915, 428916, 441861, 428875, 567763, 428974, 428874, 466998, 467000, 466999, 466997, 452647, 445209, 439920, 439919, 428998, 428973, 428934, 428933, 428932, 428930, 428929, 428928, 428926, 428925, 428924, 428918, 428917, 415584, 428923, 428927, 428922, 245436, 428931, 452646, 463872, 452645, 452644, 452643, 465667, 465666, 428996, 428936, 439315, 439917, 467002, 430482, 439316, 428919, 429738, 428935, 467001, 439918, 439916, 439915, 430486, 466205, 456208, 428893, 428892, 428868, 459286, 459285, 459282, 459280, 459276, 459275, 459274, 459273, 459272, 459271, 446368, 428903, 428901, 428870, 428869, 428867, 446366, 428900, 428912, 428913, 452661, 428907, 428910, 459279, 428911, 459287, 459284, 459283, 459281, 459278, 429002, 428943, 446367, 402552, 377308, 377117, 505397, 446232, 446231, 446211, 446210, 428905, 428904, 428897, 428895, 414149, 389674, 385537, 377531, 429065, 428906, 428896, 494552, 494546, 446230, 446213, 429067, 428921, 459313, 446220, 494550, 459314, 494545, 494547, 459312, 428898, 459315, 494549, 446222, 428764, 465705, 566856, 563555, 446228, 446227, 446221, 446219, 446217, 446214, 446212, 446209, 446207, 434054, 434053, 434052, 428909, 428902, 428894, 446229, 446226, 446224, 446216, 428097, 494551, 446225, 446218, 446208, 455781, 447138, 441897, 446223, 446215, 428990, 428965, 428963, 428961, 428876, 429066, 446166, 429062, 467461, 440938, 428858, 452667, 495190, 467458, 446168, 428863, 428850, 446167, 473902, 428954, 428953, 428851, 474122, 446170, 452664, 441785, 466851, 466850, 428962, 452669, 428862, 446169, 428877, 428992, 452662, 428864, 428976, 428955, 467460, 452653, 428949, 428950, 467459, 452668, 428857, 466852, 467463, 474124, 446171, 442368, 452665, 428728, 429034, 35591, 428880, 428860, 415760, 429073, 428879, 421632, 434125, 432823, 446172, 428881, 428951, 467456, 429033, 428729, 428952, 428852, 428878, 467462, 428970, 452663, 442746, 428948, 547529, 452666, 474123, 466853, 467457, 429072, 441968, 355590, 355589, 527975, 349098, 349099, 469490, 349933, 353277, 353262, 353274, 233282, 353280, 353297, 353271, 353180, 353276, 349931, 353284, 353287, 353178, 353290, 353302, 353304, 353298, 353261, 349295, 349935, 353301, 352524, 353179, 355593, 349294, 353048, 353286, 353783, 353269, 355591, 353291, 353275, 246779, 353049, 353300, 349936, 353782, 353056, 355592, 179944, 358269, 334915, 344755, 352508, 352054, 352484, 358279, 352462, 358273, 352505, 272724, 358281, 352506, 352503, 358282, 352010, 358272, 352575, 365226, 352006, 352001, 352522, 358275, 352483, 352467, 352608, 352486, 351431, 352056, 358300, 352507, 358548, 352468, 352465, 339994, 352471, 352016, 352053, 339238, 352487, 352501, 358276, 352480, 358299, 358274, 358271, 352504, 352463, 352502, 351997, 352610, 352051, 352052, 352049, 352008, 352050, 351993, 339853, 352469, 358278, 352015, 358270, 352470, 344794, 353378, 353174, 354206, 358280, 353175, 358277, 352482, 327444, 337226, 190549, 206737, 204666, 204665, 204658, 204645, 204193, 204179, 204657, 452407, 355229, 332214, 323855, 323853, 323852, 323851, 323850, 323849, 204656, 204646, 197323, 206538, 204604, 204602, 204192, 223814, 207414, 206546, 206735, 204215, 204212, 204213, 204601, 204214, 197257, 202717, 204191, 206539, 243461, 204607, 204198, 279295, 210181, 529988, 279294, 386349, 175787, 205142, 179707, 175080, 470037, 203969, 175788, 339344, 203378, 273300, 184633, 377216, 206110, 281340, 350063, 259114, 203979, 529989, 206610, 206729, 207094, 204723, 197276, 204600, 204209, 204200, 206530, 223739, 204710, 269949, 197284, 204202, 204663, 204627, 197279, 207098, 204610, 243462, 206736, 207889, 204729, 204197, 204611, 204210, 204196, 204620, 206545, 206727, 204195, 210059, 204623, 204639, 204632, 206741, 204603, 204709, 196837, 204194, 204163, 204199, 204651, 152614, 204725, 204208, 204606, 204730, 204621, 204634, 204205, 204204, 204647, 204203, 204608, 204655, 204211, 204201, 207096, 206609, 278281, 202590, 204628, 205108, 204633, 204640, 206608, 207646, 204622, 204605, 204631, 206995, 206726, 204724, 197287, 204662, 204609, 204650, 383583, 207100, 205109, 204664, 204207, 207097, 206725, 323854, 206549, 204626);
UPDATE `gameobject_template` SET `Data13`=1, `VerifiedBuild`=62493 WHERE `entry`=499093; -- Forlorn Wind Chime
UPDATE `gameobject_template` SET `Data13`=1, `VerifiedBuild`=62493 WHERE `entry`=499093; -- Forlorn Wind Chime
UPDATE `gameobject_template` SET `VerifiedBuild`=62438 WHERE `entry` IN (369114, 495326, 495325, 428859, 444197, 453747, 453367, 206995, 386349, 377216, 281340, 269949, 206725, 204657, 204603, 204602, 204601, 204600, 204214, 204210, 204209, 204207, 206737, 204666, 204665, 204658, 204645, 204193, 204179, 210181, 204212, 204662, 207414, 204215, 206610, 204208, 204655, 205109, 452407, 204646, 204647, 204201, 383583, 204213, 323852, 206726, 323851, 203969, 323850, 204656, 355229, 205142, 206727, 205108, 204664, 204211, 204650, 332214, 206609, 223814, 204163, 323849, 214229, 206608, 323853, 204202, 204663, 323855, 204651, 223739, 206110, 323854, 259834, 242128, 242127, 259351, 259285, 242220, 250514, 250513, 259284, 246002, 247849, 247848, 245355, 248843, 248842, 245368, 259390, 248841, 245353, 259387, 248844, 250435, 259380, 268065, 242648, 259346, 244824, 259345, 242640, 242639, 248093, 242641, 242638, 242637, 242636, 242050, 245661, 245691, 245662, 247691, 268057, 249919, 382531, 382535, 382533, 382534, 382532, 242049, 259349, 242054, 188215, 245663, 242123, 258330, 259348, 242048, 242047, 259391, 250473, 247018, 246941, 251312, 251311, 269967, 242037, 259287, 268044, 242052, 241922, 259397, 242202, 242042, 250516, 241969, 242231, 242130, 245833, 250300, 259276, 250333, 241961, 415412, 259312, 250494, 259273, 259275, 250436, 252331, 250337, 241943, 250350, 235099, 241419, 250519, 250451, 250299, 250347, 259382, 250518, 250506, 250471, 260236, 250477, 246463, 369301, 242040, 246943, 259303, 250517, 241955, 250332, 242200, 259306, 246262, 245623, 241453, 242198, 242170, 259341, 235100, 259272, 241445, 259307, 242226, 250470, 242215, 241964, 241620, 259304, 242126, 266618, 259268, 250472, 242229, 259311, 259338, 250339, 266851, 242118, 246008, 250318, 250355, 268053, 242225, 246708, 241956, 267068, 250314, 200297, 241950, 246154, 259336, 250334, 241948, 241958, 250523, 241920, 259264, 250502, 250455, 242223, 242041, 251305, 250460, 244651, 246258, 194115, 259289, 242237, 250483, 246257, 250352, 242169, 250524, 246009, 251105, 251594, 278457, 250343, 248079, 250467, 241960, 259334, 250469, 250498, 242038, 250320, 242045, 259398, 250468, 250359, 250438, 259292, 268052, 249731, 250214, 268051, 259835, 259309, 280797, 250450, 251592, 259291, 259265, 247013, 259262, 241946, 251992, 268074, 251580, 242044, 241512, 248516, 250357, 250297, 250525, 259281, 268048, 250456, 242176, 259317, 250478, 247337, 259293, 259415, 258327, 250481, 246261, 250354, 259350, 246013, 244560, 259270, 250338, 250360, 250515, 242201, 268078, 250349, 259310, 250335, 259381, 268072, 200296, 246942, 250461, 250474, 249362, 259277, 259271, 251582, 250631, 259347, 242129, 259290, 250509, 259280, 259274, 241952, 246466, 259283, 250340, 250452, 242224, 246465, 242132, 250319, 242216, 250358, 268081, 241945, 250499, 250341, 242125, 250331, 241954, 250315, 259266, 250480, 250464, 259343, 250508, 241447, 241944, 259426, 250512, 250490, 268049, 259394, 250504, 250505, 246001, 259295, 244562, 250219, 241968, 250493, 244536, 250485, 249732, 250497, 250500, 251584, 268046, 250495, 251595, 259392, 259384, 250336, 250313, 242234, 266736, 249730, 250215, 250527, 244534, 242228, 251593, 250217, 242218, 242199, 242051, 241921, 267991, 259344, 259396, 246944, 241966, 268059, 241947, 258328, 242131, 250322, 268061, 278574, 247019, 250323, 241949, 266619, 259335, 250454, 242039, 241506, 251581, 247858, 250507, 242235, 259339, 241965, 250511, 250487, 268043, 250503, 242043, 250344, 241972, 250520, 250484, 250476, 241513, 241970, 259305, 268073, 241957, 250356, 242177, 251624, 250216, 242236, 242366, 241963, 250501, 250521, 250522, 242230, 259393, 244950, 250492, 242227, 250348, 242233, 244537, 269989, 258329, 259337, 242175, 250528, 259282, 369302, 242172, 184633, 246260, 241951, 250526, 254236, 250351, 259294, 259383, 259296, 246945, 250353, 250482, 244561, 266705, 249729, 266761, 247797, 251585, 247693, 242046, 250346, 250576, 247015, 241953, 250510, 241480, 250462, 259342, 259416, 250316, 250491, 259269, 241446, 250459, 245832, 250328, 250457, 241967, 242232, 241971, 259308, 243374, 250453, 250321, 246520, 250496, 250329, 259395, 241511, 235098, 250449, 250324, 250479, 241959, 259267, 259278, 250298, 259286, 250458, 247692, 250345, 250317, 250342, 250218, 250463, 259288, 259279, 269037, 355590, 355589, 349099, 349098, 353271, 353297, 353275, 353782, 353276, 353286, 349933, 349936, 353290, 353048, 349935, 353280, 355592, 349295, 353284, 353300, 353287, 353783, 353178, 353291, 353269, 353301, 353180, 353049, 353056, 355593, 353261, 353262, 355591, 349294, 353277, 349931, 353302, 353304, 353179, 353298, 352524, 353274, 339238, 352480, 358277, 352056, 272724, 358273, 352505, 351999, 352469, 358299, 358280, 352054, 358269, 352507, 352506, 334915, 358275, 351431, 352610, 352483, 352608, 358271, 352050, 339994, 358281, 352006, 352471, 351993, 352010, 352503, 352051, 358270, 352462, 352008, 344755, 352465, 352484, 358548, 352482, 358272, 352575, 352487, 358276, 352049, 365226, 339853, 352015, 352486, 353175, 358282, 352522, 353378, 352508, 352053, 352016, 352001, 352467, 358300, 352502, 337226, 358279, 344794, 358278, 351997, 352468, 352501, 352463, 352504, 327444, 352052, 352470, 353174, 358274, 404357, 403656, 403644, 403700, 404663, 403667, 403668, 403697, 403661, 404616, 404615, 404620, 403698, 403669, 403657, 404816, 404614, 404622, 403816, 403699, 403671, 403696, 403670, 403662, 404789, 404662, 377604, 403658, 404788, 404621, 403659, 403666, 424343, 433028, 430315, 433022, 433026, 430319, 467004, 467003, 455694, 439492, 423684, 455690, 453751, 424415, 424412, 424409, 443317, 443316, 439378, 439377, 437830, 437829, 437828, 435918, 435917, 435916, 435914, 435913, 435912, 435911, 435910, 431406, 424414, 424413, 424411, 424410, 424406, 424403, 424404, 424401, 424400, 423864, 423863, 423862, 423861, 423544, 423543, 423540, 456283, 456281, 527181, 527179, 523403, 536077, 536076, 527180, 527178, 531506, 423541, 415362, 423542, 415734, 536074, 527411, 528379, 523399, 536075, 531491, 536078, 441637, 455276, 413049, 452698, 452695, 454550, 452696, 414315, 443532, 435016, 437233, 435015, 441289, 441288, 437232, 435020, 435019, 441287, 441290, 437234, 435018, 435017, 441292, 441291, 437231, 435014, 435013, 437049, 453825, 453822, 444013, 445179, 453824, 453821, 453823, 453826, 452122, 454747, 444011, 444012, 443864, 443865, 467576, 445024, 445007, 433515, 455376, 441710, 455374, 455378, 403100, 455377, 455375, 442669, 454584, 454583, 451796, 451773, 451692, 451559, 454581, 454578, 454577, 463879, 463878, 463637, 410396, 463882, 463877, 454269, 454557, 463883, 463881, 454560, 453051, 453050, 453039, 453036, 453035, 453033, 453052, 453048, 453044, 463884, 463875, 463863, 454692, 454561, 454271, 453049, 453047, 453046, 453045, 453043, 453042, 453041, 453040, 453038, 453037, 453034, 451661, 451660, 445076, 463876, 463864, 454580, 454562, 453921, 451662, 410834, 454055, 441929, 441732, 413883, 445075, 438047, 438046, 453573, 414317, 438045, 437052, 444355, 434501, 466715, 456086, 455631, 453813, 453782, 452505, 349097, 466717, 465100, 465097, 456237, 456235, 456234, 456088, 455732, 455731, 455634, 455633, 453816, 453815, 453781, 453779, 453191, 453189, 452846, 452845, 452844, 452504, 452503, 452018, 452016, 452015, 466718, 466716, 465099, 465098, 456236, 456089, 456087, 455734, 455733, 455632, 453814, 453780, 453192, 453190, 452847, 452506, 451679, 454075, 414325, 449810, 411102, 413892, 411104, 454076, 411881, 422873, 454472, 422872, 442748, 422874, 422810, 423641, 422875, 441347, 433775, 456051, 463857, 413884, 414322, 280895, 462399, 443500, 443499, 439405, 439404, 433819, 433815, 433814, 459305, 433821, 433820, 433818, 433817, 433816, 414319, 454691, 454681, 435962, 435961, 435960, 464132, 439491, 423402, 423401, 423400, 423399, 423376, 423375, 527409, 519855, 453749, 435963, 423377, 413875, 519854, 519777, 413047, 454071, 435957, 435956, 435955, 435964, 435965, 435924, 435925, 435923, 435919, 436022, 435922, 436020, 435921, 434858, 436006, 435920, 436017, 436004, 435926, 436023, 436005, 436008, 434859, 507759, 507758, 436009, 434856, 436011, 434853, 436010, 434851, 436013, 436007, 434844, 434848, 462407, 462406, 437824, 437823, 437822, 437397, 436025, 436024, 436021, 436019, 436015, 436012, 434845, 434841, 434840, 434839, 436018, 436016, 436014, 437437, 435954, 437439, 435972, 435971, 435970, 435969, 435947, 435946, 435945, 435944, 435943, 435942, 435977, 435976, 435975, 435974, 437440, 435973, 434950, 434957, 434947, 434962, 434961, 434949, 434946, 437837, 437836, 437831, 435968, 435967, 437840, 437834, 437832, 437438, 435966, 434960, 434959, 434958, 434956, 434955, 434952, 434951, 434948, 437762, 436920, 434953, 434954, 435959, 435958, 428535, 465470, 465500, 467504, 410425, 410422, 446571, 465540, 413846, 428530, 428531, 451669, 451670, 413890, 454086, 433952, 507757, 507756, 455889, 437425, 437424, 437416, 437414, 435979, 435978, 431905, 431904, 431903, 523679, 495491, 495490, 495489, 463979, 439331, 439330, 439329, 437429, 437428, 437427, 437422, 437421, 437420, 437419, 437415, 437413, 434838, 434837, 434834, 437426, 437423, 437411, 434836, 453753, 443497, 462184, 443498, 437418, 451871, 462185, 454070, 435996, 437417, 452004, 435948, 431902, 439408, 433614, 411930, 434832, 439407, 433615, 434835, 434833, 435949, 206603, 433369, 457157, 474273, 495087, 495090, 495089, 495258, 495261, 495088, 495253, 495254, 495269, 516464, 508780, 508717, 495267, 495263, 495259, 495257, 495256, 495255, 479390, 479389, 479388, 479391, 479344, 520312, 479304, 479300, 479346, 479347, 479299, 495268, 520310, 479305, 508720, 508719, 479392, 479387, 479356, 479355, 479350, 479345, 479341, 479338, 479337, 479335, 479334, 479333, 479329, 479328, 479326, 479323, 479321, 479320, 479318, 479313, 479308, 479302, 495063, 495062, 495061, 495059, 495056, 479357, 479354, 479353, 479352, 479351, 479348, 479340, 479332, 479331, 479330, 479319, 479317, 479316, 479314, 479307, 479306, 479303, 479301, 479315, 479343, 479309, 479325, 479297, 479310, 479322, 479311, 469449, 479349, 479339, 469448, 479358, 479336, 479327, 479324, 479298, 508773, 524227, 524230, 524228, 524258, 524226, 495058, 495001, 524229, 495004, 495000, 524245, 524244, 524233, 524232, 524231, 508779, 507439, 507438, 507434, 507431, 507427, 507424, 507418, 507412, 507407, 495003, 495002, 495302, 495023, 495022, 495021, 495020, 479232, 479225, 495310, 495301, 503699, 495309, 495308, 495304, 495300, 495288, 495284, 479108, 479106, 495303, 495296, 495295, 495289, 495287, 495285, 495283, 495282, 495281, 495280, 495225, 479112, 479109, 479107, 495293, 479114, 479113, 476312, 523846, 495206, 474287, 495191, 495198, 495220, 495232, 505212, 495217, 495213, 495239, 495233, 495240, 495202, 495227, 495216, 474307, 495230, 479221, 479219, 495205, 479215, 495194, 495204, 495221, 495203, 495208, 495235, 502902, 495192, 495196, 495193, 495201, 495228, 495207, 495231, 495218, 479420, 495195, 508776, 495215, 495229, 494990, 495234, 494989, 474186, 495241, 509490, 495242, 494991, 495226, 495199, 495209, 495223, 495224, 495210, 454456, 495212, 495077, 495074, 495111, 507410, 495078, 495076, 461478, 495075, 495073, 479127, 479445, 507420, 479132, 495582, 495590, 479128, 508778, 479129, 479130, 479179, 479178, 479131, 507436, 500810, 479102, 466694, 456854, 479418, 505314, 520337, 479403, 507429, 479236, 479234, 520336, 479408, 479404, 479231, 479233, 507432, 479417, 479414, 479402, 479224, 479230, 479226, 479235, 479228, 479229, 479419, 507416, 525769, 479411, 479103, 479409, 499163, 499165, 499164, 499166, 479243, 479238, 456747, 499160, 499159, 455361, 525469, 525468, 523498, 479252, 479254, 479273, 479246, 479240, 479263, 479272, 479269, 479241, 479239, 479277, 479461, 479469, 479451, 516766, 479480, 479473, 479471, 479454, 479456, 494995, 494993, 479463, 494994, 479478, 479452, 479455, 479475, 500719, 479476, 479472, 479470, 479467, 479464, 479453, 479449, 455360, 479458, 455354, 479462, 516767, 525463, 499251, 525466, 509486, 479479, 479477, 479474, 479465, 479457, 479448, 455355, 455349, 454931, 413905, 525465, 525462, 525461, 502893, 502392, 455357, 455356, 455353, 525464, 525258, 495070, 469602, 455352, 455351, 525467, 479397, 479398, 455359, 479395, 479396, 479399, 453944, 479401, 467447, 499202, 455358, 495065, 495067, 495068, 469845, 453943, 479400, 508151, 524723, 524722, 524720, 516473, 495072, 495071, 495066, 479393, 453942, 453940, 495064, 520266, 520270, 520267, 494996, 494998, 494999, 523844, 474277, 523843, 507435, 507409, 494997, 474280, 474279, 474278, 507419, 507874, 474281, 524730, 479296, 479294, 479289, 479287, 474291, 479283, 479291, 479282, 479284, 479285, 479295, 504152, 479290, 479288, 479281, 479286, 479292, 479293, 495081, 474297, 474298, 474292, 495080, 523842, 517663, 479378, 474337, 479386, 479383, 479385, 479381, 479373, 479372, 479377, 479382, 479371, 479376, 479375, 479374, 479384, 479380, 523832, 479444, 479442, 479441, 479439, 479437, 479436, 479435, 479434, 479433, 479429, 479427, 479425, 479424, 479422, 479421, 479379, 479214, 479213, 479212, 479208, 479207, 479192, 474300, 479438, 479210, 479203, 479194, 523838, 523837, 520268, 480692, 479430, 479209, 479198, 479197, 479195, 474254, 474249, 523840, 508416, 480691, 480690, 480687, 474338, 474296, 474295, 474253, 474248, 454594, 446145, 508415, 467192, 520283, 524257, 524256, 524255, 520302, 520277, 474306, 474305, 524253, 524248, 524247, 523841, 523839, 523836, 523835, 523834, 474321, 474310, 474309, 474308, 474301, 520324, 516455, 524241, 524250, 524249, 524243, 495143, 473866, 473863, 474344, 523848, 473862, 488278, 253127, 316772, 474200, 517133, 522156, 469858, 456792, 469857, 474212, 494608, 473861, 475388, 524240, 473876, 524239, 473874, 473871, 524242, 473872, 473870, 473873, 473865, 473875, 384785);
UPDATE `gameobject_template` SET `displayId`=96809, `VerifiedBuild`=62438 WHERE `entry`=409273; -- The Dawnbreaker
UPDATE `gameobject_template` SET `size`=1, `Data1`=122543, `Data6`=180, `Data10`=1, `Data17`=6065, `Data23`=1, `ContentTuningId`=982, `VerifiedBuild`=62438 WHERE `entry`=383682; -- Alliance Bounty
UPDATE `gameobject_template` SET `Data30`=129756, `VerifiedBuild`=63305 WHERE `entry`=464761; -- |cff0070ddBountiful Heavy Trunk
UPDATE `gameobject_template` SET `Data30`=129754, `VerifiedBuild`=63305 WHERE `entry`=464729; -- |cff0070ddBountiful Heavy Trunk
UPDATE `gameobject_template` SET `Data30`=129754, `VerifiedBuild`=63305 WHERE `entry`=451830; -- |cff1EFF00Heavy Trunk
UPDATE `gameobject_template` SET `Data30`=129756, `VerifiedBuild`=63305 WHERE `entry`=413563; -- |cff1EFF00Heavy Trunk
UPDATE `gameobject_template` SET `VerifiedBuild`=62958 WHERE `entry` IN (428993, 428854, 467043, 452660, 433328, 429063, 428967, 428966, 428964, 428959, 428855, 447140, 433327, 429064, 428968, 428957, 428956, 447142, 446177, 446176, 446182, 446183, 447139, 415377, 447141, 433868, 488282, 441768, 452658, 452657, 452648, 441771, 441764, 433873, 433871, 433870, 433869, 433720, 429001, 428997, 441782, 441762, 429000, 428999, 428915, 428974, 428918, 428916, 428875, 567763, 428998, 428973, 428874, 467066, 430484, 428853, 467000, 466999, 466998, 466997, 439920, 428975, 415584, 439919, 204728, 205371, 205230, 339239, 204637, 204635, 204618, 204616, 204614, 202805, 281107, 268690, 252303, 251028, 452029, 339344, 307614, 298892, 273300, 273293, 273286, 243460, 243459, 243462, 243461, 206709, 206708, 206734, 204729, 203977, 279295, 279294, 207099, 204624, 204620, 202804, 204730, 179881, 202803, 202802, 204681, 179944, 303147, 194108, 303148, 209255, 208877, 209251, 214611, 208835, 209253, 209073, 209277, 208873, 209252, 186238, 204694, 207631, 204707, 204636, 204619, 204617, 204615, 204612, 195222, 204708, 204613, 209050, 209049, 202817, 209045, 207690, 207689, 206509, 204941, 204940, 202816, 204706, 204680, 202812, 207688, 207687, 207686, 206508, 208054, 204678, 202813, 202814, 206595, 202811, 207635, 205091, 205090, 204689, 204643, 50805, 50804, 50803, 3301, 197261, 207101, 202815, 204679, 206738, 204727, 204726, 204699, 204625, 202810, 204700, 207632, 206739, 204698, 207634, 204721, 237942, 197260, 204688, 207148, 207094, 207149, 204627, 207098, 204937, 204695, 204939, 207633, 204719, 204938, 207150, 204696, 204936, 207147, 207100, 179707, 208270, 204720, 206730, 197307, 186722, 207096, 197259, 207146, 207097, 204626, 208269, 206740, 206733, 202809, 197314, 197285, 197311, 204722, 197286, 384744, 293684, 206732, 206548, 206547, 205056, 204723, 202808, 197310, 197309, 197207, 193981, 403736, 212212, 207630, 206529, 202801, 202800, 197322, 197315, 197313, 197312, 197280, 197278, 197276, 105576, 208534, 206549, 206545, 206539, 206538, 204725, 204724, 202799, 202798, 197287, 197284, 197279, 197257, 206546, 204693, 204628, 197323, 204633, 202717, 206741, 210059, 210058, 206735, 206530, 204634, 204632, 204631, 204623, 204621, 204622, 207646, 204204, 278281, 203979, 350063, 204710, 204640, 204192, 204203, 206736, 204709, 204191, 206729, 204195, 204196, 204197, 204606, 204607, 204205, 204200, 190549, 204639, 204610, 204608, 204605, 204198, 204194, 175788, 175787, 206995, 204609, 204604, 204209, 204199, 269949, 204611, 204603, 204602, 203378, 202590, 184633, 377216, 386349, 281340, 206725, 204657, 204601, 204600, 204214, 204210, 204207, 206737, 204666, 204665, 204658, 204645, 204193, 204179, 204651, 204646, 205109, 206610, 204656, 204163, 323852, 204215, 206726, 323853, 452407, 383583, 323850, 204662, 332214, 204664, 206110, 323854, 355229, 175080, 204650, 204647, 204208, 323849, 323851, 207414, 204655, 204201, 223739, 204202, 210181, 204211, 204213, 323855, 204212, 206609, 203969, 205108, 206608, 223814, 206727, 204663, 205142, 495326, 495325, 428861, 428865, 428859, 428866, 466853, 466851, 434125, 429034, 429033, 428864, 428863, 428862, 428860, 428857, 446172, 446169, 446168, 446167, 446166, 441897, 428858, 415760, 467461, 467460, 467457, 467456, 446171, 446170, 428955, 428953, 467458, 467463, 466852, 466850, 428970, 467462, 467459, 429072, 429066, 429062, 428992, 428976, 428852, 428851, 428850, 35591, 429073, 445209, 428933, 428929, 428928, 428926, 428924, 428917, 428934, 428932, 428930, 428925, 428990, 494551, 421632, 441861, 494552, 494550, 494549, 494547, 494546, 494545, 428952, 428951, 428950, 428948, 428881, 428878, 428877, 446228, 446222, 446215, 428954, 428949, 428880, 428879, 428876, 446223, 266354, 446180, 446179, 446178, 433629, 474124, 446181, 433640, 433639, 433638, 433637, 433636, 433635, 433634, 433633, 433632, 433631, 433630, 433628, 433627, 433626, 433625, 428989, 428965, 428963, 428962, 428961, 428960, 474123, 474122, 466206, 466205, 459302, 459300, 459299, 459298, 452669, 452668, 452667, 452666, 452665, 452664, 452663, 452662, 428958, 446216, 428869, 429065, 429002, 428935, 428927, 446220, 505397, 459287, 446209, 446226, 459315, 465666, 428913, 428898, 459283, 473902, 452644, 446232, 529988, 389674, 529989, 428728, 470037, 456208, 402552, 566856, 377531, 259114, 414149, 428764, 377117, 439316, 428729, 442746, 495190, 385537, 439315, 455781, 377308, 563555, 245436, 446212, 429738, 446225, 434053, 428893, 428996, 459278, 428097, 446221, 459275, 428895, 446368, 441164, 428906, 428921, 459312, 446218, 430482, 454424, 446208, 452661, 428903, 428907, 428912, 428943, 428905, 456777, 459285, 446214, 441166, 459313, 459282, 456778, 428919, 433467, 446219, 446217, 465667, 428922, 446230, 459281, 459301, 446210, 428909, 452643, 428911, 459284, 463872, 428896, 446367, 459280, 459279, 429067, 439916, 433470, 446227, 428894, 446224, 428931, 446231, 432823, 465705, 434052, 452646, 428910, 459286, 434054, 459274, 446211, 441162, 439918, 441785, 439915, 441169, 428892, 428902, 452647, 433471, 428897, 428870, 459271, 446207, 428900, 428936, 447138, 428868, 446213, 428904, 428923, 430486, 446229, 452645, 459272, 428867, 459314, 439917, 442368, 452653, 428901, 446366, 459276, 440938, 467001, 467002, 459273, 433469);
UPDATE `gameobject_template` SET `ContentTuningId`=1029, `VerifiedBuild`=62958 WHERE `entry` IN (209346, 209137); -- Circle of Thorns Portal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=46500, `ContentTuningId`=1029, `VerifiedBuild`=62958 WHERE `entry`=218654; -- Burning Seed
UPDATE `gameobject_template` SET `Data13`=1, `VerifiedBuild`=62876 WHERE `entry`=499093; -- Forlorn Wind Chime
UPDATE `gameobject_template` SET `Data13`=1, `VerifiedBuild`=62876 WHERE `entry`=499093; -- Forlorn Wind Chime
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=62748 WHERE `entry`=359882; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=62748 WHERE `entry`=359852; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=62748 WHERE `entry`=359847; -- Forge
UPDATE `gameobject_template` SET `Data3`=0, `VerifiedBuild`=62748 WHERE `entry`=369107; -- Titan Console
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=62493 WHERE `entry`=359882; -- Forge
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=62493 WHERE `entry`=359852; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=62493 WHERE `entry`=359847; -- Forge
UPDATE `gameobject_template` SET `Data3`=0, `VerifiedBuild`=62493 WHERE `entry`=369107; -- Titan Console
UPDATE `gameobject_template` SET `Data13`=1, `VerifiedBuild`=62493 WHERE `entry`=499093; -- Forlorn Wind Chime
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=62493 WHERE `entry`=296700; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=62493 WHERE `entry`=296699; -- Forge
UPDATE `gameobject_template` SET `ContentTuningId`=705, `VerifiedBuild`=62493 WHERE `entry`=291217; -- Small Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=467, `VerifiedBuild`=62493 WHERE `entry`=291129; -- Grave Plaque
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=62493 WHERE `entry`=277352; -- Minor Corrupting Circle
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=62493 WHERE `entry`=273797; -- Neglected Headstone
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=62493 WHERE `entry`=273537; -- Gravebloom
UPDATE `gameobject_template` SET `Data13`=1 WHERE `entry`=499093;

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (549348,266592,433370,469901,499099,564545,532323,532322,532321,532318,532317,517405,517410,517407,507470,473920,543787,453716,473934,338224,562348,475872,467435,466810,499949,466983,466978,268813,495605,495603,525662,465300,465295,465294,465279,446146,502907,500813,469475)) OR (`Idx`=1 AND `GameObjectEntry` IN (266592,433370,525662,446146)) OR (`Idx`=12 AND `GameObjectEntry` IN (433369,433370)) OR (`Idx`=11 AND `GameObjectEntry`=433370) OR (`Idx`=10 AND `GameObjectEntry`=433370) OR (`Idx`=9 AND `GameObjectEntry`=433370) OR (`Idx`=8 AND `GameObjectEntry`=433370) OR (`Idx`=7 AND `GameObjectEntry`=433370) OR (`Idx`=6 AND `GameObjectEntry`=433370) OR (`Idx`=5 AND `GameObjectEntry`=433370) OR (`Idx`=4 AND `GameObjectEntry`=433370) OR (`Idx`=3 AND `GameObjectEntry`=433370) OR (`Idx`=2 AND `GameObjectEntry`=433370);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(549348, 0, 246042, 63305), -- Stove
(266592, 1, 138482, 62876), -- Medivh's Footlocker
(266592, 0, 143537, 62876), -- Medivh's Footlocker
(433369, 12, 219934, 62876), -- War Supply Chest
(433370, 12, 219934, 62748), -- War Supply Chest
(433370, 11, 219934, 62748), -- War Supply Chest
(433370, 10, 219934, 62748), -- War Supply Chest
(433370, 9, 219934, 62748), -- War Supply Chest
(433370, 8, 219934, 62748), -- War Supply Chest
(433370, 7, 219934, 62748), -- War Supply Chest
(433370, 6, 202023, 62748), -- War Supply Chest
(433370, 5, 202023, 62748), -- War Supply Chest
(433370, 4, 202023, 62748), -- War Supply Chest
(433370, 3, 202023, 62748), -- War Supply Chest
(433370, 2, 202023, 62748), -- War Supply Chest
(433370, 1, 202023, 62748), -- War Supply Chest
(433370, 0, 202023, 62748), -- War Supply Chest
(469901, 0, 229892, 62748), -- Void Glass Node
(499099, 0, 232601, 62748), -- Entropic Egg
(564545, 0, 248129, 62493), -- Brann's Repossessed Gear
(532323, 0, 242535, 62493), -- Shadowtrade Imports
(532322, 0, 242535, 62493), -- Shadowtrade Imports
(532321, 0, 242535, 62493), -- Shadowtrade Imports
(532318, 0, 242535, 62493), -- Shadowtrade Imports
(532317, 0, 242535, 62493), -- Shadowtrade Imports
(517405, 0, 237022, 62493), -- Tazavesh Trash
(517410, 0, 237022, 62493), -- Tazavesh Trash
(517407, 0, 237022, 62493), -- Tazavesh Trash
(507470, 0, 235413, 62493), -- Tool Rack
(473920, 0, 229959, 62493), -- Void-infused Shard
(543787, 0, 244042, 62493), -- Phase Energy
(453716, 0, 213538, 63305), -- Cache of Expensive Libations
(473934, 0, 229968, 63163), -- Property of Cooktholomew
(338224, 0, 138951, 62958), -- Cache of the Fire Lord
(562348, 0, 220737, 62876), -- Spoils of the Nexus-King
(475872, 0, 230938, 62438), -- Rippling Wellspring
(467435, 0, 229363, 62438), -- Zaranit Bud
(466810, 0, 229994, 62438), -- Void Cleft
(499949, 0, 232876, 62438), -- Stolen Research Crate
(466983, 0, 229060, 62438), -- Curved Dagger
(466978, 0, 229058, 62438), -- Om'Bera's Clipboard
(268813, 0, 147313, 63305), -- Moon Lily
(495605, 0, 232626, 62493), -- Sealed Coffer
(495603, 0, 232625, 62493), -- Loose Sand
(525662, 1, 225741, 62493), -- Soul-Scribe's Strongbox
(525662, 0, 220737, 62493), -- Soul-Scribe's Strongbox
(465300, 0, 228823, 62438), -- Thalen Songweaver's Notes
(465295, 0, 228821, 62438), -- Medivh's Karazhan Schematics
(465294, 0, 228820, 62438), -- Antonidas' Introduction to Arcane Magic
(465279, 0, 228796, 62438), -- Arcane Box
(446146, 1, 225741, 62438), -- Recovered Nightfall Relics
(446146, 0, 220737, 62438), -- Recovered Nightfall Relics
(502907, 0, 233326, 62438), -- Rod of Activation
(500813, 0, 233068, 62438), -- Rod of analysis
(469475, 0, 235366, 62438); -- Stolen Barrier Projector

UPDATE `gameobject_questitem` SET `VerifiedBuild`=63305 WHERE (`Idx`=0 AND `GameObjectEntry` IN (415584,293699,287190,326165,287196,287193,287187,287191,278824,287468,287467,287463,278827,280552,280553,282477,203979,203969,451830,245368,244824,249729,250576,266619,464729,413590,451327,454502,165554,207145,278802,140911,203800,105174,105175,203762,213314,211312,211148,211143,211269,211270,211794,211268,211266,211770,178204)) OR (`Idx`=4 AND `GameObjectEntry` IN (451830,464729)) OR (`Idx`=3 AND `GameObjectEntry` IN (451830,464729)) OR (`Idx`=2 AND `GameObjectEntry` IN (451830,464729)) OR (`Idx`=1 AND `GameObjectEntry` IN (451830,464729));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=63163 WHERE (`Idx`=0 AND `GameObjectEntry` IN (203969,245368,249729,266619,250576,244824,250417,293688,205144,203751,203800,140911,278802,105174,203762,105175,203801,312208,323383,313618,323548,316422,316424,316423,316430,178204,759,204336,203979,415584)) OR (`Idx`=1 AND `GameObjectEntry`=759);
UPDATE `gameobject_questitem` SET `VerifiedBuild`=62876 WHERE (`GameObjectEntry`=267190 AND `Idx`=0) OR (`GameObjectEntry`=181963 AND `Idx`=0) OR (`GameObjectEntry`=266746 AND `Idx`=0) OR (`GameObjectEntry`=411623 AND `Idx`=0) OR (`GameObjectEntry`=425875 AND `Idx`=0) OR (`GameObjectEntry`=433369 AND `Idx` IN (11,10,9,8,7,6,5,4,3,2,1,0)) OR (`GameObjectEntry`=415584 AND `Idx`=0) OR (`GameObjectEntry`=278802 AND `Idx`=0) OR (`GameObjectEntry`=203969 AND `Idx`=0);
UPDATE `gameobject_questitem` SET `VerifiedBuild`=62748 WHERE (`GameObjectEntry`=451327 AND `Idx`=0) OR (`GameObjectEntry`=415584 AND `Idx`=0) OR (`GameObjectEntry`=433369 AND `Idx` IN (11,10,9,8,7,6,5,4,3,2,1,0));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=62706 WHERE (`GameObjectEntry`=415584 AND `Idx`=0);
UPDATE `gameobject_questitem` SET `VerifiedBuild`=62493 WHERE (`Idx`=0 AND `GameObjectEntry` IN (203979,203969,415584,499022,433369,411623,425875,278802,140911,105175,203800,203801,203762,105174,273537,292917,277427,313618,312208,323548,323383,316423,316422,316430,316424)) OR (`Idx`=10 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=9 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=8 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=7 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=6 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=5 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=4 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=3 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=2 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=1 AND `GameObjectEntry` IN (499022,433369)) OR (`Idx`=11 AND `GameObjectEntry`=433369);
UPDATE `gameobject_questitem` SET `VerifiedBuild`=63003 WHERE (`GameObjectEntry`=415584 AND `Idx`=0);
UPDATE `gameobject_questitem` SET `VerifiedBuild`=62958 WHERE (`Idx`=0 AND `GameObjectEntry` IN (415584,203977,203979,203969));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=62438 WHERE (`Idx`=11 AND `GameObjectEntry`=433369) OR (`Idx`=10 AND `GameObjectEntry`=433369) OR (`Idx`=9 AND `GameObjectEntry`=433369) OR (`Idx`=8 AND `GameObjectEntry`=433369) OR (`Idx`=7 AND `GameObjectEntry`=433369) OR (`Idx`=6 AND `GameObjectEntry`=433369) OR (`Idx`=5 AND `GameObjectEntry`=433369) OR (`Idx`=4 AND `GameObjectEntry`=433369) OR (`Idx`=3 AND `GameObjectEntry`=433369) OR (`Idx`=2 AND `GameObjectEntry`=433369) OR (`Idx`=1 AND `GameObjectEntry`=433369) OR (`Idx`=0 AND `GameObjectEntry` IN (433369,203969,245368,244824,266619,249729,250576,424343,425875,415584,411102,411104,411930));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=62801 WHERE (`GameObjectEntry`=415584 AND `Idx`=0);
UPDATE `gameobject_questitem` SET `VerifiedBuild`=62680 WHERE (`Idx`=0 AND `GameObjectEntry` IN (415584,203969,203979));

DELETE FROM `page_text` WHERE `ID`=10101;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(10101, 'Valued customer,\n\nAn unpaid balance on your void storage rental has forced us to place your account into arrears.\n\nAs part of proceedings, please turn over any enchanted items, magical artifacts, powerful weapons, and delve curios that might be in your possession to the recovery agent presenting this writ.\n\nFailure to do so may result in the forfeiture of your stored materials.\n\n\nThank you for your compliance,\n\n- F. Akename and Sons Void Storage, Tazavesh', 0, 0, 0, 62493); -- 10101


