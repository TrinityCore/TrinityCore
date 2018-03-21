SET @Saat := 20201;
SET @Menu := 8088;

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName`= '' WHERE `entry` = @Saat;

DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = @Saat);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Saat,0, 0,1, 62, 0,100,0,@Menu, 0,   0,   0, 72,    0, 0,0,0,0,0,7,0,0,0,0,0,0,0,"Sa'at - On gossip menu 8088 option id 0 selected - Close gossip"),
(@Saat,0, 1,0, 61, 0,100,0,    0, 0,   0,   0, 11,34975, 0,0,0,0,0,7,0,0,0,0,0,0,0,"Sa'at - On gossip menu 8088 option id 0 selected - Cast 'Conjure Chrono-Beacon'"),
(@Saat,0, 2,3, 62, 0,100,0,@Menu, 1,   0,   0, 72,    0, 0,0,0,0,0,7,0,0,0,0,0,0,0,"Sa'at - On gossip menu 8088 option id 1 selected - Close gossip"),
(@Saat,0, 3,0, 61, 0,100,0,    0, 0,   0,   0, 11,34975, 0,0,0,0,0,7,0,0,0,0,0,0,0,"Sa'at - On gossip menu 8088 option id 1 selected - Cast 'Conjure Chrono-Beacon'"),
(@Saat,0, 4,0, 10, 0,100,1,    1,16,1000,1000,  1,    0, 0,0,0,0,0,7,0,0,0,0,0,0,0,"Sa'at - Out Of Combat, in Line Of Sight - Say text 1");

DELETE FROM `gossip_menu_option` WHERE `MenuId`= @Menu AND `OptionIndex`= 1;
INSERT INTO `gossip_menu_option` (`MenuId`,`OptionIndex`,`OptionIcon`,`OptionText`,`OptionBroadcastTextId`,`OptionType`,`OptionNpcflag`,`VerifiedBuild`) VALUES
(@Menu, 1, 0, "I require a chrono-beacon, Sa'at.", 17881, 1, 1, 0);

DELETE FROM `gossip_menu` WHERE `entry`= @Menu AND `text_id` IN (10000,10001);
INSERT INTO `gossip_menu` (`entry`,`text_id`,`VerifiedBuild`) VALUES
(@Menu, 10000, 0),
(@Menu, 10001, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`= @Menu;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14, @Menu, 10001, 0, 0, 8, 0, 10297, 0, 0, 0, 0, 0, '', 'Show gossip menu 8088 text id 10001 if quest The Opening of the Dark Portal has been rewarded.'),
(14, @Menu, 10000, 0, 0, 8, 0, 10297, 0, 0, 1, 0, 0, '', 'Show gossip menu 8088 text id 10000 if quest The Opening of the Dark Portal is not rewarded.'),
(15, @Menu,     1, 0, 2, 8, 0, 10297, 0, 0, 0, 0, 0, '', 'Show gossip menu 8088 option id 1 if quest The Opening of the Dark Portal has been rewarded'),
(15, @Menu,     1, 0, 2, 2, 0, 24289, 1, 0, 1, 0, 0, '', 'Show gossip menu 8088 option id 1 if player has 0 of Chrono-Beacon. Item cannot be in bank. -AND 2-'),
(15, @Menu,     0, 0, 3, 9, 0, 10297, 0, 0, 0, 0, 0, '', 'Show gossip menu 8088 option id 0 if quest The Opening of the Dark Portal has not been taken. -AND 3-'),
(15, @Menu,     0, 0, 3, 2, 0, 24289, 1, 0, 1, 0, 0, '', 'Show gossip menu 8088 option id 0 if player has 0 of Chrono-Beacon. Item cannot be in bank. -AND 3-');

DELETE FROM `creature_text` WHERE `entry`= @Saat;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Saat, 0,0,'Stop! Do not go any further, mortal. You are ill-prepared to face the forces of the Infinite Dragonflight. Come, let me help you.', 12,0,100,1,0,0,17814,0, 'Saat');
