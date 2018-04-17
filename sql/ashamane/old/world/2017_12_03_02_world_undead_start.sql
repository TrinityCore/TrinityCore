DELETE FROM creature WHERE guid = 303152;
UPDATE creature SET modelid = 0 WHERE guid = 192768;
UPDATE creature_template SET modelid1 = 67149, scriptname = "npc_agatha", InhabitType = 4 WHERE entry = 49044;
UPDATE creature_template_addon SET auras = "" WHERE entry = 49044;
