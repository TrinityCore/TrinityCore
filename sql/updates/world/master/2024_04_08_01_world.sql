-- Add spellclick and questgiver flags
UPDATE `creature_template` SET `npcflag`=16777218 WHERE entry IN (187223,181494);

-- Spell Click
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (187223,181494);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(187223,362355,1,0),
(181494,362355,1,0);

-- Quest data
DELETE FROM `creature_queststarter` WHERE `id` IN (187223,181494) AND `quest`=64864;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(187223, 64864, 52649),
(181494, 64864, 52649);

-- Condition for Spell click event condition type Queststate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (187223,181494) AND `SourceEntry` IN (362355) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 187223, 362355, 0, 0, 47, 0, 64864, 8, 0, 0, 0, 0, '', 'Spellclick unit Kodethi <Dark Talons> will have Disintegrate cast on him if quest Awaken, Dracthyr'),
(18, 181494, 362355, 0, 1, 47, 0, 64864, 8, 0, 0, 0, 0, '', 'Spellclick unit Dervishian <Obsidian Warders> will have Disintegrate cast on him if quest Awaken, Dracthyr');

-- Quest Awaken, Dracthyr is not an auto accept quest
UPDATE `quest_template_addon` SET `SpecialFlags`=0 WHERE `ID`=64864;

-- Allow the aura when not on quest or when quest is in log
UPDATE `spell_area` SET `quest_start_status`=11 WHERE `spell` IN (369731,370112);
