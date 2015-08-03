-- Update gold drops in ICC bosses based on old.wowhead.com data
UPDATE `creature_template` SET `mingold`=250000,`maxgold`=300000 WHERE `entry` IN(36612,37957,37958,37959); -- Lord Marrowgar
UPDATE `creature_template` SET `mingold`=175000,`maxgold`=225000 WHERE `entry` IN (36626,37504,37505,37506); -- Festergut
UPDATE `creature_template` SET `mingold`=400000,`maxgold`=500000 WHERE `entry` IN (36627,38390,38549,38550); -- Rotface
UPDATE `creature_template` SET `mingold`=400000,`maxgold`=500000 WHERE `entry` IN (36678,38431,38585,38586); -- Professor Putricide
UPDATE `creature_template` SET `mingold`=300000,`maxgold`=350000 WHERE `entry` IN (37955,38434,38435,38436); -- Blood-Queen Lana'thel
UPDATE `creature_template` SET `mingold`=1330000,`maxgold`=1400000 WHERE `entry` IN (36853,38265,38266,38267); -- Sindragosa
UPDATE `creature_template` SET `mingold`=1300000,`maxgold`=1500000 WHERE `entry` IN (36597,39166,39167,39168); -- The Lich King
