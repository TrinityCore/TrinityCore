-- Remove speed hack from Living Poison and disable movement flag updates for it
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 512, `speed_run`= 1.42857 WHERE `entry`= 16027;
-- Delete unneeded spawn groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 16082 AND `summonerType`= 0;
-- Delete unneeded waypoints
DELETE FROM `waypoint_data` WHERE `id` IN (160270, 160271, 160272);
