--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-12480,12479,12480);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sunken_temple_hex_of_jammalan','spell_sunken_temple_hex_of_jammalan_transform');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(12479,'spell_sunken_temple_hex_of_jammalan'),
(12480,'spell_sunken_temple_hex_of_jammalan_transform');
