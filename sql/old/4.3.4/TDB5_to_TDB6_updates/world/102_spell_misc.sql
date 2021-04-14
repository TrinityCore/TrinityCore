DELETE FROM `spell_group` WHERE `id`=1038;
DELETE FROM `spell_group_stack_rules` WHERE `group_id` IN (1120,1038);
DELETE FROM `spell_bonus_data` WHERE `entry`=61840;
DELETE FROM `spell_ranks` WHERE `first_spell_id`=58179 AND `spell_id`=58181;
