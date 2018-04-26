DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_gen_pvp_trinket',
'spell_pvp_trinket_shared_cd');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42292, 'spell_gen_pvp_trinket'),
(59752, 'spell_gen_pvp_trinket');
