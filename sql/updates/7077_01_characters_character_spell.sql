ALTER TABLE character_db_version CHANGE COLUMN required_7075_01_characters_character_spell required_7077_01_characters_character_spell bit;

UPDATE IGNORE character_spell SET spell = 2018 WHERE spell = 2020;
DELETE FROM character_spell                    WHERE spell = 2020;

UPDATE IGNORE character_spell SET spell = 2018 WHERE spell = 2020;
DELETE FROM character_spell                    WHERE spell = 2020;

UPDATE IGNORE character_spell SET spell = 3100 WHERE spell = 2021;
DELETE FROM character_spell                    WHERE spell = 2021;

UPDATE IGNORE character_spell SET spell = 3104 WHERE spell = 2154;
DELETE FROM character_spell                    WHERE spell = 2154;

UPDATE IGNORE character_spell SET spell = 2108 WHERE spell = 2155;
DELETE FROM character_spell                    WHERE spell = 2155;

UPDATE IGNORE character_spell SET spell = 2259 WHERE spell = 2275;
DELETE FROM character_spell                    WHERE spell = 2275;

UPDATE IGNORE character_spell SET spell = 3101 WHERE spell = 2280;
DELETE FROM character_spell                    WHERE spell = 2280;

UPDATE IGNORE character_spell SET spell = 2366 WHERE spell = 2372;
DELETE FROM character_spell                    WHERE spell = 2372;

UPDATE IGNORE character_spell SET spell = 2368 WHERE spell = 2373;
DELETE FROM character_spell                    WHERE spell = 2373;

UPDATE IGNORE character_spell SET spell = 2550 WHERE spell = 2551;
DELETE FROM character_spell                    WHERE spell = 2551;

UPDATE IGNORE character_spell SET spell = 2575 WHERE spell = 2581;
DELETE FROM character_spell                    WHERE spell = 2581;

UPDATE IGNORE character_spell SET spell = 2576 WHERE spell = 2582;
DELETE FROM character_spell                    WHERE spell = 2582;

UPDATE IGNORE character_spell SET spell = 3273 WHERE spell = 3279;
DELETE FROM character_spell                    WHERE spell = 3279;

UPDATE IGNORE character_spell SET spell = 3274 WHERE spell = 3280;
DELETE FROM character_spell                    WHERE spell = 3280;

UPDATE IGNORE character_spell SET spell = 3102 WHERE spell = 3412;
DELETE FROM character_spell                    WHERE spell = 3412;

UPDATE IGNORE character_spell SET spell = 3464 WHERE spell = 3465;
DELETE FROM character_spell                    WHERE spell = 3465;

UPDATE IGNORE character_spell SET spell = 3538 WHERE spell = 3539;
DELETE FROM character_spell                    WHERE spell = 3539;

UPDATE IGNORE character_spell SET spell = 3564 WHERE spell = 3568;
DELETE FROM character_spell                    WHERE spell = 3568;

UPDATE IGNORE character_spell SET spell = 3570 WHERE spell = 3571;
DELETE FROM character_spell                    WHERE spell = 3571;

UPDATE IGNORE character_spell SET spell = 3811 WHERE spell = 3812;
DELETE FROM character_spell                    WHERE spell = 3812;

UPDATE IGNORE character_spell SET spell = 3908 WHERE spell = 3911;
DELETE FROM character_spell                    WHERE spell = 3911;

UPDATE IGNORE character_spell SET spell = 3909 WHERE spell = 3912;
DELETE FROM character_spell                    WHERE spell = 3912;

UPDATE IGNORE character_spell SET spell = 3910 WHERE spell = 3913;
DELETE FROM character_spell                    WHERE spell = 3913;

UPDATE IGNORE character_spell SET spell = 4036 WHERE spell = 4039;
DELETE FROM character_spell                    WHERE spell = 4039;

UPDATE IGNORE character_spell SET spell = 4037 WHERE spell = 4040;
DELETE FROM character_spell                    WHERE spell = 4040;

UPDATE IGNORE character_spell SET spell = 4038 WHERE spell = 4041;
DELETE FROM character_spell                    WHERE spell = 4041;

UPDATE IGNORE character_spell SET spell = 7620 WHERE spell = 7733;
DELETE FROM character_spell                    WHERE spell = 7733;

UPDATE IGNORE character_spell SET spell = 7731 WHERE spell = 7734;
DELETE FROM character_spell                    WHERE spell = 7734;

UPDATE IGNORE character_spell SET spell = 8613 WHERE spell = 8615;
DELETE FROM character_spell                    WHERE spell = 8615;

UPDATE IGNORE character_spell SET spell = 8617 WHERE spell = 8619;
DELETE FROM character_spell                    WHERE spell = 8619;

UPDATE IGNORE character_spell SET spell = 8618 WHERE spell = 8620;
DELETE FROM character_spell                    WHERE spell = 8620;

UPDATE IGNORE character_spell SET spell = 9785 WHERE spell = 9786;
DELETE FROM character_spell                    WHERE spell = 9786;

UPDATE IGNORE character_spell SET spell = 10248 WHERE spell = 10249;
DELETE FROM character_spell                     WHERE spell = 10249;

UPDATE IGNORE character_spell SET spell = 10662 WHERE spell = 10663;
DELETE FROM character_spell                     WHERE spell = 10663;

UPDATE IGNORE character_spell SET spell = 10768 WHERE spell = 10769;
DELETE FROM character_spell                     WHERE spell = 10769;

UPDATE IGNORE character_spell SET spell = 11611 WHERE spell = 11612;
DELETE FROM character_spell                     WHERE spell = 11612;

UPDATE IGNORE character_spell SET spell = 11993 WHERE spell = 11994;
DELETE FROM character_spell                     WHERE spell = 11994;

UPDATE IGNORE character_spell SET spell = 12180 WHERE spell = 12181;
DELETE FROM character_spell                     WHERE spell = 12181;

UPDATE IGNORE character_spell SET spell = 12656 WHERE spell = 12657;
DELETE FROM character_spell                     WHERE spell = 12657;

UPDATE IGNORE character_spell SET spell = 25229 WHERE spell = 25245;
DELETE FROM character_spell                     WHERE spell = 25245;

UPDATE IGNORE character_spell SET spell = 25230 WHERE spell = 25246;
DELETE FROM character_spell                     WHERE spell = 25246;

UPDATE IGNORE character_spell SET spell = 26790 WHERE spell = 26791;
DELETE FROM character_spell                     WHERE spell = 26791;

UPDATE IGNORE character_spell SET spell = 28596 WHERE spell = 28597;
DELETE FROM character_spell                     WHERE spell = 28597;

UPDATE IGNORE character_spell SET spell = 28695 WHERE spell = 28696;
DELETE FROM character_spell                     WHERE spell = 28696;

UPDATE IGNORE character_spell SET spell = 28894 WHERE spell = 28896;
DELETE FROM character_spell                     WHERE spell = 28896;

UPDATE IGNORE character_spell SET spell = 28895 WHERE spell = 28899;
DELETE FROM character_spell                     WHERE spell = 28899;

UPDATE IGNORE character_spell SET spell = 28897 WHERE spell = 28901;
DELETE FROM character_spell                     WHERE spell = 28901;

UPDATE IGNORE character_spell SET spell = 29354 WHERE spell = 29355;
DELETE FROM character_spell                     WHERE spell = 29355;

UPDATE IGNORE character_spell SET spell = 29844 WHERE spell = 29845;
DELETE FROM character_spell                     WHERE spell = 29845;

UPDATE IGNORE character_spell SET spell = 30350 WHERE spell = 30351;
DELETE FROM character_spell                     WHERE spell = 30351;

UPDATE IGNORE character_spell SET spell = 32549 WHERE spell = 32550;
DELETE FROM character_spell                     WHERE spell = 32550;

UPDATE IGNORE character_spell SET spell = 32678 WHERE spell = 32679;
DELETE FROM character_spell                     WHERE spell = 32679;

UPDATE IGNORE character_spell SET spell = 45357 WHERE spell = 45375;
DELETE FROM character_spell                     WHERE spell = 45375;

UPDATE IGNORE character_spell SET spell = 45358 WHERE spell = 45376;
DELETE FROM character_spell                     WHERE spell = 45376;

UPDATE IGNORE character_spell SET spell = 45359 WHERE spell = 45377;
DELETE FROM character_spell                     WHERE spell = 45377;

UPDATE IGNORE character_spell SET spell = 45360 WHERE spell = 45378;
DELETE FROM character_spell                     WHERE spell = 45378;

UPDATE IGNORE character_spell SET spell = 45361 WHERE spell = 45379;
DELETE FROM character_spell                     WHERE spell = 45379;

UPDATE IGNORE character_spell SET spell = 45363 WHERE spell = 45380;
DELETE FROM character_spell                     WHERE spell = 45380;

UPDATE IGNORE character_spell SET spell = 45542 WHERE spell = 50299;
DELETE FROM character_spell                     WHERE spell = 50299;

UPDATE IGNORE character_spell SET spell = 50305 WHERE spell = 50307;
DELETE FROM character_spell                     WHERE spell = 50307;

UPDATE IGNORE character_spell SET spell = 50310 WHERE spell = 50309;
DELETE FROM character_spell                     WHERE spell = 50309;

UPDATE IGNORE character_spell SET spell = 51294 WHERE spell = 51293;
DELETE FROM character_spell                     WHERE spell = 51293;

UPDATE IGNORE character_spell SET spell = 51296 WHERE spell = 51295;
DELETE FROM character_spell                     WHERE spell = 51295;

UPDATE IGNORE character_spell SET spell = 51300 WHERE spell = 51298;
DELETE FROM character_spell                     WHERE spell = 51298;

UPDATE IGNORE character_spell SET spell = 51302 WHERE spell = 51301;
DELETE FROM character_spell                     WHERE spell = 51301;

UPDATE IGNORE character_spell SET spell = 51304 WHERE spell = 51303;
DELETE FROM character_spell                     WHERE spell = 51303;

UPDATE IGNORE character_spell SET spell = 51306 WHERE spell = 51305;
DELETE FROM character_spell                     WHERE spell = 51305;

UPDATE IGNORE character_spell SET spell = 51309 WHERE spell = 51308;
DELETE FROM character_spell                     WHERE spell = 51308;

UPDATE IGNORE character_spell SET spell = 51311 WHERE spell = 51310;
DELETE FROM character_spell                     WHERE spell = 51310;

UPDATE IGNORE character_spell SET spell = 51313 WHERE spell = 51312;
DELETE FROM character_spell                     WHERE spell = 51312;

UPDATE IGNORE character_spell SET spell = 33095 WHERE spell = 54084;
DELETE FROM character_spell                     WHERE spell = 54084;
