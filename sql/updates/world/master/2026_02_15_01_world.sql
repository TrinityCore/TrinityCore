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
UPDATE `creature_template` SET `ScriptName`= 'npc_li_fei' WHERE `entry`=54135;
UPDATE `creature_template` SET `unit_flags`=`unit_flags` & ~0x100, `ScriptName`= 'npc_li_fei_combat' WHERE `entry`=54734; 

UPDATE `creature_template_difficulty` SET `StaticFlags1`=`StaticFlags1`|0x00000008 WHERE `entry`=54734;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_fire_crash', 'spell_feet_of_fury', 'spell_flying_shadow_kick');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(102499, 'spell_fire_crash'),
(108958, 'spell_feet_of_fury'),
(108936, 'spell_flying_shadow_kick');
