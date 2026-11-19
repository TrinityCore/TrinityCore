DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_rhapsody','spell_pri_rhapsody_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(390622, 'spell_pri_rhapsody'),
(390636, 'spell_pri_rhapsody_proc');

DELETE FROM `spell_proc` WHERE `SpellId` IN (390636);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390636,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0xA,0x0,0,0,0,1); -- Rhapsody
