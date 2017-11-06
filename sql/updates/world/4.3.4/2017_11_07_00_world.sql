-- Bloodtalon Raptor, Bloodtalon Hatchling, Corrupted Bloodtalon, Swiftclaw, Tiki Target, Wildmane Cat, Docile Island Boar, Captive Spitescale Scout
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (37956,37960,37961,37989,38038,38046,38141,38142);
-- Spitescale Wavethrasher, Spitescale Siren, Manifestation of the Sea Witch, Pygmy Surf Crawler, Naj'tess, Lost Bloodtalon Hatchling
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (38300,38301,38302,39004,39072,39157);

UPDATE `creature_classlevelstats` SET `basehp3`=80 WHERE `level`=1 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=101 WHERE `level`=2 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=122 WHERE `level`=3 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=143 WHERE `level`=4 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=164 WHERE `level`=5 AND `class` IN (1,2,4);
