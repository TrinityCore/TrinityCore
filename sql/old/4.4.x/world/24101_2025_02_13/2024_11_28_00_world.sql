DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_improved_steady_shot';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-53221, 'spell_hun_improved_steady_shot');

DELETE FROM `spell_proc` WHERE `SpellId`= -53221;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(-53221, 9, 0x1, 0x1);
