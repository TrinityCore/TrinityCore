-- Kalu'ak Fishing Derby start time fix ( http://old.wowhead.com/event=424 )
-- Closes https://github.com/TrinityCore/TrinityCore/issues/4009

UPDATE `game_event` SET `start_time` = '2011-01-01 13:00:00' WHERE (`eventEntry`=63);
UPDATE `game_event` SET `start_time` = '2011-01-01 14:00:00' WHERE (`eventEntry`=64);