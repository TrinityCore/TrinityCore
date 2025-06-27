-- Lorax SAI
SET @ENTRY  := 10918;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,3047,0,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lorax - On Gossip Option Select - Laugh emote'),
(@ENTRY,0,1,2,62,0,100,0,3044,0,0,0,15,5126,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lorax - On Gossip Option Select - Give Quest Credit'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lorax - On Gossip Option Select - Close gossip');
-- Lorax Gossip
DELETE FROM `gossip_menu` WHERE `MenuID` IN (3048,3047,3046,3045,3044, 21322,21323,21324,21325,21326);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES (3048,3759),(3047,3760),(3046,3761),(3045,3762),(3044,3763);
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (3049,3048,3047,3046,3045,3044, 21322,21323,21324,21325,21326);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`) VALUES
(3049,0,0, 'You will have to excuse me, Lorax, I do not speak ''crazy''.',6241,1,1,3048,0,0,0, ''),
(3048,0,0, 'My apologies, I did not realize that you could understand what I was saying. What is it you are doing out here?',6243,1,1,3047,0,0,0, ''),
(3047,0,0, 'Do you? Perhaps you should tell me what it is that is bothering you',6245,1,1,3046,0,0,0, ''),
(3046,0,0, 'What deal?',6247,1,1,3045,0,0,0, ''),
(3045,0,0, 'So how did he break the deal?',6249,1,1,3044,0,0,0, ''),
(3044,0,0, 'Perhaps I can be of some assistance. I will make a deal with you, Satyr. I shall recover this unforged breastplate and slay the beast. In exchange for this task, you will teach me how to create the breastplate',6251,1,1,0,0,0,0, '');
