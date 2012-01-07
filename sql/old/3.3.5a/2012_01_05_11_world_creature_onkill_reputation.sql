-- remade incorrect gain of ashen verdict reputation according to http://www.wowwiki.com/Ashen_Verdict
-- there were incorrect values for trash mobs ( before=25 for kill, must to be 15)
-- for Lich King it must to be 1500 and for Deathbound Wards and Deathspeaker High Priests 45
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 1500 WHERE `creature_id` IN (36597,39166,39167,39168); 
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 45 WHERE `creature_id` IN (36829,37007);
UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1` = 15 WHERE `creature_id` IN (36619,36724,36725,36791,36805,36807,36808,36811,36880,36957,36960,36968,36982,37011,37012,37022,37029,37030,37031,37032,37033,37034,37035,37117,37125,37127,37132,37133,37134,37146,37149,37228,37229,37232,37501,37502,37531,37532,37546,37571,37595,37662,37663,37664,37665,37666,37695,37782,37886,37890,37919,37934,37949,38125,38159,38184,38369,38472,38485,38508,38711,38712);
