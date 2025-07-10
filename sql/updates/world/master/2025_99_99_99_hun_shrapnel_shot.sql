DELETE FROM `spell_proc` WHERE `SpellId` IN (474310);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(474310,0x00,9,0x00001000,0x00000000,0x00000000,0x00000200,0x0,0x0,0x1,0x2,0x0,0x10,0x0,0,0,0,0); -- Shrapnel Shot

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_shrapnel_shot';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(212680, 'spell_hun_shrapnel_shot');
