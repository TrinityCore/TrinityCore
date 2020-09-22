SET @ENTRY := 42362;
UPDATE `creature_template` SET `mechanic_immune_mask`= 1 | 2 | 8 | 16 | 32 | 64 | 256 | 512 | 2048 | 4096 | 8192 | 65536 | 131072 | 4194304 | 8388608 | 33554432 | 67108864 WHERE `entry` IN (42362, 49489);
UPDATE `creature_template` SET `DamageModifier`= 90, `BaseVariance`= 1 WHERE `entry` IN (42362, 49489);
UPDATE `creature_template` SET `difficulty_entry_1`= 49489, `AIName`="SmartAI" WHERE `entry`= @ENTRY;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_walk`= 1.2, `speed_run`= 1, `unit_flags`= 32832, `lootid`= 42362 WHERE `entry`= 49489;

SET @GUID := -250140;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 1, 0, 100, 1, 6000, 6000, 0, 0, 11, 79025, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (OOC) 6000 min and 6000 max ms (repeat 0 min 0 max ms) - Self: Cast spell 79025 on Self // "),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 425, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 425 // "),
(@GUID, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 79573, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 79573 on Self // "),
(@GUID, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 28, 79573, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Remove aura due to spell 79573 // "),
(@GUID, 0, 4, 0, 0, 0, 100, 0, 8000, 8000, 7000, 7000, 11, 79604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 8000 min and 8000 max ms (repeat 7000 min 7000 max ms) - Self: Cast spell 79604 on Self // "),
(@GUID, 0, 5, 6, 0, 0, 100, 0, 20000, 20000, 20000, 20000, 11, 63984, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 20000 min and 20000 max ms (repeat 20000 min 20000 max ms) - Self: Cast spell 63984 on Self // "),
(@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 79630, 0, 0, 0, 0, 0, 28, 80, 1, 1, 0, 0, 0, 0, " Linked - Self: Cast spell 79630 on Farthest player within 80 yards on the threat list // "),
(@GUID, 0, 7, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 80035, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell 80035 on Self // ");

SET @GUID := -250141;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 1, 1, 0, 100, 1, 6000, 6000, 0, 0, 86, 88200, 0, 10, 250105, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (OOC) 6000 min and 6000 max ms (repeat 0 min 0 max ms) - SMART_TARGET_CREATURE_GUID: Cast spell 88200 at Self // "),
(@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 468, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 468 // "),
(@GUID, 0, 2, 0, 0, 0, 100, 0, 8000, 8000, 7000, 8000, 11, 79604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 8000 min and 8000 max ms (repeat 7000 min 8000 max ms) - Self: Cast spell 79604 on Self // "),
(@GUID, 0, 3, 4, 0, 0, 100, 0, 20000, 20000, 20000, 20000, 11, 63984, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 20000 min and 20000 max ms (repeat 20000 min 20000 max ms) - Self: Cast spell 63984 on Self // "),
(@GUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 79630, 0, 0, 0, 0, 0, 28, 80, 1, 1, 0, 0, 0, 0, " Linked - Self: Cast spell 79630 on Farthest player within 80 yards on the threat list // "),
(@GUID, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 80035, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell 80035 on Self // "),
(@GUID, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 92, 0, 0, 0, 0, 0, 0, 10, 250105, 0, 0, 0, 0, 0, 0, "On aggro - Creature Magmaw Spike Stalker 41767 (250105): Interrupt casted spell // ");

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (79025, 88200, 79461, 80035, 79580, 91906) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 79025, 0, 0, 31, 0, 3, 42347, 0, 0, 0, '', 'Chain Visual - Target Exposed Head of Magmaw'),
(13, 1, 88200, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Captured - Target Magmaw'),
(13, 2, 79461, 0, 0, 31, 0, 3, 42362, 0, 0, 0, '', 'Emote - Magmaw Lava Splash - Drakonid Drudge'),
(13, 7, 80035, 0, 0, 31, 0, 3, 42362, 0, 0, 0, '', 'Vengeful Rage - Drakonid Drudge'),
(13, 1, 79580, 0, 0, 31, 0, 3, 42690, 0, 0, 0, '', 'Overhead Smash - Overhead Smash'),
(13, 1, 91906, 0, 0, 31, 0, 3, 42690, 0, 0, 0, '', 'Overhead Smash - Overhead Smash');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_magmaw_captured';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88200, 'spell_magmaw_captured');

DELETE FROM `spell_custom_attr` WHERE `entry`= 79461;
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(79461, 0x1000 |0x2000 | 0x4000);

UPDATE `creature_template` SET `mechanic_immune_mask`= 1 | 2 | 8 | 16 | 32 | 64 | 256 | 512 | 2048 | 4096 | 8192 | 65536 | 131072 | 4194304 | 8388608 | 33554432 | 67108864 WHERE `entry` IN (42649, 49490);
UPDATE `creature_template` SET `DamageModifier`= 100, `BaseVariance`= 1 WHERE `entry` IN (42649, 49490);
UPDATE `creature_template` SET `difficulty_entry_1`= 49490, `AIName`='', `ScriptName`= 'npc_bwd_drakonid_chainwielder' WHERE `entry`= 42649;
UPDATE `creature_template` SET `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 42690;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_walk`= 1.2, `speed_run`= 1, `unit_flags`= 32832, `lootid`= 42649 WHERE `entry`= 49490;

-- Serverside Spells
DELETE FROM `spell_dbc` WHERE `Id`= 79578;
INSERT INTO `spell_dbc` (`Id`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `SchoolMask`, `Comment`) VALUES
(79578, 1, 205, 187, 0xA9000100, 0x00084004, 0x00040000, 0x00000080, 0x00000008, 1, '(Serverside/Non-DB2) Overhead Smash');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160107;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectBasePoints`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusMaxIndex`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `SpellID`, `EffectIndex`, `Comment`) VALUES
(160107, 28, 0, 42690, 64, 0, 0, 87, 0, 79578, 0, '');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_bwd_grievous_wound';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80051, 'spell_bwd_grievous_wound'),
(91910, 'spell_bwd_grievous_wound');
