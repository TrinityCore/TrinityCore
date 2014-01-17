-- Unlocking zuluhed chains
DELETE FROM `spell_script_names` WHERE `spell_id`=38790;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(38790, 'spell_unlocking_zuluheds_chains');
