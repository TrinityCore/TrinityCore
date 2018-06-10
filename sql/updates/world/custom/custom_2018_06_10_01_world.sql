
-- Boss: Anraphet --
-- respawn time of wardens set to one day
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `map` = 644 AND `id` in (39800, 39801, 39802, 39803);

UPDATE `creature_template` SET `DamageModifier`= 80, `mingold`= 19000, `maxgold`= 21000 WHERE `entry`= 39788;
UPDATE `creature_template` SET `DamageModifier`= 80, `mingold`= 19000, `maxgold`= 21000 WHERE `entry`= 48902;

-- spell positions for wardens
DELETE FROM `spell_target_position` WHERE `ID` IN (82329, 82330, 82331, 82332);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(82329, 0, 644, -329.727, 481.142, 89.2101, -1), -- SW 
(82330, 0, 644, -329.962, 246.302, 89.2102, -1), -- SE
(82331, 0, 644, -223.26,  488.222, 89.2101, -1), -- NW
(82332, 0, 644, -223.049, 243.161, 89.2102, -1); -- NE

-- Water Warden gets Aqua Bomb aura on aggro.
DELETE FROM `creature_template_addon` WHERE `entry` = 39802;

-- Flame Warden spell script for Lava Eruption dummy
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_hoo_platform_teleport',
'spell_flame_warden_lava_eruption',
'spell_whirling_winds_movement',
'spell_anraphet_destruction_protocol',
'spell_anraphet_omega_stance',
'spell_anraphet_omega_stance_summon',
'spell_anraphet_omega_stance_spider_effect');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(82329, 'spell_hoo_platform_teleport'),
(82330, 'spell_hoo_platform_teleport'),
(82331, 'spell_hoo_platform_teleport'),
(82332, 'spell_hoo_platform_teleport'),
(77273, 'spell_flame_warden_lava_eruption'),
(77333, 'spell_whirling_winds_movement'),
(77437, 'spell_anraphet_destruction_protocol'),
(75622, 'spell_anraphet_omega_stance'),
(91208, 'spell_anraphet_omega_stance'),
(77106, 'spell_anraphet_omega_stance_summon'),
(91176, 'spell_anraphet_omega_stance_summon'),
(77127, 'spell_anraphet_omega_stance_spider_effect');

-- Vault of Lights achievement check spell not in dbc
DELETE FROM `spell_dbc` WHERE `Id` = 94067;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `SpellInterruptsId`, `Comment`) VALUES
(94067, 384, 0, 5, 256, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Vault of Lights achievement credit');

DELETE FROM `spelleffect_dbc` WHERE `Id` = 155917;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectValueMultiplier`, `EffectApplyAuraName`, `EffectAmplitude`, `EffectBasePoints`, `EffectBonusMultiplier`, `EffectDamageMultiplier`, `EffectChainTarget`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectRealPointsPerLevel`, `EffectSpellClassMaskA`, `EffectSpellClassMaskB`, `EffectSpellClassMaskC`, `EffectTriggerSpell`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(155917, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 94067, 0, '');

-- area trigger for Brann's emote
DELETE FROM `areatrigger_scripts` WHERE `entry` = 5811;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5811, 'at_hoo_brann_idle_emote');

-- speed corrections for Brann
UPDATE `creature_template` SET `speed_walk` = 2.5/2.5, `speed_run` = 7/2.5 WHERE `entry` = 39908;

-- delete menu condition (that is not even working)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 12512 AND `SourceEntry` = 17600;

DELETE FROM `creature_template_addon` WHERE `entry`= 41144;
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(41144, '91205');

-- broadcast text ids for Brann
UPDATE `creature_text` SET `BroadcastTextId` = 40231 WHERE `CreatureID` = 39908 AND `GroupID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 40232 WHERE `CreatureID` = 39908 AND `GroupID` = 1;
UPDATE `creature_text` SET `BroadcastTextId` = 40233 WHERE `CreatureID` = 39908 AND `GroupID` = 2;
UPDATE `creature_text` SET `BroadcastTextId` = 40234 WHERE `CreatureID` = 39908 AND `GroupID` = 3;
UPDATE `creature_text` SET `BroadcastTextId` = 40240 WHERE `CreatureID` = 39908 AND `GroupID` = 4;
UPDATE `creature_text` SET `BroadcastTextId` = 40235 WHERE `CreatureID` = 39908 AND `GroupID` = 5;
UPDATE `creature_text` SET `BroadcastTextId` = 40236 WHERE `CreatureID` = 39908 AND `GroupID` = 6;
UPDATE `creature_text` SET `BroadcastTextId` = 40270 WHERE `CreatureID` = 39908 AND `GroupID` = 7;
UPDATE `creature_text` SET `BroadcastTextId` = 40271 WHERE `CreatureID` = 39908 AND `GroupID` = 8;
UPDATE `creature_text` SET `BroadcastTextId` = 40272 WHERE `CreatureID` = 39908 AND `GroupID` = 9;
UPDATE `creature_text` SET `BroadcastTextId` = 40273 WHERE `CreatureID` = 39908 AND `GroupID` = 10;
UPDATE `creature_text` SET `BroadcastTextId` = 49687 WHERE `CreatureID` = 39908 AND `GroupID` = 11;
UPDATE `creature_text` SET `BroadcastTextId` = 49688 WHERE `CreatureID` = 39908 AND `GroupID` = 12;

-- idle text lines of Brann
DELETE FROM `creature_text` WHERE `CreatureID` = 39908 AND `GroupID` IN (13, 14);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39908, 13, 0, 'Blasted titans... Why do they use a different set of mechanisms at each of their installations?', 12, 0, 100, 432, 0, 0, 39940, 0, 'Brann Bronzebeard - idle'),
(39908, 14, 0, 'This symbol, I think I''ve seen this before...', 12, 0, 100, 432, 0, 0, 40104, 0, 'Brann Bronzebeard - idle'); 

-- missing npc text of Brann
DELETE FROM `npc_text` WHERE `ID` IN (15794);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextID0`, `BroadcastTextID1`, `BroadcastTextID2`, `BroadcastTextID3`, `BroadcastTextID4`, `BroadcastTextID5`, `BroadcastTextID6`, `BroadcastTextID7`, `VerifiedBuild`) VALUES
(15794, 1, 0, 0, 0, 0, 0, 0, 0, 40129, 0, 0, 0, 0, 0, 0, 0, -1);

-- gossip menus of Brann
DELETE FROM `gossip_menu` WHERE (`MenuID` = 11339 AND `TextID` = 15794) OR (`MenuID` = 11348 AND `TextID` = 15815) OR (`MenuID` = 12512 AND `TextID` = 17600);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11339, 15794, 0),
(11348, 15815, 0),
(12512, 17600, 0);

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (39788, 48902);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(39788, 395, 3500),
(48902, 395, 7000);
