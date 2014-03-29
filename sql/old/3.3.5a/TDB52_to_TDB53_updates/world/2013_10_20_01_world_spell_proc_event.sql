-- Fixes Ormorok the Tree Shaper Spell Reflect
DELETE FROM `spell_proc_event` WHERE (`entry` = '47981');
INSERT INTO `spell_proc_event` (`entry`,`procEx`) VALUES ('47981','2048');
