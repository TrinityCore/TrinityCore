-- Lorax SAI
SET @ENTRY  := 10918;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,3051,0,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lorax - On Gossip Option Select - Laugh emote'),
(@ENTRY,0,1,2,62,0,100,0,3054,0,0,0,15,5126,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lorax - On Gossip Option Select - Give Quest Credit'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lorax - On Gossip Option Select - Close gossip');
-- Lorax Gossip
DELETE FROM `gossip_menu` WHERE `entry` IN (3050,3051,3052,3053,3054);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (3050,3759),(3051,3760),(3052,3761),(3053,3762),(3054,3763);
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN 3049 AND 3054;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(3049,0,0, 'You will have to excuse me, Lorax, I do not speak ''crazy''.',1,1,3050,0,0,0, ''),
(3050,0,0, 'My apologies, I did not realize that you could understand what I was saying. What is it you are doing out here?',1,1,3051,0,0,0, ''),
(3051,0,0, 'Do you? Perhaps you should tell me what it is that is bothering you',1,1,3052,0,0,0, ''),
(3052,0,0, 'What deal?',1,1,3053,0,0,0, ''),
(3053,0,0, 'So how did he break the deal?',1,1,3054,0,0,0, ''),
(3054,0,0, 'Perhaps I can be of some assistance. I will make a deal with you, Satyr. I shall recover this unforged breastplate and slay the beast. In exchange for this task, you will teach me how to create the breastplate',1,1,0,0,0,0, '');
-- Add conditions for gossip options
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3049;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,3049,0,0,9,5126,0,0,0,0,'','Only show gossip option if player has quest 5126');
