-- Scalawag Frog
DELETE FROM `serverside_spell_effect` WHERE `SpellID`=44421;
INSERT INTO `serverside_spell_effect` (`SpellID`, `Effect`, `EffectItemType`, `ImplicitTarget1`) VALUES
(47121, 24, 35803, 25);
UPDATE `smart_scripts` SET `action_type`=134, `action_param1`=47121 WHERE  `entryorguid`=26503 AND `source_type`=0 AND `id`=1 AND `link`=2;
-- Create Warsong Outfit
DELETE FROM `serverside_spell_effect` WHERE `SpellID`=45701;
INSERT INTO `serverside_spell_effect` (`SpellID`, `Effect`, `EffectItemType`, `ImplicitTarget1`) VALUES
(45701, 24, 34842, 25);
UPDATE `smart_scripts` SET `action_type`=134, `action_param1`=45701 WHERE  `entryorguid`IN(25342,25343) AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Create Sample of Rockflesh 
DELETE FROM `serverside_spell_effect` WHERE `SpellID`=47416;
INSERT INTO `serverside_spell_effect` (`SpellID`, `Effect`, `EffectItemType`, `ImplicitTarget1`) VALUES
(47416, 24, 36765, 25);
UPDATE `smart_scripts` SET `action_type`=134, `action_param1`=47416 WHERE  `entryorguid`=26809 AND `source_type`=0 AND `id`=1 AND `link`=0;
-- Mission: Plague This!: Create Bombs & Taxi
DELETE FROM `serverside_spell_effect` WHERE `SpellID`=43412;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `Effect`, `EffectItemType`, `ImplicitTarget1`, `EffectBasePoints`, `EffectMiscValue1`) VALUES
(43412, 0, 24, 33634, 25, 10, 0),
(43412, 1, 123, 0, 25, 0, 745);
DELETE FROM `smart_scripts` WHERE `entryorguid`=23859 AND `source_type`=0 AND `id` IN(1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23859, 0, 1, 2, 62, 0, 100, 512, 9546, 2, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Gossip Option 1 Selected - Close Gossip'),
(23859, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 134, 43412, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Gossip Option 1 Selected - Invoker cast Mission: Plague This!: Create Bombs & Taxi');
