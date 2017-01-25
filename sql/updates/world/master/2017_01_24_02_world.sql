-- Undead start area obsoletes

-- UPDATES
-- Xavier the Huntsman <Hunter Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 38911;
-- Dannel Stern <Warrior Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 2119;
-- David Trias <Rogue Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 2122;
-- Dark Cleric Duesten <Priest Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 2123;
-- Isabella <Mage Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 2124;
-- Maximillion <Warlock Trainer> is no longer a quest giver
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry`= 2126;

-- DELETE
-- Quest: Trail-Worn Scroll (24962) was removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 1569 AND `quest`= 24962;
DELETE FROM `creature_questender` WHERE `id`= 38911 AND `quest`= 24962;
-- Quest: The Thrill of the Hunt (24964) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 38911 AND `quest`= 24964;
DELETE FROM `creature_questender` WHERE `id`= 38911 AND `quest`= 24964;
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (24962,24964);
-- Quest: Simple Scroll (3095) was removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 1569 AND `quest`= 3095;
DELETE FROM `creature_questender` WHERE `id`= 2119 AND `quest`= 3095;
-- Quest: Charging into Battle (24969) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 2119 AND `quest`= 24969;
DELETE FROM `creature_questender` WHERE `id`= 2119 AND `quest`= 24969;
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3095,24969);
-- Quest: Encrypted Scroll (3096) was removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 1569 AND `quest`= 3096;
DELETE FROM `creature_questender` WHERE `id`= 2122 AND `quest`= 3096;
-- Quest: Stab! (24967) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 2122 AND `quest`= 24967;
DELETE FROM `creature_questender` WHERE `id`= 2122 AND `quest`= 24967;
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3096,24967);
-- Quest: Hallowed Scroll (3097) was removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 1569 AND `quest`= 3097;
DELETE FROM `creature_questender` WHERE `id`= 2122 AND `quest`= 3097;
-- Quest: Of Light and Shadows (24966) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 2123 AND `quest`= 24966;
DELETE FROM `creature_questender` WHERE `id`= 2123 AND `quest`= 24966;
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3097,24966);
-- Quest: Glyphic Scroll (3098) was removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 1569 AND `quest`= 3098;
DELETE FROM `creature_questender` WHERE `id`= 2124 AND `quest`= 3098;
-- Quest: Magic Training (24965) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 2124 AND `quest`= 24965;
DELETE FROM `creature_questender` WHERE `id`= 2124 AND `quest`= 24965;
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3098,24965);
-- Quest: Tainted Scroll (3099) was removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 1569 AND `quest`= 3099;
DELETE FROM `creature_questender` WHERE `id`= 2126 AND `quest`= 3099;
-- Quest: Dark Deeds (24968) removed in patch 7.0.3
DELETE FROM `creature_queststarter` WHERE `id`= 2126 AND `quest`= 24968;
DELETE FROM `creature_questender` WHERE `id`= 2126 AND `quest`= 24968;
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3099,24968);


-- INSERTS
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  24962, 0, '', '', 'Quest removed in patch 7.0.3: Trail-Worn Scroll '),
(1,  24964, 0, '', '', 'Quest removed in patch 7.0.3: The Thrill of the Hunt ');
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  3095, 0, '', '', 'Quest removed in patch 7.0.3: Simple Scroll '),
(1,  24969, 0, '', '', 'Quest removed in patch 7.0.3: Charging into Battle ');
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  3096, 0, '', '', 'Quest removed in patch 7.0.3: Encrypted Scroll '),
(1,  24967, 0, '', '', 'Quest removed in patch 7.0.3: Stab! ');
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  3097, 0, '', '', 'Quest removed in patch 7.0.3: Hallowed Scroll '),
(1,  24966, 0, '', '', 'Quest removed in patch 7.0.3: Of Light and Shadows ');
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  3098, 0, '', '', 'Quest removed in patch 7.0.3: Glyphic Scroll '),
(1,  24965, 0, '', '', 'Quest removed in patch 7.0.3: Magic Training ');
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  3099, 0, '', '', 'Quest removed in patch 7.0.3: Tainted Scroll '),
(1,  24968, 0, '', '', 'Quest removed in patch 7.0.3: Dark Deeds ');

