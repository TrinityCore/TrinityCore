DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_pri_mind_blast',
'spell_pri_masochism');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(8092, 'spell_pri_mind_blast'),
(-88994 , 'spell_pri_masochism');

DELETE FROM `spell_proc` WHERE `SpellId` IN (-88994, -14910, 87178, -47580, -87192);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`, `Chance`, `AttributesMask`, `Charges`) VALUES
(-88994, 0, 0, 0, 0, 0, 1, 0, 0, 0, 100, 0, 0),
(-14910, 6, 0, 0, 0x00010000, 0, 1, 2, 0, 0, 100, 16, 0),
(87178, 6, 0x00002000, 0, 0, 0x00020000, 1, 0, 0, 0, 100, 0, 1),
(-47580, 6, 0, 0, 0x0000040, 0, 1, 2, 0, 0, 0, 0, 0),
(-87192, 6, 0x00002000, 0, 0, 0, 1, 2, 2, 0, 0, 0, 0);
