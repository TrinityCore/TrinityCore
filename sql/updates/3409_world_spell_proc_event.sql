DELETE FROM `spell_proc_event` WHERE `entry` IN (31878, 31877, 31876, 46913, 46914, 46915);

INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(31876, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(31877, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(31878, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(46913, 0, 4, 0, 1024, 0, 0, 0, 0, 0, 0),
(46914, 0, 4, 0, 1024, 0, 0, 0, 0, 0, 0),
(46915, 0, 4, 0, 1024, 0, 0, 0, 0, 0, 0);
