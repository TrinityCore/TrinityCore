DELETE FROM spell_script_names WHERE spell_id IN (527, -527, 97690, 97691);
DELETE FROM spell_script_names WHERE ScriptName="spell_pri_dispel_magic";
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(527, "spell_pri_dispel_magic");
