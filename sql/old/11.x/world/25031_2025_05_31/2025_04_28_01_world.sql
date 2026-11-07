DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_evo_call_of_ysera';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(361195, 'spell_evo_call_of_ysera');

DELETE FROM `spell_proc` WHERE `SpellId` IN (373835);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(373835,0x00,224,0x00600000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x12,0x0,0,0,0,0); -- Call of Ysera
