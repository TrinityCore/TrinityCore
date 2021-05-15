-- Mage Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_arcane_barrage', 'spell_mage_arcane_explosion', 'spell_mage_arcane_charge_clear');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44425, 'spell_mage_arcane_barrage'),
(195302, 'spell_mage_arcane_charge_clear'),
(1449, 'spell_mage_arcane_explosion');

DELETE FROM `spell_proc` WHERE `SpellId` IN (36032);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(36032,0,3,0x0,0x8000,0x0,0x0,0,1,1,0x2FFF,0x8,0,0,0,0,0); -- Arcane Charge, drop charges from Arcane Barrage only
