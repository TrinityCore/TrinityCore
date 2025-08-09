DELETE FROM `spell_proc` WHERE `SpellId` IN (359618);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(359618,0x00,224,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x4,0x1,0x0,0x18,0x0,0,0,0,0); -- Essence Burst

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_evo_ruby_essence_burst', 'spell_evo_azure_essence_burst');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(362969, 'spell_evo_azure_essence_burst'),
(361469, 'spell_evo_ruby_essence_burst');
