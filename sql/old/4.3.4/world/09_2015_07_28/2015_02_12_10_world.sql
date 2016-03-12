-- A Little Oomph
SET @Dithers:=  11057;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Dithers;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dithers AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Dithers, 0, 0, 0, 20, 0, 100, 0, 25013, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zealot - On quest rewarded - talk');
DELETE FROM `creature_text` WHERE `entry`=@Dithers ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Dithers, 0, 0, 'Now THAT''s what I call oomph! I wish all our potions did this!', 12, 0, 100, 1, 0, 0, 'Dithers', 44553);
