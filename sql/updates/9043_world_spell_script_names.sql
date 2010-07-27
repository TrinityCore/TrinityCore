DELETE FROM spell_script_names WHERE spell_id=19958 AND ScriptName='spell_mage_cold_snap';
DELETE FROM spell_script_names WHERE spell_id=32826 AND ScriptName='spell_mage_polymorph_visual';
DELETE FROM spell_script_names WHERE spell_id=31687 AND ScriptName='spell_mage_summon_water_elemental';
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES 
(11958,'spell_mage_cold_snap'),
(32826,'spell_mage_polymorph_visual'),
(31687,'spell_mage_summon_water_elemental');
