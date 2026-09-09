-- Spawn groups, creatures
SET @CGUID := 147498; -- 13
SET @OGUID := 94138; -- 13
SET @SPAWN_GROUP_ID := 385; -- 14

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
(@CGUID+0,18412,532,0,0,1,1,0,0,-10908.856,-1773.627,90.55865,5.833214759826660156,604800,0,0,0,0,2,0,0,0,'',NULL,0),
(@CGUID+1,18412,532,0,0,1,1,0,0,-10910.791,-1771.2006,90.56122,0.364255577325820922,604800,0,0,0,0,0,0,0,0,'',NULL,0),
(@CGUID+2,18412,532,0,0,1,1,0,0,-10907.685,-1778.6509,90.56018,2.441269636154174804,604800,0,0,0,0,0,0,0,0,'',NULL,0),
(@CGUID+3,19525,532,0,0,1,1,0,0,-10895.269,-1782.6263,90.559845,3.769911,604800,0,0,0,0,0,0,0,0,'',NULL,15595),
(@CGUID+4,17603,532,0,0,1,1,0,0,-10893.254,-1756.5731,90.559845,4.485496,604800,0,0,0,0,0,0,0,0,'',NULL,15595),
(@CGUID+5,17547,532,0,0,1,1,0,1,-10883.841,-1758.8567,90.559845,4.537856101989746093,604800,0,0,0,0,0,0,0,0,'',NULL,24742),
(@CGUID+6,17543,532,0,0,1,1,0,0,-10902.105,-1756.45,90.559845,4.660028934478759765,604800,0,0,0,0,0,0,0,0,'',NULL,24742),
(@CGUID+7,17546,532,0,0,1,1,0,0,-10889.533,-1758.1,90.559845,4.572762489318847656,604800,0,0,0,0,0,0,0,0,'',NULL,24742),
(@CGUID+8,17535,532,0,0,1,1,0,0,-10896.65,-1757.6233,90.559845,4.86946868896484375,604800,0,0,0,0,0,0,0,0,'',NULL,24742),
(@CGUID+9,17534,532,0,0,1,1,0,1,-10893.56,-1760.437,90.559845,4.5553093,604800,0,0,0,0,0,0,0,0,'',NULL,15595),
(@CGUID+10,17521,532,0,0,1,1,0,0,-10893.109,-1756.247,90.55985,4.485496,604800,0,0,0,0,0,0,0,0,'',NULL,15595),
(@CGUID+11,18168,532,0,0,1,1,0,1,-10893.107,-1757.8502,90.559845,4.607669353485107421,604800,0,0,0,0,0,0,0,0,'',NULL,24742),
(@CGUID+12,17533,532,0,0,1,1,0,1,-10893.619,-1760.782,90.55985,4.764749,604800,0,0,0,0,0,0,0,0,'',NULL,15595);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+10;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Karazhan - Cyclone (The Crone)",4), -- 385
(@SPAWN_GROUP_ID+1,"Karazhan - Stage Spotlight",4), -- 386
(@SPAWN_GROUP_ID+2,"Karazhan - Grandmother",4), -- 387
(@SPAWN_GROUP_ID+3,"Karazhan - Tinhead",4), -- 388
(@SPAWN_GROUP_ID+4,"Karazhan - Strawman",4), -- 389
(@SPAWN_GROUP_ID+5,"Karazhan - Roar",4), -- 390
(@SPAWN_GROUP_ID+6,"Karazhan - Dorothee",4), -- 391
(@SPAWN_GROUP_ID+7,"Karazhan - Julianne",4), -- 392
(@SPAWN_GROUP_ID+8,"Karazhan - The Big Bad Wolf",4), -- 393
(@SPAWN_GROUP_ID+9,"Karazhan - The Crone",4), -- 394
(@SPAWN_GROUP_ID+10,"Karazhan - Romulo",4); -- 395

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+0 AND @CGUID+12 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,@CGUID+0),
(@SPAWN_GROUP_ID+0,0,@CGUID+1),
(@SPAWN_GROUP_ID+0,0,@CGUID+2),
(@SPAWN_GROUP_ID+1,0,@CGUID+3),
(@SPAWN_GROUP_ID+2,0,@CGUID+4),
(@SPAWN_GROUP_ID+3,0,@CGUID+5),
(@SPAWN_GROUP_ID+4,0,@CGUID+6),
(@SPAWN_GROUP_ID+5,0,@CGUID+7),
(@SPAWN_GROUP_ID+6,0,@CGUID+8),
(@SPAWN_GROUP_ID+7,0,@CGUID+9),
(@SPAWN_GROUP_ID+8,0,@CGUID+10),
(@SPAWN_GROUP_ID+9,0,@CGUID+11),
(@SPAWN_GROUP_ID+10,0,@CGUID+12);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+0;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+0,@CGUID+0,0,0,515,0,0),
(@CGUID+0,@CGUID+1,5,45,515,0,0),
(@CGUID+0,@CGUID+2,5,315,515,0,0);

DELETE FROM `waypoint_data` WHERE `id` = (@CGUID+0)*10;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
((@CGUID+0)*10,1,-10909.05,-1773.533,90.56085,NULL,0,0,0,100,0),
((@CGUID+0)*10,2,-10901.14,-1777.352,90.47656,NULL,0,0,0,100,0),
((@CGUID+0)*10,3,-10887.89,-1770.273,90.47697,NULL,0,0,0,100,0),
((@CGUID+0)*10,4,-10873.88,-1756.602,90.47607,NULL,0,0,0,100,0),
((@CGUID+0)*10,5,-10876.84,-1748.874,90.47689,NULL,0,0,0,100,0),
((@CGUID+0)*10,6,-10881.68,-1747.438,90.47687,NULL,0,0,0,100,0),
((@CGUID+0)*10,7,-10887.89,-1756.330,90.47715,NULL,0,0,0,100,0),
((@CGUID+0)*10,8,-10899.38,-1765.153,90.47734,NULL,0,0,0,100,0),
((@CGUID+0)*10,9,-10906.13,-1767.051,90.47772,NULL,0,0,0,100,0),
((@CGUID+0)*10,10,-10910.60,-1758.063,90.47652,NULL,0,0,0,100,0),
((@CGUID+0)*10,11,-10907.22,-1752.803,90.47632,NULL,0,0,0,100,0),
((@CGUID+0)*10,12,-10899.46,-1745.427,90.47615,NULL,0,0,0,100,0),
((@CGUID+0)*10,13,-10892.15,-1750.823,90.47671,NULL,0,0,0,100,0),
((@CGUID+0)*10,14,-10881.37,-1764.995,90.47661,NULL,0,0,0,100,0),
((@CGUID+0)*10,15,-10878.02,-1777.599,90.47767,NULL,0,0,0,100,0),
((@CGUID+0)*10,16,-10884.86,-1779.286,90.47733,NULL,0,0,0,100,0),
((@CGUID+0)*10,17,-10891.14,-1774.733,90.47724,NULL,0,0,0,100,0),
((@CGUID+0)*10,18,-10896.53,-1767.449,90.47691,NULL,0,0,0,100,0),
((@CGUID+0)*10,19,-10906.74,-1764.455,90.47702,NULL,0,0,0,100,0),
((@CGUID+0)*10,20,-10911.01,-1767.946,90.47708,NULL,0,0,0,100,0);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0,(@CGUID+0)*10,0,0,0,0,0,1,0,0,0,'');

-- Spawn groups, objects
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id` IN (183442,183496));
DELETE FROM `gameobject` WHERE `id` IN (183442,183496);
DELETE FROM `spawn_group` WHERE `spawnId` IN (24346,24381,24382,24383,24384) AND `spawnType` = 1;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0,183493,532,0,0,1,1,-10881.7421875,-1754.593505859375,90.4765167236328125,4.625123500823974609,0,0,-0.73727703094482421,0.67559051513671875,300,255,1,15595),
(@OGUID+1,183491,532,0,0,1,1,-10890.96484375,-1744.3236083984375,90.4765167236328125,4.607671737670898437,0,0,-0.74314403533935546,0.669131457805633544,300,255,1,15595),
(@OGUID+2,183492,532,0,0,1,1,-10909.7646484375,-1763.95166015625,90.47745513916015625,4.642575740814208984,0,0,-0.731353759765625,0.681998312473297119,300,255,1,15595),
(@OGUID+3,183492,532,0,0,1,1,-10903.2548828125,-1754.0880126953125,90.47650909423828125,4.555310726165771484,0,0,-0.76040554046630859,0.649448513984680175,300,255,1,15595),
(@OGUID+4,183492,532,0,0,1,1,-10875.8642578125,-1761.30419921875,90.4771270751953125,4.59021615982055664,0,0,-0.74895572662353515,0.662620067596435546,300,255,1,15595),

(@OGUID+5,183442,532,0,0,1,1,-10890.8798828125,-1744.0618896484375,90.47650909423828125,4.607671737670898437,0,0,-0.74314403533935546,0.669131457805633544,300,255,1,24742),
(@OGUID+6,183496,532,0,0,1,1,-10877.748046875,-1763.176025390625,90.47711181640625,4.59021615982055664,0,0,-0.74895572662353515,0.662620067596435546,300,255,1,24742),
(@OGUID+7,183496,532,0,0,1,1,-10909.4912109375,-1761.785888671875,90.47733306884765625,4.625123500823974609,0,0,-0.73727703094482421,0.67559051513671875,300,255,1,24742),
(@OGUID+8,183496,532,0,0,1,1,-10906.748046875,-1750.009033203125,90.4765472412109375,4.59021615982055664,0,0,-0.74895572662353515,0.662620067596435546,300,255,1,24742),
(@OGUID+9,183496,532,0,0,1,1,-10882.9970703125,-1751.80810546875,90.47650909423828125,4.555310726165771484,0,0,-0.76040554046630859,0.649448513984680175,300,255,1,24742),

(@OGUID+10,183443,532,0,0,1,1,-10891.0654296875,-1744.8685302734375,90.4765167236328125,4.607671737670898437,0,0,-0.74314403533935546,0.669131457805633544,300,255,1,15595),
(@OGUID+11,183494,532,0,0,1,1,-10900.513671875,-1748.7257080078125,110.1709518432617187,4.625123500823974609,0,0,-0.73727703094482421,0.67559051513671875,300,255,1,15595),
(@OGUID+12,183495,532,0,0,1,1,-10890.1640625,-1750.0433349609375,90.47650909423828125,4.625123500823974609,0,0,-0.73727703094482421,0.67559051513671875,300,255,1,15595);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+11 AND @SPAWN_GROUP_ID+13;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+11,"Karazhan - Red Riding Hood Decorations",4), -- 396
(@SPAWN_GROUP_ID+12,"Karazhan - Wizard of Oz Decorations",4), -- 397
(@SPAWN_GROUP_ID+13,"Karazhan - Romeo and Juliet Decorations",4); -- 398

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @OGUID+0 AND @OGUID+12 AND `spawnType` = 1;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+11,1,@OGUID+0),
(@SPAWN_GROUP_ID+11,1,@OGUID+1),
(@SPAWN_GROUP_ID+11,1,@OGUID+2),
(@SPAWN_GROUP_ID+11,1,@OGUID+3),
(@SPAWN_GROUP_ID+11,1,@OGUID+4),
(@SPAWN_GROUP_ID+12,1,@OGUID+5),
(@SPAWN_GROUP_ID+12,1,@OGUID+6),
(@SPAWN_GROUP_ID+12,1,@OGUID+7),
(@SPAWN_GROUP_ID+12,1,@OGUID+8),
(@SPAWN_GROUP_ID+12,1,@OGUID+9),
(@SPAWN_GROUP_ID+13,1,@OGUID+10),
(@SPAWN_GROUP_ID+13,1,@OGUID+11),
(@SPAWN_GROUP_ID+13,1,@OGUID+12);

-- Barnes
UPDATE `gameobject_template_addon` SET `flags` = 34 WHERE `entry` = 184275;

DELETE FROM `gossip_menu` WHERE `MenuID` = 7421 AND `TextID` IN (8969,8975,8981,8982);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7421,8969,15595),
(7421,8975,0),
(7421,8981,24742),
(7421,8982,0);

DELETE FROM `npc_text` WHERE `ID` = 8982;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `Probability0`, `BroadcastTextID0`) VALUES
(8982,"The romantic plays are really tough, but you'll do better this time. You have TALENT. Ready?","",0,1,14119);

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 7421 AND `OptionID` IN (1,2,3);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7421,1,0,"The wolf's going down.",14074,1,1,0,0,0,0,'',0,0),
(7421,2,0,"I'll nail it!",14120,1,1,0,0,0,0,'',0,24742),
(7421,3,0,"I've never been more ready.",14121,1,1,0,0,0,0,'',0,0);

DELETE FROM `creature_text` WHERE `CreatureID` = 16812;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16812,0,0,"Splendid. I'm going to get the audience ready. Break a leg!",12,0,100,0,0,0,14056,0,"Barnes SAY_BEGIN"),

(16812,1,0,"Good evening ladies and gentlemen, welcome to this evening's presentation!",14,0,100,0,0,9175,14057,0,"Barnes SAY_HOOD_1"),
(16812,2,0,"Tonight, things are not what they seem... for tonight your eyes may not be trusted!",14,0,100,0,0,9335,15359,0,"Barnes SAY_HOOD_2"),
(16812,3,0,"Take for instance this quiet elderly woman waiting for a visit from her granddaughter... surely there is nothing to fear from this sweet, gray-haired old lady!",14,0,100,0,0,9336,15360,0,"Barnes SAY_HOOD_3"),
(16812,4,0,"But don't let me pull the wool over your eyes! See for yourself what lies beneath those covers! And now... on with the show!",14,0,100,0,0,9337,15361,0,"Barnes SAY_HOOD_4"),

(16812,5,0,"Welcome ladies and gentlemen, to this evening's presentation!",14,0,100,0,0,9174,14118,0,"Barnes SAY_OZ_1"),
(16812,6,0,"Tonight we plumb the depths of the human soul as we join a lost, lonely girl trying desperately--with the help of her loyal companions--to find her way home!",14,0,100,0,0,9338,15362,0,"Barnes SAY_OZ_2"),
(16812,7,0,"But she is pursued... by a wicked, malevolent crone!",14,0,100,0,0,9339,15363,0,"Barnes SAY_OZ_3"),
(16812,8,0,"Will she survive? Will she prevail? Only time will tell. And now... on with the show!",14,0,100,0,0,9340,15364,0,"Barnes SAY_OZ_4"),

(16812,9,0,"Welcome ladies and gentlemen, to this evening's presentation!",14,0,100,0,0,9176,14122,0,"Barnes SAY_RAJ_1"),
(16812,10,0,"Tonight... we explore a tale of forbidden love!",14,0,100,0,0,9341,15365,0,"Barnes SAY_RAJ_2"),
(16812,11,0,"But beware, for not all love stories end happily, as you may find out. Sometimes, love pricks like a thorn!",14,0,100,0,0,9342,15366,0,"Barnes SAY_RAJ_3"),
(16812,12,0,"But don't take it from me; see for yourself what tragedy lies ahead when the paths of star crossed lovers meet! And now... on with the show!",14,0,100,0,0,9343,15367,0,"Barnes SAY_RAJ_4");

DELETE FROM `waypoint_data` WHERE `id` IN (134498,1358230,1358231);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(1358230,1,-10870.946,-1779.4125,90.48595,NULL,0,0,0,100,0),
(1358230,2,-10875.546,-1778.7738,90.47669,NULL,0,0,0,100,0),
(1358230,3,-10880.226,-1780.0681,90.477554,NULL,0,0,0,100,0),
(1358230,4,-10884.346,-1780.9225,90.47741,NULL,0,0,0,100,0),
(1358230,5,-10889.578,-1781.6733,90.476456,NULL,0,0,0,100,0),
(1358230,6,-10895.18,-1782.4739,90.47647,NULL,0,0,0,100,0),

(1358231,1,-10884.146,-1780.5691,90.47643,NULL,0,0,0,100,0),
(1358231,2,-10874.754,-1778.8278,90.47655,NULL,0,0,0,100,0),
(1358231,3,-10869.007,-1779.2379,90.47054,NULL,0,0,0,100,0),
(1358231,4,-10866.676,-1780.9473,90.461075,NULL,0,0,0,100,0);

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 16812);
UPDATE `creature_template_addon` SET `auras` = '28002' WHERE `entry` = 16812;

-- Hood
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71428571429, `unit_flags` = 33536 WHERE `entry` = 17603;
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.21428571429, `BaseAttackTime` = 1200, `ScriptName` = 'boss_big_bad_wolf' WHERE `entry` = 17521;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_opera_pick_red_riding_hood',
'spell_opera_little_red_riding_hood',
'spell_opera_picnic_basket_smell');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(30769, 'spell_opera_pick_red_riding_hood'),
(30768, 'spell_opera_little_red_riding_hood'),
(30755, 'spell_opera_picnic_basket_smell');

-- Oz
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71428571429 WHERE `entry` = 17547;
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71428571429 WHERE `entry` = 17543;
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71428571429 WHERE `entry` = 17546;
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71428571429 WHERE `entry` = 17535;
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71428571429 WHERE `entry` = 17548;
UPDATE `creature_template` SET `speed_walk` = 0.8, `speed_run` = 0.857143 WHERE `entry` = 18412;
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71428571429 WHERE `entry` = 18168;

UPDATE `creature_template_addon` SET `auras` = '31073' WHERE `entry` = 17543;
UPDATE `creature_template_addon` SET `auras` = '32339' WHERE `entry` = 18168;

DELETE FROM `spell_proc` WHERE `SpellId` = 31073;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(31073,4,0,0,0,0,0,0,0,0,2,0,0,0,0,0);

-- Romeo and Juliet
DELETE FROM `creature_text` WHERE `CreatureID` IN (17534,17533);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17534,0,0,"What devil art thou, that dost torment me thus?",14,0,100,0,0,9196,15070,0,"Julianne SAY_JULIANNE_AGGRO"),
(17534,1,0,"Romulo, I come! Oh... this do I drink to thee!",14,0,100,0,0,9198,15072,0,"Julianne SAY_JULIANNE_DEATH_1"),
(17534,2,0,"O happy dagger! This is thy sheath; there rust, and let me die!",14,0,100,0,0,9310,15074,0,"Julianne SAY_JULIANNE_DEATH_2"),
(17534,3,0,"Come, gentle night; and give me back my Romulo!",14,0,100,0,0,9200,15073,0,"Julianne SAY_JULIANNE_RESURRECT"),
(17534,4,0,"Parting is such sweet sorrow.",14,0,100,0,0,9201,15071,0,"Julianne SAY_JULIANNE_SLAY"),

(17533,0,0,"Wilt thou provoke me? Then have at thee, boy!",14,0,100,0,0,9233,15075,0,"Romulo SAY_ROMULO_AGGRO"),
(17533,1,0,"Thou smilest... upon the stroke that... murders me.",14,0,100,0,0,9235,15078,0,"Romulo SAY_ROMULO_DEATH"),
(17533,2,0,"Thou detestable maw, thou womb of death; I enforce thy rotten jaws to open!",14,0,100,0,0,9237,15077,0,"Romulo SAY_ROMULO_RESURRECT"),
(17533,3,0,"How well my comfort is revived by this!",14,0,100,0,0,9238,15076,0,"Romulo SAY_ROMULO_SLAY");

UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71428571429, `unit_flags` = 33088 WHERE `entry` = 17534;
