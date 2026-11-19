-- Summon minions
DELETE FROM `spell_script_names` WHERE `spell_id`=59910;
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUE
(59910,'spell_summon_minions');

-- Heroic spells
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (49198,49034,49037,50089,49668,51363) OR `spellid0` IN (49198,49034,49037,50089,49668,51363);
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(49198,49198,59909), -- Arcance Blast
(49034,49034,59854), -- Blizzard
(49037,49037,59855), -- Frostbolt
(50089,50089,59856), -- Wrath of Misery
(49668,49668,59004), -- Flash of Darkness
(51363,51363,59016); -- Shadow Bolt

-- Script assignment for summoners
UPDATE `creature_template` SET `ScriptName`='npc_crystal_channel_target',`AIName`='' WHERE `entry`=26712;

-- Spawn summoner for Crystal Handlers
SET @GUID = 19;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`) VALUE
(@GUID,26712,600,3,17188,-341.31,-724.4,28.57,3.78,3600,8982);

-- Check instance script for achievement Oh Novos
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7361;
INSERT INTO `achievement_criteria_data`(`criteria_id`,`type`,`ScriptName`) VALUE
(7361,11,'achievement_oh_novos');

-- Waypoints for summoned adds
DELETE FROM `waypoint_data` WHERE `id` IN(2759700,2759800,2760000,2662700);
INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES 
(2759700,1,-379.473,-810.974,59.7612),
(2759700,2,-379.449,-791.535,44.1756),
(2759700,3,-379.448,-790.328,44.1756),
(2759700,4,-379.426,-772.338,28.5884),
(2759700,5,-379.415,-763.518,28.5884),
(2760000,1,-376.571,-810.681,59.6673),
(2760000,2,-375.627,-791.874,44.1756),
(2760000,3,-375.629,-790.273,44.1434),
(2760000,4,-375.402,-771.145,28.5895),
(2760000,5,-375.337,-765.027,28.5895),
(2759800,1,-382.303,-810.815,59.7628),
(2759800,2,-382.324,-791.595,44.1756),
(2759800,3,-382.326,-790.331,44.1746),
(2759800,4,-383.037,-770.382,28.5884),
(2759800,5,-383.140,-765.399,28.5884),
(2662700,1,-346.977,-733.319,28.5838),
(2662700,2,-363.009,-765.202,28.5907),
(2662700,3,-378.269,-765.701,28.5893);

-- SAI for Crystal Handlers and Risen Shadowcasters
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` IN (26627,27600);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26627,27600) AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(26627,0,1000,1000,5000,5000,11,49668,2,'Crystal Handler - In fight - After 1s then every 5s - Cast Flash of Darkness - On victim'),
(27600,0,1000,1000,5000,5000,11,51363,2,'Risen Shadowcaster - In fight - After 1s then every 5s - Cast Shadow Bolt - On victim');

-- Conditions for beam spell
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=52106;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`Comment`) VALUES
(13,1,52106,31,0,3,26712,0,'Beam Channel target has to be Crystal Channel Target'),
(13,1,52106,35,1,0,   18,1,'Beam Channel target must not be self');
