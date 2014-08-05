DELETE FROM spell_proc_event WHERE entry = 44445;
INSERT INTO `spell_proc_event` VALUES 
('44445', '0', '3', '4194323', '4096', '0', '0', '2', '0', '100', '0');

DELETE FROm spell_script_names WHERE ScriptName = 'spell_mage_hot_streak';
INSERT INTO spell_script_names VALUES
(44445, 'spell_mage_hot_streak');