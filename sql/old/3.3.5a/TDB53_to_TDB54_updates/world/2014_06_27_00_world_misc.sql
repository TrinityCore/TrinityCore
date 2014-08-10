--
UPDATE `creature` SET `equipment_id`=0 WHERE `equipment_id`=86 AND `id`=24484;
DELETE FROM `creature_addon` WHERE `guid`=97892;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=-126866 AND `source_type`=0 AND `id` IN (7,15);
