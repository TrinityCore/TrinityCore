DELETE FROM `spell_proc` WHERE `SpellId`= 48108;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Chance`, `Cooldown`, `Charges`) VALUES
(48108, 0, 3, 0x00400000, 0, 0, 0x00010000, 1, 1, 0, 0, 100, 0, 1);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_mage_pyroblast';
DELETE FROM `spell_bonus_data` WHERE `entry`= 92315;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(92315, 1.545, 0.18, 0, 0, 'Mage - Pyroblast!');
