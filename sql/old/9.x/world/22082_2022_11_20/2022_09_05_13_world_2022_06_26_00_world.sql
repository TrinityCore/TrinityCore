--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-33711,-38794,33686,51010);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_murmur_murmurs_touch','spell_item_dire_brew');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(33711,'spell_murmur_murmurs_touch'),
(38794,'spell_murmur_murmurs_touch'),
(51010,'spell_item_dire_brew');
