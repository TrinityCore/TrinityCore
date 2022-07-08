-- Living Inferno
UPDATE `creature_template` SET `dmgschool`=2, `DamageModifier`=42 WHERE `entry`=40681; -- assuming 23k raw damage
UPDATE `creature_template` SET `dmgschool`=2, `DamageModifier`=51.4 WHERE `entry`=40682; -- 28k raw damage
--
-- Living Ember
UPDATE `creature_template` SET `dmgschool`=2, `DamageModifier`=9.1 WHERE `entry`=40683; -- assuming 5k raw damage
UPDATE `creature_template` SET `dmgschool`=2, `DamageModifier`=12.8 WHERE `entry`=40684; -- 7k raw damage
--
-- Deformed Fanatic
-- `DamageModifier`=1 => 500
UPDATE `creature_template` SET `DamageModifier`=60 WHERE `entry`=38135; -- 10N, 30k raw damage
UPDATE `creature_template` SET `DamageModifier`=100 WHERE `entry`=38395; -- 25N 50k raw damage
UPDATE `creature_template` SET `DamageModifier`=100 WHERE `entry`=38634; -- 10H, 50k raw damage
UPDATE `creature_template` SET `DamageModifier`=160 WHERE `entry`=38635; -- 25H, 80k raw damage
--
-- https://docs.google.com/spreadsheets/d/1edy3LvpkPMViHhVQw4ABPufDNmkjstUmXZ8hkkfvN-Q/edit#gid=94525178
UPDATE `creature_template` SET `DamageModifier`=71.7 WHERE `entry` IN (39863,40142); -- 10NM, 40k raw damage
UPDATE `creature_template` SET `DamageModifier`=217.5 WHERE `entry` IN (39864,40143); -- 25NM, 91k raw damage
UPDATE `creature_template` SET `DamageModifier`=102.2 WHERE `entry` IN (39944,40144); -- 10HC, 57k raw damage
UPDATE `creature_template` SET `DamageModifier`=385.4 WHERE `entry` IN (39945,40145); -- 25HC, 161k raw damage
--
-- Baltharus the Warborn
UPDATE `creature_template` SET `DamageModifier`=101.6 WHERE `entry` IN (39751,39899); -- 10M, 56.7k raw damage
UPDATE `creature_template` SET `DamageModifier`=129.3 WHERE `entry` IN (39920,39922); -- 25M, 72k raw damage
-- Saviana Ragefire
UPDATE `creature_template` SET `DamageModifier`=90.5 WHERE `entry`=39747; -- 10M, 50k raw damage
UPDATE `creature_template` SET `DamageModifier`=141.7 WHERE `entry`=39823; -- 25M, 79k raw damage
-- General Zarithrian
UPDATE `creature_template` SET `DamageModifier`=80.6 WHERE `entry`=39746; -- 10M, 44.9k raw damage
UPDATE `creature_template` SET `DamageModifier`=160.4 WHERE `entry`=39805; -- 25M, 90k raw damage
--
-- Charscale Invoker
UPDATE `creature_template` SET `DamageModifier`=56 WHERE `entry`=40417; -- 10M, 30k raw damage
UPDATE `creature_template` SET `DamageModifier`=90.2 WHERE `entry`=40418; -- 25M, 49k raw damage
-- Charscale Assaulter
UPDATE `creature_template` SET `DamageModifier`=56 WHERE `entry`=40419; -- 10M, 30k raw damage
UPDATE `creature_template` SET `DamageModifier`=90.2 WHERE `entry`=40420; -- 25M, 49k raw damage
-- Charscale Commander
UPDATE `creature_template` SET `DamageModifier`=50.9 WHERE `entry`=40423; -- 10M, 27.7k raw damage
UPDATE `creature_template` SET `DamageModifier`=98.6 WHERE `entry`=40424; -- 25M, 53.6k raw damage
--
UPDATE `creature_template` SET `baseattacktime`=2000 WHERE `entry` IN (40421,40422);
UPDATE `creature_template` SET `DamageModifier`=70.9 WHERE `entry`=40421; -- 10M, 38k raw damage
UPDATE `creature_template` SET `DamageModifier`=98.6 WHERE `entry`=40422; -- 25M, 53.6k raw damage
--
-- The Lich King
UPDATE `creature_template` SET `DamageModifier`=139 WHERE `entry`=36597; -- 10NM, 58k raw damage
UPDATE `creature_template` SET `DamageModifier`=276.1 WHERE `entry`=39166; -- 25NM, 115k raw damage
UPDATE `creature_template` SET `DamageModifier`=244.3 WHERE `entry`=39167; -- 10HC, 102k raw damage
UPDATE `creature_template` SET `DamageModifier`=492.9 WHERE `entry`=39168; -- 25HC, 206k raw damage
--
UPDATE `creature_template` SET `baseattacktime`=1500 WHERE `entry` IN (36853,38265,38266,38267);
UPDATE `creature_template` SET `DamageModifier`=81.6 WHERE `entry`=36853; -- 10NM, 34k raw damage
UPDATE `creature_template` SET `DamageModifier`=158.7 WHERE `entry`=38265; -- 25NM, 66k raw damage
UPDATE `creature_template` SET `DamageModifier`=121.5 WHERE `entry`=38266; -- 10HC, 50k raw damage
UPDATE `creature_template` SET `DamageModifier`=342.7 WHERE `entry`=38267; -- 25HC, 143k raw damage
--
-- Blood-Queen Lana'thel
UPDATE `creature_template` SET `DamageModifier`=80 WHERE `entry`=37955; -- 10NM, 44k raw damage
UPDATE `creature_template` SET `DamageModifier`=158.7 WHERE `entry`=38434; -- 25NM, 88k raw damage
UPDATE `creature_template` SET `DamageModifier`=105.5 WHERE `entry`=38435; -- 10HC, 58k raw damage
UPDATE `creature_template` SET `DamageModifier`=211.6 WHERE `entry`=38436; -- 25HC, 118k raw damage
--
-- Prince Taldaram
UPDATE `creature_template` SET `DamageModifier`=85.7 WHERE `entry` IN (37970,37972,37973); -- 10NM, 47k raw damage
UPDATE `creature_template` SET `DamageModifier`=157.1 WHERE `entry` IN (38401,38399,38400); -- 25NM, 87k raw damage
UPDATE `creature_template` SET `DamageModifier`=124.3 WHERE `entry` IN (38784,38769,38771); -- 10HC, 69k raw damage
UPDATE `creature_template` SET `DamageModifier`=234.8 WHERE `entry` IN (38785,38770,38772); -- 25HC, 130k raw damage
--
UPDATE `creature_template` SET `baseattacktime`=1500 WHERE `entry` IN (36678,38431,38585,38586);
UPDATE `creature_template` SET `DamageModifier`=87 WHERE `entry`=36678; -- 10NM, 36k raw damage
UPDATE `creature_template` SET `DamageModifier`=176.4 WHERE `entry`=38431; -- 25NM, 73k raw damage
UPDATE `creature_template` SET `DamageModifier`=118 WHERE `entry`=38585; -- 10HC, 49k raw damage
UPDATE `creature_template` SET `DamageModifier`=243.4 WHERE `entry`=38586; -- 25HC, 101k raw damage
--
-- Festergut
UPDATE `creature_template` SET `DamageModifier`=75 WHERE `entry`=36626; -- 10NM, 41.8k raw damage
UPDATE `creature_template` SET `DamageModifier`=122.6 WHERE `entry`=37504; -- 25NM, 68k raw damage
UPDATE `creature_template` SET `DamageModifier`=116 WHERE `entry`=37505; -- 10HC, 64k raw damage
UPDATE `creature_template` SET `DamageModifier`=174.5 WHERE `entry`=37506; -- 25HC, 97k raw damage
--
-- Rotface
UPDATE `creature_template` SET `DamageModifier`=74.5 WHERE `entry`=36627; -- 10NM, 41.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=124.5 WHERE `entry`=38390; -- 25NM, 69.4k raw damage
UPDATE `creature_template` SET `DamageModifier`=117 WHERE `entry`=38549; -- 10HC, 65.2k raw damage
UPDATE `creature_template` SET `DamageModifier`=130.2 WHERE `entry`=38550; -- 25HC, 72k raw damage
--
-- Deathbringer Saurfang
UPDATE `creature_template` SET `DamageModifier`=50.5 WHERE `entry`=37813; -- 10NM, 21k raw damage
UPDATE `creature_template` SET `DamageModifier`=120.8 WHERE `entry`=38402; -- 25NM, 50k raw damage
UPDATE `creature_template` SET `DamageModifier`=84.1 WHERE `entry`=38582; -- 10HC, 35k raw damage
UPDATE `creature_template` SET `DamageModifier`=199 WHERE `entry`=38583; -- 25HC, 83k raw damage
--
-- Blood Beast
UPDATE `creature_template` SET `DamageModifier`=18.4 WHERE `entry` IN (38508,38596,38597,38598); -- 10k raw damage
--
-- Muradin Bronzebeard
UPDATE `creature_template` SET `DamageModifier`=47 WHERE `entry` IN (36939,36948); -- 10NM, 26.2k raw damage
UPDATE `creature_template` SET `DamageModifier`=90 WHERE `entry` IN (38156,38157); -- 25NM, 50k raw damage
UPDATE `creature_template` SET `DamageModifier`=72.6 WHERE `entry` IN (38638,38639); -- 10HC, 40k raw damage
UPDATE `creature_template` SET `DamageModifier`=114.7 WHERE `entry` IN (38637,38640); -- 25HC, 64k raw damage
--
-- Kor'kron Sergeant
UPDATE `creature_template` SET `DamageModifier`=20 WHERE `entry` IN (36950,38406,38685,38686);
--
-- Lady Deathwhisper
UPDATE `creature_template` SET `DamageModifier`=69.3 WHERE `entry`=36855; -- 10NM, 38.6k raw damage
UPDATE `creature_template` SET `DamageModifier`=87.1 WHERE `entry`=38106; -- 25NM, 48.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=68.3 WHERE `entry`=38296; -- 10HC, 38k raw damage
UPDATE `creature_template` SET `DamageModifier`=170 WHERE `entry`=38297; -- 25HC, 95k raw damage
--
UPDATE `creature_template` SET `baseattacktime`=1000 WHERE `entry` IN (36612,37957,37958,37959);
UPDATE `creature_template` SET `DamageModifier`=112 WHERE `entry`=36612; -- 10NM, 31k raw damage
UPDATE `creature_template` SET `DamageModifier`=234 WHERE `entry`=37957; -- 25NM, 65k raw damage
UPDATE `creature_template` SET `DamageModifier`=177.82 WHERE `entry`=37958; -- 10HC, 49.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=352 WHERE `entry`=37959; -- 25HC, 98k raw damage
--
-- Shambling Horror
UPDATE `creature_template` SET `DamageModifier`=50 WHERE `entry`=37698; -- 10NM, 27k raw damage
UPDATE `creature_template` SET `DamageModifier`=131.9 WHERE `entry`=39299; -- 25NM, 73k raw damage
UPDATE `creature_template` SET `DamageModifier`=90.5 WHERE `entry`=39300; -- 10HC, 50k raw damage
UPDATE `creature_template` SET `DamageModifier`=214.8 WHERE `entry`=39301; -- 25HC, 119k raw damage
--
-- Drudge Ghoul
UPDATE `creature_template` SET `DamageModifier`=8.5 WHERE `entry`=37695; -- 10NM, 4.3k raw damage
UPDATE `creature_template` SET `DamageModifier`=20.7 WHERE `entry`=39309; -- 25NM, 10.4k raw damage
UPDATE `creature_template` SET `DamageModifier`=13.2 WHERE `entry`=39310; -- 10HC, 6.6k raw damage
UPDATE `creature_template` SET `DamageModifier`=29.43 WHERE `entry`=39311; -- 25HC, 14.8k raw damage
--
-- Raging Spirit
UPDATE `creature_template` SET `DamageModifier`=66.4 WHERE `entry`=36701; -- 10NM, 37k raw damage
UPDATE `creature_template` SET `DamageModifier`=152.4 WHERE `entry`=39302; -- 25NM, 85k raw damage
UPDATE `creature_template` SET `DamageModifier`=95.2 WHERE `entry`=39303; -- 10HC, 53k raw damage
UPDATE `creature_template` SET `DamageModifier`=219.2 WHERE `entry`=39304; -- 25HC, 122k raw damage
--
-- Blistering Zombie
UPDATE `creature_template` SET `DamageModifier`=36.9 WHERE `entry`=37934; -- 10NM, 18.6k raw damage
UPDATE `creature_template` SET `DamageModifier`=81.8 WHERE `entry`=38170; -- 25NM, 41.2k raw damage
UPDATE `creature_template` SET `DamageModifier`=75 WHERE `entry`=38723; -- 10HC, 37.8k raw damage
UPDATE `creature_template` SET `DamageModifier`=137.9 WHERE `entry`=38733; -- 25HC, 69.5k raw damage
--
-- Raging Spirit
UPDATE `creature_template` SET `DamageModifier`=8.9 WHERE `entry`=36791; -- 10NM, 5k raw damage
UPDATE `creature_template` SET `DamageModifier`=16.1 WHERE `entry`=38169; -- 25NM, 9k raw damage
UPDATE `creature_template` SET `DamageModifier`=20.6 WHERE `entry`=38721; -- 10HC, 11.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=26.6 WHERE `entry`=38722; -- 25HC, 14.8k raw damage
--
-- Gluttonous Abomination
UPDATE `creature_template` SET `DamageModifier`=25.8 WHERE `entry`=37886; -- 10NM, 14.3k raw damage
UPDATE `creature_template` SET `DamageModifier`=61.1 WHERE `entry`=38166; -- 25NM, 34k raw damage
UPDATE `creature_template` SET `DamageModifier`=44.3 WHERE `entry`=38724; -- 10HC, 24.6k raw damage
UPDATE `creature_template` SET `DamageModifier`=99.3 WHERE `entry`=38734; -- 25HC, 55.3k raw damage
--
-- Rot Worm
UPDATE `creature_template` SET `DamageModifier`=12.6 WHERE `entry`=37907; -- 10NM, 6.3k raw damage
UPDATE `creature_template` SET `DamageModifier`=22.6 WHERE `entry`=38168; -- 25NM, 11.3k raw damage
UPDATE `creature_template` SET `DamageModifier`=16.7 WHERE `entry`=38726; -- 10HC, 8.4k raw damage
UPDATE `creature_template` SET `DamageModifier`=28.3 WHERE `entry`=38736; -- 25HC, 14.2k raw damage
--
-- Cult Fanatic
UPDATE `creature_template` SET `DamageModifier`=25.4 WHERE `entry`=37890; -- 10NM, 13.8k raw damage
UPDATE `creature_template` SET `DamageModifier`=56.3 WHERE `entry`=38393; -- 25NM, 30k raw damage
UPDATE `creature_template` SET `DamageModifier`=53.8 WHERE `entry`=38628; -- 10HC, 29k raw damage
UPDATE `creature_template` SET `DamageModifier`=80.5 WHERE `entry`=38629; -- 25HC, 43.8k raw damage
--
-- Cult Adherent
UPDATE `creature_template` SET `DamageModifier`=10.1 WHERE `entry`=37949; -- 10NM, 5.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=18.4 WHERE `entry`=38394; -- 25NM, 10k raw damage
UPDATE `creature_template` SET `DamageModifier`=24.8 WHERE `entry`=38625; -- 10HC, 13.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=36.7 WHERE `entry`=38626; -- 25HC, (assumed) 20k raw damage
--
-- Highlord Tirion Fordring
UPDATE `creature_template` SET `DamageModifier`=19 WHERE `entry`=38995; -- all modes, 10.6k raw damage
--
-- Little Ooze
UPDATE `creature_template` SET `DamageModifier`=1.8 WHERE `entry` IN (36897,38138); -- all modes, 1k raw damage
--
-- Big Ooze
UPDATE `creature_template` SET `DamageModifier`=88.2 WHERE `entry`=36899; -- 10M, 48k raw damage
UPDATE `creature_template` SET `DamageModifier`=152.5 WHERE `entry`=38123; -- 25M, 83k raw damage
--
-- Terenas Menethil
UPDATE `creature_template` SET `DamageModifier`=14.2 WHERE `entry` IN (36823,38579,39217); -- all modes, 7.1k raw damage
--
-- Deformed Fanatic
UPDATE `creature_template` SET `DamageModifier`=3*25.4 WHERE `entry`=38135; -- 10NM, 3*13.8k raw damage
UPDATE `creature_template` SET `DamageModifier`=3*56.3 WHERE `entry`=38395; -- 25NM, 3*30k raw damage
UPDATE `creature_template` SET `DamageModifier`=3*53.8 WHERE `entry`=38634; -- 10HC, 3*29k raw damage
UPDATE `creature_template` SET `DamageModifier`=3*80.5 WHERE `entry`=38635; -- 25HC, 3*43.8k raw damage
--
-- Archavon the Stone Watcher
UPDATE `creature_template` SET `DamageModifier`=36.8 WHERE `entry`=31125; -- 10M, 20.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=70.24 WHERE `entry`=31722; -- 25M, 39k raw damage
-- Emalon the Storm Watcher
UPDATE `creature_template` SET `DamageModifier`=59.5 WHERE `entry`=33993; -- 10M, 33k raw damage
UPDATE `creature_template` SET `DamageModifier`=106.4 WHERE `entry`=33994; -- 25M, 59k raw damage
-- Koralon the Flame Watcher
UPDATE `creature_template` SET `DamageModifier`=66.5 WHERE `entry`=35013; -- 10M, 37k raw damage
UPDATE `creature_template` SET `DamageModifier`=91.9 WHERE `entry`=35360; -- 25M, 51k raw damage
-- Toravon the Ice Watcher
UPDATE `creature_template` SET `DamageModifier`=107.3 WHERE `entry`=38433; -- 10M, 59.8k raw damage
UPDATE `creature_template` SET `DamageModifier`=117.7 WHERE `entry`=38462; -- 25M, 65.6k raw damage
--
-- Tempest Minion
UPDATE `creature_template` SET `DamageModifier`=15.5 WHERE `entry` IN (33998,34049); -- 10M, 8.4k raw damage
UPDATE `creature_template` SET `DamageModifier`=25 WHERE `entry` IN (34200,33999); -- 25M, 13.5k raw damage
-- Tempest Warder
UPDATE `creature_template` SET `DamageModifier`=47.6 WHERE `entry`=34015; -- 10M, 25.9k raw damage
UPDATE `creature_template` SET `DamageModifier`=91.3 WHERE `entry`=34016; -- 25M, 49.6k raw damage
--
UPDATE `creature_template` SET `minlevel`=82, `maxlevel`=82 WHERE `entry` IN (35143,35359);
UPDATE `creature_template` SET `DamageModifier`=52 WHERE `entry`=35143; -- 10M, 28.3k raw damage
UPDATE `creature_template` SET `DamageModifier`=68.5 WHERE `entry`=35359; -- 25M, 37.3k raw damage
-- Frost Warder
UPDATE `creature_template` SET `DamageModifier`=84.7 WHERE `entry`=38482; -- 10M, 46.1k raw damage
UPDATE `creature_template` SET `DamageModifier`=87.8 WHERE `entry`=38483; -- 25M, 47.8k raw damage
--
-- Archavon Warder
UPDATE `creature_template` SET `DamageModifier`=40.8 WHERE `entry`=32353; -- 10M, 20.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=49.3 WHERE `entry`=32368; -- 25M, 24.8k raw damage
--
-- Gormok the Impaler, level 83 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=45.6 WHERE `entry`=34796; -- 10NM, 25.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=73.3 WHERE `entry`=35438; -- 25NM, 40.9k raw damage
UPDATE `creature_template` SET `DamageModifier`=54.7 WHERE `entry`=35439; -- 10HC, 30.5k raw damage
UPDATE `creature_template` SET `DamageModifier`=119.8 WHERE `entry`=35440; -- 25HC, 66.8k raw damage
-- Snobold Vassal, level 78 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=3.2 WHERE `entry`=34800; -- 10NM, 1.5 raw damage
UPDATE `creature_template` SET `DamageModifier`=5.4 WHERE `entry`=35441; -- 25NM, 2.5 raw damage
UPDATE `creature_template` SET `DamageModifier`=5.4 WHERE `entry`=35442; -- 10HC, 2.5 raw damage
UPDATE `creature_template` SET `DamageModifier`=9.7 WHERE `entry`=35443; -- 25HC, 4.5 raw damage
-- Acidmaw, level 83 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=43.2 WHERE `entry`=35144; -- 10NM, 24.1 raw damage
UPDATE `creature_template` SET `DamageModifier`=81.1 WHERE `entry`=35511; -- 25NM, 45.2 raw damage
UPDATE `creature_template` SET `DamageModifier`=78.0 WHERE `entry`=35512; -- 10HC, 43.5 raw damage
UPDATE `creature_template` SET `DamageModifier`=153.4 WHERE `entry`=35513; -- 25HC, 85.5 raw damage
-- Dreadscale, level 83 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=43.2 WHERE `entry`=34799; -- 10NM, 24.1 raw damage
UPDATE `creature_template` SET `DamageModifier`=81.1 WHERE `entry`=35514; -- 25NM, 45.2 raw damage
UPDATE `creature_template` SET `DamageModifier`=78.0 WHERE `entry`=35515; -- 10HC, 43.5 raw damage
UPDATE `creature_template` SET `DamageModifier`=153.4 WHERE `entry`=35516; -- 25HC, 85.5 raw damage
-- Icehowl, level 83 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=50.2 WHERE `entry`=34797; -- 10NM, 28.0 raw damage
UPDATE `creature_template` SET `DamageModifier`=99.6 WHERE `entry`=35447; -- 25NM, 55.5 raw damage
UPDATE `creature_template` SET `DamageModifier`=72.5 WHERE `entry`=35448; -- 10HC, 40.5 raw damage
UPDATE `creature_template` SET `DamageModifier`=161.8 WHERE `entry`=35449; -- 25HC, 90.2 raw damage
-- Lord Jaraxxus, level 83 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=64.2 WHERE `entry`=34780; -- 10NM, 35.6 raw damage
UPDATE `creature_template` SET `DamageModifier`=84.3 WHERE `entry`=35216; -- 25NM, 46.9 raw damage
UPDATE `creature_template` SET `DamageModifier`=70.3 WHERE `entry`=35268; -- 10HC, 39.1 raw damage
UPDATE `creature_template` SET `DamageModifier`=77.7 WHERE `entry`=35269; -- 25HC, 43.1 raw damage
-- Felflame Infernal, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=16.8 WHERE `entry`=34815; -- 10NM, 9.1 raw damage
UPDATE `creature_template` SET `DamageModifier`=26.3 WHERE `entry`=35262; -- 25NM, 14.3 raw damage
UPDATE `creature_template` SET `DamageModifier`=32.0 WHERE `entry`=35263; -- 10HC, 17.4 raw damage
UPDATE `creature_template` SET `DamageModifier`=49.2 WHERE `entry`=35264; -- 25HC, 26.8 raw damage
-- Mistress of Pain, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=46.4 WHERE `entry`=34826; -- 10NM, 25.3 raw damage
UPDATE `creature_template` SET `DamageModifier`=57.1 WHERE `entry`=35270; -- 25NM, 31.1 raw damage
UPDATE `creature_template` SET `DamageModifier`=54.5 WHERE `entry`=35271; -- 10HC, 29.7 raw damage
UPDATE `creature_template` SET `DamageModifier`=72.2 WHERE `entry`=35272; -- 25HC, 39.3 raw damage
-- Cat, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=0.3 WHERE `entry`=35610; -- 10NM, 0.2 raw damage
UPDATE `creature_template` SET `DamageModifier`=0.7 WHERE `entry`=35774; -- 25NM, 0.3 raw damage
UPDATE `creature_template` SET `DamageModifier`=1.0 WHERE `entry`=35775; -- 10HC, 0.5 raw damage
UPDATE `creature_template` SET `DamageModifier`=2.0 WHERE `entry`=35776; -- 25HC, 1.0 raw damage
-- Zhaagrym, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=1.8 WHERE `entry`=35465; -- 10NM, 0.9 raw damage
UPDATE `creature_template` SET `DamageModifier`=2.0 WHERE `entry`=36301; -- 25NM, 1.0 raw damage
UPDATE `creature_template` SET `DamageModifier`=2.0 WHERE `entry`=36302; -- 10HC, 1.0 raw damage
UPDATE `creature_template` SET `DamageModifier`=3.0 WHERE `entry`=36303; -- 25HC, 1.5 raw damage
-- Treant, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=2.7 WHERE `entry`=36070; -- 10NM, 0.6 raw damage
UPDATE `creature_template` SET `DamageModifier`=3.4 WHERE `entry`=36473; -- 25NM, 0.7 raw damage
UPDATE `creature_template` SET `DamageModifier`=4.9 WHERE `entry`=36474; -- 10HC, 1.0 raw damage
UPDATE `creature_template` SET `DamageModifier`=9.7 WHERE `entry`=36475; -- 25HC, 2.0 raw damage
-- Fjola Lightbane, level 83 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=41.2 WHERE `entry`=34497; -- 10NM, 22.9 raw damage
UPDATE `creature_template` SET `DamageModifier`=56.6 WHERE `entry`=35350; -- 25NM, 31.4 raw damage
UPDATE `creature_template` SET `DamageModifier`=41.0 WHERE `entry`=35351; -- 10HC, 22.8 raw damage
UPDATE `creature_template` SET `DamageModifier`=69.7 WHERE `entry`=35352; -- 25HC, 38.7 raw damage
-- Eydis Darkbane, level 83 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=41.2 WHERE `entry`=34496; -- 10NM, 22.9 raw damage
UPDATE `creature_template` SET `DamageModifier`=56.6 WHERE `entry`=35347; -- 25NM, 31.4 raw damage
UPDATE `creature_template` SET `DamageModifier`=41.0 WHERE `entry`=35348; -- 10HC, 22.8 raw damage
UPDATE `creature_template` SET `DamageModifier`=69.7 WHERE `entry`=35349; -- 25HC, 38.7 raw damage
-- Anub'arak, level 83 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=101.5 WHERE `entry`=34564; -- 10NM, 56.6 raw damage
UPDATE `creature_template` SET `DamageModifier`=146.0 WHERE `entry`=34566; -- 25NM, 81.4 raw damage
UPDATE `creature_template` SET `DamageModifier`=89.2 WHERE `entry`=35615; -- 10HC, 49.7 raw damage
UPDATE `creature_template` SET `DamageModifier`=149.1 WHERE `entry`=35616; -- 25HC, 83.2 raw damage
-- Nerubian Burrower, level 78 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=17.2 WHERE `entry`=34607; -- 10NM, 8.0 raw damage
UPDATE `creature_template` SET `DamageModifier`=29.3 WHERE `entry`=34648; -- 25NM, 13.6 raw damage
UPDATE `creature_template` SET `DamageModifier`=16.2 WHERE `entry`=35655; -- 10HC, 7.6 raw damage
UPDATE `creature_template` SET `DamageModifier`=33.6 WHERE `entry`=35656; -- 25HC, 15.6 raw damage
-- Swarm Scarab, level 79 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=1.0 WHERE `entry`=34605; -- 10NM, 0.5 raw damage
UPDATE `creature_template` SET `DamageModifier`=1.7 WHERE `entry`=34650; -- 25NM, 0.8 raw damage
UPDATE `creature_template` SET `DamageModifier`=1.7 WHERE `entry`=35658; -- 10HC, 0.8 raw damage
UPDATE `creature_template` SET `DamageModifier`=2.1 WHERE `entry`=35659; -- 25HC, 1.0 raw damage
--
-- Argent Champion, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=74.6 WHERE `entry`=37928; -- 10NM, 37.6 k raw damage
-- Ebon Champion, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=74.6 WHERE `entry`=37996; -- 10NM, 37.6 k raw damage
-- The Damned, level 80 NPC, 1000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=36.9 WHERE `entry`=37011; -- 10NM, 9.3 k raw damage
UPDATE `creature_template` SET `DamageModifier`=57.5 WHERE `entry`=38061; -- 25NM, 14.5 k raw damage
-- Servant of the Throne, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=23.9 WHERE `entry`=38057; -- 25NM, 11.9 k raw damage
-- Deathbound Ward, level 82 NPC, 1000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=70.5 WHERE `entry`=37007; -- 10NM, 19.2 k raw damage
UPDATE `creature_template` SET `DamageModifier`=102.9 WHERE `entry`=38031; -- 25NM, 28.0 k raw damage
-- Ancient Skeletal Soldier, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=35.0 WHERE `entry`=38059; -- 25NM, 17.7 k raw damage
-- Nerub'ar Broodkeeper, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=22.6 WHERE `entry`=38058; -- 25NM, 11.3 k raw damage
-- Deathspeaker Attendant, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=13.3 WHERE `entry`=38072; -- 25NM, 6.0 k raw damage
-- Deathspeaker Disciple, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=13.3 WHERE `entry`=38073; -- 25NM, 6.0 k raw damage
-- Deathspeaker Servant, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=13.9 WHERE `entry`=38075; -- 25NM, 6.3 k raw damage
-- Deathspeaker Zealot, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=35.1 WHERE `entry`=36808; -- 10NM, 19.1 k raw damage
UPDATE `creature_template` SET `DamageModifier`=67.0 WHERE `entry`=38076; -- 25NM, 36.5 k raw damage
-- Deathspeaker High Priest, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=83.8 WHERE `entry`=36829; -- 10NM, 45.0 k raw damage
UPDATE `creature_template` SET `DamageModifier`=90.8 WHERE `entry`=38074; -- 25NM, 48.8 k raw damage
-- Skybreaker Dreadblade, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=34.5 WHERE `entry`=37004; -- 10NM, 18.8 k raw damage
UPDATE `creature_template` SET `DamageModifier`=39.6 WHERE `entry`=38079; -- 25NM, 21.5 k raw damage
-- Kor'kron Reaver, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=34.5 WHERE `entry`=37029; -- 10NM, 18.8 k raw damage
UPDATE `creature_template` SET `DamageModifier`=39.6 WHERE `entry`=38092; -- 25NM, 21.5 k raw damage
-- Skybreaker Vindicator, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=30.6 WHERE `entry`=37003; -- 10NM, 16.4 k raw damage
UPDATE `creature_template` SET `DamageModifier`=57.3 WHERE `entry`=38086; -- 25NM, 30.8 k raw damage
-- Kor'kron Vanquisher, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=30.6 WHERE `entry`=37035; -- 10NM, 16.4 k raw damage
UPDATE `creature_template` SET `DamageModifier`=57.3 WHERE `entry`=38096; -- 25NM, 30.8 k raw damage
-- Kor'kron Defender, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=32.6 WHERE `entry`=37032; -- 10NM, 17.7 k raw damage
UPDATE `creature_template` SET `DamageModifier`=34.7 WHERE `entry`=38087; -- 25NM, 18.9 k raw damage
-- Skybreaker Protector, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=32.6 WHERE `entry`=36998; -- 10NM, 17.7 k raw damage
UPDATE `creature_template` SET `DamageModifier`=34.7 WHERE `entry`=38082; -- 25NM, 18.9 k raw damage
-- Kor'kron Stalker, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=40.5 WHERE `entry`=37028; -- 10NM, 22.1 k raw damage
UPDATE `creature_template` SET `DamageModifier`=54.6 WHERE `entry`=38094; -- 25NM, 29.7 k raw damage
-- Skybreaker Assassin, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=40.5 WHERE `entry`=37017; -- 10NM, 22.1 k raw damage
UPDATE `creature_template` SET `DamageModifier`=54.6 WHERE `entry`=38078; -- 25NM, 29.7 k raw damage
-- Spire Minion, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=31.7 WHERE `entry`=37545; -- 10NM, 17.0 k raw damage
UPDATE `creature_template` SET `DamageModifier`=59.4 WHERE `entry`=38445; -- 25NM, 31.9 k raw damage
-- Frenzied Abomination, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=87.9 WHERE `entry`=37546; -- 10NM, 47.8 k raw damage
UPDATE `creature_template` SET `DamageModifier`=87.9 WHERE `entry`=38446; -- 25NM, 47.8 k raw damage
-- Spire Frostwyrm, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=61.6 WHERE `entry`=37230; -- 10NM, 33.1 k raw damage
UPDATE `creature_template` SET `DamageModifier`=100.4 WHERE `entry`=38444; -- 25NM, 53.9 k raw damage
-- Rotting Frost Giant, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=93.0 WHERE `entry`=38494; -- 10NM, 50.6 k raw damage
-- Val'kyr Herald, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=59.1 WHERE `entry`=37098; -- 10NM, 29.8 k raw damage
UPDATE `creature_template` SET `DamageModifier`=73.8 WHERE `entry`=38418; -- 25NM, 37.2 k raw damage
-- Severed Essence, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=18.6 WHERE `entry`=38419; -- 25NM, 9.3 k raw damage
-- Blighted Abomination, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=34.3 WHERE `entry`=37022; -- 10NM, 17.3 k raw damage
UPDATE `creature_template` SET `DamageModifier`=50.5 WHERE `entry`=38108; -- 25NM, 25.5 k raw damage
-- Plague Scientist, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=23.5 WHERE `entry`=37023; -- 10NM, 11.7 k raw damage
UPDATE `creature_template` SET `DamageModifier`=37.7 WHERE `entry`=38062; -- 25NM, 18.8 k raw damage
-- Pustulating Horror, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=23.8 WHERE `entry`=10404; -- 10NM, 12.0 k raw damage
UPDATE `creature_template` SET `DamageModifier`=44.6 WHERE `entry`=38110; -- 25NM, 22.5 k raw damage
-- Vengeful Fleshreaper, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=18.2 WHERE `entry`=38063; -- 25NM, 9.1 k raw damage
-- Decaying Colossus, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=78.2 WHERE `entry`=36880; -- 10NM, 39.4 k raw damage
UPDATE `creature_template` SET `DamageModifier`=95.2 WHERE `entry`=37655; -- 25NM, 48.0 k raw damage
-- Stinky, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=29.6 WHERE `entry`=37025; -- 10NM, 14.9 k raw damage
UPDATE `creature_template` SET `DamageModifier`=62.6 WHERE `entry`=38064; -- 25NM, 31.6 k raw damage
-- Precious, level 80 NPC, 1000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=59.1 WHERE `entry`=37217; -- 10NM, 14.9 k raw damage
UPDATE `creature_template` SET `DamageModifier`=125.4 WHERE `entry`=38103; -- 25NM, 31.6 k raw damage
-- Darkfallen Archmage, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=24.1 WHERE `entry`=38099; -- 25NM, 10.9 k raw damage
-- Darkfallen Blood Knight, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=27.8 WHERE `entry`=37595; -- 10NM, 12.6 k raw damage
UPDATE `creature_template` SET `DamageModifier`=52.3 WHERE `entry`=38100; -- 25NM, 23.6 k raw damage
-- Darkfallen Noble, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=43.9 WHERE `entry`=38480; -- 25NM, 19.8 k raw damage
-- Darkfallen Advisor, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=29.0 WHERE `entry`=38098; -- 25NM, 13.1 k raw damage
-- Darkfallen Lieutenant, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=21.8 WHERE `entry`=37665; -- 10NM, 9.9 k raw damage
UPDATE `creature_template` SET `DamageModifier`=42.2 WHERE `entry`=38101; -- 25NM, 19.1 k raw damage
-- Darkfallen Tactician, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=31.5 WHERE `entry`=37666; -- 10NM, 14.3 k raw damage
UPDATE `creature_template` SET `DamageModifier`=43.9 WHERE `entry`=38479; -- 25NM, 19.8 k raw damage
-- Darkfallen Commander, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=23.5 WHERE `entry`=37662; -- 10NM, 10.6 k raw damage
UPDATE `creature_template` SET `DamageModifier`=45.6 WHERE `entry`=38102; -- 25NM, 20.6 k raw damage
-- Warhawk, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=13.4 WHERE `entry`=38154; -- 10NM, 6.8 k raw damage
-- Ymirjar Huntress, level 80 NPC, 1000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=27.3 WHERE `entry`=38131; -- 25NM, 13.7 k raw damage
-- Ymirjar Warlord, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=25.0 WHERE `entry`=37133; -- 10NM, 12.6 k raw damage
UPDATE `creature_template` SET `DamageModifier`=47.1 WHERE `entry`=38133; -- 25NM, 23.8 k raw damage
-- Ymirjar Battle-Maiden, level 80 NPC, 1000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=74.6 WHERE `entry`=37132; -- 10NM, 18.8 k raw damage
UPDATE `creature_template` SET `DamageModifier`=94.4 WHERE `entry`=38132; -- 25NM, 23.8 k raw damage
-- Ymirjar Deathbringer, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=24.5 WHERE `entry`=38130; -- 25NM, 12.2 k raw damage
-- Sister Svalna, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=125.7 WHERE `entry`=37126; -- 10NM, 27.0 k raw damage
UPDATE `creature_template` SET `DamageModifier`=161.0 WHERE `entry`=38258; -- 25NM, 34.6 k raw damage
-- Frostwarden Sorceress, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=25.2 WHERE `entry`=38137; -- 25NM, 12.7 k raw damage
-- Frostwarden Warrior, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=24.8 WHERE `entry`=38134; -- 25NM, 12.5 k raw damage
-- Nerub'ar Broodling, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=3.5 WHERE `entry`=38362; -- 25NM, 1.8 k raw damage
-- Nerub'ar Champion, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=24.8 WHERE `entry`=38197; -- 25NM, 12.5 k raw damage
-- Frostwarden Handler, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=157.9 WHERE `entry`=38139; -- 25NM, 32.4 k raw damag
-- Frostwing Whelp, level 80 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=14.0 WHERE `entry`=38151; -- 25NM, 2.7 k raw damage
-- Rimefang, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=88.6 WHERE `entry`=37533; -- 10NM, 47.6 k raw damage
UPDATE `creature_template` SET `DamageModifier`=105.0 WHERE `entry`=38220; -- 25NM, 56.4 k raw damage
-- Spinestalker, level 82 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=74.2 WHERE `entry`=37534; -- 10NM, 39.9 k raw damage
UPDATE `creature_template` SET `DamageModifier`=132.6 WHERE `entry`=38219; -- 25NM, 71.2 k raw damage
-- Captain Arnath, level 81 NPC, 1500 ms attack time
UPDATE `creature_template` SET `DamageModifier`=61.9 WHERE `entry`=38349; -- 25NM, 24.1 k raw damage
-- Captain Brandon, level 81 NPC, 1500 ms attack time
UPDATE `creature_template` SET `DamageModifier`=77.3 WHERE `entry`=38350; -- 25NM, 30.1 k raw damage
-- Captain Grondel, level 81 NPC, 1500 ms attack time
UPDATE `creature_template` SET `DamageModifier`=77.3 WHERE `entry`=38351; -- 25NM, 30.3 k raw damage
-- Captain Rupert, level 81 NPC, 1500 ms attack time
UPDATE `creature_template` SET `DamageModifier`=82.4 WHERE `entry`=38352; -- 25NM, 32.4 k raw damage
-- Crok Scourgebane, level 83 NPC, 2000 ms attack time
UPDATE `creature_template` SET `DamageModifier`=33.7 WHERE `entry`=37129; -- 10NM, 18.8 k raw damage
UPDATE `creature_template` SET `DamageModifier`=67.4 WHERE `entry`=38000; -- 25NM, 37.6 k raw damage
