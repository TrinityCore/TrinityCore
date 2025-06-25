-- =============================================
-- Terranios de Khaz Algar - TWW (Cadena Completa)
-- =============================================

-- Configuración de IDs
SET @NPCID := 180000;
SET @QUESTID := 200000;
SET @GOBJECTID := 500000;
SET @ITEMID := 900000;
SET @SPAWNID := 700000;
SET @PHASEID := 1000;
SET @SOUNDID := 35000;
SET @SPELLID := 87000;

-- =============================================
-- 1. NPCs (Plantillas y Spawns)
-- =============================================

-- Plantillas de NPCs
INSERT INTO `creature_template` (`entry`, `name`, `subname`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `gossip_menu_id`, `speed_walk`, `scale`, `unit_class`, `VerifiedBuild`) VALUES
(@NPCID+1, 'Brann Barbabronce', 'Liga de Expedicionarios', 70, 70, 2561, 3, 0, 1, 1, 1, 52500),
(@NPCID+2, 'Kaelumon el Vigilante', 'Guardian Terranio', 73, 73, 16, 0, 0, 1.2, 1.5, 1, 52500),
(@NPCID+3, 'Lorien Petrasombra', 'Estudioso del Vacío', 70, 70, 2553, 3, 0, 1, 1, 1, 52500),
(@NPCID+4, 'Vigía Terranio', 'Defensor de Khaz Algar', 70, 70, 2598, 0, 0, 1, 1.2, 1, 52500),
(@NPCID+5, 'Geomántica Aela', 'Instructora Terrania', 70, 70, 2598, 3, 0, 1, 1, 1, 52500),
(@NPCID+101, 'Excavador Desconocido', 'Forjado por el Vacío', 70, 70, 16, 0, 0, 1, 1, 1, 52500),
(@NPCID+102, 'Manipulador del Vacío', 'Siervo de Xal\'atath', 70, 70, 16, 0, 0, 1.1, 1, 1, 52500),
(@NPCID+103, 'Guardian de Roca', 'Esbirro de Kaelumon', 72, 72, 16, 0, 0, 0.8, 2, 1, 52500);

-- Spawns de NPCs con fases
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `phaseId`, `VerifiedBuild`) VALUES
-- Fase 1000: Introducción
(@SPAWNID+1, @NPCID+1, 2197, 5420.31, -1280.45, 1500.22, 3.892, 300, @PHASEID, 52500),
(@SPAWNID+2, @NPCID+101, 2197, 6210.22, 4930.89, -120.67, 5.934, 120, @PHASEID, 52500),
(@SPAWNID+3, @NPCID+101, 2197, 6185.44, 4875.32, -118.21, 0.122, 120, @PHASEID, 52500),

-- Fase 1100: Máquina de Despertar
(@SPAWNID+4, @NPCID+4, 2197, 5860.22, 5120.33, -150.44, 1.221, 0, @PHASEID+100, 52500),

-- Fase 1200: Post-Kaelumon
(@SPAWNID+5, @NPCID+2, 2197, 7050.11, 3410.75, -850.33, 0.261, 86400, @PHASEID+200, 52500),
(@SPAWNID+6, @NPCID+103, 2197, 7035.67, 3395.22, -849.11, 0.785, 300, @PHASEID+200, 52500),

-- Fase 1300: Aliados
(@SPAWNID+7, @NPCID+5, 2197, 5385.67, -1250.22, 1502.11, 0.785, 0, @PHASEID+300, 52500),
(@SPAWNID+8, @NPCID+3, 2197, 4470.67, 6790.45, -780.22, 4.712, 300, @PHASEID+300, 52500);

-- =============================================
-- 2. OBJETOS INTERACTIVOS
-- =============================================

-- Plantillas de Objetos
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `Data0`, `Data1`, `VerifiedBuild`) VALUES
(@GOBJECTID+1, 5, 9876, 'Consola de Control Primario', 93, 1, 52500),
(@GOBJECTID+2, 3, 5432, 'Reliquia de los Tábidos', 57, 0, 52500),
(@GOBJECTID+3, 10, 7654, 'Núcleo de Eternidad', 1691, 0, 52500), -- Objeto de misión Gouffres
(@GOBJECTID+4, 3, 8765, 'Artefacto Terranio Enterrado', 57, 0, 52500);

-- Spawns de Objetos con fases
INSERT INTO `gameobject` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `phaseId`, `VerifiedBuild`) VALUES
-- Consolas (Fase 1100)
(@SPAWNID+101, @GOBJECTID+1, 2197, 5860.22, 5120.33, -150.44, 1.221, 0, 0, 0.573, 0.819, 0, @PHASEID+100, 52500),
(@SPAWNID+102, @GOBJECTID+1, 2197, 5920.45, 5075.11, -149.88, 3.801, 0, 0, 0.945, -0.326, 0, @PHASEID+100, 52500),
(@SPAWNID+103, @GOBJECTID+1, 2197, 5810.67, 5020.78, -152.33, 5.112, 0, 0, 0.551, -0.834, 0, @PHASEID+100, 52500),

-- Reliquias (Fase 1300)
(@SPAWNID+201, @GOBJECTID+2, 2197, 4400.12, 6790.45, -780.22, 0, 0, 0, 0, 1, 300, @PHASEID+300, 52500),
(@SPAWNID+202, @GOBJECTID+2, 2197, 4275.31, 6650.33, -760.11, 0, 0, 0, 0, 1, 300, @PHASEID+300, 52500),

-- Núcleo de Eternidad (Gouffres)
(@SPAWNID+301, @GOBJECTID+3, 2450, 120.45, 230.67, -45.22, 0, 0, 0, 0, 1, 0, 0, 52500);

-- =============================================
-- 3. CADENA DE MISIONES COMPLETA
-- =============================================

-- MISIÓN 1: Llamado de las Profundidades
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestInfoID`, `LogTitle`, `LogDescription`, `QuestDescription`, `Flags`, `RewardMoney`, `RewardFactionID1`, `RewardFactionValue1`, `VerifiedBuild`) VALUES
(@QUESTID+1, 2, 901, 'Llamado de las Profundidades', 'Habla con Brann Barbabronce en Dornogal', '¡Los Terranios despiertan! Sus latidos resuenan bajo nuestros pies...', 0, 250000, 2507, 150, 52500);

INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `ObjectID`, `Amount`, `Description`, `VerifiedBuild`) VALUES
(1, @QUESTID+1, 0, @NPCID+1, 1, 'Habla con Brann Barbabronce', 52500);

-- MISIÓN 2: Rastros de Piedra
INSERT INTO `quest_template` (`ID`, `PrevQuestId`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `RequiredItemId1`, `RequiredItemCount1`, `RewardItem1`, `RewardAmount1`, `RewardFactionID1`, `RewardFactionValue1`, `VerifiedBuild`) VALUES
(@QUESTID+2, @QUESTID+1, 902, 'Rastros de Piedra', 'Recoge 8 Fragmentos de Resonancia Terrania', @ITEMID+101, 8, @ITEMID+102, 1, 2507, 100, 52500);

-- MISIÓN 3: Protocolo de Emergencia
INSERT INTO `quest_template` (`ID`, `PrevQuestId`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `RequiredNpcOrGo1`, `RequiredNpcOrGoCount1`, `RewardFactionID1`, `RewardFactionValue1`, `VerifiedBuild`) VALUES
(@QUESTID+3, @QUESTID+2, 903, 'Protocolo de Emergencia', 'Activa 3 Consolas de Control Primario', @GOBJECTID+1, 3, 2598, 200, 52500);

-- MISIÓN 4: Corazón de la Montaña (Jefe Élite)
INSERT INTO `quest_template` (`ID`, `PrevQuestId`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `FlagsEx`, `RewardItem1`, `RewardAmount1`, `RewardFactionID1`, `RewardFactionValue1`, `VerifiedBuild`) VALUES
(@QUESTID+4, @QUESTID+3, 904, 'Corazón de la Montaña', 'Derrota a Kaelumon el Vigilante', 0x4000000, @ITEMID+103, 1, 2598, 500, 52500);

INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `ObjectID`, `Amount`, `Description`, `VerifiedBuild`) VALUES
(4, @QUESTID+4, 0, @NPCID+2, 1, 'Derrota a Kaelumon el Vigilante', 52500);

-- MISIÓN 5: Secretos en la Oscuridad
INSERT INTO `quest_template` (`ID`, `PrevQuestId`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `RequiredSourceItemId1`, `RequiredSourceItemCount1`, `RewardMoney`, `RewardFactionID1`, `RewardFactionValue1`, `VerifiedBuild`) VALUES
(@QUESTID+5, @QUESTID+4, 905, 'Secretos en la Oscuridad', 'Entrega la Esquirla de Argus a Lorien Petrasombra', @ITEMID+104, 1, 500000, 2598, 250, 52500);

INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `ObjectID`, `Amount`, `Description`, `VerifiedBuild`) VALUES
(5, @QUESTID+5, 0, @NPCID+3, 1, 'Habla con Lorien Petrasombra', 52500);

-- MISIÓN 6: Refugio Perdido
INSERT INTO `quest_template` (`ID`, `PrevQuestId`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `RequiredItemId1`, `RequiredItemCount1`, `RewardItem1`, `RewardAmount1`, `RewardFactionID1`, `RewardFactionValue1`, `VerifiedBuild`) VALUES
(@QUESTID+6, @QUESTID+5, 906, 'Refugio Perdido', 'Encuentra 4 Reliquias de los Tábidos en Azj-Kahet', @ITEMID+105, 4, @ITEMID+106, 1, 2598, 500, 52500);

-- MISIÓN 7: Forjadores del Vacío (Secundaria)
INSERT INTO `quest_template` (`ID`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `RequiredNpcOrGo1`, `RequiredNpcOrGoCount1`, `RequiredMinRepFaction`, `RequiredMinRepValue`, `RewardItem1`, `RewardAmount1`, `VerifiedBuild`) VALUES
(@QUESTID+7, 907, 'Forjadores del Vacío', 'Derrota a 12 Manipuladores del Vacío', @NPCID+102, 12, 2598, 3000, @ITEMID+107, 1, 52500);

-- MISIÓN 8: El Nucleo Vivo (Mazmorra Gouffres)
INSERT INTO `quest_template` (`ID`, `PrevQuestId`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `RequiredSourceItemId1`, `RequiredSourceItemCount1`, `RewardItem1`, `RewardAmount1`, `RewardFactionID1`, `RewardFactionValue1`, `VerifiedBuild`) VALUES
(@QUESTID+8, @QUESTID+7, 908, 'El Nucleo Vivo', 'Recoge el Núcleo de Eternidad en Gouffres', @ITEMID+108, 1, @ITEMID+109, 1, 2598, 1000, 52500);

-- MISIÓN 9: Legado de los Ancestros (Final)
INSERT INTO `quest_template` (`ID`, `PrevQuestId`, `QuestInfoID`, `LogTitle`, `QuestDescription`, `RewardItem1`, `RewardAmount1`, `RewardFactionID1`, `RewardFactionValue1`, `FlagsEx`, `VerifiedBuild`) VALUES
(@QUESTID+9, @QUESTID+6, 909, 'Legado de los Ancestros', 'Consulta con la Geomántica Aela en Dornogal', @ITEMID+110, 1, 2598, 1000, 0x4000000, 52500);

-- =============================================
-- 4. ITEMS Y RECOMPENSAS
-- =============================================

-- Plantillas de Items
INSERT INTO `item_template` (`entry`, `name`, `Quality`, `ItemLevel`, `class`, `subclass`, `InventoryType`, `DisplayInfoID`, `WarbandItemIndex`, `VerifiedBuild`) VALUES
(@ITEMID+101, 'Fragmento de Resonancia Terrania', 1, 480, 15, 0, 0, 65432, 0, 52500),
(@ITEMID+102, 'Brazales de Geomensor', 3, 480, 4, 3, 9, 71234, 0, 52500),
(@ITEMID+103, 'Capa del Geodínamo', 4, 483, 4, 1, 16, 71235, 0, 52500),
(@ITEMID+104, 'Esquirla de Argus', 3, 500, 15, 0, 0, 56789, 0, 52500),
(@ITEMID+105, 'Reliquia de los Tábidos', 1, 500, 15, 0, 0, 56790, 0, 52500),
(@ITEMID+106, 'Anillo de la Tierra Infinita', 4, 485, 4, 0, 11, 56791, 0, 52500),
(@ITEMID+107, 'Martillo de los Terranios', 4, 487, 2, 4, 13, 56792, 0, 52500),
(@ITEMID+108, 'Núcleo de Eternidad', 3, 500, 15, 0, 0, 56793, 0, 52500),
(@ITEMID+109, 'Transmisor Sónico Terranio', 4, 1, 15, 5, 0, 56794, 1, 52500), -- Montura Warband
(@ITEMID+110, 'Cristal de Resonancia Ancestral', 4, 510, 15, 0, 0, 56795, 2, 52500); -- Objeto Warband

-- Recompensas de Misión
INSERT INTO `quest_rewards` (`ID`, `QuestID`, `ItemID`, `ItemCount`, `VerifiedBuild`) VALUES
(1, @QUESTID+2, @ITEMID+102, 1, 52500),
(2, @QUESTID+4, @ITEMID+103, 1, 52500),
(3, @QUESTID+6, @ITEMID+106, 1, 52500),
(4, @QUESTID+7, @ITEMID+107, 1, 52500),
(5, @QUESTID+8, @ITEMID+109, 1, 52500),
(6, @QUESTID+9, @ITEMID+110, 1, 52500);

-- =============================================
-- 5. SISTEMA DE FASES Y CONDICIONES
-- =============================================

-- Definición de Áreas de Fase
INSERT INTO `phase_area` (`areaId`, `phaseId`, `comment`, `VerifiedBuild`) VALUES
(12345, @PHASEID, 'Dornogal - Fase Inicial Terranios', 52500),
(12345, @PHASEID+100, 'Dornogal - Máquina de Despertar', 52500),
(12345, @PHASEID+200, 'Bóveda de los Ancestros - Jefe Kaelumon', 52500),
(12345, @PHASEID+300, 'Dornogal - Terranios Aliados', 52500),
(12346, @PHASEID+300, 'Azj-Kahet - Reliquias Disponibles', 52500);

-- Condiciones de Desbloqueo
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`, `VerifiedBuild`) VALUES
(26, 0, @PHASEID+100, 0, 8, @QUESTID+1, 0, 'Desbloquear Fase 100 al completar misión inicial', 52500),
(26, 0, @PHASEID+200, 0, 8, @QUESTID+3, 0, 'Desbloquear Fase 200 al completar Protocolo', 52500),
(26, 0, @PHASEID+300, 0, 8, @QUESTID+4, 0, 'Desbloquear Fase 300 al derrotar a Kaelumon', 52500),
(26, 0, @PHASEID+300, 0, 28, @QUESTID+6, 0, 'Desbloquear Fase 300 al completar Refugio Perdido', 52500),
(9, 0, @QUESTID+7, 0, 5, 2598, 3000, 'Requiere reputación Aliada con Terranios', 52500);

-- =============================================
-- 6. WARBAND (Sistema TWW)
-- =============================================

-- Reputación Compartida
INSERT INTO `account_shared_faction_reputation` (`faction`, `flags`, `VerifiedBuild`) VALUES
(2598, 1, 52500); -- Terranios de Khaz Algar

-- Logro Compartido
INSERT INTO `achievement` (`ID`, `Description`, `Title`, `RewardItem`, `Flags`, `Category`, `Points`, `UiOrder`, `IconFileID`, `VerifiedBuild`) VALUES
(10000, 'Completar la cadena de los Terranios', 'Aliado de los Terranios', @ITEMID+109, 0, 150, 10, 0, 123456, 52500);

INSERT INTO `account_achievement` (`achievement`, `account`, `date`) VALUES
(10000, 0, UNIX_TIMESTAMP());

-- =============================================
-- 7. SONIDOS Y EFECTOS (Ambientación)
-- =============================================

-- Sonidos para activación de consolas
INSERT INTO `sound_entries` (`ID`, `SoundType`, `Name`, `File`, `VerifiedBuild`) VALUES
(@SOUNDID+1, 0, 'TerranioMachineActivate', 'Sound/Creature/Terranio/MachineActivate.ogg', 52500),
(@SOUNDID+2, 0, 'TerranioAncientRumble', 'Sound/Creature/Terranio/AncientRumble.ogg', 52500);

-- Spells para efectos visuales
INSERT INTO `spell_visual` (`ID`, `SpellVisualMissileSetID`, `Flags`, `VerifiedBuild`) VALUES
(@SPELLID+1, 0, 0, 52500), -- Efecto de activación
(@SPELLID+2, 0, 0, 52500); -- Efecto de despertar

-- =============================================
-- 8. LOCALIZACIONES (Español/English)
-- =============================================

-- Localización de NPCs
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `Title`, `VerifiedBuild`) VALUES
(@NPCID+1, 'esES', 'Brann Barbabronce', 'Liga de Expedicionarios', 52500),
(@NPCID+1, 'enUS', 'Brann Bronzebeard', 'Explorers\' League', 52500),
(@NPCID+2, 'esES', 'Kaelumon el Vigilante', 'Guardian Terranio', 52500),
(@NPCID+2, 'enUS', 'Kaelumon the Watcher', 'Earthen Guardian', 52500);

-- Localización de Objetos
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`) VALUES
(@ITEMID+109, 'esES', 'Transmisor Sónico Terranio', 'Montura terrestre de los Terranios', 52500),
(@ITEMID+109, 'enUS', 'Earthen Sonic Transmitter', 'Earthen land mount', 52500);
