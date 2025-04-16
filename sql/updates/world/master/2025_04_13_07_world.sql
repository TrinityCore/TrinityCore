DELETE FROM `spell_script_names` WHERE `spell_id`=459533;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(459533, 'spell_hun_scrappy');

DELETE FROM `spell_proc` WHERE `SpellId` IN (459533);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(459533,0x00,9,0x04020000,0x00000800,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Scrappy
