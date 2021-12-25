DELETE FROM `spell_proc` WHERE `SpellId`=70904;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(70904, 0x0, 6, 0x00000000, 0x00000000, 0x00000800, 2048, 0x4, 0x0, 0x0, 0x0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dreamwalker_guardian_spirit_restriction';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(47788,'spell_dreamwalker_guardian_spirit_restriction');
