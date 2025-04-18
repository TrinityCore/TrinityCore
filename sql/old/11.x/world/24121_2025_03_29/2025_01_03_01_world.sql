DELETE FROM `spell_proc` WHERE `SpellId` IN (422054);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(422054,0x00,5,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,20,0,0); -- Shadow Invocation

DELETE FROM `spell_script_names` WHERE `spell_id` = 422054;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(422054, 'spell_warl_shadow_invocation');
