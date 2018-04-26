-- Template Updates
-- Admiral Ripsnarl
UPDATE `creature_template` SET `ScriptName`= 'boss_admiral_ripsnarl' WHERE `entry`= 47626;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `DamageModifier`= 30, `flags_extra`= 1 WHERE `entry`= 48943;
-- Vapor
UPDATE `creature_template` SET `minlevel`= 15, `maxlevel`= 15, `difficulty_entry_1`= 49241, `ScriptName`= 'npc_ripsnarl_vapor' WHERE `entry`= 47714;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 14, `DamageModifier`= 10 WHERE `entry`= 49241;


-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 47626;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(47626, 0, 0, 'Ah, fresh meat!', 14, 0, 100, 0, 0, 19882, 48179, 'Admiral Ripsnarl - Aggro'),
(47626, 1, 0, 'Do you feel that chill running up your spine?', 14, 0, 100, 0, 0, 19877, 47914, 'Admiral Ripsnarl - Fog 1'),
(47626, 2, 0, 'The fog is rolling in...', 14, 0, 100, 0, 0, 0, 47915, 'Admiral Ripsnarl - Fog 2'),
(47626, 3, 0, 'Your blood only increases my hunger!', 14, 0, 100, 0, 0, 19876, 48009, 'Admiral Ripsnarl - Slay'),
(47626, 4, 0, 'I can smell your fear...', 14, 0, 100, 0, 0, 19879, 48006, 'Admiral Ripsnarl - Go for the Throat 1'),
(47626, 4, 1, 'I will rip your heart from your chest!', 14, 0, 100, 0, 0, 19880, 48007, 'Admiral Ripsnarl - Go for the Throat 2'),
(47626, 5, 0, 'Multiple vapors appear from the fog!  Kill Admiral Ripsnarl before you are overwhelmed!', 41, 0, 100, 0, 0, 19878, 50851, 'Admiral Ripsnarl - Announce Vapor'),
(47626, 6, 0, 'You will...NOT find her...until it is too late...', 14, 0, 100, 0, 0, 19875, 48010, 'Admiral Ripsnarl - Death');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (95408) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 95408, 0, 0, 31, 0, 3, 48266, 0, 0, 0, '', 'Ripnsarl Cannon Kill - Target Defias Cannon');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_ripsnarl_go_for_the_throat_targeting',
'spell_ripsnarl_summon_vapor_targeting');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88838, 'spell_ripsnarl_go_for_the_throat_targeting'),
(88833, 'spell_ripsnarl_summon_vapor_targeting');

-- Loot
UPDATE `creature_template` SET `lootid`= 47626 WHERE `entry` = 47626;
DELETE FROM creature_loot_template WHERE `Entry` IN (47626, 48943);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(47626, 872, 0, 1, 1, 1, 1),
(47626, 5196, 0, 1, 1, 1, 1),
(47626, 1156, 0, 1, 1, 1, 1);

UPDATE `creature_template` SET `lootid`= 48943 WHERE `entry` = 48943;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(65168, 65166, 0, 1, 1, 1, 1),
(48943, 65170, 0, 1, 1, 1, 1),
(48943, 65169, 0, 1, 1, 1, 1);