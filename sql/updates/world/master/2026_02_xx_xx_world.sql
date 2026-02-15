DELETE FROM `creature_addon` WHERE `guid`=450772;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(450772, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, '49414'); -- Aysa Cloudsinger - 49414 - Generic Quest Invisibility 1 - !!! already present in database !!!

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=64978 WHERE (`Entry`=54975 AND `DifficultyID`=0); -- 54975 (Aysa Cloudsinger) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-3, `LevelScalingDeltaMax`=-3, `ContentTuningID`=1723, `StaticFlags1`=0x10000000, `VerifiedBuild`=64978 WHERE (`Entry` IN (60250, 60249) AND `DifficultyID`=0); -- 60250 (Cai) - CanSwim

UPDATE `creature_template` SET `unit_flags3`=0x40000000 WHERE `entry`=54975; -- Aysa Cloudsinger
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_cai', `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=60250; -- Cai
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_deng', `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=60249; -- Deng

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (7784);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(7784, 'at_the_singing_pools_children_summon');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (116190, 116191);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(116190, 'spell_summon_child_1'),
(116191, 'spell_summon_child_2');

DELETE FROM `creature_text` WHERE (`CreatureID` IN (60250, 60249));
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `comment`) VALUES
(60250, 0, 0, 'Hey there! Are you the one that brought back the fire spirit?', 12, 0, 100, 3, 0, 0, 0, 59875, 'Cai to Deng'),
(60250, 1, 0, 'Of course he was hot! Don''t be dumb, Deng.', 12, 0, 100, 5, 0, 0, 0, 59877, 'Cai to Deng'),
(60250, 2, 0, 'Nuh uh. Bet they could for sure kick you over that hill, though! Hah!', 12, 0, 100, 274, 0, 0, 0, 59880, 'Cai to Deng'),
(60250, 3, 0, 'Okay bye.', 12, 0, 100, 3, 0, 0, 0, 59878, 'Cai to Deng'),
(60249, 0, 0, 'Was he hot?  I bet he was hot!', 12, 0, 100, 6, 0, 0, 0, 59876, 'Deng to Cai'),
(60249, 1, 0, 'I bet you''re really strong, huh?  You could probably kick that bridge right in half if you wanted to!', 12, 0, 100, 6, 0, 0, 0, 59879, 'Deng to Cai'),
(60249, 2, 0, 'Bye!', 12, 0, 100, 3, 0, 0, 0, 59884, 'Deng to Cai');


DELETE FROM `quest_template_addon` WHERE `ID` IN (29661, 29663, 29662);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29661, 0, 0, 0, 29521, 29676, -29661521, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(29663, 0, 0, 0, 29521, 29676, -29661521, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(29662, 0, 0, 0, 0, 29676, -29661521, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
