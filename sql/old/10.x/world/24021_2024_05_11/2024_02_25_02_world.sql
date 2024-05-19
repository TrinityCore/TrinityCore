-- Frostmane Builder fixup
UPDATE `creature` SET `equipment_id`=2 WHERE `guid` IN (306720,306749,306685,306719,306721,306722,306725,306731,306748);
UPDATE `creature` SET `unit_flags`=537133824,`unit_flags2`=2049,`unit_flags3`=8192 WHERE `guid`=306672;

DELETE FROM `creature_addon` WHERE `guid` IN (306720,306749,306685,306719,306721,306722,306725,306731,306748,306672);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(306720, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- EMOTE_STATE_USE_STANDING
(306749, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- EMOTE_STATE_USE_STANDING
(306685, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- EMOTE_STATE_WORK
(306719, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- EMOTE_STATE_WORK
(306721, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- EMOTE_STATE_WORK
(306722, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- EMOTE_STATE_WORK
(306725, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- EMOTE_STATE_WORK
(306731, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- EMOTE_STATE_WORK
(306748, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- EMOTE_STATE_WORK
(306672, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '29266'); -- DEAD

DELETE FROM `creature_template_addon` WHERE `entry`=41251;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(41251, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, ''); -- EMOTE_STATE_WORK_CHOPWOOD

-- Covert Operative <Gnomeregan Covert Ops>
DELETE FROM `creature` WHERE `guid` IN (306637,306654);
UPDATE `creature` SET `unit_flags`=570721024,`unit_flags2`=2049,`unit_flags3`=8192 WHERE `guid`=306649;
DELETE FROM `creature_addon` WHERE `guid` IN (306671,306670,306645,306653,306649);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(306671, 0, 0, 0, 0, 0, 1, 1, 428, 0, 0, 0, 0, ''), -- EMOTE_STATE_LOOT
(306670, 0, 0, 0, 0, 0, 1, 1, 333, 0, 0, 0, 0, ''), -- EMOTE_STATE_READY1H
(306645, 0, 0, 0, 0, 0, 1, 1, 333, 0, 0, 0, 0, ''), -- EMOTE_STATE_READY1H
(306653, 0, 0, 0, 0, 0, 1, 1, 333, 0, 0, 0, 0, ''), -- EMOTE_STATE_READY1H
(306649, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '29266'); -- DEAD

-- Battok the Berserker
DELETE FROM `creature_template_addon` WHERE `entry`=41284;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(41284, 0, 0, 0, 0, 0, 1, 0, 10, 0, 0, 0, 0, ''); -- EMOTE_STATE_DANCE

-- Delete Vector Coil Fire (L) from frostmane Retreat 
DELETE FROM `gameobject` WHERE `guid` IN (217535,217536,217541,217542,217543,217544,217545,217546);

-- Frostmane Retreat North, Frostmane Retreat South, Bombardment Bunny, 
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (41372,41373,41375);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (41372,41373,41375);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(41372,0,0,1,1,0,0,0),
(41373,0,0,1,1,0,0,0),
(41375,0,0,1,1,0,0,0);
