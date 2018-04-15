SET @SWIFTSPEAR := 30395;
SET @GOSSIP :=9906;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,0,0,'I am sorry to disturb your rest, chieftain, but your brother''s spirit may be in danger. Would you tell me what you remember of him?',1,1,0,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,0,0,0,9,0,13037,0,0,0,0,'','Show gossip option only if player has quest Memories of Stormhoof');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@SWIFTSPEAR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SWIFTSPEAR AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SWIFTSPEAR*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SWIFTSPEAR,0,0,1,62,0,100,0,@GOSSIP,0,0,0,11,56760,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Chieftain Swiftspear - On gossip select - Spellcast Trigger Swiftspear Signal'),
(@SWIFTSPEAR,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Chieftain Swiftspear - On gossip select - Close gossip'),
(@SWIFTSPEAR,0,2,0,61,0,100,0,0,0,0,0,80,@SWIFTSPEAR*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear - On gossip select - Run script'),

(@SWIFTSPEAR*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Say line'),
(@SWIFTSPEAR*100,9,1,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Remove npcflag gossip'),
(@SWIFTSPEAR*100,9,2,0,0,0,100,0,6800,6800,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Say line'),
(@SWIFTSPEAR*100,9,3,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Say line'),
(@SWIFTSPEAR*100,9,4,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Say line'),
(@SWIFTSPEAR*100,9,5,0,0,0,100,0,6100,6100,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Say line'),
(@SWIFTSPEAR*100,9,6,0,0,0,100,0,7200,7200,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Say line'),
(@SWIFTSPEAR*100,9,7,0,0,0,100,0,6000,6000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Say line'),
(@SWIFTSPEAR*100,9,8,0,0,0,100,0,3600,3600,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Play emote'),
(@SWIFTSPEAR*100,9,9,0,0,0,100,0,2700,2700,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Add npcflag gossip'),
(@SWIFTSPEAR*100,9,10,0,0,0,100,0,0,0,0,0,33,30381,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Chieftain Swiftspear script - Quest credit');

DELETE FROM `creature_text` WHERE `entry`=@SWIFTSPEAR;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SWIFTSPEAR,0,0,'My brother, Stormhoof, was a far greater warrior than I. While I trained to be the chieftain of our clan, he prepared for a larger quest.',12,0,100,1,0,0,'Chieftain Swiftspear'),
(@SWIFTSPEAR,1,0,'How could he be in danger? All he wanted was to give us power over the elements that made life harsh for us here.',12,0,100,1,0,0,'Chieftain Swiftspear'),
(@SWIFTSPEAR,2,0,'He sought an artifact... a horn, I think. He left the village on a long journey in search of it.',12,0,100,6,0,0,'Chieftain Swiftspear'),
(@SWIFTSPEAR,3,0,'I know that a terrible enemy pursued him after he won the horn, but I... I don''t recall... what happened... next.',12,0,100,5,0,0,'Chieftain Swiftspear'),
(@SWIFTSPEAR,4,0,'It is as though my memories are shrouded in mist. I cannot even recall what became of my brother. Is this how you mean that he is in danger?',12,0,100,274,0,0,'Chieftain Swiftspear'),
(@SWIFTSPEAR,5,0,'The disturbances in the tomb, they must be involved. Look around you, $N. Do you see them?',12,0,100,25,0,0,'Chieftain Swiftspear'),
(@SWIFTSPEAR,6,0,'Yes, they are at fault, but I am powerless to stop them. Will you warn the people of Tunka''lo, stranger, that their past and their ancestors are in danger?',12,0,100,1,0,0,'Chieftain Swiftspear');
