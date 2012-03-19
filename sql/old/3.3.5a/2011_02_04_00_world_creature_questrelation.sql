-- Fix starting NPC for quest "Scrying Goggles? No Problem!"
DELETE FROM `creature_questrelation` WHERE `quest`=8578;  -- Delete existing incorrect start point
