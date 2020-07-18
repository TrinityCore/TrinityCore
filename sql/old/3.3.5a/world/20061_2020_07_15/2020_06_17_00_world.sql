--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 17658 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Stop if one of them was already summoned
(22,1,17658,0,0,29,0,17116,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Exarch Menelaous' is not near");
UPDATE `smart_scripts` SET `event_flags` = 0, `comment` = "Exarch Admetius - On Quest 'Ending Their World' Finished - Say Line 0" WHERE `entryorguid` = 17658 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 0, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Exarch Admetius - On Link - Summon Group 0" WHERE `entryorguid` = 17658 AND `source_type` = 0 AND `id` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1765800 AND `source_type` = 9;

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 17658 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(17658,0,0,17659,-1930.46,-11812.6,62.6309,2.30995,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17659,-1937.49,-11805.7,63.7985,5.53597,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17659,-1933.49,-11814.8,62.108,2.22748,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17659,-1939.96,-11808.2,62.6752,5.49985,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17659,-1936.87,-11817,61.1348,2.24899,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17659,-1942.61,-11810.6,61.8243,5.24734,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17659,-1940.21,-11819.8,60.3075,2.36209,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17659,-1945.48,-11813.6,60.9112,5.35298,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17659,-1944.12,-11823.2,59.0743,2.18733,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17659,-1948.83,-11816.8,60.053,5.34669,2,300000,"Exarch Admetius - Group 0 - Blade of Argus"),
(17658,0,0,17116,-1958.72,-11821.6,58.8921,0.461123,2,300000,"Exarch Admetius - Group 0 - Exarch Menelaous"),
(17658,0,0,17214,-1960.27,-11819.9,59.571,0.295709,2,300000,"Exarch Admetius - Group 0 - Anchorite Fateema"),
(17658,0,0,17101,-1959.95,-11823.8,57.6277,0.372766,2,300000,"Exarch Admetius - Group 0 - Diktynna"),
(17658,0,0,17215,-1961.16,-11823.4,57.702,0.640498,2,300000,"Exarch Admetius - Group 0 - Daedal"),
(17658,0,0,17110,-1961.2,-11821.9,58.6004,0.525438,2,300000,"Exarch Admetius - Group 0 - Acteon"),
(17658,0,0,17440,-1964.16,-11827,56.1668,0.561564,2,300000,"Exarch Admetius - Group 0 - High Chief Stillpine"),
(17658,0,0,17682,-1966.07,-11824.7,57.2651,0.161011,2,300000,"Exarch Admetius - Group 0 - Princess Stillpine"),
(17658,0,0,17443,-1966.24,-11822,58.598,6.20858,2,300000,"Exarch Admetius - Group 0 - Kurz the Revelator"),
(17658,0,0,17445,-1968.9,-11829.1,55.0413,0.386419,2,300000,"Exarch Admetius - Group 0 - Stillpine the Younger"),
(17658,0,0,17242,-1948.33,-11832.6,57.24,1.14982,2,300000,"Exarch Admetius - Group 0 - Archaeologist Adamant Ironheart"),
(17658,0,0,17240,-1950.2,-11831.7,56.9671,1.09092,2,300000,"Exarch Admetius - Group 0 - Admiral Odesyus"),
(17658,0,0,17117,-1952.31,-11831.3,56.7056,0.91224,2,300000,"Exarch Admetius - Group 0 - Injured Night Elf Priestess"),
(17658,0,0,17246,-1949.92,-11834,56.7319,1.21854,2,300000,"Exarch Admetius - Group 0 - Cookie McWeaksauce"),
(17658,0,0,17241,-1952.39,-11833.5,56.4305,0.977035,2,300000,"Exarch Admetius - Group 0 - Priestess Kyleen Ildinare"),
(17658,0,0,17311,-1954.8,-11838.6,55.2527,1.1616,2,300000,"Exarch Admetius - Group 0 - Cowlen"),
(17658,0,0,17649,-1955.7,-11843.1,54.1458,1.17557,2,300000,"Exarch Admetius - Group 0 - Kessel"),
(17658,0,0,17468,-1965.8,-11838.7,53.2196,0.792683,2,300000,"Exarch Admetius - Group 0 - Prophet Velen");
