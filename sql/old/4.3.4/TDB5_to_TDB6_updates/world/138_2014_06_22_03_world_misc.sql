-- QUEST The Plains of Nasam
SET @GUID := 76299; -- set the guid for spawning 6 are required
DELETE FROM `creature` WHERE id =25334;

INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID, 25334, 571, 1, 1, 2792.044, 6738.573, 7.797749, 4.34587, 120, 0, 0), -- 25334 (Area: 4130)
(@GUID+1, 25334, 571, 1, 1, 2798.961, 6735.21, 7.625851, 4.276057, 120, 0, 0), -- 25334 (Area: 4130)
(@GUID+2, 25334, 571, 1, 1, 2784.335, 6742.207, 7.92973, 4.29351, 120, 0, 0), -- 25334 (Area: 4130)
(@GUID+3, 25334, 571, 1, 1, 2766.58, 6751.198, 7.29528, 4.258604, 120, 0, 0), -- 25334 (Area: 4130)
(@GUID+4, 25334, 571, 1, 1, 2777.034, 6745.713, 7.899116, 4.29351, 120, 0, 0), -- 25334 (Area: 4130)
(@GUID+5, 25334, 571, 1, 1, 2807.21, 6730.922, 7.841674, 4.433136, 120, 0, 0); -- 25334 (Area: 4130)

UPDATE `creature_template` SET `faction`=1981, `unit_flags`=4096, `dynamicflags`=0,`speed_walk`=1.2, `speed_run`=2 WHERE `entry`=25334;

DELETE FROM `spell_area` WHERE `spell`=47917 AND  `area` IN(4027,4130);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(47917, 4027, 11652, 11652, 0, 0, 2, 0, 64, 11),
(47917, 4130, 11652, 11652, 0, 0, 2, 0, 64, 11);

UPDATE `creature_template` SET `spell1`=50672, `spell2`=45750,`spell3`=50677, `spell4`=47849, `spell5`=47962, `Health_mod`=5, `Mana_mod`=5 WHERE `entry`=25334;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=25334 AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`) VALUES (25334, 46598, 1);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (27106, 27107, 27108, 27110);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27106, 27107, 27108, 27110) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27106, 0, 0, 1, 8, 0, 100, 1, 47962, 0, 0, 0, 85, 47967, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Injured Warsong Warrior - On Spell hit - Cast Killcredit on Invoker'),
(27106, 0, 1, 0, 61, 0, 100, 1, 47962, 0, 0, 0, 41, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Warsong Warrior - On Spell hit - Despawn after 1sec'),
(27107, 0, 0, 1, 8, 0, 100, 1, 47962, 0, 0, 0, 85, 47967, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Injured Warsong Mage - On Spell hit - Cast Killcredit on Invoker'),
(27107, 0, 1, 0, 61, 0, 100, 1, 47962, 0, 0, 0, 41, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Warsong Mage - On Spell hit - Despawn after 1sec'),
(27108, 0, 0, 1, 8, 0, 100, 1, 47962, 0, 0, 0, 85, 47967, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Injured Warsong Shaman - On Spell hit - Cast Killcredit on Invoker'),
(27108, 0, 1, 0, 61, 0, 100, 1, 47962, 0, 0, 0, 41, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Warsong Shaman - On Spell hit - Despawn after 1sec'),
(27110, 0, 0, 1, 8, 0, 100, 1, 47962, 0, 0, 0, 85, 47967, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Injured Warsong Ingenieur - On Spell hit - Cast Killcredit on Invoker'),
(27110, 0, 1, 0, 61, 0, 100, 1, 47962, 0, 0, 0, 41, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Warsong Ingenieur - On Spell hit - Despawn after 1sec');

-- NPC Scourge Plague Spreader
UPDATE `creature_template` SET `faction`=974, `unit_flags`=`unit_flags`|2|33554432 WHERE `entry`=25349;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|64 WHERE `entry` IN (25333, 25469, 25332);
-- NPC Abandoned Fuel Tank 
UPDATE `creature_template` SET `faction`=2022, `unit_flags`=`unit_flags`|2|4|33554432, `AIName`='SmartAI' WHERE `entry`=27064;    
DELETE FROM `smart_scripts` WHERE `entryorguid`=27064 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27064, 0, 0, 1, 9, 0, 100, 0, 0, 5, 30000, 35000, 85, 47916, 2, 0, 0, 0, 0, 11, 25334, 5, 0, 0, 0, 0, 0, 'Abandoned Fuel Tank - On Range 2yd - Cast Fuel'),
(27064, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 25334, 0, 0, 0, 0, 0, 0, 'Abandoned Fuel Tank - Linked with Previous Event - Say'),
(27064, 0, 2, 3, 11, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abandoned Fuel Tank - On Respawn - Disable Auto Attack'),
(27064, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abandoned Fuel Tank - On Respawn - Disable Combat Movement');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=27064 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 27064, 0, 1, 29, 0, 25334, 5, 0, 0, 0, 0, '', 'Execute SAI only if there is Horde Siege Tank within 2 yards');


UPDATE `creature_template` SET `npcflag`=16777216 WHERE  `entry`=25334;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=25334;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(16, 0, 25334, 0, 0, 23, 0, 4027, 0, 0, 0, 0, 0, '', 'Horde Siege Tank (Vehicle) Allowed in Coast of Echoes'),
(16, 0, 25334, 0, 1, 23, 0, 4130, 0, 0, 0, 0, 0, '', 'Horde Siege Tank (Vehicle) Allowed in Plains of Nasam');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=25334;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 25334, 46598, 0, 0, 9, 0, 11652, 0, 0, 0, 0, 0, '', 'Player must have The Plains of Nasam taken but not completed to use Horde Siege tank');

DELETE FROM `creature_template_addon` WHERE `entry` IN(25334,27064);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(25334, 0, 0x0, 0x101, ''), -- 25334
(27064, 0, 0x0, 0x1, '50162'); -- 27064 - 50162

-- Updated 14-06-22 - Kinzcool
DELETE FROM `creature_text` WHERE `entry`=25334;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(25334, 0, 0, '%s gains fuel.', 41, 0, 100, 0, 0, 0, 'Horde Siege Tank', 26171);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=45750;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(45750, 45749, 0, 'Land Mine Barrier'), -- Front
(45750, 45751, 0, 'Land Mine Barrier'), -- Front, Right
(45750, 45752, 0, 'Land Mine Barrier'), -- Front, Left
(45750, 45753, 0, 'Land Mine Barrier'), -- Back
(45750, 45754, 0, 'Land Mine Barrier'), -- Back, Left
(45750, 45755, 0, 'Land Mine Barrier'), -- Back, Right
(45750, 45756, 0, 'Land Mine Barrier'), -- Left
(45750, 47839, 0, 'Land Mine Barrier'); -- Right

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(50674);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 50674, 0, 0, 31, 0, 3, 0, 0, 0, 0, 0, '', 'The Demoralizer only hits unit'),
(13, 1, 50674, 0, 0, 31, 0, 3, 25334, 0, 1, 0, 0, '', 'The Demoralizer does not hit horde siege tank');
