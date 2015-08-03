-- Set 10 sec delay on platforms where boss gets Temporary Electrical Charge
UPDATE `waypoint_data` SET `delay`=10000 WHERE `id`=1269810 AND `point` IN (2, 5, 11, 14);

-- Cast self Charge Up to get Temporary Electrical Charge
UPDATE `waypoint_data` SET `action`=12698101 WHERE `id`=1269810 AND `point` IN (5, 14);

-- Remove aura Temporary Electrical Charge
UPDATE `waypoint_data` SET `action`=12698102 WHERE `id`=1269810 AND `point` IN (2, 3, 4, 11, 12, 13);
