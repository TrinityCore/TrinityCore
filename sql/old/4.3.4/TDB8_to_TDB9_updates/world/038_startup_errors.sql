UPDATE `creature_template` SET `npcflag` = `npcflag`|1048576 WHERE `entry` IN (34989, 34988, 30567, 30590, 50668, 34955);

DELETE FROM `battlemaster_entry` WHERE `entry` IN (34983,34985,34987,34973,40413);
INSERT INTO `battlemaster_entry` (`entry`,`bg_template`) VALUES
(34983,32),(34985,32),(34987,32),(34973,32),(40413,32);
