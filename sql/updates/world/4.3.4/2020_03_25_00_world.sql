DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dk_killing_machine',
'spell_dru_astral_alignment',
'spell_dru_harmony_triggered',
'spell_dru_item_t11_feral_4p_bonus',
'spell_pri_chakra_flow_removal');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51124, 'spell_dk_killing_machine'),
(90164, 'spell_dru_astral_alignment'),
(100977, 'spell_dru_harmony_triggered'),
(90165, 'spell_dru_item_t11_feral_4p_bonus'),
(81208, 'spell_pri_chakra_flow_removal'),
(81209, 'spell_pri_chakra_flow_removal');

DELETE FROM `spell_proc` WHERE `SpellId`= 90164;
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Charges`) VALUES
(90164, 3, 2, 2, 3);

DELETE FROM `spell_proc` WHERE `SpellId`= 90158;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(90158, 0, 7, 0x00000020 | 0x00000040 , 0x02000000 | 0x00000002, 0x0, 0x00004000, 2, 1, 0, 0, 0, 0,  0, 0);

DELETE FROM `spell_proc` WHERE `SpellId`= 90165;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(90165, 0, 7, 0 ,0x400, 0, 0, 1, 2, 0, 0, 0, 100, 0, 0);

DELETE FROM `spell_proc` WHERE `SpellId`= 90313;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(90313, 2, 10, 0x200000 ,0, 0, 0, 3, 2, 0, 2, 0, 0, 0, 0);

DELETE FROM `spell_proc` WHERE `SpellId`= 90499;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(90499, 8, 11, 0, 0, 0x10, 0, 2, 2, 0, 0, 0, 0, 0, 0);

DELETE FROM `spell_proc` WHERE `SpellId`= 90472;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(90472, 0, 8, 0, 0, 0, 0, 1, 1, 0, 8, 0, 0, 0, 0);

DELETE FROM `spell_proc` WHERE `SpellId` IN (89935, 89937);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(89935, 0, 5, 0x4, 0x100, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0),
(89937, 0, 5, 0, 0, 0, 0, 1, 1, 0, 8, 0, 0, 0, 0);
