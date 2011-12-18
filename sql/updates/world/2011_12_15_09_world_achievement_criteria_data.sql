-- Removes wrong restriction
-- Closes https://github.com/TrinityCore/TrinityCore/issues/4038

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=3882 AND `type`=16;