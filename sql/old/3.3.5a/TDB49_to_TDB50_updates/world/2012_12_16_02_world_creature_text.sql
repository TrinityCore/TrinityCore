DELETE FROM `creature_text` WHERE `entry`=35005;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Arelas Brightstar
(35005, 0, 0, 'Entering the arena, a paladin who is no stranger to the battlefield or tournament ground, the Grand Champion of the Argent Crusade, Eadric the Pure!', 14, 0, 100, 0, 0, 8574, 'Arelas Brightstar - SAY_EADRIC_INTRO'),
(35005, 1, 0, 'The next combatant is second to none in her passion for upholding the Light. I give you Argent Confessor Paletress!', 14, 0, 100, 0, 0, 8574, 'Arelas Brightstar - SAY_ARELAS_PALETRESS_INTRO'),
(35005, 2, 0, 'The Silver Covenant is pleased to present their contenders for this event, Highlord.', 14, 0, 100, 396, 0, 8574, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_INTRO_1'),
(35005, 3, 0, 'Coming out of the gate is Eressea Dawnsinger, skilled mage and Grand Champion of Silvermoon!', 12, 0, 100, 0, 0, 8573, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_INTRO_2'),
(35005, 4, 0, 'Entering the arena is the lean and dangerous Zul''tore, Grand Champion of Sen''jin!', 12, 0, 100, 0, 0, 8573, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_INTRO_2'),
(35005, 5, 0, 'Presenting the fierce Grand Champion of Orgrimmar, Mokra the Skullcrusher!', 12, 0, 100, 0, 0, 8573, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_INTRO_2'),
(35005, 6, 0, 'Representing the tenacity of the Forsaken, here is the Grand Champion of the Undercity, Deathstalker Visceri!', 12, 0, 100, 0, 0, 8573, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_INTRO_2'),
(35005, 7, 0, 'Tall in the saddle of his kodo, here is the venerable Runok Wildmane, Grand Champion of Thunder Bluff!', 12, 0, 100, 0, 0, 8573, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_INTRO_2'),
(35005, 8, 0, 'What''s that, up near the rafters?', 12, 0, 100, 25, 0, 0, 'Arelas Brightstar - SAY_ARELAS_KNIGHT_INTRO');

DELETE FROM `creature_text` WHERE `entry`=35004;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Jaeren Sunsworn
(35004, 0, 0, 'Entering the arena, a paladin who is no stranger to the battlefield or tournament ground, the Grand Champion of the Argent Crusade, Eadric the Pure!', 12, 0, 100, 0, 0, 8574, 'Jaeren Sunsworn - SAY_JAEREN_EADRIC_INTRO'),
(35004, 1, 0, 'The next combatant is second to none in her passion for upholding the Light. I give you Argent Confessor Paletress!', 14, 0, 100, 0, 0, 8574, 'Jaeren Sunsworn - SAY_JAEREN_PALETRESS_INTRO'),
(35004, 2, 0, 'The Sunreavers are proud to present their representatives in this trial by combat.', 14, 0, 100, 396, 0, 8574, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_INTRO_1'),
(35004, 3, 0, 'Coming out of the gate is Colosos, the towering Grand Champion of the Exodar!', 12, 0, 100, 0, 0, 8573, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_INTRO_2'),
(35004, 4, 0, 'Entering the arena is the Grand Champion of Darnassus, the skilled sentinel Jaelyne Evensong!', 12, 0, 100, 0, 0, 8573, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_INTRO_2'),
(35004, 5, 0, 'Here comes the small but deadly Ambrose Boltspark, Grand Champion of Gnomeregan!', 12, 0, 100, 0, 0, 8573, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_INTRO_2'),
(35004, 6, 0, 'Proud and strong, give a cheer for Marshal Jacob Alerius, the Grand Champion of Stormwind!', 12, 0, 100, 0, 0, 8573, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_INTRO_2'),
(35004, 7, 0, 'The might of the dwarves is represented today by the Grand Champion of Ironforge, Lana Stouthammer!', 12, 0, 100, 0, 0, 8573, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_INTRO_2'),
(35004, 8, 0, 'What''s that, up near the rafters?', 12, 0, 100, 25, 0, 0, 'Jaeren Sunsworn - SAY_JAEREN_KNIGHT_INTRO');

DELETE FROM `creature_text` WHERE `entry`=34996 AND `groupid` BETWEEN 50 AND 58;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Highlord Tirion Fordring
/* Grand Champions */
(34996, 50, 0, 'Welcome, champions. Today, before the eyes of your leaders and peers, you will prove yourselves worthy combatants.', 14, 0, 100, 1, 0, 0, 'Highlord Tirion Fordring - SAY_TIRION_GRAND_CHAMPION_INTRO_1'),
(34996, 51, 0, 'You will first be facing three of the Grand Champions of the Tournament! These fierce contenders have beaten out all others to reach the pinnacle of skill in the joust.', 14, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring - SAY_TIRION_GRAND_CHAMPION_INTRO_2'),
(34996, 52, 0, 'Begin!', 14, 0, 100, 0, 0, 8574, 'Highlord Tirion Fordring - SAY_TIRION_GRAND_CHAMPION_INTRO_3'),
/* Argent Confessor Paletress */
(34996, 53, 0, 'Well fought! Your next challenge comes from the Crusade''s own ranks. You will be tested against their considerable prowess.', 14, 0, 100, 0, 0, 15882, 'Highlord Tirion Fordring - SAY_TIRION_PALETRESS_INTRO_1'),
(34996, 54, 0, 'You may begin!', 14, 0, 100, 22, 0, 8574, 'Highlord Tirion Fordring - SAY_TIRION_PALETRESS_INTRO_2'),
/* The Black Knight */
(34996, 55, 0, 'Well done. You have proven yourself today-', 14, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring - SAY_TIRION_KNIGHT_INTRO_2'),
(34996, 56, 0, 'What is the meaning of this?', 14, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring - SAY_TIRION_KNIGHT_INTRO_2'),
(34996, 57, 0, 'My congratulations, champions. Through trials both planned and unexpected, you have triumphed.', 14, 0, 100, 0, 0, 15882, 'Highlord Tirion Fordring - SAY_TIRION_KNIGHT_OUTRO_1'),
(34996, 58, 0, 'Go now and rest; you''ve earned it.', 14, 0, 100, 0, 0, 0, 'Highlord Tirion Fordring - SAY_TIRION_KNIGHT_OUTRO_2');

DELETE FROM `creature_text` WHERE `entry`=34994;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Thrall
(34994, 0, 0, 'Fight well, Horde! Lok''tar Ogar!', 14, 0, 100, 22, 0, 0, 'Thrall - SAY_THRALL_GRAND_CHAMPIONS_INTRO'),
(34994, 1, 0, 'Well done, Horde!', 14, 0, 100, 66, 0, 0, 'Thrall - SAY_THRALL_KNIGHT_OUTRO'),
(34994, 2, 0, 'Garrosh, enough.', 12, 0, 100, 396, 0, 0, 'Thrall');

DELETE FROM `creature_text` WHERE `entry`=34990 AND `groupid` BETWEEN 50 AND 53;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- King Varian Wrynn
(34990, 50, 0, 'I have no taste for these games, Tirion. Still... I trust they will perform admirably.', 12, 0, 100, 1, 0, 0, 'King Varian Wrynn'),
(34990, 51, 0, 'Don''t just stand there; kill him!', 14, 0, 100, 22, 0, 0, 'King Varian Wrynn'),
(34990, 52, 0, 'I did not come here to watch animals tear at each other senselessly, Tirion.', 12, 0, 100, 1, 0, 0, 'King Varian Wrynn'),
(34990, 53, 0, 'You fought well.', 14, 0, 100, 66, 0, 0, 'King Varian Wrynn - SAY_KNIGHT_OUTRO');

DELETE FROM `creature_text` WHERE `entry`=34995 AND `groupid` BETWEEN 50 AND 52;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Garrosh Hellscream
(34995, 50, 0, 'Finally, a fight worth watching.', 12, 0, 100, 396, 0, 0, 'Garrosh Hellscream - SAY_GARROSH_GRAND_CHAMPIONS_INTRO'),
(34995, 51, 0, 'Tear him apart!', 14, 0, 100, 22, 0, 0, 'Garrosh Hellscream'),
(34995, 52, 0, 'Admirably? Hah! I will enjoy watching your weak little champions fail, human.', 14, 0, 100, 22, 0, 0, 'Garrosh Hellscream');

DELETE FROM `creature_text` WHERE `entry` IN (35572,35569,35571,35570,35617,34705,34701,34703,34702,34657);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Grand Champions
/* Horde */
(35572, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Mokra the Skullcrusher - SAY_TRAMPLED'),
(35569, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Eressea Dawnsinger - SAY_TRAMPLED'),
(35571, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Runok Wildmane - SAY_TRAMPLED'),
(35570, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Zul''tore - SAY_TRAMPLED'),
(35617, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Deathstalker Visceri - SAY_TRAMPLED'),
/* Alliance */
(34705, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Marshal Jacob Alerius - SAY_TRAMPLED'),
(34701, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Colosos - SAY_TRAMPLED'),
(34703, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Lana Stouthammer - SAY_TRAMPLED'),
(34702, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Ambrose Boltspark - SAY_TRAMPLED'),
(34657, 0, 0, '$n is trampled!', 16, 0, 100, 0, 0, 0, 'Jaelyne Evensong - SAY_TRAMPLED');

DELETE FROM `creature_text` WHERE `entry` IN (34883,34887,34904,34903,34902,34901,34905,34906,34910,34900,34909,34908);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- [ph] Argent Raid Spectator - FX - Horde
(34883, 0, 0, 'The Horde spectators cheer for $n.', 16, 0, 100, 71, 0, 8574, '[ph] Argent Raid Spectator - FX - Horde - SAY_SPECTATOR_PALETRESS_INTRO'),
-- [ph] Argent Raid Spectator - FX - Alliance
(34887, 0, 0, 'The Alliance spectators cheer for $n.', 16, 0, 100, 71, 0, 8574, '[ph] Argent Raid Spectator - FX - Alliance - SAY_SPECTATOR_PALETRESS_INTRO'),
-- [ph] Argent Raid Spectator - FX - Blood Elf
(34904, 0, 0, 'The blood elves of Silvermoon cheer for $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Blood Elf SAY_PALETRESS_INTRO_1 - SAY_CHEER'),
-- [ph] Argent Raid Spectator - FX - Tauren
(34903, 0, 0, 'The tauren of Thunder Bluff cheer for $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Tauren - SAY_CHEER'),
-- [ph] Argent Raid Spectator - FX - Troll
(34902, 0, 0, 'The trolls of the Sen''jin Village begin a chant to celebrate $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Troll - SAY_CHEER'),
-- [ph] Argent Raid Spectator - FX - Orc
(34901, 0, 0, 'The orcs of Orgrimmar cheer for $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Orc - SAY_CHEER'),
-- [ph] Argent Raid Spectator - FX - Undead
(34905, 0, 0, 'The forsaken of the Undercity cheer for $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Undead - SAY_CHEER'),
-- [ph] Argent Raid Spectator - FX - Dwarf
(34906, 0, 0, 'The dwarves of Ironforge begin a cheer for $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Dwarf - SAY_CHEER'),
-- [ph] Argent Raid Spectator - FX - Gnome
(34910, 0, 0, 'The gnomes of Gnomeregan cheer for $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Gnome - SAY_CHEER'),
-- [ph] Argent Raid Spectator - FX - Human
(34900, 0, 0, 'The humans of Stormwind cheer for $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Human - SAY_CHEER'),
-- [ph] Argent Raid Spectator - FX - Night Elf
(34909, 0, 0, 'The night elves of Darnassus cheer for $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Night Elf - SAY_CHEER'),
-- [ph] Argent Raid Spectator - FX - Draenei
(34908, 0, 0, 'The draenei of the Exodar cheer for $n.', 16, 0, 100, 0, 0, 8573, '[ph] Argent Raid Spectator - FX - Draenei - SAY_CHEER');

DELETE FROM `creature_text` WHERE `entry` IN (35052,35041,35033,35046,35043,35047,35044,35039,35034,35049,35030,34942,35050,35042,35045,35037,35031,35038,35048,35029,35032,35028,35040,35036,35051);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Memory of X
(35052, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Algalon - EMOTE_WAKING_NIGHTMARE'),
(35041, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Archimonde - EMOTE_WAKING_NIGHTMARE'),
(35033, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Chromaggus - EMOTE_WAKING_NIGHTMARE'),
(35046, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Cyanigosa - EMOTE_WAKING_NIGHTMARE'),
(35043, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Delrissa - EMOTE_WAKING_NIGHTMARE'),
(35047, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Eck - EMOTE_WAKING_NIGHTMARE'),
(35044, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Entropius - EMOTE_WAKING_NIGHTMARE'),
(35039, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Gruul - EMOTE_WAKING_NIGHTMARE'),
(35034, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Hakkar - EMOTE_WAKING_NIGHTMARE'),
(35049, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Heigan - EMOTE_WAKING_NIGHTMARE'),
(35030, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Herod - EMOTE_WAKING_NIGHTMARE'),
(34942, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Hogger - EMOTE_WAKING_NIGHTMARE'),
(35050, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Ignis - EMOTE_WAKING_NIGHTMARE'),
(35042, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Illidan - EMOTE_WAKING_NIGHTMARE'),
(35045, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Ingvar - EMOTE_WAKING_NIGHTMARE'),
(35037, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Kalithresh - EMOTE_WAKING_NIGHTMARE'),
(35031, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Lucifron - EMOTE_WAKING_NIGHTMARE'),
(35038, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Malchezaar - EMOTE_WAKING_NIGHTMARE'),
(35048, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Onyxia - EMOTE_WAKING_NIGHTMARE'),
(35029, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Mutanus - EMOTE_WAKING_NIGHTMARE'),
(35032, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Thunderaan - EMOTE_WAKING_NIGHTMARE'),
(35028, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of VanCleef - EMOTE_WAKING_NIGHTMARE'),
(35040, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Vashj - EMOTE_WAKING_NIGHTMARE'),
(35036, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Vek''nilash - EMOTE_WAKING_NIGHTMARE'),
(35051, 0, 0, '%s begins to invoke the Waking Nightmare!', 41, 0, 100, 0, 0, 0, 'Memory of Vezax - EMOTE_WAKING_NIGHTMARE');

DELETE FROM `creature_text` WHERE `entry`=35564;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Risen Arelas Brightstar
(35564, 0, 0, 'What a Brains shot!', 12, 36, 100, 0, 0, 0, 'Risen Arelas Brightstar'),
(35564, 1, 0, 'Somone stop that ghoul!', 12, 36, 100, 0, 0, 0, 'Risen Arelas Brightstar'),
(35564, 2, 0, 'That had to hurt! Brains!', 12, 36, 100, 0, 0, 0, 'Risen Arelas Brightstar');

DELETE FROM `creature_text` WHERE `entry`=35545;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Risen Jaeren Sunsworn
(35545, 0, 0, 'What a Brains shot!', 12, 36, 100, 0, 0, 0, 'Risen Jaeren Sunsworn'),
(35545, 1, 0, 'Somone stop that ghoul!', 12, 36, 100, 0, 0, 0, 'Risen Jaeren Sunsworn'),
(35545, 2, 0, 'That had to hurt! Brains!', 12, 36, 100, 0, 0, 0, 'Risen Jaeren Sunsworn');

DELETE FROM `creature_text` WHERE `entry`=34928;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Argent Confessor Paletress
(34928, 0, 0, 'Thank you, good herald. Your words are too kind.', 12, 0, 100, 2, 0, 16245, 'Argent Confessor Paletress - SAY_INTRO_1'),
(34928, 1, 0, 'May the Light give me strength to provide a worthy challenge.', 12, 0, 100, 16, 0, 16246, 'Argent Confessor Paletress - SAY_INTRO_2'),
(34928, 2, 0, 'Well, then. Let us begin.', 14, 0, 100, 0, 0, 16247, 'Argent Confessor Paletress - SAY_AGGRO'),
(34928, 3, 0, 'Take this time to consider your past deeds.', 14, 0, 100, 0, 0, 16248, 'Argent Confessor Paletress - SAY_MEMORY_SUMMON'),
(34928, 4, 0, 'Even the darkest memory fades when confronted!', 14, 0, 100, 0, 0, 16249, 'Argent Confessor Paletress - SAY_MEMORY_DEATH'),
(34928, 5, 0, 'Take your rest.', 14, 0, 100, 0, 0, 16250, 'Argent Confessor Paletress - SAY_KILL_PLAYER'),
(34928, 5, 1, 'Be at ease.', 14, 0, 100, 0, 0, 16251, 'Argent Confessor Paletress - SAY_KILL_PLAYER'),
(34928, 6, 0, 'Excellent work!', 14, 0, 100, 0, 0, 16252, 'Argent Confessor Paletress - SAY_DEFEATED');

DELETE FROM `creature_text` WHERE `entry`=35119;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Eadric the Pure
(35119, 0, 0, 'Are you up to the challenge? I will not hold back.', 12, 0, 100, 397, 0, 16134, 'Eadric the Pure - SAY_INTRO'),
(35119, 1, 0, 'Prepare yourselves!', 14, 0, 100, 0, 0, 16135, 'Eadric the Pure - SAY_AGGRO'),
(35119, 2, 0, '%s begins to radiate light. Shield your eyes!', 41, 0, 100, 0, 0, 0, 'Eadric the Pure - EMOTE_RADIANCE'),
(35119, 3, 0, '%s targets $n with the Hammer of the Righteous!', 41, 0, 100, 0, 0, 16136, 'Eadric the Pure - EMOTE_HAMMER_RIGHTEOUS'),
(35119, 4, 0, 'Hammer of the Righteous!', 14, 0, 100, 0, 0, 16136, 'Eadric the Pure - SAY_HAMMER_RIGHTEOUS'),
(35119, 5, 0, 'You... You need more practice.', 14, 0, 100, 0, 0, 16137, 'Eadric the Pure - SAY_KILL_PLAYER'),
(35119, 5, 1, 'Nay! Nay! And I say yet again nay! Not good enough!', 14, 0, 100, 0, 0, 16138, 'Eadric the Pure - SAY_KILL_PLAYER'),
(35119, 6, 0, 'I yield! I submit. Excellent work. May I run away now?', 14, 0, 100, 0, 0, 16139, 'Eadric the Pure - SAY_DEFEATED');

DELETE FROM `creature_text` WHERE `entry`=35451;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- The Black Knight
(35451, 0, 0, 'You spoiled my grand entrance, rat.', 12, 0, 100, 0, 0, 16256, 'The Black Knight - SAY_INTRO_1'),
(35451, 1, 0, 'Did you honestly think an agent of the Lich King would be bested on the field of your pathetic little tournament?', 12, 0, 100, 396, 0, 16257, 'The Black Knight - SAY_INTRO_2'),
(35451, 2, 0, 'I''ve come to finish my task.', 12, 0, 100, 396, 0, 16258, 'The Black Knight - SAY_INTRO_3'),
(35451, 3, 0, 'This farce ends here!', 14, 0, 100, 0, 0, 16259, 'The Black Knight - SAY_AGGRO'),
(35451, 4, 0, 'My rotting flesh was just getting in the way!', 14, 0, 100, 0, 0, 16262, 'The Black Knight - SAY_PHASE_2'),
(35451, 5, 0, 'I have no need for bones to best you!', 14, 0, 100, 0, 0, 16263, 'The Black Knight - SAY_PHASE_3'),
(35451, 6, 0, 'Pathetic.', 14, 0, 100, 0, 0, 16260, 'The Black Knight - SAY_KILL_PLAYER'),
(35451, 6, 1, 'A waste of flesh.', 14, 0, 100, 0, 0, 16261, 'The Black Knight - SAY_KILL_PLAYER'),
(35451, 7, 0, 'No! I must not fail... again...', 14, 0, 100, 0, 0, 16264, 'The Black Knight - SAY_DEATH');
