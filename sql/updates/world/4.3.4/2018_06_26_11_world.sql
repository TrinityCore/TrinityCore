DELETE FROM `spell_proc` WHERE `SpellId`= 77495;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(77495, 0, 7, 0x00000020 | 0x00000040 , 0x02000000 | 0x00000002, 0x0, 0x00004000, 2, 1, 0, 32, 0, 100,  0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dru_harmony';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(77495,'spell_dru_harmony');
