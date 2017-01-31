-- Blackened Naaru Silver proc cooldown
DELETE FROM `spell_proc_event` WHERE `entry`=45355;
INSERT INTO `spell_proc_event`(`entry`,`schoolmask`,`spellfamilyname`,`spellfamilymask0`,`spellfamilymask1`,`spellfamilymask2`,`procflags`,`procex`,`ppmrate`,`customchance`,`cooldown`) VALUES
(45355,0,0,0,0,0,0,0,0,0,45);