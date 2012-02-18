-- Fix quest What Illidan Wants, Illidan Gets...
-- Make the npc_text entries work properly
DELETE FROM `gossip_menu` WHERE `entry` IN (8336,8342,8341,8340,8339,8338) AND `text_id` IN (10401,10405,10406,10407,10408,10409);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES 
(8336,10401),
(8342,10405),
(8341,10406),
(8340,10407),
(8339,10408),
(8338,10409);

-- Conditions for gossip menu of quest What Illidan Wants, Illidan Gets...
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8336;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8336,0,0,9,10577,0,0,0,'','Only show first gossip if player is on quest What Illidan Wants, Illidan Gets...');

-- Insert options (for players)
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8336,8342,8341,8340,8339,8338);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(8336,0,0,'I bring word from Lord Illidan.',1,1,8342),
(8342,0,0,'The cipher fragment is to be moved. Have it delivered to Zuluhed.',1,1,8341),
(8341,0,0,'Perhaps you did not hear me, Ruusk. I am giving you an order from Illidan himself!',1,1,8340),
(8340,0,0,'Very well. I will return to the Black Temple and notify Lord Illidan of your unwillingness to carry out his wishes. I suggest you make arrangements with your subordinates and let them know that you will soon be leaving this world.',1,1,8339),
(8339,0,0,'Do I need to go into all the gory details? I think we are both well aware of what Lord Illidan does with those that would oppose his word. Now, I must be going! Farewell, Ruusk! Forever...',1,1,8338),
(8338,0,0,'Ah, good of you to come around, Ruusk. Thank you and farewell.',1,1,0); -- Here the quest credit is given

-- Commander Ruusk SAI
UPDATE `creature_template` SET `gossip_menu_id`=8336,`AIName`='SmartAI' WHERE `entry`=20563;
DELETE FROM `smart_scripts` WHERE `entryorguid`=20563 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20563,0,0,1,62,0,100,0,8338,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Commander Ruusk - On Gossip Select - Close Gossip'),
(20563,0,1,0,61,0,100,0,0,0,0,0,26,10577,0,0,0,0,0,7,0,0,0,0,0,0,0,'Commander Ruusk - On Gossip Select (link) - Quest Credit');
