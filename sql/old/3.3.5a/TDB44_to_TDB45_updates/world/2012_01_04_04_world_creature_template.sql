-- [Q] Garments of the Moon (5621) and Garments of the Light (5625)
SET @ENTRY_SHAYA := 12429; -- Sentinel Shaya
SET @ENTRY_DOLF := 12427; -- Mountaineer Dolf
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|8 WHERE `entry` IN (@ENTRY_SHAYA, @ENTRY_DOLF);

-- [Q] Garments of Darkness (5650)
SET @ENTRY_KEL := 12428; -- Deathguard Kel (has to be +8 so in total 36872)
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|8|4096|32768 WHERE `entry` IN (@ENTRY_KEL);
