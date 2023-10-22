DELETE FROM `spell_proc` WHERE `SpellId` IN (391387);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(391387,0x00,6,0x00000000,0x00000000,0x00000000,0x00200000,0x0,0x0,0x2,0x2,0x403,0x0,0x0,0,0,0,0); -- Answered Prayers

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_answered_prayers';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(391387, 'spell_pri_answered_prayers');
