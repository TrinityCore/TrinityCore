UPDATE creature_template SET ScriptName='' WHERE entry=13936;

DELETE FROM areatrigger_scripts WHERE entry=3066;
INSERT INTO areatrigger_scripts VALUES (3066,'at_ravenholdt');

DELETE FROM script_waypoint WHERE entry=16812;
INSERT INTO script_waypoint VALUES
(16812, 0, -10868.260, -1779.836, 90.476, 2500, 'Open door, begin walking'),
(16812, 1, -10875.585, -1779.581, 90.478, 0, ''),
(16812, 2, -10887.447, -1779.258, 90.476, 0, ''),
(16812, 3, -10894.592, -1780.668, 90.476, 0, ''),
(16812, 4, -10895.015, -1782.036, 90.476, 2500, 'Begin Speech after this'),
(16812, 5, -10894.592, -1780.668, 90.476, 0, 'Resume walking (back to spawn point now) after speech'),
(16812, 6, -10887.447, -1779.258, 90.476, 0, ''),
(16812, 7, -10875.585, -1779.581, 90.478, 0, ''),
(16812, 8, -10868.260, -1779.836, 90.476, 5000, 'close door'),
(16812, 9, -10866.799, -1780.958, 90.470, 2000, 'Summon mobs, open curtains');
