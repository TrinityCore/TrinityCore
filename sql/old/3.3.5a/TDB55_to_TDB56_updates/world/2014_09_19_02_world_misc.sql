DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(43055,43053,43056,43054);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 2, 43056, 0, 0, 31, 0, 3, 23883, 0, 0, 0, 0, '', 'Vampire Soul Retrieve channel targets Forsaken Crossbowman'),
(13, 4, 43056, 0, 0, 31, 0, 3, 23883, 0, 0, 0, 0, '', 'Vampire Soul Retrieve channel targets Forsaken Crossbowman');

-- Marin Noggenfogger SAI
SET @ENTRY := 7564;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,2662,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marin Noggenfogger - On Quest '2662' Finished - Run Script");

-- Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marin Noggenfogger - On Script - Remove Npc Flag Questgiver"),
(@ENTRY*100,9,1,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marin Noggenfogger - On Script - Say Line 0"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,5,432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marin Noggenfogger - On Script - Play Emote 432"),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marin Noggenfogger - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `entry`=7564;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(7564, 0, 0, 'I''m going to carefully mix this - oops! ...Well, I spilled a little, but it''s ready!', 12, 0, 100, 0, 0, 0, 'Marin Noggenfogger', 4548);

-- Sprinkle SAI
SET @ENTRY := 7583;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,2641,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Quest '' Finished - Run Script");

-- Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Remove Npc Flag Questgiver"),
(@ENTRY*100,9,1,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Say Line 0"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,5,432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Play Emote 432"),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `entry`=7583;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(7583, 0, 0, 'Just sit tight while i get this prepared for you!', 12, 0, 100, 0, 0, 0, 'Sprinkle', 3661);

UPDATE `smart_scripts` SET `event_type`=11 WHERE  `entryorguid`=29327 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `link`=4 WHERE  `entryorguid`=29327 AND `source_type`=0 AND `id`=3 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29327 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29327, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 180000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frost Leopard - On Gossip Option 0 Selected - Despawn After 3 mins');
UPDATE `creature_template` SET `unit_flags`=0 WHERE  `entry`=29319;

UPDATE `smart_scripts` SET `event_type`=11 WHERE  `entryorguid`=29319 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `link`=4 WHERE  `entryorguid`=29319 AND `source_type`=0 AND `id`=3 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29319 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29319, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 180000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icepaw Bear - On Gossip Option 0 Selected - Despawn After 3 mins');

UPDATE `creature_template` SET `unit_flags`=262400 WHERE  `entry`=33007;
UPDATE `creature_template` SET `unit_flags`=262400 WHERE  `entry`=33008;
UPDATE `creature_template` SET `unit_flags`=32768 WHERE  `entry`=29319;

DELETE FROM `creature_template_addon` WHERE `entry` IN(33007,33008,29319);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(33007, 0, 0x0, 0x1, '42386'), -- 33007 - 42386
(33008, 0, 0x0, 0x1, '54240 42386'), -- 33008 - 54240, 42386
(29319, 0, 0x0, 0x1, '54240'); -- 29319 - 54240

DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN(2932701,2932703,2931901,2931903) AND `id`=2;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2932701, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 19, 262400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frost Leopard - On Script - Remove Unit Flags'),
(2932703, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 19, 262400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frost Leopard - On Script - Remove Unit Flags'),
(2931901, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 19, 262400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icepaw Bear - On Script - Remove Unit Flags'),
(2931903, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 19, 262400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icepaw Bear - On Script - Remove Unit Flags');

UPDATE `smart_scripts` SET `event_param3`=12000, `event_param4`=19000 WHERE `entryorguid`=3752 AND `id`=2;
UPDATE `smart_scripts` SET `event_param3`=12000, `event_param4`=19000 WHERE `entryorguid`=3755 AND `id`=2;
UPDATE `smart_scripts` SET `event_param3`=12000, `event_param4`=19000 WHERE `entryorguid`=3754 AND `id`=2;
