-- Template Updates
-- Erudax
UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `scriptname`= 'boss_erudax', `flags_extra`= `flags_extra`|1073741824  WHERE `entry`= 40484;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `mechanic_immune_mask`= 667893759, `flags_extra`= `flags_extra`|1073741824 WHERE `entry`= 48822;
-- Faceless Portal Stalker
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 131 WHERE `entry`= 44314;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`= 44314;
-- Shadow Gale Stalker
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 40567;
-- Faceless Corruptor
UPDATE `creature_template` SET `scriptname`= 'npc_erudax_faceless_corruptor', `mechanic_immune_mask`= 634339327, `flags_extra`= 1073741824 WHERE `entry` IN (40600, 48844);
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `flags_extra`= 1073741824 WHERE `entry` IN (48828, 48845);
-- Alexstrasza's Egg
UPDATE `creature_template` SET `RegenHealth`= 0 WHERE `entry`= 40486;
-- Twilight Hatchling
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (39388, 48832);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (75656, 75664, 91086, 75520, 91049, 75763, 91040, 75809) AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ScriptName, Comment) VALUES
(13, 1, 75656, 0, 0, 31, 0, 3, 40566, 0, 0, 0, '', 'Shadow Gale Trigger - Target Shadow Gale Controller'),
(13, 1, 75664, 0, 0, 31, 0, 3, 40567, 0, 0, 0, '', 'Shadow Gale - Target Shadow Gale Stalker'),
(13, 1, 91086, 0, 0, 31, 0, 3, 40567, 0, 0, 0, '', 'Shadow Gale - Target Shadow Gale Stalker'),
(13, 1, 75520, 0, 0, 31, 0, 3, 40486, 0, 0, 0, '', 'Twilight Corruption - Target Alexstrasza''s Egg'),
(13, 1, 91049, 0, 0, 31, 0, 3, 40486, 0, 0, 0, '', 'Twilight Corruption - Target Alexstrasza''s Egg'),
(13, 1, 75763, 0, 0, 31, 0, 3, 40484, 0, 0, 0, '', 'Umbral Mending - Target Erduax'),
(13, 1, 91040, 0, 0, 31, 0, 3, 40484, 0, 0, 0, '', 'Umbral Mending - Target Erduax'),
(13, 1, 75809, 0, 0, 31, 0, 3, 40600, 0, 0, 0, '', 'Shield of Nightmares - Target Faceless Corruptor'),
(13, 1, 75809, 0, 1, 31, 0, 3, 48844, 0, 0, 0, '', 'Shield of Nightmares - Target Faceless Corruptor');

DELETE FROM `creature_template_addon` WHERE `entry` IN (39388, 48832);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(39388, 76192),
(48832, 91044);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_erudax_shadow_gale_trigger',
'spell_erudax_shadow_gale',
'spell_erudax_shadow_gale_aura',
'spell_erudax_twilight_corruption');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75656, 'spell_erudax_shadow_gale_trigger'),
(75692, 'spell_erudax_shadow_gale'),
(91087, 'spell_erudax_shadow_gale'),
(75694, 'spell_erudax_shadow_gale_aura'),
(75520, 'spell_erudax_twilight_corruption'),
(91049, 'spell_erudax_twilight_corruption');

-- Spell Target Positions
DELETE FROM `spell_target_position` WHERE `ID` IN (75704, 91072);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(75704, 0, 670, -620.443, -827.19, 241.8573, 3.184877, 15595),
(91072, 0, 670, -620.443, -827.19, 241.8573, 3.184877, 15595),
(91072, 1, 670, -620.443, -827.19, 241.8573, 3.184877, 15595);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 40484;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(40484, 0, 0, 'The darkest days are still ahead!', 14, 0, 100, 0, 0, 18638, 47770, 'Erudax - Aggro'),
(40484, 1, 0, '|TInterface\\Icons\\spell_shadow_shadowfury.blp:20|t%s begins to cast |cFFA043E7|Hspell:75694|h[Shadow Gale]|h|r!', 41, 0, 100, 0, 0, 0, 40609, 'Erudax - Announce Shadow Gale'),
(40484, 2, 0, 'F\'lakh ghet! The shadow\'s hunger cannot be sated!', 14, 0, 100, 0, 0, 18644, 47774, 'Erudax - Shadow Gale'),
(40484, 3, 0, 'Come, suffering... Enter, chaos!', 14, 0, 100, 0, 0, 18646, 40612, 'Erudax to Erudax'),
(40484, 4, 0, '%s summons a |cFFFF0000Faceless Guardian|r!', 41, 0, 100, 0, 0, 0, 0, 'Erudax to Erudax'),
(40484, 5, 0, '|TInterface\\Icons\\spell_shadow_sacrificialshield.blp:20|t%s begins to cast |cFF006EFD|Hspell:75809|h[Shield of Nightmares]|h|r on the |cFF006EFDFaceless Corruptor|r!', 41, 0, 100, 0, 0, 0, 40610, 'Erudax - Shield of Nightmares'),
(40484, 6, 0, 'Flesh for the offering!', 14, 0, 100, 0, 0, 18640, 47772, 'Erudax - Slay 1'),
(40484, 6, 1, 'Ahahaha!', 16, 0, 100, 0, 0, 18639, 47771, 'Erudax - Slay 2'),
(40484, 7, 0, 'Ywaq maq oou; ywaq maq ssaggh. Yawq ma shg\'fhn.', 14, 0, 100, 0, 0, 18641, 47773, 'Erudax - Death');

-- Achiement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 16001;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(16001, 11, 0, 0, 'achievement_dont_need_to_break_eggs');

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (40484, 48822);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(40484, 395, 3500),
(48822, 395, 7000);

-- Loot
UPDATE `creature_template` SET `lootid`= 40484 WHERE `entry`= 40484;
UPDATE `creature_template` SET `lootid`= 48822 WHERE `entry`= 48822;
DELETE FROM `creature_loot_template` WHERE `entry` IN (40484, 48822);
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(40484, 404840, 100, 1, 0, 2, 2),
(48822, 488220, 100, 1, 0, 2, 2);

DELETE FROM `reference_loot_template` WHERE `entry` IN (404840, 488220);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal
(404840, 56133, 0, 1, 1, 1, 1),
(404840, 56128, 0, 1, 1, 1, 1),
(404840, 56135, 0, 1, 1, 1, 1),
(404840, 56129, 0, 1, 1, 1, 1),
(404840, 56136, 0, 1, 1, 1, 1),
(404840, 56138, 0, 1, 1, 1, 1),
(404840, 56132, 0, 1, 1, 1, 1),
(404840, 56130, 0, 1, 1, 1, 1),
(404840, 56131, 0, 1, 1, 1, 1),
(404840, 56137, 0, 1, 1, 1, 1),
-- Heroic
(488220, 56460, 0, 1, 1, 1, 1),
(488220, 56455, 0, 1, 1, 1, 1),
(488220, 56464, 0, 1, 1, 1, 1),
(488220, 56457, 0, 1, 1, 1, 1),
(488220, 56463, 0, 1, 1, 1, 1),
(488220, 56462, 0, 1, 1, 1, 1),
(488220, 56458, 0, 1, 1, 1, 1),
(488220, 56459, 0, 1, 1, 1, 1),
(488220, 56456, 0, 1, 1, 1, 1),
(488220, 56461, 0, 1, 1, 1, 1),
(488220, 52078, 100, 1, 2, 1, 1); -- Chaos Orb
