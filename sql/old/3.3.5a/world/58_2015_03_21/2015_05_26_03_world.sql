--
DELETE FROM `spell_group` WHERE `id`=1001 AND `spell_id` IN (45694, 20875, 25804, 25722, 25037);
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES (1001, 45694), (1001, 20875), (1001, 25804), (1001, 25722), (1001, 25037);
