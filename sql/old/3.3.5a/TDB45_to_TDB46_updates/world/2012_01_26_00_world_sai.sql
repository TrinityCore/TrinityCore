-- Quest Elven Legends (7481, 7482)
-- Skeletal Remains of Kariel Winthalus SAI
SET @ENTRY  := 179544; -- GO entry
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,62,0,100,0,5743,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Skeletal Remains of Kariel Winthalus - On Gossip option select - run script'),
(@ENTRY,1,1,0,62,0,100,0,5743,1,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Skeletal Remains of Kariel Winthalus - On Gossip option select - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Skeletal Remains of Kariel Winthalus - Script - Close Gossip'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Skeletal Remains of Kariel Winthalus - Script - Store target'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,11,14368,30,0,0,0,0,0, 'Skeletal Remains of Kariel Winthalus - Script - Send target'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,14368,30,0,0,0,0,0,'Skeletal Remains of Kariel Winthalus - Script - Set data 0 1 for entry 14368'),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skeletal Remains of Kariel Winthalus - Script - Deactivate self'),
(@ENTRY*100,9,5,0,0,0,100,0,28000,28000,28000,28000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skeletal Remains of Kariel Winthalus - Script - Activate self');
-- Lorekeeper Lydros SAI
SET @ENTRY := 14368; -- NPC entry
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,0,1,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lorekeeper Lydros - On dataset - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lorekeeper Lydros - Script - set data 0 0'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,1000,1000,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Lorekeeper Lydros - Script - turn to player'),
(@ENTRY*100,9,2,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lorekeeper Lydros - Script - Say 0'),
(@ENTRY*100,9,3,0,0,0,100,0,4000,4000,4000,4000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lorekeeper Lydros - Script - Say 1'),
(@ENTRY*100,9,4,0,0,0,100,0,8000,8000,8000,8000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lorekeeper Lydros - Script - Say 2'),
(@ENTRY*100,9,5,0,0,0,100,0,11000,11000,11000,11000,15,7481,0,0,0,0,0,12,1,0,0,0,0,0,0,'Lorekeeper Lydros - Script - quest credit'),
(@ENTRY*100,9,6,0,0,0,100,0,0,0,0,0,15,7482,0,0,0,0,0,12,1,0,0,0,0,0,0,'Lorekeeper Lydros - Script - quest credit'),
(@ENTRY*100,9,7,0,0,0,100,0,2000,2000,2000,2000,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lorekeeper Lydros - Script - reset orientation');
-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry`=14368;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(14368,0,0, 'I very much doubt that he will have anything to say, stranger...',12,0,100,1,0,0, 'Lorekeeper Lydros'),
(14368,1,0, 'I personally did not mind him. It was the Prince who took exception to a high elf in his domain. Alas, I am not one to question the Prince. In his defense, he did not incinerate Master Winthalus immediately.',12,0,100,1,0,0, 'Lorekeeper Lydros'),
(14368,2,0, 'We most definitely do not need anymore attention drawn to us, stranger. Return to those that sent you in search of the lost master and tell them that nothing could be found. When this is done - and I will know when it is so - return and I shall reveal the secrets of the deceased.',12,0,100,1,0,0, 'Lorekeeper Lydros');
-- Gossip Fix from nelegalno
DELETE FROM `gossip_menu_option` WHERE `menu_id`=5743;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(5743,0,0,"Mourn the great loss.",1,1,0,0,0,0,NULL), -- A gossip
(5743,1,0,"Mourn the great loss.",1,1,0,0,0,0,NULL); -- H gossip
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=5743);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,5743,0,0,9,7482,0,0,0,'',"Display gossip option when on Elven Legends A quest"),
(15,5743,1,0,9,7481,0,0,0,'',"Display gossip option when on Elven Legends H quest");
