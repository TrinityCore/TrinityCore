DELETE FROM spell_linked_spell WHERE spell_trigger = 73325;
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type, comment) VALUES
(73325, 92833, 0, "Priest - Leap of Faith");

DELETE FROM spell_script_names WHERE spell_id = 92833;
DELETE FROM spell_script_names WHERE spell_id = -139;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(92833, "spell_pri_leap_of_faith_effect_trigger"),
(139, "spell_pri_renew"); -- Minus doesnt matter, theres no rank any more
