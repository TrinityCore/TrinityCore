SET @EventEntry :=    34;
SET @CGuid :=    127312;

-- Add game events to gameevent table (one per month so different brew vendor spawns each month which sells a different brew

DELETE FROM `game_event` WHERE `eventEntry` BETWEEN @EventEntry AND @EventEntry+11;

INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`, `announce`) VALUES
(@EventEntry, '2012-10-01 00:01:00', '2020-12-31 06:00:00', 525600, 44640, 0, 'Brew of the Month October', 0, 2),
(@EventEntry+1, '2012-11-01 00:01:00', '2020-12-31 06:00:00', 525600, 43200, 0, 'Brew of the Month November', 0, 2),
(@EventEntry+2, '2012-12-01 00:01:00', '2020-12-31 06:00:00', 525600, 44640, 0, 'Brew of the Month December', 0, 2),
(@EventEntry+3, '2012-01-01 00:01:00', '2020-12-31 06:00:00', 525600, 44640, 0, 'Brew of the Month January', 0, 2),
(@EventEntry+4, '2012-02-01 00:01:00', '2020-12-31 06:00:00', 525600, 40320, 0, 'Brew of the Month February', 0, 2),
(@EventEntry+5, '2012-03-01 00:01:00', '2020-12-31 06:00:00', 525600, 44640, 0, 'Brew of the Month March', 0, 2),
(@EventEntry+6, '2012-04-01 00:01:00', '2020-12-31 06:00:00', 525600, 43200, 0, 'Brew of the Month April', 0, 2),
(@EventEntry+7, '2012-05-01 00:01:00', '2020-12-31 06:00:00', 525600, 44640, 0, 'Brew of the Month May', 0, 2),
(@EventEntry+8, '2012-06-01 00:01:00', '2020-12-31 06:00:00', 525600, 43200, 0, 'Brew of the Month June', 0, 2),
(@EventEntry+9, '2012-07-01 00:01:00', '2020-12-31 06:00:00', 525600, 44640, 0, 'Brew of the Month July', 0, 2),
(@EventEntry+10, '2012-08-01 00:01:00', '2020-12-31 06:00:00', 525600, 44640, 0, 'Brew of the Month August', 0, 2),
(@EventEntry+11, '2012-09-01 00:01:00', '2020-12-31 06:00:00', 525600, 44640, 0, 'Brew of the Month September', 0, 2);

UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=129,`gossip_menu_id`=9549 WHERE  `entry` IN(27806,27810,27811,27812,27813,27814,27815,27816,27817,27818,27819,27820);

-- Add brewfest brews to vendors some of these are already in db but all are here just in case)

DELETE FROM `npc_vendor` WHERE `entry` IN (27806,27810,27811,27812,27813,27814,27815,27816,27817,27818,27819,27820);

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
(27806, 0, 37488, 0, 0, 0), -- Wild Winter Pilsner (January)
(27810, 0, 37899, 0, 0, 0), -- Izzard's Ever Flavor (February)
(27811, 0, 37490, 0, 0, 0), -- Aromatic Honey Brew (March)
(27812, 0, 37491, 0, 0, 0), -- Metok's Bubble Bock (April)
(27813, 0, 37492, 0, 0, 0), -- Springtime Stout (May)
(27814, 0, 37493, 0, 0, 0), -- Blackrock Lager (June)
(27815, 0, 37494, 0, 0, 0), -- Stranglethorn Brew (July)
(27816, 0, 37495, 0, 0, 0), -- Draenic Pale Ale  (August)
(27817, 0, 37496, 0, 0, 0), -- Binary Brew (September)
(27818, 0, 37497, 0, 0, 0), -- Autumnal Acorn Ale (October)
(27819, 0, 37498, 0, 0, 0), -- Bartlett's Bitter Brew (November)
(27820, 0, 37499, 0, 0, 0); -- Lord of Frost's Private Label (December)

-- Set buycount to 6 and make duration of these items so the duration is in realtime and not game time
UPDATE `item_template` SET `BuyCount`=6, `flagsCustom`=1 WHERE  `entry` IN(37488,37899,37490,37491,37492,37493,37494,37495,37496,37497,37498,37499,37496);

-- Link brew vendors to monthly events
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGuid AND @CGuid+23;

INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EventEntry+3, @CGuid),
(@EventEntry+3, @CGuid+1),
(@EventEntry+4, @CGuid+2),
(@EventEntry+4, @CGuid+3),
(@EventEntry+5, @CGuid+4),
(@EventEntry+5, @CGuid+5),
(@EventEntry+6, @CGuid+6),
(@EventEntry+6, @CGuid+7),
(@EventEntry+7, @CGuid+8),
(@EventEntry+7, @CGuid+9),
(@EventEntry+8, @CGuid+10),
(@EventEntry+8, @CGuid+11),
(@EventEntry+9, @CGuid+12),
(@EventEntry+9, @CGuid+13),
(@EventEntry+10, @CGuid+14),
(@EventEntry+10, @CGuid+15),
(@EventEntry+11, @CGuid+16),
(@EventEntry+11, @CGuid+17),
(@EventEntry, @CGuid+18),
(@EventEntry, @CGuid+19),
(@EventEntry+1, @CGuid+20),
(@EventEntry+1, @CGuid+21),
(@EventEntry+2, @CGuid+22),
(@EventEntry+2, @CGuid+23);


-- Add some missing gossips and conditions for these which are needed so only players who completed brew of the month quest can access vendors
UPDATE `gossip_menu_option` SET `npc_option_npcflag`=128,`option_id`=3 WHERE  `menu_id`=9554 AND `id`=0;

DELETE FROM `gossip_menu_option` WHERE  `menu_id`=9548;

INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9548, 0, 0, 'What do you have for me?', 26695, 3, 128, 0, 0, 0, 0, '', 0);


DELETE FROM `gossip_menu_option` WHERE  `menu_id`=9549;

INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9549, 0, 1, 'I''d like to buy this month''s brew.', 26693, 3, 128, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`IN(9549,9548);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9548, 0, 0, 0, 2, 0, 37829, 1, 0, 0, 0, 0, '', 'Only show gossip menu if player has at least 1 brewfest prize token'),

(15, 9549, 0, 0, 0, 8, 0, 12421, 0, 0, 0, 0, 0, '', 'Only allow players who have completed brew of the month quest to access vendor'),
(15, 9549, 0, 0, 2, 8, 0, 12420, 0, 0, 0, 0, 0, '', 'Only allow players who have completed brew of the month quest to access vendor');

DELETE FROM `creature` WHERE `id` IN (27806,27810,27811,27812,27813,27814,27815,27816,27817,27818,27819,27820);

INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@CGuid, 27806, 0, 1, 1, 24979, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+1, 27806, 1, 1, 1, 24979, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+2, 27810, 0, 1, 1, 24980, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+3, 27810, 1, 1, 1, 24980, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+4, 27811, 0, 1, 1, 24981, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+5, 27811, 1, 1, 1, 24981, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+6, 27812, 0, 1, 1, 24982, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+7, 27812, 1, 1, 1, 24982, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+8, 27813, 0, 1, 1, 24983, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+9, 27813, 1, 1, 1, 24983, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+10, 27814, 0, 1, 1, 24984, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+11, 27814, 1, 1, 1, 24984, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+12, 27815, 0, 1, 1, 24985, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+13, 27815, 1, 1, 1, 24985, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+14, 27816, 0, 1, 1, 24986, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+15, 27816, 1, 1, 1, 24986, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+16, 27817, 0, 1, 1, 24987, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+17, 27817, 1, 1, 1, 24987, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+18, 27818, 0, 1, 1, 24988, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+19, 27818, 1, 1, 1, 24988, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+20, 27819, 0, 1, 1, 24989, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+21, 27819, 1, 1, 1, 24989, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+22, 27820, 0, 1, 1, 24990, 1, -4845.949, -861.9443, 501.9972, 4.485496, 120, 0, 0, 2215, 0, 0, 0, 0, 0),
(@CGuid+23, 27820, 1, 1, 1, 24990, 1, 1475.8, -4210.233, 43.2693, 4.014257, 120, 0, 0, 2215, 0, 0, 0, 0, 0);

-- Spawn Larkin Thunderbrew <Brew of the Month Club> who is needed so alliance can turn quest to unlock vendors
DELETE FROM `creature` WHERE `guid`=@CGuid+24;

INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@CGuid+24, 27478, 0, 1, 1, 22396, 0, -4849.41, -862.255, 501.997, 4.85202, 300, 0, 0, 2215, 0, 0, 0, 0, 0);

-- Smart scripts to dynamically change faction on brew vendors depending on location
-- 774 = Alliance only alliance can access vendor, vendor still appears neutral to horde but wont allow interaction
-- 775 = Horde only horde can access vendor, vendor still appears neutral to alliance but wont allow interaction


UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (27806,27810,27811,27812,27813,27814,27815,27816,27817,27818,27819,27820);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27806,27810,27811,27812,27813,27814,27815,27816,27817,27818,27819,27820);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27806, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27806, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27806, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27806, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27810, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27810, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27810, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27810, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27811, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27811, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27811, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27811, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27812, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27812, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27812, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27812, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27813, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27813, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27813, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27813, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27814, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27814, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27814, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27814, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27815, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27815, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27815, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27815, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27816, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27816, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27816, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27816, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27817, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27817, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27817, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27817, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27818, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27818, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27818, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27818, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27819, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27819, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27819, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27819, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde'),
(27820, 0, 0, 2, 11,  0, 100, 0, 0, 0, 0, 0, 2, 774   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Alliance)'),
(27820, 0, 1, 3, 11,  0, 100, 0, 0, 0, 0, 0, 2, 775   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Set Faction (Horde)'),
(27820, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49672   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Alliance'),
(27820, 0, 3, 0, 61,  0, 100, 0, 0, 0, 0, 0, 11, 49673   , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brew Vendor - On Spawn - Cast BOTM - Vendor - Transform - Horde');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (27806,27810,27811,27812,27813,27814,27815,27816,27817,27818,27819,27820);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,27806,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27806,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27810,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27810,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27811,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27811,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27812,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27812,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27813,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27813,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27814,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27814,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27815,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27815,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27816,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27816,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27817,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27817,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27818,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27818,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27819,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27819,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar'),
(22,1,27820,0,0,23,1,1537,0,0,0,0,'','Only Run AI in Ironforge'),
(22,2,27820,0,0,23,1,1637,0,0,0,0,'','Only Run AI in Ogrimmar');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN(42256,42255,42254,43961,42263,42257,43959,42264,42259,42260,42258,42261);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(42256, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(42255, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(42254, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(43961, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(42263, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(42257, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(43959, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(42264, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(42259, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(42260, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(42258, 51655, 0, 'BOTM - Create Empty Brew Bottle'),
(42261, 51655, 0, 'BOTM - Create Empty Brew Bottle');
