-- Trigger flag
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=34129;

-- Delete NPC which is not supposed to be here
DELETE FROM `creature` WHERE `guid`=136607;

-- Immunity
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=32906;

-- Spell Difficulties
DELETE FROM `spelldifficulty_dbc` WHERE `id` BETWEEN 3240 AND 3250;
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`)
VALUES
(3240,63169,63549,0,0), -- Ulduar: Corrupted Servitor - Petrify Joints
(3241,63082,63559,0,0), -- Ulduar: Misguided Nymph - Bind Life
(3242,63111,63562,0,0), -- Ulduar: Misguided Nymph - Frost Spear
(3243,63136,63564,0,0), -- Ulduar: Misguided Nymph - Winter's Embrace
(3244,63047,63550,0,0), -- Ulduar: Guardian Lasher - Guardian's Lash
(3245,63242,63556,0,0), -- Ulduar: Mangrove Ent - Nourish
(3246,63241,63554,0,0), -- Ulduar: Mangrove Ent - Tranquility
(3247,63240,63553,0,0), -- Ulduar: Ironroot Lasher - Ironroot Thorns
(3248,63247,63568,0,0), -- Ulduar: Nature's Blade - Living Tsunami
(3249,63226,63551,0,0), -- Ulduar: Guardian of Life - Poison Breath
(3250,64650,34650,0,0); -- Ulduar: Nature Bomb - Nature Bomb
