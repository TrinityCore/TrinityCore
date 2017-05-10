UPDATE `creature` SET `equipment_id`=0 WHERE `id` = 2057;
DELETE FROM `creature_equip_template` WHERE `entry` = 2057;
