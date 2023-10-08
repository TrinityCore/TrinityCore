DELETE FROM `spell_proc` WHERE `SpellId` IN (384041);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(384041,0x00,4,0x00000480,0x00000040,0x00000000,0x00100000,0x1010,0x0,0x1,0x4,0x403,0x0,0x0,0,100,0,0); -- Strategist

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_strategist';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(384041,'spell_warr_strategist');
