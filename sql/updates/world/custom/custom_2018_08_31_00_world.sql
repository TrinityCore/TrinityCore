
-- Template Updates
-- High Priest Venoxis
UPDATE `creature_template` SET `ScriptName`= 'boss_high_priest_venoxis', `DamageModifier`= 60, `BaseVariance`= 0.5, `mechanic_immune_mask`= 80297855, `mingold`= 20000, `maxgold`= 21000 WHERE `entry`= 52155;
-- Venomous Effusion
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 33556480, `flags_extra`= 128, `InhabitType`= 4 WHERE `entry`= 52288;
-- Pool of Acrid Tears
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 33556480, `flags_extra`= 128 WHERE `entry`= 52197;
-- Bloodvenom
UPDATE `creature_template` SET `speed_run`= 0.42857, `speed_walk`= 0.12, `unit_flags`= 34078720, `unit_flags2`= 33556480, `flags_extra`= 128 WHERE `entry`= 52525;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_venoxis_venomous_effusion',
'spell_venoxis_whispers_of_hethiss',
'spell_venoxis_toxic_link_targeting',
'spell_venoxis_toxic_link',
'spell_venoxis_toxic_link_ally',
'spell_venoxis_pool_of_acrid_tears',
'spell_venoxis_blood_venom_forcecast',
'spell_venom_withdrawal');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96680, 'spell_venoxis_venomous_effusion'),
(96466, 'spell_venoxis_whispers_of_hethiss'),
(96475, 'spell_venoxis_toxic_link_targeting'),
(96477, 'spell_venoxis_toxic_link'),
(96476, 'spell_venoxis_toxic_link_ally'),
(96520, 'spell_venoxis_pool_of_acrid_tears'),
(96842, 'spell_venoxis_blood_venom_forcecast'),
(96653, 'spell_venom_withdrawal');


-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (52288, 52197, 52525);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(52288, '96681'),
(52197, '96520'),
(52525, '97110');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 52155;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(52155, 0, 0, 'You disssssturb the plans of Gurubashi, little one.  It\'sss too late for you.  Too late for all of you!', 14, 0, 100, 0, 0, 24326, 50937, 'High Priest Venoxis - Aggro'),
(52155, 1, 0, 'Yesss...ssssuccumb to the venom...', 14, 0, 100, 0, 0, 24320, 50950, 'High Priest Venoxis - Whispers of Hethiss'),
(52155, 2, 0, 'Let the coils of death unfurl!', 14, 0, 100, 0, 0, 24319, 51382, 'High Priest Venoxis - Blessing of the Snake God'),
(52155, 3, 0, 'Hisss word, FILLS me, MY BLOOD IS VENOM, AND YOU WILL BATHE IN THE GLORY OF THE SNAKE GOD!!!', 14, 0, 100, 0, 0, 24321, 52073, 'High Priest Venoxis - Say Bloodvenom'),
(52155, 4, 0, '|TInterface\\Icons\\ability_creature_poison_06.blp:20|t High Priest Venoxis begins casting |cFFFF0000|Hspell:96637|h[Bloodvenom]|h|r!', 41, 0, 100, 0, 0, 0, 51033, 'High Priest Venoxis - Announce Bloodvenom'),
(52155, 5, 0, 'High Priest Venoxis is exhausted!', 41, 0, 100, 0, 0, 0, 51034, 'High Priest Venoxis'),
(52155, 6, 0, 'The mortal coil unwindsss...', 41, 0, 100, 0, 0, 0, 51380, 'High Priest Venoxis - Slay 1'),
(52155, 6, 1, 'Your sssacrifice pleases him.', 41, 0, 100, 0, 0, 0, 51381, 'High Priest Venoxis - Slay 2'),
(52155, 7, 0, 'My death means...nothing...', 14, 0, 100, 0, 0, 24318, 51383, 'High Priest Venoxis - Death');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 96634 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 96634, 0, 0, 31, 0, 3, 52155, 0, 0, 0, '', 'Venoxis Ult Cosmetic Missile - Target High Priest Venoxis');

-- Waypoints
SET @NPC := 52302;
SET @PATH := @NPC * 10 + 1;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-12017.63,`position_y`=-1661.311,`position_z`=34.088 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12026.56,-1670.935,33.5924,0,0,0,0,100,0),
(@PATH,2,-12017.63,-1661.311,34.088,0,0,0,0,100,0),
(@PATH,3,-12009.14,-1668.432,32.60046,0,0,0,0,100,0),
(@PATH,4,-12006.23,-1665.151,32.83873,0,0,0,0,100,0),
(@PATH,5,-12000.44,-1670.092,32.40856,0,0,0,0,100,0),
(@PATH,6,-11994.2,-1663.372,32.44453,0,0,0,0,100,0),
(@PATH,7,-11978.91,-1677.668,32.78415,0,0,0,0,100,0),
(@PATH,8,-11989.17,-1688.754,32.31588,0,0,0,0,100,0),
(@PATH,9,-11994.42,-1684.13,32.31588,0,0,0,0,100,0),
(@PATH,10,-11990.18,-1679.264,32.31588,0,0,0,0,100,0),
(@PATH,11,-11994.79,-1675.155,32.31588,0,0,0,0,100,0),
(@PATH,12,-11999.01,-1679.781,32.31588,0,0,0,0,100,0),
(@PATH,13,-12004.95,-1674.781,32.40856,0,0,0,0,100,0),
(@PATH,14,-12009.21,-1679.031,32.40856,0,0,0,0,100,0),
(@PATH,15,-12017.35,-1671.651,32.40856,0,0,0,0,100,0);

SET @NPC := 52302;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11991.27,`position_y`=-1723.13,`position_z`=32.76447 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11998.44,-1710.416,32.30133,0,0,0,0,100,0),
(@PATH,2,-12001.83,-1713.524,32.5653,0,0,0,0,100,0),
(@PATH,3,-11991.27,-1723.13,32.76447,0,0,0,0,100,0),
(@PATH,4,-11983.52,-1714.759,32.67511,0,0,0,0,100,0),
(@PATH,5,-11978.05,-1719.528,33.12287,0,0,0,0,100,0),
(@PATH,6,-11971.85,-1713.589,32.74445,0,0,0,0,100,0),
(@PATH,7,-11977.01,-1708.417,32.62214,0,0,0,0,100,0),
(@PATH,8,-11969.95,-1700.295,32.88337,0,0,0,0,100,0),
(@PATH,9,-11974.53,-1695.618,32.56588,0,0,0,0,100,0),
(@PATH,10,-11969.65,-1690.429,32.69088,0,0,0,0,100,0),
(@PATH,11,-11975.91,-1684.455,32.82199,0,0,0,0,100,0),
(@PATH,12,-11985.76,-1694.698,32.31588,0,0,0,0,100,0),
(@PATH,13,-11980.35,-1700.076,32.30133,0,0,0,0,100,0),
(@PATH,14,-11986.71,-1706.908,32.30133,0,0,0,0,100,0),
(@PATH,15,-11996.84,-1697.576,32.31588,0,0,0,0,100,0),
(@PATH,16,-11993.94,-1694.17,32.31588,0,0,0,0,100,0),
(@PATH,17,-11999.01,-1689.167,32.31588,0,0,0,0,100,0);

-- Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 52155;
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(52155, 395, 7000);

DELETE FROM `creature_loot_template` WHERE `Entry`= 52155;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
(52155, 521550, 100, 1, 521550, 1);

DELETE FROM `reference_loot_template` WHERE `Entry`= 521550;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(521550, 69603, 0, 1, 1, 1, 1),
(521550, 69600, 0, 1, 1, 1, 1),
(521550, 69604, 0, 1, 1, 1, 1),
(521550, 69601, 0, 1, 1, 1, 1),
(521550, 69602, 0, 1, 1, 1, 1);

-- Delete encounter related creatures
DELETE FROM `creature` WHERE `guid` IN (294881, 294905, 294983, 294972, 294882, 294904, 294966, 294987, 294960, 294951, 294985, 294979, 294973, 294968, 294955, 294977, 294965, 294950, 294975, 294962, 294957, 294954, 294949, 294952, 294961, 294969, 294971, 294978, 294982, 294984, 294956, 294953);
DELETE FROM `creature_addon` WHERE `guid` IN (294881, 294905, 294983, 294972, 294882, 294904, 294966, 294987, 294960, 294951, 294985, 294979, 294973, 294968, 294955, 294977, 294965, 294950, 294975, 294962, 294957, 294954, 294949, 294952, 294961, 294969, 294971, 294978, 294982, 294984, 294956, 294953);
