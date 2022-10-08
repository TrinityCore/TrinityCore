/*
**************************
*    BfaCore Reforged    *
**************************
*/


-- Fix `trainer_spell`
-- Update required level for blacksmithing, mining and engineering, skinning leatherworking
UPDATE `trainer_spell` SET `ReqLevel`=5 WHERE `SpellId` IN (264435, 265838, 264478, 265856, 264578);
-- Cataclysm professions required character level
UPDATE `trainer_spell` SET `ReqLevel`=78 WHERE `SpellId` IN (265826,264244,264441,264584,265844,264484,264466,264501,265862,264541,264623);
-- Cooking
DELETE FROM `trainer_spell` WHERE  `TrainerId`=136 AND `ReqSkillLine`=185;
DELETE FROM `trainer_spell` WHERE `TrainerId`=136 AND `SpellId`=264639;
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
  (136, 264639, 285000, 2548, 1, 0, 0, 0, 78, 27547);
-- Bandage
DELETE FROM `trainer_spell` WHERE  `TrainerId`=877 AND `SpellId`=264478;
-- Add Barbaric Iron Hauberk to Blacksmithing spells
DELETE FROM `trainer_spell` WHERE `TrainerId`=991 AND `SpellId`=280671;
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
  (991, 280671, 2500, 2477, 155, 0, 0, 0, 0, 0);
-- Fishing trainer spells
DELETE FROM `trainer_spell` WHERE `TrainerId`=10;
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(10, 271617, 10, 0, 0, 0, 0, 0, 5, 35622),
(10, 271657, 90000, 2592, 1, 0, 0, 0, 58, 27547),
(10, 271659, 135000, 2591, 1, 0, 0, 0, 58, 27547),
(10, 271661, 180000, 2590, 1, 0, 0, 0, 78, 27547),
(10, 271663, 225000, 2589, 1, 0, 0, 0, 78, 27547),
(10, 271665, 270000, 2588, 1, 0, 0, 0, 88, 27547),
(10, 271673, 360000, 2587, 1, 0, 0, 0, 98, 27547);


-- Fix Trainers
-- Elwynn Forest
DELETE FROM `npc_trainer` WHERE `ID` IN (1430,2329,56796,44238);
-- Michelle Belle (Bandage)
DELETE FROM `creature_trainer` WHERE `CreatureId`=2329;
UPDATE `creature_template` SET `npcflag`=16 WHERE  `entry`=2329;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (2329, 877, 0, 0);
-- Angela Leifeld (Bandage)
UPDATE `creature_template` SET `npcflag`=16 WHERE  `entry`=56796;
DELETE FROM `creature_trainer` WHERE `CreatureId`=56796;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (56796, 880, 0, 0);
-- Harrison Jones (Archaeology)
UPDATE `creature_template` SET `gossip_menu_id`=11821 WHERE  `entry`=44238;


-- Silvermoon city
DELETE FROM `npc_trainer` WHERE `ID` IN (16273,16692,16278,16640,16642,16644,16676,16688,16662,16663,16667,16669,16633,30710,47346,19775);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (16273,16692,16278,16640,16642,16644,16676,16688,16662,16663,16667,16669,16633,30710,47346,19775);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(16273, 989, 0, 0),
(16278, 990, 0, 0),
(16633, 125, 8731, 0),
(16640, 163, 8658, 0),
(16642, 122, 8733, 0),
(16644, 424, 7691, 0),
(16662, 880, 5855, 0),
(16663, 992, 7690, 0),
(16667, 993, 8656, 0),
(16669, 991, 7494, 0),
(16676, 136, 5854, 0),
(16688, 990, 8732, 0),
(16692, 989, 7842, 0),
(19775, 119, 8380, 0),
(30710, 383, 0, 0),
(47346, 373, 11821, 0);
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=16278;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=16273;
UPDATE `creature_template` SET `gossip_menu_id`=5855 WHERE  `entry`=16662;


-- Teldrassil
DELETE FROM `npc_trainer` WHERE `ID` IN (3604,3605,4159,4160,4210,4211,4212,4213,6094,6287,6292,47569,52636,52640,52642,52645,30715);
DELETE FROM `creature_trainer` WHERE `creatureId` IN (3604,3605,4159,4160,4210,4211,4212,4213,6094,6287,6292,47569,52636,52640,52642,52645,30715);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(3604, 424, 0, 0),
(3605, 990, 4174, 0),
(4159, 163, 4349, 0),
(4160, 122, 4131, 0),
(4210, 136, 5853, 0),
(4211, 880, 5855, 0),
(4212, 990, 4241, 0),
(4213, 125, 4163, 0),
(6094, 877, 5855, 0),
(6287, 989, 0, 0),
(6292, 989, 0, 0),
(30715, 383, 0, 0),
(47569, 373, 11821, 0),
(52636, 993, 8517, 0),
(52640, 991, 8521, 0),
(52642, 992, 7690, 0),
(52645, 119, 7815, 0);
UPDATE `creature_template` SET `gossip_menu_id`=5855 WHERE  `entry`=4211;
UPDATE `creature_template` SET `gossip_menu_id`=7815 WHERE  `entry`=52645;
UPDATE `creature_template` SET `gossip_menu_id`=7690 WHERE  `entry`=52642;
UPDATE `creature_template` SET `gossip_menu_id`=5853 WHERE  `entry`=4210;
UPDATE `gossip_menu_option` SET `OptionType`=5 WHERE  `MenuId`=8521;
UPDATE `gossip_menu_option` SET `OptionNpcFlag`=81 WHERE  `MenuId`=8521;


-- Orgrimmar
DELETE FROM `npc_trainer` WHERE `ID` IN (3404,3345,3347,3355,7230,7231,11177,11178,30706,37072,44781,46716,47571,44782);
DELETE FROM `npc_trainer` WHERE `ID` IN (72407,45545,11017,3357,3363,3365,3399,7088,42506,44783,46357,46675,46709,46741);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (133239,133261,72407,11017,45545,7231,3347,47571,37072,11178,11177,3355,7230,44781,3345,46716,30706);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (3357,3363,3365,3399,3404,7088,42506,44782,44783,45559,46357,46675,46709,46741,133104);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(3345, 125, 4168, 0), -- Godan
(3347, 122, 4126, 0), -- Yelmak
(3355, 991, 1012, 0), -- Saru Steelfury
(7230, 991, 0, 0), -- Shayis Steelfury
(7231, 991, 0, 0), -- Kelgruk Bloodaxe
(11177, 991, 0, 0), -- Okothos Ironrager
(11178, 991, 0, 0), -- Borgosh Corebender
(30706, 383, 0, 0), -- Jo'mah
(37072, 991, 0, 0), -- Rogg
(44781, 991, 8521, 0), -- Opuno Ironhorn
(46716, 383, 0, 0), -- Nerog
(47571, 373, 12410, 0), -- Belloc Brightblade
(3357, 992, 7690, 0), -- Makaru
(3363, 163, 4347, 0), -- Magar
(3365, 990, 4209, 0), -- Karolek
(3399, 136, 4747, 0), -- Zamja
(3404, 424, 7691, 0), -- Jandi
(7088, 989, 0, 0), -- Thuwd
(42506, 136, 11637, 0), -- Marogg
(44782, 989, 0, 0), -- Rento
(44783, 163, 0, 0), -- Hiwahi Three-Feathers
(46357, 992, 7690, 0), -- Gonto
(46675, 119, 7815, 0), -- Lugrah
(46709, 136, 0, 0), -- Arugi
(46741, 424, 7691, 0), -- Muraga
(133104, 424, 22114, 0), -- Grove Cultivator Kados
(45545, 993, 0, 0), -- "Jack" Pisarek Slamfix
(11017, 993, 4151, 0), -- Roxxik
(72407, 993, 0, 0), -- Roxxik
(133239, 163, 22125, 0), -- Leyweaver Aurielle
(133261, 136, 22124, 0); -- Feng su
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE  `entry`=7230;
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE  `entry`=7231;
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE  `entry`=11177;
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE  `entry`=11178;
UPDATE `creature_template` SET `gossip_menu_id`=7690 WHERE  `entry`=3357;
UPDATE `creature_template` SET `npcflag`=80 WHERE `entry`=44783;
UPDATE `creature_template` SET `npcflag`=19 WHERE `entry`=45540;
UPDATE `creature_template` SET `gossip_menu_id`=7691 WHERE  `entry`=46741;


-- Undercity
DELETE FROM `npc_trainer` WHERE `ID` IN (4552,52587,4598,4596,4576,139427,47382,4591,7087,4588,11031,30711,4611,4614,4616);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (4552,4576,4588,4591,4596,4598,4611,4614,4616,7087,11031,30711,47382,52587);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
    (4552,136,5854,0), -- Eunice Burch
    (4576,163,0,0), -- Josef Gregorian
    (4588,990,0,0), -- Arthur Moore
    (4591,880,0,0), -- Mary Edras
    (4596,991,0,0), -- James Van Brunt
    (4598,992,0,0), -- Brom Killian
    (4611,122,4132,0), -- Doctor Herbert Halsey
    (4614,424,7691,0), -- Martha Alliestar
    (4616,125,4166,0), -- Lavinia Crowe
    (7087,989,0,0), -- Killian Hagey
    (11031,993,0,0), -- Franklin Lloyd
    (30711,383,0,0), -- Margaux Parchley
    (47382,373,11821,0), -- Adam Hossack
    (52587,119,0,0); -- Neller Fayne
UPDATE `creature_template` SET `npcflag`=82 WHERE  `entry`=4576;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=4588;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=4591;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=4596;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=4598;
UPDATE `creature_template` SET `npcflag`=82 WHERE  `entry`=11031;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=52587;


-- Ironforge
DELETE FROM `npc_trainer` WHERE `ID` IN (4258,5164,11146,52586,4254,5153,5127,6291,5150,5159,5174,5177,39718);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (4258,5164,11146,52586,4254,5153,5127,6291,5150,5159,5174);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
    (4254,992,7690,0),
    (4258,991,593,0),
    (5127,990,4203,0),
    (5150,880,4762,0),
    (5153,163,4345,0),
    (5159,136,4748,0),
    (5164,991,0,0),
    (5174,993,4150,0),
    (6291,989,0,0),
    (11146,991,0,0),
    (52586,119,11861,0);
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE  `entry`=6291;
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE  `entry`=11146;
UPDATE `creature_template` SET `npcflag`=82 WHERE  `entry`=5164;
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE  `entry`=5164;
UPDATE `creature_template` SET `npcflag`=82 WHERE  `entry`=11146;
UPDATE `creature_template` SET `npcflag`=83 WHERE  `entry`=5174;
UPDATE `creature_template` SET `npcflag`=83 WHERE  `entry`=5177;


-- Exodar
DELETE FROM `npc_trainer` WHERE `ID` IN (16752,16729,16719,16736,16763,16723,47570,16724,16725,30716,16726,30716,16726,16731,19778,16728);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (16752,16729,16719,16736,16763,16723,47570,16724,16725,30716,16726,30716,16726,16731,19778,16728);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
    (16719,136,5853,0),
    (16723,122,0,0),
    (16724,991,0,0),
    (16725,122,8866,0),
    (16726,993,8867,0),
    (16728,990,0,0),
    (16729,163,8868,0),
    (16731,880,5855,0),
    (16736,424,7691,0),
    (16752,992,7690,0),
    (16763,989,7842,0),
    (19778,119,8382,0),
    (30716,383,0,0),
    (47570,373,11821,0);
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=16724;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=16728;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=16728;
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=82 WHERE  `entry`=16723;


-- Durotar
DELETE FROM `npc_trainer` WHERE `ID` IN (3174,3184,3185,5943,11025);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (3175,3185,3184,5943,3174,11025);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(3174, 991, 2746, 0),
(3175, 992, 0, 0),
(3184, 122, 0, 0),
(3185, 424, 0, 0),
(5943, 877, 5856, 0),
(11025, 993, 4142, 0);

-- Dun Morogh
DELETE FROM `npc_trainer` WHERE `ID` IN (5392,1702,2326,1701,1699,1355);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (5392,1702,2326,1701);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(1701, 992, 7690, 0),
(1702, 993, 4135, 0),
(2326, 877, 5855, 0),
(5392, 992, 7690, 0);
UPDATE `creature_template` SET `gossip_menu_id`=5855 WHERE  `entry`=2326;

-- Eversong woods
DELETE FROM `npc_trainer` WHERE `ID` IN (15501,16277,16272,16160,16272,16366,16161);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (15501,16277,16272,16160,16272,16366,16161);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(15501, 119, 8376, 0),
(16160, 125, 7524, 0),
(16161, 122, 7524, 0),
(16272, 877, 5856, 0),
(16277, 136, 5854, 0),
(16366, 163, 7524, 0);

-- Tirisfal Glades
DELETE FROM `npc_trainer` WHERE `ID` IN (2132,5695,5695,3549,3523,2114,6289);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (2132,5695,5695,3549,3523,2114,6289);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(2114, 424, 0, 0),
(2132, 122, 0, 0),
(3523, 163, 4267, 0),
(3549, 990, 4184, 0),
(5695, 125, 4202, 0),
(6289, 989, 0, 0);


-- Azuremist Isle
DELETE FROM `npc_trainer` WHERE `ID` IN (17983,17441,17215,17245,17222,17214,17442,17488,17487);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (17983,17441,17215,17245,17222,17214,17442,17488,17487);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(17214, 877, 7380, 0),
(17215, 122, 7384, 0),
(17222, 993, 7383, 0),
(17245, 991, 7389, 0),
(17441, 989, 7429, 0),
(17442, 990, 7430, 0),
(17487, 163, 8519, 0),
(17488, 992, 7690, 0),
(17983, 424, 0, 0);

-- Mulgore
DELETE FROM `npc_trainer` WHERE `ID` IN (10993,5939,3069,3067,5938,6290);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (10993,5939,3069,3067,5938,6290);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(3067, 136, 5854, 0),
(3069, 990, 4185, 0),
(5939, 877, 5856, 0),
(6290, 989, 0, 0),
(10993, 993, 0, 0);
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=6290;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=10993;

-- Booty Bay
DELETE FROM `npc_trainer` WHERE `ID` IN (54232,908,2836,2837,2836,2627,7406);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (54232,908,2836,2837,2836,2627,7406);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(908, 424, 0, 0),
(2627, 163, 4348, 0),
(2836, 991, 2784, 0),
(2837, 122, 4127, 0),
(7406, 993, 0, 0),
(54232, 136, 12838, 0);
UPDATE `creature_template` SET `gossip_menu_id`='0', `npcflag`='82' WHERE  `entry`=7406;

-- Dustwallow marsh
DELETE FROM `npc_trainer` WHERE `ID` IN (53436,53409,11052,4894,4898,53437,53421,4888,53410,53415,4941,12939,5388);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (53409,53436,11052,4894,4898,53437,53421,53410,53415,4941,12939,5388);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(4894, 136, 12847, 0),
(4898, 424, 0, 0),
(4941, 993, 12846, 0),
(5388, 119, 12848, 0),
(11052, 163, 4355, 0),
(12939, 880, 5382, 0),
(53410, 125, 12843, 0),
(53415, 383, 12844, 0),
(53421, 373, 12850, 0),
(53436, 990, 12852, 0),
(53437, 989, 0, 0),
(53409, 992, 25, 0);
-- "Kobold" Kerik
DELETE FROM `gossip_menu` WHERE `MenuId`=25 AND `TextId`=0;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES (25, 0, 35662);
UPDATE `creature_template` SET `gossip_menu_id`=25 WHERE  `entry`=53409;
DELETE FROM `gossip_menu_option` WHERE `MenuId`=25;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(25, 0, 3, 'Train me.', 0, 5, 1, 0),
(25, 1, 1, 'Let me browse your goods.', 0, 3, 128, 0);


-- Thunderbluff
DELETE FROM `npc_trainer` WHERE `ID` IN (3007,3001,3004,3026,3013,7089,3009,47572,2998,3011,30709,52651,2798,52657);
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (3007,3001,3004,3026,3013,7089,3009,47572,2998,3011,30709,52651,2798,52657);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(2798, 880, 5856, 0),
(2998, 991, 1017, 0),
(3001, 992, 7690, 0),
(3004, 163, 4351, 0),
(3007, 990, 4242, 0),
(3009, 122, 4128, 0),
(3011, 125, 4165, 0),
(3013, 424, 7691, 0),
(3026, 136, 5854, 0),
(7089, 989, 0, 0),
(30709, 383, 0, 0),
(47572, 373, 11821, 0),
(52651, 993, 13014, 0),
(52657, 119, 7815, 0);
UPDATE `creature_template` SET `npcflag`='80' WHERE  `entry`=7089;


-- Bilgewater Cartel
-- Doz Zapnozzle
DELETE FROM `creature_trainer` WHERE `CreatureId`=49879 AND `MenuId`=10826 AND `OptionIndex`=0;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (49879, 877, 10826, 0);

-- KTC Train-a-Tron Deluxe
UPDATE `gossip_menu_option` SET `OptionType`=3, `OptionNpcFlag`=128 WHERE  `MenuId`=12002 AND `OptionIndex`=0;
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=12006 WHERE  `MenuId`=12002 AND `OptionIndex`=1;
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=12007 WHERE  `MenuId`=12002 AND `OptionIndex`=2;
UPDATE `gossip_menu_option` SET `OptionNpcFlag`=1 WHERE  `MenuId`=12002 AND `OptionIndex`=1;
UPDATE `gossip_menu_option` SET `OptionNpcFlag`=1 WHERE  `MenuId`=12002 AND `OptionIndex`=2;

DELETE FROM `gossip_menu` WHERE `MenuId`=12006 AND `TextId`=0;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES (12006, 0, 35662);
DELETE FROM `gossip_menu` WHERE `MenuId`=12007 AND `TextId`=0;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES (12007, 0, 35662);

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (12002,12006,12007);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(12002, 0, 1, 'Access profession vending machine', 45513, 3, 128, 35662),
(12002, 1, 0, 'I''d like to purchase primary profession training.', 45512, 1, 1, 35662),
(12002, 2, 0, 'I''d like to purchase secondary profession training.', 45761, 1, 1, 35662),
(12006, 0, 3, 'Train me in Alchemy', 0, 5, 1, 35662),
(12006, 1, 3, 'Train me in Blacksmithing', 0, 5, 1, 35662),
(12006, 2, 3, 'Train me in Enchanting', 0, 5, 1, 35662),
(12006, 3, 3, 'Train me in Engineering', 0, 5, 1, 35662),
(12006, 4, 3, 'Train me in Herbalism', 0, 5, 1, 35662),
(12006, 5, 3, 'Train me in Inscription', 0, 5, 1, 35662),
(12006, 6, 3, 'Train me in Jewelcrafting', 0, 5, 1, 35662),
(12006, 7, 3, 'Train me in Leatherworking', 0, 5, 1, 35662),
(12006, 8, 3, 'Train me in Mining', 0, 5, 1, 35662),
(12006, 9, 3, 'Train me in Skinning', 0, 5, 1, 35662),
(12006, 10, 3, 'Train me in Tailoring', 0, 5, 1, 35662),
(12007, 0, 3, 'Train me in Cooking', 0, 5, 1, 35662),
(12007, 1, 3, 'Train me in Fishing', 0, 5, 1, 35662);

DELETE FROM `creature_trainer` WHERE `CreatureId`=49885;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
    (49885,59,12006,0),
    (49885,80,12006,1),
    (49885,51,12006,2),
    (49885,102,12006,3),
    (49885,388,12006,4),
    (49885,387,12006,5),
    (49885,48,12006,6),
    (49885,103,12006,7),
    (49885,389,12006,8),
    (49885,390,12006,9),
    (49885,117,12006,10),
    (49885, 136, 12007, 0),
    (49885, 10, 12007, 1);

-- Jordan Smith, Marie Holdston
DELETE FROM `npc_trainer` WHERE  `ID`=4888;
DELETE FROM `npc_trainer` WHERE  `ID`=55684;

DELETE FROM `gossip_menu` WHERE `MenuId`=20;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES (20, 0, 35662);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=20;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(20, 0, 3, 'Train me!', 0, 5, 1, 0),
(20, 1, 1, 'I want to browse your goods', 0, 3, 128, 0);

UPDATE `creature_template` SET `gossip_menu_id`='20' WHERE  `entry`=4888;
UPDATE `creature_template` SET `gossip_menu_id`='20' WHERE  `entry`=55684;

DELETE FROM `creature_trainer` WHERE `CreatureId` IN (4888,55684);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(4888, 991, 20, 0),
(55684, 991, 20, 0);


-- Stormwind Embassy, Lion's Rest
DELETE FROM `npc_trainer` WHERE `ID`=5502;

UPDATE `gossip_menu_option` SET `OptionNpcFlag`=1 WHERE  `MenuId`=22124 AND `OptionIndex`=0;
UPDATE `gossip_menu_option` SET `OptionNpcFlag`=128 WHERE  `MenuId`=22124 AND `OptionIndex`=1;
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry` IN (5502,133326,133363,133394,133396);
UPDATE `creature_template` SET `gossip_menu_id`=22124 WHERE  `entry`=133411;

DELETE FROM `creature_trainer` WHERE `CreatureId` IN (5502,133326,133363,133394,133396,133411);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(5502, 424, 0, 0),
(133326, 993, 0, 0),
(133363, 163, 0, 0),
(133394, 125, 0, 0),
(133396, 880, 0, 0),
(133411, 136, 22124, 0);


-- Alma Jainrose (Lakeshire)
DELETE FROM `npc_trainer` WHERE  `ID`=812;
UPDATE `creature_trainer` SET `TrainerId`='424' WHERE  `CreatureId`=812 AND `MenuId`=7691 AND `OptionIndex`=0;

-- Xylinnia starshine (Feathermoon stronghold)
UPDATE `creature_trainer` SET `TrainerId`='125' WHERE  `CreatureId`=7949 AND `MenuId`=4164 AND `OptionIndex`=0;