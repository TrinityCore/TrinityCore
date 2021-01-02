-- 
DELETE FROM `gameobject` WHERE `id`=185952;
UPDATE `quest_template_addon` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `ID`=11085;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23383;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23383 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21644 AND `source_type`=0 AND `id` IN (5, 6, 7);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2338300, 2338301, 2338302, 2338303, 2338304) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23383, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Spawn - Set Immune To NPC"),
(23383, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Spawn - Set Active"),
(23383, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 88, 2338300, 2338302, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Spawn - Run Random Script"),
(23383, 0, 3, 4, 19, 0, 100, 0, 11085, 0, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Quest 'Escape from Skettis' Accepted - Remove Immune To NPC"),
(23383, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 83, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Quest 'Escape from Skettis' Accepted - Remove Questgiver Npcflag"),
(23383, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 15, 185952, 10, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Quest 'Escape from Skettis' Accepted - Activate Gameobject 'Cage'"),
(23383, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Quest 'Escape from Skettis' Accepted - Store Invoker"),
(23383, 0, 7, 0, 19, 0, 100, 0, 11085, 0, 0, 0, 0, 113, 2338300, 2338301, 2338302, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Quest 'Escape from Skettis' Accepted - Start Closest WP"),
(23383, 0, 8, 9, 40, 0, 100, 0, 1, 0, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 1 Reached - Pause WP (10 Seconds)"),
(23383, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 1 Reached - Say Line 0"),
(23383, 0, 10, 11, 40, 0, 100, 0, 13, 2338300, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 13 Reached (Path 2338300) - Pause WP (10 Seconds)"),
(23383, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 107, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 13 Reached (Path 2338300) - Summon Creature Group 0"),
(23383, 0, 12, 13, 40, 0, 100, 0, 8, 2338301, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 8 Reached (Path 2338301) - Pause WP (10 Seconds)"),
(23383, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 8 Reached (Path 2338301) - Summon Creature Group 1"),
(23383, 0, 14, 15, 40, 0, 100, 0, 5, 2338302, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 5 Reached (Path 2338302) - Pause WP (10 Seconds)"),
(23383, 0, 15, 16, 61, 0, 100, 0, 0, 0, 0, 0, 0, 107, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 5 Reached (Path 2338302) - Summon Creature Group 2"),
(23383, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 5 Reached (Path 2338302) - Set Run On"),
(23383, 0, 17, 0, 82, 0, 100, 0, 21644, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Summoned Creature Died - Increase Counter"),
(23383, 0, 18, 0, 77, 0, 100, 0, 1, 2, 0, 0, 0, 80, 2338303, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Counter Reached 2 - Run Script"),	
(23383, 0, 19, 0, 40, 0, 100, 0, 18, 2338300, 0, 0, 0, 80, 2338304, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 18 Reached (Path 2338300) - Run Script"),
(23383, 0, 20, 0, 40, 0, 100, 0, 13, 2338301, 0, 0, 0, 80, 2338304, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 13 Reached (Path 2338301) - Run Script"),
(23383, 0, 21, 0, 40, 0, 100, 0, 12, 2338302, 0, 0, 0, 80, 2338304, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On WP 12 Reached (Path 2338302) - Run Script"),
(23383, 0, 22, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 21184, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Spawn - Morph to model"),
(2338300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 41136, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Cast 'Quest - Port Skettis Prisoner - Location 01'"),
(2338300, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 41147, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Cast 'Quest - Skettis Prisoner Cage Summon'"),
(2338300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Set Inactive"),
(2338301, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 41138, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Cast 'Quest - Port Skettis Prisoner - Location 02'"),
(2338301, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 41147, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Cast 'Quest - Skettis Prisoner Cage Summon'"),
(2338301, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Set Inactive"),
(2338302, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 41141, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Cast 'Quest - Port Skettis Prisoner - Location 03'"),
(2338302, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 41147, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Cast 'Quest - Skettis Prisoner Cage Summon'"),
(2338302, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Set Inactive"),
(2338303, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Say Line 1"),
(2338304, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 54, 20000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Pause WP"),
(2338304, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 15, 11085, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Give Quest Credit (Stored Target)"),
(2338304, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Say Line 2"),
(2338304, 9, 3, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Prisoner - On Script - Despawn"),
(21644, 0, 5, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skettis Wing Guard - On Just Summoned - Start Timed Event"),
(21644, 0, 6, 0, 59, 0, 100, 0, 1, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, "Skettis Wing Guard - On Timed Event Triggered - Attack Summoner"),
(21644, 0, 7, 0, 59, 0, 20, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skettis Wing Guard - On Timed Event Triggered - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=23383;
DELETE FROM `creature_text` WHERE `CreatureID`=21644 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23383, 0, 0, "Thanks for your help.  Let's get out of here!", 12, 0, 100, 0, 0, 0, 21481, 0, "Skyguard Prisoner"),
(23383, 1, 0, "Let's keep moving.  I don't like this place.", 12, 0, 100, 0, 0, 0, 21484, 0, "Skyguard Prisoner"),
(23383, 2, 0, "Thanks again.  Sergeant Doryn will be glad to hear he has one less scout to replace this week.", 12, 0, 100, 0, 0, 0, 21485, 0, "Skyguard Prisoner"),
(21644, 1, 0, "You'll go nowhere, Skyguard scum!", 12, 0, 100, 0, 0, 0, 21490, 0, "Skettis Wing Guard"),
(21644, 1, 1, "Skettis prevails!", 12, 0, 100, 0, 0, 0, 21491, 0, "Skettis Wing Guard"),
(21644, 1, 2, "No one escapes Skettis!", 12, 0, 100, 0, 0, 0, 21492, 0, "Skettis Wing Guard"),
(21644, 1, 3, "Death to our enemies!", 12, 0, 100, 0, 0, 0, 21493, 0, "Skettis Wing Guard");

DELETE FROM `waypoints` WHERE `entry` IN (2338300, 2338301, 2338302);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2338300, 1, -4109.42, 3034.16, 344.168, "Skyguard Prisoner"),
(2338300, 2, -4113.27, 3035.99, 344.071, "Skyguard Prisoner"),
(2338300, 3, -4120.02, 3032.22, 344.074, "Skyguard Prisoner"),
(2338300, 4, -4124.41, 3026.33, 344.151, "Skyguard Prisoner"),
(2338300, 5, -4128.82, 3026.65, 344.035, "Skyguard Prisoner"),
(2338300, 6, -4138.91, 3028.95, 338.92, "Skyguard Prisoner"),
(2338300, 7, -4152.59, 3031.23, 336.913, "Skyguard Prisoner"),
(2338300, 8, -4169.81, 3034.3, 342.047, "Skyguard Prisoner"),
(2338300, 9, -4174.63, 3036.04, 343.457, "Skyguard Prisoner"),
(2338300, 10, -4174.4, 3044.98, 343.862, "Skyguard Prisoner"),
(2338300, 11, -4176.63, 3052.01, 344.077, "Skyguard Prisoner"),
(2338300, 12, -4183.66, 3058.9, 344.15, "Skyguard Prisoner"),
(2338300, 13, -4182.92, 3065.41, 342.574, "Skyguard Prisoner"),
(2338300, 14, -4182.06, 3070.56, 337.644, "Skyguard Prisoner"),
(2338300, 15, -4181.26, 3077.13, 331.59, "Skyguard Prisoner"),
(2338300, 16, -4179.99, 3086.1, 325.571, "Skyguard Prisoner"),
(2338300, 17, -4178.77, 3090.1, 323.955, "Skyguard Prisoner"),
(2338300, 18, -4177.96, 3093.87, 323.839, "Skyguard Prisoner"),
(2338301, 1, -3716.813, 3784.913, 302.7957, "Skyguard Prisoner"),
(2338301, 2, -3713.891, 3785.578, 302.9066, "Skyguard Prisoner"),
(2338301, 3, -3701.317, 3788.437, 302.1635, "Skyguard Prisoner"),
(2338301, 4, -3691.435, 3784.761, 298.6149, "Skyguard Prisoner"),
(2338301, 5, -3679.718, 3780.137, 295.1252, "Skyguard Prisoner"),
(2338301, 6, -3678.255, 3779.54, 294.927, "Skyguard Prisoner"),
(2338301, 7, -3665.416, 3774.3, 296.5848, "Skyguard Prisoner"),
(2338301, 8, -3652.483, 3769.122, 301.5699, "Skyguard Prisoner"),
(2338301, 9, -3655.307, 3758.888, 301.9366, "Skyguard Prisoner"),
(2338301, 10, -3647.862, 3745.505, 302.1535, "Skyguard Prisoner"),
(2338301, 11, -3653.096, 3731.482, 293.2672, "Skyguard Prisoner"),
(2338301, 12, -3658.584, 3718.315, 283.3129, "Skyguard Prisoner"),
(2338301, 13, -3660.324, 3713.304, 281.269, "Skyguard Prisoner"),
(2338302, 1, -3669.901, 3388.204, 312.9493, "Skyguard Prisoner"),
(2338302, 2, -3672.78, 3371.396, 312.1327, "Skyguard Prisoner"),
(2338302, 3, -3666.887, 3367.723, 312.2306, "Skyguard Prisoner"),
(2338302, 4, -3670.773, 3352.389, 306.7109, "Skyguard Prisoner"),
(2338302, 5, -3673.615, 3342.424, 304.9935, "Skyguard Prisoner"),
(2338302, 6, -3679.221, 3318.798, 311.436, "Skyguard Prisoner"),
(2338302, 7, -3687.093, 3318.624, 311.8744, "Skyguard Prisoner"),
(2338302, 8, -3697.118, 3315.984, 312.1466, "Skyguard Prisoner"),
(2338302, 9, -3703.314, 3309.11, 312.2234, "Skyguard Prisoner"),
(2338302, 10, -3713.242, 3311.646, 307.328, "Skyguard Prisoner"),
(2338302, 11, -3724.522, 3313.627, 297.02, "Skyguard Prisoner"),
(2338302, 12, -3734.422, 3315.625, 292.3213, "Skyguard Prisoner");

DELETE FROM `creature_summon_groups` WHERE `summonerId`=23383;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(23383, 0, 0, 21644, -4179.043, 3081.007, 328.28, 4.51, 4, 60000, "Skyguard Prisoner - Group 0 - Skettis Wing Guard"),
(23383, 0, 0, 21644, -4181.610, 3081.289, 328.32, 4.52, 4, 60000, "Skyguard Prisoner - Group 0 - Skettis Wing Guard"),
(23383, 0, 1, 21644, -3653.75, 3750.8, 302.101, 2.11185, 4, 60000, "Skyguard Prisoner - Group 1 - Skettis Wing Guard"),
(23383, 0, 1, 21644, -3649.91, 3754.08, 303.007, 2.3911, 4, 60000, "Skyguard Prisoner - Group 1 - Skettis Wing Guard"),
(23383, 0, 2, 21644, -3680.32, 3318.81, 311.501, 1.55334, 4, 60000, "Skyguard Prisoner - Group 2 - Skettis Wing Guard"),
(23383, 0, 2, 21644, -3677.91, 3317.93, 311.573, 1.48353, 4, 60000, "Skyguard Prisoner - Group 2 - Skettis Wing Guard");

DELETE FROM `spell_target_position` WHERE `ID` IN (41136, 41138, 41141);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(41136, 0, 530, -4106.64, 3029.76, 344.877, 0.820305, 0),
(41138, 0, 530, -3720.35, 3789.91, 302.888, 3.615158, 0),
(41141, 0, 530, -3664.54, 3389.79, 312.952, 2.35619, 0);
