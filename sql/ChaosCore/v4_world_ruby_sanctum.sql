-- Charscale Invoker
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '7.5' WHERE entry =40417;
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '12.5' WHERE entry =40418;
 -- Charscale Assaulter
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '7.5' WHERE entry =40419;
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '12.5' WHERE entry =40420;
 -- Charscale Elite
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '7.5' WHERE entry =40421;
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '12.5' WHERE entry =40422;
 -- Charscale Commander
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '7.5' WHERE entry =40423;
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '12.5' WHERE entry =40424;

-- Baltharus the Warborn
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39751;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39920;

-- Baltharus Clone
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39899;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39922;

-- Saviana Ragefire
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39747;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39823;

-- General Zarithrian
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39746;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39805;

-- Halion
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39863;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39864;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '55' WHERE entry =39944;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '75' WHERE entry =39945;

-- Twilight Halion
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =40142;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =40143;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '55' WHERE entry =40144;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '75' WHERE entry =40145;

UPDATE creature_template SET mechanic_immune_mask = 617299803 WHERE entry IN (39751,39920,39899,39922,39747,39823,39746,39805,39863,39864,39944,39945,40142,40143,40144,40145);

UPDATE creature_template SET faction_A=103, faction_H=103, speed_walk=2, unit_flags=64 WHERE entry IN (39746,39805);
