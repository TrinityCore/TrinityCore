-- Fix Hunter Trainers offering Hunter quest to Rogues
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `id` IN (6721,6722);
