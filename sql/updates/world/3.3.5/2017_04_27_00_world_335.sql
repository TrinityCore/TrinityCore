-- Fix for "Guarded Thunderbrew Barrel" and "Distracting Jarven"
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `id` in (308,403);
