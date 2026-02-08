DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_surge_of_adrenaline';
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(280270, 'spell_warr_surge_of_adrenaline');

DELETE FROM `spell_proc` WHERE `SpellId` IN (280270);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(280270,0x00,4,0x00000000,0x00000000,0x00000000,0x00000400,0x0,0x0,0x0,0x4,0x0,0x0,0x0,0,0,0,0); -- Always Angry
