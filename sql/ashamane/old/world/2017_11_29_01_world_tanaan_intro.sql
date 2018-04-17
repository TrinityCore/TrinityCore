UPDATE creature_template SET inhabitType = 3, hoverheight = 3 WHERE entry = 78333;

DELETE FROM creature_template_addon WHERE entry = 78333;
INSERT INTO creature_template_addon (entry, bytes1) VALUES (78333, 33554432);

UPDATE quest_template_addon SET specialflags = specialflags | 2 WHERE id = 34420;
