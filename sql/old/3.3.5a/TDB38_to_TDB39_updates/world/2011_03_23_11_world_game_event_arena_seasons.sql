-- Delete wrongly assigned Arena Seasons game events
DELETE FROM `game_event_arena_seasons` WHERE `eventEntry`=53 AND `season`=1; -- Call to Arms: Strand of the Ancients!
DELETE FROM `game_event_arena_seasons` WHERE `eventEntry`=54 AND `season`=2; -- Call to Arms: Isle of Conquest!
