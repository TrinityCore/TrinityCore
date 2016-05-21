--
-- SAI script for Wyrmrest Temple taxi Flight Paths

SET @Tariolstrasz := 26443;
SET @Torastrasza  := 26949;
SET @Afrasastrasz := 27575;

-- Ground ----> Top: 878 (@Tariolstrasz,9455,0)
-- Ground -> Middle: 883 (@Tariolstrasz,9455,1)
-- Top ----> Ground: 879 (@Torastrasza, 9457,0)
-- Top ----> Middle: 880 (@Torastrasza, 9457,1)
-- Middle ----> Top: 881 (@Afrasastrasz,9563,0)
-- Middle -> Ground: 882 (@Afrasastrasz,9563,1)

-- Set AIName and remove old ScriptName in creature_template for all 3 NPCs
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName`= '' WHERE `entry` IN (@Tariolstrasz,@Torastrasza,@Afrasastrasz);

-- Tariolstrasz (Steward of Wyrmrest Temple)
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = @Tariolstrasz);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Tariolstrasz, 0, 0, 2, 62, 0, 100, 0, 9455, 0, 0, 0, 52, 878, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Tariolstrasz - On Gossip Option 0 Selected - Activate Taxi Path 878'),
(@Tariolstrasz, 0, 1, 2, 62, 0, 100, 0, 9455, 1, 0, 0, 52, 883, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Tariolstrasz - On Gossip Option 1 Selected - Activate Taxi Path 883'),
(@Tariolstrasz, 0, 2, 0, 61, 0, 100, 0,    0, 0, 0, 0, 72,   0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Tariolstrasz - On Gossip Options Selected  - Close Gossip');

-- Torastrasza (Majordomo to the Ruling Council)
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = @Torastrasza);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Torastrasza, 0, 0, 2, 62, 0, 100, 0, 9457, 0, 0, 0, 52, 879, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Torastrasza - On Gossip Option 0 Selected - Activate Taxi Path 879'),
(@Torastrasza, 0, 1, 2, 62, 0, 100, 0, 9457, 1, 0, 0, 52, 880, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Torastrasza - On Gossip Option 1 Selected - Activate Taxi Path 880'),
(@Torastrasza, 0, 2, 0, 61, 0, 100, 0,    0, 0, 0, 0, 72,   0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Torastrasza - On Gossip Options Selected  - Close Gossip');

-- Lord Afrasastrasz (Commander of Wyrmrest Temple Defenses)
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = @Afrasastrasz);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Afrasastrasz, 0, 0, 2, 62, 0, 100, 0, 9563, 0, 0, 0, 52, 881, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lord Afrasastrasz - On Gossip Option 0 Selected - Activate Taxi Path 881'),
(@Afrasastrasz, 0, 1, 2, 62, 0, 100, 0, 9563, 1, 0, 0, 52, 882, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lord Afrasastrasz - On Gossip Option 1 Selected - Activate Taxi Path 882'),
(@Afrasastrasz, 0, 2, 0, 61, 0, 100, 0,    0, 0, 0, 0, 72,   0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lord Afrasastrasz - On Gossip Options Selected  - Close Gossip');
