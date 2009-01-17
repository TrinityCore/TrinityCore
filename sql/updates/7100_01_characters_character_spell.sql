ALTER TABLE character_db_version CHANGE COLUMN required_7077_01_characters_character_spell required_7100_01_characters_character_spell bit;

/* Warrior cleanup */
DELETE FROM `character_spell` WHERE `spell` IN (1715,7372,7373);                  /* Hamstring old */
DELETE FROM `character_spell` WHERE `spell` IN (72,17671,1672);                   /* Mortar Disturb old */
DELETE FROM `character_spell` WHERE `spell` IN (7384,7887,11584,11586);           /* Overpower old */
DELETE FROM `character_spell` WHERE `spell`=23881;                                /* Bloodthirst old */
DELETE FROM `character_spell` WHERE `spell` IN (6552,6554);                       /* Pummel old */
DELETE FROM `character_spell` WHERE `spell` IN (694,7400,7402,20559,20560,25266); /* Mocking Blow old */
/* Druid cleanup */
DELETE FROM `character_spell` WHERE `spell`=22842;                                /* Frenzied Regeneration old */
/* Hunter cleanup */
DELETE FROM `character_spell` WHERE `spell`=14268;                                /* Wing Clip r1 old */
DELETE FROM `character_spell` WHERE `spell`=14267;                                /* Wing Clip r2 old */
/* Rogue */
DELETE FROM `character_spell` WHERE `spell` IN (1766,1767,1768,1769,38768);       /* Kick old */
DELETE FROM `character_spell` WHERE `spell` IN (1776,1777,8629,11285,11286,38764);/* Gouge old */
DELETE FROM `character_spell` WHERE `spell`=2842;                                 /* Poisons old */

/* Hunter's training spells for pets */
DELETE FROM `character_spell` WHERE `spell` IN (2949,2975,2976,2977,2980,2981,2982,3666,3667,4630,6327,6359,6362,
    7370,7832,7833,7834,7835,7871,7872,7873,7876,7877,7878,7879,7880,7881,7882,7883,7884,7885,7886,8318,8319,11764,
    11765,11768,11769,11772,11773,11776,11777,11781,11782,11783,11786,11787,17254,17262,17263,17264,17265,17266,
    17267,17268,17736,17753,17754,17755,17776,17855,17856,17857,17859,17860,19439,19444,19445,19446,19447,19481,
    19577,19648,19650,19661,19662,19663,19664,19737,19738,19739,20270,20312,20313,20314,20315,20316,20317,20318,
    20319,20320,20321,20322,20323,20324,20326,20327,20329,20377,20378,20379,20380,20381,20382,20383,20384,20385,
    20386,20387,20388,20389,20390,20391,20392,20393,20394,20395,20396,20397,20398,20399,20400,20401,20402,20403,
    20404,20405,20406,20407,20408,20426,20427,20428,20429,20430,20431,20432,20433,20434,20435,23100,23111,23112,
    23146,23149,23150,24424,24440,24441,24451,24454,24455,24463,24464,24475,24476,24477,24580,24581,24582,24584,
    24588,24589,24599,24607,24608,24609,24641,26065,26094,26184,26185,26186,26189,26190,26202,27347,27348,27349,
    27361,27366,27484,27485,27486,27487,27488,27489,27490,27491,27492,27493,27494,27495,27496,27497,27500,28343,
    33703,35299,35300,35302,35303,35304,35305,35306,35307,35308);
DELETE FROM `character_spell` WHERE `spell` IN (1853,14922,14923,14924,14925,14926,14927,27344);
DELETE FROM `character_spell` WHERE `spell` IN (27353,24516,24515,24514,24490);
DELETE FROM `character_spell` WHERE `spell` IN (27354,24513,24512,24511,24494,2119);
UPDATE IGNORE character_spell SET spell = 2108 WHERE spell = 3104;
DELETE FROM character_spell                    WHERE spell = 3104;
/* This cleanup character_action. This is like delete from character_action where type=0 and action not in character_spell for same player */
DELETE FROM ca,cs USING `character_action` ca LEFT JOIN `character_spell` cs ON ca.`guid`=cs.`guid` AND ca.`action`=cs.`spell` WHERE ca.`type`=0 AND cs.`guid` IS NULL;
