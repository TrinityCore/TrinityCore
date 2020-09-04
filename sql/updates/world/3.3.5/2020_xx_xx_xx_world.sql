-- Fix Gargoyle Summon
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_summon_gargoyle';
INSERT INTO spell_script_names VALUES (49206, 'spell_dk_summon_gargoyle');

-- Fix Gargoyle Strike
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_gargoyle_strike';
INSERT INTO `spell_script_names` VALUES (51963, 'spell_dk_gargoyle_strike');
