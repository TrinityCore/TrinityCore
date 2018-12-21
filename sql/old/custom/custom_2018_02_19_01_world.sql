-- Template Updates
-- "Captain" Cookie
UPDATE `creature_template` SET `unit_flags`= 33587264, `ScriptName`= 'boss_captain_cookie', `flags_extra`= 0 WHERE `entry`= 47739;
UPDATE `creature_template` SET `unit_flags`= 33587264, `minlevel`= 87, `maxlevel`= 87, `flags_extra`= 1 WHERE `entry`= 48944;
-- Cookie's Cauldron
UPDATE `creature_template` SET `unit_flags`= 2304, `VehicleId`= 1283 WHERE `entry`= 47754;
-- Food
UPDATE `creature_template` SET `unit_flags`= 768, `unit_flags2`= 67110912, `npcflag`= 16777216, `flags_extra`= 2  WHERE `entry` IN (48006, 48276, 48294, 48293, 48295, 48296, 48297, 48298, 48300, 48299, 48301, 48302);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 45979 AND `GroupID`= 3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(45979, 3, 0, 'A shadowy figure appears in the ship''s cabin!', 41, 0, 100, 0, 0, 0, 48276, 'General Purpose Bunny JMF to Player');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 89250 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89250, 0, 0, 31, 0, 3, 45979, 375838, 0, 0, '', 'Charge - Target General Purpose Bunny');

-- Creature Cookie's Cauldron 47754 SAI
SET @ENTRY := 47754;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 0, 0, 0, 0, 11, 89251, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 0 and 0 ms) - Self: Cast spell 89251 on Self // ");

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_cookie_throw_food_targeting',
'spell_cookie_satiated');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(89268, 'spell_cookie_throw_food_targeting'),
(89740, 'spell_cookie_throw_food_targeting'),
(90561, 'spell_cookie_throw_food_targeting'),
(90582, 'spell_cookie_throw_food_targeting'),
(90562, 'spell_cookie_throw_food_targeting'),
(90583, 'spell_cookie_throw_food_targeting'),
(90563, 'spell_cookie_throw_food_targeting'),
(90584, 'spell_cookie_throw_food_targeting'),
(90564, 'spell_cookie_throw_food_targeting'),
(90585, 'spell_cookie_throw_food_targeting'),
(90565, 'spell_cookie_throw_food_targeting'),
(90586, 'spell_cookie_throw_food_targeting'),
(89267, 'spell_cookie_satiated'),
(92834, 'spell_cookie_satiated');

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (48006, 48276, 48294, 48293, 48295, 48296, 48297, 48298, 48300, 48299, 48301, 48302);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
-- Delicious Food
(48006 ,'89730'),
(48294 ,'89730'),
(48296 ,'89730'),
(48297 ,'89730'),
(48300 ,'89730'),
(48301 ,'89730'),
-- Rooten Food
(48276, '95513'),
(48293, '95513'),
(48295, '95513'),
(48298, '95513'),
(48299, '95513'),
(48302, '95513');

-- Spellclick spells
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (48006, 48276, 48294, 48293, 48295, 48296, 48297, 48298, 48300, 48299, 48301, 48302);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
-- Delicious Food
(48006, 89267, 3, 0),
(48294, 89267, 3, 0),
(48296, 89267, 3, 0),
(48297, 89267, 3, 0),
(48300, 89267, 3, 0),
(48301, 89267, 3, 0),
-- Rotten Food
(48276, 89732, 3, 0),
(48293, 89732, 3, 0),
(48295, 89732, 3, 0),
(48298, 89732, 3, 0),
(48299, 89732, 3, 0),
(48302, 89732, 3, 0);

-- SAI
SET @ENTRY := 48302;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48299;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48298;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48295;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48293;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48276;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48301;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48300;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48296;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48294;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

SET @ENTRY := 48006;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 73, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Self: Despawn instantly // ");

-- Loot
UPDATE `creature_template` SET `lootid`= 47739 WHERE `entry`= 47739;
UPDATE `creature_template` SET `lootid`= 48944 WHERE `entry` = 48944;
DELETE FROM creature_loot_template WHERE `Entry` IN (47739, 48944);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(47739, 5193, 0, 1, 1, 1, 1),
(47739, 5202, 0, 1, 1, 1, 1),
(47739, 5192, 0, 1, 1, 1, 1),
(47739, 5197, 0, 1, 1, 1, 1),
(47739, 5198, 0, 1, 1, 1, 1);

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(48944, 65177, 0, 1, 1, 1, 1),
(48944, 65174, 0, 1, 1, 1, 1),
(48944, 65173, 0, 1, 1, 1, 1),
(48944, 65171, 0, 1, 1, 1, 1),
(48944, 65172, 0, 1, 1, 1, 1);
