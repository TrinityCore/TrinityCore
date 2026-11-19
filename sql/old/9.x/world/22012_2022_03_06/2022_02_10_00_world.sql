DELETE FROM `spell_proc` WHERE `SpellId` IN (223817,223819);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(223817,0x00,10,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0), -- Divine Purpose
(223819,0x00,10,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x8,0x0,0,0,0,0); -- Divine Purpose (buff)

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_divine_purpose';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(223817,'spell_pal_divine_purpose');
