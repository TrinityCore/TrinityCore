DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_eternal_sanctity';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(1215245,'spell_pri_eternal_sanctity');

DELETE FROM `spell_proc` WHERE `SpellId`=1215245;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1215245,0x00,6,0x10000400,0x00000000,0x00000020,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Eternal Sanctity
