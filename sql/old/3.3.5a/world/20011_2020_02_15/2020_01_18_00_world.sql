-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN (29149, 29006, 28025, 28668, 28667, 29124, 28443, 28112, 28001, 28010, 29036, 28095);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(29149, 0, 0, 0, 1, 0, '50726'), -- 29149 - 50726
(29006, 0, 0, 0, 1, 0, '50503'), -- 29006 - 50503
(28025, 0, 0, 0, 1, 0, '50503'), -- 28025 - 50503
(28668, 0, 0, 0, 1, 0, '54176'), -- 28668 - 54176
(28667, 0, 0, 0, 1, 0, '50726 52119'), -- 28667 - 50726, 52119
(29124, 0, 0, 0, 1, 0, '53213 54189'), -- 29124 - 53213, 54189
(28443, 0, 0, 0, 1, 0, '51841'), -- 28443 - 51841
(28112, 0, 0, 0, 1, 0, '50726'), -- 28112 - 50726
(28001, 0, 0, 0, 1, 0, '44366'), -- 28001 - 44366
(28010, 0, 0, 0, 1, 0, '54913'), -- 28010 - 54913
(29036, 0, 0, 0, 1, 0, '52948 61750 61751'), -- 29036 - 52948, 61750, 61751
(28095, 0, 0, 0, 1, 0, '52162'); -- 28095 - 52162

DELETE FROM `creature_addon` WHERE `guid` IN (151894,98348,102744);
UPDATE `creature_template_addon` SET `path_id`=1518940, `auras`="44366" WHERE `entry` IN (28297);
UPDATE `creature_template_addon` SET `auras`="29266", `bytes1`=0 WHERE `entry` IN (28464);
UPDATE `creature_template_addon` SET `auras`="52948" WHERE `entry` IN (28320);
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry` IN (28538);
UPDATE `creature` SET `unit_flags`=570425872 WHERE `guid` IN (40461, 40456, 40460, 40454, 40466, 40458, 40451, 40455,40453,40457, 40459);
UPDATE `creature` SET `unit_flags`=512 WHERE `guid` IN (40452, 40462, 40467);

DELETE FROM `creature_addon` WHERE `guid` IN (40452, 40462, 40467, 40271,40278,40276);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(40452,0, 0, 0, 1, 0, '52948'),
(40462,0, 0, 0, 1, 0, '52948'),
(40467,0, 0, 0, 1, 0, '52948'),
(40271,0, 0, 0, 1, 69, ''),
(40278,0, 0, 0, 1, 69, ''),
(40276,0, 0, 0, 1, 69, '');
