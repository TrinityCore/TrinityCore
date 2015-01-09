-- [Q] Tails Up
-- Apparently it won't fall asleep due to evading. We are evading because the gossip won't show if we are in combat.. -_-

-- Frost Leopard SAI
SET @ENTRY := 29327;
SET @QUEST := 13549;
SET @GOSSIP := 54000;
SET @SPELL_RAKE := 54668;
SET @SPELL_BLOWGUN := 62105;
SET @SPELL_SLEEP := 52742;
UPDATE `creature_template` SET `AIName`='SmartAI',`npcflag`=0,`gossip_menu_id`=@GOSSIP,`faction_A`=1990,`faction_H`=1990,`unit_flags`=`unit_flags`|0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,8000,11000,11,@SPELL_RAKE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frost Leopard - In Combat - Cast Rake"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,2,1990,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Reset - Set Faction Back"),
(@ENTRY,0,2,0,8,0,100,1,@SPELL_BLOWGUN,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,11,@SPELL_SLEEP,2,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Script - Cast Sleep"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Script - Set Faction Friendly"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Script - Set npc_flag Gossip"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Script - Evade"), -- The gossip only shows out of combat..
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Script - Stop Auto Attack"),

(@ENTRY,0,3,0,62,0,100,0,@GOSSIP,0,0,0,88,@ENTRY*100+1,@ENTRY*100+3,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Gossip Select - Run Random Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,36,33007,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Script 1 - Update Template Male"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Frost Leopard - Script 1 - Say Line 0"),
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,36,33010,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Script 2 - Update Template Female"),
(@ENTRY*100+2,9,1,0,0,0,100,0,0,0,0,0,33,33005,0,0,0,0,0,7,0,0,0,0,0,0,0,"Frost Leopard - On Script 2 - Quest Credit"),
(@ENTRY*100+2,9,2,0,0,0,100,0,0,0,0,0,29,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Frost Leopard - On Script 2 - Follow Player"), -- Apparently crediting doesn't work through this action
(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,36,33007,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Leopard - On Script 3 - Update Template Male"),
(@ENTRY*100+3,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Frost Leopard - Script 3 - Say Line 0");

-- Insert gossip and static text
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=14266;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,14266);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(@GOSSIP,0,0,"Lift the frost leopard's tail to check if it's a male or a female.",1,1,0);

-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"It's an angry male!",42,0,100,0,0,0,"Male Frost Leopard");

-- Male Frost Leopard SAI
SET @ENTRY := 33007;
SET @SPELL_RAKE := 54668;
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=1990,`faction_H`=1990,`unit_flags`=`unit_flags`|0 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,9000,11000,11,@SPELL_RAKE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Male Frost Leopard - In Combat - Cast Rake");

-- Icepaw Bear SAI
SET @ENTRY := 29319;
SET @QUEST := 13549;
SET @GOSSIP := 55000;
SET @SPELL_CLAWS_OF_ICE := 54632;
SET @SPELL_BLOWGUN := 62105;
SET @SPELL_SLEEP := 52742;
UPDATE `creature_template` SET `AIName`='SmartAI',`npcflag`=0,`gossip_menu_id`=@GOSSIP,`faction_A`=1990,`faction_H`=1990,`unit_flags`=`unit_flags`|0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,8000,11000,11,@SPELL_CLAWS_OF_ICE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Icepaw Bear - In Combat - Cast Claws of Ice"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,2,1990,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Reset - Set Faction Back"),
(@ENTRY,0,2,0,8,0,100,1,@SPELL_BLOWGUN,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,11,@SPELL_SLEEP,2,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Script - Cast Sleep"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Script - Set Faction Friendly"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Script - Set npc_flag Gossip"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Script - Evade"), -- The gossip only shows out of combat..
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Script - Stop Auto Attack"),

(@ENTRY,0,3,0,62,0,100,0,@GOSSIP,0,0,0,88,@ENTRY*100+1,@ENTRY*100+3,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Gossip Select - Run Random Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,36,33008,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Script 1 - Update Template Male"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Icepaw Bear - Script 1 - Say Line 0"),
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,36,33011,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Script 2 - Update Template Female"),
(@ENTRY*100+2,9,1,0,0,0,100,0,0,0,0,0,33,33006,0,0,0,0,0,7,0,0,0,0,0,0,0,"Icepaw Bear - On Script 2 - Quest Credit"),
(@ENTRY*100+2,9,2,0,0,0,100,0,0,0,0,0,29,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Icepaw Bear - On Script 2 - Follow Player"), -- Apparently crediting doesn't work through this action
(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,36,33008,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icepaw Bear - On Script 3 - Update Template Male"),
(@ENTRY*100+3,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Icepaw Bear - Script 3 - Say Line 0");

-- Insert gossip and static text
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=14267;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,14267);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(@GOSSIP,0,0,"Lift the icepaw bear's tail to check if it's a male or a female.",1,1,0);

-- Male Icepaw Bear SAI
SET @ENTRY := 33008;
SET @SPELL_CLAWS_OF_ICE := 54632;
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=1990,`faction_H`=1990,`unit_flags`=`unit_flags`|0 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,9000,11000,11,@SPELL_CLAWS_OF_ICE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Male Icepaw Bear - In Combat - Cast Claws of Ice");

-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"It's an angry male!",42,0,100,0,0,0,"Male Icepaw Bear");

-- Only show first gossip if player is on quest Tails Up
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP AND `ConditionValue1`=@QUEST;
DELETE FROM `conditions` WHERE `SourceEntry` IN (@SPELL_BLOWGUN) AND `ConditionValue1` IN (29327,29319);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,0,0,9,@QUEST,0,0,0,'',"Only show gossip if player is on quest Tails Up"),
(17,0,@SPELL_BLOWGUN,0,19,29327,0,0,0,'',"Spell To'kini's Blowgun can only be cast at Frost Leopard"),
(17,0,@SPELL_BLOWGUN,1,19,29319,0,0,0,'',"Spell To'kini's Blowgun can only be cast at Icepaw Bear");
