DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_rog_overkill';
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rog_vanish','spell_rog_vanish_aura');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(1856,'spell_rog_vanish'),
(11327,'spell_rog_vanish_aura');
