-- Remove unneeded SMART_ACTION_SEND_GOSSIP_MENU actions
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1855,12144) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1855,0,0,1,62,0,100,0,3683,0,0,0,0,15,5742,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tirion Fordring - On Gossip Option 0 Selected - Quest Credit 'Redemption'"),
(1855,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tirion Fordring - On Link - Close Gossip"),
(12144,0,0,0,54,0,100,0,0,0,0,0,0,11,17321,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lunaclaw Spirit - On Just Summoned - Cast 'Spirit Spawn-in'"),
(12144,0,1,0,62,0,100,0,3862,0,0,0,0,15,6001,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lunaclaw Spirit - On Gossip Option 0 Selected - Quest Credit 'Body and Heart'"),
(12144,0,2,0,62,0,100,0,3862,1,0,0,0,15,6002,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lunaclaw Spirit - On Gossip Option 1 Selected - Quest Credit 'Body and Heart'");

-- Remove CONDITION_STAND_STATE, https://youtu.be/Fiu_sVevUyw?t=91
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 3502 AND `ConditionTypeOrReference` = 42;
-- Just check if quest is taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 3862;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,3862,0,0,0,47,0,6001,10,0,0,0,0,"","Group 0: Show Gossip Option 0 if player has taken quest 'Body and Heart'"),
(15,3862,1,0,0,47,0,6002,10,0,0,0,0,"","Group 0: Show Gossip Option 1 if player has taken quest 'Body and Heart'");
