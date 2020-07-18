-- Rigglefuzz
UPDATE `creature_template` SET `faction`=121 WHERE `entry`=2817;
DELETE FROM `smart_scripts` WHERE `entryorguid`=281701 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(281701,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Remove Npc Flag Questgiver"),
(281701,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Root On"),
(281701,9,2,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 2"),
(281701,9,3,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Emote State 'Usestanding'"),
(281701,9,4,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Emote State 'None'"),
(281701,9,5,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 3"),
(281701,9,6,0,0,0,100,0,1000,1000,0,0,12,6013,1,60000,0,0,0,8,0,0,0,-6759.76,-3195.57,240.744,1.8727,"Rigglefuzz - On Script - Summon Creature 'Wayward Buzzard'"),
(281701,9,7,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,12,1,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Data 1"),
(281701,9,8,0,0,0,100,0,0,0,0,0,12,6013,1,60000,0,0,0,8,0,0,0,-6752.29,-3198.56,240.744,2.09261,"Rigglefuzz - On Script - Summon Creature 'Wayward Buzzard'"),
(281701,9,9,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,12,1,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Data 2"),
(281701,9,10,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 4"),
(281701,9,11,0,0,0,100,0,6000,6000,0,0,11,5134,2,0,0,0,0,19,6013,0,0,0,0,0,0,"Rigglefuzz - On Script - Cast 'Flash Bomb'"),
(281701,9,12,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 5"),
(281701,9,13,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 6"),
(281701,9,14,0,0,0,100,0,5000,5000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Add Npc Flag Questgiver"),
(281701,9,15,0,0,0,100,0,10000,10000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Root Off");

-- Wayward Buzzard
UPDATE `creature_template` SET `faction`=16, `AIName`="SmartAI" WHERE `entry`=6013;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6013 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6013,0,0,0,38,0,100,0,1,1,0,0,0,53,1,601300,0,0,0,2,1,0,0,0,0,0,0,0,"Wayward Buzzard - On Data Set - Start Waypoint"),
(6013,0,1,0,38,0,100,0,2,2,0,0,0,53,1,601301,0,0,0,2,1,0,0,0,0,0,0,0,"Wayward Buzzard - On Data Set - Start Waypoint"),
(6013,0,2,0,40,0,100,0,2,0,0,0,0,49,0,0,0,0,0,0,19,2817,0,0,0,0,0,0,"Wayward Buzzard - On Waypoint 2 Reached - Start Attacking"),
(6013,0,3,0,8,0,100,0,5134,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wayward Buzzard - On Spellhit 'Flash Bomb' - Despawn in 10 seconds");

DELETE FROM `waypoints` WHERE `entry` IN (2732,601300,601301);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(601300,1,-6778.27,-3153.14,240.744,""),
(601300,2,-6772.57,-3136.2,240.43,""),
(601301,1,-6765.74,-3161.81,240.76,""),
(601301,2,-6764.49,-3141.39,240.847,"");

-- Ridge Huntress
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=2732;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2732 AND `source_type`=0;
