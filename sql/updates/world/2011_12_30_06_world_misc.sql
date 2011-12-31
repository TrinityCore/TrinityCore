-- Thanks to @Aokromes for the sniff and @malcrom for all the help
-- NPC gossip update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8523 WHERE `entry`=22127;

-- Gossip insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8523;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8523,10657);

-- Gossip option suggested by Malcrom "text made up"
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8523;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8523,0,0,"Can I get another Felsworn Gas Mask?",1,1,0,0,0,0,'');

-- Gossip option conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=8523);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8523,0,1,9,10819,0,0,0,'','Show gossip only if Felsworn Gas Mask quest is rewarded'),
(15,8523,0,1,26,31366,0,0,0,'','Show gossip only if player doesnt have Felsworn Gas Mask');

-- SAI for Wildlord Antelarion
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=22127;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=22127 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(22127,0,0,0,62,0,100,0,8523,0,0,0,11,39101,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wildlord Antelarion - On Gossip option select - Cast Create Felsword Gas Mask');
