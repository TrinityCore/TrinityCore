DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_unbridled_ferocity';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(389603, 'spell_warr_unbridled_ferocity');

DELETE FROM `spell_proc` WHERE `SpellId` IN (389603);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(389603,0x00,4,0x00000000,0x00000000,0x00000000,0x08000000,0x0,0x0,0x0,0x2,0x403,0x0,0x0,0,0,0,0); -- Unbridled Ferocity
