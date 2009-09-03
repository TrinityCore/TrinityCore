DELETE FROM script_waypoint WHERE entry=18731;
INSERT INTO script_waypoint VALUES
(18731, 0, -157.366, 2.177, 8.073, 0, ''),
(18731, 1, -172.266, -18.280, 8.073, 0, ''),
(18731, 2, -171.051, -38.748, 8.073, 0, ''),
(18731, 3, -170.718, -59.436, 8.073, 0, ''),
(18731, 4, -156.659, -72.118, 8.073, 0, ''),
(18731, 5, -142.292, -59.423, 8.073, 0, ''),
(18731, 6, -141.779, -38.972, 8.073, 0, ''),
(18731, 7, -142.922, -18.950, 8.073, 0, ''),
(18731, 8, -157.366, 2.177, 8.073, 0, '');

DELETE FROM script_waypoint WHERE entry=2768 AND pointid IN (0, 18);
INSERT INTO script_waypoint VALUES
(2768, 0, -2077.73, -2091.17, 9.49, 0, ''),
(2768, 18, -2077.73, -2091.17, 9.49, 0, '');

UPDATE creature_template SET ScriptName='npc_tooga' WHERE entry=5955;
