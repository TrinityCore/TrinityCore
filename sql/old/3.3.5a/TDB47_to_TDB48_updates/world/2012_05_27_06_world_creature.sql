-- Tukemuth
DELETE FROM `smart_scripts` WHERE `entryorguid`=32400;
INSERT INTO `smart_scripts` VALUES
(32400,0,0,0,9,0,100,0,0,5,9000,13000,11,50410,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Tukemuth - Cast Tusk Strike'),
(32400,0,1,0,0,0,100,0,9000,17000,15000,22000,11,57066,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Tukemuth - Cast Trample');
UPDATE `creature_template` SET faction_A=7,faction_H=7,mindmg=2926.0,maxdmg=3542.0,skinloot=70209,spell1=50410,spell2=57066,attackpower=3384,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=2147483647 where entry=32400;

-- Fumblub Gearwind
DELETE FROM `smart_scripts` WHERE `entryorguid`=32358;
INSERT INTO `smart_scripts` VALUES
(32358,0,0,0,0,0,100,0,4000,6000,12000,15000,11,60906,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Fumblub Gearwind - Cast Machine Gun');
UPDATE `creature_template` SET faction_A=14,faction_H=14,mindmg=2792,maxdmg=3376,spell1=60906,attackpower=3384,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=2147483647,type_flags=2048,InhabitType=4 where entry=32358;
UPDATE `creature_addon` SET mount=22719,bytes1=33554432 where guid=151938;

-- Old Crystalbark
DELETE FROM `smart_scripts` WHERE `entryorguid`=32357;
INSERT INTO `smart_scripts` VALUES
(32357,0,0,0,0,0,100,0,3700,16200,19200,28000,11,50506,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Old Crystalbark - Cast Mark of Detonation'),
(32357,0,1,0,0,0,100,0,1625,8100,9600,14000,11,60903,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Old Crystalbark - Cast Arcane Breath');
UPDATE `creature_template` SET faction_A=14,faction_H=14,mindmg=3231.0,maxdmg=3309.0,spell1=60903,spell2=50506,attackpower=3214,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=2147483647 where entry=32357;

-- Terror Spinner - Tameable
DELETE FROM `smart_scripts` WHERE `entryorguid`=32475;
INSERT INTO `smart_scripts` VALUES
(32475,0,0,0,0,0,100,0,4000,6000,12000,15000,11,36839,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Terror Spinner - Cast Impairing Poison'),
(32475,0,1,0,0,0,100,0,1625,8100,9600,14000,11,28428,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Terror Spinner - Cast Instant Poison');
UPDATE `creature_template` SET faction_A=14,faction_H=14,mindmg=3625.0,maxdmg=4301.0,spell1=32475,spell2=28428,attackpower=3963,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=66624,name= 'Terror Spinner' where entry=32475;

-- Hildana Deathstealer
DELETE FROM `smart_scripts` WHERE `entryorguid`=32495;
INSERT INTO `smart_scripts` VALUES
(32495,0,0,0,0,0,100,1,0,0,0,0,22,1,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Hildana Deathstealer - Enter phase 1'),
(32495,0,1,2,0,1,100,0,3000,6000,4000,6000,11,60991,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Hildana Deathstealer - Cast Lash'),
(32495,0,2,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Hildana Deathstealer - Enter phase 2'),
(32495,0,3,0,0,2,100,0,3000,5000,9000,11000,11,57547,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Hildana Deathstealer - Cast Touch of the Valkyr'),
(32495,0,4,0,0,2,100,0,12000,13000,13000,15000,22,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Hildana Deathstealer - timer back to phase 1');
UPDATE `creature_template` SET faction_A=14,faction_H=14,mindmg=4715,maxdmg=5474,attackpower=5094,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=2147483647 where entry=32495;

-- Syreian the Bonecarver
UPDATE `creature_template` SET faction_A=14,faction_H=14,mindmg=2926,maxdmg=3542,spell1=38952,spell2=47168,spell3=50092,attackpower=3234,dmg_multiplier=1.0,mechanic_immune_mask=2147483647 where entry=32438;

-- Icehorn - Tameable
DELETE FROM `smart_scripts` WHERE `entryorguid`=32361;
INSERT INTO `smart_scripts` VALUES
(32361,0,0,0,0,0,100,0,4500,6750,6750,9750,11,57468,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Icehorn - Cast Romp');
UPDATE `creature_template` SET type_flags= '1',faction_A=14,faction_H=14,mindmg=2792,maxdmg=3376,spell1=57468,attackpower=3084,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=66624,skinloot=70211 where entry=32361;

-- King Ping
DELETE FROM `smart_scripts` WHERE `entryorguid`=32398;
INSERT INTO `smart_scripts` VALUES
(32398,0,0,0,0,0,100,0,1600,8000,12400,13000,11,61115,0,0,0,0,0,2,0,0,0,0,0,0,0, 'King Ping - Cast Belly Flop'),
(32398,0,1,0,0,0,100,0,800,2600,4200,6800,11,50169,0,0,0,0,0,2,0,0,0,0,0,0,0, 'King Ping - Cast Flipper Thwack');
UPDATE `creature_template` SET faction_A=14,faction_H=14,mindmg=2792,maxdmg=3376,spell1=61115,spell2=50169,attackpower=3234,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=2147483647 WHERE entry=32398;

-- High Thane Jorfus
DELETE FROM `smart_scripts` WHERE `entryorguid`=32501;
INSERT INTO `smart_scripts` VALUES
(32501,0,0,0,0,0,100,0,1600,3200,6400,12800,11,60950,0,0,0,0,0,2,0,0,0,0,0,0,0, 'High Thane Jorfus - Cast Blood Plague'),
(32501,0,1,0,0,0,100,2,10000,20000,10000,20000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0, 'High Thane Jorfus - Cast Blood Strike'),
(32501,0,2,0,0,0,100,0,8000,13000,16000,21000,11,60953,1,0,0,0,0,5,0,0,0,0,0,0,0, 'High Thane Jorfus - Cast Death and Decaye'),
(32501,0,3,0,0,0,100,4,1000,1400,8500,20500,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0, 'High Thane Jorfus - Cast Death Coil'),
(32501,0,4,0,0,0,100,2,5000,9000,15000,22000,11,60951,0,0,0,0,0,2,0,0,0,0,0,0,0, 'High Thane Jorfus - Cast Frost Strike');
UPDATE `creature_template` set faction_A=14,faction_H=14,mindmg=4894,maxdmg=5649,spell1=60950,spell2=60945,spell3=60953,spell4=60949,spell5=60951,attackpower=5271,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=2147483647 WHERE entry=32501;

-- Perobas the Bloodthirster
DELETE FROM `smart_scripts` WHERE `entryorguid`=32377;
INSERT INTO `smart_scripts` VALUES
(32377,0,0,0,0,0,100,0,5000,8000,12000,15000,11,50046,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Perobas the Bloodthirster - Cast Gnaw Bone'),
(32377,0,1,0,2,0,100,0,0,50,10000,13000,11,50271,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Perobas the Bloodthirster - Cast Killing Rage');
UPDATE `creature_template` set faction_A=14,faction_H=14,mindmg=2792,maxdmg=3376,spell1=50046,spell2=52071,attackpower=3084,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=66624,skinloot=70209 where entry=32377;

-- Aotona - Tameable
UPDATE `creature` SET curhealth=15952  where id=32481;
UPDATE `creature_template` SET exp=2,armor_mod=1.0,minlevel=75,maxlevel=75,faction_A=14,faction_H=14,mindmg=3376,maxdmg=4034,spell1=49865,spell2=51144,attackpower=3705,dmg_multiplier=1.0,mechanic_immune_mask=66624 where entry=32481;

--  Griegen
DELETE FROM `smart_scripts` WHERE `entryorguid`=32471;
INSERT INTO `smart_scripts` VALUES
(32471,0,0,0,0,0,100,0,5000,8000,9000,12000,11,51334,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Griegen - Cast Smash');
UPDATE `creature` set curhealth=15952  where id=32471;
UPDATE `creature_template` set exp=2,armor_mod=1.0,minlevel=75,maxlevel=75,faction_A=14,faction_H=14,mindmg=3376,maxdmg=4034,spell1=51334,attackpower=3705,dmg_multiplier=1.0,AIName= 'SmartAI',mechanic_immune_mask=2147483647 where entry=32471;

-- Seething Hate
UPDATE `creature_template` SET mindmg=2926,maxdmg=3542,attackpower=3234,dmg_multiplier=1.0,mechanic_immune_mask=66624 WHERE entry=32429;

-- Vigdis the War Maiden
DELETE FROM `creature_template_addon` WHERE entry=32386;
INSERT INTO `creature_template_addon` VALUES
(32386,0,28040,0,0,0,NULL);
UPDATE `creature` SET spawndist=20.0,MovementType=1 WHERE id=32386;
UPDATE `creature_template` SET faction_A=14,faction_H=14,mindmg=2792,maxdmg=3376,attackpower=3084,dmg_multiplier=1.0,mechanic_immune_mask=2147483647,InhabitType=1 where entry=32386;

-- King Krush - Tameable
UPDATE `creature_template` SET faction_A=14,faction_H=14,mechanic_immune_mask=66624 WHERE entry=32485;

-- Scarlet Highlord Daion
UPDATE `creature_template` SET faction_A=14,faction_H=14,mindmg=2926,maxdmg=3542,attackpower=3234,dmg_multiplier=1.0,mechanic_immune_mask=66624 WHERE entry=32417;

-- Crazed Indu'le Survivor
UPDATE `creature_template` SET mindmg=2926,maxdmg=3542,attackpower=3234,dmg_multiplier=1.0,mechanic_immune_mask=66624 WHERE entry=32409;

-- Grocklar
UPDATE `creature_template` SET mindmg=3137,maxdmg=3777,attackpower=3457,dmg_multiplier=1.0,mechanic_immune_mask=66624 WHERE entry=32422;

-- Loque'nahak - Tameable
UPDATE `creature_template` SET type_flags= '1',mechanic_immune_mask=66624 WHERE entry=32422;

-- Zuldrak Sentinel
DELETE FROM `smart_scripts` WHERE `entryorguid`=32447;
INSERT INTO `smart_scripts` VALUES
(32447,0,0,0,0,0,100,0,0,5,9000,13000,11,55196,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Zuldrak Sentinel - Cast Stomp'),
(32447,0,1,0,0,0,100,0,15000,20000,21000,35000,11,54565,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Zuldrak Sentinel - Cast Whammy');
UPDATE `creature_template` SET mindmg= '3905',maxdmg= '4600',attackpower= '4252',dmg_multiplier= '1.0',mechanic_immune_mask= '66624',spell1= '54565',spell2= '55196',AIName= 'SmartAI' WHERE entry= '32447';
