-- Taming the Wilds Quest data

-- Creature data
UPDATE `creature` SET `StringId`="garrick_briarpatch" WHERE `guid`=1051268;
UPDATE `creature` SET `StringId`="grimaxe_briarpatch" WHERE `guid`=1051271;

UPDATE `creature_template` SET `ScriptName`="npc_huxsworth_briarpatch" WHERE `entry`=154327;
UPDATE `creature_template` SET `ScriptName`="npc_dawntracker_briarpatch" WHERE `entry`=166996;

DELETE FROM `creature_text` WHERE `CreatureID` IN (154327,166996) AND `GroupID` IN (0,1);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(154327, 0, 0, 'We don''t have much time. You''ll have to learn fast.', 12, 0, 100, 0, 0, 152920, 190162, 0, 'Austin Huxworth'),
(154327, 1, 0, 'I''ve taught you the basics. Now find a beast and tame it.', 12, 0, 100, 0, 0, 152921, 190163, 0, 'Austin Huxworth'),
(166996, 0, 0, 'That shall have to do for now. Find a beast and tame it.', 12, 0, 100, 0, 0, 156740, 196683, 0, 'Mithdran Dawntracker');

-- Quest data
DELETE FROM `creature_queststarter` WHERE `id`=154327 AND `quest` IN (59342);
DELETE FROM `creature_queststarter` WHERE `id`=166996 AND `quest` IN (59937);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(154327, 59342, 45745), -- Taming the Wilds accept from Austin Huxworth "Hunter only"
(166996, 59937, 45745); -- Taming the Wilds accept from Mithdran Dawntracker "Hunter only"

DELETE FROM `creature_questender` WHERE `id`=154327 AND `quest`=59342;
DELETE FROM `creature_questender` WHERE `id`=166996 AND `quest`=59937;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(154327, 59342, 45745), -- Taming the Wilds turn in to Austin Huxworth
(166996, 59937, 45745); -- Taming the Wilds turn in to Mithdran Dawntracker

DELETE FROM `quest_template_addon` WHERE `ID` IN (59342,59937);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(59342,4,55173,0,'quest_taming_the_wilds_alliance'), -- Alliance "Hunter only"
(59937,4,59935,0,'quest_taming_the_wilds_horde'); -- Horde "Hunter only"

-- Spell data
DELETE FROM `spell_script_names` WHERE `spell_id` IN (316840, 316841);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(316840, 'spell_tutorial_health_dnt_proc_aura'),
(316841, 'spell_tutorial_health_dnt');

-- Conversation data
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (14613);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14613,76440,0,0,0,0,0,0,45745); -- Mithdran Dawntracker

DELETE FROM `conversation_line_template` WHERE `Id` IN (36602);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(36602,0,0,0,45745); -- Mithdran Dawntracker

DELETE FROM `conversation_template` WHERE `Id` IN (14613);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14613,36602,0,'',45745);

DELETE FROM `quest_template` WHERE `ID`=55607;
INSERT INTO `quest_template` (`ID`,`QuestType`,`RewardXPMultiplier`,`RewardMoneyMultiplier`,`RewardArtifactXPMultiplier`,`Flags`,`LogTitle`) VALUES
(55607,2,1,1,1,1024, '[Hidden Tracker] Quest Taming The Wilds Complete');
