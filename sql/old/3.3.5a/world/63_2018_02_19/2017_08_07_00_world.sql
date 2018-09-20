DELETE FROM `spelldifficulty_dbc` WHERE  `id` IN (64709,63317,64704,64758,63809);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(64709, 64709, 64734, 0, 0), -- Devouring Flame (Ground)
(63317, 63317, 64021, 0, 0), -- Flame Breath
(64704, 64704, 64733, 0, 0), -- Devouring Flame Damage
(64758, 64758, 64759, 0, 0), -- Chain Lightning
(63809, 63809, 64696, 0, 0); -- Lightning Bolt

DELETE FROM `gameobject` WHERE `id`=194565 AND `map`=603; -- Delete broken harpoons

DELETE FROM `creature` WHERE `id` IN(33210,33287,33816,33259,33233);
DELETE FROM `creature_summon_groups` WHERE `summonerId`=33186; -- Razorscale
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(33186,0,1,33210,585.6672,-104.4477,391.6004,1.518436,8,0), -- Expedition Commander
(33186,0,1,33287,592.5033,-98.55198,391.6004,5.742133,8,0), -- Expedition Engineer
(33186,0,1,33287,589.5328,-95.32281,391.6004,5.51524,8,0 ), -- Expedition Engineer
(33186,0,1,33287,594.3019,-94.38184,391.6004,4.817109,8,0), -- Expedition Engineer
(33186,0,1,33816,600.7484,-104.8482,391.6082,4.852015,8,0), -- Expedition Defender
(33186,0,1,33816,596.3798,-110.2639,391.6004,4.852015,8,0), -- Expedition Defender
(33186,0,1,33816,576.5787,-113.1111,391.6004,4.29351,8,0 ), -- Expedition Defender
(33186,0,1,33816,570.4106,-108.7936,391.6004,4.13643,8,0 ), -- Expedition Defender
(33186,0,1,33816,588.7609,-114.8663,391.6004,4.852015,8,0), -- Expedition Defender
(33186,0,1,33816,566.4739,-103.6336,391.6004,4.363323,8,0), -- Expedition Defender
(33186,0,1,33259,583.61  ,-110.9356,391.6004,4.939282,8,0), -- Expedition Trapper
(33186,0,1,33259,578.1771,-107.6289,391.6004,4.852015,8,0), -- Expedition Trapper
(33186,0,1,33259,588.2538,-108.7151,391.6004,4.991642,8,0), -- Expedition Trapper
(33186,0,1,33233,630.2436,-276.2591,392.3122,1.797689,8,0), -- Razorscale Controller
(33186,0,1,33233,638.2416,-272.1735,392.1351,1.815142,8,0), -- Razorscale Controller
(33186,0,1,33233,633.6514,-287.3748,391.8054,1.797689,8,0), -- Razorscale Controller
(33186,0,1,33233,605.9334,-140.0912,391.6004,4.485496,8,0), -- Razorscale Controller
(33186,0,1,33233,572.4106,-138.6564,393.9044,4.764749,8,0), -- Razorscale Controller
(33186,0,1,33233,558.9486,-142.9874,391.6004,4.764749,8,0), -- Razorscale Controller
(33186,0,1,33233,589.7287,-137.1148,393.9011,4.485496,8,0), -- Razorscale Controller
-- 10 man group
(33186,0,2,33282,589.6996,-134.6657,391.6004,4.555309,8,0), -- Razorscale Harpoon Fire State
(33186,0,2,33282,572.0398,-136.2224,391.2637,4.642576,8,0), -- Razorscale Harpoon Fire State
-- 25 man group
(33186,0,3,33282,559.5352,-140.9866,391.6004,4.642576,8,0), -- Razorscale Harpoon Fire State
(33186,0,3,33282,606.2806,-137.2628,391.6004,4.537856,8,0); -- Razorscale Harpoon Fire State

DELETE FROM `gossip_menu_option` WHERE `MenuID`=10314;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(10314, 0, 0, 'We are ready to help!', 33353, 1, 1, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID`=33210;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(33210,0,0,'Be on the lookout! Mole machines will be surfacing soon with those nasty Iron dwarves aboard!',14,0,100,0,0,0,33607,0,'Expedition Commander SAY_AGGRO'),
(33210,1,0,'Move quickly! She won\'t remain grounded for long!',14,0,100,0,0,15648,33606,0,'Expedition Commander SAY_GROUND_PHASE'),
(33210,2,0,'We have lost our engineers, this will not end well!',14,0,100,0,0,0,33818,0,'Expedition Commander SAY_ENGINEERS_DEAD');

DELETE FROM `creature_text` WHERE `CreatureID`=33186 AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(33186,2,0,'%s goes into a berserker rage!',41,0,100,0,0,0,34057,0,'Razorscale EMOTE_BERSERK');
UPDATE `creature_text` SET `comment`='Razorscale EMOTE_PERMA_GROUND' WHERE `CreatureID`=33186 AND `GroupID`=0 AND `id`=0;
UPDATE `creature_text` SET `comment`='Expedition Engineer SAY_AGGRO' WHERE `CreatureID`=33287 AND `GroupID`=0;
UPDATE `creature_text` SET `comment`='Expedition Engineer SAY_START_REPAIR' WHERE `CreatureID`='33287' AND `GroupID`=1;
UPDATE `creature_text` SET `comment`='Expedition Engineer SAY_REBUILD_TURRETS' WHERE `CreatureID`='33287' AND `GroupID`=2;

UPDATE `creature_template` SET `gossip_menu_id`=10314 WHERE `entry` IN (33210,34254); -- Expedition Commander
UPDATE `creature_template` SET `ScriptName`='npc_expedition_defender' WHERE `entry`=33816;
UPDATE `creature_template` SET `ScriptName`='npc_expedition_trapper' WHERE `entry`=33259;
UPDATE `creature_template` SET `ScriptName`='npc_expedition_engineer' WHERE `entry`=33287;
UPDATE `creature_template` SET `ScriptName`='npc_razorscale_spawner' WHERE `entry`=33245;
UPDATE `creature_template` SET `ScriptName`='npc_razorscale_harpoon_fire_state' WHERE `entry`=33282;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=34188; -- Razorscale Devouring Flame Stalker
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=33233; -- Razorscale Controller

UPDATE `gameobject_template` SET `ScriptName`='go_razorscale_mole_machine' WHERE `entry`=194316;

DELETE FROM `creature_template_addon` WHERE `entry` IN (34188,34189);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(34188,0,0,33554688,0,0,64709), --  Razorscale Devouring Flame Stalker cast Devouring Flame Ground
(34189,0,0,33554688,0,0,64709); --  Razorscale Devouring Flame Stalker cast Devouring Flame Ground

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_razorscale_summon_iron_dwarves',
'spell_razorscale_fuse_armor',
'spell_razorscale_devouring_flame',
'spell_razorscale_firebolt');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63968,'spell_razorscale_summon_iron_dwarves'),
(63970,'spell_razorscale_summon_iron_dwarves'),
(63969,'spell_razorscale_summon_iron_dwarves'),
(64771,'spell_razorscale_fuse_armor'),
(62669,'spell_razorscale_firebolt');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62646; -- Shackle
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,62646,0,0,31,0,3,33186,0,0,0,0,'','Effect_0 hits Razorscale');

-- Enginner North
-- 10

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 1, 0, 5176, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 1, 0, 0, 592.50330, -98.551980, 391.60040),
(33287, 1, 0, 1, 592.21530, -99.816540, 391.80870),
(33287, 1, 0, 2, 591.46530, -109.81650, 391.80870),
(33287, 1, 0, 3, 589.21530, -119.31650, 391.80870),
(33287, 1, 0, 4, 581.21530, -128.31650, 391.80870),
(33287, 1, 0, 5, 574.92730, -133.58110, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=2;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 2, 0, 2375, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=2;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 2, 0, 0, 574.92730, -133.58110, 391.51710),
(33287, 2, 0, 1, 575.80900, -133.45180, 391.70690),
(33287, 2, 0, 2, 584.30900, -128.95180, 391.70690);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=3;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 3, 0, 4106, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=3;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 3, 0, 0, 584.30900, -128.95180, 391.70690),
(33287, 3, 0, 1, 593.52340, -130.30840, 391.70690),
(33287, 3, 0, 2, 592.52340, -116.05840, 391.70690),
(33287, 3, 0, 3, 591.77340, -107.05840, 391.70690),
(33287, 3, 0, 4, 592.35630, -99.294380, 391.51710);

-- 25

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=4;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 4, 0, 6570, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=4;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 4, 0, 0, 592.50330, -98.551980, 391.60040),
(33287, 4, 0, 1, 591.03580, -99.607860, 391.80870),
(33287, 4, 0, 2, 583.03580, -101.60790, 391.80870),
(33287, 4, 0, 3, 574.28580, -110.60790, 391.80870),
(33287, 4, 0, 4, 564.78580, -129.35790, 391.80870),
(33287, 4, 0, 5, 561.56820, -137.66370, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=5;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 5, 0, 2111, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=5;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 5, 0, 0, 561.56820, -137.66370, 391.51710),
(33287, 5, 0, 1, 562.96840, -136.93030, 391.76710),
(33287, 5, 0, 2, 566.46840, -132.68030, 391.76710),
(33287, 5, 0, 3, 571.71840, -130.93030, 391.76710),
(33287, 5, 0, 4, 574.86850, -133.69690, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=6;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 6, 0, 2435, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=6;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 6, 0, 0, 574.86850, -133.69690, 391.51710),
(33287, 6, 0, 1, 575.80470, -133.00260, 391.76710),
(33287, 6, 0, 2, 584.30470, -129.50260, 391.76710),
(33287, 6, 0, 3, 590.30470, -128.75260, 391.76710),
(33287, 6, 0, 4, 592.24080, -131.30820, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=7;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 7, 0, 2689, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=7;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 7, 0, 0, 592.24080, -131.30820, 391.51710),
(33287, 7, 0, 1, 593.93800, -130.91290, 391.59870),
(33287, 7, 0, 2, 602.93800, -128.66290, 391.59870),
(33287, 7, 0, 3, 607.93800, -131.66290, 391.34870),
(33287, 7, 0, 4, 609.63510, -136.01760, 391.18030);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=8;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 8, 0, 5106, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=8;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 8, 0, 0, 609.63510, -136.01760, 391.18030),
(33287, 8, 0, 1, 607.93800, -130.71680, 391.34870),
(33287, 8, 0, 2, 603.43800, -117.46680, 391.34870),
(33287, 8, 0, 3, 596.93800, -107.21680, 391.59870),
(33287, 8, 0, 4, 592.24090, -99.416020, 391.51710);

-- Engineer East

-- 10

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=9;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 9, 0, 5703, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=9;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 9, 0, 0, 589.53280, -95.322810, 391.60040),
(33287, 9, 0, 1, 588.59990, -96.915040, 391.80870),
(33287, 9, 0, 2, 580.34990, -102.41500, 391.80870),
(33287, 9, 0, 3, 574.09990, -108.91500, 391.80870),
(33287, 9, 0, 4, 569.59990, -118.66500, 391.80870),
(33287, 9, 0, 5, 568.66690, -132.50730, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=10;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 10, 0, 2551, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=10;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 10, 0, 0, 568.66690, -132.50730, 391.51710),
(33287, 10, 0, 1, 570.50920, -131.02470, 391.76710),
(33287, 10, 0, 2, 579.25920, -126.52470, 391.76710),
(33287, 10, 0, 3, 586.35140, -130.54220, 391.51710);


DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=11;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 11, 0, 4375, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=11;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 11, 0, 0, 586.35140, -130.54220, 391.51710),
(33287, 11, 0, 1, 586.98820, -127.71770, 391.76710),
(33287, 11, 0, 2, 590.73820, -116.71770, 391.76710),
(33287, 11, 0, 3, 590.73820, -105.96770, 391.76710),
(33287, 11, 0, 4, 589.12480, -96.393230, 391.51710);

-- 25

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=12;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 12, 0, 6953, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=12;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 12, 0, 0, 589.53280, -95.322810, 391.60040),
(33287, 12, 0, 1, 587.84770, -95.547740, 391.80870),
(33287, 12, 0, 2, 579.59770, -100.29770, 391.80870),
(33287, 12, 0, 3, 573.59770, -107.04770, 391.80870),
(33287, 12, 0, 4, 569.09770, -115.04770, 391.80870),
(33287, 12, 0, 5, 559.59770, -131.29770, 391.80870),
(33287, 12, 0, 6, 557.16260, -138.27270, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=13;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 13, 0, 1853, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=13;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 13, 0, 0, 557.16260, -138.27270, 391.51710),
(33287, 13, 0, 1, 558.27150, -136.16690, 391.76710),
(33287, 13, 0, 2, 565.27150, -132.66690, 391.76710),
(33287, 13, 0, 3, 569.88050, -133.56110, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=14;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 14, 0, 2155, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=14;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 14, 0, 0, 569.88050, -133.56110, 391.51710),
(33287, 14, 0, 1, 574.97390, -132.21020, 391.76710),
(33287, 14, 0, 2, 580.22390, -130.71020, 391.76710),
(33287, 14, 0, 3, 586.56720, -131.85940, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=15;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 15, 0, 5040, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=15;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 15, 0, 0, 586.56720, -131.85940, 391.51710),
(33287, 15, 0, 1, 589.26450, -129.92940, 391.76710),
(33287, 15, 0, 2, 599.51450, -129.67940, 391.76710),
(33287, 15, 0, 3, 603.96190, -133.99950, 391.51710);

-- Engineer West

-- 10

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=16;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 16, 0, 5932, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=16;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 16, 0, 0, 594.30190, -94.381840, 391.60040),
(33287, 16, 0, 1, 592.85390, -95.531520, 391.80870),
(33287, 16, 0, 2, 583.85390, -102.03150, 391.80870),
(33287, 16, 0, 3, 576.85390, -107.28150, 391.80870),
(33287, 16, 0, 4, 573.10390, -118.28150, 391.80870),
(33287, 16, 0, 5, 572.40590, -132.18120, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=17;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 17, 0, 2337, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=17;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 17, 0, 0, 572.40590, -132.18120, 391.51710),
(33287, 17, 0, 1, 573.77820, -131.55440, 391.76710),
(33287, 17, 0, 2, 583.77820, -128.05440, 391.76710),
(33287, 17, 0, 3, 590.15060, -129.92770, 391.51710);


DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=18;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 18, 0, 4440, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=18;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 18, 0, 0, 590.15060, -129.92770, 391.51710),
(33287, 18, 0, 1, 590.66970, -128.37400, 391.76710),
(33287, 18, 0, 2, 592.66970, -113.37400, 391.76710),
(33287, 18, 0, 3, 594.66970, -100.12400, 391.76710),
(33287, 18, 0, 4, 594.18870, -94.820260, 391.51710);

-- 25

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=19;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 19, 0, 6906, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=19;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 19, 0, 0, 594.30190, -94.381840, 391.60040),
(33287, 19, 0, 1, 593.02330, -94.994300, 391.80870),
(33287, 19, 0, 2, 586.02330, -99.744300, 391.80870),
(33287, 19, 0, 3, 577.02330, -105.74430, 391.80870),
(33287, 19, 0, 4, 572.52330, -114.49430, 391.80870),
(33287, 19, 0, 5, 566.52330, -124.49430, 391.80870),
(33287, 19, 0, 6, 560.74480, -136.10680, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=20;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 20, 0, 1623, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=20;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 20, 0, 0, 560.74480, -136.10680, 391.51710),
(33287, 20, 0, 1, 561.80880, -135.08010, 391.76710),
(33287, 20, 0, 2, 566.30880, -131.33010, 391.76710),
(33287, 20, 0, 3, 571.87280, -131.55340, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=21;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 21, 0, 2427, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=21;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 21, 0, 0, 571.87280, -131.55340, 391.51710),
(33287, 21, 0, 1, 574.20680, -131.91800, 391.76710),
(33287, 21, 0, 2, 582.70680, -128.66800, 391.76710),
(33287, 21, 0, 3, 590.54090, -129.78250, 391.51710);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=22;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 22, 0, 2123, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=22;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 22, 0, 0, 590.54090, -129.78250, 391.51710),
(33287, 22, 0, 1, 593.33170, -129.52560, 392.16520),
(33287, 22, 0, 2, 601.08170, -128.77560, 391.66520),
(33287, 22, 0, 3, 606.12250, -132.76870, 391.31340);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=33287 AND `chainId`=23;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(33287, 23, 0, 5082, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=33287 AND `chainId`=23;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(33287, 23, 0, 0, 606.12250, -132.76870, 391.31340),
(33287, 23, 0, 1, 606.97240, -130.52870, 391.41520),
(33287, 23, 0, 2, 603.72240, -119.77870, 391.41520),
(33287, 23, 0, 3, 597.97240, -108.77870, 391.66520),
(33287, 23, 0, 4, 595.47240, -101.52870, 391.66520),
(33287, 23, 0, 5, 594.32230, -94.788800, 391.51710);
