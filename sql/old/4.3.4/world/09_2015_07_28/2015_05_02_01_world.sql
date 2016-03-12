DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=38606;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,38606,0,0,31,1,3,21326,0,0,0,0,'','Exorcism Feather can be used only on Raven''s Wood Leafbeard');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (21326, 22226);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21326, 22226) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21326, 0, 0, 0, 0, 0, 100, 0, 10000, 12000, 35000, 40000, 11, 37696, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - IC - cast Force of Nature'),
(21326, 0, 1, 2, 38, 0, 100, 0, 0, 1, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Set faction'),
(21326, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Show emote'),
(21326, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Set faction'),
(21326, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Evade'),
(21326, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Raven''s Wood Leafbeard - On Data set  - Despawn'),
(22226, 0, 0, 0, 0, 0, 100, 0, 5000, 7000, 8000, 10000, 11, 36093, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Koi-Koi Spirit - IC - Ghost Strike'),
(22226, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 21326, 40, 0, 0, 0, 0,0,'Koi-Koi Spirit - On death  - Set data');

DELETE FROM `creature_text` WHERE `entry`= 21326;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(21326,0,0,'The %s appears very grateful to be free of the koi-koi spirit''s influence.',16,0,100,0,0,0,'Raven''s Wood Leafbeard ', 19943);
