DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_mastery_elemental_overload';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_mastery_elemental_overload_proc';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_unlimited_power';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(168534, 'spell_sha_mastery_elemental_overload'), -- Mastery: Elemental Overload
(45284, 'spell_sha_mastery_elemental_overload_proc'), -- Lightning Bolt Overload
(45297, 'spell_sha_mastery_elemental_overload_proc'), -- Chain Lightning Overload
(114738, 'spell_sha_mastery_elemental_overload_proc'), -- Lava Beam Overload
(120588, 'spell_sha_mastery_elemental_overload_proc'), -- Elemental Blast Overload
(219271, 'spell_sha_mastery_elemental_overload_proc'), -- Icefury Overload
(285466, 'spell_sha_mastery_elemental_overload_proc'),-- Lava Burst Overload
(260895, 'spell_sha_unlimited_power');-- Lava Burst Overload

DELETE FROM `spell_proc` WHERE `SpellId` IN (168534,260895);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(168534,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x10000,0x5,0x2,0x0,0x0,0x6,0,100,0,0), -- Mastery: Elemental Overload
(260895,0x00,11,0x00000000,0x00000000,0x00008000,0x00000000,0x00000,0x1,0x1,0x0,0x2,0x0,0,  0,0,0); -- Unlimited Power
