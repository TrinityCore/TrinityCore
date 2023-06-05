DELETE FROM `spell_proc` WHERE `SpellId` IN (391339);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(391339,0x00,6,0x00000040,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Empowered Renew

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_empowered_renew';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(391339,'spell_pri_empowered_renew');
