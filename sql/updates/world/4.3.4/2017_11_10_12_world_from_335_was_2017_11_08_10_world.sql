-- 
UPDATE `creature_addon` SET `mount`=2404 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=28611);
