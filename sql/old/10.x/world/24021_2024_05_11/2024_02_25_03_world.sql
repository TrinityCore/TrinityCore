-- Pathing for Golorn Frostbeard Entry: 1692
SET @NPC := 1692;
SET @PATH := @NPC * 100;

-- UPDATE `creature_template` SET `flags_extra`=536870912 WHERE `entry`=1692; -- disable pathfinding as it adversely affects path

DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Golorn Frostbeard - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,0,-5636.061,-495.83292,396.67853,NULL,0),
(@PATH,1,-5640.068,-496.73785,396.66605,NULL,0),
(@PATH,2,-5641.3994,-498.89606,396.66736,NULL,0),
(@PATH,3,-5640.8315,-501.3918,396.66876,NULL,19000), -- sniffed 17s to 20s on official
(@PATH,4,-5641.3994,-498.89606,396.66736,NULL,0),
(@PATH,5,-5640.068,-496.73785,396.66605,NULL,0),
(@PATH,6,-5636.061,-495.83292,396.67853,NULL,0),
(@PATH,8,-5633.44,-496.477,396.69183,2.199115,35000); -- sniffed 30s to 40s on offical

UPDATE `creature` SET `MovementType`=2 WHERE `guid`=306365;

DELETE FROM `creature_addon` WHERE `guid`=306365;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES 
(306365,@PATH,0,0,1,0,0, '');
