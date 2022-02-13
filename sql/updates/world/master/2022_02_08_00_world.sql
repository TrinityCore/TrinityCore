--
-- Table structure for table `achievement_scripts`
--

DROP TABLE IF EXISTS `achievement_scripts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `achievement_scripts` (
  `AchievementId` int NOT NULL,
  `ScriptName` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`AchievementId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `achievement_scripts`
--
LOCK TABLES `achievement_scripts` WRITE;
/*!40000 ALTER TABLE `achievement_scripts` DISABLE KEYS */;
INSERT INTO `achievement_scripts` (`AchievementId`, `ScriptName`) VALUES
(6566,'achievement_just_a_pup'),
(7433,'achievement_newbie');
/*!40000 ALTER TABLE `achievement_scripts` ENABLE KEYS */;
UNLOCK TABLES;
