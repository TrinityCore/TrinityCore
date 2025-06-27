-- Heroism/Bloodlust should not stack with Power Infusion
DELETE FROM `spell_group` WHERE `id`=1122;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(1122,32182),
(1122,2825),
(1122,10060),
(1122,12472);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=1122;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1122,4);
