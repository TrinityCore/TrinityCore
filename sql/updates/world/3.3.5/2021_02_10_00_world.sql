-- Alliance Corpse
-- Forsaken Corpse
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 24009;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 24010;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `emote` = 0, `auras` = "29266" WHERE `entry` = 24009;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `emote` = 0, `auras` = "29266" WHERE `entry` = 24010;

-- Brutallus, I guess he was stunned by Madrigosa, no sniff
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 25158;

-- Bloodmage Alkor
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 25797;

-- Dragonblight Mage Hunter
-- Focus Wizard
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 26280;
DELETE FROM `creature` WHERE `guid` IN (43741,43769,43770,43772,44018) AND `id` IN (26280,26816);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(43741,26280,571,1,1,0,1,3026.387939453125,1384.9114990234375,129.4793548583984375,3.577924966812133789,300,0,0,11723),
(43769,26280,571,1,1,0,1,3008.05712890625,1420.3697509765625,139.6544952392578125,3.420845270156860351,300,0,0,11723),
(43770,26816,571,1,1,0,1,3022.4853515625,1412.7396240234375,130.4464569091796875,1.93731546401977539,300,0,0,11723),
(43772,26816,571,1,1,0,1,3037.97998046875,1396.55908203125,123.5310287475585937,0.541052043437957763,300,0,0,11723),
(44018,26816,571,1,1,0,1,2996.413818359375,1400.7843017578125,129.3368072509765625,1.500983119010925292,300,0,0,11723);
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0 WHERE `guid` IN (43741,43769,43770,43772,44018,111738,111733,111744,111736,111737,111732,111731,113955,113954,113944,113943,113945,113953) AND `id` IN (26280,26816);

DELETE FROM `creature_addon` WHERE `guid` IN (43741,43769,43770,43772,44018,111738,111733,111744,111736,111737,111732,111731,113955,113954,113944,113943,113945,113953);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(43741,0,0,0,1,0,0,"29266"),
(43769,0,0,0,1,0,0,"29266"),
(43770,0,0,0,1,0,0,"29266"),
(43772,0,0,0,1,0,0,"29266"),
(44018,0,0,0,1,0,0,"29266"),
(111738,0,0,0,1,0,0,"29266"),
(111733,0,0,0,1,0,0,"29266"),
(111744,0,0,0,1,0,0,"29266"),
(111736,0,0,0,1,0,0,"29266"),
(111737,0,0,0,1,0,0,"29266"),
(111732,0,0,0,1,0,0,"29266"),
(111731,0,0,0,1,0,0,"29266"),
(113955,0,0,0,1,0,0,"29266"),
(113954,0,0,0,1,0,0,"29266"),
(113944,0,0,0,1,0,0,"29266"),
(113943,0,0,0,1,0,0,"29266"),
(113945,0,0,0,1,0,0,"29266"),
(113953,0,0,0,1,0,0,"29266");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-43741,-43769,-43770,-43772,-44018,-111738,-111733,-111744,-111736,-111737,- 111732,-111731,-113955,-113954,-113944,-113943,-113945,-113953) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-43741,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Just Created - Set Faction 35"),
(-43769,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Just Created - Set Faction 35"),
(-43770,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Focus Wizard - On Just Created - Set Faction 35"),
(-43772,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Focus Wizard - On Just Created - Set Faction 35"),
(-44018,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Focus Wizard - On Just Created - Set Faction 35"),
(-111738,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Just Created - Set Faction 35"),
(-111733,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Just Created - Set Faction 35"),
(-111744,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Just Created - Set Faction 35"),
(-111736,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Just Created - Set Faction 35"),
(-111737,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Just Created - Set Faction 35"),
(-111732,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Just Created - Set Faction 35"),
(-111731,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonblight Mage Hunter - On Just Created - Set Faction 35"),
(-113955,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Focus Wizard - On Just Created - Set Faction 35"),
(-113954,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Focus Wizard - On Just Created - Set Faction 35"),
(-113944,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Focus Wizard - On Just Created - Set Faction 35"),
(-113943,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Focus Wizard - On Just Created - Set Faction 35"),
(-113945,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Focus Wizard - On Just Created - Set Faction 35"),
(-113953,0,0,0,63,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Focus Wizard - On Just Created - Set Faction 35");

-- Battle for Undercity stuff. Flags looks like sniffed but no sniff currently available + in CreatureDifficulty half of them uses no flags
-- meaning only some of them appear as dead. But if they will be spawned, probably they uses aura 29266 (based on flags)
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` BETWEEN 32390 AND 32397 OR `entry` IN (32511,32521);

-- Ebon Blade Defender
-- Ebon Blade Winged Defender
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` IN (31250,31257);

UPDATE `creature` SET `position_x` = 8286.890625, `position_y` = 2762.56201171875, `position_z` = 656.02484130859375, `orientation` = 3.141592741012573242, `VerifiedBuild` = 14545 WHERE `guid` = 121050 AND `id` = 31250;
UPDATE `creature` SET `position_x` = 8284.6923828125, `position_y` = 2768.385009765625, `position_z` = 654.97760009765625, `orientation` = 3.176499128341674804, `VerifiedBuild` = 14545 WHERE `guid` = 121051 AND `id` = 31250;
UPDATE `creature` SET `position_x` = 8284.1826171875, `position_y` = 2772.507568359375, `position_z` = 654.5260009765625, `orientation` = 3.124139308929443359, `VerifiedBuild` = 14545 WHERE `guid` = 121052 AND `id` = 31250;
UPDATE `creature` SET `position_x` = 8285.7060546875, `position_y` = 2777.061767578125, `position_z` = 655.026611328125, `orientation` = 3.246312379837036132, `VerifiedBuild` = 14545 WHERE `guid` = 121053 AND `id` = 31250;
UPDATE `creature` SET `position_x` = 8288.8310546875, `position_y` = 2781.588134765625, `position_z` = 656.02484130859375, `orientation` = 3.211405754089355468, `VerifiedBuild` = 14545 WHERE `guid` = 121054 AND `id` = 31250;

UPDATE `creature` SET `position_x` = 8282.3798828125, `position_y` = 2777.769287109375, `position_z` = 653.47955322265625, `orientation` = 3.001966238021850585, `VerifiedBuild` = 14545 WHERE `guid` = 121131 AND `id` = 31257;
UPDATE `creature` SET `position_x` = 8280.7177734375, `position_y` = 2768.34375, `position_z` = 653.15802001953125, `orientation` = 2.897246599197387695, `VerifiedBuild` = 14545 WHERE `guid` = 121132 AND `id` = 31257;
UPDATE `creature` SET `position_x` = 8282.4794921875, `position_y` = 2762.603271484375, `position_z` = 654.29119873046875, `orientation` = 3.03687286376953125, `VerifiedBuild` = 14545 WHERE `guid` = 121134 AND `id` = 31257;
DELETE FROM `creature` WHERE `guid` = 44021 AND `id` = 31257;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(44021,31257,571,1,1,0,0,8285.1767578125, 2782.968505859375, 654.5582275390625, 3.001966238021850585,15,0,0,14545);
-- Sniffed, probably other too should respawn after 15 sec
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0, `spawntimesecs` = 15 WHERE `id` = 31257;

DELETE FROM `creature_template_addon` WHERE `entry` IN (31250,31257);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(31250,0,0,0,1,375,0,"58897"),
(31257,0,0,50331648,1,0,0,"58897");

-- Male Frost Leopard
-- Male Icepaw Bear
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` IN (33007,33008);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 33008);
