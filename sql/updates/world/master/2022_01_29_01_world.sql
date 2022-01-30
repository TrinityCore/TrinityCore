DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_blessing_of_faith';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_item_blessing_of_faith';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(37877,'spell_item_blessing_of_faith');