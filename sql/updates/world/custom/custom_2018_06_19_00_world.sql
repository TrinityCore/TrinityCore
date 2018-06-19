DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_reaping';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(56835, 'spell_dk_reaping');

DELETE FROM `spell_proc` WHERE `spellId`= 56835;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(56835, 15, 0x00400000, 0x00010000, 0x00000200, 0x00011010, 0x1, 0x1, 0x0, 0x0);
