-- Update Dying Blood Elf to 1 HP
UPDATE `creature` SET `curhealth`=1 WHERE `id`=16601; 
UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry`=16601;
