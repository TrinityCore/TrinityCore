SET @CGUID       := 10998;

DELETE FROM creature WHERE `guid` IN(@CGUID,@CGUID+1);
INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 28139, 571, 0, 0, 1, 1, 0, 0, 5268.422, 4522.266, -83.79454, 4.956735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- 28069 (Area: 0)
(@CGUID+1, 28139, 571, 0, 0, 1, 1, 0, 0, 5257.281, 4501.662, -85.16033, 0.296706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463); -- 28069 (Area: 0)

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(29043,28139,29116);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(29043,28139,29116) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-@CGUID,-@CGUID-1) AND `source_type`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` =2904300 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29043, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - On Spawn - Set Phase 1'), 
(29043, 0, 1, 0, 20, 1, 100, 0, 12758, 0, 0, 0, 80, 2904300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - On Quest Reward 12758 (Phase 1) - Run Script'), 
(29116, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 53170, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwatcher Head - On Just Summoned - Cast Ride Rejek'), 
(29116, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 28, 53170, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwatcher Head - On Data Set - Remove Aura Ride Rejek'), 
(-@CGUID-0, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Data set - Set Visible'), 
(-@CGUID-1, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Data set - Set Visible'), 
(-@CGUID-0, 0, 1, 0, 61, 0, 100, 0, 1, 1, 0, 0, 53, 1, (@CGUID*10)+0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Data set - start WP'), 
(-@CGUID-1, 0, 1, 0, 61, 0, 100, 0, 1, 1, 0, 0, 53, 1, (@CGUID*10)+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Data set - start WP'), 
(-@CGUID-0, 0, 3, 0, 40, 0, 100, 0, 2, (@CGUID*10)+0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Reached WP - Set Invisible'), 
(-@CGUID-1, 0, 3, 0, 40, 0, 100, 0, 2, (@CGUID*10)+1, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Reached WP - Set Invisible'), 
(-@CGUID-0, 0, 3, 4, 40, 0, 100, 0, 1, (@CGUID*10)+0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.585053, 'Frenzyheart Pup - On Reached WP - Set Orientation'), 
(-@CGUID-1, 0, 3, 4, 40, 0, 100, 0, 1, (@CGUID*10)+1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.986479, 'Frenzyheart Pup - On Reached WP - Set Orientation'), 
(-@CGUID-0, 0, 4, 6, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Reached WP - Say'), 
(-@CGUID-1, 0, 4, 6, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Reached WP - Say'), 
(-@CGUID-0, 0, 5, 0, 38, 0, 100, 0, 3, 3, 0, 0, 11, 42963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Data set - Cast Cosmetic - Combat Knockdown Self'), 
(-@CGUID-1, 0, 5, 0, 38, 0, 100, 0, 3, 3, 0, 0, 11, 42963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Data set - Cast Cosmetic - Combat Knockdown Self'), 
(-@CGUID-0, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 22500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Reached WP - Pause WP'), 
(-@CGUID-1, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 22500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Reached WP - Pause WP'), 
(-@CGUID-0, 0, 7, 0, 11, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Spawn - Set Invisible'), 
(-@CGUID-1, 0, 7, 0, 11, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frenzyheart Pup - On Spawn - Set Invisible'), 
(2904300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Set Phase 2'), -- 16:44:29.469
(2904300, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Say Line 0'), -- 16:44:31.812
(2904300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+0, 28139, 0, 0, 0, 0, 0, 'Rejek - Script - Set Data'), 
(2904300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+1, 28139, 0, 0, 0, 0, 0, 'Rejek - Script - Set Data'), 
(2904300, 9, 4, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Say Line 1'), -- 16:44:41.562
(2904300, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.410521, 'Rejek - Script - Set Orientation'), -- 16:44:45.109
(2904300, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Play emote OneShotAttackUnarmed'), -- 16:44:46.344 
(2904300, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 53171, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Cast Summon Stormwatcher Head'), -- 16:44:46.344 
(2904300, 9, 8, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.460914, 'Rejek - Script - Set Orientation'), -- 16:44:47.531
(2904300, 9, 9, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Say Line 2'), -- 16:44:48.844
(2904300, 9, 10, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+0, 28139, 0, 0, 0, 0, 0, 'Rejek - Script - Set Data'), -- 16:44:51.359
(2904300, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+1, 28139, 0, 0, 0, 0, 0, 'Rejek - Script - Set Data'), -- 16:44:51.359
(2904300, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 28139, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Say Line 2 on Frenzyheart Pup'), -- 16:44:51.359
(2904300, 9, 13, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Say Line 3'), -- 16:44:57.312
(2904300, 9, 14, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29116, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Say Line 3'), -- 16:45:06.937
(2904300, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script - Set Phase 1');

DELETE FROM `creature_text` WHERE `entry` IN(29043,28139);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29043, 0, 0, 'Who wants to see Rejek''s new helmet?', 12, 0, 100, 1, 0, 0, 29460, 0, 'Rejek'),
(29043, 1, 0, 'Ok, Rejek show!', 12, 0, 100, 1, 0, 0, 29463, 0, 'Rejek'),
(29043, 2, 0, 'What you think?', 12, 0, 100, 1, 0, 0, 29464, 0, 'Rejek'),
(29043, 3, 0, 'Rejek like! If helmet scares pups, Rejek can''t wait to see what it does to big-tongue cowards!', 12, 0, 100, 35, 0, 0, 29466, 0, 'Rejek'),
(28139, 0, 0, 'I wanna see!', 12, 0, 100, 396, 0, 0, 29461, 0, 'Frenzyheart Pup'),
(28139, 1, 0, 'Show me too!', 12, 0, 100, 1, 0, 0, 29462, 0, 'Frenzyheart Pup'),
(28139, 2, 0, 'Metalhead ate Rejek! Run!', 12, 0, 100, 1, 0, 0, 29465, 0, 'Frenzyheart Pup');

DELETE FROM `waypoints` WHERE `entry` IN((@CGUID*10)+0,(@CGUID*10)+1);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
((@CGUID*10)+0, 1, 5267.188, 4506.771, -84.47479, 'Frenzyheart Pup'),
((@CGUID*10)+0, 2, 5267.754, 4522.471, -83.85757, 'Frenzyheart Pup'),
((@CGUID*10)+1, 1, 5264.369, 4503.333, -84.65268, 'Frenzyheart Pup'),
((@CGUID*10)+1, 2, 5243.813, 4501.6, -84.7424, 'Frenzyheart Pup');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=53170;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 53170, 0, 0, 31, 0, 3, 29043, 0, 0, 0, 0, '', 'Ride Rejek');
