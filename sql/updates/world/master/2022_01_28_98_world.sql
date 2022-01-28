UPDATE `spell_script_names` SET `ScriptName`='spell_pal_judgment' WHERE `spell_id`=20271;
UPDATE `spell_script_names` SET `ScriptName`='spell_pal_judgment' WHERE `spell_id`=275779;

DELETE FROM `spell_script_names` WHERE `spell_id`=275773 AND `ScriptName`='spell_pal_judgement';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(275773, 'spell_pal_judgment');
