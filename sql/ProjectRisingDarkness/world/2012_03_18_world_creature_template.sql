UPDATE creature_template SET scriptname = '' WHERE entry IN (36794);
UPDATE creature_template SET scriptname = "pitofsaron_start" WHERE entry IN (36990, 36993);
UPDATE creature_template SET MovementType = 2 where entry IN (36788, 367880);
DELETE FROM creature_addon where guid = 201746;