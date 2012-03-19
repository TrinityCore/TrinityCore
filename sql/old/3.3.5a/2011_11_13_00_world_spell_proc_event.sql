-- Spell proc cooldown for Item - Hunter T9 4P Bonus
DELETE FROM `spell_proc_event` WHERE `entry`=67151;
INSERT INTO `spell_proc_event` (`entry`,`Cooldown`) VALUES
(67151,45);
