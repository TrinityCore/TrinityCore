-- 
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=2453901 AND `source_type`=9 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=2453901 AND `source_type`=9 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `link`=9, `action_type`=72, `action_param1`=0, `target_type`=7 WHERE  `entryorguid`=24539 AND `source_type`=0 AND `id`=6;
UPDATE `smart_scripts` SET `event_param3`=2000, `event_param4`=2000, `action_param3`=1 WHERE  `entryorguid`=24539 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `link`=14 WHERE  `entryorguid`=24539 AND `source_type`=0 AND `id`=3;

DELETE FROM `smart_scripts` WHERE `entryorguid`=2453900 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2453901 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24539 AND `source_type`=0 AND `id`>8;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24539, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 134, 44421, 2, 0, 0, 0, 0,7, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - Cast Harry\'s Debt'),
(24539, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - Set event phase 0'),
(24539, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - Turn HP Regen on'),
(24539, 0, 12, 13, 7, 0, 100, 0, 0, 0, 0, 0, 0, 2, 1888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Evade - Set Faction 1888'),
(24539, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - Remove Equip'),
(24539, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 71, 0, 0, 20977, 20984, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Silvermoon Harry - On Gossip Select - SET Equip'),
(2453900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Turn HP Regen off'),
(2453900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Say Line 1'),
(2453900, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 2, 1888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Set Faction 1888'),
(2453900, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Set event Phase 1'),
(2453900, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Evade'),
(2453900, 9, 5, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Set event Phase 0'),
(2453900, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '\'Silvermoon\' Harry - On Script - Turn HP Regen on');

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=44421;
INSERT INTO `serverside_spell_effect` (`SpellID`, `Effect`, `EffectItemType`, `ImplicitTarget1`) VALUES
(44421, 24, 34115, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9010);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9010,0,0,9,0,11464,0,0,0,'','Only show second gossip (option 0) if player is on quest Gambling Debt');
