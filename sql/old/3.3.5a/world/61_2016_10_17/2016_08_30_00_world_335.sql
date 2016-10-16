-- NPC entry 13716 Celebras the Redeemed, Quest ID 7046 "The Scepter of Celebras", GameObject entry 178965 Incantation of Celebras

SET @Celebras := 13716;
SET @GO_IoC   := 178965;

DELETE FROM `creature_text` WHERE `entry` = @Celebras;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`sound`,`duration`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Celebras,0,0,'You wish to learn of the stone? Follow me.',                                                        12,0,100,  1,0,0,8952,0,'Celebras - Line 0'),
(@Celebras,1,0,'For so long I have drifted in my cursed form. You have freed me... Your hard work shall be repaid.',12,0,100,  1,0,0,8953,0,'Celebras - Line 1'),
(@Celebras,2,0,'Please do as I instruct you, $n.',                                                                  12,0,100,  1,0,0,8954,0,'Celebras - Line 2'),
(@Celebras,3,0,'Read this tome I have placed before you, and speak the words aloud.',                               12,0,100,  1,0,0,8950,0,'Celebras - Line 3'),
(@Celebras,4,0,'%s begins to channel his energy, focusing on the stone.',                                           16,0,100,469,0,0,8951,0,'Celebras - Emote'),
(@Celebras,5,0,'Together, the two parts shall become one, once again.',                                             12,0,100,  1,0,0,8948,0,'Celebras - Line 5'),
(@Celebras,6,0,'Shal myrinan ishnu daldorah...',                                                                    12,0,100,  1,0,0,8949,0,'Celebras - Line 6'),
(@Celebras,7,0,'My scepter will once again become whole!',                                                          12,0,100,  1,0,0,8955,0,'Celebras - Line 7');

DELETE FROM `waypoints` WHERE `entry` = @Celebras;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Celebras, 1, 657.207, 73.8004, -86.8318, 'Celebras - The Scepter of Celebras - waypoint 1'),
(@Celebras, 2, 656.58,  83.1467, -86.8285, 'Celebras - The Scepter of Celebras - waypoint 2'),
(@Celebras, 3, 656.595, 73.5683, -86.8284, 'Celebras - The Scepter of Celebras - waypoint 3'),
(@Celebras, 4, 655.405, 73.8083, -86.8384, 'Celebras - The Scepter of Celebras - waypoint 4'),
(@Celebras, 5, 655.405, 73.8083, -86.8384, 'Celebras - The Scepter of Celebras - waypoint 5'),
(@Celebras, 6, 653.437, 73.9764, -85.3354, 'Celebras - The Scepter of Celebras - waypoint 6'),
(@Celebras, 7, 655.724, 67.3549, -86.828,  'Celebras - The Scepter of Celebras - waypoint 7'),
(@Celebras, 8, 650.08,  65.0115, -86.7745, 'Celebras - The Scepter of Celebras - waypoint 8'),
(@Celebras, 9, 655.445, 67.6601, -86.8283, 'Celebras - The Scepter of Celebras - waypoint 9'),
(@Celebras,10, 657.399, 78.0873, -86.8283, 'Celebras - The Scepter of Celebras - waypoint 10'),
(@Celebras,11, 652.611, 86.3702, -86.8453, 'Celebras - The Scepter of Celebras - waypoint 11');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @Celebras;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Celebras AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Celebras,0, 0,18, 19,0,100,0,7046,        0,0,0,  1,      0,     2500,0,   0,0,0, 7, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Quest 'The Scepter of Celebras' Taken - Say Line 0"),
(@Celebras,0, 1, 0, 52,0,100,0,   0,@Celebras,0,0, 53,      0,@Celebras,0,7046,0,0,17, 0,100,0,     0,    0,     0,0, "Celebras the Redeemed - On Text 0 Over - Start Waypoint"),
(@Celebras,0, 2, 3, 40,0,100,0,   2,@Celebras,0,0,  1,      1,     4000,0,   0,0,0, 0, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Waypoint 2 Reached - Say Line 1"),
(@Celebras,0, 3, 0, 61,0,100,0,   0,        0,0,0, 54,   4000,        0,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Waypoint 2 Reached - Pause Waypoint"),
(@Celebras,0, 4, 0, 40,0,100,0,   3,@Celebras,0,0,  1,      3,     4000,0,   0,0,0, 0, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Waypoint 3 Reached - Say Line 3"),
(@Celebras,0, 5, 0, 40,0,100,0,   4,@Celebras,0,0,103,      1,        0,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Waypoint 4 Reached - Set Rooted On"),
(@Celebras,0, 6, 7, 52,0,100,0,   3,@Celebras,0,0,  1,      4,     4000,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Text 3 Over - Text Emote Line 4"),
(@Celebras,0, 7, 8, 61,0,100,0,   0,        0,0,0, 11,  32994,        0,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Text 3 Over - Cast 'Rejuvenation Impact Visual'."),
(@Celebras,0, 8, 9, 61,0,100,0,   0,        0,0,0, 50,@GO_IoC,    30000,0,   0,0,0, 8, 0,  0,0,   652, 73.5,-85.34,0, "Celebras the Redeemed - On Text 3 Over - Summon Gameobject 'Incantation of Celebras'."),
(@Celebras,0, 9,10, 61,0,100,0,   0,        0,0,0, 11,  21916,        0,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Text 3 Over - Cast 'Celebras Waiting'."),
(@Celebras,0,10, 0, 61,0,100,0,   0,        0,0,0,  1,      5,     4000,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Text 3 Over - Say Line 5"),
(@Celebras,0,11,12, 38,0,100,0,   0,        1,0,0, 65,      0,        0,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Data Set 0 1 - Resume Waypoint"),
(@Celebras,0,12,13, 61,0,100,0,   0,        0,0,0,  1,      6,     2000,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Data Set 0 1 - Say Line 6"),
(@Celebras,0,13,15, 61,0,100,0,   0,        0,0,0, 84,      6,        0,0,   0,0,0,21,20,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Data Set 0 1 - Say Line 6"),
(@Celebras,0,14,17, 40,0,100,0,   8,@Celebras,0,0,  1,      7,     2000,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Waypoint 8 Reached - Say Line 7"),
(@Celebras,0,15, 0, 61,0,100,0,   0,        0,0,0, 50, 178964,     2000,0,   0,0,0, 8, 0,  0,0,650.98,74.45,-86.86,0, "Celebras the Redeemed - On Data Set 0 1 - Summon Gameobject 'Celebras Blue Aura'."),
(@Celebras,0,16, 0, 56,0,100,0,   2,@Celebras,0,0,  1,      2,     2000,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Waypoint Resumed - Say Line 2"),
(@Celebras,0,17, 0, 61,0,100,0,   0,        0,0,0, 54,   2000,        0,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Waypoint 8 Reached - Pause Waypoint"),
(@Celebras,0,18, 0, 61,0,100,0,   0,        0,0,0, 83,      3,        0,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Quest 'The Scepter of Celebras' Taken - Remove Npc Flags Gossip & Questgiver"),
(@Celebras,0,19, 0, 40,0,100,0,  11,@Celebras,0,0, 82,      3,        0,0,   0,0,0, 1, 0,  0,0,     0,    0,     0,0, "Celebras the Redeemed - On Waypoint 11 Reached - Add Npc Flags Gossip & Questgiver");

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`= @GO_IoC;
UPDATE `gameobject_template_addon` SET `flags` = 64 WHERE `entry` = @GO_IoC;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @GO_IoC AND `source_type`= 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GO_IoC,1,0,1,70,0,100,1,2, 0,0,0, 85,21950, 1,0,0,0,0, 7,        0, 0,0,0,0,0,0, "Incantation of Celebras - On Gameobject State Changed - Invoker Cast 'Recite Words of Celebras' (No Repeat)"),
(@GO_IoC,1,1,2,61,0,100,0,0, 0,0,0,105,   16, 0,0,0,0,0, 1,        0, 0,0,0,0,0,0, 'Incantation of Celebras - On Gameobject State Changed - Add gameobject flags Not Selectable (target self)'),
(@GO_IoC,1,2,3,61,0,100,0,0, 0,0,0, 45,    0, 1,0,0,0,0,11,@Celebras,20,0,0,0,0,0, 'Incantation of Celebras - On Gameobject State Changed - Set Data 0 1, target Celebras, max 20 yards dist.'),
(@GO_IoC,1,3,0,61,0,100,0,0, 0,0,0,  9,    0, 0,0,0,0,0,15,   178560,20,0,0,0,0,0, 'Incantation of Celebras - On Gameobject State Changed - Activate Gameobject Doodad_MaraudonStaffCreator01');
