UPDATE quest_template SET NextQuestIdChain = 28850 WHERE id = 14157;
UPDATE quest_template SET PrevQuestId = 14157, NextQuestIdChain = 14154 WHERE id = 28850;
UPDATE quest_template SET PrevQuestId = 28850, NextQuestIdChain = 26129 WHERE id = 14154;
UPDATE quest_template SET PrevQuestId = 14154 WHERE id = 26129;

UPDATE quest_template SET NextQuestIdChain = 14214 WHERE id = 14204;
UPDATE quest_template SET PrevQuestId = 14204, NextQuestIdChain = 14293 WHERE id = 14214;
UPDATE quest_template SET PrevQuestId = 14214 WHERE id = 14293;

UPDATE quest_template SET NextQuestIdChain = 14218 WHERE id = 14212;
UPDATE quest_template SET PrevQuestId = 14212, NextQuestIdChain = 14221 WHERE id = 14218;
UPDATE quest_template SET PrevQuestId = 14218, NextQuestIdChain = 14222 WHERE id = 14221;
UPDATE quest_template SET PrevQuestId = 14221 WHERE id = 14222;

DELETE FROM waypoints WHERE entry = 35905;
INSERT INTO waypoints (entry, pointid, position_x, position_y,position_z,point_comment) VALUES
(35905, 1,-1797.525261, 1403.351074, 19.835711, "King Greymane's Waypoint"),
(35905, 2,-1798.400166, 1395.755859, 19.903023, "King Greymane's Waypoint"),
(35905, 3,-1793.752441, 1382.324219, 19.842448, "King Greymane's Waypoint"),
(35905, 4,-1781.656494, 1369.981812, 19.896338, "King Greymane's Waypoint"),
(35905, 5,-1763.633545, 1366.066284, 19.709974, "King Greymane's Waypoint"),
(35905, 6,-1709.085938, 1347.840820, 19.782467, "King Greymane's Waypoint"),
(35905, 7,-1703.552856, 1346.945923, 21.061985, "King Greymane's Waypoint"),
(35905, 8,-1680.925659, 1343.793091, 15.135222, "King Greymane's Waypoint"),
(35905, 9,-1669.763306, 1349.344360, 15.135222, "King Greymane's Waypoint"),
(35905, 10,-1662.996826, 1349.788574, 15.135222, "King Greymane's Waypoint"),
(35905, 11,-1665.336548, 1360.432373, 15.135222, "King Greymane's Waypoint"),
(35905, 12,-1674.381958, 1363.047241, 15.135222, "King Greymane's Waypoint"),
(35905, 13,-1704.826050, 1350.664062, 19.896397, "King Greymane's Waypoint"),
(35905, 14,-1744.681152, 1366.752930, 19.879541, "King Greymane's Waypoint"),
(35905, 15,-1761.122803, 1389.081421, 19.940752, "King Greymane's Waypoint"),
(35905, 16,-1769.649170, 1409.496704, 19.782454, "King Greymane's Waypoint"),
(35905, 17,-1771.756470, 1435.351074, 19.835711, "King Greymane's Waypoint");

SET @ACTION = 359050;

DELETE FROM waypoint_data WHERE id = 359050;
INSERT INTO waypoint_data (id, point, position_x, position_y, position_z, orientation, delay, move_flag, action, action_chance,wpguid) VALUES

(359050, 1,-1797.525261, 1403.351074, 19.835711, 5.002352, 0, 1, @ACTION, 100, 0),
(359050, 2,-1798.400166, 1395.755859, 19.903023, 5.088977, 0, 1, @ACTION, 100, 0),
(359050, 3,-1793.752441, 1382.324219, 19.842448, 5.088977, 0, 1, @ACTION, 100, 0),
(359050, 4,-1781.656494, 1369.981812, 19.896338, 5.676226, 0, 1, @ACTION, 100, 0),
(359050, 5,-1763.633545, 1366.066284, 19.709974, 8.883226, 0, 1, @ACTION, 100, 0),
(359050, 6,-1709.085938, 1347.840820, 19.782467, 6.122851, 0, 1, @ACTION, 100, 0),
(359050, 7,-1703.552856, 1346.945923, 21.061985, 6.122851, 0, 1, @ACTION, 100, 0),
(359050, 8,-1680.925659, 1343.793091, 15.135222, 6.122851, 0, 1, @ACTION, 100, 0),
(359050, 9,-1669.763306, 1349.344360, 15.135222, 6.092476, 0, 1, @ACTION, 100, 0),
(359050, 10,-1662.996826, 1349.788574, 15.135222, 0.999540, 0, 1, @ACTION, 100, 0),
(359050, 11,-1665.336548, 1360.432373, 15.135222, 2.377665, 0, 1, @ACTION, 100, 0),
(359050, 12,-1674.381958, 1363.047241, 15.135222, 2.996415, 0, 1, @ACTION, 100, 0),
(359050, 13,-1704.826050, 1350.664062, 19.896397, 3.419415, 0, 1, @ACTION, 100, 0),
(359050, 14,-1744.681152, 1366.752930, 19.879541, 2.757915, 0, 1, @ACTION, 100, 0),
(359050, 15,-1761.122803, 1389.081421, 19.940752, 2.087415, 0, 1, @ACTION, 100, 0),
(359050, 16,-1769.649170, 1409.496704, 19.782454, 1.850041, 0, 1, @ACTION, 100, 0),
(359050, 17,-1771.756470, 1435.351074, 19.835711, 5.002352, 0, 1, @ACTION, 100, 0);

DELETE FROM waypoint_scripts WHERE datalong = 359050;
INSERT INTO waypoint_scripts (id, delay, command, datalong, datalong2, dataint, x, y, z, o, guid) VALUES
(@ACTION, 0, 20, 359050, 0, 0, 0, 0, 0, 0, @ACTION );
