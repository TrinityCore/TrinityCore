-- shaman Mastery: Elemental Overload aura script
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_mastery_elemental_overload';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(168534, 'spell_sha_mastery_elemental_overload'); -- Mastery: Elemental Overload

-- shaman Mastery: Elemental Overload spell proc
DELETE FROM `spell_proc` WHERE `SpellId` IN (168534); -- Mastery: Elemental Overload
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(168534, 28, 11, 0x0, 0x0, 0x0, 0x0, 65536, 1, 2, 0x0, 0x2, 0, 0, 100, 0, 0);
