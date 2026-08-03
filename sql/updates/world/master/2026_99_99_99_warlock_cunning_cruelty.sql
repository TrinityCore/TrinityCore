DELETE FROM `spell_proc` WHERE `SpellId` IN (453172);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(453172,0x00,5,0x00800001,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Cunning Cruelty

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_cunning_cruelty';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(453172, 'spell_warl_cunning_cruelty');
