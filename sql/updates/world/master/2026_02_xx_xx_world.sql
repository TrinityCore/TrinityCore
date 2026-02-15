-- GameObject Visibility
DELETE FROM `gameobject_addon` WHERE `guid`=300137;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `invisibilityType`, `invisibilityValue`, `WorldEffectID`, `AIAnimKitID`) VALUES
(300137, 0, 0, 0, 1, 20, 1000, 0, 0);

UPDATE `gameobject` SET `PhaseId`=504 WHERE `guid`=300148;

-- Talks
DELETE FROM `creature_text` WHERE `CreatureID` IN (54135) AND `GroupID` = 0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(54135, 0, 0, 'You have earned the right to proceed.  Huo lies beyond.', 12, 0, 100, 0, 0, 0, 55251, 0, 'Master Li Fei to Player');

-- ScriptNames
UPDATE `creature_template` SET `ScriptName`= 'npc_li_fei_fight' WHERE `entry`=54734; 
UPDATE `creature_template` SET `ScriptName`= 'npc_li_fei' WHERE `entry`=54135; 

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_fire_crash', 'spell_flying_shadow_kick', 'spell_fury_kick_channel');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(102499, 'spell_fire_crash'),
(108936, 'spell_flying_shadow_kick'),
(108958, 'spell_fury_kick_channel');

-- Creature Template Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=64978 WHERE (`Entry`=54734 AND `DifficultyID` IN (0, 1)); -- 54734 (Master Li Fei) - 
