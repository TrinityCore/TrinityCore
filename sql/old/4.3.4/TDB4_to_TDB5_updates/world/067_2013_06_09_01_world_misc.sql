-- Fix quest To Westguard Keep! (11291)

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9618;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9618,0,0,'Admiral Keller sent me, Emilune. Please send me to Westguard Keep!',1,1,0,0,0,0,'');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=27930;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27930 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27930,0,0,1,62,0,100,0,9618,0,0,0,11,50028,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Emilune Winterwind - On gossip option select - Spellcast Gryphon Taxi to Westguard Keep'),
(27930,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Emilune Winterwind - On gossip option select - Close gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9618;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9618,0,0,28,11291,0,0,0,'','Emilune Winterwind show gossip option only if player has rewarded but not completed quest To Westguard Keep!');
