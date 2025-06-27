-- 
DELETE FROM `spell_script_names` WHERE `spell_id`=46444 AND `ScriptName`='spell_q11896_weakness_to_lightning_46444';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (46444,'spell_q11896_weakness_to_lightning_46444');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25752,25753,25758) AND `source_type`=0 AND `id`IN (5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25792) AND `source_type`=0 AND `id`IN (3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25752, 0, 5, 0, 6, 1, 100, 0, 0, 0, 0, 0, 0, 11, 46443, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Scavenge-bot 004-A8 - On Just Died - Cast 'Weakness to Lightning: Kill Credit Direct to Player' (Phase 1)"),
(25753, 0, 5, 0, 6, 1, 100, 0, 0, 0, 0, 0, 0, 11, 46444, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Sentry-bot 57-K - On Just Died - Cast 'Weakness to Lightning: Kill Credit from Pet' (Phase 1)"),
(25758, 0, 5, 0, 6, 1, 100, 0, 0, 0, 0, 0, 0, 11, 46444, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Defendo-tank 66D - On Just Died - Cast 'Weakness to Lightning: Kill Credit from Pet' (Phase 1)"),
(25792, 0, 3, 0, 6, 1, 100, 0, 0, 0, 0, 0, 0, 11, 46444, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Scavenge-bot 005-B6 - On Just Died - Cast 'Weakness to Lightning: Kill Credit from Pet' (Phase 1)");
UPDATE `smart_scripts` SET `action_param1`=46444, `action_param2`=2 WHERE `entryorguid` IN (25752) AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=2 WHERE `entryorguid` IN (25752,25753,25758,25792) AND `action_param1` IN (46443,46444);
