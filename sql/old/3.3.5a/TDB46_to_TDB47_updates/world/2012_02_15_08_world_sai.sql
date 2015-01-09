SET @Pinata := 34632;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Pinata AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Pinata, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 65788, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ogre Pinata - On death cast Pile of Candy'),
(@Pinata, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ogre Pinata - On reset set react state passive');

-- same faction of the GO that is spawned by spell 65788 (not sniffed)
UPDATE `creature_template` SET `faction_A`=7,`faction_H`=7,`exp`=0,`AIName`='SmartAI' WHERE `entry`=@Pinata;
