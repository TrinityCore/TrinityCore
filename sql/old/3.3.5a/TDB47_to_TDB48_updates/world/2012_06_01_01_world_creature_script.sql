-- Add Generic Harpoon gun script to prevent movement
UPDATE `creature_template` SET `ScriptName`= 'npc_generic_harpoon_cannon' WHERE `entry` IN (27714,30066,30337);
