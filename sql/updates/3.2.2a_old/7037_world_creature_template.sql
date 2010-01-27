-- Usually creature_template changes MUST GO to TDB
-- However, this is the one exception ... the GM waypoint
-- DO NOT REMOVE THIS FROM CORE REPO this is part of the core :)
-- Set Waypoint (Only GM can see it) so health is 1 from levels 1 - 80
UPDATE `creature_template` SET `maxlevel`=80,`Health_mod`=0.0125 WHERE `entry`=1;
-- Set Waypoint (Only GM can see it) so it can also show altitude
UPDATE `creature_template` SET InhabitType=7 WHERE `entry`=1;
