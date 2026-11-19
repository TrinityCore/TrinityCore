-- Zuhuled the Wacked
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=10866;
DELETE FROM `quest_start_scripts` WHERE `id`=10866;
