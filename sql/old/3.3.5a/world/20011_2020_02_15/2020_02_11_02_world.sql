-- 
SET @CGUID := 124091; -- Needs 13 consecutive guids
SET @ANNOUNCEVENT := 46; -- Event for Announces from Shattrath Saul
SET @CONCERTEVENT := 47; -- Event for Actual Concert

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12 AND  `id` IN(23623,23625,23626,23624,23619,28206,23850,23853,23855,23845,23854,23830,23852);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`,  `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 23850, 530, 3703, 3899, 1, 1, 0, 0, -1750.72, 5136.825, -36.17796, 2.111848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23850 (Area: 3899 - Difficulty: 0)
(@CGUID+1, 23853, 530, 3703, 3899, 1, 1, 0, 0, -1749.081, 5137.796, -36.17796, 2.076942, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23853 (Area: 3899 - Difficulty: 0)
(@CGUID+2, 23855, 530, 3703, 3899, 1, 1, 0, 0, -1749.921, 5134.271, -36.17796, 2.042035, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23855 (Area: 3899 - Difficulty: 0)
(@CGUID+3, 23845, 530, 3703, 3899, 1, 1, 0, 0, -1745.396, 5136.415, -36.17797, 2.024582, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23845 (Area: 3899 - Difficulty: 0)
(@CGUID+4, 23854, 530, 3703, 3899, 1, 1, 0, 0, -1752.908, 5136.067, -36.17797, 2.042035, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23854 (Area: 3899 - Difficulty: 0)
(@CGUID+5, 23830, 530, 3703, 3899, 1, 1, 0, 0, -1750.518, 5136.135, -36.17796, 2.076942, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23830 (Area: 3899 - Difficulty: 0)
(@CGUID+6, 23852, 530, 3703, 3899, 1, 1, 0, 0, -1754.977, 5133.365, -36.17797, 1.937315, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23852 (Area: 3899 - Difficulty: 0)
(@CGUID+7, 23623, 530, 3703, 3899, 1, 1, 0, 0, -1749.92,5134.53,-36.2611,1.85192, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), 
(@CGUID+8, 23625, 530, 3703, 3899, 1, 1, 0, 0, -1749.28,5138.05,-36.2611,1.826, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), 
(@CGUID+9, 23626, 530, 3703, 3899, 1, 1, 0, 0, -1752.7,5136.19,-36.2612,1.80244, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), 
(@CGUID+10, 23624, 530, 3703, 3899, 1, 1, 0, 0, -1755.31,5133.44,-36.2612,1.77574, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), 
(@CGUID+11, 23619, 530, 3703, 3899, 1, 1, 0, 0, -1745.25,5136.43,-36.2613,1.99015, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), 
(@CGUID+12, 28206, 530, 3703, 3899, 1, 1, 0, 0, -1749.92,5134.53,-36.2611,1.85192, 480, 0, 0, 0, 0, 0, 0, 0, 0, 12340); 

DELETE FROM `game_event` WHERE `eventEntry`IN(@CONCERTEVENT,@ANNOUNCEVENT);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `holidayStage`, `description`, `world_event`, `announce`) VALUES 
(@CONCERTEVENT, '2010-09-07 21:00:00', '2030-10-10 01:00:00', 180, 6, 0, 0, 'L70 ETC Shattrath', 0, 2),
(@ANNOUNCEVENT, '2010-09-07 20:50:00', '2030-10-10 01:00:00', 180, 16, 0, 0, 'L70 ETC Shattrath Announce', 0, 2);

DELETE FROM `game_event_creature` WHERE  `eventEntry`IN(@CONCERTEVENT,@ANNOUNCEVENT);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES 
(@CONCERTEVENT, @CGUID+0),
(@CONCERTEVENT, @CGUID+1),
(@CONCERTEVENT, @CGUID+2),
(@CONCERTEVENT, @CGUID+3),
(@CONCERTEVENT, @CGUID+4),
(@CONCERTEVENT, @CGUID+5),
(@CONCERTEVENT, @CGUID+6),
(@CONCERTEVENT, @CGUID+7),
(@CONCERTEVENT, @CGUID+8),
(@CONCERTEVENT, @CGUID+9),
(@CONCERTEVENT, @CGUID+10),
(@CONCERTEVENT, @CGUID+11),
(@ANNOUNCEVENT, @CGUID+12);

DELETE FROM `smart_scripts` WHERE `entryorguid`=19270 AND `source_type`=0 AND `id`IN(1,2) AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(19270, 0, 1, 0, 68, 0, 100, 512, @ANNOUNCEVENT, 0, 0, 0, 0, 80, 1927001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shattrath Saul - On Event Start Run Timed action list'),
(19270, 0, 2, 0, 11, 0, 100, 512, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shattrath Saul - On Spawn - Set Active');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1927001 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1927001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shattrath Saul - Script - Say'),
(1927001, 9, 1, 0, 0, 0, 100, 0, 120000, 120000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shattrath Saul - Script - Say'),
(1927001, 9, 2, 0, 0, 0, 100, 0, 120000, 120000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shattrath Saul - Script - Say'),
(1927001, 9, 3, 0, 0, 0, 100, 0, 120000, 120000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shattrath Saul - Script - Say');

DELETE FROM `creature_text` WHERE `CreatureID`=19270 AND `GroupID` IN(1,2,3,4) AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(19270, 1, 0, "TAUREN CHIEFTAINS! Playing LIVE, in the WORLD'S END TAVERN! Be there, at the top of the hour! Banished from Shattrath? SNEAK BACK IN!", 14, 0, 100, 0, 0, 0, 28504, 2, 'Shattrath Saul'),
(19270, 2, 0, "Are you ready to rock? Then head over to the World's End Tavern! The Tauren Chieftains start their show at the top of the hour.", 14, 0, 100, 0, 0, 0, 28496, 2, 'Shattrath Saul'),
(19270, 3, 0, "Who? The Tauren Chieftains! What? A live performance! Where? The World's End Tavern! When? The top of the hour! BE THERE!", 14, 0, 100, 0, 0, 0, 28502, 2, 'Shattrath Saul'),
(19270, 4, 0, "Now, in Shattrath City: The Tauren Chieftains! Playing in the World's End Tavern at the top of the hour!", 14, 0, 100, 0, 0, 0, 28481, 2, 'Shattrath Saul');

UPDATE `smart_scripts` SET `action_param3`=1 WHERE  `entryorguid`=23830 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=23619 AND `source_type`=0 AND `id`=12 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23619 AND `source_type`=0 AND `id`IN(19,20,21) AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23623 AND `source_type`=0 AND `id`IN(20,21,22) AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23624 AND `source_type`=0 AND `id` IN(19,20) AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23626 AND `source_type`=0 AND `id`IN(20,21) AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23625 AND `source_type`=0 AND `id`IN(19,20) AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23619, 0, 19, 0, 1, 0, 100, 1, 213000, 213000, 0, 0, 0, 28, 34126, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Remove \'Spotlight\''),
(23619, 0, 20, 0, 1, 0, 100, 1, 27990, 27990, 0, 0, 0, 28, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - Out of Combat - Remove Greater Invisibility'),
(23619, 0, 21, 0, 11, 0, 100, 1, 0, 0, 0, 0, 0, 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bergrisst - On Spawn - Cast Greater Invisibility'),
(23625, 0, 19, 0, 1, 0, 100, 1, 9900, 9900, 0, 0, 0, 28, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - Out of Combat - Remove Greater Invisibility'),
(23625, 0, 20, 0, 11, 0, 100, 1, 0, 0, 0, 0, 0, 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samuro - On Spawn - Cast Greater Invisibility'),
(23623, 0, 20, 0, 1, 0, 100, 1, 23990, 23990, 0, 0, 0, 28, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Remove Greater Invisibility'),
(23623, 0, 21, 0, 11, 0, 100, 1, 0, 0, 0, 0, 0, 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - On Spawn - Cast Greater Invisibility'),
(23623, 0, 22, 0, 1, 0, 100, 1, 23990, 23990, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 28206, 0, 0, 0, 0, 0, 0, 'Chief Thunder-Skins - Out of Combat - Despawn [DND] L70ETC Drums'),
(23624, 0, 19, 0, 1, 0, 100, 1, 12990, 12990, 0, 0, 0, 28, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - Out of Combat - Remove Greater Invisibility'),
(23624, 0, 20, 0, 11, 0, 100, 1, 0, 0, 0, 0, 0, 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mai\'Kyl - On Spawn - Cast Greater Invisibility'),
(23626, 0, 20, 0, 1, 0, 100, 1, 12990, 12990, 0, 0, 0, 28, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - Out of Combat - Remove Greater Invisibility'),
(23626, 0, 21, 0, 11, 0, 100, 1, 0, 0, 0, 0, 0, 11, 16380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sig Nicious - On Spawn - Cast Greater Invisibility');
