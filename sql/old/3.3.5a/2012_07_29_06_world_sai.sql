-- Remove previous fix
DELETE FROM `gossip_menu` WHERE `entry` = 9640;
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 9640;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28041 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28041*100 AND `source_type` = 9;
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId= 15  AND SourceGroup = 9640;

-- Argent Crusade, We Are Leaving! (12504)

SET @ENTRY := 28041; -- Argent Soldier
SET @SOURCETYPE := 0;
SET @CREDIT := 50289; -- Argent Crusade, We Are Leaving!: Argent Soldier Quest Credit
SET @MENUID := 9640;
SET @OPTION := 0;

UPDATE `creature_template` SET `gossip_menu_id`=@MENUID,`npcflag`=1,`AIName`='SmartAI' WHERE `entry`=@ENTRY;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@MENUID AND `id`=@OPTION;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@MENUID,@OPTION,0,"Soldier, you have new orders. You're to pull back and report to the sergeant!",1,1,0,0,0,0,'');

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,8000,10000,8000,12000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,"IC - Cast Sunder Armor - Victim"),
(@ENTRY,@SOURCETYPE,1,2,62,0,100,0,@MENUID,@OPTION,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"On gossip select - Close Gossip - Invoker"),
(@ENTRY,@SOURCETYPE,2,3,61,0,100,0,0,0,0,0,11,@CREDIT,0,0,0,0,0,7,0,0,0,0,0,0,0,"On link - Cast credit spell - Invoker"),
(@ENTRY,@SOURCETYPE,3,4,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"On link - Whisper - Invoker"),
(@ENTRY,@SOURCETYPE,4,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On link - Despawn - Self");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@MENUID AND `SourceEntry`=@OPTION;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@MENUID,@OPTION,2,9,12504,0,0,0,'',"Show gossip option 0 if player has quest 12504 marked as taken");

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Careful here, $C. These trolls killed their own snake god!",15,0,50,0,0,0,"Argent Soldier whisper text"),
(@ENTRY,0,1,"Watch your back. These Drakkari are a nasty lot.",15,0,50,0,0,0,"Argent Soldier whisper text"),
(@ENTRY,0,2,"These Drakkari are just bad news. We need to leave and head back to Justice Keep!",15,0,50,0,0,0,"Argent Soldier whisper text"),
(@ENTRY,0,3,"See you around.",15,0,50,0,0,0,"Argent Soldier whisper text"),
(@ENTRY,0,4,"I wonder where we're headed to. And who's going to deal with these guys?",15,0,50,0,0,0,"Argent Soldier whisper text"),
(@ENTRY,0,5,"Right. I'd better get back to the sergeant then.",15,0,50,0,0,0,"Argent Soldier whisper text"),
(@ENTRY,0,6,"Are you $N? I heard you were dead.",15,0,50,0,0,0,"Argent Soldier whisper text");
