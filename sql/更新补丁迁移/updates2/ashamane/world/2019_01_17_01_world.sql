-- 
UPDATE `creature_addon` SET `visibilityDistanceType`=3 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (SELECT `entry` FROM `creature_template_addon` WHERE `visibilityDistanceType`=3));
UPDATE `creature_addon` SET `visibilityDistanceType`=4 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (SELECT `entry` FROM `creature_template_addon` WHERE `visibilityDistanceType`=4));
UPDATE `creature_addon` SET `visibilityDistanceType`=5 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (SELECT `entry` FROM `creature_template_addon` WHERE `visibilityDistanceType`=5));
