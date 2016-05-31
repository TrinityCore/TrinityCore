-- Pathing for Anub'ar Warrior Entry: 28732 'TDB FORMAT'
SET @NPC := 127230;
SET @NPC1 := 127339;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=536.2838,`position_y`=747.2582,`position_z`=790.701 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=534.9068,`position_y`=742.6521,`position_z`=789.386 WHERE `guid`=@NPC1;
DELETE FROM `creature_addon` WHERE `guid` IN (@NPC,@NPC1);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, ''),(@NPC1,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,536.2838,747.2582,790.701,0,0,0,0,100,0),
(@PATH,2,553.5668,733.7203,777.5034,0,0,0,0,100,0),
(@PATH,3,536.2838,747.2582,790.701,0,0,0,0,100,0),
(@PATH,4,507.5956,755.1626,808.8735,0,0,0,0,100,0),
(@PATH,5,488.8975,758.9921,818.0986,0,0,0,0,100,0),
(@PATH,6,507.5956,755.1626,808.8735,0,0,0,0,100,0);
 
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@NPC);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,2,0,0),
(@NPC,@NPC1,4,90,2,2,5);
