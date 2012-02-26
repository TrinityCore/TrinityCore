SET NAMES 'utf8';

DELETE FROM `trinity_string` WHERE entry IN (756,757,758,759,760,761,762,763,764,765,766,767,768,769,770,771,772,780,781,782,783);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
('756', 'Battle begins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '�?и�?ва на�?аНас�?'),
('757', '%s has successfully defended the fortress!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '%s успошнО Са�?и�?иН(а) к�?опОс�?�?!'),
('758', '%s has taken over the fortress!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '%s Са�?ва�?иН(а) к�?опОс�?�?'),
('759', 'The %s siege workshop has been damaged by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('760', 'The %s siege workshop has been destroyed by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('761', 'The %s tower has been damaged!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '%s йашн�? пОв�?оМдона'),
('762', 'The %s tower has been destroyed!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '%s йашн�? уни�?�?ОМона!'),
('763', 'Wintergrasp fortress is under attack!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('764', 'Wintergrasp is now under the control of the %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('765', 'Wintergrasp timer set to %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('766', 'Wintergrasp battle started.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('767', 'Wintergrasp battle finished.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('768', 'Wintergrasp info: %s controlled. Timer: %s. Wartime: %s. Number of Players: (Horde: %u, Alliance: %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('769', 'Wintergrasp outdoorPvP is disabled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('770', 'Wintergrasp outdoorPvP is enabled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('771', 'You have reached Rank 1: Corporal', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '�?�? дОс�?игНи � анга 1: �?ап�?аН'),
('772', 'You have reached Rank 2: First Lieutenant', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '�?�? дОс�?игНи � анга 2: �?оК�?онан�?'),
('780', 'Before the Battle of  Wintergrasp left 30 minutes!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '�?О йи�?в�? на  �?Со�?о �?од�?н�?�? �?кОв Ос�?аНОс�? 30 Пину�?!'),
('781', 'Before the Battle of  Wintergrasp left 10 minutes! Portal from Dalaran will work at begin of the battle.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '�?О йи�?в�? на  �?Со�?о �?од�?н�?�? �?кОв Ос�?аНОс�? 10 Пину�?! �?О�?�?аН с �?аНа�?ана на�?но�? �?айО�?у вО в�?оП�? йО�?.'),
('782', 'The battle for Wintergrasp  has stopped! Not enough defenders. Wintergrasp Fortress remains  Attackers.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '�?и�?ва Са �?Со�?О �?од�?н�?�? �?кОв �?с�?анОвНона. �?о �?ва�?ао�? Са�?и�?никОв. �?�?опОс�?�? по�?о�?Оди�? а�?аку�?�?оК  с�?О�?Оно.'),
('783', 'The battle for Wintergrasp  has stopped! Not enough attackers. Wintergrasp Fortress remains  Defenders.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '�?и�?ва Са �?Со�?О �?од�?н�?�? �?кОв �?с�?анОвНона. �?о �?ва�?ао�? напада�?�?и�?. �?�?опОс�?�? Ос�?ао�?с�? Са�?и�?никаП.');

DELETE FROM `command` WHERE name IN ('wg','wg enable','wg start','wg status','wg stop','wg switch','wg timer');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('wg', '3', 'Syntax: .wg $subcommand.'),
('wg enable', '3', 'Syntax: .wg enable [on/off] Enable/Disable Wintergrasp outdoorPvP.'),
('wg start', '3', 'Syntax: .wg start\r\nForce Wintergrasp battle start.'),
('wg status', '3', 'Syntax: .wg status\r\nWintergrasp info, defender, timer, wartime.'),
('wg stop', '3', 'Syntax: .wg stop\r\nForce Wintergrasp battle stop (No rewards).'),
('wg switch', '3', 'Syntax: .wg switch\r\nSwitchs Wintergrasp defender team.'),
('wg timer', '3', 'Syntax: .wg timer $minutes\r\nChange the current timer. Min value = 1, Max value 60 (Wartime), 1440 (Not Wartime)');

/* WG scriptname */
DELETE FROM `outdoorpvp_template` WHERE TypeId=7;
INSERT INTO `outdoorpvp_template` (`TypeId`, `ScriptName`, `comment`) VALUES 
('7', 'outdoorpvp_wg', 'Wintergrasp');

/* Teleport WG SPELLs*/
DELETE FROM `spell_target_position` WHERE id IN ('59096', '58632', '58633');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
('59096', '571', '5325.06', '2843.36', '409.285', '3.20278'),
('58632', '571', '5097.79', '2180.29', '365.61', '2.41'),
('58633', '571', '5026.80', '3676.69', '362.58', '3.94');

/* Defender's Portal Activate Proper Spell */
DELETE FROM `spell_linked_spell` WHERE spell_trigger=54640;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
('54640','54643','0','Defender\'s Portal Activate Proper Spell');

/* Protect players from catching by Druid Cyclone at graveyard which removes immunity after disappear */
DELETE FROM `spell_linked_spell` WHERE spell_trigger=58729;
INSERT INTO `spell_linked_spell` VALUES (58729, -33786, 2, 'Spiritual Immunity: Protect From Cyclone (now Immune always)');

/*Spirit healer add spiritguide flag FIX for ressurection*/
UPDATE creature_template SET npcflag=npcflag|32768 WHERE entry IN (31841,31842);

/* Creature template */
UPDATE creature_template SET faction_A = '1802', faction_H = '1802' WHERE entry IN (30499,28312,28319);
UPDATE creature_template SET faction_A = '1801', faction_H = '1801' WHERE entry IN (30400,32629,32627);

/* Demolisher Engineer script */
UPDATE `creature_template` SET `ScriptName` = 'npc_demolisher_engineerer' WHERE `entry` IN (30400,30499);

/* Wintergrasp Battle-Mage */
DELETE FROM `creature` WHERE `id` IN (32170, 32169);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(NULL, 32170, 571, 1, 65535, 27801, 0, 5917.69, 584.167, 660.49, 5.17983, 300, 0, 0, 504000, 440700, 0, 0, 0, 0),
(NULL, 32170, 571, 1, 65535, 0, 2796, 5939.59, 556.516, 640.001, 2.70112, 300, 0, 0, 504000, 440700, 0, 0, 0, 0),
(NULL, 32169, 571, 1, 65535, 0, 0, 5698.38, 777.562, 647.852, 5.56938, 900, 0, 0, 504000, 440700, 0, 0, 0, 0);

UPDATE `creature_template` SET `ScriptName`='npc_wg_ally_battle_mage' WHERE `entry`=32169;
UPDATE `creature_template` SET `ScriptName`='npc_wg_horde_battle_mage' WHERE `entry`=32170;

/* Portal Dalaran->WG */
DELETE FROM `gameobject` WHERE `id`=193772;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(NULL, 193772, 571, 1, 64, 5924.11, 573.387, 661.087, 4.43208, 0, 0, 0.798953, -0.601393, 300, 0, 1),
(NULL, 193772, 571, 1, 65535, 5686.57, 772.921, 647.754, 5.62225, 0, 0, 0.324484, -0.945891, 600, 0, 1),
(NULL, 193772, 571, 1, 65535, 5930.82, 548.961, 640.632, 1.88506, 0, 0, 0.809047, 0.587744, 300, 0, 1);

/* Vehicle Teleporter */
UPDATE `gameobject_template` SET `type` = 6, `faction` = 0, `data2` = 10, `data3` = 54643, `ScriptName` = 'go_wg_veh_teleporter' WHERE `entry` = 192951;

/* Workshop */
UPDATE `gameobject_template` SET `faction` = 35 WHERE `entry` IN (192028,192029,192030,192031,192032,192033);

/* Towers */
UPDATE `gameobject_template` SET `faction` = 0, `flags` = 6553632 WHERE `entry` IN (190356,190357,190358);

/* Titan Relic remove */
DELETE FROM `gameobject` WHERE `id`=192829;

/* Temp removed gameobject stopping you getting to the relic
* 194323 - [Wintergrasp Keep Collision Wall X:5396.209961 Y:2840.010010 Z:432.268005 MapId:571
* 194162 - [Doodad_WG_Keep_Door01_collision01 X:5397.109863 Y:2841.540039 Z:425.901001 MapId:571]*/
DELETE FROM gameobject WHERE id IN ('194323', '194162');

/* spell target for build vehicles */
DELETE FROM `conditions` WHERE ConditionValue2=27852;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 49899, 0, 18, 1, 27852, 0, 0, '', NULL),
(13, 0, 56575, 0, 18, 1, 27852, 0, 0, '', NULL),
(13, 0, 56661, 0, 18, 1, 27852, 0, 0, '', NULL),
(13, 0, 56663, 0, 18, 1, 27852, 0, 0, '', NULL),
(13, 0, 56665, 0, 18, 1, 27852, 0, 0, '', NULL),
(13, 0, 56667, 0, 18, 1, 27852, 0, 0, '', NULL),
(13, 0, 56669, 0, 18, 1, 27852, 0, 0, '', NULL),
(13, 0, 61408, 0, 18, 1, 27852, 0, 0, '', NULL);

/*WG Spell area Data For wg antifly */
DELETE FROM `spell_area` WHERE spell IN (58730, 57940, 58045);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_start_active`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`) VALUES
(58730, 4197, 0, 0, 0, 0, 0, 2, 1),
(58730, 4584, 0, 0, 0, 0, 0, 2, 1),
(58730, 4581, 0, 0, 0, 0, 0, 2, 1),
(58730, 4585, 0, 0, 0, 0, 0, 2, 1),
(58730, 4612, 0, 0, 0, 0, 0, 2, 1),
(58730, 4582, 0, 0, 0, 0, 0, 2, 1),
(58730, 4611, 0, 0, 0, 0, 0, 2, 1),
(58730, 4578, 0, 0, 0, 0, 0, 2, 1),
(58730, 4576, 0, 0, 0, 0, 0, 2, 1),
(58730, 4538, 0, 0, 0, 0, 0, 2, 1),
(57940, 65, 0, 0, 0, 0, 0, 2, 1),
(57940, 66, 0, 0, 0, 0, 0, 2, 1),
(57940, 67, 0, 0, 0, 0, 0, 2, 1),
(57940, 206, 0, 0, 0, 0, 0, 2, 1),
(57940, 210, 0, 0, 0, 0, 0, 2, 1),
(57940, 394, 0, 0, 0, 0, 0, 2, 1),
(57940, 395, 0, 0, 0, 0, 0, 2, 1),
(57940, 1196, 0, 0, 0, 0, 0, 2, 1),
(57940, 2817, 0, 0, 0, 0, 0, 2, 1),
(57940, 3456, 0, 0, 0, 0, 0, 2, 1),
(57940, 3477, 0, 0, 0, 0, 0, 2, 1),
(57940, 3537, 0, 0, 0, 0, 0, 2, 1),
(57940, 3711, 0, 0, 0, 0, 0, 2, 1),
(57940, 4100, 0, 0, 0, 0, 0, 2, 1),
(57940, 4196, 0, 0, 0, 0, 0, 2, 1),
(57940, 4228, 0, 0, 0, 0, 0, 2, 1),
(57940, 4264, 0, 0, 0, 0, 0, 2, 1),
(57940, 4265, 0, 0, 0, 0, 0, 2, 1),
(57940, 4272, 0, 0, 0, 0, 0, 2, 1),
(57940, 4273, 0, 0, 0, 0, 0, 2, 1),
(57940, 4395, 0, 0, 0, 0, 0, 2, 1),
(57940, 4415, 0, 0, 0, 0, 0, 2, 1),
(57940, 4416, 0, 0, 0, 0, 0, 2, 1),
(57940, 4493, 0, 0, 0, 0, 0, 2, 1),
(57940, 4494, 0, 0, 0, 0, 0, 2, 1),
(57940, 4603, 0, 0, 0, 0, 0, 2, 1),
(58045, 4197, 0, 0, 0, 0, 0, 2, 1);

DELETE FROM gameobject WHERE 
      id IN (192317,192335,192313,192316,192332,192331,192330,192329,192487,192310,192314,192308,192309,192324,192326,192312,192325,192304,187433,193984,193983,192377,192321,192318,192322,192320,192269,192273,192274,192277,192278,192280,192283,192284,192285,192289,192290,192336,192338,192339,192349,192350,192351,192352,192353,192354,192355,192356,192357,192358,192359,192360,192361,192362,192363,192364,192366,192367,192368,192369,192370,192371,192372,192373,192374,192375,192378,192379,192406,192407,192414,192416,192417,192418,192429,192433,192434,192435,192458,192459,192460,192461,192488,192501,192254,192255,192688,192686,180398,193764,193762,192319,192287,192323,192305,192286,192334,192307,192306,192328,192252,192253,192292,192299,192327,192267,192449,192450) 
         AND map=571;
INSERT INTO `gameobject` VALUES (NULL, 192317, 571, 1, 385, 5363.39, 2781.28, 435.634, 1.58825, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192335, 571, 1, 385, 5363.72, 2763.25, 445.023, -1.54462, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192313, 571, 1, 1, 5392.65, 3037.11, 433.713, -1.52716, 0, 0, -0.691512, 0.722365, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192316, 571, 1, 385, 5322.01, 2781.13, 435.673, 1.57952, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192332, 571, 1, 1, 5289.46, 2704.68, 435.875, -0.017451, 0, 0, -0.00872539, 0.999962, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192331, 571, 1, 1, 5350.95, 2640.36, 435.408, 1.5708, 0, 0, 0.707108, 0.707106, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192330, 571, 1, 1, 5392.27, 2639.74, 435.331, 1.50971, 0, 0, 0.685183, 0.728371, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192329, 571, 1, 1, 5350.88, 2622.72, 444.686, -1.5708, 0, 0, -0.707108, 0.707106, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 1, 5278.38, 2613.83, 432.721, -1.58825, 0, 0, -0.713251, 0.700909, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 1, 5260.82, 2631.8, 433.324, 3.05433, 0, 0, 0.999048, 0.0436174, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192310, 571, 1, 1, 5271.8, 2704.87, 445.183, -3.13286, 0, 0, -0.99999, 0.00436634, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192314, 571, 1, 1, 5236.27, 2739.46, 444.992, -1.59698, 0, 0, -0.716303, 0.697789, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 1, 5163.78, 2729.68, 432.009, -1.58825, 0, 0, -0.713251, 0.700909, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192308, 571, 1, 1, 5237.07, 2757.03, 435.796, 1.51844, 0, 0, 0.688356, 0.725373, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192309, 571, 1, 1, 5235.34, 2924.34, 435.04, -1.5708, 0, 0, -0.707108, 0.707106, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 1, 5262.54, 3047.95, 430.979, 3.10665, 0, 0, 0.999847, 0.0174704, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 1, 5163.13, 2952.59, 433.503, 1.53589, 0, 0, 0.694658, 0.71934, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192324, 571, 1, 1, 5235.19, 2942, 443.948, 1.58825, 0, 0, 0.713251, 0.700909, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192326, 571, 1, 1, 5272.73, 2976.55, 443.81, 3.12412, 0, 0, 0.999962, 0.00873622, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192312, 571, 1, 1, 5352.37, 3037.09, 435.252, -1.5708, 0, 0, -0.707108, 0.707106, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192325, 571, 1, 1, 5290.35, 2976.56, 435.221, 0.017452, 0, 0, 0.00872589, 0.999962, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192304, 571, 1, 385, 5397.76, 2873.08, 455.321, 3.10665, 0, 0, 0.999847, 0.0174704, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 187433, 571, 1, 1, 2832.84, 6184.45, 84.6827, -2.58308, 0, 0, 0, 0, 300, 100, 1);
INSERT INTO `gameobject` VALUES (NULL, 187433, 571, 1, 1, 2835.96, 6180.37, 84.6827, 1.50098, 0, 0, 0, 0, 180, 100, 1);
INSERT INTO `gameobject` VALUES (NULL, 187433, 571, 1, 1, 2830.12, 6188.96, 84.6827, -0.855211, 0, 0, 0, 0, 300, 100, 1);
INSERT INTO `gameobject` VALUES (NULL, 187433, 571, 1, 1, 2831.88, 6188.72, 84.6827, -1.65806, 0, 0, 0, 0, 300, 100, 1);
INSERT INTO `gameobject` VALUES (NULL, 193984, 571, 1, 1, 7647.47, 2055.55, 599.399, -0.279252, 0, 0, 0, 0, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 193984, 571, 1, 1, 7647.42, 2065.23, 599.308, 0.279252, 0, 0, 0, 0, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 193984, 571, 1, 1, 7609.86, 2055.53, 599.494, -2.86234, 0, 0, 0, 0, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 193984, 571, 1, 1, 7610.18, 2065.31, 599.426, 2.87979, 0, 0, 0, 0, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 193983, 571, 1, 1, 7906.95, 2053.04, 599.626, -0.296705, 0, 0, 0, 0, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 193983, 571, 1, 1, 7907.01, 2063.02, 599.587, 0.261798, 0, 0, 0, 0, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 193983, 571, 1, 1, 7870.43, 2053.35, 599.669, -2.87979, 0, 0, 0, 0, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 193983, 571, 1, 1, 7870.36, 2063.25, 599.628, 2.86234, 0, 0, 0, 0, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192377, 571, 1, 1, 5414.19, 3069.8, 415.187, 1.64061, 0, 0, 0, 0, 5, 100, 1);
INSERT INTO `gameobject` VALUES (NULL, 192321, 571, 1, 385, 5288.85, 2861.82, 435.591, 0.026179, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192318, 571, 1, 385, 5322.25, 2898.95, 435.643, -1.57952, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192322, 571, 1, 385, 5322.89, 2917.14, 445.154, 1.56207, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192320, 571, 1, 385, 5289.05, 2820.23, 435.674, 0, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192269, 571, 1, 1, 4526.46, 2810.18, 391.2, -2.99322, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192273, 571, 1, 1, 4417.94, 2324.81, 371.577, 3.08051, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192274, 571, 1, 1, 4424.15, 3286.54, 371.546, 3.12412, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192277, 571, 1, 1, 4572.93, 3475.52, 363.009, 1.42244, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192278, 571, 1, 1, 4433.9, 3534.14, 360.275, -1.85005, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192280, 571, 1, 1, 4857.97, 3335.44, 368.881, -2.94959, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192283, 571, 1, 1, 5006.34, 3280.4, 371.163, 2.22529, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192284, 571, 1, 65, 5372.48, 2862.5, 409.049, 3.14159, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192285, 571, 1, 65, 5371.49, 2820.8, 409.177, 3.14159, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192289, 571, 1, 1, 4778.19, 2438.06, 345.644, -2.94088, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192290, 571, 1, 1, 5024.57, 2532.75, 344.023, -1.93732, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192336, 571, 1, 1, 5154.49, 2862.15, 445.012, 3.14159, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192338, 571, 1, 65, 5397.76, 2873.08, 455.461, 3.10665, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192339, 571, 1, 65, 5397.39, 2809.33, 455.344, 3.10665, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192349, 571, 1, 1, 5155.31, 2820.74, 444.979, -3.13286, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192350, 571, 1, 1, 5270.69, 2861.78, 445.058, -3.11539, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192351, 571, 1, 1, 5271.28, 2820.16, 445.201, -3.13286, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192352, 571, 1, 1, 5173.02, 2820.93, 435.72, 0.017452, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192353, 571, 1, 1, 5172.11, 2862.57, 435.721, 0.017452, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192354, 571, 1, 1, 5288.41, 2861.79, 435.721, 0.017452, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192355, 571, 1, 1, 5288.92, 2820.22, 435.721, 0.017452, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192356, 571, 1, 1, 5237.07, 2757.03, 435.796, 1.51844, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192357, 571, 1, 1, 5235.34, 2924.34, 435.04, -1.5708, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192358, 571, 1, 65, 5322.23, 2899.43, 435.808, -1.58825, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192359, 571, 1, 65, 5364.35, 2899.4, 435.839, -1.5708, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192360, 571, 1, 65, 5352.37, 3037.09, 435.252, -1.5708, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192361, 571, 1, 65, 5392.65, 3037.11, 433.713, -1.52716, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192362, 571, 1, 65, 5322.12, 2763.61, 444.974, -1.55334, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192363, 571, 1, 65, 5363.61, 2763.39, 445.024, -1.54462, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192364, 571, 1, 1, 5350.88, 2622.72, 444.686, -1.5708, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192366, 571, 1, 1, 5236.27, 2739.46, 444.992, -1.59698, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192367, 571, 1, 1, 5271.8, 2704.87, 445.183, -3.13286, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192368, 571, 1, 65, 5289.46, 2704.68, 435.875, -0.017451, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192369, 571, 1, 1, 5350.95, 2640.36, 435.408, 1.5708, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192370, 571, 1, 1, 5392.27, 2639.74, 435.331, 1.50971, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192371, 571, 1, 65, 5364.29, 2916.94, 445.331, 1.57952, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192372, 571, 1, 65, 5322.86, 2916.95, 445.154, 1.56207, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192373, 571, 1, 1, 5290.35, 2976.56, 435.221, 0.017452, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192374, 571, 1, 1, 5272.94, 2976.55, 444.492, 3.12412, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192375, 571, 1, 1, 5235.19, 2941.9, 444.278, 1.58825, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192378, 571, 1, 65, 5322.02, 2781.13, 435.811, 1.5708, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192379, 571, 1, 65, 5363.42, 2781.03, 435.763, 1.5708, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192406, 571, 1, 1, 4438.3, 3361.08, 371.568, -0.017451, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192407, 571, 1, 1, 4448.17, 3235.63, 370.412, -1.56207, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192414, 571, 1, 1, 4387.62, 2719.57, 389.935, -1.54462, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192416, 571, 1, 1, 4408.57, 2422.61, 377.179, 1.58825, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192417, 571, 1, 1, 4416.59, 2414.08, 377.196, 0, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192418, 571, 1, 1, 4417.25, 2301.14, 377.214, 0.026179, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192429, 571, 1, 1, 4464.12, 2855.45, 406.111, 0.829032, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192433, 571, 1, 1, 4401.63, 3377.46, 363.365, 1.55334, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192434, 571, 1, 1, 5041.61, 3294.4, 382.15, -1.63188, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192435, 571, 1, 1, 4855.63, 3297.62, 376.739, -3.13286, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192458, 571, 1, 1, 4811.4, 2441.9, 358.207, -2.0333, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192459, 571, 1, 1, 4805.67, 2407.48, 358.191, 1.78023, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192460, 571, 1, 1, 5004.35, 2486.36, 358.449, 2.17294, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192461, 571, 1, 1, 4983.28, 2503.09, 358.177, -0.427603, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 1, 5160.34, 2798.61, 430.769, 3.14159, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 1, 5158.81, 2883.13, 431.618, 3.14159, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 1, 5278.38, 2613.83, 433.409, -1.58825, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 1, 5260.82, 2631.8, 433.324, 3.05433, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 1, 5163.13, 2952.59, 433.503, 1.53589, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 1, 5145.11, 2935, 433.386, 3.14159, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 1, 5262.54, 3047.95, 432.055, 3.10665, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 1, 5146.04, 2747.21, 433.584, 3.07177, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 1, 5163.78, 2729.68, 433.394, -1.58825, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4398.82, 2804.7, 429.792, -1.58825, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4416, 2822.67, 429.851, -0.017452, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4559.11, 3606.22, 419.999, -1.48353, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4539.42, 3622.49, 420.034, -3.07177, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4555.26, 3641.65, 419.974, 1.67551, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4574.87, 3625.91, 420.079, 0.087266, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4466.79, 1960.42, 459.144, 1.15192, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4475.35, 1937.03, 459.07, -0.436332, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4451.76, 1928.1, 459.076, -2.00713, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192501, 571, 1, 1, 4442.99, 1951.9, 459.093, 2.74016, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192254, 571, 1, 1, 5154.46, 2828.94, 409.189, 3.14159, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192255, 571, 1, 1, 5154.52, 2853.31, 409.183, 3.14159, 0, 0, 0, 1, 180, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192688, 571, 1, 1, 5916.1, 566.209, 639.625, -2.72271, 0, 0, 0, 1, 180, 100, 1);
INSERT INTO `gameobject` VALUES (NULL, 192686, 571, 1, 1, 5664.81, 791.002, 653.698, -0.663223, 0, 0, 0, 1, 180, 100, 1);
INSERT INTO `gameobject` VALUES (NULL, 180398, 571, 1, 1, 5665.02, 790.2, 653.698, -0.610864, 0, 0, 0, 1, 180, 100, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 256, 4855.63, 3297.62, 376.281, -3.13286, 0, 0, -0.99999, 0.00436634, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192290, 571, 1, 256, 4526.46, 2810.18, 391.2, -2.99322, 0, 0, -0.997249, 0.0741182, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 256, 4517.75, 2717.23, 387.812, -1.53589, 0, 0, -0.694658, 0.71934, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4475.35, 1937.03, 459.07, -0.436332, 0, 0, -0.216439, 0.976296, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4451.76, 1928.1, 459.076, -2.00713, 0, 0, -0.843392, 0.537299, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4442.99, 1951.9, 459.093, 2.74016, 0, 0, 0.979924, 0.199371, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4466.8, 1960.44, 459.841, 1.15192, 0, 0, 0.54464, 0.83867, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 256, 5041.61, 3294.4, 382.15, -1.63188, 0, 0, -0.72837, 0.685184, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192278, 571, 1, 256, 5006.34, 3280.4, 371.163, 2.22529, 0, 0, 0.896872, 0.442291, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192278, 571, 1, 256, 4857.97, 3335.44, 368.881, -2.94959, 0, 0, -0.995395, 0.0958539, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192290, 571, 1, 256, 4433.9, 3534.14, 360.275, -1.85005, 0, 0, -0.798636, 0.601815, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192290, 571, 1, 256, 4572.93, 3475.52, 363.009, 1.42244, 0, 0, 0.652758, 0.757566, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4555.26, 3641.65, 419.974, 1.67551, 0, 0, 0.743143, 0.669133, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4574.87, 3625.91, 420.079, 0.087266, 0, 0, 0.0436192, 0.999048, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4559.11, 3606.22, 419.999, -1.48353, 0, 0, -0.67559, 0.737277, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4539.42, 3622.49, 420.034, -3.07177, 0, 0, -0.999391, 0.0349043, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192290, 571, 1, 256, 4401.63, 3377.46, 363.365, 1.55334, 0, 0, 0.700908, 0.713252, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4448.17, 3235.63, 370.412, -1.56207, 0, 0, -0.704015, 0.710185, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192488, 571, 1, 256, 4438.3, 3361.08, 371.299, -0.017451, 0, 0, -0.00872539, 0.999962, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192290, 571, 1, 256, 4424.15, 3286.54, 371.546, 3.12412, 0, 0, 0.999962, 0.00873622, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192461, 571, 1, 1, 4416.03, 2822.68, 430.475, -0.017452, 0, 0, -0.00872589, 0.999962, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192461, 571, 1, 1, 4464.12, 2855.45, 406.111, 0.829032, 0, 0, 0.402747, 0.915311, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192461, 571, 1, 1, 4398.82, 2804.7, 429.792, -1.58825, 0, 0, -0.713251, 0.700909, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192461, 571, 1, 1, 4408.57, 2422.61, 377.179, 1.58825, 0, 0, 0.713251, 0.700909, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192461, 571, 1, 1, 4416.59, 2414.08, 377.13, 0, 0, 0, 0, 1, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192461, 571, 1, 1, 4417.25, 2301.14, 377.214, 0.026179, 0, 0, 0.0130891, 0.999914, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192418, 571, 1, 1, 4805.67, 2407.48, 358.191, 1.78023, 0, 0, 0.777144, 0.629323, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192418, 571, 1, 1, 4811.4, 2441.9, 358.207, -2.0333, 0, 0, -0.85035, 0.526218, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192273, 571, 1, 1, 4778.19, 2438.06, 345.644, -2.94088, 0, 0, -0.994969, 0.100188, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192273, 571, 1, 1, 5024.57, 2532.75, 344.023, -1.93732, 0, 0, -0.824127, 0.566404, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192418, 571, 1, 1, 5004.35, 2486.36, 358.449, 2.17294, 0, 0, 0.884989, 0.465612, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192418, 571, 1, 1, 4983.28, 2503.09, 358.177, -0.427603, 0, 0, -0.212176, 0.977231, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 192290, 571, 1, 1, 4417.94, 2324.81, 371.577, 3.08051, 0, 0, 0.999534, 0.0305366, 300, 0, 1);
INSERT INTO `gameobject` VALUES (NULL, 193764, 571, 1, 1, 7625.87, 2060.05, 604.27, 0.07854, 0, 0, 0.99999, 0.004363, 180, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 193762, 571, 1, 1, 7625.66, 2060.04, 604.195, -3.05428, 0, 0, 0.99999, 0.004363, 180, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192319, 571, 1, 385, 5364.3, 2899.22, 435.691, -1.55334, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192287, 571, 1, 385, 5372.42, 2862.48, 409.366, 3.14159, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192323, 571, 1, 385, 5364.28, 2917.26, 445.332, 1.58825, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192305, 571, 1, 385, 5397.31, 2809.26, 455.102, 3.13286, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192286, 571, 1, 385, 5371.45, 2820.79, 409.427, 3.12412, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192334, 571, 1, 385, 5322.17, 2763.2, 444.974, -1.56207, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192307, 571, 1, 385, 5271.16, 2820.11, 445.109, -3.13286, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192306, 571, 1, 385, 5270.56, 2861.68, 444.917, -3.12412, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 385, 5160.28, 2798.6, 430.604, -3.12412, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 385, 5146.04, 2747.3, 433.527, 3.12412, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192328, 571, 1, 385, 5173.13, 2820.96, 435.658, 0.026179, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192252, 571, 1, 385, 5154.37, 2853.23, 409.183, 3.14159, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192253, 571, 1, 385, 5154.42, 2828.93, 409.189, 3.14159, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192292, 571, 1, 385, 5154.35, 2862.08, 445.01, 3.14159, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192299, 571, 1, 385, 5155.22, 2820.63, 444.979, -3.11539, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192327, 571, 1, 385, 5172.34, 2862.57, 435.658, 0, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 385, 5158.71, 2882.9, 431.274, 3.14159, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192487, 571, 1, 385, 5145.11, 2934.95, 433.255, -3.10665, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192267, 571, 1, 385, 4452.76, 2639.14, 358.444, 1.67552, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192449, 571, 1, 385, 4517.75, 2717.23, 387.812, -1.53589, 0, 0, 0, 1, 300, 255, 1);
INSERT INTO `gameobject` VALUES (NULL, 192450, 571, 1, 385, 4387.59, 2719.9, 390.201, -1.51843, 0, 0, 0, 1, 300, 255, 1);

