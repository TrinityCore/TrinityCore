-- Critter Fire Beetle should not give reputation with Honor Hold when killed
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` = 9699;
