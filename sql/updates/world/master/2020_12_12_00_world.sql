-- add Queststarter for first Quest
DELETE FROM `creature_queststarter` WHERE (`id`) = 53566 AND `quest` IN (30027, 30033, 30034, 30036, 30038);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(53566,30027), -- Monk & Prist
(53566,30033), -- Mage
(53566,30034), -- Hunter
(53566,30036), -- Rogue
(53566,30038); -- Warrior

-- add AllowableClasses to Quests
DELETE FROM `quest_template_addon` WHERE (`ID`) IN (30027,30033,30034,30036,30038);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(30027, 0, 528, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Monk & Priest
(30033, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 , ''), -- Mage
(30034, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Hunter
(30036, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Rogue
(30038, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Warrior

-- add Questender for first Quest
DELETE FROM `creature_questender` WHERE (`id`) = 53566 AND `quest` IN (30027, 30033, 30034, 30036, 30038);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(53566, 30027),
(53566, 30033),
(53566, 30034),
(53566, 30036),
(53566, 30038);

-- add Gameobject Loot for Quests
DELETE FROM `gameobject_loot_template` WHERE `Entry` = 210015;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(210015, 73210, 0, 100, 1, 1, 0, 1, 1, "Trainees sword"),
(210015, 73211, 0, 100, 1, 1, 0, 1, 1, "Trainees Crossbow "),
(210015, 76392, 0, 100, 1, 1, 0, 1, 1, "Trainees Hand Fan"),
(210015, 73209, 0, 100, 1, 1, 0, 1, 1, "Trainees Staff"),
(210015, 76390, 0, 100, 1, 1, 0, 1, 1, "Trainees Spellblade"),
(210015, 73212, 0, 100, 1, 1, 0, 1, 1, "Trainees Dagger"),
(210015, 73208, 0, 100, 1, 1, 0, 1, 1, "Trainees Dagger"),
(210015, 76391, 0, 100, 1, 1, 0, 1, 1, "Trainees Axe"),
(210015, 73213, 0, 100, 1, 1, 0, 1, 1, "Trainees Shield"),
(210015, 73207, 0, 100, 1, 1, 0, 1, 1, "Trainees Mace"),
(210015, 76393, 0, 100, 1, 1, 0, 1, 1, "Trainees Book of Prayers");