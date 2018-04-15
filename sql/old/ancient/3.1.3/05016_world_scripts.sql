UPDATE creature_template SET ScriptName='npc_kanati' WHERE entry=10638;

DELETE FROM script_waypoint WHERE entry=10638;
INSERT INTO script_waypoint VALUES
(10638, 0, -4903.521973, -1368.339844, -52.611, 5000, 'SAY_KAN_START'),
(10638, 1, -4906.004395, -1367.048096, -52.611, 0, '');

