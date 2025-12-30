DELETE FROM `spell_proc` WHERE `SpellId` IN (368275);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(368275,0x00,6,0x00001800,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x0,0x0,0x0,0,0,0,0); -- Binding Heals

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_binding_heals';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(368275,'spell_pri_binding_heals');
