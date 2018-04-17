UPDATE creature SET spawntimesecs = 300 WHERE map = 1220 AND id NOT IN (SELECT entry FROM creature_template WHERE rank != 0);
