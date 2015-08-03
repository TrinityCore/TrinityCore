--
SET @ENTRY := 29483;
SET @SPELL_ENERGY_SURGE := 54559;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id` =@ENTRY;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|4|33554432, `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 9, 0, 100, 0, 1, 20, 1000, 1000, 11, @SPELL_ENERGY_SURGE, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'K3 Perimeter Turret - Within 1-20 Range - Cast ''Energy Surge''');
