DELETE FROM `spell_proc` WHERE `SpellId` IN (302385,304086);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(302385,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x4,0x2,0x0,0x0,0x0,0,0,0,0), -- Resurrect Health
(304086,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x7,0x2,0x0,0x0,0x0,0,0,0,0); -- Conflict (Azerite Essence)

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_item_conflict_wearer_on_stun_proc','spell_item_zanjir_scaleguard_greatcloak');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(302385,'spell_item_zanjir_scaleguard_greatcloak'),
(304086,'spell_item_conflict_wearer_on_stun_proc');
