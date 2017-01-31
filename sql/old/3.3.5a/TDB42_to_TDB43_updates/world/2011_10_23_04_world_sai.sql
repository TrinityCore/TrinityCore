-- Altruis the Sufferer SAI
-- [Q] Survey the Land
-- [Q] Illidan's Pupil
SET @ENTRY := 18417;
SET @GOSSIP := 21304;
SET @QUEST_SURVEY := 9991;
SET @QUEST_PUPIL := 10646;
UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `entry` IN (@QUEST_SURVEY,@QUEST_PUPIL);
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP+0,`AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Survey the Land
(@ENTRY,0,0,0,62,0,100,0,@GOSSIP+1,0,0,0,52,532,0,0,0,0,0,7,0,0,0,0,0,0,0,"Altruis the Sufferer - On Gossip Select - Activate Taxi Path"),
(@ENTRY,0,1,0,62,0,100,0,@GOSSIP+1,0,0,0,26,@QUEST_SURVEY,0,0,0,0,0,7,0,0,0,0,0,0,0,"Altruis the Sufferer - On Gossip Select - Quest Credit"),
-- Illidan's Pupil
(@ENTRY,0,2,0,62,0,100,0,@GOSSIP+6,0,0,0,26,@QUEST_PUPIL,0,0,0,0,0,7,0,0,0,0,0,0,0,"Altruis the Sufferer - On Gossip Select - Give Quest Credit");

DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+0 AND `text_id`=9427;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+1 AND `text_id`=10492;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+2 AND `text_id`=10493;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+3 AND `text_id`=10494;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+4 AND `text_id`=10495;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+5 AND `text_id`=10497;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP+0,9427), -- Survey the Land
(@GOSSIP+1,10492), -- Illidan's Pupil
(@GOSSIP+2,10493), -- Illidan's Pupil
(@GOSSIP+3,10494), -- Illidan's Pupil
(@GOSSIP+4,10495), -- Illidan's Pupil
(@GOSSIP+5,10497); -- Illidan's Pupil

-- Insert menu options
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN @GOSSIP+0 AND @GOSSIP+6;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
-- Survey the Land
(@GOSSIP+0,0,0,"Well?",1,3,@GOSSIP+1),
(@GOSSIP+1,0,0,"Ok.",1,3,0),
-- Illidan's Pupil
(@GOSSIP+0,1,0,"Tell me about the demon hunter training grounds at the Ruins of Karabor.",1,3,@GOSSIP+2),
(@GOSSIP+2,0,0,"I'm listening.",1,3,@GOSSIP+3),
(@GOSSIP+3,0,0,"Go on, please.",1,3,@GOSSIP+4),
(@GOSSIP+4,0,0,"Interesting.",1,3,@GOSSIP+5),
(@GOSSIP+5,0,0,"That's quite a story.",1,3,@GOSSIP+6),
(@GOSSIP+6,0,0,"There was something else I wanted to ask you, Altruis.",1,3,@GOSSIP+0); -- Back to first page

-- Conditions for gossip menu of quest Survey the Land
DELETE FROM `conditions` WHERE `SourceGroup` IN (@GOSSIP+0,@GOSSIP+10) AND `ConditionValue1` IN (@QUEST_SURVEY,@QUEST_PUPIL);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP+0,0,0,9,@QUEST_SURVEY,0,0,0,'',"Only show first gossip if player is on quest Survey the Land"),
(15,@GOSSIP+0,1,0,9,@QUEST_PUPIL,0,0,0,'',"Only show first gossip if player is on quest Illidans Pupil");
