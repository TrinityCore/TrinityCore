-- Quests and quest givers removed in patch 7.0.3
-- Orc starting area (Valley of Trials)

-- These NPCs are no longer quest givers as of patch 7.0.3:
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry` IN
(3153,  -- Frang <Warrior Trainer>
 3155,  -- Rwag <Rogue Trainer>
 3156,  -- Nartok <Warlock Trainer>
 3157,  -- Shikrik <Shaman Trainer>
 3707,  -- Ken'jai <Priest Trainer>
39206,  -- Acrypha <Mage Trainer>
39214); -- Karranisha <Hunter Trainer>

-- Gornek (3143) no longer offers these class quests:
DELETE FROM `creature_queststarter` WHERE `id`= 3143 AND `quest` IN
(2383,  -- Quest:Simple Parchment
 3087,  -- Quest:Etched Parchment
 3088,  -- Quest:Encrypted Parchment
 3089,  -- Quest:Rune-Inscribed Parchment
 3090,  -- Quest:Tainted Parchment
25138); -- Quest:Glyphic Parchment

DELETE FROM `creature_queststarter` WHERE `id` = 3153 AND `quest`= 25147; -- Frang <Warrior Trainer>, Quest:Charge
DELETE FROM `creature_queststarter` WHERE `id` = 3155 AND `quest`= 25141; -- Rwag <Rogue Trainer>, Quest:Eviscerate
DELETE FROM `creature_queststarter` WHERE `id` = 3156 AND `quest`= 25145; -- Nartok <Warlock Trainer>, Quest:Corruption
DELETE FROM `creature_queststarter` WHERE `id` = 3157 AND `quest`= 25143; -- Shikrik <Shaman Trainer>, Quest:Primal Strike
DELETE FROM `creature_queststarter` WHERE `id`= 39206 AND `quest`= 25149; -- Acrypha <Mage Trainer>, Quest:Frost Nova
DELETE FROM `creature_queststarter` WHERE `id`= 39214 AND `quest`= 25139; -- Karranisha <Hunter Trainer>, Quest:Steady Shot

DELETE FROM `creature_questender` WHERE `id` = 3153 AND `quest` IN (2383,3065,25147,25148); -- Simple Parchment,Simple Tablet,Charge,Hone Your Holler
DELETE FROM `creature_questender` WHERE `id` = 3155 AND `quest` IN (3083,3088,25141,25142); -- Encrypted Tablet,Encrypted Parchment,Eviscerate,Into the Shadows
DELETE FROM `creature_questender` WHERE `id` = 3156 AND `quest` IN (3090, 25145, 25146);    -- Tainted Parchment, Corruption, A Demonic Fire
DELETE FROM `creature_questender` WHERE `id` = 3157 AND `quest` IN (3084,3089,25143,25144); -- Rune-Inscribed Tablet,Rune-Inscribed Parchment,Primal Strike,Rock Meets Flesh
DELETE FROM `creature_questender` WHERE `id` = 3707 AND `quest` = 3085;                     -- Ken'jai <Priest Trainer>, Quest:Hallowed Tablet
DELETE FROM `creature_questender` WHERE `id`= 39206 AND `quest` IN (25138, 25149, 25150);   -- Glyphic Parchment, Frost Nova, Empowered Minds
DELETE FROM `creature_questender` WHERE `id`= 39214 AND `quest` IN (3082,3087,25139,25140); -- Etched Tablet,Etched Parchment,Steady Shot,Swine Hunting

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (2383,3065,3082,3083,3084,3085,3087,3088,3089,3090,25138,25139,25140,25141,25142,25143,25144,25145,25146,25147,25148,25149,25150);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  2383, 0, '', '', 'Obsolete quest: Simple Parchment'),
(1,  3065, 0, '', '', 'Obsolete quest: Simple Tablet'),
(1,  3082, 0, '', '', 'Obsolete quest: Etched Tablet'),
(1,  3083, 0, '', '', 'Obsolete quest: Encrypted Tablet'),
(1,  3084, 0, '', '', 'Obsolete quest: Rune-Inscribed Tablet'),
(1,  3085, 0, '', '', 'Obsolete quest: Hallowed Tablet'),
(1,  3087, 0, '', '', 'Obsolete quest: Etched Parchment'),
(1,  3088, 0, '', '', 'Obsolete quest: Encrypted Parchment'),
(1,  3089, 0, '', '', 'Obsolete quest: Rune-Inscribed Parchment'),
(1,  3090, 0, '', '', 'Obsolete quest: Tainted Parchment'),
(1, 25138, 0, '', '', 'Obsolete quest: Glyphic Parchment'),
(1, 25139, 0, '', '', 'Obsolete quest: Steady Shot'),
(1, 25140, 0, '', '', 'Obsolete quest: Swine Hunting'),
(1, 25141, 0, '', '', 'Obsolete quest: Eviscerate'),
(1, 25142, 0, '', '', 'Obsolete quest: Into the Shadows'),
(1, 25143, 0, '', '', 'Obsolete quest: Primal Strike'),
(1, 25144, 0, '', '', 'Obsolete quest: Rock Meets Flesh'),
(1, 25145, 0, '', '', 'Obsolete quest: Corruption'),
(1, 25146, 0, '', '', 'Obsolete quest: A Demonic Fire'),
(1, 25147, 0, '', '', 'Obsolete quest: Charge'),
(1, 25148, 0, '', '', 'Obsolete quest: Hone Your Holler'),
(1, 25149, 0, '', '', 'Obsolete quest: Frost Nova'),
(1, 25150, 0, '', '', 'Obsolete quest: Empowered Minds');
