UPDATE `creature_template` SET `gossip_menu_id` = 22537 WHERE (entry = 136907);

DELETE FROM `conversation_actors` WHERE ConversationId IN (8689, 9001, 9435, 9436, 9437, 9438);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorGuid`, `Idx`, `VerifiedBuild`) VALUES
(8689, 210302887, 0, 27404), -- Full: 0x20424CF12085B2C0007038000000A886 Creature/0 R4243/S28728 Map: Chamber of Heart Entry: Magni Bronzebeard Low: 43142
(9001, 210302887, 0, 27404), -- Full: 0x20424CF12085B2C0007038000000A886 Creature/0 R4243/S28728 Map: Chamber of Heart Entry: Magni Bronzebeard Low: 43142
(9435, 210302887, 0, 27404), -- Full: 0x20424CF12085B2C0007038000000A886 Creature/0 R4243/S28728 Map: Chamber of Heart Entry: Magni Bronzebeard Low: 43142
(9436, 210302887, 0, 27404), -- Full: 0x20424CF12085B2C0007038000000A886 Creature/0 R4243/S28728 Map: Chamber of Heart Entry: Magni Bronzebeard Low: 43142
(9437, 210302887, 0, 27404), -- Full: 0x20424CF12085B2C0007038000000A886 Creature/0 R4243/S28728 Map: Chamber of Heart Entry: Magni Bronzebeard Low: 43142
(9438, 210302887, 0, 27404); -- Full: 0x20424CF12085B2C0007038000000A886 Creature/0 R4243/S28728 Map: Chamber of Heart Entry: Magni Bronzebeard Low: 43142

UPDATE `creature_template` SET `InhabitType` = 4 WHERE (entry = 136728);

UPDATE `quest_template_addon` SET `PrevQuestID` = '51211', `ExclusiveGroup` = '0' WHERE `id` = 52428;

UPDATE creature_template SET scriptname = "npc_magni_bronzebeard_silithus" WHERE entry = 130216;
UPDATE creature_template SET scriptname = "npc_magni_bronzebeard_heart_chamber" WHERE entry = 136907;
UPDATE creature_template SET scriptname = "npc_azeroth_heart_chamber_azerite_wound" WHERE entry = 141870;

UPDATE gameobject_template SET scriptname = "go_azeroth_heart_chamber_titan_console" WHERE entry = 293847;

DELETE FROM spell_script_names WHERE scriptname = "spell_azeroth_heart_chamber_heart_of_azeroth";
INSERT INTO spell_script_names VALUES
(267913, "spell_azeroth_heart_chamber_heart_of_azeroth");

UPDATE gameobject_template SET scriptname = "go_azeroth_heart_chamber_teleport_pad" WHERE entry IN (294313, 294538, 289522);

UPDATE creature_addon SET aiAnimKit = 16268 WHERE guid = 210302876;
