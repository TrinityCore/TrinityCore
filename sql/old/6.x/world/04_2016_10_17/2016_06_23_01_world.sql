-- Make both quests 24812 & 24813 available to players: you must complete both quests to take next one, quest 24814.
UPDATE `quest_template_addon` SET `ExclusiveGroup`= -24812 WHERE `id` IN (24812, 24813);
