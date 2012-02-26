-- Fix object states for icc and ulduar teleporter

UPDATE gameobject_template SET data20 = 0 WHERE scriptname = "icecrown_citadel_teleport";
UPDATE gameobject_template SET data19 = 0 WHERE scriptname = "icecrown_citadel_teleport";
UPDATE gameobject_template SET data17 = 0 WHERE scriptname = "icecrown_citadel_teleport";
UPDATE gameobject_template SET data13 = 0 WHERE scriptname = "icecrown_citadel_teleport";
UPDATE gameobject_template SET data3 = 10368 WHERE scriptname = "icecrown_citadel_teleport";
UPDATE gameobject_template SET data1 = 9593 WHERE scriptname = "icecrown_citadel_teleport";
UPDATE gameobject_template SET type = 2 WHERE scriptname = "icecrown_citadel_teleport";
UPDATE gameobject_template SET flags = 0 WHERE scriptname = "icecrown_citadel_teleport";
UPDATE gameobject_template SET faction = 0 WHERE scriptname = "icecrown_citadel_teleport";


UPDATE gameobject_template SET data20 = 0 WHERE scriptname = "ulduar_teleporter";
UPDATE gameobject_template SET data19 = 0 WHERE scriptname = "ulduar_teleporter";
UPDATE gameobject_template SET data17 = 0 WHERE scriptname = "ulduar_teleporter";
UPDATE gameobject_template SET data13 = 0 WHERE scriptname = "ulduar_teleporter";
UPDATE gameobject_template SET data3 = 10368 WHERE scriptname = "ulduar_teleporter";
UPDATE gameobject_template SET data1 = 9593 WHERE scriptname = "ulduar_teleporter";
UPDATE gameobject_template SET type = 2 WHERE scriptname = "ulduar_teleporter";
UPDATE gameobject_template SET flags = 0 WHERE scriptname = "ulduar_teleporter";
UPDATE gameobject_template SET faction = 0 WHERE scriptname = "ulduar_teleporter";

