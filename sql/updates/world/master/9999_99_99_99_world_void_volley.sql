DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_void_volley', 'spell_pri_void_volley_passive');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1242173, 'spell_pri_void_volley'),
(1240401, 'spell_pri_void_volley_passive');

DELETE FROM `spell_proc` WHERE `SpellId` IN (1240401);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1240401,0x00,6,0x00000000,0x00080000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Void Volley
