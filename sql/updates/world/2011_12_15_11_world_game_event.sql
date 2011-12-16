-- Stranglethorn Fishing Extravaganza start time fix ( http://old.wowhead.com/event=301 )
-- Closes https://github.com/TrinityCore/TrinityCore/issues/4008

UPDATE `game_event` SET `start_time` = '2011-01-01 14:00:00' WHERE `eventEntry` IN (14, 15, 62);
UPDATE `game_event` SET `description` = 'Stranglethorn Fishing Extravaganza Announce' WHERE (`eventEntry`=14);
UPDATE `game_event` SET `description` = 'Stranglethorn Fishing Extravaganza Fishing Pools' WHERE (`eventEntry`=15);
UPDATE `game_event` SET `description` = 'Stranglethorn Fishing Extravaganza Turn-ins' WHERE (`eventEntry`=62);