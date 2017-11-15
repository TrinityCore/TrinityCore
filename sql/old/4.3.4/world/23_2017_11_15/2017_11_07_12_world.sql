UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=1 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=2 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=3 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=4 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=5 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=6 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=7 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=8 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=9 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=10 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=11 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=18 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=20 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=30 AND `class` IN (1,2,4);

UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=4 AND `class` IN (8);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=8 AND `class` IN (8);
UPDATE `creature_classlevelstats` SET `basehp3`=1 WHERE `level`=11 AND `class` IN (8);

-- Marshal McBride, Janos Hammerknuckle, Brother Danil, Dermot Johns,Godric Rothgar, Stormwind Infantry, Blackrock Worg, Blackrock Spy, Brother Paxton
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (197,78,152,190,1213,49869,49871,49874,951);
-- Injured Stormwind Infantry, Goblin Assassin, Sergeant Willem, Milly Osworth, Stormwind Army Registrar, Ashley Blank, Riding White Stallion,Drusilla La Salle
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (50047,50039,823,9296,42216,43278,5403,459);
-- Dane Winslow, Jorik Kerridan, Northshire Peasant, Blackrock Invader, Kurtok the Slayer, Llane Beshere, Brother Sammuel, Priestess Anetta,Khelden Bremen,Gug Fatcandle, Falkhaan Isenstrider
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (6373,915,11260,42937,42938,911,925,375,198,62,6774);
-- Bloodtalon Raptor, Bloodtalon Hatchling, Corrupted Bloodtalon, Swiftclaw, Tiki Target, Wildmane Cat, Docile Island Boar, Captive Spitescale Scout
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (37956,37960,37961,37989,38038,38046,38141,38142);
-- Spitescale Wavethrasher, Spitescale Siren, Manifestation of the Sea Witch, Pygmy Surf Crawler, Naj'tess, Lost Bloodtalon Hatchling
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (38300,38301,38302,39004,39072,39157);
-- Jin'thala, Nekali, Voldreka, Darkspear Jailor, Legati, Nortet, Ortezza, Tunari, Zen'tabra, Soratha, Wounded Darkspear Watcher
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (37951,38242,42618,39062,38244,38037,38247,38245,38243,38246,47057);
-- Novice Darkspear Warrior, Novice Darkspear Rogue, Novice Darkspear Priest, Novice Darkspear Mage, Novice Darkspear Druid, Novice Darkspear Shaman, Novice Darkspear Hunter, Novice Darkspear Warlock 
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (38268,38272,38278,38279,38280,38281,38282,42619);
-- Gora'tin, Moraya, Morakki, Torenda, Jornun, Bloodtalon Thrasher, Sortura, Tora'jin, Hira'jin
UPDATE `creature_template` SET `exp`=0 WHERE `entry` IN (39032,38005,38442,39031,38989,38987,39033,39007,39008);
