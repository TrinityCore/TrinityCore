
-- Target Critical Increase Debuffs should stack, and only the higher effect apply
UPDATE spell_group_stack_rules SET stack_rule=3 WHERE group_id=1058;
