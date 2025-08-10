-- This Wouunded Mountaineer should be kneeling
DELETE FROM `creature_addon` WHERE `guid` IN (306342);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(306342, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Technician missing emotestate
DELETE FROM `creature_template_addon` WHERE `entry`=41393;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(41393, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '');

-- Warstrider Cannon SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=41366;
DELETE FROM `smart_scripts` WHERE `entryorguid`=41366 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(41366,0,0,0,1,0,100,1,1000,1000,1000,1000,0,11,46598,0,0,0,0,0,19,41365,1,0,0,0,0,0,0,'OOC cast ride vehicle once');

DELETE FROM `creature` WHERE `id`=41366;

DELETE FROM `vehicle_template_accessory` WHERE (`entry`=41365 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(41365, 41366, 0, 1, 'Warstrider Prototype - Warstrider Cannon', 8, 0); -- Warstrider Prototype - Warstrider Cannon

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=41365;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(41365, 46598, 1, 1);

-- Update movement for Warstrider Cannon
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (41366);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(41366,0,0,1,1,0,0,0);
