DELETE FROM `spell_proc` WHERE `SpellId` IN (47515);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(47515,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x402,0x0,0x0,0,0,0,0); -- Divine Aegis

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_divine_aegis';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(47515,'spell_pri_divine_aegis');
