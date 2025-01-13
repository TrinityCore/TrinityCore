DELETE FROM `spell_proc` WHERE `SpellId` IN (382289);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(382289,0x00,3,0x00010000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Tempest Barrier

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_tempest_barrier';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(382289, 'spell_mage_tempest_barrier');
