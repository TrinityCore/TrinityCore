DELETE FROM `spell_proc` WHERE `SpellId` IN (-18179, 17941);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Chance`, `Charges`, `AttributesMask`) VALUES
(-18179, 5, 0, 0x00000200, 0, 0, 4, 2, 0, 0, 0, 32),
(17941, 5, 0x00000001, 0, 0, 0x00010000, 1, 1, 0, 100, 1, 8);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_warl_jinx',
'spell_warl_curse_of_weakness');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-18179, 'spell_warl_jinx'),
(702, 'spell_warl_curse_of_weakness');
