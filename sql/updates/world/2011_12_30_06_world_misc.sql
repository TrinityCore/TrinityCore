-- Thanks to @Aokromes for the sniff and @malcrom for all the help
-- NPC gossip update from sniff

UPDATE `creature_template` SET `gossip_menu_id`=8523 WHERE `entry`=22127;

-- Gossip insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8523;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8523,10657);

-- Gossip option sfiffed by Aokromes
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8523;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8523,0,0,"The Felsworn Gas Mask was destroyed, do you have another one?",1,1,0,0,0,0,'');

-- Gossip option conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=8523);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8523,0,0,9,10819,0,0,0,'','Show gossip only if Felsworn Gas Mask quest is taken'),
(15,8523,0,0,26,31366,0,0,0,'','Show gossip only if player doesnt have Felsworn Gas Mask'),
(15,8523,0,1,8,10819,0,0,0,'','Show gossip only if Felsworn Gas Mask quest is completed'),
(15,8523,0,1,26,31366,0,0,0,'','Show gossip only if player doesnt have Felsworn Gas Mask');

-- SAI for Wildlord Antelarion
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=22127;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=22127 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22127,0,0,1,62,0,100,0,8523,0,0,0,11,39101,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wildlord Antelarion - On Gossip option select - Cast Create Felsword Gas Mask'),
(22127,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wildlord Antelarion - On Gossip option select - Close Gossip'),
(22127,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildlord Antelarion - On Gossip option select - Say 0');

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (22127) AND `groupid` IN (0);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(22127,0,0, "It's a good thing I was able to make duplicates of the Felsworn Gas Mask.",12,0,100,1,0,0, 'Wildlord Antelarion');
