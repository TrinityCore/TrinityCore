SET @NPC := 45211;

-- SAI for Ulfang/Sage Mistwalker/Watcher Moonleaf
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=24261;
UPDATE `creature_template` SET `AIName`='SmartAI',`npcflag`=3 WHERE `entry` IN(24186, 24273);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(24186,24261,24273) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24261, 0, 0, 0, 19, 0, 100, 0, 11326, 0, 0, 0, 85, 50102, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ulfang - On Quest Accept Alpha Worg - Invoker Cast Ulfang: Force Cast Player Eyes of the Eagle'),
(24261, 0, 1, 0, 19, 0, 100, 0, 11324, 0, 0, 0, 85, 50102, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ulfang - On Quest Accept Alpha Worg - Invoker cast Ulfang: Force Cast Player Eyes of the Eagle'),
(24273, 0, 0, 1, 20, 0, 100, 0, 11326, 0, 0, 0, 28, 50102, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Watcher Moonleaf - On Quest Reward Alpha Worg - Remove Aura Ulfang: Force Cast Player Eyes of the Eagle'),
(24273, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 28, 43060, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Watcher Moonleaf - Linked with Previous Event - Remove Aura Eyes of the Eagle'),
(24273, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 43369, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Watcher Moonleaf - Linked with Previous Event - Remove Aura Worg Disguise'),
(24273, 0, 3, 4, 62, 0, 100, 0, 8918, 0, 0, 0, 85, 43379, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Watcher Moonleaf - On Gossip Option Select - Invoker Cast The Cleansing: Create Worg Disguise'),
(24273, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Watcher Moonleaf - Linked with Previous Event - Close Gossip'),
(24186, 0, 0, 1, 20, 0, 100, 0, 11324, 0, 0, 0, 28, 50102, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sage Mistwalker - On Quest Reward Alpha Worg - Remove Aura Ulfang: Force Cast Player Eyes of the Eagle'),
(24186, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 28, 43060, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sage Mistwalker - Linked with Previous Event - Remove Aura Eyes of the Eagle'),
(24186, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 43369, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sage Mistwalker - Linked with Previous Event - Remove Aura Worg Disguise'),
(24186, 0, 3, 4, 62, 0, 100, 0, 8908, 0, 0, 0, 85, 43379, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sage Mistwalker - On Gossip Option Select - Invoker Cast The Cleansing: Create Worg Disguise'),
(24186, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sage Mistwalker - Linked with Previous Event - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(8918,8908);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8918, 0, 0, 0, 8, 0, 11322, 0, 0, 0, 0, 0, '', 'Gossip Option requires The Cleansing rewarded'),
(15, 8918, 0, 0, 0, 2, 0, 33618, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have worg disguise'),
(15, 8918, 0, 0, 0, 8, 0, 11326, 0, 0, 1, 0, 0, '', 'Gossip Option requires Alpha Worg not rewarded'),
(15, 8908, 0, 0, 0, 8, 0, 11317, 0, 0, 0, 0, 0, '', 'Gossip Option requires The Cleansing rewarded'),
(15, 8908, 0, 0, 0, 2, 0, 33618, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have worg disguise'),
(15, 8908, 0, 0, 0, 8, 0, 11324, 0, 0, 1, 0, 0, '', 'Gossip Option requires Alpha Worg not rewarded');


DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(8918,8908);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8918, 0, 0, 'I have misplaced my worg disguise.', 23068, 1, 1, 0, 0, 0, 0, '', 0),
(8908, 0, 0, 'I have misplaced my worg disguise.', 23068, 1, 1, 0, 0, 0, 0, '', 0);

-- Pathing for Garwal Entry: 24277
SET @PATH := @NPC * 10;

UPDATE `creature_template` SET `faction`=1971 WHERE `entry`=24277;

DELETE FROM `creature_template_addon` WHERE `entry`=24277;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(24277, @PATH, 0x10000, 0x1, '43062'); -- Alpha Worg: Garwal's Invisibility is in spell_DBC but does not work so npc is friendly spell 43060 makes this creature hostile to player and is also the see invisibilty spell 

DELETE FROM `creature` WHERE `guid` = @NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@NPC, 24277,571,1,1,2724.867,-2996.879,91.80984,6.232399,120,0,2);

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=24277;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(24277,0,0, 'Enough of this charade!',12,0,100,0,0,0, 'Garwal',23064);

-- SAI for Garwal
SET @ENTRY  := 24277;
SET @SPELL1 := 6749;  -- Wide Swipe
SET @SPELL2 := 13443; -- Rend
SET @SPELL3 := 31279; -- Swipe
SET @SPELL4 := 50047; -- Broken Bone
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,3,0,22233,0,0,0,0,1,0,0,0,0,0,0,0, 'Garwal - On Reset - Set Model'),
(@ENTRY,0,1,2,2,0,100,1,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Garwal - On HP@50% - Say text'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,3,0,26791,0,0,0,0,1,0,0,0,0,0,0,0, 'Garwal - On HP@50% - Set Model'),
-- Combat (Needs Timing)
(@ENTRY,0,3,0,9,0,100,0,0,5,13000,18000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Garwal - Combat - Cast Spell Wide Swipe'),  -- Duration 5 sec 
(@ENTRY,0,4,0,9,0,100,0,0,5,21000,31000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Garwal - Combat - Cast Spell Rend'),        -- Duration 15 sec
(@ENTRY,0,5,0,9,0,100,0,0,5,3000,7000,11,@SPELL3,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Garwal - Combat - Cast Spell Swipe'),
(@ENTRY,0,7,0,0,0,100,0,0,5,15000,26000,11,@SPELL4,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Garwal - Combat - Cast Spell Broken Bone'); -- Duration 8 sec

DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2724.867,-2996.879,91.80984,0,0,0,100,0),
(@PATH,2,2751.252,-3001.074,89.98224,0,0,0,100,0),
(@PATH,3,2779.356,-3012.149,91.01633,0,0,0,100,0),
(@PATH,4,2790.117,-3024.486,94.64133,0,0,0,100,0),
(@PATH,5,2793.189,-3046.271,97.17670,0,0,0,100,0);
