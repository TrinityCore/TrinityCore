-- hand of sacrifice scriptname
DELETE FROM spell_script_names WHERE spell_id = 6940;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(6940, 'spell_pal_hand_of_sacrifice');

-- divine sacrifice scriptname
DELETE FROM spell_script_names WHERE spell_id = 64205;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(64205, 'spell_pal_divine_sacrifice');

-- righteous defense scriptname
DELETE FROM spell_script_names WHERE spell_id = 31789;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(31789, 'spell_pal_righteous_defense');
