-- Shadow and Flame
UPDATE `spell_proc` SET `SpellFamilyMask1`= 0x00000040, `SpellTypeMask`= 1 WHERE `SpellId`= -17793;
-- Aftermath
UPDATE `spell_proc` SET `ProcFlags`= 0, `SpellFamilyMask1`= 0x00800000, `SpellFamilyMask0`= 0x00000020 WHERE `SpellID`= -85113;
-- Improved Soul Fire
DELETE FROM `spell_proc` WHERE `SpellId`= -18119;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Chance`) VALUES
(-18119, 5, 0, 0x00000080, 0, 0x00010000, 1, 2, 0, 100);
-- Backdraft
UPDATE `spell_proc` SET `SpellTypeMask`= 1, `SpellFamilyMask1`= 0x00800000 WHERE `SpellId`= -47258;
-- Burning Embers
DELETE FROM `spell_proc` WHERE `SpellId`= -91986;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Chance`, `AttributesMask`) VALUES
(-91986, 5, 0x00001000, 0x00000080, 0, 0, 1, 2, 0, 0, 32);
-- Empowered Imp
DELETE FROM `spell_proc` WHERE `SpellId`= 54278;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Chance`) VALUES
(54278, 5, 0x00001000, 0, 0, 0, 1, 2, 0, 0);
-- Empowered Imp Proc
DELETE FROM `spell_proc` WHERE `SpellId`= 47283;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Chance`, `Charges`) VALUES
(47283, 5, 0, 0x00000080, 0, 0x00010000, 1, 1, 0, 100, 1);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_warl_incinerate',
'spell_warl_shadowburn',
'spell_warl_burning_embers',
'spell_warl_chaos_bolt');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(29722, 'spell_warl_incinerate'),
(29341, 'spell_warl_shadowburn'),
(-91986, 'spell_warl_burning_embers'),
(50796, 'spell_warl_chaos_bolt');

DELETE FROM `spell_pet_auras` WHERE `spell` IN (85112, 91986, 47220, 47221);
INSERT INTO `spell_pet_auras` (`spell`, `effectId`, `pet`, `aura`) VALUES
(85112, 0, 416, 85112),
(91986, 0, 416, 91986),
(47220, 0, 416, 47220),
(47221, 0, 416, 47221);
