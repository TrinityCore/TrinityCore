--
SET @Bird1       :=22337;
SET @Bird2       :=22339;
SET @Egg         :=185211;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Bird2);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@Egg);

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Egg*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Egg*100+1 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Egg AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Egg, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 87, @Egg*100, @Egg*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed egg - On State 2 - Action random action list'),
(@Egg*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Bird2, 3, 15000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed egg - Action list - Summon'),
(@Egg*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Bird1, 3, 40000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed egg - Action list  - Summon');
