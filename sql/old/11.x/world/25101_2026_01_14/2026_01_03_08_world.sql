-- 
SET NAMES 'utf8';
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (216632,229955,230245,230248,231039,231042,231131,231132,231136,231218,232019,232022,232023,232027,232028,232030,232031,232032,232033,232035,232036,232037,232038,233252,233253,233312,233314,233329,233366,233372,233374,244655,244656,244657,244658,244666,244667,244674,244675,244685,244690,244695,244709,244711,244715,244785,245134,246336,246613,249249,249254,249423,249435,250839,255519,255944));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(216632, 1, 155770, 0, 0, 0, 0, 0, 155818, 0, 0, 64978), -- Lamplighter Rathling
(229955, 1, 5956, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Stromgarde Citizen
(230245, 1, 118560, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Hammerfall Peon
(230248, 1, 190675, 0, 0, 190871, 0, 0, 5260, 0, 0, 64978), -- Hammerfall Grunt
(231039, 1, 233067, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Arator
(231042, 1, 2179, 0, 0, 0, 0, 0, 42140, 0, 0, 64978), -- Vereesa Windrunner
(231131, 1, 57036, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Twilight Voidshaper
(231132, 1, 52057, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Twilight Reaver
(231136, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Dalaran Custodian
(231218, 1, 199652, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Stromic Stablehand
(232019, 1, 107263, 0, 0, 0, 0, 0, 58800, 0, 0, 64978), -- Mag'har Grunt
(232022, 1, 13631, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Drum Fel
(232023, 1, 12290, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Gor'mul
(232027, 1, 2717, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Innkeeper Adegwa
(232028, 1, 1908, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Korin Fel
(232030, 1, 10611, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Tharlidun
(232031, 1, 2827, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Slagg
(232032, 1, 2703, 0, 0, 13407, 0, 0, 0, 0, 0, 64978), -- Graud
(232033, 1, 5281, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Jun'ha
(232035, 1, 2717, 0, 0, 13407, 0, 0, 0, 0, 0, 64978), -- Keena
(232036, 1, 10619, 0, 0, 2081, 0, 0, 0, 0, 0, 64978), -- Tunkk
(232037, 1, 0, 0, 0, 0, 0, 0, 5262, 0, 0, 64978), -- Mu'uta
(232038, 1, 0, 0, 0, 13407, 0, 0, 0, 0, 0, 64978), -- Uttnar
(233252, 1, 2179, 0, 0, 0, 0, 0, 42140, 0, 0, 64978), -- Vereesa Windrunner
(233253, 1, 233067, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Arator
(233312, 1, 233067, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Arator
(233314, 1, 2179, 0, 0, 0, 0, 0, 42140, 0, 0, 64978), -- Vereesa Windrunner
(233329, 1, 233067, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Silver Hand Avenger
(233366, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Dalaran Custodian
(233372, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Dalaran Custodian
(233374, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Dalaran Custodian
(244655, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Lady Jaina Proudmoore
(244656, 1, 204482, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Thrall
(244657, 1, 204482, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Thrall
(244658, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Lady Jaina Proudmoore
(244666, 1, 204482, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Thrall
(244667, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Lady Jaina Proudmoore
(244674, 1, 107407, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Ogre Destroyer
(244675, 1, 105909, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Runk
(244685, 1, 107407, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Ogre Basher
(244690, 1, 161794, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Stromgarde Footman
(244695, 1, 36509, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Ettin Crusher
(244709, 1, 163874, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Ro'grok
(244711, 1, 162868, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Armored Cleaver
(244715, 1, 204482, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Thrall
(244785, 1, 162868, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Armored Cleaver
(245134, 1, 187518, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Local
(246336, 1, 187518, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Neighborhood Laborer
(246613, 1, 14874, 0, 0, 12893, 0, 0, 0, 0, 0, 64978), -- Doomrider Helgrim
(249249, 1, 118560, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Hammerfall Peon
(249254, 1, 107407, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Ogre Destroyer
(249423, 1, 161794, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Sergeant Colvin
(249435, 1, 237344, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Local Blacksmith
(250839, 1, 141368, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Silver Hand Squire
(255519, 1, 218325, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Lestia Goldenstrike
(255944, 1, 194326, 0, 0, 0, 0, 0, 0, 0, 0, 64978); -- Ema Silverswatch

UPDATE `creature_equip_template` SET `VerifiedBuild`=64978 WHERE (`ID`=1 AND `CreatureID` IN (1439,1750,1752,1756,2504,4960,44238,44239,44241,44243,51348,69791,99541,142693,142694,175138,189600,204127,207450,207454,207456,207468,207481,210759,211027,211060,211061,211062,211119,212697,214251,214338,216584,217429,217516,219014,221633,221848,222270,222292,222303,222336,223875,225766,226270,226708,226833,226834,227422,230352,230353,230354,230617,230618,230619,230620,230621,230624,230985,231549,231689,231692,231694,232403,234033,234562,234563,237790,240938,242126,244485,245782,247409)) OR (`ID`=2 AND `CreatureID` IN (17252,69792,219014)) OR (`ID`=3 AND `CreatureID`=219014) OR (`ID`=4 AND `CreatureID`=219014) OR (`ID`=5 AND `CreatureID`=219014) OR (`ID`=6 AND `CreatureID`=219014) OR (`ID`=7 AND `CreatureID`=219014);

UPDATE `creature_template_locale` SET `VerifiedBuild`=64978 WHERE (`locale`='deDE' AND `entry` IN (231133,233329,231132,231131,231136,233312,233314,233366,233372,231044,233252,224462,233253,224454,233374,224460,229638,224456,231042,223097,223227,223245,223093,221528,223558,219544,221084,223852,221525,221644,221526,221524,222294,222307,222292,222271,222270,222162,222303,223740,219181,216939,214950,225351,223095,219103,224713,224714,219159,198464,224711,224712,221848,219104,215520,227252,226237,234677,212370,212369,223875,242126,231855,234563,225766,226919,227422,227417,217704,226511,226623,234562,226749,231039,142668,142666,88402,230098,230031,227389,214824,226708,229379,222245,230100,250450,250454,222336,222142,219392,222160,222258,229927,250839,219382,219391,249276,214113,252857,227675,248490,228605,253181,248538,215658,219142,219226,229336,226832,226250,234768,219151,248351,248491,227038,252786,226743,253183,226833,249262,226287,238149,226270,248341,242566,219029,206017,226834,249277,243652,249592,249263,220944,238147,249264,208070,197711,234262,242550,219225,219040,223858,220300,236918,219036,219023,222610,233492,233487,214948,238155,248479,226742,214838,238148,185669,220943,214772,225654,219126,219014,225664,214947,215070,235403,244756,244688,244697,244681,244687,256632,256630,240353,239919,255634,255635,255636,257168,255920,235014,255230,255228,255222,256520,255910,255248,239906,249503,244951,255214,255649,255215,257015,256750,257014,236118,245087,235460,247298,235452,247302,242122,235442,235456,236820,235458,235457,245038,236116,245045,245259,235016,239415,255942,255944,245753,236112,249850,255519,255203,255221,255213,255218,255216,255941,233063,233124,255126,249435,255110,255104,255227,256085,245134,248854,255200,255202,244806,235461,238582,245551,246336,245815,256636,245552,244973,235451,245276,255778,235453,256327,242052,242053,255198,255196,255197,235454,235021,234993,234995,244569,235017,237438,244547,235026,236111,238584,247958,235455,256825,245042,244568,244166,237063,232031,232037,232035,232032,232022,232028,232036,244715,232030,246613,230248,232023,246612,232027,232033,232019,230245,232038,883,244709,244711,244667,244666,244786,244785,141725,142342,142343,49778,257072,142694,142693,142341,244685,249347,231218,244683,244682,249351,13321,244691,4075,249423,244658,244657,231309,231219,249456,229999,230004,230001,229955,230002,249281,244690,244695,142335,141659,141727,249269,49999,2620,95072,234018,63508,3527,95061,234170,142340,142339,69791,69792,175519,253463,253460,142337));

DELETE FROM `quest_template_locale` WHERE (`ID`=92715 AND `locale`='deDE');
INSERT INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(92715, 'deDE', 'Nur per Einladung?', 'Sprecht mit Alton Philips in der Nähe der Shlae\'gararena.', 'Ihr haltet Euch für den perfekten Shlae\'gar-Teilnehmer, was, $C? Die lassen da nicht einfach jeden rein. Und ganz sicher nicht ohne Einladung.\n\nDas heißt... nur unter uns gesagt: Wenn man weiß, wo man suchen muss, und die nötigen Mittel hat, kann heutzutage angeblich jeder seinen Moment im Rampenlicht haben.', '', '', '', '', '', '', 64978);

UPDATE `quest_template_locale` SET `VerifiedBuild`=64978 WHERE (`locale`='deDE' AND `ID` IN (84996,79232,91454,91314,84972,86934,90972,86196,85238,84376,84915,84740,84215,81556,83160,83153,83152,83092,79686,79724,82441,79119,83325,79355,79174,83628,83082,83081,83247,83283,80378,79555,79554,80576,79367,80508,83155,81693,81655,80392,79149,79148,82773,82628,80677,80673,79108,79159,78743,81661,79309,80314,80313,78469,83616,81667,79256,78562,78754,82792,82681,82680,82477,78901,78898,78897,82216,79574,80176,80175,79300,79304,79151,78996,78686,78571,78570,69960,77570,78589,76990,76367,75119,48722,81497,69953,60950,74990,86395,81477,67605,48511,48101,70701,69974,77982,74988,48175,86409,49044,48833,69973,69972,82964,78933,86429,86372,79234,69970,86610,76519,69955,48526,47552,82963,48828,47507,75200,75661,76549,81475,48832,69971,81482,76169,85863,78434,85855,69969,48284,65798,77878,75835,81504,52953,75151,75466,75124,76518,76991,81555,74892,48701,69954,48725,48514,72686,77867,86367,86869,48831,74292,69952,70299,69951,85864,47828,75071,76997,69956,86391,47728,59016,82995,48512,79158,78439,78656,69961,76550,69938,74991,82966,89195,48737,47720,74879,82961,76558,79173,78972,69959,69975,48957,82124,83587,91039,80207,92331,83497,81966,78289,85108,85085,79659,79655,79636,79628,92816,92984,93647,94210,82256,79960,83079,76588,82526,82468,82552,82298,82297,82293,82254,82133,82088,82041,81990,81825,81822,81813,76247,82456,82747,82448,82291,82234,81799,81465,79321,73147,67012,73079,69927,71212,70661,70662,70652,70651,72022,71206,71166,71145,70629,70012,70649,70625,70622,70602,70430,70423,70415,70412,70072,70075,69931,67026,67010,67009,66588,43942,91968,94455,94379,82672,26801,25056,25030,25003,24997,24994,24992,24983,24981,25090,24979,24978,24975,24974,26965,26953,26999,27000,26931,26934,26922,26923,26921,42985,83137,86352,92405,91863,90911,90898,90896,90893,90895,90888));

DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='deDE' AND `ID` IN (84997,84996,92405,92816,94379,94210,93647,91969,91968,94455,91863,90898,90896,90893,90895,92028,90888,90887,90886,90885));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(84997, 'deDE', 'Uff... <Vereesa krümmt sich.>\n\nTruppen der Leere... greifen an. Wieso hier... jetzt?', 64978),
(84996, 'deDE', 'Das hier scheint ein passender Ort zu sein, meinem verstorbenen Ehemann zu gedenken, Rhonin.\n\nWir sollten mit der Zeremonie fortfahren.', 64978),
(92405, 'deDE', 'Meine Tante wird von schrecklichen Visionen geplagt, und sie werden immer schlimmer.', 64978),
(92816, 'deDE', '<Ihr seid jetzt auf dem Weg in ein neues Abenteuer!>', 64978),
(94379, 'deDE', 'Wie lief die Renovierung? Hoffentlich habt Ihr nun genug Stauraum für all die Schätze, die Ihr auf Euren Abenteuern erbeutet.\n\nSchaut wieder beim Baumeister vorbei, wenn Ihr bereit für die nächste Aufwertung seid.\n\nOh, und es ist ein Brief für Euch angekommen, als Ihr unterwegs wart.', 64978),
(94210, 'deDE', 'Konntet Ihr gute Stücke für Euer Haus finden? Wir hoffen, dass uns in der Zukunft weitere Händler besuchen werden, also schaut gelegentlich vorbei!', 64978),
(93647, 'deDE', 'Ihr seht wie jemand aus, der sich gut im Holzfäll\'n mach\'n würd\'.\n\nHier, ich zeig\' Euch, woran Ihr Bäume erkennt, die sich zum Fäll\'n eignen.\n\nHolz is\' für viele Dinge in Euerm Haus nützlich. Oder auch für andere Häuser, wenn Ihr was verschenk\'n oder verkauf\'n wollt. Ich wette, die alten Handwerkslehrer, von denen Ihr gelernt habt, hab\'n neue Dinge anzubiet\'n.\n\nGeht da raus un\' schaut, was sich so mach\'n lässt!', 64978),
(91969, 'deDE', 'Ausgezeichnete Arbeit! Jetzt sieht es hier schon mehr nach einem Zuhause aus.\n\nIch könnte Euch zwar jahrtausendelang mein Wissen näherbringen, aber ich denke, man lernt am besten, wenn man etwas selbst macht.\n\nHört nie auf zu gestalten! Hört nie auf zu erschaffen!', 64978),
(91968, 'deDE', 'Ein Platz für alles, an dem alles seinen Platz hat.', 64978),
(94455, 'deDE', 'Macht es Euch gemütlich!', 64978),
(91863, 'deDE', 'Glückwunsch zu Eurem neuen Zuhause. Wir wissen, dass Ihr Euch hier sehr wohlfühlen werdet, und wir freuen uns schon darauf, Euch in der Nachbarschaft zu sehen.', 64978),
(90898, 'deDE', 'Hammerfall wird sich schnell erholen und stärker als zuvor aus dieser Belagerung hervorgehen.', 64978),
(90896, 'deDE', 'Die Belagerung ist vorüber. Das Arathihochland wird nun hoffentlich wieder einigermaßen zur Ruhe kommen.', 64978),
(90893, 'deDE', 'Die Belagerung ist vorbei. Wir haben ihren Anführer umstellt.', 64978),
(90895, 'deDE', 'Ohne die Katapulte sollten die Soldaten von Stromgarde die Oberhand gewinnen können.', 64978),
(92028, 'deDE', 'Hervorragende Arbeit! Jetzt sollte ich Zeit haben, den Fehler zu beheben, der ursprünglich dafür verantwortlich ist.\n\nVielleicht sollte ich einfach so tun, als wäre es Absicht gewesen, und es gut sein lassen!', 64978),
(90888, 'deDE', 'Das sieht schlimm aus, aber wir werden schon damit fertig.', 64978),
(90887, 'deDE', 'Das sollte helfen, die Kreaturen zu vertreiben. Ohne einen Anführer werden sie flüchten, wenn die Verstärkungen von Allianz und Horde erscheinen.', 64978),
(90886, 'deDE', 'Wie ich mir gedacht habe.\n\nIch kann das kaum entziffern.', 64978),
(90885, 'deDE', 'Das sind... ziemlich viele Kürbisse.\n\nIch denke, unser Bauernfreund sollte sie zurück nach Hammerfall bringen. Verstärkungen der Horde sollten bereits dort sein.', 64978);

UPDATE `quest_objectives_locale` SET `VerifiedBuild`=64978 WHERE (`locale`='deDE' AND `ID` IN (457800,455357,448613,462568,462539,462552,462010,454466,456214,453373,455830,453103,453371,453233,453232,453231,453545,452124,452123,452122,448504,448951,448744,448503,448743,448741,448740,448502,448949,448742,450659,450641,450640,450605,447259,449933,449934,449935,445751,446294,446181,451350,451349,451088,448198,447000,449141,450655,448185,446126,448789,446003,448065,448064,448009,447406,448099,448098,448097,448096,451309,450384,450229,445057,445053,449795,449841,447819,446087,446086,446085,446084,446910,446838,445628,445627,445618,445626,445625,445606,445624,445623,445342,445341,438035,443502,436772,434860,405055,405097,434834,448556,430862,430861,443668,434674,434673,293134,293116,456703,456701,293573,456762,464502,456646,457126,457132,457128,457127,457123,437127,437126,437128,292444,292443,292424,292418,434982,443392,443435,448481,447535,436394,455757,455756,455755,464500,444402,455798,455736,455735,455734,292575,423386,443588,435934,340378,435509,435570,435569,435510,435544,435543,435508,435542,435541,434865,443254,443261,437123,443255,443272,443271,443270,443269,434507,432283,443578,456629,457490,464505,436013,430264,464501,434858,434857,445542,445541,437504,445531,456655,395346,445629,445621,444408,445971,445597,443394,443453,429505,434680,459660,461563,459659,290838,434474,434473,443389,445678,445677,445676,445675,445674,445673,445672,445671,445670,445669,445665,445664,445359,445354,445189,293303,293302,449800,447867,451084,465579,465899,468127,468130,468491,468126,468123,468125,468124,468122,449655,449654,449653,449652,449651,449650,447040,450597,437375,450417,450039,450034,450029,450336,450017,449752,449751,449748,449638,449424,449423,449422,449421,449420,449419,449392,449217,449216,449215,448865,448858,448848,436502,450554,450553,449931,449746,449612,449611,449613,448837,448269,433049,433048,433047,433046,428720,428719,432903,431607,431054,431053,431052,431348,431347,431346,430909,430922,430916,430806,430833,430832,431682,431598,431535,431464,430724,429641,430781,430685,430675,430680,430655,430654,430423,430416,430405,430403,430179,429823,430672,430671,430670,430669,429829,430648,429488,428781,428716,428710,428709,427291,463905,468486,468485,265962,258621,267187,267186,266110,254100,266699,253484,456685,456599,463610,463613,463641,463640,463639,463638,463637,463636,463635,463634,463633,463632,463631,463630,463609,463615,461829,461752,461767));

DELETE FROM `quest_greeting_locale` WHERE (`ID`=244656 AND `Type`=0 AND `locale`='deDE');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(244656, 0, 'deDE', 'Die Orcs auf diesem Hof wollten ein einfaches Leben führen. Wir müssen ihnen dabei helfen, ihn zurückzuerobern.', 64978);

DELETE FROM `quest_request_items_locale` WHERE (`locale`='deDE' AND `ID` IN (84998,90886));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(84998, 'deDE', 'Wieso will... diese Leerenkreatur... unseren Tod?', 64978),
(90886, 'deDE', 'Habt Ihr die Pläne? Sie sollten bei den meisten der Gegner auf dem Hof zu finden sein.', 64978);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (84997 /*What Might Come*/, 84996 /*Vereesa's Tale*/, 92405 /*Meet Arator*/, 92816 /*A Letter for Adventure*/, 94379 /*This Old Hearth*/, 94210 /*Feathering the Nest*/, 93647 /*Lumber For You*/, 91969 /*Time to Decorate*/, 91968 /*Welcome Home*/, 94455 /*Home at Last*/, 91863 /*My First Home*/, 90898 /*Back to Hammerfall*/, 90896 /*One Last Ogre*/, 90893 /*Repelling the Siege*/, 90895 /*Catapult Bombardment*/, 92028 /*Pardon the Interruption*/, 90888 /*Saving Stromgarde Keep*/, 90887 /*Farmer's Nemesis*/, 90886 /*Best Laid Plans of Kobolds and Ogres*/, 90885 /*My Beautiful Pumpkins*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(84997, 0, 0, 0, 0, 0, 0, 0, 0, 'Uff... <Vereesa krümmt sich.>\n\nTruppen der Leere... greifen an. Wieso hier... jetzt?', 64978), -- What Might Come
(84996, 273, 1, 0, 0, 0, 0, 0, 0, 'Das hier scheint ein passender Ort zu sein, meinem verstorbenen Ehemann zu gedenken, Rhonin.\n\nWir sollten mit der Zeremonie fortfahren.', 64978), -- Vereesa's Tale
(92405, 1, 0, 0, 0, 0, 0, 0, 0, 'Meine Tante wird von schrecklichen Visionen geplagt, und sie werden immer schlimmer.', 64978), -- Meet Arator
(92816, 0, 0, 0, 0, 0, 0, 0, 0, '<Ihr seid jetzt auf dem Weg in ein neues Abenteuer!>', 64978), -- A Letter for Adventure
(94379, 0, 0, 0, 0, 0, 0, 0, 0, 'Wie lief die Renovierung? Hoffentlich habt Ihr nun genug Stauraum für all die Schätze, die Ihr auf Euren Abenteuern erbeutet.\n\nSchaut wieder beim Baumeister vorbei, wenn Ihr bereit für die nächste Aufwertung seid.\n\nOh, und es ist ein Brief für Euch angekommen, als Ihr unterwegs wart.', 64978), -- This Old Hearth
(94210, 0, 0, 0, 0, 0, 0, 0, 0, 'Konntet Ihr gute Stücke für Euer Haus finden? Wir hoffen, dass uns in der Zukunft weitere Händler besuchen werden, also schaut gelegentlich vorbei!', 64978), -- Feathering the Nest
(93647, 0, 0, 0, 0, 0, 0, 0, 0, 'Ihr seht wie jemand aus, der sich gut im Holzfäll\'n mach\'n würd\'.\n\nHier, ich zeig\' Euch, woran Ihr Bäume erkennt, die sich zum Fäll\'n eignen.\n\nHolz is\' für viele Dinge in Euerm Haus nützlich. Oder auch für andere Häuser, wenn Ihr was verschenk\'n oder verkauf\'n wollt. Ich wette, die alten Handwerkslehrer, von denen Ihr gelernt habt, hab\'n neue Dinge anzubiet\'n.\n\nGeht da raus un\' schaut, was sich so mach\'n lässt!', 64978), -- Lumber For You
(91969, 0, 0, 0, 0, 0, 0, 0, 0, 'Ausgezeichnete Arbeit! Jetzt sieht es hier schon mehr nach einem Zuhause aus.\n\nIch könnte Euch zwar jahrtausendelang mein Wissen näherbringen, aber ich denke, man lernt am besten, wenn man etwas selbst macht.\n\nHört nie auf zu gestalten! Hört nie auf zu erschaffen!', 64978), -- Time to Decorate
(91968, 0, 0, 0, 0, 0, 0, 0, 0, 'Ein Platz für alles, an dem alles seinen Platz hat.', 64978), -- Welcome Home
(94455, 0, 0, 0, 0, 0, 0, 0, 0, 'Macht es Euch gemütlich!', 64978), -- Home at Last
(91863, 0, 0, 0, 0, 0, 0, 0, 0, 'Glückwunsch zu Eurem neuen Zuhause. Wir wissen, dass Ihr Euch hier sehr wohlfühlen werdet, und wir freuen uns schon darauf, Euch in der Nachbarschaft zu sehen.', 64978), -- My First Home
(90898, 0, 0, 0, 0, 0, 0, 0, 0, 'Hammerfall wird sich schnell erholen und stärker als zuvor aus dieser Belagerung hervorgehen.', 64978), -- Back to Hammerfall
(90896, 0, 0, 0, 0, 0, 0, 0, 0, 'Die Belagerung ist vorüber. Das Arathihochland wird nun hoffentlich wieder einigermaßen zur Ruhe kommen.', 64978), -- One Last Ogre
(90893, 0, 0, 0, 0, 0, 0, 0, 0, 'Die Belagerung ist vorbei. Wir haben ihren Anführer umstellt.', 64978), -- Repelling the Siege
(90895, 0, 0, 0, 0, 0, 0, 0, 0, 'Ohne die Katapulte sollten die Soldaten von Stromgarde die Oberhand gewinnen können.', 64978), -- Catapult Bombardment
(92028, 0, 0, 0, 0, 0, 0, 0, 0, 'Hervorragende Arbeit! Jetzt sollte ich Zeit haben, den Fehler zu beheben, der ursprünglich dafür verantwortlich ist.\n\nVielleicht sollte ich einfach so tun, als wäre es Absicht gewesen, und es gut sein lassen!', 64978), -- Pardon the Interruption
(90888, 0, 0, 0, 0, 0, 0, 0, 0, 'Das sieht schlimm aus, aber wir werden schon damit fertig.', 64978), -- Saving Stromgarde Keep
(90887, 0, 0, 0, 0, 0, 0, 0, 0, 'Das sollte helfen, die Kreaturen zu vertreiben. Ohne einen Anführer werden sie flüchten, wenn die Verstärkungen von Allianz und Horde erscheinen.', 64978), -- Farmer's Nemesis
(90886, 0, 0, 0, 0, 0, 0, 0, 0, 'Wie ich mir gedacht habe.\n\nIch kann das kaum entziffern.', 64978), -- Best Laid Plans of Kobolds and Ogres
(90885, 0, 0, 0, 0, 0, 0, 0, 0, 'Das sind... ziemlich viele Kürbisse.\n\nIch denke, unser Bauernfreund sollte sie zurück nach Hammerfall bringen. Verstärkungen der Horde sollten bereits dort sein.', 64978); -- My Beautiful Pumpkins

UPDATE `quest_offer_reward` SET `VerifiedBuild`=64978 WHERE `ID`=65436;
UPDATE `quest_offer_reward` SET `RewardText`='I cannot wait to see the Dragon Isles with you, $p!\n\nNow then, I believe that diminutive ally of yours said something about putting together an expedition.', `VerifiedBuild`=64978 WHERE `ID`=66577; -- Aspectral Invitation

DELETE FROM `quest_poi` WHERE (`QuestID`=83492 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=83492 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=85001 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=85001 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=85001 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=84998 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=84998 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=84998 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=84997 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=84997 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=84997 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=84996 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=84996 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=84996 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=84996 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=92405 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=92405 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=94379 AND `BlobIndex`=1 AND `Idx1`=7) OR (`QuestID`=94379 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=94379 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=94379 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=94379 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=94379 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=94379 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=94379 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=92984 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=94210 AND `BlobIndex`=1 AND `Idx1`=19) OR (`QuestID`=94210 AND `BlobIndex`=0 AND `Idx1`=18) OR (`QuestID`=94210 AND `BlobIndex`=1 AND `Idx1`=17) OR (`QuestID`=94210 AND `BlobIndex`=0 AND `Idx1`=16) OR (`QuestID`=94210 AND `BlobIndex`=1 AND `Idx1`=15) OR (`QuestID`=94210 AND `BlobIndex`=0 AND `Idx1`=14) OR (`QuestID`=94210 AND `BlobIndex`=1 AND `Idx1`=13) OR (`QuestID`=94210 AND `BlobIndex`=0 AND `Idx1`=12) OR (`QuestID`=94210 AND `BlobIndex`=3 AND `Idx1`=11) OR (`QuestID`=94210 AND `BlobIndex`=2 AND `Idx1`=10) OR (`QuestID`=94210 AND `BlobIndex`=1 AND `Idx1`=9) OR (`QuestID`=94210 AND `BlobIndex`=0 AND `Idx1`=8) OR (`QuestID`=94210 AND `BlobIndex`=1 AND `Idx1`=7) OR (`QuestID`=94210 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=94210 AND `BlobIndex`=3 AND `Idx1`=5) OR (`QuestID`=94210 AND `BlobIndex`=2 AND `Idx1`=4) OR (`QuestID`=94210 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=94210 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=94210 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=94210 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=94455 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=94455 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=91863 AND `BlobIndex`=1 AND `Idx1`=21) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=20) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=19) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=18) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=17) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=16) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=15) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=14) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=13) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=12) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=11) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=10) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=9) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=8) OR (`QuestID`=91863 AND `BlobIndex`=1 AND `Idx1`=7) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=91863 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=91863 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=93057 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=93057 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90911 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=90911 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=90911 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=90911 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90911 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90898 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90898 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90896 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=90896 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90896 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90893 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=90893 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90893 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=92028 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=92028 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=92028 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=92028 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90895 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=90895 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90895 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90888 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90888 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90886 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=90886 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90886 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90885 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=90885 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90885 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90887 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=90887 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90887 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(83492, 1, 2, 32, 0, 0, 1, 85, 0, 0, 0, 0, 0, 1457285, 0, 64978), -- Warbands: Warbanding Together
(83492, 0, 1, 32, 0, 0, 0, 84, 0, 0, 0, 0, 0, 1456603, 0, 64978), -- Warbands: Warbanding Together
(85001, 0, 2, 32, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2675971, 0, 64978), -- Blessings Be Upon You
(85001, 0, 1, 0, 453591, 4002, 2552, 2248, 0, 0, 0, 0, 0, 0, 0, 64978), -- Blessings Be Upon You
(85001, 0, 0, -1, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2675971, 0, 64978), -- Blessings Be Upon You
(84998, 0, 2, 32, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2675972, 0, 64978), -- Bringer of the Void
(84998, 0, 1, 0, 453589, 231044, 2552, 2248, 0, 0, 0, 0, 0, 2594570, 0, 64978), -- Bringer of the Void
(84998, 0, 0, -1, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2675972, 0, 64978), -- Bringer of the Void
(84997, 0, 2, 32, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2594440, 0, 64978), -- What Might Come
(84997, 0, 1, 0, 453588, 233252, 2552, 2248, 0, 0, 0, 0, 0, 2594440, 0, 64978), -- What Might Come
(84997, 0, 0, -1, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2675972, 0, 64978), -- What Might Come
(84996, 0, 3, 32, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2594242, 0, 64978), -- Vereesa's Tale
(84996, 1, 2, 0, 455357, 231042, 2552, 2248, 0, 0, 0, 134211, 0, 2594242, 0, 64978), -- Vereesa's Tale
(84996, 0, 1, 0, 455357, 231042, 2552, 2248, 0, 0, 0, 134212, 0, 2594440, 0, 64978), -- Vereesa's Tale
(84996, 0, 0, -1, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2594440, 0, 64978), -- Vereesa's Tale
(92405, 0, 1, 32, 0, 0, 2552, 2339, 0, 0, 0, 0, 0, 2967842, 0, 64978), -- Meet Arator
(92405, 0, 0, -1, 0, 0, 2552, 2248, 0, 0, 0, 0, 0, 2594241, 0, 64978), -- Meet Arator
(94379, 1, 7, 32, 0, 0, 2736, 2351, 0, 0, 0, 0, 0, 2779505, 0, 64978), -- This Old Hearth
(94379, 0, 6, 32, 0, 0, 2735, 2352, 0, 0, 0, 0, 0, 2914024, 0, 64978), -- This Old Hearth
(94379, 1, 5, 1, 468486, 257414, 2735, 2352, 0, 0, 0, 0, 0, 3094819, 0, 64978), -- This Old Hearth
(94379, 0, 4, 1, 468486, 257414, 2736, 2351, 0, 0, 0, 0, 0, 3094857, 0, 64978), -- This Old Hearth
(94379, 1, 3, 0, 468485, 257414, 2735, 2352, 0, 0, 0, 0, 0, 3094819, 0, 64978), -- This Old Hearth
(94379, 0, 2, 0, 468485, 257414, 2736, 2351, 0, 0, 0, 0, 0, 3094857, 0, 64978), -- This Old Hearth
(94379, 0, 1, -1, 0, 0, 2736, 2351, 0, 0, 0, 0, 0, 2779505, 0, 64978), -- This Old Hearth
(94379, 0, 0, -1, 0, 0, 2735, 2352, 0, 0, 0, 0, 0, 2914024, 0, 64978), -- This Old Hearth
(92984, 0, 0, 31, 0, 0, 2735, 2352, 0, 2, 0, 0, 0, 0, 0, 64978), -- Decor Treasure Hunt
(94210, 1, 19, 32, 0, 0, 2736, 2351, 0, 0, 0, 0, 0, 2779505, 0, 64978), -- Feathering the Nest
(94210, 0, 18, 32, 0, 0, 2735, 2352, 0, 0, 0, 0, 0, 2914024, 0, 64978), -- Feathering the Nest
(94210, 1, 17, 6, 468491, 257357, 2735, 2352, 0, 0, 0, 0, 0, 3097527, 0, 64978), -- Feathering the Nest
(94210, 0, 16, 6, 468491, 257357, 2736, 2351, 0, 0, 0, 0, 0, 3098462, 0, 64978), -- Feathering the Nest
(94210, 1, 15, 5, 468126, 257351, 2735, 2352, 0, 0, 0, 0, 0, 3097527, 0, 64978), -- Feathering the Nest
(94210, 0, 14, 5, 468126, 257351, 2736, 2351, 0, 0, 0, 0, 0, 3098462, 0, 64978), -- Feathering the Nest
(94210, 1, 13, 4, 468123, 255296, 2735, 2352, 0, 0, 0, 0, 0, 2914025, 0, 64978), -- Feathering the Nest
(94210, 0, 12, 4, 468123, 255296, 2736, 2351, 0, 0, 0, 0, 0, 2913539, 0, 64978), -- Feathering the Nest
(94210, 3, 11, 3, 468125, 257350, 2735, 2352, 0, 0, 0, 0, 0, 3097851, 0, 64978), -- Feathering the Nest
(94210, 2, 10, 3, 468125, 257350, 2735, 2352, 0, 0, 0, 0, 0, 3097850, 0, 64978), -- Feathering the Nest
(94210, 1, 9, 3, 468125, 257350, 2736, 2351, 0, 0, 0, 0, 0, 3098136, 0, 64978), -- Feathering the Nest
(94210, 0, 8, 3, 468125, 257350, 2736, 2351, 0, 0, 0, 0, 0, 3098138, 0, 64978), -- Feathering the Nest
(94210, 1, 7, 2, 468124, 257349, 2735, 2352, 0, 0, 0, 0, 0, 3098145, 0, 64978), -- Feathering the Nest
(94210, 0, 6, 2, 468124, 257349, 2736, 2351, 0, 0, 0, 0, 0, 3098144, 0, 64978), -- Feathering the Nest
(94210, 3, 5, 1, 468122, 255291, 2735, 2352, 0, 0, 0, 0, 0, 3097893, 0, 64978), -- Feathering the Nest
(94210, 2, 4, 1, 468122, 255291, 2735, 2352, 0, 0, 0, 0, 0, 3097897, 0, 64978), -- Feathering the Nest
(94210, 1, 3, 1, 468122, 255291, 2736, 2351, 0, 0, 0, 0, 0, 3098135, 0, 64978), -- Feathering the Nest
(94210, 0, 2, 1, 468122, 255291, 2736, 2351, 0, 0, 0, 0, 0, 3097903, 0, 64978), -- Feathering the Nest
(94210, 0, 1, -1, 0, 0, 2736, 2351, 0, 0, 0, 0, 0, 2779505, 0, 64978), -- Feathering the Nest
(94210, 0, 0, -1, 0, 0, 2735, 2352, 0, 0, 0, 0, 0, 2914024, 0, 64978), -- Feathering the Nest
(94455, 1, 1, 31, 0, 0, 2736, 2351, 0, 2, 0, 149921, 0, 0, 0, 64978), -- Home at Last
(94455, 0, 0, 31, 0, 0, 2735, 2352, 0, 2, 0, 149922, 0, 0, 0, 64978), -- Home at Last
(91863, 1, 21, 17, 463610, 248858, 2736, 2351, 0, 2, 0, 145790, 0, 0, 0, 64978), -- My First Home
(91863, 0, 20, 17, 463610, 248858, 2735, 2352, 0, 2, 0, 145789, 0, 0, 0, 64978), -- My First Home
(91863, 0, 19, 15, 463641, 38960, 2735, 2352, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 18, 14, 463640, 38962, 2735, 2352, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 17, 13, 463639, 38961, 2735, 2352, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 16, 12, 463638, 38958, 2735, 2352, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 15, 11, 463637, 38959, 2735, 2352, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 14, 10, 463636, 38957, 2735, 2352, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 13, 9, 463635, 38952, 2736, 2351, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 12, 8, 463634, 38953, 2736, 2351, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 11, 7, 463633, 38954, 2736, 2351, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 10, 6, 463632, 38955, 2736, 2351, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 9, 5, 463631, 38956, 2736, 2351, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 0, 8, 4, 463630, 38951, 2736, 2351, 0, 0, 0, 146925, 0, 0, 0, 64978), -- My First Home
(91863, 1, 7, 3, 463609, 248857, 2735, 2352, 0, 0, 0, 0, 0, 2914024, 0, 64978), -- My First Home
(91863, 0, 6, 3, 463609, 248857, 2736, 2351, 0, 0, 0, 0, 0, 2779505, 0, 64978), -- My First Home
(91863, 0, 5, 2, 464281, 233708, 2736, 2351, 0, 0, 0, 0, 0, 2779505, 0, 64978), -- My First Home
(91863, 0, 4, 1, 464280, 233063, 2735, 2352, 0, 0, 0, 0, 0, 2914024, 0, 64978), -- My First Home
(91863, 1, 3, 0, 463615, 249851, 2735, 2352, 0, 0, 0, 0, 0, 2914024, 0, 64978), -- My First Home
(91863, 0, 2, 0, 463615, 249851, 2736, 2351, 0, 0, 0, 0, 0, 2779505, 0, 64978), -- My First Home
(91863, 0, 1, -1, 0, 0, 2735, 2352, 0, 0, 0, 0, 0, 2914024, 0, 64978), -- My First Home
(91863, 0, 0, -1, 0, 0, 2736, 2351, 0, 0, 0, 0, 0, 2779505, 0, 64978), -- My First Home
(93057, 1, 1, 0, 466019, 218238, 2735, 2352, 0, 2, 0, 23503, 0, 0, 0, 64978), -- A House For You
(93057, 0, 0, 0, 466019, 218238, 2736, 2351, 0, 2, 0, 23504, 0, 0, 0, 64978), -- A House For You
(90911, 1, 4, 32, 0, 0, 2927, 2451, 0, 0, 0, 122972, 0, 2811190, 0, 64978), -- Your Next Adventure
(90911, 0, 3, 32, 0, 0, 2927, 2451, 0, 0, 0, 122973, 0, 2811189, 0, 64978), -- Your Next Adventure
(90911, 1, 2, 0, 461829, 244885, 2927, 2451, 0, 0, 0, 20068, 0, 2811189, 0, 64978), -- Your Next Adventure
(90911, 0, 1, 0, 461829, 244885, 2927, 2451, 0, 0, 0, 23504, 0, 2811190, 0, 64978), -- Your Next Adventure
(90911, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2811190, 0, 64978), -- Your Next Adventure
(90898, 0, 1, 32, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810658, 0, 64978), -- Back to Hammerfall
(90898, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2811190, 0, 64978), -- Back to Hammerfall
(90896, 0, 2, 32, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810658, 0, 64978), -- One Last Ogre
(90896, 0, 1, 0, 461768, 244709, 2927, 2451, 0, 0, 0, 0, 0, 2811137, 0, 64978), -- One Last Ogre
(90896, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810658, 0, 64978), -- One Last Ogre
(90893, 0, 2, 32, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810628, 0, 64978), -- Repelling the Siege
(90893, 0, 1, 1, 461753, 244683, 2927, 2451, 0, 2, 0, 0, 0, 0, 1, 64978), -- Repelling the Siege
(90893, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810658, 0, 64978), -- Repelling the Siege
(92028, 0, 3, 32, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2923286, 0, 64978), -- Pardon the Interruption
(92028, 0, 2, 1, 463996, 249347, 2927, 2451, 0, 2, 0, 0, 0, 0, 0, 64978), -- Pardon the Interruption
(92028, 0, 1, 0, 463995, 249351, 2927, 2451, 0, 0, 0, 0, 0, 2922038, 0, 64978), -- Pardon the Interruption
(92028, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2924218, 0, 64978), -- Pardon the Interruption
(90895, 0, 2, 32, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810629, 0, 64978), -- Catapult Bombardment
(90895, 0, 1, 0, 461767, 249269, 2927, 2451, 0, 2, 0, 0, 0, 0, 0, 64978), -- Catapult Bombardment
(90895, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810659, 0, 64978), -- Catapult Bombardment
(90888, 0, 1, 32, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810624, 0, 64978), -- Saving Stromgarde Keep
(90888, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810629, 0, 64978), -- Saving Stromgarde Keep
(90886, 0, 2, 32, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810626, 0, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 0, 1, 0, 461734, 243573, 2927, 2451, 0, 0, 0, 0, 0, 0, 0, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810626, 0, 64978), -- Best Laid Plans of Kobolds and Ogres
(90885, 0, 2, 32, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2811338, 0, 64978), -- My Beautiful Pumpkins
(90885, 0, 1, 0, 461736, 244956, 2927, 2451, 0, 0, 0, 0, 0, 0, 0, 64978), -- My Beautiful Pumpkins
(90885, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810626, 0, 64978), -- My Beautiful Pumpkins
(90887, 0, 2, 32, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810624, 0, 64978), -- Farmer's Nemesis
(90887, 0, 1, 0, 461733, 244675, 2927, 2451, 0, 0, 0, 0, 0, 2810823, 0, 64978), -- Farmer's Nemesis
(90887, 0, 0, -1, 0, 0, 2927, 2451, 0, 0, 0, 0, 0, 2810624, 0, 64978); -- Farmer's Nemesis

UPDATE `quest_poi` SET `VerifiedBuild`=64978 WHERE (`QuestID`=66577 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=66577 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=66577 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=65436 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=65436 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=65436 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=76113 AND `BlobIndex`=2 AND `Idx1`=5) OR (`QuestID`=76113 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=76113 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=76113 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=76113 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=76113 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90719 AND `BlobIndex`=4 AND `Idx1`=5) OR (`QuestID`=90719 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=90719 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=90719 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=90719 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=90719 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=89332 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=89332 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=89331 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=89331 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=88803 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=88803 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=83492 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=76112 AND `BlobIndex`=2 AND `Idx1`=5) OR (`QuestID`=76112 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=76112 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=76112 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=76112 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=76112 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71229 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=71229 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=71229 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=26) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=25) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=24) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=23) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=22) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=21) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=20) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=19) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=18) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=17) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=16) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=15) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=14) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=13) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=12) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=11) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=10) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=9) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=8) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=71227 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71210 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=71210 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=71210 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=71210 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=71210 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71151 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71150 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71149 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71148 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71146 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=70702 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=91624 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=91624 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=91173 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=91173 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=83759 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=83759 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=83758 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=83758 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=83758 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=79553 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=79553 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=79553 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=78463 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=78463 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=78463 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=57267 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=57267 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=57267 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=57263 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=57263 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=57263 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=91461 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=91461 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=91461 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=87374 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71161 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=71161 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=71161 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=91089 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=91089 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=91089 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=91089 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=88945 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=88945 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=88945 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=88916 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=88916 AND `BlobIndex`=2 AND `Idx1`=4) OR (`QuestID`=88916 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=88916 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=88916 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=88916 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=88711 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=88711 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=88711 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=80670 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=80670 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=80670 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=80388 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=80388 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=80388 AND `BlobIndex`=3 AND `Idx1`=5) OR (`QuestID`=80388 AND `BlobIndex`=2 AND `Idx1`=4) OR (`QuestID`=80388 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=80388 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=80388 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=80388 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=9) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=8) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=79024 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=78876 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=78876 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=78876 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=76317 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=75874 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=71093 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=71093 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53734 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53734 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53466 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53466 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=84370 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=85648 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=85648 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=85648 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=90705 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=90705 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=90705 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=84956 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=84956 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `ObjectiveIndex`=32, `QuestObjectiveID`=0, `QuestObjectID`=0, `UiMapID`=2023, `Flags`=0, `PlayerConditionID`=0, `SpawnTrackingID`=2349078, `VerifiedBuild`=64978 WHERE (`QuestID`=76317 AND `BlobIndex`=0 AND `Idx1`=1); -- Call of the Dream
DELETE FROM `quest_poi_points` WHERE (`QuestID`=83492 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=83492 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=85001 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=85001 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=85001 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=85001 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=85001 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=85001 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=85001 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=85001 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=85001 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=85001 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=84998 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=84998 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=84998 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=84997 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=84997 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=84997 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=84996 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=84996 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=84996 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=84996 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=92405 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=92405 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=94379 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=94379 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=94379 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=94379 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=94379 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=94379 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=94379 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=94379 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=11) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=10) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=9) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=8) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=7) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=92984 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=19 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=18 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=17 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=16 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=15 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=14 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=13 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=12 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=11 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=10 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=9 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=94210 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=94455 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=11) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=10) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=9) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=8) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=7) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=94455 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=11) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=10) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=9) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=8) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=21 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=11) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=10) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=9) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=8) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=20 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=19 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=19 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=19 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=19 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=19 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=19 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=19 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=19 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=18 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=18 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=18 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=18 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=18 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=18 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=18 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=18 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=17 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=17 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=17 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=17 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=17 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=17 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=17 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=17 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=16 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=16 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=16 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=16 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=16 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=16 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=16 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=16 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=15 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=15 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=15 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=15 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=15 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=15 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=15 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=15 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=14 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=14 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=14 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=14 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=14 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=14 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=14 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=14 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=13 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=13 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=13 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=13 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=13 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=13 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=13 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=13 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=12 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=12 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=12 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=12 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=12 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=12 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=12 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=12 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=11 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=11 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=11 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=11 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=11 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=11 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=11 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=11 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=10 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=10 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=10 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=10 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=10 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=10 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=10 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=10 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=9 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=9 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=9 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=9 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=9 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=9 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=9 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=9 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=8 AND `Idx2`=7) OR (`QuestID`=91863 AND `Idx1`=8 AND `Idx2`=6) OR (`QuestID`=91863 AND `Idx1`=8 AND `Idx2`=5) OR (`QuestID`=91863 AND `Idx1`=8 AND `Idx2`=4) OR (`QuestID`=91863 AND `Idx1`=8 AND `Idx2`=3) OR (`QuestID`=91863 AND `Idx1`=8 AND `Idx2`=2) OR (`QuestID`=91863 AND `Idx1`=8 AND `Idx2`=1) OR (`QuestID`=91863 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=91863 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=93057 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=93057 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90911 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=90911 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=90911 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90911 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90911 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90898 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90898 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90896 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90896 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90896 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90893 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=90893 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90893 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=92028 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=92028 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=92028 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=92028 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90895 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=90895 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90895 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90888 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90888 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90886 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=90886 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90886 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90885 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90885 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=90885 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=90885 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=90885 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90885 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90887 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90887 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90887 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(83492, 2, 0, 1564, -4192, 54, 64978), -- Warbands: Warbanding Together
(83492, 1, 0, -8173, 801, 74, 64978), -- Warbands: Warbanding Together
(85001, 2, 0, 2732, -608, 11, 64978), -- Blessings Be Upon You
(85001, 1, 7, 2557, -673, 39, 64978), -- Blessings Be Upon You
(85001, 1, 6, 2542, -661, 41, 64978), -- Blessings Be Upon You
(85001, 1, 5, 2584, -626, 33, 64978), -- Blessings Be Upon You
(85001, 1, 4, 2618, -609, 19, 64978), -- Blessings Be Upon You
(85001, 1, 3, 2653, -595, 11, 64978), -- Blessings Be Upon You
(85001, 1, 2, 2672, -594, 11, 64978), -- Blessings Be Upon You
(85001, 1, 1, 2657, -697, 16, 64978), -- Blessings Be Upon You
(85001, 1, 0, 2624, -700, 17, 64978), -- Blessings Be Upon You
(85001, 0, 0, 2732, -608, 11, 64978), -- Blessings Be Upon You
(84998, 2, 0, 2732, -610, 10, 64978), -- Bringer of the Void
(84998, 1, 0, 2507, -618, 43, 64978), -- Bringer of the Void
(84998, 0, 0, 2732, -610, 10, 64978), -- Bringer of the Void
(84997, 2, 0, 2732, -610, 10, 64978), -- What Might Come
(84997, 1, 0, 2732, -610, 10, 64978), -- What Might Come
(84997, 0, 0, 2732, -610, 10, 64978), -- What Might Come
(84996, 3, 0, 2596, -780, 31, 64978), -- Vereesa's Tale
(84996, 2, 0, 2596, -780, 31, 64978), -- Vereesa's Tale
(84996, 1, 0, 2732, -610, 10, 64978), -- Vereesa's Tale
(84996, 0, 0, 2732, -610, 10, 64978), -- Vereesa's Tale
(92405, 1, 0, 2659, -2616, 224, 64978), -- Meet Arator
(92405, 0, 0, 2594, -781, 31, 64978), -- Meet Arator
(94379, 7, 0, 1715, 95, 102, 64978), -- This Old Hearth
(94379, 6, 0, 3323, 72, 101, 64978), -- This Old Hearth
(94379, 5, 0, 3339, 24, 99, 64978), -- This Old Hearth
(94379, 4, 0, 1764, 216, 107, 64978), -- This Old Hearth
(94379, 3, 0, 3339, 24, 99, 64978), -- This Old Hearth
(94379, 2, 0, 1764, 216, 107, 64978), -- This Old Hearth
(94379, 1, 0, 1715, 95, 102, 64978), -- This Old Hearth
(94379, 0, 0, 3323, 72, 101, 64978), -- This Old Hearth
(92984, 0, 11, 2714, -763, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 10, 2120, -653, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 9, 1953, -359, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 8, 2005, 1078, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 7, 2161, 1251, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 6, 3444, 1700, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 5, 3835, 1435, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 4, 3956, 1061, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 3, 4002, -43, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 2, 3720, -452, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 1, 3392, -613, 0, 64978), -- Decor Treasure Hunt
(92984, 0, 0, 3110, -693, 0, 64978), -- Decor Treasure Hunt
(94210, 19, 0, 1715, 95, 102, 64978), -- Feathering the Nest
(94210, 18, 0, 3323, 72, 101, 64978), -- Feathering the Nest
(94210, 17, 0, 1882, -426, 1, 64978), -- Feathering the Nest
(94210, 16, 0, 1028, 1151, 9, 64978), -- Feathering the Nest
(94210, 15, 0, 1882, -426, 1, 64978), -- Feathering the Nest
(94210, 14, 0, 1028, 1151, 9, 64978), -- Feathering the Nest
(94210, 13, 0, 3416, 94, 96, 64978), -- Feathering the Nest
(94210, 12, 0, 1728, 205, 100, 64978), -- Feathering the Nest
(94210, 11, 0, 3405, 120, 96, 64978), -- Feathering the Nest
(94210, 10, 0, 3403, 122, 96, 64978), -- Feathering the Nest
(94210, 9, 0, 1677, 214, 99, 64978), -- Feathering the Nest
(94210, 8, 0, 1675, 219, 99, 64978), -- Feathering the Nest
(94210, 7, 0, 3292, 54, 103, 64978), -- Feathering the Nest
(94210, 6, 0, 1720, 209, 100, 64978), -- Feathering the Nest
(94210, 5, 0, 3386, 135, 96, 64978), -- Feathering the Nest
(94210, 4, 0, 3382, 134, 96, 64978), -- Feathering the Nest
(94210, 3, 0, 1652, 175, 99, 64978), -- Feathering the Nest
(94210, 2, 0, 1649, 176, 99, 64978), -- Feathering the Nest
(94210, 1, 0, 1715, 95, 102, 64978), -- Feathering the Nest
(94210, 0, 0, 3323, 72, 101, 64978), -- Feathering the Nest
(94455, 1, 11, 1567, -1052, 0, 64978), -- Home at Last
(94455, 1, 10, 801, -680, 0, 64978), -- Home at Last
(94455, 1, 9, 362, -320, 0, 64978), -- Home at Last
(94455, 1, 8, 181, 6, 0, 64978), -- Home at Last
(94455, 1, 7, 80, 615, 0, 64978), -- Home at Last
(94455, 1, 6, 452, 975, 0, 64978), -- Home at Last
(94455, 1, 5, 925, 1133, 0, 64978), -- Home at Last
(94455, 1, 4, 1691, 1268, 0, 64978), -- Home at Last
(94455, 1, 3, 2097, 998, 0, 64978), -- Home at Last
(94455, 1, 2, 2277, 175, 0, 64978), -- Home at Last
(94455, 1, 1, 2401, -950, 0, 64978), -- Home at Last
(94455, 1, 0, 2018, -1142, 0, 64978), -- Home at Last
(94455, 0, 11, 2663, -711, 0, 64978), -- Home at Last
(94455, 0, 10, 2289, -542, 0, 64978), -- Home at Last
(94455, 0, 9, 2129, 44, 0, 64978), -- Home at Last
(94455, 0, 8, 2405, 1005, 0, 64978), -- Home at Last
(94455, 0, 7, 2689, 1272, 0, 64978), -- Home at Last
(94455, 0, 6, 3383, 1663, 0, 64978), -- Home at Last
(94455, 0, 5, 3668, 1619, 0, 64978), -- Home at Last
(94455, 0, 4, 3935, 1227, 0, 64978), -- Home at Last
(94455, 0, 3, 3908, 783, 0, 64978), -- Home at Last
(94455, 0, 2, 3837, 347, 0, 64978), -- Home at Last
(94455, 0, 1, 3490, -542, 0, 64978), -- Home at Last
(94455, 0, 0, 3134, -755, 0, 64978), -- Home at Last
(91863, 21, 11, 755, -641, 0, 64978), -- My First Home
(91863, 21, 10, 271, -120, 0, 64978), -- My First Home
(91863, 21, 9, 99, 338, 0, 64978), -- My First Home
(91863, 21, 8, 118, 754, 0, 64978), -- My First Home
(91863, 21, 7, 553, 919, 0, 64978), -- My First Home
(91863, 21, 6, 1079, 1249, 0, 64978), -- My First Home
(91863, 21, 5, 1752, 1182, 0, 64978), -- My First Home
(91863, 21, 4, 2113, 1084, 0, 64978), -- My First Home
(91863, 21, 3, 1960, 32, 0, 64978), -- My First Home
(91863, 21, 2, 2431, -800, 0, 64978), -- My First Home
(91863, 21, 1, 1782, -1130, 0, 64978), -- My First Home
(91863, 21, 0, 1379, -806, 0, 64978), -- My First Home
(91863, 20, 11, 2615, -717, 0, 64978), -- My First Home
(91863, 20, 10, 2057, -382, 0, 64978), -- My First Home
(91863, 20, 9, 2103, -78, 0, 64978), -- My First Home
(91863, 20, 8, 2425, 318, 0, 64978), -- My First Home
(91863, 20, 7, 2287, 813, 0, 64978), -- My First Home
(91863, 20, 6, 2679, 1303, 0, 64978), -- My First Home
(91863, 20, 5, 3478, 1648, 0, 64978), -- My First Home
(91863, 20, 4, 3766, 1389, 0, 64978), -- My First Home
(91863, 20, 3, 3922, 1193, 0, 64978), -- My First Home
(91863, 20, 2, 3721, 508, 0, 64978), -- My First Home
(91863, 20, 1, 3772, 227, 0, 64978), -- My First Home
(91863, 20, 0, 3381, -671, 0, 64978), -- My First Home
(91863, 19, 7, 2951, 453, 77, 64978), -- My First Home
(91863, 19, 6, 2934, 495, 77, 64978), -- My First Home
(91863, 19, 5, 2951, 538, 77, 64978), -- My First Home
(91863, 19, 4, 2994, 555, 77, 64978), -- My First Home
(91863, 19, 3, 3036, 538, 77, 64978), -- My First Home
(91863, 19, 2, 3054, 495, 77, 64978), -- My First Home
(91863, 19, 1, 3036, 453, 77, 64978), -- My First Home
(91863, 19, 0, 2994, 435, 77, 64978), -- My First Home
(91863, 18, 7, 3635, 700, 78, 64978), -- My First Home
(91863, 18, 6, 3618, 742, 78, 64978), -- My First Home
(91863, 18, 5, 3635, 785, 78, 64978), -- My First Home
(91863, 18, 4, 3678, 802, 78, 64978), -- My First Home
(91863, 18, 3, 3720, 785, 78, 64978), -- My First Home
(91863, 18, 2, 3738, 742, 78, 64978), -- My First Home
(91863, 18, 1, 3720, 700, 78, 64978), -- My First Home
(91863, 18, 0, 3678, 682, 78, 64978), -- My First Home
(91863, 17, 7, 3335, -524, 197, 64978), -- My First Home
(91863, 17, 6, 3318, -482, 197, 64978), -- My First Home
(91863, 17, 5, 3335, -439, 197, 64978), -- My First Home
(91863, 17, 4, 3378, -422, 197, 64978), -- My First Home
(91863, 17, 3, 3420, -439, 197, 64978), -- My First Home
(91863, 17, 2, 3438, -482, 197, 64978), -- My First Home
(91863, 17, 1, 3420, -524, 197, 64978), -- My First Home
(91863, 17, 0, 3378, -542, 197, 64978), -- My First Home
(91863, 16, 7, 2484, -206, 84, 64978), -- My First Home
(91863, 16, 6, 2466, -163, 84, 64978), -- My First Home
(91863, 16, 5, 2484, -121, 84, 64978), -- My First Home
(91863, 16, 4, 2526, -103, 84, 64978), -- My First Home
(91863, 16, 3, 2568, -121, 84, 64978), -- My First Home
(91863, 16, 2, 2586, -163, 84, 64978), -- My First Home
(91863, 16, 1, 2568, -206, 84, 64978), -- My First Home
(91863, 16, 0, 2526, -223, 84, 64978), -- My First Home
(91863, 15, 7, 3082, 1267, 12, 64978), -- My First Home
(91863, 15, 6, 3064, 1310, 12, 64978), -- My First Home
(91863, 15, 5, 3082, 1352, 12, 64978), -- My First Home
(91863, 15, 4, 3124, 1370, 12, 64978), -- My First Home
(91863, 15, 3, 3167, 1352, 12, 64978), -- My First Home
(91863, 15, 2, 3184, 1310, 12, 64978), -- My First Home
(91863, 15, 1, 3167, 1267, 12, 64978), -- My First Home
(91863, 15, 0, 3124, 1250, 12, 64978), -- My First Home
(91863, 14, 7, 2414, 804, 42, 64978), -- My First Home
(91863, 14, 6, 2396, 847, 42, 64978), -- My First Home
(91863, 14, 5, 2414, 889, 42, 64978), -- My First Home
(91863, 14, 4, 2456, 907, 42, 64978), -- My First Home
(91863, 14, 3, 2499, 889, 42, 64978), -- My First Home
(91863, 14, 2, 2516, 847, 42, 64978), -- My First Home
(91863, 14, 1, 2499, 804, 42, 64978), -- My First Home
(91863, 14, 0, 2456, 787, 42, 64978), -- My First Home
(91863, 13, 7, 1507, 642, 23, 64978), -- My First Home
(91863, 13, 6, 1490, 685, 23, 64978), -- My First Home
(91863, 13, 5, 1507, 727, 23, 64978), -- My First Home
(91863, 13, 4, 1550, 745, 23, 64978), -- My First Home
(91863, 13, 3, 1592, 727, 23, 64978), -- My First Home
(91863, 13, 2, 1610, 685, 23, 64978), -- My First Home
(91863, 13, 1, 1592, 642, 23, 64978), -- My First Home
(91863, 13, 0, 1550, 625, 23, 64978), -- My First Home
(91863, 12, 7, 960, -799, 8, 64978), -- My First Home
(91863, 12, 6, 943, -756, 8, 64978), -- My First Home
(91863, 12, 5, 960, -714, 8, 64978), -- My First Home
(91863, 12, 4, 1003, -696, 8, 64978), -- My First Home
(91863, 12, 3, 1045, -714, 8, 64978), -- My First Home
(91863, 12, 2, 1063, -756, 8, 64978), -- My First Home
(91863, 12, 1, 1045, -799, 8, 64978), -- My First Home
(91863, 12, 0, 1003, -816, 8, 64978), -- My First Home
(91863, 11, 7, 1064, -148, 76, 64978), -- My First Home
(91863, 11, 6, 1047, -106, 76, 64978), -- My First Home
(91863, 11, 5, 1064, -63, 76, 64978), -- My First Home
(91863, 11, 4, 1107, -46, 76, 64978), -- My First Home
(91863, 11, 3, 1149, -63, 76, 64978), -- My First Home
(91863, 11, 2, 1167, -106, 76, 64978), -- My First Home
(91863, 11, 1, 1149, -148, 76, 64978), -- My First Home
(91863, 11, 0, 1107, -166, 76, 64978), -- My First Home
(91863, 10, 7, 1956, -424, 135, 64978), -- My First Home
(91863, 10, 6, 1938, -382, 135, 64978), -- My First Home
(91863, 10, 5, 1956, -339, 135, 64978), -- My First Home
(91863, 10, 4, 1998, -322, 135, 64978), -- My First Home
(91863, 10, 3, 2041, -339, 135, 64978), -- My First Home
(91863, 10, 2, 2058, -382, 135, 64978), -- My First Home
(91863, 10, 1, 2041, -424, 135, 64978), -- My First Home
(91863, 10, 0, 1998, -442, 135, 64978), -- My First Home
(91863, 9, 7, 765, 243, 68, 64978), -- My First Home
(91863, 9, 6, 747, 286, 68, 64978), -- My First Home
(91863, 9, 5, 765, 328, 68, 64978), -- My First Home
(91863, 9, 4, 807, 346, 68, 64978), -- My First Home
(91863, 9, 3, 850, 328, 68, 64978), -- My First Home
(91863, 9, 2, 867, 286, 68, 64978), -- My First Home
(91863, 9, 1, 850, 243, 68, 64978), -- My First Home
(91863, 9, 0, 807, 226, 68, 64978), -- My First Home
(91863, 8, 7, 890, 909, 1, 64978), -- My First Home
(91863, 8, 6, 873, 952, 1, 64978), -- My First Home
(91863, 8, 5, 890, 994, 1, 64978), -- My First Home
(91863, 8, 4, 933, 1012, 1, 64978), -- My First Home
(91863, 8, 3, 975, 994, 1, 64978), -- My First Home
(91863, 8, 2, 993, 952, 1, 64978), -- My First Home
(91863, 8, 1, 975, 909, 1, 64978), -- My First Home
(91863, 8, 0, 933, 892, 1, 64978), -- My First Home
(91863, 7, 0, 3323, 77, 102, 64978), -- My First Home
(91863, 6, 0, 1715, 95, 102, 64978), -- My First Home
(91863, 5, 0, 1715, 95, 102, 64978), -- My First Home
(91863, 4, 0, 3323, 77, 102, 64978), -- My First Home
(91863, 3, 0, 3323, 77, 102, 64978), -- My First Home
(91863, 2, 0, 1715, 95, 102, 64978), -- My First Home
(91863, 1, 0, 3323, 77, 102, 64978), -- My First Home
(91863, 0, 0, 1715, 95, 102, 64978), -- My First Home
(93057, 1, 0, 3775, -160, 191, 64978), -- A House For You
(93057, 0, 0, 2068, 175, 175, 64978), -- A House For You
(90911, 4, 0, -943, -3534, 71, 64978), -- Your Next Adventure
(90911, 3, 0, -1570, -1807, 68, 64978), -- Your Next Adventure
(90911, 2, 0, -1570, -1807, 68, 64978), -- Your Next Adventure
(90911, 1, 0, -943, -3534, 71, 64978), -- Your Next Adventure
(90911, 0, 0, -943, -3534, 71, 64978), -- Your Next Adventure
(90898, 1, 0, -1001, -1982, 62, 64978), -- Back to Hammerfall
(90898, 0, 0, -943, -3534, 71, 64978), -- Back to Hammerfall
(90896, 2, 0, -1001, -1982, 62, 64978), -- One Last Ogre
(90896, 1, 0, -854, -2133, 67, 64978), -- One Last Ogre
(90896, 0, 0, -1001, -1982, 62, 64978), -- One Last Ogre
(90893, 2, 0, -1473, -1800, 95, 64978), -- Repelling the Siege
(90893, 1, 11, -1441, -1939, 62, 64978), -- Repelling the Siege
(90893, 1, 10, -1429, -1813, 62, 64978), -- Repelling the Siege
(90893, 1, 9, -1406, -1747, 62, 64978), -- Repelling the Siege
(90893, 1, 8, -1375, -1682, 62, 64978), -- Repelling the Siege
(90893, 1, 7, -1313, -1611, 62, 64978), -- Repelling the Siege
(90893, 1, 6, -1225, -1631, 62, 64978), -- Repelling the Siege
(90893, 1, 5, -1166, -1707, 62, 64978), -- Repelling the Siege
(90893, 1, 4, -1141, -1773, 62, 64978), -- Repelling the Siege
(90893, 1, 3, -1140, -1862, 62, 64978), -- Repelling the Siege
(90893, 1, 2, -1145, -1923, 62, 64978), -- Repelling the Siege
(90893, 1, 1, -1200, -1987, 62, 64978), -- Repelling the Siege
(90893, 1, 0, -1338, -2000, 62, 64978), -- Repelling the Siege
(90893, 0, 0, -1001, -1982, 62, 64978), -- Repelling the Siege
(92028, 3, 0, -1473, -1808, 94, 64978), -- Pardon the Interruption
(92028, 2, 11, -1549, -1890, 0, 64978), -- Pardon the Interruption
(92028, 2, 10, -1549, -1875, 0, 64978), -- Pardon the Interruption
(92028, 2, 9, -1549, -1863, 0, 64978), -- Pardon the Interruption
(92028, 2, 8, -1548, -1845, 0, 64978), -- Pardon the Interruption
(92028, 2, 7, -1541, -1838, 0, 64978), -- Pardon the Interruption
(92028, 2, 6, -1531, -1834, 0, 64978), -- Pardon the Interruption
(92028, 2, 5, -1514, -1838, 0, 64978); -- Pardon the Interruption

INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(92028, 2, 4, -1504, -1851, 0, 64978), -- Pardon the Interruption
(92028, 2, 3, -1508, -1867, 0, 64978), -- Pardon the Interruption
(92028, 2, 2, -1517, -1879, 0, 64978), -- Pardon the Interruption
(92028, 2, 1, -1530, -1890, 0, 64978), -- Pardon the Interruption
(92028, 2, 0, -1539, -1893, 0, 64978), -- Pardon the Interruption
(92028, 1, 0, -1524, -1855, 69, 64978), -- Pardon the Interruption
(92028, 0, 0, -1525, -1852, 69, 64978), -- Pardon the Interruption
(90895, 2, 0, -1473, -1804, 95, 64978), -- Catapult Bombardment
(90895, 1, 11, -1365, -1983, 67, 64978), -- Catapult Bombardment
(90895, 1, 10, -1385, -1910, 67, 64978), -- Catapult Bombardment
(90895, 1, 9, -1378, -1863, 67, 64978), -- Catapult Bombardment
(90895, 1, 8, -1348, -1787, 67, 64978), -- Catapult Bombardment
(90895, 1, 7, -1272, -1710, 67, 64978), -- Catapult Bombardment
(90895, 1, 6, -1172, -1717, 67, 64978), -- Catapult Bombardment
(90895, 1, 5, -1135, -1780, 67, 64978), -- Catapult Bombardment
(90895, 1, 4, -1118, -1860, 67, 64978), -- Catapult Bombardment
(90895, 1, 3, -1135, -1937, 67, 64978), -- Catapult Bombardment
(90895, 1, 2, -1182, -1993, 67, 64978), -- Catapult Bombardment
(90895, 1, 1, -1228, -2010, 67, 64978), -- Catapult Bombardment
(90895, 1, 0, -1298, -2010, 67, 64978), -- Catapult Bombardment
(90895, 0, 0, -1002, -1985, 62, 64978), -- Catapult Bombardment
(90888, 1, 0, -1526, -3090, 26, 64978), -- Saving Stromgarde Keep
(90888, 0, 0, -1473, -1804, 95, 64978), -- Saving Stromgarde Keep
(90886, 2, 0, -1523, -3086, 26, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 11, -1593, -2996, 16, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 10, -1601, -2977, 22, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 9, -1618, -2880, 20, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 8, -1615, -2877, 20, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 7, -1562, -2866, 15, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 6, -1525, -2860, 14, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 5, -1461, -2875, 14, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 4, -1456, -2879, 14, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 3, -1404, -2992, 24, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 2, -1500, -3015, 15, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 1, -1534, -3022, 14, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 1, 0, -1563, -3026, 14, 64978), -- Best Laid Plans of Kobolds and Ogres
(90886, 0, 0, -1523, -3086, 26, 64978), -- Best Laid Plans of Kobolds and Ogres
(90885, 2, 0, -1522, -3089, 26, 64978), -- My Beautiful Pumpkins
(90885, 1, 3, -1554, -2960, 14, 64978), -- My Beautiful Pumpkins
(90885, 1, 2, -1505, -2916, 14, 64978), -- My Beautiful Pumpkins
(90885, 1, 1, -1514, -2972, 14, 64978), -- My Beautiful Pumpkins
(90885, 1, 0, -1535, -3003, 14, 64978), -- My Beautiful Pumpkins
(90885, 0, 0, -1523, -3086, 26, 64978), -- My Beautiful Pumpkins
(90887, 2, 0, -1526, -3090, 26, 64978), -- Farmer's Nemesis
(90887, 1, 0, -1460, -3004, 14, 64978), -- Farmer's Nemesis
(90887, 0, 0, -1526, -3090, 26, 64978); -- Farmer's Nemesis

UPDATE `quest_poi_points` SET `VerifiedBuild`=64978 WHERE (`QuestID`=66577 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=66577 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=66577 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=65436 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=65436 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=65436 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=76113 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=76113 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=76113 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=76113 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=76113 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=76113 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90719 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=89332 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=89332 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=89331 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=89331 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=88803 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=88803 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=83492 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=76112 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=76112 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=76112 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=76112 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=76112 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=76112 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71229 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=71229 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=71229 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=26 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=25 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=24 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=23 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=22 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=21 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=20 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=19 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=18 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=17 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=16 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=15 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=14 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=13 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=12 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=11 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=10 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=9 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=71227 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=11) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=10) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=9) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=71210 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=11) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=10) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=9) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=71210 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=71210 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=71210 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=71210 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71151 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71150 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71149 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71148 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71146 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=70702 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=91624 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=91624 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=91173 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=91173 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=83759 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=83759 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=83758 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=83758 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=83758 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=79553 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=79553 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=79553 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=78463 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=78463 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=78463 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=78463 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=78463 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=78463 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=78463 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=78463 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=57267 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=57267 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=57267 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=57267 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=57267 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=57267 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=57267 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=57267 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=57263 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=57263 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=57263 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=57263 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=57263 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=57263 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=57263 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=57263 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=57263 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=91461 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=91461 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=91461 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=87374 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71161 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=71161 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=71161 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=91089 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=91089 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=91089 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=91089 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=88945 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=88945 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=88945 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=88945 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=88945 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=88945 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=88945 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=88945 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=88945 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=88945 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=88945 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=10) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=9) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=8) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=7) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=6) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=5) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=4) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=3) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=2) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=1) OR (`QuestID`=88916 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=88916 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=88916 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=88916 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=88916 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=88916 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=88711 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=88711 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=88711 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=80670 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=80670 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=80670 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=80388 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=80388 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=80388 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=80388 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=80388 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=80388 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=80388 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=80388 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=9 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=79024 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=78876 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=78876 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=78876 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=76317 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=75874 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=71093 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=71093 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=53734 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=53734 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=53466 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=53466 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=84370 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=85648 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=85648 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=85648 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=90705 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=90705 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=90705 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=84956 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=84956 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `X`=-1193, `Y`=5409, `Z`=31, `VerifiedBuild`=64978 WHERE (`QuestID`=76317 AND `Idx1`=1 AND `Idx2`=0); -- Call of the Dream

DELETE FROM `quest_details` WHERE `ID` IN (85001 /*Blessings Be Upon You*/, 84998 /*Bringer of the Void*/, 84997 /*What Might Come*/, 84996 /*Vereesa's Tale*/, 92405 /*Meet Arator*/, 92816 /*A Letter for Adventure*/, 94379 /*This Old Hearth*/, 92984 /*Decor Treasure Hunt*/, 94210 /*Feathering the Nest*/, 91969 /*Time to Decorate*/, 91863 /*My First Home*/, 90911 /*Your Next Adventure*/, 90898 /*Back to Hammerfall*/, 90896 /*One Last Ogre*/, 90893 /*Repelling the Siege*/, 92028 /*Pardon the Interruption*/, 90895 /*Catapult Bombardment*/, 90888 /*Saving Stromgarde Keep*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(85001, 5, 273, 0, 0, 0, 0, 0, 0, 64978), -- Blessings Be Upon You
(84998, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Bringer of the Void
(84997, 1, 0, 0, 0, 0, 0, 0, 0, 64978), -- What Might Come
(84996, 1, 273, 0, 0, 0, 0, 0, 0, 64978), -- Vereesa's Tale
(92405, 2, 25, 0, 0, 0, 0, 0, 0, 64978), -- Meet Arator
(92816, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- A Letter for Adventure
(94379, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- This Old Hearth
(92984, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Decor Treasure Hunt
(94210, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Feathering the Nest
(91969, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Time to Decorate
(91863, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- My First Home
(90911, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Your Next Adventure
(90898, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Back to Hammerfall
(90896, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- One Last Ogre
(90893, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Repelling the Siege
(92028, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Pardon the Interruption
(90895, 0, 0, 0, 0, 0, 0, 0, 0, 64978), -- Catapult Bombardment
(90888, 0, 0, 0, 0, 0, 0, 0, 0, 64978); -- Saving Stromgarde Keep

UPDATE `quest_details` SET `VerifiedBuild`=64978 WHERE `ID` IN (65436, 66577, 83758, 90778, 84370, 85648);

DELETE FROM `quest_description_conditional` WHERE (`QuestId`=90911 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=244715 AND `locale`='deDE') OR (`QuestId`=90911 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=244714 AND `locale`='deDE');
INSERT INTO `quest_description_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(90911, 0, 244715, 'deDE', 'Ihr habt hier gute Arbeit geleistet, $n. Andere Gebiete Azeroths bedürfen nun Eurer Hilfe.\n\nWohin wollt Ihr als Nächstes aufbrechen?', 1, 64978), -- Your Next Adventure
(90911, 0, 244714, 'deDE', 'Hier ist es derzeit ruhig, aber ich weiß von mehreren Gebieten in Azeroth, die Eure Hilfe gebrauchen könnten.\n\nIch kann Euch helfen, an jeden beliebigen Ort zu gelangen. Besprechen wir Euer nächstes Abenteuer.', 0, 64978); -- Your Next Adventure

UPDATE `quest_description_conditional` SET `VerifiedBuild`=64978 WHERE (`QuestId`=66577 AND `PlayerConditionId`=99433 AND `QuestgiverCreatureId`=0 AND `locale`='enUS') OR (`QuestId`=76113 AND `PlayerConditionId`=923 AND `QuestgiverCreatureId`=0 AND `locale`='enUS') OR (`QuestId`=83247 AND `PlayerConditionId`=124163 AND `QuestgiverCreatureId`=0 AND `locale`='enUS') OR (`QuestId`=80176 AND `PlayerConditionId`=41725 AND `QuestgiverCreatureId`=219135 AND `locale`='enUS') OR (`QuestId`=80175 AND `PlayerConditionId`=41725 AND `QuestgiverCreatureId`=215335 AND `locale`='enUS') OR (`QuestId`=76112 AND `PlayerConditionId`=923 AND `QuestgiverCreatureId`=0 AND `locale`='enUS') OR (`QuestId`=83247 AND `PlayerConditionId`=124163 AND `QuestgiverCreatureId`=0 AND `locale`='deDE') OR (`QuestId`=82680 AND `PlayerConditionId`=125262 AND `QuestgiverCreatureId`=224394 AND `locale`='deDE') OR (`QuestId`=80176 AND `PlayerConditionId`=41725 AND `QuestgiverCreatureId`=219135 AND `locale`='deDE') OR (`QuestId`=80175 AND `PlayerConditionId`=41725 AND `QuestgiverCreatureId`=215335 AND `locale`='deDE') OR (`QuestId`=90705 AND `PlayerConditionId`=20069 AND `QuestgiverCreatureId`=0 AND `locale`='enUS');

DELETE FROM `quest_completion_log_conditional` WHERE (`QuestId`=91968 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=0 AND `locale`='deDE');
INSERT INTO `quest_completion_log_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(91968, 0, 0, 'deDE', '', 0, 64978); -- Welcome Home

UPDATE `quest_completion_log_conditional` SET `VerifiedBuild`=64978 WHERE (`QuestId`=91968 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=0 AND `locale`='enUS') OR (`QuestId`=90705 AND `PlayerConditionId`=20069 AND `QuestgiverCreatureId`=0 AND `locale`='enUS');

DELETE FROM `quest_offer_reward_conditional` WHERE (`QuestId`=66577 AND `PlayerConditionId`=99433 AND `QuestgiverCreatureId`=0 AND `locale`='enUS') OR (`QuestId`=93647 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=255520 AND `locale`='deDE');
INSERT INTO `quest_offer_reward_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(66577, 99433, 0, 'enUS', 'There is much more to the Dragon Isles beyond the Forbidden Reach. I cannot wait for you to see it!\n\nNow then, I believe that diminutive archaeologist said something about putting together an expedition.', 0, 64978), -- Aspectral Invitation
(93647, 0, 255520, 'deDE', 'Ihr seht wie jemand aus, der sich gut im Holzfäll\'n mach\'n würd\'.\n\nHier, ich zeig\' Euch, woran Ihr Bäume erkennt, die sich zum Fäll\'n eignen.\n\nHolz is\' für viele Dinge in Euerm Haus nützlich. Oder auch für andere Häuser, wenn Ihr was verschenk\'n oder verkauf\'n wollt. Ich wette, die alten Handwerkslehrer, von denen Ihr gelernt habt, hab\'n neue Dinge anzubiet\'n.\n\nGeht da raus un\' schaut, was sich so mach\'n lässt!', 0, 64978); -- Lumber For You

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=84 AND `QuestLineId` IN (6058,6024,6021,6009,6008,6007,6006,5740,1107,242)) OR (`UIMapId`=2371 AND `QuestLineId` IN (6009,6008,6007,6006,5708,5707,5706,5709)) OR (`UIMapId`=2248 AND `QuestLineId` IN (6009,6008,6007,6006,5708,5707)) OR (`UIMapId`=2339 AND `QuestLineId` IN (6009,6008,6007,6006,5707)) OR (`UIMapId`=2352 AND `QuestLineId` IN (5673,5406,5389,1391,1377,1295,1294,612,584,565,432,418,199,177)) OR (`UIMapId`=2451 AND `QuestLineId` IN (5934,5684,747,434,409,390));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(84, 6058, 64978),
(84, 6024, 64978),
(84, 6021, 64978),
(84, 6009, 64978),
(84, 6008, 64978),
(84, 6007, 64978),
(84, 6006, 64978),
(84, 5740, 64978),
(84, 1107, 64978),
(84, 242, 64978),
(2371, 6009, 64978),
(2371, 6008, 64978),
(2371, 6007, 64978),
(2371, 6006, 64978),
(2371, 5708, 64978),
(2371, 5707, 64978),
(2371, 5706, 64978),
(2371, 5709, 64978),
(2248, 6009, 64978),
(2248, 6008, 64978),
(2248, 6007, 64978),
(2248, 6006, 64978),
(2248, 5708, 64978),
(2248, 5707, 64978),
(2339, 6009, 64978),
(2339, 6008, 64978),
(2339, 6007, 64978),
(2339, 6006, 64978),
(2339, 5707, 64978),
(2352, 5673, 64978),
(2352, 5406, 64978),
(2352, 5389, 64978),
(2352, 1391, 64978),
(2352, 1377, 64978),
(2352, 1295, 64978),
(2352, 1294, 64978),
(2352, 612, 64978),
(2352, 584, 64978),
(2352, 565, 64978),
(2352, 432, 64978),
(2352, 418, 64978),
(2352, 199, 64978),
(2352, 177, 64978),
(2451, 5934, 64978),
(2451, 5684, 64978),
(2451, 747, 64978),
(2451, 434, 64978),
(2451, 409, 64978),
(2451, 390, 64978);

UPDATE `ui_map_quest_line` SET `VerifiedBuild`=64978 WHERE (`UIMapId`=84 AND `QuestLineId` IN (5697,5691,5673,5638,5593,5519,5513,5511,5497,5482,5458,5382,5377,5372,1379,1289,1276,1267,1128,1108,1030,1000,972,957,929,926,916,858,797,781,737,637,635,589,576,547,546,539,533,532,526,421,347,346,300,289,262,259,240,198,131)) OR (`UIMapId`=2371 AND `QuestLineId` IN (5953,5906,5903,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5710,5705,5703,5699,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5654,5653,5651,5649,5648,5647,5646,5644,5642,5641,5638,5634,5631,5630,5628,5627,5620,5619,5618,5617,5615,5614,5613,5612,5610,5609,5607,5605,5603,5602,5601,5600,5598,5597,5593,5591,5574,5572,5565,5563,5562,5559,5558,5552,5551,5550,5544,5543,5542,5541,5540,5539,5535,5534,5533,5532,5531,5530,5529,5527,5526,5525,5524,5523,5522,5521,5520,5513,5512,5509,5506,1416)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5655,5654,5653,5652,5651,5648,5647,5644,5642,5641,5638,5634,5631,5630,5628,5627,5626,5625,5624,5623,5622,5621,5620,5619,5617,5615,5614,5611,5610,5609,5608,5607,5606,5605,5603,5602,5601,5600,5598,5597,5596,5593,5591,5590,5574,5572,5565,5563,5562,5559,5558,5552,5551,5550,5544,5542,5540,5539,5535,5534,5533,5532,5531,5530,5529,5527,5526,5525,5524,5523,5522,5521,5520,5513,5512,5509,5506,1416)) OR (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5542,5540,5539,5533,5531,5525,5523,5513,5509,1416)) OR (`UIMapId`=2249 AND `QuestLineId`=5666) OR (`UIMapId`=2269 AND `QuestLineId`=5666);

UPDATE `ui_map_quest` SET `VerifiedBuild`=64978 WHERE (`UIMapId`=2248 AND `QuestId` IN (84001,83827,86610,79232,82448,83079,82552,82256,82254)) OR (`UIMapId`=2339 AND `QuestId`=82448);

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2675971 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 25036*/, 2675972 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 25035*/, 2594570 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 25033*/, 2594440 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 25025*/, 2594242 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 25024*/, 2967842 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 27399*/, 2594241 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 25024*/, 2779505 /*Map: 2736 (Razorwind Shores) - Phase: 0*/, 2914024 /*Map: 2735 (Founder's Point) - Phase: 27429*/, 3094819 /*Map: 2735 (Founder's Point) - Phase: 0*/, 3094857 /*Map: 2736 (Razorwind Shores) - Phase: 0*/, 3097527 /*Map: 2735 (Founder's Point) - Phase: 0*/, 3098462 /*Map: 2736 (Razorwind Shores) - Phase: 0*/, 2914025 /*Map: 2735 (Founder's Point) - Phase: 0*/, 2913539 /*Map: 2736 (Razorwind Shores) - Phase: 0*/, 3097851 /*Map: 2735 (Founder's Point) - Phase: 0*/, 3097850 /*Map: 2735 (Founder's Point) - Phase: 0*/, 3098136 /*Map: 2736 (Razorwind Shores) - Phase: 0*/, 3098138 /*Map: 2736 (Razorwind Shores) - Phase: 0*/, 3098145 /*Map: 2735 (Founder's Point) - Phase: 0*/, 3098144 /*Map: 2736 (Razorwind Shores) - Phase: 0*/, 3097893 /*Map: 2735 (Founder's Point) - Phase: 0*/, 3097897 /*Map: 2735 (Founder's Point) - Phase: 0*/, 3098135 /*Map: 2736 (Razorwind Shores) - Phase: 0*/, 3097903 /*Map: 2736 (Razorwind Shores) - Phase: 0*/, 2811190 /*Map: 0 (Eastern Kingdoms) - Phase: 26610*/, 2811189 /*Map: 0 (Eastern Kingdoms) - Phase: 26609*/, 2810658 /*Map: 0 (Eastern Kingdoms) - Phase: 26608*/, 2811137 /*Map: 0 (Eastern Kingdoms) - Phase: 0*/, 2810628 /*Map: 0 (Eastern Kingdoms) - Phase: 26604*/, 2810629 /*Map: 0 (Eastern Kingdoms) - Phase: 26615*/, 2810659 /*Map: 0 (Eastern Kingdoms) - Phase: 26607*/, 2810905 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2810902 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2810865 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2810903 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2810906 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2810872 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2810863 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2810864 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2820253 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2923286 /*Map: 0 (Eastern Kingdoms) - Phase: 27245*/, 2922038 /*Map: 0 (Eastern Kingdoms) - Phase: 27239*/, 2924218 /*Map: 0 (Eastern Kingdoms) - Phase: 0*/, 2810624 /*Map: 0 (Eastern Kingdoms) - Phase: 26599*/, 2810626 /*Map: 0 (Eastern Kingdoms) - Phase: 26599*/, 2811338 /*Map: 0 (Eastern Kingdoms) - Phase: 26588*/, 2810825 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2811852 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2811853 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2811854 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2811855 /*Map: 2927 (Arathi Highlands RPE) - Phase: 0*/, 2810823 /*Map: 0 (Eastern Kingdoms) - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2675971, 2552, 25036, 0, 0, 64978), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 25036
(2675972, 2552, 25035, 0, 0, 64978), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 25035
(2594570, 2552, 25033, 0, 0, 64978), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 25033
(2594440, 2552, 25025, 0, 0, 64978), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 25025
(2594242, 2552, 25024, 0, 0, 64978), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 25024
(2967842, 2552, 27399, 0, 0, 64978), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 27399
(2594241, 2552, 25024, 0, 0, 64978), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 25024
(2779505, 2736, 0, 0, 0, 64978), -- Map: 2736 (Razorwind Shores) - Phase: 0
(2914024, 2735, 27429, 0, 0, 64978), -- Map: 2735 (Founder's Point) - Phase: 27429
(3094819, 2735, 0, 0, 0, 64978), -- Map: 2735 (Founder's Point) - Phase: 0
(3094857, 2736, 0, 0, 0, 64978), -- Map: 2736 (Razorwind Shores) - Phase: 0
(3097527, 2735, 0, 0, 0, 64978), -- Map: 2735 (Founder's Point) - Phase: 0
(3098462, 2736, 0, 0, 0, 64978), -- Map: 2736 (Razorwind Shores) - Phase: 0
(2914025, 2735, 0, 0, 0, 64978), -- Map: 2735 (Founder's Point) - Phase: 0
(2913539, 2736, 0, 0, 0, 64978), -- Map: 2736 (Razorwind Shores) - Phase: 0
(3097851, 2735, 0, 0, 0, 64978), -- Map: 2735 (Founder's Point) - Phase: 0
(3097850, 2735, 0, 0, 0, 64978), -- Map: 2735 (Founder's Point) - Phase: 0
(3098136, 2736, 0, 0, 0, 64978), -- Map: 2736 (Razorwind Shores) - Phase: 0
(3098138, 2736, 0, 0, 0, 64978), -- Map: 2736 (Razorwind Shores) - Phase: 0
(3098145, 2735, 0, 0, 0, 64978), -- Map: 2735 (Founder's Point) - Phase: 0
(3098144, 2736, 0, 0, 0, 64978), -- Map: 2736 (Razorwind Shores) - Phase: 0
(3097893, 2735, 0, 0, 0, 64978), -- Map: 2735 (Founder's Point) - Phase: 0
(3097897, 2735, 0, 0, 0, 64978), -- Map: 2735 (Founder's Point) - Phase: 0
(3098135, 2736, 0, 0, 0, 64978), -- Map: 2736 (Razorwind Shores) - Phase: 0
(3097903, 2736, 0, 0, 0, 64978), -- Map: 2736 (Razorwind Shores) - Phase: 0
(2811190, 0, 26610, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 26610
(2811189, 0, 26609, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 26609
(2810658, 0, 26608, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 26608
(2811137, 0, 0, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 0
(2810628, 0, 26604, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 26604
(2810629, 0, 26615, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 26615
(2810659, 0, 26607, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 26607
(2810905, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2810902, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2810865, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2810903, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2810906, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2810872, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2810863, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2810864, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2820253, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2923286, 0, 27245, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 27245
(2922038, 0, 27239, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 27239
(2924218, 0, 0, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 0
(2810624, 0, 26599, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 26599
(2810626, 0, 26599, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 26599
(2811338, 0, 26588, 0, 0, 64978), -- Map: 0 (Eastern Kingdoms) - Phase: 26588
(2810825, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2811852, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2811853, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2811854, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2811855, 2927, 0, 0, 0, 64978), -- Map: 2927 (Arathi Highlands RPE) - Phase: 0
(2810823, 0, 0, 0, 0, 64978); -- Map: 0 (Eastern Kingdoms) - Phase: 0

UPDATE `spawn_tracking_template` SET `VerifiedBuild`=64978 WHERE `SpawnTrackingId` IN (2194169, 2165473, 2165492, 2675100, 2675101, 2674550, 2674549, 2721780, 2737295, 2540136, 2169797, 2243006, 2240036, 2240785, 2496880, 2512633, 2549586, 2834475, 2840256, 2840250, 2347280, 2771526, 2779024, 2779041, 2678920, 2513682, 2265375, 2370969, 2361526, 2370952, 2370939, 2412477, 2415060, 2415057, 2415055, 2341010, 2378883, 2351713, 2349078, 1328068, 144608, 1649726, 1409970, 1431565, 2454147, 2423828, 2396981, 2442965, 2598992, 2577108, 2669754);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=64978 WHERE `SpawnTrackingId` IN (2454147, 2423828, 2396981, 2442965, 2552578); -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=64978 WHERE `SpawnTrackingId`=1457285; -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=64978 WHERE `SpawnTrackingId`=1456603; -- Map: 0 (Eastern Kingdoms) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=64978 WHERE `SpawnTrackingId`=2165473; -- Map: 0 (Eastern Kingdoms) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=64978 WHERE `SpawnTrackingId` IN (2210264, 2213239, 2214093, 2221436, 2221984, 2223246, 2208566, 2209633, 2204347, 2206096, 2206462, 2206905, 2258584, 2218400, 2229997, 2236221, 2236937, 2241242, 2241540, 2198154, 2201406, 2201759, 2202041, 2202841, 2203493, 2200183, 2201555); -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=64978 WHERE `SpawnTrackingId`=1846462; -- Map: 2222 (The Shadowlands) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=24825, `VerifiedBuild`=64978 WHERE `SpawnTrackingId`=2839851; -- Map: 2552 (Khaz Algar (Surface)) - Phase: 24825

DELETE FROM `spawn_tracking_quest_objective` WHERE (`QuestObjectiveId`=455357 AND `SpawnTrackingId` IN (2594242,2594440)) OR (`QuestObjectiveId`=468486 AND `SpawnTrackingId` IN (3094819,3094857)) OR (`QuestObjectiveId`=468485 AND `SpawnTrackingId` IN (3094819,3094857)) OR (`QuestObjectiveId`=468491 AND `SpawnTrackingId` IN (3097527,3098462)) OR (`QuestObjectiveId`=468126 AND `SpawnTrackingId` IN (3097527,3098462)) OR (`QuestObjectiveId`=468123 AND `SpawnTrackingId` IN (2914025,2913539)) OR (`QuestObjectiveId`=468125 AND `SpawnTrackingId` IN (3097851,3097850,3098136,3098138)) OR (`QuestObjectiveId`=468124 AND `SpawnTrackingId` IN (3098145,3098144)) OR (`QuestObjectiveId`=468122 AND `SpawnTrackingId` IN (3097893,3097897,3098135,3097903)) OR (`QuestObjectiveId`=463609 AND `SpawnTrackingId` IN (2914024,2779505)) OR (`QuestObjectiveId`=464281 AND `SpawnTrackingId`=2779505) OR (`QuestObjectiveId`=464280 AND `SpawnTrackingId`=2914024) OR (`QuestObjectiveId`=463615 AND `SpawnTrackingId` IN (2914024,2779505)) OR (`QuestObjectiveId`=461829 AND `SpawnTrackingId` IN (2811189,2811190)) OR (`QuestObjectiveId`=461768 AND `SpawnTrackingId`=2811137);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2594242, 455357, 64978), -- 2594242
(2594440, 455357, 64978), -- 2594440
(3094819, 468486, 64978), -- 3094819
(3094857, 468486, 64978), -- 3094857
(3094819, 468485, 64978), -- 3094819
(3094857, 468485, 64978), -- 3094857
(3097527, 468491, 64978), -- 3097527
(3098462, 468491, 64978), -- 3098462
(3097527, 468126, 64978), -- 3097527
(3098462, 468126, 64978), -- 3098462
(2914025, 468123, 64978), -- 2914025
(2913539, 468123, 64978), -- 2913539
(3097851, 468125, 64978), -- 3097851
(3097850, 468125, 64978), -- 3097850
(3098136, 468125, 64978), -- 3098136
(3098138, 468125, 64978), -- 3098138
(3098145, 468124, 64978), -- 3098145
(3098144, 468124, 64978), -- 3098144
(3097893, 468122, 64978), -- 3097893
(3097897, 468122, 64978), -- 3097897
(3098135, 468122, 64978), -- 3098135
(3097903, 468122, 64978), -- 3097903
(2914024, 463609, 64978), -- 2914024
(2779505, 463609, 64978), -- 2779505
(2779505, 464281, 64978), -- 2779505
(2914024, 464280, 64978), -- 2914024
(2914024, 463615, 64978), -- 2914024
(2779505, 463615, 64978), -- 2779505
(2811189, 461829, 64978), -- 2811189
(2811190, 461829, 64978), -- 2811190
(2811137, 461768, 64978); -- 2811137

UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=64978 WHERE (`QuestObjectiveId`=461360 AND `SpawnTrackingId` IN (2675100,2675101,2674550,2674549)) OR (`QuestObjectiveId`=462182 AND `SpawnTrackingId` IN (2840256,2840250));

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (131871, 131869, 131868, 129733, 137872, 131872, 131866, 131867, 123908, 123910, 123907, 123906, 123904, 123905, 123915, 123909, 130420, 131998, 116386, 137558, 114737, 140019, 137568, 129526, 129537, 140280, 129278, 129358, 139722, 139750, 129331, 126842, 140785, 140789, 140787, 139953, 139959, 139957, 138691, 140788, 140791, 138699, 138698, 138743, 138745, 121251, 139782, 139913, 139914, 129326, 139621, 126827, 129305, 141096, 114969, 141097, 125874, 141149, 125873, 141150, 129539, 129314, 126816, 129301, 129270, 129548, 138692, 129271, 140281, 129512, 129323, 129518, 129530, 126815, 129534, 129520, 129531, 129276, 129327, 129274, 126839, 126812, 139748, 139745, 139747, 139873, 139871, 139874, 141143, 129547, 126810, 141137, 141110, 129517, 141104, 141144, 126807, 141102, 126805, 139617, 126836, 129264, 141136, 141111, 126822, 126830, 139900, 139739, 139736, 139740, 139733, 139735, 139744, 141142, 126820, 139380, 129523, 139381, 141140, 129521, 129525, 139619, 129554, 129515, 129541, 129535, 129543, 129513, 129272, 126831, 126837, 129559, 129303, 139112, 138689, 138688, 138690, 138687, 138684, 129330, 129529, 129514, 129538, 136650, 129757, 138693, 111027, 138653, 138648, 138694, 138695, 131963, 138696, 139746, 138650, 138681, 136070, 129556, 126825, 129273, 129551, 138683, 139734, 129315, 140296, 129309, 139724, 126813, 141141, 129265, 140297, 139902, 141105, 139738, 139742, 139743, 139565, 139093, 138679, 141138, 141107, 138680, 141108, 141106, 138678, 141139, 141109, 141112, 139901, 80963, 123317, 123318, 123253, 123316, 123258, 123319, 123257, 122357, 129376, 129377, 129378, 129360, 103264, 129359, 103178, 122212, 130529, 130509, 103679, 103680, 103681, 103266, 103265, 129823, 130521, 129822, 130527, 130516, 130515, 122211, 130512, 130511, 130508, 122359, 122360, 121451, 129434);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(131871, 0.305999994277954101, 1.5, 0, 64978),
(131869, 0.382999986410140991, 1.5, 0, 64978),
(131868, 0.305999994277954101, 1.5, 0, 64978),
(129733, 0.768872499465942382, 0.699999988079071044, 0, 64978),
(137872, 1.347197294235229492, 3.5, 0, 64978),
(131872, 0.208000004291534423, 1.5, 0, 64978),
(131866, 0.305999994277954101, 1.5, 0, 64978),
(131867, 0.722000002861022949, 3, 0, 64978),
(123908, 0.382999986410140991, 1.5, 0, 64978),
(123910, 0.305999994277954101, 1.5, 0, 64978),
(123907, 1, 1.5, 0, 64978),
(123906, 0.347000002861022949, 1.5, 0, 64978),
(123904, 0.305999994277954101, 1.5, 0, 64978),
(123905, 0.305999994277954101, 1.5, 0, 64978),
(123915, 0.305999994277954101, 1.5, 0, 64978),
(123909, 0.236000001430511474, 1.5, 0, 64978),
(130420, 0.451939970254898071, 1.769999980926513671, 0, 64978),
(131998, 1.176657438278198242, 0, 0, 64978),
(116386, 0.49456837773323059, 1.5, 0, 64978),
(137558, 0.372000008821487426, 1.5, 0, 64978),
(114737, 1.581808328628540039, 1.5, 0, 64978),
(140019, 0.305999994277954101, 1.5, 0, 64978),
(137568, 0.236000001430511474, 1.5, 0, 64978),
(129526, 0.305999994277954101, 1.5, 0, 64978),
(129537, 0.347000002861022949, 1.5, 0, 64978),
(140280, 0.347222000360488891, 1.5, 0, 64978),
(129278, 0.347000002861022949, 1.5, 0, 64978),
(129358, 0.347222000360488891, 1.5, 0, 64978),
(139722, 0.208000004291534423, 1.5, 0, 64978),
(139750, 1.116250038146972656, 1.875, 0, 64978),
(129331, 0.698715150356292724, 1.5, 0, 64978),
(126842, 0.347222000360488891, 1.5, 0, 64978),
(140785, 0.958336830139160156, 1.25, 0, 64978),
(140789, 0.958336830139160156, 1.25, 0, 64978),
(140787, 0.958336830139160156, 1.25, 0, 64978),
(139953, 1.140607118606567382, 1.5, 0, 64978),
(139959, 1.140607118606567382, 1.5, 0, 64978),
(139957, 1.140607118606567382, 1.5, 0, 64978),
(138691, 1, 1.5, 0, 64978),
(140788, 0.958336830139160156, 1.25, 0, 64978),
(140791, 0.958336830139160156, 1.25, 0, 64978),
(138699, 0.347222000360488891, 1.5, 0, 64978),
(138698, 0.698000013828277587, 3, 0, 64978),
(138743, 0.305999994277954101, 1.5, 0, 64978),
(138745, 0.305999994277954101, 1.5, 0, 64978),
(121251, 0.279741913080215454, 1, 0, 64978),
(139782, 0.698715150356292724, 1.5, 0, 64978),
(139913, 0.305999994277954101, 1.5, 0, 64978),
(139914, 0.305999994277954101, 1.5, 0, 64978),
(129326, 1, 1.5, 0, 64978),
(139621, 0.388999998569488525, 1.5, 0, 64978),
(126827, 1, 1.5, 0, 64978),
(129305, 0.347222000360488891, 1.5, 0, 64978),
(141096, 2.085362434387207031, 0, 0, 64978),
(114969, 0.517951607704162597, 0.300000011920928955, 0, 64978),
(141097, 2.085362434387207031, 0, 0, 64978),
(125874, 0.440759658813476562, 0, 0, 64978),
(141149, 0.529112696647644042, 0.699999988079071044, 0, 64978),
(125873, 0.440759658813476562, 0, 0, 64978),
(141150, 0.529112696647644042, 0.699999988079071044, 0, 64978),
(129539, 0.347222000360488891, 1.5, 0, 64978),
(129314, 0.347222000360488891, 1.5, 0, 64978),
(126816, 0.347000002861022949, 1.5, 0, 64978),
(129301, 1, 1.5, 0, 64978),
(129270, 0.208000004291534423, 1.5, 0, 64978),
(129548, 1, 1.5, 0, 64978),
(138692, 0.305999994277954101, 1.5, 0, 64978),
(129271, 0.347000002861022949, 1.5, 0, 64978),
(140281, 0.347222000360488891, 1.5, 0, 64978),
(129512, 0.305999994277954101, 1.5, 0, 64978),
(129323, 1, 1.5, 0, 64978),
(129518, 0.305999994277954101, 1.5, 0, 64978),
(129530, 0.305999994277954101, 1.5, 0, 64978),
(126815, 0.347000002861022949, 1.5, 0, 64978),
(129534, 0.347000002861022949, 1.5, 0, 64978),
(129520, 0.305999994277954101, 1.5, 0, 64978),
(129531, 0.347000002861022949, 1.5, 0, 64978),
(129276, 0.347000002861022949, 1.5, 0, 64978),
(129327, 0.347000002861022949, 1.5, 0, 64978),
(129274, 0.347000002861022949, 1.5, 0, 64978),
(126839, 0.305999994277954101, 1.5, 0, 64978),
(126812, 0.347222000360488891, 1.5, 0, 64978),
(139748, 1.116250038146972656, 1.875, 0, 64978),
(139745, 1.116250038146972656, 1.875, 0, 64978),
(139747, 1.116250038146972656, 1.875, 0, 64978),
(139873, 0.153927803039550781, 1, 0, 64978),
(139871, 0.153927803039550781, 1, 0, 64978),
(139874, 0.153927803039550781, 1, 0, 64978),
(141143, 1.156227827072143554, 1, 0, 64978),
(129547, 1, 1.5, 0, 64978),
(126810, 0.698715150356292724, 1.5, 0, 64978),
(141137, 0.415864378213882446, 0.5, 0, 64978),
(141110, 0.34672054648399353, 0.800000011920928955, 0, 64978),
(129517, 0.208000004291534423, 1.5, 0, 64978),
(141104, 0.300000011920928955, 0.375, 0, 64978),
(141144, 1.156227827072143554, 1, 0, 64978),
(126807, 0.305999994277954101, 1.5, 0, 64978),
(141102, 0.25, 0.3125, 0, 64978),
(126805, 0.347222000360488891, 1.5, 0, 64978),
(139617, 0.305999994277954101, 1.5, 0, 64978),
(126836, 0.347000002861022949, 1.5, 0, 64978),
(129264, 0.305999994277954101, 1.5, 0, 64978),
(141136, 0.415864378213882446, 0.5, 0, 64978),
(141111, 0.34672054648399353, 0.800000011920928955, 0, 64978),
(126822, 0.305999994277954101, 1.5, 0, 64978),
(126830, 0.305999994277954101, 1.5, 0, 64978),
(139900, 0.310000002384185791, 1, 0, 64978),
(139739, 1.116250038146972656, 1.875, 0, 64978),
(139736, 1.116250038146972656, 1.875, 0, 64978),
(139740, 1.116250038146972656, 1.875, 0, 64978),
(139733, 1.116250038146972656, 1.875, 0, 64978),
(139735, 1.116250038146972656, 1.875, 0, 64978),
(139744, 1.116250038146972656, 1.875, 0, 64978),
(141142, 1.156227827072143554, 1, 0, 64978),
(126820, 0.388999998569488525, 1.5, 0, 64978),
(139380, 0.305999994277954101, 1.5, 0, 64978),
(129523, 0.208000004291534423, 1.5, 0, 64978),
(139381, 0.305999994277954101, 1.5, 0, 64978),
(141140, 0.310000002384185791, 0, 0, 64978),
(129521, 0.208000004291534423, 1.5, 0, 64978),
(129525, 0.388999998569488525, 1.5, 0, 64978),
(139619, 0.347000002861022949, 1.5, 0, 64978),
(129554, 0.347222000360488891, 1.5, 0, 64978),
(129515, 0.208000004291534423, 1.5, 0, 64978),
(129541, 0.698715150356292724, 1.5, 0, 64978),
(129535, 0.347000002861022949, 1.5, 0, 64978),
(129543, 0.347222000360488891, 1.5, 0, 64978),
(129513, 0.305999994277954101, 1.5, 0, 64978),
(129272, 0.347000002861022949, 1.5, 0, 64978),
(126831, 0.305999994277954101, 1.5, 0, 64978),
(126837, 0.208000004291534423, 1.5, 0, 64978),
(129559, 0.208000004291534423, 1.5, 0, 64978),
(129303, 0.347222000360488891, 1.5, 0, 64978),
(139112, 0.347000002861022949, 1.5, 0, 64978),
(138689, 0.347000002861022949, 1.5, 0, 64978),
(138688, 0.347222000360488891, 1.5, 0, 64978),
(138690, 0.305999994277954101, 1.5, 0, 64978),
(138687, 1, 1.5, 0, 64978),
(138684, 0.347222000360488891, 1.5, 0, 64978),
(129330, 0.347000002861022949, 1.5, 0, 64978),
(129529, 0.388999998569488525, 1.5, 0, 64978),
(129514, 0.208000004291534423, 1.5, 0, 64978),
(129538, 0.698715150356292724, 1.5, 0, 64978),
(136650, 0.40845489501953125, 0, 0, 64978),
(129757, 0.208000004291534423, 1.5, 0, 64978),
(138693, 0.305999994277954101, 1.5, 0, 64978),
(111027, 0.218090251088142395, 0, 0, 64978),
(138653, 0.347222000360488891, 1.5, 0, 64978),
(138648, 0.305999994277954101, 1.5, 0, 64978),
(138694, 0.305999994277954101, 1.5, 0, 64978),
(138695, 0.305999994277954101, 1.5, 0, 64978),
(131963, 0.305999994277954101, 1.5, 0, 64978),
(138696, 0.305999994277954101, 1.5, 0, 64978),
(139746, 1.116250038146972656, 1.875, 0, 64978),
(138650, 2.777777910232543945, 0, 0, 64978),
(138681, 1.1655120849609375, 0, 0, 64978),
(136070, 0.923013925552368164, 0, 0, 64978),
(129556, 0.347222000360488891, 1.5, 0, 64978),
(126825, 0.347000002861022949, 1.5, 0, 64978),
(129273, 0.347000002861022949, 1.5, 0, 64978),
(129551, 0.305999994277954101, 1.5, 0, 64978),
(138683, 0.901570618152618408, 0, 0, 64978),
(139734, 1.116250038146972656, 1.875, 0, 64978),
(129315, 0.347222000360488891, 1.5, 0, 64978),
(140296, 0.447777867317199707, 0.5, 0, 64978),
(129309, 0.347222000360488891, 1.5, 0, 64978),
(139724, 0.208000004291534423, 1.5, 0, 64978),
(126813, 0.347222000360488891, 1.5, 0, 64978),
(141141, 0.100000001490116119, 0.200000002980232238, 0, 64978),
(129265, 0.208000004291534423, 1.5, 0, 64978),
(140297, 0.447777867317199707, 0.5, 0, 64978),
(139902, 0.310000002384185791, 1, 0, 64978),
(141105, 0.5, 1, 0, 64978),
(139738, 1.116250038146972656, 1.875, 0, 64978),
(139742, 1.116250038146972656, 1.875, 0, 64978),
(139743, 1.116250038146972656, 1.875, 0, 64978),
(139565, 0.698715150356292724, 1.5, 0, 64978),
(139093, 4.089955329895019531, 0, 0, 64978),
(138679, 2.52813577651977539, 0, 0, 64978),
(141138, 0.831728756427764892, 1, 0, 64978),
(141107, 0.548862576484680175, 1, 0, 64978),
(138680, 2.526702404022216796, 0, 0, 64978),
(141108, 0.548862576484680175, 1, 0, 64978),
(141106, 0.548862576484680175, 1, 0, 64978),
(138678, 2.794721603393554687, 0, 0, 64978),
(141139, 0.463837504386901855, 1.5, 0, 64978),
(141109, 0.548862576484680175, 1, 0, 64978),
(141112, 0.34672054648399353, 0.800000011920928955, 0, 64978),
(139901, 0.310000002384185791, 1, 0, 64978),
(80963, 1.026380538940429687, 0, 0, 64978),
(123317, 0.372000008821487426, 1.5, 0, 64978),
(123318, 0.236000001430511474, 1.5, 0, 64978),
(123253, 0.372000008821487426, 1.5, 0, 64978),
(123316, 0.372000008821487426, 1.5, 0, 64978),
(123258, 0.236000001430511474, 1.5, 0, 64978),
(123319, 0.236000001430511474, 1.5, 0, 64978),
(123257, 0.236000001430511474, 1.5, 0, 64978),
(122357, 0.297600001096725463, 1.20000004768371582, 0, 64978),
(129376, 0.85789954662322998, 1.5, 0, 64978),
(129377, 0.85789954662322998, 1.5, 0, 64978),
(129378, 0.85789954662322998, 1.5, 0, 64978),
(129360, 0.85789954662322998, 1.5, 0, 64978),
(103264, 0.912917256355285644, 1.875, 0, 64978),
(129359, 0.85789954662322998, 1.5, 0, 64978),
(103178, 0.912917256355285644, 1.875, 0, 64978),
(122212, 0.165866583585739135, 1, 0, 64978),
(130529, 0.208000004291534423, 1.5, 0, 64978),
(130509, 0.305999994277954101, 1.5, 0, 64978),
(103679, 0.912917256355285644, 1.875, 0, 64978),
(103680, 0.912917256355285644, 1.875, 0, 64978),
(103681, 0.912917256355285644, 1.875, 0, 64978),
(103266, 0.912917256355285644, 1.875, 0, 64978),
(103265, 0.912917256355285644, 1.875, 0, 64978),
(129823, 0.305999994277954101, 1.5, 0, 64978),
(130521, 0.208000004291534423, 1.5, 0, 64978),
(129822, 0.208000004291534423, 1.5, 0, 64978),
(130527, 0.208000004291534423, 1.5, 0, 64978),
(130516, 0.208000004291534423, 1.5, 0, 64978),
(130515, 0.305999994277954101, 1.5, 0, 64978),
(122211, 0.165866583585739135, 1, 0, 64978),
(130512, 0.208000004291534423, 1.5, 0, 64978),
(130511, 0.208000004291534423, 1.5, 0, 64978),
(130508, 0.305999994277954101, 1.5, 0, 64978),
(122359, 0.297600001096725463, 1.20000004768371582, 0, 64978),
(122360, 0.297600001096725463, 1.20000004768371582, 0, 64978),
(121451, 2.872158527374267578, 0, 0, 64978),
(129434, 0.371129333972930908, 5, 0, 64978);

UPDATE `creature_model_info` SET `VerifiedBuild`=64978 WHERE `DisplayID` IN (61948, 104530, 114816, 104531, 114820, 118318, 106699, 106700, 28222, 75345, 119382, 75344, 75347, 120662, 75343, 103501, 75346, 117484, 119091, 119976, 119065, 119046, 118377, 119120, 122492, 122125, 117287, 120016, 114814, 119090, 120661, 117696, 117336, 118376, 5555, 120638, 117697, 120629, 38804, 117415, 118268, 88424, 117695, 117690, 15698, 117689, 28282, 28111, 120630, 118267, 121975, 121148, 120609, 117424, 118462, 120981, 85555, 129142, 117431, 117199, 128002, 119305, 115037, 120626, 117200, 117198, 117238, 118597, 115038, 118181, 117660, 117346, 120914, 121065, 27959, 77687, 77690, 118450, 131516, 126177, 117414, 117657, 117806, 117357, 36904, 120618, 121155, 112806, 120628, 119051, 125913, 22003, 27019, 121052, 117356, 119101, 117418, 117411, 117410, 43328, 117671, 120606, 121153, 117354, 36905, 65251, 112141, 117651, 121951, 117666, 19283, 108811, 108778, 121053, 117341, 121157, 120739, 120614, 120617, 117676, 47677, 119217, 34556, 118463, 88792, 52318, 119103, 129695, 117409, 114796, 43965, 120607, 117339, 120920, 117412, 110227, 118319, 118459, 121976, 117430, 122301, 124793, 125318, 125805, 118429, 126362, 130297, 33479, 116218, 130321, 110229, 114500, 120637, 105546, 111138, 119050, 106349, 106697, 121156, 112165, 119216, 120612, 120925, 117429, 110362, 117649, 120615, 117667, 117427, 117650, 117652, 121154, 81467, 107486, 23959, 5558, 103954, 79720, 82908, 103956, 103955, 103931, 103929, 115144, 103904, 5554, 114623, 19999, 19985, 42343, 111025, 121106, 107219, 120525, 85817, 104673, 104669, 107226, 107224, 80966, 36743, 104516, 81029, 40090, 80951, 119975, 121107, 121104, 121103, 119977, 121108, 104042, 120522, 121105, 120526, 111029, 120527, 64016, 107285, 42334, 80962, 120528, 103843, 104044, 104041, 104040, 82019, 75443, 91847, 103844, 120523, 103841, 87594, 40089, 3952, 3951, 4046, 4045, 3953, 8677, 3950, 5367, 3957, 8634, 4048, 2672, 4008, 1606, 9250, 2657, 347, 2176, 2172, 117208, 115258, 117224, 103831, 53781, 114829, 28118, 28120, 45042, 28830, 119060, 21735, 115751, 12236, 96887, 115041, 36620, 119061, 103177, 55621, 52461, 88092, 328, 52463, 88091, 55547, 118875, 115042, 118871, 388, 31330, 116853, 4626, 25733, 123888, 123825, 123824, 123812, 123810, 123924, 123878, 123821, 123880, 123809, 124473, 123855, 19893, 129936, 126845, 92168, 124292, 78509, 123925, 125237, 90821, 116308, 123877, 123835, 901, 119058, 6297, 119059, 120520, 124536, 90813, 72178, 84084, 83889, 84065, 119057, 119062, 120521, 10824, 35201, 9587, 98508, 100248, 123876, 123851, 6302, 100571, 122471, 94692, 1072, 100574, 62385, 100247, 70623, 121664, 11316, 125923, 124337, 127479, 127478, 127480, 125924, 114325, 116852, 75012, 124589, 114510, 83183, 75006, 123822, 123879, 123808, 124607, 123854, 123846, 123860, 99952, 123839, 123838, 123867, 123841, 123859, 123834, 124081, 123858, 123861, 128502, 136040, 101299, 128506, 42372, 124300, 123229, 123228, 27823, 129792, 38615, 116544, 109964, 119365, 129114, 66845, 121468, 121467, 40658, 100362, 26079, 129115, 131544, 41853, 40657, 100060, 97761, 131545, 131546, 99883, 14511, 128503, 92621, 129937, 128505, 124183, 28647, 124254, 123521, 124255, 89308, 91526, 42373, 125630, 94544, 59799, 65631, 119675, 125631, 961, 34885, 121139, 121140, 128246, 93594, 130488, 128247, 124338, 122799, 130285, 39353, 15880, 124537, 130284, 122774, 130377, 83764, 83766, 115495, 53291, 130304, 106962, 5565, 1104, 100578, 23275, 136038, 1105, 128498, 37310, 100573, 128500, 131875, 125880, 101300, 83789, 124339, 136039, 100575, 122176, 122773, 125276, 125287, 1141, 118399, 118975, 115039, 116685, 116686, 118397, 83613, 127921, 117451, 1418, 80458, 117448, 117524, 114624, 127920, 127923, 117449, 124306, 117450, 118401, 114484, 105131, 116348, 114706, 116507, 116684, 116345, 119787, 23257, 1103, 118175, 118389, 99951, 83604, 116642, 54643, 115530, 70903, 116637, 104518, 57495, 53782, 114770, 104517, 104515, 115426, 121772, 118976, 129163, 32789, 114287, 104522, 108810, 116683, 104633, 114308, 114306, 107520, 115505, 129741, 104519, 124305, 45880, 124095, 113940, 114833, 83593, 83597, 104520, 115157, 91887, 130469, 124092, 83621, 83605, 114778, 116384, 129832, 16925, 115528, 83598, 104523, 104521, 84036, 112490, 114622, 117725, 112458, 37311, 115226, 100675, 117494, 103812, 115263, 33745, 78345, 18931, 102032, 257, 87011, 63521, 63522, 344, 33746, 1758, 105170, 100074, 5075, 31174, 134, 99949, 99947, 16854, 34004, 99950, 91079, 33748, 17188, 91081, 91080, 338, 2961, 33747, 262, 15321, 21072, 1573, 21342, 107146, 104045, 107366, 115238, 117223, 119703, 114304, 114653, 117497, 117487, 107365, 114563, 114562, 115264, 120395, 103499, 118006, 117491, 114930, 117496, 117485, 114561, 114532, 115190, 119067, 119497, 70178, 119170, 114659, 114928, 90583, 115242, 104043, 106698);
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=64978 WHERE `DisplayID` IN (47158, 47159);
UPDATE `creature_model_info` SET `BoundingRadius`=0.195172175765037536, `CombatReach`=0.25, `VerifiedBuild`=64978 WHERE `DisplayID` IN (115113, 115110);
UPDATE `creature_model_info` SET `BoundingRadius`=0.095833681523799896, `CombatReach`=0.125, `VerifiedBuild`=64978 WHERE `DisplayID`=5559;
UPDATE `creature_model_info` SET `BoundingRadius`=0.363841086626052856, `VerifiedBuild`=64978 WHERE `DisplayID`=114621;
UPDATE `creature_model_info` SET `BoundingRadius`=0.218090251088142395, `VerifiedBuild`=64978 WHERE `DisplayID`=111028;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=64978 WHERE `DisplayID`=87703;
UPDATE `creature_model_info` SET `BoundingRadius`=2.344965934753417968, `CombatReach`=0.880000054836273193, `VerifiedBuild`=64978 WHERE `DisplayID`=123927;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=6, `VerifiedBuild`=64978 WHERE `DisplayID`=71117;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=12, `VerifiedBuild`=64978 WHERE `DisplayID`=51677;
UPDATE `creature_model_info` SET `BoundingRadius`=1.770069241523742675, `CombatReach`=1.625, `VerifiedBuild`=64978 WHERE `DisplayID`=114511;
UPDATE `creature_model_info` SET `BoundingRadius`=0.186000004410743713, `CombatReach`=0.60000002384185791, `VerifiedBuild`=64978 WHERE `DisplayID`=22791;
UPDATE `creature_model_info` SET `BoundingRadius`=0.549581527709960937, `VerifiedBuild`=64978 WHERE `DisplayID` IN (124203, 124202, 124205);
UPDATE `creature_model_info` SET `BoundingRadius`=0.85839998722076416, `CombatReach`=1.20000004768371582, `VerifiedBuild`=64978 WHERE `DisplayID`=180;
UPDATE `creature_model_info` SET `BoundingRadius`=0.85789954662322998, `CombatReach`=1.5, `VerifiedBuild`=64978 WHERE `DisplayID` IN (91775, 91851, 91778, 91776);
UPDATE `creature_model_info` SET `BoundingRadius`=2.623784065246582031, `CombatReach`=4, `VerifiedBuild`=64978 WHERE `DisplayID`=75597;
UPDATE `creature_model_info` SET `BoundingRadius`=0.420002311468124389, `VerifiedBuild`=64978 WHERE `DisplayID`=114831;

UPDATE `quest_template` SET `VerifiedBuild`=64978 WHERE `ID` IN (66577, 65436, 82672, 82994, 46736, 46735, 46277, 77721, 77719, 77718, 65779, 56775, 46727, 26286, 26271, 43806, 40519, 42978, 44700, 76113, 91454, 90972, 86196, 84719, 85238, 84490, 92405, 84960, 84376, 84915, 84740, 84215, 83160, 83153, 83152, 83092, 79686, 82441, 79119, 83325, 79355, 79174, 81928, 81890, 83082, 83081, 83247, 83283, 79683, 80392, 79149, 79148, 82628, 80677, 80673, 79159, 80207, 79309, 80312, 78469, 82792, 82477, 92331, 78901, 78898, 78897, 79574, 80176, 80175, 79711, 79710, 79300, 79304, 78996, 78686, 81966, 78571, 78570, 78289, 83360, 84972, 90778, 90719, 89332, 89331, 88803, 86461, 83492, 76112, 71229, 71227, 71210, 71151, 71150, 71149, 71148, 71146, 70938, 70702, 91624, 91173, 83759, 83758, 79553, 78463, 75511, 57267, 57263, 69960, 69953, 69955, 47507, 48832, 69969, 76991, 69954, 77867, 69961, 69959, 69927, 83105, 87417, 82679, 86731, 91442, 82706, 91968, 93149, 92572, 90731, 84095, 84094, 84093, 84092, 84091, 84090, 81508, 79351, 77737, 77736, 77732, 77728, 91193, 91093, 91089, 90779, 87410, 85244, 82156, 82157, 80670, 78447, 75636, 64599, 57566, 57564, 53435, 50604, 50598, 50562, 49076, 48641, 48639, 42422, 29433, 79321, 77251, 70369, 74378, 73147, 73083, 69929, 70149, 70661, 70654, 70662, 66070, 72029, 71205, 71206, 71166, 71156, 71145, 70712, 70659, 70631, 70442, 70068, 70428, 70415, 70057, 70150, 69924, 66588, 43942, 86363, 82747, 82296, 84370, 85648, 90705, 84956);

UPDATE `quest_visual_effect` SET `VerifiedBuild`=64978 WHERE (`Index`=0 AND `ID` IN (427235,451775,391353,337818,436310,462010,454466,452660,453600,456341,456340,453373,453233,453232,453231,452124,450659,447259,449933,449934,449935,445751,446294,449249,451088,450777,448571,448570,448569,448185,446126,448789,446003,447867,448022,447406,448096,445055,447473,450308,450296,446087,446086,446085,446084,445342,445341,453632,461364,461360,459115,436308,445662,392992,392938,455357,448613,445956,462568,462539,462552,451350,451349,447716,448198,447000,447491,448065,448064,448009,451309,450384,444579,444578,444577,449795,449841,446910,438036,438035,436772,448478,405128,405055,405097,434678,456668,448556,293409,432500,432499,432498,430861,443668,434674,434673,293134,293116,456703,456701,293216,445155,457123,437128,435722,443392,443435,448481,436395,455755,455798,455736,455735,430837,443589,443588,435934,448320,434908,435509,435570,435569,435510,435544,435543,435508,435542,435541,443261,443272,443271,443270,434507,432283,443579,443578,456629,457493,457490,434695,455761,290986,434858,434857,445531,456655,445629,445621,443394,443453,429505,434680,434850,459660,461563,459659,290838,434474,434473,445673,445672,445671,445670,445669,445665,445359,445354,293303,293302,449804,468491,468126,468123,468125,468124,468122,449651,449650,447040,450597,450039,450336,449752,449751,449748,449420,449419,449393,449217,449216,449215,436502,450554,450553,449930,449931,449746,449612,449611,449613,433046,428719,431054,431053,431052,431348,431347,431346,430909,430922,430916,430806,430833,430832,431682,431598,431535,431464,430781,430678,430677,430676,430654,430179,429829,430648,429488,428716,428715,428709,427291,468710,258621,456685,456599,463610,463609,463615,461829,461768,461767,450969,462804,461378,461377,461565,450676,436761,436519,436518,436517,436510,436508,430513,429957,429956,430914,430926,430920,427035,423863,423862,423861,431688,431589,432307,431635,430801,430800,430518,430481,430480,429964,429458,456624)) OR (`Index`=1 AND `ID` IN (436310,453600,447259,445751,446294,449249,448571,448569,448022,448096,445342,445341,436308,445662,392938,447716,447000,438035,448478,293409,443668,293134,445155,437128,435722,443392,455755,430837,443588,443261,434507,443578,434695,455761,290986,434858,434857,445531,445621,443394,434680,459659,290838,434474,434473,445359,445354,468123,450039,449217,449216,450554,449931,449612,433046,428719,431054,431053,431348,431347,430909,430922,430806,430833,430781,430654,430179,428716,428709,468710,463610,463609,463615,461829,461767,429957,430914,430926,427035,423863,423862,429964,429458)) OR (`Index`=2 AND `ID` IN (447259,445751,446294,449249,448571,448022,448096,445342,445341,447716,438035,448478,293409,443668,293134,435722,443392,430837,443261,443578,434695,290986,434858,445531,443394,434680,290838,450039,449217,449612,433046,428719,431054,431348,430909,430806,430654,430179,468710,430914,423863,429964)) OR (`Index`=6 AND `ID` IN (445751,448478,293409,434695,428719)) OR (`Index`=5 AND `ID` IN (445751,448478,293409,443578,434695,290838,428719)) OR (`Index`=4 AND `ID` IN (445751,445341,438035,448478,293409,443392,443578,434695,443394,290838,428719)) OR (`Index`=3 AND `ID` IN (445751,446294,445341,438035,448478,293409,443392,443578,434695,290986,443394,290838,449217,433046,428719,431054,431348,430909,430806,430654,468710,430914,423863)) OR (`Index`=7 AND `ID` IN (448478,293409)) OR (`Index`=17 AND `ID`=293409) OR (`Index`=16 AND `ID`=293409) OR (`Index`=15 AND `ID`=293409) OR (`Index`=14 AND `ID`=293409) OR (`Index`=13 AND `ID`=293409) OR (`Index`=12 AND `ID`=293409) OR (`Index`=11 AND `ID`=293409) OR (`Index`=10 AND `ID`=293409) OR (`Index`=9 AND `ID`=293409) OR (`Index`=8 AND `ID`=293409);

UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=64978 WHERE (`Idx`=0 AND `QuestID` IN (80207,83492,70938,84996,78743,81661,78562,93647,87417,82706,82296,84956));

UPDATE `gameobject_questitem` SET `VerifiedBuild`=64978 WHERE (`Idx`=0 AND `GameObjectEntry` IN (344604,203800,466978,466983,469901,467435,411571,451830)) OR (`Idx`=4 AND `GameObjectEntry`=451830) OR (`Idx`=3 AND `GameObjectEntry`=451830) OR (`Idx`=2 AND `GameObjectEntry`=451830) OR (`Idx`=1 AND `GameObjectEntry`=451830);

SET NAMES 'latin1';
