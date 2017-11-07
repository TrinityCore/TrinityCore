UPDATE `creature_classlevelstats` SET `basehp3`=114 WHERE `level`=4 AND `class` IN (8);
UPDATE `creature_classlevelstats` SET `basehp3`=182 WHERE `level`=8 AND `class` IN (8);
UPDATE `creature_classlevelstats` SET `basehp3`=269 WHERE `level`=10 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=488 WHERE `level`=18 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=547 WHERE `level`=20 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=950 WHERE `level`=30 AND `class` IN (1,2,4);

-- Marshal McBride, Janos Hammerknuckle, Brother Danil, Dermot Johns,Godric Rothgar, Stormwind Infantry, Blackrock Worg, Blackrock Spy, Brother Paxton
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (197,78,152,190,1213,49869,49871,49874,951);
-- Injured Stormwind Infantry, Goblin Assassin, Sergeant Willem, Milly Osworth, Stormwind Army Registrar, Ashley Blank, Riding White Stallion,Drusilla La Salle
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (50047,50039,823,9296,42216,43278,5403,459);
-- Dane Winslow, Jorik Kerridan, Northshire Peasant, Blackrock Invader, Kurtok the Slayer, Llane Beshere, Brother Sammuel, Priestess Anetta,Khelden Bremen,Gug Fatcandle, Falkhaan Isenstrider
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (6373,915,11260,42937,42938,911,925,375,198,62,6774);
