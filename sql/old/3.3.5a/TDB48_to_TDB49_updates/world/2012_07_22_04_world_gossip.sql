-- NPC Cowlen - Missing Gossip Options
SET @NPC := 17311;
DELETE FROM `creature_addon` WHERE `guid`=84415;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(84415,0,0,1,0,0,NULL);
UPDATE `creature_template` SET `gossip_menu_id`=7403, `AIName`='SmartAI' WHERE `entry`=@NPC;
DELETE FROM `gossip_menu` WHERE `entry` IN (7403,7402,7401);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7403,8870),
(7402,8871),
(7401,8872);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7403,7402,7401) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7403,0,0, 'I have not come to kill you, night elf. And the gods did not do this...',1,1,7402,0,0,0, ''),
(7402,0,0, 'I fear that my people are somewhat responsible for this destruction. We are refugees, displaced from our homes by the Burning Legion. This tragedy is a result of our latest evacuation. Our vessel crashed - this debris is a part of that vessel.',1,1,7401,0,0,0, ''),
(7401,0,0, 'We have much in common, night elf. I can''t help but feel that perhaps it was fate that brought us together. Let me help you, Cowlen. Let my people help. We will right the wrongs. This I vow.',1,1,0,0,0,0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,1,62,0,100,0,7401,0,0,0,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cowlen - On gossip option play emote'),
(@NPC,0,1,0,61,0,100,0,7401,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Cowlen - On gossip option Close Gossip');
