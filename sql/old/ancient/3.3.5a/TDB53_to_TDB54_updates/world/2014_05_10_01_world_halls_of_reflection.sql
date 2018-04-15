SET @CGUID := 142975; -- need 93
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+92;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
-- The Skybreaker
(@CGUID+0, 30351, 712, 3, 1, 40.85356, 44.65979, 25.11708, 2.617994, 7200, 0, 0),
(@CGUID+1, 30867, 712, 3, 1, -32.58828, 22.11204, 21.78542, 1.762783, 7200, 0, 0),
(@CGUID+2, 30867, 712, 3, 1, -11.11922, 23.02313, 21.71026, 1.727876, 7200, 0, 0),
(@CGUID+3, 30867, 712, 3, 1, 36.80393, 45.60984, 25.11626, 1.43117, 7200, 0, 0),
(@CGUID+4, 30351, 712, 3, 1, 1.432831, 22.45517, 21.75367, 3.193953, 7200, 0, 0),
(@CGUID+5, 30394, 712, 3, 1, -57.66117, -6.004808, 23.56313, 4.956735, 7200, 0, 0),
(@CGUID+6, 30351, 712, 3, 1, 1.032896, 9.635975, 20.53982, 3.211406, 7200, 0, 0),
(@CGUID+7, 30351, 712, 3, 1, -36.27486, -6.711545, 20.53283, 1.53589, 7200, 0, 0),
(@CGUID+8, 30351, 712, 3, 1, -36.26366, 6.612509, 20.5329, 4.642576, 7200, 0, 0),
(@CGUID+9, 30352, 712, 3, 1, -16.93313, 2.497342, 20.87589, 3.106686, 7200, 0, 0),
(@CGUID+10, 30352, 712, 3, 1, -49.00542, 0.003014, 20.75066, 0.01745329, 7200, 0, 0),
(@CGUID+11, 30352, 712, 3, 1, 16.73826, 2.378118, 20.50117, 3.159046, 7200, 0, 0),
(@CGUID+12, 30352, 712, 3, 1, 48.81408, 8.76864, 40.16452, 1.675516, 7200, 0, 0),
(@CGUID+13, 30352, 712, 3, 1, -16.85414, -2.518523, 20.87587, 3.263766, 7200, 0, 0),
(@CGUID+14, 30351, 712, 3, 1, 4.010166, -22.42914, 21.77942, 0.2617994, 7200, 0, 0),
(@CGUID+15, 30351, 712, 3, 1, 0.778628, -9.484917, 20.5411, 3.036873, 7200, 0, 0),
(@CGUID+16, 30867, 712, 3, 1, -9.599308, -23.15501, 21.71576, 4.782202, 7200, 0, 0),
(@CGUID+17, 30352, 712, 3, 1, 48.82674, -8.803922, 40.16443, 4.712389, 7200, 0, 0),
(@CGUID+18, 30867, 712, 3, 1, -32.99351, -22.17393, 21.7879, 4.502949, 7200, 0, 0),
(@CGUID+19, 30867, 712, 3, 1, 37.14339, -45.94594, 25.11639, 4.014257, 7200, 0, 0),
(@CGUID+20, 30344, 712, 3, 1, -2.700737, 12.2316, 20.52945, 1.727876, 7200, 0, 0),
(@CGUID+21, 22515, 712, 3, 1, -27.09398, 38.85326, 1.366914, 1.256637, 7200, 0, 0),
(@CGUID+22, 22515, 712, 3, 1, -6.396934, 39.80114, 1.470398, 1.256637, 7200, 0, 0),
(@CGUID+23, 22515, 712, 3, 1, 4.017809, 38.32001, 1.533938, 1.256637, 7200, 0, 0),
(@CGUID+24, 30392, 712, 3, 1, 28.1948, 7.542603, 23.37183, 5.8294, 7200, 0, 0),
(@CGUID+25, 30833, 712, 3, 1, 6.518055, 0.003965, 20.66434, 0, 7200, 0, 0),
(@CGUID+26, 30350, 712, 3, 1, 16.36582, -2.323581, 20.49201, 3.141593, 7200, 0, 0),
(@CGUID+27, 30347, 712, 3, 1, 28.24817, -7.667989, 23.37183, 0.4363323, 7200, 0, 0),
-- Orgrim Hammer
(@CGUID+28, 30755, 713, 3, 1, -18.96152, 27.52218, 90.04992, 6.213372, 7200, 0, 0),
(@CGUID+29, 30754, 713, 3, 1, -54.68485, 15.01545, 34.49284, 2.338741, 7200, 0, 0),
(@CGUID+30, 30752, 713, 3, 1, -10.94232, 32.12282, 10.65215, 1.518436, 7200, 0, 0),
(@CGUID+31, 30754, 713, 3, 1, -8.504885, -0.019059, 86.17371, 3.159046, 7200, 0, 0),
(@CGUID+32, 30866, 713, 3, 1, -36.03656, 23.91632, 34.00398, 1.937315, 7200, 0, 0),
(@CGUID+33, 30754, 713, 3, 1, 29.97084, 29.32993, 89.84912, 0.122173, 7200, 0, 0),
(@CGUID+34, 30753, 713, 3, 1, 15.19238, -0.108369, 86.17371, 3.071779, 7200, 0, 0),
(@CGUID+35, 30752, 713, 3, 1, 7.702429, 25.23042, 35.08076, 4.764749, 7200, 0, 0),
(@CGUID+36, 30755, 713, 3, 1, 8.555423, 5.155768, 84.79706, 3.560472, 7200, 0, 0),
(@CGUID+37, 30755, 713, 3, 1, -4.588624, 27.91955, 34.27925, 4.729842, 7200, 0, 0),
(@CGUID+38, 30754, 713, 3, 1, -19.19535, -27.024, 90.05069, 3.124139, 7200, 0, 0),
(@CGUID+39, 30754, 713, 3, 1, -54.63672, -15.29832, 34.48149, 3.717551, 7200, 0, 0),
(@CGUID+40, 30753, 713, 3, 1, -26.19901, -10.37834, 35.63048, 1.64061, 7200, 0, 0),
(@CGUID+41, 30755, 713, 3, 1, -56.79522, -3.870484, 13.31639, 0.1047198, 7200, 0, 0),
(@CGUID+42, 30755, 713, 3, 1, -56.8364, 3.557915, 13.3138, 6.178465, 7200, 0, 0),
(@CGUID+43, 30753, 713, 3, 1, -34.95441, 11.84717, 11.5961, 1.082104, 7200, 0, 0),
(@CGUID+44, 30752, 713, 3, 1, 1.994709, 31.96335, 10.09305, 1.448623, 7200, 0, 0),
(@CGUID+45, 30753, 713, 3, 1, -26.06219, 10.57757, 35.58858, 4.712389, 7200, 0, 0),
(@CGUID+46, 30752, 713, 3, 1, 15.2307, 31.76827, 10.66515, 1.466077, 7200, 0, 0),
(@CGUID+47, 30753, 713, 3, 1, 1.994774, 17.06817, 9.246212, 1.500983, 7200, 0, 0),
(@CGUID+48, 30755, 713, 3, 1, -4.484874, 18.00111, 8.70937, 4.729842, 7200, 0, 0),
(@CGUID+49, 30755, 713, 3, 1, 8.521951, 17.92888, 8.777781, 4.625123, 7200, 0, 0),
(@CGUID+50, 30755, 713, 3, 1, -26.0374, 6.533113, 9.42994, 3.124139, 7200, 0, 0),
(@CGUID+51, 30755, 713, 3, 1, -19.30323, 6.17474, 6.879124, 0, 7200, 0, 0),
(@CGUID+52, 30755, 713, 3, 1, 8.786416, -5.037911, 84.79706, 2.740167, 7200, 0, 0),
(@CGUID+53, 30755, 713, 3, 1, 8.557505, 5.72448, 34.52152, 3.106686, 7200, 0, 0),
(@CGUID+54, 30755, 713, 3, 1, 8.450569, -5.609207, 34.52058, 2.792527, 7200, 0, 0),
(@CGUID+55, 30866, 713, 3, 1, -36.32559, -23.21568, 34.04234, 4.39823, 7200, 0, 0),
(@CGUID+56, 30753, 713, 3, 1, -35.48437, -11.9256, 11.71411, 5.986479, 7200, 0, 0),
(@CGUID+57, 30752, 713, 3, 1, 8.472344, -22.36673, 34.99833, 1.780236, 7200, 0, 0),
(@CGUID+58, 30755, 713, 3, 1, -4.738312, -28.17381, 34.26831, 1.466077, 7200, 0, 0),
(@CGUID+59, 30755, 713, 3, 1, 31.3718, -29.84369, 89.84172, 2.96706, 7200, 0, 0),
(@CGUID+60, 30755, 713, 3, 1, 37.59615, -9.010085, 30.1788, 0.05235988, 7200, 0, 0),
(@CGUID+61, 30755, 713, 3, 1, 37.52684, 8.718971, 30.17881, 5.969026, 7200, 0, 0),
(@CGUID+62, 30755, 713, 3, 1, -25.42656, -6.577197, 9.33257, 2.932153, 7200, 0, 0),
(@CGUID+63, 30755, 713, 3, 1, 23.24178, 6.302864, 7.032903, 3.176499, 7200, 0, 0),
(@CGUID+64, 30755, 713, 3, 1, -19.45751, -6.235432, 6.89157, 6.265732, 7200, 0, 0),
(@CGUID+65, 30752, 713, 3, 1, -11.36508, -29.14235, 10.01249, 4.642576, 7200, 0, 0),
(@CGUID+66, 30753, 713, 3, 1, 46.41658, 7.696208, 10.48851, 4.101524, 7200, 0, 0),
(@CGUID+67, 30752, 713, 3, 1, 15.44485, -29.7788, 9.977043, 4.694936, 7200, 0, 0),
(@CGUID+68, 30754, 713, 3, 1, 38.01897, -12.83605, 30.17452, 0.6108652, 7200, 0, 0),
(@CGUID+69, 30866, 713, 3, 1, 17.22244, -26.63993, 35.64188, 4.817109, 7200, 0, 0),
(@CGUID+70, 30752, 713, 3, 1, 2.069969, -29.66959, 9.395721, 4.677482, 7200, 0, 0),
(@CGUID+71, 30753, 713, 3, 1, 2.036507, -17.18819, 9.245911, 4.764749, 7200, 0, 0),
(@CGUID+72, 30753, 713, 3, 1, 46.33955, -7.35728, 10.47599, 2.391101, 7200, 0, 0),
(@CGUID+73, 30755, 713, 3, 1, 8.592517, -17.94128, 8.77952, 1.553343, 7200, 0, 0),
(@CGUID+74, 30755, 713, 3, 1, -4.406364, -17.97099, 8.709299, 1.48353, 7200, 0, 0),
(@CGUID+75, 30755, 713, 3, 1, 22.90693, -6.745431, 7.115322, 3.124139, 7200, 0, 0),
(@CGUID+76, 30824, 713, 3, 1, 17.28272, 21.73325, 35.37741, 1.623156, 7200, 0, 0),
(@CGUID+77, 30827, 713, 3, 1, 45.76886, -8.964413, 30.17881, 1.396263, 7200, 0, 0),
(@CGUID+78, 30825, 713, 3, 1, 38.55754, -0.025193, 10.27214, 3.106686, 7200, 0, 0),
(@CGUID+79, 30826, 713, 3, 1, 55.08521, -3.344726, 30.1788, 2.687807, 7200, 0, 0),
(@CGUID+80, 37593, 713, 3, 1, 2.015905, 34.44526, 10.09305, 1.64061, 7200, 0, 0),
(@CGUID+81, 37593, 713, 3, 1, 14.85607, 33.80163, 9.849781, 1.64061, 7200, 0, 0),
(@CGUID+82, 37593, 713, 3, 1, -10.84229, 34.34502, 10.6434, 1.64061, 7200, 0, 0),
-- Others
(@CGUID+83, 22515, 668, 3, 1, 5274.933, 1693.941, 797.2499, 0, 7200, 0, 0),
(@CGUID+84, 36736, 668, 3, 1, 5415.332, 2080.358, 720.5068, 1.64061, 7200, 0, 0),
(@CGUID+85, 36736, 668, 3, 1, 5376.905, 2115.425, 720.3566, 6.126106, 7200, 0, 0),
(@CGUID+86, 36736, 668, 3, 1, 5445.525, 2099.37, 720.3999, 2.600541, 7200, 0, 0),
(@CGUID+87, 36736, 668, 3, 1, 5431.74, 2087.503, 720.3914, 2.076942, 7200, 0, 0),
(@CGUID+88, 36736, 668, 3, 1, 5395.38, 2146.632, 720.2123, 5.305801, 7200, 0, 0),
(@CGUID+89, 36736, 668, 3, 1, 5380.971, 2134.462, 720.6889, 5.637414, 7200, 0, 0),
(@CGUID+90, 36736, 668, 3, 1, 5449.623, 2117.587, 720.4929, 3.176499, 7200, 0, 0),
(@CGUID+91, 36736, 668, 3, 1, 5412.493, 2150.627, 720.3359, 4.502949, 7200, 0, 0),
(@CGUID+92, 37071, 668, 3, 1, 5408.362, 2110.33, 726.9917, 3.630285, 7200, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry`=36736; 
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(36736, 0, 0x0, 0x1, '69174'); -- Invisible Stalker (Icecrown Dungeon Trap) - Reflection Window Beam Visual

DELETE FROM `creature_text` WHERE `entry` IN (30344, 30824, 36954);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
-- High Captain Justin Bartlett
(30344, 0, 0, 'FIRE! FIRE!', 14, 0, 100, 0, 0, 16721, 'High Captain Justin Bartlett - Fire', 36993),
(30344, 1, 0, 'Quickly, climb aboard! We mustn''t tarry here! There''s no telling when this whole mountainside will collapse.', 14, 0, 100, 0, 0, 16722, 'High Captain Justin Bartlett - Final', 37213),
-- Sky-Reaver Korm Blackscar
(30824, 0, 0, 'FIRE! FIRE!', 14, 0, 100, 0, 0, 16732, 'Sky-Reaver Korm Blackscar - Fire', 38681),
(30824, 1, 0, 'Get on board, now! This whole mountainside could collapse at any moment.', 14, 0, 100, 0, 0, 16733, 'Sky-Reaver Korm Blackscar - Final', 37212),
-- Lich King
(36954, 0, 0, 'Your allies have arrived, Jaina, just as you promised. You will all become powerful agents of the Scourge..', 14, 0, 100, 0, 0, 17212, 'Lich King SAY_LICH_KING_AGGRO_A', 37172),
(36954, 1, 0, 'I will not make the same mistake again, Sylvanas. This time there will be no escape. You will all serve me in death!', 14, 0, 100, 0, 0, 17213, 'Lich King SAY_LICH_KING_AGGRO_H', 37173),
(36954, 2, 0, 'There is no escape!', 14, 0, 100, 0, 0, 17217, 'Lich King SAY_LICH_KING_WALL_01', 37177),
(36954, 3, 0, 'Succumb to the chill of the grave.', 14, 0, 100, 0, 0, 17218, 'Lich King SAY_LICH_KING_WALL_02', 37175),
(36954, 4, 0, 'Another dead end.', 14, 0, 100, 0, 0, 17219, 'Lich King SAY_LICH_KING_WALL_03', 37176),
(36954, 5, 0, 'How long can you fight it?', 14, 0, 100, 0, 0, 17220, 'Lich King SAY_LICH_KING_WALL_04', 38668),
(36954, 6, 0, 'Arise minions.  Do not let them pass.', 14, 0, 100, 0, 0, 17216, 'Lich King SAY_LICH_KING_GHOUL', 38669),
(36954, 7, 0, 'Minions, sieze them.  Bring their corpses back to me.', 14, 0, 100, 0, 0, 17222, 'Lich King SAY_LICH_KING_ABON', 38670),
(36954, 8, 0, 'Death''s cold embrace awaits.', 14, 0, 100, 0, 0, 17221, 'Lich King SAY_LICH_KING_WINTER', 37174),
(36954, 9, 0, 'Nowhere to run! You''re mine now...', 14, 0, 100, 0, 0, 17223, 'Lich King SAY_LICH_KING_END_DUN', 36994);

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5605,5740);
INSERT INTO `areatrigger_scripts` (`entry`,`scriptname`) VALUES
(5605, 'at_hor_shadow_throne'),
(5740, 'at_hor_impenetrable_door');

DELETE FROM `areatrigger_teleport` WHERE `id`=5740;
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(5740, 'Halls of Reflection (The Impenetrable Door)', 668, 5354.01, 2053.53, 707.695, 0.7853982);

DELETE FROM `lfg_entrances` WHERE `dungeonId` IN(255,256);
INSERT INTO `lfg_entrances` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(255, 'Halls of Reflection (Normal)', 5239.01, 1932.64, 707.695, 0.800565),
(256, 'Halls of Reflection (Heroic)', 5239.01, 1932.64, 707.695, 0.800565);

-- Lady Jaina Proudmoore
UPDATE `creature_template` SET `ScriptName`='npc_jaina_or_sylvanas_intro_hor' WHERE `entry`=37221;
-- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `ScriptName`='npc_jaina_or_sylvanas_intro_hor' WHERE `entry`=37223;
-- Frostsworn General
UPDATE `creature_template` SET `ScriptName`='npc_frostsworn_general' WHERE `entry`=36723;
-- The Lich King
UPDATE `creature_template` SET `ScriptName`='npc_the_lich_king_escape_hor', `mechanic_immune_mask`=617299839 WHERE `entry` = 36954;
-- Icecrown Dungeon Horde Gunship Cannon
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=37593;

UPDATE `gameobject_template` SET `faction`=2102,`flags`=32 WHERE `entry`=201385;
UPDATE `gameobject_template` SET `faction`=1375,`flags`=32 WHERE `entry` IN (201596,201709,202211);
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry` IN (201598,201599);
UPDATE `gameobject_template` SET `faction`=35,`flags`=16 WHERE `entry` IN (201710,202212,202336,202337);

 -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `spell1`=0, `gossip_menu_id`=10860 WHERE `entry`=36955;
 -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `gossip_menu_id`=10909 WHERE `entry`=37554;

DELETE FROM `gossip_menu` WHERE `entry`=10931;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10931, 15190); -- 37554 -- outro gossip

UPDATE `gossip_menu_option` SET `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id`=10860 AND `id`=0;

-- skip intro
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (11031,10950);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11031,1,0,0,14,0,24500,0,0,1,0,0,'','Show options only if quest 24500 taken/complete/rewarded'),
(15,10950,1,0,0,14,0,24802,0,0,1,0,0,'','Show options only if quest 24802 taken/complete/rewarded');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (72900,70190,70017,72368,72369);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(72900, 'spell_hor_start_halls_of_reflection_quest_ae'),
(70190, 'spell_hor_evasion'),
(70017, 'spell_hor_gunship_cannon_fire'),
(72368, 'spell_marwyn_shared_suffering'),
(72369, 'spell_marwyn_shared_suffering');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (69857,70199,70021,70246);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,69857,0,0,31,0,3,36954,0,0,0,0,'','Taunt Arthas targets The Lich King'),
(13,2,70199,0,0,31,0,3,36954,0,0,0,0,'','Blinding Retreat targets The Lich King'),
(13,1,70021,0,0,31,0,3,22515,0,0,0,0,'','Gunship Cannon Fire targets World Trigger'),
(13,1,70021,0,0,1,0,70017,0,0,1,0,0,'','Gunship Cannon Fire target not has aura Gunship Cannon Fire'),
(13,1,70246,0,0,31,0,3,22515,0,0,0,0,'','Gunship Cannon Fire targets World Trigger'),
(13,1,70246,0,0,1,0,70017,0,0,1,0,0,'','Gunship Cannon Fire target not has aura Gunship Cannon Fire');

-- Cloak of Darkness proc on dodge
DELETE FROM `spell_proc_event` WHERE `entry`=70188;
INSERT INTO `spell_proc_event` (`entry`,`procEx`) VALUES
(70188,0x10);

SET @OGUID := 21620; -- need 12
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 201709, 668, 3, 1, 5228.354, 1640.958, 783.7306, 5.585054, 0, 0, 0, 1, -7200, 255, 1),
(@OGUID+1, 201709, 668, 3, 1, 5215.889, 1626.078, 796.4562, 5.585054, 0, 0, 0, 1, -7200, 255, 1),
(@OGUID+2, 202211, 668, 3, 1, 5242.835, 1623.45,  784.1498, 5.811947, 0, 0, 0, 1, -7200, 255, 1),
(@OGUID+3, 202211, 668, 3, 1, 5225.201, 1589.099, 808.5507, 5.811947, 0, 0, 0, 1, -7200, 255, 1),
(@OGUID+4, 202211, 668, 3, 1, 5233.985, 1606.311, 796.2543, 5.811947, 0, 0, 0, 1, -7200, 255, 1),
(@OGUID+5, 195682, 712, 3, 1, 4.395291, 13.68329, 20.80389, 4.19445, 0, 0, 0, 1, 7200, 255, 1),
(@OGUID+6, 201710, 712, 1, 1, -11.7548, 12.02463, 20.40827, 3.217069, 0, 0, 0, 1, 7200, 255, 1),
(@OGUID+7, 202336, 712, 2, 1, -11.7548, 12.02463, 20.40827, 3.217069, 0, 0, 0, 1, 7200, 255, 1),
(@OGUID+8, 202212, 713, 1, 1, 12.23327, 22.47315, 35.07432, 1.239183, 0, 0, 0, 1, 7200, 255, 1),
(@OGUID+9, 202337, 713, 2, 1, 12.23327, 22.47315, 35.07432, 1.239183, 0, 0, 0, 1, 7200, 255, 1),
(@OGUID+10, 195682, 713, 3, 1, 22.17697, 22.95274, 35.65761, 1.919862, 0, 0, 0, 1, 7200, 255, 1),
(@OGUID+11, 191640, 713, 3, 1, 42.08455, 14.60723, 10.65548, 4.244588, 0, 0, 0, 1, 7200, 255, 1);

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN(72395,72396,72397);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(72395,72395,72390), -- Hopelessness
(72396,72396,72391), -- Hopelessness
(72397,72397,72393); -- Hopelessness

DELETE FROM `spell_custom_attr` WHERE `entry` = 74117;
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(74117, 2);
