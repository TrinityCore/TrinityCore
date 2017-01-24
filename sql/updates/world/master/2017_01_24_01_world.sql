/*
	Blood Elf
	Start Area
	Class Quest that are obsolete
*/

-- MAGE
-- Julia Sunstriker <Mage Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 15279;

-- Quest: Mage Training (8328) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15278 AND `quest`= 8328;
DELETE FROM `creature_questender` WHERE `id`= 15279 AND `quest`= 8328;

-- Quest: Frost Nova (10068) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15279 AND `quest`= 10068;
DELETE FROM `creature_questender` WHERE `id`= 15279 AND `quest`= 10068;

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (8328,10068);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  8328, 0, '', '', 'Quest removed in patch 7.0.3: Mage Training'),
(1, 10068, 0, '', '', 'Quest removed in patch 7.0.3: Frost Nova');

-- HUNTER
-- Ranger Sallina <Hunter Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 15513;

-- Quest: Hunter Training (9393) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15278 AND `quest`= 9393;
DELETE FROM `creature_questender` WHERE `id`= 15513 AND `quest`= 9393;

-- Quest: Steady Shot (10070) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15513 AND `quest`= 10070;
DELETE FROM `creature_questender` WHERE `id`= 15295 AND `quest`= 10070;

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (9393,10070);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  9393, 0, '', '', 'Quest removed in patch 7.0.3: Hunter Training'),
(1, 10070, 0, '', '', 'Quest removed in patch 7.0.3: Steady Shot');

-- ROGUE
-- Pathstalker Kariel <Rogue Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 15285;

-- Quest: Rogue Training (9392) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15278 AND `quest`= 9392;
DELETE FROM `creature_questender` WHERE `id`= 15285 AND `quest`= 9392;

-- Quest: Evisceration (9393) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15285 AND `quest`= 9393;
DELETE FROM `creature_questender` WHERE `id`= 15295 AND `quest`= 9393;

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (9392,10071);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  9392, 0, '', '', 'Quest removed in patch 7.0.3: Rogue Training'),
(1, 10071, 0, '', '', 'Quest removed in patch 7.0.3: Evisceration');

-- WARRIOR
-- Delios Silverblade <Warrior Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 43010;

-- Quest: Warrior Training (9289) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15278 AND `quest`= 9289;
DELETE FROM `creature_questender` WHERE `id`= 43010 AND `quest`= 9289;

-- Quest: Charge (27091) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 43010 AND `quest`= 27091;
DELETE FROM `creature_questender` WHERE `id`= 43010 AND `quest`= 27091;

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (9389,27091);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  9383, 0, '', '', 'Quest removed in patch 7.0.3: Warrior Training'),
(1, 27091, 0, '', '', 'Quest removed in patch 7.0.3: Charge');

-- PRIEST
-- Matron Arena <Priest Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 15284;

-- Quest: Priest Training (8564) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15278 AND `quest`= 8564;
DELETE FROM `creature_questender` WHERE `id`= 15284 AND `quest`= 8564;

-- Quest: Learning the Word (10072) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15284 AND `quest`= 10072;
DELETE FROM `creature_questender` WHERE `id`= 15295 AND `quest`= 10072;

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (8564,10072);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  8564, 0, '', '', 'Quest removed in patch 7.0.3: Priest Training'),
(1, 10072, 0, '', '', 'Quest removed in patch 7.0.3: Learning the Word');

-- PALADIN
-- Jesthenis Sunstriker <Paladin Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 15280;

-- Quest: Paladin Training (9676) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15278 AND `quest`= 9676;
DELETE FROM `creature_questender` WHERE `id`= 15280 AND `quest`= 9676;

-- Quest: Ways of the Light (10069) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15280 AND `quest`= 10069;
DELETE FROM `creature_questender` WHERE `id`= 15295 AND `quest`= 10069;

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (9676,10069);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  9675, 0, '', '', 'Quest removed in patch 7.0.3: Paladin Training'),
(1, 10069, 0, '', '', 'Quest removed in patch 7.0.3: Ways of the Light');

-- WARLOCK
-- Summoner Teli'Larien <Warlock Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 15283;

-- Quest: Warlock Training (8563) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15278 AND `quest`= 8563;
DELETE FROM `creature_questender` WHERE `id`= 15283 AND `quest`= 8563;

-- Quest: Curruption (10073) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15283 AND `quest`= 10073;
DELETE FROM `creature_questender` WHERE `id`= 15295 AND `quest`= 10073;

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (8563,10073);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  8563, 0, '', '', 'Quest removed in patch 7.0.3: Warlock Training'),
(1, 10073, 0, '', '', 'Quest removed in patch 7.0.3: Curruption');

-- MONK
-- Pao <Monk Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 63332;

-- Quest: Monk Training (31170) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 15278 AND `quest`= 31170;
DELETE FROM `creature_questender` WHERE `id`= 63332 AND `quest`= 31170;

-- Quest: Tiger Palm (31171) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 63332 AND `quest`= 31171;
DELETE FROM `creature_questender` WHERE `id`= 63332 AND `quest`= 31171;

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (31170,31171);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  31170, 0, '', '', 'Quest removed in patch 7.0.3: Monk Training'),
(1, 31171, 0, '', '', 'Quest removed in patch 7.0.3: Tiger Palm');