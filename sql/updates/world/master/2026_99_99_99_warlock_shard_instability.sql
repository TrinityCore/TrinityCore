DELETE FROM `spell_proc` WHERE `SpellId` IN (1260264);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1260264,0x00,5,0x00800001,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Shard Instability

DELETE FROM `spell_proc` WHERE `SpellId` IN (1260269);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1260269,0x00,5,0x00000000,0x00000100,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x10,0x0,0,0,0,0); -- Shard Instability

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_shard_instability';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1260264, 'spell_warl_shard_instability');
