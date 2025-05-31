DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_crimson_scourge';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(81136,'spell_dk_crimson_scourge');

DELETE FROM `spell_proc` WHERE `SpellId` IN (81141);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(81141,0x00,15,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x4,0x0,0x0,0x0,0x8,0x0,0,100,0,1); -- Crimson Scourge
