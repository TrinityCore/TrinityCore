DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_black_magic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(59630,'spell_gen_black_magic');

DELETE FROM `spell_proc` WHERE `SpellId`=59630;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(59630,0,0,0,0,0,69648,5,1,0,2,0,0,35000,0);
