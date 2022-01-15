--
-- 1. Cleanup
--

-- Handled in core
DELETE FROM `smart_scripts` WHERE `entryorguid` = 261000 AND `source_type` = 9 AND `action_type` IN (105,106);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 186944 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(186944,1,0,1,70,0,100,0,2,0,0,0,0,12,24790,1,120000,1,0,0,8,0,0,0,0,688.912,-3377.74,67.8758,1.29154,"Dirt Mound - On State Changed - Summon Black Conrads Ghost"),
(186944,1,1,2,61,0,100,0,0,0,0,0,0,12,24796,1,120000,1,0,0,8,0,0,0,0,691.571,-3375.86,68.0995,1.309,"Dirt Mound - On State Changed - Summon Spectral Sailor"),
(186944,1,2,0,61,0,100,0,0,0,0,0,0,12,24796,1,120000,1,0,0,8,0,0,0,0,687.27,-3374.88,67.9214,1.0472,"Dirt Mound - On State Changed - Summon Spectral Sailor");

-- "Patches" does not reset Metal Stake when respawns (sniff), he respawns before objects resets, object resets exactly after autoCloseTime
-- Anyway that script never worked, creature sets 1 1 and object reacts to 2 2, event is never triggered
-- And if it was triggered, it sets flag 4 which that object never has, that probably will break interaction with object until grid unload
UPDATE `creature` SET `wander_distance` = 5, `MovementType` = 1, `spawntimesecs` = 15, `position_x` = 6621.147, `position_y` = 3197.2717, `position_z` = 647.6063, `orientation` = 3.700098037719726562, `VerifiedBuild` = 14545 WHERE `id` = 30993;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30993 AND `source_type` = 0 AND `id` BETWEEN 13 AND 16;

UPDATE `smart_scripts` SET `link` = 0 WHERE `entryorguid` = 193025 AND `source_type` = 1 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 193025 AND `source_type` = 1 AND `id` BETWEEN 1 AND 2;

-- Gameobject is not unselectable and should not be
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11032 AND `source_type` = 0 AND `action_type` = 104;

--
-- 2. Replace SMART_ACTION_SET_GO_FLAG with SMART_ACTION_ADD_GO_FLAG & SMART_ACTION_REMOVE_GO_FLAG
--

--
UPDATE `smart_scripts` SET `action_type` = 105 WHERE `entryorguid` = 194555 AND `source_type` = 1 AND `action_type` = 104 AND `action_param1` = 16;
UPDATE `smart_scripts` SET `action_type` = 106, `action_param1` = 16 WHERE `entryorguid` = 194555 AND `source_type` = 1 AND `action_type` = 104 AND `action_param1` = 0;

UPDATE `smart_scripts` SET `action_type` = 105 WHERE `entryorguid` BETWEEN 19455500 AND 19455505 AND `source_type` = 9 AND `action_type` = 104 AND `action_param1` = 16;
UPDATE `smart_scripts` SET `action_type` = 106, `action_param1` = 16 WHERE `entryorguid` BETWEEN 19455500 AND 19455505 AND `source_type` = 9 AND `action_type` = 104 AND `action_param1` = 0;

--
UPDATE `smart_scripts` SET `action_type` = 106, `action_param1` = 16 WHERE `entryorguid` IN (184312,184311,183956,183770) AND `source_type` = 1 AND `action_type` = 104 AND `action_param1` = 0;

UPDATE `smart_scripts` SET `action_type` = 105 WHERE `entryorguid` IN (18431200,18431100,18395600,18377000) AND `source_type` = 9 AND `action_type` = 104 AND `action_param1` = 16;
UPDATE `smart_scripts` SET `action_type` = 106, `action_param1` = 16 WHERE `entryorguid` IN (18431200,18431100,18395600,18377000) AND `source_type` = 9 AND `action_type` = 104 AND `action_param1` = 0;

--
UPDATE `smart_scripts` SET `action_type` = 105 WHERE `entryorguid` = 201937 AND `source_type` = 1 AND `action_type` = 104 AND `action_param1` = 16;
UPDATE `smart_scripts` SET `action_type` = 106, `action_param1` = 16 WHERE `entryorguid` = 201937 AND `source_type` = 1 AND `action_type` = 104 AND `action_param1` = 0;

--
-- 3. Replace everything with GameObjectActions
--

-- Make Inert
UPDATE `smart_scripts` SET `action_type` = 147 WHERE `entryorguid` IN (164881,164882,164883,164884,171940,171943,173325,173326,174609,174610,174612,174613,174614,174615,174616,174617,174618,174619,174620,174621,174622,174623,174624,174625,174685,174687,174710,174711,174714,174715,178965,182026,194555,201937) AND `source_type` = 1 AND `action_type` = 105 AND `action_param1` = 16;
UPDATE `smart_scripts` SET `action_type` = 147 WHERE `entryorguid` IN (207600,251901,17724300,18045200,18051500,18377000,18395600,18431100,18431200,18656000,19455500,19455501,19455502,19455503,19455504,19455505) AND `source_type` = 9 AND `action_type` = 105 AND `action_param1` = 16;

-- Make Active
UPDATE `smart_scripts` SET `action_type` = 147, `action_param1` = 17 WHERE `entryorguid` IN (7668,7669,7670,7671,11937) AND `source_type` = 0 AND `action_type` = 106 AND `action_param1` = 16;
UPDATE `smart_scripts` SET `action_type` = 147, `action_param1` = 17 WHERE `entryorguid` IN (174553,174554,174555,174556,174557,174558,174559,174560,174561,174562,174563,174564,174565,174566,177243,177365,177366,177367,177368,177369,177385,177397,177398,177399,177400,182026,183770,183956,184311,184312,194555,201937) AND `source_type` = 1 AND `action_type` = 106 AND `action_param1` = 16;
UPDATE `smart_scripts` SET `action_type` = 147, `action_param1` = 17 WHERE `entryorguid` IN (207600,251901,2390500,2390500,2390500,16481900,16481901,16481902,16481903,16481904,16481905,17724300,18045200,18051500,18377000,18395600,18431100,18431200,18656000,19455500,19455501,19455502,19455503,19455504,19455505) AND `source_type` = 9 AND `action_type` = 106 AND `action_param1` = 16;
