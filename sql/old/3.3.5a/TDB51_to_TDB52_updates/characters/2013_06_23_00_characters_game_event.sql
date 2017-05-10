-- Delete no longer used data from Characters Database
DELETE FROM `game_event_save` WHERE `eventEntry` BETWEEN 33 AND 47;
DELETE FROM `game_event_condition_save` WHERE `eventEntry` BETWEEN 33 AND 47;
