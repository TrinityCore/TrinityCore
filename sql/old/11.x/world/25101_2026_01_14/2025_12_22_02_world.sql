DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_protector_of_the_frail');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(373036, 'spell_pri_protector_of_the_frail');

DELETE FROM `spell_proc` WHERE `SpellId` IN (373035);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(373035,0x00,6,0x00000001,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Protector of the Frail
