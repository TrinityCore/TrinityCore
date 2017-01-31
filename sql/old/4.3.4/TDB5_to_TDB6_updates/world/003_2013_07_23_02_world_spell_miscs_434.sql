DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dk_death_strike_enabler';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(89832, 'spell_dk_death_strike_enabler');

-- Improved Death Strike (talent) ranks
DELETE FROM `spell_ranks` WHERE `first_spell_id` = 62905;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(62905, 62905, 1),
(62905, 62908, 2),
(62905, 81138, 3);

