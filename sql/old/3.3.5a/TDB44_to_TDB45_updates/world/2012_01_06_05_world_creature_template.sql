-- Creatures with EAI flag set but no EAI script
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (29329,29330,29333,29338);
