-- Unstable Affliction / Immolate stacking from same caster
DELETE FROM `spell_group_stack_rules` where `group_id`=1112;
INSERT INTO spell_group_stack_rules (group_id, stack_rule) VALUES (1112, 2);
