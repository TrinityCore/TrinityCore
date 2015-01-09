UPDATE `creature_template` SET `npcflag`=`npcflag`|0x100000 WHERE `entry` IN (16711, 17506, 17507);

DELETE FROM `battlemaster_entry` WHERE `entry` IN (34955, 35008);
INSERT INTO `battlemaster_entry` (`entry`, `bg_template`) VALUES
(34955, 32),
(35008, 32);
