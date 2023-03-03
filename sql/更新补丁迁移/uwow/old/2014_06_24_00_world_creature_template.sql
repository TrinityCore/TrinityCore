-- SELECT * FROM `creature_template` WHERE `dynamicflags` &1 > 0;
UPDATE `creature_template` SET `dynamicflags` = `dynamicflags` &~ 1  WHERE `dynamicflags` &1 > 0;