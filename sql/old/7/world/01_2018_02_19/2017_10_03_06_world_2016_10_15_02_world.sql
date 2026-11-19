-- NPC ID 4489 Braug Dimspirit, Test of Lore
SET @Braug  := 4489;
SET @menu   := 4763;
SET @quest  := 6627;
SET @Script := 448900;

UPDATE `creature_template` SET `AIName`= 'SmartAI', `ScriptName`= '' WHERE `entry`= @Braug;

DELETE FROM `creature_text` WHERE `entry`= @Braug;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Braug, 0,0,'Ah, Ysera the Dreamer.',                                12,0,100,1,3000,0,8382,0, 'Braug Dimspirit - Test of Lore'),
(@Braug, 1,0,'Neltharion, hmm? As good an answer as any, yes?',       12,0,100,1,3000,0,8386,0, 'Braug Dimspirit - Test of Lore'),
(@Braug, 2,0,'Alexstrazsa, the Life-Binder. A magnificent creature.', 12,0,100,1,3000,0,8387,0, 'Braug Dimspirit - Test of Lore'),
(@Braug, 3,0,'Malygos, is it?',                                       12,0,100,1,3000,0,8388,0, 'Braug Dimspirit - Test of Lore'),
(@Braug, 4,0,'That is the wrong answer, $n. Be off with you.',        12,0,100,1,3000,0,8393,0, 'Braug Dimspirit - Test of Lore');

DELETE FROM `gossip_menu_option` WHERE `MenuId` = @menu;
INSERT INTO `gossip_menu_option` (`MenuId`,`OptionIndex`,`OptionIcon`,`OptionText`,`OptionBroadcastTextId`,`OptionType`,`OptionNpcflag`,`VerifiedBuild`) VALUES
(@menu, 0, 0, 'Ysera is my answer.',        8381, 1, 1, 0),
(@menu, 1, 0, 'Neltharion is  my answer.',  8383, 1, 1, 0),
(@menu, 2, 0, 'Alexstrasza is  my answer.', 8384, 1, 1, 0),
(@menu, 3, 0, 'Malygos is my answer.',      8385, 1, 1, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Braug AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Script AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Braug, 0, 0,0, 31,0,100,0, 6766,0,0,0, 82,      3,0,0,0,0,0, 1,0,0,0,0,0,0,0,"Braug Dimspirit - on Target Spellhit 'Test of Lore' - Add npcflag Gossip & Questgiver"),
(@Braug, 0, 1,0, 62,0,100,0,@menu,0,0,0, 80,@Script,0,0,0,0,0, 1,0,0,0,0,0,0,0,'Braug Dimspirit - on Gossip Option 0 selected - Run Script'),
(@Braug, 0, 2,0, 62,0,100,0,@menu,2,0,0, 80,@Script,0,0,0,0,0, 1,0,0,0,0,0,0,0,'Braug Dimspirit - on Gossip Option 2 selected - Run Script'),
(@Braug, 0, 3,0, 62,0,100,0,@menu,3,0,0, 80,@Script,0,0,0,0,0, 1,0,0,0,0,0,0,0,'Braug Dimspirit - on Gossip Option 3 selected - Run Script'),
(@Braug, 0, 4,5, 62,0,100,0,@menu,1,0,0, 72,      0,0,0,0,0,0, 7,0,0,0,0,0,0,0,'Braug Dimspirit - on Gossip Option 1 selected - Close Gossip'),
(@Braug, 0, 5,6, 61,0,100,0,    0,0,0,0, 15, @quest,0,0,0,0,0, 7,0,0,0,0,0,0,0,"Braug Dimspirit - on Gossip Option 1 selected - Credit quest 'Test of Lore (3)'"),
(@Braug, 0, 6,7, 61,0,100,0,    0,0,0,0,  5,      4,0,0,0,0,0, 1,0,0,0,0,0,0,0,'Braug Dimspirit - on Gossip Option 1 selected - Play Emote 4 (ONESHOT_CHEER)'),
(@Braug, 0, 7,0, 61,0,100,0,    0,0,0,0,  5,     21,0,0,0,0,0, 1,0,0,0,0,0,0,0,'Braug Dimspirit - on Gossip Option 1 selected - Play Emote 21 (ONESHOT_APPLAUD)'),
(@Script,9, 0,0,  0,0,100,0,    0,0,0,0, 72,     0, 0,0,0,0,0, 7,0,0,0,0,0,0,0,'Braug Dimspirit - on Script - Close Gossip'),
(@Script,9, 1,0,  0,0,100,0,    0,0,0,0, 83,     3, 0,0,0,0,0, 1,0,0,0,0,0,0,0,'Braug Dimspirit - on Script - Remove npcflag Gossip & Questgiver'),
(@Script,9, 2,0,  0,0,100,0,    0,0,0,0,  1,     4, 0,0,0,0,0, 7,0,0,0,0,0,0,0,'Braug Dimspirit - on Script - Say Line 4'),
(@Script,9, 3,0,  0,0,100,0,    0,0,0,0, 11,  6766,64,0,0,0,0, 7,0,0,0,0,0,0,0,"Braug Dimspirit - on Script - Cast 'Test of Lore' (Prevent combat movement on cast, allow on fail range, mana, LOS)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`= @menu;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14, @menu, 5819,0, 1, 9,0, @quest,0,0,1,0,0,'', "Show gossip menu 4763 text id 5819 if quest 'Test of Lore (3)' has not been taken. -OR-"),
(14, @menu, 5819,0, 2, 8,0, @quest,0,0,0,0,0,'', "Show gossip menu 4763 text id 5819 if quest 'Test of Lore (3)' has been rewarded. -OR-"),
(14, @menu, 5819,0, 3,28,0, @quest,0,0,0,0,0,'', "Show gossip menu 4763 text id 5819 if quest 'Test of Lore (3)' has been completed. -OR-"),
(14, @menu, 5820,0, 4, 9,0, @quest,0,0,0,0,0,'', "Show gossip menu 4763 text id 5820 if quest 'Test of Lore (3)' has been taken. -AND-"),
(15, @menu,    0,0, 4, 9,0, @quest,0,0,0,0,0,'', "Show gossip menu 4763 option id  0 if quest 'Test of Lore (3)' has been taken. -AND-"),
(15, @menu,    1,0, 4, 9,0, @quest,0,0,0,0,0,'', "Show gossip menu 4763 option id  1 if quest 'Test of Lore (3)' has been taken. -AND-"),
(15, @menu,    2,0, 4, 9,0, @quest,0,0,0,0,0,'', "Show gossip menu 4763 option id  2 if quest 'Test of Lore (3)' has been taken. -AND-"),
(15, @menu,    3,0, 4, 9,0, @quest,0,0,0,0,0,'', "Show gossip menu 4763 option id  3 if quest 'Test of Lore (3)' has been taken. -AND-");
