DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_violent_transformation';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(452409, 'spell_dh_violent_transformation');

DELETE FROM `spell_proc` WHERE `SpellId` IN (452409);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(452409,0x00,107,0x10008000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Violent Transformation
