DELETE FROM `spell_proc` WHERE `SpellId` IN (344179,410681);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(344179,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0), -- Maelstrom Weapon
(410681,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x0,0x8,0x0,0,0,0,1); -- Stormweaver (PvP Talent)

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_maelstrom_weapon','spell_sha_maelstrom_weapon_proc','spell_sha_thorims_invocation','spell_sha_thorims_invocation_primer','spell_sha_thorims_invocation_trigger','spell_sha_stormweaver');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(187880,'spell_sha_maelstrom_weapon'),
(344179,'spell_sha_maelstrom_weapon_proc'),
(384444,'spell_sha_thorims_invocation'),
(188196,'spell_sha_thorims_invocation_primer'),
(188443,'spell_sha_thorims_invocation_primer'),
(452201,'spell_sha_thorims_invocation_primer'),
(115357,'spell_sha_thorims_invocation_trigger'),
(187881,'spell_sha_stormweaver');
