-- fix "Val'anyr, Hammer of Ancient Kings" to properly provide shields from Earth Shield charges and Glyph of Holy Light heals (as well as others)
DELETE FROM `spell_proc_event` WHERE `entry`=64411;
INSERT INTO `spell_proc_event` (`entry`,`procFlags`) VALUES
(64411,0x00044400);
