-- Horde Honor the Flame Quests
DELETE FROM `creature_queststarter` WHERE `quest` IN (11821,11836,11856,11838,11843);
DELETE FROM `creature_questender` WHERE `quest` IN (11847,11849,11854);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(25932, 11849), -- Feralas
(25930, 11847), -- Dustwallow marsh
(25937, 11854); -- Nagrand
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Durotar flame!' WHERE `Id`=11846;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Mulgore flame!' WHERE `Id`=11852;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Barrens flame!' WHERE `Id`=11859;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Tanaris flame!' WHERE `Id`=11838;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Ashenvale flame!' WHERE `Id`=11841;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Winterspring flame!' WHERE `Id`=11839;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Desolace flame!' WHERE `Id`=11845;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Thousand Needles flame!' WHERE `Id`=11861;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Feralas flame!' WHERE `Id`=11849;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Dustwallow Marsh flame!' WHERE `Id`=11847;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Silithus flame!' WHERE `Id`=11836;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Stonetalon Mountains flame!' WHERE `Id`=11856;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Hellfire Peninsula flame!' WHERE `Id`=11851;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Shadowmoon Valley flame!' WHERE `Id`=11855;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Nagrand flame!' WHERE `Id`=11854;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Netherstorm flame!' WHERE `Id`=11835;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Blades Edge Mountains flame! ' WHERE `Id`=11843;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Terokkar flame!' WHERE `Id`=11858;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Zangarmarsh flame!' WHERE `Id`=11863;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Zul''Drak flame!' WHERE `Id`=13500;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Borean Tundra flame!' WHERE `Id`=13493;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Sholazar Basin flame!' WHERE `Id`=13494;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Dragonblight flame!' WHERE `Id`=13495;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Crystalsong Forest flame!' WHERE `Id`=13499;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Storm Peaks flame!' WHERE `Id`=13498;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Grizzly Hills flame!' WHERE `Id`=13497;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Howling Fjords flame!' WHERE `Id`=13496;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Ghostland flame!' WHERE `Id`=11850;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Eversong woods flame!' WHERE `Id`=11848;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Hillsbrad Foothills flame!' WHERE `Id`=11853;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Swamp of sorrows flame!' WHERE `Id`=11857;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Cape of Stranglethorn flame!' WHERE `Id`=11837;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Burning Steppes flame!' WHERE `Id`=11844;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Hinterlands flame!' WHERE `Id`=11860;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Silverpine Forest flame!' WHERE `Id`=11584;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Tirisfal Glades flame!' WHERE `Id`=11862;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Badlands flame!' WHERE `Id`=11842;
UPDATE `quest_template` SET `RequiredRaces`=690,`OfferRewardText`='Honor the Arathi Highlands flame!' WHERE `Id`=11840;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33356 WHERE `entry`=32816;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=32813;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=32812;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=32811;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25946;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25938;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25936;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25933;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25931;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25929;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25926;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25918;
-- Alliance Honor the Flame Quests
DELETE FROM `creature_questender` WHERE `quest` IN (11805,11812,11815,11834,11833,11831,11817,11811,11806,11809,11826,11824,11826,11827,11819,11583,11828,11816,11810,11808,11804,11832,11813,11814,11820,11822,13485,13487,13489,13488,13492,13490,13486,13491,11823,11821,11830,11818,11825,11807,11829);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(25883, 11805), -- Ashenvale
(25894, 11812), -- Desolace
(25897, 11815), -- Dustwallow Marsh
(25917, 11834), -- Winterspring
(25916, 11833), -- Tanaris
(25914, 11831), -- Silithus
(25899, 11817), -- Feralas
(25893, 11811), -- Darkshore
(25888, 11806), -- Azuremyst Isle
(25891, 11809), -- Bloodmyst Isle
(25906, 11824), -- Teldrassil
(25908, 11826), -- The Hinterlands
(25909, 11827), -- The Western Plaguelands
(25901, 11819), -- Hillsbrad Foothills
(25910, 11583), -- Westfall
(25911, 11828), -- Wetlands
(25898, 11816), -- Elwynn Forest
(25892, 11810), -- Burning Steppes
(25890, 11808), -- Blasted Lands
(25887, 11804), -- Arathi Highlands
(25915, 11832), -- Cape of Stranglethorn
(25895, 11813), -- Dun Morogh
(25896, 11814), -- Duskwood
(25902, 11820), -- Loch Modan
(25904, 11822), -- Redridge Mountains
(32801, 13485), -- Borean Tundra
(32803, 13487), -- Dragonblight
(32805, 13489), -- Grizzly Hills
(32804, 13488), -- Howling Fjord
(32808, 13492), -- Zul'Drak
(32806, 13490), -- The Storm Peaks
(32802, 13486), -- Sholazar Basin
(32807, 13491), -- Crystalsong Forest
(25905, 11823), -- Shadowmoon Valley
(25903, 11821), -- Nagrand
(25913, 11830), -- Netherstorm
(25900, 11818), -- Hellfire Peninsula
(25907, 11825), -- Terokkar
(25889, 11807), -- Blade's Edge
(25912, 11829); -- Zangarmarsh
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Ashenvale flame!' WHERE `Id`=11805;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Desolace flame!' WHERE `Id`=11812;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Dustwallow Marsh flame!' WHERE `Id`=11815;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Winterspring flame!' WHERE `Id`=11834;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Tanaris flame!' WHERE `Id`=11833;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Silithus flame!' WHERE `Id`=11831;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Feralas flame!' WHERE `Id`=11817;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Darkshore flame!' WHERE `Id`=11811;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Azuremyst Isle flame!' WHERE `Id`=11806;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Bloodmyst Isle flame!' WHERE `Id`=11809;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Teldrassil flame!' WHERE `Id`=11824;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Hinterlands flame!' WHERE `Id`=11826;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Western Plaguelands flame!' WHERE `Id`=11827;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Hillsbrad Foothills flame!' WHERE `Id`=11819;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Westfall flame!' WHERE `Id`=11583;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Wetlands flame!' WHERE `Id`=11828;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Elwynn Forest flame!' WHERE `Id`=11816;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Burning Steppes flame!' WHERE `Id`=11810;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Blasted Lands flame!' WHERE `Id`=11808;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Arathi Highlands flame!' WHERE `Id`=11804;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Cape of Stranglethorn flame!' WHERE `Id`=11832;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Dun Morogh flame!' WHERE `Id`=11813;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Duskwood flame!' WHERE `Id`=11814;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Loch Modan flame!' WHERE `Id`=11820;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Redridge Mountains flame!' WHERE `Id`=11822;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Borean Tundra flame!' WHERE `Id`=13485;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Dragonblight flame!' WHERE `Id`=13487;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Grizzly Hills flame!' WHERE `Id`=13489;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Howling Fjord flame!' WHERE `Id`=13488;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Zul''Drak flame!' WHERE `Id`=13492;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Storm Peaks flame!' WHERE `Id`=13490;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Sholazar Basin flame!' WHERE `Id`=13486;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Crystalsong Forest flame!' WHERE `Id`=13491;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Shadowmoon Valley flame!' WHERE `Id`=11823;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Nagrand flame!' WHERE `Id`=11821;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Netherstorm flame!' WHERE `Id`=11830;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Hellfire Peninsula flame!' WHERE `Id`=11818;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Terokkar flame!' WHERE `Id`=11825;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Blade''s Edge Mountains flame!' WHERE `Id`=11807;
UPDATE `quest_template` SET `RequiredRaces`=1101,`OfferRewardText`='Honor the Zangarmarsh flame!' WHERE `Id`=11829;
UPDATE `creature_template` SET `gossip_menu_id`=9203, `npcflag`=3, `unit_flags`=33536 WHERE `entry`=32803;
UPDATE `creature_template` SET `gossip_menu_id`=9203, `npcflag`=3, `unit_flags`=33536 WHERE `entry`=32804;
UPDATE `creature_template` SET `gossip_menu_id`=9203, `npcflag`=3, `unit_flags`=33536 WHERE `entry`=32805;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25888;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25891;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25892;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25903;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25905;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25907;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25909;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25912;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25913;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=32808;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=33536 WHERE `entry`=25889;
-- Northrend Alliance's Bonfire Quests
DELETE FROM `gameobject_queststarter` WHERE `quest` IN (13441,13450,13451,13453,13454,13455,13457,13458);
-- Northrend Horde's Bonfire Quests
DELETE FROM `gameobject_queststarter` WHERE `quest` IN (13440,13442,13443,13444,13445,13446,13447,13449);
-- Stealing the flame
DELETE FROM `creature_queststarter` WHERE `quest` IN (11933,11935);
DELETE FROM `spell_scripts` WHERE `id` IN (29137,29135,29126,46671,29139,29138,29136,46672);
INSERT INTO `spell_scripts` (`id`, `effIndex`,`command`, `datalong`, `datalong2`) VALUES
(29137, 2, 15,29101, 2),
(29135, 2, 15,29102, 2),
(29126, 2, 15,29099, 2),
(46671, 2, 15,46690, 2),
(29139, 2, 15,29133, 2),
(29136, 2, 15,29130, 2),
(29138, 2, 15,29132, 2),
(46672, 2, 15,46689, 2);
-- A Thief's Reward
DELETE FROM `creature_queststarter` WHERE `quest` IN (9365,9339);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(16817, 9365), -- Alliance
(16818, 9339); -- Horde
DELETE FROM `creature_questender` WHERE `quest` IN (9365,9339);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(16817, 9365), -- Alliance
(16818, 9339); -- Horde
-- Alliance Desecrate the flame
DELETE FROM `gameobject_queststarter` WHERE `id` IN (187958,187952,187953,187950,187973,187971,187968,187965,187961,187957,187959,187948,187963,187967,187949,187970,187975,187966,187955,194048,194033,194034,194037,194046,194043,194042,194039,187962,187960,187964,187969,187951,187956,187972,187559,187974,187954,187947);
DELETE FROM `gameobject_questender`   WHERE `id` IN (187958,187952,187953,187950,187973,187971,187968,187965,187961,187957,187959,187948,187963,187967,187949,187970,187975,187966,187955,194048,194033,194034,194037,194046,194043,194042,194039,187962,187960,187964,187969,187951,187956,187972,187559,187974,187954,187947);
INSERT INTO `gameobject_questender` (`id`, `quest`) VALUES
(187958, 11770), -- Durotar
(187957, 11769), -- Desolace
(187965, 11777), -- Mulgore
(187953, 11803), -- Winterspring
(187971, 11783), -- Barrens
(187961, 11773), -- Feralas
(187948, 11765), -- Ashenvale
(187959, 11771), -- Dustwallow marsh
(187973, 11785), -- Thousand Needles
(187950, 11800), -- Silithus
(187968, 11780), -- Stonetalon Mountains
(187952, 11802), -- Tanaris
(187963, 11775), -- Hellfire Peninsula
(187967, 11779), -- Shadowmoon Valley
(187949, 11799), -- Netherstorm
(187970, 11782), -- Terokkar
(187975, 11787), -- Zangarmarsh
(187955, 11767), -- Blade' Edge
(187966, 11778), -- Nagrand
(194048, 13458), -- Zul'Drak
(194033, 13441), -- Borean Tundra
(194034, 13450), -- Sholazar Basin
(194037, 13451), -- Dragonblight
(194046, 13457), -- Crystalsong Forest
(194043, 13455), -- Storm Peaks
(194042, 13454), -- Grizzly Hills
(194039, 13453), -- Howling Fjords
(187962, 11774), -- Ghostland
(187960, 11772), -- Eversong woods
(187964, 11776), -- Hillsbrad Foothills
(187969, 11781), -- Swamp of sorrows
(187951, 11801), -- Cape of Stranglethorn
(187956, 11768), -- Burning Steppes
(187972, 11784), -- The Hinterlands
(187559, 11580), -- Silverpine Forest
(187974, 11786), -- Tirisfal Glades
(187954, 11766), -- Badlands
(187947, 11764); -- Arathi Highlands
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Zul''Drak bonfire!' WHERE `id`=13458;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Crystalsong Forest bonfire!' WHERE `id`=13457;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Storm Peaks bonfire!' WHERE `id`=13455;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Grizzly Hills bonfire!' WHERE `id`=13454;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Howling Fjord bonfire!' WHERE `id`=13453;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Dragonblight bonfire!' WHERE `id`=13451;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Sholazar Basin bonfire!' WHERE `id`=13450;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Borean Tundra bonfire!' WHERE `id`=13441;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Winterspring bonfire!' WHERE `id`=11803;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Tanaris bonfire!' WHERE `id`=11802;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Stranglethorn Vale bonfire!' WHERE `id`=11801;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Silithus bonfire!' WHERE `id`=11800;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Netherstorm bonfire!' WHERE `id`=11799;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Zangarmarsh bonfire!' WHERE `id`=11787;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Dustwallow Marsh bonfire!' WHERE `id`=11771;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Hinterlands bonfire!' WHERE `id`=11784;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Terokkar Forest bonfire!' WHERE `id`=11782;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Shadowmoon Valley bonfire!' WHERE `id`=11779;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Nagrand bonfire!' WHERE `id`=11778;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Hillsbrad Foothills Bonfire!' WHERE `id`=11776;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Hellfire Peninsula bonfire!' WHERE `id`=11775;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Feralas bonfire!' WHERE `id`=11773;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Desolace bonfire!' WHERE `id`=11769;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Burning Steppes bonfire!' WHERE `id`=11768;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Blade''s Edge Mountains bonfire!' WHERE `id`=11767;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Ashenvale bonfire!' WHERE `id`=11765;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Arathi Highlands bonfire!' WHERE `id`=11764;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Silverpine bonfire!' WHERE `id`=11580;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Durotar bonfire!' WHERE `id`=11770;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Mulgore bonfire!' WHERE `id`=11777;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Barrens bonfire!' WHERE `id`=11783;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Thousand Needles bonfire!' WHERE `id`=11785;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Stonetalon Mountains bonfire!' WHERE `id`=11780;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Ghostlands bonfire!' WHERE `id`=11774;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Eversong Woods bonfire!' WHERE `id`=11772;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Swamp of Sorrows bonfire!' WHERE `id`=11781;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Tirisfal Glades bonfire!' WHERE `id`=11786;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Horde''s Badlands bonfire!' WHERE `id`=11766;
-- Horde  Desecrate the flame
DELETE FROM `gameobject_queststarter` WHERE `id` IN (187916,187924,187927,187946,187945,187943,187929,187923,187917,187921,187936,187938,187939,187931,187564,187940,187928,187922,187920,187914,187944,187925,187926,187932,187934,194032,194036,194040,194038,194049,194044,194035,194045,187935,187933,187942,187930,187937,187919,187941);
DELETE FROM `gameobject_questender`   WHERE `id` IN (187916,187924,187927,187946,187945,187943,187929,187923,187917,187921,187936,187938,187939,187931,187564,187940,187928,187922,187920,187914,187944,187925,187926,187932,187934,194032,194036,194040,194038,194049,194044,194035,194045,187935,187933,187942,187930,187937,187919,187941);
INSERT INTO `gameobject_questender` (`id`, `quest`) VALUES
(187916, 11734), -- Ashenvale
(187924, 11741), -- Desolace
(187927, 11744), -- Dustwallow Marsh
(187946, 11763), -- Winterspring
(187945, 11762), -- Tanaris
(187943, 11760), -- Silithus
(187929, 11746), -- Feralas
(187923, 11740), -- Darkshore
(187917, 11735), -- Azuremyst Isle
(187921, 11738), -- Bloodmyst Isle
(187936, 11753), -- Teldrassil
(187938, 11755), -- The Hinterlands
(187939, 11756), -- The Western Plaguelands
(187931, 11748), -- Hillsbrad Foothills
(187564, 11581), -- Westfall
(187940, 11757), -- Wetlands
(187928, 11745), -- Elwynn Forest
(187922, 11739), -- Burning Steppes
(187920, 11737), -- Blasted Lands
(187914, 11732), -- Arathi Highlands
(187944, 11761), -- Cape of Stranglethorn
(187925, 11742), -- Dun Morogh
(187926, 11743), -- Duskwood
(187932, 11749), -- Loch Modan
(187934, 11751), -- Redridge Mountains
(194032, 13440), -- Borean Tundra
(194036, 13443), -- Dragonblight
(194040, 13445), -- Grizzly
(194038, 13444), -- Howling Fjord
(194049, 13449), -- Zul'Drak
(194044, 13446), -- The Storm Peaks
(194035, 13442), -- Sholazar Basin
(194045, 13447), -- Crystalsong Forest
(187935, 11752), -- Shadowmoon Valley
(187933, 11750), -- Nagrand
(187942, 11759), -- Netherstorm
(187930, 11747), -- Hellfire Peninsula
(187937, 11754), -- Terokkar
(187919, 11736), -- Blade's Edge
(187941, 11758); -- Zangarmarsh
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Zul''Drak bonfire!' WHERE `id`=13449;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Crystalsong Forest bonfire!' WHERE `id`=13447;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Storm Peaks bonfire!' WHERE `id`=13446;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Grizzly Hills bonfire!' WHERE `id`=13445;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Howling Fjord bonfire!' WHERE `id`=13444;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Dragonblight bonfire!' WHERE `id`=13443;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Sholazar Basin bonfire!' WHERE `id`=13442;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Borean Tundra bonfire!' WHERE `id`=13440;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Winterspring bonfire!' WHERE `id`=11763;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Tanaris bonfire!' WHERE `id`=11762;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Stranglethorn Vale bonfire!' WHERE `id`=11761;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Silithus bonfire!' WHERE `id`=11760;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Netherstorm bonfire!' WHERE `id`=11759;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Zangarmarsh bonfire!' WHERE `id`=11758;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Wetlands bonfire!' WHERE `id`=11757;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Western Plaguelands bonfire!' WHERE `id`=11756;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Hinterlands bonfire!' WHERE `id`=11755;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Terokkar Forest bonfire!' WHERE `id`=11754;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Teldrassil bonfire!' WHERE `id`=11753;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Shadowmoon Valley bonfire!' WHERE `id`=11752;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Redridge Mountains bonfire!' WHERE `id`=11751;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Nagrand bonfire!' WHERE `id`=11750;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Loch Modan bonfire!' WHERE `id`=11749;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Hillsbrad Foothills Bonfire!' WHERE `id`=11748;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Hellfire Peninsula bonfire!' WHERE `id`=11747;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Feralas bonfire!' WHERE `id`=11746;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Elywnn Forest bonfire!' WHERE `id`=11745;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Dustwallow Marsh bonfire!' WHERE `id`=11744;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Duskwood bonfire!' WHERE `id`=11743;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Dun Morogh bonfire!' WHERE `id`=11742;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Desolace bonfire!' WHERE `id`=11741;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Darkshore bonfire!' WHERE `id`=11740;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Burning Steppes bonfire!' WHERE `id`=11739;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Bloodmyst Isle bonfire!' WHERE `id`=11738;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Blasted Lands bonfire!' WHERE `id`=11737;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Blade''s Edge Mountains bonfire!' WHERE `id`=11736;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Azuremyst Isle bonfire!' WHERE `id`=11735;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Ashenvale bonfire!' WHERE `id`=11734;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Arathi Highlands bonfire!' WHERE `id`=11732;
UPDATE `quest_template` SET `OfferRewardText`='Desecrate the Alliance''s Westfall bonfire!' WHERE `id`=11581;
