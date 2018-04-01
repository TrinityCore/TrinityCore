UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=11721;

UPDATE `gameobject_template_addon` SET `flags`=0 WHERE `entry`=241949; -- Lamp
UPDATE `gameobject_template_addon` SET `flags`=0 WHERE `entry`=241948; -- Lamp
UPDATE `gameobject_template_addon` SET `flags`=0 WHERE `entry`=241969; -- Lamp
UPDATE `gameobject_template_addon` SET `flags`=0 WHERE `entry`=241971; -- Lamp
UPDATE `gameobject_template_addon` SET `flags`=0 WHERE `entry`=241970; -- Lamp
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=206294; -- Hero's Call Board

SET @CGUID := 20555650;
SET @OGUID := 20405933;

DELETE FROM creature WHERE guid = 188718;
DELETE FROM `creature` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 107574, 0, 1519, 6292, 1, 0, 0, 0, 0, -8363.292, 232.5469, 157.0733, 2.249798, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549); -- King Anduin Wrynn (Area: Stormwind Keep - Difficulty: 0)

DELETE FROM gameobject WHERE guid IN (20375672, 20375673);
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 216350, 0, 1519, 0, 1, 0, 0, -8401.058, 330.757, 147.0138, 5.152676, 0, 0, -0.5356312, 0.844452, 120, 255, 1, 25549), -- Portal to Dalaran (Area: 0 - Difficulty: 0)
(@OGUID+1, 270011, 0, 1519, 5154, 1, 1, 0, -8809.973, 662.8707, 99.60842, 3.551751, 0, 0, -0.9790449, 0.2036445, 120, 255, 1, 25549), -- Doodad de l’hôtel des ventes (Area: Mage Quarter - Difficulty: 0)
(@OGUID+2, 254292, 1, 1637, 0, 1, 0, 0, 1758.979, -4293.224, 7.621215, 5.058824, 0, 0, -0.5746536, 0.8183967, 120, 255, 1, 25549); -- 254292 (Area: 0 - Difficulty: 1)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+1, 0, 0, 0.944089, -0.3296907); -- Doodad de l’hôtel des ventes

DELETE FROM `creature_template_addon` WHERE `entry` IN (118524 /*118524 (Dalaran Crystal)*/, 119272 /*119272 (Sarah the Savage)*/, 119487 /*119487 (Talia Direhorn)*/, 116175 /*116175 (Karam Magespear)*/, 119486 /*119486 (Apothecary Lee)*/, 96983 /*96983 (Dalaran Citizen)*/, 121602 /*121602 (Manapoof)*/, 121541 /*121541 (Ban-Lu)*/, 123793 /*123793 (Console Hearthstone) - Ride Vehicle Hardcoded*/, 92553 /*92553 (Kirin Tor Summoner) - Garrison Magus*/, 3581 /*3581 (Sewer Beast)*/, 85307 /*85307 (Sparkbright)*/, 52408 /*52408 (Coridormi) - Generic Quest Invisibility 25*/, 89174 /*89174 (Laluu)*/, 97529 /*97529 (The Amazing Zanzo)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(118524, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 118524 (Dalaran Crystal)
(119272, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 119272 (Sarah the Savage)
(119487, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 119487 (Talia Direhorn)
(116175, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 116175 (Karam Magespear)
(119486, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 119486 (Apothecary Lee)
(96983, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 96983 (Dalaran Citizen)
(121602, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121602 (Manapoof)
(121541, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121541 (Ban-Lu)
(123793, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 123793 (Console Hearthstone) - Ride Vehicle Hardcoded
(92553, 0, 0, 0, 1, 0, 0, 0, 0, '174827'), -- 92553 (Kirin Tor Summoner) - Garrison Magus
(3581, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 3581 (Sewer Beast)
(85307, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 85307 (Sparkbright)
(52408, 0, 0, 33619968, 1, 0, 0, 0, 0, '94223'), -- 52408 (Coridormi) - Generic Quest Invisibility 25
(89174, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 89174 (Laluu)
(97529, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 97529 (The Amazing Zanzo)

UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=96198; -- 96198 (Catriona Macrae)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=72587; -- 72587 (VFX Bunny)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=104091; -- 104091 (Kirin Tor Guardian)
UPDATE `creature_template_addon` SET `auras`='127239' WHERE `entry`=51938; -- 51938 (Crithto)
UPDATE `creature_template_addon` SET `auras`='79976 79977' WHERE `entry`=61840; -- 61840 (Naanae)
UPDATE `creature_template_addon` SET `auras`='221508 18950' WHERE `entry`=14439; -- 14439 (Officer Brady)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (112543, 106263, 106262, 107772, 112545, 15659);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(112543, 0, 25549),
(106263, 0, 25549),
(106262, 0, 25549),
(107772, 0, 25549),
(112545, 0, 25549),
(15659, 0, 25549);


INSERT IGNORE INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(74782, 0.5, 1, 0, 25549),
(75130, 0.4213, 1.65, 0, 25549),
(75302, 0.95975, 4.125, 0, 25549),
(74087, 0.4596, 1.8, 0, 25549),
(75301, 0.4213, 1.65, 0, 25549),
(77627, 0.4622682, 1.5, 0, 25549);

UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28151;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=65450;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27952;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=65244;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=65255;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=72103;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=36905;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=71017;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=47997;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25673;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5556;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27287;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1206;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=71599;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=69152;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=47999;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=69156;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25595;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=65371;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=40155;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=52659;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1669;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5777;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28147;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27667;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28156;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27955;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=59102;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28162;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=72095;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25605;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28155;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27960;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=69926;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42720;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=26395;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25806;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25947;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=67001;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42722;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=15918;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27882;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25983;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=6296;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28282;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1072;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28111;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=60156;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25041;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=26394;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=26299;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=65101;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=43497;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25875;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25791;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=65422;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=58822;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=65412;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27682;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28158;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=72344;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5585;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3043069, `CombatReach`=0.75, `VerifiedBuild`=25549 WHERE `DisplayID`=65714;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=15180;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28143;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42872;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27657;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28161;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=6295;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=65356;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27915;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28160;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=69790;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25607;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27720;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27592;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25807;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=64759;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=58842;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5554;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27822;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=72104;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=28159;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=26440;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=26441;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=22003;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=251;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27616;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27959;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=64048;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=71019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=34172;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=48000;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27448;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=26307;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=69627;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=33542;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=2954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=71088;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=64049;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=56704;
UPDATE `creature_model_info` SET `BoundingRadius`=1.36, `CombatReach`=1.2, `VerifiedBuild`=25549 WHERE `DisplayID`=63521;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=63522;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=31174;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=344;
UPDATE `creature_model_info` SET `BoundingRadius`=0.472041, `VerifiedBuild`=25549 WHERE `DisplayID`=65199;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=29515;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=29514;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5077;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5565;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=15321;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5075;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=55538;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=16854;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1758;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=2961;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=18931;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42278;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42277;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3288;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1521;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1516;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5728;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3281;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=4996;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1696;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1509;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=33743;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5000;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25336;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=34005;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25319;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=34004;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1519;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42279;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=18053;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1697;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=60316;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1511;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3448;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1520;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1517;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=60207;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1505;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=21072;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1141;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1522;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=2850;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=2176;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1510;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42275;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=36816;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=36815;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=36814;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=18054;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=15921;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1544;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42276;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=49021;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=37087;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=39532;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=2038;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=33977;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1473;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=33948;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=33974;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1472;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42274;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=42273;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1429;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1448;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1440;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1434;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=36839;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1541;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5082;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=34070;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1445;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1423;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=14493;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5074;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1439;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5551;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5567;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=11873;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=4888;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=25901;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=31269;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1431;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=33303;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=37850;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1444;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=7992;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=36597;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1418;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=7991;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5552;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1447;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1438;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=262;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=15594;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=22769;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1437;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1471;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1427;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1446;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=14492;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5444;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=72724;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5446;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1433;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3290;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3285;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1443;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5545;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=37721;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5081;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=2239;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=19670;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=36656;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=10591;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=34931;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5080;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27261;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1492;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27295;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1481;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1485;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1486;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1477;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3295;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1482;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3298;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3297;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1497;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3445;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1432;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1502;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1488;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=37310;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=37311;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1694;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1695;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=58785;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5076;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3167;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=5073;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1491;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1489;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1480;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=221;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=328;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=4626;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1494;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=57081;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=37874;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1484;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=58478;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=134;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=11686;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=2181;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=59144;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=59145;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3444;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=19803;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=3292;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=17241;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1483;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=1470;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=252;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=7935;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=19619;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=27823;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=2968;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=338;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=21342;
UPDATE `creature_model_info` SET `VerifiedBuild`=25549 WHERE `DisplayID`=65253;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=119272 AND `ID`=1) OR (`CreatureID`=119487 AND `ID`=1) OR (`CreatureID`=116175 AND `ID`=1) OR (`CreatureID`=119486 AND `ID`=1) OR (`CreatureID`=97529 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(119272, 1, 3267, 0, 0, 49777, 0, 0, 0, 0, 0), -- Sarah the Savage
(119487, 1, 126320, 0, 0, 126334, 0, 0, 0, 0, 0), -- Talia Direhorn
(116175, 1, 65492, 0, 0, 111717, 0, 0, 0, 0, 0), -- Karam Magespear
(119486, 1, 126324, 0, 0, 0, 0, 0, 0, 0, 0), -- Apothecary Lee
(97529, 1, 124382, 0, 0, 0, 0, 0, 0, 0, 0); -- The Amazing Zanzo

UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=112079; -- Crimson Pilgrim
UPDATE `creature_template` SET `npcflag`=17179869184, `unit_flags3`=32 WHERE `entry`=97514; -- Danric the Bold
UPDATE `creature_template` SET `npcflag`=17179869184, `unit_flags3`=32 WHERE `entry`=97533; -- Felcaster Virim
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=112543; -- Khronus Lightwarden
UPDATE `creature_template` SET `npcflag`=17180655617, `unit_flags3`=32 WHERE `entry`=96811; -- Andrew Matthews
UPDATE `creature_template` SET `npcflag`=17179869185, `unit_flags3`=32 WHERE `entry`=96810; -- Archivist Betha
UPDATE `creature_template` SET `minlevel`=105 WHERE `entry`=106263; -- Earthen Ring Shaman
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=71305216, `unit_flags3`=1 WHERE `entry`=118524; -- Dalaran Crystal
UPDATE `creature_template` SET `minlevel`=105 WHERE `entry`=106262; -- Earthen Ring Shaman
UPDATE `creature_template` SET `minlevel`=102, `maxlevel`=102 WHERE `entry`=96641; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=101, `maxlevel`=101 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=68, `npcflag`=129, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=119272; -- Sarah the Savage
UPDATE `creature_template` SET `minlevel`=107, `maxlevel`=107 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=96786; -- Archmage Celindra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=68, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=119487; -- Talia Direhorn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1770, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=116175; -- Karam Magespear
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=68, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=119486; -- Apothecary Lee
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `speed_walk`=0.8, `speed_run`=1 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=107772; -- Ol' Toomba
UPDATE `creature_template` SET `speed_walk`=0.666668, `speed_run`=1.142857 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `npcflag`=130 WHERE `entry`=96479; -- Breanni
UPDATE `creature_template` SET `minlevel`=107, `maxlevel`=107, `speed_run`=1.142857 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `unit_flags2`=1073743874 WHERE `entry`=43359; -- ELM General Purpose Bunny Infinite Hide Body
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=2007, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=96983; -- Dalaran Citizen
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=121602; -- Manapoof
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=121541; -- Ban-Lu
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `VehicleId`=0 WHERE `entry`=31689; -- Gnome Diver
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=123793; -- Console Hearthstone
UPDATE `creature_template` SET `npcflag`=131 WHERE `entry`=98725; -- Lio the Lioness
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=112545; -- Zariya
UPDATE `creature_template` SET `minlevel`=75, `maxlevel`=75, `faction`=2007, `unit_class`=8, `unit_flags`=33536 WHERE `entry`=32494; -- Dalaran Child
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=110409; -- Credit - Portal Taken
UPDATE `creature_template` SET `npcflag`=131 WHERE `entry`=115287; -- Serr'ah
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=93307; -- Rygarius
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=51938; -- Crithto
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=107574; -- King Anduin Wrynn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=34998; -- Alison Devay
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=34997; -- Devin Fardale
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=92553; -- Kirin Tor Summoner
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=1756; -- Stormwind Royal Guard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=87501; -- Paulie
UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=2795; -- Lenny "Fingers" McCoy
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=38821; -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)
UPDATE `creature_template` SET `unit_flags`=33344 WHERE `entry`=3581; -- Sewer Beast
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=50525; -- Chris Miller
UPDATE `creature_template` SET `maxlevel`=24 WHERE `entry`=42421; -- Stormwind Fisherman
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=37944; -- Stormwind City Patroller
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=14439; -- Officer Brady
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=8719; -- Auctioneer Fitch
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=8670; -- Auctioneer Chilton
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=110 WHERE `entry`=15659; -- Auctioneer Jaxon
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=14438; -- Officer Pomeroy
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=113211; -- Officer Fairbanks
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=46180; -- Ithurian Whitespire
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=51348; -- Stormwind Gryphon Rider
UPDATE `creature_template` SET `faction`=12, `npcflag`=1, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=85307; -- Sparkbright
UPDATE `creature_template` SET `RangeAttackTime`=2000 WHERE `entry`=5694; -- High Sorcerer Andromath
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=1976; -- Stormwind City Patroller
UPDATE `creature_template` SET `RangeAttackTime`=2000 WHERE `entry`=1141; -- Angus Stern
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=34816 WHERE `entry`=52408; -- Coridormi
UPDATE `creature_template` SET `faction`=1638, `npcflag`=3, `unit_class`=8, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=89174; -- Laluu
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=2007, `npcflag`=17179869185, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=97529; -- The Amazing Zanzo

DELETE FROM `gameobject_template` WHERE `entry` IN (216350 /*Portal to Dalaran*/, 270011 /*Doodad de l’hôtel des ventes*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(216350, 22, 8111, 'Portail vers Dalaran', '', '', '', 1, 228329, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Portal to Dalaran
(270011, 5, 42369, 'Doodad de l’hôtel des ventes', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25549); -- Doodad de l’hôtel des ventes

UPDATE `gameobject_questitem` SET `VerifiedBuild`=25549 WHERE (`GameObjectEntry`=203801 AND `Idx`=0); -- Sack of Confectioner's Sugar
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25549 WHERE (`GameObjectEntry`=203800 AND `Idx`=0); -- Barrel of Canal Fish
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25549 WHERE (`GameObjectEntry`=203762 AND `Idx`=0); -- Juicy Apple
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25549 WHERE (`GameObjectEntry`=105175 AND `Idx`=0); -- Cantation of Manifestation
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25549 WHERE (`GameObjectEntry`=105174 AND `Idx`=0); -- Chest of Containment Coffers
