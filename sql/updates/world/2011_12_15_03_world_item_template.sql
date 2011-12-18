-- The Diary of High General Abbendis text fix by nelegalno
-- Closes https://github.com/TrinityCore/TrinityCore/issues/4324

UPDATE `item_template` SET `PageText` = 3092 WHERE `entry` = 37540;