--
DELETE FROM `creature` WHERE `id` = 29498;
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (29500) AND `accessory_entry` IN (29498);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(29500,29498,0,1,'Brunnhildar Warbear',8,0);

DELETE FROM `creature` WHERE `id` = 30175;
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (30174) AND `accessory_entry` IN (30175);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(30174,30175,0,1,'Hyldsmeet Warbear',8,0);
