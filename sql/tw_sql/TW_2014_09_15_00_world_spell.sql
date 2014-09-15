
DELETE FROM `creature_template_addon` WHERE `entry` IN (38374, 23231, 25706, 24968, 40295, 36979);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES 
(38374, '71849'), -- Toxic Wasteling Passive
(23231, '40619'), -- willy
(25706, '45887'), -- Scorchling
(24968, '45266'), -- Clockwork Rocket Bot
(40295, '45266'), -- Blue Clockwork Rocket Bot
(36979, '69683 69732'); -- Lil KT

DELETE FROM `spell_script_names` WHERE `spell_id` IN (45888, 40638, 69682, 71848, 45267);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(45888, 'TW_spell_scorchling_focus'),
(40638, 'TW_spell_willy_focus'),
(69682, 'TW_spell_lil_kt_focus'),
(71848, 'TW_spell_toxic_wasteling_focus'),
(45267, 'TW_spell_rocket_bot_focus');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 71847;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(71847, 71874, 0, 'Toxic Wasteling - Devour');
