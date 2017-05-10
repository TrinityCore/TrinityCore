SET @Guid := 79263;

-- Script Undercity NPC's 

-- Sniffs used Undercity_full.bin (3.3.5) for spawns, etc   2014-07-17_11-12-35_19FAA762.pkt (5.4.8) for texts, emotes etc

-- Set Spawntime of Caged Human Male to 120 seconds as is in sniff of this creature not 300 seconds
UPDATE `creature` SET `spawntimesecs`=120 WHERE `guid`=45218;

-- Delete the incorrectly spawned human male captive, human female captive, captive ghoul, zombie and abomination as these are spawned as part of event
DELETE FROM `creature` WHERE  `id` IN (5680,5681,5685,5686,5687);

-- Delete the incorrectly spawned Caged Squirrel
DELETE FROM `creature` WHERE `guid`=45216;
DELETE FROM `creature_addon` WHERE `guid`=45216; -- Caged Squirrel

-- Spawn overseer Kraggosh and the 4 Kor'kron overseers which are missing from the Apothacarium
DELETE FROM `creature` WHERE `guid` IN (@Guid,@Guid+1,@Guid+2,@Guid+3,@Guid+4);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@Guid, 36217, 0, 1, 1, 1438.026, 403.8299, -85.26257, 3.124139, 120, 0, 0), -- 36217 (Area: 0)
(@Guid+1, 36213, 0, 1, 1, 1388.434, 421.5955, -77.15382, 6.091199, 120, 0, 0), -- 36213 (Area: 0)
(@Guid+2, 36213, 0, 1, 1, 1446.222, 415.6059, -84.90555, 3.857178, 120, 0, 0), -- 36213 (Area: 0)
(@Guid+3, 36213, 0, 1, 1, 1414.677, 448.1597, -77.15431, 4.677482, 120, 0, 0), -- 36213 (Area: 0)
(@Guid+4, 36213, 0, 1, 1, 1419.076, 389.0208, -84.98041, 0.6981317, 120, 0, 0); -- 36213 (Area: 0)

-- Set NPC Flags on Overseer Kraggosh and Apothacary Farnell, gossip is already in db and linked to creature but flag is not set
UPDATE `creature_template` SET `npcflag`=1 WHERE  `entry`=36217;
UPDATE `creature_template` SET `npcflag`=3 WHERE  `entry`=2055;

-- Creature template addon data for Overseer Kraggosh
DELETE FROM `creature_template_addon` WHERE `entry`=36217;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(36217, 0, 0x0, 0x101, ''); -- 36217

-- Smart AI
UPDATE `creature_template` SET AIName='SmartAI' WHERE `entry` IN (5735,5736,5738,5734,5661,5657,5656, 5655, 5659, 5660, 5658, 2055, 5662, 5700, 5696, 5697, 5726,5727,5728,5729,5730, 36217);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (5735,5736,5738,5734,5661,5657,5656, 5655, 5659, 5660, 5658, 2055, 5662, 5700, 5696, 5697, 5726,5727,5728,5729,5730, 36217) AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (573600,573400,566100,205500, 569600) AND `source_type`=9);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
-- Caged human male
(5736, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 36, 5742, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caged Human Male - On Data Set 1 1 Change Entry to Caged Toad'),
(5736, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 36, 5739, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caged Human Male - On Data Set 2 2 Change Entry to Caged Sqirrel'),
(5736, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 36, 5741, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caged Human Male - On Data Set 3 3 Change Entry to Caged Rabbit'),
(5736, 0, 3, 0, 38, 0, 100, 0, 4, 4, 0, 0, 36, 5743, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caged Human Male - On Data Set 4 4 Change Entry to Caged Sheep'),
(5736, 0, 4, 5, 38, 0, 100, 0, 5, 5, 0, 0, 11, 7670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caged Human Male - On Data Set 5 5 Cast Explode'),
(5736, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caged Human Male - On Data Set 5 5 - Run Script'),
-- Caged Human Female
(5735,0,0,0,1,0,100,0,0,13000,29000,45000,10,18,20,1,0,0,0,1,0,0,0,0,0,0,0,"Caged Human Female - Out of Combat - Play Random Emote"),
-- Caged Dwarf Male
(5738,0,0,0,1,0,100,0,0,13000,29000,45000,10,18,20,1,0,0,0,1,0,0,0,0,0,0,0,"Caged Dwarf Male - Out of Combat - Play Random Emote"),
-- Apothecary Keever
(5734, 0, 0, 0, 1, 0, 100, 0, 0, 0, 321000, 321000, 80, 573400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - OOC - Run Script'),
(573400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Stand'),
(573400, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 1'),
(573400, 9, 2, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 2'),
(573400, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Kneel'),
(573400, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 5736, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Set Data 1 1 on Caged Human'),
(573400, 9, 5, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 3'),
(573400, 9, 6, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 4'),
(573400, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Stand'),
(573400, 9, 8, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 5'),
(573400, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Kneel'),
(573400, 9, 10, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 5742, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Set Data 2 2 on Caged Toad'),
(573400, 9, 11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 6'),
(573400, 9, 12, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 7'),
(573400, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Stand'),
(573400, 9, 14, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 8'),
(573400, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Kneel'),
(573400, 9, 16, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 5739, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Set Data 3 3 on Caged Squirrel'),
(573400, 9, 17, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 6'),
(573400, 9, 18, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 7'),
(573400, 9, 19, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Stand'),
(573400, 9, 20, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 8'),
(573400, 9, 21, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Kneel'),
(573400, 9, 22, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 4, 4, 0, 0, 0, 0, 19, 5741, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Set Data 4 4 on Caged Rabbit'),
(573400, 9, 23, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 6'),
(573400, 9, 24, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Stand'),
(573400, 9, 25, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 7'),
(573400, 9, 26, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Kneel'),
(573400, 9, 27, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 5, 5, 0, 0, 0, 0, 19, 5743, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Set Data 5 5 on Caged Sheep'),
(573400, 9, 28, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 8'),
(573400, 9, 39, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Stand'),
(573400, 9, 30, 0, 0, 0, 100, 0, 174500, 174500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Say Line 0'),
(573400, 9, 31, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 7794, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Cast Teleport'),
(573400, 9, 37, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society> - Script - Kneel'),
-- Brother Malach
(5661, 0, 0, 0, 1, 0, 100, 0, 0, 0, 170000, 170000, 80, 566100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - OOC - Run script'),
(566100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Say Line 0'),
(566100, 9, 1, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Say Line 1'),
(566100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 107, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Summon Group 0'),
(566100, 9, 3, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Say Line 2'),
(566100, 9, 4, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Say Line 3'),
(566100, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Summon Group 1'),
(566100, 9, 6, 0, 0, 0, 100, 0, 35000, 35000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Say Line 4'),
(566100, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Say Line 5'),
(566100, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 107, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Summon Group 2'),
(566100, 9, 9, 0, 0, 0, 100, 0, 50000, 50000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Malach - Script - Say Line 5'),
-- Spectator NPC's
(5657, 0, 0, 0, 1, 0, 100, 0, 0, 5000, 2000, 5000, 10, 21, 4, 71, 22, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marla Fowler - OOC  - Random Emote'),
(5656, 0, 0, 0, 1, 0, 100, 0, 0, 5000, 2000, 5000, 10, 21, 4, 71, 22, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Richard Van Brunt - OOC  - Random Emote'),
(5655, 0, 0, 0, 1, 0, 100, 0, 0, 5000, 2000, 5000, 10, 21, 4, 71, 22, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Robert Gossom - OOC  - Random Emote'),
(5659, 0, 0, 0, 1, 0, 100, 0, 0, 5000, 2000, 5000, 10, 21, 4, 71, 22, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Andrew Hartwell - OOC  - Random Emote'),
(5660, 0, 0, 0, 1, 0, 100, 0, 0, 5000, 2000, 5000, 10, 21, 4, 71, 22, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Riley Walker - OOC  - Random Emote'),
(5658, 0, 0, 0, 1, 0, 100, 0, 0, 5000, 2000, 5000, 10, 21, 4, 71, 22, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chloe Curthas - OOC  - Random Emote'),
-- Below sai is to stop the spectator npcs from attacking summoned npcs, unit_flags 32768 are correct according to sniff and these have flags extra civillian but this does not stop these attacking summoned npcs
(5657, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marla Fowler - On Spawn - Set Immune to NPC'),
(5656, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Richard Van Brunt - On Spawn - Set Immune to NPC'),
(5655, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Robert Gossom - On Spawn - Set Immune to NPC'),
(5659, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Andrew Hartwell - On Spawn - Set Immune to NPC'),
(5660, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Riley Walker - On Spawn - Set Immune to NPC'),
(5658, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chloe Curthas - On Spawn - Set Immune to NPC'),
-- Master Apothecary Faranell
(2055, 0, 0, 0, 1, 0, 100, 0, 90000, 180000, 150000, 320000, 80, 205500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - OOC  - Run Script'),
(205500, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 36217, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Say Line 0'),
(205500, 9, 1, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 36217, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Set Data'),
(205500, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 36217, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Say Line 1'),
(205500, 9, 3, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 36217, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Say Line 1'),
(205500, 9, 4, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 36217, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Face Overseer Kraggosh'),
(205500, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Say Line 1'),
(205500, 9, 6, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Say Line 1'),
(205500, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 36217, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Say Line 3'),
(205500, 9, 8, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 36217, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Set Data'),
(205500, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.26893, 'Master Apothecary Faranell - Script - Set Orientation'),
(205500, 9, 10, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 36217, 0, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Say Line 4'),
(205500, 9, 11, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10, @Guid+4, 36213, 0, 0, 0, 0, 0, 'Master Apothecary Faranell - Script - Say Line 4'),
-- Sergeant Houser
(5662, 0, 0, 1, 1, 0, 100, 0, 7000, 15000, 15000, 22000, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sergeant Houser - OOC  - Pause WP'),
(5662, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sergeant Houser - OOC  - Say'),
(5662, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 5662, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sergeant Houser - On Spawn  - Start WP'),
(5700, 0, 0, 0, 1, 0, 100, 0, 7000, 10000, 7000, 10000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Samantha Shackleton - OOC  - Say'),
-- Gerald Abernathy
(5696, 0, 0, 0, 1, 0, 100, 0, 30000, 45000, 230000, 300000, 80, 569600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gerard Abernathy - OOC - Run Script'),
(569600, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gerard Abernathy - Script - Say Line 0'),
(569600, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 5697, 0, 0, 0, 0, 0, 0, 'Gerard Abernathy - Script - Set Data Theresa'),
(569600, 9, 2, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 1, 2, 3000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gerard Abernathy - Script - Say Line 2'),
(569600, 9, 3, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 3000, 0, 0, 0, 0, 19, 5699, 0, 0, 0, 0, 0, 0, 'Gerard Abernathy - Script - Say Line 0'),
(569600, 9, 4, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 3, 3000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gerard Abernathy - Script - Say Line 3'),
(569600, 9, 5, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 3000, 0, 0, 0, 0, 19, 5698, 0, 0, 0, 0, 0, 0, 'Gerard Abernathy - Script - Say Line 0'),
-- Theresa
(5697, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 5697, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Data Set  - Start WP'),
(5697, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2717, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Data Set  - Equip Bottle'),
(5697, 0, 2, 3, 40, 0, 100, 0, 9, 5697, 0, 0, 54, 17000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Reached WP9  - Pause WP'),
(5697, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Reached WP9  - Say Line 1'),
(5697, 0, 4, 13, 61, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Reached WP9  - Unequip Bottle'),
(5697, 0, 5, 6, 52, 0, 100, 0, 1, 5697, 0, 0, 1, 0, 3000, 0, 0, 0, 0, 19, 4607, 0, 0, 0, 0, 0, 0, 'Theresa - On Text Over  - Say'),
(5697, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2717, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Text Over  - Equip Bottle'),
(5697, 0, 7, 8, 40, 0, 100, 0, 18, 5697, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.27606, 'Theresa - On Reached WP18  - Set Orientation'),
(5697, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Reached WP18  - Say Line 1'),
(5697, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Reached WP18 - Unequip Bottle'),
(5697, 0, 10, 0, 52, 0, 100, 0, 2, 5697, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 5696, 0, 0, 0, 0, 0, 0, 'Theresa - On Text Over  - Say'),
(5697, 0, 11, 12, 52, 0, 100, 0, 0, 4607, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Text Over  - Say'),
(5697, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Text Over - Stand'),
(5697, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Reached WP9 - Kneel'),
(5726, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jezelles Felhunter - On Spawn  - Set Random Movement'),
(5727, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jezelles Felstead - On Spawn  - Set Random Movement'),
(5728, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jezelles Succubus - On Spawn  - Set Random Movement'),
(5729, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jezelles Voidwalker - On Spawn  - Set Random Movement'),
(5730, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jezelles Imp - On Spawn  - Set Random Movement'),
(36217, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 36217, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Kraggosh - On Data Set  - Start WP'),
(36217, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 66, 0, 0, 0, 0, 0, 0, 10, @Guid+4, 36213, 0, 0, 0, 0, 0, 'Overseer Kraggosh - On Data Set  - Face Kor kron overseer'),
(36217, 0, 2, 0, 40, 0, 100, 0, 2, 36217, 0, 0, 54, 45000, 0, 0, 0, 0, 0, 1,0, 0, 0, 0, 0, 0, 0, 'Overseer Kraggosh - On Reached WP2  - Pause WP'),
(36217, 0, 3, 0, 40, 0, 100, 0, 5, 36217, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.124139, 'Overseer Kraggosh - On Reached WP5  - Set Orientation');

-- Creature Text
DELETE FROM `creature_text` WHERE `entry` IN(5734, 36217, 2055, 36213,5662,5700,5696,5697,5698,5699,4607,5661);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(5734, 0, 0, 'Hmm, it would seem Keever needs a new subject. If that fool Abernathy keeps taking Keever''s subjects, Keever may have to have a word with him.', 12, 33, 100, 1, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2061),
(5734, 1, 0, 'Ahh, there we go. Now, Keever must try this vial and see if it works.', 12, 33, 100, 1, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2062),
(5734, 2, 0, '%s forces the fluid down the weary man''s throat.', 16, 0, 100, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2075),
(5734, 3, 0, '%s pokes the small toad.', 16, 0, 100, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2064),
(5734, 4, 0, 'Not what Keever was hoping for. Keever may have added too much earthroot. Let''s see if the second serum will do what Keever needs.', 12, 33, 100, 1, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2063),
(5734, 5, 0, '%s feeds the toad some of the strange liquid.', 16, 0, 100, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2065),
(5734, 6, 0, '%s pokes the small fuzzy squirrel with obvious disappointment.', 16, 0, 100, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2066),
(5734, 7, 0, 'Well, that is just not right. The creature is far too small. Let us see what Keever''s third batch will do.', 12, 33, 100, 1, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2067),
(5734, 8, 0, '%s feeds the squirrel some of the viscous fluid.', 16, 0, 100, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2068),
(5734, 9, 0, '%s pokes the skittish rabbit.', 16, 0, 100, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2069),
(5734, 10, 0, 'Keever is unhappy with this. Perhaps if Keever were to try a larger dose, that may fix this dilemma.', 12, 33, 100, 1, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2070),
(5734, 11, 0, '%s grabs the rabbit and pours the fluid down its throat, then sets it back inside the cage.', 16, 0, 100, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2071),
(5734, 12, 0, 'What is this? Did Keever ask for a sheep? Keever wanted a weapon of great power and all he got was this sheep. Keever is very disappointed.', 12, 33, 100, 1, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2072),
(5734, 13, 0, '%s pokes the wooly sheep repeatedly.', 16, 0, 100, 0, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2073),
(5734, 14, 0, 'Keever is most pleased.', 12, 33, 100, 11, 0, 0, 'Apothecary Keever <Royal Apothecary Society>', 2074),
(36217, 0, 0, 'I''ve got my eye on you, Faranell.', 12, 1, 100, 1, 0, 0, 'Overseer Kraggosh', 36299),
(36217, 1, 0, 'No abominations protecting you. No secrecy. No plotting in the dark.', 12, 1, 100, 0, 0, 0, 'Overseer Kraggosh', 36300),
(36217, 2, 0, 'If you so much as spit without my permission, this place shuts down. Forcefully.', 12, 1, 100, 0, 0, 0, 'Overseer Kraggosh', 36301),
(2055, 0, 0, 'I assure you, overseer, the Royal Apothecary Society dearly wishes to make up for the tragic misguidance which ended so many lives.', 12, 1, 100, 0, 0, 0, 'Master Apothecary Faranell ', 36302),
(2055, 1, 0, 'We will cause you no trouble. We seek only to continue our research in peace.', 12, 1, 100, 0, 0, 0, 'Master Apothecary Faranell ', 36303),
(36217, 3, 0, 'We''ll see about that.', 12, 1, 100, 1, 0, 0, 'Overseer Kraggosh', 36304),
(36217, 4, 0, 'Get that rotten nut to shut his trap!', 12, 1, 100, 5, 0, 0, 'Overseer Kraggosh', 36305),
(36213, 0, 0, 'Shut your face, you gibbering idiot!', 12, 1, 100, 0, 0, 0, 'Kor''kron Overseer', 36306),
(5662, 0, 0, 'You sorry sacks of maggot flesh can do better than that, now prove it!', 12, 33, 100, 25, 0, 0, 'Sergeant Houser', 1969),
(5662, 0, 1, 'Alright you sorry sacks of bones. Let''s see what you''ve got. Strike your opponent, and don''t stop till I say so.', 12, 33, 100, 1, 0, 0, 'Sergeant Houser', 1963),
(5662, 0, 2, 'What do you call that? If that''s fighting then I''m Lothar himself!', 12, 33, 100, 25, 0, 0, 'Sergeant Houser', 1971),
(5662, 0, 3, 'These piles of wood and straw may show mercy, but the Lich King won''t!', 12, 33, 100, 25, 0, 0, 'Sergeant Houser', 1968),
(5662, 0, 4, 'The sword isn''t a tool, it''s an extension of you. I expect better!', 12, 33, 100, 25, 0, 0, 'Sergeant Houser', 1970),
(5662, 0, 5, 'Stop! You maggots call that fighting? That is pathetic! Now put your hearts in it, you don''t need them anymore anyway!', 12, 33, 100, 25, 0, 0, 'Sergeant Houser', 1964),
(5662, 0, 6, 'You''re dead, not buried. Now show me your best!', 12, 33, 100, 25, 0, 0, 'Sergeant Houser', 1967),
(5662, 0, 7, 'You don''t fight for yourselves anymore, maggots! You fight for the Queen now so show me something worthy of her!', 12, 33, 100, 25, 0, 0, 'Sergeant Houser', 1966),
(5700, 0, 0, 'If I could just find "Magic and the Ways of Power". Ahh here it is, what was it doing over here?', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2034),
(5700, 0, 1, 'Very interesting. But if that''s the case then my theory is wrong. I must reread the other sections to see what I missed.', 12, 33, 100, 1, 0, 0, 'Samantha Shackleton', 2040),
(5700, 0, 2, 'Magical Flows and How They Effect the World", by Maginor Dumas. That''s the one I was looking for.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2030),
(5700, 0, 3, 'If this is correct then I have a lot more research to do.', 12, 33, 100, 1, 0, 0, 'Samantha Shackleton', 2042),
(5700, 0, 4, 'Ahh there it is.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2029),
(5700, 0, 5, 'I really need a better system for filing these books. Ahh that''s the one I wanted.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2031),
(5700, 0, 6, 'But this can''t be right. Where did I put that other book?', 12, 33, 100, 1, 0, 0, 'Samantha Shackleton', 2043),
(5700, 0, 7, '"Khadgar''s Mystical Journal, Volume 8." I think this is the one I wanted.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2032),
(5700, 0, 8, 'Ahh, "Mystical Conjurings of the Archmages of Dalaran." Perfect.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2033),
(5700, 0, 9, 'If I could just find "Magic and the Ways of Power". Ahh here it is, what was it doing over here?', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2034),
(5700, 0, 10, '"Magic Maladies", no. "Magic Matricies", no. Ahh here we go "Magic Mysteries".', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2035),
(5700, 0, 11, 'There''s the mystical tome I was looking for.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2036),
(5700, 0, 12, 'Yes, yes. Hmm, it seems to cross reference another tome. Guess I have to find that one too.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2037),
(5700, 0, 13, 'That wasn''t very helpful. Let me check the other one.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2038),
(5700, 0, 14, 'That''s what I wanted to know. Now I just need to find where the flux variance is discussed.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2039),
(5700, 0, 15, 'So I was right about the energies. Let''s see what the other tome has to say on the subject.', 12, 33, 100, 0, 0, 0, 'Samantha Shackleton', 2041),
(5696, 0, 0, 'Theresa, take this to Father Lankester.', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 1995),
(5696, 1, 0, 'Why thank you, my pet.', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2011),
(5696, 2, 0, 'As good as I told you it would be, yes?', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2003),
(5696, 2, 1, 'Didn''t I tell you my new domination techniques would work?', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2002),
(5696, 2, 2, 'So what do you think of my new toy?', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 1994),
(5696, 2, 3, 'How do you like my pet?', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2000),
(5696, 3, 0, 'A little torture, a pinch of magic, and an ample helping of invasive surgery. She was conscious, of course.', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2007),
(5696, 3, 1, 'Everyone has a weakness, it''s just a matter of finding it.', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2008),
(5696, 3, 2, 'It was simple once I broke her spirit.', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2004),
(5696, 3, 3, 'I managed to discover that certain parts of the brain when removed or stimulated will make a subject much more docile.', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2009),
(5696, 3, 4, 'You don''t expect me to give up all my secrets do you?', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2005),
(5696, 3, 5, 'A little ritual torture can go a long way.', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2006),
(5697, 0, 0, 'Yes My Lord.', 12, 33, 100, 0, 0, 0, 'Theresa', 1998),
(5697, 1, 0, 'My Lord Abernathy sends this to you.', 12, 33, 100, 0, 0, 0, 'Theresa', 1997),
(5697, 2, 0, 'My Lord. From Father Lankester.', 12, 33, 100, 0, 0, 0, 'Theresa', 1999),
(5698, 0, 0, 'Bravo, Gerard, you have exceeded yourself, yet again.', 12, 33, 100, 1, 0, 0, 'Joanna Whitehall', 2018),
(5698, 0, 1, 'I am truly impressed, Gerard. I thought you were all talk, but I see I have been proven wrong.', 12, 33, 100, 1, 0, 0, 'Joanna Whitehall', 2019),
(5698, 0, 2, 'I don''t agree with your turning to alchemy to fix some of the problems, but I do agree with the results. Very well done.', 12, 33, 100, 0, 0, 0, 'Joanna Whitehall', 2024),
(5698, 0, 3, 'Did you have to house train her, Gerard?', 12, 33, 100, 1, 0, 0, 'Joanna Whitehall', 2027),
(5698, 0, 4, 'An amazing discovery you have made. I would love an opportunity to look at all of the failed experiments.', 12, 33, 100, 0, 0, 0, 'Joanna Whitehall', 2023),
(5699, 0, 0, 'I''ve never seen anything like it. No concentration or loss of awareness while the subject is dominated. What did you do to her?', 12, 33, 100, 1, 0, 0, 'Leona Tharpe', 2017),
(5699, 0, 1, 'Amazing! How did you manage a permanent dominate?', 12, 33, 100, 1, 0, 0, 'Leona Tharpe', 2013),
(5699, 0, 2, 'I don''t approve of your experiments, Gerard, but I must admit the results are impressive. What exactly did you do to her?', 12, 33, 100, 1, 0, 0, 'Leona Tharpe', 2014),
(5699, 0, 3, 'She retains knowledge and speech, and even the self sufficiency to perform tasks for you. Precisely what did you do?', 12, 33, 100, 1, 0, 0, 'Leona Tharpe', 2016),
(5699, 0, 4, 'Truly amazing, Gerard. How did you do it?', 12, 33, 100, 1, 0, 0, 'Leona Tharpe', 2012),
(4607, 0, 0, 'Ugh! What is that scoundrel doing sending his vermin to me? Get out of my sight before I take what is left of your life. And take this with you.', 12, 33, 100, 1, 0, 0, 'Father Lankester', 2028),
(5661, 0, 0, 'Edward. Tyler. Prepare for your first challenge.', 12, 33, 100, 1, 0, 0, 'Brother Malach', 1978),
(5661, 1, 0, 'Lysta, summon in the captives.', 12, 33, 100, 0, 0, 0, 'Brother Malach', 1977),
(5661, 2, 0, 'Not a challenge at all it seems. Let us see how you handle your second test. Lysta, bring forth the minions of the Lich King.', 12, 33, 100, 0, 0, 0, 'Brother Malach', 1980),
(5661, 3, 0, 'Lysta, summon in undead captives.', 12, 33, 100, 0, 0, 0, 'Brother Malach', 8306),
(5661, 4, 0, 'It is time to face your final challenge young warriors! Prepare for your hardest fight yet.', 12, 33, 100, 0, 0, 0, 'Brother Malach', 1984),
(5661, 5, 0, 'Lysta, summon forth... the abomination!', 12, 33, 100, 0, 0, 0, 'Brother Malach', 8307),
(5661, 6, 0, 'Well done Edward and Tyler. You are progressing along in your training quite nicely. We shall test your mettle again soon.', 12, 33, 100, 0, 0, 0, 'Brother Malach', 1985);

-- Update Jezelle Pruitts text as in sniff she uses emote 1 with every line as this is in sniff
UPDATE `creature_text` SET `emote`=1 WHERE  `entry`=5702;

-- Creature summon groups for Brother Malach (Human captives, captive zombie, ghoul and abomination)
DELETE FROM `creature_summon_groups` WHERE `summonerId`=5661;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(5661, 0, 0, 5680, 1735.93, 378.124, -62.2055, 3.71755, 1, 60000),
(5661, 0, 0, 5680, 1734.36, 379.952, -62.2058, 3.92699, 1, 60000),
(5661, 0, 0, 5681, 1734.67, 379.246, -62.2881, -2.78843, 1, 60000),
(5661, 0, 1, 5686, 1734.68, 378.533, -62.1315, 3.85718, 1, 60000),
(5661, 0, 1, 5685, 1735.24, 380.689, -62.2077, 3.85718, 1, 60000),
(5661, 0, 2, 5687, 1735.33, 379.152, -62.206, 3.82227, 1, 60000);

-- Waypoints

DELETE FROM `waypoints` WHERE `entry`IN(5697,36217,5662);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(5697, 1,  1662.228149, 353.675415, -60.742798, 'Theresa'),
(5697, 2,  1667.451416, 349.544647, -60.740757, 'Theresa'),
(5697, 3,  1678.154785, 345.241730, -60.481709, 'Theresa'),
(5697, 4,  1698.429199, 334.720062, -60.482483, 'Theresa'),
(5697, 5,  1706.992676, 324.664032, -55.392391, 'Theresa'),
(5697, 6,  1734.973267, 346.734009, -55.393040, 'Theresa'),
(5697, 7,  1782.811035, 350.868103, -62.369541, 'Theresa'),
(5697, 8,  1795.520752, 370.227966, -60.158966, 'Theresa'),
(5697, 9,  1785.445190, 400.132721, -57.214481, 'Theresa'), 
(5697, 10,  1795.520752, 370.227966, -60.158966, 'Theresa'),
(5697, 11,  1782.811035, 350.868103, -62.369541, 'Theresa'),
(5697, 12,  1734.973267, 346.734009, -55.393040, 'Theresa'),
(5697, 13,  1706.992676, 324.664032, -55.392391, 'Theresa'),
(5697, 14,  1698.429199, 334.720062, -60.482483, 'Theresa'),
(5697, 15,  1662.228149, 353.675415, -60.742798, 'Theresa'),
(5697, 16,  1678.154785, 345.241730, -60.481709, 'Theresa'),
(5697, 17,  1667.451416, 349.544647, -60.740757, 'Theresa'),
(5697, 18,  1655.74, 367.394, -60.7665, 'Theresa'),
(36217, 1,  1443.416260, 402.955078, -85.267242, 'Overseer Kraggosh'),
(36217, 2,  1441.223755, 394.899078, -85.271645, 'Overseer Kraggosh'),
(36217, 3,  1432.243774, 392.635132, -85.268372, 'Overseer Kraggosh'),
(36217, 4,  1431.118286, 397.971283, -85.262215, 'Overseer Kraggosh'),
(36217, 5,  1438.026, 403.8299, -85.26257, 'Overseer Kraggosh'),
(5662, 1,  1685.04, 417.976, -62.2986, 'Sergeant Houser'),
(5662, 2,  1694.53, 418.755, -62.2986, 'Sergeant Houser'),
(5662, 3,  1704.5, 421.202, -62.3554, 'Sergeant Houser'),
(5662, 4,  1693.69, 418.24, -62.2982, 'Sergeant Houser');

-- Delete Sergeant Housers waypoints from waypoint_data as these moved to waypoints table so WP can be paused by SAI
DELETE FROM `waypoint_data` WHERE `id`=384350;
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=38435;
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid`=38435;
