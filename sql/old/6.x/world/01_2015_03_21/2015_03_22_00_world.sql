DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21181,21310,17008,21052,21685,21686,21687,21738,21739,21740,21741,21049) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2118100,2131000,2102401) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` =21024 AND `source_type`=0 AND `id`>1;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE entry IN (21181, 17008, 21052, 21685, 21686, 21687, 21310,21738,21739,21740,21741,21049);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21049, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit of the Past - On spawn - set Phase 1'),
(21049, 0, 1, 0, 1, 1, 100, 0, 0, 180000, 90000, 180000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit of the Past - OOC (Phase 1) - Say Line 0'),
(21049, 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit of the Past - On Data Set 1 1 - set Phase 2'),
(21049, 0, 3, 0, 1, 2, 100, 0, 300000, 300000, 300000, 300000, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit of the Past - OOC (Phase 2) - Set Phase 1'),
(21738, 0, 0, 0, 1, 0, 100, 1, 100, 100, 0, 0, 11, 25035, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redeemed Spirit of Air - OOC (No Repeat) - Cast Elemental Spawn-in'),
(21739, 0, 0, 0, 1, 0, 100, 1, 100, 100, 0, 0, 11, 25035, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redeemed Spirit of Earth - OOC (No Repeat) - Cast Elemental Spawn-in'),
(21740, 0, 0, 0, 1, 0, 100, 1, 100, 100, 0, 0, 11, 25035, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redeemed Spirit of Fire  - OOC (No Repeat) - Cast Elemental Spawn-in'),
(21741, 0, 0, 0, 1, 0, 100, 1, 100, 100, 0, 0, 11, 25035, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redeemed Spirit of Water - OOC (No Repeat) - Cast Elemental Spawn-in'),
(21024, 0, 2, 0, 38, 1, 100, 0, 1, 1, 0, 0, 80, 2102401, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - On Data Set 1 1 - Run Script 2'),
(21181, 0, 0 ,0, 9,  0, 100, 0, 0,20,10000,15000,11,18945,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Range - Cast Knock-Away'),
(21181, 0, 1 ,0, 0,  0, 100, 0, 3000,5000,5000,11000,11,39429,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - IC - Cast Fel Flamestrike'),
(21181, 0, 2 ,0, 9,  0, 100, 0, 0,20,8000,13000,11,39425,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Range - Cast Trample'),
(21181, 0, 3 ,0, 11,  0, 100, 0, 0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Spawn - Set Unit Flags'),
(21181, 0, 4 ,0, 38,  0, 100, 0, 1,1,0,0,53,0,21181,0,0,0,0,1,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Data Set 1 1 - Start WP'),
(21181, 0, 5 ,6, 40,  0, 100, 0, 1,21181,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Set Home Position'),
(21181, 0, 6 ,7, 61,  0, 100, 0, 0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Set Unit Flags'),
(21181, 0, 7 ,8, 61,  0, 100, 0, 0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Set Aggresive'),
(21181, 0, 8 ,9, 61,  0, 100, 0, 0,0,0,0,49,0,0,0,0,0,0,19,21685,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Start Attack'),
(21181, 0, 9 ,10, 61,  0, 100, 0, 0,0,0,0,45,2,2,0,0,0,0,19,21686,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Start Attack'),
(21181, 0, 10 ,0, 61,  0, 100, 0, 0,0,0,0,45,2,2,0,0,0,0,19,21687,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Reached WP1 - Start Attack'),
(21181, 0, 11 ,0, 1,  0, 100, 0, 0,0,15000,30000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - IC - Say'),
(21181, 0, 12 ,0, 6,  0, 100, 0, 0,0,0,0,45,1,1,0,0,0,0,19,21024,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Death - Set Data'),
(21181, 0, 13 ,0, 54,  0, 100, 0, 0,0,0,0,11,36329,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cyrukh the Firelord <The Dirge of Karabor> - On Just SUmmoned - Cast Cyrukh Fire Kit'),
(17008, 0, 0 ,0, 38,  0, 100, 0, 1,1,0,0,11,35996,0,0,0,0,0,1,0,0,0,0,0,0,0,'Guldan - On Data Set 1 1 - Cast Guldan Channel'),
(17008, 0, 1 ,0, 38,  0, 100, 0, 2,2,0,0,28,35996,0,0,0,0,0,1,0,0,0,0,0,0,0,'Guldan - On Data Set 2 2 - Remove Aura Guldan Channel'),
(17008, 0, 2 ,0, 38,  0, 100, 0, 3,3,0,0,66,0,0,0,0,0,0,19,21049,0,0,0,0,0,0,'Guldan - On Data Set 3 3 - Set Orientation'),
(17008, 0, 3 ,0, 38,  0, 100, 0, 4,4,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.95674,'Guldan - On Data Set 3 3 - Set Orientation'),
(21052, 0, 0 ,0, 1,  2, 100, 0, 0,0,500,1000,11,35997,0,0,0,0,0,1,0,0,0,0,0,0,0,'Camera Shaker - Altar of Damnation - OOC (Phase 2) - Cast Fel Flames'),
(21052, 0, 1 ,0, 1,  2, 100, 0, 30000,30000,30000,30000,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Camera Shaker - Altar of Damnation - OOC (Phase 2) - Set Phase 1'),
(21052, 0, 2 ,0, 1,  2, 100, 0, 0,1000,1000,3000,11,35757,0,0,0,0,0,1,0,0,0,0,0,0,0,'Camera Shaker - Altar of Damnation - OOC (Phase 2) - Cast Ultris Destroyed'),
(21052, 0, 3 ,0, 38,  0, 100, 0, 1,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Camera Shaker - Altar of Damnation -On Data Set 1 1 - Set Phase 2'),
(21685, 0, 0 ,0, 38,  0, 100, 0, 1,1,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Data Set 1 1 - Set NPC Flags Gossip'),
(21685, 0, 1 ,2, 62,  0, 100, 0, 8350,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Oronok Torn-heart - On Gossip Select - Store Targetlist'),
(21685, 0, 2 ,3, 61,  0, 100, 0, 0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Gossip Select - Set NPC Flags None'),
(21685, 0, 3 ,4, 61,  0, 100, 0, 0,0,0,0,45,1,1,0,0,0,0,19,21686,0,0,0,0,0,0,'Oronok Torn-heart - On Gossip Select - Set Data'),
(21685, 0, 4 ,5, 61,  0, 100, 0, 0,0,0,0,45,1,1,0,0,0,0,19,21687,0,0,0,0,0,0,'Oronok Torn-heart - On Gossip Select - Set Data'),
(21685, 0, 5 ,0, 61,  0, 100, 0, 0,0,0,0,53,0,21685,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Gossip Select - Start WP'),
(21685, 0, 6 ,7, 40,  0, 100, 0, 12,21685,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Reached WP12 - Set Home Position'),
(21685, 0, 7 ,8, 61,  0, 100, 0, 0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Reached WP12 - Set Unit Flags'),
(21685, 0, 8 ,9, 61,  0, 100, 0, 0,0,0,0,2,495,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Reached WP12 - Set Faction'),
(21685, 0, 9 ,10, 61,  0, 100, 0, 0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Reached WP12 - Set Aggresive'),
(21685, 0, 10 ,0, 61,  0, 100, 0, 0,0,0,0,45,1,1,0,0,0,0,19,21181,0,0,0,0,0,0,'Oronok Torn-heart - On Reached WP12 - Set Data on Cyrukh the Firelord <The Dirge of Karabor>'),
(21685, 0, 11 ,0, 0,  0, 100, 0, 0,0,8000,11000,11,16006,0,0,0,0,0,2,0,0,0,0,0,0,0,'Oronok Torn-heart - IC - Cast Chain Lightning'),
(21685, 0, 12 ,0, 0,  0, 100, 0, 0,0,6000,8000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,'Oronok Torn-heart - IC - Cast Frost Shock'),
(21685, 0, 13 ,0, 2,  0, 100, 0, 0,40,5000,8000,11,12491,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Less than 40% HP - Cast Healing Wave'),
(21685, 0, 14 ,0, 38,  0, 100, 0, 5,5,0,0,11,12491,0,0,0,0,0,19,21687,0,0,0,0,0,0,'Oronok Torn-heart - On Data Set - Cast Healing Wave'),
(21685, 0, 15 ,16, 38,  0, 100, 0, 6,6,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Data Set 6 6 - Unequip weapon'),
(21685, 0, 16 ,0, 61,  0, 100, 0, 0,0,0,0,15,10588,0,0,0,0,0,12,1,0,0,0,0,0,0,'Oronok Torn-heart - On Data Set 6 6 - Complete Quest - The Cipher of Damnation'),
(21685, 0, 17 ,0, 7,  0, 100, 0, 0,0,0,0,53,0,2168500,0,0,0,0,1,0,0,0,0,0,0,0,'Oronok Torn-heart - On Evade - Start WP (Path 2)'),
(21685, 0, 18 ,0, 40,  0, 100, 0, 1,2168500,0,0,66,0,0,0,0,0,0,19,21024,0,0,0,0,0,0,'Oronok Torn-heart - On Reached WP1 (Path 2) - Set Orientation'),
(21686, 0, 0 ,0, 38,  0, 100, 0, 1,1,0,0,53,0,21686,0,0,0,0,1,0,0,0,0,0,0,0,'Borak, Son of Oronok - On Data Set - Start WP'),
(21686, 0, 1 ,2, 40,  0, 100, 0, 18,21686,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Borak, Son of Oronok - On Reached WP18 - Set Home Position'),
(21686, 0, 2 ,3, 61,  0, 100, 0, 0,0,0,0,2,495,0,0,0,0,0,1,0,0,0,0,0,0,0,'Borak, Son of Oronok - On Reached WP18 - Set Faction'),
(21686, 0, 3 ,4, 61,  0, 100, 0, 0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Borak, Son of Oronok - On Reached WP18 - Set Unit Flags'),
(21686, 0, 4 ,0, 61,  0, 100, 0, 0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Borak, Son of Oronok - On Reached WP18 - Set Aggresive'),
(21686, 0, 5 ,0, 38,  0, 100, 0, 2,2,0,0,49,0,0,0,0,0,0,19,21181,0,0,0,0,0,0,'Borak, Son of Oronok - On Data Set - Start Attack'),
(21686, 0, 6 ,0, 9,  0, 100, 0, 0,5,3000,6000,11,27611,0,0,0,0,0,1,0,0,0,0,0,0,0,'Borak, Son of Oronok - On Range - Cast Eviscerate'),
(21686, 0, 7 ,0, 9,  0, 100, 0, 0,5,15000,18000,11,30470,0,0,0,0,0,1,0,0,0,0,0,0,0,'Borak, Son of Oronok - On Range - Cast Slice and Dice'),
(21686, 0, 8 ,0, 38,  0, 100, 0, 3,3,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Borak, Son of Oronok - On Data Set 3 3 - Unequip weapon'),
(21686, 0, 9 ,0, 7,  0, 100, 0, 0,0,0,0,53,0,2168600,0,0,0,0,1,0,0,0,0,0,0,0,'Borak, Son of Oronok - On Evade - Start WP (Path 2)'),
(21686, 0, 10 ,0, 40,  0, 100, 0, 1,2168600,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.660839,'Borak, Son of Oronok - On Reached WP1 (Path 2) - Set Orientation'),
(21687, 0, 0 ,0, 38,  0, 100, 0, 1,1,0,0,53,0,21687,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Data Set - Start WP'),
(21687, 0, 1 ,2, 40,  0, 100, 0, 17,21687,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Reached WP17 - Set Home Position'),
(21687, 0, 2 ,3, 61,  0, 100, 0, 0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Reached WP17 - Set Unit Flags'),
(21687, 0, 3 ,4, 61,  0, 100, 0, 0,0,0,0,2,495,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Reached WP17 - Set Faction'),
(21687, 0, 4 ,0, 61,  0, 100, 0, 0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Reached WP17 - Set Aggresive'),
(21687, 0, 5 ,0, 38,  0, 100, 0, 2,2,0,0,49,0,0,0,0,0,0,19,21181,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Data Set - Start Attack'),
(21687, 0, 6 ,0, 4,  0, 100, 0, 0,0,0,0,11,31403,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Agro - Cast Battle Shout'),
(21687, 0, 7 ,0, 9,  0, 100, 0, 0,5,3000,7000,11,29426,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Range - Cast Heroic Strike'),
(21687, 0, 8 ,0, 9,  0, 100, 0, 0,5,8000,13000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Range - Cast Shield Block'),
(21687, 0, 9 ,0, 9,  0, 100, 0, 0,5,18000,23000,11,15062,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Range - Cast Shield Wall'),
(21687, 0, 10 ,0, 0,  0, 100, 0, 0,5000,5000,8000,11,26281,0,0,0,0,0,2,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - IC - Cast Taunt'),
(21687, 0, 11 ,0, 2,  0, 100, 0, 0,40,5000,8000,45,4,4,0,0,0,0,19,21685,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Less than 40% HP - Set Data Oronok Torn-heart'),
(21687, 0, 12 ,0, 38,  0, 100, 0, 3,3,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Data Set 3 3 - Unequip weapon'),
(21687, 0, 13 ,0, 7,  0, 100, 0, 0,0,0,0,53,0,2168700,0,0,0,0,1,0,0,0,0,0,0,0,'Gromtor, Son of Oronok - On Evade - Start WP (Path 2)'),
(21687, 0, 14 ,0, 40,  0, 100, 0, 1,2168700,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.503118,'Gromtor, Son of Oronok - On Reached WP1 (Path 2) - Set Orientation'),
(21310, 0, 3 ,0, 54,  0, 100, 0, 0,0,0,0,80,2131000,2,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - On Spawn - Run Script'),
(2102401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Set Phase 2'), 
(2102401, 9, 1, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 21685, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 6 (Oronok Torn-heart)'), -- 18:45:48.094
(2102401, 9, 2, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 11'), -- 18:46:05.594
(2102401, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Summon Group 2'), -- 18:46:08.938
(2102401, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 21685, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 7 (Oronok Torn-heart)'), -- 18:46:13.844
(2102401, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 21739, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 1 (Redeemed Spirit of Earth)'), -- 18:46:18.938
(2102401, 9, 6, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21740, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 0 (Redeemed Spirit of Fire)'), -- 18:46:27.953
(2102401, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 8'), -- 18:46:34.235
(2102401, 9, 8, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21739, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 0 (Redeemed Spirit of Earth)'), -- 18:46:38.813
(2102401, 9, 9, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 21685, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 1 (Oronok Torn-heart)'), -- 18:46:42.844
(2102401, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 21685, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 2 (Oronok Torn-heart)'), -- 18:46:42.844
(2102401, 9, 11, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 21685, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Say Line 3 (Oronok Torn-heart)'), -- 18:46:48.860
(2102401, 9, 12, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 6, 6, 0, 0, 0, 0, 19, 21685, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Set Data 6 6 Oronok Torn-heart'), -- 18:46:48.860
(2102401, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 21686, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Set Data 3 3 Borak, Son of Oronok'), -- 18:46:48.860
(2102401, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 21687, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Set Data 3 3 Gromtor, Son of Oronok'), -- 18:46:48.860
(2102401, 9, 15, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 21685, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Despawn '), -- 18:46:48.860
(2102401, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 21686, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Despawn'), -- 18:46:48.860
(2102401, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 21687, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Despawn'), -- 18:46:48.860
(2102401, 9, 18, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script 2 - Set Phase 1'), 
(2131000, 9, 1 ,0, 0,  0, 100, 0, 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 1'),
(2131000, 9, 2 ,0, 0,  0, 100, 0, 0,0,0,0,45,3,3,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Set Data 3 3 on Gul''Dan'),
(2131000, 9, 3 ,0, 0,  0, 100, 0, 3000,3000,0,0,1,0,0,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 1 on Gul''Dan'),
(2131000, 9, 4 ,0, 0,  0, 100, 0, 0,0,0,0,45,1,1,0,0,0,0,9,21049,0,200,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Set Data 1 1 on Spirit of the Past'),
(2131000, 9, 5 ,0, 0,  0, 100, 0, 6000,6000,0,0,45,4,4,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Set Data 4 4 on Gul''Dan'),
(2131000, 9, 6 ,0, 0,  0, 100, 0, 1000,1000,0,0,45,1,1,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Set Data 1 1 on Gul''Dan'),
(2131000, 9, 7 ,0, 0,  0, 100, 0, 0,0,0,0,1,1,0,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 2 on Gul''Dan'),
(2131000, 9, 8 ,0, 0,  0, 100, 0, 0,0,0,0,45,1,1,0,0,0,0,9,21052,0,200,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Set Data 1 1 on Camera Shaker - Altar of Damnation'),
(2131000, 9, 9 ,0, 0,  0, 100, 0, 3000,3000,0,0,1,2,0,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 3 on Gul''Dan'),
(2131000, 9, 10 ,0, 0,  0, 100, 0, 4000,4000,0,0,12,21181,2,600000,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Summon Cyrukh the Firelord <The Dirge of Karabor>'),
(2131000, 9, 11 ,0, 0,  0, 100, 0, 0,0,0,0,1,3,0,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 4 on Gul''Dan'),
(2131000, 9, 12 ,0, 0,  0, 100, 0, 1000,1000,0,0,1,0,0,0,0,0,0,19,21181,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 4 on Cyrukh the Firelord <The Dirge of Karabor>'),
(2131000, 9, 13 ,0, 0,  0, 100, 0, 3000,3000,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Summon Group'),
(2131000, 9, 14 ,0, 0,  0, 100, 0, 3000,3000,0,0,1,0,0,0,0,0,0,19,21685,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 1 on Oronok Torn-heart'),
(2131000, 9, 15 ,0, 0,  0, 100, 0, 3000,3000,0,0,1,4,0,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 5 on Gul''Dan'),
(2131000, 9, 16 ,0, 0,  0, 100, 0, 6000,6000,0,0,1,5,0,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 6 on Gul''Dan'),
(2131000, 9, 17 ,0, 0,  0, 100, 0, 0,0,0,0,45,2,2,0,0,0,0,19,17008,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Set Data 2 2 on Gul''Dan'),
(2131000, 9, 18 ,0, 0,  0, 100, 0, 6000,6000,0,0,1,5,0,0,0,0,0,19,21685,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Say Line 2 on Oronok Torn-heart'),
(2131000, 9, 19 ,0, 0,  0, 100, 0, 0,0,0,0,45,1,1,0,0,0,0,19,21685,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Set Data 1 1 on Oronok Torn-heart'),
(2131000, 9, 20 ,0, 0,  0, 100, 0, 0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Valley Invisible Trigger (Tiny) - Script - Despawn');

DELETE FROM `waypoints` WHERE `entry` IN(21685,21686,21687,21181,2168500,2168600,2168700);

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(21687, 1,-3620.271, 1862.062, 48.44324, 'Gromtor, Son of Oronok'),
(21687, 2,-3623.021, 1861.062, 48.94324, 'Gromtor, Son of Oronok'),
(21687, 3,-3626.021, 1860.062, 49.94324, 'Gromtor, Son of Oronok'),
(21687, 4,-3629.771, 1858.812, 50.94324, 'Gromtor, Son of Oronok'),
(21687, 5,-3631.521, 1858.312, 51.69324, 'Gromtor, Son of Oronok'),
(21687, 6,-3633.521, 1857.562, 52.44324, 'Gromtor, Son of Oronok'),
(21687, 7,-3634.521, 1857.312, 53.44324, 'Gromtor, Son of Oronok'),
(21687, 8,-3636.271, 1856.562, 54.19324, 'Gromtor, Son of Oronok'),
(21687, 9,-3637.271, 1856.312, 55.19324, 'Gromtor, Son of Oronok'),
(21687, 10,-3640.271, 1855.312, 55.69324, 'Gromtor, Son of Oronok'),
(21687, 11,-3643.021, 1854.562, 56.44324, 'Gromtor, Son of Oronok'),
(21687, 12,-3642.169, 1854.779, 56.43678, 'Gromtor, Son of Oronok'),
(21687, 13,-3644.919, 1854.529, 56.68678, 'Gromtor, Son of Oronok'),
(21687, 14,-3642.169, 1854.779, 56.43678, 'Gromtor, Son of Oronok'),
(21687, 15,-3644.919, 1854.529, 56.68678, 'Gromtor, Son of Oronok'),
(21687, 16,-3646.248, 1853.079, 57.05591, 'Gromtor, Son of Oronok'),
(21687, 17,-3647.998, 1852.079, 57.80591, 'Gromtor, Son of Oronok'),
(21686, 1,-3618.578, 1866.529, 48.23744, 'Borak, Son of Oronok'),
(21686, 2,-3620.311, 1865.76, 48.47595, 'Borak, Son of Oronok'),
(21686, 3,-3622.811, 1865.26, 48.97595, 'Borak, Son of Oronok'),
(21686, 4,-3624.811, 1864.51, 49.47595, 'Borak, Son of Oronok'),
(21686, 5,-3626.313, 1863.896, 50.1328, 'Borak, Son of Oronok'),
(21686, 6,-3628.313, 1863.396, 50.8828, 'Borak, Son of Oronok'),
(21686, 7,-3630.313, 1862.646, 51.3828, 'Borak, Son of Oronok'),
(21686, 8,-3632.813, 1861.896, 52.1328, 'Borak, Son of Oronok'),
(21686, 9,-3634.813, 1861.396, 52.8828, 'Borak, Son of Oronok'),
(21686, 10,-3634.81, 1861.143, 53.03374, 'Borak, Son of Oronok'),
(21686, 11,-3636.56, 1860.643, 53.78374, 'Borak, Son of Oronok'),
(21686, 12,-3639.31, 1859.893, 54.28374, 'Borak, Son of Oronok'),
(21686, 13,-3641.06, 1859.393, 55.03374, 'Borak, Son of Oronok'),
(21686, 14,-3643.06, 1858.643, 56.03374, 'Borak, Son of Oronok'),
(21686, 15,-3643.157, 1857.902, 56.33821, 'Borak, Son of Oronok'),
(21686, 16,-3644.657, 1857.152, 57.08821, 'Borak, Son of Oronok'),
(21686, 17,-3646.227, 1855.506, 57.3797, 'Borak, Son of Oronok'),
(21686, 18,-3648.227, 1853.756, 58.3797, 'Borak, Son of Oronok'),
(21685, 1,-3619.83, 1857.978, 48.17765, 'Oronok Torn-heart'),
(21685, 2,-3624.58, 1856.228, 48.67765, 'Oronok Torn-heart'),
(21685, 3,-3625.787, 1855.872, 49.38496, 'Oronok Torn-heart'),
(21685, 4,-3627.787, 1855.122, 50.13496, 'Oronok Torn-heart'),
(21685, 5,-3629.537, 1854.622, 51.13496, 'Oronok Torn-heart'),
(21685, 6,-3630.287, 1854.372, 51.63496, 'Oronok Torn-heart'),
(21685, 7,-3631.287, 1854.122, 53.13496, 'Oronok Torn-heart'),
(21685, 8,-3632.287, 1853.872, 53.88496, 'Oronok Torn-heart'),
(21685, 9,-3632.533, 1853.489, 54.04154, 'Oronok Torn-heart'),
(21685, 10,-3634.533, 1852.989, 56.29154, 'Oronok Torn-heart'),
(21685, 11,-3637.033, 1852.239, 57.79154, 'Oronok Torn-heart'),
(21685, 12,-3640.951, 1852.142, 57.46563, 'Oronok Torn-heart'),
(21181, 1,-3617.7155, 1823.1611, 39.7751, 'Cyrukh the Firelord <The Dirge of Karabor>'),
(2168500, 1,-3600.319, 1898.602, 47.36539, 'Oronok Torn-heart (Path 2)'),
(2168600, 1,-3597.452, 1895.446, 47.36539, 'Borak, Son of Oronok (Path 2)'),
(2168700, 1,-3603.953, 1895.167, 47.36539, 'Gromtor, Son of Oronok (Path 2)');

DELETE FROM `creature_text` WHERE `entry` IN(21685,17008,21181,21310,21049,21739,21740);
DELETE FROM `creature_text` WHERE `entry` IN(21024) and `groupid`>10;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(21024, 11, 0, 'I hear what you hear, brother. Look behind you...', 12, 0, 100, 1, 0, 0,  'Earthmender Torlok to Cyrukh the Firelord',19336),

(21685, 0, 0, 'You do not fight alone, $n! Together, we will banish this spawn of hellfire!', 14, 0, 100, 0, 0, 0, 'Oronok Torn-heart',19304),
(21685, 1, 0, 'We leave, then, Torlok. I have only one request...', 12, 0, 100, 1, 0, 0, 'Oronok Torn-heart',19341),
(21685, 2, 0, 'The Torn-heart men give their weapons to Earthmender Torlok.', 16, 0, 100, 1, 0, 0, 'Oronok Torn-heart',19342),
(21685, 3, 0, 'Give these to the heroes that made this possible.', 12, 0, 100, 1, 0, 0, 'Oronok Torn-heart',19343),
(21685, 4, 0, 'We will set the elements free of your grasp by force!', 14, 0, 100, 0, 0, 0, 'Oronok Torn-heart',19309),
(21685, 5, 0, 'We will fight when you are ready.', 12, 0, 100, 0, 0, 0, 'Oronok Torn-heart',19310),
(21685, 6, 0, 'What say the elements, Torlok? I hear only silence.', 12, 0, 100, 1, 0, 0, 'Oronok Torn-heart',19334),
(21685, 7, 0, 'They are redeemed! Then we have won?', 12, 0, 100, 5, 0, 0, 'Oronok Torn-heart',19337),
(17008, 0, 0, 'Be silent! The shattering is soon to come!', 12, 0, 100, 15, 0, 0, 'Gul''dan',18701),
(17008, 1, 0, 'Bear witness to the undeniable power of our dark master!', 12, 0, 100, 0, 0, 0, 'Gul''dan',18702),
(17008, 2, 0, 'With his gift, I shall raze this land and reform it!', 12, 0, 100, 0, 0, 0, 'Gul''dan',18703),
(17008, 3, 0, 'Watch! See the ground shatter before us! Watch as the energy flows! It will feed our armies...', 12, 0, 100, 0, 0, 0, 'Gul''dan',18704),
(17008, 4, 0, 'We will never be without power! I have secured our future! Bask in my glory!', 12, 0, 100, 0, 0, 0, 'Gul''dan',18705),
(17008, 5, 0, 'It... is... done...', 12, 0, 100, 0, 0, 0, 'Gul''dan',18706),
(21181, 0, 0, 'Cyrukh has awoken!', 14, 0, 100, 0, 0, 0, 'Cyrukh the Firelord',19298),
(21181, 1, 0, 'Cyrukh comes for you!', 14, 0, 100, 0, 0, 0, 'Cyrukh the Firelord',19301),
(21181, 1, 1, 'You will suffer eternally!', 14, 0, 100, 0, 0, 0, 'Cyrukh the Firelord',19299),
(21181, 1, 2, 'Those that dare play with fire will be incinerated!', 14, 0, 100, 0, 0, 0, 'Cyrukh the Firelord',19302),
(21181, 1, 3, 'Little creature made of flesh, your wish is granted! Death comes for you!', 14, 0, 100, 0, 0, 0, 'Cyrukh the Firelord',19308),
(21310, 0, 0, 'A flaming vortex takes shape.', 16, 0, 100, 0, 0, 0, 'Shadowmoon Valley Invisible Trigger (Tiny)',19303),
(21049, 0, 0, 'You have damned us all... We are lost.', 12, 0, 100, 20, 0, 0, 'Spirit of the Past',18700),
(21049, 0, 1, 'Stop! You must stop!', 12, 0, 100, 20, 0, 0, 'Spirit of the Past',18698),
(21049, 0, 2, 'Do not do this, Gul''dan! The elements will never forgive us!', 12, 0, 100, 20, 0, 0, 'Spirit of the Past',18697),
(21049, 0, 3, 'Think of our younglings, Gul''dan! You will destroy us all!', 12, 0, 100, 20, 0, 0, 'Spirit of the Past',18699),
(21049, 0, 4, 'We will take from the land if it refuses to give!', 12, 0, 100, 15, 0, 0, 'Spirit of the Past',18696),
(21049, 0, 5, 'Tear the land asunder, Gul''dan! Sever the tie!', 12, 0, 100, 15, 0, 0, 'Spirit of the Past',18694),
(21049, 0, 6, 'They have abandoned us! Do not forget!', 12, 0, 100, 15, 0, 0, 'Spirit of the Past',18695),
(21740, 0, 0, 'Yes... Well enough for the elements that are here, but the cipher is known to another... The spirits of fire are in turmoil... If this force is not stopped, the world where these mortals came from will cease.', 12, 0, 100, 0, 0, 0, 'Redeemed Spirit of Fire',19339),
(21739, 0, 0, 'Farewell, mortals... The earthmender knows what fire feels...', 12, 0, 100, 0, 0, 0, 'Redeemed Spirit of Earth',19340),
(21739, 1, 0, 'It is now as it should be, shaman. You have done well.', 12, 0, 100, 0, 0, 0, 'Redeemed Spirit of Earth',19338);

DELETE FROM `creature_template_addon` WHERE `entry`	BETWEEN 21738 AND 21741;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(21741, 0, 0x0, 0x1, ''), -- 21741
(21740, 0, 0x0, 0x1, ''), -- 21740
(21739, 0, 0x0, 0x1, ''), -- 21739
(21738, 0, 0x0, 0x1, ''); -- 21738

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=35997;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 35997, 0, 0, 35, 1, 0, 20, 1, 0, 0, 0, '', 'Fel Flames target must not be self'),
(13, 1, 35997, 0, 0, 31, 0, 3, 21052, 0, 0, 0, 0, '', 'Fel Flames target has to be Camera Shaker - Altar of Damnation');

DELETE FROM `creature_summon_groups` WHERE `summonerId`IN(21310);
DELETE FROM `creature_summon_groups` WHERE `summonerId`IN(21024) AND `groupId`=1;

INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(21024, 0, 1, 21738, -3587.229, 1892.889, 47.32373, 2.199115, 1, 37000),
(21024, 0, 1, 21739, -3598.681, 1888.016, 47.32373, 1.692969, 1, 37000),
(21024, 0, 1, 21740, -3605.315, 1884.477, 47.32373, 1.308997, 1, 37000),
(21024, 0, 1, 21741, -3591.871, 1886.822, 47.32373, 1.850049, 1, 37000),
(21310, 0, 0, 21685, -3600.319, 1898.602, 47.36539, 4.921828, 1, 600000),
(21310, 0, 0, 21686, -3603.865, 1900.854, 47.36539, 4.931085, 1, 600000),
(21310, 0, 0, 21687, -3597.99, 1902.118, 47.3654, 4.848677, 1, 600000);

DELETE FROM `event_scripts` WHERE id=13961;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(13961, 3, 10, 21310, 50000, 0, -3590.538574, 1832.343506, 41.749908, 1.65);
