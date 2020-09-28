--
DELETE FROM `gossip_menu` WHERE `MenuID` = 6443 AND `TextID` = 7637;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES
(6443,7637,0);

DELETE FROM `npc_text` WHERE `ID` = 7637;
INSERT INTO `npc_text` (`ID`,`text0_0`,`BroadcastTextID0`,`lang0`,`Probability0`) VALUES
(7637,"The markings of this tablet show ancient diagrams and hold dire words of power.$B$BYou believe it is an alchemical recipe, but it is beyond your skill...",10487,0,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 6443;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,6443,7635,0,0,25,0,2259,0,0,1,0,0,"","Group 0: Show gossip text 7635 if spell 'Alchemy' is not learned"),
(14,6443,7636,0,0,7,0,171,300,0,0,0,0,"","Group 0: Show gossip text 7636 if player has Alchemy with skill level 300"),
(14,6443,7637,0,0,25,0,2259,0,0,0,0,0,"","Group 0: Show gossip text 7637 if spell 'Alchemy' is learned"),
(14,6443,7637,0,0,7,0,171,300,0,1,0,0,"","Group 0: Show gossip text 7637 if player has not Alchemy with skill level 300");

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 6443;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(6443,0,0,"Learn the recipe.",10486,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 6443;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,6443,0,0,0,7,0,171,300,0,0,0,0,"","Group 0: Show Gossip Option 0 if player has Alchemy with skill level 300"),
(15,6443,0,0,0,25,0,24266,0,0,1,0,0,"","Group 0: Show Gossip Option 0 if spell 'Gurubashi Mojo Madness' is not learned");

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = 180368;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 180368 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(180368,1,0,1,62,0,100,0,6443,0,0,0,0,85,24267,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tablet of Madness - On Gossip Option 0 Selected - Self Cast 'Gurubashi Mojo Madness'"),
(180368,1,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tablet of Madness - On Link - Close Gossip");
