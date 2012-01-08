-- Add Send Script Event (17841) summon 3 triggers
DELETE FROM `event_scripts` WHERE `id` = 17841;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('17841', '0', '10', '27273', '10000', '0', '285.6', '-357.5', '91.0833', '5.75959'),
('17841', '3', '10', '27273', '10000', '0', '307', '-357.5', '91.0833', '6.02139'),
('17841', '6', '10', '27273', '10000', '0', '285.6', '-357.5', '91.0833', '5.75959');
