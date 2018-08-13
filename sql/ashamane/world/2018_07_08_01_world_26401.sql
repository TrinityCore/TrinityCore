
-- Festival Scorchling Ally 26401
UPDATE creature SET position_x=-9387.433, position_y=24.364, position_z=60.6744, orientation=3.707 WHERE id=26401 AND guid=352709;

-- 26401 Festival Scorchling
DELETE FROM creature_text WHERE CreatureID=26401;
INSERT INTO creature_text 
(CreatureID, groupid, id, text, type, language, probability, emote, duration, sound, comment, BroadcastTextID)
VALUES
(26401, 1, 0, "Thank you again, $n, for this delectable incense.", 12, 0, 100.0, 0, 0, 0, "", 25699),
(26401, 2, 0, "%s devours the incense.  It\'s ravenous!", 42, 0, 100.0, 0, 0, 0, "", 25717),
(26401, 3, 0, "So good!  So packed with energy!", 12, 0, 100.0, 0, 0, 0, "", 25718),
(26401, 4, 0, "It has everything a growing scorchling needs!", 12, 0, 100.0, 0, 0, 0, "", 25719),
(26401, 5, 0, "I can feel the power SURGING within me!", 12, 0, 100.0, 0, 0, 0, "", 25730),
(26401, 6, 0, "%s bellows with laughter!", 42, 0, 100.0, 0, 0, 0, "", 25720),
(26401, 7, 0, "Now!  Finally!  Our plans can take effect!", 12, 0, 100.0, 0, 0, 0, "", 25721),
(26401, 8, 0, "KNEEL, LITTLE MORTAL!  KNEEL BEFORE THE MIGHT OF THE HERALD OF RAGNAROS!", 12, 0, 100.0, 0, 0, 0, "", 25722),
(26401, 9, 0, "YOU WILL ALL PERISH IN FLAMES!", 12, 0, 100.0, 0, 0, 0, "", 25723),
(26401, 10, 0, "%s blinks...", 42, 0, 100.0, 0, 0, 0, "", 25724),
(26401, 11, 0, "Ah.  I was merely jesting...", 12, 0, 100.0, 0, 0, 0, "", 25725);

delete from creature_text_locale where CreatureID=26401;

UPDATE creature_template SET AIName="", ScriptName="npc_summer_scorchling_26401" WHERE entry=26401;

DELETE FROM smart_scripts WHERE entryorguid=26401;

-- Move NPC: 26401 Summer Scorchling: Winterspring
UPDATE creature SET position_x = 6853.793945, position_y = -4757.094727, position_z = 696.864136, orientation = 1.110913 WHERE guid = 353133;

-- Move NPC: 26401 Summer Scorchling: Hellfire Peninsula
UPDATE creature SET position_x = -524.180603, position_y = 2326.326172, position_z = 38.996391, orientation = 3.670424 WHERE guid = 353545;

-- Move NPC: 26401 Summer Scorchling Dun Morogh
UPDATE creature SET position_x = -5421.563965, position_y = -496.423859, position_z = 397.671661, orientation = 4.822781 WHERE guid = 352710;

-- Move NPC: 26401 Summer Scorchling Redridge Mountains
UPDATE creature SET position_x = -9426.042969, position_y = -2119.329834, position_z = 67.705330, orientation = 4.437054 WHERE guid = 352704;

-- Move NPC: 26401 Summer Scorchling The Hinterlands
UPDATE creature SET position_x = 180.568054, position_y = -2123.990723, position_z = 103.986183, orientation = 3.879432 WHERE guid = 352505;

-- Move NPC: 26401 Summer Scorchling Borean Tundra
UPDATE creature SET position_x = 4130.172363, position_y = 5393.307129, position_z = 26.346027, orientation = 2.099187 WHERE guid = 353327;







