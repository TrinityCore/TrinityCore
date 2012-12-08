-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8054: wintergrasp Tower Cannon
UPDATE `creature_template` SET `unit_flags`=32772 WHERE `entry`=28366;
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7983: Priest Shadowfiend's Mana leech procs on absorb
DELETE FROM `spell_proc_event` WHERE `entry`=28305;
INSERT INTO `spell_proc_event` VALUES (28305,0,0,0,0,0,0,65536,0,0,0);
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8276: Kings and Sanctuary
SET @GUID = 1038;
DELETE FROM `spell_group_stack_rules` WHERE `group_id`=@GUID;
INSERT INTO `spell_group_stack_rules`(`group_id`,`stack_rule`) VALUES (@GUID,1);
DELETE FROM `spell_group` WHERE `id`=@GUID;
INSERT INTO `spell_group`(`id`,`spell_id`) VALUES
(@GUID,25899),
(@GUID,20911),
(@GUID,25898);
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8364: Prepping the Speech
-- Remove event flag "1" that was preventing events to trigger from spell more than once
UPDATE `smart_scripts` SET `event_flags`=0 WHERE `entryorguid` IN (1268,7955,6119) AND `id`=0;
-- Remove flag that gives immunity to other NPCs, was blocking SAI and it has no point in it when has extra civilian already, if it was set to prevent killing mobs led by low levels
UPDATE `creature_template` SET `unit_flags`=unit_flags&~512 WHERE `entry` IN (6119,7955,1268);
-- Add conditions to target only the specific NPCs
DELETE FROM `conditions` WHERE `SourceEntry`=74222 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,74222,0,1,31,1,3,1268,0,0,173,'','Gnomish Playback Device can target only Ozzie Togglevolt'),
(17,0,74222,0,2,31,1,3,7955,0,0,173,'','Gnomish Playback Device can target only Milli Featherwhistle'),
(17,0,74222,0,3,31,1,3,6119,0,0,173,'','Gnomish Playback Device can target only Tog Rustsprocket');
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8495: Sludge Beast - correct spawn point
UPDATE creature SET position_x=1071.40, position_y=-3135.26, position_z=67.39 WHERE guid=51809;
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8504: Cycle of Rebirth
-- Issue 7253: Cycle of Rebirth
UPDATE quest_template SET RequestItemsText='The continuous destruction caused by war and those that seek a profit from lumber pains me deeply. To aid the cycle of rebirth and replenish the lands, I need Gaea seeds. Do you have them, $C?',OfferRewardText='Ah, $N, you have the Gaea seeds. Watch and see how the blessing of the Earthmother can cause even these small kernels of life to bloom and flourish.$b$b<Tammra begins to chant.>' WHERE id = 6301;
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8506: No Rest for the Wicked
-- Fix typo in SAI that was blocking "No Rest for the Wicked" 
UPDATE `smart_scripts` SET `link`=0, `action_param6`=0, `target_type`=8 WHERE `entryorguid`=32347 AND `id`=0;
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8547: Fix Looting of Dr. Terrible's "Building a Better Flesh Giant"
-- Update quest loot template so item does not require player to be on a quest for item to drop
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=100 WHERE  `entry`=30409 AND `item`=42772;
-- Conditions so item will only drop if player is on or has completed (13042) Deep in the Bowels of The Underhalls
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=30409 AND `SourceEntry`=42772;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(1, 30409, 42772, 0, 0, 8, 13042, 0, 0, 0, '', 'Dr. Terribles "Building a Better Flesh Giant" only drops if player has completed Deep in the Bowels of The Underhalls OR'),
(1, 30409, 42772, 0, 1, 9, 13042, 0, 0, 0, '', 'Dr. Terribles "Building a Better Flesh Giant" only drops if player has taken Deep in the Bowels of The Underhalls');
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `creature_text` WHERE `entry`IN (234,3142,5888,19255);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(234 ,0,0, 'The People of Westfall salute $N, a brave and valiant defender of freedom.',12,7,100,0,0,0,'Marshal Gryan Stoutmantle'),
(3142,0,0, 'We will suffer no demon''s servant in our lands!',12,1,100,0,0,0,'Orgnil Soulscar'),
(5888,0,0, 'Peace and patience be with you, $N. Remain strong always.',12,1,100,0,0,0,'Seer Ravenfeather'),
(19255,0,0, 'How many more of you grunts do I need to send back to mommy and daddy in a body bag before you grow a brain and realize that runnin'' head first into a Legion kill squad is suicide? And don''t nod your thick skulls at me as if you know what I''m talkin'' about!',12,1,100,0,0,0,'Seer Ravenfeather');
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (234,3142,5888,3594,14347,19255,22231);
UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE `entry` IN (61,3643); 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (234,3142,5888,3594,14347,19255,22231);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3643,61) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (234,3142,5888,3594,14347,19255,22231) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3643 ,1,0,1,20,0,100,0,   67,0,0,0,12,2044 ,2,300000,0,0,0,7,0,0,0,0,0,0,0,'Old Footlocker - On quest The Legend of Stalvan rewarded - Summon creature'),
(234  ,0,0,1,20,0,100,0,  166,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Marshal Gryan Stoutmantle - On quest The Defias Brotherhood rewarded - Say line'),
(61   ,1,0,1,20,0,100,0,  231,0,0,0,12,3301 ,1,10000 ,0,0,0,7,0,0,0,0,0,0,0,'A Weathered Grave - On quest A Daughter''s Love rewarded - Summon creature'),
(3142 ,0,0,1,20,0,100,0,  806,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orgnil Soulscar - On quest Dark Storms rewarded - Say line'),
(5888 ,0,0,1,20,0,100,0, 1521,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Seer Ravenfeather - On quest Call of Earth rewarded - Say line'),
(3594 ,0,0,1,20,0,100,0, 3118,0,0,0,5,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Frahun Shadewhisper - On quest Encrypted Sigil rewarded - Emote ONESHOT_TALK(DNR)'),
(14347,0,0,1,20,0,100,0, 7786,0,0,0,12,14435,2,180000,0,0,0,7,0,0,0,0,0,0,0,'Highlord Demitrian - On quest Thunderaan the Windseeker rewarded - Summon creature'),
(19255,0,0,1,20,0,100,0,10289,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'General Krakork - On quest Journey to Thrallmar rewarded - Say line'),
(22231,0,0,1,20,0,100,0,10813,0,0,0,28,38495,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zezzak - On quest The Eyes of Grillok rewarded - Remove Aura');
DELETE FROM `quest_end_scripts` WHERE `id` IN (234,3142,5888,3594,14347,19255,22231,61,3643);
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
