SET @CGUID := 74539;

UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`IN(25335,25336,25338,25359);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25335,25336,25338,25359) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2533500,2533501,2533600) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25335,0,0,1,19,0,100,0,11592,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Quest Accept (We Strike!) - Store Targetlist'),
(25335,0,1,0,61,0,100,0,0,0,0,0,80,2533500,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Quest Accept (We Strike!) - Run Script'),
(25335,0,2,3,6,0,100,0,0,0,0,0,6,11592,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - On Death - Fail Quest (We Strike)'),
(25335,0,3,4,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - On Death - Set Data to Grunt Ragefist'),
(25335,0,4,0,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - On Death - Set Data to Warsong Caravan Guard'),
(25335,0,5,0,40,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP - Set Home Position'),
(25335,0,6,7,61,0,100,0,0,0,0,0,45,4,4,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP - Set Data to Grunt Ragefist'),
(25335,0,7,0,61,0,100,0,0,0,0,0,45,4,4,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - On Reached WP - Set Data to Warsong Caravan Guard'),
(25335,0,8,9,40,0,100,1,9,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP9 - Pause WP for 5 Seconds'),
(25335,0,9,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP9 - Say Line 2'),
(25335,0,10,0,61,0,100,0,9,0,0,0,107,1,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP9 - Summon Group 1'),
(25335,0,11,0,40,0,100,1,10,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP10 - Say Line 3'),
(25335,0,12,13,40,0,100,1,13,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - On Reached WP13 - Say Line 4'),
(25335,0,13,14,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0, 0, 0,0, 'Longrunner Proudhoof - On Reached WP13 - Set Home Position'),
(25335,0,14,0,61,0,100,0,0,0,0,0,12,25359,1,100000,0,0,0,8,0,0,0,3879.794, 5719.112, 66.50308,1.048136, 'Longrunner Proudhoof - On Reached WP13 - Summon '),
(25335,0,15,0,38,0,100,0,5,5,0,0,80,2533501,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Data Set 5 5 - Run Script 2'),
(25335,0,16,0,11,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - On Respawn - Reset Scripts '),
(25336,0,0,0,38,0,100,0,1,1,0,0,80,2533600,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 1 1 - Run Script'),
(25336,0,1,2,38,0,100,0,2,2,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 2 2 - Set Run on'),
(25336,0,2,0,61,0,100,0,0,0,0,0,29,2,3,0,0,0,0,19,25335,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 2 2 - Follow Longrunner Proudhoof'),
(25336,0,3,0,38,0,100,0,3,3,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 3 3 - Despawn'),
(25336,0,4,0,38,0,100,0,4,4,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - On Data Set 4 4 - Set Home Position'),
(25336,0,5,0,1,0,100,0,0,0,2000,2000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - OOC - Set Home Position'),
(25338,0,0,1,38,0,100,0,1,1,0,0,2,232,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 1 1 - Set Faction'),
(25338,0,1,2,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 1 1 - Set Hostile'),
(25338,0,2,0,61,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 1 1 - Switch HP Regen off'),
(25338,0,3,4,38,0,100,0,2,2,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 2 2 - Set Run on'),
(25338,0,4,0,61,0,100,0,0,0,0,0,29,1,2,0,0,0,0,19,25335,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 2 2 - Follow Longrunner Proudhoof'),
(25338,0,5,0,38,0,100,0,3,3,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 3 3 - Despawn'),
(25338,0,6,0,38,0,100,0,4,4,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - On Data Set 4 4 - Set Home Position'),
(25338,0,7,0,1,0,100,0,0,0,2000,2000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Caravan Guard - OOC - Set Home Position'),

(25359,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,25335,0,0,0,0,0,0, 'Force-Commander Steeljaw - On Just Summoned - Attack Longrunner Proudhoof'),
(25359,0,1,2,6,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - On Death Say Line 0'),
(25359,0,2,0,6,0,100,0,0,0,0,0,45,5,5,0,0,0,0,19,25335,0,0,0,0,0,0, 'Force-Commander Steeljaw - On Death - Set Data to Longrunner Proudhoof'),
(25359,0,3,0,9,0,100,0,0,5,8000,13000,11,15284,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - On Range - Cast Cleave'),
(25359,0,4,0,0,0,100,0,6000,9000,11000,18000,11,38256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - IC - Cast Piercing Howl'),
(25359,0,5,0,2,0,100,1,0,50,0,0,11,50204,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - On 20% HP - Cast Steeljaw'),
(25359,0,6,0,0,0,100,0,9000,15000,18000,24000,11,41056,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Force-Commander Steeljaw - IC - Cast Whirlwind'),

(2533500,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set NPC Flags'),
(2533500,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set Data to Grunt Ragefist'),
(2533500,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - Script - Set Data to Warsong Caravan Guard'),
(2533500,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Say Line 0'),
(2533500,9,4,0,0,0,100,0,0,0,0,0,2,232,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set Faction'),
(2533500,9,5,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set Hostile'),
(2533500,9,6,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Switch HP Regen off'),
(2533500,9,7,0,0,0,100,0,11000,11000,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Say Line 0'),
(2533500,9,8,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Set Data to Grunt Ragefist'),
(2533500,9,9,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - Script - Set Data to Warsong Caravan Guard'),
(2533500,9,10,0,0,0,100,0,0,0,0,0,53,1,25335,0,0,0,2,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script - Start WP'),

(2533501,9,0,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Say Line 5'),
(2533501,9,1,0,0,0,100,0,0,0,0,0,15,11592,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Complete Quest (We Strike)'),
(2533501,9,2,0,0,0,100,0,6000,6000,0,0,45,3,3,0,0,0,0,19,25336,0,0,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Set Data to Grunt Ragefist'),
(2533501,9,3,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,9,25338,0,200,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Set Data to Warsong Caravan Guard'),
(2533501,9,4,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Longrunner Proudhoof - Script 2 - Despawn'),

(2533600,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - Script - Set NPC Flags'),
(2533600,9,1,0,0,0,100,0,0,0,0,0,2,232,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - Script - Set Faction'),
(2533600,9,2,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - Script - Set Hostile'),
(2533600,9,3,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grunt Ragefist - Script - Switch HP Regen off');


DELETE FROM `waypoints` WHERE `entry`=25335;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25335, 1, 4121.404, 5791.311, 62.72873, 'Longrunner Proudhoof'),
(25335, 2, 4101.437, 5799.435, 67.94357, 'Longrunner Proudhoof'),
(25335, 3, 4083.929, 5805.443, 71.37161, 'Longrunner Proudhoof'),
(25335, 4, 4068.87, 5807.64, 73.81717, 'Longrunner Proudhoof'),
(25335, 5, 4052.772, 5802.647, 75.09177, 'Longrunner Proudhoof'),
(25335, 6, 4038.374, 5795.233, 75.40152, 'Longrunner Proudhoof'),
(25335, 7, 4025.04, 5789.227, 75.19473, 'Longrunner Proudhoof'),
(25335, 8, 4006.379, 5787.299, 73.14676, 'Longrunner Proudhoof'),
(25335, 9, 3984.424, 5778.06, 73.17698, 'Longrunner Proudhoof'), -- Event
(25335, 10, 3952.678, 5758.444, 70.48514, 'Longrunner Proudhoof'), -- text
(25335, 11, 3919.015, 5753.338, 69.2403, 'Longrunner Proudhoof'),
(25335, 12, 3894.645, 5745.702, 70.36196, 'Longrunner Proudhoof'),
(25335, 13, 3883.361, 5725.309, 67.55053, 'Longrunner Proudhoof');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=25335;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(25335, 0, 1, 25351, 3981.684, 5766.304, 71.69027, 1.508547, 3, 100000),
(25335, 0, 1, 25351, 3972.008, 5783.715, 74.18502, 5.856251, 3, 100000),
(25335, 0, 1, 25351, 3996.715, 5773.316, 70.84, 2.772876, 3, 100000),
(25335, 0, 1, 25350, 3988.267, 5791.996, 74.18443, 4.443494, 3, 100000),
(25335, 0, 1, 25351, 3969.23, 5768.75, 72.69688, 0.5497994, 3, 100000);


DELETE FROM `creature_text` WHERE `entry`IN(25335,25359);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(25335, 0, 0, '$n is going to join us on our assault. Let us bring peace to my ancestors!', 12, 1, 100, 396, 0, 0, 'Longrunner Proudhoof',24561),
(25335, 1, 0, 'WE STRIKE!', 14, 1, 100, 15, 0, 0, 'Longrunner Proudhoof',24562),
(25335, 2, 0, 'An ambush. Return them to their rest!', 12, 1, 100, 5, 0, 0, 'Longrunner Proudhoof',24563),
(25335, 3, 0, 'Regain your strength. The place where Steeljaw was felled is just ahead.', 12, 1, 100, 396, 0, 0, 'Longrunner Proudhoof',24564),
(25335, 4, 0, 'There''s the dog''s banner and there''s his corpse. What''s that? He''s upon us!', 12, 1, 100, 25, 0, 0, 'Longrunner Proudhoof',24565),
(25335, 5, 0, 'You fought well. Now go north to your orc outpost and inform Overlord Bor''gorok of our success!', 12, 1, 100, 113, 0, 0, 'Longrunner Proudhoof',24566),
(25359, 0, 0, 'I''m freed! Thank you.', 12, 1, 100, 0, 0, 0, 'Force-Commander Steeljaw',24575);

-- Warsong Caravan Guards
DELETE FROM `creature` WHERE `id`=25338;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 25338, 571, 1, 1, 4141.54, 5783.948, 60.69736, 2.86234, 120, 0, 0), -- 25338 (Area: 3537)
(@CGUID+1, 25338, 571, 1, 1, 4139.149, 5782.773, 60.48185, 2.86234, 120, 0, 0), -- 25338 (Area: 3537)
(@CGUID+2, 25338, 571, 1, 1, 4141.218, 5786.635, 61.20373, 2.9147, 120, 0, 0); -- 25338 (Area: 3537)
