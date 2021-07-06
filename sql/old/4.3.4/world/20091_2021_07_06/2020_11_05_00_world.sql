--
DELETE FROM `creature_summon_groups` WHERE `summonerId`=22841; -- Shade of Akama
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(22841,0,1,23421,443.495,413.973,118.621,5.13127 ,6,6000),-- Ashtongue Channeler
(22841,0,1,23421,456.694,414.117,118.621,4.2586  ,6,6000),
(22841,0,1,23421,457.763,390.117,118.621,2.25148 ,6,6000),
(22841,0,1,23421,444.153,389.214,118.621,1.0821  ,6,6000),
(22841,0,1,23421,438.279,401.258,118.621,0.017453,6,6000),
(22841,0,1,23421,463.186,401.64 ,118.621,3.19395 ,6,6000),
(22841,0,1,23191,547.186,400.534,112.867,3.12414 ,8,   0); -- Akama

DELETE FROM `creature` WHERE `id` IN (23191,23421);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_shade_soul_channel_serverside','spell_shade_soul_channel');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40401,'spell_shade_soul_channel_serverside'),
(40520,'spell_shade_soul_channel');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40902;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,2,40902,0,1,31,0,3,22841,0,0,0,0,'','Effect_1 - Hits Shade of Akama'),
(13,4,40902,0,2,31,0,3,23351,0,0,0,0,'','Effect_2 - Hits Trigger');

UPDATE `creature_template` SET `mechanic_immune_mask`=618610687 WHERE `entry`=23215; -- Ashtongue Sorcerer Immunity
UPDATE `creature_template` SET `ScriptName`='npc_ashtongue_broken' WHERE `entry`=23319;
UPDATE `creature_template` SET `speed_run`=0.571429 WHERE `entry`=22841;

DELETE FROM `creature_text` WHERE `CreatureID`=23191 AND `groupid` IN (3,4);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23191,3,0,'I will not last much longer!',14,0,100,0,0,11385,21784,0,'Akama SAY_LOW_HEALTH'),
(23191,4,0,'No! Not yet!',14,0,100,0,0,11386,21785,0,'Akama SAY_DEAD');

-- Waypoints

-- Middle Creatures
SET @NPC := 12806;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=489.6115,`position_y`=407.0968,`position_z`=112.7839 WHERE `guid`=@NPC;
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid`=12805;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`waypointPathId`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,489.6115,407.0968,112.7839,0,0,0,0,100,0),
(@PATH,2,521.2068,407.0993,112.7837,0,0,0,0,100,0);
DELETE FROM `creature_formations` WHERE `LeaderGUID`=@NPC;
INSERT INTO `creature_formations` (`LeaderGUID`, `MemberGUID`, `FollowDistance`, `FollowAngle`, `GroupAI`, `InversionPoint1`, `InversionPoint2`) VALUES
(@NPC,@NPC ,0, 0,1,-1,-1),
(@NPC,12805,6,90,2,1,2);

-- Side Creatures
SET @NPC := 12780;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=528.3928,`position_y`=429.879,`position_z`=113.0337 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`waypointPathId`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,528.3928, 429.879,113.0337,0,0,0,0,100,0),
(@PATH,2, 506.946,432.0048,113.0337,0,0,0,0,100,0),
(@PATH,3,500.5693,414.4586,113.0338,0,0,0,0,100,0),
(@PATH,4, 506.946,432.0048,113.0337,0,0,0,0,100,0);

SET @NPC := 12782;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=516.83,`position_y`=368.9177,`position_z`=113.0337 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`waypointPathId`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1, 501.718,381.9136,113.0337,0,0,0,0,100,0),
(@PATH,2, 507.699,369.5598,113.0337,0,0,0,0,100,0),
(@PATH,3,527.0941,372.4955,113.0337,0,0,0,0,100,0),
(@PATH,4, 507.699,369.5598,113.0337,0,0,0,0,100,0);

UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid` IN (12804,12814,12791,12807,12815,12793);
DELETE FROM `creature_formations` WHERE `LeaderGUID` IN (12780,12782);
INSERT INTO `creature_formations` (`LeaderGUID`, `MemberGUID`, `FollowDistance`, `FollowAngle`, `GroupAI`, `InversionPoint1`, `InversionPoint2`) VALUES
(12780,12780,0,  0,1,-1,-1),
(12780,12804,5, 30,1,3,1),
(12780,12814,8, 45,1,3,1),
(12780,12791,5,315,1,3,1),
(12782,12782,0,  0,1,-1,-1),
(12782,12807,5,290,1,1,3),
(12782,12815,8,315,1,1,3),
(12782,12793,5, 45,1,1,3);

UPDATE `creature_template_addon` SET `auras`='39839' WHERE `entry`=22853;
UPDATE `creature_template_addon` SET `auras`='41191 34189' WHERE `entry`=23374;

-- Add Ashtongue Stalker's
SET @CGUID := 86283;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`) VALUES 
(@CGUID+0, 23374, 564, 656.2982, 387.9902, 112.7728, 2.478368, 7200, 0), -- 23374 (Area: 4009) (Auras: 41191 - 41191) (possible waypoints or random movement)
(@CGUID+1, 23374, 564, 707.5325, 352.4765, 125.2653, 1.32645, 7200, 0), -- 23374 (Area: 4009) (Auras: 41191 - 41191)
(@CGUID+2, 23374, 564, 769.7925, 370.5881, 112.8415, 0.6128875, 7200, 0), -- 23374 (Area: 4009) (Auras: 41191 - 41191)
(@CGUID+3, 23374, 564, 702.7503, 352.3887, 125.2664, 1.972222, 7200, 0), -- 23374 (Area: 4009) (Auras: 41191 - 41191)
(@CGUID+4, 23374, 564, 666.9014, 290.3525, 125.2559, 3.176499, 7200, 0), -- 23374 (Area: 4009) (Auras: 41191 - 41191)
(@CGUID+5, 23374, 564, 740.3699, 286.297, 125.2686, 5.113815, 7200, 0), -- 23374 (Area: 4009) (Auras: 41191 - 41191)
(@CGUID+6, 23374, 564, 669.1512, 286.5623, 125.2573, 4.24115, 7200, 0), -- 23374 (Area: 4009) (Auras: 41191 - 41191) (possible waypoints or random movement)
(@CGUID+7, 23374, 564, 742.5994, 290.4014, 125.2681, 0.05235988, 7200, 0), -- 23374 (Area: 4009) (Auras: 41191 - 41191)
(@CGUID+8, 23374, 564, 631.986, 251.5276, 112.749, 2.80998, 7200, 0); -- 23374 (Area: 0) (Auras: 41191 - 41191, 34189 - 34189)

DELETE FROM `creature_formations` WHERE `LeaderGUID`=12827;
INSERT INTO `creature_formations` (`LeaderGUID`, `MemberGUID`, `FollowDistance`, `FollowAngle`, `GroupAI`) VALUES
(12827, 12827, 0, 0, 2),
(12827, 12840, 10, 90, 2),
(12827, 12824, 10, 270, 2);

-- Pathing for Illidari Nightlord Entry: 22855 'TDB FORMAT' 
SET @NPC := 12827;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=797.9049,`position_y`=255.5211,`position_z`=113.0057 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`waypointPathId`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,797.9049,255.5211,113.0057,0,0,0,0,100,0), -- 21:33:21
(@PATH,2,799.5116,265.5505,112.9946,0,0,0,0,100,0), -- 21:34:44
(@PATH,3,799.6346,277.1103,112.9948,0,0,0,0,100,0), -- 21:33:26
(@PATH,4,799.4362,303.9547,113.0016,0,0,0,0,100,0), -- 21:33:31
(@PATH,5,799.0039,333.6956,113.0056,0,0,0,0,100,0), -- 21:34:33
(@PATH,6,799.1071,339.8928,113.0009,0,0,0,0,100,0), -- 21:33:37
(@PATH,7,798.9255,345.5464,113.0027,0,0,0,0,100,0), -- 21:33:42
(@PATH,8,798.3091,375.1995,112.9979,0,0,0,0,100,0), -- 21:33:47
(@PATH,9,796.5051,380.055,112.9991,0,0,0,0,100,0), -- 21:34:21
(@PATH,10,790.2986,393.373,113.0041,0,0,0,0,100,0), -- 21:33:49
(@PATH,11,788.781,396.0202,112.9945,0,0,0,0,100,0), -- 21:33:53
(@PATH,12,776.2429,410.9937,112.9996,0,0,0,0,100,0), -- 21:34:17
(@PATH,13,769.3853,414.8633,112.9868,0,0,0,0,100,0), -- 21:34:12
(@PATH,14,759.0627,420.3231,112.9865,0,0,0,0,100,0), -- 21:33:58
(@PATH,15,755.8228,421.9212,112.7266,0,0,0,0,100,0), -- 21:34:08
(@PATH,16,730.3083,422.5441,112.9883,0,0,0,0,100,0), -- 21:34:02
(@PATH,17,755.8228,421.9212,112.7266,0,0,0,0,100,0), -- 21:34:08
(@PATH,18,759.0627,420.3231,112.9865,0,0,0,0,100,0), -- 21:33:58
(@PATH,19,769.3853,414.8633,112.9868,0,0,0,0,100,0), -- 21:34:12
(@PATH,20,776.2429,410.9937,112.9996,0,0,0,0,100,0), -- 21:34:17
(@PATH,21,788.781,396.0202,112.9945,0,0,0,0,100,0), -- 21:33:53
(@PATH,22,790.2986,393.373,113.0041,0,0,0,0,100,0), -- 21:33:49
(@PATH,23,796.5051,380.055,112.9991,0,0,0,0,100,0), -- 21:34:21
(@PATH,24,798.2438,374.1577,112.9994,0,0,0,0,100,0), -- 21:34:25
(@PATH,25,798.8231,345.4242,112.9964,0,0,0,0,100,0), -- 21:34:28
(@PATH,26,799.1071,339.8928,113.0009,0,0,0,0,100,0), -- 21:33:37
(@PATH,27,799.0039,333.6956,113.0056,0,0,0,0,100,0), -- 21:34:33
(@PATH,28,799.4362,303.9547,113.0016,0,0,0,0,100,0), -- 21:33:31
(@PATH,29,799.7034,286.332,113.0002,0,0,0,0,100,0), -- 21:34:38
(@PATH,30,799.6346,277.1103,112.9948,0,0,0,0,100,0), -- 21:33:26
(@PATH,31,799.5116,265.5505,112.9946,0,0,0,0,100,0); -- 21:34:44
-- 0x1C16F446801651C0006A5B00009D4B4E .go 797.9049 255.5211 113.0057

DELETE FROM `creature_formations` WHERE `LeaderGUID`=12826;
INSERT INTO `creature_formations` (`LeaderGUID`, `MemberGUID`, `FollowDistance`, `FollowAngle`, `GroupAI`) VALUES
(12826, 12826, 0, 0, 2),
(12826, 12835, 10, 90, 2),
(12826, 12821, 10, 270, 2);

-- Pathing for Illidari Nightlord Entry: 22855 'TDB FORMAT' 
SET @NPC := 12826;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=671.0103,`position_y`=418.0573,`position_z`=112.9719 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`waypointPathId`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,671.0103,418.0573,112.9719,0,0,0,0,100,0), -- 21:30:49
(@PATH,2,664.3151,418.1411,112.9714,0,0,0,0,100,0), -- 21:30:58
(@PATH,3,643.6459,416.9381,112.9693,0,0,0,0,100,0), -- 21:32:19
(@PATH,4,633.8777,410.9504,112.9694,0,0,0,0,100,0), -- 21:31:04
(@PATH,5,625.0879,404.1424,112.968,0,0,0,0,100,0), -- 21:31:09
(@PATH,6,616.4854,383.6906,112.9617,0,0,0,0,100,0), -- 21:32:08
(@PATH,7,609.0042,357.2156,112.9686,0,0,0,0,100,0), -- 21:31:12
(@PATH,8,608.3771,346.3979,112.973,0,0,0,0,100,0), -- 21:32:05
(@PATH,9,608.604,340.5182,112.9734,0,0,0,0,100,0), -- 21:31:20
(@PATH,10,608.3019,334.7826,112.9586,0,0,0,0,100,0), -- 21:31:23
(@PATH,11,608.424,297.6053,112.9599,0,0,0,0,100,0), -- 21:31:49
(@PATH,12,607.9512,258.337,112.967,0,0,0,0,100,0), -- 21:31:29
(@PATH,13,614.2401,245.8512,112.9672,0,0,0,0,100,0), -- 21:31:39
(@PATH,14,608.4531,256.4178,112.9667,0,0,0,0,100,0), -- 21:31:45
(@PATH,15,608.424,297.6053,112.9599,0,0,0,0,100,0), -- 21:31:49
(@PATH,16,608.3019,334.7826,112.9586,0,0,0,0,100,0), -- 21:31:23
(@PATH,17,608.604,340.5182,112.9734,0,0,0,0,100,0), -- 21:31:20
(@PATH,18,608.3771,346.3979,112.973,0,0,0,0,100,0), -- 21:32:05
(@PATH,19,609.0042,357.2156,112.9686,0,0,0,0,100,0), -- 21:31:12
(@PATH,20,616.4854,383.6906,112.9617,0,0,0,0,100,0), -- 21:32:08
(@PATH,21,625.0543,404.2943,112.965,0,0,0,0,100,0), -- 21:32:16
(@PATH,22,633.8777,410.9504,112.9694,0,0,0,0,100,0), -- 21:31:04
(@PATH,23,643.6459,416.9381,112.9693,0,0,0,0,100,0), -- 21:32:19
(@PATH,24,664.3151,418.1411,112.9714,0,0,0,0,100,0); -- 21:30:58
-- 0x1C16F446801651C0006A5B00001D4B4E .go 671.0103 418.0573 112.9719

-- Disable PathFinding for High Warlord Naj'entus
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|536870912 WHERE `entry`=22887;

UPDATE `creature_addon` SET `auras`=19818 WHERE `guid`=40527;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_najentus_needle_spine';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39992,'spell_najentus_needle_spine');

DELETE FROM `creature_text` WHERE `CreatureID`=22887 AND (`GroupID` IN(5,6) OR (`GroupID`=4 AND `ID`=1));
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22887,4,1,'My patience has run out! Die! Die!',14,0,100,0,0,11458,21096,0,"High Warlord Naj'entus SAY_ENRAGE2"),
(22887,5,0,'Lord Illidan will... crush you!',14,0,100,0,0,11459,21093,0,"High Warlord Naj'entus SAY_DEATH");

UPDATE `creature_text` SET `Text`='Stick around...',`BroadcastTextId`=21089 WHERE `CreatureID`=22887 AND `GroupID`=1 AND `ID`=0;

-- Fixed speed for Supremus
UPDATE `creature_template` SET `speed_walk`=2.4, `speed_run`=2.14286 WHERE `entry`=22898;
-- Added unit_flag UNIT_FLAG_NOT_SELECTABLE in Supremus Volcano
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432 WHERE `entry`=23085;
-- Updated script name of creature Molten Flame
UPDATE `creature_template` SET `ScriptName`='npc_molten_flame' WHERE `entry`=23095;

-- Added aura Acidic Wound on Gurtogg Bloodboil
DELETE FROM `creature_addon` where `guid`=52761;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52761, 0, 0, 0, 0, 0, 40484);

-- SpellScripts
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gurtogg_bloodboil_insignificance';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40618, 'spell_gurtogg_bloodboil_insignificance');

-- Added creature script in Fel Geyser creature
UPDATE `creature_template` SET `ScriptName`='npc_fel_geyser' WHERE `entry`=23254;

-- Conditions for spell Taunt Gurtogg
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40603;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,3,40603,0,0,31,0,3,22948,0,0,0,0,'','Effect_0 and Effect_1 - Hits Gurtogg Bloodboil');

-- Fix Texts
UPDATE `creature_text` SET `Text`='I hunger.',`BroadcastTextId`=21744 WHERE `CreatureID`=22948 AND `GroupID`=2 AND `ID`=1;
DELETE FROM `creature_text` WHERE `CreatureID`=22948 AND `GroupID`IN(3,4);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22948,3,0,'I\'ll rip the meat from your bones!',14,0,100,0,0,11438,21745,0,'bloodboil SAY_ENRAGE');

DELETE FROM `creature_text` WHERE CreatureID=22984;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22984, 0, 0, 'You hear a loud rumble of metal grinding on stone...', 16, 0, 100, 0, 0, 0, 18600, 2, "Black Temple Trigger - when High Warlord Naj'entus dies - Emote"),
(22984, 1, 0, 'The door to The Den of Mortal Delights has opened.', 16, 0, 100, 0, 0, 0, 21494, 2, 'Black Temple Trigger - when Lower Temple Defeated - Emote');

-- Add missing spells to Ghost (Vengeful Spirit)
UPDATE `creature_template` SET `spell1`=40325, `spell3`=40157, `spell4`=40175, `spell5`=40314, `spell7`=40322 WHERE `entry`=23109;
-- Add missing auras in Shadowy Construct
DELETE FROM `creature_template_addon` WHERE `entry`=23111;
INSERT INTO `creature_template_addon` (`entry`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23111, 0, 0, 0, 0, 0, '40326 40334');

-- Teron Gorefiend texts
DELETE FROM `creature_text` where `CreatureID`= 22871;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22871, 0, 0, 'I was the first you know. For me the wheel of death has spun many times. So much time has passed... I have a lot of catching up to do.' , 14, 0, 100, 0, 0, 11512, 21098, 0, 'Teron Gorefiend SAY_INTRO'),
(22871, 1, 0, 'Vengeance is mine!', 14, 0, 100, 0, 0, 11513, 21097, 0, 'Teron Gorefiend SAY_AGGRO'),
(22871, 2, 0, 'I have use for you...', 14, 0, 100, 0, 0, 11514, 21099, 0, 'Teron Gorefiend SAY_SLAY1'),
(22871, 2, 1, 'It gets worse.', 14, 0, 100, 0, 0, 11515, 21100, 0, 'Teron Gorefiend SAY_SLAY2'),
(22871, 3, 0, 'What are you afraid of?', 14, 0, 100, 0, 0, 11517, 21102, 0, 'Teron Gorefiend SAY_INCINERATE1'),
(22871, 3, 1, 'You will show the proper respect!', 14, 0, 100, 0, 0, 11520, 21105, 0, 'Teron Gorefiend SAY_INCINERATE2'),
(22871, 4, 0, "Death really isn't so bad.", 14, 0, 100, 0, 0, 11516, 21101, 0, 'Teron Gorefiend SAY_DOOM_BLOSSOM1'),
(22871, 4, 1, 'I have something for you...', 14, 0, 100, 0, 0, 11519, 21104, 0, 'Teron Gorefiend SAY_DOOM_BLOSSOM2'),
(22871, 5, 0, 'Give in.', 14, 0, 100, 0, 0, 11518, 21103, 0, 'Teron Gorefiend SPELL_CRUSHING_SHADOWS'),
(22871, 6, 0, 'The wheel... spins... again.', 14, 0, 100, 0, 0, 11521, 21106, 0, 'Teron Gorefiend SAY_DEATH');

-- Area Trigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=4665;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4665,'at_teron_gorefiend_entrance');

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_teron_gorefiend_spiritual_vengeance','spell_teron_gorefiend_shadow_of_death','spell_teron_gorefiend_shadow_of_death_remove');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40268,'spell_teron_gorefiend_spiritual_vengeance'),
(40251,'spell_teron_gorefiend_shadow_of_death'),
(41999,'spell_teron_gorefiend_shadow_of_death_remove');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40268;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,3,40268,0,0,31,0,3,23109,0,0,0,0,'','Effect_0 and Effect_1 hits Vengeful Spirit');

UPDATE `creature_template` SET `AIName`='' WHERE `entry`=23472;

-- Condition for spell Fixate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=41295;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,41295,0,0,31,0,3,23418,0,0,0,0,'','Effect_0 hits Essence of Suffering');

DELETE FROM `creature_template_addon` WHERE `entry`=23418;
INSERT INTO `creature_template_addon` (`entry`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23418, 0, 0, 0, 1, 0,'41296 41623');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_reliquary_of_souls_aura_of_desire','spell_reliquary_of_souls_submerge','spell_reliquary_of_souls_spite','spell_soul_fragment_anger','spell_reliquary_of_souls_frenzy');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(41350,'spell_reliquary_of_souls_aura_of_desire'),
(28819,'spell_reliquary_of_souls_submerge'),
(41376,'spell_reliquary_of_souls_spite'),
(41986,'spell_soul_fragment_anger'),
(41305,'spell_reliquary_of_souls_frenzy');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-41376 AND`spell_effect`=41377 AND`type`=0;

UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=1126, `flags_extra`=0, `ScriptName`='npc_angered_soul_fragment' WHERE `entry`=23398;

DELETE FROM `spell_proc` WHERE `SpellId`=41350;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(41350, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x2, 0x0, 0x2, 0, 0, 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID`=23418;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23418,0,0,'Pain and suffering are all that await you!',14,0,100,0,0,11415,21759,0,'SUFF_SAY_AGRO'),
(23418,1,0,'Don\'t leave me alone!',14,0,100,0,0,11416,21760,0,'SUFF_SAY_SLAY'),
(23418,1,1,'Look at what you made me do!',14,0,100,0,0,11417,21761,0,'SUFF_SAY_SLAY2'),
(23418,1,2,'I didn\'t ask for this!',14,0,100,0,0,11418,21762,0,'SUFF_SAY_SLAY3'),
(23418,2,0,'The pain is only beginning...',14,0,100,0,0,11419,21763,0,'SUFF_SAY_ENRAGE'),
(23418,3,0,'I don\'t want to go back!',14,0,100,0,0,11420,21764,0,'SUFF_SAY_RECAP'),
(23418,4,0,'Now what do I do?',14,0,100,0,0,11421,21765,0,'SUFF_SAY_AFTER'),
(23418,5,0,'%s becomes enraged!',41,0,100,0,0,0,24144,0,'SUFF_EMOTE_ENRAGE');

DELETE FROM `creature_text` WHERE `CreatureID`=23419;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23419,0,0,'You can have anything you desire... for a price.',14,0,100,0,0,11408,21752,0,'DESI_SAY_FREED'),
(23419,1,0,'Fulfillment is at hand.',14,0,100,0,0,11409,21753,0,'DESI_SAY_SLAY1'),
(23419,1,1,'Yes, you\'ll stay with us now...',14,0,100,0,0,11410,21754,0,'DESI_SAY_SLAY2'),
(23419,1,2,'Your reach exceeds your grasp.',14,0,100,0,0,11412,21756,0,'DESI_SAY_SLAY3'),
(23419,2,0,'Be careful what you wish for.',14,0,100,0,0,11411,21755,0,'DESI_SAY_SPEC'),
(23419,3,0,'I won\'t be far!',14,0,100,0,0,11414,21758,0,'DESI_SAY_RECAP'),
(23419,4,0,'I\'ll be waiting.',14,0,100,0,0,11413,21757,0,'DESI_SAY_AFTER');

DELETE FROM `creature_text` WHERE `CreatureID`=23420;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23420,0,0,'Beware: I live!',14,0,100,0,0,11399,21746,0,'ANGER_SAY_FREED'),
(23420,1,0,'So... foolish.',14,0,100,0,0,11400,21747,0,'ANGER_SAY_FREED2'),
(23420,2,0,'Enough! No more!',14,0,100,0,0,11402,21748,0,'ANGER_SAY_SEETHE'),
(23420,3,0,'%s seethes in anger!',14,0,100,0,0,0,21878,0,'ANGER_EMOTE_SEETHE'),
(23420,4,0,'On your knees!',14,0,100,0,0,11403,21749,0,'ANGER_SAY_SPEC'),
(23420,5,0,'Beware, coward!',14,0,100,0,0,11405,21751,0,'ANGER_SAY_SPITE'),
(23420,6,0,'I won\'t... be... ignored!',14,0,100,0,0,11404,21750,0,'ANGER_SAY_DEATH');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_mother_shahraz_fatal_attraction',
'spell_mother_shahraz_fatal_attraction_link',
'spell_mother_shahraz_saber_lash',
'spell_mother_shahraz_generic_periodic',
'spell_mother_shahraz_random_periodic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40869,'spell_mother_shahraz_fatal_attraction'),
(40870,'spell_mother_shahraz_fatal_attraction_link'),
(40816,'spell_mother_shahraz_saber_lash'),
(40863,'spell_mother_shahraz_generic_periodic'),
(40865,'spell_mother_shahraz_generic_periodic'),
(40866,'spell_mother_shahraz_generic_periodic'),
(40862,'spell_mother_shahraz_generic_periodic'),
(40867,'spell_mother_shahraz_random_periodic');

DELETE FROM `creature_addon` WHERE `guid`=52760;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52760, 0, 0, 0, 0, 0, 40816);

DELETE FROM `creature_text` WHERE CreatureID=22947 AND `GroupID` IN(6,7);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22947, 6, 0, '%s goes into a frenzy!', 41, 0, 100, 0, 0, 0, 2384, 0, 'shahraz EMOTE_ENRAGE'),
(22947, 7, 0, '%s goes into a berserker rage!', 16, 0, 100, 0, 0, 0, 4428, 0, 'shahraz EMOTE_BERSERK');

DELETE FROM `creature_addon` WHERE guid IN(52480,52481);
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52480, 0, 0, 8, 1, 0, NULL),
(52481, 0, 0, 8, 1, 0, NULL);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_illidari_nightlord_shadow_inferno';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39645,'spell_illidari_nightlord_shadow_inferno');

DELETE FROM `creature` WHERE `id` IN(22952,22950,22949,22951);
DELETE FROM `creature_summon_groups` WHERE `summonerId`=23426; -- Illidari Council Trigger
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(23426,0,1,22952,697.495,310.651,277.527,3.1765 ,6,3600000), -- Veras Darkshadow
(23426,0,1,22950,700.792,307.192,277.526,3.14159,6,3600000), -- High Nethermancer Zerevor
(23426,0,1,22949,700.739,302.722,277.526,3.10669,6,3600000), -- Gathios the Shatterer
(23426,0,1,22951,697.409,299.377,277.526,3.07178,6,3600000); -- Lady Malande

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=41333; -- Empyreal Equivalency
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,41333,0,0,31,0,3,22950,0,0,0,0,'','Effect_0 hits High Nethermancer Zerevor'),
(13,1,41333,0,1,31,0,3,22949,0,0,0,0,'','Effect_0 hits Gathios the Shatterer'),
(13,1,41333,0,2,31,0,3,22951,0,0,0,0,'','Effect_0 hits Lady Malande'),
(13,1,41333,0,3,31,0,3,22952,0,0,0,0,'','Effect_0 hits Veras Darkshadow');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=41499; --  Empyreal Balance
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,41499,0,0,31,0,3,22950,0,0,0,0,'','Effect_0 hits High Nethermancer Zerevor'),
(13,1,41499,0,1,31,0,3,22949,0,0,0,0,'','Effect_0 hits Gathios the Shatterer'),
(13,1,41499,0,2,31,0,3,22951,0,0,0,0,'','Effect_0 hits Lady Malande'),
(13,1,41499,0,3,31,0,3,22952,0,0,0,0,'','Effect_0 hits Veras Darkshadow');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=41342; -- Shared Rule
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,41342,0,0,31,0,3,23426,0,0,0,0,'','Effect_0 hits The Illidari Council');

UPDATE `linked_respawn` SET `linkedGuid`=52479 WHERE `linkedGuid`=52762;

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128, `ScriptName`='npc_veras_vanish_effect' WHERE `entry`=23451;
UPDATE `creature_template` SET `ScriptName`='boss_illidari_council' WHERE `entry`=23426;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=23499;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN(
'spell_illidari_council_empyreal_balance',
'spell_illidari_council_empyreal_equivalency',
'spell_illidari_council_balance_of_power',
'spell_illidari_council_deadly_strike',
'spell_illidari_council_deadly_poison',
'spell_illidari_council_judgement',
'spell_illidari_council_seal',
'spell_boss_lady_malande_shield',
'spell_illidari_council_reflective_shield',
'spell_illidari_dampen_magic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(41499,'spell_illidari_council_empyreal_balance'),
(41333,'spell_illidari_council_empyreal_equivalency'),
(41341,'spell_illidari_council_balance_of_power'),
(41480,'spell_illidari_council_deadly_strike'),
(41485,'spell_illidari_council_deadly_poison'),
(41467,'spell_illidari_council_judgement'),
(41469,'spell_illidari_council_seal'),
(41459,'spell_illidari_council_seal'),
(41475,'spell_illidari_council_reflective_shield'),
(41478,'spell_illidari_dampen_magic');

DELETE FROM `creature_text` WHERE `CreatureID` IN(22951,22949,22950,22952) AND (`groupid` IN(3,4,5,6) OR (`groupid`=2 AND `id`=1));
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22949,2,1,'You are MINE!',14,0,100,0,0,11427,21739,0,'council gath SPECIAL2'),
(22949,3,0,'Selama am\'oronor!',14,0,100,0,0,11423,21735,0,'council gath SLAY'),
(22949,4,0,'Well done!',14,0,100,0,0,11424,21736,0,'council gath SLAY_COMT'),
(22949,5,0,'Lord Illidan, I...',14,0,100,0,0,11425,21737,0,'council gath DEATH'),
(22951,2,1,'I\'m full of surprises!',14,0,100,0,0,11487,21719,0,'council mala SPECIAL2'),
(22951,3,0,'My work is done.',14,0,100,0,0,11483,21712,0,'council mala SLAY'),
(22951,4,0,'As it should be.',14,0,100,0,0,11484,21713,0,'council mala SLAY_COMT'),
(22951,5,0,'Destiny... awaits.',14,0,100,0,0,11485,21715,0,'council mala DEATH'),
(22950,2,1,'Sha\'amoor ara mashal?',14,0,100,0,0,11445,21731,0,'council zere SPECIAL2'),
(22950,3,0,'Shorel\'aran.',14,0,100,0,0,11441,21725,0,'council zere SLAY'),
(22950,4,0,'Belesa menoor!',14,0,100,0,0,11442,21727,0,'council zere SLAY_COMT'),
(22950,5,0,'Diel ma\'ahn... orindel\'o.',14,0,100,0,0,11443,21729,0,'council zere DEATH'),
(22952,2,1,'Anar\'alah belore!',14,0,100,0,0,11529,21705,0,'council vera SPECIAL2'),
(22952,3,0,'Valiant effort.',14,0,100,0,0,11525,21699,0,'council vera SLAY'),
(22952,4,0,'A glorious kill!',14,0,100,0,0,11526,21701,0,'council vera SLAY_COMT'),
(22952,5,0,'You got... lucky.',14,0,100,0,0,11527,21703,0,'council vera DEATH');

DELETE FROM `gossip_menu` WHERE `MenuID`=8713;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(8713, 10960, 0),
(8713, 10835, 0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=8713 AND `OptionIndex`=1;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(8713, 1, 0, 'We\'re ready to face Illidan.', 20903, 1, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(14,15) AND `SourceGroup`=8713;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 8713, 10960, 0, 0, 13, 0, 10, 1, 0, 0, 0, 0, '', 'Show Gossip if Akama is in Intro State'),
(14, 8713, 10835, 0, 0, 13, 0, 10, 2, 0, 0, 0, 0, '', 'Show Gossip if Akama is in Waiting Fight State'),
(15, 8713, 0, 0, 0, 13, 0, 10, 1, 0, 0, 0, 0, '', 'Show Option if Akama in Intro State'),
(15, 8713, 1, 0, 0, 13, 0, 10, 2, 0, 0, 0, 0, '', 'Show Option if Akama is in Waiting Fight State');

-- Illidan Group Summon
DELETE FROM `creature` WHERE `guid`=12776;
DELETE FROM `creature_summon_groups` WHERE `summonerId`=22917;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(22917,0,1,23089,748.5206,236.6311,353.0794,2.373648,8,0); -- Akama

-- Akama Group Summon
DELETE FROM `creature_summon_groups` WHERE `summonerId`=23089;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(23089,0,1,23410,751.4565,311.0107,312.19,0,8,0), -- Spirit of Undalo
(23089,0,1,23411,751.6437,297.2233,312.2083,0,8,0); -- Spirit of Olum

UPDATE `creature_template` SET `scale`=1 WHERE `entry`=23412; -- Door Trigger
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=2, `unit_flags2`=2099200, `flags_extra`=`flags_extra` | 512 WHERE `entry`=22917; -- Illidan Stormrage
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=23336; -- Flame Crash
UPDATE `creature_template` SET `speed_walk`=0.35, `speed_run`=0.992063, `flags_extra`=128, `ScriptName`='npc_illidan_db_target' WHERE `entry`=23070;
UPDATE `creature_template` SET `speed_walk`=1.6, `speed_run`=0.571429 WHERE `entry`=23375; -- Shadow Demon
UPDATE `creature_template` SET `ScriptName`='npc_maiev' WHERE `entry`=23197;

UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=185916;
UPDATE `gameobject_template` SET `ScriptName`='' WHERE `entry`=185916;

-- Blaze SAI
SET @ENTRY := 23259;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blaze - On Reset - Set Reactstate Passive (No Repeat)"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,11,40610,2,0,0,0,0,1,0,0,0,0,0,0,0,"Blaze - On Reset - Cast 'Blaze'"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,11,40031,2,0,0,0,0,1,0,0,0,0,0,0,0,"Blaze - On Reset - Cast 'Birth - No Visual (Instant Spawn)'");

-- Cage Trap Trigger - 1 SAI
SET @ENTRY := 23292;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40704,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 1 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 2 SAI
SET @ENTRY := 23293;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40707,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 2 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 3 SAI
SET @ENTRY := 23294;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40708,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 3 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 4 SAI
SET @ENTRY := 23295;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40709,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 4 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 5 SAI
SET @ENTRY := 23296;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40710,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 5 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 6 SAI
SET @ENTRY := 23297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40711,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 6 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 7 SAI
SET @ENTRY := 23298;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40712,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 7 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 8 SAI
SET @ENTRY := 23299;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40713,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 8 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

DELETE FROM `creature_addon` WHERE `guid`=52484; -- Illidan
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52484, 0, 0, 256, 0, 0, '39656 43689');

DELETE FROM `creature_template_addon` WHERE `entry` IN(23069,23336,23498);
INSERT INTO `creature_template_addon` (`entry`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23069, 0, 0, 256, 0, 0, 40029),
(23336, 0, 0, 256, 0, 0, 40836),
(23498, 0, 0, 16908544, 0, 0, '34429 41913');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN(-41914,-41917); -- Remove Parasitic hack

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_illidan_akama_teleport',
'spell_illidan_akama_door_channel',
'spell_illidan_draw_soul',
'spell_illidan_parasitic_shadowfiend',
'spell_illidan_throw_warglaive',
'spell_illidan_tear_of_azzinoth_channel',
'spell_illidan_flame_blast',
'spell_illidan_return_glaives',
'spell_illidan_agonizing_flames',
'spell_illidan_demon_transform1',
'spell_illidan_demon_transform2',
'spell_illidan_flame_burst',
'spell_illidan_find_target',
'spell_illidan_eye_blast',
'spell_illidan_cage_trap',
'spell_illidan_caged',
'spell_maiev_down',
'spell_illidan_cage_teleport',
'spell_illidan_despawn_akama');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(41077,'spell_illidan_akama_teleport'),
(41268,'spell_illidan_akama_door_channel'),
(40904,'spell_illidan_draw_soul'),
(41917,'spell_illidan_parasitic_shadowfiend'),
(41914,'spell_illidan_parasitic_shadowfiend'),
(39635,'spell_illidan_throw_warglaive'),
(39849,'spell_illidan_throw_warglaive'),
(39857,'spell_illidan_tear_of_azzinoth_channel'),
(40631,'spell_illidan_flame_blast'),
(39873,'spell_illidan_return_glaives'),
(40834,'spell_illidan_agonizing_flames'),
(40511,'spell_illidan_demon_transform1'),
(40398,'spell_illidan_demon_transform2'),
(41126,'spell_illidan_flame_burst'),
(41081,'spell_illidan_find_target'),
(39908,'spell_illidan_eye_blast'),
(40761,'spell_illidan_cage_trap'),
(40760,'spell_illidan_caged'),
(40409,'spell_maiev_down'),
(40693,'spell_illidan_cage_teleport'),
(41242,'spell_illidan_despawn_akama');

DELETE FROM `creature_text` WHERE CreatureID IN(23089,23410,23411); -- Akama and Minions
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23089, 0, 0, 'This door is all that stands between us and the Betrayer.  Stand aside, friends.', 12, 0, 100, 1, 0, 0, 21563, 0, 'SAY_AKAMA_DOOR'),
(23089, 1, 0, 'I cannot do this alone...', 12, 0, 100, 274, 0, 0, 21548, 0, 'SAY_AKAMA_ALONE'),
(23089, 2, 0, 'I thank you for your aid, brothers.  Our people will be redeemed!', 12, 0, 100, 66, 0, 0, 21554, 0, 'SAY_AKAMA_SALUTE'),
(23089, 3, 0, 'Be wary, friends. The Betrayer meditates in the court just beyond.', 12, 0, 100, 0, 0, 11388, 21555, 0, 'SAY_AKAMA_BETRAYER'),
(23089, 4, 0, 'We\'ve come to end your reign, Illidan. My people, and all of Outland, shall be free!', 14, 0, 100, 25, 0, 11389, 20893, 0, 'SAY_AKAMA_FREE'),
(23089, 5, 0, 'The time has come! The moment is at hand!', 14, 0, 100, 22, 0, 11380, 20894, 0, 'SAY_AKAMA_TIME_HAS_COME'),
(23089, 6, 0, 'I will deal with these mongrels! Strike now, friends! Strike at the Betrayer!', 14, 0, 100, 22, 0, 11390, 21250, 0, 'SAY_AKAMA_MINIONS'),
(23089, 7, 0, 'The Light will bless these dismal halls once again.... I swear it.', 14, 0, 100, 1, 0, 11387, 21514, 0, 'SAY_AKAMA_LIGHT'),
(23089, 8, 0, 'Let us finish what we\'ve started.  I will lead you to Illidan\'s abode once you\'ve recovered your strength.', 12, 0, 100, 1, 0, 0, 21520, 0, 'SAY_AKAMA_FINISH'),
--  AKAMA MINIONS
(23410, 0, 0, 'You are not alone, Akama.', 12, 0, 100, 0, 0, 0, 21545, 0, 'SAY_SPIRIT_ALONE'), -- Spirit of Udalo
(23411, 0, 0, 'Your people will always be with you!', 12, 0, 100, 0, 0, 0, 21546, 0, 'SAY_SPIRIT_ALONE'); -- Spirit of Olum

DELETE FROM `creature_text` WHERE CreatureID=22917 AND `GroupID` IN(8,9,10,11,12,13,14); -- Illidan
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22917, 8, 0, 'Akama. Your duplicity is hardly surprising. I should have slaughtered you and your malformed brethren long ago.', 14, 0, 100, 6, 0, 11463, 20867, 0, 'Illidan SAY_ILLIDAN_DUPLICITY'),
(22917, 9, 0, 'Boldly said. But I remain... unconvinced.', 14, 0, 100, 6, 0, 11464, 20868, 0, 'Illidan SAY_ILLIDAN_UNCONVINCED'),
(22917, 10, 0, 'You are not prepared!', 14, 0, 100, 406, 0, 11466, 20884, 0, 'Illidan SAY_ILLIDAN_PREPARED'),
(22917, 11, 0, 'Is this it, mortals? Is this all the fury you can muster?', 14, 0, 100, 0, 0, 11476, 21068, 0, 'Illidan SAY_ILLIDAN_SHADOW_PRISON'),
(22917, 12, 0, 'Maiev... How is it even possible?', 14, 0, 100, 1, 0, 11477, 21069, 0, 'Illidan SAY_ILLIDAN_CONFRONT_MAIEV'),
(22917, 13, 0, 'Feel the hatred of ten thousand years!', 14, 0, 100, 0, 0, 11470, 21501, 0, 'Illidan SAY_ILLIDAN_FRENZY'),
(22917, 14, 0, 'You have won... Maiev. But the huntress... is nothing without the hunt. You... are nothing... without me.', 14, 0, 100, 0, 0, 11478, 21506, 0, 'Illidan SAY_ILLIDAN_DEFEATED');

DELETE FROM `creature_text` WHERE CreatureID=23197 AND ((`GroupID` IN(1,2,3,4,5,6,7)) OR (`GroupID`=0 AND ID=2)); -- Maiev
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23197, 1, 0, 'Their fury pales before mine, Illidan. We have some unsettled business between us.', 14, 0, 100, 6, 0, 11491, 21070, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_APPEAR'),
(23197, 2, 0, 'My long hunt is finally over. Today, Justice will be done!', 14, 0, 100, 5, 0, 11492, 21071, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_JUSTICE'),
(23197, 3, 0, 'There shall be no prison for you this time!', 14, 0, 100, 0, 0, 11495, 22208, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_TRAP'),
(23197, 4, 0, '%s falls to the floor.', 16, 0, 100, 0, 0, 0, 21317, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_DOWN'),
(23197, 5, 0, 'It is finished. You are beaten.', 14, 0, 100, 0, 0, 11496, 21507, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_FINISHED'),
(23197, 6, 0, 'He\'s right. I feel nothing... I am... nothing.', 14, 0, 100, 0, 0, 11497, 21508, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_OUTRO'),
(23197, 7, 0, 'Farewell, champions.', 14, 0, 100, 0, 0, 11498, 21509, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_FAREWELL');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(40704,40707,40708,40709,40710,40711,40712,40713); -- Caged (Visual)
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,40704,0,0,31,0,3,23296,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 5'),
(13,1,40707,0,0,31,0,3,23297,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 6'),
(13,1,40708,0,0,31,0,3,23298,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 7'),
(13,1,40709,0,0,31,0,3,23299,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 8'),
(13,1,40710,0,0,31,0,3,23292,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 1'),
(13,1,40711,0,0,31,0,3,23293,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 2'),
(13,1,40712,0,0,31,0,3,23294,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 3'),
(13,1,40713,0,0,31,0,3,23295,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 4');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(39849,39635); -- Throw Glaive
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,39849,0,0,31,0,3,23448,52503,0,0,0,'','Effect_0 hits Glaive Target'),
(13,1,39635,0,0,31,0,3,23448,52502,0,0,0,'','Effect_0 hits Glaive Target');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=39873; -- Return Glaive
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,39873,0,0,31,0,3,22917,0,0,0,0,'','Effect_0 hits Illidan Stormrage');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40761; -- Cage Trap
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,40761,0,0,31,0,3,22917,0,0,0,0,'','Effect_0 hits Illidan Stormrage');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40693; -- Cage Trap Teleport
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,40693,0,0,31,0,3,23197,0,0,0,0,'','Effect_0 hits Maiev Shadowsong');

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 1, 0, 3297, 2391),
(23089, 1, 1, 2744, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 1, 0, 0, 609.77200, 308.45600, 271.82600),
(23089, 1, 0, 1, 610.93130, 308.29240, 272.00720),
(23089, 1, 0, 2, 625.68130, 307.04240, 271.75720),
(23089, 1, 0, 3, 628.43130, 307.04240, 271.75720),
(23089, 1, 0, 4, 630.18130, 307.04240, 271.75720),
(23089, 1, 0, 5, 631.68130, 306.79240, 271.75720),
(23089, 1, 0, 6, 642.59050, 305.62870, 271.68840),
(23089, 1, 1, 0, 633.37040, 306.42300, 271.66000),
(23089, 1, 1, 1, 642.81750, 305.84460, 271.93120),
(23089, 1, 1, 2, 660.76460, 305.76630, 271.70240);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=2;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 2, 0, 5077, 3297),
(23089, 2, 1, 5259, 3656),
(23089, 2, 2, 4364, 3640),
(23089, 2, 3, 3825, 2422),
(23089, 2, 4, 3466, 2422),
(23089, 2, 5, 2911, 1235),
(23089, 2, 6, 2798, 1203),
(23089, 2, 7, 2172, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=2;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 2, 0, 0, 660.76460, 305.76630, 271.70240),
(23089, 2, 0, 1, 664.95350, 321.87480, 271.94820),
(23089, 2, 0, 2, 665.70350, 324.87480, 271.94820),
(23089, 2, 0, 3, 673.14240, 354.98330, 271.69400),
(23089, 2, 1, 0, 668.70380, 337.33420, 271.68930),
(23089, 2, 1, 1, 673.44130, 355.17200, 271.79190),
(23089, 2, 1, 2, 680.94130, 363.17200, 271.79190),
(23089, 2, 1, 3, 681.94130, 363.92200, 271.79190),
(23089, 2, 1, 4, 691.69130, 374.67200, 271.79190),
(23089, 2, 1, 5, 694.19130, 377.42200, 271.79190),
(23089, 2, 1, 6, 696.67880, 380.00980, 271.89450),
(23089, 2, 2, 0, 685.40080, 368.01770, 271.67940),
(23089, 2, 2, 1, 691.88500, 374.69560, 272.08730),
(23089, 2, 2, 2, 694.38500, 377.19560, 272.08730),
(23089, 2, 2, 3, 696.88500, 379.94560, 272.33730),
(23089, 2, 2, 4, 699.38500, 379.44560, 272.33730),
(23089, 2, 2, 5, 704.13500, 378.44560, 274.58730),
(23089, 2, 2, 6, 714.88500, 375.94560, 277.83730),
(23089, 2, 2, 7, 719.63500, 374.69560, 280.08730),
(23089, 2, 2, 8, 721.36930, 374.37350, 280.99510),
(23089, 2, 3, 0, 715.07500, 375.81030, 277.75200),
(23089, 2, 3, 1, 719.93350, 374.65850, 280.34520),
(23089, 2, 3, 2, 721.68350, 374.40850, 281.34520),
(23089, 2, 3, 3, 725.93350, 368.15850, 284.84520),
(23089, 2, 3, 4, 728.18350, 364.65850, 287.84520),
(23089, 2, 3, 5, 732.68350, 358.65850, 291.84520),
(23089, 2, 3, 6, 736.79190, 352.50670, 296.43850),
(23089, 2, 4, 0, 729.85970, 362.33540, 289.17460),
(23089, 2, 4, 1, 732.96180, 358.54080, 292.23680),
(23089, 2, 4, 2, 736.96180, 352.54080, 296.73680),
(23089, 2, 4, 3, 737.71180, 350.79080, 297.73680),
(23089, 2, 4, 4, 741.71180, 344.04080, 301.73680),
(23089, 2, 4, 5, 745.56390, 336.74620, 306.29910),
(23089, 2, 5, 0, 741.17650, 344.62910, 301.12160),
(23089, 2, 5, 1, 741.90870, 343.92740, 301.90360),
(23089, 2, 5, 2, 745.65870, 336.67740, 306.40360),
(23089, 2, 5, 3, 747.65870, 326.42740, 309.40360),
(23089, 2, 5, 4, 749.14090, 319.22560, 311.68560),
(23089, 2, 6, 0, 745.88320, 335.18240, 306.71790),
(23089, 2, 6, 1, 747.93570, 326.16000, 309.39880),
(23089, 2, 6, 2, 749.18570, 319.41000, 311.89880),
(23089, 2, 6, 3, 749.43570, 318.41000, 312.39880),
(23089, 2, 6, 4, 751.48830, 308.63760, 312.07980),
(23089, 2, 7, 0, 748.24830, 323.59770, 310.07210),
(23089, 2, 7, 1, 749.51420, 319.24910, 311.87080),
(23089, 2, 7, 2, 749.76420, 317.99910, 312.37080),
(23089, 2, 7, 3, 751.76420, 308.99910, 312.37080),
(23089, 2, 7, 4, 755.51420, 304.99910, 312.37080),
(23089, 2, 7, 5, 755.78010, 304.40060, 312.16960);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=3;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 3, 0, 4686, 3640),
(23089, 3, 1, 3261, 2453),
(23089, 3, 2, 3415, 2438),
(23089, 3, 3, 4631, 3641),
(23089, 3, 4, 2627, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=3;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 3, 0, 0, 755.78010, 304.40060, 312.16960),
(23089, 3, 0, 1, 759.85900, 303.60590, 312.72120),
(23089, 3, 0, 2, 770.35900, 301.10590, 312.72120),
(23089, 3, 0, 3, 779.60900, 299.10590, 319.97120),
(23089, 3, 0, 4, 781.35900, 298.60590, 319.97120),
(23089, 3, 0, 5, 786.35900, 297.60590, 319.97120),
(23089, 3, 0, 6, 787.35900, 297.35590, 319.97120),
(23089, 3, 0, 7, 798.93790, 294.31120, 319.77270),
(23089, 3, 1, 0, 788.57950, 296.73280, 319.76110),
(23089, 3, 1, 1, 799.06010, 294.20360, 320.06920),
(23089, 3, 1, 2, 798.56010, 289.20360, 320.31920),
(23089, 3, 1, 3, 797.54060, 276.17450, 330.37730),
(23089, 3, 2, 0, 798.04160, 282.67720, 325.05990),
(23089, 3, 2, 1, 797.59280, 276.20070, 330.76180),
(23089, 3, 2, 2, 795.34280, 262.95070, 341.51180),
(23089, 3, 2, 3, 794.59280, 258.70070, 341.51180),
(23089, 3, 2, 4, 793.64410, 254.72420, 341.46370),
(23089, 3, 3, 0, 795.28610, 263.76330, 340.53130),
(23089, 3, 3, 1, 795.05350, 262.63820, 341.82590),
(23089, 3, 3, 2, 794.30350, 258.38820, 341.82590),
(23089, 3, 3, 3, 793.55350, 254.63820, 341.82590),
(23089, 3, 3, 4, 792.55350, 254.13820, 341.82590),
(23089, 3, 3, 5, 787.80350, 251.38820, 341.82590),
(23089, 3, 3, 6, 783.55350, 249.13820, 341.82590),
(23089, 3, 3, 7, 773.05350, 242.88820, 349.07590),
(23089, 3, 3, 8, 766.30350, 238.88820, 353.82590),
(23089, 3, 3, 9, 764.82070, 238.01300, 353.62060),
(23089, 3, 4, 0, 772.12710, 242.24910, 349.37410),
(23089, 3, 4, 1, 766.03170, 239.02710, 353.95420),
(23089, 3, 4, 2, 764.78170, 238.27710, 353.70420),
(23089, 3, 4, 3, 760.28170, 237.77710, 353.45420),
(23089, 3, 4, 4, 750.28170, 236.27710, 353.20420),
(23089, 3, 4, 5, 748.43620, 235.80510, 353.03430);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=4;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 4, 0, 6925, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=4;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 4, 0, 0, 748.43620, 235.80510, 353.03430),
(23089, 4, 0, 1, 747.83060, 249.37560, 353.26520),
(23089, 4, 0, 2, 747.58060, 252.87560, 353.26520),
(23089, 4, 0, 3, 747.33060, 257.37560, 353.26520),
(23089, 4, 0, 4, 747.33060, 260.87560, 353.26520),
(23089, 4, 0, 5, 746.83060, 277.12560, 353.26520),
(23089, 4, 0, 6, 746.08060, 293.12560, 353.26520),
(23089, 4, 0, 7, 745.58060, 302.87560, 353.26520),
(23089, 4, 0, 8, 745.22500, 304.94600, 352.99600);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=5;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 5, 0, 5893, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=5;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 5, 0, 0, 745.22500, 304.94600, 352.99600),
(23089, 5, 0, 1, 744.74730, 320.38350, 353.25160),
(23089, 5, 0, 2, 744.49730, 331.88350, 353.25160),
(23089, 5, 0, 3, 744.49730, 348.38350, 353.25160),
(23089, 5, 0, 4, 744.24730, 349.63350, 353.25160),
(23089, 5, 0, 5, 744.24730, 352.13350, 353.25160),
(23089, 5, 0, 6, 743.99730, 362.63350, 353.25160),
(23089, 5, 0, 7, 743.76950, 363.82110, 353.00730);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=6;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 6, 0, 9319, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=6;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 6, 0, 0, 752.27710, 369.94010, 353.15840),
(23089, 6, 0, 1, 753.94520, 368.68850, 353.20910),
(23089, 6, 0, 2, 762.69520, 361.68850, 353.70910),
(23089, 6, 0, 3, 763.94520, 360.68850, 353.95910),
(23089, 6, 0, 4, 764.94520, 359.68850, 352.95910),
(23089, 6, 0, 5, 780.19520, 347.18850, 341.70910),
(23089, 6, 0, 6, 780.44520, 346.68850, 341.70910),
(23089, 6, 0, 7, 792.19520, 320.18850, 320.20910),
(23089, 6, 0, 8, 794.69520, 314.93850, 320.20910),
(23089, 6, 0, 9, 796.19520, 311.43850, 320.20910),
(23089, 6, 0, 10, 799.11330, 304.43700, 319.75990);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=7;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 7, 0, 4704, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=7;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 7, 0, 0, 753.04650, 369.30210, 353.12700),
(23089, 7, 0, 1, 751.76920, 369.24790, 353.31160),
(23089, 7, 0, 2, 739.51920, 368.74790, 353.06160),
(23089, 7, 0, 3, 723.26920, 367.99790, 353.06160),
(23089, 7, 0, 4, 722.76920, 367.49790, 353.06160),
(23089, 7, 0, 5, 715.76920, 369.49790, 353.06160),
(23089, 7, 0, 6, 714.51920, 368.24790, 353.06160);

DELETE FROM `gameobject` WHERE guid=44;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(44, 185966, 564, 3959, 3959, 1, 1, 706.406006, 302.182373, 353.743744, 0.157961, 0, 0, 0, 0, 7200, 0, 1);

UPDATE `creature_template` SET `ScriptName`='npc_illidari_elite' WHERE `entry`=23226;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_illidan_remove_parasitic_shadowfiend';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(41923,'spell_illidan_remove_parasitic_shadowfiend');

-- DELETE FROM `spell_dbc` WHERE `Id`=41923;
-- INSERT INTO `spell_dbc` (`Id`,`Dispel`,`Mechanic`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`AttributesEx6`,`AttributesEx7`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectItemType1`,`EffectItemType2`,`EffectItemType3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectMiscValueB1`,`EffectMiscValueB2`,`EffectMiscValueB3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`EffectSpellClassMaskA1`,`EffectSpellClassMaskA2`,`EffectSpellClassMaskA3`,`EffectSpellClassMaskB1`,`EffectSpellClassMaskB2`,`EffectSpellClassMaskB3`,`EffectSpellClassMaskC1`,`EffectSpellClassMaskC2`,`EffectSpellClassMaskC3`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`SpellFamilyFlags3`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`DmgMultiplier1`,`DmgMultiplier2`,`DmgMultiplier3`,`AreaGroupId`,`SchoolMask`,`Comment`) VALUES
-- (41923,0,0,536871296,268435592,4,256,0,8,0,0,0,0,0,1,0,0,0,0,0,0,0,27,1,0,-1,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,22,0,0,15,0,0,28,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,'Remove Parasitic Shadowfiends');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160109;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectAura`, `EffectRadiusIndex`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `SpellID`, `EffectIndex`, `Comment`) VALUES
(160109, 6, 4, 28, 22, 15, 41923, 0, '');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_illidari_council_vanish');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(41476,'spell_illidari_council_vanish');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_illidan_parasitic_shadowfiend_proc';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(41913,'spell_illidan_parasitic_shadowfiend_proc');

-- 
DELETE FROM `creature` WHERE `id`  IN (22934) AND `guid`=107033;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(107033, 22934, 530, 1, 1, -3565.66, 499.164, 20.2467, 2.54818, 120, 0, 0);

-- Reliquary of Souls Combat Trigger
UPDATE `creature_template` SET `flags_extra`=`flags_extra`&~128, `ScriptName` = 'npc_reliquary_combat_trigger' WHERE `entry`=23417;

UPDATE `creature_template` SET `ScriptName`= 'npc_illidan_generic_fire' WHERE `entry`= 23069;

--
DELETE FROM `conditions` WHERE `SourceEntry`= 40647 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 4, 40647, 0, 0, 31, 0, 3, 23089, 0, 0, 0, '', 'Shadow Prison - Target Akama');
