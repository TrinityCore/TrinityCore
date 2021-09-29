--
UPDATE `creature_template` SET `unit_flags2` = `unit_flags2` &~ 0x00200000 WHERE `unit_flags2` & 0x00200000;
