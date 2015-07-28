DELETE FROM `spell_target_position` WHERE `id` IN (49362, 85545, 99557, 101260, 99662, 84515, 82621, 84513, 17609);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(49362, 1, -3748.11, -4440.21, 30.5688, 3.95172), -- Portal Effect: Theramore
(85545, 0, -4890.07, -6626.74, 10.2846, 5.41085), -- Stormwind Portal to Highbank
(99557, 861, 1032.01, 317.815, 41.0351, 1.857502), -- Teleport into Firelands
(101260, 0, -9517.5, 82.3, 59.51, 2.921681), -- To the Staging Area! - Elwyn Forest
(99662, 1, 4611.91, -2095.26, 1239.01, 0.8557105), -- Teleport to Regrowth from Firelands
(84515, 646, 974.921, 566.768, -47.5163, 5.39048), -- Teleport to Deepholm - Alliance
(82621, 0, -4032.79, -6318.53, 38.6975, 4.648562), -- Orgrimmar Portal to Dragonmaw
(84513, 646, 995.808, 471.879, -48.1172, 1.30641), -- Teleport to Deepholm - Horde
(17609, 1, 1776.5, -4338.8, -7.48, 3.55349); -- Portal Effect: Orgrimmar
