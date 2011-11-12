UPDATE `spell_group` SET `spell_id`=63944 WHERE `spell_id`=47930 LIMIT 1; -- Removes Grace and adds Renewed Hope
UPDATE `spell_group` SET `spell_id`=-1007 WHERE `id`=1092 AND `spell_id`=20911 LIMIT 1; -- Adds Greater Blessing of Sanctuary
UPDATE `spell_group_stack_rules` SET `stack_rule`=3 WHERE `group_id`=1093 LIMIT 1;