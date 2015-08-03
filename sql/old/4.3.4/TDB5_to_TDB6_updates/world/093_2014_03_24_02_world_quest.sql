-- Fix for Expression of Gratitude quest chain ( http://www.wowwiki.com/Quest:Expression_of_Gratitude )
-- Cast Phase Shift: Garm Assault (54635) on player once Know No Fear (12822) quest is taken.
DELETE FROM `spell_area` WHERE `spell`=54635 AND `area`=4461;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(54635, 4461, 12822, 0, 0, 0, 2, 1, 74, 1);

-- Ample Inspiration (12828) needs Expression of Gratitude (12836) quest completed (https://www.youtube.com/watch?v=lwHuQAL51m0, https://www.youtube.com/watch?v=K_rsnPXwouY)
UPDATE `quest_template` SET `PrevQuestId`=12836 WHERE `Id`=12828;

-- Opening the Backdoor (12821) needs Ample Inspiration (12828) quest completed (https://www.youtube.com/watch?v=K_rsnPXwouY, https://www.youtube.com/watch?v=DzLrImBiYvM)
UPDATE `quest_template` SET `PrevQuestId`=12828 WHERE `Id`=12821;

-- Overstock (12833) needs Demolitionist Extraordinaire (12824) quest completed (http://www.wowhead.com/quest=12833#comments:id=468099)
UPDATE `quest_template` SET `PrevQuestId`=12824 WHERE `Id`=12833;

UPDATE `gameobject` SET `phaseMask`=3 WHERE `guid`=58035;
