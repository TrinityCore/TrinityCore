-- Fix quest 28724 Iverron's Antidote Moonpetal Lily should not be interactible without quest
UPDATE `gameobject_template_addon` SET `flags` = 4 WHERE `entry` = 207346;
