delete from spell_target_position where id = 123811;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(123811, 1009, -2275.04, 258.741, 406.381, 4.00693);

update areatrigger_data set height = 2, heightTarget = 2 where entry = 363;

delete from areatrigger_actions where entry in (351,363,428,429,430,431);
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) VALUES 
(351, 0, 1, 0, 4096, 122706, 0, 0, 0, 0, 0, 0, 0, 'Noise Cancelling - Apply'),
(351, 1, 42, 1, 4096, 122706, 0, 0, 0, 0, 0, 0, 0, 'Noise Cancelling - Remove'),
(430, 0, 1, 0, 4096, 122706, 0, 0, 0, 0, 0, 4, 0, 'Noise Cancelling 10n - Apply'),
(430, 1, 42, 1, 4096, 122706, 0, 0, 0, 0, 0, 4, 0, 'Noise Cancelling 10n - Remove'),
(428, 0, 1, 0, 4096, 122706, 0, 0, 0, 0, 0, 3, 0, 'Noise Cancelling 10h - Apply'),
(428, 1, 42, 1, 4096, 122706, 0, 0, 0, 0, 0, 3, 0, 'Noise Cancelling 10h - Remove'),
(431, 0, 1, 0, 4096, 122706, 0, 0, 0, 0, 0, 9, 0, 'Noise Cancelling 25n - Apply'),
(431, 1, 42, 1, 4096, 122706, 0, 0, 0, 0, 0, 9, 0, 'Noise Cancelling 25n - Remove'),
(429, 0, 1, 0, 4096, 122706, 0, 0, 0, 0, 0, 7, 0, 'Noise Cancelling 25n - Apply'),
(429, 1, 42, 1, 4096, 122706, 0, 0, 0, 0, 0, 7, 0, 'Noise Cancelling 25n - Remove'),
(363, 0, 1, 0, 4096, 123812, 0, 0, 0, 0, 0, 0, 0, 'Pheromones of Zeal - Apply'),
(363, 1, 42, 1, 4096, 123812, 0, 0, 0, 0, 0, 0, 0, 'Pheromones of Zeal - Remove');

delete from spell_target_filter where spellId in (122336,124673);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(122336, 7, 2, 0, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 'Zorlok - Sonic Ring'),
(124673, 7, 2, 0, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 'Zorlok - Sonic Ring_H');

update creature_template set minlevel = 93, maxlevel = 93, faction = 14, speed_walk = 1, speed_run = 1, ScriptName = 'npc_zorlok_sonic_ring', flags_extra = 128 where entry in (62689, 62716, 62717, 62743, 62744);
