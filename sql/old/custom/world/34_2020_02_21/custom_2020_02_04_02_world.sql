DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_rog_combat_potency',
'spell_rog_restless_blades',
'spell_rog_bandits_guile');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-35541, 'spell_rog_combat_potency'),
(-79095, 'spell_rog_restless_blades'),
(-84652, 'spell_rog_bandits_guile');

DELETE FROM `spell_proc` WHERE `SpellId` In (-35541, -79095, -14158, -84652);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(-35541, 8, 0, 0, 0, 0, 1, 2, 0, 2),
(-79095, 8, 0x00020000 | 0x00100000, 0x00000008, 0, 0x00000010, 1, 2, 0, 0),
(-14158, 8, 0x00000004, 0, 0, 0x00000010, 1, 2, 0, 2),
(-84652, 8, 0x00000002, 0x10000000, 0, 0, 1, 2, 0, 2);
