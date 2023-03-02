-- Ruby Sanctum white damage update
UPDATE `creature_template` SET `DamageModifier`=114 WHERE `entry` IN (39863,40142); -- Halion/Halion Twilight 10N
UPDATE `creature_template` SET `DamageModifier`=172 WHERE `entry` IN (39864,40143); -- Halion/Halion Twilight 25N
UPDATE `creature_template` SET `DamageModifier`=172 WHERE `entry` IN (39944,40144); -- Halion/Halion Twilight 10H
UPDATE `creature_template` SET `DamageModifier`=257 WHERE `entry` IN (39945,40145); -- Halion/Halion Twilight 25H

UPDATE `creature_template` SET `DamageModifier`= 86 WHERE `entry`=39746; -- General Zarithrian 10
UPDATE `creature_template` SET `DamageModifier`=129 WHERE `entry`=39805; -- General Zarithrian 25

UPDATE `creature_template` SET `DamageModifier`= 86 WHERE `entry`=39747; -- Saviana Ragefire 10
UPDATE `creature_template` SET `DamageModifier`=129 WHERE `entry`=39823; -- Saviana Ragefire 25

UPDATE `creature_template` SET `DamageModifier`= 86 WHERE `entry`=39751; -- Baltharus the Warborn 10
UPDATE `creature_template` SET `DamageModifier`=129 WHERE `entry`=39920; -- Baltharus the Warborn 25

UPDATE `creature_template` SET `DamageModifier`= 86 WHERE `entry`=39899; -- Baltharus Clone 10
UPDATE `creature_template` SET `DamageModifier`=129 WHERE `entry`=39922; -- Baltharus Clone 25

UPDATE `creature_template` SET `DamageModifier`= 20 WHERE `entry` IN (40429); -- Sanctum Guardian Xerestrasza

-- Trash Mobs: Charscale Invoker, Charscale Assaulter, Charscale Elite, Charscale Commander
UPDATE `creature_template` SET `DamageModifier`= 20 WHERE `entry` IN (40417,40419,40421,40423); -- 10
UPDATE `creature_template` SET `DamageModifier`= 40 WHERE `entry` IN (40418,40420,40422,40424); -- 25

-- Ruby Drakonid, Ruby Drake, Ruby Scalebane, Ruby Dragon
UPDATE `creature_template` SET `DamageModifier`= 20 WHERE `entry` IN (40626,40627,40628,40870);

UPDATE `creature_template` SET `DamageModifier`= 14 WHERE `entry`=40683; -- Living Ember 10
UPDATE `creature_template` SET `DamageModifier`= 22 WHERE `entry`=40684; -- Living Ember 25

UPDATE `creature_template` SET `DamageModifier`= 86 WHERE `entry`=40681; -- Living Inferno 10
UPDATE `creature_template` SET `DamageModifier`=129 WHERE `entry`=40682; -- Living Inferno 25
