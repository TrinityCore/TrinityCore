-- Unleash the Raptors (11147)
SET @EVENT         := 15363;
SET @RAPTOR        := 23741;
SET @QUEST_CREDIT  := 23727;

DELETE FROM `event_scripts` WHERE `id`= @EVENT;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@EVENT,0,8,@QUEST_CREDIT,1,0,0,0,0,0),
(@EVENT,0,10,@RAPTOR,600000,0,-2617.885,-3277.134,31.93436,0.541052),
(@EVENT,0,10,@RAPTOR,600000,0,-2621.778,-3275.271,30.62537,0.296706),
(@EVENT,0,10,@RAPTOR,600000,0,-2620.451,-3279.923,31.8134,0.296706),
(@EVENT,0,10,@RAPTOR,600000,0,-2482.963,-3240.589,40.96778,2.495821),
(@EVENT,0,10,@RAPTOR,600000,0,-2481.632,-3245.017,43.09342,2.583087),
(@EVENT,0,10,@RAPTOR,600000,0,-2479.413,-3239.004,40.06413,2.530727),
(@EVENT,0,10,@RAPTOR,600000,0,-2524.415,-3128.137,29.7597,0.3316126),
(@EVENT,0,10,@RAPTOR,600000,0,-2527.19,-3125.763,29.5518,0.3839724),
(@EVENT,0,10,@RAPTOR,600000,0,-2526.191,-3131.122,29.00879,0.2792527);

UPDATE `creature_template` SET AIName='SmartAI' WHERE entry=@RAPTOR;
DELETE FROM `smart_scripts` WHERE entryorguid IN (@RAPTOR);
INSERT INTO `smart_scripts` VALUES
(@RAPTOR,0,0,0,54,0,100,0,0,0,0,0,53,1,@RAPTOR,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Raptor - On Summon - Start WayPoint'),
(@RAPTOR,0,1,0,54,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Raptor - Summon - Aggresive'),
(@RAPTOR,0,2,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,0,0,0,0,0,0,0,'Captured Raptor - Summon - Attack Random Hostile'),
(@RAPTOR,0,3,0,1,0,100,1,60000,60000,60000,60000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Raptor - OOC 60 Secs - Despawn'),
(@RAPTOR,0,4,0,1,0,100,1,25000,25000,25000,25000,53,1,@RAPTOR,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Raptor - OOC 25 Secs - Start WayPoint');

DELETE FROM `waypoints` WHERE entry IN (@RAPTOR);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@RAPTOR,1,-2457.79, -3169.9, 35.109,'Captured Raptor'),
(@RAPTOR,2,-2446.18, -3176.67, 34.5238,'Captured Raptor'),
(@RAPTOR,3,-2436.55, -3170.93, 35.8081,'Captured Raptor'),
(@RAPTOR,4,-2428.23, -3146.74, 35.8573,'Captured Raptor'),
(@RAPTOR,5,-2444.57, -3138.12, 35.8598,'Captured Raptor'),
(@RAPTOR,6,-2457.32, -3146.25, 35.4215,'Captured Raptor'),
(@RAPTOR,7,-2468, -3161.3, 34.8617,'Captured Raptor');

-- Missing spell focus
DELETE FROM `gameobject` WHERE `id` = 124154;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES 
(146, 124154, 1, 1, 1, -2456.02, -3150.7, 35.8358, 4.69274, 0, 0, 0.714019, -0.700126, 300, 0, 1); -- 4.x changed

-- Missing gameobject template
DELETE FROM `gameobject_template` WHERE `entry`= 124154;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES 
(124154, 8, 1287, 'TEMP Blackhoof Village Windmill', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 1459, 10, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1);
-- Hack field
UPDATE `quest_template` SET `RequiredSpellCast1`=0 WHERE `Id`=11147;
