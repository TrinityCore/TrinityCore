-- NPC ID 7783 Loramus Thalipedes, Quest 2744 'The Demon Hunter' and 3141 'Loramus'
UPDATE `creature_template` SET `AIName`= 'SmartAI', `ScriptName`= '' WHERE `entry`= 7783;

DELETE FROM `gossip_menu` WHERE `entry` IN (1212,1213,1214,1215,1216,1217);
INSERT INTO `gossip_menu` (`entry`,`text_id`,`VerifiedBuild`) VALUES
(1212, 1812, 0),
(1213, 1813, 0),
(1214, 1814, 0),
(1215, 1815, 0),
(1216, 1816, 0),
(1217, 1817, 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (11487,1212,1213,1214,1215,1216,1217);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(11487,0,0,'Hail, Loramus. I bring word from the Blasted Lands.',4230,1,1,1212,0,0,0,'',0,0),
(1212, 0,0,'Will you help?',                                     4245,1,1,   0,0,0,0,'',0,0),
(11487,1,0,'I wish to hear your story.',                         4257,1,1,1213,0,0,0,'',0,0),
(1213, 0,0,'Please continue.',                                   4247,1,1,1214,0,0,0,'',0,0),
(1214, 0,0,'I do not understand.',                               4249,1,1,1215,0,0,0,'',0,0),
(1215, 0,0,'Indeed.',                                            4251,1,1,1216,0,0,0,'',0,0),
(1216, 0,0,'I will do this with or without your help, Loramus.', 4254,1,1,1217,0,0,0,'',0,0),
(1217, 0,0,'Yes.',                                               4256,1,1,   0,0,0,0,'',0,0);

DELETE FROM `npc_text` WHERE `ID`= 1812;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`BroadcastTextID0`,`lang0`,`Probability0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`BroadcastTextID1`,`lang1`,`Probability1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`BroadcastTextID2`,`lang2`,`Probability2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`BroadcastTextID3`,`lang3`,`Probability3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`BroadcastTextID4`,`lang4`,`Probability4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`BroadcastTextID5`,`lang5`,`Probability5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`BroadcastTextID6`,`lang6`,`Probability6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`BroadcastTextID7`,`lang7`,`Probability7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`VerifiedBuild`) VALUES
(1812,"You freed Kirith from his suffering? Inconceivable -- and now Trebor has sent you here to learn of demons and their minions?$B$B<Loramus laughs.>$B$BBe thankful the arcane pangs have finally dissipated, $r.$b$b",'',4228,0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 7783 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7783,0,0,1,62,0,100,0,1212,0,0,0,72,   0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Loramus Thalipedes - On gossip menu_id 1212 selected - Close gossip"),
(7783,0,1,0,61,0,100,0,   0,0,0,0,15,2744,0,0,0,0,0,7,0,0,0,0,0,0,0,"Loramus Thalipedes - On gossip menu_id 1212 selected - Credit quest 'The Demon Hunter'"),
(7783,0,2,3,62,0,100,0,1217,0,0,0,72,   0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Loramus Thalipedes - On gossip menu_id 1217 selected - Close gossip"),
(7783,0,3,0,61,0,100,0,   0,0,0,0,15,3141,0,0,0,0,0,7,0,0,0,0,0,0,0,"Loramus Thalipedes - On gossip menu_id 1217 selected - Credit quest 'Loramus'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 11487 AND `SourceEntry` IN (0,1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11487, 0,0,0, 9,0, 2744,0,0,0,0,0,'',"Show gossip menu 11487 option id 0 if quest 'The Demon Hunter' has been taken."),
(15, 11487, 1,0,0, 9,0, 3141,0,0,0,0,0,'',"Show gossip menu 11487 option id 1 if quest 'Loramus' has been taken.");
