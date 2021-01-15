-- Quests and quest givers removed in patch 7.0.3
-- Undead starting area (Deathknell)

-- The following NPCs are no longer quest givers:
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry` IN
(2119,  -- Dannal Stern <Warrior Trainer>
 2122,  -- David Trias <Rogue Trainer>
 2123,  -- Dark Cleric Duesten <Priest Trainer>
 2124,  -- Isabella <Mage Trainer>
 2126,  -- Maximillion <Warlock Trainer>
38911, -- Xavier the Huntsman <Hunter Trainer>
63272); -- Ting <Monk Trainer>

-- Shadow Priest Sarvis (1569) no longer starts these quests:
DELETE FROM `creature_queststarter` WHERE `id`= 1569 AND `quest` IN
(3095,  -- Quest:Simple Scroll
 3096,  -- Quest:Encrypted Scroll
 3097,  -- Quest:Hallowed Scroll
 3098,  -- Quest:Glyphic Scroll
 3099,  -- Quest:Tainted Scroll
24962); -- Quest:Trail-Worn Scroll

-- These NPCs should no longer offer the following quests:
DELETE FROM `creature_queststarter` WHERE `id` = 2119 AND `quest`= 24969; -- Dannal Stern <Warrior Trainer>, Quest:Charging into Battle
DELETE FROM `creature_queststarter` WHERE `id` = 2122 AND `quest`= 24967; -- David Trias <Rogue Trainer>, Quest:Stab!
DELETE FROM `creature_queststarter` WHERE `id` = 2123 AND `quest`= 24966; -- Dark Cleric Duesten <Priest Trainer>, Quest:Of Light and Shadows
DELETE FROM `creature_queststarter` WHERE `id` = 2124 AND `quest`= 24965; -- Isabella <Mage Trainer>, Quest:Magic Training
DELETE FROM `creature_queststarter` WHERE `id` = 2126 AND `quest`= 24968; -- Maximillion <Warlock Trainer>, Quest:Dark Deeds
DELETE FROM `creature_queststarter` WHERE `id`= 38911 AND `quest`= 24964; -- Xavier the Huntsman <Hunter Trainer>, Quest:The Thrill of the Hunt
DELETE FROM `creature_queststarter` WHERE `id`= 63272 AND `quest`= 31147; -- Ting <Monk Trainer>, Quest: Tiger Palm

-- and they also should no longer end these quests:
DELETE FROM `creature_questender` WHERE `id` = 2119 AND `quest` IN (3095,24969);  -- Dannal Stern <Warrior Trainer>, Quest:Simple Scroll & Charging into Battle
DELETE FROM `creature_questender` WHERE `id` = 2122 AND `quest` IN (3096,24967);  -- David Trias <Rogue Trainer>, Quest:Encrypted Scroll & Stab!
DELETE FROM `creature_questender` WHERE `id` = 2123 AND `quest` IN (3097,24966);  -- Dark Cleric Duesten <Priest Trainer>, Quest:Hallowed Scroll & Of Light and Shadows
DELETE FROM `creature_questender` WHERE `id` = 2124 AND `quest` IN (3098,24965);  -- Isabella <Mage Trainer>, Quest:Glyphic Scroll & Magic Training
DELETE FROM `creature_questender` WHERE `id` = 2126 AND `quest` IN (3099,24968);  -- Maximillion <Warlock Trainer>, Quest:Tainted Scroll & Dark Deeds
DELETE FROM `creature_questender` WHERE `id`= 38911 AND `quest` IN (24962,24964); -- Xavier the Huntsman <Hunter Trainer>, Quest:Trail-Worn Scroll & The Thrill of the Hunt
DELETE FROM `creature_questender` WHERE `id`= 63272 AND `quest` IN (31146,31147); -- Ting <Monk Trainer>, Quest:Scribbled Scroll & Tiger Palm

-- Disable all the quests listed above
DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (3095,3096,3097,3098,3099,24962,24964,24965,24966,24967,24968,24969,31146,31147);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  3095, 0, '', '', 'Obsolete quest: Simple Scroll'),
(1,  3096, 0, '', '', 'Obsolete quest: Encrypted Scroll'),
(1,  3097, 0, '', '', 'Obsolete quest: Hallowed Scroll'),
(1,  3098, 0, '', '', 'Obsolete quest: Glyphic Scroll'),
(1,  3099, 0, '', '', 'Obsolete quest: Tainted Scroll'),
(1, 24962, 0, '', '', 'Obsolete quest: Trail-Worn Scroll'),
(1, 24964, 0, '', '', 'Obsolete quest: The Thrill of the Hunt'),
(1, 24965, 0, '', '', 'Obsolete quest: Magic Training'),
(1, 24966, 0, '', '', 'Obsolete quest: Of Light and Shadows'),
(1, 24967, 0, '', '', 'Obsolete quest: Stab!'),
(1, 24968, 0, '', '', 'Obsolete quest: Dark Deeds'),
(1, 24969, 0, '', '', 'Obsolete quest: Charging into Battle'),
(1, 31146, 0, '', '', 'Obsolete quest: Scribbled Scroll'),
(1, 31147, 0, '', '', 'Obsolete quest: Tiger Palm');
