-- Saronite Mine Slave SAI
SET @ENTRY := 31397;
SET @QUEST := 13300;
SET @GOSSIP := 10137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,@GOSSIP,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Saronite Mine Slave - On Gossip Select - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,1,0,0,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Saronite Mine Slave - On Script - Close Gossip"),
(@ENTRY*100,9,1,0,0,0,100,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Saronite Mine Slave - On Script - Yell Line (random)"),
(@ENTRY*100,9,2,0,0,0,100,1,0,0,0,0,33,31866,0,0,0,0,0,0,0,0,0,0,0,0,0,"Saronite Mine Slave - On Script - Quest Credit"),
(@ENTRY*100,9,3,0,0,0,100,1,0,0,0,0,41,5000,0,0,0,0,0,0,0,0,0,0,0,0,0,"Saronite Mine Slave - On Script - Force Despawn");

-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"AHAHAHAHA... you'll join us soon enough!",14,0,100,0,0,0,"Saronite Mine Slave"),
(@ENTRY,0,1,"I don't want to leave! I want to stay here!",14,0,100,0,0,0,"Saronite Mine Slave"),
(@ENTRY,0,2,"NO! You're wrong! The voices in my head are beautiful!",14,0,100,0,0,0,"Saronite Mine Slave"),
(@ENTRY,0,3,"My life for you!",14,0,100,0,0,0,"Saronite Mine Slave"),
(@ENTRY,0,4,"I'm coming, master!",14,0,100,0,0,0,"Saronite Mine Slave");

-- Actual story menu
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=14068;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,14068);

-- Insert option menu
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(@GOSSIP,0,0,"Go on, you're free. Get out of here!",1,1,0);

-- Only show gossip if player is on quest Slaves to Saronite
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP AND `ConditionValue1`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,0,0,9,@QUEST,0,0,0,'',"Only show first gossip if player is on quest Slaves to Saronite");
