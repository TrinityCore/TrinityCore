DELETE FROM `npc_trainer` WHERE `ID` IN (19340,20791);
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`, `Index`) VALUES
(19340,3561,5100,0,0,0,0),
(19340,3562,5100,0,0,0,0),
(19340,3563,5100,0,0,0,0),
(19340,3565,5100,0,0,0,0),
(19340,3566,5100,0,0,0,0),
(19340,3567,5100,0,0,0,0),
(19340,10059,16500,0,0,0,0),
(19340,11416,16500,0,0,0,0),
(19340,11417,16500,0,0,0,0),
(19340,11418,16500,0,0,0,0),
(19340,11419,16500,0,0,0,0),
(19340,11420,16500,0,0,0,0),
(19340,32266,16500,0,0,0,0),
(19340,32267,16500,0,0,0,0),
(19340,32271,5100,0,0,0,0),
(19340,32272,5100,0,0,0,0),
(19340,33690,81000,0,0,0,0),
(19340,33691,105000,0,0,0,0),
(19340,35715,81000,0,0,0,0),
(19340,35717,105000,0,0,0,0),
(19340,49358,22500,0,0,0,0),
(19340,49359,5100,0,0,0,0),
(19340,49360,16500,0,0,0,0),
(19340,49361,22500,0,0,0,0),
(19340,53140,150000,0,0,0,0),
(19340,53142,168000,0,0,0,0),
(19340,88342,282000,0,0,0,0),
(19340,88344,282000,0,0,0,0),
(19340,88345,282000,0,0,0,0),
(19340,88346,282000,0,0,0,0),
(19340,132620,423000,0,0,0,0),
(19340,132621,423000,0,0,0,0),
(19340,132626,423000,0,0,0,0),
(19340,132627,423000,0,0,0,0),
(19340,176242,635000,0,0,0,0),
(19340,176244,635000,0,0,0,0),
(19340,176246,635000,0,0,0,0),
(19340,176248,635000,0,0,0,0),
(19340,224869,500000,0,0,0,0),
(19340,224871,500000,0,0,0,0),
(20791,3561,5100,0,0,0,0),
(20791,3562,5100,0,0,0,0),
(20791,3563,5100,0,0,0,0),
(20791,3565,5100,0,0,0,0),
(20791,3566,5100,0,0,0,0),
(20791,3567,5100,0,0,0,0),
(20791,10059,16500,0,0,0,0),
(20791,11416,16500,0,0,0,0),
(20791,11417,16500,0,0,0,0),
(20791,11418,16500,0,0,0,0),
(20791,11419,16500,0,0,0,0),
(20791,11420,16500,0,0,0,0),
(20791,32266,16500,0,0,0,0),
(20791,32267,16500,0,0,0,0),
(20791,32271,5100,0,0,0,0),
(20791,32272,5100,0,0,0,0),
(20791,33690,81000,0,0,0,0),
(20791,33691,105000,0,0,0,0),
(20791,35715,81000,0,0,0,0),
(20791,35717,105000,0,0,0,0),
(20791,49358,22500,0,0,0,0),
(20791,49359,5100,0,0,0,0),
(20791,49360,16500,0,0,0,0),
(20791,49361,22500,0,0,0,0),
(20791,53140,150000,0,0,0,0),
(20791,53142,168000,0,0,0,0),
(20791,88342,282000,0,0,0,0),
(20791,88344,282000,0,0,0,0),
(20791,88345,282000,0,0,0,0),
(20791,88346,282000,0,0,0,0),
(20791,132620,423000,0,0,0,0),
(20791,132621,423000,0,0,0,0),
(20791,132626,423000,0,0,0,0),
(20791,132627,423000,0,0,0,0),
(20791,176242,635000,0,0,0,0),
(20791,176244,635000,0,0,0,0),
(20791,176246,635000,0,0,0,0),
(20791,176248,635000,0,0,0,0),
(20791,224869,500000,0,0,0,0),
(20791,224871,500000,0,0,0,0);

-- Fix Loot
UPDATE creature_loot_template SET MinCount = 1 WHERE MinCount = 0;
UPDATE creature_loot_template SET MaxCount = 1 WHERE MaxCount = 0;

-- Creature models

UPDATE creature_template SET modelid1 = 17693 WHERE modelid1 = 35520;
UPDATE creature_template SET modelid1 = 17759 WHERE modelid1 = 17698;
UPDATE creature_template SET modelid1 = 75730 WHERE modelid1 = 29680;
UPDATE creature_template SET modelid1 = 67146 WHERE modelid1 = 25452;
UPDATE creature_template SET modelid1 = 65891 WHERE modelid1 = 14380;
UPDATE creature_template SET modelid1 = 27913 WHERE modelid1 = 24472;
UPDATE creature_template SET modelid1 = 26303 WHERE modelid1 = 26363;
UPDATE creature_template SET modelid1 = 62616 WHERE modelid1 = 7552;
UPDATE creature_template SET modelid1 = 67149 WHERE modelid1 IN (33996,36450);
UPDATE creature_template SET modelid1 = 21135 WHERE modelid1 = 21526;
UPDATE creature_template SET modelid1 = 33997 WHERE modelid1 = 26101;
UPDATE creature_template SET modelid1 = 9135 WHERE modelid1 = 33071;
UPDATE creature_template SET modelid1 = 11259 WHERE modelid1 = 33072;
UPDATE creature_template SET modelid1 = 75747 WHERE modelid1 = 46377;
UPDATE creature_template SET modelid1 = 75730 WHERE modelid1 IN (72639,31477,35525);
UPDATE creature_template SET modelid1 = 68172 WHERE modelid1 = 14693;
UPDATE creature_template SET modelid1 = 18342 WHERE modelid1 = 18287;
UPDATE creature_template SET modelid1 = 27571 WHERE modelid1 = 21137;
UPDATE creature_template SET modelid1 = 30562 WHERE modelid1 = 23646;
UPDATE creature_template SET modelid1 = 67152 WHERE modelid1 = 27403;
UPDATE creature_template SET modelid1 = 33997 WHERE modelid1 = 31181;
UPDATE creature_template SET modelid1 = 27571 WHERE modelid1 = 65661;
UPDATE creature_template SET modelid1 = 4974 WHERE modelid1 = 67517;
UPDATE creature_template SET modelid1 = 4764 WHERE modelid1 = 67511;
UPDATE creature_template SET modelid1 = 67156 WHERE modelid1 = 30521;
UPDATE creature_template SET modelid1 = 71757 WHERE modelid1 = 19338;
UPDATE creature_template SET modelid1 = 38985 WHERE modelid1 = 32901;
UPDATE creature_template SET modelid1 = 67153 WHERE modelid1 = 31312;
UPDATE creature_template SET modelid1 = 987 WHERE modelid1 = 31812;
UPDATE creature_template SET modelid1 = 71764 WHERE modelid1 = 68353;
UPDATE creature_template SET modelid1 = 67155 WHERE modelid1 = 27074;
UPDATE creature_template SET modelid1 = 67147 WHERE modelid1 = 29182;
UPDATE creature_template SET modelid1 = 67154 WHERE modelid1 = 34658;
UPDATE creature_template SET modelid1 = 16217 WHERE modelid1 = 22588;
UPDATE creature_template SET modelid1 = 5047 WHERE modelid1 = 15298;
UPDATE creature_template SET modelid1 = 28213 WHERE modelid1 IN (27015,27016,27017);
UPDATE creature_template SET modelid1 = 20570 WHERE modelid1 = 58342;
UPDATE creature_template SET modelid1 = 17035 WHERE modelid1 = 58344;
UPDATE creature_template SET modelid1 = 20476 WHERE modelid1 = 62608;
UPDATE creature_template SET modelid1 = 4763 WHERE modelid1 = 32783;
UPDATE creature_template SET modelid1 = 27773 WHERE modelid1 = 25202;
UPDATE creature_template SET modelid1 = 31547 WHERE modelid1 = 68823;
UPDATE creature_template SET modelid1 = 20521 WHERE modelid1 = 19680;
UPDATE creature_template SET modelid1 = 17166 WHERE modelid1 = 24446;
UPDATE creature_template SET modelid1 = 20070 WHERE modelid1 = 24447;
UPDATE creature_template SET modelid1 = 46930 WHERE modelid1 = 19609;
UPDATE creature_template SET modelid1 = 62066 WHERE modelid1 = 27561;
UPDATE creature_template SET modelid1 = 26566 WHERE modelid1 = 62208;
UPDATE creature_template SET modelid2 = 26566 WHERE modelid2 = 62208;
UPDATE creature_template SET modelid4 = 26566 WHERE modelid4 = 62208;
UPDATE creature_template SET modelid1 = 24992 WHERE modelid1 = 45262;
UPDATE creature_template SET modelid2 = 24992 WHERE modelid2 = 45262;
UPDATE creature_template SET modelid1 = 70783 WHERE modelid1 = 8470;
UPDATE creature_template SET modelid1 = 4763 WHERE modelid1 = 31530;
UPDATE creature_template SET modelid1 = 4765 WHERE modelid1 = 31533;
UPDATE creature_template SET modelid1 = 18712 WHERE modelid1 = 17675;
UPDATE creature_template SET modelid1 = 67151 WHERE modelid1 = 27348;
UPDATE creature_template SET modelid1 = 71754 WHERE modelid1 = 16635;
UPDATE creature_template SET modelid1 = 56836 WHERE modelid1 = 56344;
UPDATE creature_template SET modelid1 = 4976 WHERE modelid1 = 33069;
UPDATE creature_template SET modelid1 = 76355 WHERE modelid1 = 71743;
UPDATE creature_template SET modelid1 = 25527 WHERE modelid1 = 28283;
UPDATE creature_template SET modelid1 = 17700 WHERE modelid1 = 24891;
UPDATE creature_template SET modelid1 = 67157 WHERE modelid1 = 26077;
UPDATE creature_template SET modelid1 = 65882 WHERE modelid1 = 18510;
UPDATE creature_template SET modelid1 = 67148 WHERE modelid1 = 27983;
UPDATE creature_template SET modelid1 = 10817 WHERE modelid1 = 59666;
UPDATE creature_template SET modelid1 = 16480 WHERE modelid1 = 62179;
UPDATE creature_template SET modelid1 = 5048 WHERE modelid1 = 62177;
UPDATE creature_template SET modelid1 = 4763 WHERE modelid1 = 33068;
UPDATE creature_template SET modelid1 = 9016 WHERE modelid1 = 9015;
UPDATE creature_template SET modelid1 = 76347 WHERE modelid1 = 7268;
UPDATE creature_template SET modelid1 = 1148 WHERE modelid1 = 7269;
UPDATE creature_template SET modelid1 = 1149 WHERE modelid1 = 7270;
UPDATE creature_template SET modelid1 = 70783 WHERE modelid1 = 9342;
UPDATE creature_template SET modelid1 = 295 WHERE modelid1 = 2157;
UPDATE creature_template SET modelid1 = 17719 WHERE modelid1 = 23056;
UPDATE creature_template SET modelid1 = 17693 WHERE modelid1 = 25579;
UPDATE creature_template SET modelid1 = 6749 WHERE modelid1 = 37284;
UPDATE creature_template SET modelid1 = 39427 WHERE modelid1 = 32412;
UPDATE creature_template SET modelid1 = 29487 WHERE modelid1 = 37096;
UPDATE creature_template SET modelid1 = 4975 WHERE modelid1 = 34788;
UPDATE creature_template SET modelid1 = 17718 WHERE modelid1 = 35534;
UPDATE creature_template SET modelid3 = 0 WHERE entry = 47316 ;
UPDATE creature_template SET modelid1 = 17703 WHERE modelid1 = 35548;
UPDATE creature_template SET modelid1 = 37526 WHERE modelid1 = 37413;
UPDATE creature_template SET modelid1 = 62187 WHERE modelid1 = 27624;
UPDATE creature_template SET modelid1 = 1147 WHERE modelid1 = 45390;
UPDATE creature_template SET modelid1 = 295 WHERE modelid1 = 2156;
UPDATE creature_template SET modelid1 = 36743 WHERE modelid1 = 45435;
UPDATE creature_template SET modelid1 = 38985 WHERE modelid1 = 47824;
UPDATE creature_template SET modelid1 = 62185 WHERE modelid1 = 38640;
UPDATE creature_template SET modelid1 = 29225 WHERE modelid1 = 48818;
UPDATE creature_template SET modelid1 = 75730 WHERE modelid1 = 51187;
UPDATE creature_template SET modelid1 = 17081 WHERE modelid1 = 52285;
UPDATE creature_template SET modelid1 = 52035 WHERE modelid1 = 52527;
UPDATE creature_template SET modelid1 = 63345 WHERE modelid1 = 52653;
UPDATE creature_template SET modelid1 = 63345 WHERE modelid1 = 51164;
UPDATE creature_template SET modelid1 = 19608 WHERE modelid1 = 53942;
UPDATE creature_template SET modelid1 = 4923 WHERE modelid1 = 33216;
UPDATE creature_template SET modelid1 = 71755 WHERE modelid1 = 58126;
UPDATE creature_template SET modelid1 = 20570 WHERE modelid1 = 58345;
UPDATE creature_template SET modelid1 = 10815 WHERE modelid1 = 58347;
UPDATE creature_template SET modelid1 = 4762 WHERE modelid1 = 32782;
UPDATE creature_template SET modelid1 = 18651 WHERE modelid1 = 59667;
UPDATE creature_template SET modelid1 = 62187 WHERE modelid1 = 27624;
UPDATE creature_template SET modelid1 = 39850 WHERE modelid1 = 60600;
UPDATE creature_template SET modelid1 = 60637 WHERE modelid1 = 18726;
UPDATE creature_template SET modelid1 = 6809 WHERE modelid1 = 62209;
UPDATE creature_template SET modelid1 = 47166 WHERE modelid1 = 64072;
UPDATE creature_template SET modelid1 = 64535 WHERE modelid1 = 65223;
UPDATE creature_template SET modelid1 = 6749 WHERE modelid1 = 37284;
UPDATE creature_template SET modelid1 = 42145 WHERE modelid1 = 62383;
UPDATE creature_template SET modelid1 = 4762 WHERE modelid1 = 32782;
UPDATE creature_template SET modelid1 = 9134 WHERE modelid1 = 67522;
UPDATE creature_template SET modelid1 = 4973 WHERE modelid1 = 67701;
UPDATE creature_template SET modelid1 = 22255 WHERE modelid1 = 62206;
UPDATE creature_template SET modelid2 = 26566 WHERE entry = 103079;
UPDATE creature_template SET modelid4 = 0 WHERE entry = 103079;
UPDATE creature_template SET modelid1 = 67130 WHERE modelid1 = 69537;
UPDATE creature_template SET modelid1 = 11686 WHERE modelid1 = 67553;
UPDATE creature_template SET modelid2 = 0 WHERE entry = 106783;
UPDATE creature_template SET modelid1 = 65922 WHERE modelid1 = 65819;
UPDATE creature_template SET modelid1 = 47166 WHERE modelid1 = 64072;
UPDATE creature_template SET modelid1 = 4763 WHERE modelid1 = 67418;
UPDATE creature_template SET modelid1 = 19285 WHERE modelid1 = 67606;
UPDATE creature_template SET modelid1 = 15405 WHERE modelid1 = 70810;
UPDATE creature_template SET modelid1 = 60753 WHERE modelid1 = 60754;

-- Creature models (creature table)

UPDATE creature SET modelid = 4763 WHERE ID = 2595;
UPDATE creature SET modelid = 4976 WHERE ID = 2596;
UPDATE creature SET modelid = 4765 WHERE ID = 6196;
UPDATE creature SET modelid = 295 WHERE ID = 9297;
UPDATE creature SET modelid = 75730 WHERE modelid = 29680;
UPDATE creature SET modelid = 62616 WHERE modelid = 7552;
UPDATE creature SET modelid = 26303 WHERE modelid = 26363;
UPDATE creature SET modelid = 67146 WHERE modelid = 25452;

-- Fel hunter fix and some model_info data

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (76355,75747,77398,75730,76347,81472,81473,81474,77402,77403,77404,77405,77406,77407,82821,82688,83228);
INSERT INTO `creature_model_info` VALUES 
(77398,0,0,0,26124),
(75730,0,0,0,26124),
(76347,0,0,0,26124),
(81472,0,0,0,26124),
(81473,0,0,0,26124),
(81474,0,0,0,26124),
(77402,0,0,0,26124),
(77403,0,0,0,26124),
(77404,0,0,0,26124),
(77405,0,0,0,26124),
(77406,0,0,0,26124),
(77407,0,0,0,26124),
(82821,0,0,0,26124),
(82688,0,0,0,26124),
(75747,0,0,0,26124),
(76355,0,0,0,26124),
(83228,0,0,0,26124);

-- Delete summoned spawns

DELETE FROM creature WHERE id = 28528;

-- Bloody Breakout Temp Fix

UPDATE gameobject SET PhaseId = 0 AND (PhaseGroup = 696) WHERE ID = 191092;

-- Correct Iron Siege Cannon Faction

UPDATE creature_template SET faction = 14 WHERE Entry = 85820;

-- Into the Realm of Shadows Fix

DELETE FROM npc_spellclick_spells WHERE spell_id = 52349;
