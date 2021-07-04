-- mage Alter Time spell
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_alter_time_aura', 'spell_mage_alter_time_active');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(110909,'spell_mage_alter_time_aura'),
(127140,'spell_mage_alter_time_active'),
(342246,'spell_mage_alter_time_aura'),
(342247,'spell_mage_alter_time_active');
