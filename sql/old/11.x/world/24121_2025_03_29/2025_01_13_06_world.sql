DELETE FROM `spell_script_names` WHERE `ScriptName`IN ('spell_evo_snapfire', 'spell_evo_snapfire_bonus_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(368847, 'spell_evo_snapfire'),
(369374, 'spell_evo_snapfire_bonus_damage');

DELETE FROM `spell_proc` WHERE `SpellId` IN (370783,370818);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(370783,0x00,224,0x00000020,0x00040000,0x00000000,0x00000000,0x00000000,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0), -- Snapfire
(370818,0x00,224,0x00000000,0x00000000,0x00000000,0x00000000,0x20000000,0x0,0x0,0x0,0x0,0x8,0x0,0,100,0,1); -- Snapfire
