-- Holland's Experiment

Set @Nain  :=2211;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Nain;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Nain AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Nain*100 AND `source_type` = 9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Nain, 0, 0, 0, 20, 0, 100, 0, 24996, 0, 0, 0, 80, @Nain*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nain - On quest rewarded - action list'),
(@Nain*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Nain - action list - TALK'),
(@Nain*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nain - action list - Die');

DELETE FROM `creature_text` WHERE `entry`=@Nain ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Nain, 0, 0, ' I raise my brew and hope to be rid of the likes of you! Cheers, you no good scoundrel, $n!', 12, 0, 100, 1, 0, 0, 'Nain', 576);
