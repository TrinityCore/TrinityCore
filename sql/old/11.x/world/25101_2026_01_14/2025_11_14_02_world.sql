DELETE FROM `spell_proc` WHERE `SpellId` IN (206478);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(206478,0x00,107,0x00000040,0x00000000,0x00000000,0x80000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Demonic Appetite

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_demonic_appetite_energize','spell_dh_demonic_appetite_energize');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(206478,'spell_dh_demonic_appetite'),
(178963,'spell_dh_demonic_appetite_energize'),
(202644,'spell_dh_demonic_appetite_energize'),
(228532,'spell_dh_demonic_appetite_energize'),
(328953,'spell_dh_demonic_appetite_energize'),
(1238743,'spell_dh_demonic_appetite_energize');
