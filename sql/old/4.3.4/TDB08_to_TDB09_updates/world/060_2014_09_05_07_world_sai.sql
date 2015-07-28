SET @OGUID :=    21036;

-- respawn  Fel Crystal Prism (Currently only 1 is spawned)

DELETE FROM `gameobject` WHERE `id`=185927;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 185927, 530, 1, 1, 2909.894, 6797.157, 365.7202, 2.391098, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+1, 185927, 530, 1, 1, 2988.61, 7129.965, 368.9746, 1.029743, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+2, 185927, 530, 1, 1, 3080.931, 6914.941, 369.3258, 4.32842, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+3, 185927, 530, 1, 1, 2810.343, 7006.054, 376.0882, 1.151916, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+4, 185927, 530, 1, 1, 1385.925, 7392.285, 371.1215, 0.5585039, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+5, 185927, 530, 1, 1, 1280.611, 7164.499, 377.1786, 5.585054, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+6, 185927, 530, 1, 1, 1616.641, 7207.047, 375.4805, 5.131269, 0, 0, 0, 1, 120, 255, 1), 
(@OGUID+9, 185927, 530, 1, 1, 1673.486, 7377.358, 375.558, 1.308995, 0, 0, 0, 1, 120, 255, 1);

-- SAI for Fel Crystal Prism
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=185927;
DELETE FROM `smart_scripts` WHERE `entryorguid`=185927 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 18592700 AND 18592703 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(185927, 1, 0, 1, 62, 0, 100, 0, 8671, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - On Gossip Option 0 Selected - Store Targetlist'),
(185927, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 40958, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - On Gossip Option 0 Selected - Invoker Cast Blades Edge Terrace Demon Boss Summon Trigger'),
(185927, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 85, 40962, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - On Gossip Option 0 Selected - Invoker Cast Blades Edge Terrace Demon Boss Summon Branch'),
(185927, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 87, 18592700, 18592701, 18592702, 18592703, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - On Gossip Option 0 Selected - Run Random Timed Action list'),
(18592700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 40957, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 1 - Invoker Cast Blades Edge Terrace Demon Boss Summon 1'),
(18592700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 1 - Despawn GO'),
(18592700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 1 - Close Gossip'),
(18592701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 40959, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 2 - Invoker Cast Blades Edge Terrace Demon Boss Summon 2'),
(18592701, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 2 - Despawn GO'),
(18592701, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 2 - Close Gossip'),
(18592702, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 40960, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 3 - Invoker Cast Blades Edge Terrace Demon Boss Summon 3'),
(18592702, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 3 - Despawn GO'),
(18592702, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 3 - Close Gossip'),
(18592703, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 40961, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 4 - Invoker Cast Blades Edge Terrace Demon Boss Summon 4'),
(18592703, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 4 - Despawn GO'),
(18592703, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Fel Crystal Prism - Script 4 - Close Gossip');

-- SAI for Demons
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(22281,23353,23354,23355) AND `source_type`=0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(22281,23353,23354,23355);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22281,0,0,0,11,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Galvanoth - On Spawn - Set Faction'),
(22281,0,1,0,9,0,100,0,0,30,8000,11000,11,39139,0,0,0,0,0,7,0,0,0,0,0,0,0,'Galvanoth - On Range - Cast Fel Flamestike'),
(22281,0,2,0,9,0,100,0,0,10,13000,23000,11,38750,0,0,0,0,0,1,0,0,0,0,0,0,0,'Galvanoth - On Range - Cast War Stomp'),
(22281,0,3,0,9,0,100,0,0,5,11000,18000,11,15708,0,0,0,0,0,7,0,0,0,0,0,0,0,'Galvanoth - On Range - Cast Mortal Strike'),
(23353,0,0,0,11,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Braxxus - On Spawn - Set Faction'),
(23353,0,1,0,9,0,100,0,0,5,4000,8000,11,41437,0,0,0,0,0,7,0,0,0,0,0,0,0,'Braxxus - On Range - Cast Double Breath'),
(23353,0,2,0,9,0,100,0,0,10,15000,25000,11,41439,2,0,0,0,0,7,0,0,0,0,0,0,0,'Braxxus - On Range - Cast Mangle'),
(23353,0,3,0,0,0,100,0,5000,8000,7000,11000,11,41436,0,0,0,0,0,1,0,0,0,0,0,0,0,'Braxxus - IC - Cast Panic'),
(23354,0,0,0,11,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mo arg Incinerator - On Spawn - Set Faction'),
(23354,0,1,0,9,0,100,0,0,40,5000,8000,11,44431,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mo arg Incinerator - On Range - Cast Acid Geyser'),
(23354,0,2,0,9,0,100,0,10,60,10000,15000,11,36606,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mo arg Incinerator - On Range - Cast Mighty Charge'),
(23354,0,3,0,9,0,100,0,0,5,15000,25000,11,25174,2,0,0,0,0,7,0,0,0,0,0,0,0,'Mo arg Incinerator - On Range - Cast Sundering Cleave'),
(23355,0,0,0,11,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zarcsin - On Spawn - Set Faction'),
(23355,0,1,0,9,0,100,0,0,5,5000,8000,11,41444,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zarcsin - On Range - Cast Fel Flames'),
(23355,0,2,0,2,0,100,1,0,50,5000,8000,11,41447,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zarcsin - 50% HP - Cast Enrage');

-- ALL 4 of these should have 100% chance to drop an apexis crystal, this is rolled if in party
UPDATE `creature_loot_template` SET `Chance`=100 WHERE  `entry`IN(22281,23353,23354,23355) AND `item`=32572;
-- Fel Whip to complete quest is meant to have 100% chance to drop if on quest as all comments state you only have to kill 1 demon to complete the quest
UPDATE `creature_loot_template` SET `Chance`=100 AND `QuestRequired`=1 WHERE `entry`IN(22281,23353,23354,23355) AND `item`=32733;

DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid` IN (185937,185938,185936,185932);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(185937, 1, 0, 1, 62, 0, 100, 0, 8690, 0, 0, 0, 85, 41050, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Furywing\'s Egg - On Gossip Option 0 Selected - Invoker cast Four Dragons: Force Cast - Furywing'),
(185938, 1, 0, 1, 62, 0, 100, 0, 8691, 0, 0, 0, 85, 41052, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Insidion\'s Egg - On Gossip Option 0 Selected - Invoker cast Four Dragons: Force Cast - Insidion'),
(185936, 1, 0, 1, 62, 0, 100, 0, 8689, 0, 0, 0, 85, 41044, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rivendark\'s Egg - On Gossip Option 0 Selected - Invoker cast Four Dragons: Force Cast - Rivendark'),
(185937, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 41049, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Furywing\'s Egg - On Gossip Option 0 Selected - Invoker Cast Four Dragons: Reagents - Furywing'),
(185938, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 41051, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Insidion\'s Egg - On Gossip Option 0 Selected - Invoker Cast Four Dragons: Reagents - Insidion'),
(185936, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 41045, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rivendark\'s Egg - On Gossip Option 0 Selected - Invoker Cast Four Dragons: Reagents - Rivendark'),
(185937, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Furywing\'s Egg - On Gossip Option 0 Selected - Close Gossip'),
(185938, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Insidion\'s Egg - On Gossip Option 0 Selected - Close Gossip'),
(185936, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rivendark\'s Egg - On Gossip Option 0 Selected - Close Gossip'),
(185937, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Furywing\'s Egg - On Gossip Option 0 Selected - Despawn GO'),
(185938, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Insidion\'s Egg - On Gossip Option 0 Selected - Despawn GO'),
(185936, 1, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rivendark\'s Egg - On Gossip Option 0 Selected - Despawn GO'),
(185932, 1, 0, 1, 62, 0, 100, 0, 8685, 0, 0, 0, 85, 41035, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Obsidia\'s Egg - On Gossip Option 0 Selected - Invoker Cast 41035 Four Dragons: Force Cast - Obsidia'),
(185932, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 41036, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Obsidia\'s Egg - On Gossip Option 0 Selected - Invoker Cast Four Dragons: Reagents - Obsidia'),
(185932, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Obsidia\'s Egg - On Gossip Option 0 Selected - Close Gossip');

DELETE FROM `event_scripts` WHERE `id` IN(15004,15002);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(15004, 0, 10, 23061, 300000, 0, 2060.6, 7418.53, 391.098, 0),
(15002, 0, 10, 23281, 300000, 0, 4176.5, 5452.21, 291.923, 0),
(15003, 0, 10, 23261, 300000, 0, 3845.31, 5220.04, 295.412, 0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=23282;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =23364;
DELETE FROM `smart_scripts` WHERE `entryorguid` =23364 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =23282 AND `source_type`=0 AND `id`>4;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23364, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 11, 15750, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Cast Rookery Whelp Spawn-in Spell'),
(23364, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Say'),
(23364, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Set Unit Flags'),
(23364, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 14, 27915, 185932, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Despawn Obsidia\'s Egg'),
(23364, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 23364, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Start WP'),
(23364, 0, 5, 6, 40, 0, 100, 0, 2, 23364, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 23282, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Reached WP2 - Set Data on Obsidia'),
(23364, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - Reached WP2 - Despawn'),
(23282, 0, 5, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Spawn - Set Unit Flags'),
(23282, 0, 6, 7, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Data Set - Say'),
(23282, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 23282, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Data Set - Start WP'),
(23282, 0, 8, 9, 40, 0, 100, 0, 1, 23282, 0, 0, 94, 280, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Reached WP1 - Set Dynamic Flags'),
(23282, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Reached WP1 - Set Unit Flags'),
(23282, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Reached WP1 - Set Home Position'),
(23282, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Reached WP1 - Set Aggresive');

DELETE FROM `creature_text` WHERE `entry` IN(23364,23282);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(23364, 0, 0, 'The %s screams out for its mother.', 16, 0, 100, 0, 0, 431, 'Black Dragon Whelpling',21420),
(23282, 0, 0, 'I believe that I shall feast upon both $r and ogre flesh tonight.', 14, 0, 100, 0, 0, 7274, 'Obsidia',21718);


DELETE FROM `waypoints` WHERE `entry` IN(23364,23282);

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(23364, 1,2425.253, 6994.862, 368.0848, 'Black Dragon Whelpling'),
(23364, 2,2424.881, 6998.754, 367.8495, 'Black Dragon Whelpling'),
(23282, 1,2428.085, 6980.77, 369.7684, 'Obsidia');

DELETE FROM `event_scripts` WHERE `id` IN(15004,15002,15003,15005);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(15004, 0, 10, 23061, 300000, 0, 2060.6, 7418.53, 391.098, 0),
(15002, 0, 10, 23281, 300000, 0, 4176.5, 5452.21, 291.923, 0),
(15003, 0, 10, 23261, 300000, 0, 3845.31, 5220.04, 295.412, 0),
(15005, 1, 10, 23364, 100000, 0, 2426.954, 7001.479, 367.3824, 0),
(15005, 0, 10, 23282, 300000, 0, 2424.975, 6933.425, 409.5501, 1.43117);
