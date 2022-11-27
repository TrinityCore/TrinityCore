SET @CGUID := 850376;
SET @OGUID := 501350;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=8988 WHERE `entry`=19175; -- Orc Commoner
UPDATE `creature_template` SET `gossip_menu_id`=8988, `npcflag`=1 WHERE `entry`=19176; -- Tauren Commoner
UPDATE `creature_template` SET `gossip_menu_id`=8988, `npcflag`=1 WHERE `entry`=19177; -- Troll Commoner
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23533; -- T'chali's Voodoo Brewery Apprentice
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23603; -- Uta Roughdough
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23604; -- Agnes Farwithers
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23605; -- Bron
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23706; -- Gordok Festive Keg
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24372; -- Drohn's Distillery Festive Keg
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24373; -- T'chali's Voodoo Brew Festive Keg
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24462; -- Racing Ram
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24495; -- Blix Fixwidget
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24497; -- Ram Master Ray
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24498; -- Cort Gorestein
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24499; -- Ja'ron
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24501; -- Drohn's Distillery Apprentice
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24510; -- Driz Tumblequick
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=27216; -- Bizzle Quicklift
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=27707; -- Great Brewfest Kodo
UPDATE `creature_template` SET `gossip_menu_id`=11383, `minlevel`=60, `maxlevel`=60 WHERE `entry`=40437; -- Battered Brewer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=73914; -- Brewmaster Tao
UPDATE `creature_template` SET `gossip_menu_id`=9549 WHERE `entry`=89830; -- Brew Vendor
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=152775; -- Vinter Mollyleux
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=152780; -- Zenda
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=152948; -- Ha'ka Openview
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153008; -- Kaara
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153009; -- Ikura
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153012; -- Aichi
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153014; -- Lucky Nuru
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=153016; -- Gadar
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153116; -- Jun Soo
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=153167; -- Hydratius
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=154299; -- T'chali's Voodoo Brewery Barker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=154313; -- Drohn's Distillery Barker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=154980; -- Kyl'kahn
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=155131; -- Zipsi Switchcrank
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1735, `npcflag`=16777216, `unit_flags3`=16777216 WHERE `entry`=155134; -- Chowdown Participant's Seat
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216 WHERE `entry`=155135; -- Chowdown Participant's Platter
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=155194; -- La'gar Brewshout
UPDATE `creature_template` SET `gossip_menu_id`=24389, `minlevel`=60, `maxlevel`=60 WHERE `entry`=155269; -- Snipehunter Goro
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=155280; -- Azu
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=155320; -- Brewmaster Pijiu
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry` IN (153070, 153071, 153072, 153073, 153082, 153105, 155034); -- Brewfest Reveler
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags2`=2048 WHERE `entry` IN (153074, 153075); -- Brewfest Reveler

DELETE FROM `creature_template_addon` WHERE `entry` IN (19175, 19176, 19177, 24372, 24373, 40437, 73914, 152775, 152780, 152948, 153008, 153009, 153012, 153014, 153016, 153070, 153071, 153072, 153073, 153074, 153075, 153082, 153105, 153116, 153167, 154299, 154313, 154980, 155034, 155131, 155133, 155134, 155135, 155194, 155269, 155280, 155320);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(19175, 0, 0, 0, 257, 0, 0, 0, 0, 0, '33209 33207 33208'), -- Aura 65511 - Gossip NPC Appearance (only during Brewfest)
(19176, 0, 0, 0, 257, 0, 0, 0, 0, 0, '33209 33207 33208'), -- Aura 65511 - Gossip NPC Appearance (only during Brewfest)
(19177, 0, 0, 0, 257, 0, 0, 0, 0, 0, '33209 33207 33208'), -- Aura 65511 - Gossip NPC Appearance (only during Brewfest)
(24372, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 24372 (Drohn's Distillery Festive Keg)
(24373, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 24373 (T'chali's Voodoo Brew Festive Keg)
(40437, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 40437 (Battered Brewer)
(73914, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 73914 (Brewmaster Tao)
(152775, 0, 0, 0, 1, 0, 10516, 0, 0, 0, '216450'), -- 152775 (Vinter Mollyleux) - Serving Platter Female
(152780, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 152780 (Zenda)
(152948, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 152948 (Ha'ka Openview)
(153008, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153008 (Kaara)
(153009, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153009 (Ikura)
(153012, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153012 (Aichi)
(153014, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153014 (Lucky Nuru)
(153016, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 153016 (Gadar)
(153070, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153070 (Brewfest Reveler)
(153071, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153071 (Brewfest Reveler)
(153072, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153072 (Brewfest Reveler)
(153073, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153073 (Brewfest Reveler)
(153074, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153074 (Brewfest Reveler)
(153075, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153075 (Brewfest Reveler)
(153082, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153082 (Brewfest Reveler)
(153105, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153105 (Brewfest Reveler)
(153116, 0, 0, 0, 1, 0, 0, 0, 0, 0, '297197'), -- 153116 (Jun Soo) - Barserver
(153167, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153167 (Hydratius)
(154299, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154299 (T'chali's Voodoo Brewery Barker)
(154313, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 154313 (Drohn's Distillery Barker)
(154980, 0, 0, 0, 1, 0, 0, 0, 0, 0, '301619 301615'), -- 154980 (Kyl'kahn)
(155034, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 155034 (Brewfest Reveler)
(155131, 0, 0, 0, 1, 0, 0, 0, 0, 0, '301745'), -- 155131 (Zipsi Switchcrank) - Serving Platter
(155133, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 155133 (Etga) - [DNT] Chowdown Organizer
(155134, 0, 0, 0, 1, 0, 0, 0, 0, 0, '297978'), -- 155134 (Chowdown Participant's Seat) - [DNT] Seat Preparation
(155135, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 155135 (Chowdown Participant's Platter)
(155194, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 155194 (La'gar Brewshout)
(155269, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 155269 (Snipehunter Goro)
(155280, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 155280 (Azu)
(155320, 0, 0, 0, 257, 0, 0, 0, 0, 0, '44067'); -- 155320 (Brewmaster Pijiu) - Supplier Mark

UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=24497; -- 24497 (Ram Master Ray)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (23706, 24372, 24373);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(23706, 0, 0, 1, 1, 0, 0, NULL),
(24372, 0, 0, 1, 1, 0, 0, NULL),
(24373, 0, 0, 1, 1, 0, 0, NULL);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (155134);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(155134, 105080, 1, 0);

-- Vehicle data
DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry`=20766;
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(20766, 0, 2.928, 0, 0, 0, 1);

DELETE FROM `creature_template_spell` WHERE `CreatureID`=155134;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(155134, 2, 303242, 45745), -- Chowdown Participant's Seat
(155134, 1, 303241, 45745), -- Chowdown Participant's Seat
(155134, 0, 303240, 45745); -- Chowdown Participant's Seat

-- Gossips
DELETE FROM `gossip_menu` WHERE `MenuID` IN (24389, 24390);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(24389, 38253, 45745), -- 155269 (Snipehunter Goro)
(24390, 14672, 45745); -- 155269 (Snipehunter Goro)

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (24389, 24390);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(24389, 0, 0, 'What are Synthebrew Goggles?', 35222, 1, 0, 24390, 0, 0, 0, NULL, 0, 45745),
(24390, 0, 0, 'I''d like a pair of Synthebrew Goggles.', 35220, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(24390, 1, 0, 'What did you say earlier?', 35223, 1, 0, 24389, 0, 0, 0, NULL, 0, 45745);

UPDATE `gossip_menu_option` SET `ActionPoiID`=0 WHERE `MenuID`=8968 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=45745 WHERE `MenuID` IN (8968, 8967, 9560);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=24389;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,24389,0,0,0,2,0,46735,1,1,1,0,0,'','Show gossip option if the player does not have the item 46735');

-- Equipments
DELETE FROM `creature_equip_template` WHERE (`ID`=7 AND `CreatureID` IN (19176,153082)) OR (`ID`=1 AND `CreatureID`=153016);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(19176, 7, 46733, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Tauren Commoner
(153016, 1, 168670, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Gadar
(153082, 7, 168670, 0, 0, 0, 0, 0, 0, 0, 0, 45745); -- Brewfest Reveler

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN (23533, 23603, 23604, 23605, 23706, 24372, 24373, 24462, 24495, 24497, 24498, 24499, 24501, 24510, 27216, 27707, 40437, 73914, 152775, 152780, 152948, 153008, 153009, 153012, 153014, 153016, 153070, 153071, 153072, 153073, 153074, 153075, 153082, 153105, 153116, 153167, 154299, 154313, 154980, 155034, 155131, 155133, 155134, 155135, 155194, 155269, 155280, 155320);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(23533, 0, 0, 0, 298, 45745),
(23603, 0, 0, 0, 298, 45745),
(23604, 0, 0, 0, 298, 45745),
(23605, 0, 0, 0, 298, 45745),
(23706, 0, 0, 0, 298, 45745),
(24372, 0, 0, 0, 298, 45745),
(24373, 0, 0, 0, 298, 45745),
(24462, 0, 0, 0, 872, 45745),
(24495, 0, 0, 0, 298, 45745),
(24497, 0, 0, 0, 298, 45745),
(24498, 0, 0, 0, 298, 45745),
(24499, 0, 0, 0, 298, 45745),
(24501, 0, 0, 0, 298, 45745),
(24510, 0, 0, 0, 298, 45745),
(27216, 0, 0, 0, 298, 45745),
(27707, 0, 0, 0, 872, 45745),
(40437, 0, 0, 0, 298, 45745),
(73914, 0, 0, 0, 298, 45745),
(152775, 0, 0, 0, 298, 45745),
(152780, 0, 0, 0, 298, 45745),
(152948, 0, 0, 0, 298, 45745),
(153008, 0, 0, 0, 298, 45745),
(153009, 0, 0, 0, 298, 45745),
(153012, 0, 0, 0, 298, 45745),
(153014, 0, 0, 0, 298, 45745),
(153016, 0, 0, 0, 298, 45745),
(153070, 0, 0, 0, 298, 45745),
(153071, 0, 0, 0, 298, 45745),
(153072, 0, 0, 0, 298, 45745),
(153073, 0, 0, 0, 298, 45745),
(153074, 0, 0, 0, 298, 45745),
(153075, 0, 0, 0, 298, 45745),
(153082, 0, 0, 0, 298, 45745),
(153105, 0, 0, 0, 298, 45745),
(153116, 0, 0, 0, 298, 45745),
(153167, 0, 0, 0, 298, 45745),
(154299, 0, 0, 0, 298, 45745),
(154313, 0, 0, 0, 298, 45745),
(154980, 0, 0, 0, 298, 45745),
(155034, 0, 0, 0, 298, 45745),
(155131, 0, 0, 0, 298, 45745),
(155133, 0, 0, 0, 298, 45745),
(155134, 0, 0, 0, 298, 45745),
(155135, 0, 0, 0, 298, 45745),
(155194, 0, 0, 0, 298, 45745),
(155269, 0, 0, 0, 298, 45745),
(155280, 0, 0, 0, 298, 45745),
(155320, 0, 0, 0, 298, 45745);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=45745 WHERE (`DifficultyID`=0 AND `Entry` IN (45244,51230,47336,24930,24927,24926,24924,25081,25080,24931,24929,20493,20488,20486,31720,31727,31724,31723,31725,31726,5640,45095,9988,45081,7567,7565,7562,8404,11814,45086,45082,45093,44978,3399,45094,45008,3400,53081,45029,30706,16926,16909,45211,45025,45558,133108,45559,45789,133153,180176,45548,45546,45540,45023,52170,133236,45019,188163,45545,174864,174863,133114,45015,45549,174865,45567,45565,46080,140462,45659,46078,45347,133228,133523,45566,45830,158141,158138,158133,158131,30611,133276,167032,45563,45814,45552,46755,45553,48510,46082,172558,46754,48513,63086,63085,29929,30723,45138,45137,12795,12794,12793,7311,12791,12789,175050,3405,3404,52036,52033,44975,146626,19850,45139,12797,12790,54657,12798,69978,69977,5910,29143,179897,3189,3334,58199,44783,44785,3403,5892,44788,72939,13417,58193,44782,44770,15188,19176,44781,44780,5816,3330,44779,3322,44787,47321,161223,5909,88706,44735,44725,44740,3335,47335,44726,44723,44745,88704,44743,47254,5875,141912,88705,45230,141920,9564,174147,141528,54004,54113,130911,176095,176094,176012,50088,43062,11046,47663,35162,8576,35096,35086,42672,42673,42671,42650,14539,47817,47818,47767,114840,10266,1383,3360,11178,7790,3355,7231,3361,133355,7230,11177,11176,7793,7792,5812,3356,4043,3409,46675,50482,57922,3358,3357,3362,47788,31769,31758,31757,31755,47815,12353,47771,5195,3352,47764,31756,31768,46640,46639,46638,46637,168619,65058,65065,65060,168598,171691,168626,174164,65063,49573,2756,5029,68869,168551,16869,65061,16868,69333,5034,65008,62445,3353,34955,35364,70301,65074,66022,168553,13842,3354,168597,168596,171689,169166,168628,168621,46985,46667,168623,65071,42709,176261,14377,46642,175084,7951,65078,65076,42638,35845,43239,3333,3332,46619,46622,46618,46620,46621,62193,158789,180684,3359,161203,160452,4953,3348,8659,3347,3345,11066,12136,3346,46181,3350,3351,46742,6987,6986,46741,62197,62196,61369,3365,3225,7088,3366,3316,3372,7010,5811,188169,3321,46716,3371,3367,3364,3363,11017,2855,1420,42548,3413,3317,3315,46718,3412,52032,14451,62200,62199,52810,14498,2857,52812,52809,14499,68979,54473,54472,3369,49737,5639,46708,57801,3368,46709,42506,62194,88703,44871,44868,44866,63626,14881,44867,44865,15476,50488,50477,44918,3310,3216,50323,44948,44919,62198,20492,20491,20490,141310,20489,19177,3329,47247,47246,3328,47233,3327,47248,187775,26537,44160,3331,34765,49131,10880,44158,133218,133271,133270,133261,12796,73151,3323,45337,47571,52034,44338,35068,135201,17098,44872,46140,46358,46556,58155,46555,37072,23128,3312,27489,46512,49622,46357,3144,3319,46359,46142,188655,4047,3342,3314,45339,14375,14376,51195,149404,46572,5188,3370,188656,187758,49750,19175,188157,74228,23635,135202,5614,5613,5611,5610,5609,5606,88702,88701,6466,175135,137762,72559,149279,6929,44877,3313,151937,5817,44853,47253,148263,148795,150131,149408,44876,44854,44852,44878,149297,28960,62195,44856,133186,168459,149626,14392,149371,148250,149290,149258,149523,148242,44851,32520,38821,149296,168441,148770,149522,149270,155739,49837,3108,41621,5822,3204,3198,3197,61751,49743,5951,71100,3296,51346,53408,39380,39379,3100,40949,10685,42504,34719,34718,24935,24934,25075,34717,34715,3084,34730,34723,34721,40891,40948,62114,3127,3123,4311,62116,3300,155194,42859,62115,39596,61325,39595));
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `VerifiedBuild`=45745 WHERE (`Entry`=72654 AND `DifficultyID`=0);

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=45745 WHERE (`Idx`=0 AND `CreatureID` IN (45244,45008,45025,45015,45549,45567,46755,44782,44723,9564,47818,168626,168553,3317,3412,14451,44866,50477,47248,49131,46512,188157,5609,149297,155320,34717,24501,24495,39596,153008,24372,24924,31727,5640,8404,45093,46080,45566,172558,12794,3404,5892,58193,54113,47663,42672,42673,7231,4043,62445,13842,46642,46620,46618,46742,3316,14881,187775,44872,27489,14376,3370,175135,148242,53700,155034,25081,31724,7562,44978,45546,45565,45347,7311,69978,44770,141912,130911,43062,31216,42671,7790,5195,65060,2756,72934,3346,3225,3372,3364,5639,3216,20492,3319,51195,175165,3198,3084,3300,24497,152780,73914,154299,30706,45019,46078,133523,48513,12789,12798,5909,5875,7230,31755,65065,16868,168628,12922,3345,46741,62197,5811,2855,52032,52812,20491,3331,133270,12796,52034,45339,5611,44877,28960,149626,34718,34730,24510,155269,23604,47336,24931,31725,45548,63085,45553,45138,52036,69977,54004,11178,7793,3358,31758,168598,34955,168621,46667,7951,3359,4953,3347,3365,11017,52810,57801,46709,44865,50488,133261,73151,17098,14375,188656,5614,44876,149523,149270,49837,3123,23706,155280,133153,52170,45830,158131,52033,3403,19176,3322,3335,174147,141528,176095,176012,10266,65063,5034,3353,168597,43239,61369,46718,62194,44868,26537,44338,46358,44853,133186,38821,24373,24498,153075,20488,45081,45082,11814,174863,140462,48510,44743,3355,5812,3357,3362,46637,65058,46985,65076,3348,6986,188169,3368,88703,44867,3310,44948,62198,44158,135201,46556,6466,150131,44856,3197,3100,40949,62116,153167,31720,7567,180176,45552,12793,19850,44783,15188,44780,88706,44735,11176,47764,46639,35364,168623,175084,3350,7088,46716,3413,49737,3329,47233,35068,188655,4047,46572,137762,149408,148263,149522,155739,40891,61325,62115,154980,45211,45558,174865,133276,45563,3405,12790,3334,3189,44781,44740,60199,47817,1383,3361,46675,12353,171691,49573,5029,65008,169166,46622,180684,51090,3366,62199,14499,68979,44919,133218,37072,49622,149404,88701,151937,14392,32520,71100,3296,24934,153072,20493,45095,53081,3400,45029,174864,133228,158138,30723,12791,44788,13417,45230,35096,42650,31756,168619,65061,66022,42709,3332,46621,7010,3321,3315,42506,44918,20489,46359,19175,74228,40437,72559,148770,3204,34723,153016,27707,40948,62114,24462,152948,153070,155194,153105,24930,16909,45559,133114,45659,46082,45139,54657,5910,3330,88705,114840,11177,3409,3352,168551,65074,171689,42638,46619,62193,8659,3369,46708,44871,50323,34765,58155,46357,23635,5610,5817,44852,148795,148250,3108,5822,175156,4311,155131,153074,23603,24929,20486,188163,158141,63086,30611,45137,175050,44785,161223,8576,3360,7792,50482,47788,46638,70301,3354,176261,3333,158789,160452,46181,3371,1420,14498,54472,47246,44160,10880,46555,3342,88702,168459,61751,39380,24935,34721,152775,24499,153071,23533,24927,9988,16926,133236,46754,12795,12797,47321,88704,44725,35086,14539,47815,31768,46640,68869,65071,14377,11066,3351,3367,3363,15476,133271,3144,135202,5606,3313,44878,149258,10685,42859,153014,153009,25080,45789,45540,158133,45814,179897,44787,47254,44726,141920,176094,11046,47767,57922,31757,69333,168596,35845,62196,52809,2857,63626,19177,3327,3323,3314,5188,44854,149371,149290,168441,41621,53408,34719,25075,153012,155134,153116,23605,155133,51230,31726,45545,29929,44975,29143,72939,5816,44779,50088,3356,31769,174164,16869,6987,42548,54473,72654,20490,3328,47571,23128,3312,187758,47253,3527,53701,49743,42504,3127,154313,155135,153082,153073,24926,31723,7565,45086,45094,3399,133108,45023,167032,146626,58199,47335,44745,35162,133355,47771,65078,161203,12136,62200,141310,47247,45337,46140,46142,49750,5613,149279,6929,62195,44851,149296,5951,51346,39379,34715,39595,27216)) OR (`Idx`=3 AND `CreatureID` IN (45015,149297,58193,155034,3084,31755,31758,4953,49837,45830,158131,133186,153075,44158,149408,40891,62115,65008,14499,133218,149404,71100,3296,153072,158138,45230,42650,31756,74228,40948,62114,153070,153105,153074,158141,44160,168459,153071,31768,15476,133271,158133,45814,31757,149371,149290,51230,31769,42548,49743,153082,153073,46140,46142,149296,51346)) OR (`Idx`=2 AND `CreatureID` IN (45015,149297,58193,155034,3084,3300,31755,31758,4953,49837,45830,158131,133186,153075,44158,149408,40891,61325,62115,65008,14499,133218,149404,71100,3296,153072,158138,45230,42650,31756,74228,40948,62114,153070,153105,153074,158141,44160,168459,153071,31768,15476,133271,42859,158133,45814,31757,149371,149290,51230,31769,42548,49743,42504,153082,153073,46140,46142,149296,51346)) OR (`Idx`=1 AND `CreatureID` IN (45015,149297,58193,14881,53700,155034,42671,72934,3198,3084,3300,31755,28960,149626,31758,4953,52810,149270,49837,45830,158131,19176,133186,38821,153075,46985,44158,3197,47764,149408,148263,149522,155739,40891,61325,62115,65008,14499,133218,149404,32520,71100,3296,153072,158138,45230,42650,31756,19175,74228,72559,148770,40948,62114,153070,153105,148795,153074,158141,44160,168459,153071,31768,15476,133271,149258,42859,158133,45814,31757,35845,19177,149371,149290,51230,50088,31769,42548,72654,53701,49743,42504,153082,153073,46140,46142,149296,51346)) OR (`Idx`=5 AND `CreatureID` IN (3296,45230,46140)) OR (`Idx`=4 AND `CreatureID` IN (3296,45230,46140)) OR (`Idx`=7 AND `CreatureID`=46140) OR (`Idx`=6 AND `CreatureID`=46140);

DELETE FROM `creature_model_info` WHERE `DisplayID`=91662;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(91662, 0.409200012683868408, 1.65000009536743164, 0, 45745);

UPDATE `creature_model_info` SET `VerifiedBuild`=45745 WHERE `DisplayID` IN (26748, 33191, 34340, 33194, 35545, 22745, 22743, 22740, 22739, 22746, 22744, 17701, 17699, 17700, 27686, 27685, 27684, 27687, 4602, 3759, 34247, 9261, 34241, 6303, 2957, 99508, 11734, 34243, 34242, 34245, 34204, 2734, 34246, 34206, 2735, 38008, 34222, 27252, 81306, 81307, 34220, 34564, 82725, 34565, 34673, 70260, 48526, 100500, 34557, 34556, 34551, 34219, 37795, 82816, 34214, 34555, 99139, 99138, 82732, 48528, 48527, 34558, 72174, 34569, 34567, 34842, 86688, 34593, 34841, 34421, 66298, 34568, 34694, 93436, 93435, 93431, 93423, 93421, 93420, 27164, 64304, 24877, 34566, 99513, 34561, 35250, 34562, 36169, 34843, 98009, 35249, 36170, 29968, 25871, 99511, 34266, 99510, 12677, 12676, 12675, 6060, 12673, 12671, 99374, 99509, 4358, 37725, 37723, 34203, 66245, 19217, 34268, 12679, 12672, 22602, 12680, 14612, 28300, 4546, 101484, 99459, 1334, 24806, 34114, 82821, 34109, 4231, 4534, 34111, 51000, 13341, 26741, 34113, 34066, 15322, 99429, 34108, 99457, 1330, 34107, 99428, 9391, 34110, 35538, 94494, 99426, 8572, 4545, 99455, 34049, 34047, 99403, 99427, 99454, 35544, 34046, 34045, 30501, 61026, 34059, 4449, 99461, 87513, 61027, 9392, 91667, 64307, 32936, 38631, 81476, 100158, 100157, 100150, 4368, 10578, 99822, 30108, 7871, 1917, 29599, 33016, 32996, 33014, 25092, 33015, 32997, 32998, 34705, 14575, 342, 35818, 73494, 9739, 1382, 10697, 6873, 1377, 6006, 1383, 82868, 6005, 10696, 10695, 6854, 6843, 4351, 1378, 4612, 4363, 35218, 37088, 39910, 1380, 1379, 1384, 35827, 27700, 2541, 23521, 23519, 11414, 247, 35819, 2328, 1373, 35816, 27690, 20833, 35195, 35194, 35193, 35192, 96910, 43717, 43721, 43718, 96906, 97757, 96915, 98725, 43720, 36545, 46093, 45320, 46986, 96884, 45862, 45319, 43719, 45170, 45864, 47465, 43669, 45863, 39637, 1374, 29496, 29795, 47982, 43724, 44740, 96885, 13843, 1375, 96905, 96903, 72325, 96364, 96916, 96913, 35216, 96914, 43722, 33032, 100444, 14415, 35198, 99385, 15352, 43726, 43725, 32982, 35301, 1333, 1332, 35184, 35187, 35183, 35185, 35186, 42384, 18269, 93637, 101799, 79390, 85697, 2956, 32937, 99821, 99820, 1368, 1366, 10589, 12229, 99823, 34932, 99819, 1372, 35244, 5770, 5769, 99810, 42388, 42387, 1387, 744, 5846, 1388, 1316, 1394, 6839, 99817, 99816, 35241, 1393, 99811, 1386, 99812, 10472, 4384, 901, 32938, 7136, 99813, 1315, 35242, 99818, 99809, 14499, 20545, 99815, 38419, 4386, 33303, 38047, 14616, 14589, 38418, 47231, 38804, 38800, 99814, 1381, 99456, 99808, 39809, 1390, 33701, 35237, 99807, 42386, 15471, 20923, 8001, 9133, 34157, 34155, 5705, 44816, 34156, 34154, 15469, 37020, 31760, 34184, 49781, 1311, 99449, 37437, 30413, 34185, 33700, 42389, 17722, 17719, 17721, 86393, 17720, 1329, 35499, 1328, 99460, 1327, 35500, 2588, 24164, 33698, 99458, 15468, 29396, 31988, 10186, 33699, 83225, 83227, 82819, 82803, 12678, 51098, 1323, 99462, 89800, 34406, 35695, 37724, 29569, 16850, 8000, 89803, 35052, 35140, 40012, 35141, 4382, 21264, 1312, 22493, 35133, 36559, 35051, 24980, 82115, 1319, 14369, 35053, 14370, 4514, 1358, 1314, 34412, 14413, 14414, 37138, 31737, 90315, 35148, 3128, 1392, 21867, 106382, 106345, 36615, 31738, 106383, 99507, 8848, 3609, 3608, 3606, 7137, 3605, 3604, 61024, 61023, 31848, 5205, 24079, 49770, 90246, 5706, 1320, 1313, 4356, 34141, 36585, 36583, 90293, 35504, 90242, 20985, 20988, 90133, 90321, 34143, 34139, 1310, 90301, 42385, 16238, 34144, 82773, 92463, 35498, 51613, 90304, 89937, 90249, 16235, 90366, 86333, 89935, 83765, 36584, 34136, 21342, 21072, 90255, 96314, 86332, 90245, 83764, 90244, 92464, 15467, 32529, 4193, 4594, 240, 4191, 4190, 4192, 92322, 46130, 46126, 8971, 1560, 46131, 99453, 37331, 4601, 99452, 99451, 4260, 37329, 37330, 4259, 37328, 25256, 21856, 21874, 21838, 4366, 19017, 32171, 20546, 29369, 29368, 22750, 22873, 29367, 29366, 2141, 29375, 29371, 29370, 32172, 32173, 24757, 32170, 36598, 2732, 91661, 91660, 91755, 91715, 1987, 21841, 92280, 24860, 1959, 1318, 4515, 46940, 52599, 92190, 91659, 22492, 21878, 21881, 21880, 193, 1206, 7358, 21871, 21866, 4728, 70075, 21857, 22498, 21840, 92051, 91655, 92257, 21873, 22487, 22489, 92218, 21872, 704, 3027, 91723, 92228, 21877, 91584, 92224, 21879, 21875, 21870, 7511, 21839, 91705, 91724, 92055, 22490, 5561, 1986, 171, 22488, 22480, 91712, 21868);
UPDATE `creature_model_info` SET `BoundingRadius`=0.287056982517242431, `CombatReach`=0.375, `VerifiedBuild`=45745 WHERE `DisplayID`=32790;
UPDATE `creature_model_info` SET `BoundingRadius`=0.548862099647521972, `VerifiedBuild`=45745 WHERE `DisplayID`=6807;
UPDATE `creature_model_info` SET `BoundingRadius`=0.973670184612274169, `CombatReach`=2, `VerifiedBuild`=45745 WHERE `DisplayID`=913;
UPDATE `creature_model_info` SET `BoundingRadius`=1.066211581230163574, `CombatReach`=1.392857074737548828, `VerifiedBuild`=45745 WHERE `DisplayID`=999;
UPDATE `creature_model_info` SET `BoundingRadius`=0.219544842839241027, `VerifiedBuild`=45745 WHERE `DisplayID`=10015;
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=45745 WHERE `DisplayID`=21876;

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=153167 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=81921 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=81922 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152775 AND `item`=141209 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152775 AND `item`=169464 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152775 AND `item`=169462 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152775 AND `item`=169463 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=155133 AND `item`=169865 AND `ExtendedCost`=6619 AND `type`=1) OR (`entry`=154980 AND `item`=169466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=154980 AND `item`=169467 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=154980 AND `item`=169468 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=154980 AND `item`=169469 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153008 AND `item`=169466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153008 AND `item`=169467 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153008 AND `item`=169468 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153008 AND `item`=169469 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152948 AND `item`=169527 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152948 AND `item`=128841 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152948 AND `item`=169521 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153012 AND `item`=104344 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153012 AND `item`=104348 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153012 AND `item`=81414 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153012 AND `item`=104343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=24495 AND `item`=187998 AND `ExtendedCost`=5795 AND `type`=1) OR (`entry`=24495 AND `item`=167732 AND `ExtendedCost`=5795 AND `type`=1) OR (`entry`=24495 AND `item`=151615 AND `ExtendedCost`=5795 AND `type`=1) OR (`entry`=24495 AND `item`=122341 AND `ExtendedCost`=5795 AND `type`=1) OR (`entry`=24495 AND `item`=122339 AND `ExtendedCost`=5794 AND `type`=1) OR (`entry`=24495 AND `item`=166747 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=24495 AND `item`=138730 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=24495 AND `item`=116758 AND `ExtendedCost`=2275 AND `type`=1) OR (`entry`=24495 AND `item`=116757 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=24495 AND `item`=116756 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=24495 AND `item`=90427 AND `ExtendedCost`=2275 AND `type`=1) OR (`entry`=24495 AND `item`=90426 AND `ExtendedCost`=2398 AND `type`=1) OR (`entry`=24495 AND `item`=168915 AND `ExtendedCost`=2276 AND `type`=1) OR (`entry`=24495 AND `item`=169461 AND `ExtendedCost`=6597 AND `type`=1) OR (`entry`=24495 AND `item`=169448 AND `ExtendedCost`=6582 AND `type`=1) OR (`entry`=155131 AND `item`=34065 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=155131 AND `item`=33043 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23533 AND `item`=138870 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105704 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105707 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105703 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105706 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105700 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105701 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105711 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105705 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=73914 AND `item`=105702 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152780 AND `item`=166420 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152780 AND `item`=162573 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152780 AND `item`=169458 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152780 AND `item`=169460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=152780 AND `item`=169459 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153116 AND `item`=128841 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=153116 AND `item`=128842 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=24501 AND `item`=138871 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=24501 AND `item`=138868 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23605 AND `item`=81918 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23605 AND `item`=81917 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23605 AND `item`=138884 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23605 AND `item`=138900 AND `ExtendedCost`=2275 AND `type`=1) OR (`entry`=23603 AND `item`=82451 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=82450 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(23533, 5, 138870, 0, 0, 1, 0, 0, 45745), -- Spirit Spirits
(23603, 14, 82451, 0, 0, 1, 0, 0, 45745), -- Frybread
(23603, 13, 82450, 0, 0, 1, 0, 0, 45745), -- Cornmeal Biscuit
(23604, 14, 81921, 0, 0, 1, 0, 0, 45745), -- Chilton Stilton
(23604, 13, 81922, 0, 0, 1, 0, 0, 45745), -- Redridge Roquefort
(23605, 21, 81918, 0, 0, 1, 0, 0, 45745), -- Pickled Pig's Snout
(23605, 20, 81917, 0, 0, 1, 0, 0, 45745), -- Mutton Stew
(23605, 2, 138884, 0, 0, 1, 0, 0, 45745), -- Throwing Sausage
(23605, 1, 138900, 0, 2275, 1, 0, 0, 45745), -- Gravil Goldbraid's Famous Sausage Hat
(24495, 33, 187998, 0, 5795, 1, 0, 0, 45745), -- Eternal Heirloom Scabbard
(24495, 32, 167732, 0, 5795, 1, 0, 0, 45745), -- Battle-Hardened Heirloom Scabbard
(24495, 31, 151615, 0, 5795, 1, 0, 0, 45745), -- Weathered Heirloom Scabbard
(24495, 30, 122341, 0, 5795, 1, 0, 0, 45745), -- Timeworn Heirloom Scabbard
(24495, 29, 122339, 0, 5794, 1, 0, 0, 45745), -- Ancient Heirloom Scabbard
(24495, 28, 166747, 0, 2276, 1, 0, 0, 45745), -- Brewfest Reveler's Hearthstone
(24495, 27, 138730, 0, 2276, 1, 0, 0, 45745), -- Synthebrew Goggles XL
(24495, 25, 116758, 0, 2275, 1, 0, 0, 45745), -- Brewfest Banner
(24495, 24, 116757, 0, 2276, 1, 0, 0, 45745), -- Steamworks Sausage Grill
(24495, 21, 116756, 0, 2276, 1, 0, 0, 45745), -- Stout Alemental
(24495, 16, 90427, 0, 2275, 1, 0, 0, 45745), -- Pandaren Brewpack
(24495, 15, 90426, 0, 2398, 1, 0, 0, 45745), -- Brewhelm
(24495, 11, 168915, 0, 2276, 1, 0, 0, 45745), -- Tabard of Brew
(24495, 10, 169461, 0, 6597, 1, 0, 0, 45745), -- Garland of Grain
(24495, 1, 169448, 0, 6582, 1, 0, 0, 45745), -- Bottomless Brewfest Stein
(24501, 6, 138871, 0, 0, 1, 0, 0, 45745), -- Storming Saison
(24501, 5, 138868, 0, 0, 1, 0, 0, 45745), -- Mannoroth's Blood Red Ale
(73914, 10, 105704, 0, 0, 1, 0, 0, 45745), -- Yan-Zhu's Blazing Brew
(73914, 9, 105707, 0, 0, 1, 0, 0, 45745), -- Unga Brew
(73914, 8, 105703, 0, 0, 1, 0, 0, 45745), -- Stormstout Brew
(73914, 7, 105708, 0, 0, 1, 0, 0, 45745), -- Shimmering Amber-Brew
(73914, 6, 105706, 0, 0, 1, 0, 0, 45745), -- Shado-Pan Brew
(73914, 5, 105700, 0, 0, 1, 0, 0, 45745), -- Kun-Lai Kicker
(73914, 4, 105701, 0, 0, 1, 0, 0, 45745), -- Greenstone Brew
(73914, 3, 105711, 0, 0, 1, 0, 0, 45745), -- Funky Monkey Brew
(73914, 2, 105705, 0, 0, 1, 0, 0, 45745), -- Chani's Bitter Brew
(73914, 1, 105702, 0, 0, 1, 0, 0, 45745), -- Boomer Brew
(152775, 4, 141209, 0, 0, 1, 0, 0, 45745), -- Distilled Nightwine
(152775, 3, 169464, 0, 0, 1, 0, 0, 45745), -- Sparkling Suramar Spritz
(152775, 2, 169462, 0, 0, 1, 0, 0, 45745), -- Boxed Nightwine
(152775, 1, 169463, 0, 0, 1, 0, 0, 45745), -- Nightwine Cooler
(152780, 5, 166420, 0, 0, 1, 0, 0, 45745), -- Xibala Kombucha
(152780, 4, 162573, 0, 0, 1, 0, 0, 45745), -- Amani Mule
(152780, 3, 169458, 0, 0, 1, 0, 0, 45745), -- Vol'dunshine
(152780, 2, 169460, 0, 0, 1, 0, 0, 45745), -- Really Really Really Old Fashioned
(152780, 1, 169459, 0, 0, 1, 0, 0, 45745), -- Saurid Sipper
(152948, 3, 169527, 0, 0, 1, 0, 0, 45745), -- Thunder Stumbler
(152948, 2, 128841, 0, 0, 1, 0, 0, 45745), -- Highmountain Tiswin
(152948, 1, 169521, 0, 0, 1, 0, 0, 45745), -- Butterhoof Milk Stout
(153012, 4, 104344, 0, 0, 1, 0, 0, 45745), -- Lucky Mushroom Noodles
(153012, 3, 104348, 0, 0, 1, 0, 0, 45745), -- Timeless Tea
(153012, 2, 81414, 0, 0, 1, 0, 0, 45745), -- Pearl Milk Tea
(153012, 1, 104343, 0, 0, 1, 0, 0, 45745), -- Golden Dragon Noodles
(153116, 2, 128841, 0, 0, 1, 0, 0, 45745), -- Highmountain Tiswin
(153116, 1, 128842, 0, 0, 1, 0, 0, 45745), -- Tideskorn Mead Ale
(153167, 1, 159, 0, 0, 1, 0, 0, 45745), -- Refreshing Spring Water
(154980, 4, 169466, 0, 0, 1, 0, 0, 45745), -- Everbloom IPA
(154980, 3, 169467, 0, 0, 1, 0, 0, 45745), -- Doomlager
(154980, 2, 169468, 0, 0, 1, 0, 0, 45745), -- Ancestral Ale
(154980, 1, 169469, 0, 0, 1, 0, 0, 45745), -- Mag'helada
(153008, 4, 169466, 0, 0, 1, 0, 0, 45745), -- Everbloom IPA
(153008, 3, 169467, 0, 0, 1, 0, 0, 45745), -- Doomlager
(153008, 2, 169468, 0, 0, 1, 0, 0, 45745), -- Ancestral Ale
(153008, 1, 169469, 0, 0, 1, 0, 0, 45745), -- Mag'helada
(155131, 2, 34065, 0, 0, 1, 0, 0, 45745), -- Spiced Onion Cheese
(155131, 1, 33043, 0, 0, 1, 0, 0, 45745), -- The Essential Brewfest Pretzel
(155133, 1, 169865, 0, 6619, 1, 0, 0, 45745); -- Brewfest Chowdown Trophy

UPDATE `npc_vendor` SET `VerifiedBuild`=45745 WHERE (`entry`=23604 AND `item`=58259 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=58258 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=35952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=33443 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23604 AND `item`=34065 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23533 AND `item`=46401 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23533 AND `item`=34022 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23533 AND `item`=34021 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23533 AND `item`=34020 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=24501 AND `item`=46402 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=24501 AND `item`=34019 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=24501 AND `item`=34018 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=24501 AND `item`=34017 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=58261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=58260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=35950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23603 AND `item`=33043 AND `ExtendedCost`=0 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=58269 AND `ExtendedCost`=0 AND `type`=1); -- Massive Turkey Leg
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=58268 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Beef
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=35953 AND `ExtendedCost`=0 AND `type`=1); -- Mead Basted Caribou
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=33454 AND `ExtendedCost`=0 AND `type`=1); -- Salted Venison
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=33026 AND `ExtendedCost`=0 AND `type`=1); -- The Golden Link
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=33025 AND `ExtendedCost`=0 AND `type`=1); -- Spicy Smoked Sausage
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=33024 AND `ExtendedCost`=0 AND `type`=1); -- Pickled Sausage
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=33023 AND `ExtendedCost`=0 AND `type`=1); -- Savory Sausage
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=34064 AND `ExtendedCost`=0 AND `type`=1); -- Succulent Sausage
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=23605 AND `item`=34063 AND `ExtendedCost`=0 AND `type`=1); -- Dried Sausage
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=37816 AND `ExtendedCost`=2399 AND `type`=1); -- Preserved Brewfest Hops
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=37750 AND `ExtendedCost`=2398 AND `type`=1); -- Fresh Brewfest Hops
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=32233 AND `ExtendedCost`=2276 AND `type`=1); -- Wolpertinger's Tankard
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=46707 AND `ExtendedCost`=2275 AND `type`=1); -- Pint-Sized Pink Pachyderm
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=33927 AND `ExtendedCost`=2275 AND `type`=1); -- Brewfest Pony Keg
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=71137 AND `ExtendedCost`=2276 AND `type`=1); -- Brewfest Keg Pony
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=39477 AND `ExtendedCost`=2424 AND `type`=1); -- Fresh Dwarven Brewfest Hops
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=34008 AND `ExtendedCost`=2275 AND `type`=1); -- Blix's Eyesight Enhancing Romance Goggles
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=37599 AND `ExtendedCost`=2276 AND `type`=1); -- "Brew of the Month" Club Membership Form
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=33868 AND `ExtendedCost`=2275 AND `type`=1); -- Brewfest Boots
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=33862 AND `ExtendedCost`=2276 AND `type`=1); -- Brewfest Regalia
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=33966 AND `ExtendedCost`=2275 AND `type`=1); -- Brewfest Slippers
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=33863 AND `ExtendedCost`=2276 AND `type`=1); -- Brewfest Dress
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=33969 AND `ExtendedCost`=2274 AND `type`=1); -- Purple Brewfest Hat
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=33967 AND `ExtendedCost`=2274 AND `type`=1); -- Green Brewfest Hat
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=33864 AND `ExtendedCost`=2274 AND `type`=1); -- Brown Brewfest Hat
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=45745 WHERE (`entry`=24495 AND `item`=33968 AND `ExtendedCost`=2274 AND `type`=1); -- Blue Brewfest Hat

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=298, `VerifiedBuild`=45745 WHERE `entry`=186186; -- Drohn's Distillery Festive Keg
UPDATE `gameobject_template` SET `ContentTuningId`=298, `VerifiedBuild`=45745 WHERE `entry`=186187; -- T'chali's Voodoo Brew Festive Keg
UPDATE `gameobject_template` SET `ContentTuningId`=334, `VerifiedBuild`=45745 WHERE `entry` IN (250563, 250564); -- Baskets
UPDATE `gameobject_template` SET `ContentTuningId`=334, `VerifiedBuild`=45745 WHERE `entry`=250566; -- Hides

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (252967, 265545, 279239, 279243, 325994, 325998, 326067, 326077, 326104);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(252967, 1375, 8192, 0, 0), -- Nightborne Goods
(265545, 0, 8192, 0, 0), -- Frostwolf Banner
(279239, 114, 0, 0, 0), -- [DNT] Crate
(279243, 114, 0, 0, 0), -- [DNT] Basket
(325994, 0, 32, 0, 0), -- Nightborne Arcwine Tent
(325998, 0, 32, 0, 0), -- Zandalari Tent
(326067, 0, 32, 0, 0), -- Highmountain Tent
(326077, 0, 32, 0, 0), -- Ogre Tent
(326104, 0, 32, 0, 0); -- Frostwolf Tent

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (134901, 134902, 134903, 134904);
DELETE FROM `creature` WHERE `guid` BETWEEN 361880 AND 361948;
DELETE FROM `creature` WHERE `guid` BETWEEN 361975 AND 361992;
DELETE FROM `game_event_creature` WHERE `guid` IN (134901, 134902, 134903, 134904);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 361880 AND 361948;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 361975 AND 361992;
DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid` BETWEEN 361993 AND 362042; -- Hallow's End incorrectly assigned to Brewfest

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+112;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Orgrimmar
(@CGUID+0, 19175, 1, 1637, 5170, '0', 0, 0, 0, 0, 1616.7708740234375, -4402.65625, 15.6053314208984375, 3.333578824996948242, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Orc Commoner (Area: Valley of Strength - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+1, 19175, 1, 1637, 5170, '0', 0, 0, 0, 0, 1614.998291015625, -4402.95166015625, 15.43872261047363281, 0.157079637050628662, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Orc Commoner (Area: Valley of Strength - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget; 33208 - Gossip NPC Periodic - Talk)
(@CGUID+2, 19175, 1, 1637, 5168, '0', 0, 0, 0, 0, 1913.703125, -4721.34033203125, 36.20418167114257812, 3.543018341064453125, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Orc Commoner (Area: Valley of Honor - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+3, 19175, 1, 1637, 5168, '0', 0, 0, 0, 0, 1912.15283203125, -4721.97412109375, 36.272613525390625, 0.366519153118133544, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Orc Commoner (Area: Valley of Honor - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+4, 19177, 1, 1637, 5170, '0', 0, 0, 0, 0, 1773.5225830078125, -4360.0869140625, 102.4606094360351562, 1.29154360294342041, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Troll Commoner (Area: Valley of Strength - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+5, 19177, 1, 1637, 5170, '0', 0, 0, 0, 0, 1774.470458984375, -4356.31591796875, 102.4248123168945312, 4.485496044158935546, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Troll Commoner (Area: Valley of Strength - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+6, 19176, 1, 1637, 5171, '0', 0, 0, 0, 0, 1920.2222900390625, -4208.2099609375, 37.35242462158203125, 2.530727386474609375, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Tauren Commoner (Area: Valley of Wisdom - Difficulty: 0)
(@CGUID+7, 19176, 1, 1637, 5171, '0', 0, 0, 0, 0, 1917.8507080078125, -4206.5712890625, 37.436767578125, 5.672319889068603515, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Tauren Commoner (Area: Valley of Wisdom - Difficulty: 0)
(@CGUID+8, 19177, 1, 1637, 5170, '0', 0, 0, 0, 0, 1581.74658203125, -4194.71728515625, 53.84771728515625, 3.655785560607910156, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Troll Commoner (Area: Valley of Strength - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+9, 19176, 1, 1637, 5170, '0', 0, 0, 0, 0, 1579.4375, -4195.90283203125, 53.75600051879882812, 0.528533637523651123, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Tauren Commoner (Area: Valley of Strength - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+10, 19177, 1, 1637, 5169, '0', 0, 0, 0, 0, 1724.2603759765625, -4067.032958984375, 49.31903839111328125, 3.769911050796508789, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Troll Commoner (Area: Valley of Spirits - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+11, 19177, 1, 1637, 5169, '0', 0, 0, 0, 0, 1722.670166015625, -4068.328125, 49.186065673828125, 0.715584993362426757, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Troll Commoner (Area: Valley of Spirits - Difficulty: 0) (Auras: 65511 - Gossip NPC Appearance - Brewfest, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+12, 40437, 1, 1637, 5170, '0', 0, 0, 0, 0, 1571.1510009765625, -4383.47412109375, 16.42013931274414062, 4.677482128143310546, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Battered Brewer (Area: Valley of Strength - Difficulty: 0)
(@CGUID+13, 155345, 1, 14, 1296, '0', 0, 0, 0, 0, 1367.26220703125, -4340.767578125, 28.69970512390136718, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- [DNT] Brewfest Music (Area: Rocktusk Farm - Difficulty: 0)
(@CGUID+14, 155034, 1, 14, 1296, '0', 0, 0, 0, 1, 1364.9461669921875, -4342.8349609375, 28.63378524780273437, 0.518876433372497558, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Rocktusk Farm - Difficulty: 0) (Auras: 300452 - [DNT] Brewfest Reveler)
(@CGUID+15, 155034, 1, 14, 1296, '0', 0, 0, 0, 4, 1367.94970703125, -4341.93212890625, 28.61717796325683593, 2.833275318145751953, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Rocktusk Farm - Difficulty: 0) (Auras: 300456 - [DNT] Brewfest Reveler)
(@CGUID+16, 155034, 1, 14, 1296, '0', 0, 0, 0, 3, 1366.095458984375, -4340.0400390625, 28.63378524780273437, 4.830263137817382812, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Rocktusk Farm - Difficulty: 0) (Auras: 300456 - [DNT] Brewfest Reveler)
(@CGUID+17, 155034, 1, 14, 1296, '0', 0, 0, 0, 5, 1357.484375, -4339.142578125, 27.25878524780273437, 5.621531486511230468, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Rocktusk Farm - Difficulty: 0) (Auras: 300453 - [DNT] Brewfest Reveler)
(@CGUID+18, 155034, 1, 14, 1296, '0', 0, 0, 0, 6, 1359.3785400390625, -4341.11865234375, 27.61812782287597656, 2.420148611068725585, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Rocktusk Farm - Difficulty: 0) (Auras: 300452 - [DNT] Brewfest Reveler)
-- Brewfest area
(@CGUID+19, 23488, 1, 14, 14, '0', 0, 0, 0, 0, 1229.4583740234375, -4090.0244140625, 23.11458396911621093, 3.124139308929443359, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Crowd (Area: Durotar - Difficulty: 0)
(@CGUID+20, 23511, 1, 14, 14, '0', 0, 0, 0, 0, 1215.63720703125, -4125.736328125, 23.97222328186035156, 2.565046548843383789, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gordok Brew Apprentice (Area: Durotar - Difficulty: 0)
(@CGUID+21, 23533, 1, 14, 14, '0', 0, 0, 0, 0, 1213.4114990234375, -4094.145751953125, 21.94293022155761718, 3.717269420623779296, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- T'chali's Voodoo Brewery Apprentice (Area: Durotar - Difficulty: 0)
(@CGUID+22, 23603, 1, 14, 14, '0', 0, 0, 0, 1, 1178.4444580078125, -4168.548828125, 22.13372802734375, 1.408244967460632324, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Uta Roughdough (Area: Durotar - Difficulty: 0)
(@CGUID+23, 23604, 1, 14, 14, '0', 0, 0, 0, 0, 1158.3472900390625, -4132.17724609375, 21.3791046142578125, 6.157011985778808593, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Agnes Farwithers (Area: Durotar - Difficulty: 0)
(@CGUID+24, 23605, 1, 14, 14, '0', 0, 0, 0, 1, 1180.720458984375, -4168.66162109375, 21.7808380126953125, 1.828440666198730468, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Bron (Area: Durotar - Difficulty: 0)
(@CGUID+25, 23685, 1, 14, 14, '0', 0, 0, 0, 1, 1212.376708984375, -4127.4130859375, 23.54305839538574218, 2.525485754013061523, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gordok Brew Barker (Area: Durotar - Difficulty: 0)
(@CGUID+26, 23696, 1, 14, 14, '0', 0, 0, 0, 0, 1216.7413330078125, -4122.8818359375, 24.1805572509765625, 2.819426774978637695, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gordok Brew Chief (Area: Durotar - Difficulty: 0)
(@CGUID+27, 23706, 1, 14, 14, '0', 0, 0, 0, 0, 1159.52783203125, -4147.73291015625, 21.43576431274414062, 4.764749050140380859, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Gordok Festive Keg (Area: Durotar - Difficulty: 0)
(@CGUID+28, 24108, 1, 14, 14, '0', 0, 0, 0, 0, 1200, -4175, 23.03881, 0, 120, 5, 0, 11791, 0, 1, 0, 0, 0, 45745), -- Self-Turning and Oscillating Utility Target (Area: Durotar - Difficulty: 0)
(@CGUID+29, 24372, 1, 14, 14, '0', 0, 0, 0, 0, 1167.4305419921875, -4110.26025390625, 19.70313453674316406, 5.969262599945068359, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Drohn's Distillery Festive Keg (Area: Durotar - Difficulty: 0)
(@CGUID+30, 24373, 1, 14, 14, '0', 0, 0, 0, 0, 1205.8697509765625, -4086.998291015625, 20.775665283203125, 2.460632562637329101, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- T'chali's Voodoo Brew Festive Keg (Area: Durotar - Difficulty: 0)
(@CGUID+31, 24462, 1, 14, 14, '0', 0, 0, 0, 0, 1166.37353515625, -4229.322265625, 22.00942802429199218, 3.157378435134887695, 120, 3, 0, 11791, 2434, 1, 0, 0, 0, 45745), -- Racing Ram (Area: Durotar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+32, 24463, 1, 14, 14, '0', 0, 0, 0, 0, 1175.72509765625, -4230.49072265625, 23.1514129638671875, 4.364664554595947265, 120, 3, 0, 11791, 2434, 1, 0, 0, 0, 45745), -- Swift Racing Ram (Area: Durotar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+33, 24495, 1, 14, 14, '0', 0, 0, 0, 0, 1210.576416015625, -4133.68408203125, 23.2743072509765625, 3.319325685501098632, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Blix Fixwidget (Area: Durotar - Difficulty: 0)
(@CGUID+34, 24497, 1, 14, 14, '0', 0, 0, 0, 0, 1179.486083984375, -4216.001953125, 23.89583396911621093, 0.994837641716003417, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Ram Master Ray (Area: Durotar - Difficulty: 0)
(@CGUID+35, 24498, 1, 14, 14, '0', 0, 0, 0, 0, 1162.9322509765625, -4104.0849609375, 18.73113822937011718, 5.782631397247314453, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Cort Gorestein (Area: Durotar - Difficulty: 0)
(@CGUID+36, 24499, 1, 14, 14, '0', 0, 0, 0, 0, 1211.670166015625, -4091.069580078125, 21.57013511657714843, 4.031428813934326171, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Ja'ron (Area: Durotar - Difficulty: 0)
(@CGUID+37, 24766, 1, 14, 14, '0', 0, 0, 0, 0, 1191.486083984375, -4135.0068359375, 22.05243492126464843, 6.161012172698974609, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- [DND] Brewfest Face Me Bunny (Area: Durotar - Difficulty: 0)
(@CGUID+38, 24766, 1, 14, 14, '0', 0, 0, 0, 0, 1207.18408203125, -4227.68408203125, 22.99848365783691406, 3.246312379837036132, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- [DND] Brewfest Face Me Bunny (Area: Durotar - Difficulty: 0)
(@CGUID+39, 24501, 1, 14, 14, '0', 0, 0, 0, 0, 1163.9288330078125, -4100.04541015625, 18.36631965637207031, 5.81893777847290039, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Drohn's Distillery Apprentice (Area: Durotar - Difficulty: 0)
(@CGUID+40, 24510, 1, 14, 14, '0', 0, 0, 0, 1, 1183.782958984375, -4219.56787109375, 24.22222328186035156, 1.082104086875915527, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Driz Tumblequick (Area: Durotar - Difficulty: 0) (Auras: 44068 - Base Camp Mark)
(@CGUID+41, 27216, 1, 14, 14, '0', 0, 0, 0, 0, 1190.5069580078125, -4163.85400390625, 21.78594970703125, 2.420037269592285156, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Bizzle Quicklift (Area: Durotar - Difficulty: 0)
(@CGUID+42, 27707, 1, 14, 14, '0', 0, 0, 0, 0, 1170.9761962890625, -4233.14892578125, 22.5858612060546875, 0.565559566020965576, 120, 3, 0, 11791, 0, 1, 0, 0, 0, 45745), -- Great Brewfest Kodo (Area: Durotar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+43, 73914, 1, 14, 14, '0', 0, 0, 0, 1, 1199.5555419921875, -4152.57275390625, 21.80753135681152343, 2.48207259178161621, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewmaster Tao (Area: Durotar - Difficulty: 0)
(@CGUID+44, 152643, 1, 14, 14, '0', 0, 0, 0, 0, 1159.21875, -4202.88720703125, 22.9639739990234375, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Despawn Bunny (Area: Durotar - Difficulty: 0) (Auras: 182641 - Game Object Despawn Periodic)
(@CGUID+45, 152775, 1, 14, 14, '0', 0, 0, 0, 0, 1176.8697509765625, -4092.59375, 18.10720062255859375, 5.319868087768554687, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Vinter Mollyleux (Area: Durotar - Difficulty: 0) (Auras: 216450 - Serving Platter Female)
(@CGUID+46, 152780, 1, 14, 14, '0', 0, 0, 0, 0, 1161.1441650390625, -4119.9931640625, 21.171875, 6.127427577972412109, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Zenda (Area: Durotar - Difficulty: 0)
(@CGUID+47, 152948, 1, 14, 14, '0', 0, 0, 0, 0, 1218.05908203125, -4110.359375, 23.76736259460449218, 3.144051790237426757, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Ha'ka Openview (Area: Durotar - Difficulty: 0)
(@CGUID+48, 153008, 1, 14, 14, '0', 0, 0, 0, 0, 1192.59375, -4087.4775390625, 19.0246734619140625, 4.570484161376953125, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Kaara (Area: Durotar - Difficulty: 0)
(@CGUID+49, 153009, 1, 14, 14, '0', 0, 0, 0, 0, 1191.5677490234375, -4084.944580078125, 18.80224227905273437, 4.477460861206054687, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Ikura (Area: Durotar - Difficulty: 0)
(@CGUID+50, 153012, 1, 14, 14, '0', 0, 0, 0, 0, 1137.951416015625, -4172.126953125, 20.87484169006347656, 0.359767496585845947, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Aichi (Area: Durotar - Difficulty: 0)
(@CGUID+51, 153014, 1, 14, 14, '0', 0, 0, 0, 0, 1135.4461669921875, -4174.00341796875, 21.45240020751953125, 4.969699859619140625, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Lucky Nuru (Area: Durotar - Difficulty: 0)
(@CGUID+52, 153070, 1, 14, 14, '0', 0, 0, 0, 1, 1240.1754150390625, -4153.91650390625, 26.43368721008300781, 5.854429244995117187, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+53, 153070, 1, 14, 14, '0', 0, 0, 0, 1, 1216.765625, -4144.298828125, 23.24872779846191406, 5.604043006896972656, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+54, 153070, 1, 14, 14, '0', 0, 0, 0, 2, 1196.41845703125, -4151.65478515625, 21.82093238830566406, 5.830943107604980468, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+55, 153071, 1, 14, 14, '0', 0, 0, 0, 1, 1231.6510009765625, -4151.6005859375, 25.28311347961425781, 5.774788856506347656, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+56, 153072, 1, 14, 14, '0', 0, 0, 0, 1, 1226.0694580078125, -4149.142578125, 24.28403663635253906, 5.69806671142578125, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+57, 153073, 1, 14, 14, '0', 0, 0, 0, 0, 1220.079833984375, -4145.85791015625, 23.592987060546875, 2.385058403015136718, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+58, 153074, 1, 14, 14, '0', 0, 0, 0, 3, 1237.9097900390625, -4152.7431640625, 26.28298759460449218, 3.123387336730957031, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+59, 153074, 1, 14, 14, '0', 0, 0, 0, 2, 1208.7135009765625, -4092.265625, 21.26233291625976562, 3.925227880477905273, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+60, 153075, 1, 14, 14, '0', 0, 0, 0, 2, 1163.7899169921875, -4118.876953125, 20.7342071533203125, 2.956824541091918945, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+61, 153075, 1, 14, 14, '0', 0, 0, 0, 1, 1223.4722900390625, -4147.55224609375, 23.96996116638183593, 5.768915176391601562, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+62, 153082, 1, 14, 14, '0', 0, 0, 0, 7, 1234.68408203125, -4152.86279296875, 25.76388931274414062, 0.084523409605026245, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+63, 153105, 1, 14, 14, '0', 0, 0, 0, 1, 1228.84375, -4150.2744140625, 24.77285957336425781, 5.672098636627197265, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+64, 153116, 1, 14, 14, '0', 0, 0, 0, 0, 1200.486083984375, -4148.21533203125, 22.01844978332519531, 3.142458200454711914, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Jun Soo (Area: Durotar - Difficulty: 0) (Auras: 297197 - Barserver)
(@CGUID+65, 153167, 1, 14, 14, '0', 0, 0, 0, 0, 1230.105, -4148.242, 25.01845, 0, 120, 0, 0, 11791, 0, 2, 0, 0, 0, 45745), -- Hydratius (Area: Durotar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+66, 154078, 1, 14, 14, '0', 0, 0, 0, 0, 1186.2760009765625, -4132.1787109375, 21.81571197509765625, 1.419320464134216308, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Crowd (Area: Durotar - Difficulty: 0)
(@CGUID+67, 154086, 1, 14, 14, '0', 0, 0, 0, 0, 1193.1510009765625, -4120.44775390625, 24.31232643127441406, 2.3516845703125, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Keg Tap (Area: Durotar - Difficulty: 0) (Auras: )
(@CGUID+68, 154299, 1, 14, 14, '0', 0, 0, 0, 1, 1212.6649169921875, -4098.9375, 22.237335205078125, 3.75217604637145996, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- T'chali's Voodoo Brewery Barker (Area: Durotar - Difficulty: 0)
(@CGUID+69, 154313, 1, 14, 14, '0', 0, 0, 0, 1, 1169.296875, -4100.111328125, 18.52376556396484375, 5.7142181396484375, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Drohn's Distillery Barker (Area: Durotar - Difficulty: 0)
(@CGUID+70, 154477, 1, 14, 14, '0', 0, 0, 0, 0, 1191.5972900390625, -4120.38525390625, 34.79286956787109375, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Event Controller (Area: Durotar - Difficulty: 0)
(@CGUID+71, 154980, 1, 14, 14, '0', 0, 0, 0, 0, 1199.251708984375, -4086.18408203125, 19.803985595703125, 4.58296060562133789, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Kyl'kahn (Area: Durotar - Difficulty: 0)
(@CGUID+72, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1176.357666015625, -4155.73779296875, 21.78881072998046875, 4.830263137817382812, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300461 - [DNT] Brewfest Reveler)
(@CGUID+73, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1175.2083740234375, -4158.533203125, 21.78881072998046875, 0.518876433372497558, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300458 - [DNT] Brewfest Reveler)
(@CGUID+74, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1189.579833984375, -4152.11474609375, 21.53881072998046875, 4.170112133026123046, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300454 - [DNT] Brewfest Reveler)
(@CGUID+75, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1176.782958984375, -4127.126953125, 21.14876556396484375, 0.234249517321586608, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+76, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1201.8524169921875, -4106.46337890625, 21.41598320007324218, 5.621531486511230468, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300459 - [DNT] Brewfest Reveler)
(@CGUID+77, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1186.705810546875, -4098.537109375, 19.08099746704101562, 4.591934680938720703, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300454 - [DNT] Brewfest Reveler)
(@CGUID+78, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1168.15283203125, -4131.65478515625, 21.39876556396484375, 1.549370646476745605, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+79, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1188.376708984375, -4134.53466796875, 21.83153533935546875, 4.591934680938720703, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300455 - [DNT] Brewfest Reveler)
(@CGUID+80, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1185.2847900390625, -4100.5400390625, 19.27376556396484375, 0.30574047565460205, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300455 - [DNT] Brewfest Reveler)
(@CGUID+81, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1180.6788330078125, -4110.05908203125, 20.03719329833984375, 5.621531486511230468, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300452 - [DNT] Brewfest Reveler)
(@CGUID+82, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1203.328125, -4107.92724609375, 21.76888847351074218, 2.420148611068725585, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300454 - [DNT] Brewfest Reveler)
(@CGUID+83, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1182.8524169921875, -4113.09375, 20.53731536865234375, 2.420148611068725585, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300455 - [DNT] Brewfest Reveler)
(@CGUID+84, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1210.126708984375, -4115.93212890625, 23.29513359069824218, 5.463227748870849609, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300457 - [DNT] Brewfest Reveler)
(@CGUID+85, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1178.2117919921875, -4157.63037109375, 21.78881072998046875, 2.833275318145751953, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300457 - [DNT] Brewfest Reveler)
(@CGUID+86, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1210.3194580078125, -4119.47216796875, 23.46883964538574218, 1.151840567588806152, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300452 - [DNT] Brewfest Reveler)
(@CGUID+87, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1187.8958740234375, -4154.73291015625, 21.53881072998046875, 1.088313579559326171, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300456 - [DNT] Brewfest Reveler)
(@CGUID+88, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1179.63720703125, -4127.876953125, 21.27376556396484375, 2.428172826766967773, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+89, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1178.375, -4124.814453125, 21.02376556396484375, 4.520446300506591796, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+90, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1168.4930419921875, -4128.56787109375, 21.26448822021484375, 4.631168365478515625, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+91, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1199.8177490234375, -4126.81591796875, 22.89876556396484375, 4.586582660675048828, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+92, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1199.3004150390625, -4128.82666015625, 22.75203704833984375, 1.385201692581176757, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+93, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1188.24658203125, -4101.158203125, 19.47518157958984375, 2.277539014816284179, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300457 - [DNT] Brewfest Reveler)
(@CGUID+94, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1186.85595703125, -4136.7119140625, 21.78881072998046875, 0.30574047565460205, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300459 - [DNT] Brewfest Reveler)
(@CGUID+95, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1190.01220703125, -4137.5849609375, 21.96630096435546875, 2.277539014816284179, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0)
(@CGUID+96, 155034, 1, 14, 14, '0', 0, 0, 0, 0, 1212.7413330078125, -4116.361328125, 23.78536796569824218, 3.466239213943481445, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Brewfest Reveler (Area: Durotar - Difficulty: 0) (Auras: 300453 - [DNT] Brewfest Reveler)
(@CGUID+97, 155131, 1, 14, 14, '0', 0, 0, 0, 0, 1170.089, -4159.592, 21.87743, 0, 120, 0, 0, 11791, 0, 2, 0, 0, 0, 45745), -- Zipsi Switchcrank (Area: Durotar - Difficulty: 0) (Auras: 301745 - Serving Platter) (possible waypoints or random movement)
(@CGUID+98, 155133, 1, 14, 14, '0', 0, 0, 0, 0, 1158.3038330078125, -4198.1787109375, 22.92135047912597656, 0.469425290822982788, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Etga (Area: Durotar - Difficulty: 0) (Auras: 300158 - [DNT] Chowdown Organizer)
(@CGUID+99, 155134, 1, 14, 14, '0', 0, 0, 0, 0, 1161.1910400390625, -4201.44970703125, 22.78371238708496093, 0.948976457118988037, 120, 0, 0, 11791, 100, 0, 0, 0, 0, 45745), -- Chowdown Participant's Seat (Area: Durotar - Difficulty: 0) (Auras: 297978 - [DNT] Seat Preparation)
(@CGUID+100, 155134, 1, 14, 14, '0', 0, 0, 0, 0, 1162.170166015625, -4202.15087890625, 22.73781776428222656, 0.87310725450515747, 120, 0, 0, 11791, 100, 0, 0, 0, 0, 45745), -- Chowdown Participant's Seat (Area: Durotar - Difficulty: 0) (Auras: 297978 - [DNT] Seat Preparation)
(@CGUID+101, 155134, 1, 14, 14, '0', 0, 0, 0, 0, 1158.998291015625, -4199.61474609375, 22.81603431701660156, 0.875549912452697753, 120, 0, 0, 11791, 100, 0, 0, 0, 0, 45745), -- Chowdown Participant's Seat (Area: Durotar - Difficulty: 0) (Auras: 297978 - [DNT] Seat Preparation)
(@CGUID+102, 155134, 1, 14, 14, '0', 0, 0, 0, 0, 1159.9791259765625, -4200.56103515625, 22.79554557800292968, 0.902219831943511962, 120, 0, 0, 11791, 100, 0, 0, 0, 0, 45745), -- Chowdown Participant's Seat (Area: Durotar - Difficulty: 0) (Auras: 297978 - [DNT] Seat Preparation)
(@CGUID+103, 155194, 1, 14, 14, '0', 0, 0, 0, 0, 1160.49658203125, -4159.39599609375, 21.83278465270996093, 3.757717132568359375, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- La'gar Brewshout (Area: Durotar - Difficulty: 0)
(@CGUID+104, 155269, 1, 14, 14, '0', 0, 0, 0, 1, 1156.7882080078125, -4144.97216796875, 21.34722328186035156, 0.396518051624298095, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Snipehunter Goro (Area: Durotar - Difficulty: 0)
(@CGUID+105, 155280, 1, 14, 14, '0', 0, 0, 0, 0, 1155.298583984375, -4141.97900390625, 21.32192420959472656, 5.610020160675048828, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Azu (Area: Durotar - Difficulty: 0)
(@CGUID+106, 155303, 1, 14, 14, '0', 0, 0, 0, 0, 1210.642333984375, -4326.0244140625, 21.27673721313476562, 2.39110112190246582, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Apple Bucket (Area: Durotar - Difficulty: 0) (Auras: 302192 - Apple Bucket)
(@CGUID+107, 155303, 1, 14, 14, '0', 0, 0, 0, 0, 1306.1944580078125, -4284.8525390625, 25.79408645629882812, 5.148721218109130859, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Apple Bucket (Area: Durotar - Difficulty: 0) (Auras: 302192 - Apple Bucket)
(@CGUID+108, 155303, 1, 14, 14, '0', 0, 0, 0, 0, 1177.829833984375, -4236.8525390625, 23.70227241516113281, 1.082104086875915527, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Apple Bucket (Area: Durotar - Difficulty: 0) (Auras: 302192 - Apple Bucket)
(@CGUID+109, 155303, 1, 14, 1296, '0', 0, 0, 0, 0, 1327.1632080078125, -4557.8056640625, 26.40106010437011718, 6.038839340209960937, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Apple Bucket (Area: 0 - Difficulty: 0)
(@CGUID+110, 155303, 1, 14, 4982, '0', 0, 0, 0, 0, 1317.0833740234375, -4650.15625, 21.91450119018554687, 5.148721218109130859, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Apple Bucket (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@CGUID+111, 155320, 1, 14, 4982, '0', 0, 0, 0, 0, 1333.298583984375, -4637.97216796875, 24.31587409973144531, 1.205543756484985351, 120, 0, 0, 12381, 0, 0, 0, 0, 0, 45745), -- Brewmaster Pijiu (Area: The Dranosh'ar Blockade - Difficulty: 0) (Auras: 44067 - Supplier Mark)
(@CGUID+112, 155345, 1, 14, 14, '0', 0, 0, 0, 0, 1189, -4122.65283203125, 27.37759780883789062, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745); -- [DNT] Brewfest Music (Area: Durotar - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+35, @CGUID+49, @CGUID+59, @CGUID+60, @CGUID+65, @CGUID+97, @CGUID+105);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+35, 0, 0, 0, 1, 886, 0, 0, 0, 0, ''), -- 24498 (Cort Gorestein)
(@CGUID+49, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 153009 (Ikura)
(@CGUID+59, 0, 0, 0, 257, 876, 0, 0, 0, 0, ''), -- 153074 (Brewfest Reveler)
(@CGUID+60, 0, 0, 0, 257, 876, 0, 0, 0, 0, ''), -- 153075 (Brewfest Reveler)
(@CGUID+65, (@CGUID+65)*10, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 153167 (Hydratius)
(@CGUID+97, (@CGUID+97)*10, 0, 0, 1, 0, 0, 0, 0, 0, '301745'), -- 155131 (Zipsi Switchcrank)
(@CGUID+105, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''); -- 155280 (Azu)

DELETE FROM `waypoint_data` WHERE `id` IN ((@CGUID+65)*10, (@CGUID+97)*10);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
((@CGUID+65)*10, 0, 1230.105, -4148.242, 25.01845, NULL, 0),
((@CGUID+65)*10, 1, 1227.957, -4146.755, 24.76247, NULL, 0),
((@CGUID+65)*10, 2, 1219.97, -4143.997, 23.63539, NULL, 0),
((@CGUID+65)*10, 3, 1212.345, -4140.24, 22.87709, NULL, 0),
((@CGUID+65)*10, 4, 1206.528, -4131.109, 23.2474, NULL, 0),
((@CGUID+65)*10, 5, 1201.875, -4124.385, 23.08053, NULL, 0),
((@CGUID+65)*10, 6, 1201.363, -4115.306, 22.44247, NULL, 0),
((@CGUID+65)*10, 7, 1206.809, -4110.424, 22.48605, NULL, 0),
((@CGUID+65)*10, 8, 1207.439, -4105.983, 22.15378, NULL, 0),
((@CGUID+65)*10, 9, 1206.285, -4099.927, 21.46573, NULL, 0),
((@CGUID+65)*10,10, 1200.125, -4098.143, 20.38712, NULL, 0),
((@CGUID+65)*10,11, 1197.417, -4097.176, 19.9509, NULL, 0),
((@CGUID+65)*10,12, 1194.649, -4093.417, 19.39377, NULL, 0),
((@CGUID+65)*10,13, 1184.311, -4092.384, 18.40439, NULL, 0),
((@CGUID+65)*10,14, 1178.108, -4100.158, 18.79073, NULL, 0),
((@CGUID+65)*10,15, 1174.429, -4105.071, 19.1888, NULL, 0),
((@CGUID+65)*10,16, 1170.266, -4114.856, 20.24398, NULL, 0),
((@CGUID+65)*10,17, 1170.295, -4118.288, 20.53085, NULL, 0),
((@CGUID+65)*10,18, 1170.927, -4124.158, 20.89877, NULL, 0),
((@CGUID+65)*10,19, 1171.629, -4129.851, 21.2933, NULL, 0),
((@CGUID+65)*10,20, 1164.443, -4140.469, 21.50074, NULL, 0),
((@CGUID+65)*10,21, 1162.399, -4147.304, 21.50074, NULL, 0),
((@CGUID+65)*10,22, 1165.495, -4151.363, 21.52369, NULL, 0),
((@CGUID+65)*10,23, 1170.347, -4152.16, 21.78881, NULL, 0),
((@CGUID+65)*10,24, 1176.149, -4153.429, 21.66381, NULL, 0),
((@CGUID+65)*10,25, 1179.656, -4155.997, 21.66381, NULL, 0),
((@CGUID+65)*10,26, 1182.898, -4154.781, 21.66381, NULL, 0),
((@CGUID+65)*10,27, 1188.462, -4147.853, 21.60888, NULL, 0),
((@CGUID+65)*10,28, 1195.363, -4143.415, 21.89135, NULL, 0),
((@CGUID+65)*10,29, 1205.549, -4141.537, 22.49684, NULL, 0),
((@CGUID+65)*10,30, 1217.363, -4146.057, 23.16457, NULL, 0),
((@CGUID+65)*10,31, 1225.363, -4150.702, 24.2278, NULL, 0),
((@CGUID+65)*10,32, 1231.686, -4154.181, 25.12294, NULL, 0),
((@CGUID+65)*10,33, 1238.47, -4157.247, 26.10553, NULL, 0),
((@CGUID+65)*10,34, 1242.597, -4151.847, 26.76739, NULL, 0),
((@CGUID+97)*10, 0, 1170.089, -4159.592, 21.87743, NULL, 0),
((@CGUID+97)*10, 1, 1176.951, -4162.259, 21.9475, NULL, 0),
((@CGUID+97)*10, 2, 1183.174, -4158.271, 21.66381, NULL, 0),
((@CGUID+97)*10, 3, 1186.161, -4153.375, 21.53881, NULL, 0),
((@CGUID+97)*10, 4, 1191.946, -4144.971, 21.78881, NULL, 0),
((@CGUID+97)*10, 5, 1193.736, -4137.021, 22.03368, NULL, 0),
((@CGUID+97)*10, 6, 1198.467, -4131.066, 22.73324, NULL, 0),
((@CGUID+97)*10, 7, 1204.021, -4123.304, 23.16806, NULL, 0),
((@CGUID+97)*10, 8, 1208.387, -4113.538, 22.98703, NULL, 0),
((@CGUID+97)*10, 9, 1204.365, -4103.955, 21.37924, NULL, 0),
((@CGUID+97)*10,10, 1200.323, -4098.753, 20.48441, NULL, 0),
((@CGUID+97)*10,11, 1194.639, -4093.148, 19.36033, NULL, 0),
((@CGUID+97)*10,12, 1188.694, -4092.564, 18.70188, NULL, 0),
((@CGUID+97)*10,13, 1178.106, -4102.728, 19.03866, NULL, 0),
((@CGUID+97)*10,14, 1170.561, -4115.974, 20.37826, NULL, 0),
((@CGUID+97)*10,15, 1168.573, -4121.882, 20.837, NULL, 0),
((@CGUID+97)*10,16, 1172.038, -4133.092, 21.39877, NULL, 0),
((@CGUID+97)*10,17, 1163.767, -4141.554, 21.50074, NULL, 0),
((@CGUID+97)*10,18, 1162.981, -4147.268, 21.35548, NULL, 0),
((@CGUID+97)*10,19, 1166.406, -4155.194, 21.71778, NULL, 0);

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 225989 AND 226286;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 225989 AND 226286;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+426;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Orgrimmar
(@OGUID+0, 186717, 1, 1637, 1637, '0', 0, 0, 1563.8072509765625, -4394.62353515625, 16.38290786743164062, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- Brewfest Banner (Area: Orgrimmar - Difficulty: 0)
(@OGUID+1, 186717, 1, 1637, 1637, '0', 0, 0, 1566.5191650390625, -4409.3349609375, 16.26761627197265625, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- Brewfest Banner (Area: Orgrimmar - Difficulty: 0)
(@OGUID+2, 186717, 1, 1637, 1637, '0', 0, 0, 1610.015625, -4152.1474609375, 49.28722000122070312, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 45745), -- Brewfest Banner (Area: Orgrimmar - Difficulty: 0)
(@OGUID+3, 186717, 1, 1637, 1637, '0', 0, 0, 1600.59375, -4160.32275390625, 49.7701568603515625, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- Brewfest Banner (Area: Orgrimmar - Difficulty: 0)
(@OGUID+4, 186717, 1, 1637, 1637, '0', 0, 0, 1610.7882080078125, -4175.73291015625, 50.69487380981445312, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 45745), -- Brewfest Banner (Area: Orgrimmar - Difficulty: 0)
(@OGUID+5, 186717, 1, 1637, 1637, '0', 0, 0, 1585.0364990234375, -4400.3369140625, 15.98898124694824218, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- Brewfest Banner (Area: Orgrimmar - Difficulty: 0)
(@OGUID+6, 186717, 1, 1637, 5170, '0', 0, 0, 1908.1510009765625, -4279.31591796875, 27.85268783569335937, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- Brewfest Banner (Area: Valley of Strength - Difficulty: 0)
(@OGUID+7, 186717, 1, 1637, 5170, '0', 0, 0, 1910.4305419921875, -4264.19091796875, 29.54247665405273437, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 45745), -- Brewfest Banner (Area: Valley of Strength - Difficulty: 0)
(@OGUID+8, 186717, 1, 1637, 5170, '0', 0, 0, 1932.470458984375, -4270.8837890625, 28.41196632385253906, 3.36761784553527832, 0, 0, -0.99362087249755859, 0.112772092223167419, 120, 255, 1, 45745), -- Brewfest Banner (Area: Valley of Strength - Difficulty: 0)
(@OGUID+9, 186717, 1, 1637, 5170, '0', 0, 0, 1929.7379150390625, -4283.72216796875, 26.04098320007324218, 2.94610452651977539, 0, 0, 0.995226860046386718, 0.09758847951889038, 120, 255, 1, 45745), -- Brewfest Banner (Area: Valley of Strength - Difficulty: 0)
(@OGUID+10, 186717, 1, 1637, 5170, '0', 0, 0, 1917.9635009765625, -4672.923828125, 34.47301101684570312, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 45745), -- Brewfest Banner (Area: Valley of Strength - Difficulty: 0)
(@OGUID+11, 186717, 1, 1637, 5170, '0', 0, 0, 1936.204833984375, -4670.52783203125, 33.3103790283203125, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- Brewfest Banner (Area: Valley of Strength - Difficulty: 0)
(@OGUID+12, 186717, 1, 1637, 5170, '0', 0, 0, 1941.8194580078125, -4696.8662109375, 35.99005508422851562, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 45745), -- Brewfest Banner (Area: Valley of Strength - Difficulty: 0)
(@OGUID+13, 195253, 1, 1637, 5170, '0', 0, 0, 1616.550048828125, -4423.97998046875, 27.18330001831054687, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+14, 195253, 1, 1637, 5170, '0', 0, 0, 1586.5999755859375, -4311.75, 28.184600830078125, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+15, 195253, 1, 1637, 5170, '0', 0, 0, 1667.9300537109375, -4343.41015625, 73.01419830322265625, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+16, 195253, 1, 1637, 5170, '0', 0, 0, 1799.31005859375, -4370.669921875, 107.9680023193359375, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+17, 195253, 1, 1637, 5168, '0', 0, 0, 2037.280029296875, -4676.0498046875, 42.38940048217773437, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+18, 195253, 1, 1637, 5168, '0', 0, 0, 2073.52001953125, -4766.5, 33.80910110473632812, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+19, 195253, 1, 1637, 5171, '0', 0, 0, 1951.3900146484375, -4199.58984375, 41.89910125732421875, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+20, 195253, 1, 1637, 5332, '0', 0, 0, 1640.0699462890625, -4121.75, 67.02790069580078125, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Orgrimmar Embassy - Difficulty: 0)
(@OGUID+21, 195253, 1, 1637, 5169, '0', 0, 0, 1734.68994140625, -4078.679931640625, 58.73630142211914062, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 45745), -- Hanging, Streamer x3 - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+22, 195256, 1, 1637, 1637, '0', 0, 0, 1546.18994140625, -4358.0400390625, 18.04109954833984375, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+23, 195256, 1, 1637, 1637, '0', 0, 0, 1543.31005859375, -4363.77978515625, 20.5475006103515625, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+24, 195256, 1, 1637, 1637, '0', 0, 0, 1563.93994140625, -4429.7900390625, 14.31309986114501953, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+25, 195256, 1, 1637, 1637, '0', 0, 0, 1537.75, -4375.93994140625, 17.67499923706054687, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+26, 195256, 1, 1637, 1637, '0', 0, 0, 1569.3819580078125, -4382.36962890625, 16.33680534362792968, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+27, 195256, 1, 1637, 5170, '0', 0, 0, 1556.81005859375, -4331.14990234375, 22.68700027465820312, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+28, 195256, 1, 1637, 5170, '0', 0, 0, 1617.3900146484375, -4414.43994140625, 14.88309955596923828, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+29, 195256, 1, 1637, 5170, '0', 0, 0, 1607.72998046875, -4383.830078125, 20.79039955139160156, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+30, 195256, 1, 1637, 5170, '0', 0, 0, 1593.260009765625, -4310.6201171875, 20.62369918823242187, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+31, 195256, 1, 1637, 5170, '0', 0, 0, 1662.050048828125, -4339.31005859375, 63.58499908447265625, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+32, 195256, 1, 1637, 5170, '0', 0, 0, 1668.0899658203125, -4351.06982421875, 63.58499908447265625, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+33, 195256, 1, 1637, 5170, '0', 0, 0, 1642.969970703125, -4230.47998046875, 52.0428009033203125, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+34, 195256, 1, 1637, 5170, '0', 0, 0, 1707.4200439453125, -4308.009765625, 31.22760009765625, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- Standing, Exterior; Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+35, 195256, 1, 1637, 5170, '0', 0, 0, 1577.092041015625, -4217.59375, 54.19200897216796875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+36, 195256, 1, 1637, 5170, '0', 0, 0, 1738.0799560546875, -4399.5, 36.53369903564453125, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+37, 195256, 1, 1637, 5170, '0', 0, 0, 1747.0400390625, -4412.490234375, 36.96250152587890625, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+38, 195256, 1, 1637, 5167, '0', 0, 0, 1869.699951171875, -4520.35986328125, 24.58790016174316406, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Drag - Difficulty: 0)
(@OGUID+39, 195256, 1, 1637, 5168, '0', 0, 0, 1904.030029296875, -4673.02001953125, 35.39350128173828125, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+40, 195256, 1, 1637, 5171, '0', 0, 0, 1916.9000244140625, -4227.490234375, 37.07920074462890625, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+41, 195256, 1, 1637, 5170, '0', 0, 0, 1588.361083984375, -4178.126953125, 52.32696533203125, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+42, 195256, 1, 1637, 5170, '0', 0, 0, 1594.1597900390625, -4162.80712890625, 51.74104690551757812, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+43, 195256, 1, 1637, 5170, '0', 0, 0, 1537.5504150390625, -4206.1337890625, 54.383453369140625, 0.132501229643821716, 0, 0, 0.066202163696289062, 0.997806251049041748, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+44, 195256, 1, 1637, 5170, '0', 0, 0, 1573.921875, -4164.142578125, 53.75942230224609375, 0.047823697328567504, 0, 0, 0.023909568786621093, 0.999714136123657226, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+45, 195256, 1, 1637, 5169, '0', 0, 0, 1727.25, -4065.760009765625, 49.26470184326171875, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+46, 195260, 1, 1637, 1637, '0', 0, 0, 1519.72998046875, -4346.31005859375, 21.89909934997558593, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+47, 195260, 1, 1637, 1637, '0', 0, 0, 1511, -4353.7099609375, 21.87989997863769531, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+48, 195260, 1, 1637, 1637, '0', 0, 0, 1514.97998046875, -4347.080078125, 21.87989997863769531, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+49, 195260, 1, 1637, 5170, '0', 0, 0, 1583.2900390625, -4463.080078125, 17.24099922180175781, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+50, 195260, 1, 1637, 5170, '0', 0, 0, 1582.6800537109375, -4460.990234375, 23.16650009155273437, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+51, 195260, 1, 1637, 5170, '0', 0, 0, 1580.0999755859375, -4464.06005859375, 17.23870086669921875, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+52, 195260, 1, 1637, 5170, '0', 0, 0, 1577.530029296875, -4464.759765625, 17.26910018920898437, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+53, 195260, 1, 1637, 5170, '0', 0, 0, 1576.56005859375, -4462.5400390625, 23.16650009155273437, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+54, 195260, 1, 1637, 5170, '0', 0, 0, 1639.2239990234375, -4444.65283203125, 18.51654434204101562, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+55, 195260, 1, 1637, 5170, '0', 0, 0, 1642.949951171875, -4446.10009765625, 26.27840042114257812, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+56, 195260, 1, 1637, 5170, '0', 0, 0, 1635.7135009765625, -4448.33837890625, 18.51782989501953125, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+57, 195260, 1, 1637, 5169, '0', 0, 0, 1730, -4078.510009765625, 71.4373016357421875, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+58, 195260, 1, 1637, 5169, '0', 0, 0, 1728.760009765625, -4081.260009765625, 71.351898193359375, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+59, 195260, 1, 1637, 5169, '0', 0, 0, 1742.6099853515625, -4084.449951171875, 69.10540008544921875, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+60, 195260, 1, 1637, 5169, '0', 0, 0, 1741.1400146484375, -4080.510009765625, 69.105499267578125, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+61, 195263, 1, 1637, 5170, '0', 0, 0, 1611.719970703125, -4426.97021484375, 18.53499984741210937, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+62, 195263, 1, 1637, 5170, '0', 0, 0, 1619.52001953125, -4419.08984375, 18.13489913940429687, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+63, 195263, 1, 1637, 5170, '0', 0, 0, 1583.8199462890625, -4223.68994140625, 57.40999984741210937, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+64, 195263, 1, 1637, 5170, '0', 0, 0, 1600.010009765625, -4210.419921875, 57.44120025634765625, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+65, 195263, 1, 1637, 5170, '0', 0, 0, 1747.4599609375, -4391.85986328125, 44.42950057983398437, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+66, 195263, 1, 1637, 5170, '0', 0, 0, 1753.6600341796875, -4387.60009765625, 44.42029953002929687, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+67, 195263, 1, 1637, 5170, '0', 0, 0, 1756.81005859375, -4405.8701171875, 44.31529998779296875, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+68, 195263, 1, 1637, 5170, '0', 0, 0, 1763.0799560546875, -4401.580078125, 44.29320144653320312, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+69, 195263, 1, 1637, 5168, '0', 0, 0, 1900.3199462890625, -4687.97998046875, 39.13949966430664062, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+70, 195263, 1, 1637, 5171, '0', 0, 0, 1917.9000244140625, -4231.1298828125, 39.3524017333984375, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 45745), -- Hanging, Square, Medium - Brewfest (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+71, 195265, 1, 14, 4982, '0', 0, 0, 1438.06005859375, -4360.259765625, 25.31410026550292968, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+72, 195265, 1, 14, 4982, '0', 0, 0, 1430.47998046875, -4426.52978515625, 25.3069000244140625, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+73, 195265, 1, 14, 4982, '0', 0, 0, 1431.02001953125, -4429.31982421875, 25.30839920043945312, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+74, 195265, 1, 14, 4982, '0', 0, 0, 1450.3055419921875, -4429.1162109375, 25.45359230041503906, 2.64692997932434082, 0, 0, 0.969569206237792968, 0.244817420840263366, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+75, 195265, 1, 14, 4982, '0', 0, 0, 1461.6199951171875, -4412.8701171875, 25.33069992065429687, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+76, 195265, 1, 1637, 5169, '0', 0, 0, 1738.969970703125, -4070.3798828125, 48.10770034790039062, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+77, 195265, 1, 1637, 5169, '0', 0, 0, 1737.4100341796875, -4069.719970703125, 48.42779922485351562, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+78, 195265, 1, 1637, 5169, '0', 0, 0, 1739.489990234375, -4068.919921875, 48.1074981689453125, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+79, 195265, 1, 1637, 5169, '0', 0, 0, 1738.9300537109375, -4070.35009765625, 49.35660171508789062, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+80, 195266, 1, 1637, 1637, '0', 0, 0, 1568.6600341796875, -4430.39990234375, 22.46669960021972656, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+81, 195266, 1, 1637, 1637, '0', 0, 0, 1572.1099853515625, -4429.39990234375, 22.37619972229003906, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+82, 195266, 1, 1637, 5168, '0', 0, 0, 1918.699951171875, -4729.64013671875, 44.61510086059570312, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+83, 195266, 1, 1637, 5171, '0', 0, 0, 1919.7900390625, -4232.330078125, 42.38560104370117187, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+84, 195273, 1, 14, 4982, '0', 0, 0, 1442.5103759765625, -4359.3349609375, 29.79220008850097656, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+85, 195273, 1, 14, 4982, '0', 0, 0, 1443.4427490234375, -4367.59033203125, 29.67009925842285156, 3.231614112854003906, 0, 0, -0.99898719787597656, 0.044995453208684921, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+86, 195273, 1, 14, 4982, '0', 0, 0, 1422.7742919921875, -4420.73291015625, 29.58182144165039062, 0.238904312252998352, 0, 0, 0.119168281555175781, 0.992874085903167724, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+87, 195273, 1, 14, 4982, '0', 0, 0, 1423.8177490234375, -4428.921875, 29.56694984436035156, 0.168968856334686279, 0, 0, 0.084383964538574218, 0.9964333176612854, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+88, 195273, 1, 1637, 1637, '0', 0, 0, 1537.530029296875, -4371.990234375, 26.2845001220703125, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+89, 195273, 1, 1637, 1637, '0', 0, 0, 1565.719970703125, -4436.2900390625, 19.36989974975585937, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Orgrimmar - Difficulty: 0)
(@OGUID+90, 195273, 1, 1637, 5170, '0', 0, 0, 1577.8900146484375, -4432.9501953125, 19.15780067443847656, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+91, 195273, 1, 1637, 5170, '0', 0, 0, 1665.3499755859375, -4338.89990234375, 69.08350372314453125, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+92, 195273, 1, 1637, 5170, '0', 0, 0, 1670.5400390625, -4347.97021484375, 69.05699920654296875, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+93, 195273, 1, 1637, 5170, '0', 0, 0, 1695.1400146484375, -4271.14990234375, 37.30810165405273437, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+94, 195273, 1, 1637, 5170, '0', 0, 0, 1700.5, -4275.990234375, 37.31660079956054687, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+95, 195273, 1, 1637, 5170, '0', 0, 0, 1670.949951171875, -4423.81982421875, 25.05089950561523437, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+96, 195273, 1, 1637, 5170, '0', 0, 0, 1663.8199462890625, -4433.52001953125, 24.72699928283691406, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Strength - Difficulty: 0)
(@OGUID+97, 195273, 1, 1637, 5167, '0', 0, 0, 1888.52001953125, -4600.31005859375, 41.44359970092773437, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Drag - Difficulty: 0)
(@OGUID+98, 195273, 1, 1637, 5167, '0', 0, 0, 1934.8800048828125, -4594.58984375, 41.61320114135742187, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Drag - Difficulty: 0)
(@OGUID+99, 195273, 1, 1637, 5168, '0', 0, 0, 1900.760009765625, -4678.77978515625, 39.08229827880859375, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+100, 195273, 1, 1637, 5168, '0', 0, 0, 1999.1700439453125, -4668.81005859375, 30.54710006713867187, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+101, 195273, 1, 1637, 5168, '0', 0, 0, 2038.800048828125, -4681.9501953125, 35.07889938354492187, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+102, 195273, 1, 1637, 5168, '0', 0, 0, 2034.510009765625, -4670.43994140625, 34.97359848022460937, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+103, 195273, 1, 1637, 5168, '0', 0, 0, 2070.340087890625, -4804.7099609375, 31.90710067749023437, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+104, 195273, 1, 1637, 5168, '0', 0, 0, 2078.75, -4800.27978515625, 31.87400054931640625, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Honor - Difficulty: 0)
(@OGUID+105, 195273, 1, 1637, 5167, '0', 0, 0, 1900.0400390625, -4382.08984375, 46.42800140380859375, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Drag - Difficulty: 0)
(@OGUID+106, 195273, 1, 1637, 5167, '0', 0, 0, 1907.4000244140625, -4380.60986328125, 46.34769821166992187, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Drag - Difficulty: 0)
(@OGUID+107, 195273, 1, 1637, 5167, '0', 0, 0, 1904.1099853515625, -4364.18017578125, 46.06280136108398437, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Drag - Difficulty: 0)
(@OGUID+108, 195273, 1, 1637, 5167, '0', 0, 0, 1896.68994140625, -4365.68994140625, 46.20119857788085937, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: The Drag - Difficulty: 0)
(@OGUID+109, 195273, 1, 1637, 5171, '0', 0, 0, 1886.199951171875, -4281.509765625, 28.75539970397949218, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+110, 195273, 1, 1637, 5171, '0', 0, 0, 1860.77001953125, -4291.64013671875, 31.61899948120117187, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+111, 195273, 1, 1637, 5171, '0', 0, 0, 1952.469970703125, -4204.52978515625, 38.86209869384765625, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+112, 195273, 1, 1637, 5171, '0', 0, 0, 1932.4100341796875, -4182.22021484375, 40.4954986572265625, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+113, 195273, 1, 1637, 5171, '0', 0, 0, 1914.27001953125, -4188.22021484375, 40.4468994140625, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+114, 195273, 1, 1637, 0, '0', 0, 0, 1747.469970703125, -4198.3798828125, 54.29600143432617187, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: 0 - Difficulty: 0)
(@OGUID+115, 195273, 1, 1637, 5169, '0', 0, 0, 1709.199951171875, -4085.52001953125, 51.69260025024414062, 2.897245407104492187, 0, 0, 0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+116, 195273, 1, 1637, 5169, '0', 0, 0, 1729.1800537109375, -4080.590087890625, 56.01599884033203125, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+117, 195273, 1, 1637, 5169, '0', 0, 0, 1740.31005859375, -4076.7099609375, 55.63199996948242187, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 45745), -- Hanging, Tall/Thin, Medium - Brewfest (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+118, 195256, 1, 14, 4982, '0', 0, 0, 1301.5699462890625, -4330.2998046875, 33.035400390625, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+119, 195256, 1, 14, 4982, '0', 0, 0, 1304.5999755859375, -4345.02001953125, 32.999298095703125, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 120, 255, 1, 45745), -- Standing, Exterior, Medium - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+120, 195260, 1, 14, 4982, '0', 0, 0, 1289.800048828125, -4344.31005859375, 35.50780105590820312, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+121, 195260, 1, 14, 4982, '0', 0, 0, 1286.1700439453125, -4333.47021484375, 35.69499969482421875, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- Standing, Interior, Small - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+122, 195264, 1, 14, 4982, '0', 0, 0, 1309.8199462890625, -4324.27001953125, 33.939300537109375, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 120, 255, 1, 45745), -- Standing, Interior, Medium - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+123, 195265, 1, 14, 4982, '0', 0, 0, 1312.3900146484375, -4325.31005859375, 32.47679901123046875, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+124, 195265, 1, 14, 4982, '0', 0, 0, 1311.3499755859375, -4324.43017578125, 32.7333984375, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+125, 195266, 1, 14, 4982, '0', 0, 0, 1297.5400390625, -4337.66015625, 38.1259002685546875, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- Hanging, Streamer - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+126, 186680, 1, 14, 4982, '0', 0, 0, 1367.19970703125, -4341.9619140625, 28.61637115478515625, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- Brewfest Canopy (Area: Durotar - Difficulty: 0)
(@OGUID+127, 186717, 1, 14, 4982, '0', 0, 0, 1362.54345703125, -4352.3505859375, 26.83419990539550781, 3.600472211837768554, 0, 0, -0.97379398345947265, 0.227431893348693847, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+128, 326138, 1, 14, 4982, '0', 0, 0, 1366.5538330078125, -4343.95166015625, 28.61637115478515625, 1.762728452682495117, 0, 0, 0.771607398986816406, 0.636099040508270263, 120, 255, 1, 45745), -- Party Table (Area: Rocktusk Farm - Difficulty: 0)
(@OGUID+129, 326139, 1, 14, 4982, '0', 0, 0, 1366.6024169921875, -4343.6318359375, 29.59897613525390625, 5.183575630187988281, 0, 0, -0.52252101898193359, 0.852626383304595947, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Rocktusk Farm - Difficulty: 0)
(@OGUID+130, 326139, 1, 14, 4982, '0', 0, 0, 1366.38720703125, -4344.12353515625, 29.59897613525390625, 1.832538485527038574, 0, 0, 0.793335914611816406, 0.608784139156341552, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Rocktusk Farm - Difficulty: 0)
(@OGUID+131, 326139, 1, 14, 4982, '0', 0, 0, 1366.185791015625, -4343.7119140625, 29.59897613525390625, 2.984450340270996093, 0, 0, 0.996914863586425781, 0.078490354120731353, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Rocktusk Farm - Difficulty: 0)
(@OGUID+132, 326139, 1, 14, 4982, '0', 0, 0, 1366.890625, -4344.078125, 29.59897613525390625, 2.024524688720703125, 0, 0, 0.848032951354980468, 0.529943466186523437, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Rocktusk Farm - Difficulty: 0)
(@OGUID+133, 326705, 1, 14, 4982, '0', 0, 0, 1363.201416015625, -4346.9150390625, 28.46174812316894531, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Rocktusk Farm - Difficulty: 0)
(@OGUID+134, 327165, 1, 14, 4982, '0', 0, 0, 1369.3992919921875, -4339.7744140625, 28.61636734008789062, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Keg (Area: Rocktusk Farm - Difficulty: 0)
(@OGUID+135, 327165, 1, 14, 4982, '0', 0, 0, 1368.0728759765625, -4339.29541015625, 28.61637115478515625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Keg (Area: Rocktusk Farm - Difficulty: 0)
-- Brewfest area
(@OGUID+136, 180749, 1, 14, 14, '0', 0, 0, 1211.642333984375, -4126.75537109375, 23.55902862548828125, 3.118648052215576171, 0, 0, 0.999934196472167968, 0.011472011916339397, 120, 255, 1, 45745), -- Cheer Speaker (Area: Durotar - Difficulty: 0)
(@OGUID+137, 180749, 1, 14, 14, '0', 0, 0, 1170.4114990234375, -4103.33154296875, 18.73263931274414062, 1.950362563133239746, 0, 0, 0.827803611755371093, 0.561017990112304687, 120, 255, 1, 45745), -- Cheer Speaker (Area: Durotar - Difficulty: 0)
(@OGUID+138, 180749, 1, 14, 14, '0', 0, 0, 1181.3211669921875, -4156.6337890625, 22.16675567626953125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- Cheer Speaker (Area: Durotar - Difficulty: 0)
(@OGUID+139, 180749, 1, 14, 14, '0', 0, 0, 1160.07470703125, -4137.736328125, 23.89529037475585937, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 45745), -- Cheer Speaker (Area: Durotar - Difficulty: 0)
(@OGUID+140, 186185, 1, 14, 14, '0', 0, 0, 1220.7603759765625, -4118.80224609375, 24.45111083984375, 2.984743833541870117, -0.06064844131469726, -0.00642013549804687, 0.995122909545898437, 0.07753031700849533, 120, 255, 1, 45745), -- Gordok Festive Keg (Area: Durotar - Difficulty: 0)
(@OGUID+141, 186186, 1, 14, 14, '0', 0, 0, 1159.5347900390625, -4110.66162109375, 19.61979103088378906, 5.957599163055419921, 0, 0, -0.16207504272460937, 0.986778438091278076, 120, 255, 1, 45745), -- Drohn's Distillery Festive Keg (Area: Durotar - Difficulty: 0)
(@OGUID+142, 186187, 1, 14, 14, '0', 0, 0, 1206.2413330078125, -4086.3212890625, 20.765625, 4.305149078369140625, 0.021349430084228515, -0.04157352447509765, -0.83444595336914062, 0.549104571342468261, 120, 255, 1, 45745), -- T'chali's Voodoo Brew Festive Keg (Area: Durotar - Difficulty: 0)
(@OGUID+143, 186229, 1, 14, 14, '0', 0, 0, 1154.4322509765625, -4156.54150390625, 20.29161643981933593, 3.866014957427978515, 0.000954627990722656, -0.00771808624267578, -0.93508243560791015, 0.354344964027404785, 120, 255, 1, 45745), -- BREWFEST (Area: Durotar - Difficulty: 0)
(@OGUID+144, 186680, 1, 14, 14, '0', 0, 0, 1158.361083984375, -4204.28125, 22.59717369079589843, 0.960300564765930175, 0.001619815826416015, 0.005380630493164062, 0.46189117431640625, 0.88691878318786621, 120, 255, 1, 45745), -- Brewfest Canopy (Area: Durotar - Difficulty: 0)
(@OGUID+145, 186680, 1, 14, 14, '0', 0, 0, 1177.5989990234375, -4223.517578125, 22.81329345703125, 0.996037423610687255, -0.00771903991699218, -0.0010986328125, 0.477688789367675781, 0.878494501113891601, 120, 255, 1, 45745), -- Brewfest Canopy (Area: Durotar - Difficulty: 0)
(@OGUID+146, 186680, 1, 14, 14, '0', 0, 0, 1192.282958984375, -4165.546875, 21.58426666259765625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- Brewfest Canopy (Area: Durotar - Difficulty: 0)
(@OGUID+147, 186681, 1, 14, 14, '0', 0, 0, 1180.1197509765625, -4172.142578125, 21.61299324035644531, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 45745), -- Brewfest Food Tent (Area: Durotar - Difficulty: 0)
(@OGUID+148, 186681, 1, 14, 14, '0', 0, 0, 1153.68408203125, -4132.06591796875, 20.99527549743652343, 6.233623504638671875, 0, 0, -0.02477836608886718, 0.999692976474761962, 120, 255, 1, 45745), -- Brewfest Food Tent (Area: Durotar - Difficulty: 0)
(@OGUID+149, 186682, 1, 14, 14, '0', 0, 0, 1213.8072509765625, -4091.828125, 21.6852874755859375, 3.852287530899047851, 0.008812427520751953, -0.06044673919677734, -0.93550872802734375, 0.347982615232467651, 120, 255, 1, 45745), -- Brewfest Beer Tent (Area: Durotar - Difficulty: 0)
(@OGUID+150, 186682, 1, 14, 14, '0', 0, 0, 1161.9461669921875, -4101.453125, 18.52599143981933593, 5.89983987808227539, -0.05095100402832031, -0.02523517608642578, -0.19172573089599609, 0.979800224304199218, 120, 255, 1, 45745), -- Brewfest Beer Tent (Area: Durotar - Difficulty: 0)
(@OGUID+151, 186683, 1, 14, 4982, '0', 0, 0, 1330.5382080078125, -4642.48974609375, 23.62487220764160156, 2.916415691375732421, -0.05447006225585937, 0.000032424926757812, 0.992230415344238281, 0.111856110394001007, 120, 255, 1, 45745), -- Empty Brew Wagon (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+152, 186709, 1, 14, 14, '0', 0, 0, 1186.8524169921875, -4226.95849609375, 24.453125, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: Durotar - Difficulty: 0)
(@OGUID+153, 186709, 1, 14, 14, '0', 0, 0, 1185.2742919921875, -4225.986328125, 24.31208229064941406, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: Durotar - Difficulty: 0)
(@OGUID+154, 186709, 1, 14, 14, '0', 0, 0, 1183.748291015625, -4224.830078125, 24.16156959533691406, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: Durotar - Difficulty: 0)
(@OGUID+155, 186709, 1, 14, 4982, '0', 0, 0, 1334.13720703125, -4641.48291015625, 24.26278495788574218, 1.534296512603759765, 0, 0, 0.694085121154785156, 0.719892919063568115, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+156, 186709, 1, 14, 4982, '0', 0, 0, 1336.1129150390625, -4642.34716796875, 24.44666290283203125, 2.472614765167236328, 0, 0, 0.944578170776367187, 0.328286528587341308, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+157, 186709, 1, 14, 4982, '0', 0, 0, 1327.2447509765625, -4638.3837890625, 23.74754524230957031, 0.887380897998809814, 0, 0, 0.4292755126953125, 0.903173565864562988, 120, 255, 1, 45745), -- Standing Brewfest Keg (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+158, 186717, 1, 14, 14, '0', 0, 0, 1168.560791015625, -4098.484375, 18.39724540710449218, 5.714218616485595703, 0, 0, -0.28066158294677734, 0.959806799888610839, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+159, 186717, 1, 14, 14, '0', 0, 0, 1188.3316650390625, -4228.2099609375, 24.51194190979003906, 0.97809380292892456, 0, 0, 0.469784736633300781, 0.882781028747558593, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+160, 186717, 1, 14, 14, '0', 0, 0, 1161.77783203125, -4398.2255859375, 25.27201652526855468, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+161, 186717, 1, 14, 14, '0', 0, 0, 1214.3004150390625, -4129.8818359375, 23.59349250793457031, 2.593387126922607421, 0, 0, 0.962668418884277343, 0.270683377981185913, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+162, 186717, 1, 14, 14, '0', 0, 0, 1336.015625, -4365.609375, 26.71100234985351562, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+163, 186717, 1, 14, 14, '0', 0, 0, 1173.80908203125, -4216.86474609375, 22.98779106140136718, 0.784946799278259277, 0, 0, 0.382474899291992187, 0.923965871334075927, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+164, 186717, 1, 14, 14, '0', 0, 0, 1168.8350830078125, -4239.81787109375, 22.41514778137207031, 1.168083429336547851, 0, 0, 0.551400184631347656, 0.834240853786468505, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+165, 186717, 1, 14, 14, '0', 0, 0, 1227.3385009765625, -4433.4619140625, 24.40195274353027343, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+166, 186717, 1, 14, 14, '0', 0, 0, 1308.4722900390625, -4448.673828125, 26.03033447265625, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+167, 186717, 1, 14, 14, '0', 0, 0, 1217.2916259765625, -4098.77099609375, 21.89983940124511718, 3.682364940643310546, 0, 0, -0.96366786956787109, 0.267103463411331176, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+168, 186717, 1, 14, 14, '0', 0, 0, 1194.1197509765625, -4123.40087890625, 22.48537826538085937, 3.885187387466430664, 0, 0, -0.93167591094970703, 0.363290518522262573, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+169, 186717, 1, 14, 14, '0', 0, 0, 1188.032958984375, -4117.51220703125, 21.44266128540039062, 4.183285713195800781, 0, 0, -0.86739826202392578, 0.497614592313766479, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+170, 186717, 1, 14, 14, '0', 0, 0, 1305.7847900390625, -4408.330078125, 25.85153007507324218, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- Brewfest Banner (Area: Durotar - Difficulty: 0)
(@OGUID+171, 186717, 1, 14, 0, '0', 0, 0, 1318.3333740234375, -4549.20654296875, 22.76087379455566406, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 45745), -- Brewfest Banner (Area: 0 - Difficulty: 0)
(@OGUID+172, 186717, 1, 14, 4982, '0', 0, 0, 1314.638916015625, -4599.16650390625, 23.74962234497070312, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+173, 186717, 1, 14, 4982, '0', 0, 0, 1336.0504150390625, -4640.5625, 24.45138931274414062, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+174, 186717, 1, 14, 4982, '0', 0, 0, 1329.55908203125, -4637.970703125, 23.95576286315917968, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 45745), -- Brewfest Banner (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+175, 186737, 1, 14, 14, '0', 0, 0, 1225.9635009765625, -4138.01220703125, 24.39450263977050781, 4.948596000671386718, 0.017147541046142578, 0.01239776611328125, -0.61881732940673828, 0.785249829292297363, 120, 255, 1, 45745), -- Brewfest Wagon Loaded (Area: Durotar - Difficulty: 0)
(@OGUID+176, 195265, 1, 14, 4982, '0', 0, 0, 1404.300048828125, -4892.35009765625, 12.58650016784667968, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+177, 195265, 1, 14, 4982, '0', 0, 0, 1404.280029296875, -4892.39990234375, 11.33829975128173828, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+178, 195265, 1, 14, 4982, '0', 0, 0, 1405.93994140625, -4898.8701171875, 14.34070014953613281, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- Standing, Large - Brewfest (Area: The Dranosh'ar Blockade - Difficulty: 0)
(@OGUID+179, 209654, 1, 14, 14, '0', 0, 0, 1204.59033203125, -4156.26904296875, 21.91840362548828125, 2.488084793090820312, 0, 0, 0.947089195251464843, 0.320970475673675537, 120, 255, 1, 45745), -- Pandaren Tent (Area: Durotar - Difficulty: 0)
(@OGUID+180, 211694, 1, 14, 14, '0', 0, 0, 1202.0035400390625, -4154.37158203125, 21.79358291625976562, 2.493256330490112304, 0, 0, 0.947916030883789062, 0.318520337343215942, 120, 255, 1, 45745), -- Pandaren Brew (Area: Durotar - Difficulty: 0)
(@OGUID+181, 211694, 1, 14, 14, '0', 0, 0, 1207.0816650390625, -4156.345703125, 22.0625, 0.550789594650268554, 0, 0, 0.2719268798828125, 0.962317943572998046, 120, 255, 1, 45745), -- Pandaren Brew (Area: Durotar - Difficulty: 0)
(@OGUID+182, 211694, 1, 14, 14, '0', 0, 0, 1205.640625, -4158.9775390625, 22.01388931274414062, 3.869777917861938476, 0, 0, -0.93444728851318359, 0.356101512908935546, 120, 255, 1, 45745), -- Pandaren Brew (Area: Durotar - Difficulty: 0)
(@OGUID+183, 211694, 1, 14, 14, '0', 0, 0, 1204.18408203125, -4154.5869140625, 21.89236068725585937, 2.022863149642944335, 0, 0, 0.847592353820800781, 0.530647873878479003, 120, 255, 1, 45745), -- Pandaren Brew (Area: Durotar - Difficulty: 0)
(@OGUID+184, 211694, 1, 14, 14, '0', 0, 0, 1202.625, -4156.6025390625, 21.81944465637207031, 2.982998847961425781, 0, 0, 0.996857643127441406, 0.079213760793209075, 120, 255, 1, 45745), -- Pandaren Brew (Area: Durotar - Difficulty: 0)
(@OGUID+185, 211694, 1, 14, 14, '0', 0, 0, 1204.826416015625, -4156.783203125, 21.93402862548828125, 3.869777917861938476, 0, 0, -0.93444728851318359, 0.356101512908935546, 120, 255, 1, 45745), -- Pandaren Brew (Area: Durotar - Difficulty: 0)
(@OGUID+186, 221481, 1, 14, 14, '0', 0, 0, 1200.953125, -4153.53662109375, 21.7617340087890625, 5.616784095764160156, 0, 0, -0.32706928253173828, 0.945000350475311279, 120, 255, 1, 45745), -- Pandaren Kitchen Table (Area: Durotar - Difficulty: 0)
(@OGUID+187, 221482, 1, 14, 14, '0', 0, 0, 1198.2552490234375, -4152.84375, 22.57123947143554687, 4.765048980712890625, 0, 0, -0.68824577331542968, 0.725477576255798339, 120, 255, 1, 45745), -- PA Mug Bamboo 06 (Area: Durotar - Difficulty: 0)
(@OGUID+188, 221482, 1, 14, 14, '0', 0, 0, 1199.7257080078125, -4151.32275390625, 22.62852859497070312, 3.774377346038818359, 0, 0, -0.9503641128540039, 0.311139971017837524, 120, 255, 1, 45745), -- PA Mug Bamboo 06 (Area: Durotar - Difficulty: 0)
(@OGUID+189, 221482, 1, 14, 14, '0', 0, 0, 1198.5989990234375, -4152.29541015625, 22.58253097534179687, 4.189875125885009765, 0, 0, -0.8657541275024414, 0.500469565391540527, 120, 255, 1, 45745), -- PA Mug Bamboo 06 (Area: Durotar - Difficulty: 0)
(@OGUID+190, 231654, 1, 14, 14, '0', 0, 0, 1200.6441650390625, -4085.538330078125, 19.77874183654785156, 6.239365100860595703, 0.029206275939941406, -0.01964378356933593, -0.021331787109375, 0.999152660369873046, 120, 255, 1, 45745), -- Crate (Area: Durotar - Difficulty: 0)
(@OGUID+191, 239935, 1, 14, 14, '0', 0, 0, 1216.875, -4124.63916015625, 24.05902862548828125, 5.379328727722167968, 0.040865421295166015, -0.03658676147460937, -0.43532752990722656, 0.898599684238433837, 120, 255, 1, 45745), -- Ogre Rug (Area: Durotar - Difficulty: 0)
(@OGUID+192, 239938, 1, 14, 14, '0', 0, 0, 1218.8680419921875, -4125.0712890625, 24.30034828186035156, 0.08190155029296875, 0, 0, 0.0409393310546875, 0.99916166067123413, 120, 255, 1, 45745), -- Ogre Bag (Area: Durotar - Difficulty: 0)
(@OGUID+193, 250563, 1, 14, 14, '0', 0, 0, 1225.0521240234375, -4108.71337890625, 24.12847328186035156, 6.041737556457519531, 0, 0, -0.12043094635009765, 0.992721736431121826, 120, 255, 1, 45745), -- Baskets (Area: Durotar - Difficulty: 0)
(@OGUID+194, 250564, 1, 14, 14, '0', 0, 0, 1223.40625, -4107.828125, 23.91557693481445312, 6.041737556457519531, 0, 0, -0.12043094635009765, 0.992721736431121826, 120, 255, 1, 45745), -- Baskets (Area: Durotar - Difficulty: 0)
(@OGUID+195, 259240, 1, 14, 14, '0', 0, 0, 1201.88720703125, -4176.13720703125, 23.37236976623535156, 6.267628669738769531, -0.0411996841430664, -0.04799079895019531, -0.00973892211914062, 0.997950196266174316, 120, 255, 1, 45745), -- Hay (Area: Durotar - Difficulty: 0)
(@OGUID+196, 250566, 1, 14, 14, '0', 0, 0, 1222.173583984375, -4110.83154296875, 24.14080810546875, 6.151299953460693359, -0.0275125503540039, -0.02701950073242187, -0.06658363342285156, 0.997035443782806396, 120, 255, 1, 45745), -- Hides (Area: Durotar - Difficulty: 0)
(@OGUID+197, 252967, 1, 14, 14, '0', 0, 0, 1179.87158203125, -4088.670166015625, 17.74131965637207031, 5.079838752746582031, 0, 0, -0.56602287292480468, 0.824389517307281494, 120, 255, 1, 45745), -- Nightborne Goods (Area: Durotar - Difficulty: 0)
(@OGUID+198, 259240, 1, 14, 14, '0', 0, 0, 1171.29345703125, -4229.07666015625, 22.54635047912597656, 0.003711672266945242, -0.00420665740966796, -0.06631088256835937, 0.00156402587890625, 0.997788906097412109, 120, 255, 1, 45745), -- Hay (Area: Durotar - Difficulty: 0)
(@OGUID+199, 265545, 1, 14, 14, '0', 0, 0, 1185.29345703125, -4082.798583984375, 18.27788925170898437, 4.954325199127197265, 0, 0, -0.61661052703857421, 0.787268340587615966, 120, 255, 1, 45745), -- Frostwolf Banner (Area: Durotar - Difficulty: 0)
(@OGUID+200, 268917, 1, 14, 14, '0', 0, 0, 1155.1754150390625, -4117.484375, 20.68668746948242187, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Zandalari Sack (Area: Durotar - Difficulty: 0)
(@OGUID+201, 268919, 1, 14, 14, '0', 0, 0, 1156.6632080078125, -4118.064453125, 20.71174240112304687, 0.101058095693588256, 0, 0, 0.050507545471191406, 0.99872368574142456, 120, 255, 1, 45745), -- Zandalari Sack (Area: Durotar - Difficulty: 0)
(@OGUID+202, 279239, 1, 14, 14, '0', 0, 0, 1155.5625, -4120.66650390625, 20.91491127014160156, 0.239497929811477661, 0, 0, 0.119462966918945312, 0.992838680744171142, 120, 255, 1, 45745), -- [DNT] Crate (Area: Durotar - Difficulty: 0)
(@OGUID+203, 279243, 1, 14, 14, '0', 0, 0, 1156.7603759765625, -4116.892578125, 20.60756874084472656, 5.680264472961425781, 0, 0, -0.29691505432128906, 0.954903900623321533, 120, 255, 1, 45745), -- [DNT] Basket (Area: Durotar - Difficulty: 0)
(@OGUID+204, 279243, 1, 14, 14, '0', 0, 0, 1153.9583740234375, -4119.90283203125, 20.87203598022460937, 0.179707959294319152, 0, 0, 0.089733123779296875, 0.995965838432312011, 120, 255, 1, 45745), -- [DNT] Basket (Area: Durotar - Difficulty: 0)
(@OGUID+205, 279361, 1, 14, 14, '0', 0, 0, 1162.13720703125, -4122.796875, 22.13183021545410156, 6.030962944030761718, 0, 0, -0.12577724456787109, 0.992058515548706054, 120, 255, 1, 45745), -- [DNT] Bottle (Area: Durotar - Difficulty: 0)
(@OGUID+206, 279362, 1, 14, 14, '0', 0, 0, 1161.546875, -4116.67529296875, 21.823822021484375, 0.048470471054315567, 0, 0, 0.024232864379882812, 0.99970632791519165, 120, 255, 1, 45745), -- [DNT] Bottle (Area: Durotar - Difficulty: 0)
(@OGUID+207, 279363, 1, 14, 14, '0', 0, 0, 1161.876708984375, -4123.064453125, 22.20417404174804687, 0.205458387732505798, 0, 0, 0.102548599243164062, 0.994727969169616699, 120, 255, 1, 45745), -- [DNT] Bottle (Area: Durotar - Difficulty: 0)
(@OGUID+208, 279592, 1, 14, 0, '0', 0, 0, 1163.91845703125, -4232.361328125, 21.82450294494628906, 0.139094695448875427, 0.005823612213134765, -0.06205654144287109, 0.069449424743652343, 0.995636403560638427, 120, 255, 1, 45745), -- Trough (Area: 0 - Difficulty: 0)
(@OGUID+209, 282271, 1, 14, 14, '0', 0, 0, 1167.01220703125, -4237.25341796875, 22.07019233703613281, 2.677776813507080078, -0.08114147186279296, 0.036334037780761718, 0.969038009643554687, 0.230350270867347717, 120, 255, 1, 45745), -- Haypile (Area: Durotar - Difficulty: 0)
(@OGUID+210, 288421, 1, 14, 14, '0', 0, 0, 1245.8125, -4158.79541015625, 26.64020729064941406, 2.738005638122558593, 0, 0, 0.979708671569824218, 0.200426816940307617, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+211, 288422, 1, 14, 14, '0', 0, 0, 1245.8367919921875, -4159.3837890625, 26.81944465637207031, 4.149754047393798828, 0.289687633514404296, 0.142897605895996093, -0.83110523223876953, 0.452686876058578491, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+212, 288422, 1, 14, 14, '0', 0, 0, 1155.4132080078125, -4144.20654296875, 21.22547340393066406, 4.509018421173095703, 0.092716217041015625, -0.03387737274169921, -0.77415752410888671, 0.625248849391937255, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+213, 288422, 1, 14, 14, '0', 0, 0, 1206.517333984375, -4174.4912109375, 23.77289009094238281, 4.822723388671875, 0, 0, -0.66704177856445312, 0.74502032995223999, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+214, 292549, 1, 14, 14, '0', 0, 0, 1241.6024169921875, -4162.63037109375, 26.27643966674804687, 5.815616130828857421, 0, 0, -0.23166084289550781, 0.972796618938446044, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+215, 292549, 1, 14, 14, '0', 0, 0, 1155.876708984375, -4146.46728515625, 21.22748184204101562, 5.396428108215332031, 0.016949176788330078, -0.04012966156005859, -0.427734375, 0.902854144573211669, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+216, 292549, 1, 14, 14, '0', 0, 0, 1248.857666015625, -4154.09375, 26.79288864135742187, 1.641946911811828613, 0, 0, 0.731809616088867187, 0.681509137153625488, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+217, 292549, 1, 14, 14, '0', 0, 0, 1171.1163330078125, -4239.31787109375, 22.65429306030273437, 5.815616130828857421, 0, 0, -0.23166084289550781, 0.972796618938446044, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+218, 292549, 1, 14, 14, '0', 0, 0, 1174.310791015625, -4239.5556640625, 23.07766151428222656, 0.212071418762207031, -0.0117349624633789, -0.07427501678466796, 0.104123115539550781, 0.991717636585235595, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+219, 292549, 1, 14, 14, '0', 0, 0, 1208.232666015625, -4175.73291015625, 24.05777931213378906, 5.00761270523071289, 0.033525466918945312, -0.05630207061767578, -0.59290790557861328, 0.802599728107452392, 120, 255, 1, 45745), -- Hay Bale (Area: Durotar - Difficulty: 0)
(@OGUID+220, 325994, 1, 14, 14, '0', 0, 0, 1173.7535400390625, -4087.192626953125, 17.52020645141601562, 5.279533863067626953, 0.014568328857421875, -0.01856231689453125, -0.48071670532226562, 0.876558423042297363, 120, 255, 1, 45745), -- Nightborne Arcwine Tent (Area: Durotar - Difficulty: 0)
(@OGUID+221, 325995, 1, 14, 14, '0', 0, 0, 1178.9722900390625, -4082.967041015625, 17.90609931945800781, 5.108705043792724609, 0, 0, -0.55406570434570312, 0.832472920417785644, 120, 255, 1, 45745), -- Nightborne Banner (Area: Durotar - Difficulty: 0)
(@OGUID+222, 325995, 1, 14, 14, '0', 0, 0, 1167.548583984375, -4090.354248046875, 17.29179000854492187, 5.370433807373046875, 0, 0, -0.44069766998291015, 0.897655606269836425, 120, 255, 1, 45745), -- Nightborne Banner (Area: Durotar - Difficulty: 0)
(@OGUID+223, 325998, 1, 14, 14, '0', 0, 0, 1156.76220703125, -4119.064453125, 20.38928794860839843, 6.094967842102050781, -0.03520488739013671, -0.08049678802490234, -0.09589862823486328, 0.991506099700927734, 120, 255, 1, 45745), -- Zandalari Tent (Area: Durotar - Difficulty: 0)
(@OGUID+224, 326051, 1, 14, 14, '0', 0, 0, 1246.7291259765625, -4156.7275390625, 26.546966552734375, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- Outhouse (Area: Durotar - Difficulty: 0)
(@OGUID+225, 326051, 1, 14, 14, '0', 0, 0, 1247.6024169921875, -4151.90283203125, 26.83595848083496093, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 45745), -- Outhouse (Area: Durotar - Difficulty: 0)
(@OGUID+226, 326051, 1, 14, 14, '0', 0, 0, 1243.8489990234375, -4161.15966796875, 26.48284530639648437, 2.413209438323974609, 0, 0, 0.934412002563476562, 0.35619404911994934, 120, 255, 1, 45745), -- Outhouse (Area: Durotar - Difficulty: 0)
(@OGUID+227, 326067, 1, 14, 14, '0', 0, 0, 1221.7100830078125, -4110.36962890625, 24.05058097839355468, 3.158229827880859375, 0.031802654266357421, -0.01746749877929687, -0.99931144714355468, 0.007751224562525749, 120, 255, 1, 45745), -- Highmountain Tent (Area: Durotar - Difficulty: 0)
(@OGUID+228, 326072, 1, 14, 14, '0', 0, 0, 1219.0711669921875, -4104.15087890625, 23.62022018432617187, 3.585670232772827148, 0, 0, -0.97545051574707031, 0.220218762755393981, 120, 255, 1, 45745), -- Highmountain Banner (Area: Durotar - Difficulty: 0)
(@OGUID+229, 326073, 1, 14, 14, '0', 0, 0, 1223.361083984375, -4109.09228515625, 24.05807304382324218, 6.041737556457519531, 0, 0, -0.12043094635009765, 0.992721736431121826, 120, 255, 1, 45745), -- Highmountain Pot (Area: Durotar - Difficulty: 0)
(@OGUID+230, 326076, 1, 14, 14, '0', 0, 0, 1224.251708984375, -4112.85595703125, 24.51909828186035156, 6.041737556457519531, 0, 0, -0.12043094635009765, 0.992721736431121826, 120, 255, 1, 45745), -- Highmountain Pot (Area: Durotar - Difficulty: 0)
(@OGUID+231, 326077, 1, 14, 14, '0', 0, 0, 1218.0867919921875, -4125.09228515625, 24.19965362548828125, 1.114475965499877929, -0.01489973068237304, -0.05338954925537109, 0.526729583740234375, 0.848223745822906494, 120, 255, 1, 45745), -- Ogre Tent (Area: Durotar - Difficulty: 0)
(@OGUID+232, 326078, 1, 14, 14, '0', 0, 0, 1217.96533203125, -4127.0537109375, 24.08159828186035156, 5.017419815063476562, 0, 0, -0.59147167205810546, 0.806325793266296386, 120, 255, 1, 45745), -- Ogre Container (Area: Durotar - Difficulty: 0)
(@OGUID+233, 326078, 1, 14, 14, '0', 0, 0, 1219.4444580078125, -4123.7880859375, 24.41840362548828125, 0.08190155029296875, 0, 0, 0.0409393310546875, 0.99916166067123413, 120, 255, 1, 45745), -- Ogre Container (Area: Durotar - Difficulty: 0)
(@OGUID+234, 326104, 1, 14, 14, '0', 0, 0, 1193.0208740234375, -4083.473876953125, 19.12903213500976562, 4.667319774627685546, 0.022777080535888671, -0.03143501281738281, -0.72217559814453125, 0.690619587898254394, 120, 255, 1, 45745), -- Frostwolf Tent (Area: Durotar - Difficulty: 0)
(@OGUID+235, 326105, 1, 14, 14, '0', 0, 0, 1188.15625, -4085.626708984375, 18.43210411071777343, 6.194991588592529296, -0.00144624710083007, -0.03811073303222656, -0.04404163360595703, 0.998301446437835693, 120, 255, 1, 45745), -- Frostwolf Barrel (Area: Durotar - Difficulty: 0)
(@OGUID+236, 326105, 1, 14, 14, '0', 0, 0, 1201.017333984375, -4083.833251953125, 19.99400901794433593, 6.194991588592529296, -0.00144624710083007, -0.03811073303222656, -0.04404163360595703, 0.998301446437835693, 120, 255, 1, 45745), -- Frostwolf Barrel (Area: Durotar - Difficulty: 0)
(@OGUID+237, 326105, 1, 14, 14, '0', 0, 0, 1199.314208984375, -4084.56591796875, 18.88818359375, 6.194991588592529296, -0.00144624710083007, -0.03811073303222656, -0.04404163360595703, 0.998301446437835693, 120, 255, 1, 45745), -- Frostwolf Barrel (Area: Durotar - Difficulty: 0)
(@OGUID+238, 326106, 1, 14, 14, '0', 0, 0, 1134.640625, -4170.8193359375, 21.01600265502929687, 0.261188268661499023, -0.02238416671752929, -0.02194023132324218, 0.129691123962402343, 0.991058886051177978, 120, 255, 1, 45745), -- Pandaren Noodle Cart (Area: Durotar - Difficulty: 0)
(@OGUID+239, 326138, 1, 14, 14, '0', 0, 0, 1191.6822509765625, -4168.439453125, 21.86184310913085937, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+240, 326138, 1, 14, 14, '0', 0, 0, 1211.3941650390625, -4117.06787109375, 23.30309104919433593, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+241, 326138, 1, 14, 14, '0', 0, 0, 1168.236083984375, -4130.0537109375, 21.35139274597167968, 1.762728452682495117, 0, 0, 0.771607398986816406, 0.636099040508270263, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+242, 326138, 1, 14, 14, '0', 0, 0, 1199.90625, -4093.453125, 20.19466018676757812, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+243, 326138, 1, 14, 14, '0', 0, 0, 1188.3038330078125, -4136.455078125, 21.77704238891601562, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+244, 326138, 1, 14, 14, '0', 0, 0, 1201.5572509765625, -4134.6337890625, 22.6997528076171875, 5.941990375518798828, 0, 0, -0.16977119445800781, 0.985483527183532714, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+245, 326138, 1, 14, 14, '0', 0, 0, 1181.68408203125, -4111.3037109375, 20.16932106018066406, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+246, 326138, 1, 14, 14, '0', 0, 0, 1176.4375, -4157.3662109375, 21.84375, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+247, 326138, 1, 14, 14, '0', 0, 0, 1195.3367919921875, -4164.94970703125, 22.02010536193847656, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+248, 326138, 1, 14, 14, '0', 0, 0, 1174.3836669921875, -4145.20654296875, 21.53821754455566406, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- Party Table (Area: Durotar - Difficulty: 0)
(@OGUID+249, 326139, 1, 14, 14, '0', 0, 0, 1168.0694580078125, -4130.2255859375, 22.39730262756347656, 1.832538485527038574, 0, 0, 0.793335914611816406, 0.608784139156341552, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+250, 326139, 1, 14, 14, '0', 0, 0, 1199.6927490234375, -4093.017333984375, 21.24505233764648437, 3.980001688003540039, 0, 0, -0.91341304779052734, 0.407033890485763549, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+251, 326139, 1, 14, 14, '0', 0, 0, 1174.154541015625, -4145.41845703125, 22.61979293823242187, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+252, 326139, 1, 14, 14, '0', 0, 0, 1191.2864990234375, -4168.80712890625, 22.94851303100585937, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+253, 326139, 1, 14, 14, '0', 0, 0, 1167.8680419921875, -4129.814453125, 22.39557647705078125, 2.984450340270996093, 0, 0, 0.996914863586425781, 0.078490354120731353, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+254, 326139, 1, 14, 14, '0', 0, 0, 1191.98095703125, -4168.48095703125, 22.94320297241210937, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+255, 326139, 1, 14, 14, '0', 0, 0, 1176.7117919921875, -4157.90087890625, 23.02410316467285156, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+256, 326139, 1, 14, 14, '0', 0, 0, 1176.1353759765625, -4157.04345703125, 23.01053810119628906, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+257, 326139, 1, 14, 14, '0', 0, 0, 1174.8524169921875, -4145.17529296875, 22.62784957885742187, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+258, 326139, 1, 14, 14, '0', 0, 0, 1182.0555419921875, -4111.109375, 21.20943832397460937, 3.959301948547363281, 0, 0, -0.91757678985595703, 0.397558629512786865, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+259, 326139, 1, 14, 14, '0', 0, 0, 1195.642333984375, -4164.76904296875, 23.14155960083007812, 3.016298294067382812, 0, 0, 0.998038291931152343, 0.062606245279312133, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+260, 326139, 1, 14, 14, '0', 0, 0, 1195.263916015625, -4164.533203125, 23.10936355590820312, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+261, 326139, 1, 14, 14, '0', 0, 0, 1201.73095703125, -4134.95849609375, 23.764373779296875, 5.889630794525146484, 0, 0, -0.19550991058349609, 0.980701744556427001, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+262, 326139, 1, 14, 14, '0', 0, 0, 1201.2413330078125, -4134.81591796875, 23.74793434143066406, 3.63816070556640625, 0, 0, -0.96933555603027343, 0.245740845799446105, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+263, 326139, 1, 14, 14, '0', 0, 0, 1188.8316650390625, -4136.361328125, 22.87487220764160156, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+264, 326139, 1, 14, 14, '0', 0, 0, 1188.545166015625, -4136.91650390625, 22.84414100646972656, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+265, 326139, 1, 14, 14, '0', 0, 0, 1211.5504150390625, -4116.76416015625, 24.41340065002441406, 4.068844795227050781, 0, 0, -0.89443683624267578, 0.447194308042526245, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+266, 326139, 1, 14, 14, '0', 0, 0, 1211.5052490234375, -4117.40625, 24.399658203125, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+267, 326139, 1, 14, 14, '0', 0, 0, 1200.1129150390625, -4093.263916015625, 21.29027938842773437, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+268, 326139, 1, 14, 14, '0', 0, 0, 1199.626708984375, -4093.611083984375, 21.26465797424316406, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+269, 326139, 1, 14, 14, '0', 0, 0, 1168.5728759765625, -4130.1806640625, 22.40348052978515625, 2.024524688720703125, 0, 0, 0.848032951354980468, 0.529943466186523437, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+270, 326139, 1, 14, 14, '0', 0, 0, 1168.2847900390625, -4129.734375, 22.40000152587890625, 5.183575630187988281, 0, 0, -0.52252101898193359, 0.852626383304595947, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+271, 326139, 1, 14, 14, '0', 0, 0, 1191.0850830078125, -4168.26904296875, 22.92492294311523437, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+272, 326139, 1, 14, 14, '0', 0, 0, 1191.609375, -4168.20654296875, 22.92678451538085937, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+273, 326139, 1, 14, 14, '0', 0, 0, 1176.2083740234375, -4157.578125, 23.02436256408691406, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+274, 326139, 1, 14, 14, '0', 0, 0, 1174.657958984375, -4145.7412109375, 22.63218307495117187, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+275, 326139, 1, 14, 14, '0', 0, 0, 1174.0816650390625, -4144.8837890625, 22.596435546875, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+276, 326139, 1, 14, 14, '0', 0, 0, 1181.5555419921875, -4110.87353515625, 21.21795082092285156, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+277, 326139, 1, 14, 14, '0', 0, 0, 1181.9617919921875, -4111.70166015625, 21.21451377868652343, 0.518747806549072265, 0, 0, 0.256475448608398437, 0.966550707817077636, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+278, 326139, 1, 14, 14, '0', 0, 0, 1176.90625, -4157.3349609375, 23.00159645080566406, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+279, 326139, 1, 14, 14, '0', 0, 0, 1195.107666015625, -4165.02978515625, 23.09685134887695312, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+280, 326139, 1, 14, 14, '0', 0, 0, 1195.4305419921875, -4165.41162109375, 23.12318801879882812, 3.700104713439941406, 0, 0, -0.96126079559326171, 0.275640487670898437, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+281, 326139, 1, 14, 14, '0', 0, 0, 1201.970458984375, -4134.34716796875, 23.774322509765625, 3.533439397811889648, 0, 0, -0.98086833953857421, 0.194672256708145141, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+282, 326139, 1, 14, 14, '0', 0, 0, 1181.4375, -4111.486328125, 21.23317909240722656, 0.769762754440307617, 0, 0, 0.375449180603027343, 0.926842987537384033, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+283, 326139, 1, 14, 14, '0', 0, 0, 1187.875, -4136.64599609375, 22.82799720764160156, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+284, 326139, 1, 14, 14, '0', 0, 0, 1201.3629150390625, -4134.2119140625, 23.7636566162109375, 5.167458057403564453, 0, 0, -0.52937507629394531, 0.848387897014617919, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+285, 326139, 1, 14, 14, '0', 0, 0, 1200.1319580078125, -4093.71533203125, 21.23446273803710937, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+286, 326139, 1, 14, 14, '0', 0, 0, 1188.2569580078125, -4136.12353515625, 22.854034423828125, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+287, 326139, 1, 14, 14, '0', 0, 0, 1210.9739990234375, -4116.6943359375, 24.34250831604003906, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+288, 326139, 1, 14, 14, '0', 0, 0, 1210.8697509765625, -4117.23291015625, 24.38750267028808593, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 45745), -- Alcohol-Free Brewfest Sampler (Area: Durotar - Difficulty: 0)
(@OGUID+289, 326705, 1, 14, 14, '0', 0, 0, 1160.3038330078125, -4167.142578125, 21.07406234741210937, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+290, 326705, 1, 14, 14, '0', 0, 0, 1163.8992919921875, -4108.11279296875, 19.32998085021972656, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+291, 326705, 1, 14, 14, '0', 0, 0, 1209.6319580078125, -4145.95654296875, 22.543792724609375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+292, 326705, 1, 14, 14, '0', 0, 0, 1206.9114990234375, -4090.890625, 20.89776802062988281, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+293, 326705, 1, 14, 14, '0', 0, 0, 1213.8507080078125, -4099.5244140625, 22.38380050659179687, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+294, 326705, 1, 14, 14, '0', 0, 0, 1152.5208740234375, -4157.26904296875, 20.64238929748535156, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+295, 326705, 1, 14, 14, '0', 0, 0, 1187.7413330078125, -4119.111328125, 21.52308464050292968, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+296, 326705, 1, 14, 14, '0', 0, 0, 1192.048583984375, -4123.84033203125, 22.26082229614257812, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+297, 326705, 1, 14, 14, '0', 0, 0, 1213.18408203125, -4138.111328125, 23.0437774658203125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+298, 326705, 1, 14, 14, '0', 0, 0, 1158.484375, -4128.53466796875, 21.22426223754882812, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+299, 326705, 1, 14, 14, '0', 0, 0, 1185.6458740234375, -4164.8994140625, 21.57254981994628906, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+300, 326705, 1, 14, 14, '0', 0, 0, 1191.87158203125, -4159.0400390625, 21.64283180236816406, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+301, 326705, 1, 14, 14, '0', 0, 0, 1157.7066650390625, -4136.07470703125, 21.3104400634765625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+302, 326705, 1, 14, 14, '0', 0, 0, 1176.861083984375, -4217.29541015625, 23.41971206665039062, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+303, 326705, 1, 14, 14, '0', 0, 0, 1183.203125, -4221.5224609375, 24.09801673889160156, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Brewfest Torch (Area: Durotar - Difficulty: 0)
(@OGUID+304, 326708, 1, 14, 14, '0', 0, 0, 1222.3177490234375, -4096.5244140625, 22.97561073303222656, 0.633452475070953369, -0.0630950927734375, -0.0199594497680664, 0.310817718505859375, 0.948162972927093505, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+305, 326708, 1, 14, 14, '0', 0, 0, 1208.3941650390625, -4149.8681640625, 22.4567718505859375, 2.556633710861206054, 0, 0, 0.957531929016113281, 0.288327276706695556, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+306, 326708, 1, 14, 14, '0', 0, 0, 1209.017333984375, -4084.895751953125, 21.17451667785644531, 3.965971231460571289, -0.00867986679077148, -0.04658317565917968, -0.91479778289794921, 0.401123046875, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+307, 326708, 1, 14, 14, '0', 0, 0, 1187.9444580078125, -4173.89404296875, 21.90042877197265625, 1.743061780929565429, -0.01884365081787109, -0.0082244873046875, 0.765261650085449218, 0.643390893936157226, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+308, 326708, 1, 14, 14, '0', 0, 0, 1155.4947509765625, -4108.173828125, 19.45225906372070312, 5.928020477294921875, -0.06035232543945312, -0.00873661041259765, -0.17742061614990234, 0.982243955135345458, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+309, 326708, 1, 14, 14, '0', 0, 0, 1151.7603759765625, -4138.251953125, 21.16435813903808593, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+310, 326708, 1, 14, 14, '0', 0, 0, 1166.482666015625, -4167.330078125, 21.07039833068847656, 0.826242983341217041, 0, 0, 0.401470184326171875, 0.915872097015380859, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+311, 326709, 1, 14, 14, '0', 0, 0, 1200.90625, -4163.84375, 22.51183509826660156, 5.566211700439453125, 0, 0, -0.35085773468017578, 0.936428785324096679, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+312, 326709, 1, 14, 14, '0', 0, 0, 1151.5885009765625, -4125.15966796875, 21.06639289855957031, 3.210317134857177734, 0, 0, -0.99940967559814453, 0.034355364739894866, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+313, 326709, 1, 14, 14, '0', 0, 0, 1163.1961669921875, -4092.27783203125, 17.43325233459472656, 2.47894597053527832, -0.01303815841674804, 0.014267921447753906, 0.945384979248046875, 0.325382381677627563, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+314, 326709, 1, 14, 14, '0', 0, 0, 1153.3072509765625, -4150.94775390625, 20.83297538757324218, 3.490700244903564453, 0, 0, -0.98480415344238281, 0.17366860806941986, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+315, 326709, 1, 14, 14, '0', 0, 0, 1173.09375, -4171.7431640625, 21.60127830505371093, 4.441921710968017578, 0.013788223266601562, -0.05063629150390625, -0.79430675506591796, 0.605245947837829589, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+316, 326710, 1, 14, 14, '0', 0, 0, 1154.732666015625, -4110.40478515625, 19.74267959594726562, 5.913068294525146484, -0.07373523712158203, -0.01727676391601562, -0.1855621337890625, 0.979709804058074951, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+317, 326710, 1, 14, 14, '0', 0, 0, 1218.2725830078125, -4132.9306640625, 23.81694984436035156, 5.64350128173828125, 0.06102609634399414, -0.04268074035644531, -0.31209468841552734, 0.947127819061279296, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+318, 326710, 1, 14, 14, '0', 0, 0, 1178.529541015625, -4081.953125, 17.92189979553222656, 5.079979896545410156, 0, 0, -0.5659646987915039, 0.824429452419281005, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+319, 326710, 1, 14, 14, '0', 0, 0, 1219.798583984375, -4130.6630859375, 24.16628646850585937, 5.734424114227294921, 0.062902450561523437, -0.03986263275146484, -0.26872920989990234, 0.960332691669464111, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+320, 326710, 1, 14, 14, '0', 0, 0, 1181.0677490234375, -4081.00341796875, 18.08133697509765625, 4.955861091613769531, 0, 0, -0.61600589752197265, 0.787741541862487792, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+321, 326710, 1, 14, 14, '0', 0, 0, 1153.0086669921875, -4115.22216796875, 20.45124053955078125, 5.950453758239746093, -0.04327583312988281, -0.01657676696777343, -0.16634845733642578, 0.984977483749389648, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+322, 326710, 1, 14, 14, '0', 0, 0, 1152.4097900390625, -4117.5244140625, 20.69107437133789062, 6.038239002227783203, -0.03565788269042968, -0.01436519622802734, -0.12269878387451171, 0.991699099540710449, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+323, 326710, 1, 14, 14, '0', 0, 0, 1171.3541259765625, -4085.30908203125, 17.49865913391113281, 5.280141830444335937, 0, 0, -0.48076057434082031, 0.876851916313171386, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+324, 326710, 1, 14, 14, '0', 0, 0, 1215.0572509765625, -4137.21337890625, 23.26137733459472656, 5.632528305053710937, 0.037496566772460937, -0.03366279602050781, -0.31833934783935546, 0.946636617183685302, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+325, 326710, 1, 14, 14, '0', 0, 0, 1209.9617919921875, -4147.77783203125, 22.38415718078613281, 2.522373914718627929, 0, 0, 0.952452659606933593, 0.304686605930328369, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+326, 326710, 1, 14, 14, '0', 0, 0, 1207.23095703125, -4083.33154296875, 20.9185791015625, 4.044252395629882812, 0.023983001708984375, -0.04281806945800781, -0.89884567260742187, 0.435508757829666137, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+327, 326710, 1, 14, 14, '0', 0, 0, 1224.7239990234375, -4101.19775390625, 23.61733436584472656, 0.371945858001708984, -0.03762578964233398, 0.007227897644042968, 0.185259819030761718, 0.981942415237426757, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+328, 326710, 1, 14, 14, '0', 0, 0, 1168.4635009765625, -4169.125, 21.14083671569824218, 0.864042639732360839, -0.03757572174072265, -0.0026559829711914, 0.418836593627929687, 0.90727996826171875, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+329, 326710, 1, 14, 14, '0', 0, 0, 1165.107666015625, -4090.364501953125, 17.35306739807128906, 5.410946846008300781, 0, 0, -0.4224252700805664, 0.906397759914398193, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+330, 326710, 1, 14, 14, '0', 0, 0, 1226.904541015625, -4111.30029296875, 24.84675216674804687, 0.011765378527343273, -0.03977537155151367, 0.006158828735351562, 0.006132125854492187, 0.999170839786529541, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+331, 326710, 1, 14, 14, '0', 0, 0, 1200.6875, -4079.671875, 19.96458625793457031, 4.221101760864257812, 0.02767038345336914, -0.04053306579589843, -0.85687446594238281, 0.513183772563934326, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+332, 326710, 1, 14, 14, '0', 0, 0, 1226.7586669921875, -4108.6943359375, 24.5869903564453125, 0.076451934874057769, -0.03995370864868164, 0.004869461059570312, 0.038439750671386718, 0.998449981212615966, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+333, 326710, 1, 14, 14, '0', 0, 0, 1202.8541259765625, -4080.88720703125, 20.27736091613769531, 4.221101760864257812, 0.02767038345336914, -0.04053306579589843, -0.85687446594238281, 0.513183772563934326, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+334, 326710, 1, 14, 14, '0', 0, 0, 1151.6805419921875, -4140.71533203125, 21.14700126647949218, 6.264788627624511718, 0, 0, -0.00919818878173828, 0.999957680702209472, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+335, 326710, 1, 14, 14, '0', 0, 0, 1151.810791015625, -4143.41845703125, 21.13012886047363281, 0.043294470757246017, 0, 0, 0.021645545959472656, 0.999765694141387939, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+336, 326710, 1, 14, 14, '0', 0, 0, 1191.1666259765625, -4078.163330078125, 18.84395790100097656, 4.965994834899902343, 0.021069049835205078, -0.00946426391601562, -0.6119394302368164, 0.790567278861999511, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+337, 326710, 1, 14, 14, '0', 0, 0, 1225.35595703125, -4119.11474609375, 25.16012001037597656, 5.926921844482421875, -0.01021480560302734, 0.004061698913574218, -0.17715740203857421, 0.984121143817901611, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+338, 326710, 1, 14, 14, '0', 0, 0, 1193.3489990234375, -4077.744873046875, 19.10667991638183593, 4.729961395263671875, 0.019807815551757812, -0.01187896728515625, -0.70076656341552734, 0.713016629219055175, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+339, 326710, 1, 14, 14, '0', 0, 0, 1220.9322509765625, -4128.53662109375, 24.39414405822753906, 5.784495353698730468, 0.06388092041015625, -0.03827571868896484, -0.24460506439208984, 0.966758787631988525, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+340, 326710, 1, 14, 14, '0', 0, 0, 1183.6961669921875, -4080.21875, 18.25495147705078125, 4.972775936126708984, 0.01308298110961914, -0.00330829620361328, -0.60931873321533203, 0.792810559272766113, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+341, 326710, 1, 14, 14, '0', 0, 0, 1222.0972900390625, -4126.1962890625, 24.65500068664550781, 5.838710308074951171, 0.021559715270996093, -0.01891899108886718, -0.21998500823974609, 0.975081443786621093, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+342, 326710, 1, 14, 14, '0', 0, 0, 1186.1319580078125, -4079.595458984375, 18.42324256896972656, 4.965994834899902343, 0.021069049835205078, -0.00946426391601562, -0.6119394302368164, 0.790567278861999511, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+343, 326710, 1, 14, 14, '0', 0, 0, 1153.8802490234375, -4112.87353515625, 20.14188575744628906, 5.949895381927490234, -0.05208158493041992, -0.01838588714599609, -0.16689872741699218, 0.984425842761993408, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+344, 326710, 1, 14, 14, '0', 0, 0, 1173.701416015625, -4083.932373046875, 17.63467216491699218, 5.102732658386230468, 0, 0, -0.556549072265625, 0.830814719200134277, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+345, 326710, 1, 14, 14, '0', 0, 0, 1216.6475830078125, -4135.05908203125, 23.53311920166015625, 5.632528305053710937, 0.037496566772460937, -0.03366279602050781, -0.31833934783935546, 0.946636617183685302, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+346, 326710, 1, 14, 14, '0', 0, 0, 1176.09033203125, -4082.89404296875, 17.77958297729492187, 5.079979896545410156, 0, 0, -0.5659646987915039, 0.824429452419281005, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+347, 326710, 1, 14, 14, '0', 0, 0, 1151.717041015625, -4122.63916015625, 20.98644447326660156, 0.0129185626283288, 0, 0, 0.006459236145019531, 0.999979138374328613, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+348, 326710, 1, 14, 14, '0', 0, 0, 1223.623291015625, -4098.8212890625, 23.26004791259765625, 0.501992523670196533, -0.03801584243774414, 0.004767417907714843, 0.2486724853515625, 0.967829585075378417, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+349, 326710, 1, 14, 14, '0', 0, 0, 1151.8194580078125, -4120.08349609375, 20.86469459533691406, 6.092520713806152343, 0, 0, -0.09518814086914062, 0.995459318161010742, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+350, 326710, 1, 14, 14, '0', 0, 0, 1190.5242919921875, -4173.35791015625, 22.05714225769042968, 1.804385185241699218, 0, 0, 0.784687995910644531, 0.619890928268432617, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+351, 326710, 1, 14, 14, '0', 0, 0, 1167.0885009765625, -4088.56591796875, 17.33317184448242187, 5.373526573181152343, 0, 0, -0.43930912017822265, 0.898335933685302734, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+352, 326710, 1, 14, 14, '0', 0, 0, 1169.1492919921875, -4086.944580078125, 17.38120460510253906, 5.284567832946777343, 0, 0, -0.47881889343261718, 0.877913713455200195, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+353, 326710, 1, 14, 14, '0', 0, 0, 1226.3177490234375, -4106.1005859375, 24.28898811340332031, 0.272668421268463134, -0.0402388572692871, 0.000932693481445312, 0.136054039001464843, 0.9898834228515625, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+354, 326710, 1, 14, 14, '0', 0, 0, 1205.1927490234375, -4082.057373046875, 20.61474609375, 4.221101760864257812, 0.02767038345336914, -0.04053306579589843, -0.85687446594238281, 0.513183772563934326, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+355, 326710, 1, 14, 14, '0', 0, 0, 1225.6146240234375, -4103.642578125, 23.94603919982910156, 0.293304353952407836, -0.03731250762939453, 0.008701324462890625, 0.146515846252441406, 0.988466084003448486, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+356, 326710, 1, 14, 14, '0', 0, 0, 1170.671875, -4170.5380859375, 21.35815048217773437, 1.032340645790100097, -0.04212379455566406, -0.01778984069824218, 0.493247032165527343, 0.868686676025390625, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+357, 326710, 1, 14, 14, '0', 0, 0, 1226.2257080078125, -4116.5693359375, 25.17003822326660156, 5.994946002960205078, -0.0122995376586914, 0.001423835754394531, -0.14361476898193359, 0.989556193351745605, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+358, 326710, 1, 14, 14, '0', 0, 0, 1195.9149169921875, -4077.907958984375, 19.38944435119628906, 4.501958370208740234, 0.0262451171875, -0.02285671234130859, -0.77711677551269531, 0.628393411636352539, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+359, 326710, 1, 14, 14, '0', 0, 0, 1226.8038330078125, -4113.8818359375, 24.99077796936035156, 6.182949542999267578, -0.0095381736755371, 0.005211830139160156, -0.05004787445068359, 0.998687684535980224, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+360, 326710, 1, 14, 14, '0', 0, 0, 1198.4635009765625, -4078.6025390625, 19.73458671569824218, 4.287338733673095703, 0.028997421264648437, -0.03959465026855468, -0.83941173553466796, 0.541275680065155029, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+361, 326710, 1, 14, 14, '0', 0, 0, 1152.640625, -4148.5, 20.99882888793945312, 0.293301761150360107, 0, 0, 0.14612579345703125, 0.989265978336334228, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+362, 326710, 1, 14, 14, '0', 0, 0, 1151.9879150390625, -4145.984375, 21.09777259826660156, 0.08971744030714035, 0, 0, 0.044843673706054687, 0.998994052410125732, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+363, 326710, 1, 14, 14, '0', 0, 0, 1223.2083740234375, -4123.8837890625, 24.90470123291015625, 5.846728324890136718, 0.001762866973876953, -0.0091409683227539, -0.21646022796630859, 0.976247072219848632, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+364, 326710, 1, 14, 14, '0', 0, 0, 1188.671875, -4078.8681640625, 18.60277748107910156, 4.965994834899902343, 0.021069049835205078, -0.00946426391601562, -0.6119394302368164, 0.790567278861999511, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+365, 326710, 1, 14, 14, '0', 0, 0, 1224.2379150390625, -4121.57275390625, 25.04964637756347656, 5.850917339324951171, -0.00546884536743164, -0.00114727020263671, -0.2144632339477539, 0.976716101169586181, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+366, 326711, 1, 14, 14, '0', 0, 0, 1246.001708984375, -4148.81787109375, 26.92018699645996093, 4.576684474945068359, 0, 0, -0.75342178344726562, 0.657537579536437988, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+367, 326711, 1, 14, 14, '0', 0, 0, 1240.361083984375, -4162.78125, 26.10763931274414062, 4.020020008087158203, 0.040850162506103515, -0.02119064331054687, -0.90456199645996093, 0.423851191997528076, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+368, 326711, 1, 14, 14, '0', 0, 0, 1179.7691650390625, -4232.77587890625, 23.85638618469238281, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+369, 326712, 1, 14, 14, '0', 0, 0, 1169.4305419921875, -4224.02587890625, 22.44408035278320312, 5.006129264831542968, 0.029574871063232421, -0.03989028930664062, -0.59472846984863281, 0.802391529083251953, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+370, 326714, 1, 14, 14, '0', 0, 0, 1230.26220703125, -4144.91650390625, 25.35247230529785156, 1.254625439643859863, -0.05862665176391601, -0.03569984436035156, 0.585892677307128906, 0.807476460933685302, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+371, 326714, 1, 14, 14, '0', 0, 0, 1224.1771240234375, -4152.9306640625, 23.55729103088378906, 1.133419513702392578, -0.06068086624145507, -0.03208351135253906, 0.53591156005859375, 0.841479241847991943, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+372, 326714, 1, 14, 14, '0', 0, 0, 1201.451416015625, -4183.361328125, 23.83646202087402343, 0.746263980865478515, -0.0639801025390625, -0.0296030044555664, 0.363348007202148437, 0.928982496261596679, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+373, 326714, 1, 14, 14, '0', 0, 0, 1221.28125, -4151.53125, 23.28504753112792968, 1.085174441337585449, -0.06143712997436523, -0.0306100845336914, 0.515459060668945312, 0.854160666465759277, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+374, 326714, 1, 14, 14, '0', 0, 0, 1199.3055419921875, -4181.03466796875, 23.37188720703125, 0.746263980865478515, -0.0639801025390625, -0.0296030044555664, 0.363348007202148437, 0.928982496261596679, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+375, 326714, 1, 14, 14, '0', 0, 0, 1215.798583984375, -4139.07275390625, 23.23427009582519531, 1.063872456550598144, -0.03925657272338867, -0.0089111328125, 0.507196426391601562, 0.860889852046966552, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+376, 326714, 1, 14, 14, '0', 0, 0, 1218.4757080078125, -4140.49853515625, 23.57233238220214843, 1.070296764373779296, -0.02289867401123046, -0.017608642578125, 0.509670257568359375, 0.859884798526763916, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+377, 326714, 1, 14, 14, '0', 0, 0, 1232.548583984375, -4157.19287109375, 25.109375, 1.05975961685180664, -0.03412532806396484, -0.02210521697998046, 0.504947662353515625, 0.86219179630279541, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+378, 326714, 1, 14, 14, '0', 0, 0, 1208.0399169921875, -4178.828125, 24.17127609252929687, 2.367144584655761718, -0.00236415863037109, 0.004133224487304687, 0.925946235656738281, 0.377625346183776855, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+379, 326714, 1, 14, 14, '0', 0, 0, 1229.7535400390625, -4155.68603515625, 24.62229537963867187, 1.105190634727478027, -0.06145238876342773, -0.0168771743774414, 0.524764060974121093, 0.848858892917633056, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+380, 326714, 1, 14, 14, '0', 0, 0, 1205.7760009765625, -4181.1630859375, 24.17322731018066406, 2.367144584655761718, -0.00236415863037109, 0.004133224487304687, 0.925946235656738281, 0.377625346183776855, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+381, 326714, 1, 14, 14, '0', 0, 0, 1165.376708984375, -4238.970703125, 21.81675529479980468, 0.869859933853149414, -0.04855871200561523, -0.00266838073730468, 0.421587944030761718, 0.905482470989227294, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+382, 326714, 1, 14, 14, '0', 0, 0, 1212.263916015625, -4147.3505859375, 22.65798568725585937, 1.200875043869018554, -0.03855419158935546, -0.01157665252685546, 0.564932823181152343, 0.824154376983642578, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+383, 326714, 1, 14, 14, '0', 0, 0, 1207.7603759765625, -4172.1875, 23.69666862487792968, 3.957872867584228515, 0.017980098724365234, -0.04546928405761718, -0.9167327880859375, 0.396497458219528198, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+384, 326714, 1, 14, 14, '0', 0, 0, 1176.6302490234375, -4241.1005859375, 23.34795570373535156, 1.989899635314941406, -0.04907703399658203, -0.05222225189208984, 0.837064743041992187, 0.542389988899230957, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+385, 326714, 1, 14, 14, '0', 0, 0, 1163.2847900390625, -4236.40478515625, 21.63939285278320312, 0.53510594367980957, -0.01319742202758789, 0.006329536437988281, 0.264446258544921875, 0.964289307594299316, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+386, 326714, 1, 14, 14, '0', 0, 0, 1242.8228759765625, -4148.31591796875, 26.84514236450195312, 1.313121795654296875, -0.03251934051513671, -0.02779674530029296, 0.60976409912109375, 0.791427552700042724, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+387, 326714, 1, 14, 14, '0', 0, 0, 1201.0225830078125, -4165.796875, 22.70091438293457031, 3.90763711929321289, 0.018980979919433593, -0.01956558227539062, -0.9272918701171875, 0.37334531545639038, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+388, 326714, 1, 14, 14, '0', 0, 0, 1164.314208984375, -4227.46728515625, 21.87195014953613281, 5.538869857788085937, 0.056564807891845703, -0.00668907165527343, -0.36377334594726562, 0.929744422435760498, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+389, 326714, 1, 14, 14, '0', 0, 0, 1173.546875, -4242.001953125, 22.93574333190917968, 1.696153879165649414, -0.05619096755981445, -0.04447746276855468, 0.748676300048828125, 0.659050941467285156, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+390, 326714, 1, 14, 14, '0', 0, 0, 1233.328125, -4145.8056640625, 25.91005134582519531, 1.287923574447631835, -0.05802392959594726, -0.03667068481445312, 0.599254608154296875, 0.797610461711883544, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+391, 326714, 1, 14, 14, '0', 0, 0, 1218.3472900390625, -4150.05029296875, 23.05268096923828125, 1.117441177368164062, -0.00591516494750976, -0.016326904296875, 0.529897689819335937, 0.847883760929107666, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+392, 326714, 1, 14, 14, '0', 0, 0, 1197.05908203125, -4178.68408203125, 22.89385414123535156, 0.746263980865478515, -0.0639801025390625, -0.0296030044555664, 0.363348007202148437, 0.928982496261596679, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+393, 326714, 1, 14, 14, '0', 0, 0, 1215.5191650390625, -4148.65625, 22.83680534362792968, 1.160894036293029785, -0.03453922271728515, -0.02524375915527343, 0.547818183898925781, 0.835502862930297851, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+394, 326714, 1, 14, 14, '0', 0, 0, 1194.94970703125, -4176.32275390625, 22.57561111450195312, 0.752347052097320556, -0.0638895034790039, -0.02979755401611328, 0.366171836853027343, 0.927873075008392333, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+395, 326714, 1, 14, 14, '0', 0, 0, 1221.2708740234375, -4141.88720703125, 23.93290138244628906, 1.132466316223144531, -0.03329944610595703, -0.0233316421508789, 0.535950660705566406, 0.843269646167755126, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+396, 326714, 1, 14, 14, '0', 0, 0, 1224.1666259765625, -4142.96533203125, 24.29731178283691406, 1.250104904174804687, -0.03187036514282226, -0.02524852752685546, 0.584595680236816406, 0.810305297374725341, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+397, 326714, 1, 14, 14, '0', 0, 0, 1227.0416259765625, -4154.3681640625, 24.00332450866699218, 1.133964300155639648, -0.07883119583129882, -0.03194713592529296, 0.53623199462890625, 0.839773893356323242, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+398, 326714, 1, 14, 14, '0', 0, 0, 1203.7708740234375, -4183.2724609375, 24.09170913696289062, 2.367144584655761718, -0.00236415863037109, 0.004133224487304687, 0.925946235656738281, 0.377625346183776855, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+399, 326714, 1, 14, 14, '0', 0, 0, 1162.2916259765625, -4233.35595703125, 21.66277503967285156, 0.109781250357627868, 0.012288570404052734, 0.009785652160644531, 0.054739952087402343, 0.998377084732055664, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+400, 326714, 1, 14, 14, '0', 0, 0, 1237.8367919921875, -4160.91162109375, 25.82291603088378906, 0.920627117156982421, -0.02415084838867187, -0.01584815979003906, 0.4439544677734375, 0.895583629608154296, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+401, 326714, 1, 14, 14, '0', 0, 0, 1210.0103759765625, -4174.2900390625, 24.08692741394042968, 3.957872867584228515, 0.017980098724365234, -0.04546928405761718, -0.9167327880859375, 0.396497458219528198, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+402, 326714, 1, 14, 14, '0', 0, 0, 1235.3055419921875, -4158.96337890625, 25.49479103088378906, 0.935477435588836669, -0.0354323387145996, -0.0199441909790039, 0.450429916381835937, 0.891885459423065185, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+403, 326714, 1, 14, 14, '0', 0, 0, 1210.0660400390625, -4176.68603515625, 24.249481201171875, 2.366029262542724609, 0.005297183990478515, 0.014570236206054687, 0.925635337829589843, 0.378099024295806884, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+404, 326714, 1, 14, 14, '0', 0, 0, 1178.6927490234375, -4239.07275390625, 23.74661064147949218, 2.645234584808349609, -0.03950786590576171, -0.02753734588623046, 0.968518257141113281, 0.244240090250968933, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+405, 326714, 1, 14, 14, '0', 0, 0, 1203.44970703125, -4168.17529296875, 23.03880119323730468, 3.957872867584228515, 0.017980098724365234, -0.04546928405761718, -0.9167327880859375, 0.396497458219528198, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+406, 326714, 1, 14, 14, '0', 0, 0, 1205.453125, -4170.08837890625, 23.35750198364257812, 3.957872867584228515, 0.017980098724365234, -0.04546928405761718, -0.9167327880859375, 0.396497458219528198, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+407, 326714, 1, 14, 14, '0', 0, 0, 1166.52783203125, -4225.51904296875, 22.1557464599609375, 5.342114925384521484, 0.022593975067138671, -0.04102611541748046, -0.45195579528808593, 0.890809953212738037, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+408, 326714, 1, 14, 14, '0', 0, 0, 1236.4583740234375, -4146.68212890625, 26.3146820068359375, 1.300769805908203125, -0.05778741836547851, -0.03704261779785156, 0.604365348815917968, 0.793744921684265136, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+409, 326714, 1, 14, 14, '0', 0, 0, 1239.5660400390625, -4147.50537109375, 26.63835334777832031, 1.315019845962524414, -0.05752182006835937, -0.03745365142822265, 0.610005378723144531, 0.789418756961822509, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+410, 326714, 1, 14, 14, '0', 0, 0, 1162.7222900390625, -4230.15478515625, 21.706024169921875, 5.902915000915527343, -0.00566530227661132, -0.00207901000976562, -0.18900394439697265, 0.981957793235778808, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+411, 326714, 1, 14, 14, '0', 0, 0, 1167.7847900390625, -4240.61279296875, 22.15450096130371093, 1.01648104190826416, -0.03000926971435546, -0.01204967498779296, 0.486500740051269531, 0.873081505298614501, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+412, 326714, 1, 14, 14, '0', 0, 0, 1170.515625, -4241.77783203125, 22.49571800231933593, 1.25540316104888916, -0.02835941314697265, -0.01554012298583984, 0.587084770202636718, 0.808879256248474121, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+413, 326714, 1, 14, 14, '0', 0, 0, 1193.171875, -4174.501953125, 22.32460975646972656, 0.752347052097320556, -0.0638895034790039, -0.02979755401611328, 0.366171836853027343, 0.927873075008392333, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+414, 326714, 1, 14, 14, '0', 0, 0, 1179.6024169921875, -4236.09716796875, 23.88064002990722656, 2.95117354393005371, 0, 0, 0.995471000671386718, 0.095065735280513763, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+415, 326714, 1, 14, 14, '0', 0, 0, 1227.1285400390625, -4143.92724609375, 24.82602310180664062, 1.262239694595336914, -0.04847240447998046, -0.03463172912597656, 0.589032173156738281, 0.805910766124725341, 120, 255, 1, 45745), -- Fence (Area: Durotar - Difficulty: 0)
(@OGUID+416, 327133, 1, 14, 14, '0', 0, 0, 1194.5208740234375, -4116.39404296875, 21.67856788635253906, 3.932958364486694335, -0.004730224609375, -0.02535629272460937, -0.92230892181396484, 0.38559165596961975, 120, 255, 1, 45745), -- Shoutbox (Area: Durotar - Difficulty: 0)
(@OGUID+417, 327134, 1, 14, 14, '0', 0, 0, 1193.1510009765625, -4120.44775390625, 24.22899246215820312, 2.314473628997802734, 0, 0, 0.915696144104003906, 0.401871353387832641, 120, 255, 1, 45745), -- Brewfest Ceremonial Keg (Area: Durotar - Difficulty: 0)
(@OGUID+418, 327165, 1, 14, 14, '0', 0, 0, 1213.4461669921875, -4134.05908203125, 23.30555534362792968, 1.251651644706726074, 0, 0, 0.585766792297363281, 0.810479640960693359, 120, 255, 1, 45745), -- Keg (Area: Durotar - Difficulty: 0)
(@OGUID+419, 327165, 1, 14, 14, '0', 0, 0, 1212.2274169921875, -4133.09716796875, 23.28819465637207031, 2.927161693572998046, 0, 0, 0.994257926940917968, 0.107010208070278167, 120, 255, 1, 45745), -- Keg (Area: Durotar - Difficulty: 0)
(@OGUID+420, 327165, 1, 14, 14, '0', 0, 0, 1212.1129150390625, -4134.63037109375, 23.18490028381347656, 6.208388328552246093, 0, 0, -0.03738975524902343, 0.999300777912139892, 120, 255, 1, 45745), -- Keg (Area: Durotar - Difficulty: 0)
(@OGUID+421, 327182, 1, 14, 14, '0', 0, 0, 1161.28125, -4199.94970703125, 22.76983833312988281, 0.928048253059387207, 0.007281303405761718, 0.005219459533691406, 0.447521209716796875, 0.894228458404541015, 120, 255, 1, 45745), -- Table (Area: Durotar - Difficulty: 0)
(@OGUID+422, 327538, 1, 14, 14, '0', 0, 0, 1160.6875, -4204.63037109375, 22.80034828186035156, 0.291971474885940551, 0, 0, 0.145467758178710937, 0.989363014698028564, 120, 255, 1, 45745), -- Flag (Area: Durotar - Difficulty: 0)
(@OGUID+423, 327539, 1, 14, 14, '0', 0, 0, 1159.546875, -4203.75537109375, 22.84201431274414062, 0.291971474885940551, 0, 0, 0.145467758178710937, 0.989363014698028564, 120, 255, 1, 45745), -- Flag (Area: Durotar - Difficulty: 0)
(@OGUID+424, 327540, 1, 14, 14, '0', 0, 0, 1158.3211669921875, -4202.75, 22.83680534362792968, 0.291971474885940551, 0, 0, 0.145467758178710937, 0.989363014698028564, 120, 255, 1, 45745), -- Flag (Area: Durotar - Difficulty: 0)
(@OGUID+425, 327541, 1, 14, 14, '0', 0, 0, 1157.157958984375, -4201.7568359375, 22.80555534362792968, 0.291971474885940551, 0, 0, 0.145467758178710937, 0.989363014698028564, 120, 255, 1, 45745), -- Flag (Area: Durotar - Difficulty: 0)
(@OGUID+426, 328424, 1, 14, 14, '0', 0, 0, 1163.251708984375, -4120.18408203125, 20.75914573669433593, 6.133948802947998046, -0.02899646759033203, 0.002473831176757812, -0.0745086669921875, 0.996795654296875, 120, 255, 1, 45745); -- Zandalari Tent (Area: Durotar - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid` BETWEEN @CGUID+0 AND @CGUID+112;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(24, @CGUID+0), 
(24, @CGUID+1), 
(24, @CGUID+2), 
(24, @CGUID+3), 
(24, @CGUID+4), 
(24, @CGUID+5), 
(24, @CGUID+6), 
(24, @CGUID+7), 
(24, @CGUID+8), 
(24, @CGUID+9), 
(24, @CGUID+10),
(24, @CGUID+11),
(24, @CGUID+12),
(24, @CGUID+13),
(24, @CGUID+14),
(24, @CGUID+15),
(24, @CGUID+16),
(24, @CGUID+17),
(24, @CGUID+18),
(24, @CGUID+19),
(24, @CGUID+20),
(24, @CGUID+21),
(24, @CGUID+22),
(24, @CGUID+23),
(24, @CGUID+24),
(24, @CGUID+25),
(24, @CGUID+26),
(24, @CGUID+27),
(24, @CGUID+28),
(24, @CGUID+29),
(24, @CGUID+30),
(24, @CGUID+31),
(24, @CGUID+32),
(24, @CGUID+33),
(24, @CGUID+34),
(24, @CGUID+35),
(24, @CGUID+36),
(24, @CGUID+37),
(24, @CGUID+38),
(24, @CGUID+39),
(24, @CGUID+40),
(24, @CGUID+41),
(24, @CGUID+42),
(24, @CGUID+43),
(24, @CGUID+44),
(24, @CGUID+45),
(24, @CGUID+46),
(24, @CGUID+47),
(24, @CGUID+48),
(24, @CGUID+49),
(24, @CGUID+50),
(24, @CGUID+51),
(24, @CGUID+52),
(24, @CGUID+53),
(24, @CGUID+54),
(24, @CGUID+55),
(24, @CGUID+56),
(24, @CGUID+57),
(24, @CGUID+58),
(24, @CGUID+59),
(24, @CGUID+60),
(24, @CGUID+61),
(24, @CGUID+62),
(24, @CGUID+63),
(24, @CGUID+64),
(24, @CGUID+65),
(24, @CGUID+66),
(24, @CGUID+67),
(24, @CGUID+68),
(24, @CGUID+69),
(24, @CGUID+70),
(24, @CGUID+71),
(24, @CGUID+72),
(24, @CGUID+73),
(24, @CGUID+74),
(24, @CGUID+75),
(24, @CGUID+76),
(24, @CGUID+77),
(24, @CGUID+78),
(24, @CGUID+79),
(24, @CGUID+80),
(24, @CGUID+81),
(24, @CGUID+82),
(24, @CGUID+83),
(24, @CGUID+84),
(24, @CGUID+85),
(24, @CGUID+86),
(24, @CGUID+87),
(24, @CGUID+88),
(24, @CGUID+89),
(24, @CGUID+90),
(24, @CGUID+91),
(24, @CGUID+92),
(24, @CGUID+93),
(24, @CGUID+94),
(24, @CGUID+95),
(24, @CGUID+96),
(24, @CGUID+97),
(24, @CGUID+98),
(24, @CGUID+99),
(24, @CGUID+100),
(24, @CGUID+101),
(24, @CGUID+102),
(24, @CGUID+103),
(24, @CGUID+104),
(24, @CGUID+105),
(24, @CGUID+106),
(24, @CGUID+107),
(24, @CGUID+108),
(24, @CGUID+109),
(24, @CGUID+110),
(24, @CGUID+111),
(24, @CGUID+112);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=24 AND `guid` BETWEEN @OGUID+0 AND @OGUID+426;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(24, @OGUID+0),
(24, @OGUID+1),
(24, @OGUID+2),
(24, @OGUID+3),
(24, @OGUID+4),
(24, @OGUID+5),
(24, @OGUID+6),
(24, @OGUID+7),
(24, @OGUID+8),
(24, @OGUID+9),
(24, @OGUID+10),
(24, @OGUID+11),
(24, @OGUID+12),
(24, @OGUID+13),
(24, @OGUID+14),
(24, @OGUID+15),
(24, @OGUID+16),
(24, @OGUID+17),
(24, @OGUID+18),
(24, @OGUID+19),
(24, @OGUID+20),
(24, @OGUID+21),
(24, @OGUID+22),
(24, @OGUID+23),
(24, @OGUID+24),
(24, @OGUID+25),
(24, @OGUID+26),
(24, @OGUID+27),
(24, @OGUID+28),
(24, @OGUID+29),
(24, @OGUID+30),
(24, @OGUID+31),
(24, @OGUID+32),
(24, @OGUID+33),
(24, @OGUID+34),
(24, @OGUID+35),
(24, @OGUID+36),
(24, @OGUID+37),
(24, @OGUID+38),
(24, @OGUID+39),
(24, @OGUID+40),
(24, @OGUID+41),
(24, @OGUID+42),
(24, @OGUID+43),
(24, @OGUID+44),
(24, @OGUID+45),
(24, @OGUID+46),
(24, @OGUID+47),
(24, @OGUID+48),
(24, @OGUID+49),
(24, @OGUID+50),
(24, @OGUID+51),
(24, @OGUID+52),
(24, @OGUID+53),
(24, @OGUID+54),
(24, @OGUID+55),
(24, @OGUID+56),
(24, @OGUID+57),
(24, @OGUID+58),
(24, @OGUID+59),
(24, @OGUID+60),
(24, @OGUID+61),
(24, @OGUID+62),
(24, @OGUID+63),
(24, @OGUID+64),
(24, @OGUID+65),
(24, @OGUID+66),
(24, @OGUID+67),
(24, @OGUID+68),
(24, @OGUID+69),
(24, @OGUID+70),
(24, @OGUID+71),
(24, @OGUID+72),
(24, @OGUID+73),
(24, @OGUID+74),
(24, @OGUID+75),
(24, @OGUID+76),
(24, @OGUID+77),
(24, @OGUID+78),
(24, @OGUID+79),
(24, @OGUID+80),
(24, @OGUID+81),
(24, @OGUID+82),
(24, @OGUID+83),
(24, @OGUID+84),
(24, @OGUID+85),
(24, @OGUID+86),
(24, @OGUID+87),
(24, @OGUID+88),
(24, @OGUID+89),
(24, @OGUID+90),
(24, @OGUID+91),
(24, @OGUID+92),
(24, @OGUID+93),
(24, @OGUID+94),
(24, @OGUID+95),
(24, @OGUID+96),
(24, @OGUID+97),
(24, @OGUID+98),
(24, @OGUID+99),
(24, @OGUID+100),
(24, @OGUID+101),
(24, @OGUID+102),
(24, @OGUID+103),
(24, @OGUID+104),
(24, @OGUID+105),
(24, @OGUID+106),
(24, @OGUID+107),
(24, @OGUID+108),
(24, @OGUID+109),
(24, @OGUID+110),
(24, @OGUID+111),
(24, @OGUID+112),
(24, @OGUID+113),
(24, @OGUID+114),
(24, @OGUID+115),
(24, @OGUID+116),
(24, @OGUID+117),
(24, @OGUID+118),
(24, @OGUID+119),
(24, @OGUID+120),
(24, @OGUID+121),
(24, @OGUID+122),
(24, @OGUID+123),
(24, @OGUID+124),
(24, @OGUID+125),
(24, @OGUID+126),
(24, @OGUID+127),
(24, @OGUID+128),
(24, @OGUID+129),
(24, @OGUID+130),
(24, @OGUID+131),
(24, @OGUID+132),
(24, @OGUID+133),
(24, @OGUID+134),
(24, @OGUID+135),
(24, @OGUID+136),
(24, @OGUID+137),
(24, @OGUID+138),
(24, @OGUID+139),
(24, @OGUID+140),
(24, @OGUID+141),
(24, @OGUID+142),
(24, @OGUID+143),
(24, @OGUID+144),
(24, @OGUID+145),
(24, @OGUID+146),
(24, @OGUID+147),
(24, @OGUID+148),
(24, @OGUID+149),
(24, @OGUID+150),
(24, @OGUID+151),
(24, @OGUID+152),
(24, @OGUID+153),
(24, @OGUID+154),
(24, @OGUID+155),
(24, @OGUID+156),
(24, @OGUID+157),
(24, @OGUID+158),
(24, @OGUID+159),
(24, @OGUID+160),
(24, @OGUID+161),
(24, @OGUID+162),
(24, @OGUID+163),
(24, @OGUID+164),
(24, @OGUID+165),
(24, @OGUID+166),
(24, @OGUID+167),
(24, @OGUID+168),
(24, @OGUID+169),
(24, @OGUID+170),
(24, @OGUID+171),
(24, @OGUID+172),
(24, @OGUID+173),
(24, @OGUID+174),
(24, @OGUID+175),
(24, @OGUID+176),
(24, @OGUID+177),
(24, @OGUID+178),
(24, @OGUID+179),
(24, @OGUID+180),
(24, @OGUID+181),
(24, @OGUID+182),
(24, @OGUID+183),
(24, @OGUID+184),
(24, @OGUID+185),
(24, @OGUID+186),
(24, @OGUID+187),
(24, @OGUID+188),
(24, @OGUID+189),
(24, @OGUID+190),
(24, @OGUID+191),
(24, @OGUID+192),
(24, @OGUID+193),
(24, @OGUID+194),
(24, @OGUID+195),
(24, @OGUID+196),
(24, @OGUID+197),
(24, @OGUID+198),
(24, @OGUID+199),
(24, @OGUID+200),
(24, @OGUID+201),
(24, @OGUID+202),
(24, @OGUID+203),
(24, @OGUID+204),
(24, @OGUID+205),
(24, @OGUID+206),
(24, @OGUID+207),
(24, @OGUID+208),
(24, @OGUID+209),
(24, @OGUID+210),
(24, @OGUID+211),
(24, @OGUID+212),
(24, @OGUID+213),
(24, @OGUID+214),
(24, @OGUID+215),
(24, @OGUID+216),
(24, @OGUID+217),
(24, @OGUID+218),
(24, @OGUID+219),
(24, @OGUID+220),
(24, @OGUID+221),
(24, @OGUID+222),
(24, @OGUID+223),
(24, @OGUID+224),
(24, @OGUID+225),
(24, @OGUID+226),
(24, @OGUID+227),
(24, @OGUID+228),
(24, @OGUID+229),
(24, @OGUID+230),
(24, @OGUID+231),
(24, @OGUID+232),
(24, @OGUID+233),
(24, @OGUID+234),
(24, @OGUID+235),
(24, @OGUID+236),
(24, @OGUID+237),
(24, @OGUID+238),
(24, @OGUID+239),
(24, @OGUID+240),
(24, @OGUID+241),
(24, @OGUID+242),
(24, @OGUID+243),
(24, @OGUID+244),
(24, @OGUID+245),
(24, @OGUID+246),
(24, @OGUID+247),
(24, @OGUID+248),
(24, @OGUID+249),
(24, @OGUID+250),
(24, @OGUID+251),
(24, @OGUID+252),
(24, @OGUID+253),
(24, @OGUID+254),
(24, @OGUID+255),
(24, @OGUID+256),
(24, @OGUID+257),
(24, @OGUID+258),
(24, @OGUID+259),
(24, @OGUID+260),
(24, @OGUID+261),
(24, @OGUID+262),
(24, @OGUID+263),
(24, @OGUID+264),
(24, @OGUID+265),
(24, @OGUID+266),
(24, @OGUID+267),
(24, @OGUID+268),
(24, @OGUID+269),
(24, @OGUID+270),
(24, @OGUID+271),
(24, @OGUID+272),
(24, @OGUID+273),
(24, @OGUID+274),
(24, @OGUID+275),
(24, @OGUID+276),
(24, @OGUID+277),
(24, @OGUID+278),
(24, @OGUID+279),
(24, @OGUID+280),
(24, @OGUID+281),
(24, @OGUID+282),
(24, @OGUID+283),
(24, @OGUID+284),
(24, @OGUID+285),
(24, @OGUID+286),
(24, @OGUID+287),
(24, @OGUID+288),
(24, @OGUID+289),
(24, @OGUID+290),
(24, @OGUID+291),
(24, @OGUID+292),
(24, @OGUID+293),
(24, @OGUID+294),
(24, @OGUID+295),
(24, @OGUID+296),
(24, @OGUID+297),
(24, @OGUID+298),
(24, @OGUID+299),
(24, @OGUID+300),
(24, @OGUID+301),
(24, @OGUID+302),
(24, @OGUID+303),
(24, @OGUID+304),
(24, @OGUID+305),
(24, @OGUID+306),
(24, @OGUID+307),
(24, @OGUID+308),
(24, @OGUID+309),
(24, @OGUID+310),
(24, @OGUID+311),
(24, @OGUID+312),
(24, @OGUID+313),
(24, @OGUID+314),
(24, @OGUID+315),
(24, @OGUID+316),
(24, @OGUID+317),
(24, @OGUID+318),
(24, @OGUID+319),
(24, @OGUID+320),
(24, @OGUID+321),
(24, @OGUID+322),
(24, @OGUID+323),
(24, @OGUID+324),
(24, @OGUID+325),
(24, @OGUID+326),
(24, @OGUID+327),
(24, @OGUID+328),
(24, @OGUID+329),
(24, @OGUID+330),
(24, @OGUID+331),
(24, @OGUID+332),
(24, @OGUID+333),
(24, @OGUID+334),
(24, @OGUID+335),
(24, @OGUID+336),
(24, @OGUID+337),
(24, @OGUID+338),
(24, @OGUID+339),
(24, @OGUID+340),
(24, @OGUID+341),
(24, @OGUID+342),
(24, @OGUID+343),
(24, @OGUID+344),
(24, @OGUID+345),
(24, @OGUID+346),
(24, @OGUID+347),
(24, @OGUID+348),
(24, @OGUID+349),
(24, @OGUID+350),
(24, @OGUID+351),
(24, @OGUID+352),
(24, @OGUID+353),
(24, @OGUID+354),
(24, @OGUID+355),
(24, @OGUID+356),
(24, @OGUID+357),
(24, @OGUID+358),
(24, @OGUID+359),
(24, @OGUID+360),
(24, @OGUID+361),
(24, @OGUID+362),
(24, @OGUID+363),
(24, @OGUID+364),
(24, @OGUID+365),
(24, @OGUID+366),
(24, @OGUID+367),
(24, @OGUID+368),
(24, @OGUID+369),
(24, @OGUID+370),
(24, @OGUID+371),
(24, @OGUID+372),
(24, @OGUID+373),
(24, @OGUID+374),
(24, @OGUID+375),
(24, @OGUID+376),
(24, @OGUID+377),
(24, @OGUID+378),
(24, @OGUID+379),
(24, @OGUID+380),
(24, @OGUID+381),
(24, @OGUID+382),
(24, @OGUID+383),
(24, @OGUID+384),
(24, @OGUID+385),
(24, @OGUID+386),
(24, @OGUID+387),
(24, @OGUID+388),
(24, @OGUID+389),
(24, @OGUID+390),
(24, @OGUID+391),
(24, @OGUID+392),
(24, @OGUID+393),
(24, @OGUID+394),
(24, @OGUID+395),
(24, @OGUID+396),
(24, @OGUID+397),
(24, @OGUID+398),
(24, @OGUID+399),
(24, @OGUID+400),
(24, @OGUID+401),
(24, @OGUID+402),
(24, @OGUID+403),
(24, @OGUID+404),
(24, @OGUID+405),
(24, @OGUID+406),
(24, @OGUID+407),
(24, @OGUID+408),
(24, @OGUID+409),
(24, @OGUID+410),
(24, @OGUID+411),
(24, @OGUID+412),
(24, @OGUID+413),
(24, @OGUID+414),
(24, @OGUID+415),
(24, @OGUID+416),
(24, @OGUID+417),
(24, @OGUID+418),
(24, @OGUID+419),
(24, @OGUID+420),
(24, @OGUID+421),
(24, @OGUID+422),
(24, @OGUID+423),
(24, @OGUID+424),
(24, @OGUID+425),
(24, @OGUID+426);
