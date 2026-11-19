-- Creature_AI to Smart_AI Conversion for Proto-Drake Egg (ID 23777)
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` =23777;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=23777;
DELETE FROM `smart_scripts` WHERE `entryorguid` =23777;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23777,0,0,1,25,0,100,0,0,0, 0, 0, 21 ,0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Proto-Drake Egg - On Spawn - Prevent Combat Movement"),
(23777,0,1,0,61,0,100,0,0,0, 0, 0, 20 ,0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Proto-Drake Egg - Linked with Previous Event - Disable Combat"),
(23777,0,2,3,8 ,0,100,0,46606,0, 0, 0, 12 ,24160, 1, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Proto-Drake Egg - On Spellhit Tillinghast's Plague Canister Dummy - Spawn Plagued Proto-Whelp"),
(23777,0,3,0,61,0,100,0,0,0, 0, 0, 37 ,0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Proto-Drake Egg - Linked with Previous Event - Die"),
(23777,0,4,0,6 ,1,100,0,0,0, 0, 0, 12 ,23688, 1, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Proto-Drake Egg - On Death - Spawn Proto-Whelp"),
(23777,0,5,0,4, 0,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, "Proto-Drake Egg - On Aggro - Set Phase 2");
