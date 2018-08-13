UPDATE creature_template SET faction = 7 WHERE faction = 0; 
UPDATE creature_template SET unit_class = 1 WHERE unit_class = 0;
UPDATE creature_template SET minlevel = 1, maxlevel = 1 WHERE minlevel = 0 AND maxlevel = 0;
