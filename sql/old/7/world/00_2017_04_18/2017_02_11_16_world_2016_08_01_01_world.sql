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

DELETE FROM `creature_text` WHERE `entry`=23191 AND `groupid` IN (3,4);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23191,3,0,'I will not last much longer!',14,0,100,0,0,11385,21784,0,'Akama SAY_LOW_HEALTH'),
(23191,4,0,'No! Not yet!',14,0,100,0,0,11386,21785,0,'Akama SAY_DEAD');

-- Waypoints

-- Middle Creatures
SET @NPC := 12806;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=489.6115,`position_y`=407.0968,`position_z`=112.7839 WHERE `guid`=@NPC;
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid`=12805;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,489.6115,407.0968,112.7839,0,0,0,0,100,0),
(@PATH,2,521.2068,407.0993,112.7837,0,0,0,0,100,0);
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@NPC,@NPC ,0, 0,1,0,0),
(@NPC,12805,6,90,2,1,2);

-- Side Creatures
SET @NPC := 12780;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=528.3928,`position_y`=429.879,`position_z`=113.0337 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
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
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1, 501.718,381.9136,113.0337,0,0,0,0,100,0),
(@PATH,2, 507.699,369.5598,113.0337,0,0,0,0,100,0),
(@PATH,3,527.0941,372.4955,113.0337,0,0,0,0,100,0),
(@PATH,4, 507.699,369.5598,113.0337,0,0,0,0,100,0);

UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid` IN (12804,12814,12791,12807,12815,12793);
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (12780,12782);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(12780,12780,0,  0,1,0,0),
(12780,12804,5, 30,1,3,1),
(12780,12814,8, 45,1,3,1),
(12780,12791,5,315,1,3,1),
(12782,12782,0,  0,1,0,0),
(12782,12807,5,290,1,1,3),
(12782,12815,8,315,1,1,3),
(12782,12793,5, 45,1,1,3);
