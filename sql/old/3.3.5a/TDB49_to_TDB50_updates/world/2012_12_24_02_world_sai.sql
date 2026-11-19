-- [Q] Gambling Debt - http://www.wowhead.com/quest=11464
-- Discover's work,  thanks to Vincent-Michael for helping with gossips and Pitcrawler for advices
-- Indexes
SET @ENTRY := 24539;
SET @SCRIPT := @ENTRY * 100;
SET @SCRIPT1 := (@ENTRY * 100) + 1;
SET @GOSSIP_1 := 9010;
SET @GOSSIP_2 := 9011;
SET @QUEST := 11464;
SET @SPELL_SCORCH := 50183;
SET @SPELL_BLAST_WAVE := 15091;

-- SAI support - "Silvermoon" Harry
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SCRIPT,@SCRIPT1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP_1,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary - On Gossip Select option 2 - Set Faction Aggressive'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Silvermoon Hary - On Gossip Select - Close Gossip'),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Silvermoon Hary - Linked with previous event - Say Line 0'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary - Linked with previous event - Set faction aggressive'),
(@ENTRY,0,4,0,2,0,100,1,1,50,60000,60000,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary - On hp % between 1/50 - Start acitonlist'),
(@ENTRY,0,5,0,64,1,100,0,0,0,0,0,98,@GOSSIP_2,12175,0,0,0,0,7,0,0,0,0,0,0,0, 'Silvermoon Hary - On gossip hello in phase 1 - Send gossip menu 2'),
(@ENTRY,0,6,0,62,1,100,0,@GOSSIP_2,0,0,0,80,@SCRIPT1,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary - On gossip select - Start actionlist 1'),
(@ENTRY,0,7,0,0,0,100,0,3000,6000,15000,22000,11,@SPELL_BLAST_WAVE,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary - IC - Cast Blast Wave'),
(@ENTRY,0,8,0,0,0,100,0,2500,4000,4000,5000,11,@SPELL_SCORCH,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Silvermoon Hary - IC - Cast Scorch'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary (script 0) - Action 0 - Say line 1'),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary (script 0) - Action 1 - Set hp reg disabled'),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary (script 0) - Action 2 - Set home position'),
(@SCRIPT,9,3,0,0,0,100,0,0,0,0,0,2,1080,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary (script 0) - Action 3 - Change faction to friendly'),
(@SCRIPT,9,4,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary (script 0) - Action 4 - Evade (to stop attack)'),
(@SCRIPT,9,5,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary (script 0) - Action 6 - Set event phase 1'),
(@SCRIPT1,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Silvermoon Hary (script 1) - Action 0 - Close gossip window'),
(@SCRIPT1,9,1,0,0,0,100,0,0,0,0,0,56,34115,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Silvermoon Hary (script 1) - Action 1 - Give item to invoker'),
(@SCRIPT1,9,2,0,0,0,100,0,0,0,0,0,102,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary (script 1) - Action 2 - Set hp reg enabled'),
(@SCRIPT1,9,3,0,0,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary (script 1) - Action 3 - Despawn in 10 sec'),
(@SCRIPT1,9,4,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silvermoon Hary (script 1) - Action 4 - Set event phase 0');

-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Do not test me, scurvy dog! I''m trained in the way of Blood Knights!',12,0,100,0,0,0, 'Silvermoon Hary - start to fight'),
(@ENTRY,1,0,"I'll pay! I'll pay! Eeeek! Please don't hurt me!",12,0,100,0,0,0, 'Silvermoon Hary - second gossip');

-- Gossip menu
DELETE FROM `gossip_menu` WHERE `entry` IN (@GOSSIP_1,@GOSSIP_2);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP_1,12174),
(@GOSSIP_2,12175);

-- Gossip option menu
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP_1;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP_2;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_id`,`npc_option_npcflag`,`option_icon`,`option_text`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP_1,0,1,1,0, 'Taruk sent me to collect what you owe.',0,0, ''),
(@GOSSIP_1,1,3,128,1, 'Do you sell any of this stuff?',0,0, ''),
(@GOSSIP_2,0,1,1,0, 'Pay up, Harry!',0,0, ''),
(@GOSSIP_2,1,3,128,1, 'Do you sell any of this stuff?',0,0, '');

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (@GOSSIP_1,@GOSSIP_2);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP_1,0,0,9,0,@QUEST,0,0,0,'','Only show first gossip (option 0) if player is on quest Gambling Debt'),
(15,@GOSSIP_2,0,0,9,0,@QUEST,0,0,0,'','Only show second gossip (option 0) if player is on quest Gambling Debt');
