-- 
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (18201));
DELETE FROM `creature` WHERE `id` IN (18201);
