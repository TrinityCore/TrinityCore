-- [Q] A Taste of Flame

-- Cyrus Therepentous SAI
SET @ENTRY := 9459;
SET @GOSSIP := 40060;
UPDATE `creature_template` SET `AIName`='SmartAI',`gossip_menu_id`=@GOSSIP WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,12,9461,1,360000,0,0,0,8,0,0,0,-7656.939941,-3009.474121,133.205612,4.830283,"Cyrus Therepentous - On Gossip Select - Summon Frenzied Black Drake"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cyrus Therepentous - On Gossip Select (Link) - Close Gossip");

-- Actual gossip option and text for Cyrus Therepentous
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=2494;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,2494);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,0,0,"I present you with proof...",1,1,0,0,0,0,NULL);

-- Frenzied Black Drake SAI
SET @ENTRY := 9461;
SET @SPELL_FRENZY := 8269;
SET @SPELL_DECIMATE := 13459;
SET @SPELL_FLAME_BREATH := 9573;
SET @SPELL_FLAME_BUFFET := 9574;
UPDATE `creature_template` SET `AIName`='SmartAI',`mechanic_immune_mask`=1104 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2300,2900,19500,46300,11,@SPELL_FLAME_BREATH,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzied Black Drake - In Combat - Cast Flame Breath"),
(@ENTRY,0,1,0,0,0,100,0,1100,3800,2300,6100,11,@SPELL_FLAME_BUFFET,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzied Black Drake - In Combat - Cast Flame Buffet"),
(@ENTRY,0,2,0,0,0,100,0,28500,31600,70100,74400,11,@SPELL_DECIMATE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzied Black Drake - In Combat - Cast Decimate"),
(@ENTRY,0,3,4,2,0,100,1,0,30,0,0,11,@SPELL_FRENZY,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzied Black Drake - At 30% HP - Cast Frenzy"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Frenzied Black Drake - At 30% HP - Emote Line 0");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Frenzied Black Drake");

-- Conditions for the gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
(15,@GOSSIP,0,0,9,4022, 'Show gossip if on quest A Taste of Flame (1) OR'),
(15,@GOSSIP,0,1,9,4023, 'Show gossip if on quest A Taste of Flame (2) OR'),
(15,@GOSSIP,0,2,9,4024, 'Show gossip if on quest A Taste of Flame (3) OR');
