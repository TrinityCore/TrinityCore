-- hahahahahahahahahahahahaha oh god this is the most ridiculous blizzlike hack ever
-- seriously blizz devs WHAT WERE YOU THINKING
UPDATE `creature_template` SET `faction`=(1761+(`entry`-19300)),`scriptname`="boss_blackheart_the_inciter_mc_dummy" WHERE `entry` BETWEEN 19300 AND 19304;
DELETE FROM `creature` WHERE `id` BETWEEN 19300 and 19304;
