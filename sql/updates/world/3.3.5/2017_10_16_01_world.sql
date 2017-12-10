-- Feral Tender
SET @ENTRY := 15294;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,2,0,100,0,0,45,16000,18000,11,31325,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feral Tender - Between 0-45% Health - Cast 'Renew'");

-- Arcane Wraith
SET @ENTRY := 15273;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,0,0,100,0,6000,15000,6000,15000,11,37361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Wraith - In Combat - Cast 'Arcane Bolt'");

-- Tainted Arcane Wraith
SET @ENTRY := 15298;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,0,0,100,0,8000,16000,8000,16000,11,25603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Arcane Wraith - In Combat - Cast 'Slow'");

-- Felendren the Banished
SET @ENTRY := 15367;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,0,6000,9000,9000,12000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felendren the Banished - In Combat - Cast 'Mind Flay'");

-- Correct Felendren's respawn time
UPDATE `creature` SET `spawntimesecs`=60 WHERE `guid`=55165;

-- Slain by the Wretched requires Aiding the Outrunners
UPDATE `quest_template_addon` SET `PrevQuestID`=8347 WHERE `ID`=9704;

-- Felendren the Banished rewards Aiding the Outrunners
UPDATE `quest_template` SET `RewardNextQuest`=8347 WHERE `ID`=8335;

-- Package Recovery rewards Completing the Delivery
UPDATE `quest_template` SET `RewardNextQuest`=8350 WHERE `ID`=9705;

-- Tainted Arcane Sliver is refusable
UPDATE `quest_template_addon` SET `SpecialFlags`=0 WHERE `ID`=8338;

-- Reclaiming Sunstrider Isle
-- Talk on accept
DELETE FROM `quest_details` WHERE  `ID`=8325;
INSERT INTO `quest_details` (`ID`, `Emote1`) VALUES (8325, 1);

-- Solanian's Belongings
-- Talk when incomplete. Clap on turn in
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=8330;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=8330;

-- The Shrine of Dath'Remar
-- Talk and point on accept. Bow and talk on turn in
DELETE FROM `quest_details` WHERE `ID`=8345;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`) VALUES (8345, 1, 25);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=8345;

-- Felendren the Banished
-- Bow and talk on turn in
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=8335;

-- Thirst Unending
-- Point when incomplete
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=8346;

-- Report to Lanthan Perlion
-- Bow and talk on turn in
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=8327;

-- Aggression
-- Talk and point on offer. Point when incomplete. Talk on turn in.
DELETE FROM `quest_details` WHERE `ID`=8334;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`) VALUES (8334, 1, 25);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=8334;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8334;

-- Lynx collars (quest item) always drop
UPDATE `creature_loot_template` SET `Chance`=100 WHERE `Item`=20797;
-- Incorrect ref loot table on all NPCs
DELETE FROM `creature_loot_template` WHERE  `Entry` IN (15271,15273,15274,15294,15298,15366,15372) AND `Reference`=44007;

-- Random movement on some Mana Wyrms
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `id` IN (15274) AND `MovementType`=0;
-- Fix Mana Wyrm spawning underground
UPDATE `creature` SET `position_z`=30.85 WHERE `guid`=54934;
