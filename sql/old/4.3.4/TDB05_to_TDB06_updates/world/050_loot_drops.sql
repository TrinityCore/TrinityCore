-- Quest #361 is flagged as deprecated / obsolete, the item that starts it should not drop anymore
DELETE FROM creature_loot_template WHERE item = 2839;
