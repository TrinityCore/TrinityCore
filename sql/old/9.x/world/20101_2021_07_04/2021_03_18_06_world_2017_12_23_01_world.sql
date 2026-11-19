SET @CGUID :=79369; -- 2 Guids needed
DELETE FROM `creature` WHERE `guid` IN(@CGUID,  @CGUID+1);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnDifficulties`,`PhaseId`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@CGUID,16980,649,0,0,'3,4,5,6',0,0,0,646.073,60.3333,394.856,0,7200,0,0,4120,0,0,0,0,0,'',0), -- Lich King voice
(@CGUID+1,34564,649,0,0,'3,4,5,6',0,0,0,783.9305,132.9722,142.6711,3.141593,7200,0,0,4120,0,0,0,0,0,'',0); -- Anub'arak

DELETE FROM `creature_text` WHERE `CreatureID`=16980 AND `GroupId` IN (4,5); -- The Lich King Voice
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(16980,4,0,'You will have your challenge, Fordring.',14,0,100,0,0,16321,35747,0,'The Lich King SAY CHALLENGE'),
(16980,5,0,'The souls of your fallen champions will be mine, Fordring.',14,0,100,0,0,16323,35749,0,'The Lich King SAY SOULS WILL BE MINE');

DELETE FROM `creature_text` WHERE `CreatureID`=35877; -- Lich King
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(35877,0,0,'The Nerubians built an empire beneath the frozen wastes of Northrend. An empire that you so foolishly built your structures upon. MY EMPIRE.',14,0,100,11,0,16322,35748,0,'The Lich King SAY EMPIRE');

DELETE FROM `creature` WHERE `id`=34816; -- Barrett

-- 34854 (Fire Bomb)
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=34854;
DELETE FROM `creature_template_addon`WHERE `entry`=34854;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(34854,0,0,16908544,1,0,'66318'); -- Fire Bomb Aura

-- Added trigger flag in Slime Pool
UPDATE `creature_template` SET `ScriptName`='npc_jormungars_slime_pool' WHERE `entry`=35176;
DELETE FROM `creature_template_addon`WHERE `entry`=35176;

UPDATE `creature_template` SET `flags_extra`=128, `ScriptName`='npc_beasts_combat_stalker' WHERE `entry`=36549;
UPDATE `creature_template` SET `ScriptName`='npc_open_portal_target_toc' WHERE `entry`=17965;

UPDATE `conditions` SET `Comment`='Effect_0 hits Gormok the Impaler' WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=66636;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=67888; -- Fel Lightning
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,67888,0,0,31,0,3,35458,0,0,0,0,'','Effect_0 hits Wilfred Fizzlebang');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=67864; -- Open Portal
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,67864,0,0,31,0,3,17965,0,0,0,0,'','Effect_0 hits Open Portal Target');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=69016; -- Corpse Teleport
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,69016,0,0,31,0,3,34797,0,0,0,0,'','Effect_0 hits Icehowl'),
(13,1,69016,0,1,31,0,3,34780,0,0,0,0,'','Effect_0 hits Lord Jaraxxus'),
(13,1,69016,0,2,31,0,3,34496,0,0,0,0,'','Effect_0 hits Eydis Darkbane'),
(13,1,69016,0,3,31,0,3,34497,0,0,0,0,'','Effect_0 hits Fjola Lightbane');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gormok_fire_bomb';
-- 66729 Furious Charge Summon Stalker (SERVERSIDE)
DELETE FROM `serverside_spell_effect` WHERE `SpellID`=66729 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(66729, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35062, 64, 0, 0, 0, 0, 0, 0, 6, 53);
-- 66319 Summon Fire Bomb (SERVERSIDE)
DELETE FROM `serverside_spell` WHERE `Id`=66319;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(66319, 0, 0, 0, 0, 256, 268435456, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 125, 13, 0, 0, 0, -1, 0, 0, 0, 'Summon Fire Bomb', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=66319 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(66319, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34854, 64, 0, 0, 0, 0, 0, 0, 6, 53);


DELETE FROM `spell_linked_spell` WHERE `spell_effect`=68667 AND `type`=0;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_icehowl_arctic_breath',
'spell_icehowl_trample',
'spell_icehowl_massive_crash',
'spell_lich_king_teleport_corpse',
'spell_jormungars_burning_bile');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66688,'spell_icehowl_arctic_breath'),
(66734,'spell_icehowl_trample'),
(66683,'spell_icehowl_massive_crash'),
(69016,'spell_lich_king_teleport_corpse'),
(66870,'spell_jormungars_burning_bile'),
(67621,'spell_jormungars_burning_bile'),
(67622,'spell_jormungars_burning_bile'),
(67623,'spell_jormungars_burning_bile');

UPDATE `creature_text` SET `comment`='Icehowl - Roar' WHERE `CreatureID`=34797 AND`GroupID`=0 AND `ID`=0;
UPDATE `creature_text` SET `comment`='Icehowl - Fail' WHERE `CreatureID`=34797 and`GroupID`=1 AND `ID`=0;
UPDATE `creature_text` SET `comment`='Icehowl - Enrage' WHERE `CreatureID`=34797 and`GroupID`=2 AND `ID`=0;

-- Open Portal Target
UPDATE `creature_template` SET /*`modelid1`=20024, `modelid2`=0,*/ `ScriptName`='npc_open_portal_target_toc' WHERE `entry`=17965;
DELETE FROM `creature_template_addon`WHERE `entry`=17965;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(17965,0,0,16908544,50331648,0,'');

-- UPDATE `creature_template` SET `modelid1`=29890, `modelid2`=0, `modelid3`=0 WHERE `entry`=35651; -- Purple Ground Rune Argent Raid

DELETE FROM `creature_summon_groups` WHERE `summonerId`=34996;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(34996,0,1,34497,571.684,204.9028,399.263,4.590216,8,0), -- Fjola Lightbane
(34996,0,1,34496,555.4514,205.8889,399.2634,4.886922,8,0), -- Eydis Darkbane
(34996,0,1,34567,536.5504,164.5504,394.7856,0,8,0), -- Dark Essence
(34996,0,1,34567,588.2083,115.6667,394.5307,0,8,0), -- Dark Essence
(34996,0,1,34568,542.6441,117.3194,394.7847,0,8,0), -- Light Essence
(34996,0,1,34568,589.743,163.0955,394.7754,0,8,0); -- Light Essence

-- Barrett related stuffs
DELETE FROM `npc_text` WHERE `ID`=14852;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextID0`, `BroadcastTextID1`, `BroadcastTextID2`, `BroadcastTextID3`, `BroadcastTextID4`, `BroadcastTextID5`, `BroadcastTextID6`, `BroadcastTextID7`, `VerifiedBuild`) VALUES
(14852, 1, 0, 0, 0, 0, 0, 0, 0, 36084, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `gossip_menu_id`=10692 WHERE `entry`=35771;
UPDATE `creature_template` SET `gossip_menu_id`=10704 WHERE `entry`=35909;
UPDATE `creature_template` SET `npcflag`=1, `ScriptName`='npc_barrett_toc' WHERE `entry` IN (34816,35035,35766,35770,35771,35909);

DELETE FROM `gossip_menu` WHERE `MenuID` IN (10692,10693,10704,10705,10706,10610,10609,10599,10678,10687,10679,10688,10600);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES 
(10599,14664,0),
(10599,14667,0),
(10600,14665,0),
(10600,14668,0),
(10609,14678,0),
(10609,14679,0),
(10610,14680,0),
(10610,14682,0),
(10678,14813,0),
(10678,14815,0),
(10679,14819,0),
(10679,14820,0),
(10687,14814,0),
(10687,14816,0),
(10688,14821,0),
(10688,14822,0),
(10692,14828,0),
(10693,14829,0),
(10704,14667,0),
(10704,14850,0),
(10705,14852,0),
(10706,14853,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (10692,10693,10704,10705,10706,10610,10609,10599,10678,10687,10679,10688,10600);
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionIndex`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`) VALUES
(10599,0,0,'Yes. We are prepared for the challenges ahead of us.',35172,1,1),
(10599,1,0,'We want another shot at those beasts!',35215,1,1),
(10600,0,0,'Bring forth the first challenge!',35174,1,1),
(10600,1,0,'We\'re ready. This time things will be different.',35216,1,1),
(10609,0,0,'What new challenge awaits us?',35251,1,1),
(10609,1,0,'We\'re ready to fight the sorceror again.',35254,1,1),
(10610,0,0,'I am ready for the next challenge.',35538,1,1),
(10610,1,0,'Now.',35258,1,1),
(10678,0,0,'Of course!',35987,1,1),
(10678,1,0,'You\'ll be even more amazed after we take them out!',35991,1,1),
(10679,0,0,'That tough, huh?',36024,1,1),
(10679,1,0,'We\'ll just have to improve our own teamwork to match the two of them.',36025,1,1),
(10687,0,0,'Give the signal! We\'re ready to go!',35989,1,1),
(10687,1,0,'We\'re ready for anything!',35993,1,1),
(10688,0,0,'Val\'kyr? We\'re ready for them.',36027,1,1),
(10688,1,0,'Just bring them out again, then watch.',36029,1,1),
(10692,0,0,'Your words of praise are appreciated, Coliseum Master.',36047,1,1),
(10693,0,0,'That is strange...',36049,1,1),
(10704,0,0,'I have completed the Trial of the Crusader.',36082,1,1),
(10704,1,0,'I have not completed the Trial of the Crusader.',36083,1,1),
(10704,2,0,'We want another shot at those beasts!',35215,1,1),
(10706,0,0,'Yes. We are prepared for the challenges ahead of us.',35172,1,1);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId` IN (10599,10609,10678,10679,10692,10704,10706);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES 
(10599, 0, 10600, 0),
(10599, 1, 10600, 0),
(10609, 0, 10610, 0),
(10609, 1, 10610, 0),
(10678, 0, 10687, 0),
(10678, 1, 10687, 0),
(10679, 0, 10688, 0),
(10679, 1, 10688, 0),
(10692, 0, 10693, 0),
(10704, 0, 10706, 0),
(10704, 1, 10705, 0),
(10704, 2, 10600, 0),
(10706, 0, 10600, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(14,15) AND `SourceGroup` IN(10704,10600,10599,10609,10610,10678,10687,10679,10688);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10704,0,0,0,17,0,3916,0,0,0,0,0,'','Show gossip option if player achieved Call of the Crusade (25 player)'),
(15,10704,0,0,0,19,0,8,0,0,0,0,0,'','Show gossip option if player is in 25 version'),
(15,10704,0,0,0,13,0,0,2,2,1,0,0,'','Show gossip option if player not failed to defeat Northrend Beasts'),
(15,10704,0,0,1,17,0,3917,0,0,0,0,0,'','Show gossip option if player achieved Call of the Crusade (10 player)'),
(15,10704,0,0,1,19,0,4,0,0,0,0,0,'','Show gossip option if player is in 10 version'),
(15,10704,0,0,1,13,0,0,2,2,1,0,0,'','Show gossip option if player not failed to defeat Northrend Beasts'),
(15,10704,1,0,0,17,0,3916,0,0,1,0,0,'','Show gossip option if player not achieved Call of the Crusade (25 player)'),
(15,10704,1,0,0,19,0,8,0,0,0,0,0,'','Show gossip option if player is in 25 version'),
(15,10704,1,0,0,13,0,0,2,2,1,0,0,'','Show gossip option if player not failed to defeat Northrend Beasts'),
(15,10704,1,0,1,17,0,3917,0,0,1,0,0,'','Show gossip option if player not achieved Call of the Crusade (10 player)'),
(15,10704,1,0,1,19,0,4,0,0,0,0,0,'','Show gossip option if player is in 10 version'),
(15,10704,1,0,1,13,0,0,2,2,1,0,0,'','Show gossip option if player not failed to defeat Northrend Beasts'),
(15,10704,2,0,0,13,0,0,2,2,0,0,0,'','Show gossip option if player failed to defeat Northrend Beasts'),
(14,10704,14667,0,0,13,0,0,2,2,0,0,0,'','Show gossip text if player failed to defeat Northrend Beasts'),
(14,10704,14850,0,0,13,0,0,2,2,1,0,0,'','Show gossip text if player not failed to defeat Northrend Beasts'),
(14,10600,14668,0,0,13,0,0,2,2,0,0,0,'','Show gossip text if player failed to defeat Northrend Beasts'),
(14,10600,14665,0,0,13,0,0,2,2,1,0,0,'','Show gossip text if player not failed to defeat Northrend Beasts'),
(15,10600,0,0,0,13,0,0,2,2,1,0,0,'','Show gossip option if player not failed to defeat Northrend Beasts'),
(15,10600,1,0,0,13,0,0,2,2,0,0,0,'','Show gossip option if player failed to defeat Northrend Beasts'),
(14,10599,14667,0,0,13,0,0,2,2,0,0,0,'','Show gossip text if player failed to defeat Northrend Beasts'),
(14,10599,14664,0,0,13,0,0,2,2,1,0,0,'','Show gossip text if player not failed to defeat Northrend Beasts'),
(15,10599,0,0,0,13,0,0,2,2,1,0,0,'','Show gossip option if player not failed to defeat Northrend Beasts'),
(15,10599,1,0,0,13,0,0,2,2,0,0,0,'','Show gossip option if player failed to defeat Northrend Beasts'),
(14,10609,14679,0,0,13,0,1,2,2,0,0,0,'','Show gossip text if player failed to defeat Jaraxxus'),
(14,10609,14678,0,0,13,0,1,2,2,1,0,0,'','Show gossip text if player not failed to defeat Jaraxxus'),
(15,10609,0,0,1,13,0,1,2,2,1,0,0,'','Show gossip option if player not failed to defeat Jaraxxus'),
(15,10609,1,0,0,13,0,1,2,2,0,0,0,'','Show gossip option if player failed to defeat Jaraxxus'),
(14,10610,14682,0,0,13,0,1,2,2,0,0,0,'','Show gossip text if player failed to defeat Jaraxxus'),
(14,10610,14680,0,0,13,0,1,2,2,1,0,0,'','Show gossip text if player not failed to defeat Jaraxxus'),
(15,10610,0,0,1,13,0,1,2,2,1,0,0,'','Show gossip option if player not failed to defeat Jaraxxus'),
(15,10610,1,0,0,13,0,1,2,2,0,0,0,'','Show gossip option if player failed to defeat Jaraxxus'),
(14,10678,14815,0,0,13,0,2,2,2,0,0,0,'','Show gossip text if player failed to defeat Faction Champions'),
(14,10678,14813,0,0,13,0,2,2,2,1,0,0,'','Show gossip text if player not failed to defeat Faction Champions'),
(15,10678,0,0,1,13,0,2,2,2,1,0,0,'','Show gossip option if player not failed to defeat Faction Champions'),
(15,10678,1,0,0,13,0,2,2,2,0,0,0,'','Show gossip option if player failed to defeat Faction Champions'),
(14,10687,14816,0,0,13,0,2,2,2,0,0,0,'','Show gossip text if player failed to defeat Faction Champions'),
(14,10687,14814,0,0,13,0,2,2,2,1,0,0,'','Show gossip text if player not failed to defeat Faction Champions'),
(15,10687,0,0,1,13,0,2,2,2,1,0,0,'','Show gossip option if player not failed to defeat Faction Champions'),
(15,10687,1,0,0,13,0,2,2,2,0,0,0,'','Show gossip option if player failed to defeat Faction Champions'),
(14,10679,14820,0,0,13,0,3,2,2,0,0,0,'','Show gossip text if player failed to defeat Valkyr'),
(14,10679,14819,0,0,13,0,3,2,2,1,0,0,'','Show gossip text if player not failed to defeat Valkyr'),
(15,10679,0,0,1,13,0,3,2,2,1,0,0,'','Show gossip option if player not failed to defeat Valkyr'),
(15,10679,1,0,0,13,0,3,2,2,0,0,0,'','Show gossip option if player failed to defeat Valkyr'),
(14,10688,14822,0,0,13,0,3,2,2,0,0,0,'','Show gossip text if player failed to defeat Valkyr'),
(14,10688,14821,0,0,13,0,3,2,2,1,0,0,'','Show gossip text if player not failed to defeat Valkyr'),
(15,10688,0,0,1,13,0,3,2,2,1,0,0,'','Show gossip option if player not failed to defeat Valkyrs'),
(15,10688,1,0,0,13,0,3,2,2,0,0,0,'','Show gossip option if player failed to defeat Valkyr');

-- Gormok
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34796 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34796, 1, 0, 4181, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34796 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34796, 1, 0, 0, 563.93580, 229.82990, 394.80610),
(34796, 1, 0, 1, 563.84190, 224.04790, 394.89610),
(34796, 1, 0, 2, 563.84190, 222.79790, 394.89610),
(34796, 1, 0, 3, 563.84190, 218.54790, 394.89610),
(34796, 1, 0, 4, 563.84190, 216.04790, 395.39610),
(34796, 1, 0, 5, 563.84190, 204.04790, 395.39610),
(34796, 1, 0, 6, 563.84190, 202.54790, 395.39610),
(34796, 1, 0, 7, 563.84190, 186.79790, 394.64610),
(34796, 1, 0, 8, 563.74800, 179.76600, 394.48620);

-- Dreadscale
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34799 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34799, 1, 0, 10805, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34799 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34799, 1, 0, 0, 564.36460, 231.48260, 394.83890),
(34799, 1, 0, 1, 564.32970, 232.48200, 394.83890),
(34799, 1, 0, 2, 564.36460, 231.48260, 394.83890),
(34799, 1, 0, 3, 564.12680, 236.13020, 394.70030),
(34799, 1, 0, 4, 564.49300, 221.61810, 394.64320),
(34799, 1, 0, 5, 563.88370, 194.52080, 395.24500),
(34799, 1, 0, 6, 567.82640, 182.76910, 395.20800),
(34799, 1, 0, 7, 576.53470, 168.95140, 394.70640),
(34799, 1, 0, 8, 576.53470, 168.95140, 394.70640);

-- Icehowl
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34797 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34797, 1, 0, 6729, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34797 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34797, 1, 0, 0, 563.71700, 230.39930, 394.81330),
(34797, 1, 0, 1, 563.73450, 231.39920, 394.81330),
(34797, 1, 0, 2, 563.71700, 230.39930, 394.81330),
(34797, 1, 0, 3, 563.60240, 228.03130, 394.70000),
(34797, 1, 0, 4, 563.71360, 192.86810, 394.63020),
(34797, 1, 0, 5, 563.85770, 176.58850, 394.44170),
(34797, 1, 0, 6, 563.85770, 176.58850, 394.44170);

-- Barrett Ramsay
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34816 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34816, 1, 0, 1544, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34816 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34816, 1, 0, 0, 559.14060, 90.272570, 395.27180),
(34816, 1, 0, 1, 561.59470, 84.008530, 395.22810),
(34816, 1, 0, 2, 563.54880, 78.744500, 395.18450);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=35909 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(35909, 1, 0, 1544, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=35909 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(35909, 1, 0, 0, 559.14060, 90.272570, 395.27180),
(35909, 1, 0, 1, 561.59470, 84.008530, 395.22810),
(35909, 1, 0, 2, 563.54880, 78.744500, 395.18450);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=35035 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(35035, 1, 0, 1544, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=35035 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(35035, 1, 0, 0, 559.14060, 90.272570, 395.27180),
(35035, 1, 0, 1, 561.59470, 84.008530, 395.22810),
(35035, 1, 0, 2, 563.54880, 78.744500, 395.18450);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=35766 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(35766, 1, 0, 1544, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=35766 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(35766, 1, 0, 0, 559.14060, 90.272570, 395.27180),
(35766, 1, 0, 1, 561.59470, 84.008530, 395.22810),
(35766, 1, 0, 2, 563.54880, 78.744500, 395.18450);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=35770 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(35770, 1, 0, 1544, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=35770 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(35770, 1, 0, 0, 559.14060, 90.272570, 395.27180),
(35770, 1, 0, 1, 561.59470, 84.008530, 395.22810),
(35770, 1, 0, 2, 563.54880, 78.744500, 395.18450);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=35771 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(35771, 1, 0, 1544, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=35771 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(35771, 1, 0, 0, 559.14060, 90.272570, 395.27180),
(35771, 1, 0, 1, 561.59470, 84.008530, 395.22810),
(35771, 1, 0, 2, 563.54880, 78.744500, 395.18450);

-- Wilfred
DELETE FROM `script_spline_chain_meta` WHERE `entry`=35458 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(35458, 1, 0, 10626, 9969),
(35458, 1, 1, 4280, 3203),
(35458, 1, 2, 5631, 5266),
(35458, 1, 3, 5325, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=35458 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(35458, 1, 0, 0, 563.60070, 208.52780, 395.26960),
(35458, 1, 0, 1, 563.58330, 209.52760, 395.26960),
(35458, 1, 0, 2, 563.60070, 208.52780, 395.26960),
(35458, 1, 0, 3, 563.62780, 203.76760, 395.21350),
(35458, 1, 0, 4, 563.72610, 186.49170, 394.56950),
(35458, 1, 0, 5, 563.75180, 181.98090, 394.51520),
(35458, 1, 0, 6, 563.75180, 181.98090, 394.51520),
(35458, 1, 1, 0, 563.74210, 183.67530, 394.53560),
(35458, 1, 1, 1, 563.69400, 182.07720, 394.71280),
(35458, 1, 1, 2, 563.64580, 172.97920, 394.39000),
(35458, 1, 2, 0, 563.67610, 175.55330, 394.42580),
(35458, 1, 2, 1, 563.68090, 173.01620, 394.65770),
(35458, 1, 2, 2, 563.68090, 168.01620, 394.65770),
(35458, 1, 2, 3, 563.68580, 161.47920, 394.38960),
(35458, 1, 3, 0, 563.68260, 162.41400, 394.38780),
(35458, 1, 3, 1, 563.66330, 161.52210, 394.43900),
(35458, 1, 3, 2, 563.66330, 152.77210, 394.43900),
(35458, 1, 3, 3, 563.64410, 149.13020, 393.99010);

-- Jaraxxus
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34780 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34780, 1, 0, 1354, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34780 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34780, 1, 0, 0, 563.84390, 141.65610, 393.98610),
(34780, 1, 0, 1, 563.82640, 140.65630, 393.98610),
(34780, 1, 0, 2, 563.81340, 139.47290, 393.90840),
(34780, 1, 0, 3, 563.77460, 135.96830, 393.90840),
(34780, 1, 0, 4, 563.75520, 134.21640, 394.23520),
(34780, 1, 0, 5, 563.72220, 131.23440, 393.99010),
(34780, 1, 0, 6, 563.72220, 131.23440, 393.99010);

-- Fjola Lightbane
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34497 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34497, 1, 0, 3499, 2438),
(34497, 1, 1, 3586, 2437),
(34497, 1, 2, 3214, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34497 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34497, 1, 0, 0, 571.68400, 204.90280, 399.26300),
(34497, 1, 0, 1, 571.73790, 204.94450, 401.48890),
(34497, 1, 0, 2, 571.73790, 203.69450, 401.48890),
(34497, 1, 0, 3, 571.73790, 190.69450, 401.48890),
(34497, 1, 0, 4, 571.79170, 184.48610, 401.21480),
(34497, 1, 1, 0, 571.75040, 192.30170, 401.20640),
(34497, 1, 1, 1, 572.04100, 190.26200, 401.45710),
(34497, 1, 1, 2, 572.04100, 184.76200, 401.45710),
(34497, 1, 1, 3, 579.29100, 181.01200, 401.45710),
(34497, 1, 1, 4, 583.33160, 178.72220, 401.20780),
(34497, 1, 2, 0, 576.00200, 182.38320, 401.21590),
(34497, 1, 2, 1, 579.49060, 180.61520, 401.46680),
(34497, 1, 2, 2, 583.24060, 178.61520, 401.46680),
(34497, 1, 2, 3, 583.49060, 176.36520, 401.46680),
(34497, 1, 2, 4, 584.47920, 167.84720, 400.71780);

-- Eydis Darkbane
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34496 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34496, 1, 0, 4306, 3594),
(34496, 1, 1, 3304, 2437),
(34496, 1, 2, 2047, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34496 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34496, 1, 0, 0, 555.45140, 205.88890, 399.26340),
(34496, 1, 0, 1, 555.51310, 205.85760, 401.48250),
(34496, 1, 0, 2, 555.51310, 203.60760, 401.48250),
(34496, 1, 0, 3, 555.26310, 198.60760, 401.48250),
(34496, 1, 0, 4, 555.07460, 179.82640, 401.20160),
(34496, 1, 1, 0, 555.14360, 184.59820, 401.20050),
(34496, 1, 1, 1, 554.95030, 180.11680, 401.48760),
(34496, 1, 1, 2, 547.70030, 178.11680, 401.23760),
(34496, 1, 1, 3, 542.45030, 176.36680, 401.48760),
(34496, 1, 1, 4, 540.25700, 175.63540, 400.77480),
(34496, 1, 2, 0, 546.12530, 177.29520, 401.19950),
(34496, 1, 2, 1, 542.29610, 176.19790, 401.47940),
(34496, 1, 2, 2, 540.54610, 175.69790, 400.97940),
(34496, 1, 2, 3, 540.46700, 170.60070, 400.75930);

-- Lich King
DELETE FROM `script_spline_chain_meta` WHERE `entry`=35877 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(35877, 1, 0, 4474, 3594),
(35877, 1, 1, 2894, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=35877 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(35877, 1, 0, 0, 563.57120, 175.83510, 394.49540),
(35877, 1, 0, 1, 563.57120, 174.83510, 394.49540),
(35877, 1, 0, 2, 563.56950, 173.12000, 394.39130),
(35877, 1, 0, 3, 563.56410, 167.81720, 394.29680),
(35877, 1, 0, 4, 563.54860, 152.47400, 394.39250),
(35877, 1, 0, 5, 563.54860, 152.47400, 394.39250),
(35877, 1, 1, 0, 563.55220, 156.01330, 394.37050),
(35877, 1, 1, 1, 563.54960, 152.56310, 394.63950),
(35877, 1, 1, 2, 563.54960, 147.56310, 394.13950),
(35877, 1, 1, 3, 563.54960, 145.31310, 394.13950),
(35877, 1, 1, 4, 563.54960, 144.31310, 394.38950),
(35877, 1, 1, 5, 563.54690, 141.61290, 393.90840);
