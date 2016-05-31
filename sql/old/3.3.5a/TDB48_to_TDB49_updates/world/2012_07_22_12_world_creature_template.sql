-- Fix Night Elf Corpse (16804) so it can't be attacked
UPDATE `creature_template` SET `unit_flags`=768, `dynamicflags`=40 WHERE `entry` = 16804;
