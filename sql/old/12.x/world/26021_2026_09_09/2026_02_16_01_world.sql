DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_sudden_death','spell_warr_sudden_death_proc');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(29725,'spell_warr_sudden_death');

DELETE FROM `spell_proc` WHERE `SpellId` IN (29725,52437);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(29725,0x00,4,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0), -- Sudden Death
(52437,0x00,4,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x18,0x0,0,0,0,0); -- Sudden Death
