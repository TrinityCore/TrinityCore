-- Tirisfal Farmhand SAI
SET @ENTRY := 1935;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tirisfal Farmhand - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tirisfal Farmhand - On Aggro - Say Line 0");

-- Tirisfal Farmer SAI
SET @ENTRY := 1934;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tirisfal Farmer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,12000,20000,11,80382,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tirisfal Farmer - In Combat - Cast 'Cast Dirt Toss'"),
(@ENTRY,0,2,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tirisfal Farmhand - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `entry` IN (1934, 1935);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(1934, 0, 0, 'Get out of my kitchen!', 12, 0, 100, 0, 0, 0, 44544, 0, 'Tirisfal Farmer'),
(1934, 0, 1, 'Get back, $r!', 12, 0, 100, 0, 0, 0, 44542, 0, 'Tirisfal Farmer'),
(1934, 0, 2, 'No, no, no... you took my family, but you won''t take my land!', 12, 0, 100, 0, 0, 0, 44541, 0, 'Tirisfal Farmer'),
(1934, 0, 3, 'Why won''t you leave us alone?', 12, 0, 100, 0, 0, 0, 44543, 0, 'Tirisfal Farmer'),
-- 
(1935, 0, 0, 'Get out of my kitchen!', 12, 0, 100, 0, 0, 0, 44544, 0, 'Tirisfal Farmhand'),
(1935, 0, 1, 'Get back, $r!', 12, 0, 100, 0, 0, 0, 44542, 0, 'Tirisfal Farmhand'),
(1935, 0, 2, 'No, no, no... you took my family, but you won''t take my land!', 12, 0, 100, 0, 0, 0, 44541, 0, 'Tirisfal Farmhand'),
(1935, 0, 3, 'Why won''t you leave us alone?', 12, 0, 100, 0, 0, 0, 44543, 0, 'Tirisfal Farmhand');

-- The Chef SAI
SET @ENTRY := 47405;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,120000,120000,120000,53,0,47405,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - Out of Combat - Start Waypoint"),
(@ENTRY,0,1,2,40,0,100,0,2,47405,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 2 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,61,0,100,0,2,47405,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 2 Reached - Set Emote State 233"),
(@ENTRY,0,3,4,40,0,100,0,3,47405,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 3 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,61,0,100,0,3,47405,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 3 Reached - Set Emote State 69"),
(@ENTRY,0,5,0,40,0,100,0,4,47405,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Chef - On Waypoint 4 Reached - Set Emote State 26");

DELETE FROM `waypoints` WHERE `entry`=47405;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(47405, 1, 2259.79, 268.161, 33.6901, 'The Chef'),
(47405, 2, 2259.9, 267.349, 34.3857, 'The Chef'),
(47405, 3, 2260.2, 268.822, 33.6908, 'The Chef'),
(47405, 4, 2257.37, 269.111, 33.6908, 'The Chef');

-- Junior Apothecary Holland SAI
SET @ENTRY := 10665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,60000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Junior Apothecary Holland - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=10665;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10665, 0, 0, 'What could be taking so long?', 12, 0, 100, 0, 0, 0, 5955, 0, 'Junior Apothecary Holland'),
(10665, 0, 1, 'How long can it take to pick a handful of weeds?', 12, 0, 100, 0, 0, 0, 5956, 0, 'Junior Apothecary Holland'),
(10665, 0, 2, 'At this rate I could have gathered them myself!', 12, 0, 100, 0, 0, 0, 5957, 0, 'Junior Apothecary Holland'),
(10665, 0, 3, 'If you want something done right, do it yourself!', 12, 0, 100, 0, 0, 0, 5958, 0, 'Junior Apothecary Holland'),
(10665, 0, 4, 'As if I had all eternity.', 12, 0, 100, 0, 0, 0, 5959, 0, 'Junior Apothecary Holland'),
(10665, 0, 5, 'Ah, this must be him now... NO?  Bah!', 12, 0, 100, 0, 0, 0,  5960, 0, 'Junior Apothecary Holland'),
(10665, 0, 6, 'Maybe I should have just bought SOME off of Faruza?', 12, 0, 100, 0, 0, 0,  5961, 0, 'Junior Apothecary Holland'),
(10665, 0, 7, 'I had TO go AND requisition an Abomination... an Abomination!', 12, 0, 100, 0, 0, 0,  5962, 0, 'Junior Apothecary Holland');

-- Gina Lang SAI
SET @ENTRY := 5750;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,11939,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gina Lang - On Reset - Cast 'Summon Imp'");

-- Apothecary Jerrod
DELETE FROM `gossip_menu` WHERE (`entry`=11144 AND `text_id`=15511);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(11144, 15511); -- 38977

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=11144 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(11144, 0, 0, 'Who''s the little guy?', 0, 0, ''); -- 38977

DELETE FROM `creature_template_addon` WHERE `entry`=1548;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(1548, 0, 0x0, 0x1, ''); -- 1548

-- Scarlet Friar SAI
SET @ENTRY := 1538;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Friar - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,0,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Friar - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,20000,25000,11,75967,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Friar - In Combat - Cast 'Whirlwind'");

-- Captain Vachon SAI
SET @ENTRY := 1664;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vachon - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,6000,6000,11,79732,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Vachon - In Combat - Cast 'Shield Bash'"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,8000,12000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vachon - In Combat - Cast 'Shield Block'");

-- Scarlet Vanguard SAI
SET @ENTRY := 1540;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Vanguard - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,0,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Vanguard - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,75,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Vanguard - On Aggro - Add Aura 'Defensive Stance'"),
(@ENTRY,0,3,0,0,0,100,0,3000,6000,3000,6000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Vanguard - In Combat - Cast 'Shield Bash'");

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=11194; -- Argent Defender <The Argent Dawn>
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11194 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11194, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 12024, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '11194 - IC - CAST'),
(11194, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 6000, 6000, 11, 6660, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '11194 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10356; -- Bayne
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10356 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10356, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 15000, 15000, 11, 13443, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10356 - IC - CAST'),
(10356, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 20000, 20000, 11, 3604, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10356 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI', `minlevel`=85, `maxlevel`=85 WHERE `entry`=51522; -- Bulwark Dreadguard (not spawned, wrong level and hp)
DELETE FROM `smart_scripts` WHERE `entryorguid` = 51522 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(51522, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 7000, 7000, 11, 95826, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '51522 - IC - CAST'),
(51522, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 40505, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '51522 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1662; -- Captain Perrine
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1662 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1662, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 7000, 7000, 11, 12169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1662 - IC - CAST'),
(1662, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 15000, 15000, 11, 3019, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1662 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1523; -- Cracked Skull Soldier
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1523 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1523, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 5000, 5000, 11, 84282, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1523 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1522; -- Darkeye Bonecaster
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1522 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1522, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 13322, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1522 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1911; -- Deeb
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1911 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1911, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 4000, 4000, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1911 - IC - CAST'),
(1911, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 6000, 6000, 11, 2607, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1911 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1936; -- Farmer Solliden
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1936 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1936, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 5000, 5000, 11, 11976, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1936 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10358; -- Fellicent's Shade
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10358 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10358, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 5000, 5000, 11, 13901, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10358 - IC - CAST'),
(10358, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 7000, 7000, 11, 11975, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10358 - IC - CAST'),
(10358, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 7068, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10358 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10666; -- Gordo
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10666 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10666, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 9000, 9000, 11, 59395, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10666 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1521; -- Gretchen Dedmar
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1521 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1521, 0, 0, 0, 1, 1, 100, 0, 5000, 5000, 50000, 50000, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1521 - ooc - play emote'),
(1521, 0, 1, 0, 63, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1521 - IC - talk');
DELETE FROM creature_text WHERE entry IN (1521);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(1521, 0, 0, 'So cold...', 12, 0, 100, 0, 0, 0, 'Gretchen Dedmar', 39007);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1527; -- Hungering Dead
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1527 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1527, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 5000, 5000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1527 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1531; -- Lost Soul
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1531 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1531, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 8000, 8000, 11, 7713, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1531 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1753; -- Maggot Eye
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1753 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1753, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 100000, 100000, 11, 3237, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1753 - IC - CAST'),
(1753, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 7000, 7000, 11, 3243, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1753 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1910; -- Muad
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1910 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1910, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 6000, 6000, 11, 11824, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1910 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1688; -- Night Web Matriarch
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1688 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1688, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 15000, 15000, 11, 11918, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1688 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1505; -- Night Web Spider
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1505 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1505, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 15000, 15000, 11, 6751, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1505 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39049; -- Plagued Bruin
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39049 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39049, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 6000, 6000, 11, 16827, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '39049 - IC - CAST'),
(39049, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 11000, 11000, 11, 3242, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '39049 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1890; -- Rattlecage Skeleton
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1890 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1890, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 15000, 15000, 11, 81219, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1890 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1520; -- Rattlecage Soldier
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1520 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1520, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 7000, 7000, 11, 84282, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1520 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1526; -- Ravaged Corpse
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1526 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1526, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 7000, 7000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1526 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1549; -- Ravenous Darkhound
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1549 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1549, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 13000, 13000, 11, 82797, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1549 - IC - CAST'),
(1549, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 7000, 7000, 11, 17253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1549 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1941; -- Rot Hide Graverobber
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1941 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1941, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 120000, 120000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1941 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1675; -- Rot Hide Mongrel
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1675 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1675, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 120000, 120000, 11, 3237, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1675 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1525; -- Rotting Dead
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1525 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1525, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1525 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4282; -- Scarlet Magician
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4282 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4282, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 11, 9053, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '4282 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1528; -- Shambling Horror
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1528 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1528, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 3234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1528 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10359; -- Sri'skulk
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10359 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10359, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 15000, 15000, 11, 3583, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '10359 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1533; -- Tormented Spirit
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1533 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1533, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 13000, 13000, 11, 7713, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1533 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1545; -- Vile Fin Muckdweller
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1545 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1545, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 7159, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1545 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1532; -- Wandering Spirit
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1532 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1532, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 13000, 13000, 11, 7713, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1532 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1655; -- Nissa Agamand
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1655 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1655, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 17000, 17000, 11, 51897, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1532 - IC - CAST'),
(1655, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 3000, 3000, 11, 28993, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1532 - IC - CAST');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1657; -- Devlin Agamand
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1657 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1657, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 11, 34447, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1657 - IC - CAST'),
(1657, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, '1657 - on aggro - Talk');
DELETE FROM creature_text WHERE entry IN (1657);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(1657, 0, 0, 'Here to visit the family? Die, fool!', 12, 0, 100, 0, 0, 0, 'Devlin Agamand', 574),
(1657, 0, 1, 'The Agamand Mills is held by the Scourge, $c. Join us!', 12, 0, 100, 0, 0, 0, 'Devlin Agamand', 575);
