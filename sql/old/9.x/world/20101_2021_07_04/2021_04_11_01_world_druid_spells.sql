-- Spell Proc
DELETE FROM `spell_proc` WHERE `SpellId` IN (135286);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(135286, 0, 7, 0x800, 0x0, 0x0, 0x0, 0x10, 1, 2, 0x403, 0x10, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_cat_form');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (768, 'spell_dru_cat_form');
