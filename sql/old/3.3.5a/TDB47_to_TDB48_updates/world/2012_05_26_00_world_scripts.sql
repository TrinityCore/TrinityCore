-- Correction for Obsidian Nullifier EAI
UPDATE `creature_ai_scripts` SET
    `action1_param1` = 23
WHERE `id` = 1531201;

-- Correction for Wildspawn Felsworn and Wildspawn Hellcaller SAI
UPDATE `smart_scripts` SET
    `event_phase_mask` = 2,
    `action_type` = 22,
    `action_param1` = 1,
    `target_type` = 1
WHERE
    (`entryorguid` = 11457 AND
    `source_type` = 0 AND
    `id` = 10 AND
    `link` = 0) OR
    (`entryorguid` = 11455 AND
    `source_type` = 0 AND
    `id` = 11 AND
    `link` = 0);
