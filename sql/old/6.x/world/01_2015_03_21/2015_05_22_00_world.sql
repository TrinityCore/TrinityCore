DROP TABLE IF EXISTS `garrison_follower_class_spec_abilities`;
CREATE TABLE `garrison_follower_class_spec_abilities` (
  `classSpecId` int(10) unsigned NOT NULL DEFAULT '0',
  `abilityId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`classSpecId`,`abilityId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `garrison_follower_class_spec_abilities` (`abilityId`,`classSpecId`) VALUES
(119,3), -- Anti-Magic Shell
(158,29),(158,30), -- Ascendance
(131,22), -- Avenging Wrath
(132,7),(132,8), -- Barkskin
(138,7), -- Berserk
(170,14),(170,15), -- Blink
(5,15),(5,16),   -- Blizzard
(115,2),(115,4), -- Bone Shield
(139,5), -- Celestial Alignment
(106,29),(106,30),(106,31), -- Chain Heal
(154,29),(154,30),(154,31), -- Chain Lightning
(142,17),(142,18), -- Chi Wave
(125,20),(125,21), -- Cleanse
(120,35),(120,37),(120,38), -- Cleave
(169,14), -- Conjure Food
(166,12), -- Counter Shot
(171,14),(171,15),(171,16), -- Counterspell
(114,2),(114,3),(114,4), -- Dark Command
(182,5),(182,7),(182,8), -- Dash
(116,2),(116,3),(116,4), -- Death and Decay
(164,13), -- Deterrence
(145,18), -- Detox
(165,10),(165,12),(165,13), -- Disengage
(148,23),(148,24),(148,25), -- Dispel Magic
(129,20), -- Divine Plea
(124,21),(124,22), -- Divine Shield
(130,22), -- Divine Storm
(151,23),(151,25), -- Dominate Mind
(175,34), -- Drain Life
(118,2),(118,3),(118,4), -- Empower Rune Weapon
(183,19), -- Energizing Brew
(134,5),(134,8),(134,9), -- Entangling Roots
(159,26),(159,28), -- Evasion
(161,27),(161,28), -- Fan of Knives
(180,32),(180,34), -- Fear
(163,10), -- Feign Death
(167,10),(167,12),(167,13), -- Freezing Trap
(156,30), -- Ghost Wolf
(108,7),(108,8), -- Growl
(141,17), -- Guard
(102,35),(102,37),(102,38), -- Heroic Leap
(157,29),(157,30), -- Hex
(128,20), -- Holy Radiance
(137,5),(137,9), -- Hurricane
(168,16), -- Ice Block
(133,5),(133,7),(133,8),(133,9), -- Innervate
(105,26),(105,27),(105,28), -- Kick
(10,23),(10,24),(10,25), -- Leap of Faith
(146,18), -- Mana Tea
(162,26),(162,27), -- Marked for Death
(177,33),(177,34), -- Metamorphosis
(117,2),(117,3),(117,4), -- Mind Freeze
(150,24),(150,25), -- Mind Sear
(101,10),(101,12),(101,13), -- Multi-Shot
(136,9), -- Nature's Cure
(144,17),(144,19), -- Paralysis
(172,14),(172,15),(172,16), -- Polymorph
(152,25), -- Power Infusion
(11,23),(11,24), -- Prayer of Healing
(140,17),(140,19), -- Provoke
(121,35),(121,37),(121,38), -- Pummel
(107,31), -- Purify Spirit
(178,32),(178,33), -- Rain of Fire
(103,10),(103,12),(103,13), -- Rapid Fire
(126,20),(126,21),(126,22), -- Rebuke
(122,35),(122,37), -- Recklessness
(123,21), -- Reckoning
(127,20),(127,21),(127,22), -- Repentance
(143,17),(143,18),(143,19), -- Roll
(104,26),(104,27),(104,28), -- Sap
(149,23),(149,24), -- Shadowfiend
(6,37),(6,38), -- Shield Wall
(176,32), -- Singe Magic
(147,18),(147,19), -- Spear Hand Strike
(179,32),(179,33),(179,34), -- Spell Lock
(160,26),(160,27),(160,28), -- Sprint
(181,32),(181,33),(181,34), -- Summon Infernal
(100,35),(100,38), -- Taunt
(173,14),(173,15),(173,16), -- Time Warp
(174,33), -- Unending Resolve
(153,31), -- Water Shield
(135,9), -- Wild Growth
(155,29),(155,31); -- Wind Shear
