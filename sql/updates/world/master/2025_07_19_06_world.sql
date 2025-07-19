DELETE FROM `spell_proc` WHERE `SpellId` IN (392536, 280776);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392536,0x01,4,0x00000000,0x00000000,0x00000000,0x00100000,0x0,0x0,0x1,0x2,0x577,0x10,0x0,0,0,0,0), -- Ashen Juggernaut
(280776,0x01,4,0x00000000,0x00000000,0x00000000,0x00100000,0x0,0x0,0x1,0x2,0x577,0x10,0x0,0,0,0,1); -- Sudden Death

DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_warr_ashen_juggernaut', 'spell_warr_sudden_death', 'spell_warr_sudden_death_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(392536, 'spell_warr_ashen_juggernaut'),
(280776, 'spell_warr_sudden_death'),
(280721, 'spell_warr_sudden_death_proc');
