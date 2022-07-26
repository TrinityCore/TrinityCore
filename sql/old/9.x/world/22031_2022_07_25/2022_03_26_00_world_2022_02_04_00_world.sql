--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15209,15211,15212,15307,15206,15207,15208,15220,15203,15204,15205,15305) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1520300,1520600,1520900) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1520300,9,0,0,0,0,100,0,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Skaldrenox - On Script - Cast 'Elemental Spawn-in'"),
(1520300,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Prince Skaldrenox - On Script - Set Orientation Summoner"),
(1520300,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Prince Skaldrenox - On Script - Say Line 0"),
(1520300,9,3,0,0,0,100,0,8000,8000,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Skaldrenox - On Script - Set ImmunePC Off"),
(1520300,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Prince Skaldrenox - On Script - Start Attack Summoner"),

(1520600,9,0,0,0,0,100,0,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Cynders - On Script - Cast 'Elemental Spawn-in'"),
(1520600,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Duke of Cynders - On Script - Set Orientation Summoner"),
(1520600,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Duke of Cynders - On Script - Say Line 0"),
(1520600,9,3,0,0,0,100,0,8000,8000,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Cynders - On Script - Set ImmunePC Off"),
(1520600,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Duke of Cynders - On Script - Start Attack Summoner"),

(1520900,9,0,0,0,0,100,0,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crimson Templar - On Script - Cast 'Elemental Spawn-in'"),
(1520900,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crimson Templar - On Script - Set Orientation Summoner"),
(1520900,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crimson Templar - On Script - Say Line 0"),
(1520900,9,3,0,0,0,100,0,8000,8000,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crimson Templar - On Script - Set ImmunePC Off"),
(1520900,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Crimson Templar - On Script - Start Attack Summoner"),

-- High Council
(15203,0,0,0,11,0,100,0,0,0,0,0,0,80,1520300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Skaldrenox - On Spawn - Run Script"),
(15203,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Skaldrenox - On Evade - Despawn"),
(15203,0,2,0,0,0,100,0,10000,15000,10000,15000,0,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Prince Skaldrenox - In Combat - Cast 'Cleave'"),
(15203,0,3,0,0,0,100,0,15000,15000,30000,30000,0,11,25049,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prince Skaldrenox - In Combat - Cast 'Blastwave'"),
(15203,0,4,0,0,0,100,0,10000,20000,10000,20000,0,11,25050,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Prince Skaldrenox - In Combat - Cast 'Mark of Flames'"),

(15204,0,0,0,11,0,100,0,0,0,0,0,0,80,1520300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Marshal Whirlaxis - On Spawn - Run Script"),
(15204,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Marshal Whirlaxis - On Evade - Despawn"),
(15204,0,2,0,60,0,100,0,0,25000,25000,35000,0,11,25020,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Marshal Whirlaxis - On Update - Cast 'Lightning Shield'"),
(15204,0,3,0,0,0,100,0,15000,25000,15000,25000,0,11,20627,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"High Marshal Whirlaxis - In Combat - Cast 'Lightning Breath'"),
(15204,0,4,0,0,0,100,0,25000,35000,25000,35000,0,11,25060,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Marshal Whirlaxis - In Combat - Cast 'Updraft'"),

(15205,0,0,0,11,0,100,0,0,0,0,0,0,80,1520300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Baron Kazum - On Spawn - Run Script"),
(15205,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Baron Kazum - On Evade - Despawn"),
(15205,0,2,0,0,0,100,0,10000,15000,10000,15000,0,11,17547,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Baron Kazum - In Combat - Cast 'Mortal Strike'"),
(15205,0,3,0,0,0,100,0,15000,25000,15000,25000,0,11,19129,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Baron Kazum - In Combat - Cast 'Massive Tremor'"),
(15205,0,4,0,0,0,100,0,25000,35000,25000,35000,0,11,25056,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Baron Kazum - In Combat - Cast 'Stomp'"),
-- Sunder Armor was removed at some point in vanilla
-- No aura here for Thrash
(15305,0,0,0,11,0,100,0,0,0,0,0,0,80,1520300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lord Skwol - On Spawn - Run Script"),
(15305,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lord Skwol - On Evade - Despawn"),
(15305,0,2,0,0,0,100,0,10000,15000,10000,15000,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lord Skwol - In Combat - Cast 'Thrash'"),
(15305,0,3,0,0,0,100,0,10000,15000,20000,30000,0,11,25053,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lord Skwol - In Combat - Cast 'Venom Spit'"),

-- The Duke
(15206,0,0,0,11,0,100,0,0,0,0,0,0,80,1520600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Cynders - On Spawn - Run Script"),
(15206,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Cynders - On Evade - Despawn"),
(15206,0,2,0,0,0,100,0,15000,20000,20000,25000,0,11,18399,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"The Duke of Cynders - In Combat - Cast 'Flamestrike'"),
(15206,0,3,0,0,0,100,0,10000,15000,20000,25000,0,11,22424,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Cynders - In Combat - Cast 'Blast Wave'"),
(15206,0,4,0,0,0,100,0,15000,25000,15000,25000,0,11,25028,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Duke of Cynders - In Combat - Cast 'Fire Blast'"),
-- No aura here for Thrash
(15207,0,0,0,11,0,100,0,0,0,0,0,0,80,1520600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Fathoms - On Spawn - Run Script"),
(15207,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Fathoms - On Evade - Despawn"),
(15207,0,2,0,0,0,100,0,10000,15000,10000,15000,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Fathoms - In Combat - Cast 'Thrash'"),
(15207,0,3,0,0,0,100,0,10000,15000,15000,20000,0,11,16790,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Duke of Fathoms - In Combat - Cast 'Knockdown'"),
(15207,0,4,0,0,0,100,0,15000,20000,20000,25000,0,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Duke of Fathoms - In Combat - Cast 'Knock Away'"),

(15208,0,0,0,11,0,100,0,0,0,0,0,0,80,1520600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Shards - On Spawn - Run Script"),
(15208,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Shards - On Evade - Despawn"),
(15208,0,2,0,0,0,100,0,5000,10000,5000,10000,0,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Duke of Shards - In Combat - Cast 'Strike'"),
(15208,0,3,0,0,0,100,0,10000,15000,15000,20000,0,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Shards - In Combat - Cast 'Thunderclap'"),
(15208,0,4,0,0,0,100,0,15000,25000,15000,25000,0,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Shards - In Combat - Cast 'Ground Tremor'"),

(15220,0,0,0,11,0,100,0,0,0,0,0,0,80,1520600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Zephyrs - On Spawn - Run Script"),
(15220,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Zephyrs - On Evade - Despawn"),
(15220,0,2,0,0,0,100,0,15000,20000,20000,30000,0,11,12882,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Duke of Zephyrs - In Combat - Cast 'Wing Flap'"),
(15220,0,3,0,0,0,100,0,10000,15000,15000,25000,0,11,15535,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"The Duke of Zephyrs - In Combat - Cast 'Enveloping Winds'"),
(15220,0,4,0,0,0,100,0,10000,15000,10000,20000,0,11,25034,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Duke of Zephyrs - In Combat - Cast 'Forked Lightning'"),

-- Templar
(15209,0,0,0,11,0,100,0,0,0,0,0,0,80,1520900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crimson Templar - On Spawn - Run Script"),
(15209,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crimson Templar - On Evade - Despawn"),
(15209,0,2,0,0,0,100,0,10000,15000,10000,15000,0,11,11989,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crimson Templar - In Combat - Cast 'Fireball Volley'"),
(15209,0,3,0,0,0,100,0,5000,10000,5000,10000,0,11,16536,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Crimson Templar - In Combat - Cast 'Flame Buffet'"),

(15211,0,0,0,11,0,100,0,0,0,0,0,0,80,1520900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Azure Templar - On Spawn - Run Script"),
(15211,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Azure Templar - On Evade - Despawn"),
(15211,0,2,0,0,0,100,0,5000,10000,10000,15000,0,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Azure Templar - In Combat - Cast 'Frost Shock'"),
(15211,0,3,0,0,0,100,0,10000,15000,15000,20000,0,11,14907,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Azure Templar - In Combat - Cast 'Frost Nova'"),

(15212,0,0,0,11,0,100,0,0,0,0,0,0,80,1520900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hoary Templar - On Spawn - Run Script"),
(15212,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hoary Templar - On Evade - Despawn"),
(15212,0,2,0,60,0,100,0,0,10000,10000,15000,0,11,25020,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hoary Templar - On Update - Cast 'Lightning Shield'"),
(15212,0,3,0,0,0,100,0,10000,15000,10000,15000,0,11,2610,2,0,0,0,0,2,0,0,0,0,0,0,0,0,"Hoary Templar - In Combat - Cast 'Shock'"),

(15307,0,0,0,11,0,100,0,0,0,0,0,0,80,1520900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthen Templar - On Spawn - Run Script"),
(15307,0,1,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthen Templar - On Evade - Despawn"),
(15307,0,2,0,0,0,100,0,10000,15000,15000,25000,0,11,18813,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Earthen Templar - In Combat - Cast 'Knock Away'"),
(15307,0,3,0,0,0,100,0,5000,10000,15000,25000,0,11,22127,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Earthen Templar - In Combat - Cast 'Entangling Roots'");

--
UPDATE `gameobject` SET `spawntimesecs` = 300 WHERE `id` IN (180456,180518,180529,180544,180549,180564);
UPDATE `gameobject` SET `spawntimesecs` = 10800 WHERE `id` IN (180466,180539,180559);

-- Credit: vmangos
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 2.28571, `BaseAttackTime` = 2500, `unit_flags` = 256 WHERE `entry` = 15203;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 2.28571, `unit_flags` = 256 WHERE `entry` = 15204;
UPDATE `creature_template` SET `speed_walk` = 0.777776, `speed_run` = 2.28571, `BaseAttackTime` = 3000, `unit_flags` = 256 WHERE `entry` = 15205;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429, `unit_flags` = 256 WHERE `entry` = 15206;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429, `unit_flags` = 256 WHERE `entry` = 15207;
UPDATE `creature_template` SET `speed_walk` = 0.777776, `speed_run` = 1.71429, `unit_flags` = 256 WHERE `entry` = 15208;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429, `unit_flags` = 256 WHERE `entry` = 15209;
UPDATE `creature_template` SET `speed_walk` = 1.55556, `speed_run` = 1.71429, `unit_flags` = 256 WHERE `entry` = 15211;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429, `unit_flags` = 256 WHERE `entry` = 15212;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429, `unit_flags` = 256 WHERE `entry` = 15220;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429, `BaseAttackTime` = 2000, `unit_flags` = 256 WHERE `entry` = 15305;
UPDATE `creature_template` SET `speed_walk` = 1.55556, `speed_run` = 1.71429, `unit_flags` = 256 WHERE `entry` = 15307;

UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = '19818' WHERE `entry` = 15204;
