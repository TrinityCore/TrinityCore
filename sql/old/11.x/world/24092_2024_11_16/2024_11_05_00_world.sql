SET @SPELL_GROUP := 1500;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_rog_poisoned_knife';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(185565, 'spell_rog_poisoned_knife');

-- Non-lethal poisons
DELETE FROM `spell_group` WHERE `id`= @SPELL_GROUP;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(@SPELL_GROUP, 5761),
(@SPELL_GROUP, 381637),
(@SPELL_GROUP, 3408);

-- Lethal poisons
DELETE FROM `spell_group` WHERE `id`= @SPELL_GROUP+1;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(@SPELL_GROUP+1, 315584),
(@SPELL_GROUP+1, 8679),
(@SPELL_GROUP+1, 2823),
(@SPELL_GROUP+1, 381664);

DELETE FROM `spell_group_stack_rules` WHERE `group_id` IN (@SPELL_GROUP, @SPELL_GROUP+1);
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(@SPELL_GROUP, 1),
(@SPELL_GROUP+1, 1);
