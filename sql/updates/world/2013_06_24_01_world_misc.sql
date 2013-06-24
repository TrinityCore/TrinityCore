-- Add Missing Gossip Menu for Lord Victor Nefarius
UPDATE `creature_template` SET `gossip_menu_id`=21330 WHERE `entry`=10162;

-- Add Missing Gossip Menu items for Lord Victor Nefarius
DELETE FROM `gossip_menu` WHERE `entry`=21330 AND `text_id`=7134;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (21330,7134);
DELETE FROM `gossip_menu` WHERE `entry`=21331 AND `text_id`=7198;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (21331,7198);
DELETE FROM `gossip_menu` WHERE `entry`=21332 AND `text_id`=7199;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (21332,7199);

-- Add Missing Gossip Menu options for Lord Victor Nefarius
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (21330,21331,21332);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(21330,0,0, 'I''ve made no mistakes.',1,1,21331,0,0,0, ''),
(21331,0,0, 'You have lost your mind, Nefarius. You speak in riddles.',1,1,21332,0,0,0, ''),
(21332,0,0, 'Please do.',1,1,0,0,0,0, '');

-- Add Missing Gossip Menu for Vaelastrasz the Corrupt
UPDATE `creature_template` SET `gossip_menu_id`=21333 WHERE `entry`=13020;

-- Add Missing Gossip Menu items for Vaelastrasz the Corrupt
DELETE FROM `gossip_menu` WHERE `entry`=21333 AND `text_id`=7156;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (21333,7156);
DELETE FROM `gossip_menu` WHERE `entry`=21334 AND `text_id`=7256;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (21334,7256);

-- Add Missing Gossip Menu options for Vaelastrasz the Corrupt
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (21333,21334);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(21333,0,0, 'I cannot Vaelastraz! Surely something can be done to heal you!',1,1,21334,0,0,0, ''),
(21334,0,0, 'Vaelastraz, no!!',1,1,21332,0,0,0, '');

-- Add missing text for Nefarian
SET @NEFARIAN := 11583;
DELETE FROM `creature_text` WHERE `entry`=@NEFARIAN AND `groupid`=13;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NEFARIAN,13,0,"'Death Knights, get over here!'",14,0,100,0,0,0,'nefarian SAY_DEATH_KNIGHT');

-- wrong creature spawn
DELETE FROM creature WHERE guid IN (84511, 84510, 84509, 84505, 84444, 84404, 84393);
DELETE FROM creature WHERE guid IN (84496, 84489, 84487, 84439, 84437, 84405, 84403);
DELETE FROM creature WHERE guid IN (84503, 84494, 84493, 84392);
DELETE FROM creature WHERE guid IN (84486, 84484, 84436);
DELETE FROM creature WHERE guid IN (84495, 84432, 84406);

UPDATE creature_template SET spell2=19873, spell3=19872, spell4=0 WHERE entry=12435;
UPDATE gameobject_template SET ScriptName='go_orb_of_domination' WHERE entry=177808;

DELETE FROM spell_script_names WHERE spell_id=19873;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(19873, 'spell_egg_event');

DELETE FROM spell_linked_spell WHERE spell_trigger=42013 AND spell_effect=45537;
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, comment) VALUES
(42013, 45537, 'Visual Channel');

-- nefarian
REPLACE INTO spell_target_position (id, target_map, target_position_x, target_position_y, target_position_z, target_orientation) VALUES
(22981, 469, -7536.73, -1280.18, 476.799, 2.11467),
(22982, 469, -7503.34, -1163.17, 476.797, 2.57019),
(22983, 469, -7482.73, -1196.49, 476.799, 2.31887),
(22984, 469, -7462.38, -1224.99, 476.786, 2.37385),
(22978, 469, -7534.08, -1198.57, 476.799, 2.23641),
(22979, 469, -7514.02, -1224.35, 476.8, 2.21677),
(22980, 469, -7496.05, -1248.45, 476.799, 2.09111),
(22972, 469, -7516.38, -1263.78, 476.773, 2.18536),
(22975, 469, -7582.36, -1213.9, 476.799, 2.17357),
(22976, 469, -7564.18, -1240.31, 476.799, 2.17357),
(22977, 469, -7550.29, -1260.5, 476.799, 2.17357);

UPDATE creature_template SET InhabitType=7 WHERE entry=11583;

-- Add missing go spawns

-- doors
SET @OGUID = 7226; -- 7230
DELETE FROM gameobject WHERE guid BETWEEN @OGUID AND @OGUID+4;
INSERT INTO gameobject (guid, id, map, position_x, position_y, position_z, orientation, rotation2, rotation3, spawntimesecs, state) VALUES
(@OGUID , 181125, 469, -7488.35, -1150.67, 476.534, 0.674574, 0.330928, 0.943656, 300, 1),
(@OGUID+1, 185483, 469, -7455.08, -1051.84, 476.556, 2.17155, 0.884665, 0.466227, 300, 1),
(@OGUID+2, 180424, 469, -7565.34, -1029.19, 449.142, 3.75568, 0.953231, -0.302244, 300, 1),
(@OGUID+3, 175185, 469, -7520.27, -972.05, 423.429, 5.32599, 0.460536, -0.887641, 300, 1),
(@OGUID+4, 175946, 469, -7552.26, -1022.92, 408.491, 3.75109, 0.953922, -0.300053, 300, 1);
-- SELECT * FROM gameobject where id IN(181125,185483,180424,175185,175946);

SET @OGUID := 56158;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+19;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 179121, 469, 1, 1, -7683.71, -1052.777, 440.6431, 3.752462, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+1, 179122, 469, 1, 1, -7691.453, -1040.233, 440.6851, 3.752462, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+2, 153723, 469, 1, 1, -7752.402, -1155.65, 396.6956, 3.33359, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1), 
(@OGUID+3, 179148, 469, 1, 1, -7510.984, -1094.69, 476.5545, 5.340709, 0, 0, 0, 1, 7200, 255, 1),
(@OGUID+4, 149045, 469, 1, 1, -6904.809, -1206.778, 178.5116, 2.984498, 0, 0, 1, -4.371139E-08, 7200, 255, 24),
(@OGUID+5, 149046, 469, 1, 1, -6900.417, -1339.326, 239.6519, 3.394674, 0, 0, 1, -4.371139E-08, 7200, 255, 24),
(@OGUID+6, 161536, 469, 1, 1, -6756.733, -1166.698, 187.0418, 1.317723, 0, 0, 0.9969173, -0.07845917, 7200, 255, 1),
(@OGUID+7, 179113, 469, 1, 1, -7629.542, -1017.326, 413.3823, 6.06502, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+8, 179112, 469, 1, 1, -7628.558, -1012.672, 413.3823, 5.750863, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+9, 179114, 469, 1, 1, -7627.558, -1009.027, 413.3823, 5.366888, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+10, 179111, 469, 1, 1, -7623.486, -1009.636, 413.3823, 4.89565, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+11, 179110, 469, 1, 1, -7618.736, -1009.88, 413.3823, 4.651303, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+12, 180632, 469, 1, 1, -7554.886, -1039.864, 449.2131, 2.967041, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+13, 180631, 469, 1, 1, -7545.932, -978.4827, 449.2131, 2.967041, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+14, 179106, 469, 1, 1, -7468.113, -1047.162, 411.971, 0.6108655, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+15, 179105, 469, 1, 1, -7466.616, -1042.562, 411.9711, 2.18166, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+16, 179104, 469, 1, 1, -7464.983, -1041.419, 411.9711, 2.18166, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+17, 179108, 469, 1, 1, -7464.785, -1048.651, 411.971, 2.18166, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+18, 179107, 469, 1, 1, -7459.672, -1041.251, 411.971, 3.752462, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1),
(@OGUID+19, 179109, 469, 1, 1, -7459.427, -1044.899, 411.971, 2.18166, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1);

-- eggs for razorgore
SET @OGUID := 74165; -- 74181
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+29;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 177807, 469, 1, 1, -7549.479, -1069.964, 408.4904, 5.759587, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+1, 177807, 469, 1, 1, -7554.418, -1061.5, 408.4904, 3.996807, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+2, 177807, 469, 1, 1, -7563.152, -1088.705, 413.3812, 5.829401, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+3, 177807, 469, 1, 1, -7564.887, -1058.87, 408.4904, 2.286379, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+4, 177807, 469, 1, 1, -7566.002, -1045.929, 408.4904, 3.054327, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+5, 177807, 469, 1, 1, -7568.273, -1097.68, 413.3809, 2.792518, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+6, 177807, 469, 1, 1, -7568.621, -1086.578, 413.3812, 0.8552105, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+7, 177807, 469, 1, 1, -7569.38, -1079.727, 413.3812, 3.595379, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+8, 177807, 469, 1, 1, -7572.491, -1095.034, 413.3812, 3.42085, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+9, 177807, 469, 1, 1, -7576.924, -1083.691, 413.3812, 3.38594, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+10, 177807, 469, 1, 1, -7577.844, -1035.97, 408.4904, 5.166176, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+11, 177807, 469, 1, 1, -7578.64, -1089.948, 413.3812, 2.216565, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+12, 177807, 469, 1, 1, -7579.486, -1051.485, 408.1571, 0.523598, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+13, 177807, 469, 1, 1, -7580.799, -1067.292, 408.4904, 3.298687, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+14, 177807, 469, 1, 1, -7584.68, -1075.842, 408.4904, 3.019413, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+15, 177807, 469, 1, 1, -7586.365, -1024.429, 408.4904, 3.351047, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+16, 177807, 469, 1, 1, -7588.843, -1053.786, 408.1571, 4.555311, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+17, 177807, 469, 1, 1, -7592.354, -1010.842, 408.4904, 3.735006, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+18, 177807, 469, 1, 1, -7592.379, -1035.677, 408.1571, 1.623156, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+19, 177807, 469, 1, 1, -7594.374, -1102.896, 408.4904, 5.375615, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+20, 177807, 469, 1, 1, -7597.528, -1094.538, 408.4904, 2.373644, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+21, 177807, 469, 1, 1, -7598.997, -1044.769, 408.1571, 5.253442, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+22, 177807, 469, 1, 1, -7601.142, -1077.111, 408.2178, 5.009095, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+23, 177807, 469, 1, 1, -7604.356, -1060.245, 408.1571, 3.508117, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+24, 177807, 469, 1, 1, -7609.944, -1035.106, 408.4904, 4.34587, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+25, 177807, 469, 1, 1, -7611.604, -1020.322, 413.3812, 3.089183, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+26, 177807, 469, 1, 1, -7618.098, -1069.328, 408.4904, 4.956738, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+27, 177807, 469, 1, 1, -7619.756, -1058.941, 408.4904, 1.815142, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+28, 177807, 469, 1, 1, -7626.688, -1011.714, 413.3809, 0.2268925, 0, 0, 0, 1, 7200, 255, 1), -- Black Dragon Egg (Area: 0)
(@OGUID+29, 177807, 469, 1, 1, -7628.317, -1044.573, 408.4904, 6.108654, 0, 0, 0, 1, 7200, 255, 1); -- Black Dragon Egg (Area: 0)
-- SELECT * FROM gameobject where id IN(177807);

SET @OGUID := 75120; -- 75157
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+45;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 179784, 469, 1, 1, -7572.59, -1062.572, 449.1642, 0.5410506, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+1, 179784, 469, 1, 1, -7593.775, -1063.449, 449.1642, 0.4712385, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+2, 179784, 469, 1, 1, -7595.269, -1030.421, 449.1642, 0.3141584, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+3, 179784, 469, 1, 1, -7595.774, -1080.002, 449.1642, 0.5585039, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+4, 179784, 469, 1, 1, -7605.952, -1045.063, 449.1642, 0.6457717, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+5, 179784, 469, 1, 1, -7609.894, -1061.456, 449.1642, 0.4188786, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+6, 179784, 469, 1, 1, -7616.209, -997.0844, 440.2823, 0.2094394, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+7, 179784, 469, 1, 1, -7619.151, -1047.152, 449.1642, 0.5061446, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+8, 179784, 469, 1, 1, -7620.089, -1075.735, 449.1642, 0.4712385, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+9, 179784, 469, 1, 1, -7626.954, -981.3593, 440.0226, 0.157079, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+10, 179784, 469, 1, 1, -7627.983, -1095.305, 449.1642, 0.5410506, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+11, 179784, 469, 1, 1, -7629.779, -1061.484, 449.1642, 0.6283169, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+12, 179784, 469, 1, 1, -7630.286, -1005.49, 440.2624, 0.4014249, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+13, 179784, 469, 1, 1, -7637.638, -965.0227, 440.2754, 0.01745246, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+14, 179784, 469, 1, 1, -7637.933, -1081.127, 449.1642, 0.453785, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+15, 179784, 469, 1, 1, -7640.291, -991.3019, 440.2628, 0.453785, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+16, 179784, 469, 1, 1, -7642.733, -1015.651, 440.2449, 0.4712385, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+17, 179784, 469, 1, 1, -7647.777, -1066.966, 449.1642, 0.5585039, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+18, 179784, 469, 1, 1, -7650.901, -975.7917, 440.2633, 0.2268925, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+19, 179784, 469, 1, 1, -7651.322, -1103.534, 449.1642, 0.523598, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+20, 179784, 469, 1, 1, -7653.694, -999.9188, 439.9861, 0.5061446, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+21, 179784, 469, 1, 1, -7656.672, -1024.323, 440.2567, 0.5061446, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+22, 179784, 469, 1, 1, -7663.989, -1084.885, 449.1642, 0.6283169, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+23, 179784, 469, 1, 1, -7664.824, -984.0574, 440.2471, 0.3141584, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+24, 179784, 469, 1, 1, -7665.261, -1113.61, 449.1642, 0.523598, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+25, 179784, 469, 1, 1, -7667.542, -1008.341, 440.2592, 0.523598, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+26, 179784, 469, 1, 1, -7669.463, -1034.205, 440.244, 0.5410506, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+27, 179784, 469, 1, 1, -7677.631, -994.4258, 440.2595, 0.383971, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+28, 179784, 469, 1, 1, -7677.684, -1095.238, 449.1351, 0.6283169, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+29, 179784, 469, 1, 1, -7680.108, -1123.294, 449.1051, 0.523598, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+30, 179784, 469, 1, 1, -7680.508, -1018.701, 439.9826, 0.5585039, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+31, 179784, 469, 1, 1, -7686.851, -1047.039, 440.3709, 0.5585039, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+32, 179784, 469, 1, 1, -7691.257, -1002.378, 440.2438, 0.4188786, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+33, 179784, 469, 1, 1, -7691.966, -1105.405, 449.13, 0.6283169, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+34, 179784, 469, 1, 1, -7699.204, -1030.978, 440.5882, 0.5585039, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+35, 179784, 469, 1, 1, -7709.169, -1017.005, 440.4458, 0.4712385, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+36, 179784, 469, 1, 1, -7713.143, -1060.038, 445.1762, 5.096362, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+37, 179784, 469, 1, 1, -7716.096, -1077.452, 445.1762, 0.8726639, 0, 0, 0, 1, 7200, 255, 1), -- Suppression Device (Area: 0)
(@OGUID+38, 176964, 469, 1, 1, -7639.43, -1083.943, 408.5284, 3.752462, 0, 0, 0.9537169, -0.3007059, 7200, 255, 0), -- Portcullis (Area: 0)
(@OGUID+39, 179365, 469, 1, 1, -7568.426, -1031.59, 449.1086, 3.752462, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1), -- Portcullis (Area: 0)
(@OGUID+40, 176965, 469, 1, 1, -7552.37, -1022.984, 408.5284, 3.752462, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1), -- Portcullis (Area: 0)
(@OGUID+41, 179116, 469, 1, 1, -7506.288, -1043.155, 480.03, 0.6108655, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1), -- Portcullis (Area: 0)
(@OGUID+42, 176966, 469, 1, 1, -7488.173, -1150.542, 476.712, 0.6108655, 0, 0, 0.9537169, -0.3007059, 7200, 255, 0), -- Portcullis (Area: 0)
(@OGUID+43, 179364, 469, 1, 1, -7531.224, -956.4108, 428.2516, 5.323256, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1), -- Portcullis (Area: 0)
(@OGUID+44, 179117, 469, 1, 1, -7464, -1103.549, 480.03, 0.6108655, 0, 0, 0.9537169, -0.3007059, 7200, 255, 1), -- Portcullis (Area: 0)
(@OGUID+45, 179115, 469, 1, 1, -7455.243, -1051.711, 480.03, 2.18166, 0, 0, 0.9537169, -0.3007059, 7200, 255, 0); -- Portcullis (Area: 0)
