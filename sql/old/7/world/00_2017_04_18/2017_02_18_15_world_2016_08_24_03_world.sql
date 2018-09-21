-- Scarlet Mine Car must have UNIT_FIELD_FLAGS UNIT_FLAG_IMMUNE_TO_PC
UPDATE `creature_template` SET `unit_flags`= `unit_flags`| 520 WHERE `entry`= 28817;
