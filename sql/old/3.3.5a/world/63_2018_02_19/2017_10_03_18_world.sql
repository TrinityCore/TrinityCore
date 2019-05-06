UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=31892;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31892, 3189200) AND `source_type` IN (0, 9);
DELETE FROM smart_scripts WHERE entryorguid IN (-121628, -121627, -121626, -121625, -121624, -121623, -121622, -121621, -121620, -121619, -121618, -121617, -121616, -121615) AND source_type=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31892, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 24110, 0, 50, 0, 0, 0, 0, "Darkspeaker R'khem - On Respawn - Set Data 1 1 (ELM General Purpose Bunny Large)"),
(31892, 0, 1, 0, 20, 0, 100, 0, 13308, 0, 0, 0, 80, 3189200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkspeaker R'khem - On Quest 'Mind Tricks' Rewarded - Run Script"),
(3189200, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkspeaker R'khem - On Script - Say Line 0"),
(3189200, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkspeaker R'khem - On Script - Cast 'Teleport Visual Only'"),
(3189200, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkspeaker R'khem - On Script - Despawn"),
(-121628, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 59952, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Right Hand'"),
(-121627, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 59951, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Left Hand'"),
(-121626, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 59951, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Left Hand'"),
(-121625, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 5432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Torso Blood Back'"),
(-121624, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 5432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Torso Blood Back'"),
(-121623, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 5432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Torso Blood Back'"),
(-121622, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 59951, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Left Hand'"),
(-121621, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 59951, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Left Hand'"),
(-121620, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 5432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Torso Blood Back'"),
(-121619, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 5432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Torso Blood Back'"),
(-121618, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 5432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Torso Blood Back'"),
(-121617, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 59952, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Right Hand'"),
(-121616, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 59952, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Right Hand'"),
(-121615, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 59952, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny Large - On Data 1 1 Set - Cast 'Mind Trick: Chains - Right Hand'");

DELETE FROM `creature_text` WHERE `CreatureID`=31892;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(31892, 0, 0, "%s makes a strange noise that translates as laughter in your mind.", 16, 0, 100, 0, 0, 0, 32533, 0, "Darkspeaker R'khem");
