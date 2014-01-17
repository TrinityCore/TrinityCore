-- Slad'ran
DELETE FROM `creature_text` WHERE `entry`=29304 AND `groupid`=5;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(29304, 5, 0, '%s begins to cast Poison Nova!', 41, 0, 100, 0, 0, 0, 'Slad''ran - EMOTE_NOVA');

-- Mage-Lord Urom
DELETE FROM `creature_text` WHERE `entry`=27655;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(27655, 0, 0, 'What do we have here... those that would defy the Spell-Weaver? Those without foresight or understanding. How can I make you see? Malygos is saving the world from itself! Bah! You are hardly worth my time!', 14, 0, 100, 1, 0, 13635, 'Mage-Lord Urom - SAY_SUMMON_1'),
(27655, 1, 0, 'Clearly my pets failed. Perhaps another demonstration is in order.', 14, 0, 100, 1, 0, 13636, 'Mage-Lord Urom - SAY_SUMMON_2'),
(27655, 2, 0, 'Still you fight. Still you cling to misguided principles. If you survive, you''ll find me in the center ring.', 14, 0, 100, 1, 0, 13637, 'Mage-Lord Urom - SAY_SUMMON_3'),
(27655, 3, 0, 'Poor blind fools!', 14, 0, 100, 0, 0, 13638, 'Mage-Lord Urom - SAY_AGGRO'),
(27655, 4, 0, '%s begins to cast Empowered Arcane Explosion!', 41, 0, 100, 0, 0, 0, 'Mage-Lord Urom - EMOTE_ARCANE_EXPLOSION'),
(27655, 5, 0, 'A taste... just a small taste... of the Spell-Weaver''s power!', 14, 0, 100, 0, 0, 13639, 'Mage-Lord Urom - SAY_ARCANE_EXPLOSION'),
(27655, 5, 1, 'So much unstable energy... but worth the risk to destroy you!', 14, 0, 100, 0, 0, 13640, 'Mage-Lord Urom - SAY_ARCANE_EXPLOSION'),
(27655, 6, 0, 'Everything I have done... has been for Azeroth....', 14, 0, 100, 0, 0, 13644, 'Mage-Lord Urom - SAY_DEATH'),
(27655, 7, 0, 'If only you understood!', 14, 0, 100, 0, 0, 13641, 'Mage-Lord Urom - SAY_PLAYER_KILL'),
(27655, 7, 1, 'Now do you see? Do you?!', 14, 0, 100, 0, 0, 13642, 'Mage-Lord Urom - SAY_PLAYER_KILL'),
(27655, 7, 2, 'Everything I\'ve done... has been for Azeroth...', 14, 0, 100, 0, 0, 13643, 'Mage-Lord Urom - SAY_PLAYER_KILL');

-- Shadron / Vesperon
DELETE FROM `creature_text` WHERE `entry`IN (30451,30449) AND `groupid`=7;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(30451, 7, 0, 'A Shadron Disciple appears in the Twilight!', 41, 0, 100, 0, 0, 0, 'Shadron - WHISPER_SHADRON_DICIPLE'),
(30449, 7, 0, 'A Vesperon Disciple appears in the Twilight!', 41, 0, 100, 0, 0, 0, 'Vesperon - WHISPER_SHADRON_DICIPLE');
