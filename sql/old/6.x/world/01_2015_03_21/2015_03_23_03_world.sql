--
SET @Disco         :=190351;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@Disco);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Disco AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@Disco, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 85, 50493 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Disco - On gossip hello - cast Listening to Music');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-50314, -50493, 50493);
INSERT INTO `spell_linked_spell` VALUES 
(-50314, -50493, 0, 'Disco Ball'),
(-50493, -50314, 0, 'Disco Ball(Listening to Music)'),
(50493, 50314, 0, 'Disco Ball(Listening to Music)');
