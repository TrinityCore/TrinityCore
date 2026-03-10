DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_demon_muzzle';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(388111, 'spell_dh_demon_muzzle');

DELETE FROM `spell_proc` WHERE `SpellId` IN (388111);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(388111,0x00,107,0x00000000,0x00000002,0x00000000,0x00000000,0x11010,0x0,0x0,0x2,0x0,0x2,0x0,0,100,0,0); -- Demon Muzzle
