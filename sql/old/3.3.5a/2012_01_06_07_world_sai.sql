-- Fix Quest 11795, 11887 'Emergency Protocol: Section 8.2, Paragraph C', 'Emergency Supplies' 
SET @NPC    :=25841; -- Fizzcrank Recon Pilot
SET @Gossip :=21248;

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=@Gossip AND `id`=1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@Gossip,1,0,"Search the body for the pilot's insignia.",1,1,0,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceGroup`=21248;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@Gossip,0,0,9,11887,0,0,0,'',''),
(15,@Gossip,1,0,9,11795,0,0,0,'','');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,0,11,0,100,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - On spawn - set gossip flag'),
(@NPC,0,1,2,62,0,100,0,@Gossip,0,0,0,11,46362,2,0,0,0,0,7,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - On gossip option 0 select - cast spell'),
(@NPC,0,2,3,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - close gossip'),
(@NPC,0,3,7,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - remove gossip flag'),
(@NPC,0,4,5,62,0,100,0,@Gossip,1,0,0,11,46166,2,0,0,0,0,7,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - On gossip option 1 select - cast spell'),
(@NPC,0,5,6,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - close gossip'),
(@NPC,0,6,7,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - remove gossip flag'),
(@NPC,0,7,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - Despawn');
