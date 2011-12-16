-- Remove empty EAI Script call from the following entries
-- Closes https://github.com/TrinityCore/TrinityCore/issues/4338

UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (30243,30632);