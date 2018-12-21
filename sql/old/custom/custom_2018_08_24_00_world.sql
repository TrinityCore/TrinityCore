DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_pri_evangelism',
'spell_pri_evangelism_triggered',
'spell_pri_archangel');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-81659, 'spell_pri_evangelism'),
(81660, 'spell_pri_evangelism_triggered'),
(81661, 'spell_pri_evangelism_triggered'),
(87117, 'spell_pri_evangelism_triggered'),
(87118, 'spell_pri_evangelism_triggered'),
(87151, 'spell_pri_archangel');

DELETE FROM `spell_proc` WHERE `SpellId`= -81659;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-81659, 6, 0x00000080 | 0x00100000, 0, 0x00000440, 0, 1, 1, 0, 0, 0, 0, 0);

DELETE FROM `spell_group` WHERE `id`= 1124;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1124, 81660),
(1124, 81661),
(1124, 87117),
(1124, 87118);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`= 1124;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1124, 2);
