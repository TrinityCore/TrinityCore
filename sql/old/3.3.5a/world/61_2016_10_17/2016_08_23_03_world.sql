DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=66512;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_q14076_14092_pound_drum','spell_q12279_cast_net');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(66512,'spell_q14076_14092_pound_drum'),
(48794,'spell_q12279_cast_net');
