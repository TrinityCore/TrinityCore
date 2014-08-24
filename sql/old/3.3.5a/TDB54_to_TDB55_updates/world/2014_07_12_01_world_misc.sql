DELETE FROM `smart_scripts` WHERE `entryorguid`=2755 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2755, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 10000, 15000, 11, 4938, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myzrael - In Combat - Cast Myzrael Earthquake'),
(2755, 0, 1, 0, 2, 0, 100, 0, 0, 75, 60000, 90000, 11, 10388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myzrael - At 75% Hp  - Cast Summon Prismatic Exile'),
(2755, 0, 2, 0, 2, 0, 100, 0, 0, 50, 60000, 90000, 11, 10388, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myzrael - At 50% Hp  - Cast Summon Prismatic Exile'),
(2755, 0, 3, 0, 2, 0, 100, 0, 0, 25, 60000, 90000, 11, 4937, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myzrael - At 25% Hp  - Cast Summon Prismatic Exiles'),
(2755, 0, 4, 5, 54, 0, 100, 1, 0, 0, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Myzrael - On Spawn  - Say 0'),
(2755, 0, 5, 0, 61, 0, 100, 1, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Myzrael - Linked with Previous event  - Store Targetlist'),

(2755, 0, 6, 0, 52, 0, 100, 1, 0, 2755, 0, 0, 1, 1, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myzrael - On Text Over Line 0  - Say Line 1'),
(2755, 0, 7, 8, 52, 0, 100, 1, 1, 2755, 0, 0, 1, 2, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Myzrael - On Text Over Line 1  - Say Line 2'),
(2755, 0, 8, 0, 61, 0, 100, 1, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Myzrael - Linked with Previous event  - Attack');

DELETE FROM `creature_text` WHERE `entry`=2755;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(2755, 0, 0, 'What?  $n, you served me well, but...', 12, 0, 0, 0, 0, 0, 'Myzrael', 842),
(2755, 1, 0, 'Why have you summoned me so soon?  I haven''t yet reached my full power!', 12, 0, 0, 0, 0, 0, 'Myzrael', 843),
(2755, 2, 0, 'No matter.  You were a fool to help me, and now you will pay!', 12, 0, 0, 0, 0, 0, 'Myzrael', 844);

-- Myzreal is only meant to spawn for 10 mins
UPDATE `event_scripts` SET `datalong2`=600000 WHERE  `id`=420;
