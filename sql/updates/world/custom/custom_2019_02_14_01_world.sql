DELETE FROM `spell_proc` WHERE `SpellId` IN (-96269, -49018, 49018, 49529, 49530, -51099);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `ProcsPerMinute`, `Chance`) VALUES
(-96269, 15, 0x00000001 | 0x00000020 | 0x00000800, 0x08000000 | 0x00080000 | 0x00000080 | 0x00020000, 0x00002000 | 0x00000020, 0, 7, 4, 12287, 0, 0, 0, 0, 100),
(49018, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(49529, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0),
(49530, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0),
(-51099, 15, 0x00000001 | 0x00000002 | 0x00000004, 0, 0x00001000, 0, 1 | 4, 1, 0, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dk_deaths_advance',
'spell_dk_deaths_advance_aura',
'spell_dk_ebon_plaguebringer');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-96269, 'spell_dk_deaths_advance'),
(96268, 'spell_dk_deaths_advance_aura'),
(-51099, 'spell_dk_ebon_plaguebringer');
