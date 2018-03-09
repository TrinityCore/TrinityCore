DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=64799; -- Lightning Tether
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,64799,0,0,31,0,3,33293,0,0,0,0,'','Effect_0 hits XT002');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_xt002_exposed_heart',
'spell_xt002_energy_orb');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63849,'spell_xt002_exposed_heart'),
(62826,'spell_xt002_energy_orb');

DELETE FROM `spell_proc` WHERE `SpellId`=63849; -- Disable spell proc to effect_1
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(63849,0,0,0,0,0,0,0,0,0,32,0,0,0,0);

UPDATE `creature` SET `MovementType`=0, `Spawndist`=0 WHERE `id`=33337; -- XT-Toy Pile

UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=0.428571, `ScriptName`='npc_scrapbot' WHERE `entry`=33343;
UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=0.428571 WHERE `entry`=33887; -- Scrapbot
UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=0.428571 WHERE `entry` IN (33346,33886); -- Boombot
UPDATE `creature_template` SET `BaseAttackTime`=2000 WHERE `entry` IN (33293,33885); -- X002 (hi ariel, i'm stoling you xD)
UPDATE `creature_template` SET `mechanic_immune_mask`=617299839 WHERE `entry` IN (33329,33885); -- Heart immunes xD
