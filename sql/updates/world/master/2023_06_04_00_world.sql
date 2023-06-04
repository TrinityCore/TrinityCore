DELETE FROM `spell_proc` WHERE `SpellId` IN (390881,390885);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390881,0x00,6,0x00000040,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x3,0x0,0x0,0,0,0,0), -- Healing Chorus
(390885,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x0,0x8,0x0,0,0,0,1); -- Healing Chorus

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_circle_of_healing';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(204883,'spell_pri_circle_of_healing');
