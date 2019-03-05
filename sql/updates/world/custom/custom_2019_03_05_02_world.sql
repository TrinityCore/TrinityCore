DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_feludius_fire_proc_check',
'spell_ignacious_inferno_rush');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(82860, 'spell_ignacious_inferno_rush'),
(92523, 'spell_ignacious_inferno_rush'),
(92524, 'spell_ignacious_inferno_rush'),
(92525, 'spell_ignacious_inferno_rush');

DELETE FROM `spell_proc` WHERE `SpellId` IN (82762, 82772, 92503, 92504, 92505);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(82762, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
(82772, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
(92503, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
(92504, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
(92505, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0);
