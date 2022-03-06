DELETE FROM `spell_proc` WHERE `SpellId` IN (231843);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(231843,0x00,10,0x00000000,0x00000000,0x00000000,0x40000000,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Art of War

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_art_of_war';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(267344,'spell_pal_art_of_war');
