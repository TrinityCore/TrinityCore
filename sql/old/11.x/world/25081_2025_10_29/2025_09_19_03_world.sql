DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_heat_shimmer', 'spell_mage_heat_shimmer_remove', 'spell_mage_ignition_burst');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(457735, 'spell_mage_heat_shimmer'),
(2948, 'spell_mage_heat_shimmer_remove'),
(458964, 'spell_mage_ignition_burst');

DELETE FROM `spell_proc` WHERE `SpellId` IN (457735);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(457735,0x00,3,0x08000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Heat Shimmer
