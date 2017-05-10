-- And Now, the Moment of Truth (10201) quest fix
SET @ENTRY := 19606;
-- texts
-- DELETE FROM `creature_ai_texts` WHERE `entry` IN (-247,-246,-245,-244);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Someone come read this wanted poster to Grek. Grek can't read.",12,0,100,18,0,6941,"Grek1"),
(@ENTRY,1,0,"Grek get a drink.",12,0,100,7,0,0,"Grek2"),
(@ENTRY,2,0,"Grek try!",12,0,100,5,0,0,"Grek - Quest1"),
(@ENTRY,3,0,"This oil no good for Grek! What Grek look like to you, some weakling in robes?",12,0,100,6,0,0,"Grek - Quest2");
-- gossips
-- UPDATE `creature_template` SET `gossip_menu_id` = 7999 WHERE `entry` = @ENTRY; -- YTDB value (should work fine until someone can sniff/verify)
-- DELETE FROM `gossip_menu` WHERE `entry`=7999 AND `text_id`=9853;
-- INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7999,9853); -- YTDB value (should work fine until someone can sniff/verify)
-- DELETE FROM `gossip_menu_option` WHERE `menu_id`=7999;
-- INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
-- (7999,0,0,"Grek, will you try out this new weapon oil Rakoria made?",1,1,0,0,0,0,''); -- YTDB value (should work fine until someone can sniff/verify)
-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` = @ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,120000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Grek - OOC - Say Grek1"),
(@ENTRY,0,1,0,1,0,100,0,420000,420000,420000,420000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Grek - OOC - Say Grek2"),
(@ENTRY,0,2,3,62,0,100,0,7999,0,0,0,1,2,3000,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Grek - On gossip select - Say Quest1"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Grek - Link - Close gossip"),
(@ENTRY,0,4,5,52,0,100,0,2,@ENTRY,0,0,1,3,10000,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Grek - On text_over - Say Quest2"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,33,@ENTRY,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Grek - Link - Give quest credit");
-- conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7999 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7999,0,0,0,9,0,10201,0,0,0,0,'',"Display gossip only if quest taken");
