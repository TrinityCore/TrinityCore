--
SET @GUID := 12481; -- 1 free Cguid set by TC
SET @OGUID := 9468; -- 5 free Oguid set by TC
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+4;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID,165738,230,1,1,891.99,-181.77,-42.811,4.98,0,0,0,1,120,255,1),
(@OGUID+1,165738,230,1,1,891.36,-182.133,-42.811,3.6782,0,0,0,1,120,255,1),
(@OGUID+2,165738,230,1,1,891.2988,-183.168,-42.811,4.55,0,0,0,1,120,255,1),
(@oGUID+3,165738,230,1,1,891.788,-182.847,-42.811,0.597,0,0,0,1,120,255,1),
(@OGUID+4,165738,230,1,1,891.7,-184.356,-42.811,4.673,0,0,0,1,120,255,1);

DELETE FROM `creature` WHERE `guid`= @GUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,28067,230,1,1,0,0,891.271,-174.899,-43.925,0.445,180,0,0,2215,0,0);

DELETE FROM `creature_template_addon` WHERE `entry`=28067;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`) VALUES
(28067,0,1, 69);

UPDATE `gossip_menu_option` SET `action_menu_id`=9648 WHERE `menu_id`=9648 AND `id`=1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`=9648;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 9648, 13061, 0, 0, 10, 0, 1, 0, 0, 1, 0, 0, '', 'Show the gossip text for Dark Iron Brewer if the player is Sober'),
(14, 9648, 13060, 0, 0, 10, 0, 3, 0, 0, 0, 0, 0, '', 'Show the gossip text for Dark Iron Brewer if the player is smashed'),
(14, 9648, 13063, 0, 0, 10, 0, 2, 0, 0, 0, 0, 0, '', 'Show the gossip text for Dark Iron Brewer if the player is Drunk'),
(14, 9648, 13063, 0, 0, 10, 0, 3, 0, 0, 1, 0, 0, '', 'Show the gossip text for Dark Iron Brewer if the player is not smashed'),
(14, 9648, 13064, 0, 0, 10, 0, 1, 0, 0, 0, 0, 0, '', 'Show the gossip text for Dark Iron Brewer if the player is tipsy'),
(14, 9648, 13064, 0, 0, 10, 0, 2, 0, 0, 1, 0, 0, '', 'Show the gossip text for Dark Iron Brewer if the player is not drunk'),
(15, 9648, 0, 0, 0, 10, 0, 1, 0, 0, 1, 0, 0, '', 'Show the gossip option for Dark Iron Brewer if the player is not tipsy'),
(15, 9648, 1, 0, 0, 10, 0, 1, 0, 0, 0, 0, 0, '', 'Show the gossip option for Dark Iron Brewer if the player is tipsy'),
(15, 9648, 1, 0, 0, 10, 0, 3, 0, 0, 1, 0, 0, '', 'Show the gossip option for Dark Iron Brewer if the player is not smashed'),
(15, 9648, 2, 0, 0, 10, 0, 3, 0, 0, 0, 0, 0, '', 'Show the gossip option for Dark Iron Brewer if the player is smashed');

UPDATE `creature_template` SET `npcflag`=1, `AIName`= 'SmartAI' WHERE `entry` IN(28067);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN(28067);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`IN(2806700);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28067, 0, 0 ,0, 62, 0, 100, 0, 9652, 0, 0,0,11,50631,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Dark Iron Brewer - On gossip select - Cast Dark Iron Brewer Drinks'),
(28067, 0, 1 ,0, 62, 0, 100, 0, 9648, 1, 0,0,11,50631,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Dark Iron Brewer - On gossip select - Cast Dark Iron Brewer Drinks'),
(28067, 0, 2 ,0, 62, 0, 100, 0, 9648, 2, 0,0,80,2806700,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dark Iron Brewer - On gossip select - action_list'),
(2806700, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,11,50631,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Dark Iron Brewer - action_list - Cast Dark Iron Brewer Drinks'),
(2806700, 9, 1 ,0, 0, 0, 100, 0, 0, 0, 0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Dark Iron Brewer - action_list - Close gossip'),
(2806700, 9, 2,0, 0, 0, 100, 0, 0, 0, 0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dark Iron Brewer - action_list - Remove npcflag 1'),
(2806700, 9, 3,0, 0, 0, 100, 0, 0, 0, 0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dark Iron Brewer - action_list - Add unitflag immune to pc'),
(2806700, 9, 4 ,0, 0, 0, 100, 0, 0, 0, 0,0,11,50651,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dark Iron Brewer - action_list - Cast Dark Iron Brewer is Swaggering'),
(2806700, 9, 5 ,0, 0, 0, 100, 0, 3000, 3000, 0,0,11,50650,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dark Iron Brewer - action_list - Cast Dark Iron Brewer is Sleeping'),  
(2806700, 9, 6 ,0, 0, 0, 100, 0, 0, 0, 0,0,50,190394,180,0,0,0,0,8,0,0,0,891.688, -175.735, -43.925, 1.21, 'Dark Iron Brewer - action_list - Mug of Dire Brew');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (51010);
INSERT INTO `spell_linked_spell` VALUES
(51010, 5268, 2, 'Dire Brew'),
(51010, -5268, 0, 'Dire Brew');

UPDATE `smart_scripts` SET `event_param1`=200000 WHERE `entryorguid`=-91064 AND `source_type`=0 AND `id`=6;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=25160;
UPDATE `creature` SET `position_z`=9 WHERE `guid` IN (62845, 62846);
