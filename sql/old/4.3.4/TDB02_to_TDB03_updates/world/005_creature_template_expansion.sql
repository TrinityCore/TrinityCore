-- Update exp values for all Npcs between Level 81 and 88 which are not spawned in WotLK Content
UPDATE `creature_template` ct LEFT JOIN `creature` c ON ct.`entry` = c.`id` SET ct.`exp` = 3 WHERE `exp` = 0 AND c.`map` NOT IN (571, 249, 575, 576, 578, 533, 595, 608, 604, 602, 599, 601, 619, 615, 600, 616, 603, 571, 649, 650, 631, 632, 668, 658, 724) AND ct.`minlevel` BETWEEN 81 AND 88;
