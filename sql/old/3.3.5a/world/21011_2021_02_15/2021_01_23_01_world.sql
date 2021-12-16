--
UPDATE `creature` SET `dynamicflags` = `dynamicflags` &~ 8 WHERE `dynamicflags` & 8;
UPDATE `creature_template` SET `dynamicflags` = `dynamicflags` &~ 8 WHERE `dynamicflags` & 8;
