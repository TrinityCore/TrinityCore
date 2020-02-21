DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_rog_improved_expose_armor',
'spell_rog_murderous_intent');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-14168, 'spell_rog_improved_expose_armor'),
(-14158, 'spell_rog_murderous_intent');

DELETE FROM `spell_proc` WHERE `SpellId` In (-14168, -14158);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(-14168, 8, 0, 0, 0, 0, 4, 2, 0, 0),
(-14158, 8, 0x00000004, 0, 0, 0, 1, 2, 0, 0);
