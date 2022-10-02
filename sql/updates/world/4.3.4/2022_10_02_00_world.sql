DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_dark_simulacrum';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77606, 'spell_dk_dark_simulacrum');

DELETE FROM `spell_proc` WHERE `SpellId` IN (77606, 77616);
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(77606 , 0x1 | 0x2 | 0x4, 0x1),
(77616 , 0x1 | 0x2 | 0x4, 0x1);
