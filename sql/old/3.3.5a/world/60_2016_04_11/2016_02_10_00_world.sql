-- Pathing for Kalecgos Entry: 24844 'TDB FORMAT' 
SET @NPC := 24844;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,163.9735,-398.0906,2.083333,0,0,0,0,100,0), -- 16:16:43
(@PATH,2,164.3802,-397.1771,2.083333,0,0,0,0,100,0), -- 16:16:43
(@PATH,3,162.7923,-386.1964,15.67094,0,0,0,0,100,0), -- 16:16:43
(@PATH,4,151.5555,-345.349,5.92646,0,0,0,0,100,0), -- 16:16:43
(@PATH,5,162.2416,-299.8032,-5.436685,0,0,0,0,100,0), -- 16:16:43
(@PATH,6,199.7482,-272.3315,-7.186677,0,0,0,0,100,0), -- 16:16:43
(@PATH,7,199.7482,-272.3315,-7.186677,0,0,0,0,100,0), -- 16:16:43
(@PATH,8,199.7482,-272.3315,-7.186677,0.06981317,0,0,0,100,0); -- 16:16:54
-- 0x1C2F2C4920184300001F1D000038BF6E .go 163.9735 -398.0906 2.083333

DELETE FROM `creature_text` WHERE `entry` = 24844 AND `groupid` = 0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24844, 0, 0, 'Be still, mortals, and hearken to my words.', 14, 0, 100, 0, 0, 0, 23936, 3, 'Kalecgos - SAY_KALECGOS_SPAWN');
