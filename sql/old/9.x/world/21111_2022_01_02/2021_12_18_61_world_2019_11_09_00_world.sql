-- Archaeologist Andorin and Moteha Windborn Brann's Communicator recovery
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (9854, 9929);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`) VALUES
(9854, 1, 0, "I lost Brann's Communicator and need a replacement.",  31229, 1, 1),
(9929, 1, 0, "I lost Brann's Communicator and need a replacement.",  33084, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9854, 9929);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9854, 1, 0, 0, 28, 0, 12910, 0, 0, 0, 0, 0, '', 'Gossip Option requires quest complete 12910 before this option is visible'),
(15, 9854, 1, 0, 0, 2, 0, 40971, 1, 0, 1, 0, 0, '', 'Gossip Option requires not having item 40971'),
(15, 9929, 1, 0, 0, 28, 0, 12855, 0, 0, 0, 0, 0, '', 'Gossip Option requires quest complete 12855 before this option is visible'),
(15, 9929, 1, 0, 0, 2, 0, 40971, 1, 0, 1, 0, 0, '', 'Gossip Option requires not having item 40971'),
(15, 9854, 1, 0, 1, 8, 0, 12910, 0, 0, 0, 0, 0, '', 'Gossip Option requires quest rewarded 12910 before this option is visible'),
(15, 9854, 1, 0, 1, 2, 0, 40971, 1, 0, 1, 0, 0, '', 'Gossip Option requires not having item 40971'),
(15, 9929, 1, 0, 1, 8, 0, 12855, 0, 0, 0, 0, 0, '', 'Gossip Option requires quest rewarded 12855 before this option is visible'),
(15, 9929, 1, 0, 1, 2, 0, 40971, 1, 0, 1, 0, 0, '', 'Gossip Option requires not having item 40971');

UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry` IN (29937,29650);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29937) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29650) AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29937, 0, 0, 1, 62, 0, 100, 0, 9854, 1, 0, 0, 11, 57093, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Moteha Windborn - On Gossip Option 0 Selected - Invoker cast Branns Communicator Replacement"),
(29937, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Moteha Windborn - Link - Close Gossip"),
(29650, 0, 1, 2, 62, 0, 100, 0, 9929, 1, 0, 0, 11, 57093, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Andorin - On Gossip Option 0 Selected - Invoker cast Branns Communicator Replacement"),
(29650, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Andorin - Link - Close Gossip");

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=57093;
INSERT INTO `serverside_spell_effect` (`SpellID`, `Effect`, `EffectItemType`, `ImplicitTarget1`) VALUES
(57093, 24, 40971, 25);
