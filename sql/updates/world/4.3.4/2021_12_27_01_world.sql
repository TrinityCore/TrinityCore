DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hun_serpent_spread', 'spell_hun_serpent_sting');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-87934, 'spell_hun_serpent_spread'),
(1978, 'spell_hun_serpent_sting'),
(88466, 'spell_hun_serpent_sting'),
(88453, 'spell_hun_serpent_sting');

DELETE FROM `spell_proc` WHERE `SpellId`= -87934;
INSERT INTO `spell_proc` (`SpellId`,`SpellFamilyName`, `SpellFamilyMask0`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(-87934, 9, 0x1000, 1, 2);

DELETE FROM `spell_bonus_data` WHERE `entry` IN (88453, 88466);
INSERT INTO `spell_bonus_data` (`entry`, `ap_dot_bonus`, `comments`) VALUES
(88453, 0.08, 'Hunter - Serpent Sting'),
(88466, 0.08, 'Hunter - Serpent Sting');

DELETE FROM `spell_group` WHERE `id`= 1150;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1150, 88453),
(1150, 88466),
(1150, 1978);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`= 1150;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1150, 2);
