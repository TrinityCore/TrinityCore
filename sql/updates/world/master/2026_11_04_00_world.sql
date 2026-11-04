DELETE FROM `spell_proc` WHERE `SpellId` IN (1240201);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1240201,0x00,107,0x40000000,0x00000000,0x00040000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x2,0x0,0,0,0,0); -- Devourer's Bite

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_devourers_bite';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1240201, 'spell_dh_devourers_bite');
