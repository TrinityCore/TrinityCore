-- Script
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (208000,208001,208002);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES

-- Timed List 1, for the quest "Denalan's Earth" (997)
(208000,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Remove Npc Flag Questgiver"),
(208000,9,1,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 0"),
(208000,9,2,0,0,0,100,0,3000,3000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9508.02,715.749,1255.89,0,"Denalan - On Script - Move To Position"),
(208000,9,3,0,0,0,100,0,1000,1000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9507.66,718.009,1255.89,0,"Denalan - On Script - Move To Position"),
(208000,9,4,0,0,0,100,0,1000,1000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9505.56,719.088,1256.2,0,"Denalan - On Script - Move To Position"),
(208000,9,5,0,0,0,100,0,2000,2000,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Play Emote 16"),
(208000,9,6,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Denalan - On Script - Set Orientation To Invoker"),
(208000,9,7,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 1"),
(208000,9,8,0,0,0,100,0,2000,2000,0,0,0,59,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Denalan - On Script - Set Run On"),
(208000,9,9,0,0,0,100,0,4000,4000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9506.9199,713.7660,1255.89,0,"Denalan - On Script - Move"),
(208000,9,10,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Reset Orientation"),
(208000,9,11,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Add Npc Flag Questgiver"),

-- Timed List 2, for the quest "The Shimmering Frond" (931)
(208001,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Remove Npc Flag Questgiver"),
(208001,9,1,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 2"),
(208001,9,2,0,0,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9508.02,715.749,1255.89,0,"Denalan - On Script - Move To Position"),
(208001,9,3,0,0,0,100,0,1000,1000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9507.66,718.009,1255.89,0,"Denalan - On Script - Move To Position"),
(208001,9,4,0,0,0,100,0,1000,1000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9505.56,719.088,1256.2,0,"Denalan - On Script - Move To Position"),
(208001,9,5,0,0,0,100,0,2000,2000,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Play Emote 16"),
(208001,9,6,0,0,0,100,0,3500,3500,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 3"),
(208001,9,7,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Denalan - On Script - Set Run On"),
(208001,9,8,0,0,0,100,0,3000,3000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9506.9199,713.7660,1255.89,0,"Denalan - On Script - Move"),
(208001,9,9,0,0,0,100,0,500,500,0,0,0,70,60,0,0,0,0,0,14,67984,7510,0,0,0,0,0,0,"Denalan - On Script - Respawn Closest Gameobject 'Sprouted Frond'"),
(208001,9,10,0,0,0,100,0,0,0,0,0,0,70,60,0,0,0,0,0,14,42936,7510,0,0,0,0,0,0,"Denalan - On Script - Respawn Closest Gameobject 'Sprouted Frond'"),
(208001,9,11,0,0,0,100,0,0,0,0,0,0,70,60,0,0,0,0,0,14,30276,7510,0,0,0,0,0,0,"Denalan - On Script - Respawn ClosestGameobject 'Sprouted Frond'"),
(208001,9,12,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Reset Orientation"),
(208001,9,13,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Add Npc Flag Questgiver"),

-- Timed List 3, for the quest "The Glowing Fruit" (930)
(208002,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Remove Npc Flag Questgiver"),
(208002,9,1,0,0,0,100,0,1000,1000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 4"),
(208002,9,2,0,0,0,100,0,4000,4000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 5"),
(208002,9,3,0,0,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9508.02,715.749,1255.89,0,"Denalan - On Script - Move To Position"),
(208002,9,4,0,0,0,100,0,1000,1000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9507.66,718.009,1255.89,0,"Denalan - On Script - Move To Position"),
(208002,9,5,0,0,0,100,0,1000,1000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9505.56,719.088,1256.2,0,"Denalan - On Script - Move To Position"),
(208002,9,6,0,0,0,100,0,2000,2000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Set Flag Standstate 'Kneel'"),
(208002,9,7,0,0,0,100,0,2000,2000,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 6"),
(208002,9,8,0,0,0,100,0,2000,2000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Remove Flag Standstate 'Kneel'"),
(208002,9,9,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Denalan - On Script - Set Run On"),
(208002,9,10,0,0,0,100,0,3000,3000,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,9506.9199,713.7660,1255.89,0,"Denalan - On Script - Move"),
(208002,9,11,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Reset Orientation"),
(208002,9,12,0,0,0,100,0,1000,1000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Summon Creature Group 0"),
(208002,9,13,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,19,3569,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 1 (Bogling)"),
(208002,9,14,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Denalan - On Script - Add Npc Flag Questgiver");

-- "Bogling" (3569) summon group
DELETE FROM `creature_summon_groups` WHERE `summonerId`=2080 AND `summonerType`=0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES 
(2080,0,0,3569,9504.4580,721.7338,1255.9418,5.7422,3,300000),
(2080,0,0,3569,9503.4727,719.9250,1255.9418,5.781,3,300000),
(2080,0,0,3569,9502.4785,718.0815,1255.9418,5.757,3,300000);
