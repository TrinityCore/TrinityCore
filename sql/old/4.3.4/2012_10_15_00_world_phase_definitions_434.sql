DROP TABLE IF EXISTS `phase_definitions`;
CREATE TABLE `phase_definitions` (
  `zoneId` mediumint(7) unsigned NOT NULL DEFAULT '0',
  `entry` smallint(5) unsigned NOT NULL AUTO_INCREMENT,
  `phasemask` bigint(20) unsigned NOT NULL DEFAULT '0',
  `phaseId` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `terrainswapmap` smallint(5) unsigned NOT NULL DEFAULT '0',
  `flags` tinyint(3) unsigned DEFAULT '0',
  `comment` text,
  PRIMARY KEY (`zoneId`, `entry`)
)
AUTO_INCREMENT=1
ENGINE=MyISAM
COLLATE='utf8_general_ci';

INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `flags`, `comment`) VALUES
(1519, 1, 129,  0,   0,   0, 'Stormwind: [A] Heros Call: Vashj''ir'),
(1519, 2, 257,  0,   0,   0, 'Stormwind: [A] Heros Call: Hyjal'),
(1519, 3, 513,  0,   0,   0, 'Stormwind: [A] Heros Call: Deepholm'),
(1519, 4, 1025, 0,   0,   0, 'Stormwind: [A] Heros Call: Uldum'),
(1519, 5, 2049, 0,   0,   0, 'Stormwind: [A] Heros Call: Twilight Highlands'),
(1637, 1, 129,  0,   0,   0, 'Orgrimmar: [H] Warchiefs Command: Vashj''ir'),
(1637, 2, 257,  0,   0,   0, 'Orgrimmar: [H] Warchiefs Command: Hyjal'),
(1637, 3, 513,  0,   0,   0, 'Orgrimmar: [H] Warchiefs Command: Deepholm'),
(1637, 4, 1025, 0,   0,   0, 'Orgrimmar: [H] Warchiefs Command: Uldum'),
(1637, 5, 2049, 0,   0,   0, 'Orgrimmar: [H] Warchiefs Command: Twilight Highlands'),
(616 , 1, 0   , 165, 719, 0, 'Mount Hyjal: Default Terrainswap');

DROP TABLE IF EXISTS `spell_phase`;
CREATE TABLE `spell_phase` (
  `id` mediumint(7) unsigned NOT NULL DEFAULT '0',
  `phasemask` bigint(20) unsigned NOT NULL DEFAULT '1',
  `terrainswapmap` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
)
AUTO_INCREMENT=1
ENGINE=MyISAM
COLLATE='utf8_general_ci';

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 176 AND 182;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(176, '|cff0099FFPhaseMgr: Report for player: %s, zoneId: %u, level: %u, team: %u, phaseupdateflag: %u|r'),
(177, '|cff663399PhaseMgr: There are no definitions defined for zoneId %u.|r'),
(178, '|cff0066FFPhaseMgr: Success (entry: %u) - added %s %u to the players phase.|r'),
(179, '|cffFF0000PhaseMgr: Condition for phase %u (entry: %u, zoneId: %u) failed.|r'),
(180, '|cffFF0000PhaseMgr: Condition for phase %u (entry: %u, zoneId: %u) has last phasemask flag. Skipped other definitions.|r'),
(181, '|cff6699FFPhaseMgr: The player gets phasemask %u through definitions, %u through phasing auras, and phase %u through custom phase.|r'),
(182, '|cff0099FFPhaseMgr: The player has phasemask %u (real: %u).|r');

DELETE FROM `command` WHERE `name` IN('debug phase', 'debug send setphaseshift');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('debug phase', 1, 'Syntax: .debug phase\r\n\r\nSends a phase debug report of a player to you.');

/*
Conditions (SourceGroup -> ZoneId, SourceEntry -> Entry)

If you visit the Gm Island as a alliance race you are automatically phased into phase 2.

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=23 AND `SourceGroup`=876 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(23, 876, 1, 0, 0, 6, 0, 469, 0, 0, 0, 0, '', 'Phase Definitions Example: Phase is only visible for Alliance Members');

DELETE FROM `phase_definitions` WHERE  `zoneId`=876 AND `entry`=1;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `flags`, `comment`) VALUES
(876, 1, 2, 0, 0, 0, '[Example] Gm Island');
*/
