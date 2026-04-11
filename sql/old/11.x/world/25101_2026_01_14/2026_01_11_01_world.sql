DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_shadowy_apparitions','spell_pri_shadowy_apparition_dummy','spell_pri_auspicious_spirits');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(341491,'spell_pri_shadowy_apparitions'),
(341263,'spell_pri_shadowy_apparition_dummy'),
(148859,'spell_pri_auspicious_spirits');

DELETE FROM `spell_proc` WHERE `SpellId` IN (341491);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(341491,0x00,6,0x0000A000,0x00000000,0x00800000,0x00000400,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Shadowy Apparitions
