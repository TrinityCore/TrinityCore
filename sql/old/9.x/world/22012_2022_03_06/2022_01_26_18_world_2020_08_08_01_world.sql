-- Change respawn time of Lordaeron Footsoldier to correct (Source: https://www.youtube.com/watch?v=ty7dzVLHCOE)
UPDATE `creature` SET `spawntimesecs` = 45 WHERE `id` = 31254;
