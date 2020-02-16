-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28253,28273,-119104,-119105) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2827300) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-119104, 0, 0, 1, 8, 0, 100, 0, 51172, 0, 2000, 2000, 0, 11, 51169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On spell hit - Cast Fierce Lightning Spawner'),
(-119104, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 1, 2825300, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On spell hit - Start WP'),
(-119104, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 23310, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On spell hit - morph'),
(-119104, 0, 3, 0, 40, 0, 100, 0, 4, 2825300, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On Waypoint reach - despawn'),
(-119105, 0, 0, 1, 8, 0, 100, 0, 51172, 0, 2000, 2000, 0, 11, 51169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On spell hit - Cast Fierce Lightning Spawner'),
(-119105, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 1, 2825301, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On spell hit - Start WP'),
(-119105, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 23310, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On spell hit - morph'),
(-119105, 0, 3, 0, 40, 0, 100, 0, 4, 2825301, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Lightning Cloud - On Waypoint reach - despawn'),
(28273, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 2827300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Arranged Crystal Formation Bunny - On just summoned - Action list'),
(2827300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 51150, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Arranged Crystal Formation Bunny - Action list - Cast  Crystal Shatter Visual\ Action list'),
(2827300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 19, 28216, 40, 0, 0, 0, 0, 0, 0, 'Arranged Crystal Formation Bunny - Action list - Set Data 1 2'),
(2827300, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 51172, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Arranged Crystal Formation Bunny - Action list - Cast  Lightning to Cloud'),
(2827300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 99, 2, 0, 0, 0, 0, 0, 20, 190502, 0, 0, 0, 0, 0, 0, 0, 'Arranged Crystal Formation Bunny - Action list - Set loot state Gameobject \'Arranged Crystal Formation\''),
(2827300, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 99, 3, 0, 0, 0, 0, 0, 15, 190503, 10, 0, 0, 0, 0, 0, 0, 'Arranged Crystal Formation Bunny - Action list - Set loot state Gameobject \'Arranged Crystal Formation\''),
(2827300, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 15, 12537, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Arranged Crystal Formation Bunny - Action list - Quest Credit \'Lightning Definitely Strikes Twice\'');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28110,28109) AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2811000,2811001) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28110, 0, 3, 0, 8, 0, 100, 0, 51122, 0, 11000, 11000, 0, 88, 2811000, 2811001, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Oracle - On Spellhit \'Fierce Lightning Stike\' - Run random Script'),
(28109, 0, 3, 0, 8, 0, 100, 0, 51122, 0, 11000, 11000, 0, 88, 2811000, 2811001, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Warrior - On Spellhit \'Fierce Lightning Stike\' - Run random Script'),
(2811000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 52079, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Oracle - Script - Cast Impact'),
(2811000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 28216, 40, 0, 0, 0, 0, 0, 0, 'Arranged Crystal Formation Bunny - Action list - Set Data 1 2'),
(2811000, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 42963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Oracle - Script - cast Knockdown'),
(2811000, 9, 3, 0, 0, 0, 100, 0, 500, 500, 0, 0, 0, 11, 51201, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Oracle - Script - Cast Cosmetic - Smoking Corpse'),
(2811000, 9, 4, 0, 0, 0, 100, 0, 500, 500, 0, 0, 0, 11, 3617, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Oracle - Script   - Cast killself'),
(2811001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 52079, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Oracle - Script - Cast Impact'),
(2811001, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 28216, 40, 0, 0, 0, 0, 0, 0, 'Arranged Crystal Formation Bunny - Action list - Set Data 1 2'),
(2811001, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 42963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Oracle - Script - cast Knockdown'),
(2811001, 9, 3, 0, 0, 0, 100, 0, 500, 500, 0, 0, 0, 11, 52061, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Oracle - Script - Cast Fear'),
(2811001, 9, 4, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mistwhisper Oracle - Script   - Cast killself');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN (51172,51122);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,51172,0,0,31,0,3,28253,0,0,0,0, '', 'Cloud to Lightning hits Mistwhisper Lightning Cloud'),
(13,1,51122,0,0,31,0,3,28254,0,0,0,0, '', 'Fierce Lightning Stike hits Mistwhisper Lightning Target'),
(13,1,51122,0,1,31,0,3,28109,0,0,0,0, '', 'Fierce Lightning Stike hits Mistwhisper Warrior'),
(13,1,51122,0,2,31,0,3,28110,0,0,0,0, '', 'Fierce Lightning Stike hits Mistwhisper Oracle');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`IN (51151);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,51151,0,0,29,0,28273,20,0,1,0,0, '', 'Place Skyreach Crystals'),
(17,0,51151,0,0,30,0,190502,20,0,1,0,0, '', 'Place Skyreach Crystals');

DELETE FROM `event_scripts` WHERE `id` IN (18475,18474);
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(18475, 2, 9, 4599, 60, 0, 0, 0, 0, 0),
(18475, 2, 9, 9304, 60, 0, 0, 0, 0, 0),
(18475, 2, 9, 9305, 60, 0, 0, 0, 0, 0),
(18475, 2, 9, 9307, 60, 0, 0, 0, 0, 0),
(18474, 1, 10,28273,30000,0,6206.318,4951.269,-96.66917,0.6108652);

DELETE FROM `creature` WHERE `id` IN (28273);
DELETE FROM `creature_addon` WHERE `guid` IN (106338);
DELETE FROM `creature` WHERE `guid` IN (119104,119105);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(119104, 28253, 571, 3711, 4306, 1, 1, 11686, 0, 6224.011, 4944.437, -80.04568, 4.904375, 2, 0, 0, 1, 0, 0, 0, 0, 0, 14545), -- 28253 (Area: 4306 - Difficulty: 0) (Auras: 51169 - 51169) (possible waypoints or random movement)
(119105, 28253, 571, 3711, 4306, 1, 1, 11686, 0, 6196.975, 4964.1, -80.53481, 2.949606, 2, 0, 0, 1, 0, 0, 0, 0, 0, 14545); -- 28253 (Area: 4306 - Difficulty: 0) (Auras: 51169 - 51169) (possible waypoints or random movement)

UPDATE `gameobject` SET `position_x`=6206.035, `position_y`=4950.958, `position_z`=-98.87278, `orientation`=6.073746 WHERE `id`=190502;
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `Entry` IN (190502);

DELETE FROM `gameobject` WHERE `guid` IN (9304,9305,9307);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(9304, 190503, 571, 3711, 4306, 1, 1, 6205.198, 4951.755, -98.87682, 3.839725, 0, 0, -0.9396925, 0.3420205, -1, 255, 1, 14545), -- 190503 (Area: 4306 - Difficulty: 0)
(9305, 190503, 571, 3711, 4306, 1, 1, 6207.116, 4950.446, -98.87629, 5.480334, 0, 0, -0.3907309, 0.920505, -1, 255, 1, 14545), -- 190503 (Area: 4306 - Difficulty: 0)
(9307, 190503, 571, 3711, 4306, 1, 1, 6206.69, 4951.788, -98.91489, 2.740162, 0, 0, 0.9799242, 0.1993704, -1, 255, 1, 14545); -- 190503 (Area: 4306 - Difficulty: 0)

DELETE FROM `waypoints` WHERE `entry` IN (2825300,2825301);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2825300, 1, 6224.967, 4957.806, -70.71909, 'Mistwhisper Lightning Cloud'),
(2825300, 2, 6233.925, 4986.368, -70.71909, 'Mistwhisper Lightning Cloud'),
(2825300, 3, 6269.082, 4992.032, -70.71909, 'Mistwhisper Lightning Cloud'),
(2825300, 4, 6317.538, 4970.312, -70.71909, 'Mistwhisper Lightning Cloud'),
(2825301, 1, 6191.627, 4973.427, -70.71909, 'Mistwhisper Lightning Cloud'),
(2825301, 2, 6158.727, 5018.104, -61.37012, 'Mistwhisper Lightning Cloud'),
(2825301, 3, 6134.556, 4969.962, -61.37012, 'Mistwhisper Lightning Cloud'),
(2825301, 4, 6107.038, 5010.760, -61.37012, 'Mistwhisper Lightning Cloud');

DELETE FROM `creature_template_addon` WHERE `entry` IN (28110);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(28110, 0, 0, 0, 1, 0, '50727'); -- 28110 - 50727

-- Zepik the Gorloc Hunter
DELETE FROM `smart_scripts` WHERE `entryorguid`=28216 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28216, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Respawn - Set Reactstate Defensive"),
(28216, 0, 1, 0, 8, 0, 100, 0, 51234, 0, 45000, 70000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Spellhit 'Frenzyheart Hill Aura' - Say Line 0"), -- Frenzyheart Hill
(28216, 0, 2, 0, 8, 0, 100, 0, 53163, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Spellhit 'Dessawn Retainer' - Despawn Instant"),
(28216, 0, 3, 0, 0, 0, 100, 0, 4000, 7000, 15000, 18000, 0, 11, 52761, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - In Combat - Cast 'Barbed Net'"),
(28216, 0, 4, 0, 0, 0, 100, 0, 5000, 8000, 12000, 15000, 0, 11, 52889, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - In Combat - Cast 'Envenomed Shot'"),
(28216, 0, 5, 0, 0, 0, 100, 0, 0, 6000, 15000, 18000, 0, 11, 52873, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - In Combat - Cast 'Open Wound'"),
(28216, 0, 6, 0, 0, 0, 100, 0, 3000, 5000, 3000, 7000, 0, 11, 52758, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - In Combat - Cast 'Piercing Arrow'"),
(28216, 0, 7, 0, 2, 0, 100, 0, 0, 30, 60000, 60000, 0, 11, 52895, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - Between 0-30% Health - Cast 'Bandage'"),
(28216, 0, 8, 0, 38, 0, 100, 0, 2, 2, 20000, 20000, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On data set - Say Line 1"),--  light hit big-tongues
(28216, 0, 9, 0, 1, 0, 100, 0, 10000, 40000, 45000, 90000, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - Out of Combat - Say Line 7"), -- River's heart
(28216, 0, 10, 0, 8, 2, 100, 0, 51239, 0, 40000, 70000, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Spellhit 'Mistwhisper Refuge Aura' - Say Line 3"), -- Mistwhisper Refuge
(28216, 0, 11, 0, 1, 0, 100, 0, 3000, 3000, 3000, 3000, 0, 11, 51792, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Respawn - Cast 'Wolvar Location Periodic'"),
(28216, 0, 12, 0, 1, 0, 100, 0, 3000, 3000, 3000, 3000, 0, 11, 51623, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Respawn - Cast 'Sholazar Guardian Heartbeat'"),
(28216, 0, 13, 0, 38, 0, 100, 0, 1, 2, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Data Set 1 2 - Say Line 3"),
(28216, 0, 14, 0, 8, 0, 100, 0, 51843, 0, 6000, 10000, 0, 11, 51959, 0, 0, 0, 0, 0, 19, 28161, 5, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Spellhit 'Chicken Location Ping' - Cast 'Chicken Net'"),
(28216, 0, 15, 0, 8, 0, 100, 0, 51843, 0, 40000, 70000, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Spellhit 'Chicken Location Ping' - Say Line 2"), -- Chikn quest Chickens
(28216, 0, 16, 17, 38, 0, 100, 0, 1, 3, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Data Set 1 3 - Say Line 6"), -- Croco quest
(28216, 0, 17, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Data Set 1 3 - Despawn"),
(28216, 0, 18, 0, 8, 0, 100, 0, 51643, 0, 45000, 70000, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - On Spellhit 'Kartak's Hold Aura' - Say Line 9"), -- 'Kartak's Hold
(28216, 0, 19, 20, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - Out of Combat - Say Line 7"), -- Broken pillar
(28216, 0, 20, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Zepik the Gorloc Hunter - Out of Combat - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=28216 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 15, 28216, 0, 0, 29, 0, 28161, 5, 0, 0, 0, 0, "", "Execute SAI only if there is chicken escapee within 5 yards"),
(22, 10, 28216, 0, 0, 23, 1, 4290, 0, 0, 0, 0, 0, "", "Zepik dont execute sai in River's heart"),
(22, 20, 28216, 0, 0, 23, 1, 4296, 0, 0, 0, 0, 0, "", "Zepik dont execute sai in Broken pillar");

DELETE FROM `creature_text` WHERE `CreatureID`=28216;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
-- Frenzyheart Hill
(28216, 0, 0, "Dajik tried to show me ways of hunt,, but I do better when I do things my way.", 12, 0, 100, 0, 0, 0, 28201, 0, "Zepik"),
(28216, 0, 1, "Bring back good meat and the camp treat you like high-shaman for a day. Good deal.", 12, 0, 100, 0, 0, 0, 28202, 0, "Zepik"),
(28216, 0, 2, "You should go let chickens out again and say Goregek did it. Never get old.", 12, 0, 100, 0, 0, 0, 28203, 0, "Zepik"),
(28216, 0, 3, "I not in a big hurry. We can rest here a while if want.", 12, 0, 100, 0, 0, 0, 28204, 0, "Zepik"),
(28216, 0, 5, "I not live here always... I traveled lot of world on my own not long ago. I like all the stories of beasts and dragons and gods and stuff.", 12, 0, 100, 0, 0, 0, 28205, 0, "Zepik"),
(28216, 0, 6, "Elder Harkek pretty good Frenzyheart. He help me a lot when I was littler and not liking Dajik.", 12, 0, 100, 0, 0, 0, 28206, 0, "Zepik"),
 -- light hit big-tongues
(28216, 1, 0, "Hahah! You see that? Lightning bolt hit him right in the head!", 12, 0, 100, 0, 0, 0, 28223, 0, "Zepik"),
(28216, 1, 1, "BOOM! That so good! More! More!", 12, 0, 100, 0, 0, 0, 28224, 0, "Zepik"),
(28216, 1, 2, "Zap!", 12, 0, 100, 0, 0, 0, 28225, 0, "Zepik"),
(28216, 1, 3, "We need to do this more often! This so funny... lightning hitting big-tongues everywhere!", 12, 0, 100, 0, 0, 0, 28226, 0, "Zepik"),
(28216, 1, 4, "Good one! It not even see it coming.", 12, 0, 100, 0, 0, 0, 28239, 0, "Zepik"),
(28216, 1, 5, "Hah! Leave some for Zepik too.", 12, 0, 100, 0, 0, 0, 28240, 0, "Zepik"),
(28216, 1, 6, "No more play?", 12, 0, 100, 0, 0, 0, 28241, 0, "Zepik"),
(28216, 1, 7, "Flame! Death! Destruction! The black fire rages within my heart! I must... release it! Hahah!", 12, 0, 100, 0, 0, 0, 28242, 0, "Zepik"),
-- Chickens
(28216, 2, 0, "May not be great hunt,, but this still fun after so many time.", 12, 0, 100, 0, 0, 0, 28231, 0, "Zepik"),
(28216, 2, 1, "You think they learn to keep Goregek away from chickens.", 12, 0, 100, 0, 0, 0, 28232, 0, "Zepik"),
(28216, 2, 2, "Goregek never 'stumble' into chicken hut... Goregek always have to feed his dumb belly. Always one chicken missing when we catch them all.", 12, 0, 100, 0, 0, 0, 28233, 0, "Zepik"),
(28216, 2, 3, "You chickens are tougher than I thought! I'll have to improvise!", 12, 0, 100, 0, 0, 0, 28234, 0, "Zepik"),
(28216, 2, 4, "You pretty good! Natural at hunt,, like me.", 12, 0, 100, 0, 0, 0, 28235, 0, "Zepik"),
(28216, 2, 5, "Goregek think he the boss of everyone,, but he eat too much and hunt too little.", 12, 0, 100, 0, 0, 0, 28236, 0, "Zepik"),
(28216, 2, 6, "Dajik forget what he doing,, where he at... sometime even forget his own name. Make him not so good teacher sometimes.", 12, 0, 100, 0, 0, 0, 28237, 0, "Zepik"),
(28216, 2, 7, "You ever fought big dragon or god or anything? Zepik like hearing stories.", 12, 0, 100, 0, 0, 0, 28238, 0, "Zepik"),
-- cristal activation
(28216, 3, 0, "Hah! This the fun part!", 12, 0, 100, 0, 0, 0, 28475, 0, "Zepik"),
(28216, 3, 1, "Eat it big-tongues!", 12, 0, 100, 0, 0, 0, 28478, 0, "Zepik"),
(28216, 3, 2, "Trust me - you going love this!", 12, 0, 100, 0, 0, 0, 28477, 0, "Zepik"),
-- say at  Mistwhisper Refuge
(28216, 4, 0, "That lake near here actually full of sea things. Not sure how it all get here... maybe in floods?", 12, 0, 100, 0, 0, 0, 28227, 0, "Zepik"),
(28216, 4, 1, "I think one reason I like hunting big-tongues so much... they not as dumb as the other hunts. They give a real fight.", 12, 0, 100, 0, 0, 0, 28228, 0, "Zepik"),
(28216, 4, 2, "Mist big-tongues are smart with their shrine thing sometimes... cover whole area with mist and it get hard to find any.", 12, 0, 100, 0, 0, 0, 28229, 0, "Zepik"),
(28216, 4, 3, "Careful of big mistcaller guy... Zepik fought him once and barely got away. He lot stronger than rest of big-tongues here.", 12, 0, 100, 0, 0, 0, 28230, 0, "Zepik"),
-- Croco quest 
(28216, 5, 0, "Enjoy ride! Call me when you get there.", 12, 0, 100, 0, 0, 0, 28881, 0, "Zepik"),
-- despawn Broken pillar
(28216, 6, 0, "My kind not welcome at broken pillar. I going back to hill - find me when you done.", 12, 0, 100, 0, 0, 0, 28219, 0, "Zepik"),
(28216, 6, 1, "Many Frenzyheart lost at broken pillar. Today is not Zepik's day to be lost too.", 12, 0, 100, 0, 0, 0, 28220, 0, "Zepik"),
(28216, 6, 2, "I thought about tricking big-tongues to come here,, but it too dangerous for me. You have good luck and I meet you back at hill.", 12, 0, 100, 0, 0, 0, 28221, 0, "Zepik"),
(28216, 6, 3, "Bad plan to come here... many more adventures to be had before I risk this place. Be safe... I meet you later.", 12, 0, 100, 0, 0, 0, 28222, 0, "Zepik"),
-- River heart
(28216, 7, 0, "Not sure if you notice,, but there rumbling sometimes from the water in the big hole. I think there something down there.", 12, 0, 100, 0, 0, 0, 28243, 0, "Zepik"),
(28216, 7, 1, "Big-tongues don't usually come down here anymore... I had a big fight and killed lots.", 12, 0, 100, 0, 0, 0, 28244, 0, "Zepik"),
(28216, 7, 2, "I always wonder where all the water go... doesn't make sense.", 12, 0, 100, 0, 0, 0, 28245, 0, "Zepik"),
(28216, 7, 3, "Vekjik likes finding big-tongues that wander too far to throw in the basin. He help me trap some of the dumb ones. You should watch him sometime... it pretty funny actually.", 12, 0, 100, 0, 0, 0, 28246, 0, "Zepik"),
(28216, 7, 4, "Battle here been going on for a while... these spark big-tongues have a lot more fight than the other ones.", 12, 0, 100, 0, 0, 0, 28247, 0, "Zepik"),
(28216, 7, 5, "Big-tongues here worship shrine,, like at other places,, but this shrine sometimes have a guardian. Careful if it shows up.", 12, 0, 100, 0, 0, 0, 28248, 0, "Zepik"),
(28216, 7, 6, "Feels good to hunt with a not dumb hunter. You good at this.", 12, 0, 100, 0, 0, 0, 28249, 0, "Zepik"),
(28216, 7, 7, "Maybe I not be the only one big-tongues fear much longer. You scary when in the fight.", 12, 0, 100, 0, 0, 0, 28250, 0, "Zepik"),
-- Fortunate Misunderstandings quest ?
(28216, 8, 0, "Gorlocs are the bad-guys, just so you know.", 12, 0, 100, 0, 0, 0, 28207, 0, "Zepik"),
(28216, 8, 1, "I hope you planning something secret involving that big-tongue ending up dead.", 12, 0, 100, 0, 0, 0, 28208, 0, "Zepik"),
(28216, 8, 2, "If I step on its tail,, it was an accident.", 12, 0, 100, 0, 0, 0, 28209, 0, "Zepik"),
(28216, 8, 3, "Normally I kill these things. You know that,, yeah?", 12, 0, 100, 0, 0, 0, 28210, 0, "Zepik"),
(28216, 8, 4, "I not so happy about traveling with big-tongues.", 12, 0, 100, 0, 0, 0, 28211, 0, "Zepik"),
(28216, 8, 5, "I see what you doing... maybe if we treat it nice it will lead us back to more big-tongues.", 12, 0, 100, 0, 0, 0, 28212, 0, "Zepik"),
-- Kartak hold
(28216, 9, 0, "Good to stay away from Kartak. He only a friend of Frenzyheart so long as we keep his belly full... and he's got a big belly.", 12, 0, 100, 0, 0, 0, 28213, 0, "Zepik"),
(28216, 9, 1, "I teach myself a lot of my big-tongue hunt here. Lot to kill.", 12, 0, 100, 0, 0, 0, 28214, 0, "Zepik"),
(28216, 9, 2, "Something about sound of battle make this place more relaxing than main hill.", 12, 0, 100, 0, 0, 0, 28215, 0, "Zepik"),
(28216, 9, 3, "Not mentioned much,, but Kartak ate dozen Frenzyheart before became 'friend.'", 12, 0, 100, 0, 0, 0, 28216, 0, "Zepik"),
(28216, 9, 5, "Ever met Tartek? He one of our best fighters... leads in the northwest. I hear he captured one of the dragon things. No lie,, I a little jealous.", 12, 0, 100, 0, 0, 0, 28217, 0, "Zepik"),
(28216, 9, 6, "Shaman Jakjek is quiet for a Frenzyheart,, but still very strong. He probably the only reason Kartak not turned on more of us.", 12, 0, 100, 0, 0, 0, 28218, 0, "Zepik");
