DELETE FROM spell_proc_event WHERE entry IN (142531, 120033, 118333, 104561);
INSERT INTO spell_proc_event (entry, ppmRate, Cooldown) VALUES 
(142531, 2, 0),
(120033, 2, 50),
(118333, 2, 0),
(104561, 2, 0);

DELETE FROM spell_script_names WHERE ScriptName = 'spell_pandaria_enchants';
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(142531, 'spell_pandaria_enchants'),
(120033, 'spell_pandaria_enchants'),
(104561, 'spell_pandaria_enchants'),
(118333, 'spell_pandaria_enchants');