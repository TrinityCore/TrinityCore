-- =============================================
-- Terranios de Khaz Algar - TWW (Fases Oficiales)
-- Mantiene estructura original del primer SQL
-- =============================================

-- Configuración de IDs
SET @NPCID := 180000;
SET @QUESTID := 200000;
SET @GOBJECTID := 500000;
SET @ITEMID := 900000;
SET @SPAWNID := 700000;
SET @PHASEID := 1000;

-- =============================================
-- 1. NPCs (Plantillas y Spawns)
-- =============================================

-- Plantillas de NPCs
INSERT INTO `creature_template` (`entry`, `name`, `subname`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `gossip_menu_id`, `speed_walk`, `VerifiedBuild`) VALUES
(@NPCID+1, 'Brann Barbabronce', 'Liga de Expedicionarios', 70, 70, 2561, 3, 0, 1, 52500),
(@NPCID+2, 'Kaelumon el Vigilante', 'Guardian Terranio', 73, 73, 16, 0, 0, 1.2, 52500),
(@NPCID+3, 'Lorien Petrasombra', 'Estudioso del Vacío', 70, 70, 2553, 3, 0, 1, 52500),
(@NPCID+101, 'Excavador Desconocido', 'Forjado por el Vacío', 70, 70, 16, 0, 0, 1, 52500);

-- Spawns de NPCs con fases
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `phaseId`, `VerifiedBuild`) VALUES
-- Brann (Fase inicial)
(@SPAWNID+1, @NPCID+1, 2197, 5420.31, -1280.45, 1500.22, 3.892, 300, @PHASEID, 52500),

-- Enemigos (Fase inicial)
(@SPAWNID+2, @NPCID+101, 2197, 6210.22, 4930.89, -120.67, 5.934, 120, @PHASEID, 52500),
(@SPAWNID+3, @NPCID+101, 2197, 6185.44, 4875.32, -118.21, 0.122, 120, @PHASEID, 52500),

-- Kaelumon (Fase 200)
(@SPAWNID+4, @NPCID+2, 2197, 7050.11, 3410.75, -850.33, 0.261, 86400, @PHASEID+100, 52500);

-- =============================================
-- 2. OBJETOS INTERACTIVOS
-- =============================================

-- Plantillas de Objetos
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `Data0`, `Data1`, `VerifiedBuild`) VALUES
(@GOBJECTID+1, 5, 9876, 'Consola de Control Primario', 93, 1, 52500),
(@GOBJECTID+2, 3, 5432, 'Reliquia de los Tábidos', 57, 0, 52500);

-- Spawns de Objetos con fases
INSERT INTO `gameobject` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `phaseId`, `VerifiedBuild`) VALUES
-- Consolas (Fase 100)
(@SPAWNID+101, @GOBJECTID+1, 2197, 5860.22, 5120.33, -150.44, 1.221, 0, 0, 0.573, 0.819, 0, @PHASEID+100, 52500),
(@SPAWNID+102, @GOBJECTID+1, 2197, 5920.45, 5075.11, -149.88, 3.801, 0, 0, 0.945, -0.326, 0, @PHASEID+100, 52500),

-- Reliquias (Fase 300)
(@SPAWNID+201, @GOBJECTID+2, 2197, 4400.12, 6790.45, -780.22, 0, 0, 0, 0, 1, 300, @PHASEID+200, 52500);

-- =============================================
-- 3. CADENA DE MISIONES
-- =============================================

-- Misión 1: Llamado de las Profundidades
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestInfoID`, `LogTitle`, `LogDescription`, `QuestDescription`, `Flags`, `RewardMoney`, `RewardFactionID1`, `RewardFactionValue1`, `VerifiedBuild`) VALUES
(@QUESTID+1, 2, 901, 'Llamado de las Profundidades', 'Habla con Brann Barbabronce en Dornogal', '¡Los Terranios despiertan! Sus latidos resuenan bajo nuestros pies...', 0, 250000, 2507, 150, 52500);

INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `ObjectID`, `Amount`, `Description`, `VerifiedBuild`) VALUES
(1, @QUESTID+1, 0, @NPCID+1, 1, 'Habla con Brann Barbabronce', 52500);

-- Misión 2: Rastros de Piedra
INSERT INTO `quest_template` (`ID`, `PrevQuestId`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `RequiredItemId1`, `RequiredItemCount1`, `RewardItem1`, `RewardAmount1`, `VerifiedBuild`) VALUES
(@QUESTID+2, @QUESTID+1, 902, 'Rastros de Piedra', 'Recoge 8 Fragmentos de Resonancia Terrania', @ITEMID+101, 8, @ITEMID+102, 1, 52500);

-- Misión 3: Protocolo de Emergencia
INSERT INTO `quest_template` (`ID`, `PrevQuestId`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `RequiredNpcOrGo1`, `RequiredNpcOrGoCount1`, `RewardFactionID1`, `RewardFactionValue1`, `VerifiedBuild`) VALUES
(@QUESTID+3, @QUESTID+2, 903, 'Protocolo de Emergencia', 'Activa 3 Consolas de Control Primario', @GOBJECTID+1, 3, 2598, 200, 52500);

-- =============================================
-- 4. SISTEMA DE FASES
-- =============================================

-- Definición de Áreas de Fase
INSERT INTO `phase_area` (`areaId`, `phaseId`, `comment`, `VerifiedBuild`) VALUES
(12345, @PHASEID, 'Dornogal - Fase Inicial Terranios', 52500),
(12345, @PHASEID+100, 'Dornogal - Máquina de Despertar', 52500),
(12345, @PHASEID+200, 'Dornogal - Terranios Aliados', 52500);

-- Condiciones de Desbloqueo
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`, `VerifiedBuild`) VALUES
(26, 0, @PHASEID+100, 0, 8, @QUESTID+1, 0, 'Desbloquear Fase 100 al completar misión inicial', 52500),
(26, 0, @PHASEID+200, 0, 8, @QUESTID+3, 0, 'Desbloquear Fase 200 al completar Protocolo', 52500);

-- =============================================
-- 5. ITEMS Y RECOMPENSAS
-- =============================================

-- Plantillas de Items
INSERT INTO `item_template` (`entry`, `name`, `Quality`, `ItemLevel`, `class`, `subclass`, `InventoryType`, `DisplayInfoID`, `VerifiedBuild`) VALUES
(@ITEMID+101, 'Fragmento de Resonancia Terrania', 1, 480, 15, 0, 0, 65432, 52500),
(@ITEMID+102, 'Brazales de Geomensor', 3, 480, 4, 3, 9, 71234, 52500),
(@ITEMID+103, 'Capa del Geodínamo', 4, 483, 4, 1, 16, 71235, 52500);

-- Recompensas de Misión
INSERT INTO `quest_rewards` (`ID`, `QuestID`, `ItemID`, `ItemCount`, `VerifiedBuild`) VALUES
(1, @QUESTID+2, @ITEMID+102, 1, 52500),
(2, @QUESTID+3, @ITEMID+103, 1, 52500);

-- =============================================
-- 6. WARBAND (Sistema TWW)
-- =============================================

-- Reputación Compartida
INSERT INTO `account_shared_faction_reputation` (`faction`, `flags`, `VerifiedBuild`) VALUES
(2598, 1, 52500); -- Terranios de Khaz Algar

-- Objetos de Banda
INSERT INTO `item_template` (`entry`, `name`, `Quality`, `ItemLevel`, `class`, `subclass`, `WarbandItemIndex`, `InventoryType`, `VerifiedBuild`) VALUES
(@ITEMID+201, 'Cristal de Resonancia Ancestral', 4, 510, 15, 0, 1, 0, 52500);
