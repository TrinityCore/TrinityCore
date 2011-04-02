-- Hover Disk
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (30234,30248);
INSERT INTO `vehicle_template_accessory` (entry,accessory_entry,seat_id,minion,description) VALUES 
(30234,30245,0,0,'Hover Disk - Nexus Lord'),
(30248,30249,0,0,'Hover Disk - Scion of Eternity');