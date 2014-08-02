UPDATE `spell_proc_event` SET `procEx`='32768' WHERE entry = '-63730';
DELETE FROM spell_script_names WHERE Scriptname = 'spell_pri_binding_heal';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
('32546', 'spell_pri_binding_heal');