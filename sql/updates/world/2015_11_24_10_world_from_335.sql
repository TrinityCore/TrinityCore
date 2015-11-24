--
/*
SET @NPCTEXT= 724006;

DELETE FROM `gossip_menu` WHERE `entry`=6539 AND `text_id`=@NPCTEXT;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(6539, @NPCTEXT);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=6539 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(6539,0,0,'I am ready, Anachronos. Please grant me the Scepter of the Shifting Sands.',11331,1,1,0,0,0,0,'',0);

DELETE FROM `npc_text` WHERE `ID`=@NPCTEXT;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `Probability1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `Probability2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `Probability3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `Probability4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `Probability5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `Probability6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `Probability7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `VerifiedBuild`) VALUES
(@NPCTEXT, "The Scepter of the Shifting Sands is whole once more, $n.$B$BIt is you who must lead your armies into the cursed fortress city of Ahn'Qiraj and mete justice to its inhabitants.$B$BVenture to Silithus and present the Scepter of the Shifting Sands to Jonathan the Revelator.", '', 11333, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, -1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=6539 AND `SourceEntry`=@NPCTEXT;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6539 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6539,@NPCTEXT,0,0,8,0,8742,0,0,0,0,0,'','Show gossip text after quest The Might of Kalimdor rewarded'),
(14,6539,@NPCTEXT,0,0,2,0,21175,1,1,1,0,0,'','Show gossip text if doesnt have item The Scepter of the Shifting Sands'),
(14,6539,@NPCTEXT,0,0,8,0,8745,0,0,1,0,0,'','Show gossip text if Treasure of the Timeless One is not rewarded'),
(15,6539,0,0,0,8,0,8742,0,0,0,0,0,'','Show gossip menu option after quest The Might of Kalimdor rewarded'),
(15,6539,0,0,0,2,0,21175,1,1,1,0,0,'','Show gossip menu option if doesnt have item The Scepter of the Shifting Sands'),
(15,6539,0,0,0,8,0,8745,0,0,1,0,0,'','Show gossip menu option if Treasure of the Timeless One is not rewarded');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=15192;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=15192;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15192,0,0,1,62,0,100,0,6539,0,0,0,11,25861,0,0,0,0,0,7,0,0,0,0,0,0,0,'Anachronos - On Gossip Option 0 Selected - Cast \'Call Scepter DND\''),
(15192,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anachronos - On Gossip Option 0 Selected - Close Gossip');
*/