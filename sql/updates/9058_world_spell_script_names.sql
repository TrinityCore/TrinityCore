DELETE FROM spell_script_names WHERE spell_id=-47540 AND ScriptName='spell_pri_penance';
DELETE FROM spell_script_names WHERE spell_id=31231 AND ScriptName='spell_rog_cheat_death';
DELETE FROM spell_script_names WHERE spell_id=51662 AND ScriptName='spell_rog_hunger_for_blood';
DELETE FROM spell_script_names WHERE spell_id=14185 AND ScriptName='spell_rog_preparation';
DELETE FROM spell_script_names WHERE spell_id=5938 AND ScriptName='spell_rog_shiv';
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(-47540,'spell_pri_penance'),
(31231,'spell_rog_cheat_death'),
(51662,'spell_rog_hunger_for_blood'),
(14185,'spell_rog_preparation'),
(5938,'spell_rog_shiv');
