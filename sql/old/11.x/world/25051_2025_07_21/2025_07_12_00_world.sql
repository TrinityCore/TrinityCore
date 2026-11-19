SET @GROUP_ID := 1502; 

DELETE FROM  `spell_group_stack_rules` WHERE `group_id`= @GROUP_ID;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(@GROUP_ID, 1);

DELETE FROM `spell_group` WHERE `id` = @GROUP_ID;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(@GROUP_ID, 386208), -- Defensive Stance
(@GROUP_ID, 386196), -- Berserker Stance 
(@GROUP_ID, 386164); -- Battle Stance
