SET @ENTRY := 14354; -- the little bugger Pusillin 

SET @SPELL_1 := 14145; -- Fire Blast
SET @SPELL_2 := 15228; -- Fireball
SET @SPELL_3 := 22424; -- Blast Wave
SET @SPELL_4 := 22735; -- Spirit of Runn Tum (reflect magic) 
SET @NPC_WILDSPAWN_IMP := 13276; -- 5 of them summoned by Pusillin during fight

-- Gossip menu's from npc_text
SET @GOSSIP_1 := 6877;
SET @GOSSIP_2 := 6878;
SET @GOSSIP_3 := 6879;
SET @GOSSIP_4 := 6880;
SET @GOSSIP_5 := 6881;

-- Gossip menu options
SET @GOSSIP_OPTION_1 := 6877;
SET @GOSSIP_OPTION_2 := 6878;
SET @GOSSIP_OPTION_3 := 6879;
SET @GOSSIP_OPTION_4 := 6880;
SET @GOSSIP_OPTION_5 := 6881; 

SET @SCRIPT_1 := 1435400; -- gossip
SET @SCRIPT_2 := 1435401; -- gossip
SET @SCRIPT_3 := 1435402; -- gossip
SET @SCRIPT_4 := 1435403; -- gossip
SET @SCRIPT_5 := 1435404; -- fight

SET @SA_SEND_GOSSIP := 98; -- SMART ACTION_SEND_GOSSIP

-- SmartAI for Pusillin
UPDATE `creature_template` SET `lootid`=@ENTRY,`gossip_menu_id`=0,`speed_run`=2.14286,`AIName`='SmartAI',`npcflag`=1 WHERE `entry`=@ENTRY;
UPDATE `creature` SET `MovementType`=1,`spawndist`=3,`spawntimesecs`=300  WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SCRIPT_1,@SCRIPT_2,@SCRIPT_3,@SCRIPT_4,@SCRIPT_5) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Pusillin - On Spawn - Set Phase 1'),

 -- send gossip depending on phase
 (@ENTRY,0,1,0,64,0,100,0,0,0,0,0,@SA_SEND_GOSSIP,@GOSSIP_1,@GOSSIP_OPTION_1,0,0,0,0,7,0,0,0,0,0,0,0,'Pusillin - On Gossip Hello & Phase 1 - Send Gossip'),
 (@ENTRY,0,2,0,64,1,100,0,0,0,0,0,@SA_SEND_GOSSIP,@GOSSIP_2,@GOSSIP_OPTION_2,0,0,0,0,7,0,0,0,0,0,0,0,'Pusillin - On Gossip Hello & Phase 2 - Send Gossip'),
 (@ENTRY,0,3,0,64,2,100,0,0,0,0,0,@SA_SEND_GOSSIP,@GOSSIP_3,@GOSSIP_OPTION_3,0,0,0,0,7,0,0,0,0,0,0,0,'Pusillin - On Gossip Hello & Phase 3 - Send Gossip'),
 (@ENTRY,0,4,0,64,4,100,0,0,0,0,0,@SA_SEND_GOSSIP,@GOSSIP_4,@GOSSIP_OPTION_4,0,0,0,0,7,0,0,0,0,0,0,0,'Pusillin - On Gossip Hello & Phase 4 - Send Gossip'),
 (@ENTRY,0,5,0,64,8,100,0,0,0,0,0,@SA_SEND_GOSSIP,@GOSSIP_5,@GOSSIP_OPTION_5,0,0,0,0,7,0,0,0,0,0,0,0,'Pusillin - On Gossip Hello & Phase 5 - Send Gossip'), 

-- run script depending on phase
(@ENTRY,0,6,0,62,0,100,0,@GOSSIP_OPTION_1,0,0,0,80,@SCRIPT_1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Gossip Select - Run Script 1'),
(@ENTRY,0,7,0,62,1,100,0,@GOSSIP_OPTION_2,0,0,0,80,@SCRIPT_2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Gossip Select - Run Script 2'),
(@ENTRY,0,8,0,62,2,100,0,@GOSSIP_OPTION_3,0,0,0,80,@SCRIPT_3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Gossip Select - Run Script 3'),
(@ENTRY,0,9,0,62,4,100,0,@GOSSIP_OPTION_4,0,0,0,80,@SCRIPT_4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Gossip Select - Run Script 4'),
(@ENTRY,0,10,0,62,8,100,0,@GOSSIP_OPTION_5,0,0,0,80,@SCRIPT_5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Gossip Select - Run Script 5'),

 -- Waypoint 3 (chit-chat 1)
(@ENTRY,0,11,12,40,0,100,0,3,@ENTRY,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - At WP3 - stop'),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - At WP3 - Turn on Gossip flag'), 

-- Waypoint 14 (chit-chat 2)
(@ENTRY,0,13,14,40,0,100,0,14,@ENTRY*10,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - At WP14 - stop'),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - At WP14 - Turn on Gossip flag'), 

-- Waypoint 12 (chit-chat 3)
(@ENTRY,0,15,16,40,0,100,0,12,@ENTRY*20,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - At WP12 - stop'),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - At WP12 - Turn on Gossip flag'), 

-- Waypoint 7 (chit-chat 4)
(@ENTRY,0,17,18,40,0,100,0,7,@ENTRY*30,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - At WP7 - stop'),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - At WP7 - Turn on Gossip flag'), 

-- casts during fight
(@ENTRY,0,19,0,0,0,100,0,1000,4250,8000,8000,11,@SPELL_1,0,0,0,0,0,2,0,0,0,0,0,0,0,'Pusillin - In Combat - Cast Fire Blast'),
(@ENTRY,0,20,0,0,0,100,0,1000,1000,4000,4000,11,@SPELL_2,0,0,0,0,0,2,0,0,0,0,0,0,0,'Pusillin - In Combat - Cast Fireball'),
(@ENTRY,0,21,0,0,0,100,0,2000,10000,10000,17500,11,@SPELL_3,0,0,0,0,0,2,0,0,0,0,0,0,0,'Pusillin - In Combat - Cast Blast Wave'), 

-- Script 1
(@SCRIPT_1,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Pusillin - On Script 1 - Close Gossip'),
(@SCRIPT_1,9,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 1 - Turn Off Gossip Flags'),
(@SCRIPT_1,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 1 - Say Text 0'),
(@SCRIPT_1,9,3,0,0,0,100,0,0,0,0,0,23,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Pusillin - On Script 1 - Set Phase to 2'),
(@SCRIPT_1,9,4,0,0,0,100,0,0,0,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 1 - Start Waypoint Movement'), 

-- Script 2
(@SCRIPT_2,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Pusillin - On Script 2 - Close Gossip'),
(@SCRIPT_2,9,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 2 - Turn Off Gossip Flags'),
(@SCRIPT_2,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 2 - Say Text 1'),
(@SCRIPT_2,9,3,0,0,0,100,0,0,0,0,0,23,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Pusillin - On Script 2 - Set Phase to 3'),
(@SCRIPT_2,9,4,0,0,0,100,0,0,0,0,0,53,1,@ENTRY*10,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 2 - Start Waypoint Movement'),

-- Script 3
(@SCRIPT_3,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Pusillin - On Script 3 - Close Gossip'),
(@SCRIPT_3,9,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 3 - Turn Off Gossip Flags'),
(@SCRIPT_3,9,2,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 3 - Say Text 2'),
(@SCRIPT_3,9,3,0,0,0,100,0,0,0,0,0,23,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Pusillin - On Script 3 - Set Phase to 4'),
(@SCRIPT_3,9,4,0,0,0,100,0,0,0,0,0,53,1,@ENTRY*20,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 3 - Start Waypoint Movement'), 

-- Script 4
(@SCRIPT_4,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Pusillin - On Script 4 - Close Gossip'),
(@SCRIPT_4,9,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 4 - Turn Off Gossip Flags'),
(@SCRIPT_4,9,2,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 4 - Say Text 3'),
(@SCRIPT_4,9,3,0,0,0,100,0,0,0,0,0,23,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Pusillin - On Script 4 - Set Phase to 5'),
(@SCRIPT_4,9,4,0,0,0,100,0,0,0,0,0,53,1,@ENTRY*30,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 4 - Start Waypoint Movement'),

-- Script 5
(@SCRIPT_5,9,0,0,0,0,100,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 5 - Stop Waypoint Movement'),
(@SCRIPT_5,9,1,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,9,0,0,0,0,0,0,0,'Pusillin - On script 5 - Say Text 4'),
(@SCRIPT_5,9,2,0,0,0,100,0,0,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 5  - Set Faction Enemy'),
(@SCRIPT_5,9,3,0,0,0,100,0,100,100,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On script 5 - Set React State Hostile'),
(@SCRIPT_5,9,4,0,0,0,100,0,100,100,0,0,11,@SPELL_4,1,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Script 5 - Aura Self'),
(@SCRIPT_5,9,5,0,0,0,100,0,0,0,0,0,12,@NPC_WILDSPAWN_IMP,7,0,0,0,0,8,0,0,0,25.1447,-703.067,-12.6426,0,'Pusillin - On Script 5 - Summon Wildspawn Imp'),
(@SCRIPT_5,9,6,0,0,0,100,0,0,0,0,0,12,@NPC_WILDSPAWN_IMP,7,0,0,0,0,8,0,0,0,13.1924,-709.858,-12.6426,0,'Pusillin - On Script 5 - Summon Wildspawn Imp'),
(@SCRIPT_5,9,7,0,0,0,100,0,0,0,0,0,12,@NPC_WILDSPAWN_IMP,7,0,0,0,0,8,0,0,0,24.2691,-694.881,-12.6426,0,'Pusillin - On Script 5 - Summon Wildspawn Imp'),
(@SCRIPT_5,9,8,0,0,0,100,0,0,0,0,0,12,@NPC_WILDSPAWN_IMP,7,0,0,0,0,8,0,0,0,15.6403,-690.705,-12.6426,0,'Pusillin - On Script 5 - Summon Wildspawn Imp'),
(@SCRIPT_5,9,9,0,0,0,100,0,0,0,0,0,12,@NPC_WILDSPAWN_IMP,7,0,0,0,0,8,0,0,0,19.6062,-677.524,-12.6426,0,'Pusillin - On Script 5 - Summon Wildspawn Imp'),
(@SCRIPT_5,9,10,0,4,0,100,0,0,0,0,0,20,1,0,0,0,0,0,21,0,0,0,0,0,0,0,'Pusillin - On Aggro - Attack Nearest Player'),
(@SCRIPT_5,9,11,0,4,0,100,0,0,0,0,0,39,125,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pusillin - On Aggro - Call for help (within 125 yards)');

-- waypoints for Pusillin from sniff
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY,@ENTRY*10,@ENTRY*20,@ENTRY*30);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,82.88,-198.508,-4.1331,'Pusillin path'),
(@ENTRY,2,-159.153,-201.138,-4.15275,'Pusillin path'),
(@ENTRY,3,-154.512,-276.2,-4.14787,'Pusillin path'), 
(@ENTRY*10,1,-159.64,-320.208,-4.14787,'Pusillin path'),
(@ENTRY*10,2,-142.923,-344.111,-4.11348,'Pusillin path'),
(@ENTRY*10,3,-84.2623,-363.37,-4.14729,'Pusillin path'),
(@ENTRY*10,4,-71.9857,-364.048,-4.14729,'Pusillin path'),
(@ENTRY*10,5,-53.8684,-348.615,-4.06211,'Pusillin path'),
(@ENTRY*10,6,-31.2778,-353.235,-4.09911,'Pusillin path'),
(@ENTRY*10,7,40.8255,-356.709,-4.12891,'Pusillin path'),
(@ENTRY*10,8,44.4199,-357.733,-4.13713,'Pusillin path'),
(@ENTRY*10,9,43.8367,-362.318,-4.14879,'Pusillin path'),
(@ENTRY*10,10,36.4393,-359.959,-4.14924,'Pusillin path'),
(@ENTRY*10,11,38.3357,-357.051,-4.13201,'Pusillin path'),
(@ENTRY*10,12,55.7067,-349.754,-4.07173,'Pusillin path'),
(@ENTRY*10,13,88.4046,-354.125,-4.10444,'Pusillin path'),
(@ENTRY*10,14,113.54,-372.365,-4.08966,'Pusillin path'), 
(@ENTRY*20,1,111.71,-468.929,-2.71837,'Pusillin path'),
(@ENTRY*20,2,111.557,-485.672,-6.88627,'Pusillin path'),
(@ENTRY*20,3,111.29,-514.931,-6.91324,'Pusillin path'),
(@ENTRY*20,4,111.144,-530.976,-11.0799,'Pusillin path'),
(@ENTRY*20,5,106.029,-539.906,-11.0803,'Pusillin path'),
(@ENTRY*20,6,92.632,-544.772,-11.1469,'Pusillin path'),
(@ENTRY*20,7,78.5392,-545.053,-15.2469,'Pusillin path'),
(@ENTRY*20,8,67.4856,-547.887,-15.2466,'Pusillin path'),
(@ENTRY*20,9,54.6709,-557.626,-19.4133,'Pusillin path'),
(@ENTRY*20,10,50.4845,-565.069,-19.4122,'Pusillin path'),
(@ENTRY*20,11,49.8745,-586.269,-23.5734,'Pusillin path'),
(@ENTRY*20,12,49.3262,-636.426,-25.1286,'Pusillin path'),
(@ENTRY*30,1,39.8513,-677.459,-25.1611,'Pusillin path'),
(@ENTRY*30,2,11.7509,-698.469,-25.1611,'Pusillin path'),
(@ENTRY*30,3,4.38368,-694.666,-25.1611,'Pusillin path'),
(@ENTRY*30,4,4.88613,-671.499,-12.6426,'Pusillin path'),
(@ENTRY*30,5,8.9517,-667.447,-12.6426,'Pusillin path'),
(@ENTRY*30,6,13.0878,-672.124,-12.6426,'Pusillin path'),
(@ENTRY*30,7,16.2925,-701.417,-12.6426,'Pusillin path');

-- add gossip menu option id's
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(@GOSSIP_OPTION_1,@GOSSIP_OPTION_2,@GOSSIP_OPTION_3,@GOSSIP_OPTION_4,@GOSSIP_OPTION_5) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(@GOSSIP_OPTION_1,0,0,'Game? Are you crazy?',1,1),
(@GOSSIP_OPTION_2,0,0,'Why you little...',1,1),
(@GOSSIP_OPTION_3,0,0,'Mark my words, I will catch you, imp. And when I do!',1,1),
(@GOSSIP_OPTION_4,0,0,'DIE!',1,1),
(@GOSSIP_OPTION_5,0,0,'Prepare to meet your maker.',1,1); 

-- Pusillin texts
DELETE FROM `creature_text` WHERE `entry`= @ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'If you want the key, you''ll have to catch me!',12,0,0,0,0,0,'Pusillin text #1'),
(@ENTRY,1,0,'Chase me if you dare! I run without a care!',12,0,0,0,0,0,'Pusillin text #2'),
(@ENTRY,2,0,'Why would you ever want to harm me!? Come. Friends we can be!',12,0,0,0,0,0,'Pusillin text #3'),
(@ENTRY,3,0,'DIE?! You make Pusillin cry!',12,0,0,0,0,0,'Pusillin text #4'),
(@ENTRY,4,0,'Say hello to my little friends!',12,0,0,0,0,0,'Pusillin text #5'); 

-- remove already spawned Wildspawn Imp
DELETE FROM `creature` WHERE `guid`=56995;
