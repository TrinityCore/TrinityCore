--
DELETE FROM `conditions` WHERE `SourceEntry`=24539;
DELETE FROM `conditions` WHERE `SourceGroup`=9010;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2453900, 2453901);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2453900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "'Silvermoon' Harry - On Script - Say Line 1"),
(2453900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 1080, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "'Silvermoon' Harry - On Script - Set Faction 1080"),
(2453900, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "'Silvermoon' Harry - On Script - Set Phase 1"),
(2453900, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "'Silvermoon' Harry - On Script - Evade"),
(2453900, 9, 4, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "'Silvermoon' Harry - On Script - Set Phase 0"),
(2453901, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "'Silvermoon' Harry - On Script - Close Gossip"),
(2453901, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 56, 34115, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "'Silvermoon' Harry - On Script - Add Item 'Silvermoon Harry's Debt'"),
(2453901, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "'Silvermoon' Harry - On Script - Set Phase 0");

UPDATE `smart_scripts` SET `event_phase_mask`=1 WHERE `entryorguid`=24539 AND `id`=5;
UPDATE `smart_scripts` SET `action_type`=49, `action_param1`=0, `target_type`=7, `comment`="'Silvermoon' Harry - On Gossip Option 0 Selected - Attack Invoker" WHERE `entryorguid`=24539 AND `id`=3;
