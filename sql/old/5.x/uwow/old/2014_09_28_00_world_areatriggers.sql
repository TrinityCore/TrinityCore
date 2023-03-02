DROP TABLE IF EXISTS `areatrigger_actions`;
CREATE TABLE `areatrigger_actions` (
  `entry` mediumint(5) unsigned NOT NULL DEFAULT '0',
  `id` tinyint(3) unsigned  NOT NULL DEFAULT '0',
  `moment` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `actionType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `targetFlags` tinyint(3) NOT NULL DEFAULT '0',
  `spellId` mediumint(5) unsigned NOT NULL DEFAULT '0',
  `maxCharges` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `chargeRecoveryTime` int(11) unsigned NOT NULL DEFAULT '0',
  `comment` text NOT NULL,
  PRIMARY KEY (`entry`, `id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `areatrigger_data`;
CREATE TABLE `areatrigger_data` (
  `entry` mediumint(5) unsigned NOT NULL DEFAULT '0',
  `radius` float unsigned NOT NULL DEFAULT '1',
  `activationDelay` mediumint(7) unsigned NOT NULL DEFAULT '0',
  `updateDelay` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `maxCount` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `comment` text NOT NULL,
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `areatrigger_data` ADD `visualId` INT(8) UNSIGNED NOT NULL DEFAULT '1' AFTER `entry`;
ALTER TABLE `areatrigger_data` ADD `radius2` float UNSIGNED NOT NULL DEFAULT '0' AFTER `radius`;

-- Healing Sphere
REPLACE INTO areatrigger_data (entry, radius, visualId, activationDelay, updateDelay, maxCount, comment) VALUES
(228, 3, 242, 0, 0, 3, '115460 - Healing Sphere');
DELETE FROM areatrigger_actions WHERE entry = 228;
INSERT INTO areatrigger_actions (entry, id, moment, actionType, targetFlags, spellId, maxCharges, chargeRecoveryTime, comment) VALUES
(228, 0, 0, 0, 9, 115464, 1, 0, '115460 - Healing Sphere - cast 115464 when friendly player enters'),
(228, 1, 1, 0, 0, 135920, 1, 0, '115460 - Healing Sphere - cast 135920 on despawn after use charge');

-- Chi Sphere (Afterlife)
REPLACE INTO areatrigger_data (entry, radius, visualId, activationDelay, updateDelay, maxCount, comment) VALUES
(336, 3, 391, 0, 0, 0, '121286 - Chi Sphere');
DELETE FROM areatrigger_actions WHERE entry = 336;
INSERT INTO areatrigger_actions (entry, id, moment, actionType, targetFlags, spellId, maxCharges, chargeRecoveryTime, comment) VALUES
(336, 0, 0, 0, 4, 121283, 1, 0, '121286 - Chi Sphere - cast 121283 when owner player enters');

-- Healing Sphere (Afterlife)
REPLACE INTO areatrigger_data (entry, radius, visualId, activationDelay, updateDelay, maxCount, comment) VALUES
(383, 3, 368, 0, 0, 0, '117032 - Healing Sphere (Afterlife)');
DELETE FROM areatrigger_actions WHERE entry = 383;
INSERT INTO areatrigger_actions (entry, id, moment, actionType, targetFlags, spellId, maxCharges, chargeRecoveryTime, comment) VALUES
(383, 0, 0, 0, 4, 125355, 1, 0, '117032 - Healing Sphere (Afterlife) - cast 125355 when owner player enters');

-- Angelic Feather
REPLACE INTO areatrigger_data (entry, radius, visualId, activationDelay, updateDelay, maxCount, comment) VALUES
(337, 3, 24, 0, 0, 3, '121536 - Angelic Feather');
DELETE FROM areatrigger_actions WHERE entry = 337;
INSERT INTO areatrigger_actions (entry, id, moment, actionType, targetFlags, spellId, maxCharges, chargeRecoveryTime, comment) VALUES
(337, 0, 0, 0, 9, 121557, 1, 10000, '121536 - Angelic Feather - cast 121557 when friendly player enters');

-- Gift of the Serpent (Mastery)
REPLACE INTO areatrigger_data (entry, radius, visualId, activationDelay, updateDelay, maxCount, comment) VALUES
(321, 3, 371, 0, 0, 0, '119031 - Gift of the Serpent');
DELETE FROM areatrigger_actions WHERE entry = 321;
INSERT INTO areatrigger_actions (entry, id, moment, actionType, targetFlags, spellId, maxCharges, chargeRecoveryTime, comment) VALUES
(321, 0, 0, 0, 9, 124041, 1, 0, '119031 - Gift of the Serpent - cast 124041 when friendly player enters'),
(321, 1, 1, 0, 0, 135920, 1, 0, '119031 - Gift of the Serpent - cast 135920 on despawn after use charge');

-- Path of Blossoms. ToDo: VisualID
-- to do: Fire Blossoms cannot be created within 3 yards of an existing blossom.
REPLACE INTO areatrigger_data (entry, radius, activationDelay, updateDelay, maxCount, comment) VALUES
(341, 3, 0, 0, 0, '122035 - Path of Blossoms');
DELETE FROM areatrigger_actions WHERE entry = 341;
INSERT INTO areatrigger_actions (entry, id, moment, actionType, targetFlags, spellId, maxCharges, chargeRecoveryTime, comment) VALUES
(341, 0, 0, 0, 2, 122036, 1, 0, '122035 - Path of Blossoms - cast 122036 when hostile unit enters');

-- Rune of Power
REPLACE INTO areatrigger_data (entry, radius, visualId, activationDelay, updateDelay, maxCount, comment) VALUES
(304, 8, 230, 0, 200, 2, '116011 - Rune of Power');
DELETE FROM areatrigger_actions WHERE entry = 304;
INSERT INTO areatrigger_actions (entry, id, moment, actionType, targetFlags, spellId, maxCharges, chargeRecoveryTime, comment) VALUES
(304, 0, 2, 0, 4, 116014, 0, 0, '116011 - Rune of Power - cast 116014 on owner player on update'),
(304, 1, 1, 1, 4, 116014, 0, 0, '116011 - Rune of Power - remove 116014 on owner player leave');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 304;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `NegativeCondition`, `Comment`) VALUE
(26, 304, 0, 1, 1, 116014, 1, '116011 - Do not recast 116014 if target already has it.');

-- Nullification Barrier. ToDo: VisualID
REPLACE INTO areatrigger_data (entry, radius, activationDelay, updateDelay, maxCount, comment) VALUES
(229, 6, 0, 5000, 0, '115817 - Nullification Barrier');
DELETE FROM areatrigger_actions WHERE entry = 229;
INSERT INTO areatrigger_actions (entry, id, moment, actionType, targetFlags, spellId, maxCharges, chargeRecoveryTime, comment) VALUES
(229, 0, 0, 0, 4, 116014, 0, 0, '115817 - Nullification Barrier - cast 115856 on owner player enter'),
(229, 1, 2, 0, 4, 116014, 0, 0, '115817 - Nullification Barrier - cast 115856 on owner player on update'),
(229, 2, 1, 1, 4, 116014, 0, 0, '115817 - Nullification Barrier - remove 115856 on owner player leave');

-- Flare
REPLACE INTO areatrigger_data (entry, `visualId`, radius, activationDelay, updateDelay, maxCount, comment) VALUES
(510, 390, 10, 0, 200, 0, '132950 - Flare');
DELETE FROM areatrigger_actions WHERE entry = 510;
INSERT INTO areatrigger_actions (entry, id, moment, actionType, targetFlags, spellId, maxCharges, chargeRecoveryTime, comment) VALUES
(510, 0, 2, 0, 2, 132951, 0, 0, '132950 - Flare - cast 132951 when hostile unit updates'),
(510, 1, 1, 1, 2, 132951, 0, 0, '132950 - Flare - remove 132951 when hostile unit exit');

-- DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 228;
-- INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `Comment`) VALUE
-- (26, 228, 0, 1, 0, 115069, '');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_mage_rune_of_power';

-- 143235 - OO Noxious Poison
DELETE FROM `areatrigger_actions` WHERE entry = 1013;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('1013', '0', '0', '0', '2', '143239', '0', '0', 'OO: Noxious Poison on enter cast'), 
('1013', '1', '1', '1', '0', '143239', '0', '0', 'OO: Noxious Poison on exit remove');
REPLACE INTO `areatrigger_data` (`entry`, `visualId`, `radius`, `activationDelay`, `updateDelay`, `maxCount`, `comment`) VALUES 
('1013', '97', '2', '0', '2000', '0', 'OO: Noxious Poison');

-- 143546 OO Dark Meditation
DELETE FROM `areatrigger_actions` WHERE entry = 1032;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('1032', '0', '0', '0', '2', '143564', '0', '0', 'OO: Dark Meditation on enter cast'), 
('1032', '1', '1', '1', '0', '143564', '0', '0', 'OO: Dark Meditation on exit remove'),
('1032', '2', '0', '0', '4', '143843', '0', '0', 'OO: Dark Meditation on enter cast'), 
('1032', '3', '1', '1', '0', '143843', '0', '0', 'OO: Dark Meditation on exit remove');
REPLACE INTO `areatrigger_data` (`entry`, `visualId`, `radius`, `activationDelay`, `updateDelay`, `maxCount`, `comment`) VALUES 
('1032', '3', '10', '0', '2000', '0', 'OO: Dark Meditation');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143546', 'spell_OO_dark_meditation');

-- 102793 Druid: Ursol's Vortex
DELETE FROM `spell_script_names` WHERE `spell_id` = 102793;
DELETE FROM `areatrigger_actions` WHERE entry = 314;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('314', '0', '0', '0', '2', '127797', '0', '0', 'Druid: Ursol\'s Vortex on enter cast'), 
('314', '1', '1', '0', 0x2 | 0x20 | 0x40, '118283', '1', '0', 'Druid: Ursol\'s Vortex on exit first target jump back');

DELETE FROM `areatrigger_data` WHERE `entry` = 314;
INSERT INTO `areatrigger_data` (`entry`, `radius`, `activationDelay`, `updateDelay`, `maxCount`, `comment`) VALUES 
('314', '8', '0', '0', '0', 'Ursol''s Vortex');

-- 51052 DK: Anti-Magic Zone
DELETE FROM `areatrigger_actions` WHERE entry = 1193;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('1193', '0', '0', '0', '1', '145629', '0', '0', 'DK: Anti-Magic Zone on enter cast'), 
('1193', '1', '1', '1', '0', '145629', '0', '0', 'DK: Anti-Magic Zone on exit remove');

REPLACE INTO `areatrigger_data` (`entry`, `visualId`, `radius`, `activationDelay`, `updateDelay`, `maxCount`, `comment`) 
VALUES ('1193', '78', '6.5', '0', '0', '0', 'DK: Anti-Magic Zone');

-- 63487 - 13810 Hunter: Ice Trap
REPLACE INTO `areatrigger_data` (`entry`, `visualId`, `radius`, `activationDelay`, `updateDelay`, `maxCount`, `comment`) 
VALUES ('621', '4', '9.75', '0', '0', '0', 'Ice Trap');
DELETE FROM `areatrigger_actions` WHERE entry = 621;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('621', '0', '0', '0', '2', '135299', '0', '0', 'Hunter: Ice Trap on enter cast'), 
('621', '1', '1', '1', '0', '135299', '0', '0', 'Hunter: Ice Trap on exit remove');

REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('63487', 'spell_hun_ice_trap');

-- 120517 Priest: Halo Light
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
('120692', 'spell_pri_halo'), 
('120696', 'spell_pri_halo');

DELETE FROM `spell_script_names` WHERE `spell_id` = 120517;
REPLACE INTO `areatrigger_data` (`entry`, `visualId`, `radius`, `radius2`, `activationDelay`, `updateDelay`, `maxCount`, `comment`) 
VALUES ('658', '342', '5', '60', '1000', '0', '0', 'Priest: Halo');
DELETE FROM `areatrigger_actions` WHERE entry = 658;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('658', '0', '0', '0', '1', '120692', '0', '0', 'Priest: Halo Light on friend enter cast'),
('658', '1', '0', '0', '2', '120692', '0', '0', 'Priest: Halo Light on enemy enter cast');

-- 120644  Priest: Halo Dark
DELETE FROM `spell_script_names` WHERE `spell_id` = 120644;
REPLACE INTO `areatrigger_data` (`entry`, `visualId`, `radius`, `radius2`, `activationDelay`, `updateDelay`, `maxCount`, `comment`) 
VALUES ('657', '342', '5', '60', '1000', '0', '0', 'Priest: Halo');
DELETE FROM `areatrigger_actions` WHERE entry = 657;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
('657', '0', '0', '0', '1', '120696', '0', '0', 'Priest: Halo Dark on friend enter cast'),
('657', '1', '0', '0', '2', '120696', '0', '0', 'Priest: Halo Dark on enemy enter cast');