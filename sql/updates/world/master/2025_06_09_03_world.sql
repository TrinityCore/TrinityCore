DELETE FROM `spell_proc` WHERE `SpellId` IN (394329);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(394329,0x00,4,0x00000000,0x00000000,0x00000000,0x00000080,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Titanic Rage

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_titanic_rage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(394329, 'spell_warr_titanic_rage');
