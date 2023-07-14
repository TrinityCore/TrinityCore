-- Playercreateinfo data
DELETE FROM `playercreateinfo` WHERE (`class`=9 AND `race` IN (24,31,36,28,6,32,11,4,30,26,25));
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(24, 9, 860, 1466.0899658203125, 3465.97998046875, 181.8600006103515625, 2.87962), -- Pandaren Neutral
(31, 9, 1642, -1127.300048828125, 805.42999267578125, 500.22900390625, 3.184), -- Zandalari Troll
(36, 9, 1, 1968.949951171875, -4742.919921875, 37.19570159912109375, 1.22251), -- Maghar Orc
(28, 9, 1220, 4079.050048828125, 4392.3798828125, 670.60302734375, 5.18155), -- Highmountain Tauren
(6, 9, 1, -2915.550048828125, -257.34698486328125, 59.26929855346679687, 0.302378), -- Tauren
(32, 9, 1643, 1072.030029296875, -484.800994873046875, 9.700130462646484375, 1.34485), -- Kultiran
(11, 9, 530, -3961.639892578125, -13931.2001953125, 100.6149978637695312, 2.08364), -- Draenei
(4, 9, 1, 10311.2998046875, 831.4630126953125, 1326.5699462890625, 5.48033), -- Nightelf
(30, 9, 1860, 458.822998046875, 1449.6099853515625, 757.572998046875, 0.466425), -- Lightforged Draenei
(26, 9, 2175, -10.729100227355957, -7.14634990692138671, 8.731129646301269531, 0.67), -- Pandaren Horde
(25, 9, 2175, 11.13010025024414062, -0.41718199849128723, 5.187409877777099609, 0.67); -- Pandaren Alliance

-- NPE spawn data
UPDATE `playercreateinfo` SET `npe_map` = 2175, `npe_position_x` = 11.1301, `npe_position_y` = -0.417182, `npe_position_z` = 5.18741, `npe_orientation` = 3.14843, `npe_transport_guid` = 29, `npe_intro_scene_id` = 2236 WHERE (`race` IN (11, 4, 25) AND `class` = 9);
UPDATE `playercreateinfo` SET `npe_map` = 2175, `npe_position_x` = -10.7291, `npe_position_y` = -7.14635, `npe_position_z` = 8.73113, `npe_orientation` = 1.56321, `npe_transport_guid` = 30, `npe_intro_scene_id` = 2486 WHERE (`race` IN (6, 26) AND `class` = 9);

-- Actionbutton data
DELETE FROM `playercreateinfo_action` WHERE (`race`=24 AND `class`=9 AND `button`=9) OR (`race`=24 AND `class`=9 AND `button`=0) OR (`race`=31 AND `class`=9 AND `button`=11) OR (`race`=31 AND `class`=9 AND `button`=10) OR (`race`=31 AND `class`=9 AND `button`=7) OR (`race`=31 AND `class`=9 AND `button`=6) OR (`race`=31 AND `class`=9 AND `button`=5) OR (`race`=31 AND `class`=9 AND `button`=4) OR (`race`=31 AND `class`=9 AND `button`=3) OR (`race`=31 AND `class`=9 AND `button`=2) OR (`race`=31 AND `class`=9 AND `button`=1) OR (`race`=31 AND `class`=9 AND `button`=0) OR (`race`=36 AND `class`=9 AND `button`=11) OR (`race`=36 AND `class`=9 AND `button`=10) OR (`race`=36 AND `class`=9 AND `button`=7) OR (`race`=36 AND `class`=9 AND `button`=6) OR (`race`=36 AND `class`=9 AND `button`=5) OR (`race`=36 AND `class`=9 AND `button`=4) OR (`race`=36 AND `class`=9 AND `button`=3) OR (`race`=36 AND `class`=9 AND `button`=2) OR (`race`=36 AND `class`=9 AND `button`=1) OR (`race`=36 AND `class`=9 AND `button`=0) OR (`race`=28 AND `class`=9 AND `button`=11) OR (`race`=28 AND `class`=9 AND `button`=10) OR (`race`=28 AND `class`=9 AND `button`=7) OR (`race`=28 AND `class`=9 AND `button`=6) OR (`race`=28 AND `class`=9 AND `button`=5) OR (`race`=28 AND `class`=9 AND `button`=4) OR (`race`=28 AND `class`=9 AND `button`=3) OR (`race`=28 AND `class`=9 AND `button`=2) OR (`race`=28 AND `class`=9 AND `button`=1) OR (`race`=28 AND `class`=9 AND `button`=0) OR (`race`=6 AND `class`=9 AND `button`=9) OR (`race`=6 AND `class`=9 AND `button`=0) OR (`race`=32 AND `class`=9 AND `button`=11) OR (`race`=32 AND `class`=9 AND `button`=10) OR (`race`=32 AND `class`=9 AND `button`=7) OR (`race`=32 AND `class`=9 AND `button`=6) OR (`race`=32 AND `class`=9 AND `button`=5) OR (`race`=32 AND `class`=9 AND `button`=4) OR (`race`=32 AND `class`=9 AND `button`=3) OR (`race`=32 AND `class`=9 AND `button`=2) OR (`race`=32 AND `class`=9 AND `button`=1) OR (`race`=32 AND `class`=9 AND `button`=0) OR (`race`=11 AND `class`=9 AND `button`=9) OR (`race`=11 AND `class`=9 AND `button`=0) OR (`race`=4 AND `class`=9 AND `button`=9) OR (`race`=4 AND `class`=9 AND `button`=0) OR (`race`=30 AND `class`=9 AND `button`=11) OR (`race`=30 AND `class`=9 AND `button`=10) OR (`race`=30 AND `class`=9 AND `button`=7) OR (`race`=30 AND `class`=9 AND `button`=6) OR (`race`=30 AND `class`=9 AND `button`=5) OR (`race`=30 AND `class`=9 AND `button`=4) OR (`race`=30 AND `class`=9 AND `button`=3) OR (`race`=30 AND `class`=9 AND `button`=2) OR (`race`=30 AND `class`=9 AND `button`=1) OR (`race`=30 AND `class`=9 AND `button`=0) OR (`race`=26 AND `class`=9 AND `button`=9) OR (`race`=26 AND `class`=9 AND `button`=0) OR (`race`=25 AND `class`=9 AND `button`=9) OR (`race`=25 AND `class`=9 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(24, 9, 9, 107079, 0), -- Quaking Palm
(24, 9, 0, 686, 0), -- Shadow Bolt
(31, 9, 11, 263707, 0), -- Zandalari Direhorn
(31, 9, 10, 292752, 0), -- Embrace of the Loa
(31, 9, 7, 6201, 0), -- Create Healthstone
(31, 9, 6, 755, 0), -- Health Funnel
(31, 9, 5, 5782, 0), -- Fear
(31, 9, 4, 104773, 0), -- Unending Resolve
(31, 9, 3, 702, 0), -- Curse of Weakness
(31, 9, 2, 234153, 0), -- Drain Life
(31, 9, 1, 686, 0), -- Shadow Bolt
(31, 9, 0, 172, 0), -- Corruption
(36, 9, 11, 267274, 0), -- Mag'har Direwolf
(36, 9, 10, 274738, 0), -- Ancestral Call
(36, 9, 7, 6201, 0), -- Create Healthstone
(36, 9, 6, 755, 0), -- Health Funnel
(36, 9, 5, 5782, 0), -- Fear
(36, 9, 4, 104773, 0), -- Unending Resolve
(36, 9, 3, 702, 0), -- Curse of Weakness
(36, 9, 2, 234153, 0), -- Drain Life
(36, 9, 1, 686, 0), -- Shadow Bolt
(36, 9, 0, 172, 0), -- Corruption
(28, 9, 11, 258060, 0), -- Highmountain Thunderhoof
(28, 9, 10, 255654, 0), -- Bull Rush
(28, 9, 7, 6201, 0), -- Create Healthstone
(28, 9, 6, 755, 0), -- Health Funnel
(28, 9, 5, 5782, 0), -- Fear
(28, 9, 4, 104773, 0), -- Unending Resolve
(28, 9, 3, 702, 0), -- Curse of Weakness
(28, 9, 2, 234153, 0), -- Drain Life
(28, 9, 1, 686, 0), -- Shadow Bolt
(28, 9, 0, 172, 0), -- Corruption
(6, 9, 9, 20549, 0), -- War Stomp
(6, 9, 0, 686, 0), -- Shadow Bolt
(32, 9, 11, 282682, 0), -- Kul Tiran Charger
(32, 9, 10, 287712, 0), -- Haymaker
(32, 9, 7, 6201, 0), -- Create Healthstone
(32, 9, 6, 755, 0), -- Health Funnel
(32, 9, 5, 5782, 0), -- Fear
(32, 9, 4, 104773, 0), -- Unending Resolve
(32, 9, 3, 702, 0), -- Curse of Weakness
(32, 9, 2, 234153, 0), -- Drain Life
(32, 9, 1, 686, 0), -- Shadow Bolt
(32, 9, 0, 172, 0), -- Corruption
(11, 9, 9, 416250, 0), -- -Unknown-
(11, 9, 0, 686, 0), -- Shadow Bolt
(4, 9, 9, 58984, 0), -- Shadowmeld
(4, 9, 0, 686, 0), -- Shadow Bolt
(30, 9, 11, 258022, 0), -- Lightforged Felcrusher
(30, 9, 10, 255647, 0), -- Light's Judgment
(30, 9, 7, 6201, 0), -- Create Healthstone
(30, 9, 6, 755, 0), -- Health Funnel
(30, 9, 5, 5782, 0), -- Fear
(30, 9, 4, 104773, 0), -- Unending Resolve
(30, 9, 3, 702, 0), -- Curse of Weakness
(30, 9, 2, 234153, 0), -- Drain Life
(30, 9, 1, 686, 0), -- Shadow Bolt
(30, 9, 0, 172, 0), -- Corruption
(26, 9, 9, 107079, 0), -- Quaking Palm
(26, 9, 0, 686, 0), -- Shadow Bolt
(25, 9, 9, 107079, 0), -- Quaking Palm
(25, 9, 0, 686, 0); -- Shadow Bolt
