DELETE FROM `spell_proc` WHERE `SpellId` IN (1259886);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1259886,0x00,5,0x00000000,0x00000110,0x00000000,0x00000000,0x0,0x0,0x4,0x1,0x0,0x0,0x0,0,0,0,0); -- Cull the Weak

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_cull_the_weak';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1259886, 'spell_warl_cull_the_weak');
