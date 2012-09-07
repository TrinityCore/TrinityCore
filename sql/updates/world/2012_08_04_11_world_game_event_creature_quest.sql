--  Add all quests connected with Midsummer Fire Festival that are to be reseted on each next year to game_event_seasonal_questrelation, so players can complete them on and on... /as of different festivals/.
DELETE FROM `game_event_seasonal_questrelation` WHERE `questId` IN (11846,11845,11852,11839,11859,11841,11849,11861,11847,11836,11838,11856,11850,11848,11853,11857,11837,11844,11860,11584,11862,11842,11840,11851,11855,11835,11858,11863,11821,11854,11843,13500,13493,13494,13495,13496,13497,13498,13499,11805,11812,11815,11834,11833,11831,11817,11811,11806,11809,11826,11824,11826,11827,11819,11583,11828,11816,11810,11808,11804,11832,11813,11814,11820,11822,11823,11821,11830,11818,11825,11807,11829,13485,13487,13489,13488,13490,13486,13491,13492,11770,11769,11777,11803,11783,11773,11765,11771,11785,11800,11780,11802,11774,11772,11776,11781,11801,11768,11784,11580,11786,11766,11764,11775,11779,11799,11782,11787,11767,11778,13458,13441,13450,13451,13457,13455,13454,13453,11734,11741,11744,11763,11762,11760,11746,11740,11735,11738,11753,11755,11756,11748,11581,11757,11745,11739,11737,11732,11761,11742,11743,11749,11751,11752,11750,11759,11747,11754,11736,11758,13440,13443,13445,13444,13449,13446,13442,13447,13431,9324,11935,9326,9325,9332,9331,9330,11933,11972);
INSERT INTO `game_event_seasonal_questrelation` (`questId`, `eventEntry`) VALUES
(11846,1), -- Durotar // Honor the Flame (Horde) - Kalimdor
(11845,1), -- Desolace
(11852,1), -- Mulgore
(11839,1), -- Winterspring
(11859,1), -- Barrens
(11849,1), -- Feralas
(11841,1), -- Ashenvale
(11847,1), -- Dustwallow marsh
(11861,1), -- Thousand Needles
(11856,1), -- Stonetalon Mountains
(11836,1), -- Silithus
(11838,1), -- Tanaris
(11850,1), -- Ghostland // Honor the Flame (Horde) - Eeastern Kingdoms
(11848,1), -- Eversong woods
(11853,1), -- Hillsbrad Foothills
(11857,1), -- Swamp of sorrows
(11837,1), -- Cape of Stranglethorn
(11844,1), -- Burning Steppes
(11860,1), -- The Hinterlands
(11584,1), -- Silverpine Forest
(11862,1), -- Tirisfal Glades
(11842,1), -- Badlands
(11840,1), -- Arathi Highlands
(11851,1), -- Hellfire Peninsula // Honor the Flame (Horde) - Outland
(11855,1), -- Shadowmoon Valley
(11835,1), -- Netherstorm
(11858,1), -- Terokkar
(11863,1), -- Zangarmarsh
(11854,1), -- Nagrand
(11843,1), -- Blade''s Edge Mountains
(13500,1), -- Zul'Drak // Honor the Flame (Horde) - Northrend
(13493,1), -- Borean Tundra
(13494,1), -- Sholazar Basin
(13495,1), -- Dragonblight
(13499,1), -- Crystalsong Forest
(13498,1), -- Storm Peaks
(13497,1), -- Grizzly Hills
(13496,1), -- Howling Fjords
(11805,1), -- Ashenvale // Honor the Flame (Alliance) - Kalimdor
(11812,1), -- Desolace
(11815,1), -- Dustwallow Marsh
(11834,1), -- Winterspring
(11833,1), -- Tanaris
(11831,1), -- Silithus
(11817,1), -- Feralas
(11811,1), -- Darkshore
(11806,1), -- Azuremyst Isle
(11809,1), -- Bloodmyst Isle
(11824,1), -- Teldrassil
(11826,1), -- The Hinterlands // Honor the Flame (Alliance) - Eeastern Kingdoms
(11827,1), -- The Western Plaguelands
(11819,1), -- Hillsbrad Foothills
(11583,1), -- Westfall
(11828,1), -- Wetlands
(11816,1), -- Elwynn Forest
(11810,1), -- Burning Steppes
(11808,1), -- Blasted Lands
(11804,1), -- Arathi Highlands
(11832,1), -- Cape of Stranglethorn
(11813,1), -- Dun Morogh
(11814,1), -- Duskwood
(11820,1), -- Loch Modan
(11822,1), -- Redridge Mountains
(11823,1), -- Shadowmoon Valley // Honor the Flame (Alliance) - Outland
(11821,1), -- Nagrand
(11830,1), -- Netherstorm
(11818,1), -- Hellfire Peninsula
(11825,1), -- Terokkar
(11807,1), -- Blade's Edge
(11829,1), -- Zangarmarsh
(13485,1), -- Borean Tundra // Honor the Flame (Alliance) - Northrend
(13487,1), -- Dragonblight
(13489,1), -- Grizzly Hills
(13488,1), -- Howling Fjord
(13492,1), -- Zul'Drak
(13490,1), -- The Storm Peaks
(13486,1), -- Sholazar Basin
(13491,1), -- Crystalsong Forest
(11770,1), -- Durotar // Desecrate the Flame (Alliance) - Kalimdor
(11769,1), -- Desolace
(11777,1), -- Mulgore
(11803,1), -- Winterspring
(11783,1), -- Barrens
(11773,1), -- Feralas
(11765,1), -- Ashenvale
(11771,1), -- Dustwallow marsh
(11785,1), -- Thousand Needles
(11800,1), -- Silithus
(11780,1), -- Stonetalon Mountains
(11802,1), -- Tanaris
(11774,1), -- Ghostland // Desecrate the Flame (Alliance) - Eastern Kingdoms
(11772,1), -- Eversong woods
(11776,1), -- Hillsbrad Foothills
(11781,1), -- Swamp of sorrows
(11801,1), -- Cape of Stranglethorn
(11768,1), -- Burning Steppes
(11784,1), -- The Hinterlands
(11580,1), -- Silverpine Forest
(11786,1), -- Tirisfal Glades
(11766,1), -- Badlands
(11764,1), -- Arathi Highlands
(11775,1), -- Hellfire Peninsula // Desecrate the Flame (Alliance) - Outland
(11779,1), -- Shadowmoon Valley
(11799,1), -- Netherstorm
(11782,1), -- Terokkar
(11787,1), -- Zangarmarsh
(11767,1), -- Blade' Edge
(11778,1), -- Nagrand
(13458,1), -- Zul'Drak // Desecrate the Flame (Alliance) - Northrend
(13441,1), -- Borean Tundra
(13450,1), -- Sholazar Basin
(13451,1), -- Dragonblight
(13457,1), -- Crystalsong Forest
(13455,1), -- Storm Peaks
(13454,1), -- Grizzly Hills
(13453,1), -- Howling Fjords
(11734,1), -- Ashenvale // Desecrate the Flame (Horde) - Kalimdor
(11741,1), -- Desolace
(11744,1), -- Dustwallow Marsh
(11763,1), -- Winterspring
(11762,1), -- Tanaris
(11760,1), -- Silithus
(11746,1), -- Feralas
(11740,1), -- Darkshore
(11735,1), -- Azuremyst Isle
(11738,1), -- Bloodmyst Isle
(11753,1), -- Teldrassil
(11755,1), -- The Hinterlands // Desecrate the Flame (Horde) - Eastern Kingdoms
(11756,1), -- The Western Plaguelands
(11748,1), -- Hillsbrad Foothills
(11581,1), -- Westfall
(11757,1), -- Wetlands
(11745,1), -- Elwynn Forest
(11739,1), -- Burning Steppes
(11737,1), -- Blasted Lands
(11732,1), -- Arathi Highlands
(11761,1), -- Cape of Stranglethorn
(11742,1), -- Dun Morogh
(11743,1), -- Duskwood
(11749,1), -- Loch Modan
(11751,1), -- Redridge Mountains
(11752,1), -- Shadowmoon Valley // Desecrate the Flame (Horde) - Outland
(11750,1), -- Nagrand
(11759,1), -- Netherstorm
(11747,1), -- Hellfire Peninsula
(11754,1), -- Terokkar
(11736,1), -- Blade's Edge
(11758,1), -- Zangarmarsh
(13440,1), -- Borean Tundra // Desecrate the Flame (Horde) - Northrend
(13443,1), -- Dragonblight
(13445,1), -- Grizzly
(13444,1), -- Howling Fjord
(13449,1), -- Zul'Drak
(13446,1), -- The Storm Peaks
(13442,1), -- Sholazar Basin
(13447,1), -- Crystalsong Forest
(11972,1), -- Shards of Ahune
(9324,1), -- Stealing Orgrimmar''s Flame
(11935,1), -- Stealing Silvermoon''s Flame
(9326,1), -- Stealing the Undercity''s Flame
(9325,1), -- Stealing Thunder Bluff''s Flame
(9332,1), -- Stealing Darnassus''s Flame
(9331,1), -- Stealing Ironforge''s Flame
(9330,1), -- Stealing Stormwind''s Flame
(11933,1); -- Stealing the Exodar''s Flame
--  Add quest relations to game_event_gameobject_quest and game_event_creature_quest
DELETE FROM `game_event_creature_quest` WHERE `quest` IN (11846,11845,11852,11839,11859,11841,11849,11861,11847,11836,11838,11856,11850,11848,11853,11857,11837,11844,11860,11584,11862,11842,11840,11851,11855,11835,11858,11863,11821,11854,11843,13500,13493,13494,13495,13496,13497,13498,13499,11805,11812,11815,11834,11833,11831,11817,11811,11806,11809,11826,11824,11826,11827,11819,11583,11828,11816,11810,11808,11804,11832,11813,11814,11820,11822,11823,11821,11830,11818,11825,11807,11829,13485,13487,13489,13488,13490,13486,13491,13492,11805,11812,11815,11834,11833,11831,11817,11811,11806,11809,11824,11826,11827,11819,11583,11828,11816,11810,11808,11804,11832,11813,11814,11820,11822,13485,13487,13489,13488,13490,13486,13491,13490,11823,11821,11830,11818,11825,11807,11829,11775,11917,11947,11948,11952,11953,11954,11886,11891,12012,11955,11696,11691,11971,11970,11966,11964,11922,11923,11926,11925,11731,11657,11921,11924,9339,9365);
INSERT INTO `game_event_creature_quest` (`eventEntry`,`id`, `quest`) VALUES
(1,25929, 11846), -- Durotar // Honor the Flame (Horde) - Kalimdor
(1,25928, 11845), -- Desolace
(1,25936, 11852), -- Mulgore
(1,25922, 11839), -- Winterspring
(1,25943, 11859), -- Barrens
(1,25932, 11849), -- Feralas
(1,25884, 11841), -- Ashenvale
(1,25930, 11847), -- Dustwallow marsh
(1,25945, 11861), -- Thousand Needles
(1,25919, 11836), -- Silithus
(1,25921, 11838), -- Tanaris
(1,25940, 11856), -- Stonetalon Mountains
(1,25934, 11851), -- Hellfire Peninsula // Honor the Flame (Horde) - Outland
(1,25938, 11855), -- Shadowmoon Valley
(1,25918, 11835), -- Netherstorm
(1,25942, 11858), -- Terokkar
(1,25947, 11863), -- Zangarmarsh
(1,25937, 11854), -- Nagrand
(1,25926, 11843), -- Blade''s Edge Mountains
(1,32816, 13500), -- Zul'Drak // Honor the Flame (Horde) - Northrend
(1,32809, 13493), -- Borean Tundra
(1,32810, 13494), -- Sholazar Basin
(1,32811, 13495), -- Dragonblight
(1,32815, 13499), -- Crystalsong Forest
(1,32814, 13498), -- Storm Peaks
(1,32813, 13497), -- Grizzly Hills
(1,32812, 13496), -- Howling Fjords
(1,25933, 11850), -- Ghostland // Honor the Flame (Horde) - Eastern Kingdoms
(1,25931, 11848), -- Eversong woods
(1,25935, 11853), -- Hillsbrad Foothills
(1,25941, 11857), -- Swamp of sorrows
(1,25920, 11837), -- Cape of Stranglethorn
(1,25927, 11844), -- Burning Steppes
(1,25944, 11860), -- The Hinterlands
(1,25939, 11584), -- Silverpine Forest
(1,25946, 11862), -- Tirisfal Glades
(1,25925, 11842), -- Badlands
(1,25923, 11840), -- Arathi Highlands
(1,25883, 11805), -- Ashenvale // Honor the Flame (Alliance) - Kalimdor
(1,25894, 11812), -- Desolace
(1,25897, 11815), -- Dustwallow Marsh
(1,25917, 11834), -- Winterspring
(1,25916, 11833), -- Tanaris
(1,25914, 11831), -- Silithus
(1,25899, 11817), -- Feralas
(1,25893, 11811), -- Darkshore
(1,25888, 11806), -- Azuremyst Isle
(1,25891, 11809), -- Bloodmyst Isle
(1,25906, 11824), -- Teldrassil
(1,25908, 11826), -- The Hinterlands // Honor the Flame (Alliance) - Eeastern Kingdoms
(1,25909, 11827), -- The Western Plaguelands
(1,25901, 11819), -- Hillsbrad Foothills
(1,25910, 11583), -- Westfall
(1,25911, 11828), -- Wetlands
(1,25898, 11816), -- Elwynn Forest
(1,25892, 11810), -- Burning Steppes
(1,25890, 11808), -- Blasted Lands
(1,25887, 11804), -- Arathi Highlands
(1,25915, 11832), -- Cape of Stranglethorn
(1,25895, 11813), -- Dun Morogh
(1,25896, 11814), -- Duskwood
(1,25902, 11820), -- Loch Modan
(1,25904, 11822), -- Redridge Mountains
(1,32801, 13485), -- Borean Tundra // Honor the Flame (Alliance) - Northrend
(1,32803, 13487), -- Dragonblight
(1,32805, 13489), -- Grizzly
(1,32804, 13488), -- Howling Fjord
(1,32808, 13492), -- Zul'Drak
(1,32806, 13490), -- The Storm Peaks
(1,32802, 13486), -- Sholazar Basin
(1,32807, 13491), -- Crystalsong Forest
(1,25905, 11823), -- Shadowmoon Valley // Honor the Flame (Alliance) - Outland
(1,25903, 11821), -- Nagrand
(1,25913, 11830), -- Netherstorm
(1,25900, 11818), -- Hellfire Peninsula
(1,25907, 11825), -- Terokkar
(1,25889, 11807), -- Blade's Edge
(1,25912, 11829), -- Zangarmarsh
(1,26221, 11917), -- Striking Back
(1,26221, 11947), -- Striking Back
(1,26221, 11948), -- Striking Back
(1,26221, 11952), -- Striking Back
(1,26221, 11953), -- Striking Back
(1,26221, 11954), -- Striking Back
(1,26221, 11886), -- Unusual Activity
(1,25324, 11891), -- An Innocent Disguise
(1,25324, 12012), -- Inform the Elder
(1,26221, 11955), -- Ahune, the Frost Lord
(1,25710, 11696), -- Ahune is Here!
(1,25697, 11691), -- Summon Ahune
(1,19169, 11971), -- The Spinner of Summer Tales /Horde/
(1,19178, 11971), -- The Spinner of Summer Tales
(1,19175, 11971), -- The Spinner of Summer Tales
(1,19176, 11971), -- The Spinner of Summer Tales
(1,19177, 11971), -- The Spinner of Summer Tales
(1,20102, 11971), -- The Spinner of Summer Tales
(1,19171, 11970), -- The Master of Summer Lore /Alliance/
(1,19148, 11970), -- The Master of Summer Lore
(1,19172, 11970), -- The Master of Summer Lore
(1,18927, 11970), -- The Master of Summer Lore
(1,19173, 11970), -- The Master of Summer Lore
(1,20102, 11970), -- The Master of Summer Lore
(1,16818, 11966), -- Incense for the Festival Scorchlings
(1,16817, 11964), -- Incense for the Summer Scorchlings
(1,26113, 11922), -- Torch Tossing /H/
(1,26113, 11923), -- Torch Catching /H/
(1,26113, 11926), -- More Torch Tossing /H/
(1,26113, 11925), -- More Torch Catching /H/
(1,25975, 11731), -- Torch Tossing /A/
(1,25975, 11657), -- Torch Catching /A/
(1,25975, 11921), -- More Torch Tossing /A/
(1,25975, 11924), -- More Torch Catching /A/
(1,16818, 9339), -- A Thief''s Reward /H/
(1,16817, 9365); -- A Thief''s Reward /A/
DELETE FROM `game_event_gameobject_quest` WHERE `quest` IN (11767,11778,11787,11782,11799,11779,11775,11734,11741,11744,11763,11762,11760,11746,11740,11735,11738,11753,11755,11756,11748,11581,11757,11745,11739,11737,11732,11761,11742,11743,11749,11751,13440,13443,13445,13444,13449,13446,13442,13447,11752,11750,11759,11747,11754,11736,11758,11770,11769,11777,11803,11783,11773,11765,11771,11785,11800,11780,11802,11774,11772,11776,11781,11801,11768,11784,11580,11786,11766,11764,13458,13441,13450,13451,13457,13455,13454,13453);
INSERT INTO `game_event_gameobject_quest` (`eventEntry`,`id`, `quest`) VALUES
(1,187916, 11734), -- Ashenvale // Desecrate the Flame (Horde) - Kalimdor
(1,187924, 11741), -- Desolace
(1,187927, 11744), -- Dustwallow Marsh
(1,187946, 11763), -- Winterspring
(1,187945, 11762), -- Tanaris
(1,187943, 11760), -- Silithus
(1,187929, 11746), -- Feralas
(1,187923, 11740), -- Darkshore
(1,187917, 11735), -- Azuremyst Isle
(1,187921, 11738), -- Bloodmyst Isle
(1,187936, 11753), -- Teldrassil
(1,187938, 11755), -- The Hinterlands // Desecrate the Flame (Horde) - Eeastern Kingdoms
(1,187939, 11756), -- The Western Plaguelands
(1,187931, 11748), -- Hillsbrad Foothills
(1,187564, 11581), -- Westfall
(1,187940, 11757), -- Wetlands
(1,187928, 11745), -- Elwynn Forest
(1,187922, 11739), -- Burning Steppes
(1,187920, 11737), -- Blasted Lands
(1,187914, 11732), -- Arathi Highlands
(1,187944, 11761), -- Cape of Stranglethorn
(1,187925, 11742), -- Dun Morogh
(1,187926, 11743), -- Duskwood
(1,187932, 11749), -- Loch Modan
(1,187934, 11751), -- Redridge Mountains
(1,194032, 13440), -- Borean Tundra // Desecrate the Flame (Horde) - Northrend
(1,194036, 13443), -- Dragonblight
(1,194040, 13445), -- Grizzly
(1,194038, 13444), -- Howling Fjord
(1,194049, 13449), -- Zul'Drak
(1,194044, 13446), -- The Storm Peaks
(1,194035, 13442), -- Sholazar Basin
(1,194045, 13447), -- Crystalsong Forest
(1,187935, 11752), -- Shadowmoon Valley // Desecrate the Flame (Horde) - Outland
(1,187933, 11750), -- Nagrand
(1,187942, 11759), -- Netherstorm
(1,187930, 11747), -- Hellfire Peninsula
(1,187937, 11754), -- Terokkar
(1,187919, 11736), -- Blade's Edge
(1,187941, 11758), -- Zangarmarsh
(1,187958, 11770), -- Durotar // Desecrate the Flame (Alliance) - Kalimdor
(1,187957, 11769), -- Desolace
(1,187965, 11777), -- Mulgore
(1,187953, 11803), -- Winterspring
(1,187971, 11783), -- Barrens
(1,187961, 11773), -- Feralas
(1,187948, 11765), -- Ashenvale
(1,187959, 11771), -- Dustwallow marsh
(1,187973, 11785), -- Thousand Needles
(1,187950, 11800), -- Silithus
(1,187968, 11780), -- Stonetalon Mountains
(1,187952, 11802), -- Tanaris
(1,187962, 11774), -- Ghostland // Desecrate the Flame (Alliance) - Eeastern Kingdoms
(1,187960, 11772), -- Eversong woods
(1,187964, 11776), -- Hillsbrad Foothills
(1,187969, 11781), -- Swamp of sorrows
(1,187951, 11801), -- Cape of Stranglethorn
(1,187956, 11768), -- Burning Steppes
(1,187972, 11784), -- The Hinterlands
(1,187559, 11580), -- Silverpine Forest
(1,187974, 11786), -- Tirisfal Glades
(1,187954, 11766), -- Badlands
(1,187947, 11764), -- Arathi Highlands
(1,187963, 11775), -- Hellfire Peninsula // Desecrate the Flame (Alliance) - Outland
(1,187967, 11779), -- Shadowmoon Valley
(1,187949, 11799), -- Netherstorm
(1,187970, 11782), -- Terokkar
(1,187975, 11787), -- Zangarmarsh
(1,187955, 11767), -- Blade' Edge
(1,187966, 11778), -- Nagrand
(1,194048, 13458), -- Zul'Drak // Desecrate the Flame (Alliance) - Northend
(1,194033, 13441), -- Borean Tundra
(1,194034, 13450), -- Sholazar Basin
(1,194037, 13451), -- Dragonblight
(1,194046, 13457), -- Crystalsong Forest
(1,194043, 13455), -- Storm Peaks
(1,194042, 13454), -- Grizzly Hills
(1,194039, 13453); -- Howling Fjords
