UPDATE gameobject_template SET faction=1375 WHERE entry IN (184203, 184204, 184205);
UPDATE gameobject_template SET Scriptname='go_bridge_console' WHERE entry=184568;

DELETE FROM gameobject WHERE id IN (184205, 184204, 184203, 184568);
INSERT INTO gameobject (id, map, spawnMask, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state) VALUES
(184568, 548, 1, 47.7806, -582.962, 2.88104, 3.14159, 0, 0, 1, 0, 0, 1, 1),
(184203, 548, 1, 26.198, -654.59, 15.5, 3.14159, 0, 0, 1, 0, 0, 1, 1),
(184204, 548, 1, 26.198, -654.59, 15.5, 3.14159, 0, 0, 1, 0, 0, 1, 1),
(184205, 548, 1, 26.198, -654.59, 15.5, 3.14159, 0, 0, 1, 0, 0, 1, 1);