-- Ordered by quest progression
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 0, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Gurgthock - On Script - Summon Group 0" WHERE `entryorguid` = 3000701 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 1, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Gurgthock - On Script - Summon Group 1" WHERE `entryorguid` = 3000702 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 2, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Gurgthock - On Script - Summon Group 2" WHERE `entryorguid` = 3000703 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 3, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Gurgthock - On Script - Summon Group 3" WHERE `entryorguid` = 3000707 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 4, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Gurgthock - On Script - Summon Group 4" WHERE `entryorguid` = 3000708 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 5, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Gurgthock - On Script - Summon Group 5" WHERE `entryorguid` = 3000709 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 6, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Gurgthock - On Script - Summon Group 6" WHERE `entryorguid` = 3000704 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 7, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Gurgthock - On Script - Summon Group 7" WHERE `entryorguid` = 3000705 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 8, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Gurgthock - On Script - Summon Group 8" WHERE `entryorguid` = 3000706 AND `source_type` = 9 AND `id` = 2;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 3000703 AND `source_type` = 9 AND `id` BETWEEN 3 AND 18;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3000707 AND `source_type` = 9 AND `id` BETWEEN 3 AND 18;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3000708 AND `source_type` = 9 AND `id` BETWEEN 3 AND 18;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3000709 AND `source_type` = 9 AND `id` BETWEEN 3 AND 18;

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 30007;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(30007,0,0,30014,5762.05,-2954.39,273.827,5.10829,2,300000,"Gurgthock - Group 0 - Yggdras"),
(30007,0,1,30017,5754.69,-2939.46,286.276,5.15638,2,300000,"Gurgthock - Group 1 - Stinkbeard"),
(30007,0,2,30024,5776.85,-2989.78,272.968,5.194,2,300000,"Gurgthock - Group 2 - Gargoral the Water Lord"),
(30007,0,2,30044,5739.81,-2981.52,290.767,5.98648,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5828.9,-2960.16,312.752,3.52556,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5743.31,-3011.3,290.767,0.610865,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5763.19,-3029.68,290.767,1.37881,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5793.06,-2934.59,286.36,4.08407,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5742.1,-2950.76,286.264,5.11381,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5828.5,-2981.74,286.36,3.14159,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5769.4,-2935.12,286.336,4.85202,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5820.31,-3002.84,290.767,2.58309,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5733.76,-3000.35,286.36,0.471239,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5724.98,-2969.9,286.36,6.05629,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5722.49,-3010.75,312.752,0.506145,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5744.42,-3025.53,286.36,0.942478,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5813.94,-2956.75,286.36,3.71755,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5797.32,-2955.27,290.767,4.11898,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,2,30044,5816.85,-2974.48,290.767,3.61283,2,300000,"Gurgthock - Group 2 - Fiend of Water"),
(30007,0,3,30026,5776.85,-2989.78,272.968,5.194,2,300000,"Gurgthock - Group 3 - Az'Barin, Prince of the Gust"),
(30007,0,3,30045,5739.81,-2981.52,290.767,5.98648,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5828.9,-2960.16,312.752,3.52556,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5743.31,-3011.3,290.767,0.610865,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5763.19,-3029.68,290.767,1.37881,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5793.06,-2934.59,286.36,4.08407,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5742.1,-2950.76,286.264,5.11381,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5828.5,-2981.74,286.36,3.14159,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5769.4,-2935.12,286.336,4.85202,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5820.31,-3002.84,290.767,2.58309,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5733.76,-3000.35,286.36,0.471239,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5724.98,-2969.9,286.36,6.05629,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5722.49,-3010.75,312.752,0.506145,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5744.42,-3025.53,286.36,0.942478,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5813.94,-2956.75,286.36,3.71755,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5797.32,-2955.27,290.767,4.11898,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,3,30045,5816.85,-2974.48,290.767,3.61283,2,300000,"Gurgthock - Group 3 - Fiend of Air"),
(30007,0,4,30019,5776.85,-2989.78,272.968,5.194,2,300000,"Gurgthock - Group 4 - Duke Singen"),
(30007,0,4,30042,5739.81,-2981.52,290.767,5.98648,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5828.9,-2960.16,312.752,3.52556,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5743.31,-3011.3,290.767,0.610865,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5763.19,-3029.68,290.767,1.37881,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5793.06,-2934.59,286.36,4.08407,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5742.1,-2950.76,286.264,5.11381,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5828.5,-2981.74,286.36,3.14159,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5769.4,-2935.12,286.336,4.85202,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5820.31,-3002.84,290.767,2.58309,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5733.76,-3000.35,286.36,0.471239,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5724.98,-2969.9,286.36,6.05629,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5722.49,-3010.75,312.752,0.506145,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5744.42,-3025.53,286.36,0.942478,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5813.94,-2956.75,286.36,3.71755,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5797.32,-2955.27,290.767,4.11898,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,4,30042,5816.85,-2974.48,290.767,3.61283,2,300000,"Gurgthock - Group 4 - Fiend of Fire"),
(30007,0,5,30025,5776.85,-2989.78,272.968,5.194,2,300000,"Gurgthock - Group 5 - Erathius, King of Dirt"),
(30007,0,5,30043,5739.81,-2981.52,290.767,5.98648,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5828.9,-2960.16,312.752,3.52556,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5743.31,-3011.3,290.767,0.610865,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5763.19,-3029.68,290.767,1.37881,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5793.06,-2934.59,286.36,4.08407,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5742.1,-2950.76,286.264,5.11381,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5828.5,-2981.74,286.36,3.14159,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5769.4,-2935.12,286.336,4.85202,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5820.31,-3002.84,290.767,2.58309,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5733.76,-3000.35,286.36,0.471239,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5724.98,-2969.9,286.36,6.05629,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5722.49,-3010.75,312.752,0.506145,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5744.42,-3025.53,286.36,0.942478,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5813.94,-2956.75,286.36,3.71755,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5797.32,-2955.27,290.767,4.11898,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,5,30043,5816.85,-2974.48,290.767,3.61283,2,300000,"Gurgthock - Group 5 - Fiend of Earth"),
(30007,0,6,30020,5754.69,-2939.46,286.276,5.15638,2,300000,"Gurgthock - Group 6 - Orinoko Tuskbreaker"),
(30007,0,7,30023,5754.69,-2939.46,286.276,5.15638,2,300000,"Gurgthock - Group 7 - Korrak the Bloodrager"),
(30007,0,8,30022,5754.69,-2939.46,286.276,5.15638,2,300000,"Gurgthock - Group 8 - Vladof the Butcher");
