-- Remove redundant areatrigger scripts
DELETE FROM `areatrigger_scripts` WHERE `entry` IN(5369,5423);
-- Add spellscript for trap spell
DELETE FROM `spell_script_names` WHERE `spell_id`=62705;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(62705,'spell_auto_repair');

