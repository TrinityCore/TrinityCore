-- Update flags_extra 2 to 0 (civilian to none)
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ 2 WHERE `Entry` = 10928;
