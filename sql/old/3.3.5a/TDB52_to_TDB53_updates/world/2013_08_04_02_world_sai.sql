-- Added missing gossip and text for Meridith the Mermaiden.Her gossip should now cast spell=25678 Siren's Song if player has Quest:Love_Song_for_Narain done, which will make players with quest Draconic for Dummies swim faster and not suffer from fatigue loss in waters.

-- Meridith the Mermaiden NPC id (15526)
-- http://www.youtube.com/watch?v=8lz_LbsEsBQ    Video of her giving spell on gossip select

SET @MERIDITH      := 15526;
SET @SPELL         := 25678; -- http://www.wowhead.com/spell=25678
SET @GOSSIP        := 6658;
SET @NPCTEXT       := 7916; 
SET @NPCTEXT1      := 7917;
SET @QUEST         := 8599;

UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=@MERIDITH;

DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id` IN (@NPCTEXT,@NPCTEXT1);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP,@NPCTEXT),
(@GOSSIP,@NPCTEXT1);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,0,0,"That would be wonderful! Thank you, Meridith.",1,1,0,0,0,0,'');

-- SAI for Meridith the Mermaiden
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@MERIDITH;

DELETE FROM `smart_scripts` WHERE (`entryorguid`=15526 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@MERIDITH,0,0,1,62,0,100,0,@GOSSIP,0,0,0,11,@SPELL,0,0,0,0,0,7,0,0,0,0,0,0,0,'Meridith the Mermaiden - On gossip select - Spellcast'),
(@MERIDITH,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Meridith the Mermaiden - On gossip select - Close Gossip'),
(@MERIDITH,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Meridith the Mermaiden - On Gossip select - Say');

-- Conditions for Spellcast
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,@GOSSIP,@NPCTEXT,0,0,8,0,@QUEST,0,0,1,0,'','Show text if player doesn''t have quest rewarded' ),
(14,@GOSSIP,@NPCTEXT1,0,0,8,0,@QUEST,0,0,0,0,'','Show text if player has quest rewarded'),
(15,@GOSSIP,0,0,0,8,0,@QUEST,0,0,0,0,'','Show gossip only if player has quest done');


-- Creature text
DELETE FROM `npc_text` WHERE `ID` IN (@NPCTEXT,@NPCTEXT1);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES 
(@NPCTEXT, '', 'It''s so lovely to see you again, $N! I really can''t thank you enough for delivering that message to my dear little gnome.$B$BWould you like to hear a song? It will make traveling in the rough seas much easier!', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 11723),
(@NPCTEXT1, '', 'I find the ocean floor to be very peaceful.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 11723);
