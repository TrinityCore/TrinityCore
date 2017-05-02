-- Slaves of the Stormforged quest fix by nelegalno
-- Closes #4498

SET @MENUID := 9871;
SET @TEXTID := 13682;

-- Gossip insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=@MENUID;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@MENUID,@TEXTID);

-- Gossip option from sfiff
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@MENUID,0,0,"I'm not a laborer. I'm here to free you from servitude in the mines.",1,1,0,0,0,0,'');

-- SAI workaround
-- TODO: quest probably uses Trigger Captive Mechagnome Signal ( http://old.wowhead.com/spell=55874 ) and Captive Mechagnome Signal ( http://old.wowhead.com/spell=55875 )
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29384;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=29384 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(29384,0,0,1,62,0,100,1,9871,0,0,0,33,29962,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captive Mechagnome - on gossip select 9871 - Slaves of the Stormforged quest credit'),
(29384,0,1,2,61,0,100,1,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captive Mechagnome - on gossip select 9871 - close gossip'),
(29384,0,2,0,61,0,100,1,0,0,0,0,41,30,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captive Mechagnome - on gossip select 9871 - close gossip');

-- Gossip option conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=@MENUID);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@MENUID,0,0,9,12957,0,0,0,'','Show gossip only if Slaves of the Stormforged quest taken');
