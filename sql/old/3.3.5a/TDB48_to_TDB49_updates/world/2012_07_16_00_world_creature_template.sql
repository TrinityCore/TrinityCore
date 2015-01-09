-- Fix the damage for Wretched mobs in Magisters' Terrace
UPDATE `creature_template` SET `dmg_multiplier`=0.6 WHERE `entry` IN (24688, 24689, 24690);
