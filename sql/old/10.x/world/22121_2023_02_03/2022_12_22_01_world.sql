-- 
DELETE FROM `player_classlevelstats` WHERE `level` > 70; -- delete old lvl data

-- 9.1.5
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=5);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=6);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=7);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=8);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=9);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=11);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=12);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=13);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=14);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41031 WHERE (`class`=10 AND `level`=15);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=42010 WHERE (`class`=6 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=42010 WHERE (`class`=8 AND `level`=59);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41079 WHERE (`class`=3 AND `level`=18);
UPDATE `player_classlevelstats` SET `inte`=23 WHERE (`class`=6 AND `level`=11);
UPDATE `player_classlevelstats` SET `inte`=24 WHERE (`class`=6 AND `level`=12);
UPDATE `player_classlevelstats` SET `inte`=25 WHERE (`class`=6 AND `level`=13);
UPDATE `player_classlevelstats` SET `inte`=26 WHERE (`class`=6 AND `level`=14);
UPDATE `player_classlevelstats` SET `inte`=27 WHERE (`class`=6 AND `level`=15);
UPDATE `player_classlevelstats` SET `inte`=28 WHERE (`class`=6 AND `level`=16);
UPDATE `player_classlevelstats` SET `agi`=45, `inte`=29 WHERE (`class`=6 AND `level`=17); -- Human DeathKnight recalculated
UPDATE `player_classlevelstats` SET `inte`=32 WHERE (`class`=6 AND `level`=20);
UPDATE `player_classlevelstats` SET `agi`=52, `inte`=33 WHERE (`class`=6 AND `level`=21); -- Human DeathKnight recalculated
UPDATE `player_classlevelstats` SET `agi`=92, `inte`=59 WHERE (`class`=6 AND `level`=39); -- Human DeathKnight recalculated
UPDATE `player_classlevelstats` SET `agi`=95, `inte`=61 WHERE (`class`=6 AND `level`=40); -- Human DeathKnight recalculated
UPDATE `player_classlevelstats` SET `agi`=101, `inte`=66 WHERE (`class`=6 AND `level`=42); -- Human DeathKnight recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=41323 WHERE (`class`=6 AND `level`=45);

-- 9.2.0
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43114 WHERE (`class`=1 AND `level`=60);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43114 WHERE (`class`=3 AND `level`=60);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43206 WHERE (`class`=6 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43345 WHERE (`class`=6 AND `level`=43);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43345 WHERE (`class`=7 AND `level`=45);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43345 WHERE (`class`=7 AND `level`=46);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43114 WHERE (`class`=7 AND `level`=60);

-- 9.2.5
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44232 WHERE (`class`=2 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44232 WHERE (`class`=4 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44061 WHERE (`class`=6 AND `level`=50);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44325 WHERE (`class`=7 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44325 WHERE (`class`=7 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44908 WHERE (`class`=8 AND `level`=2);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44908 WHERE (`class`=8 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44061 WHERE (`class`=8 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44908 WHERE (`class`=8 AND `level`=30);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44325 WHERE (`class`=8 AND `level`=51);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44061 WHERE (`class`=9 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44061 WHERE (`class`=9 AND `level`=2);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44730 WHERE (`class`=9 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43971 WHERE (`class`=9 AND `level`=50);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43971 WHERE (`class`=9 AND `level`=51);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44061 WHERE (`class`=9 AND `level`=52);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44061 WHERE (`class`=9 AND `level`=53);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44061 WHERE (`class`=9 AND `level`=54);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44061 WHERE (`class`=9 AND `level`=55);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44061 WHERE (`class`=9 AND `level`=56);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43971 WHERE (`class`=10 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43971 WHERE (`class`=10 AND `level`=2);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43971 WHERE (`class`=10 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=43971 WHERE (`class`=10 AND `level`=4); -- PandarenNeutral Monk recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44325 WHERE (`class`=11 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44908 WHERE (`class`=11 AND `level`=11);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44730 WHERE (`class`=11 AND `level`=40);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44730 WHERE (`class`=12 AND `level`=45);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=44730 WHERE (`class`=12 AND `level`=46);

-- 9.2.7
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=2 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=2 AND `level`=11);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=2);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=4);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=5);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=6);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=7);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=8);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=9);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=11);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=12);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=3 AND `level`=55);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=6 AND `level`=35);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=6 AND `level`=50);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=6 AND `level`=51);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=6 AND `level`=53);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=7 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=8 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=8 AND `level`=11);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=8 AND `level`=12);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=9 AND `level`=2);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=9 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=9 AND `level`=4); -- Troll Warlock recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=9 AND `level`=5);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=9 AND `level`=6);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=9 AND `level`=7);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=10 AND `level`=50);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=11 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=11 AND `level`=4); -- Worgen Druid recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=11 AND `level`=5);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=11 AND `level`=6);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=7);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=8);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=9);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=11);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=12);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=13);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=14);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=15);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=16);
UPDATE `player_classlevelstats` SET `inte`=56, `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=17); -- Worgen Druid recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=18);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=19);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=20);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=21);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=22);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=23);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=24);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=25);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=26);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=27);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=28);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=29);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=30);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=31);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=32);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=33);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=34);
UPDATE `player_classlevelstats` SET `inte`=97, `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=35); -- Worgen Druid recalculated
UPDATE `player_classlevelstats` SET `inte`=100, `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=36); -- Worgen Druid recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=37);
UPDATE `player_classlevelstats` SET `inte`=106, `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=38); -- Worgen Druid recalculated
UPDATE `player_classlevelstats` SET `str`=34, `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=39); -- Worgen Druid recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45338 WHERE (`class`=11 AND `level`=40);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=41);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=42);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=43);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=44);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=45);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=46);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=47);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=48);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=49);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=50);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=11 AND `level`=51);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45114 WHERE (`class`=11 AND `level`=59);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=45745 WHERE (`class`=12 AND `level`=46);

-- 10.0.0
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=1 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=3 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=4 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=5 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=6 AND `level`=44);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=10 AND `level`=50);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=11 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=6);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=11 AND `level`=11);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=11 AND `level`=59);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=12 AND `level`=46);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=12 AND `level`=47);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=4 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=4 AND `level`=2);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=4 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=4 AND `level`=4);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=4 AND `level`=5);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=4 AND `level`=6);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=4 AND `level`=7);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=4 AND `level`=8);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=4 AND `level`=9);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=4 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=4 AND `level`=11);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=4 AND `level`=12);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=4 AND `level`=13);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=4 AND `level`=14);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=4 AND `level`=15);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=4 AND `level`=16);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=4 AND `level`=17);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=4 AND `level`=18);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=4 AND `level`=19);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=4 AND `level`=20);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=4 AND `level`=60);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46547 WHERE (`class`=6 AND `level`=35);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=6 AND `level`=48);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=6 AND `level`=49);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=6 AND `level`=50);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=6 AND `level`=51);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=6 AND `level`=52);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=6 AND `level`=53);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=6 AND `level`=54);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46455 WHERE (`class`=6 AND `level`=55);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46549 WHERE (`class`=6 AND `level`=56);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46549 WHERE (`class`=6 AND `level`=57);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46597 WHERE (`class`=6 AND `level`=58);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=6 AND `level`=59);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=4); -- Orc Shaman recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=5);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=6);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=7);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=8);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=9); -- Orc Shaman recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=10);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=11);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=12);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=13);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=14);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=15);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=16);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=18);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=19);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=20);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=21);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=22);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=23);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=25);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=26);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=27);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=28);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=29);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=30);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=31);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=32);
UPDATE `player_classlevelstats` SET `str`=37, `agi`=87, `sta`=83, `inte`=87, `VerifiedBuild`=46340 WHERE (`class`=7 AND `level`=33); -- Orc Shaman recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=9 AND `level`=1);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=9 AND `level`=2);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=9 AND `level`=3);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=9 AND `level`=4); -- Undead Warlock recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=9 AND `level`=5);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=16);
UPDATE `player_classlevelstats` SET `inte`=52, `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=17); -- NightElf Druid recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=18);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=19);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=20);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=21);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=22);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=23);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=24); -- NightElf Druid recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=25);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=26);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=27);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=28);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=29);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46313 WHERE (`class`=11 AND `level`=30);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=11 AND `level`=31);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=11 AND `level`=32);
UPDATE `player_classlevelstats` SET `inte`=96, `VerifiedBuild`=46340 WHERE (`class`=11 AND `level`=36); -- NightElf Druid recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46340 WHERE (`class`=11 AND `level`=37);
UPDATE `player_classlevelstats` SET `inte`=102, `VerifiedBuild`=46340 WHERE (`class`=11 AND `level`=38); -- NightElf Druid recalculated
UPDATE `player_classlevelstats` SET `str`=46, `VerifiedBuild`=46340 WHERE (`class`=11 AND `level`=39); -- NightElf Druid recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=11 AND `level`=43);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=11 AND `level`=44);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=11 AND `level`=45);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=11 AND `level`=46);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=11 AND `level`=47);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46366 WHERE (`class`=11 AND `level`=48);

-- 10.0.2

DELETE FROM `player_classlevelstats` WHERE (`class`=11 AND `level` IN (61,62,63,64,65,66,67,68,69,70)) OR (`class`=12 AND `level` IN (61,62,63,64)) OR (`class`=13 AND `level`=58);
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(11, 61, 288, 670, 741, 670, 46801), -- HighmountainTauren Druid recalculated
(11, 62, 328, 764, 891, 764, 46801), -- HighmountainTauren Druid recalculated
(11, 63, 374, 870, 1068, 870, 46801), -- HighmountainTauren Druid recalculated
(11, 64, 426, 992, 1278, 992, 46801), -- HighmountainTauren Druid recalculated
(11, 65, 486, 1130, 1526, 1130, 46801), -- HighmountainTauren Druid recalculated
(11, 66, 553, 1287, 1817, 1287, 46801), -- HighmountainTauren Druid recalculated
(11, 67, 631, 1466, 2161, 1466, 46801), -- HighmountainTauren Druid recalculated
(11, 68, 718, 1671, 2564, 1671, 46801), -- HighmountainTauren Druid recalculated
(11, 69, 819, 1903, 3038, 1903, 46801), -- HighmountainTauren Druid recalculated
(11, 70, 898, 2089, 3463, 2089, 46801), -- HighmountainTauren Druid recalculated
(12, 61, 556, 670, 741, 456, 47213), -- BloodElf DemonHunter recalculated
(12, 62, 634, 764, 891, 519, 47213), -- BloodElf DemonHunter recalculated
(12, 63, 722, 870, 1068, 592, 47213), -- BloodElf DemonHunter recalculated
(12, 64, 823, 992, 1278, 674, 47213), -- BloodElf DemonHunter recalculated
(13, 58, 174, 271, 364, 400, 46702); -- DracthyrHorde Evoker recalculated

UPDATE `player_classlevelstats` SET `VerifiedBuild`=46658 WHERE (`class`=2 AND `level`=60);
UPDATE `player_classlevelstats` SET `str`=133, `agi`=191, `sta`=212, `inte`=230, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=49); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=141, `agi`=202, `sta`=224, `inte`=243, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=50); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=150, `agi`=214, `sta`=238, `inte`=258, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=51); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=159, `agi`=228, `sta`=253, `inte`=275, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=52); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=169, `agi`=243, `sta`=269, `inte`=292, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=53); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=180, `agi`=258, `sta`=286, `inte`=311, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=54); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=192, `agi`=274, `sta`=304, `inte`=331, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=55); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=204, `agi`=292, `sta`=324, `inte`=352, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=56); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=217, `agi`=310, `sta`=344, `inte`=374, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=57); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=231, `agi`=330, `sta`=366, `inte`=398, `VerifiedBuild`=46702 WHERE (`class`=5 AND `level`=58); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `str`=245, `agi`=351, `sta`=389, `inte`=423, `VerifiedBuild`=46741 WHERE (`class`=5 AND `level`=59); -- Goblin Priest recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46741 WHERE (`class`=5 AND `level`=60);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46801 WHERE (`class`=6 AND `level`=60);
UPDATE `player_classlevelstats` SET `agi`=20, `VerifiedBuild`=47187 WHERE (`class`=7 AND `level`=2); -- PandarenNeutral Shaman recalculated
UPDATE `player_classlevelstats` SET `str`=8, `VerifiedBuild`=47187 WHERE (`class`=8 AND `level`=1); -- Troll Mage recalculated
UPDATE `player_classlevelstats` SET `str`=12, `agi`=24, `sta`=35, `VerifiedBuild`=46702 WHERE (`class`=9 AND `level`=8); -- Troll Warlock recalculated
UPDATE `player_classlevelstats` SET `str`=34, `agi`=68, `sta`=81, `inte`=88, `VerifiedBuild`=46924 WHERE (`class`=9 AND `level`=30); -- Troll Warlock recalculated
UPDATE `player_classlevelstats` SET `str`=142, `agi`=288, `sta`=344, `inte`=374, `VerifiedBuild`=46924 WHERE (`class`=9 AND `level`=57); -- Troll Warlock recalculated
UPDATE `player_classlevelstats` SET `str`=151, `agi`=306, `sta`=366, `inte`=398, `VerifiedBuild`=46924 WHERE (`class`=9 AND `level`=58); -- Troll Warlock recalculated
UPDATE `player_classlevelstats` SET `str`=161, `agi`=326, `sta`=389, `inte`=423, `VerifiedBuild`=46924 WHERE (`class`=9 AND `level`=59); -- Troll Warlock recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46924 WHERE (`class`=9 AND `level`=60);
UPDATE `player_classlevelstats` SET `agi`=20, `sta`=20, `VerifiedBuild`=47187 WHERE (`class`=11 AND `level`=2); -- Troll Druid recalculated
UPDATE `player_classlevelstats` SET `str`=15, `agi`=35, `sta`=35, `VerifiedBuild`=46801 WHERE (`class`=11 AND `level`=10); -- ZandalariTroll Druid recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46658 WHERE (`class`=11 AND `level`=60);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46801 WHERE (`class`=12 AND `level`=60);

UPDATE `player_classlevelstats` SET `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=60);
UPDATE `player_classlevelstats` SET `str`=295, `agi`=456, `sta`=741, `inte`=670, `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=61); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=336, `agi`=519, `sta`=891, `inte`=764, `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=62); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=383, `agi`=592, `sta`=1068, `inte`=870, `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=63); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=436, `agi`=674, `sta`=1278, `inte`=992, `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=64); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=497, `agi`=768, `sta`=1526, `inte`=1130, `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=65); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=566, `agi`=875, `sta`=1817, `inte`=1287, `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=66); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=645, `agi`=997, `sta`=2161, `inte`=1466, `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=67); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=735, `agi`=1136, `sta`=2564, `inte`=1671, `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=68); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=838, `agi`=1294, `sta`=3038, `inte`=1903, `VerifiedBuild`=46924 WHERE (`class`=8 AND `level`=69); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=919, `agi`=1421, `sta`=3463, `inte`=2089, `VerifiedBuild`=47187 WHERE (`class`=8 AND `level`=70); -- Gnome Mage recalculated
UPDATE `player_classlevelstats` SET `str`=118, `agi`=275, `sta`=253, `inte`=275, `VerifiedBuild`=46924 WHERE (`class`=11 AND `level`=52); -- NightElf Druid recalculated

DELETE FROM `player_classlevelstats` WHERE (`class`=2 AND `level` IN (61,62)) OR (`class`=13 AND `level` IN (59,60));
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(2, 61, 670, 235, 741, 670, 46924), -- LightforgedDraenei Paladin recalculated
(2, 62, 764, 267, 891, 764, 46924), -- LightforgedDraenei Paladin recalculated
-- (13, 58, 174, 271, 364, 400, 47213), -- DracthyrAlliance Evoker recalculated
(13, 59, 185, 289, 387, 425, 47213), -- DracthyrAlliance Evoker recalculated
(13, 60, 197, 307, 412, 452, 47213); -- DracthyrAlliance Evoker recalculated

UPDATE `player_classlevelstats` SET `VerifiedBuild`=46741 WHERE (`class`=2 AND `level`=60);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=60);
UPDATE `player_classlevelstats` SET `str`=389, `agi`=556, `sta`=741, `inte`=670, `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=61); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=443, `agi`=634, `sta`=891, `inte`=764, `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=62); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=505, `agi`=722, `sta`=1068, `inte`=870, `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=63); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=575, `agi`=823, `sta`=1278, `inte`=992, `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=64); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=655, `agi`=938, `sta`=1526, `inte`=1130, `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=65); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=746, `agi`=1068, `sta`=1817, `inte`=1287, `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=66); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=851, `agi`=1217, `sta`=2161, `inte`=1466, `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=67); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=969, `agi`=1387, `sta`=2564, `inte`=1671, `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=68); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=1104, `agi`=1580, `sta`=3038, `inte`=1903, `VerifiedBuild`=46801 WHERE (`class`=5 AND `level`=69); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=1212, `agi`=1734, `sta`=3463, `inte`=2089, `VerifiedBuild`=46879 WHERE (`class`=5 AND `level`=70); -- VoidElf Priest recalculated
UPDATE `player_classlevelstats` SET `str`=29, `agi`=68, `inte`=68, `VerifiedBuild`=46924 WHERE (`class`=7 AND `level`=24); -- Vulpera Shaman recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46924 WHERE (`class`=10 AND `level`=60);

DELETE FROM `player_classlevelstats` WHERE (`class`=12 AND `level` IN (65,66,67,68));
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(12, 65, 938, 1130, 1526, 768, 46924), -- BloodElf DemonHunter recalculated
(12, 66, 1068, 1287, 1817, 875, 46924), -- BloodElf DemonHunter recalculated
(12, 67, 1217, 1466, 2161, 997, 46924), -- BloodElf DemonHunter recalculated
(12, 68, 1387, 1671, 2564, 1136, 46924); -- BloodElf DemonHunter recalculated

UPDATE `player_classlevelstats` SET `str`=18, `agi`=29, `sta`=29, `VerifiedBuild`=46741 WHERE (`class`=3 AND `level`=7); -- Human Hunter recalculated
UPDATE `player_classlevelstats` SET `str`=15, `agi`=35, `sta`=31, `VerifiedBuild`=46741 WHERE (`class`=7 AND `level`=10); -- DarkIronDwarf Shaman recalculated
UPDATE `player_classlevelstats` SET `str`=16, `agi`=37, `sta`=34, `VerifiedBuild`=46741 WHERE (`class`=7 AND `level`=11); -- DarkIronDwarf Shaman recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=46924 WHERE (`class`=11 AND `level`=70);
