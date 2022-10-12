/*
**************************
*    BfaCore Reforged    *
**************************
*/


-- Fix starting area profession Trainer 
DELETE FROM `npc_trainer` WHERE `ID`=47396;
DELETE FROM `creature_trainer` WHERE `MenuId`=12180;
DELETE FROM `creature_trainer` WHERE `MenuId`=12199 AND `OptionIndex`=10;
DELETE FROM `gossip_menu_option` WHERE  `MenuId` IN (12180,12185,12186,12188,12189,12190,12191,12192,12193,12195,12196,12197,12198,12199) AND `OptionIndex` IN (0,1,2,3,4,5,6,7,8,9,10);
-- Blacksmithing
UPDATE `trainer_spell` SET `ReqSkillLine`=2477 WHERE  `TrainerId`=80 AND `ReqSkillLine`=164;
-- Enchanting
UPDATE `trainer_spell` SET `ReqSkillLine`=2494 WHERE  `TrainerId`=51 AND `ReqSkillLine`=333;
UPDATE `creature_trainer` SET `OptionIndex`=11 WHERE `trainerId`=51 AND `MenuId`=12193 AND `OptionIndex`=2;
-- Herbalism
DELETE FROM `trainer_spell` WHERE  `TrainerId`=388 AND `SpellId`=2372;
-- Skinning
DELETE FROM `trainer_spell` WHERE  `TrainerId`=390 AND `SpellId`=8615;
-- Alchemy
DELETE FROM `trainer_spell` WHERE  `TrainerId`=59 AND `SpellId`=2275;
-- Engineering
DELETE FROM `trainer_spell` WHERE  `TrainerId`=102 AND `SpellId`=4039;
-- Inscription
DELETE FROM `trainer_spell` WHERE  `TrainerId`=387 AND `SpellId`=45375;
-- Jewelcrafting
UPDATE `trainer_spell` SET `ReqSkillLine`=2524 WHERE  `TrainerId`=48 AND `ReqSkillLine`=755;
-- Mining
UPDATE `trainer_spell` SET `ReqSkillLine`=2572 WHERE  `TrainerId`=389 AND `ReqSkillLine`=186;
-- Tailoring
UPDATE `trainer_spell` SET `ReqSkillLine`=2540 WHERE  `TrainerId`=117 AND `ReqSkillLine`=197;



-- Fix `trainer_spell` tables for classic/cataclysm trainers
-- Skinning
UPDATE `world_bfa`.`trainer_spell` SET `ReqSkillLine`=2564 WHERE  `TrainerId`=989 AND `SpellId`=265862;

-- Tailoring
DELETE FROM `trainer_spell` WHERE `trainerId`=163 AND `ReqSkillLine` = 197;
DELETE FROM `trainer_spell` WHERE `TrainerId`=163 AND `SpellId`=264623;
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(163, 264623, 10, 2540, 1, 0, 0, 0, 5, 35622);

-- Herbalism
UPDATE `trainer_spell` SET `MoneyCost`=10 WHERE `TrainerId`=388 AND `SpellId`=265820;
DELETE FROM `trainer_spell` WHERE  `TrainerId`=424 AND `SpellId` IN (2373, 265826);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(424, 265826, 10, 2556, 1, 0, 0, 0, 5, 0);

-- Alchemy ReqSkillRank
UPDATE `world_bfa`.`trainer_spell` SET `ReqSkillLine`=2485 WHERE  `TrainerId`=122 AND `SpellId`=264244;
DELETE FROM `trainer_spell` WHERE `TrainerId`=122 AND`SpellId` IN (3170,2331,2332,2334,2337,7836,7934,3171,7179,7841,3447,3173,3176,7837,63732,7845,3177,7181,3452,3448,3449,3450,11449,11450,12609,11448,11451,11457,22808,15833,11461,11465,11467,11460,11478,17551,17552,17553,17555,17556,17557,17573,17572);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
    (122,3170,50,2485,15,0,0,0,0,35662),
    (122,2331,100,2485,25,0,0,0,0,35662),
    (122,2332,150,2485,40,0,0,0,0,35662),
    (122,2334,200,2485,50,0,0,0,0,35662),
    (122,2337,225,2485,55,0,0,0,0,35662),
    (122,7836,400,2485,80,0,0,0,0,35662),
    (122,7934,400,2485,80,0,0,0,0,35662),
    (122,3171,650,2485,90,0,0,0,0,35662),
    (122,7179,650,2485,90,0,0,0,0,35662),
    (122,7841,1000,2485,100,0,0,0,0,35662),
    (122,3447,1500,2485,110,0,0,0,0,35662),
    (122,3173,2000,2485,120,0,0,0,0,35662),
    (122,3176,2500,2485,125,0,0,0,0,35662),
    (122,7837,3000,2485,130,0,0,0,0,35662),
    (122,63732,3500,2485,135,0,0,0,0,35662),
    (122,7845,4000,2485,140,0,0,0,0,35662),
    (122,3177,3000,2485,155,0,0,0,0,35662),
    (122,7181,7750,2485,155,0,0,0,0,35662),
    (122,3452,9000,2485,160,0,0,0,0,35662),
    (122,3448,10500,2485,165,0,0,0,0,35662),
    (122,3449,10500,2485,165,0,0,0,0,35662),
    (122,3450,15500,2485,175,0,0,0,0,35662),
    (122,11449,21000,2485,185,0,0,0,0,35662),
    (122,11450,31000,2485,195,0,0,0,0,35662),
    (122,12609,36000,2485,200,0,0,0,0,35662),
    (122,11448,41000,2485,205,0,0,0,0,35662),
    (122,11451,41000,2485,205,0,0,0,0,35662),
    (122,11457,52500,2485,215,0,0,0,0,35662),
    (122,22808,52500,2485,215,0,0,0,0,35662),
    (122,15833,90000,2485,230,0,0,0,0,35662),
    (122,11461,105000,2485,235,0,0,0,0,35662),
    (122,11465,105000,2485,235,0,0,0,0,35662),
    (122,11467,130000,2485,240,0,0,0,0,35662),
    (122,11460,90000,2485,230,0,0,0,0,35662),
    (122,11478,180000,2485,250,0,0,0,0,35662),
    (122,17551,180000,2485,250,0,0,0,0,35662),
    (122,17552,210000,2485,255,0,0,0,0,35662),
    (122,17553,260000,2485,260,0,0,0,0,35662),
    (122,17555,360000,2485,260,0,0,0,0,35662),
    (122,17556,410000,2485,275,0,0,0,0,35662),
    (122,17557,410000,2485,275,0,0,0,0,35662),
    (122,17573,510000,2485,285,0,0,0,0,35662),
    (122,17572,510000,2485,285,0,0,0,0,35662);

-- Blacksmithing ReqSkillRank
DELETE FROM `trainer_spell` WHERE  `TrainerId`=991 AND `SpellId`=280671;
DELETE FROM `trainer_spell` WHERE `TrainerId`=991 AND`SpellId` IN (2661,2662,2665,2666,2737,2738,2739,3116,3293,3294,3319,3320,3323,3324,3326,7408,8880,9983);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(991,2661,100,2477,35,0,0,0,0,35662),
(991,2662,50,2477,1,0,0,0,0,35662),
(991,2665,100,2477,65,0,0,0,0,35662),
(991,2666,200,2477,70,0,0,0,0,35662),
(991,2737,50,2477,15,0,0,0,0,35662),
(991,2738,50,2477,20,0,0,0,0,35662),
(991,2739,50,2477,25,0,0,0,0,35662),
(991,3116,100,2477,65,0,0,0,0,35662),
(991,3293,250,2477,35,0,0,0,0,35662),
(991,3294,500,2477,70,0,0,0,0,35662),
(991,3319,50,2477,20,0,0,0,0,35662),
(991,3320,100,2477,25,0,0,0,0,35662),
(991,3323,100,2477,40,0,0,0,0,35662),
(991,3324,200,2477,45,0,0,0,0,35662),
(991,3326,250,2477,75,0,0,0,0,35662),
(991,7408,300,2477,65,0,0,0,0,35662),
(991,8880,100,2477,30,0,0,0,0,35662),
(991,9983,100,2477,30,0,0,0,0,35662);

-- Engineering ReqSkillRank
DELETE FROM `trainer_spell` WHERE `TrainerId`= 993 AND `SpellId` IN (3922,3923,3925,3929,3977,7430,3929,3931,3932,3973,8334,3934,3936,3937,3938,3978,3939,3949,6458,3955,3956);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES    
    (993,3922,115,2506,30,0,0,0,0,0),
    (993,3923,115,2506,30,0,0,0,0,0),
    (993,3925,200,2506,50,0,0,0,0,0),
    (993,3929,275,2506,65,0,0,0,0,0),
    (993,3931,275,2506,65,0,0,0,0,0),
    (993,3932,525,2506,85,0,0,0,0,0),
    (993,3934,1000,2506,100,0,0,0,0,0),
    (993,3936,1250,2506,105,0,0,0,0,0),
    (993,3937,1250,2506,105,0,0,0,0,0),
    (993,3938,1250,2506,105,0,0,0,0,0),
    (993,3939,2000,2506,120,0,0,0,0,0),
    (993,3949,3000,2506,130,0,0,0,0,0),
    (993,3955,6500,2506,150,0,0,0,0,0),
    (993,3956,6500,2506,150,0,0,0,0,0),
    (993,3973,650,2506,90,0,0,0,0,0),
    (993,3977,200,2506,60,0,0,0,0,0),
    (993,3978,1500,2506,110,0,0,0,0,0),
    (993,6458,3500,2506,135,0,0,0,0,0),
    (993,7430,200,2506,50,0,0,0,0,0),
    (993,8334,1000,2506,100,0,0,0,0,0);

-- Enchanting
UPDATE `trainer_spell` SET `ReqSkillLine`=2494 WHERE  `TrainerId`=125 AND `ReqSkillLine`=333;
DELETE FROM `trainer_spell` WHERE  `TrainerId`=125 AND `SpellId`=7415;
DELETE FROM `trainer_spell` WHERE `TrainerId`=125 AND`SpellId` IN (13631,13635,14809,13637,13640,13642,13644,13646,13648,14810,13659,13661,13663,13693,13695,13700,13746,13815,13822,13836,13858,13887,13890,63746,13905,13917,13935,13937,13939,13941,13943,13948,17180,17181,20008,20012,217637,20016,20028,20013,20023);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
    (125,13631,7750,2494,155,0,0,0,0,35662),
    (125,13635,7750,2494,155,0,0,0,0,35662),
    (125,14809,7750,2494,155,0,0,0,0,35662),
    (125,13637,9000,2494,160,0,0,0,0,35662),
    (125,13640,9000,2494,160,0,0,0,0,35662),
    (125,13642,10500,2494,165,0,0,0,0,35662),
    (125,13644,13000,2494,170,0,0,0,0,35662),
    (125,13646,13000,2494,170,0,0,0,0,35662),
    (125,13648,13000,2494,170,0,0,0,0,35662),
    (125,14810,15500,2494,175,0,0,0,0,35662),
    (125,13659,18000,2494,180,0,0,0,0,35662),
    (125,13661,18000,2494,180,0,0,0,0,35662),
    (125,13663,21000,2494,185,0,0,0,0,35662),
    (125,13693,31000,2494,195,0,0,0,0,35662),
    (125,13695,36000,2494,200,0,0,0,0,35662),
    (125,13700,36000,2494,200,0,0,0,0,35662),
    (125,13746,41000,2494,205,0,0,0,0,35662),
    (125,13815,46000,2494,210,0,0,0,0,35662),
    (125,13822,46000,2494,210,0,0,0,0,35662),
    (125,13836,52500,2494,215,0,0,0,0,35662),
    (125,13858,65000,2494,220,0,0,0,0,35662),
    (125,13887,77500,2494,225,0,0,0,0,35662),
    (125,13890,77500,2494,225,0,0,0,0,35662),
    (125,63746,77500,2494,225,0,0,0,0,35662),
    (125,13905,90000,2494,230,0,0,0,0,35662),
    (125,13917,90000,2494,230,0,0,0,0,35662),
    (125,13935,105000,2494,235,0,0,0,0,35662),
    (125,13937,130000,2494,240,0,0,0,0,35662),
    (125,13939,130000,2494,240,0,0,0,0,35662),
    (125,13941,155000,2494,245,0,0,0,0,35662),
    (125,13943,155000,2494,245,0,0,0,0,35662),
    (125,13948,180000,2494,250,0,0,0,0,35662),
    (125,17180,180000,2494,250,0,0,0,0,35662),
    (125,17181,180000,2494,250,0,0,0,0,35662),
    (125,20008,210000,2494,255,0,0,0,0,35662),
    (125,20012,360000,2494,270,0,0,0,0,35662),
    (125,217637,410000,2494,275,0,0,0,0,35662),
    (125,20016,460000,2494,280,0,0,0,0,35662),
    (125,20028,560000,2494,290,0,0,0,0,35662),
    (125,20013,610000,2494,295,0,0,0,0,35662),
    (125,20023,610000,2494,295,0,0,0,0,35662);
-- Cataclysm enchanting
DELETE FROM `trainer_spell` WHERE `TrainerId`=125 AND`SpellId` IN (264466);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
	(125,264466,10,2494,1,0,0,0,0,35662);

-- Inscription
DELETE FROM `trainer_spell` WHERE `trainerId`=383 AND `SpellId` IN (50614,50606,50599,58486,57708,58476,59484,59486,59487,57709,59387,60336,50616,50607,50600,58487,57710,58478,59489,59490,59491,50617,57711,50608,50601,58488,58480,57712,59493,59494,59502,50618,57713,50609);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
    (383,50614,7750,2514,155,0,0,0,0,35662),
    (383,50606,9000,2514,160,0,0,0,0,35662),
    (383,50599,10500,2514,165,0,0,0,0,35662),
    (383,58486,13000,2514,170,0,0,0,0,35662),
    (383,57708,15500,2514,175,0,0,0,0,35662),
    (383,58476,15500,2514,175,0,0,0,0,35662),
    (383,59484,15500,2514,175,0,0,0,0,35662),
    (383,59486,15500,2514,175,0,0,0,0,35662),
    (383,59487,15500,2514,175,0,0,0,0,35662),
    (383,57709,36000,2514,200,0,0,0,0,35662),
    (383,59387,36000,2514,200,0,0,0,0,35662),
    (383,60336,36000,2514,200,0,0,0,0,35662),
    (383,50616,41000,2514,205,0,0,0,0,35662),
    (383,50607,46000,2514,210,0,0,0,0,35662),
    (383,50600,52500,2514,215,0,0,0,0,35662),
    (383,58487,65000,2514,220,0,0,0,0,35662),
    (383,57710,77500,2514,225,0,0,0,0,35662),
    (383,58478,77500,2514,225,0,0,0,0,35662),
    (383,59489,77500,2514,225,0,0,0,0,35662),
    (383,59490,77500,2514,225,0,0,0,0,35662),
    (383,59491,77500,2514,225,0,0,0,0,35662),
    (383,50617,180000,2514,250,0,0,0,0,35662),
    (383,57711,180000,2514,250,0,0,0,0,35662),
    (383,50608,210000,2514,255,0,0,0,0,35662),
    (383,50601,260000,2514,260,0,0,0,0,35662),
    (383,58488,310000,2514,265,0,0,0,0,35662),
    (383,58480,360000,2514,270,0,0,0,0,35662),
    (383,57712,410000,2514,275,0,0,0,0,35662),
    (383,59493,410000,2514,275,0,0,0,0,35662),
    (383,59494,410000,2514,275,0,0,0,0,35662),
    (383,59502,410000,2514,275,0,0,0,0,35662),
    (383,50618,560000,2514,290,0,0,0,0,35662),
    (383,57713,560000,2514,290,0,0,0,0,35662),
    (383,50609,610000,2514,295,0,0,0,0,35662);
-- Cataclysm inscription
DELETE FROM `trainer_spell` WHERE `trainerId`=383 AND`SpellId` IN (69385,85785,86004,86005,86375,86401,86402,86403,86615,86609,86616,86640,86641,86642,86643,86648,86649,86652,86653,86654,89244,89368,89369,89370,89371,89372,89373,264501);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
    (383,86004,10,2511,1,0,0,0,0,35662),
    (383,86609,10,2511,1,0,0,0,0,35662),
    (383,89368,10,2511,1,0,0,0,0,35662),
    (383,89373,10,2511,1,0,0,0,0,35662),
    (383,89371,15,2511,5,0,0,0,0,35662),
    (383,89372,30,2511,10,0,0,0,0,35662),
    (383,69385,50,2511,15,0,0,0,0,35662),
    (383,89369,50,2511,15,0,0,0,0,35662),
    (383,89370,75,2511,20,0,0,0,0,35662),
    (383,86005,100,2511,25,0,0,0,0,35662),
    (383,86616,100,2511,25,0,0,0,0,35662),
    (383,86640,100,2511,25,0,0,0,0,35662),
    (383,86648,115,2511,30,0,0,0,0,35662),
    (383,85785,200,2511,50,0,0,0,0,35662),
    (383,86375,200,2511,50,0,0,0,0,35662),
    (383,86401,200,2511,50,0,0,0,0,35662),
    (383,86402,200,2511,50,0,0,0,0,35662),
    (383,86403,200,2511,50,0,0,0,0,35662),
    (383,86654,200,2511,50,0,0,0,0,35662),
    (383,89244,200,2511,50,0,0,0,0,35662),
    (383,86649,225,2511,55,0,0,0,0,35662),
    (383,86641,250,2511,60,0,0,0,0,35662),
    (383,86642,250,2511,60,0,0,0,0,35662),
    (383,86643,250,2511,60,0,0,0,0,35662),
    (383,86652,275,2511,65,0,0,0,0,35662),
    (383,86653,275,2511,65,0,0,0,0,35662),
    (383,86615,350,2511,75,0,0,0,0,35662),
    (383,264501,10,2514,1,0,0,0,5,35662);

-- Jewelcrafting
UPDATE `trainer_spell` SET `ReqSkillLine`=2524 WHERE `TrainerId`=119 AND `ReqSkillLine`=755;
DELETE FROM `trainer_spell` WHERE `TrainerId`=119 AND`SpellId` IN (25620,32808,25621,34955,26872,34959,63743,26874,26876,26880,32809,36525,26883,26885,26902,36526,26903,26907,26908,34960,26911,34961);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
    (119,25620,13000,2524,170,0,0,0,0,35662),
    (119,32808,15500,2524,175,0,0,0,0,35662),
    (119,25621,18000,2524,180,0,0,0,0,35662),
    (119,34955,18000,2524,180,0,0,0,0,35662),
    (119,26872,36000,2524,200,0,0,0,0,35662),
    (119,34959,36000,2524,200,0,0,0,0,35662),
    (119,63743,36000,2524,200,0,0,0,0,35662),
    (119,26874,46000,2524,210,0,0,0,0,35662),
    (119,26876,65000,2524,220,0,0,0,0,35662),
    (119,26880,77500,2524,225,0,0,0,0,35662),
    (119,32809,77500,2524,225,0,0,0,0,35662),
    (119,36525,90000,2524,230,0,0,0,0,35662),
    (119,26883,105000,2524,235,0,0,0,0,35662),
    (119,26885,130000,2524,240,0,0,0,0,35662),
    (119,26902,260000,2524,260,0,0,0,0,35662),
    (119,36526,310000,2524,265,0,0,0,0,35662),
    (119,26903,410000,2524,275,0,0,0,0,35662),
    (119,26907,460000,2524,280,0,0,0,0,35662),
    (119,26908,460000,2524,280,0,0,0,0,35662),
    (119,34960,460000,2524,280,0,0,0,0,35662),
    (119,26911,560000,2524,290,0,0,0,0,35662),
    (119,34961,560000,2524,290,0,0,0,0,35662);
-- Cataclysm jewelcrafting
DELETE FROM `trainer_spell` WHERE `TrainerId`=119 AND`SpellId` IN (264541);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
    (119,264541,10,2524,1,0,0,0,5,35662);
	
	

-- Fix training costs
UPDATE `trainer_spell` SET `MoneyCost`=10 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=1;
UPDATE `trainer_spell` SET `MoneyCost`=15 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=5;
UPDATE `trainer_spell` SET `MoneyCost`=30 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=10;
UPDATE `trainer_spell` SET `MoneyCost`=50 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=15;
UPDATE `trainer_spell` SET `MoneyCost`=75 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=20;
UPDATE `trainer_spell` SET `MoneyCost`=100 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=25;
UPDATE `trainer_spell` SET `MoneyCost`=115 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=30;
UPDATE `trainer_spell` SET `MoneyCost`=130 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=35;
UPDATE `trainer_spell` SET `MoneyCost`=150 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=40;
UPDATE `trainer_spell` SET `MoneyCost`=175 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=45;
UPDATE `trainer_spell` SET `MoneyCost`=200 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=50;
UPDATE `trainer_spell` SET `MoneyCost`=225 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=55;
UPDATE `trainer_spell` SET `MoneyCost`=250 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=60;
UPDATE `trainer_spell` SET `MoneyCost`=275 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=65;
UPDATE `trainer_spell` SET `MoneyCost`=300 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=70;
UPDATE `trainer_spell` SET `MoneyCost`=350 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=75;
UPDATE `trainer_spell` SET `MoneyCost`=400 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=80;
UPDATE `trainer_spell` SET `MoneyCost`=525 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=85;
UPDATE `trainer_spell` SET `MoneyCost`=650 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=90;
UPDATE `trainer_spell` SET `MoneyCost`=775 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=95;
UPDATE `trainer_spell` SET `MoneyCost`=1000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=100;
UPDATE `trainer_spell` SET `MoneyCost`=1250 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=105;
UPDATE `trainer_spell` SET `MoneyCost`=1500 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=110;
UPDATE `trainer_spell` SET `MoneyCost`=1750 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=115;
UPDATE `trainer_spell` SET `MoneyCost`=2000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=120;
UPDATE `trainer_spell` SET `MoneyCost`=2500 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=125;
UPDATE `trainer_spell` SET `MoneyCost`=3000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=130;
UPDATE `trainer_spell` SET `MoneyCost`=3500 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=135;
UPDATE `trainer_spell` SET `MoneyCost`=4000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=140;
UPDATE `trainer_spell` SET `MoneyCost`=5250 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=145;
UPDATE `trainer_spell` SET `MoneyCost`=6500 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=150;
UPDATE `trainer_spell` SET `MoneyCost`=7750 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=155;
UPDATE `trainer_spell` SET `MoneyCost`=9000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=160;
UPDATE `trainer_spell` SET `MoneyCost`=10500 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=165;
UPDATE `trainer_spell` SET `MoneyCost`=13000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=170;
UPDATE `trainer_spell` SET `MoneyCost`=15500 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=175;
UPDATE `trainer_spell` SET `MoneyCost`=18000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=180;
UPDATE `trainer_spell` SET `MoneyCost`=21000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=185;
UPDATE `trainer_spell` SET `MoneyCost`=26000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=190;
UPDATE `trainer_spell` SET `MoneyCost`=31000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=195;
UPDATE `trainer_spell` SET `MoneyCost`=36000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=200;
UPDATE `trainer_spell` SET `MoneyCost`=41000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=205;
UPDATE `trainer_spell` SET `MoneyCost`=46000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=210;
UPDATE `trainer_spell` SET `MoneyCost`=52500 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=215;
UPDATE `trainer_spell` SET `MoneyCost`=65000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=220;
UPDATE `trainer_spell` SET `MoneyCost`=77500 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=225;
UPDATE `trainer_spell` SET `MoneyCost`=90000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=230;
UPDATE `trainer_spell` SET `MoneyCost`=105000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=235;
UPDATE `trainer_spell` SET `MoneyCost`=130000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=240;
UPDATE `trainer_spell` SET `MoneyCost`=155000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=245;
UPDATE `trainer_spell` SET `MoneyCost`=180000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=250;
UPDATE `trainer_spell` SET `MoneyCost`=210000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=255;
UPDATE `trainer_spell` SET `MoneyCost`=260000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=260;
UPDATE `trainer_spell` SET `MoneyCost`=310000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=265;
UPDATE `trainer_spell` SET `MoneyCost`=360000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=270;
UPDATE `trainer_spell` SET `MoneyCost`=410000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=275;
UPDATE `trainer_spell` SET `MoneyCost`=460000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=280;
UPDATE `trainer_spell` SET `MoneyCost`=507895 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=285;
UPDATE `trainer_spell` SET `MoneyCost`=560000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=290;
UPDATE `trainer_spell` SET `MoneyCost`=610000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=295;
UPDATE `trainer_spell` SET `MoneyCost`=660000 WHERE `TrainerId` IN (383,163,125,119) AND `ReqSkillRank`=300;



-- Fix trainers
-- Adele Fielder (Goldshire Leatherworking)
DELETE FROM `npc_trainer` WHERE `ID`=1632;
DELETE FROM `creature_trainer` WHERE `CreatureId`=1632;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (1632, 990, 4203, 0);
UPDATE `creature_template` SET `gossip_menu_id`=4203 WHERE  `entry`=1632;

-- Helen Peltskinner (Goldshire Skinning)
DELETE FROM `npc_trainer` WHERE `ID`=6306;
DELETE FROM `creature_trainer` WHERE `CreatureId`=6306;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (6306, 989, 648, 0);
UPDATE `creature_template` SET `gossip_menu_id`=648 WHERE  `entry`=6306;
UPDATE `creature_template` SET `npcflag`=81 WHERE  `entry`=6306;

-- Smith Argus (Goldshire Blacksmith)
UPDATE `creature_trainer` SET `TrainerId`=991 WHERE  `CreatureId`=514;

-- Alchemist Mallory (Elwynn Forest Alchemy)
DELETE FROM `npc_trainer` WHERE `ID`=1215;
DELETE FROM `creature_trainer` WHERE `CreatureId`=1215;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`) VALUES (1215, 122);
UPDATE `creature_template` SET `npcflag`=80 WHERE  `entry`=1215;

-- Reyna Stonebranch (Elwynn Forest Herbalism)
DELETE FROM `npc_trainer` WHERE `ID`=5137;
DELETE FROM `creature_trainer` WHERE `CreatureId`=5137;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`) VALUES (5137, 424, 7691);

-- Tannysa (Stormwind Herbalism)
DELETE FROM `npc_trainer` WHERE `ID`=5566;
UPDATE `creature_trainer` SET `TrainerId`=424 WHERE `CreatureId`=5566;

-- Theresa Denman (Stormwind Jewelcrafting)
DELETE FROM `npc_trainer` WHERE `ID`=44582;
UPDATE `creature_trainer` SET `TrainerId`=119 WHERE `CreatureId`=44582;

-- Catarina Stanford (Stormwind Inscription)
DELETE FROM `npc_trainer` WHERE `ID`=30713;
UPDATE `creature_trainer` SET `TrainerId`=383 WHERE `CreatureId`=30713;

-- Lucan Cordell (Stormwind Enchanting)
DELETE FROM `npc_trainer` WHERE `ID`=1317;
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=1317;
UPDATE `creature_template` SET `npcflag`=80 WHERE `entry`=1317;
UPDATE `creature_template` SET `trainer_type`=2 WHERE `entry`=1317;
DELETE FROM `creature_trainer` WHERE `CreatureId`=1317;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (1317, 125, 0, 0);

-- Tognus Flintfire (Dun Morogh Blacksmithing)
UPDATE `creature_trainer` SET `TrainerId`=991 WHERE `CreatureId`=1241;

-- Gimble Thislefuzz (Ironforge Enchanting)
DELETE FROM `npc_trainer` WHERE  `ID`=5157;
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=5157;
UPDATE `creature_template` SET `npcflag`=80 WHERE `entry`=5157;
DELETE FROM `creature_trainer` WHERE `CreatureId`=5157;
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (5157, 125, 0, 0);

-- Herbalist Pomeroy (Ironforge Herbalism)
DELETE FROM `npc_trainer` WHERE `ID`=1218;
UPDATE `creature_trainer` SET `TrainerId`=424 WHERE  `CreatureId`=1218;

-- Elise Brightletter (Ironforge Inscription)
DELETE FROM `npc_trainer` WHERE  `ID`=30717;
UPDATE `creature_trainer` SET `TrainerId`=383 WHERE  `CreatureId`=30717;
