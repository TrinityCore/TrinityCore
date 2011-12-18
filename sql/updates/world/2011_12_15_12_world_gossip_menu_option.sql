-- Eitrigg's Wisdom fix ( https://github.com/TrinityCore/TrinityCore/issues/3592#issuecomment-2471834 [ http://pastebin.com/7gkg96p1 ]).
-- Closes https://github.com/TrinityCore/TrinityCore/issues/3592

SET @GOSSIP =2901;
SET @NPC = 3144;
SET @QUEST =4941;
-- Add gossip options for each menu id
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN @GOSSIP AND @GOSSIP+7;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(@GOSSIP, 0, 0, 'Hello, Eitrigg. I bring news from Blackrock Spire.', 1, 1, @GOSSIP+1, 0, 0, 0, ''),
(@GOSSIP+1, 0, 0, 'There is only one Warchief, Eitrigg!', 1, 1, @GOSSIP+2, 0, 0, 0, ''),
(@GOSSIP+2, 0, 0, 'What do you mean?', 1, 1, @GOSSIP+3, 0, 0, 0, ''),
(@GOSSIP+3, 0, 0, 'Hearthglen? But...', 1, 1, @GOSSIP+4, 0, 0, 0, ''),
(@GOSSIP+4, 0, 0, 'I will take you up on that offer, Eitrigg.', 1, 1, @GOSSIP+5, 0, 0, 0, ''),
(@GOSSIP+5, 0, 0, 'Ah, so that is how they pushed the Dark Iron to the lower parts of the Spire.', 1, 1, @GOSSIP+6, 0, 0, 0, ''),
(@GOSSIP+6, 0, 0, 'Perhaps there exists a way?', 1, 1, @GOSSIP+7, 0, 0, 0, ''),
(@GOSSIP+7, 0, 0, 'As you wish, Eitrigg.', 1, 1, 0, 0, 0, 0, '');
-- Add gossip menus (text values already in db)
DELETE FROM `gossip_menu` WHERE `entry`BETWEEN @GOSSIP+1 AND @GOSSIP+7;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(@GOSSIP+1, 3574),
(@GOSSIP+2, 3575),
(@GOSSIP+3, 3576),
(@GOSSIP+4, 3577),
(@GOSSIP+5, 3578),
(@GOSSIP+6, 3579),
(@GOSSIP+7, 3580);
-- Add Condtion so gossip only shows when on quest
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, @GOSSIP, 0, 0, 9, 4941, 0, 0, 0, '', NULL);
-- Add SAI for quest complete and close of gossip when last option selected
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,1,62,0,100,0,@GOSSIP+7,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Eitrigg - Select As you wish, Eitrigg. - Close gossip'),
(@NPC,0,1,0,61,0,100,0,0,0,0,0,15,@QUEST,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Eitrigg - on link - give credit quest(4941)');