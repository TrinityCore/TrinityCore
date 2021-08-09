-- Fix questgiver flag of two npc in the alliance main questline

UPDATE `creature_template` SET `npcflag` = 2 WHERE (entry = 126158);
UPDATE `creature_template` SET `npcflag` = 2 WHERE (entry = 125342);