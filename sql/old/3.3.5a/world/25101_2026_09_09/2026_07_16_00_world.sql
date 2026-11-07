--
DELETE FROM `spell_target_position` WHERE `ID` IN (12885,13142,27694);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(12885,0,0,-11235.3,-2832.14,157.925,4.71,0),
(13142,0,0,-11235.3,-2832.14,157.925,4.71,0),
(27694,0,0,-11235.3,-2832.14,157.925,4.71,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 1541 AND `OptionID` = 1;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(1541,1,0,"We wish to face the Defiler.",11869,1,1,0,0,0,0,"",0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 8816 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8816,0,0,0,62,0,100,0,1541,0,0,0,0,11,12885,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Deathly Usher - On Gossip Option 0 Selected - Cast 'Teleport to Razelikh'"),
(8816,0,1,0,62,0,100,0,1541,1,0,0,0,11,27686,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Deathly Usher - On Gossip Option 1 Selected - Cast 'Teleport to Razelikh (GROUP)'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 1541;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1541,0,0,0,47,0,3628,10,0,'',0,0,0,'',"Group 0: Show Gossip Option 0 if player has taken quest 'You Are Rakh'likh, Demon'"),
(15,1541,0,0,0,2,0,10757,1,0,'',0,0,0,'',"Group 0: Show Gossip Option 0 if player has item 'Ward of the Defiler'"),
(15,1541,0,0,0,60,0,0,0,0,'',0,0,0,'',"Group 0: Show Gossip Option 0 if player is not in group"),

(15,1541,1,0,0,47,0,3628,10,0,'',0,0,0,'',"Group 0: Show Gossip Option 1 if player has taken quest 'You Are Rakh'likh, Demon'"),
(15,1541,1,0,0,2,0,10757,1,0,'',0,0,0,'',"Group 0: Show Gossip Option 1 if player has item 'Ward of the Defiler'"),
(15,1541,1,0,0,60,0,1,0,0,'',0,0,0,'',"Group 0: Show Gossip Option 1 if player is in group");

UPDATE `spell_script_names` SET `ScriptName` = 'spell_blasted_lands_teleport_to_razelikh_group' WHERE `ScriptName` = 'spell_razelikh_teleport_group';
