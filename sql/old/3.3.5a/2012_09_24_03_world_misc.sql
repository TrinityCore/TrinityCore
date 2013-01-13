-- Molten Core + Ruins of Ahn'Qiraj + Blackwing Lair + Zul'Gurub + Temple of Ahn'Qiraj Boss Respawn Fix author armano2 closes #5883
UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `Id` IN (12118,11982,12259,12057,12264,12056,11988,12098);
UPDATE `creature` SET `spawntimesecs` = 259200 WHERE `Id` IN (15348,15341,15340,15370,15369,15339);

-- Fix Fertile Spores Drop Chance authore exodius Closes #7727
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`= 35 WHERE `item`=24449;

-- Fix quest Gammothra the tormentor author gacko Closes #7770
UPDATE `creature_template` SET `minlevel`=71,`maxlevel`=71,`faction_A`=14,`faction_H`=14 WHERE `entry`=25790;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=25789;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25789 AND `source_type`=0;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=25789;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`event_param1`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(25789,8,46012,36,25790,1,'Gammothra the Tormentor - On spell hit - Update entry to Weakened Gammothra');

-- Disable Unfinished Gordok Business (1318) replaced with Disable Unfinished Gordok Business (7703) fix by nelegalno Closes #7819
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=1318;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,1318,0,'','','Unfinished Gordok Business replaced by 7703');

-- Fix Plague Siphon ability (74074) in Lich King encounter in instance Icecrown Citadel, may only target LK (36597) author elron103 Closes #7729
DELETE FROM `conditions` WHERE `SourceEntry` = 74074 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorTextId, ScriptName, Comment) VALUES
(13, 1, 74074, 0, 0, 31, 0, 3, 36597, 0, 0, 0, '', 'Plague Siphon may only target The Lich King');

-- Gurubashi Arena Grand Master (396) achievement fix by nelegalno Closes #7699
-- Short John Mithril (14508) gossip
UPDATE `creature_template` SET `gossip_menu_id` = 5921 WHERE `entry` = 14508;
DELETE FROM `gossip_menu` WHERE `entry`=5921 AND `text_id`=7074;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES(5921,7074);
-- Arena Master (18706) loot fix
UPDATE `item_template` SET `flagsCustom`=flagsCustom|2 WHERE `entry`=18706;
-- Arena Grandmaster (7838) quest is repeatable (players can get 2x Arena Grand Master trinkets)
-- https://www.youtube.com/watch?v=fkJ3vrwC4q4&feature=player_detailpage#t=170s
UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `Id` = 7838;

-- Update DisenchantID's to proper values for items from Satchel of Helpful Goods (51999) author Exodius Closes #7572
UPDATE `item_template` SET `DisenchantID`=41 WHERE `entry` IN (51964, 51968, 51978, 51994);

-- X Marks... Your Doom! (11166) quest fix by nelegalno Closes #7528
-- For some reason the script doesn't trigger if `flags_extra` = 128 is set
UPDATE `creature_template` SET `unit_flags` = 33554432, `flags_extra` = 0 WHERE `entry` = 23815;

-- Whitebark's Memory (10166) fix despawn timer author nelegalno Closes #7521
-- TODO: Find fix for one-shot kill by high level players
UPDATE `smart_scripts` SET `event_param1`=60000, `event_param2`=60000, `event_param3`=60000, `event_param4`=60000, `comment`="Whitebark's Spirit - after 60sec OOC - despawn" WHERE `entryorguid`=19456 AND `id`=5;

-- Armor of Darkness (12979) conditions fix by nelegalno Closes #7506
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=29380 AND `SourceEntry`=42203;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,29380,42203,0,0,9,0,12978,0,0,0,0,'',"Dark Armor Plate drops if Facing the Storm taken"),
(1,29380,42203,0,1,8,0,12978,0,0,0,0,'',"Dark Armor Plate drops if Facing the Storm rewarded"),
(1,29380,42203,0,1,8,0,12979,0,0,1,0,'',"Dark Armor Plate drops if Armor of Darkness isn't rewarded");

-- Remove duplicate of Swirling Maelstrom (180669) GO author nelegalno Closes #7498
UPDATE `gameobject` SET `id` = 180669 WHERE `guid` = 99900;
DELETE FROM `gameobject_template` WHERE `entry`=300057;

-- The Scepter of the Shifting Sands quest chain fix by nelegalno based on http://www.wowwiki.com/The_Scepter_of_the_Shifting_Sands_quest_chain Closes #7473
-- What Tomorrow Brings > Only One May Rise
UPDATE `quest_template` SET `NextQuestIdChain` = 8288 WHERE `Id` = 8286;
-- A Pawn on the Eternal Board > The Charge of the Dragonflights
UPDATE `quest_template` SET `NextQuestIdChain` = 8555 WHERE `Id` = 8519;
-- The Nightmare's Corruption > The Nightmare Manifests
UPDATE `quest_template` SET `NextQuestIdChain` = 8736 WHERE `Id` = 8735;
-- Azuregos's Magical Ledger > Translating the Ledger
UPDATE `quest_template` SET `NextQuestIdChain` = 8576 WHERE `Id` = 8575;

-- Hive'Zora Scout Report (8534), Hive'Regal Scout Report (8738) and Hive'Ashi Scout Report (8739) quests fix by Raszagal (Inspired by Justiciar's fix drom #3311)
-- TODO: Get sniffs for gossip_menu_option placeholder texts
-- Closes #3311 and Closes #7453

SET @GOSSIP1 := 6690; -- need confirmation
SET @GOSSIP2 := 6691; -- need confirmation
SET @GOSSIP3 := 6692; -- need confirmation
SET @NPC1 := 15609;
SET @NPC2 := 15610;
SET @NPC3 := 15611;

-- Update Cenarion Scout Landion's, Azenel's, & Jalia's gossip_menu and AI
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP1 WHERE `entry`=@NPC1;
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP2 WHERE `entry`=@NPC2;
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP3 WHERE `entry`=@NPC3;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC1,@NPC2,@NPC3);
-- Gossips
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP1 AND `text_id`=8063;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP2 AND `text_id`=8064;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP3 AND `text_id`=8065;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP1,8063),
(@GOSSIP2,8064),
(@GOSSIP3,8065);
-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (@GOSSIP1,@GOSSIP2,@GOSSIP3);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP1,0,0,"May I have your report?",1,1,0,0,0,0,''), -- placeholder untill sniffed
(@GOSSIP2,0,0,"May I have your report?",1,1,0,0,0,0,''), -- placeholder untill sniffed
(@GOSSIP3,0,0,"May I have your report?",1,1,0,0,0,0,''); -- placeholder untill sniffed
-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (@GOSSIP1,@GOSSIP2,@GOSSIP3);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP1,0,0,0,2,0,21160,1,0,1,0,'',"Show gossip only if player dosn't have Hive'Regal Scout Report"),
(15,@GOSSIP1,0,0,0,9,0,8738,0,0,0,0,'',"Show gossip only if Hive'Regal Scout Report quest has been taken"),
(15,@GOSSIP2,0,0,0,2,0,21158,1,0,1,0,'',"Show gossip only if player dosn't have Hive'Zora Scout Report"),
(15,@GOSSIP2,0,0,0,9,0,8534,0,0,0,0,'',"Show gossip only if Hive'Zora Scout Report quest has been taken"),
(15,@GOSSIP3,0,0,0,2,0,21161,1,0,1,0,'',"Show gossip only if player dosn't have Hive'Ashi Scout Report"),
(15,@GOSSIP3,0,0,0,9,0,8739,0,0,0,0,'',"Show gossip only if Hive'Ashi Scout Report quest has been taken");
-- Scripts
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC1,@NPC2,@NPC3) AND source_type=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC1,0,0,1,62,0,100,0,@GOSSIP1,0,0,0,11,25847,1,0,0,0,0,7,0,0,0,0,0,0,0,"Cenarion Scout Landion - on gossip option select - cast Create Hive'Regal Scout Report"),
(@NPC1,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cenarion Scout Landion - Link - close gossip"),
(@NPC2,0,0,1,62,0,100,0,@GOSSIP2,0,0,0,11,25843,1,0,0,0,0,7,0,0,0,0,0,0,0,"Cenarion Scout Azenel - on gossip option select - cast Create Hive'Zora Scout Report"),
(@NPC2,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cenarion Scout Azenel - Link - close gossip"),
(@NPC3,0,0,1,62,0,100,0,@GOSSIP3,0,0,0,11,25845,1,0,0,0,0,7,0,0,0,0,0,0,0,"Cenarion Scout Jalia - on gossip option select - ast Create Hive'Ashi Scout Report"),
(@NPC3,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cenarion Scout Jalia - Link - close gossip");
