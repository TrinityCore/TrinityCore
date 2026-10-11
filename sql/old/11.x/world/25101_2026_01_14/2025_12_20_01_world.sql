DELETE FROM `spell_proc` WHERE `SpellId` IN (1215265);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1215265,0x00,6,0x00001800,0x00000000,0x00008000,0x00000000,0x0,0x0,0x2,0x2,0x0,0x0,0x0,0,0,0,0); -- Dispersing Light

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_dispersing_light', 'spell_pri_dispersing_light_heal');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1215265, 'spell_pri_dispersing_light'),
(1215266, 'spell_pri_dispersing_light_heal');
