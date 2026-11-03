DELETE FROM `spell_proc` WHERE `SpellId` IN (1246556);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1246556,0x00,107,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0,0,0,0); -- Spontaneous Immolation

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_spontaneous_immolation';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1246556, 'spell_dh_spontaneous_immolation');
