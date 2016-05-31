-- This creature is only supposed to be summoned.
DELETE FROM `creature` WHERE `id`=4196;
DELETE FROM `creature_addon` WHERE `guid` IN (14343,14342,14341,14340,14339,14338,14337);
