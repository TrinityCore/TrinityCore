DELETE FROM `spell_proc` WHERE `SpellId` IN (390881);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390881,0x00,6,0x00000000,0x00000000,0x00400000,0x00000000,0x0,0x0,0x2,0x2,0x403,0x0,0x0,0,0,0,0); -- Healing Chorus

DELETE FROM `spell_script_names` WHERE `spell_id`=204883;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(204883, 'spell_pri_circle_of_healing');
