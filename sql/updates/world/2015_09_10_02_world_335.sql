-- The Crown - remove UNIT_FLAG_IMMUNE_TO_PC flag
UPDATE `creature_template` SET `unit_flags` = 32832 WHERE `entry` = 18168;