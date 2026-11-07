-- Pathing for Buin "Phloppy" Freehand Entry: 43352
SET @NPC := 43352;
SET @PATH := @NPC * 100;
DELETE FROM `waypoint_path` WHERE `PathId` IN (@PATH, @PATH+1);
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Buin "Phloppy" Freehand - Pickup sack'),
(@PATH+1,0,0,'Buin "Phloppy" Freehand - Put sack');

DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH, @PATH+1);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-5327.369,-1049.114,393.48065,NULL,0),
(@PATH,2,-5333.88,-1047.53,396.37463,NULL,0),
(@PATH,3,-5342.15,-1045.4,396.55692,NULL,0),
(@PATH,4,-5347.22,-1043.99,395.29846,NULL,0),
(@PATH,5,-5353.2,-1045.4,394.60522,NULL,0),
(@PATH,6,-5356.63,-1046.43,394.45398,NULL,0),
(@PATH,7,-5364.01,-1051.07,394.09357,NULL,0),
(@PATH,8,-5379.9785,-1051.9141,392.5756,NULL,0),
(@PATH,9,-5397.13,-1047.28,391.11234,NULL,0),
(@PATH,10,-5402.08,-1041.68,390.77133,NULL,0),
(@PATH,11,-5410.98,-1043.86,392.52325,NULL,0),
(@PATH,12,-5417.56,-1046.09,393.81155,NULL,0),
(@PATH+1,1,-5401.83,-1041.84,390.77032,NULL,0),
(@PATH+1,2,-5397.03,-1047.69,391.1369,NULL,0),
(@PATH+1,3,-5378.8,-1052.12,392.7226,NULL,0),
(@PATH+1,4,-5364.23,-1050.28,394.08246,NULL,0),
(@PATH+1,5,-5353.2383,-1045.4746,394.52502,NULL,0),
(@PATH+1,6,-5343.23,-1044.66,396.39218,NULL,0),
(@PATH+1,7,-5339.66,-1046.02,396.5569,NULL,0),
(@PATH+1,8,-5334.69,-1047.18,396.55695,NULL,0),
(@PATH+1,9,-5328.56,-1048.75,393.66238,NULL,0),
(@PATH+1,10,-5324.21,-1049.56,393.48068,NULL,0),
(@PATH+1,11,-5317.26,-1050.86,393.64874,NULL,0);

 -- Buin "Phloppy" Freehand smart ai
SET @ENTRY := 43352;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ENTRY * 100, @ENTRY * 100 + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(@ENTRY, 0, 1, 0, '', 58, 0, 100, 0, 12, @PATH, 0, 0, 80, 4335200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 12 of path ', @PATH, ' ended - Self: Start timed action list id #Buin "Phloppy" Freehand #0 (4335200) (update out of combat) // -inline')),
(@ENTRY * 100, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to STATE_USESTANDING (69)'),
(@ENTRY * 100, 9, 1, 0, '', 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ENTRY * 100, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 11, 81041, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell  Sack Carry State (81041) on Self'),
(@ENTRY * 100, 9, 3, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @PATH+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @PATH+1, ', walk, do not repeat, Passive')),
(@ENTRY, 0, 2, 0, '', 58, 0, 100, 0, 11, @PATH+1, 0, 0, 80, 4335201, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 11 of path ', @PATH+1, ' ended - Self: Start timed action list id #Buin "Phloppy" Freehand #1 (4335201) (update out of combat) // -inline')),
(@ENTRY * 100 + 1, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 81041, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  Sack Carry State (81041)'),
(@ENTRY * 100 + 1, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @PATH, ', walk, do not repeat, Passive'));

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=43352;

UPDATE `creature` SET `position_x`=-5317.26,`position_y`=-1050.86,`position_z`=393.64874 WHERE `guid`=306710;
