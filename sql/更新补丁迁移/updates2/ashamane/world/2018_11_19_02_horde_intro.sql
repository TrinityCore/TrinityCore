DELETE FROM instance_template WHERE `map` = 1904;
INSERT INTO instance_template VALUES
(1904, 0, "scenario_stormwind_extraction", 1, 0);

DELETE FROM creature_questender WHERE id IN (140176, 135205);
INSERT INTO creature_questender VALUES
(140176, 53031),
(135205, 51443);

DELETE FROM creature_queststarter WHERE id IN (140176, 135205);
INSERT INTO creature_queststarter VALUES
(140176, 51443),
(135205, 50769);

UPDATE `quest_template_addon` SET `PrevQuestID` = 53031 WHERE (ID = 51443);
UPDATE `quest_template_addon` SET `PrevQuestID` = 51443 WHERE (ID = 50769);
UPDATE `quest_template_addon` SET `PrevQuestID` = 50769 WHERE (ID = 46957);

UPDATE quest_template_addon SET scriptname = "quest_stormwind_extraction" WHERE Id = 50769;

UPDATE creature_template SET scriptname = "npc_orgri_mission_orders_speak_sylvanas" WHERE entry = 135201;
UPDATE scene_template SET scriptname = "scene_orgri_secret_weapon" WHERE SceneId = 2136;
UPDATE creature_template SET scriptname = "npc_orgri_mission_orders_meet_team" WHERE entry = 135202;
UPDATE creature_template SET scriptname = "npc_skyhorn_eagle" WHERE entry = 135211;

DELETE FROM scenarios WHERE `map` = 1904;
INSERT INTO scenarios VALUES
(1904, 12, 0, 1522);

UPDATE gossip_menu_option SET OptionType = 21 WHERE OptionIcon = 31;
UPDATE `creature_template` SET `npcflag` = 1 WHERE (entry = 144635);

DELETE FROM phase_area WHERE AreaId = 9553;
INSERT INTO phase_area VALUES
(9553, 169, "The Stormwind Extraction - Default phase"),
(9553, 11775, "The Stormwind Extraction - Fire phase");

UPDATE gameobject SET phaseId = 11775 WHERE map = 1904 AND id IN (282244, 282245, 282242, 282238, 282243, 282239, 282241, 282240);
UPDATE creature SET movementType = 0, spawnDist = 0 WHERE map = 1904;
DELETE FROM creature WHERE guid IN (280000688, 280000711);
DELETE FROM gameobject WHERE id = 281661;

UPDATE creature_addon SET aiAnimKit = 6059 WHERE guid = 280000383;
UPDATE creature_addon SET aiAnimKit = 4175 WHERE guid IN (280000370, 280000379, 280000380);
DELETE FROM creature WHERE id = 134094 AND map = 1904 AND guid IN (SELECT guid FROM creature_addon WHERE auras = "271187" OR auras = "263506");

UPDATE creature_template SET inhabitType = 4 WHERE entry IN (134094, 134085, 134087, 137428);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=8174 AND `Idx`=0) OR (`ConversationId`=8175 AND `Idx`=0) OR (`ConversationId`=6721 AND `Idx`=0) OR (`ConversationId`=6722 AND `Idx`=0) OR (`ConversationId`=6722 AND `Idx`=1) OR (`ConversationId`=7039 AND `Idx`=0) OR (`ConversationId`=7040 AND `Idx`=0) OR (`ConversationId`=7041 AND `Idx`=0) OR (`ConversationId`=7042 AND `Idx`=1) OR (`ConversationId`=7042 AND `Idx`=0) OR (`ConversationId`=7044 AND `Idx`=0) OR (`ConversationId`=7044 AND `Idx`=2) OR (`ConversationId`=7044 AND `Idx`=1) OR (`ConversationId`=7047 AND `Idx`=3) OR (`ConversationId`=7047 AND `Idx`=2) OR (`ConversationId`=7047 AND `Idx`=1) OR (`ConversationId`=7047 AND `Idx`=0) OR (`ConversationId`=7049 AND `ConversationActorId`=134163 AND `Idx`=0) OR (`ConversationId`=7052 AND `Idx`=0) OR (`ConversationId`=7052 AND `Idx`=2) OR (`ConversationId`=7052 AND `Idx`=1) OR (`ConversationId`=7055 AND `Idx`=0) OR (`ConversationId`=7055 AND `Idx`=1) OR (`ConversationId`=7058 AND `Idx`=3) OR (`ConversationId`=7058 AND `Idx`=2) OR (`ConversationId`=7058 AND `Idx`=1) OR (`ConversationId`=7058 AND `Idx`=0) OR (`ConversationId`=7088 AND `Idx`=1) OR (`ConversationId`=7088 AND `Idx`=0) OR (`ConversationId`=7089 AND `Idx`=0) OR (`ConversationId`=7091 AND `Idx`=1) OR (`ConversationId`=7091 AND `Idx`=0) OR (`ConversationId`=7092 AND `Idx`=0) OR (`ConversationId`=7092 AND `Idx`=1) OR (`ConversationId`=7093 AND `Idx`=0) OR (`ConversationId`=7094 AND `Idx`=1) OR (`ConversationId`=7094 AND `Idx`=0) OR (`ConversationId`=7095 AND `Idx`=2) OR (`ConversationId`=7095 AND `Idx`=1) OR (`ConversationId`=7095 AND `Idx`=0) OR (`ConversationId`=7109 AND `Idx`=1) OR (`ConversationId`=7109 AND `Idx`=0) OR (`ConversationId`=7110 AND `Idx`=1) OR (`ConversationId`=7110 AND `Idx`=0) OR (`ConversationId`=7112 AND `Idx`=0) OR (`ConversationId`=7113 AND `Idx`=1) OR (`ConversationId`=7113 AND `Idx`=0) OR (`ConversationId`=7114 AND `Idx`=1) OR (`ConversationId`=7114 AND `Idx`=0) OR (`ConversationId`=7115 AND `Idx`=0) OR (`ConversationId`=7115 AND `Idx`=1) OR (`ConversationId`=7138 AND `Idx`=0) OR (`ConversationId`=7139 AND `Idx`=1) OR (`ConversationId`=7139 AND `Idx`=0) OR (`ConversationId`=7142 AND `Idx`=1) OR (`ConversationId`=7142 AND `Idx`=0) OR (`ConversationId`=7143 AND `Idx`=3) OR (`ConversationId`=7143 AND `Idx`=2) OR (`ConversationId`=7143 AND `Idx`=1) OR (`ConversationId`=7143 AND `Idx`=0) OR (`ConversationId`=7144 AND `Idx`=1) OR (`ConversationId`=7144 AND `Idx`=0) OR (`ConversationId`=7145 AND `Idx`=0) OR (`ConversationId`=7145 AND `Idx`=1) OR (`ConversationId`=7147 AND `Idx`=1) OR (`ConversationId`=7147 AND `Idx`=2) OR (`ConversationId`=7147 AND `Idx`=3) OR (`ConversationId`=7147 AND `Idx`=0) OR (`ConversationId`=7170 AND `Idx`=2) OR (`ConversationId`=7170 AND `Idx`=1) OR (`ConversationId`=7170 AND `Idx`=0) OR (`ConversationId`=8174 AND `ConversationActorId`=134201 AND `Idx`=0) OR (`ConversationId`=8175 AND `ConversationActorId`=134201 AND `Idx`=0) OR (`ConversationId`=8177 AND `Idx`=0) OR (`ConversationId`=8178 AND `Idx`=1) OR (`ConversationId`=8178 AND `Idx`=0) OR (`ConversationId`=8399 AND `Idx`=0) OR (`ConversationId`=8689 AND `Idx`=0) OR (`ConversationId`=9001 AND `Idx`=0) OR (`ConversationId`=9435 AND `Idx`=0) OR (`ConversationId`=9436 AND `Idx`=0) OR (`ConversationId`=9437 AND `Idx`=0) OR (`ConversationId`=9438 AND `Idx`=0) OR (`ConversationId`=9570 AND `Idx`=0) OR (`ConversationId`=9683 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(7049, 134163, 0, 28153),
(8174, 134201, 0, 28153),
(8175, 134201, 0, 28153);

INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorGuid`, `ConversationActorNearId`, `Idx`, `VerifiedBuild`) VALUES
(9570, 0,           140176, 0, 28153), -- Full: 0x2016FC002088E40000755B000072001D Creature/0 R1471/S30043 Map: Kalimdor Entry: 140176 -- (Nathanos Blightcaller) Low: 7471133


(7170, 0,           135205, 2, 28153), -- Full: 0x2016FC002084094000755B0000720B37 Creature/0 R1471/S30043 Map: Kalimdor Entry: 135205 -- (Nathanos Blightcaller) Low: 7473975
(7170, 0,           135206, 1, 28153), -- Full: 0x2016FC002084098000755B0000720B37 Creature/0 R1471/S30043 Map: Kalimdor Entry: 135206 -- (Rokhan) Low: 7473975
(7170, 0,           135207, 0, 28153), -- Full: 0x2016FC00208409C000755B0000720B37 Creature/0 R1471/S30043 Map: Kalimdor Entry: 135207 -- (First Arcanist Thalyssra) Low: 7473975

-- Transports await on remparts, lets move out
(8399, 0,           135205, 0, 28153), -- Full: 0x2016FC002084094000755B0000720B64 Creature/0 R1471/S30043 Map: Kalimdor Entry: 135205 -- (Nathanos Blightcaller) Low: 7474020

-- Nathanos arrival speech
(7039, 0,           134039, 0, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720BAC Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7474092
(7040, 0,           134039, 0, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720BAC Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7474092
(7041, 0,           134039, 0, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720BAC Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7474092

-- At prison entrance, rokhan go ahead
(7042, 0,           134037, 1, 28153), -- Full: 0x2016FCEE0082E54000014E0000720BFD Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7474173
(7042, 0,           134038, 0, 28153), -- Full: 0x2016FCEE0082E58000014E0000720BFD Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474173

-- Saurfang dialog
(7044, 280000345,   0,      0, 28153), -- Full: 0x2016FCEE0082FA0000014E0000720BFE Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: 134120 -- (High Overlord Saurfang) Low: 7474174
(7044, 0,           134037, 2, 28153), -- Full: 0x2016FCEE0082E54000014E0000720CAB Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7474347
(7044, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720CAB Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474347

-- Escort arrive just as i said
(9683, 0,           134093, 0, 28153), -- Full: 0x2016FCEE0082F34000014E0000720C9D Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7474333

-- Thank you (prison free)
(7047, 0,           134093, 3, 28153), -- Full: 0x2016FCEE0082F34000014E0000720C9D Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7474333
(7047, 0,           134037, 2, 28153), -- Full: 0x2016FCEE0082E54000014E0000720CAB Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7474347
(7047, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720CAB Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474347
(7047, 0,           134092, 0, 28153), -- Full: 0x2016FCEE0082F30000014E0000720C9D Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7474333

-- Nullification field
(7055, 0,           134038, 0, 28153), -- Full: 0x2016FCEE0082E58000014E0000720CAB Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474347
(7055, 0,           134037, 1, 28153), -- Full: 0x2016FCEE0082E54000014E0000720CAB Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7474347

-- How do we get out ? this way ! that would be a mistake
(7052, 0,           134092, 0, 28153), -- Full: 0x2016FCEE0082F30000014E0000720C9D Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7474333
(7052, 0,           134093, 2, 28153), -- Full: 0x2016FCEE0082F34000014E0000720C9D Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7474333
(7052, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720CAB Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474347

-- It smells unpleasant. Where dis be leading ? out
(7058, 0,           134093, 3, 28153), -- Full: 0x2016FCEE0082F34000014E0000720C9D Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7474333
(7058, 0,           134037, 2, 28153), -- Full: 0x2016FCEE0082E54000014E0000720CAB Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7474347
(7058, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720CAB Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474347
(7058, 0,           134092, 0, 28153), -- Full: 0x2016FCEE0082F30000014E0000720C9D Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7474333

-- After prison escape
(7088, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474643
(7088, 0,           134037, 0, 28153), -- Full: 0x2016FCEE0082E54000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7474643

-- All citizen shall remain inside
(7089, 0,           137892, 0, 28153), -- Full: 0x2016FCEE0086A90000014E0000720DFF Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: 137892 (Crier Goodman) Low: 7474687

-- Let's cross the bridge
(7091, 0,           134092, 1, 28153), -- Full: 0x2016FCEE0082F30000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7474643
(7091, 0,           134038, 0, 28153), -- Full: 0x2016FCEE0082E58000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474643

-- Jump the bridge
(7092, 0,           134093, 0, 28153), -- Full: 0x2016FCEE0082F34000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7474643
(7092, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474643

-- Anduin on the bridge intruder have been detected
(7093, 0,           134202, 0, 28153), -- Full: 0x2016FCEE00830E8000014E0000720E49 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: 134202 (Anduin Wrynn) Low: 7474761

-- A little more warning would have been nice
(7094, 0,           134093, 1, 28153), -- Full: 0x2016FCEE0082F34000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7474643
(7094, 0,           134038, 0, 28153), -- Full: 0x2016FCEE0082E58000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474643

-- Where are the guards ?
(7095, 0,           134093, 2, 28153), -- Full: 0x2016FCEE0082F34000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7474643
(7095, 0,           134092, 1, 28153), -- Full: 0x2016FCEE0082F30000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7474643
(7095, 0,           134037, 0, 28153), -- Full: 0x2016FCEE0082E54000014E0000720DD3 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7474643

(7110, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720EB5 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474869
(7110, 0,           134200, 0, 28153), -- Full: 0x2016FCEE00830E0000014E0000720EB5 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Genn Greymane Low: 7474869

-- At genn attack
(7109, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720EB5 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474869
(7109, 0,           134037, 0, 28153), -- Full: 0x2016FCEE0082E54000014E0000720EB5 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7474869

-- You will want to wait here
(7113, 0,           134092, 1, 28153), -- Full: 0x2016FCEE0082F30000014E0000720EB5 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7474869
(7113, 0,           134093, 0, 28153), -- Full: 0x2016FCEE0082F34000014E0000720EB5 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7474869

(7112, 0,           134201, 0, 28153), -- Full: 0x2016FCEE00830E4000014E0000720F35 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Lady Jaina Proudmoore Low: 7474997

-- One would think a city is less flamable
(7114, 0,           134092, 1, 28153), -- Full: 0x2016FCEE0082F30000014E0000720EB5 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7474869
(7114, 0,           134093, 0, 28153), -- Full: 0x2016FCEE0082F34000014E0000720EB5 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7474869

-- fine mess we're in
(7115, 0,           134039, 0, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720EB2 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7474866
(7115, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720EB5 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7474869

-- Alliance won't be taking prisonner this time
(7138, 0,           134039, 0, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7475104

-- She has cut our escape ! break the ice !
(7139, 0,           134039, 1, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7475104
(7139, 0,           134037, 0, 28153), -- Full: 0x2016FCEE0082E54000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7475104

-- Loa lend me your strenght !
(8177, 0,           134092, 0, 28153), -- Full: 0x2016FCEE0082F30000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7475104

-- Thank loa lets move
(8178, 0,           134038, 1, 28153), -- Full: 0x2016FCEE0082E58000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7475104
(8178, 0,           134039, 0, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7475104

-- Their force must have returned how will we get through ?
(7142, 0,           134039, 1, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7475104
(7142, 0,           134037, 0, 28153), -- Full: 0x2016FCEE0082E54000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7475104

-- Lasan appear from sky with eagles
(7143, 0,           134092, 3, 28153), -- Full: 0x2016FCEE0082F30000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7475104
(7143, 0,           134038, 2, 28153), -- Full: 0x2016FCEE0082E58000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7475104
(7143, 0,           134036, 1, 28153), -- Full: 0x2016FCEE0082E50000014E0000721092 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: 134036 (Lasan Skyhorn) Low: 7475346
(7143, 0,           134093, 0, 28153), -- Full: 0x2016FCEE0082F34000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7475104

-- Are they not pursuing us ? (jaina front)
(7144, 0,           134039, 1, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7475104
(7144, 0,           134037, 0, 28153), -- Full: 0x2016FCEE0082E54000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: First Arcanist Thalyssra Low: 7475104

-- Your little jailbreak is hover
(7145, 0,           134201, 0, 28153), -- Full: 0x2016FCEE00830E4000014E00007210BE Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Lady Jaina Proudmoore Low: 7475390
(7145, 0,           134039, 1, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7475104

-- Thank you zul (go to ship)
(7147, 0,           134093, 1, 28153), -- Full: 0x2016FCEE0082F34000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Zul the Prophet Low: 7475104
(7147, 0,           134092, 2, 28153), -- Full: 0x2016FCEE0082F30000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Princess Talanji Low: 7475104
(7147, 0,           134039, 3, 28153), -- Full: 0x2016FCEE0082E5C000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Nathanos Blightcaller Low: 7475104
(7147, 0,           134038, 0, 28153), -- Full: 0x2016FCEE0082E58000014E0000720FA0 Creature/0 R1471/S334 Map: Stormwind Escape from Stockades Entry: Rokhan Low: 7475104

(6721, 0,           132661, 0, 28153), -- Full: 0x204234CD40818D400077A60000721226 Creature/0 R4237/S30630 Map: Zandalar Entry: Princess Talanji Low: 7475750

(6722, 0,           122661, 0, 28153), -- Full: 0x204234CD4077C9400077A600007206F4 Creature/0 R4237/S30630 Map: Zandalar Entry: General Jakra'zet Low: 7472884
(6722, 0,           132661, 1, 28153); -- Full: 0x204234CD40818D400077A60000721226 Creature/0 R4237/S30630 Map: Zandalar Entry: Princess Talanji Low: 7475750

DELETE FROM creature WHERE id = 134091 AND position_z > 46;
DELETE FROM creature WHERE map = 1904 AND id IN (134038, 134037, 134092, 134093);
DELETE FROM `creature_summon_groups` WHERE (summonerId = 134120 AND summonerType = 0) OR (summonerId = 1904 AND summonerType = 2);
INSERT INTO `creature_summon_groups` VALUES
-- Rokhan & Thalyssra at beginning
(1904,  2, 10,  134038, -8689.73,   897.597,    93.1204,    1.36126,    8,  0),
(1904,  2, 10,  134037, -8688.62,   896.144,    93.8165,    0.77452,    8,  0),

-- Talanji & Zul in prison
(1904,  2, 11,  134092, -8751.38,   895.338,    52.9426,    4.07637,    8,  0),
(1904,  2, 11,  134093, -8746.82,   894.208, 	52.8987,    5.35803,    8,  0),

-- Rokhan & Thalyssra inside prison
(1904,  2, 20,  134038, -8718.78,   1000.06,    45.482,     3.25104,    8,  0),
(1904,  2, 20,  134037, -8716.91,   1002.92,    45.482,     3.21722,    8,  0),

-- 7th Legion patrol at prison entranced
(1904,  2, 21,  134083, -8726.49,   999.258,    45.481,     0.08642,    6,  5000),
(1904,  2, 21,  134084, -8727.34,   1002.08,    45.481,     0.08450,    6,  5000),

-- 7th Legion patrol coming to first prison room
(1904,  2, 22,  134083, -8776.01,   993.645,    45.4819,    4.86111,    6,  5000),
(1904,  2, 22,  134084, -8775.62,   991.278,    45.4819,    1.80494,    6,  5000),

-- Rokhan & Thalyssra & Talanji & Zul after cell open
(1904,  2, 30,  134038, -8743.460938, 883.260620, 52.815895, 2.071085,  8,  0),
(1904,  2, 30,  134037, -8741.128906, 885.286560, 52.815895, 2.326339,  8,  0),
(1904,  2, 30,  134092, -8745.711914, 886.244446, 52.815662, 5.269852,  8,  0),
(1904,  2, 30,  134093, -8743.465820, 888.028198, 52.815895, 5.251949,  8,  0),

-- 7th Legion battlemage after Talanji & Zul freed
-- (1904,  2, 31,  134091, -8691.55,   891.026,    53.8153,    2.28253,    6,  5000),
(1904,  2, 31,  134091, -8704.78,   907.356,    53.8153,    5.36426,    6,  5000),
(1904,  2, 31,  134091, -8691.04,   904.984,    53.8153,    3.75466,    6,  5000),
(1904,  2, 31,  134091, -8741.61,   865.161,    53.8153,    0.67442,    6,  5000),
(1904,  2, 31,  134091, -8742.98,   866.946,    53.8153,    0.67442,    6,  5000),
(1904,  2, 31,  134091, -8740.20,   863.165,    53.8153,    0.67442,    6,  5000),

-- Rokhan & Thalyssra & Talanji & Zul outside of prison
(1904,  2, 40,  134038, -8535.25,   486.085,    101.567,    2.00541,    8,  0),
(1904,  2, 40,  134037, -8533.11,   489.399,    101.172,    2.29067,    8,  0),
(1904,  2, 40,  134092, -8537.86,   486.47,     101.176,    1.82384,    8,  0),
(1904,  2, 40,  134093, -8533.56,   483.793, 	102.027,    2.04008,    8,  0),

-- Rokhan & Thalyssra & Talanji & Zul at cathedral place
(1904,  2, 50,  134038, -8658.96,   746.929,    96.9081,    3.8786,     8,  0),
(1904,  2, 50,  134037, -8655.75,   749.967,    96.9362,    3.8846,     8,  0),
(1904,  2, 50,  134092, -8653.04,   746.418,    96.9171,    5.4403,     8,  0),
(1904,  2, 50,  134093, -8658.19,   753.052,    97.0275,    2.4085,     8,  0),

-- Everybody near the stormwind harbor
(1904,  2, 60,  134038, -8493.51,   931.075,    97.4637,    1.85595,    8,  0),
(1904,  2, 60,  134037, -8495.97,   930.771,    97.5362,    1.02702,    8,  0),
(1904,  2, 60,  134092, -8491.81,   932.398,    97.4484,    2.68383,    8,  0),
(1904,  2, 60,  134093, -8490.09,   933.602,    97.4276,    3.14107,    8,  0),

-- HACKFIX everybody in front of jaina at dock
(1904,  2, 70,  134038, -8294.779297, 1364.241455, 5.230810, 1.573214,  8,  0),
(1904,  2, 70,  134037, -8297.929688, 1364.233887, 5.230810, 1.573214,  8,  0),
(1904,  2, 70,  134092, -8290.789063, 1364.251099, 5.562543, 1.573214,  8,  0),
(1904,  2, 70,  134093, -8283.789063, 1364.267944, 5.230956, 1.573214,  8,  0),
(1904,  2, 70,  134039, -8281.269531, 1364.264160, 5.227362, 1.569287,  8,  0);

UPDATE gameobject_template SET scriptname = "go_se_sewer_access_portal" WHERE entry = 281484;
UPDATE gameobject_template SET scriptname = "go_se_talanji_zul_cell_door" WHERE entry = 287550;

UPDATE `creature_template` SET `unit_flags` = 33024 WHERE entry IN (134037, 134038);
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE entry IN (134037, 134038);

DELETE FROM creature WHERE guid IN (280000375, 280000381, 280000384, 280000389, 280000394);

UPDATE creature SET unit_flags = 768 WHERE guid IN (280000365, 280000355);
UPDATE creature_addon SET auras = "31261 230246 248811" WHERE guid IN (280000365, 280000355);

UPDATE creature_template SET scriptname = "npc_se_thalyssra" WHERE entry = 134037;
UPDATE creature_template SET scriptname = "npc_se_saurfang" WHERE entry = 134120;

UPDATE creature_template_addon SET auras = "" WHERE entry = 134093;

UPDATE `creature_template` SET `unit_flags` = 32768 WHERE entry IN (134092, 134093, 134038, 134091);
UPDATE creature_template SET aiName = "CombatAI" WHERE entry IN (134092, 134093, 134038);

DELETE FROM `gameobject_loot_template` WHERE (Entry = 289645) AND (Item IN (160251));
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(289645, 160251, 0, 100, 1, 1, 0, 1, 1, '');

UPDATE `gameobject_template_addon` SET flags = 0 WHERE entry = 289645;

-- TEMP HACKFIX
DELETE FROM `spell_target_position` WHERE ID = 263524;
INSERT INTO `spell_target_position` VALUES
(263524, 0, 1904, -8287.646484, 1364.246338, 5.233779, 28153);
-- (263524, 0, 1904, -8536.96, 483.68, 101.7, 28153);

UPDATE `creature_template` SET `npcflag` = 16777216 WHERE (entry = 139948);

UPDATE scene_template SET scriptname = "scene_se_jaina_and_zul" WHERE SceneId = 2119;

DELETE FROM `creature_addon` WHERE guid IN (280000435);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(280000435, 0, 0, 0, 1, 0, '');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 135211;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
('135211', '52391', '1');

DELETE FROM `lfg_dungeon_template` WHERE dungeonId = 1702;
INSERT INTO `lfg_dungeon_template` VALUES
-- Temp hackfix
(1702, "The Stormwind Extraction", -8692.881836, 900.341980, 90.369476, 0.642935, 0, 28153);
-- Real data (1702, "The Stormwind Extraction", -7442.66, 1270.47, 6.8, 0, 0, 28153);

SET @CGUID := 280001213;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 135205, 1, 1637, 8618, '0', 0, 0, 0, 0, 1569.832, -4412.496, 15.76778, 4.602501, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),
(@CGUID+1, 135206, 1, 1637, 8618, '0', 0, 0, 0, 0, 1575.929, -4457.361, 15.82104, 1.154236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),
(@CGUID+2, 135207, 1, 1637, 8618, '0', 0, 0, 0, 0, 1580.411, -4456.325, 15.82240, 2.439798, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),

(@CGUID+3, 135211, 1, 1637, 1637, '0', 0, 0, 0, 0, 1400.568, -4370.092, 73.99435, 0.4421007, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),
(@CGUID+4, 135211, 1, 1637, 1637, '0', 0, 0, 0, 0, 1399.734, -4366.507, 73.99405, 0.3240699, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),
(@CGUID+5, 135211, 1, 1637, 1637, '0', 0, 0, 0, 0, 1398.655, -4362.934, 74.0129,  0.1080972, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),
(@CGUID+6, 135211, 1, 1637, 1637, '0', 0, 0, 0, 0, 1398.134, -4352.111, 74.03416, 0.1517032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),
(@CGUID+7, 135211, 1, 1637, 1637, '0', 0, 0, 0, 0, 1397.248, -4347.71,  74.05701, 0.0766947, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),
(@CGUID+8, 135211, 1, 1637, 1637, '0', 0, 0, 0, 0, 1397.168, -4344.111, 73.97974, 0.1371043, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),
(@CGUID+9, 135211, 1, 1637, 1637, '0', 0, 0, 0, 0, 1398.134, -4352.111, 74.1175,  0.1517032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153);

UPDATE `creature_template` SET `npcflag` = 16777216 WHERE (entry = 135438);
UPDATE `npc_spellclick_spells` SET `cast_flags` = '1' WHERE `npc_entry` = '135438' AND `spell_id` = '241199'; 

UPDATE creature_template SET scriptname = "npc_talanji_arrival_escort" WHERE entry = 132661;

UPDATE `quest_template_addon` SET `PrevQuestID` = 46957 WHERE (ID = 46930);
UPDATE `quest_template_addon` SET `PrevQuestID` = 46930 WHERE (ID = 46931);

UPDATE creature_template SET scriptname = "npc_enforcer_pterrordax" WHERE entry = 138912;

UPDATE creature_template SET minlevel = 120, maxlevel = 120, vehicleId = 6031, InhabitType = 4 WHERE entry = 138912;
UPDATE `vehicle_template_accessory` SET `minion` = '1' , `summontype` = '8' WHERE `entry` = '138912' AND `seat_id` = '1'; 
