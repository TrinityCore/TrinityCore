-- Blessing of Sanctuary + Grace
DELETE FROM `spell_group` WHERE `id`>=1091 AND `id`<=1093  LIMIT 4;
DELETE FROM `spell_group_stack_rules` WHERE `group_id`=1093 LIMIT 1;

-- Ebon Plague + Curse of Elements + Earth and Moon
DELETE FROM `spell_group` WHERE `id`>=1040 AND `id`<=1043  LIMIT 6;
DELETE FROM `spell_group_stack_rules` WHERE `group_id`=1043 LIMIT 1;
