-- Sindragosa update
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_mystic_buffet';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(70127,'spell_sindragosa_mystic_buffet'),
(72528,'spell_sindragosa_mystic_buffet'),
(72529,'spell_sindragosa_mystic_buffet'),
(72530,'spell_sindragosa_mystic_buffet');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 70157 AND `spell_effect` = 69700;

-- Register spell-script for Sindragosa ability Permeating Chill / Durchdringende Kaelte 70107 in instance / Instanz ICC / Eiskronenzitadelle / Icecrown Citadel
DELETE FROM `spell_script_names` WHERE `spell_id` = 70107 AND `ScriptName` = 'spell_sindragosa_permeating_chill';
INSERT INTO `spell_script_names` (spell_id, ScriptName) VALUES
(70107, 'spell_sindragosa_permeating_chill');

-- Fix creature Ice Tomb / Eisgrab in Sindragosa encounter in instance / Instanz ICC Icecrown Citadel Eiskronenzitadelle
-- Add immunities to avoid being moved away (knockback in script)
UPDATE `creature_template` SET `mechanic_immune_mask` = 650853247 WHERE `entry` IN (36980, 38320, 38321, 38322);

-- Fix spell 69762 Unchained Magic / Entfesselte Magie debuff in Sindragosa encounter in instance / Instanz ICC Icecrown Citadel Eiskronenzitadelle
-- Add internal cooldown with 1 seconds, so multi-spell spells will only apply one stack of triggered spell 69766 (i.e. Chain Heal)
DELETE FROM `spell_proc_event` WHERE `entry` = 69762;
INSERT INTO `spell_proc_event` (entry, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, procFlags, procEx, ppmRate, CustomChance, Cooldown) VALUES
(69762, 0, 0, 0, 0, 0, 81920, 0, 0, 0, 1);

-- Close entrance door by default in encounter Sindragosa in instance / Instanz ICC / Eiskronenzitadelle / Icecrown Citadel
UPDATE `gameobject` SET `state` = 1 WHERE `id` = 201373;

-- Fix Ice Tomb ability, link script to correct spell, in encounter Sindragosa in instance / Instanz ICC / Eiskronenzitadelle / Icecrown Citadel
DELETE FROM `spell_script_names` WHERE `spell_id` = 69675 OR `ScriptName` = 'spell_sindragosa_ice_tomb_dummy';
INSERT INTO `spell_script_names` (spell_id, ScriptName) VALUES
(69675, 'spell_sindragosa_ice_tomb_dummy');
