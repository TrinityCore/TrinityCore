-- Conjure Refreshment
DELETE FROM `spell_script_names` WHERE `spell_id`=42955;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(42955, 'spell_mage_conjure_refreshment');

-- Sacred Shield
DELETE FROM spell_proc_event WHERE entry=85285;
INSERT INTO spell_proc_event (entry, Cooldown) VALUES(85285, 60);
DELETE FROM spell_script_names WHERE spell_id=85285;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(85285, 'spell_pal_sacred_shield');

-- Recuperate
DELETE FROM spell_script_names WHERE spell_id=73651;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(73651, "spell_rog_recuperate");
