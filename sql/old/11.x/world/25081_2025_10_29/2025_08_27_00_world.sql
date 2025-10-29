DELETE FROM `spell_proc` WHERE `SpellId` IN (393760, 393763);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(393760,0x00,7,0x00000005,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,20,0,0), -- Umbral Embrace
(393763,0x00,7,0x00000005,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x10,0x0,0,0,0,0); -- Umbral Embrace

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_umbral_embrace','spell_dru_umbral_inspiration','spell_dru_umbral_embrace_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(393763, 'spell_dru_umbral_embrace'),
(393763, 'spell_dru_umbral_inspiration'),
(194153, 'spell_dru_umbral_embrace_damage'),
(190984, 'spell_dru_umbral_embrace_damage');
