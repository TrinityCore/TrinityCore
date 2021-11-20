-- Patch 2.2.0 (2007-09-25): The following old-world factions have had their acquisition rate significantly increased: Cenarion Circle, Argent Dawn and Timbermaw Hold.
-- x2 in 2.2.0
-- x4 somewhere in 3xx for Timbermaw Hold (already adjusted)
UPDATE `reputation_reward_rate` SET `quest_rate` = 2, `quest_repeatable_rate` = 2 WHERE `faction` IN (529,609);
