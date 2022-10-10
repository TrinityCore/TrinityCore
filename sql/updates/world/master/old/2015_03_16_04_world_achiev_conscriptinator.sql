update creature_template set ScriptName = 'npc_krikthik_conscript' where entry = 61213;

delete from spell_script_names where spell_id = 118795;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (118795, 'spell_resin_residue');
