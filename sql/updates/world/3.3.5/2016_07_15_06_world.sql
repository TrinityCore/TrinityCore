--
DELETE FROM `creature` WHERE `id`=2435;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(11004, 2435, 0, 1, 1, 0, 1, -740.538, -525.298, 21.9343, 3.9523, 3600, 0, 0, 1163, 0, 0, 0, 0, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=2435;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2435, 0, 0, 0, 11, 0, 100, 1, 5000, 5000, 5000, 5000, 53, 0, 2435, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier - On Spawn - Start Waypoint'),
(2435, 0, 1, 0, 40, 0, 100, 0, 11, 0, 0, 0, 1, 0, 1000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier - On WP 11 reached - Say Line 0'),
(2435, 0, 2, 3, 40, 0, 100, 0, 12, 2435, 0, 0, 54, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier - On WP 12 reached - Pause Waypoint'),
(2435, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier - On WP 12 reached - Say Line 1'),
(2435, 0, 4, 0, 52, 0, 100, 0, 1, 2435, 0, 0, 1, 2, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier - On Text 1 Over - Say Line 2'),
(2435, 0, 5, 0, 52, 0, 100, 0, 2, 2435, 0, 0, 1, 3, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier - On Text 2 Over - Say line 3'),
(2435, 0, 6, 7, 52, 0, 100, 0, 3, 2435, 0, 0, 1, 4, 500, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier  - On Text 3 Over  - Say line 4'),
(2435, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 243500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier - On Text 3 Over – Start Script'),
(2435, 0, 8, 9, 52, 0, 100, 0, 4, 2435, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier  - On Text 4 Over  - Say line 5'),
(2435, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Southshore Crier - On Text 4 Over - Kill self');

DELETE FROM `smart_scripts` WHERE `entryorguid`=243500;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(243500, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -858.214, -471.187, 13.3554, 0.58591, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 1, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -864.901, -472.452, 13.3564, 0.58591, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -862.522, -476.413, 13.3564, 0.58591, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -861.232, -542.347, 9.33058, 0.58591, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 4, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -849.912, -536.618, 10.717, 0.30081, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 5, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -842.906, -536.79, 12.5283, 6.23677, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 6, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -843.281, -526.083, 11.1464, 0.819482, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 7, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -848.99, -517.981, 12.1924, 0.819482, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 8, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -867.763, -516.11, 11.3357, 0.819482, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 9, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -855.221, -518.702, 11.547, 0.819482, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 10, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -879.868, -538.859, 7.67274, 0.819482, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 11, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -877.552, -561.351, 11.0384, 0.819482, 'Southshore Crier - On Script - Summon Shadowy Assassin'),
(243500, 9, 12, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 12, 2434, 4, 15000, 0, 0, 0, 8, 0, 0, 0, -840.952, -505.281, 14.4908, 0.819482, 'Southshore Crier - On Script - Summon Shadowy Assassin');

DELETE FROM `waypoints` WHERE `entry`=2435;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(2435, 1, -745.74, -530.658, 21.0302, 'Southshore Crier'),
(2435, 2, -749.623, -536.482, 19.8807, 'Southshore Crier'),
(2435, 3, -749.831, -542.323, 19.0502, 'Southshore Crier'),
(2435, 4, -751.399, -545.452, 18.7756, 'Southshore Crier'),
(2435, 5, -751.399, -545.452, 18.7756, 'Southshore Crier'),
(2435, 6, -760.746, -546.233, 18.1427, 'Southshore Crier'),
(2435, 7, -771.772, -545.382, 17.7874, 'Southshore Crier'),
(2435, 8, -787.449, -540.515, 17.7064, 'Southshore Crier'),
(2435, 9, -803.583, -531.155, 15.9356, 'Southshore Crier'),
(2435, 10, -815.697, -524.158, 14.4849, 'Southshore Crier'),
(2435, 11, -824.224, -522.261, 13.1434, 'Southshore Crier'),
(2435, 12, -840.92, -524.92, 11.2505, 'Southshore Crier'),
(2435, 13, -857.888, -532.908, 9.43952, 'Southshore Crier'),
(2435, 14, -870.759, -539.774, 8.12229, 'Southshore Crier'),
(2435, 15, -880.055, -540.594, 7.56718, 'Southshore Crier'),
(2435, 16, -898.525, -541.205, 6.87974, 'Southshore Crier'),
(2435, 17, -901.819, -547.256, 6.87974, 'Southshore Crier'),
(2435, 18, -903.291, -555.882, 6.87974, 'Southshore Crier');

DELETE FROM `creature_text` WHERE `entry`=2435;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2435, 0, 0, "Hear ye! Hear ye! *pant pant* Be warned citizens of Southshore: assassins are heading to our fair town!", 12, 7, 100, 0, 0, 0, 620, 0, "Southshore Crier"),
(2435, 1, 0, "Help me! Help! Assassins in the hills! To arms! To arms!", 14, 7, 100, 22, 0, 0, 619, 0, "Southshore Crier"),
(2435, 2, 0, "Guards to your posts! They must be after the Magistrate again. He must be protected! They could come from any direction!", 12, 7, 100, 1, 0, 0, 621, 0, "Southshore Crier"),
(2435, 3, 0, "The Southshore Crier grabs the back of his neck and his eyes go wide.", 16, 0, 100, 0, 0, 0, 623, 0, "Southshore Crier"),
(2435, 4, 0, "Assassins... save... th... Magistraaa...", 12, 7, 100, 65, 0, 0, 626, 0, "Southshore Crier"),
(2435, 5, 0, "Southshore Crier dies.", 16, 0, 100, 0, 0, 0, 0, 0, "Southshore Crier");
