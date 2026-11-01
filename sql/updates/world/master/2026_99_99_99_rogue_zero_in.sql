DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_rog_zero_in_proc';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (1259486, 'spell_rog_zero_in_proc');

DELETE FROM `spell_proc` WHERE `SpellId` IN (1259485);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1259485,0x00,8,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0,0,0,0); -- Zero In

DELETE FROM `spell_proc` WHERE `SpellId` IN (1259486);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1259486,0x00,8,0x00000000,0x00000000,0x00000000,0x00008000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Zero In
