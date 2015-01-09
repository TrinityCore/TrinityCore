--
SET @CGuid     := 71997;

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE  `entry`=164911;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`unit_flags`=0 WHERE `entry` IN(9537,9541);

DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=164911;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN(9537,-@CGuid,-@CGuid-1,-@CGuid-2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(164911, 1, 0 ,0, 70, 0, 100, 0, 2, 0, 0,0,45,1,1,0,0,0,0,13,164911,0,200,0,0,0,0, 'Thunderbrew Lager Keg - On State Changed - Set Data'),
(164911, 1, 1 ,0, 70, 2, 100, 0, 2, 0, 0,0,45,1,1,0,0,0,0,9,9537,0,200,0,0,0,0, 'Thunderbrew Lager Keg - On State Changed - Set Data'),
(164911, 1, 2 ,0, 38, 0, 100, 0, 1, 1, 0,0,23,1,0,0,0,0,0,9,9537,0,200,0,0,0,0, 'Thunderbrew Lager Keg - On Data Set - Increment Phase'),
--
(9537, 0, 0 ,1, 11, 0, 100, 0, 0, 0, 0,0,18,320,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - On Spawn - Set Unit Flags'),
(9537, 0, 1 ,0, 61, 0, 100, 0, 0, 0, 0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - Linked with Previous Event - Set Invisible'),
(9537, 0, 3 ,4, 38, 0, 100, 1, 1, 1, 0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - On Data Set - Set Visible'),
(9537, 0, 4 ,6, 61, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,9,9541,0,200,0,0,0,0, 'Hurley Blackbreath - Linked with Previous Event - Set Data'),
(9537, 0, 6 ,7, 61, 0, 100, 0, 0, 0, 0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - Linked with Previous Event - Say'),
(9537, 0, 7 ,0, 61, 0, 100, 0, 0, 0, 0,0,53,0,9537,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - Linked with Previous Event - Start WP'),
(9537, 0, 8 ,9, 40, 0, 100, 0, 3, 0, 0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - On Reached WP 3 - Set Home Position'),
(9537, 0, 9 ,10, 61, 0, 100, 0, 0, 0, 0,0,19,320,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - Linked with Previous Event - Set Unit Flags'),
(9537, 0, 10 ,15, 61, 0, 100, 0, 0, 0, 0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - Linked with Previous Event - Say'),
(9537, 0, 11 ,0,  2, 0, 100, 0, 0, 30, 30000,45000,11,14872,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - On Less than 30% HP - Cast Drunken Rage'),
(9537, 0, 12 ,0,  9, 0, 100, 0, 0, 5, 10000,15000,11,9573,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Hurley Blackbreath - On Range - Cast Flame Breath'),
(9537, 0, 13 ,0,  0, 0, 100, 0, 5000, 6000, 10000,14000,11,26211,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Hurley Blackbreath - IC - Cast Hamstring'),
(9537, 0, 14 ,0,  0, 0, 100, 0, 5000, 8000, 8000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Hurley Blackbreath - IC - Cast Mortal Strike'),
(9537, 0, 15 ,0, 61, 0, 100, 0, 0, 0, 0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - Linked with Previous Event - Set Random Movement'),
(9537, 0, 16 ,17, 4, 0, 100, 0, 0, 0, 0,0,45,1,2,0,0,0,0,9,9541,0,200,0,0,0,0, 'Hurley Blackbreath - On Agro - Set Set Data'),
(9537, 0, 17 ,0, 61, 0, 100, 0, 0, 0, 0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Hurley Blackbreath - Linked with Previous Event - Attack'),
(9537, 0, 18 ,0, 38, 0, 100, 0, 1, 2, 0,0,49,0,0,0,0,0,0,21,200,0,0,0,0,0,0, 'Hurley Blackbreath - On Data Set - Attack'),
--
(-@CGuid, 0, 0 ,1, 11, 0, 100, 0, 0, 0, 0,0,18,320,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On Spawn - Set Unit Flags'),
(-@CGuid, 0, 1 ,0, 61, 0, 100, 0, 0, 0, 0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Set Invisible'),
(-@CGuid, 0, 2 ,4, 38, 0, 100, 0, 1, 1, 0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On Data Set - Set visible'),
(-@CGuid, 0, 4 ,0, 61, 0, 100, 0, 0, 0, 0,0,53,0,9541,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Start WP'),
(-@CGuid, 0, 5 ,6, 40, 0, 100, 0, 3, 0, 0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On Reached WP 5 - Set Home Position'),
(-@CGuid, 0, 6 ,7, 61, 0, 100, 0, 0, 0, 0,0,19,320,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Set Unit Flags'),
(-@CGuid, 0, 7 ,0, 61, 0, 100, 0, 0, 0, 0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Set Random Movement'),
(-@CGuid, 0, 8, 0, 0,  0, 100, 0, 1000, 3000, 4000, 7000, 11, 15581, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blackbreath Crony - IC - Cast Sinister Strike'),
(-@CGuid, 0, 9, 0, 0,  0, 100, 0, 2000, 2000, 11000, 12000, 11, 15583, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blackbreath Crony - IC - Cast Rupture'),
(-@CGuid, 0, 10 ,11, 4, 0, 100, 0, 0, 0, 0,0,45,1,2,0,0,0,0,9,9541,0,200,0,0,0,0, 'Hurley Blackbreath - On Agro - Set Set Data'),
(-@CGuid, 0, 11 ,12,61, 0, 100, 0, 0, 0, 0,0,45,1,2,0,0,0,0,9,9537,0,200,0,0,0,0, 'Hurley Blackbreath - On Agro - Set Set Data'),
(-@CGuid, 0, 12 ,0, 61, 0, 100, 0, 0, 0, 0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Hurley Blackbreath - Linked with Previous Event - Attack'),
(-@CGuid, 0, 13 ,0, 38, 0, 100, 0, 1, 2, 0,0,49,0,0,0,0,0,0,21,200,0,0,0,0,0,0, 'Hurley Blackbreath - On Data Set - Attack'),
--
(-@CGuid-1, 0, 0 ,1, 11, 0, 100, 0, 0, 0, 0,0,18,320,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On Spawn - Set Unit Flags'),
(-@CGuid-1, 0, 1 ,0, 61, 0, 100, 0, 0, 0, 0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Set Invisible'),
(-@CGuid-1, 0, 2 ,4, 38, 0, 100, 0, 1, 1, 0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On Data Set - Set visible'),
(-@CGuid-1, 0, 4 ,0, 61, 0, 100, 0, 0, 0, 0,0,53,0,9541000,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Start WP'),
(-@CGuid-1, 0, 5 ,6, 40, 0, 100, 0, 3, 0, 0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On Reached WP 5 - Set Home Position'),
(-@CGuid-1, 0, 6 ,7, 61, 0, 100, 0, 0, 0, 0,0,19,320,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Set Unit Flags'),
(-@CGuid-1, 0, 7 ,0, 61, 0, 100, 0, 0, 0, 0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Set Random Movement'),
(-@CGuid-1, 0, 8, 0, 0,  0, 100, 0, 1000, 3000, 4000, 7000, 11, 15581, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blackbreath Crony - IC - Cast Sinister Strike'),
(-@CGuid-1, 0, 9, 0, 0,  0, 100, 0, 2000, 2000, 11000, 12000, 11, 15583, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blackbreath Crony - IC - Cast Rupture'),
(-@CGuid-1, 0, 10 ,11, 4, 0, 100, 0, 0, 0, 0,0,45,1,2,0,0,0,0,9,9541,0,200,0,0,0,0, 'Blackbreath Crony - On Agro - Set Set Data'),
(-@CGuid-1, 0, 11 ,12,61, 0, 100, 0, 0, 0, 0,0,45,1,2,0,0,0,0,9,9537,0,200,0,0,0,0, 'Blackbreath Crony - On Agro - Set Set Data'),
(-@CGuid-1, 0, 12 ,0, 61, 0, 100, 0, 0, 0, 0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Attack'),
(-@CGuid-1, 0, 13 ,0, 38, 0, 100, 0, 1, 2, 0,0,49,0,0,0,0,0,0,21,200,0,0,0,0,0,0, 'Blackbreath Crony - On Data Set - Attack'),
--
(-@CGuid-2, 0, 0 ,1, 11, 0, 100, 0, 0, 0, 0,0,18,320,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On Spawn - Set Unit Flags'),
(-@CGuid-2, 0, 1 ,0, 61, 0, 100, 0, 0, 0, 0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Set Invisible'),
(-@CGuid-2, 0, 2 ,4, 38, 0, 100, 0, 1, 1, 0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On Data Set - Set visible'),
(-@CGuid-2, 0, 4 ,0, 61, 0, 100, 0, 0, 0, 0,0,53,0,9541001,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Start WP'),
(-@CGuid-2, 0, 5 ,6, 40, 0, 100, 0, 3, 0, 0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On Reached WP 5 - Set Home Position'),
(-@CGuid-2, 0, 6 ,7, 61, 0, 100, 0, 0, 0, 0,0,19,320,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Set Unit Flags'),
(-@CGuid-2, 0, 7 ,0, 61, 0, 100, 0, 0, 0, 0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Set Random Movement'),
(-@CGuid-2, 0, 8, 0, 0,  0, 100, 0, 2000, 2000, 11000, 12000, 11, 15581, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blackbreath Crony - IC - Cast Sinister Strike'),
(-@CGuid-2, 0, 9, 0, 0,  0, 100, 0, 3000, 5000, 15000, 20000, 11, 15583, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blackbreath Crony - IC - Cast Rupture'),
(-@CGuid-2, 0, 10 ,11, 4, 0, 100, 0, 0, 0, 0,0,45,1,2,0,0,0,0,9,9541,0,200,0,0,0,0, 'Blackbreath Crony - On Agro - Set Set Data'),
(-@CGuid-2, 0, 11 ,12,61, 0, 100, 0, 0, 0, 0,0,45,1,2,0,0,0,0,9,9537,0,200,0,0,0,0, 'Blackbreath Crony - On Agro - Set Set Data'),
(-@CGuid-2, 0, 12 ,0, 61, 0, 100, 0, 0, 0, 0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Blackbreath Crony - Linked with Previous Event - Attack'),
(-@CGuid-2, 0, 13 ,0, 38, 0, 100, 0, 1, 2, 0,0,49,0,0,0,0,0,0,21,200,0,0,0,0,0,0, 'Blackbreath Crony - On Data Set - Attack');

DELETE FROM `creature_text` WHERE `entry` =9537;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(9537, 1, 0, 'You''ll pay for that!', 12, 0, 100, 0, 0, 0, 'Hurley Blackbreath', 4936),
(9537, 0, 0, 'Get away from those kegs!', 14, 0, 100, 0, 0, 0, 'Hurley Blackbreath', 4934);

DELETE FROM `waypoints` WHERE `entry`IN (9537,9541,9541000,9541001);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(9537, 1, 886.916870,-149.176147,-49.760010, 'Hurley Blackbreath'),
(9537, 2, 897.698730,-137.324112,-49.752193, 'Hurley Blackbreath'),
(9537, 3, 898.569946,-141.830872,-49.755016, 'Hurley Blackbreath'),
(9541, 1, 885.926453,-145.907608,-49.760010, 'Blackbreath Crony'),
(9541, 2, 891.983093,-138.613907,-49.754261, 'Blackbreath Crony'),
(9541, 3, 896.412170,-144.160172,-49.757446, 'Blackbreath Crony'),
(9541000, 1, 888.984070,-152.598846,-49.760010, 'Blackbreath Crony'),
(9541000, 2, 895.560303,-134.140274,-49.748451, 'Blackbreath Crony'),
(9541000, 3, 897.199036,-139.512802,-49.755379, 'Blackbreath Crony'),
(9541001, 1, 886.916870,-149.176147,-49.760010, 'Blackbreath Crony'),
(9541001, 2, 899.913330,-133.534821,-49.747944, 'Blackbreath Crony'),
(9541001, 3, 901.009399,-139.603699,-49.755054, 'Blackbreath Crony');

DELETE FROM `creature` WHERE `id` IN(9537,9541);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@CGuid, 9541, 230, 1, 1, 0, 1, 879.018, -155.273, -49.7591, 0.57177, 300, 0, 0, 7359, 0, 0, 0, 0, 0),
(@CGuid+1, 9541, 230, 1, 1, 0, 1, 876.961, -151.796, -49.7591, 0.499513, 300, 0, 0, 7359, 0, 0, 0, 0, 0),
(@CGuid+2, 9541, 230, 1, 1, 0, 1, 876.535, -154.334, -49.7586, 0.339292, 300, 0, 0, 7359, 0, 0, 0, 0, 0),
(@CGuid+3, 9537, 230, 1, 1, 0, 1, 878.121, -153.074, -49.76, 0.527783, 300, 0, 0, 13070, 0, 0, 0, 0, 0);
