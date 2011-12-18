-- Fix NPCs falling underground when killed by nelegalno
-- Closes https://github.com/TrinityCore/TrinityCore/issues/4236

UPDATE `creature_template` SET `InhabitType` = 3 WHERE (`entry` = 5936 OR `entry` = 24899);