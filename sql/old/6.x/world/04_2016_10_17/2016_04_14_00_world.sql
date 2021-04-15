-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN (39859, 38821, 34527, 35845);
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128 WHERE `entry` IN (39859, 38821, 34527, 35845);
