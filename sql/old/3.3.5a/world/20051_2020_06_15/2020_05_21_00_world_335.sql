-- Source: https://youtu.be/kVfgLG_62uA?list=PLDE1B8773F01F292B&t=296 https://youtu.be/kVfgLG_62uA?list=PLDE1B8773F01F292B&t=485
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7891;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7891,9654,0,0,8,0,10109,0,0,1,0,0,"","Group 0: Show gossip text 9654 if quest 'I Must Have Them!' is not rewarded"),
(14,7891,9659,0,0,8,0,10109,0,0,0,0,0,"","Group 0: Show gossip text 9659 if quest 'I Must Have Them!' is rewarded");

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 7891;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(7891,0,0,"Wazat, I have done something foolish and have lost my key as a result of this action. Could I trouble you for a spare?",16144,1,1,7894,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 7891;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7891,0,0,0,8,0,10109,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if quest 'I Must Have Them!' is rewarded"),
(15,7891,0,0,0,2,0,27808,1,1,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have item 'Jump-a-tron 4000 Key'");

DELETE FROM `gossip_menu` WHERE `MenuID` = 7894;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(7894,9658);
DELETE FROM `npc_text` WHERE `ID` = 9658;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `EmoteDelay0_0`, `Emote0_0`, `EmoteDelay0_1`, `Emote0_1`, `EmoteDelay0_2`, `Emote0_2`) VALUES 
(9658,"Anything for you, $n!","",16145,0,100,0,5,0,1,0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 19035 AND `source_type` = 0 AND `id` = 3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19035,0,3,0,62,0,100,0,7891,0,0,0,0,11,33383,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Wazat - On Gossip Option 0 Selected - Cast 'Spare Jump-a-tron Key'");
