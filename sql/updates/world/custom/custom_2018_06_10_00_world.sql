-- Template Updates
UPDATE `creature_template` SET `DamageModifier`= 80, `mingold`= 19000, `maxgold`= 21000 WHERE `entry`= 39425;
UPDATE `creature_template` SET `DamageModifier`= 80, `mingold`= 19000, `maxgold`= 21000 WHERE `entry`= 49262;

-- Pit Viper snakes respawn in 30 seconds.
UPDATE `creature` SET `spawntimesecs`= 30 WHERE `map`= 644 AND `id`= 39444;

-- broadcast text ids for Anhuur
UPDATE `creature_text` SET `BroadcastTextId`= 40968 WHERE `CreatureID`= 39425 AND `GroupID` = 2;
UPDATE `creature_text` SET `BroadcastTextId`= 50665 WHERE `CreatureID`= 39425 AND `GroupID` = 3;

-- script names ("spell_anhuur_activate_beacons" rewritten into "spell_anhuur_handle_beacons")
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_anhuur_reverberating_hymn',
'spell_anhuur_activate_beacons',
'spell_anhuur_handle_beacons');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75322, 'spell_anhuur_reverberating_hymn'),
(76599, 'spell_anhuur_handle_beacons'),
(76600, 'spell_anhuur_handle_beacons');

-- spell condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (76599, 76600);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 76599, 0, 0, 31, 0, 5, 207218, 0, 0, 0, 0, '', 'Activate Beacons targets Beacon of Light'),
(13, 1, 76599, 0, 1, 31, 0, 5, 207219, 0, 0, 0, 0, '', 'Activate Beacons targets Beacon of Light'),
(13, 1, 76599, 0, 2, 31, 0, 5, 203133, 0, 0, 0, 0, '', 'Activate Beacons targets Beacon of Light'),
(13, 1, 76599, 0, 3, 31, 0, 5, 203136, 0, 0, 0, 0, '', 'Activate Beacons targets Beacon of Light'),
(13, 1, 76600, 0, 0, 31, 0, 5, 207218, 0, 0, 0, 0, '', 'Deactivate Beacons targets Beacon of Light'),
(13, 1, 76600, 0, 1, 31, 0, 5, 207219, 0, 0, 0, 0, '', 'Deactivate Beacons targets Beacon of Light'),
(13, 1, 76600, 0, 2, 31, 0, 5, 203133, 0, 0, 0, 0, '', 'Deactivate Beacons targets Beacon of Light'),
(13, 1, 76600, 0, 3, 31, 0, 5, 203136, 0, 0, 0, 0, '', 'Deactivate Beacons targets Beacon of Light');

UPDATE `gameobject` SET `spawnMask`= 1 WHERE `guid` IN (220773, 220775);
UPDATE `gameobject` SET `spawnMask`= 2 WHERE `guid` IN (200969, 200968);

-- Creature Pit Viper 39444 SAI
SET @ENTRY := 39444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 116, 6000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Sets corpse delay of Self to 6000ms // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 6000, 7000, 11, 74538, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 6000 and 7000 ms) - Self: Cast spell 74538 on Victim // ");

UPDATE `creature_template` SET `DamageModifier`= 5, `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16 WHERE `entry`= 48891;

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (39425, 49262);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(39425, 395, 3500),
(49262, 395, 7000);
