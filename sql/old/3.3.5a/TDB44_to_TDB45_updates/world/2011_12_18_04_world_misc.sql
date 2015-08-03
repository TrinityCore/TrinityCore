-- Remove empty EAI Script call from the following entries
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (30243,30632);

-- Crimson Hammersmith summon from Blacksmithing Plans fix
-- Black Guard Swordsmith summon from Blacksmithing Plans fix
UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` IN (176325, 176327);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (176325, 176327) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(176325, 1, 0, 0, 64, 0, 100, 1, 0, 0, 0, 0, 12, 11120, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 3585.5, -3000.15, 125, 2.19912, 'Blacksmithing Plans - summon Crimson Hammersmith'),
(176327, 1, 0, 0, 64, 0, 100, 1, 0, 0, 0, 0, 12, 11121, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 3818.4, -3693.32, 144.242, 0.261799, 'Blacksmithing Plans - summon Black Guard Swordsmith');

-- Sleeping Giants fix
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24669;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=24669 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24669, 0, 0, 1, 8, 0, 100, 0, 44261, 1, 0, 0, 33, 24669, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dormant Vrykul - Sleeping Giants quest credit'),
(24669, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dormant Vrykul - Sleeping Giants despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=34083;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 0, 34083, 0, 24, 1, 24669, 0, 63, '', 'Awakening Rod target limit to Dormant Vrykul'); -- changed to item script by Nay, not tested.

-- Culling of Stratholme Hemotoxin SAI spell fix version
SET @ENTRY := 28199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=@ENTRY);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY);
INSERT INTO `smart_scripts` VALUES
(@ENTRY, 0, 0, 0, 9, 0, 25, 2, 0, 20, 5000, 8000, 11, 52522, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tomb Stalker - Cast Hemotoxin Normal'),
(@ENTRY, 0, 1, 0, 9, 0, 40, 4, 0, 20, 5000, 8000, 11, 58782, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Tomb Stalker - Cast Hemotoxin Heroic');

DELETE FROM `creature` WHERE `id` IN (28318, 29346);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(40153, 28318, 530, 1, 1, 0, 0, -1775.148438, 5548.291992, -12.428190, 4.146070, 300, 0, 0, 1, 0, 0, 0, 0, 0), -- Grand Apothecary Putress
(40251, 29346, 530, 1, 1, 0, 0, 1925, -4123.1899,  43.1780,  4.79965, 300, 0, 0, 1, 0, 0, 0, 0, 0); -- Apothecary Karlov

-- Fix NPCs falling underground when killed by nelegalno
UPDATE `creature_template` SET `InhabitType` = 3 WHERE `entry` IN (5936, 24899); -- Orca and Scoodles

-- Removes wrong restriction from G.N.E.R.D. rage
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=3882 AND `type`=16;

-- Kalu'ak Fishing Derby start time fix
UPDATE `game_event` SET `start_time` = '2011-01-01 13:00:00' WHERE `eventEntry`=63;
UPDATE `game_event` SET `start_time` = '2011-01-01 14:00:00' WHERE `eventEntry`=64;

-- Stranglethorn Fishing Extravaganza start time fix ( http://old.wowhead.com/event=301 )
UPDATE `game_event` SET `start_time` = '2011-01-01 14:00:00' WHERE `eventEntry` IN (14, 15, 62);
UPDATE `game_event` SET `description` = 'Stranglethorn Fishing Extravaganza Announce' WHERE `eventEntry`=14;
UPDATE `game_event` SET `description` = 'Stranglethorn Fishing Extravaganza Fishing Pools' WHERE `eventEntry`=15;
UPDATE `game_event` SET `description` = 'Stranglethorn Fishing Extravaganza Turn-ins' WHERE `eventEntry`=62;

-- Eitrigg's Wisdom fix
SET @GOSSIP = 21312;
SET @NPC = 3144;
SET @QUEST = 4941;
-- Add gossip options for each menu id
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN @GOSSIP AND @GOSSIP+7;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP, 0, 0, 'Hello, Eitrigg. I bring news from Blackrock Spire.', 1, 1, @GOSSIP+1, 0, 0, 0, ''),
(@GOSSIP+1, 0, 0, 'There is only one Warchief, Eitrigg!', 1, 1, @GOSSIP+2, 0, 0, 0, ''),
(@GOSSIP+2, 0, 0, 'What do you mean?', 1, 1, @GOSSIP+3, 0, 0, 0, ''),
(@GOSSIP+3, 0, 0, 'Hearthglen? But...', 1, 1, @GOSSIP+4, 0, 0, 0, ''),
(@GOSSIP+4, 0, 0, 'I will take you up on that offer, Eitrigg.', 1, 1, @GOSSIP+5, 0, 0, 0, ''),
(@GOSSIP+5, 0, 0, 'Ah, so that is how they pushed the Dark Iron to the lower parts of the Spire.', 1, 1, @GOSSIP+6, 0, 0, 0, ''),
(@GOSSIP+6, 0, 0, 'Perhaps there exists a way?', 1, 1, @GOSSIP+7, 0, 0, 0, ''),
(@GOSSIP+7, 0, 0, 'As you wish, Eitrigg.', 1, 1, 0, 0, 0, 0, '');
-- Add gossip menus (text values already in db)
DELETE FROM `gossip_menu` WHERE `entry`BETWEEN @GOSSIP+1 AND @GOSSIP+7;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(@GOSSIP+1, 3574),
(@GOSSIP+2, 3575),
(@GOSSIP+3, 3576),
(@GOSSIP+4, 3577),
(@GOSSIP+5, 3578),
(@GOSSIP+6, 3579),
(@GOSSIP+7, 3580);
-- Add Condtion so gossip only shows when on quest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, @GOSSIP, 0, 0, 9, 4941, 0, 0, 0, '', NULL);
-- Add SAI for quest complete and close of gossip when last option selected
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,1,62,0,100,0,@GOSSIP+7,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Eitrigg - Select As you wish, Eitrigg. - Close gossip'),
(@NPC,0,1,0,61,0,100,0,0,0,0,0,15,@QUEST,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Eitrigg - On link - Give credit quest (4941)');
