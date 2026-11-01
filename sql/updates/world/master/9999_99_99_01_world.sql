-- Frequent Traveler
DELETE FROM `spell_script_names` WHERE `spell_id` IN (113896, 120729) AND `ScriptName` = 'spell_warl_demonic_gateway_travel';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(113896, 'spell_warl_demonic_gateway_travel'),
(120729, 'spell_warl_demonic_gateway_travel');
