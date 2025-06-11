DELETE FROM `spell_proc` WHERE `SpellId` IN (392536, 280776);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392536,0x00,4,0x00000000,0x00000000,0x00004000,0x00000000,0x0,0x0,0x0,0x4,0x0,0x0,0x0,0,0,0,0), -- Ashen Juggernaut
(280776,0x00,4,0x00000000,0x00000000,0x00004000,0x00000000,0x0,0x0,0x0,0x4,0x0,0x10,0x0,0,0,0,1); -- Sudden Death

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_sudden_death_proc';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(280721, 'spell_warr_sudden_death_proc');
