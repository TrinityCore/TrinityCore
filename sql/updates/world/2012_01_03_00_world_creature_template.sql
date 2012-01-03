-- [Q] Garments of Darkness (5650)
SET @ENTRY_KEL := 12428; -- Deathguard Kel (has to be +8 so 36872)

UPDATE `creature_template` SET `unit_flags`=`unit_flags`|36872 WHERE `entry` IN (@ENTRY_KEL);
