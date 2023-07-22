DELETE FROM `spell_proc` WHERE `SpellId` IN (414553);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(414553,0x00,6,0x10200400,0x00000000,0x00000020,0x00000000,0x0,0x0,0x3,0x2,0x403,0x0,0x0,0,0,0,0); -- Epiphany

DELETE FROM `spell_script_names` WHERE `spell_id`=414553;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(414553, 'spell_pri_epiphany'); -- Epiphany
