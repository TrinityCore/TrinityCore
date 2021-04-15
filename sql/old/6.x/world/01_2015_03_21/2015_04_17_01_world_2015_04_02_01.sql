UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (21302, 21316, 20683, 21314, 21500, 19740, 19755, 21499, 21501, 21305);
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=21302;
UPDATE `creature_addon` SET `emote`=0 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=21302);
UPDATE `creature_template` SET  `InhabitType`=4 WHERE  `entry`=21316;
UPDATE `creature` SET `position_x`= -3441.672363, `position_y`= 2950.212646, `position_z`= 171.877686, `orientation`= 6.151093 WHERE `guid`= 74657;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-74662, -74651, 21305, 21501, 21499, 19755, 19740, 21500, 21314, 21302, 20683) AND `source_type` = 0 ;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21316*100, 21316*100+1) AND `source_type` = 9 ;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21302,0,0,0,25,0,100,0,0,0,0,0,11,33346,0,0,0,0,0,19,21348,15,0,0,0,0,0,'Shadow Council Warlock - On Reset - Cast Green Beam'),
(21302,0,1,0,1,0,100,1,0,0,0,0,11,33346,0,0,0,0,0,19,21348,15,0,0,0,0,0,'Shadow Council Warlock- OOC - Cast Green Beam (No repeat)'),
(21302,0,2,0,0,0,100,0,1000,2000,5000,7000,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,'Shadow Council Warlock- IC - Cast Shadow Bolt'),
(21302,0,3,0,0,0,100,0,6000,8000,10000,12000,11,37992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Shadow Council Warlock- IC - Cast Drain Life'),
(19755,0,0,0,0,0,100,0,4000,5000,15000,17000,11,36253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mo''arg Weaponsmith- IC - Chemical Flames'),
(19755,0,1,0,0,0,100,0,6000,8000,10000,12000,11,37580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mo''arg Weaponsmith - IC - Drill Armor'),
(21499,0,0,0,0,0,100,0,4000,5000,15000,17000,11,35321,0,0,0,0,0,2,0,0,0,0,0,0,0,'Overseer Ripsaw - IC - Gushing Wound'),
(21499,0,1,0,0,0,100,0,6000,8000,9000,11000,11,32735,0,0,0,0,0,2,0,0,0,0,0,0,0,'Overseer Ripsaw - IC - Saw Blade'),
(21305,0,0,0,0,0,100,0,4000,5000,10000,12000,11,37950,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mutant Horror - IC - Mutant Horror'),
(21305,0,1,0,0,0,100,0,15000,15000,15000,15000,11,8599,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mutant Horror - IC - Enrage'),
(19740,0,0,0,0,0,100,0,1000,2000,9000,13000,11,33799,0,0,0,0,0,2,0,0,0,0,0,0,0,'wrathwalker - IC - Cast Flame Wave'),
(20683,0,0,0,0,0,100,0,1000,2000,15000,17000,11,37629,0,0,0,0,0,2,0,0,0,0,0,0,0,'Prophetess Cavrylin - IC - Cast Melt Flesh'),
(20683,0,1,0,0,0,100,0,6000,8000,10000,12000,11,37997,0,0,0,0,0,2,0,0,0,0,0,0,0,'Prophetess Cavrylin - IC - Cast Chaos Nova'),
(21314,0,0,0,0,0,100,0,1000,2000,4000,7000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Terrormaster - IC - Cast Cleave'),
(21314,0,1,0,0,0,100,0,9000,12000,20000,25000,11,38154,0,0,0,0,0,2,0,0,0,0,0,0,0,'Terrormaster - IC - Cast Fear'), 
(21500,0,0,0,0,0,100,0,1000,2000,6000,9000,11,22859,0,0,0,0,0,2,0,0,0,0,0,0,0,'Morgroron - IC - Cast Mortal Cleave'),
(21500,0,1,0,0,0,100,0,12000,15000,20000,25000,11,38741,0,0,0,0,0,2,0,0,0,0,0,0,0,'Morgroron - IC - Rain of Fire'),
(21500,0,2,0,0,0,100,0,5000,7000,10000,13000,11,38750,0,0,0,0,0,2,0,0,0,0,0,0,0,'Morgroron - IC - War Stomp'),
(21501,0,0,0,0,0,100,0,1000,2000,8000,12000,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,'Makazradon - IC - Cripple'),
(21501,0,1,0,0,0,100,0,4000,5000,7000,10000,11,38742,0,0,0,0,0,2,0,0,0,0,0,0,0,'Makazradon - IC - Fel Cleave'),
(21501,0,2,0,0,0,100,0,12000,15000,20000,25000,11,38741,0,0,0,0,0,2,0,0,0,0,0,0,0,'Makazradon - IC - Rain of Fire'),
(-74662,0,0,0,1,0,100,0,120000,120000,240000,240000,80,21316*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - OOC - Action list'),
(-74651,0,0,0,1,0,100,0,180000,180000,300000,300000,80,21316*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - OOC - Action liist'),
(-74662,0,1,0,40,0,100,0,1,7466200,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint1 - pause wp)'),
(-74651,0,1,0,40,0,100,0,1,7465100,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint1 - pause wp)'),
(-74662,0,2,0,40,0,100,0,2,7466200,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint2 - Set visible off'),
(-74651,0,2,0,40,0,100,0,2,7465100,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint2 - Set visible off'),
(-74662,0,3,4,40,0,100,0,3,7466200,0,0,28,36658,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint3 - Remove aura)'),   
(-74662,0,4,5,61,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint3 - Set visible on'),
(-74662,0,5,6,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.265730,'Deathforged Infernal - On waypoint3 - Set orientation'),
(-74662,0,6,7,61,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint3 - Set fly Off'),
(-74662,0,7,0,61,0,100,0,0,0,0,0,11,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint3 - Cast spell'),
(-74651,0,3,4,40,0,100,0,3,7465100,0,0,28,36658,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint1 - Remove aura)'), 
(-74651,0,4,5,61,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint3 - Set visible on'),
(-74651,0,5,6,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.468040,'Deathforged Infernal - On waypoint3 - Set orientation'),
(-74651,0,6,7,61,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint3 - Set fly Off'),
(-74651,0,7,0,61,0,100,0,0,0,0,0,11,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - On waypoint3 - Cast spell'),
(21316*100,9,0,0,0,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Set fly off'),  
(21316*100,9,1,0,0,0,100,0,0,0,0,0,28,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Remove aura'), 
(21316*100,9,2,0,0,0,100,0,0,0,0,0,53,1,7466200,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - start wp'),
(21316*100,9,3,0,0,0,100,0,13000,13000,0,0,86,33346,0,19,20683,15,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Cross cast'), 
(21316*100,9,4,0,0,0,100,0,3000,3000,0,0,86,36656,0,19,20683,15,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Cross cast'), 
(21316*100,9,5,0,0,0,100,0,0,0,0,0,11,36658,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Cast Transform'),
(21316*100,9,6,0,0,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Set fly On'), 
(21316*100+1,9,0,0,0,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Set fly off'),  
(21316*100+1,9,1,0,0,0,100,0,0,0,0,0,28,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Remove aura'), 
(21316*100+1,9,2,0,0,0,100,0,0,0,0,0,53,1,7465100,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - start wp'),
(21316*100+1,9,3,0,0,0,100,0,12000,12000,0,0,86,33346,0,19,20683,15,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Cross cast'), 
(21316*100+1,9,4,0,0,0,100,0,3000,3000,0,0,86,36656,0,19,20683,15,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Cross cast'),
(21316*100+1,9,5,0,0,0,100,0,0,0,0,0,11,36658,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Cast Transform'),  
(21316*100+1,9,6,0,0,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deathforged Infernal - Action list - Set fly On');

DELETE FROM `waypoints` WHERE `entry` IN(7466200, 7465100);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(7466200, 1, -3411.152100, 2979.670410, 169.896851, 'Deathforged Infernal'),
(7466200, 2, -3411.152100, 2979.670410, 293.973755, 'Deathforged Infernal'),
(7466200, 3, -3441.462891, 2974.701172, 171.833115, 'Deathforged Infernal'),
(7465100, 1, -3411.152100, 2979.670410, 169.896851, 'Deathforged Infernal'),
(7465100, 2, -3411.152100, 2979.670410, 293.973755, 'Deathforged Infernal'),
(7465100, 3, -3408.362061, 3007.351807, 171.597610, 'Deathforged Infernal');


UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=74602;
DELETE FROM `creature_addon` WHERE `guid`=74602;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (74602,746020,0,0,4097,0, '');
DELETE FROM `waypoint_data` WHERE `id`=746020;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(746020,1,-3374.98, 3001.77, 170.893,0,0,0,0,100,0),
(746020,2,-3423.57, 3005.07, 171.273,0,0,0,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=74601;
DELETE FROM `creature_addon` WHERE `guid`=74601;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (74601,746010,0,0,4097,0, '');
DELETE FROM `waypoint_data` WHERE `id`=746010;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(746010, 1, -3438.26, 2988.15, 171.462, 0, 0, 0, 0, 100, 0),
(746010, 2, -3437.38, 2950.23, 171.240, 0, 0, 0, 0, 100, 0);
