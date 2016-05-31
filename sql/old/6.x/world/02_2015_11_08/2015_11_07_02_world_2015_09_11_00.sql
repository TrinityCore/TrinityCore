DROP TABLE IF EXISTS `skill_perfect_item_template`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `skill_perfect_item_template` (
	`spellId` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'SpellId of the item creation spell',
	`requiredSpecialization` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Specialization spell id',
	`perfectCreateChance` float NOT NULL DEFAULT '0' COMMENT 'chance to create the perfect item instead',
	`perfectItemType` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'perfect item type to create instead',
	PRIMARY KEY (`spellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Crafting Perfection System';
/*!40101 SET character_set_client = @saved_cs_client */;

LOCK TABLES `skill_perfect_item_template` WRITE;
/*!40000 ALTER TABLE `skill_perfect_item_template` DISABLE KEYS */;
INSERT INTO `skill_perfect_item_template` (`spellId`, `requiredSpecialization`, `perfectCreateChance`, `perfectItemType`)
VALUES
/* Bloodstone */
(53831,55534,20,41432), -- Bold
(53835,55534,20,41433), -- Bright
(53832,55534,20,41434), -- Delicate
(53844,55534,20,41435), -- Flashing
(53845,55534,20,41436), -- Fractured
(54017,55534,20,41437), -- Precise
(53834,55534,20,41438), -- Runed
(53843,55534,20,41439), -- Subtle
/* Sun Crystal */
(53852,55534,20,41444), -- Brilliant
(53857,55534,20,41445), -- Mystic
(53856,55534,20,41446), -- Quick
(53854,55534,20,41447), -- Rigid
(53853,55534,20,41448), -- Smooth
(53855,55534,20,41449), -- Thick
/* Chalcedony */
(53941,55534,20,41440), -- Lustrous
(53934,55534,20,41441), -- Solid
(53940,55534,20,41442), -- Sparkling
(53943,55534,20,41443), -- Stormy
/* Dark Jade */
(53926,55534,20,41463), -- Dazzling
(53918,55534,20,41464), -- Enduring
(53930,55534,20,41465), -- Energized
(53920,55534,20,41466), -- Forceful
(53925,55534,20,41467), -- Intricate
(53916,55534,20,41468), -- Jagged
(53928,55534,20,41469), -- Lambent
(53922,55534,20,41470), -- Misty
(53929,55534,20,41471), -- Opaque
(53931,55534,20,41472), -- Radiant
(53921,55534,20,41473), -- Seer's
(53933,55534,20,41474), -- Shattered
(53923,55534,20,41475), -- Shining
(53919,55534,20,41476), -- Steady
(53927,55534,20,41477), -- Sundered
(53932,55534,20,41478), -- Tense
(53894,55534,20,41479), -- Timeless
(53924,55534,20,41480), -- Turbid
(53917,55534,20,41481), -- Vivid
/* Huge Citrine */
(53886,55534,20,41429), -- Wicked
(53892,55534,20,41482), -- Accurate
(53874,55534,20,41483), -- Champion's
(53877,55534,20,41484), -- Deadly
(53880,55534,20,41485), -- Deft
(53884,55534,20,41486), -- Durable
(53888,55534,20,41487), -- Empowered
(53873,55534,20,41488), -- Etched
(53876,55534,20,41489), -- Fierce
(53891,55534,20,41490), -- Glimmering
(53878,55534,20,41491), -- Glinting
(53872,55534,20,41492), -- Inscribed
(53879,55534,20,41493), -- Lucent
(53881,55534,20,41494), -- Luminous
(53882,55534,20,41495), -- Potent
(53887,55534,20,41496), -- Pristine
(53885,55534,20,41497), -- Reckless
(53893,55534,20,41498), -- Resolute
(53875,55534,20,41499), -- Resplendent
(53890,55534,20,41500), -- Stalwart
(53889,55534,20,41501), -- Stark
(53883,55534,20,41502), -- Veiled
/* Shadow Crystal */
(53866,55534,20,41450), -- Balanced
(53869,55534,20,41451), -- Defender's
(53862,55534,20,41452), -- Glowing
(53871,55534,20,41453), -- Guardian's
(53867,55534,20,41454), -- Infused
(53865,55534,20,41455), -- Mysterious
(53870,55534,20,41456), -- Puissant
(53863,55534,20,41457), -- Purified
(53868,55534,20,41458), -- Regal
(53864,55534,20,41459), -- Royal
(53860,55534,20,41460), -- Shifting
(53859,55534,20,41461), -- Sovereign
(53861,55534,20,41462); -- Tenuous
/*!40000 ALTER TABLE `skill_perfect_item_template` ENABLE KEYS */;
UNLOCK TABLES;
