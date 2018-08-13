SET @CGUID := 1100002;
UPDATE creature SET SpawnMask = 1 WHERE guid BETWEEN @CGUID+0 AND @CGUID+1000;

SET @GOGUID := 20000015;
UPDATE gameobject SET SpawnMask = 1 WHERE guid BETWEEN @GOGUID+0 AND @GOGUID+100;

UPDATE creature_template SET unit_class = 1, faction = 2799 WHERE entry = 131326;
UPDATE creature_template SET unit_class = 1, faction = 2799 WHERE entry = 132032;
UPDATE creature_template SET unit_class = 1, faction = 2875 WHERE entry = 133407;
UPDATE creature_template SET unit_class = 1, faction = 2799 WHERE entry = 132026;
UPDATE creature_template SET unit_class = 1, faction = 2801 WHERE entry = 131413;
UPDATE creature_template SET unit_class = 1, faction = 2799 WHERE entry = 133695;
UPDATE creature_template SET unit_class = 1, faction = 83 WHERE entry = 133185;
UPDATE creature_template SET unit_class = 1, faction = 2799 WHERE entry = 132027;
UPDATE creature_template SET unit_class = 1, faction = 83 WHERE entry = 133186;
UPDATE creature_template SET unit_class = 1, faction = 35 WHERE entry = 126306;
UPDATE creature_template SET gossip_menu_id = 22001, unit_class = 1, faction = 2799, npcflag = 1 WHERE entry = 132024;
UPDATE creature_template SET gossip_menu_id = 22000, unit_class = 1, faction = 2802, npcflag = 1 WHERE entry = 132029;
