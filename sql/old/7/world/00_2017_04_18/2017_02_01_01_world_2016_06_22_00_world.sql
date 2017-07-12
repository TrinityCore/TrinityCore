--
DELETE FROM `creature_queststarter` WHERE `quest` IN (SELECT `quest` FROM `game_event_creature_quest`);
