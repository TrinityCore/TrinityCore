-- Removed useless event_flags 6, added CMC flag since he uses caster AI type https://youtu.be/tEAZeDdtK-E?t=89
-- Interrupt Shadow Bolt so he can cast second spell
UPDATE `smart_scripts` SET `event_flags` = 0 WHERE `entryorguid` = 36788 AND `source_type` = 0;
UPDATE `smart_scripts` SET `event_param1` = 0, `event_param2` = 0, `action_param2` = 64, `comment` = "Deathwhisper Necrolyte - In Combat CMC - Cast 'Shadow Bolt'" WHERE `entryorguid` = 36788 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_param2` = 1 WHERE `entryorguid` = 36788 AND `source_type` = 0 AND `id` = 1;
