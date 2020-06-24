SET @GUID := 130968; -- Need 3 free GUIDs

DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID  , 23377, 530, 0, 0, 1, 2, 0, 0, -3712.531494, 3514.539551, 325.550507, 3.277899, 0, 0, 0, 1, 0, 0, 0, 0, 0, "", 0),
(@GUID+1, 23377, 530, 0, 0, 1, 2, 0, 0, -3712.062256, 3510.393799, 319.9505, 3.277899, 0, 0, 0, 1, 0, 0, 0, 0, 0, "", 0),
(@GUID+2, 23377, 530, 0, 0, 1, 2, 0, 0, -3712.901123, 3517.808594, 319.9505, 3.277899, 0, 0, 0, 1, 0, 0, 0, 0, 0, "", 0);

UPDATE `creature_template` SET `unit_flags`=256+512, `AIName`="SmartAI" WHERE `entry`=23377;
UPDATE `creature_template` SET `unit_flags`=256+512 WHERE `entry`=21838;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23277;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21838, 23277, -@GUID, -(@GUID+1), -(@GUID+2)) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=185928 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2183800, 2183801, 2327700, 2337700) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(185928, 1, 0, 1, 62, 0, 100, 0, 8687, 0, 0, 0, 0, 85, 41004, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Ancient Skull Pile - On Gossip Option 0 Selected - Invoker Cast Summon Terokk"),
(185928, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Ancient Skull Pile - On Gossip Option 0 Selected - Close Gossip"),
(185928, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 900, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ancient Skull Pile - On Gossip Option 0 Selected - Despawn for 15 minutes"),

(21838, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 80, 2183800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Respawn - Call Script"),
(21838, 0, 1, 0, 0, 0, 100, 0, 4000, 7000, 15000, 20000, 0, 11, 40721, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - In Combat - Cast 'Shadow Bolt Volley'"),
(21838, 0, 2, 0, 0, 0, 100, 0, 6000, 9000, 7000, 9000, 0, 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - In Combat - Cast 'Cleave'"),
(21838, 0, 3, 0, 0, 0, 100, 0, 30000, 40000, 30000, 40000, 0, 80, 2183801, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - In Combat - Call Script"),
(21838, 0, 4, 0, 2, 0, 100, 1, 0, 50, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID, 0, 0, 0, 0, 0, 0, 0, "Terokk - Between 0-50% Health - Set Data 1 1 (Skyguard Ace) (No Repeat)"),
(21838, 0, 5, 6, 2, 0, 100, 1, 0, 25, 0, 0, 0, 11, 40733, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - Between 0-25% Health - Cast 'Divine Shield' (No Repeat)"),
(21838, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - Between 0-25% Health - Say Line 2 (No Repeat)"),
(21838, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @GUID, 0, 0, 0, 0, 0, 0, 0, "Terokk - Between 0-25% Health - Set Data 1 1 (Skyguard Ace) (No Repeat)"),
(21838, 0, 8, 0, 23, 0, 100, 0, 40657, 1, 1000, 1000, 0, 28, 40733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Has Aura 'Ancient Flames' - Remove Aura 'Divine Shield'"),
(21838, 0, 9, 10, 23, 0, 100, 1, 40657, 1, 0, 0, 0, 11, 28747, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Has Aura 'Ancient Flames' - Cast 'Frenzy' (No Repeat)"),
(21838, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Has Aura 'Ancient Flames' - Say Line 3 (No Repeat)"),
(21838, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Has Aura 'Ancient Flames' - Set Event Phase 1"),
(21838, 0, 12, 0, 0, 1, 100, 0, 5000, 10000, 5000, 10000, 0, 11, 40733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - In Combat - Cast 'Divine Shield' (Phase 1)"),
(21838, 0, 13, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @GUID, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Death - Set Data 3 3 (Skyguard Ace)"),
(21838, 0, 14, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 10, @GUID, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Evade - Set Data 4 4 (Skyguard Ace)"),
(21838, 0, 15, 0, 21, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 5000, 5000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Reached Home - Start Timed Event"),
(21838, 0, 16, 0, 59, 0, 100, 0, 1, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Timed Event Triggered - Despawn"),
(21838, 0, 17, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 74, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Aggro - Remove Timed Event"),
(21838, 0, 18, 0, 31, 0, 100, 0, 40726, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Target Hit By Spell 'Chosen One' - Say Line 1"),

(2183800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 24240, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Script - Cast 'Spawn - Red Lightning'"),
(2183800, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 41408, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Script - Cast 'Shadowform'"),
(2183800, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Script - Say Line 0"),
(2183800, 9, 3, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 19, 256+512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Script - Remove Unitflag Immune to PC+NPC"),
(2183800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Script - Attack Summoner"),
(2183801, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 40726, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Script - Cast 'Chosen One'"),
(2183801, 9, 1, 0, 0, 0, 100, 0, 500, 500, 0, 0, 0, 11, 40722, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Terokk - On Script - Cast 'Will of the Arakkoa God'"),

(23277, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 80, 2327700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Target - On Spawn - Run Script"),
(2327700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 40656, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Target - On Script - Cast 'Skyguard Flare'"),
(2327700, 9, 1, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 10, @GUID, 0, 0, 0, 0, 0, 0, 0, "Skyguard Target - On Script - Set Data 5 5 (Skyguard Ace)"),

(-@GUID, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 0, 44, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 1 1 Set - Set Phasemask 1"),
(-@GUID, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 1 1 Set - Say Line 0"),
(-@GUID, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 1, 23377, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 1 1 Set - Start WP"),
(-@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 44, 1, 0, 0, 0, 0, 0, 10, @GUID+1, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 1 1 Set - Set Phasemask 1 (Skyguard Ace)"),
(-@GUID, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 44, 1, 0, 0, 0, 0, 0, 10, @GUID+2, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 1 1 Set - Set Phasemask 1 (Skyguard Ace)"),
(-@GUID, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 600000, 600000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 1 1 Set - Start Timed Event"),
(-@GUID, 0, 6, 0, 59, 0, 100, 0, 1, 0, 0, 0, 0, 80, 2337700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Timed Event Triggered - Run Script"),
(-@GUID, 0, 7, 8, 38, 0, 100, 0, 2, 2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 2 2 Set - Say Line 1"),
(-@GUID, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 2 2 Set - Set Event Phase 1"),
(-@GUID, 0, 9, 10, 38, 0, 100, 0, 3, 3, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 3 3 Set - Say Line 2"),
(-@GUID, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 80, 2337700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 3 3 Set - Run Script"),
(-@GUID, 0, 11, 0, 38, 0, 100, 0, 4, 4, 0, 0, 0, 80, 2337700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 4 4 Set - Run Script"),
(-@GUID, 0, 12, 0, 1, 1, 100, 0, 10000, 15000, 30000, 40000, 0, 11, 40655, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - OOC - Cast Skyguard Flare (Phase 1)"),
(-@GUID, 0, 13, 0, 38, 0, 100, 0, 5, 5, 0, 0, 0, 11, 40657, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Data 5 5 Set - Cast 'Ancient Flames'"),

(2337700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 10, @GUID+1, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Script - Despawn In 5 Seconds (Skyguard Ace)"),
(2337700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 10, @GUID+2, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Script - Despawn In 5 Seconds (Skyguard Ace)"),
(2337700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Skyguard Ace - On Script - Despawn In 5 Seconds");

DELETE FROM `creature_text` WHERE `CreatureID` IN (21838, 23377);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(21838, 0, 0, "Who calls me to this world?  The stars are not yet aligned... my powers fail me!  You will pay for this!", 12, 0, 100, 0, 0, 0, 21639, 0, "Terokk"),
(21838, 1, 0, "Show me what you're made of, $n!", 14, 0, 100, 0, 0, 0, 21327, 0, "Terokk"),
(21838, 2, 0, "Kwa! You cannot kill me, I am immortal!", 14, 0, 100, 0, 0, 0, 24020, 0, "Terokk"),
(21838, 3, 0, "%s becomes enraged as his shield shatters.", 41, 0, 100, 0, 0, 0, 21328, 0, "Terokk"),
(23377, 0, 0, "Enemy sighted!  Fall into formation and prepare for bombing maneuvers!", 14, 0, 100, 0, 0, 0, 21439, 0, "Skyguard Ace"),
(23377, 1, 0, "Quickly! Use the flames and support the ground troops. Its ancient magic should cleanse Terokk's shield.", 14, 0, 100, 0, 0, 0, 24021, 0, "Skyguard Ace"),
(23377, 2, 0, "They did it!  Enemy down!  Return to base!", 14, 0, 100, 0, 0, 0, 21437, 0, "Skyguard Ace");

DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_skyguard_flare";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40655, "spell_skyguard_flare");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=21838;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 40722, 0, 0, 1, 0, 40726, 0, 0, 1, 0, 0, "", "Will of the Arakkoa God does not affect targets with Chosen One aura"),
(22, 13, 21838, 0, 0, 1, 1, 40657, 1, 0, 1, 0, 0, "", "SAI executes only if Terokk does not have Ancient Flames aura AND"),
(22, 13, 21838, 0, 0, 1, 1, 40733, 0, 0, 1, 0, 0, "", "SAI executes only if Terokk does not have Divine Shield aura");

DELETE FROM `creature_template_movement` WHERE `CreatureId`=23377;
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`) VALUES
(23377, 1);

DELETE FROM `creature_template_addon` WHERE `entry`=23377;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `auras`) VALUES
(23377, 21152, "");

DELETE FROM `waypoints` WHERE `entry`=23377;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(23377, 1, -3774.552246, 3514.509766, 325.550507, "Skyguard Ace"),
(23377, 2, -3794.875, 3497.479004, 325.550507, "Skyguard Ace"),
(23377, 3, -3808.633789, 3515.702393, 325.550507, "Skyguard Ace"),
(23377, 4, -3783.597168, 3524.585205, 325.550507, "Skyguard Ace");

DELETE FROM `creature_formations` WHERE `leaderGUID`=@GUID;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(@GUID, @GUID, 0, 0, 515),
(@GUID, @GUID+1, 5, 45, 515),
(@GUID, @GUID+2, 5, 315, 515);
