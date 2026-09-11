DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_expurgation';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(383344, 'spell_pal_expurgation');

DELETE FROM `spell_proc` WHERE `SpellId` IN (383344);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(383344,0x00,10,0x00000000,0x00000000,0x00000000,0x40000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Expurgation
