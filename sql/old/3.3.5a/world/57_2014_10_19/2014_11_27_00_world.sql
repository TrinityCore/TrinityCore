-- quest linking for Judgment at the eye of eternity/ Heroic Judgment at the eye of eternity
-- requires The Key to the Focusing Iris for 10m or Heroic: The Key to the Focusing Iris for 25m
UPDATE `quest_template` SET `PrevQuestId`=13372 WHERE  `Id`=13384;
UPDATE `quest_template` SET `PrevQuestId`=13375 WHERE  `Id`=13385;
UPDATE `quest_template` SET `NextQuestId`=13384 WHERE  `Id`=13372;
UPDATE `quest_template` SET `NextQuestId`=13385 WHERE  `Id`=13375;
-- Prevent Image of Loken and Warlord Jin\'arrak from aggroing on player when summoned for scripted quest event
DELETE FROM `smart_scripts` WHERE `entryorguid`=27199 AND `source_type`=0 AND `id`=5;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27212 AND `source_type`=0 AND `id`=6;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27199, 0, 5, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warlord Jin\'arrak - On Spawn - Set Passive'),
(27212, 0, 6, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Loken - On Spawn - Set Passive');
