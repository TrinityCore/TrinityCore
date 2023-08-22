-- 
DROP TABLE IF EXISTS `areatrigger_polygon_vertex`;
CREATE TABLE `areatrigger_polygon_vertex`  (
  `SpawnId` bigint UNSIGNED NOT NULL,
  `Idx` int UNSIGNED NOT NULL,
  `VerticeX` float NOT NULL DEFAULT 0,
  `VerticeY` float NOT NULL DEFAULT 0,
  `VerticeTargetX` float NULL DEFAULT NULL,
  `VerticeTargetY` float NULL DEFAULT NULL,
  `VerifiedBuild` int UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`SpawnId`, `Idx`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;
