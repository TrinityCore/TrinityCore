DELETE FROM `creature` WHERE `guid` IN (349907,309225,308824,308876,308904,308926,309201,309039,308889,308919,308647,308825,309010,309012,309240);
DELETE FROM `creature_addon` WHERE `guid` IN (349907,309225,308824,308876,308904,308926,309201,309039,308889,308919,308647,308825,309010,309012,309240);

-- Echo Isles Quest Bunny, Spitescale Flag Bunny
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (38003,38560);

DELETE FROM `quest_template_addon` WHERE `ID`=25073;
INSERT INTO `quest_template_addon` (`ID`,`PrevQuestID`) VALUES (25073,38966);

-- Remove duplicate gossip option
DELETE FROM `gossip_menu_option` WHERE `MenuId`=10974 AND `OptionIndex`=0;

-- Condition for source Gossip menu option condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10974 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10974, 1, 0, 1, 9, 0, 24642, 0, 0, 0, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has been taken.'),
(15, 10974, 1, 0, 1, 8, 0, 24642, 0, 0, 1, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has not been rewarded.'),
(15, 10974, 1, 0, 2, 9, 0, 24754, 0, 0, 0, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has been taken.'),
(15, 10974, 1, 0, 2, 8, 0, 24754, 0, 0, 1, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has not been rewarded.'),
(15, 10974, 1, 0, 3, 9, 0, 24762, 0, 0, 0, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has been taken.'),
(15, 10974, 1, 0, 3, 8, 0, 24762, 0, 0, 1, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has not been rewarded.'),
(15, 10974, 1, 0, 4, 9, 0, 24768, 0, 0, 0, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has been taken.'),
(15, 10974, 1, 0, 4, 8, 0, 24768, 0, 0, 1, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has not been rewarded.'),
(15, 10974, 1, 0, 5, 9, 0, 24774, 0, 0, 0, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has been taken.'),
(15, 10974, 1, 0, 5, 8, 0, 24774, 0, 0, 1, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has not been rewarded.'),
(15, 10974, 1, 0, 6, 9, 0, 24780, 0, 0, 0, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has been taken.'),
(15, 10974, 1, 0, 6, 8, 0, 24780, 0, 0, 1, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has not been rewarded.'),
(15, 10974, 1, 0, 7, 9, 0, 24786, 0, 0, 0, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has been taken.'),
(15, 10974, 1, 0, 7, 8, 0, 24786, 0, 0, 1, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has not been rewarded.'),
(15, 10974, 1, 0, 8, 9, 0, 26276, 0, 0, 0, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has been taken.'),
(15, 10974, 1, 0, 8, 8, 0, 26276, 0, 0, 1, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has not been rewarded.');

-- Pathing for Morakki <Captain of the Watch> Entry: 38442
SET @NPC := 309061;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1253.396,`position_y`=-5542.613,`position_z`=19.13959 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,65536,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1253.396,-5542.613,19.13959,0,0,0,0,100,0),
(@PATH,2,-1253.396,-5542.613,19.13959,0.05235988,35000,0,0,100,0),
(@PATH,3,-1277.457,-5553.068,20.98919,0,0,0,0,100,0),
(@PATH,4,-1286.646,-5549.514,20.98919,0,0,0,0,100,0),
(@PATH,5,-1290.415,-5537.613,20.86419,0,0,0,0,100,0),
(@PATH,6,-1302.569,-5523.547,20.00925,0,35000,0,0,100,0),
(@PATH,7,-1286.477,-5550.003,20.98919,0,0,0,0,100,0),
(@PATH,8,-1273.783,-5551.601,20.98919,0,0,0,0,100,0),
(@PATH,9,-1261.026,-5544.897,20.41034,0,0,0,0,100,0);
-- 0x202F400020258A80004BBE00006EE8BD .go xyz -1253.396 -5542.613 19.13959

-- Fix Quest Proving Pit
DELETE FROM `creature_queststarter` WHERE `quest` IN (24642,24754,24762,24768,24774,24780,24786,26276);
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES 
(38037,24642),(38246,24754),(38242,24762),(38243,24768),(38244,24774),(38247,24780),(38245,24786),(42618,26276);
DELETE FROM `creature_questender` WHERE `quest` IN (24642,24754,24762,24768,24774,24780,24786,26276);
INSERT INTO `creature_questender` (`id`,`quest`) VALUES 
(38037,24642),(38246,24754),(38242,24762),(38243,24768),(38244,24774),(38247,24780),(38245,24786),(42618,26276);
