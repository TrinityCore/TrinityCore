-- Gossip for npc 6497 Astor Hadren from sniff
UPDATE `creature_template` SET `gossip_menu_id`=126,`AIName`='SmartAI',`ScriptName`='' WHERE `entry`=6497;
DELETE FROM `gossip_menu` WHERE `entry`=126 AND `text_id`=623;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (126,623);
DELETE FROM `gossip_menu` WHERE `entry`=125 AND `text_id`=624;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (125,624);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (126,125);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(126,0,0, "You''re Astor Hadren, right?",1,1,125),
(125,0,0, "You''ve got something I need, Astor. And I''ll be taking it now.",1,1,0);
-- SAI for npc 6497 Astor Hadren
DELETE FROM `smart_scripts` WHERE `entryorguid`=6497;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6497,0,0,0,62,0,100,0,125,0,0,0,2,21,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Astor Hadren - Make Hostile on Gossip Select');
-- Gossip option condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=126;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
(15,126,0,0,9,14420, 'Show Gossip Option If quest The Deathstalkers(new) is Incomplete');
