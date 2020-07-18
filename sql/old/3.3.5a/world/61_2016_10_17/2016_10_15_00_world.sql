-- Gnomish Mind Control Cap and Mind Amplification Dish script
DELETE FROM `spell_script_names` WHERE ScriptName IN ('spell_item_mind_control_cap','spell_item_universal_remote');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(67799, 'spell_item_mind_control_cap'),
(13180, 'spell_item_mind_control_cap'),
-- Gnomish Universal Remote script
(8344, 'spell_item_universal_remote');
