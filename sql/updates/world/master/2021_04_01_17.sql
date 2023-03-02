-- DB update 2021_04_01_16 -> 2021_04_01_17
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_16';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_16 2021_04_01_17 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617189129916741181'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617189129916741181');

-- Delete duplicate mining nodes
SET
@GUID            = '12384,12490,17099,42956,32865,32523,17092,12610,12484,74030,74090,74050,74045,74075,74140,74135,150133,150141,150140,150131,150142,150132,150135,75239,75257,75762,75933,150136,150134,150137,15456,15490,15161,70348,70180,70288,69880,70066,69910,70066,70276,70288,74031,74091,74051,74046,74076,74141,74136,75240,75258,75763,75934,68592,68532,68537,68542,68547,68587,68552,68557,68562,68567,70346,70178,70286,69878,70064,69908,70064,70103,70274,70286,70645,71234,71244,74032,74092,74052,74047,74077,74142,74137,17482,68593,68533,68538,68543,68548,68588,68553,68558,68563,68568,70347,70179,70287,69879,70065,69909,70065,70275,70287,70646,72854,71864,71904,73424,73400,73406,74450,74520,74520,74565,74655,71534,71865,71905,73422,73398,73404,74451,74521,74521,74566,74656,73423,73399,73405,74452,74522,74522,74567,74657,68595,68535,68540,68545,68550,68590,68555,68560,68565,68570,70349,70181,70289,69881,70067,69911,70067,70277,70289,70648,74033,74093,74053,74048,74078,74143,74138,75241,75259,75764,75935,73427,73403,73409,68596,68536,68541,68546,68551,68591,68556,68561,68566,68571,70351,70183,70291,69883,70069,69913,70069,70279,70291,70649,72856,71274,71867,71907,73426,73402,73408,74454,74524,74524,74569,74659,68594,68534,68539,68544,68549,68589,68554,68559,68564,68569,70350,70182,70290,69882,70068,69912,70068,70278,70290,70647,72855,71866,71906,73425,73401,73407,74034,74094,74054,74049,74079,74144,74139,74453,74523,74523,74568,74658,46453';

DELETE FROM `gameobject` WHERE `guid` IN (
12384,  -- Duplicate of 4702, Copper Vein
12490,  -- Duplicate of 4772, Copper Vein
17099,  -- Duplicate of 4851, Copper Vein
42956,  -- Duplicate of 4861, Copper Vein
32865,  -- Duplicate of 4978, Copper Vein
32523,  -- Duplicate of 5041, Copper Vein
17092,  -- Duplicate of 5211, Copper Vein
12610,  -- Duplicate of 5366, Copper Vein
12484,  -- Duplicate of 5376, Copper Vein
74030,  -- Duplicate of 73680, Copper Vein
74090,  -- Duplicate of 73695, Copper Vein
74050,  -- Duplicate of 73895, Copper Vein
74045,  -- Duplicate of 74040, Copper Vein
74075,  -- Duplicate of 74060, Copper Vein
74140,  -- Duplicate of 74125, Copper Vein
74135,  -- Duplicate of 74130, Copper Vein
150133, -- Duplicate of 74823, Copper Vein
150141, -- Duplicate of 74825, Copper Vein
150140, -- Duplicate of 74828, Copper Vein
150131, -- Duplicate of 74835, Copper Vein
150142, -- Duplicate of 74838, Copper Vein
150132, -- Duplicate of 74861, Copper Vein
150135, -- Duplicate of 74870, Copper Vein
75239,  -- Duplicate of 75200, Copper Vein
75257,  -- Duplicate of 75206, Copper Vein
75762,  -- Duplicate of 75615, Copper Vein
75933,  -- Duplicate of 75921, Copper Vein
150136, -- Duplicate of 120306, Copper Vein
150134, -- Duplicate of 120309, Copper Vein
150137, -- Duplicate of 120318, Copper Vein
15456,  -- Duplicate of 4811, Copper Vein
15490,  -- Duplicate of 5164, Copper Vein
15161,  -- Duplicate of 5454, Copper Vein
70348,  -- Duplicate of 68800, Tin Vein
70180,  -- Duplicate of 68974, Tin Vein
70288,  -- Duplicate of 68974, Tin Vein
69880,  -- Duplicate of 69088, Tin Vein
70066,  -- Duplicate of 69088, Tin Vein
69910,  -- Duplicate of 69268, Tin Vein
70066,  -- Duplicate of 69880, Tin Vein
70276,  -- Duplicate of 70162, Tin Vein
70288,  -- Duplicate of 70180, Tin Vein
74031,  -- Duplicate of 73681, Tin Vein
74091,  -- Duplicate of 73696, Tin Vein
74051,  -- Duplicate of 73896, Tin Vein
74046,  -- Duplicate of 74041, Tin Vein
74076,  -- Duplicate of 74061, Tin Vein
74141,  -- Duplicate of 74126, Tin Vein
74136,  -- Duplicate of 74131, Tin Vein
75240,  -- Duplicate of 75201, Tin Vein
75258,  -- Duplicate of 75207, Tin Vein
75763,  -- Duplicate of 75616, Tin Vein
75934,  -- Duplicate of 75922, Tin Vein
46453,  -- Duplicate of 75427, Iron Deposit
68592,  -- Duplicate of 68100, Iron Deposit
68532,  -- Duplicate of 68105, Iron Deposit
68537,  -- Duplicate of 68110, Iron Deposit
68542,  -- Duplicate of 68115, Iron Deposit
68547,  -- Duplicate of 68120, Iron Deposit
68587,  -- Duplicate of 68125, Iron Deposit
68552,  -- Duplicate of 68130, Iron Deposit
68557,  -- Duplicate of 68135, Iron Deposit
68562,  -- Duplicate of 68140, Iron Deposit
68567,  -- Duplicate of 68145, Iron Deposit
70346,  -- Duplicate of 68798, Iron Deposit
70178,  -- Duplicate of 68972, Iron Deposit
70286,  -- Duplicate of 68972, Iron Deposit
69878,  -- Duplicate of 69086, Iron Deposit
70064,  -- Duplicate of 69086, Iron Deposit
69908,  -- Duplicate of 69266, Iron Deposit
70064,  -- Duplicate of 69878, Iron Deposit
70103,  -- Duplicate of 70100, Iron Deposit
70274,  -- Duplicate of 70160, Iron Deposit
70286,  -- Duplicate of 70178, Iron Deposit
70645,  -- Duplicate of 70610, Iron Deposit
71234,  -- Duplicate of 71230, Iron Deposit
71244,  -- Duplicate of 71240, Iron Deposit
74032,  -- Duplicate of 73682, Iron Deposit
74092,  -- Duplicate of 73697, Iron Deposit
74052,  -- Duplicate of 73897, Iron Deposit
74047,  -- Duplicate of 74042, Iron Deposit
74077,  -- Duplicate of 74062, Iron Deposit
74142,  -- Duplicate of 74127, Iron Deposit
74137,  -- Duplicate of 74132, Iron Deposit
17482,  -- Duplicate of 7201, Mithril Deposit
68593,  -- Duplicate of 68101, Mithril Deposit
68533,  -- Duplicate of 68106, Mithril Deposit
68538,  -- Duplicate of 68111, Mithril Deposit
68543,  -- Duplicate of 68116, Mithril Deposit
68548,  -- Duplicate of 68121, Mithril Deposit
68588,  -- Duplicate of 68126, Mithril Deposit
68553,  -- Duplicate of 68131, Mithril Deposit
68558,  -- Duplicate of 68136, Mithril Deposit
68563,  -- Duplicate of 68141, Mithril Deposit
68568,  -- Duplicate of 68146, Mithril Deposit
70347,  -- Duplicate of 68799, Mithril Deposit
70179,  -- Duplicate of 68973, Mithril Deposit
70287,  -- Duplicate of 68973, Mithril Deposit
69879,  -- Duplicate of 69087, Mithril Deposit
70065,  -- Duplicate of 69087, Mithril Deposit
69909,  -- Duplicate of 69267, Mithril Deposit
70065,  -- Duplicate of 69879, Mithril Deposit
70275,  -- Duplicate of 70161, Mithril Deposit
70287,  -- Duplicate of 70179, Mithril Deposit
70646,  -- Duplicate of 70611, Mithril Deposit
72854,  -- Duplicate of 70721, Mithril Deposit
71864,  -- Duplicate of 71844, Mithril Deposit
71904,  -- Duplicate of 71876, Mithril Deposit
73424,  -- Duplicate of 72212, Mithril Deposit
73400,  -- Duplicate of 72302, Mithril Deposit
73406,  -- Duplicate of 73388, Mithril Deposit
74450,  -- Duplicate of 74340, Mithril Deposit
74520,  -- Duplicate of 74340, Mithril Deposit
74520,  -- Duplicate of 74450, Mithril Deposit
74565,  -- Duplicate of 74555, Mithril Deposit
74655,  -- Duplicate of 74625, Mithril Deposit
71534,  -- Duplicate of 71533, Small Thorium Vein
71865,  -- Duplicate of 71845, Small Thorium Vein
71905,  -- Duplicate of 71877, Small Thorium Vein
73422,  -- Duplicate of 72210, Small Thorium Vein
73398,  -- Duplicate of 72300, Small Thorium Vein
73404,  -- Duplicate of 73386, Small Thorium Vein
74451,  -- Duplicate of 74341, Small Thorium Vein
74521,  -- Duplicate of 74341, Small Thorium Vein
74521,  -- Duplicate of 74451, Small Thorium Vein
74566,  -- Duplicate of 74556, Small Thorium Vein
74656,  -- Duplicate of 74626, Small Thorium Vein
73423,  -- Duplicate of 72211, Rich Thorium Vein
73399,  -- Duplicate of 72301, Rich Thorium Vein
73405,  -- Duplicate of 73387, Rich Thorium Vein
74452,  -- Duplicate of 74342, Rich Thorium Vein
74522,  -- Duplicate of 74342, Rich Thorium Vein
74522,  -- Duplicate of 74452, Rich Thorium Vein
74567,  -- Duplicate of 74557, Rich Thorium Vein
74657,  -- Duplicate of 74627, Rich Thorium Vein
68595,  -- Duplicate of 68103, Silver Vein
68535,  -- Duplicate of 68108, Silver Vein
68540,  -- Duplicate of 68113, Silver Vein
68545,  -- Duplicate of 68118, Silver Vein
68550,  -- Duplicate of 68123, Silver Vein
68590,  -- Duplicate of 68128, Silver Vein
68555,  -- Duplicate of 68133, Silver Vein
68560,  -- Duplicate of 68138, Silver Vein
68565,  -- Duplicate of 68143, Silver Vein
68570,  -- Duplicate of 68148, Silver Vein
70349,  -- Duplicate of 68801, Silver Vein
70181,  -- Duplicate of 68975, Silver Vein
70289,  -- Duplicate of 68975, Silver Vein
69881,  -- Duplicate of 69089, Silver Vein
70067,  -- Duplicate of 69089, Silver Vein
69911,  -- Duplicate of 69269, Silver Vein
70067,  -- Duplicate of 69881, Silver Vein
70277,  -- Duplicate of 70163, Silver Vein
70289,  -- Duplicate of 70181, Silver Vein
70648,  -- Duplicate of 70613, Silver Vein
74033,  -- Duplicate of 73683, Silver Vein
74093,  -- Duplicate of 73698, Silver Vein
74053,  -- Duplicate of 73898, Silver Vein
74048,  -- Duplicate of 74043, Silver Vein
74078,  -- Duplicate of 74063, Silver Vein
74143,  -- Duplicate of 74128, Silver Vein
74138,  -- Duplicate of 74133, Silver Vein
75241,  -- Duplicate of 75202, Silver Vein
75259,  -- Duplicate of 75208, Silver Vein
75764,  -- Duplicate of 75617, Silver Vein
75935,  -- Duplicate of 75923, Silver Vein
73427,  -- Duplicate of 72215, Dark Iron Deposit
73403,  -- Duplicate of 72305, Dark Iron Deposit
73409,  -- Duplicate of 73391, Dark Iron Deposit
68596,  -- Duplicate of 68104, Truesilver Deposit
68536,  -- Duplicate of 68109, Truesilver Deposit
68541,  -- Duplicate of 68114, Truesilver Deposit
68546,  -- Duplicate of 68119, Truesilver Deposit
68551,  -- Duplicate of 68124, Truesilver Deposit
68591,  -- Duplicate of 68129, Truesilver Deposit
68556,  -- Duplicate of 68134, Truesilver Deposit
68561,  -- Duplicate of 68139, Truesilver Deposit
68566,  -- Duplicate of 68144, Truesilver Deposit
68571,  -- Duplicate of 68149, Truesilver Deposit
70351,  -- Duplicate of 68803, Truesilver Deposit
70183,  -- Duplicate of 68977, Truesilver Deposit
70291,  -- Duplicate of 68977, Truesilver Deposit
69883,  -- Duplicate of 69091, Truesilver Deposit
70069,  -- Duplicate of 69091, Truesilver Deposit
69913,  -- Duplicate of 69271, Truesilver Deposit
70069,  -- Duplicate of 69883, Truesilver Deposit
70279,  -- Duplicate of 70165, Truesilver Deposit
70291,  -- Duplicate of 70183, Truesilver Deposit
70649,  -- Duplicate of 70614, Truesilver Deposit
72856,  -- Duplicate of 70724, Truesilver Deposit
71274,  -- Duplicate of 71270, Truesilver Deposit
71867,  -- Duplicate of 71847, Truesilver Deposit
71907,  -- Duplicate of 71879, Truesilver Deposit
73426,  -- Duplicate of 72214, Truesilver Deposit
73402,  -- Duplicate of 72304, Truesilver Deposit
73408,  -- Duplicate of 73390, Truesilver Deposit
74454,  -- Duplicate of 74344, Truesilver Deposit
74524,  -- Duplicate of 74344, Truesilver Deposit
74524,  -- Duplicate of 74454, Truesilver Deposit
74569,  -- Duplicate of 74559, Truesilver Deposit
74659,  -- Duplicate of 74629, Truesilver Deposit
68594,  -- Duplicate of 68102, Gold Vein
68534,  -- Duplicate of 68107, Gold Vein
68539,  -- Duplicate of 68112, Gold Vein
68544,  -- Duplicate of 68117, Gold Vein
68549,  -- Duplicate of 68122, Gold Vein
68589,  -- Duplicate of 68127, Gold Vein
68554,  -- Duplicate of 68132, Gold Vein
68559,  -- Duplicate of 68137, Gold Vein
68564,  -- Duplicate of 68142, Gold Vein
68569,  -- Duplicate of 68147, Gold Vein
70350,  -- Duplicate of 68802, Gold Vein
70182,  -- Duplicate of 68976, Gold Vein
70290,  -- Duplicate of 68976, Gold Vein
69882,  -- Duplicate of 69090, Gold Vein
70068,  -- Duplicate of 69090, Gold Vein
69912,  -- Duplicate of 69270, Gold Vein
70068,  -- Duplicate of 69882, Gold Vein
70278,  -- Duplicate of 70164, Gold Vein
70290,  -- Duplicate of 70182, Gold Vein
70647,  -- Duplicate of 70612, Gold Vein
72855,  -- Duplicate of 70722, Gold Vein
71866,  -- Duplicate of 71846, Gold Vein
71906,  -- Duplicate of 71878, Gold Vein
73425,  -- Duplicate of 72213, Gold Vein
73401,  -- Duplicate of 72303, Gold Vein
73407,  -- Duplicate of 73389, Gold Vein
74034,  -- Duplicate of 73684, Gold Vein
74094,  -- Duplicate of 73699, Gold Vein
74054,  -- Duplicate of 73899, Gold Vein
74049,  -- Duplicate of 74044, Gold Vein
74079,  -- Duplicate of 74064, Gold Vein
74144,  -- Duplicate of 74129, Gold Vein
74139,  -- Duplicate of 74134, Gold Vein
74453,  -- Duplicate of 74343, Gold Vein
74523,  -- Duplicate of 74343, Gold Vein
74523,  -- Duplicate of 74453, Gold Vein
74568,  -- Duplicate of 74558, Gold Vein
74658); -- Duplicate of 74628, Gold Vein

-- Cleanup pools
DELETE FROM `pool_gameobject` WHERE FIND_IN_SET (`guid`,@GUID);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
