-- Update Revitalize Proc
UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x00000010, `SpellFamilyMask1`= 0x00000010, `SpellFamilyMask2`= 0, `ProcFlags`= 0x00040000, `SpellTypeMask`= 2, `SpellPhaseMask`= 2, `HitMask`= 0, `Cooldown`= 12000 WHERE `SpellId`= -48539;
-- Update Nature's Grace Proc
UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x00000002 | 0x00200000 | 0x00000040, `SpellFamilyMask1`= 0, `SpellFamilyMask2`= 0, `ProcFlags`= 0x00014000, `SpellTypeMask`= 1 | 2, `SpellPhaseMask`= 1, `HitMask`= 0 WHERE `SpellId`= -16880;

-- Effloresence
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dru_effloresence',
'spell_dru_effloresence_aoe',
'spell_dru_effloresence_heal',
'spell_dru_natures_grace',
'spell_dru_rejuvenation');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-34151, 'spell_dru_effloresence'),
(81262, 'spell_dru_effloresence_aoe'),
(81269, 'spell_dru_effloresence_heal'),
(774, 'spell_dru_rejuvenation');

DELETE FROM `spell_proc` WHERE `SpellId` IN (-34151);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(-34151, 7, 0, 0x00000002, 0, 0x00004000, 0x2, 0x2, 0x0, 0x0);

-- Remove Swiftment spell_bonus_data entry
DELETE FROM `spell_bonus_data` WHERE `entry`= 18562;
