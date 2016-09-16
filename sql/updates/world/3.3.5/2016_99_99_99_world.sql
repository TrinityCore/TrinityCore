DELETE FROM `spell_proc` WHERE `SpellId` IN (49222, 51209, 70844);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(49222,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Bone Shield
(51209,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Hungering Cold
(70844,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0); -- Item - Warrior T10 Protection 4P Bonus

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_hungering_cold','spell_warr_item_T10_prot_4P_bonus');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51209, 'spell_dk_hungering_cold'),
(70844, 'spell_warr_item_T10_prot_4P_bonus');
