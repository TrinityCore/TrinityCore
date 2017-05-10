-- Fixes the Dragonmaw Race: Wing Commander Ichman creature_queststarter mistake
UPDATE creature_template SET npcflag=3 WHERE entry=23345;
DELETE FROM creature_queststarter WHERE quest=11069;
INSERT INTO creature_queststarter VALUES (23345,11069);
